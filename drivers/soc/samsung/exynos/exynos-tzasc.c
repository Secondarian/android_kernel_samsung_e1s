/*
 * Copyright (c) 2018 Samsung Electronics Co., Ltd.
 *	      http://www.samsung.com/
 *
 * EXYNOS - TrustZone Address Space Controller(TZASC) fail detector
 * Author: Junho Choi <junhosj.choi@samsung.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#include <linux/device.h>
#include <linux/dma-mapping.h>
#include <linux/err.h>
#include <linux/interrupt.h>
#include <linux/irq.h>
#include <linux/irqreturn.h>
#include <linux/module.h>
#include <linux/of.h>
#include <linux/of_irq.h>
#include <linux/platform_device.h>
#include <linux/slab.h>
#include <linux/debugfs.h>
#include <soc/samsung/exynos-smc.h>

#include <soc/samsung/exynos/exynos-tzasc.h>


static irqreturn_t exynos_tzasc_irq_handler(int irq, void *dev_id)
{
	struct tzasc_info_data *data = dev_id;
	uint32_t irq_idx;

	for (irq_idx = 0; irq_idx < data->irqcnt; irq_idx++) {
		if (irq == data->irq[irq_idx])
			break;
	}

	/*
	 *	 * Interrupt status register in TZASC will clear
	 *		 * in this SMC handler
	 *			 */
	data->need_log = exynos_smc(SMC_CMD_GET_TZASC_FAIL_INFO,
			data->fail_info_pa,
			irq_idx,
			data->info_flag);
	if ((data->need_log == TZASC_NEED_FAIL_INFO_LOGGING) ||
			(data->need_log == TZASC_SKIP_FAIL_INFO_LOGGING)) {
		data->need_handle = TZASC_HANDLE_INTERRUPT_THREAD;
	} else if (data->need_log == TZASC_NO_TZASC_FAIL_INTERRUPT) {
		data->need_handle = TZASC_DO_NOT_HANDLE_INTERRUPT_THREAD;
	} else {
		pr_err("TZASC_FAIL_DETECTOR: Failed to get fail information! ret(%#x)\n",
				data->need_log);
		data->need_handle = TZASC_DO_NOT_HANDLE_INTERRUPT_THREAD;
	}

	return IRQ_WAKE_THREAD;
}

static irqreturn_t exynos_tzasc_irq_handler_thread(int irq, void *dev_id)
{
	struct tzasc_info_data *data = dev_id;
	unsigned int intr_stat, fail_ctrl, fail_id, addr_low, tzc_ver, ch_num;
	unsigned int dir_mask;
	unsigned long addr_high;
	int i;

	if (data->need_handle == TZASC_DO_NOT_HANDLE_INTERRUPT_THREAD)
		return IRQ_HANDLED;

	if (data->need_log == TZASC_SKIP_FAIL_INFO_LOGGING) {
		pr_debug("TZASC_FAIL_DETECTOR: Ignore TZASC illegal reads\n");
		return IRQ_HANDLED;
	}

	pr_info("===============[TZASC FAIL DETECTION]===============\n");

	tzc_ver = data->tzc_ver;
	ch_num = data->ch_num;

	/* Parse fail register information */
	for (i = 0; i < ch_num; i++) {
		pr_info("[Channel %d]\n", i);

		intr_stat = data->fail_info[i].tzasc_intr_stat;
		fail_ctrl = data->fail_info[i].tzasc_fail_ctrl;
		fail_id = data->fail_info[i].tzasc_fail_id;

		if (!(intr_stat & TZASC_INTR_STATUS_INTR_STAT_MASK)) {
			pr_info("NO access failure in this Channel\n\n");
			continue;
		}

		addr_low = data->fail_info[i].tzasc_fail_addr_low;
		addr_high = data->fail_info[i].tzasc_fail_addr_high &
			TZASC_FAIL_ADDR_HIGH_MASK;

		if ((tzc_ver == TZASC_VERSION_TZC380) && (ch_num == 2)) {
			addr_low = mif_addr_to_pa(addr_low, i);
			addr_high <<= 1;
		}

		pr_info("- Fail Adddress : %#lx\n",
				addr_high ?
				(addr_high << 32) | addr_low :
				addr_low);

		if (tzc_ver == TZASC_VERSION_TZC380) {
			// ASP WR Fail Interrpt Status per Port : intr_stat[7:4]
			dir_mask = TZASC_FAIL_CONTROL_DIRECTION_MASK_TZC380;
		} else {
			// WrIntStatus : intr_stat[1]
			dir_mask = TZASC_FAIL_CONTROL_DIRECTION_MASK;
		}
		pr_info("- Fail Direction : %s\n",
				intr_stat & dir_mask ?
				"WRITE" :
				"READ");

		pr_info("- Fail Security : %s\n",
				fail_ctrl & TZASC_FAIL_CONTROL_NON_SECURE_MASK ?
				"Non-secure" :
				"Secure");

		if (tzc_ver == TZASC_VERSION_TZC380) {
			pr_info("- Fail Privilege : %s\n",
					fail_ctrl & TZASC_DREX_FAIL_CONTROL_PRIVILEGED_MASK ?
					"Privileged" :
					"Unprivileged");

			pr_info("- Fail AXID : %#x\n",
					fail_id & TZASC_DREX_FAIL_ID_AXID_MASK);
		} else {	/* (tzc_ver == TZASC_VERSION_TZC400) */
			pr_info("- Fail Vnet : %#x\n",
					fail_id & TZASC_SMC_FAIL_ID_VNET_MASK);

			pr_info("- Fail ID : %#x\n",
					fail_id & TZASC_SMC_FAIL_ID_FAIL_ID_MASK);
		}

		pr_info("- Interrupt Status : %s\n",
				intr_stat & TZASC_INTR_STATUS_INTR_STAT_MASK ?
				"Interrupt is asserted" :
				"Interrupt is not asserted");
		pr_info("- Overrun : %s\n",
				intr_stat & TZASC_INTR_STATUS_OVERRUN_MASK ?
				"Two or more failures occurred" :
				"Only one failure occurred");

		if (tzc_ver == TZASC_VERSION_TZC380) {
			pr_info("- Region Setup Fail : %s\n",
					intr_stat & TZASC_DREX_INTR_STATUS_RS_FAIL_MASK ?
					"Region setup failure is detected" :
					"No region setup failure");
			pr_info("- AXI Address Decoding Error : %s\n",
					intr_stat & TZASC_DREX_INTR_STATUS_AXADDR_DECERR_MASK ?
					"AXI address decoding error is detected" :
					"No AXI address decoding error");
			pr_info("- Mismatch of WLAST : %s\n",
					intr_stat & TZASC_DREX_INTR_STATUS_WLAST_ERROR_MASK ?
					"WLAST mismatch is detected" :
					"No WLAST mismatch");
		} else {	/* (tzc_ver == TZASC_VERSION_TZC400) */
			pr_info("- Overlap : %s\n",
					intr_stat & TZASC_SMC_INTR_STATUS_OVERLAP_MASK ?
					"Region overlap violation" :
					"No region overlap");
		}

		pr_info("\n");

		pr_info("- SFR values\n");
		pr_info("FAIL_ADDRESS_LOW : %#x\n", addr_low);
		pr_info("FAIL_ADDRESS_HIGH : %#x\n",
				data->fail_info[i].tzasc_fail_addr_high);
		pr_info("FAIL_CONTROL : %#x\n",
				data->fail_info[i].tzasc_fail_ctrl);
		pr_info("FAIL_ID : %#x\n",
				data->fail_info[i].tzasc_fail_id);
		pr_info("INT_STATUS : %#x\n",
				data->fail_info[i].tzasc_intr_stat);

		pr_info("\n");
	}

	pr_info("====================================================\n");

#ifdef CONFIG_EXYNOS_TZASC_ILLEGAL_ACCESS_PANIC
	BUG();
#endif
	return IRQ_HANDLED;
}

static int exynos_tzasc_probe(struct platform_device *pdev)
{
	struct tzasc_info_data *data;
	unsigned long irqf = IRQF_ONESHOT;
	int ret, i;

	data = devm_kzalloc(&pdev->dev, sizeof(struct tzasc_info_data), GFP_KERNEL);
	if (!data) {
		dev_err(&pdev->dev, "Fail to allocate memory(tzasc_info_data)\n");
		ret = -ENOMEM;
		goto out;
	}

	platform_set_drvdata(pdev, data);
	data->dev = &pdev->dev;

	ret = of_property_read_u32(data->dev->of_node,
			"channel",
			&data->ch_num);
	if (ret) {
		dev_err(data->dev,
				"Fail to get TZASC channel number(%d) from dt\n",
				data->ch_num);
		goto out;
	}

	ret = of_property_read_u32(data->dev->of_node,
			"tzc_ver",
			&data->tzc_ver);
	if (ret) {
		dev_err(data->dev,
				"Fail to get TZC version(%d) from dt\n",
				data->tzc_ver);
		goto out;
	}

	if ((data->tzc_ver != TZASC_VERSION_TZC380) &&
			(data->tzc_ver != TZASC_VERSION_TZC400)) {
		dev_err(data->dev,
				"Invalid TZC version(%d)\n",
				data->tzc_ver);
		ret = -EINVAL;
		goto out;
	}

	ret = exynos_smc(SMC_CMD_CHECK_TZASC_CH_NUM,
			data->ch_num,
			sizeof(struct tzasc_fail_info),
			0);
	if (ret) {
		switch (ret) {
			case TZASC_ERROR_INVALID_CH_NUM:
				dev_err(data->dev,
						"The channel number(%d) defined in DT is invalid\n",
						data->ch_num);
				break;
			case TZASC_ERROR_INVALID_FAIL_INFO_SIZE:
				dev_err(data->dev,
						"The size of struct tzasc_fail_info(%#lx) is invalid\n",
						sizeof(struct tzasc_fail_info));
				break;
			case SMC_CMD_CHECK_TZASC_CH_NUM:
				dev_err(data->dev,
						"DO NOT support this SMC(%#x)\n",
						SMC_CMD_CHECK_TZASC_CH_NUM);
				break;
			default:
				dev_err(data->dev,
						"Unknown error from SMC. ret[%#x]\n",
						ret);
				break;
		}

		ret = -EINVAL;
		goto out;
	}

	dev_dbg(data->dev,
			"TZASC channel number : %d\n",
			data->ch_num);
	dev_info(data->dev,
			"TZASC channel number is valid\n");

	/*
	 * Allocate TZASC fail information buffers as the channel number
	 *
	 * EL3_Monitor has mapped Kernel region with non-cacheable,
	 * so Kernel allocates it by dma_alloc_coherent
	 */
	ret = dma_set_mask(data->dev, DMA_BIT_MASK(36));
	if (ret) {
		dev_err(data->dev,
				"Fail to dma_set_mask. ret[%d]\n",
				ret);
		goto out;
	}

	data->fail_info = dmam_alloc_coherent(data->dev,
			sizeof(struct tzasc_fail_info) *
			data->ch_num,
			&data->fail_info_pa,
			__GFP_ZERO);
	if (!data->fail_info) {
		dev_err(data->dev, "Fail to allocate memory(tzasc_fail_info)\n");
		ret = -ENOMEM;
		goto out;
	}

	dev_dbg(data->dev,
			"VA of tzasc_fail_info : %lx\n",
			(unsigned long)data->fail_info);
	dev_dbg(data->dev,
			"PA of tzasc_fail_info : %llx\n",
			data->fail_info_pa);

#ifdef CONFIG_EXYNOS_TZASC_ILLEGAL_READ_LOGGING
	data->info_flag = TZASC_STR_INFO_FLAG;
#endif

	ret = of_property_read_u32(data->dev->of_node, "irqcnt", &data->irqcnt);
	if (ret) {
		dev_err(data->dev,
				"Fail to get irqcnt(%d) from dt\n",
				data->irqcnt);
		goto out_with_dma_free;
	}

	dev_dbg(data->dev,
			"The number of TZASC interrupt : %d\n",
			data->irqcnt);

	if (data->tzc_ver == TZASC_VERSION_TZC400)
		irqf = IRQF_ONESHOT;

	for (i = 0; i < data->irqcnt; i++) {
		data->irq[i] = irq_of_parse_and_map(data->dev->of_node, i);
		if (!data->irq[i]) {
			dev_err(data->dev,
					"Fail to get irq(%d) from dt\n",
					data->irq[i]);
			ret = -EINVAL;
			goto out_with_dma_free;
		}

		ret = devm_request_threaded_irq(data->dev,
				data->irq[i],
				exynos_tzasc_irq_handler,
				exynos_tzasc_irq_handler_thread,
				irqf,
				pdev->name,
				data);
		if (ret) {
			dev_err(data->dev,
					"Fail to request IRQ handler. ret(%d) irq(%d)\n",
					ret, data->irq[i]);
			goto out_with_dma_free;
		}
	}

	dev_info(data->dev, "Exynos TZASC driver probe done!\n");

	return 0;

out_with_dma_free:
	platform_set_drvdata(pdev, NULL);

	dma_free_coherent(data->dev,
			sizeof(struct tzasc_fail_info) *
			data->ch_num,
			data->fail_info,
			data->fail_info_pa);

	data->fail_info = NULL;
	data->fail_info_pa = 0;

	data->ch_num = 0;
	data->tzc_ver = 0;
	data->irqcnt = 0;
	data->info_flag = 0;

out:
	return ret;
}

static int exynos_tzasc_remove(struct platform_device *pdev)
{
	struct tzasc_info_data *data = platform_get_drvdata(pdev);
	int i;

	platform_set_drvdata(pdev, NULL);

	if (data->fail_info) {
		dma_free_coherent(data->dev,
				sizeof(struct tzasc_fail_info) *
				data->ch_num,
				data->fail_info,
				data->fail_info_pa);

		data->fail_info = NULL;
		data->fail_info_pa = 0;
	}

	for (i = 0; i < data->ch_num; i++)
		data->irq[i] = 0;

	data->ch_num = 0;
	data->tzc_ver = 0;
	data->irqcnt = 0;
	data->info_flag = 0;

	return 0;
}

static const struct of_device_id exynos_tzasc_of_match_table[] = {
	{ .compatible = "samsung,exynos-tzasc", },
	{ },
};
MODULE_DEVICE_TABLE(of, exynos_tzasc_of_match_table);

static struct platform_driver exynos_tzasc_driver = {
	.probe = exynos_tzasc_probe,
	.remove = exynos_tzasc_remove,
	.driver = {
		.name = "exynos-tzasc",
		.owner = THIS_MODULE,
		.of_match_table = of_match_ptr(exynos_tzasc_of_match_table),
	}
};

static int __init exynos_tzasc_init(void)
{
	return platform_driver_register(&exynos_tzasc_driver);
}

static void __exit exynos_tzasc_exit(void)
{
	platform_driver_unregister(&exynos_tzasc_driver);
}

//core_initcall(exynos_tzasc_init);
module_init(exynos_tzasc_init);
module_exit(exynos_tzasc_exit);

MODULE_DESCRIPTION("Exynos TrustZone Address Controller(TZASC) driver");
MODULE_AUTHOR("<junhosj.choi@samsung.com>");
MODULE_LICENSE("GPL");


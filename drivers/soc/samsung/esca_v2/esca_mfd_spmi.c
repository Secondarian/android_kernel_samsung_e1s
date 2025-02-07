/*
 * Copyright (c) 2016 Samsung Electronics Co., Ltd.
 *		http://www.samsung.com
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#include <linux/kernel.h>
#include <linux/of_address.h>
#include <linux/init.h>
#include <linux/platform_device.h>
#include <soc/samsung/esca.h>

#include "esca_mfd.h"

int exynos_esca_read_reg(struct device_node *esca_mfd_node, u8 sid, u16 type, u8 reg, u8 *dest)
{
	unsigned int channel_num, size;
	struct ipc_config config;
	unsigned int command[4] = {0,};
	int ret = 0;

	if (!esca_ipc_request_channel(esca_mfd_node, NULL, &channel_num, &size)) {
		config.cmd = command;
		config.cmd[0] = set_protocol(type, TYPE) | set_protocol(reg, REG);
		config.cmd[1] = set_protocol(FUNC_READ, FUNC) | set_protocol(sid, SID);

		config.response = true;
		config.indirection = false;

		ESCA_MFD_PRINT("%s - addr: 0x%03x\n",
				__func__, set_protocol(type, TYPE) | set_protocol(reg, REG));

		ret = esca_ipc_send_data(channel_num, &config);
		if (ret) {
			pr_err(ESCA_MFD_PREFIX "%s - esca_ipc_send_data fail.\n", __func__);
			return ret;
		}

		*dest = read_protocol(config.cmd[1], DEST);
		ret = read_protocol(config.cmd[1], RETURN);
		if (ret) {
			pr_err(ESCA_MFD_PREFIX "%s - APM's speedy_rx fail.\n", __func__);
			return ret;
		}

		ESCA_MFD_PRINT("%s - data = 0x%02x ret = 0x%02x\n",
						__func__, *dest, ret);

		esca_ipc_release_channel(esca_mfd_node, channel_num);
	} else {
		pr_err(ESCA_MFD_PREFIX "%s ipc request_channel fail, id:%u, size:%u\n",
				__func__, channel_num, size);
		ret = -EBUSY;
	}

	return ret;
}
EXPORT_SYMBOL_GPL(exynos_esca_read_reg);

int exynos_esca_bulk_read(struct device_node *esca_mfd_node, u8 sid, u16 type, u8 reg, int count, u8 *buf)
{
	unsigned int channel_num, size;
	struct ipc_config config;
	unsigned int command[4] = {0,};
	int i, ret = 0;

	if (!esca_ipc_request_channel(esca_mfd_node, NULL, &channel_num, &size)) {
		config.cmd = command;
		config.cmd[0] = set_protocol(type, TYPE) | set_protocol(reg, REG);
		config.cmd[1] = set_protocol(FUNC_BULK_READ, FUNC) | set_protocol(count, CNT) | set_protocol(sid, SID);
		config.response = true;
		config.indirection = false;

		ESCA_MFD_PRINT("%s - addr: 0x%03x\n",
				__func__, set_protocol(type, TYPE) | set_protocol(reg, REG));

		ret = esca_ipc_send_data(channel_num, &config);
		if (ret) {
			pr_err(ESCA_MFD_PREFIX "%s - esca_ipc_send_data fail.\n", __func__);
			return ret;
		}

		ret = read_protocol(config.cmd[1], RETURN);
		if (ret) {
			pr_err(ESCA_MFD_PREFIX "%s - APM's speedy_rx fail.\n", __func__);
			return ret;
		}

		for (i = 0; i < count; i++) {
			if (i < 4)
				buf[i] = read_bulk_protocol(config.cmd[2], BULK_VAL, i);
			else
				buf[i] = read_bulk_protocol(config.cmd[3], BULK_VAL , i - 4);
		}

		esca_ipc_release_channel(esca_mfd_node, channel_num);
	} else {
		pr_err(ESCA_MFD_PREFIX "%s ipc request_channel fail, id:%u, size:%u\n",
				__func__, channel_num, size);
		ret = -EBUSY;
	}

	return ret;
}
EXPORT_SYMBOL_GPL(exynos_esca_bulk_read);

int exynos_esca_write_reg(struct device_node *esca_mfd_node, u8 sid, u16 type, u8 reg, u8 value)
{
	unsigned int channel_num, size;
	struct ipc_config config;
	unsigned int command[4] = {0,};
	int ret = 0;

	if (!esca_ipc_request_channel(esca_mfd_node, NULL, &channel_num, &size)) {
		config.cmd = command;
		config.cmd[0] = set_protocol(type, TYPE) | set_protocol(reg, REG);
		config.cmd[1] = set_protocol(FUNC_WRITE, FUNC) | set_protocol(value, WRITE_VAL) | set_protocol(sid, SID);
		config.response = true;
		config.indirection = false;

		ESCA_MFD_PRINT("%s - addr: 0x%03x val: 0x%02x\n",
				__func__, set_protocol(type, TYPE) | set_protocol(reg, REG), value);

		ret = esca_ipc_send_data(channel_num, &config);
		if (ret) {
			pr_err(ESCA_MFD_PREFIX "%s - esca_ipc_send_data fail.\n", __func__);
			return ret;
		}

		ret = read_protocol(config.cmd[1], RETURN);
		if (ret) {
			pr_err(ESCA_MFD_PREFIX "%s - APM's speedy_tx fail.\n", __func__);
			return ret;
		}

		ESCA_MFD_PRINT("%s - read(ret) val: 0x%02x\n", __func__, ret);

		esca_ipc_release_channel(esca_mfd_node, channel_num);
	} else {
		pr_err(ESCA_MFD_PREFIX "%s ipc request_channel fail, id:%u, size:%u\n",
				__func__, channel_num, size);
		ret = -EBUSY;
	}

	return ret;
}
EXPORT_SYMBOL_GPL(exynos_esca_write_reg);

int exynos_esca_bulk_write(struct device_node *esca_mfd_node, u8 sid, u16 type, u8 reg, int count, u8 *buf)
{
	unsigned int channel_num, size;
	struct ipc_config config;
	unsigned int command[4] = {0,};
	int ret = 0;
	int i;

	if (!esca_ipc_request_channel(esca_mfd_node, NULL, &channel_num, &size)) {
		config.cmd = command;
		config.cmd[0] = set_protocol(type, TYPE) | set_protocol(reg, REG);
		config.cmd[1] = set_protocol(FUNC_BULK_WRITE, FUNC) | set_protocol(count, CNT) | set_protocol(sid, SID);
		config.response = true;
		config.indirection = false;

		ESCA_MFD_PRINT("%s - addr: 0x%03x\n cnt: 0x%02x\n",
				__func__, set_protocol(type, TYPE) | set_protocol(reg, REG), count);

		for (i = 0; i < count; i++) {
			if (i < 4)
				config.cmd[2] |= set_bulk_protocol(buf[i], BULK_VAL, i);
			else
				config.cmd[3] |= set_bulk_protocol(buf[i], BULK_VAL, i - 4);
		}

		ret = esca_ipc_send_data(channel_num, &config);
		if (ret) {
			pr_err(ESCA_MFD_PREFIX "%s - esca_ipc_send_data fail.\n", __func__);
			return ret;
		}

		ret = read_protocol(config.cmd[1], RETURN);
		if (ret) {
			pr_err(ESCA_MFD_PREFIX "%s - APM's speedy_tx fail.\n", __func__);
			return ret;
		}

		esca_ipc_release_channel(esca_mfd_node, channel_num);
	} else {
		pr_err(ESCA_MFD_PREFIX "%s ipc request_channel fail, id:%u, size:%u\n",
				__func__, channel_num, size);
		ret = -EBUSY;
	}

	return ret;
}
EXPORT_SYMBOL_GPL(exynos_esca_bulk_write);

int exynos_esca_update_reg(struct device_node *esca_mfd_node, u8 sid, u16 type, u8 reg, u8 value, u8 mask)
{
	unsigned int channel_num, size;
	struct ipc_config config;
	unsigned int command[4] = {0,};
	int ret = 0;

	if (!esca_ipc_request_channel(esca_mfd_node, NULL, &channel_num, &size)) {
		config.cmd = command;
		config.cmd[0] = set_protocol(type, TYPE) | set_protocol(reg, REG);
		config.cmd[1] = set_protocol(FUNC_UPDATE, FUNC)
				| set_protocol(value, UPDATE_VAL)
				| set_protocol(mask, UPDATE_MASK)
				| set_protocol(sid, SID);
		config.response = true;
		config.indirection = false;

		ESCA_MFD_PRINT("%s - addr: 0x%03x val: 0x%02x mask: 0x%02x\n",
				__func__, set_protocol(type, TYPE) | set_protocol(reg, REG), value, mask);

		ret = esca_ipc_send_data(channel_num, &config);
		if (ret) {
			pr_err(ESCA_MFD_PREFIX "%s - esca_ipc_send_data fail.\n", __func__);
			return ret;
		}

		ret = read_protocol(config.cmd[1], RETURN);
		if (ret) {
			if (ret == 1)
				pr_err(ESCA_MFD_PREFIX "%s - APM's speedy_rx fail.\n", __func__);
			else if (ret == 2)
				pr_err(ESCA_MFD_PREFIX "%s - APM's speedy_tx fail.\n", __func__);
			return ret;
		}

		esca_ipc_release_channel(esca_mfd_node, channel_num);
	} else {
		pr_err(ESCA_MFD_PREFIX "%s ipc request_channel fail, id:%u, size:%u\n",
				__func__, channel_num, size);
		ret = -EBUSY;
	}

	return ret;
}
EXPORT_SYMBOL_GPL(exynos_esca_update_reg);

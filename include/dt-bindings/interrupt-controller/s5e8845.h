/*
 * Copyright (c) 2023 Samsung Electronics Co., Ltd.
 *
 * Author: Jiss Jose <jiss.jose@samsung.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * Device Tree binding constants for S5E8845 interrupt controller.
*/

#ifndef _DT_BINDINGS_INTERRUPT_CONTROLLER_S5E_8845_H
#define _DT_BINDINGS_INTERRUPT_CONTROLLER_S5E_8845_H

#include <dt-bindings/interrupt-controller/arm-gic.h>

#define INTREQ__ALIVE_EINT0		0
#define INTREQ__ALIVE_EINT1		1
#define INTREQ__ALIVE_EINT2		2
#define INTREQ__ALIVE_EINT3		3
#define INTREQ__ALIVE_EINT4		4
#define INTREQ__ALIVE_EINT5		5
#define INTREQ__ALIVE_EINT6		6
#define INTREQ__ALIVE_EINT7		7
#define INTREQ__ALIVE_EINT8		8
#define INTREQ__ALIVE_EINT9		9
#define INTREQ__ALIVE_EINT10		10
#define INTREQ__ALIVE_EINT11		11
#define INTREQ__ALIVE_EINT12		12
#define INTREQ__ALIVE_EXT_INTC0		13
#define INTREQ__ALIVE_EXT_INTC1		14
#define INTREQ__ALIVE_EXT_INTC2		15
#define INTREQ__ALIVE_EXT_INTC3		16
#define INTREQ__ALIVE_EXT_INTC4		17
#define INTREQ__ALIVE_EXT_INTC5		18
#define INTREQ__ALIVE_EXT_INTC6		19
#define INTREQ__ALIVE_EXT_INTC7		20
#define INTREQ__ALIVE_EXT_INTC8		21
#define INTREQ__ALIVE_EXT_INTC9		22
#define INTREQ__ALIVE_EXT_INTC10		23
#define INTREQ__ALIVE_EXT_INTC11		24
#define INTREQ__ALIVE_EXT_INTC12		25
#define INTREQ__ALIVE_EXT_INTC13		26
#define INTREQ__ALIVE_EXT_INTC14		27
#define INTREQ__ALIVE_EXT_INTC15		28
#define INTREQ__ALIVE_EXT_INTC16		29
#define INTREQ__ALIVE_EXT_INTC17		30
#define INTREQ__ALIVE_GNSS_ACTIVE		31
#define INTREQ__ALIVE_WLBT_ACTIVE		32
#define INTREQ__CLKMON_MONCLK		33
#define INTREQ__CLKMON_REFSTUCK		34
#define INTREQ__COMB_NONSECURE_INTCOMB_VGPIO2AP		35
#define INTREQ__COMB_SFI_CE_NONSECURE_SYSREG_APM		36
#define INTREQ__COMB_SFI_UCE_NONSECURE_SYSREG_APM		37
#define INTREQ__DBGCORE_UART		38
#define INTREQ__I2C_ALIVE0		39
#define INTREQ__MAILBOX_APM2AP		40
#define INTREQ__MAILBOX_APM12AP		41
#define INTREQ__MAILBOX_ASM2AP		42
#define INTREQ__MAILBOX_CHUB2AP		43
#define INTREQ__MAILBOX_CP2AP_0		44
#define INTREQ__MAILBOX_CP2AP_1		45
#define INTREQ__MAILBOX_CP2AP_2		46
#define INTREQ__MAILBOX_CP2AP_3		47
#define INTREQ__MAILBOX_CP2AP_4		48
#define INTREQ__MAILBOX_DBGCORE2AP		49
#define INTREQ__MAILBOX_GNSS2AP		50
#define INTREQ__MAILBOX_WLAN2AP		51
#define INTREQ__MAILBOX_WLBT_PMU2AP		52
#define INTREQ__MAILBOX_WPAN2AP		53
#define INTREQ__MCT_ALIVE_IRQ_0		54
#define INTREQ__MCT_ALIVE_IRQ_1		55
#define INTREQ__MCT_ALIVE_IRQ_2		56
#define INTREQ__MCT_ALIVE_IRQ_3		57
#define INTREQ__MCT_ALIVE_IRQ_4		58
#define INTREQ__MCT_ALIVE_IRQ_5		59
#define INTREQ__MCT_ALIVE_IRQ_6		60
#define INTREQ__MCT_ALIVE_IRQ_7		61
#define INTREQ__MCT_ALIVE_IRQ_8		62
#define INTREQ__MCT_ALIVE_S_IRQ_0		63
#define INTREQ__MCT_ALIVE_S_IRQ_1		64
#define INTREQ__MCT_ALIVE_S_IRQ_2		65
#define INTREQ__MCT_ALIVE_S_IRQ_3		66
#define INTREQ__NOTIFY		67
#define INTREQ__RTC_0_ALARM_INT		68
#define INTREQ__RTC_0_TIC_INT_0		69
#define INTREQ__RTC_S_ALARM_INT		70
#define INTREQ__RTC_S_TIC_INT_0		71
#define INTREQ__S_MAILBOX_CP2AP		72
#define INTREQ__SPMI_MASTER_PMIC_0		73
#define INTREQ__SPMI_MASTER_PMIC_1		74
#define INTREQ__USI_ALIVE0		75
#define INTREQ__AUD_ABOX_GIC400_MCPU		76
#define INTREQ__AUD_WDT		77
#define INTREQ__SYSMMU_ABOX_S1_NS		78
#define INTREQ__SYSMMU_ABOX_S1_S		79
#define INTREQ__SYSMMU_ABOX_S2_NS		80
#define INTREQ__SYSMMU_ABOX_S2_S		81
#define INTREQ__EXT_INTE0		82
#define INTREQ__EXT_INTE1		83
#define INTREQ__EXT_INTH0_0		84
#define INTREQ__EXT_INTH0_1		85
#define INTREQ__EXT_INTH0_2		86
#define INTREQ__EXT_INTH0_3		87
#define INTREQ__EXT_INTH0_4		88
#define INTREQ__EXT_INTH0_5		89
#define INTREQ__EXT_INTH0_6		90
#define INTREQ__EXT_INTH0_7		91
#define INTREQ__EXT_INTH1_0		92
#define INTREQ__EXT_INTH1_1		93
#define INTREQ__EXT_INTH1_2		94
#define INTREQ__EXT_INTH1_3		95
#define INTREQ__I2C_CHUB1		96
#define INTREQ__I2C_CHUB2		97
#define INTREQ__I3C_CHUB		98
#define INTREQ__MAILBOX_AP_VTS		99
#define INTREQ__TIMER_CHUB		100
#define INTREQ__USI_CHUB0		101
#define INTREQ__USI_CHUB1		102
#define INTREQ__USI_CHUB2		103
#define INTREQ__USI_CHUB3		104
#define INTREQ__WDT_CHUB		105
#define INTREQ__WDT_VTS		106
#define INTRQ_PWM_CHUB_0		107
#define INTRQ_PWM_CHUB_1		108
#define INTREQ__CPUCL0_CTIIRQ_0		109
#define INTREQ__CPUCL0_CTIIRQ_1		110
#define INTREQ__CPUCL0_CTIIRQ_2		111
#define INTREQ__CPUCL0_CTIIRQ_3		112
#define INTREQ__CPUCL0_CTIIRQ_4		113
#define INTREQ__CPUCL0_CTIIRQ_5		114
#define INTREQ__CPUCL0_CTIIRQ_6		115
#define INTREQ__CPUCL0_CTIIRQ_7		116
#define INTREQ__CPUCL0_PMBIRQ_4		117
#define INTREQ__CPUCL0_PMBIRQ_5		118
#define INTREQ__CPUCL0_PMBIRQ_6		119
#define INTREQ__CPUCL0_PMBIRQ_7		120
#define INTRQ_PWM_CHUB_2		121
#define INTRQ_PWM_CHUB_3		122
#define INTREQ__EXT_INTM00		123
#define INTREQ__EXT_INTM01		124
#define INTREQ__EXT_INTM02		125
#define INTREQ__EXT_INTM03		126
#define INTREQ__EXT_INTM04		127
#define INTREQ__EXT_INTM05		128
#define INTREQ__EXT_INTM06		129
#define INTREQ__EXT_INTM07		130
#define INTREQ__EXT_INTM08		131
#define INTREQ__EXT_INTM09		132
#define INTREQ__EXT_INTM10		133
#define INTREQ__EXT_INTM11		134
#define INTREQ__EXT_INTM12		135
#define INTREQ__EXT_INTM13		136
#define INTREQ__EXT_INTM14		137
#define INTREQ__EXT_INTM15		138
#define INTREQ__EXT_INTM16		139
#define INTREQ__EXT_INTM17		140
#define INTREQ__EXT_INTM18		141
#define INTREQ__EXT_INTM19		142
#define INTREQ__EXT_INTM20		143
#define INTREQ__I2C_CMGP0		144
#define INTREQ__I2C_CMGP1		145
#define INTREQ__I2C_CMGP2		146
#define INTREQ__I2C_CMGP3		147
#define INTREQ__I2C_CMGP4		148
#define INTREQ__I3C_CMGP0		149
#define INTREQ__I3C_CMGP1		150
#define INTREQ__USI_CMGP0		151
#define INTREQ__USI_CMGP1		152
#define INTREQ__USI_CMGP2		153
#define INTREQ__USI_CMGP3		154
#define INTREQ__USI_CMGP4		155
#define CMU_CPUCL1_PLL_CTRL_USER_IRQ		156
#define INTREQ__CPUCL0_CLUSTERPMUIRQ		157
#define INTREQ__CPUCL0_COMMIRQ_0		158
#define INTREQ__CPUCL0_COMMIRQ_1		159
#define INTREQ__CPUCL0_COMMIRQ_2		160
#define INTREQ__CPUCL0_COMMIRQ_3		161
#define INTREQ__CPUCL0_COMMIRQ_4		162
#define INTREQ__CPUCL0_COMMIRQ_5		163
#define INTREQ__CPUCL0_COMMIRQ_6		164
#define INTREQ__CPUCL0_COMMIRQ_7		165
#define INTREQ__CPUCL0_ERRIRQ_0		166
#define INTREQ__CPUCL0_ERRIRQ_1		167
#define INTREQ__CPUCL0_ERRIRQ_2		168
#define INTREQ__CPUCL0_ERRIRQ_3		169
#define INTREQ__CPUCL0_ERRIRQ_4		170
#define INTREQ__CPUCL0_ERRIRQ_5		171
#define INTREQ__CPUCL0_ERRIRQ_6		172
#define INTREQ__CPUCL0_ERRIRQ_7		173
#define INTREQ__CPUCL0_ERRIRQ_8		174
#define INTREQ__CPUCL0_FAULTIRQ_0		175
#define INTREQ__CPUCL0_FAULTIRQ_1		176
#define INTREQ__CPUCL0_FAULTIRQ_2		177
#define INTREQ__CPUCL0_FAULTIRQ_3		178
#define INTREQ__CPUCL0_FAULTIRQ_4		179
#define INTREQ__CPUCL0_FAULTIRQ_5		180
#define INTREQ__CPUCL0_FAULTIRQ_6		181
#define INTREQ__CPUCL0_FAULTIRQ_7		182
#define INTREQ__CPUCL0_FAULTIRQ_8		183
#define INTREQ__CPUCL0_PMUIRQ_0		184
#define INTREQ__CPUCL0_PMUIRQ_1		185
#define INTREQ__CPUCL0_PMUIRQ_2		186
#define INTREQ__CPUCL0_PMUIRQ_3		187
#define INTREQ__CPUCL0_PMUIRQ_4		188
#define INTREQ__CPUCL0_PMUIRQ_5		189
#define INTREQ__CPUCL0_PMUIRQ_6		190
#define INTREQ__CPUCL0_PMUIRQ_7		191
#define INTREQ__OCP_REATOR_CPUCL0_0		192
#define INTREQ__OCP_REATOR_CPUCL0_1		193
#define INTREQ__OCP_REATOR_DSU		194
#define INTREQ__PPC_INSTRRET_LOWER_CPUCL0_0		195
#define INTREQ__PPC_INSTRRET_LOWER_CPUCL0_1		196
#define INTREQ__PPC_INSTRRET_UPPER_CPUCL0_0		197
#define INTREQ__PPC_INSTRRET_UPPER_CPUCL0_1		198
#define INTREQ__PPC_INSTRRUN_LOWER_CPUCL0_0		199
#define INTREQ__PPC_INSTRRUN_LOWER_CPUCL0_1		200
#define INTREQ__PPC_INSTRRUN_UPPER_CPUCL0_0		201
#define INTREQ__PPC_INSTRRUN_UPPER_CPUCL0_1		202
#define O_DDC_IRQ_CPUCL0		203
#define INTREQ__CSIS0		204
#define INTREQ__CSIS1		205
#define INTREQ__CSIS2		206
#define INTREQ__CSIS3		207
#define INTREQ__CSIS4		208
#define INTREQ__CSIS_DMA0		209
#define INTREQ__CSIS_DMA1		210
#define INTREQ__CSIS_DMA2		211
#define INTREQ__CSIS_DMA3		212
#define INTREQ__CSIS_TOP		213
#define INTREQ__NFI		214
#define INTREQ__OIS_FROM_CM4		215
#define INTREQ__OVERFLOW_CSIS_PDP		216
#define INTREQ__PDP0		217
#define INTREQ__PDP1		218
#define INTREQ__PDP2		219
#define INTREQ__PDP3		220
#define INTREQ__PDP4		221

//		222
#define INTREQ__TBASE		223
#define INTREQ__SECURE_LOG	224
#define INTREQ__RPMB		225
#define INTREQ__S2_LV3_TABLE_ALLOC		226
/*
		227
		228
		229
*/
#define INTREQ__PDP5		230
#define INTREQ__PDP6		231
#define INTREQ__PDP7		232
#define INTREQ__SENSOR_ABORT		233
#define INTREQ__SYSMMU_S0_CSIS_S1_NS		234
#define INTREQ__SYSMMU_S0_CSIS_S1_S		235
#define INTREQ__SYSMMU_S0_CSIS_S2_NS		236
#define INTREQ__SYSMMU_S0_CSIS_S2_S		237
#define INTREQ__WDTRESET_OIS_MCU		238
#define INTREQ__BYRP_0		239
#define INTREQ__BYRP_1		240
#define INTREQ__CSTAT_CH0_0		241
#define INTREQ__CSTAT_CH0_1		242
#define INTREQ__CSTAT_CH1_0		243
#define INTREQ__CSTAT_CH1_1		244
#define INTREQ__CSTAT_CH2_0		245
#define INTREQ__CSTAT_CH2_1		246
#define INTREQ_PPMU_D0_CSTAT_upper_or_normal		247
#define INTREQ_PPMU_D1_CSTAT_upper_or_normal		248
#define INTREQ__SYSMMU_S0_CSTAT_S1_NS		249
#define INTREQ__SYSMMU_S0_CSTAT_S1_S		250
#define INTREQ__SYSMMU_S0_CSTAT_S2_NS		251
#define INTREQ__SYSMMU_S0_CSTAT_S2_S		252
#define INTREQ__FROM_DNC_OCP_THROTT		253
#define INTREQ__FROM_DNC_SYSMMU_DNC_S0_O_STAGE1_NONSEC		254
#define INTREQ__FROM_DNC_SYSMMU_DNC_S0_O_STAGE1_SECURE		255
#define INTREQ__FROM_DNC_SYSMMU_DNC_S0_O_STAGE2_NONSEC		256
#define INTREQ__FROM_DNC_SYSMMU_DNC_S0_O_STAGE2_SECURE		257
#define INTREQ__FROM_DNC_SYSMMU_DNC_S1_O_STAGE1_NONSEC		258
#define INTREQ__FROM_DNC_SYSMMU_DNC_S1_O_STAGE1_SECURE		259
#define INTREQ__FROM_DNC_SYSMMU_DNC_S1_O_STAGE2_NONSEC		260
#define INTREQ__FROM_DNC_SYSMMU_DNC_S1_O_STAGE2_SECURE		261
#define INTREQ__FROM_DNC_TO_HOST_NS_0		262
#define INTREQ__FROM_DNC_TO_HOST_NS_1		263
#define INTREQ__FROM_DNC_TO_HOST_NS_2		264
#define INTREQ__FROM_DNC_TO_HOST_NS_3		265
#define INTREQ__FROM_DNC_TO_HOST_NS_4		266
#define INTREQ__FROM_DNC_TO_HOST_NS_5		267
#define INTREQ__FROM_DNC_TO_HOST_NS_6		268
#define INTREQ__FROM_DNC_TO_HOST_NS_7		269
#define INTREQ__FROM_DNC_TO_HOST_S_0		270
#define INTREQ__FROM_DNC_TO_HOST_S_1		271
#define INTREQ__FROM_DNC_TO_HOST_S_2		272
#define INTREQ__FROM_DNC_TO_HOST_S_3		273
#define INTREQ__FROM_DNC_TO_HOST_S_4		274
#define INTREQ__FROM_DNC_TO_HOST_S_5		275
#define INTREQ__FROM_DNC_TO_HOST_S_6		276
#define INTREQ__FROM_DNC_TO_HOST_S_7		277
#define INTREQ__DPU_DECON0_DQE_DIMMING_END		278
#define INTREQ__DPU_DECON0_DQE_DIMMING_START		279
#define INTREQ__DPU_DECON0_EXTRA		280
#define INTREQ__DPU_DECON0_FRAME_DONE		281
#define INTREQ__DPU_DECON0_FRAME_START		282
#define INTREQ__DPU_DECON0_MDNIE		283
#define INTREQ__DPU_DECON1_EXTRA		284
#define INTREQ__DPU_DECON1_FRAME_DONE		285
#define INTREQ__DPU_DECON1_FRAME_START		286
#define INTREQ__DPU_DMA_CGCTRL0		287
#define INTREQ__DPU_DMA_DSIMFC0		288
#define INTREQ__DPU_DMA_L0		289
#define INTREQ__DPU_DMA_L1		290
#define INTREQ__DPU_DMA_L2		291
#define INTREQ__DPU_DMA_L3		292
#define INTREQ__DPU_DMA_L4		293
#define INTREQ__DPU_DMA_L5		294
#define INTREQ__DPU_DMA_L6		295
#define INTREQ__DPU_DMA_L7		296
#define INTREQ__DPU_DMA_RCD0		297
#define INTREQ__DPU_DMA_WB		298
#define INTREQ__DPU_DPP_L0		299
#define INTREQ__DPU_DPP_L1		300
#define INTREQ__DPU_DPP_L2		301
#define INTREQ__DPU_DPP_L3		302
#define INTREQ__DPU_DPP_L4		303
#define INTREQ__DPU_DPP_L5		304
#define INTREQ__DPU_DPP_L6		305
#define INTREQ__DPU_DPP_L7		306
#define INTREQ__DPU_DSIM0		307
#define INTREQ__SYSMMU_DPU_S0_STAGE1_NONSEC		308
#define INTREQ__SYSMMU_DPU_S0_STAGE1_SECURE		309
#define INTREQ__SYSMMU_DPU_S0_STAGE2_NONSEC		310
#define INTREQ__SYSMMU_DPU_S0_STAGE2_SECURE		311
#define INTREQ__GPU_INT		312
#define INTREQ__HTU_G3D_INT		313
#define INTREQ__HTU_GNPU0		314
#define INTREQ__GNSS_PPMU_IRQ		315
#define INTREQ__GNSS_SW_INT		316
#define INTREQ__GNSS_WAKEUP_INT		317
#define INTREQ__GNSS_WDOG_RESET		318
#define INTREQ__GPIO_HSI_UFS		319
#define INTREQ__S2MPU_HSI_S0_S2_NS		320
#define INTREQ__S2MPU_HSI_S0_S2_S		321
#define INTREQ__UFS_EMBD		322
#define INTREQ__UFS_EMBD_VS		323
#define INTREQ__FROM_ICPU_TO_HOST_0		324
#define INTREQ__FROM_ICPU_TO_HOST_1		325
#define INTREQ__FROM_ICPU_TO_HOST_2		326
#define INTREQ__FROM_ICPU_TO_HOST_3		327
#define INTREQ__FROM_ICPU_TO_HOST_4		328
#define INTREQ__FROM_ICPU_TO_HOST_5		329
#define INTREQ__FROM_ICPU_TO_HOST_6		330
#define INTREQ__FROM_ICPU_TO_HOST_7		331
#define INTREQ__FROM_ICPU_TO_HOST_8		332
#define INTREQ__FROM_ICPU_TO_HOST_9		333
#define INTREQ__FROM_ICPU_TO_HOST_10		334
#define INTREQ__FROM_ICPU_TO_HOST_11		335
#define INTREQ__PPMU_ICPU		336
#define INTREQ__SYSMMU_S0_ICPU_S1_NS		337
#define INTREQ__SYSMMU_S0_ICPU_S1_S		338
#define INTREQ__SYSMMU_S0_ICPU_S2_NS		339
#define INTREQ__SYSMMU_S0_ICPU_S2_S		340
#define INTREQ__GDC_L_IRQ_0		341
#define INTREQ__GDC_L_IRQ_1		342
#define INTREQ__GDC_O_IRQ_0		343
#define INTREQ__GDC_O_IRQ_1		344
#define INTREQ__JPEG		345
#define INTREQ__LME_O_INT_0		346
#define INTREQ__LME_O_INT_1		347
#define INTREQ__M2M		348
#define INTREQ_PPMU_D0_M2M_upper_or_normal		349
#define INTREQ_PPMU_D1_M2M_upper_or_normal		350
#define INTREQ__SYSMMU_S0_M2M_STAGE1_NONSEC		351
#define INTREQ__SYSMMU_S0_M2M_STAGE1_SECURE		352
#define INTREQ__SYSMMU_S0_M2M_STAGE2_NONSEC		353
#define INTREQ__SYSMMU_S0_M2M_STAGE2_SECURE		354
#define INTREQ__FG		355
#define INTREQ__MFC		356
#define INTREQ__SYSMMU_MFC_S0_interrupt_s1_ns		357
#define INTREQ__SYSMMU_MFC_S0_interrupt_s1_s		358
#define INTREQ__SYSMMU_MFC_S0_interrupt_s2_ns		359
#define INTREQ__SYSMMU_MFC_S0_interrupt_s2_s		360
#define INTREQ__SYSMMU_MFC_S1_interrupt_s1_ns		361
#define INTREQ__SYSMMU_MFC_S1_interrupt_s1_s		362
#define INTREQ__SYSMMU_MFC_S1_interrupt_s2_ns		363
#define INTREQ__SYSMMU_MFC_S1_interrupt_s2_s		364
#define INTREQ__DMC_ECC_CORERR_MIF0		365
#define INTREQ__DMC_ECC_UNCORERR_MIF0		366
#define INTREQ__DMC_PPMPINT_MIF0		367
#define INTREQ__DMC_TEMPERR_MIF0		368
#define INTREQ__DMC_TEMPHOT_MIF0		369
#define INTREQ__DMC_TZCINT_MIF0		370
#define INTREQ__PPMU_MIF_MIF0		371
#define INTREQ__DMC_ECC_CORERR_MIF1		372
#define INTREQ__DMC_ECC_UNCORERR_MIF1		373
#define INTREQ__DMC_PPMPINT_MIF1		374
#define INTREQ__DMC_TEMPERR_MIF1		375
#define INTREQ__DMC_TEMPHOT_MIF1		376
#define INTREQ__DMC_TZCINT_MIF1		377
#define INTREQ__PPMU_MIF_MIF1		378
#define INTREQ_CPALV_GPIO		379
#define INTREQ_MODEM_PPMU		380
#define INTREQ_RESET_REQ		381
#define INTREQ_WOW_DVFS		382
#define INTREQ_CPU2DRAM_PPMU_INT		383
#define INTREQ__NOCL0_CON_ALIVE_INTERRUPT		384
#define INTREQ_S2MPU_G3D_S2_NS		385
#define INTREQ_S2MPU_G3D_S2_S		386
#define INTREQ_SCI_Lite_INT_AST		387
#define INTREQ_SYSMMU_MODEM_S1_NS		388
#define INTREQ_SYSMMU_MODEM_S1_S		389
#define INTREQ_SYSMMU_MODEM_S2_NS		390
#define INTREQ_SYSMMU_MODEM_S2_S		391
#define INTREQ_TREX_PPMU		392
#define INTREQ__WOW_DVFS_SMC_GIC		393
#define INTREQ__S2MPU_S0_ALIVE_O_INTERRUPT_STAGE2_NONSEC		394
#define INTREQ__S2MPU_S0_ALIVE_O_INTERRUPT_STAGE2_SECURE		395
#define INTREQ__GPIO_PERIC		396
#define INTREQ__GPIO_PERICMMC		397
#define INTREQ__I3C00_OIS		398
#define INTREQ__MMC_CARD		399
#define INTREQ__PDMA_PERIC		400
#define INTREQ__PPMU_D_PERIC		401
#define INTREQ__S2MPU_S0_PERIC_S2_NS		402
#define INTREQ__S2MPU_S0_PERIC_S2_S		403
#define INTREQ__SPDMA_PERIC		404
#define INTREQ__UART_DBG		405
#define INTREQ__USI00_I2C		406
#define INTREQ__USI00_USI		407
#define INTREQ__USI01_I2C		408
#define INTREQ__USI01_USI		409
#define INTREQ__USI02_I2C		410
#define INTREQ__USI02_USI		411
#define INTREQ__USI03_I2C		412
#define INTREQ__USI03_USI		413
#define INTREQ__USI04_I2C		414
#define INTREQ__USI04_USI		415
#define INTREQ__USI05_I2C		416
#define INTREQ__USI09_USI_OIS		417
#define INTREQ__USI10_USI_OIS		418
#define INTREQ_MAILBOX_TO_AP		419
#define INTREQ__PPMU_PSP_O_interrupt_upper_or_normal		420
#define INTREQ_RTIC		421
#define INTREQ_S2MPU_S2_NONSECURE		422
#define INTREQ_S2MPU_S2_SECURE		423
#define INTREQ__MCFP_0		424
#define INTREQ__MCFP_1		425
#define INTREQ__RGBP_0		426
#define INTREQ__RGBP_1		427
#define INTREQ__SYSMMU_S0_RGBP_S1_NS		428
#define INTREQ__SYSMMU_S0_RGBP_S1_S		429
#define INTREQ__SYSMMU_S0_RGBP_S2_NS		430
#define INTREQ__SYSMMU_S0_RGBP_S2_S		431
#define INTREQ__S2MPU_USB_S0_S2_NS		432
#define INTREQ__S2MPU_USB_S0_S2_S		433
#define INTREQ__USB2_REMOTE_CONNECT_GIC		434
#define INTREQ__USB2_REMOTE_TIMER_GIC		435
#define INTREQ__USB2_REMOTE_WAKEUP_GIC		436
#define INTREQ__USB20DRD_GIC_0		437
#define INTREQ__USB20DRD_GIC_1		438
#define INTREQ__USB20DRD_REWA_WAKEUP_REQ		439
#define INTREQ__USB20_PHY_FSVPLUS_MINUS_GIC		440
#define INTREQ__GPIO_USI		441
#define INTREQ__USI06_I2C		442
#define INTREQ__USI06_USI		443
#define INTREQ__USI07_I2C		444
#define INTREQ__USI07_USI		445
#define INTREQ__USI08_I2C		446
#define WB2AP_CFG_REQ		447
#define WB2AP_O_DBUS_INTERRUPT_STAGE2_NONSEC		448
#define WB2AP_O_DBUS_INTERRUPT_STAGE2_SECURE		449
#define WB2AP_O_LPBUS_INTERRUPT_STAGE2_NONSEC		450
#define WB2AP_O_LPBUS_INTERRUPT_STAGE2_SECURE		451
#define WB2AP_WDOG_RESET_REQ_IRQ		452
#define INTREQ__MCSC_0		453
#define INTREQ__MCSC_1		454
#define INTREQ__SYSMMU_YUVP_S0_S1_NS		455
#define INTREQ__SYSMMU_YUVP_S0_S1_S		456
#define INTREQ__SYSMMU_YUVP_S0_S2_NS		457
#define INTREQ__SYSMMU_YUVP_S0_S2_S		458
#define INTREQ__YUVP_0		459
#define INTREQ__YUVP_1		460
#define INTREQ__OR4_TREX_debugInterrupt		470
#define INTREQ__PWM4		471
#define INTREQ__PWM3		472
#define INTREQ__PWM2		473
#define INTREQ__PWM1		474
#define INTREQ__PWM0		475
#define INTREQ__TMU		476
#define INTREQ__WDT1		477
#define INTREQ__WDT0		478
#define INTREQ__OTP_CON_TOP		479

#endif /* _DT_BINDINGS_INTERRUPT_CONTROLLER_S5E_8845_H */
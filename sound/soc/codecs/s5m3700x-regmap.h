/*
 * sound/soc/codec/s5m3700x-regmap.h
 *
 * ALSA SoC Audio Layer - Samsung Codec Driver
 *
 * Copyright (C) 2021 Samsung Electronics
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#ifndef _S5M3700X_REGMAP_H
#define _S5M3700X_REGMAP_H

/**
 * struct reg_default - Default value for a register.
 *
 * @reg: Register address.
 * @def: Register default value.
 *
 * We use an array of structs rather than a simple array as many modern devices
 * have very sparse register maps.
 */

/* HW Reset Register */
static struct reg_default s5m3700x_reg_defaults[] = {
	/* IRQ and Status */
	{S5M3700X_008_IRQ1M,							0xFF},
	{S5M3700X_009_IRQ2M,							0xFF},
	{S5M3700X_00A_IRQ3M,							0xFF},
	{S5M3700X_00B_IRQ4M,							0xFF},
	{S5M3700X_00C_IRQ5M,							0xFF},
	{S5M3700X_00D_IRQ6M,							0xFF},

	/* Clock and Reset */
	{S5M3700X_010_CLKGATE0,							0x00},
	{S5M3700X_011_CLKGATE1,							0x00},
	{S5M3700X_012_CLKGATE2, 						0x00},
	{S5M3700X_013_CLKGATE3, 						0x3F},
	{S5M3700X_014_RESETB0, 							0x83},
	{S5M3700X_015_RESETB1, 							0x00},
	{S5M3700X_016_CLK_MODE_SEL1, 					0x04},
	{S5M3700X_017_CLK_MODE_SEL2, 					0x08},
	{S5M3700X_018_PWAUTO_AD, 						0x00},
	{S5M3700X_019_PWAUTO_DA, 						0x00},

	/* Reserved for SW Operation */
	{S5M3700X_01E_CHOP1,							0x00},
	{S5M3700X_01F_CHOP2, 							0x00},

	/* Digital Audio Interface */
	{S5M3700X_020_IF_FORM1,							0x00},
	{S5M3700X_021_IF_FORM2, 						0x18},
	{S5M3700X_022_IF_FORM3, 						0x40},
	{S5M3700X_023_IF_FORM4, 						0xE4},
	{S5M3700X_024_IF_FORM5, 						0x10},
	{S5M3700X_025_IF_LOOPBACK, 						0x80},
	{S5M3700X_026_IF_CK0, 							0x00},
	{S5M3700X_027_IF_CK1, 							0x00},
	{S5M3700X_028_IF_CK2, 							0x00},
	{S5M3700X_029_IF_FORM6, 						0x00},
	{S5M3700X_02F_DMIC_ST, 							0x00},

	/* Recording path Digital Setting */
	{S5M3700X_030_ADC1, 							0x00},
	{S5M3700X_031_ADC2, 							0x00},
	{S5M3700X_032_ADC3, 							0xB0},
	{S5M3700X_033_ADC4, 							0x00},
	{S5M3700X_034_AD_VOLL, 							0x54},
	{S5M3700X_035_AD_VOLR, 							0x54},
	{S5M3700X_036_AD_VOLC, 							0x54},
	{S5M3700X_037_AD_HPF, 							0x48},
	{S5M3700X_038_AD_TRIM1, 						0x05},
	{S5M3700X_039_AD_TRIM2, 						0x03},
	{S5M3700X_03A_AD_VOL, 							0x00},
	{S5M3700X_03B_AD_NS_DET0, 						0x00},
	{S5M3700X_03C_AD_NS_DET1, 						0x04},
	{S5M3700X_03D_AD_OFFSETL, 						0x00},
	{S5M3700X_03E_AD_OFFSETR, 						0x00},
	{S5M3700X_03F_AD_OFFSETC, 						0x00},

	/* Playback path Digital Setting */
	{S5M3700X_040_PLAY_MODE, 						0x04},
	{S5M3700X_041_PLAY_VOLL, 						0x54},
	{S5M3700X_042_PLAY_VOLR, 						0x54},
	{S5M3700X_044_PLAY_MIX0, 						0x00},
	{S5M3700X_045_PLAY_MIX1, 						0x04},
	{S5M3700X_046_PLAY_MIX2, 						0x00},
	{S5M3700X_047_TRIM_DAC0, 						0xF7},
	{S5M3700X_048_TRIM_DAC1, 						0x4F},
	{S5M3700X_049_RSVD, 							0x00},
	{S5M3700X_04A_RSVD, 							0x00},
	{S5M3700X_04B_OFFSET_CTR, 						0x00},
	{S5M3700X_04C_HSYS_CP2_32, 						0x00},
	{S5M3700X_04D_HSYS_CP2_16, 						0x00},
	{S5M3700X_04E_HSYS_CP2_6, 						0x00},
	{S5M3700X_04F_HSYS_CP2_SIGN, 					0x85},

	/* Adaptive Volume Control */
	{S5M3700X_050_AVC1, 							0x03},
	{S5M3700X_051_AVC2, 							0x6A},
	{S5M3700X_052_AVC3, 							0x1A},
	{S5M3700X_053_AVC4, 							0x80},
	{S5M3700X_054_AVC5, 							0x89},
	{S5M3700X_055_AVC6, 							0x05},
	{S5M3700X_056_AVC7, 							0x05},
	{S5M3700X_057_AVC8, 							0x00},
	{S5M3700X_058_AVC9, 							0x00},
	{S5M3700X_059_AVC10, 							0x00},
	{S5M3700X_05A_AVC11, 							0x0A},
	{S5M3700X_05B_AVC12, 							0x56},
	{S5M3700X_05C_AVC13, 							0x00},
	{S5M3700X_05D_AVC14, 							0x22},
	{S5M3700X_05E_AVC15, 							0x00},
	{S5M3700X_05F_AVC16, 							0x00},

	{S5M3700X_060_AVC17, 							0x00},
	{S5M3700X_061_AVC18, 							0x00},
	{S5M3700X_062_AVC19, 							0x00},
	{S5M3700X_063_AVC20, 							0x00},
	{S5M3700X_064_AVC21, 							0x00},
	{S5M3700X_065_AVC22, 							0x1F},
	{S5M3700X_066_AVC23, 							0x1F},
	{S5M3700X_067_AVC24,							0x00},
	{S5M3700X_068_AVC25, 							0x08},
	{S5M3700X_069_AVC26, 							0x1F},
	{S5M3700X_06A_AVC27, 							0x60},
	{S5M3700X_06B_AVC28, 							0x00},
	{S5M3700X_06C_AVC29, 							0x00},
	{S5M3700X_06D_AVC30, 							0x00},
	{S5M3700X_06E_AVC31, 							0x03},
	{S5M3700X_06F_AVC32, 							0x1F},

	{S5M3700X_070_AVC33, 							0x93},
	{S5M3700X_071_AVC34, 							0x18},
	{S5M3700X_072_AVC35, 							0xDD},
	{S5M3700X_073_AVC36, 							0x17},
	{S5M3700X_074_AVC37, 							0xE9},
	{S5M3700X_075_AVC38, 							0x00},
	{S5M3700X_076_AVC39, 							0x00},
	{S5M3700X_077_AVC40, 							0x4B},
	{S5M3700X_078_AVC41, 							0xFF},
	{S5M3700X_079_AVC42, 							0xFF},
	{S5M3700X_07A_AVC43, 							0xC0},
	{S5M3700X_07B_AVC44, 							0x00},
	{S5M3700X_07C_OCPCTRL0, 						0x00},
	{S5M3700X_07D_OCPCTRL1, 						0xCC},
	{S5M3700X_07E_AVC45, 							0x40},
	{S5M3700X_07F_AVC46, 							0x6E},

	/* IRQ for LV */
	{S5M3700X_089_IRQ1M, 							0xFF},
	{S5M3700X_08A_IRQ2M, 							0xFF},
	{S5M3700X_08B_IRQ3M, 							0xFF},
	{S5M3700X_08C_IRQ4M, 							0xFF},
	{S5M3700X_08D_IRQ5M, 							0xFF},
	{S5M3700X_08E_IRQ6M, 							0xFF},

	/* Digital DSM Control */
	{S5M3700X_093_DSM_CON1, 						0x52},
	{S5M3700X_094_DSM_CON2, 						0x00},
	{S5M3700X_095_DSM_CON3, 						0x01},
	{S5M3700X_096_DSM_CON4, 						0x00},
	{S5M3700X_097_CP2_HOLD, 						0x0A},
	{S5M3700X_098_GPIO1_CON, 						0x20},
	{S5M3700X_099_GPIO2_CON, 						0x20},
	{S5M3700X_09A_GPIO3_CON, 						0x20},
	{S5M3700X_09B_DSM_MONL, 						0x00},
	{S5M3700X_09C_DSM_MONR, 						0x00},
	{S5M3700X_09D_AVC_DWA, 							0x46},
	{S5M3700X_09E_GPIO123_CON, 						0x00},

	/* Auto SEQ in Detail */
	{S5M3700X_0A0_AMU_CTR_CM1, 						0x55},
	{S5M3700X_0A1_AMU_CTR_CM2, 						0x56},
	{S5M3700X_0A2_AMU_CTR_CM3, 						0x14},
	{S5M3700X_0A3_AMU_CTR_RCV1, 					0x84},
	{S5M3700X_0A4_AMU_CTR_RCV2, 					0x55},
	{S5M3700X_0A5_AMU_CTR_RCV3, 					0x46},
	{S5M3700X_0A6_AMU_CTR_HP1, 						0x84},
	{S5M3700X_0A7_AMU_CTR_HP2, 						0x55},
	{S5M3700X_0A8_AMU_CTR_HP3, 						0x95},
	{S5M3700X_0A9_AMU_CTR_HP4, 						0x55},
	{S5M3700X_0AA_AMU_CTR_HP5, 						0x55},
	{S5M3700X_0AB_AMU_CTR_HP6, 						0x55},
	{S5M3700X_0AC_AMU_CTR_HP7, 						0x6A},
	{S5M3700X_0AD_AMU_CTR_LINE1, 					0x24},
	{S5M3700X_0AE_AMU_CTR_LINE2, 					0x55},
	{S5M3700X_0AF_BST_CTR, 							0x00},

	{S5M3700X_0B0_ODSEL1, 							0x00},
	{S5M3700X_0B1_ODSEL2, 							0x00},
	{S5M3700X_0B2_ODSEL3, 							0x00},
	{S5M3700X_0B3_ODSEL4, 							0x00},
	{S5M3700X_0B4_ODSEL5, 							0x00},
	{S5M3700X_0B5_ODSEL6, 							0x00},
	{S5M3700X_0B6_ODSEL7, 							0x00},
	{S5M3700X_0B7_ODSEL8, 							0x00},
	{S5M3700X_0B8_ODSEL9, 							0x00},
	{S5M3700X_0B9_ODSEL10, 							0x00},
	{S5M3700X_0BA_ODSEL11, 							0x00},
	{S5M3700X_0BB_ODSEL12, 							0x02},
	{S5M3700X_0BC_AMU_CTR_CP1, 						0x33},
	{S5M3700X_0BD_AMU_CTR_CP2, 						0x36},
	{S5M3700X_0BE_AMU_CTR_CP3, 						0x36},

	/* HMU Control */
	{S5M3700X_0C0_ACTR_JD1, 						0x00},
	{S5M3700X_0C1_ACTR_JD2, 						0x37},
	{S5M3700X_0C2_ACTR_JD3, 						0x77},
	{S5M3700X_0C3_ACTR_JD4, 						0x31},
	{S5M3700X_0C4_ACTR_JD5, 						0x60},
	{S5M3700X_0C5_ACTR_MCB1, 						0xD0},
	{S5M3700X_0C6_ACTR_MCB2, 						0x00},
	{S5M3700X_0C7_ACTR_MCB3, 						0x00},
	{S5M3700X_0C8_ACTR_MCB4, 						0x0F},
	{S5M3700X_0C9_ACTR_MCB5, 						0xFF},
	{S5M3700X_0CA_ACTR_IMP1, 						0x00},
	{S5M3700X_0CB_ACTR_IMP2, 						0x00},
	{S5M3700X_0CC_ACTR_IMP3, 						0x00},
	{S5M3700X_0CD_ACTR_IMP4, 						0x07},

	{S5M3700X_0D0_DCTR_CM, 							0x00},
	{S5M3700X_0D1_DCTR_TEST1, 						0x00},
	{S5M3700X_0D2_DCTR_TEST2, 						0x00},
	{S5M3700X_0D3_DCTR_TEST3, 						0x00},
	{S5M3700X_0D4_DCTR_TEST4, 						0x00},
	{S5M3700X_0D5_DCTR_TEST5, 						0x00},
	{S5M3700X_0D6_DCTR_TEST6, 						0x00},
	{S5M3700X_0D7_DCTR_TEST7, 						0x00},
	{S5M3700X_0D8_DCTR_DBNC1, 						0x90},
	{S5M3700X_0D9_DCTR_DBNC2, 						0x90},
	{S5M3700X_0DA_DCTR_DBNC3, 						0x90},
	{S5M3700X_0DB_DCTR_DBNC4, 						0x90},
	{S5M3700X_0DC_DCTR_DBNC5, 						0x90},
	{S5M3700X_0DD_DCTR_DBNC6, 						0x03},
	{S5M3700X_0DE_DCTR_DLY1, 						0x00},
	{S5M3700X_0DF_DCTR_DLY2, 						0x40},

	{S5M3700X_0E0_DCTR_FSM1, 						0x03},
	{S5M3700X_0E1_DCTR_FSM2, 						0x01},
	{S5M3700X_0E2_DCTR_FSM3, 						0x80},
	{S5M3700X_0E3_DCTR_FSM4, 						0x00},
	{S5M3700X_0E4_DCTR_FSM5, 						0x08},
	{S5M3700X_0E5_DCTR_FSM6, 						0x00},
	{S5M3700X_0E6_DCTR_GP, 							0xAA},
	{S5M3700X_0E7_DCTR_IMP1, 						0x03},
	{S5M3700X_0E8_DCTR_IMP2, 						0x00},
	{S5M3700X_0E9_DCTR_IMP3, 						0x02},
	{S5M3700X_0EA_DCTR_IMP4, 						0x2B},
	{S5M3700X_0EB_DCTR_IMP5, 						0x13},
	{S5M3700X_0EC_DCTR_IMP6, 						0x31},
	{S5M3700X_0ED_DCTR_IMP7, 						0x03},
	{S5M3700X_0EE_ACTR_ETC1, 						0x04},
	{S5M3700X_0EF_ACTR_ETC2, 						0x00},

	{S5M3700X_0F0_STATUS1, 							0x00},
	{S5M3700X_0F1_STATUS2, 							0x00},
	{S5M3700X_0F2_STATUS3, 							0x00},
	{S5M3700X_0F3_STATUS4, 							0x00},
	{S5M3700X_0F4_STATUS5, 							0x00},
	{S5M3700X_0F5_STATUS6, 							0x00},
	{S5M3700X_0F7_STATUS8, 							0x00},
	{S5M3700X_0F8_STATUS9, 							0x00},
	{S5M3700X_0F9_STATUS10, 						0x00},
	{S5M3700X_0FA_STATUS11, 						0x00},
	{S5M3700X_0FB_STATUS12, 						0x00},
	{S5M3700X_0FC_STATUS13, 						0x00},
	{S5M3700X_0FD_ACTR_GP, 							0x00},
	{S5M3700X_0FE_DCTR_GP1, 						0x02},
	{S5M3700X_0FF_DCTR_GP2, 						0x24},

	/* Analog Ref */
	{S5M3700X_104_CTRL_CP, 							0x20},
	{S5M3700X_105_CTRL_CP2_1, 						0x07},
	{S5M3700X_106_CTRL_CP2_2, 						0x00},
	{S5M3700X_107_CTRL_CP2_3, 						0xD3},

	/* VTS-ADC Control */
	{S5M3700X_108_PD_VTS, 							0x00},
	{S5M3700X_109_CTRL_VTS1, 						0x44},
	{S5M3700X_10A_CTRL_VTS2, 						0x44},
	{S5M3700X_10B_CTRL_VTS3, 						0xCC},
	{S5M3700X_10D_CTRL_VTS5, 						0x00},

	/* Recording path Analog Setting */
	{S5M3700X_110_BST_PDB, 							0x00},
	{S5M3700X_111_BST1, 							0x10},
	{S5M3700X_112_BST2, 							0x10},
	{S5M3700X_113_BST3, 							0x15},
	{S5M3700X_114_BST4, 							0x15},
	{S5M3700X_115_DSM1, 							0x1F},
	{S5M3700X_116_DSMC_1, 							0x80},
	{S5M3700X_117_DSM2, 							0x15},
	{S5M3700X_118_DSMC_2, 							0x05},
	{S5M3700X_119_DSM3, 							0x10},
	{S5M3700X_11A_DSMC3, 							0xE0},
	{S5M3700X_11B_DSMC4, 							0x87},
	{S5M3700X_11C_BSTC, 							0x00},
	{S5M3700X_11D_BST_OP, 							0x00},
	{S5M3700X_11E_CTRL_MIC_I1, 						0x48},
	{S5M3700X_11F_CTRL_MIC_I2, 						0x48},
	{S5M3700X_120_CTRL_MIC_I3, 						0x48},
	{S5M3700X_121_CTRL_MIC_I4, 						0x40},
	{S5M3700X_122_BST4PN, 							0x00},
	{S5M3700X_124_AUTO_DWA, 						0x00},
	{S5M3700X_125_RSVD, 							0x00},

	/* Playback path Analog Setting */
	{S5M3700X_130_PD_IDAC1, 						0x00},
	{S5M3700X_131_PD_IDAC2, 						0xC0},
	{S5M3700X_132_PD_IDAC3, 						0x80},
	{S5M3700X_135_PD_IDAC4, 						0xC3},
	{S5M3700X_138_PD_HP, 							0x00},
	{S5M3700X_139_PD_SURGE, 						0x00},
	{S5M3700X_13A_POP_HP, 							0x61},
	{S5M3700X_13B_OCP_HP, 							0x00},
	{S5M3700X_13F_HP_AVOLL, 						0x18},
	{S5M3700X_140_HP_AVOLR, 						0x18},
	{S5M3700X_142_REF_SURGE, 						0x67},
	{S5M3700X_143_CTRL_OVP1, 						0x02},
	{S5M3700X_144_EN_SURGE, 						0x00},
	{S5M3700X_145_CTRL_OVP2, 						0x02},
	{S5M3700X_149_PD_EP, 							0xC0},
	{S5M3700X_14A_PD_LO, 							0xC0},
	{S5M3700X_14C_EP_AVOL, 							0x14},
	{S5M3700X_14D_LINE_AVOL, 						0x14},

	/* Analog Clock Control */
	{S5M3700X_150_AD_CLK0, 							0x10},
	{S5M3700X_151_AD_CLK1, 							0x00},
	{S5M3700X_152_DA_CLK, 							0x00},
	{S5M3700X_153_DA_CP0, 							0xBE},
	{S5M3700X_154_DA_CP1, 							0x50},
	{S5M3700X_155_DA_CP2, 							0xBE},
	{S5M3700X_156_DA_CP3, 							0x33},

	/* Analog Read Register */
	{S5M3700X_180_READ_0, 							0x00},
	{S5M3700X_181_READ_1, 							0x00},
	{S5M3700X_182_READ_2, 							0x00},
	{S5M3700X_183_READ_3, 							0x00},
	{S5M3700X_184_READ_4, 							0x00},
	{S5M3700X_185_READ_5, 							0x00},
	{S5M3700X_186_READ_6, 							0x00},
	{S5M3700X_187_READ_7, 							0x00},
	{S5M3700X_188_READ_8, 							0x00},
	{S5M3700X_189_READ_9, 							0x00},
	{S5M3700X_18A_READ_10, 							0x00},
	{S5M3700X_18B_READ_11, 							0x00},
	{S5M3700X_18C_READ_12, 							0x00},
	{S5M3700X_18D_READ_13, 							0x00},
	{S5M3700X_18E_READ_14, 							0x00},
	{S5M3700X_18F_READ_15, 							0x00},
	{S5M3700X_190_READ_16, 							0x00},
	{S5M3700X_191_READ_17, 							0x00},
	{S5M3700X_192_READ_18, 							0x00},
	{S5M3700X_193_READ_19, 							0x00},
	{S5M3700X_194_READ_20, 							0x00},
	{S5M3700X_195_READ_21, 							0x00},

	/* OTP Register for OFFSET */
	{S5M3700X_200_HP_OFFSET_L0,						0x00},
	{S5M3700X_201_HP_OFFSET_L1,						0x00},
	{S5M3700X_202_HP_OFFSET_L2,						0x00},
	{S5M3700X_203_HP_OFFSET_L3,						0x00},
	{S5M3700X_204_HP_OFFSET_L4,						0x00},
	{S5M3700X_205_HP_OFFSET_L5,						0x00},
	{S5M3700X_206_HP_OFFSET_L6,						0x00},
	{S5M3700X_207_HP_OFFSET_L7,						0x00},
	{S5M3700X_208_HP_OFFSET_L8,						0x00},
	{S5M3700X_209_HP_OFFSET_L9,						0x00},
	{S5M3700X_20A_HP_OFFSET_L10,					0x00},
	{S5M3700X_20B_HP_OFFSET_L11,					0x00},
	{S5M3700X_20C_HP_OFFSET_L12,					0x00},
	{S5M3700X_20D_HP_OFFSET_L13,					0x00},
	{S5M3700X_20E_HP_OFFSET_L14,					0x00},
	{S5M3700X_20F_HP_OFFSET_L15,					0x00},
	{S5M3700X_210_HP_OFFSET_L16,					0x00},
	{S5M3700X_211_HP_OFFSET_L17,					0x00},
	{S5M3700X_212_HP_OFFSET_L18,					0x00},
	{S5M3700X_213_HP_OFFSET_L19,					0x00},
	{S5M3700X_214_HP_OFFSET_L20,					0x00},
	{S5M3700X_215_HP_OFFSET_L21,					0x00},
	{S5M3700X_216_HP_OFFSET_L22,					0x00},
	{S5M3700X_217_HP_OFFSET_L23,					0x00},
	{S5M3700X_218_HP_OFFSET_L24,					0x00},

	{S5M3700X_219_HP_OFFSET_R0,						0x00},
	{S5M3700X_21A_HP_OFFSET_R1,						0x00},
	{S5M3700X_21B_HP_OFFSET_R2,						0x00},
	{S5M3700X_21C_HP_OFFSET_R3,						0x00},
	{S5M3700X_21D_HP_OFFSET_R4,						0x00},
	{S5M3700X_21E_HP_OFFSET_R5,						0x00},
	{S5M3700X_21F_HP_OFFSET_R6,						0x00},
	{S5M3700X_220_HP_OFFSET_R7,						0x00},
	{S5M3700X_221_HP_OFFSET_R8,						0x00},
	{S5M3700X_222_HP_OFFSET_R9,						0x00},
	{S5M3700X_223_HP_OFFSET_R10,					0x00},
	{S5M3700X_224_HP_OFFSET_R11,					0x00},
	{S5M3700X_225_HP_OFFSET_R12,					0x00},
	{S5M3700X_226_HP_OFFSET_R13,					0x00},
	{S5M3700X_227_HP_OFFSET_R14,					0x00},
	{S5M3700X_228_HP_OFFSET_R15,					0x00},
	{S5M3700X_229_HP_OFFSET_R16,					0x00},
	{S5M3700X_22A_HP_OFFSET_R17,					0x00},
	{S5M3700X_22B_HP_OFFSET_R18,					0x00},
	{S5M3700X_22C_HP_OFFSET_R19,					0x00},
	{S5M3700X_22D_HP_OFFSET_R20,					0x00},
	{S5M3700X_22E_HP_OFFSET_R21,					0x00},
	{S5M3700X_22F_HP_OFFSET_R22,					0x00},
	{S5M3700X_230_HP_OFFSET_R23,					0x00},
	{S5M3700X_231_HP_OFFSET_R24,					0x00},

	{S5M3700X_232_EP_OFFSET_0,						0x00},
	{S5M3700X_233_EP_OFFSET_1,						0x00},
	{S5M3700X_234_EP_OFFSET_2,						0x00},
	{S5M3700X_235_EP_OFFSET_3,						0x00},
	{S5M3700X_236_EP_OFFSET_4,						0x00},
	{S5M3700X_237_EP_OFFSET_5,						0x00},
	{S5M3700X_238_EP_OFFSET_6,						0x00},
	{S5M3700X_239_EP_OFFSET_7,						0x00},
	{S5M3700X_23A_EP_OFFSET_8,						0x00},
	{S5M3700X_23B_EP_OFFSET_9,						0x00},
	{S5M3700X_23C_EP_OFFSET_10,						0x00},
	{S5M3700X_23D_EP_OFFSET_11,						0x00},
	{S5M3700X_23E_EP_OFFSET_12,						0x00},
	{S5M3700X_23F_EP_OFFSET_13,						0x00},
	{S5M3700X_240_EP_OFFSET_14,						0x00},
	{S5M3700X_241_EP_OFFSET_15,						0x00},
	{S5M3700X_242_EP_OFFSET_16,						0x00},
	{S5M3700X_243_EP_OFFSET_17,						0x00},
	{S5M3700X_244_EP_OFFSET_18,						0x00},
	{S5M3700X_245_EP_OFFSET_19,						0x00},
	{S5M3700X_246_EP_OFFSET_20,						0x00},

	{S5M3700X_247_LINE_OFFSET_0,					0x00},
	{S5M3700X_248_LINE_OFFSET_1,					0x00},
	{S5M3700X_249_LINE_OFFSET_2,					0x00},
	{S5M3700X_24A_LINE_OFFSET_3,					0x00},
	{S5M3700X_24B_LINE_OFFSET_4,					0x00},
	{S5M3700X_24C_LINE_OFFSET_5,					0x00},
	{S5M3700X_24D_LINE_OFFSET_6,					0x00},
	{S5M3700X_24E_LINE_OFFSET_7,					0x00},
	{S5M3700X_24F_LINE_OFFSET_8,					0x00},
	{S5M3700X_250_LINE_OFFSET_9,					0x00},
	{S5M3700X_251_LINE_OFFSET_10,					0x00},
	{S5M3700X_252_LINE_OFFSET_11,					0x00},
	{S5M3700X_253_LINE_OFFSET_12,					0x00},
	{S5M3700X_254_LINE_OFFSET_13,					0x00},
	{S5M3700X_255_LINE_OFFSET_14,					0x00},
	{S5M3700X_256_LINE_OFFSET_15,					0x00},
	{S5M3700X_257_LINE_OFFSET_16,					0x00},
	{S5M3700X_258_LINE_OFFSET_17,					0x00},
	{S5M3700X_259_LINE_OFFSET_18,					0x00},
	{S5M3700X_25A_LINE_OFFSET_19,					0x00},
	{S5M3700X_25B_LINE_OFFSET_20,					0x00},

	{S5M3700X_25C_HPLOFF_S_0,						0x00},
	{S5M3700X_25D_HPLOFF_S_1,						0x00},
	{S5M3700X_25E_HPLOFF_S_2,						0x00},
	{S5M3700X_25F_HPLOFF_S_3,						0x00},
	{S5M3700X_260_HPROFF_S_0,						0x00},
	{S5M3700X_261_HPROFF_S_1,						0x00},
	{S5M3700X_262_HPROFF_S_2,						0x00},
	{S5M3700X_263_HPROFF_S_3,						0x00},
	{S5M3700X_264_EPOFF_S_0,						0x00},
	{S5M3700X_265_EPOFF_S_1,						0x00},
	{S5M3700X_266_EPOFF_S_2,						0x00},
	{S5M3700X_267_LINEOFF_S_0,						0x00},
	{S5M3700X_268_LINEOFF_S_1,						0x00},
	{S5M3700X_269_LINEOFF_S_2,						0x00},

	{S5M3700X_26A_HPL_OFFMSK_S_0,					0x00},
	{S5M3700X_26B_HPL_OFFMSK_S_1,					0x00},
	{S5M3700X_26C_HPL_OFFMSK_S_2,					0x00},
	{S5M3700X_26D_HPL_OFFMSK_S_3,					0x00},
	{S5M3700X_26E_HPR_OFFMSK_S_0,					0x00},
	{S5M3700X_26F_HPR_OFFMSK_S_1,					0x00},
	{S5M3700X_270_HPR_OFFMSK_S_2,					0x00},
	{S5M3700X_271_HPR_OFFMSK_S_3,					0x00},
	{S5M3700X_272_EP_OFFMSK_S_0,					0x00},
	{S5M3700X_273_EP_OFFMSK_S_1,					0x00},
	{S5M3700X_274_EP_OFFMSK_S_2,					0x00},
	{S5M3700X_275_LINE_OFFMSK_S_0,					0x00},
	{S5M3700X_276_LINE_OFFMSK_S_1,					0x00},
	{S5M3700X_277_LINE_OFFMSK_S_2,					0x00},

	{S5M3700X_288_IDAC3_OTP,						0x00},
	{S5M3700X_289_IDAC4_OTP,						0x00},
	{S5M3700X_28A_IDAC5_OTP,						0x00},

	/* OTP Register for Analog */
	{S5M3700X_2A6_DSM_OFFSETC,						0x00},
	{S5M3700X_2A7_DSM_OFFSET_RANGEC,				0x00},
	{S5M3700X_2A8_CTRL_DAC1,						0x00},
	{S5M3700X_2A9_CTRL_DAC2,						0x00},
	{S5M3700X_2AA_CTRL_DAC3,						0x00},
	{S5M3700X_2AB_CTRL_ADC1,						0x00},
	{S5M3700X_2AC_CTRL_ADC2,						0x00},
	{S5M3700X_2AD_CTRL_ADC3,						0x00},
	{S5M3700X_2AE_HP_DSML,							0x00},
	{S5M3700X_2AF_HP_DSMR,							0x00},
	{S5M3700X_2B0_DSM_OFFSETL,						0x00},
	{S5M3700X_2B1_DSM_OFFSETR,						0x00},
	{S5M3700X_2B2_DSM_OFFSET_RANGE,					0x00},
	{S5M3700X_2B3_CTRL_IHP,							0x00},
	{S5M3700X_2B4_CTRL_HP0,							0x00},
	{S5M3700X_2B5_CTRL_HP1,							0x00},
	{S5M3700X_2B6_CTRL_HP2,							0x00},
	{S5M3700X_2B7_CTRL_EP0,							0x00},
	{S5M3700X_2B8_CTRL_EP1,							0x00},
	{S5M3700X_2B9_CTRL_EP2,							0x00},
	{S5M3700X_2BA_CTRL_LN0,							0x00},
	{S5M3700X_2BB_CTRL_LN1,							0x00},
	{S5M3700X_2BE_IDAC0_OTP,						0x00},
	{S5M3700X_2BF_IDAC1_OTP,						0x00},
	{S5M3700X_2C0_IDAC2_OTP,						0x00},
	{S5M3700X_2C0_EP_DSML,							0x00},
	{S5M3700X_2C0_EP_DSMR,							0x00},

	/* OTP Register for CP2 */
	{S5M3700X_2C3_CP2_TH1_32,						0x00},
	{S5M3700X_2C4_CP2_TH2_32,						0x00},
	{S5M3700X_2C5_CP2_TH3_32,						0x00},
	{S5M3700X_2C6_CP2_TH1_16,						0x00},
	{S5M3700X_2C7_CP2_TH2_16,						0x00},
	{S5M3700X_2C8_CP2_TH3_16,						0x00},
	{S5M3700X_2C9_CP2_TH1_06,						0x00},
	{S5M3700X_2CA_CP2_TH2_06,						0x00},
	{S5M3700X_2CB_CP2_TH3_06,						0x00},

	/* OTP Register for Jack */
	{S5M3700X_2D0_JACK_OTP00,						0x00},
	{S5M3700X_2D1_JACK_OTP01,						0x00},
	{S5M3700X_2D2_JACK_OTP02,						0x00},
	{S5M3700X_2D3_JACK_OTP03,						0x00},
	{S5M3700X_2D4_JACK_OTP04,						0x00},
	{S5M3700X_2D5_JACK_OTP05,						0x00},
	{S5M3700X_2D6_JACK_OTP06,						0x00},
	{S5M3700X_2D7_JACK_OTP07,						0x00},
	{S5M3700X_2D8_JACK_OTP08,						0x00},
	{S5M3700X_2D9_JACK_OTP09,						0x00},
	{S5M3700X_2DA_JACK_OTP0A,						0x00},
	{S5M3700X_2DB_JACK_OTP0B,						0x00},
	{S5M3700X_2DC_JACK_OTP0C,						0x00},
	{S5M3700X_2DD_JACK_OTP0D,						0x00},
	{S5M3700X_2DE_JACK_OTP0E,						0x00},
	{S5M3700X_2DF_JACK_OTP0F,						0x00},
	{S5M3700X_2E0_JACK_OTP10,						0x00},
	{S5M3700X_2E1_JACK_OTP11,						0x00},
	{S5M3700X_2E2_JACK_OTP12,						0x00},
	{S5M3700X_2E3_JACK_OTP13,						0x00},
	{S5M3700X_2E4_JACK_OTP14,						0x00},
	{S5M3700X_2E5_JACK_OTP15,						0x00},
	{S5M3700X_2E6_JACK_OTP16,						0x00},
	{S5M3700X_2E7_JACK_OTP17,						0x00},
	{S5M3700X_2E8_JACK_OTP18,						0x00},

	{S5M3700X_2E8_RSVD,								0x00},
	{S5M3700X_2EA_RSVD,								0x00},
	{S5M3700X_2EB_RSVD,								0x00},
	{S5M3700X_2EC_RSVD,								0x00},
	{S5M3700X_2ED_RSVD,								0x00},
	{S5M3700X_2EE_RSVD,								0x00},
	{S5M3700X_2EF_RSVD,								0x00},
	{S5M3700X_2F0_RSVD,								0x00},

	/* MV register */
	{S5M3700X_300_MV_OTP1,							0x00},
	{S5M3700X_301_MV_OTP2,							0x00},
	{S5M3700X_302_MV_OTP3,							0x00},
	{S5M3700X_303_MV_OTP4,							0x00},
	{S5M3700X_304_MV_ACTR1,							0x00},
	{S5M3700X_305_MV_ACTR2,							0x00},
	{S5M3700X_306_CHIP_ID,							0x00},
	{S5M3700X_307_LV_DCTR,							0x00},
	{S5M3700X_308_COM_OTP_TEST,						0x00},
	{S5M3700X_309_COM_OTP_ADRL,						0x00},
	{S5M3700X_30A_COM_OTP_ADRH,						0x00},
	{S5M3700X_30B_COM_OTP_DATA,						0x00},
};

/**
 * struct reg_sequence - An individual write from a sequence of writes.
 *
 * @reg: Register address.
 * @def: Register value.
 * @delay_us: Delay to be applied after the register write in microseconds
 *
 * Register/value pairs for sequences of writes with an optional delay in
 * microseconds to be applied after each write.
 */

static const struct reg_sequence s5m3700x_init_patch[] = {
#if IS_ENABLED(CONFIG_SND_SOC_S5M3700X_VTS)
	{S5M3700X_02F_DMIC_ST,						0x10},
#endif
	{S5M3700X_033_ADC4,							0x11},
	{S5M3700X_038_AD_TRIM1,						0x48},
	{S5M3700X_039_AD_TRIM2,						0x98},
	{S5M3700X_040_PLAY_MODE,					0x04},
	{S5M3700X_050_AVC1,							0x05},
	{S5M3700X_053_AVC4,							0x80},
	{S5M3700X_054_AVC5,							0x89},
	{S5M3700X_058_AVC9,							0x00},
	{S5M3700X_05C_AVC13,						0x99},
	{S5M3700X_068_AVC25,						0x08},
	{S5M3700X_093_DSM_CON1,						0x52},
	{S5M3700X_09D_AVC_DWA,						0x46},
	{S5M3700X_04B_OFFSET_CTR,					0xFF},
	/* PD_IDAC4 */
	{S5M3700X_135_PD_IDAC4,						0x00},
	/* ODSEL6 */
	{S5M3700X_0B5_ODSEL6,						0x18},
	/* Default Digital Gain */
	{S5M3700X_041_PLAY_VOLL,					0x54},
	{S5M3700X_042_PLAY_VOLR,					0x54},
	/* RCV gain setting faster to 166usec */
	{S5M3700X_07E_AVC45,						0x4B},
	/* ADC/DAC Mute */
	{S5M3700X_030_ADC1,							0x07},
	{S5M3700X_040_PLAY_MODE,					0x07}, //RESET Regisrer 0x04
};

static const struct reg_sequence s5m3700x_jack_patch[] = {
	/* PDB JD CLK Enable */
	{S5M3700X_0D0_DCTR_CM,						0x01},
	/* PDB JD Comparator On */
	{S5M3700X_0C0_ACTR_JD1,						0x03},
	/* ANT LDET VTH Setting */
	{S5M3700X_0C3_ACTR_JD4,						0x30},
	{S5M3700X_0D6_DCTR_TEST6,					0x01},
	/* Tuning Jack DBNC Value */
	{S5M3700X_0D8_DCTR_DBNC1,					0x92},
	{S5M3700X_0D9_DCTR_DBNC2,					0x92},
	/* ANT MDET OUT Debounce Time */
	{S5M3700X_0DB_DCTR_DBNC4,					0x92},
	/* IMP RAMP */
	{S5M3700X_0E9_DCTR_IMP3,					0x82},
	/* ODSEL5 */
	{S5M3700X_0B4_ODSEL5,						0x09},
	/* HP PULLDN */
	{S5M3700X_13A_POP_HP,						0x60},
	/* LDET ADC Range Setting */
	{S5M3700X_2E0_JACK_OTP10,					0x4D},
	{S5M3700X_2E1_JACK_OTP11,					0x60},
	{S5M3700X_2E2_JACK_OTP12,					0x77},
	/* IRQ Un-masking */
	{S5M3700X_008_IRQ1M,						0x30},
	{S5M3700X_009_IRQ2M,						0x03},
	{S5M3700X_00A_IRQ3M,						0xEE},
	{S5M3700X_00B_IRQ4M,						0xEE},
	/* Pin Setting */
	{S5M3700X_0E0_DCTR_FSM1,					0x0A},
	/* Mdet jack out */
	{S5M3700X_0E1_DCTR_FSM2,					0x00},
};

static const struct reg_sequence s5m3700x_usbjack_patch[] = {
	/* PDB JD CLK Enable */
	{S5M3700X_0D0_DCTR_CM,						0x01},
	/* ANT LDET VTH Setting */
	{S5M3700X_0C3_ACTR_JD4,						0x33},
	/* PDB JD Comparator On */
	{S5M3700X_0C0_ACTR_JD1,						0x03},
	/* T_PDB_BTN_DET */
	{S5M3700X_0D5_DCTR_TEST5,					0xC3},
	/* T_D2D_ANT_MDET_DBNC */
	{S5M3700X_0D6_DCTR_TEST6,					0x01},
	{S5M3700X_0D7_DCTR_TEST7,					0x04},
	{S5M3700X_0DB_DCTR_DBNC4,					0x00},
	{S5M3700X_0DC_DCTR_DBNC5,					0x00},
	/* IMP RAMP */
	{S5M3700X_0E9_DCTR_IMP3,					0x81},
	{S5M3700X_0FD_ACTR_GP,						0x0C},
	/* T_JACK_STATE */
	{S5M3700X_0E3_DCTR_FSM4,					0x40},
	/* Auto Btn Enable */
	{S5M3700X_0E5_DCTR_FSM6,					0x04},
	/* IMP Skip */
	{S5M3700X_0EA_DCTR_IMP4,					0xAB},
	/* MDET Trigger Setting */
	{S5M3700X_0EE_ACTR_ETC1,					0x24},
	/* ADC Delay */
	{S5M3700X_0DF_DCTR_DLY2,					0x00},
	/* LDET ADC Range Setting */
	{S5M3700X_2E0_JACK_OTP10,					0x4D},
	{S5M3700X_2E1_JACK_OTP11,					0x60},
	{S5M3700X_2E2_JACK_OTP12,					0x77},
	/* Setting the MDET Trim */
	{S5M3700X_2DD_JACK_OTP0D,					0x66},
	/* IRQ Un-masking */
	{S5M3700X_008_IRQ1M,						0x3F},
	{S5M3700X_009_IRQ2M,						0x7F},
	{S5M3700X_00A_IRQ3M,						0xEE},
	{S5M3700X_00B_IRQ4M,						0xEE},
	/* Pin Setting */
	{S5M3700X_0E0_DCTR_FSM1,					0x06},
	/* Tuning BTN DBNC Value */
	{S5M3700X_0DD_DCTR_DBNC6,					0x03},
};
#endif /* _S5M3700X_REGMAP_H */

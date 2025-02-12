// SPDX-License-Identifier: GPL-2.0
/*
 * Samsung Exynos SoC series Pablo driver
 *
 * Copyright (c) 2022 Samsung Electronics Co., Ltd
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#include <linux/module.h>

#include "is-core.h"
#include "is-param.h"
#include "is-device-ischain.h"
#include "pablo-debug.h"
#include "pablo-mem.h"
#include "is-hw-common-dma.h"

void is_subdev_internal_get_sbwc_type(const struct is_subdev *subdev,
					u32 *sbwc_type, u32 *lossy_byte32num)
{
	*lossy_byte32num = 0;

	switch (subdev->id) {
	case ENTRY_SSVC0:
		*sbwc_type = COMP;
		break;
	default:
		*sbwc_type = NONE;
	}
}
KUNIT_EXPORT_SYMBOL(is_subdev_internal_get_sbwc_type);

int is_subdev_internal_get_buffer_size(const struct is_subdev *subdev,
	u32 *width, u32 *height, u32 *sbwc_block_width, u32 *sbwc_block_height)
{
	if (!width) {
		mserr("width is NULL", subdev, subdev);
		return -EINVAL;
	}
	if (!height) {
		mserr("height is NULL", subdev, subdev);
		return -EINVAL;
	}

	switch (subdev->id) {
	case ENTRY_SSVC0:
		*width = subdev->output.width;
		*height = subdev->output.height;
		*sbwc_block_width = CSIS_COMP_BLOCK_WIDTH;
		*sbwc_block_height = CSIS_COMP_BLOCK_HEIGHT;
		break;
	default:
		*width = subdev->output.width;
		*height = subdev->output.height;
		break;
	}

	return 0;
}
KUNIT_EXPORT_SYMBOL(is_subdev_internal_get_buffer_size);

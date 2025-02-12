#include "mif_reg.h"

#define DBUS_BAAW_COUNT 1
#define PBUS_BAAW_COUNT 2
#define BAAW_BIT_SHIFT 12

const u32 dbus_baaw_offset[DBUS_BAAW_COUNT][4] = {
	{BAAW0_D_WLBT_START, BAAW0_D_WLBT_END, BAAW0_D_WLBT_REMAP, BAAW0_D_WLBT_INIT_DONE},
};

const u32 dbus_baaw_value[DBUS_BAAW_COUNT][4] = {
	{WLBT_DBUS_BAAW_0_START, WLBT_DBUS_BAAW_0_END, 0 /* platform->mem_start */, WLBT_BAAW_ACCESS_CTRL},
};

const u32 pbus_baaw_offset[PBUS_BAAW_COUNT][4] = {
	{BAAW_C_WLBT_START_0, BAAW_C_WLBT_END_0, BAAW_C_WLBT_REMAP_0, BAAW_C_WLBT_INIT_DONE_0},
	{BAAW_C_WLBT_START_1, BAAW_C_WLBT_END_1, BAAW_C_WLBT_REMAP_1, BAAW_C_WLBT_INIT_DONE_1},
};

const u32 pbus_baaw_value[PBUS_BAAW_COUNT][4] = {
	{WLBT_CBUS_BAAW_0_START, WLBT_CBUS_BAAW_0_END, WLBT_MAILBOX_GNSS_WLBT, WLBT_BAAW_ACCESS_CTRL},
	{WLBT_CBUS_BAAW_1_START, WLBT_CBUS_BAAW_1_END, WLBT_MAILBOX_AP_WLBT_WL, WLBT_BAAW_ACCESS_CTRL},
};

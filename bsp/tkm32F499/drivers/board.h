/*
 * Copyright (c) 2017-2019, MindMotion AE Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2021-10-02     spaceman           first version
 */

#ifndef BOARD_H__
#define BOARD_H__
#include <rtthread.h>
#include <rtdevice.h>
#include <hal_device.h>
#include "sys.h"



#define SRAM_SIZE           (8 * 1024 * 1024)
// #define SRAM_BASE           ((uint32_t)0x70000000)


#define SRAM_END (T_SDRAM_BASE + SRAM_SIZE)
#ifdef __CC_ARM
    extern int Image$$RW_IRAM1$$ZI$$Limit;
    #define HEAP_BEGIN ((void *)&Image$$RW_IRAM1$$ZI$$Limit)
#elif __ICCARM__
    #pragma section = "HEAP"
    #define HEAP_BEGIN (__segment_end("HEAP"))
#else
    extern int __bss_end;
    #define HEAP_BEGIN ((void *)&__bss_end)
#endif
#define HEAP_END SRAM_END
#define HEAP_SIZE (HEAP_END - (rt_uint32_t)HEAP_BEGIN)
extern void rt_hw_board_init(void);
#endif

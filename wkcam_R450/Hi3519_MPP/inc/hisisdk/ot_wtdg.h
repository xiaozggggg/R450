/*
  Copyright (c), 2001-2022, Shenshu Tech. Co., Ltd.
 */

#ifndef OT_WTDG_H
#define OT_WTDG_H

#include "securec.h"
#include "osal_ioctl.h"
#ifdef __cplusplus
extern "C"{
#endif /* __cplusplus */

int watchdog_init(void);
void watchdog_exit(void);

#define    WATCHDOG_IOCTL_BASE    'W'
#define wtdg_unused(x)             ((void)(x))

struct watchdog_info {
    unsigned int options;             /* Options the card/driver supports */
    unsigned int firmware_version;    /* Firmware version of the card */
    unsigned char identity[32];       /* 32 bit Identity of the board */
};

#define WDIOC_GETSUPPORT     _IOR(WATCHDOG_IOCTL_BASE, 0, struct watchdog_info)
#define WDIOC_GETSTATUS      _IOR(WATCHDOG_IOCTL_BASE, 1, unsigned int)
#define WDIOC_GETBOOTSTATUS  _IOR(WATCHDOG_IOCTL_BASE, 2, unsigned int)

#define WDIOC_SETOPTIONS     _IOWR(WATCHDOG_IOCTL_BASE, 4, unsigned int)
#define WDIOC_KEEPALIVE      _IO(WATCHDOG_IOCTL_BASE, 5)
#define WDIOC_SETTIMEOUT     _IOWR(WATCHDOG_IOCTL_BASE, 6, int)
#define WDIOC_GETTIMEOUT     _IOR(WATCHDOG_IOCTL_BASE, 7, int)

#define WDIOF_UNKNOWN        (-1)    /* Unknown flag error */
#define WDIOS_UNKNOWN        (-1)    /* Unknown status error */

#define WDIOF_OVERHEAT       0x0001    /* Reset due to CPU overheat */
#define WDIOF_FANFAULT       0x0002    /* Fan failed */
#define WDIOF_EXTERN1        0x0004    /* External relay 1 */
#define WDIOF_EXTERN2        0x0008    /* External relay 2 */
#define WDIOF_POWERUNDER     0x0010    /* Power bad/power fault */
#define WDIOF_CARDRESET      0x0020    /* Card previously reset the CPU */
#define WDIOF_POWEROVER      0x0040    /* Power over voltage */
#define WDIOF_SETTIMEOUT     0x0080    /* Set timeout (in seconds) */
#define WDIOF_MAGICCLOSE     0x0100    /* Supports magic close char */
#define WDIOF_PRETIMEOUT     0x0200    /* Pretimeout (in seconds), get/set */
#define WDIOF_KEEPALIVEPING  0x8000    /* Keep alive ping reply */

#define WDIOS_DISABLECARD    0x0001    /* Turn off the watchdog timer */
#define WDIOS_ENABLECARD     0x0002    /* Turn on the watchdog timer */
#define WDIOS_TEMPPANIC      0x0004    /* Kernel panic on temperature trip */

#define OT_DOG_TIMER_MARGIN    60

volatile void **get_wtdg_reg_base(void);
void wtdg_set_module_param(int margin, int daemon, int fiq_support);
void creat_dog_thread(int cpu_num);
void fiq_dog_feed(void);
void ot_dog_feed(void);
int ot_dog_deamon(void *data);
void stop_hrtimer(void);
void stop_dog_thread(void);
#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif

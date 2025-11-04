#ifndef __cbm858x_LPTM_H__
#define __cbm858x_LPTM_H__


#ifdef __cplusplus
 extern "C" {
#endif
#include <stdio.h>
#include <stdint.h>
#include "main.h"

#define softtrigger 1
#define ETR_trigger 0
#define RTC_trigger 0

#define lptime_1S   10000
#define lptime_1ms  10
#define NormalPeriod    250
#define SleepPeriod     5000

void lptime_config(void);
void lptim_timer_reload(uint16_t lptime);
void lptim_timer_disable(void);

#endif
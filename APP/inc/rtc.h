#ifndef __RTC_H__
#define __RTC_H__

#include "main.h"
#include <stdio.h>
#include <stdint.h>

void RTC_Init(void);
void rtc_config(void);
void rtc_reconfig(void);
void rtc_time_show(void);
void rtc_alarmshow(void);
void rtc_wakeup(void);//rtc period wake up
void rtc_calendar_config(uint8_t year,uint8_t month,uint8_t date,uint8_t hour,uint8_t min,uint8_t sec);
void RTC_Set_Alarm(uint8_t hour,uint8_t min,uint8_t sec);
void deepsleep_RTCalarm_wk_test(void);//rtc alarm

uint8_t rtc_write_bak_reg(uint32_t value);

#endif
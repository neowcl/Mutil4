#ifndef __cbm858x_TIM_H__
#define __cbm858x_TIM_H__

#ifdef __cplusplus
 extern "C" {
#endif
#include <stdio.h>
#include <stdint.h>
#include "main.h"
#include "cbm858xm_tim.h"

extern uint32_t SystemCoreClock;

void time_config(void);
void time_enable(void);
void time_disable(void);

#endif
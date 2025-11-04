/*******************************************************************************
* Copyright(C) 2008, 2019 Renesas Electronics Corporation
* RENESAS ELECTRONICS CONFIDENTIAL AND PROPRIETARY
* This program must be used solely for the purpose for which
* it was furnished by Renesas Electronics Corporation. No part of this
* program may be reproduced or disclosed to others, in any
* form, without the prior written permission of Renesas Electronics
* Corporation.
*******************************************************************************
*******************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corp. and is only 
* intended for use with Renesas products. No other uses are authorized.
*
* This software is owned by Renesas Electronics Corp. and is protected under 
* all applicable laws, including copyright laws.
*
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES 
* REGARDING THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, 
* INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A 
* PARTICULAR PURPOSE AND NON-INFRINGEMENT.  ALL SUCH WARRANTIES ARE EXPRESSLY 
* DISCLAIMED.
*
* TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS 
* ELECTRONICS CORP. NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE 
* FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES 
* FOR ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS 
* AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
*
* http://www.renesas.com/disclaimer

*""FILE COMMENT""***************************************************************
* System Name	: RAJ240090/100 sample code
* File Name		: datcalc_spl.h
* Contents		: SMBus data calculating function header file
* Device		: RAJ240090/100
* Compiler		: CC-RL (V.1.04)
* Note			: 
*""FILE COMMENT END""**********************************************************/

#ifndef _DATCALC_SPL_H
#define _DATCALC_SPL_H
#include "main.h"

/***********************************************************************
extern functions
***********************************************************************/
extern void Calc_RC(void);						// RemainingCapacity() calc
extern void Make_RC(void);						// RC calc from integration
extern void Calc_CC(void);						// CycleCount() calc
extern void Init_Cap(void);						// Initial capacity calc
extern void Calc_RSOC(void);
extern void Calc_iRSOC(void);

// - Internal functions - 
void FCC_Limit_Chk(void);						// FCC Limit check function

// - Grobal variable -
extern uint8_t		arelearn_cnt;					// Relearn counter
extern uint16_t		toldrc;							// last RemCap value
extern uint16_t		tdfup_cnt;						// DataFlash update counter 
extern uint32_t 	lmaxerr_cnt;					// MaxError integration counter
extern uint16_t		tccup;							// CycleCount increment cap.

extern uint16_t		tcom10c_w;						// FCC temporary save area
extern uint16_t		tcph_v;							// CP_H
extern uint16_t		tcpl_v;							// CP_L
extern uint8_t		arcflg;							// Flags for RC

extern long lrccr_w;						// Charge relearn capacity
extern long lrcdr_w;						// Discharge relearn capacity
extern uint16_t  t_com0dsoclast ;  // RelativeStateOfCharge// RelativeStateOfCharge=t_com0d;
// extern uint16_t Vol_0RSOC_time  ;
extern uint16_t VoltagetoRSOCcount;
extern uint16_t   t_com0fCap;
extern uint32_t   t_com10Cap;
extern uint16_t t_com17_w;
extern uint16_t DF_IRC_temp;
extern uint16_t DF_IFCC_temp;
extern uint16_t DF_IRsoc_temp;

extern uint8_t f_ful_chg_once ;

extern uint8_t irsoc_last ;

// dsg inner  resis
typedef struct
{
	uint8_t cnt_30m_start : 1;
	uint8_t chg_last_state1 : 1;
	// uint8_t cnt_30m_start : 1;
	uint8_t relex3_last : 1;
	uint8_t start_save : 1;
	uint8_t RSVD : 4;
} DSG_INNER_RES1;

// extern  DSG_INNER_RES1   DSG_INNER_RES;

#define f_cnt_30m_start   DSG_INNER_RES.cnt_30m_start
#define f_chg_last_state1 DSG_INNER_RES.chg_last_state1
#define f_relex3_last     DSG_INNER_RES.relex3_last
#define f_start_save      DSG_INNER_RES.start_save

// - bit / union variable definition -
									// Flags for RC
#define f_studied	DEF_BIT2(&arcflg)			// relearned flag
#define f_firstFlg   DEF_BIT0(&arcflg)
#define f_secondFlg  DEF_BIT1(&arcflg)


#endif

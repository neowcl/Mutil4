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
* System Name	: RAJ240090/100 sample program
* File Name		: datcalc_spl.c
* Contents		: Data calculation function source file
* Device		: RAJ240090/100
* Compiler		: CC-RL (V.4.01)
* Note			: 
*""FILE COMMENT END""**********************************************************/

#define _DATCALC_SPL

#include "main.h"								// union/define definition

/***********************************************************************
** Announcement of internal function prototype
***********************************************************************/
static void Calc_NormalRC(uint32_t	lrc);
long lrccr_w;						// Charge relearn capacity
long lrcdr_w;						// Discharge relearn capacity
uint16_t  t_com0dsoclast ;  // RelativeStateOfCharge// RelativeStateOfCharge=t_com0d;
uint16_t firstCurrentCnt=0;
uint16_t secondCurrentCnt=0;
float currentRultiple=1.0;

uint16_t   t_com0fCap;
uint32_t   t_com10Cap;
uint8_t	   arelearn_cnt;					// Relearn counter
uint16_t   toldrc;							// last RemCap value
uint16_t   tdfup_cnt;						// DataFlash update counter 
uint32_t   lmaxerr_cnt;					// MaxError integration counter
uint16_t   tccup;							// CycleCount increment cap.
uint16_t  tcom10c_w;						// FCC temporary save area
uint16_t  tcph_v;							// CP_H
uint16_t  tcpl_v;							// CP_L
uint8_t   arcflg;							// Flags for RC
// uint16_t Vol_0RSOC_time  ;
uint16_t VoltagetoRSOCcount = 0 ;



// uint8_t dsg_point_test;
uint8_t Qmax_update_DSG_test  ; 
uint8_t RSOC_USE_DF_test  ;
uint8_t f_study_d_test ;
uint16_t t_com17_w;
uint8_t   f_init_first_time ;
// uint16_t DF_IRC_temp;
// uint16_t DF_IFCC_temp;
// uint16_t DF_IRsoc_temp;


// Dsg_Update_work(void)

// Dsg_Update_FCC(void)
int16_t dsg_upfcc_keep_current;
int8_t dsg_upfcc_keep_temp;
uint16_t save_fac_dsg_upd;
uint16_t save_dsg_upd_fcc;
uint32_t leiji;
uint8_t count_3s;
uint8_t count_3s_b ;
uint8_t f_count3s_en;
uint8_t  f_count3s_en_b ;
uint8_t f_ful_chg_once ;
uint8_t f_chg_last2 ;
uint8_t f_relax_last;
uint8_t f_start_add_chg ;
uint8_t f_discharge_last2;

uint8_t f_relax_last_dsgupdate_use ;
uint8_t f_charge_last_dsgupdate_use  ;


// pinghua work
uint8_t f_pinghua_conditon;
uint8_t pinghua_soc_start;
uint8_t buchang_conditon_cnt;
uint8_t f_pinghua_work;
uint16_t temp_Current;
uint16_t chg_pinghua_current;

// uint8_t f_start_save;
uint8_t f_cp_h_fccupdated ;
uint8_t	f_cp_l_fccupdated ;
uint8_t f_fulchg_dsg_updated;
int32_t lrc_w_last ;
int8_t CellTemp_last_time_update ; 
uint8_t f_bigger_than_zero ;

// uint16_t outer_tinreg ;
uint16_t inner_res_old_buchang_vol;
uint16_t inner_res_buchang_vol;
uint16_t f_calc_inner_3res_work = 0;

int16_t dis_fac_cpl = 100  ; // discharge factor when reach cpl voltage .
// int16_t t_com0dsoclast ; 
uint8_t f_cp_l_last ;


int8_t CellTemp_use_rsoc;

uint16_t	Voltage_new_Si ; 
uint16_t	temp_Si_rsoc; 
uint16_t temp_Si_rsoc_out ;


// dsg inner  resis
// uint8_t f_cnt_30m_start;
// // uint8_t f_cnt_30m_start;
// uint8_t f_chg_last_state1;
// uint8_t f_relex3_last;
// uint8_t f_start_save;
uint16_t cnt_30m;
uint8_t cnt5_i;
uint8_t cnt5_j;
uint16_t save_volstart_dsg_inner;
uint16_t save_volend_dsg_inner;
uint16_t  inner_res_dsg_100 ; 
uint16_t  temp_dsg_inner_res;  


 uint16_t t_com0f_keep ;
 uint16_t count_hold94_100_soc100 ;
 uint8_t  f_count_hold94_100_soc100 ;
 uint8_t  f_gs_fc_last ;
//  uint16_t t_com0f_out_show ;
uint8_t f_relax1_fc1_soc100_state ;
uint8_t f_break_relax ;
uint8_t f_incount ;

uint8_t  Count_13s_rsoc_1  ;
uint8_t temptime_D_Discharge_0_voltage_Delay ;
// uint8_t  Count_13s_rsoc_2  ;

DSG_INNER_RES1   DSG_INNER_RES;


// uint16_t  inner_res_dsg_100 ;  // t_com2a
// uint16_t  temp_dsg_inner_res;  // t_com2b

uint16_t Vol3[5] ;

uint8_t irsoc_last ;

void Calc_inner_3res(void)
{
	uint32_t restemp;

	if (t_com0d != 100 || f_fullchg == OFF || f_charge == ON)
	{
		f_cnt_30m_start = 0;
	}

	if (f_fullchg && f_chg_last_state1 == ON && f_charge == OFF && f_relax == ON)
	{

		f_cnt_30m_start = 1; // 1. fullchg 2. last state chg 3. this state relax
	}

	f_chg_last_state1 = f_charge;
	// //1. fullchg 2. last state chg 3. this state relax , start count
	if (f_cnt_30m_start == 1)
	{
		cnt_30m++;
		if (cnt_30m >= 1795)
		{
			Vol3[cnt5_i] = Voltage(); //
			//	Cur3[cnt5_i] = t_com0a;
			cnt5_i++;
			if (cnt5_i >= 5)
			{
				cnt5_i = 0;
			}
			if (cnt_30m >= 1800)
			{
				cnt_30m = 1800;
				if (f_relex3_last == ON && f_discharge == ON)
				{
					save_volstart_dsg_inner = Vol3[cnt5_i];
					// save_curstart_inner = I_abs ;
					f_start_save = 1;
				}
				if (f_start_save == 1 && f_discharge == ON)
				{
					cnt5_j++;
				}

				if (cnt5_j >= 5)
				{
					cnt5_i = 0;
					cnt5_j = 0;
					cnt_30m = 0;
					f_start_save = 0;
					f_cnt_30m_start = 0;
					// save_curend_dsg_inner = I_abs ;
					// save_volend_dsg_inner = t_com09  ;



					// if (I_abs > t_com18 / 10 && I_abs < t_com18 / 2) // t_com18  Design Capacity
					if (I_abs > D_Design_Capacity_mAh / 10 && I_abs < D_Design_Capacity_mAh / 2) // t_com18  Design Capacity
					{
						// (volt start - vol end ) / I_abs
						restemp = save_volstart_dsg_inner - save_volend_dsg_inner;
						inner_res_dsg_100 = restemp*1000 / I_abs;
						temp_dsg_inner_res = CellTemp;
					}
				}
			}
		}
	}
	f_relex3_last = f_relax ;
}


/*""FUNC COMMENT""**********************************************************
 * ID				: 1.0
 * module outline	: RemainingCapacity() Calculation Function
 *--------------------------------------------------------------------------
 * Include			: 
 *--------------------------------------------------------------------------
 * Declaration		: void Make_RC(void)
 *--------------------------------------------------------------------------
 * Function			: Calculate RemainingCapacity() from RC integration work.
 *					: 
 *--------------------------------------------------------------------------
 * Argument			: None
 *--------------------------------------------------------------------------
 * Return			: None
 *--------------------------------------------------------------------------
 * Input			: Record_lrc_w		: RC integration work
 *					: 
 * Output			: t_com0fc	: RemainingCapacity() [mAh]
 *					: 
 *--------------------------------------------------------------------------
 * Used function	: 
 *					: 
 *--------------------------------------------------------------------------
 * Caution			: 
 *--------------------------------------------------------------------------
 *""FUNC COMMENT END""*****************************************************/
void Make_RC(void)
{
	uint16_t	twork;

	if ((f_fullchg == 0) && (f_charge != 0))
	{
		// if rc >= 0.995 fcc ,rc = 0.995 * fcc    t_com10 *(60*60*4) *0.995  3600*4 *0.995 = 14328
		if (Record_lrc_w >= (int32_t)(t_com10 * 14328))
		{
			Record_lrc_w = (int32_t)(t_com10 * 14328);
		}
	}

	twork = (uint16_t)(Record_lrc_w / (60*60*4));			// RC = RC_W / (60min*60sec*4)

	if( twork > t_com10  )						// RC > FCC ?
	{
		t_com0f  = t_com10 ;					// RC = FCC
	} 
	else 
	{		
		t_com0f  = twork;	
	}	
}

void Make_iRC(void)
{
	uint16_t	twork;

	twork = (uint16_t)(Record_Ilrc_w / (60*60*4));			// RC = RC_W / (60min*60sec*4)
	if( twork > t_com89  )						// RC > FCC ?
	{
		t_com88  = t_com89 ;					// RC = FCC
	} 
	else 
	{		
		t_com88  = twork;	
	}	

}

/*""FUNC COMMENT""**********************************************************
* ID				: 1.0
* module outline	: Function of capacity calculation while
* 					: discharging and voltage is higher than CP_H.
*--------------------------------------------------------------------------
* Include			: 
*--------------------------------------------------------------------------
* Declaration		: void Calc_NormalRC(uint32_t lrc)
*--------------------------------------------------------------------------
* Function			: It calculates capacity while discharging and
*					:  the voltage is higher than CP_H.
*--------------------------------------------------------------------------
* Argument			: None
*--------------------------------------------------------------------------
* Return			: None
*--------------------------------------------------------------------------
* Input			: None
*					: 
* Output			: Record_lrc_w		: RC integration work
*					: 
*--------------------------------------------------------------------------
* Used function	: 
*					: 
*--------------------------------------------------------------------------
* Caution			: 
*--------------------------------------------------------------------------
*""FUNC COMMENT END""*****************************************************/
static void Calc_NormalRC(uint32_t	lrc)
{
	long	lwork;

	if( f_study_d == ON )					// Now discharge relearning ?
	{
		lrcdr_w += lrc;						// Integrate discharge rel.cap
	}
	// CP_x capacity = FCC*60*60*4*(D_CP_x/100)
	//               = FCC*D_CP_x*144
	// lwork = (long)t_com10  * D_CP_H * 144;	// Calculate CP_H capacity
	// if( Record_lrc_w < lwork )						// Correction cap < CP_H cap ?
	// {
	// 	lrc /= 2;							// Correction coefficient = 0.5
	// }
	Record_lrc_w -= lrc;							// Substruct correction value

	// lwork = (long)t_com10  * D_CP_L * 144;				// Calculate CP_L capacity
	// if( Record_lrc_w < lwork )						// Correction cap < CP_L cap ?
	// {
	// 	Record_lrc_w = lwork;						// Correction cap hold to CP_H cap
	// }

	
	if (Record_lrc_w <= 0)
	{
		Record_lrc_w = 0; // Set 0
	}
	if (lrc_w_last <= 0)
	{
		lrc_w_last = 0; // 40 is right number ,since t_com10*36/3600 ,maybe rsoc == 0 ;
	}
}



// void clr_flg_fulchg_update(void)
// {
// 	keep_rc_rsoc20 = 0;
// 	cap_accmu_chg_update = 0;
// 	f_20rc_cap_detected = 0;
// 	f_chg_update_20 = 0;
// 	voltage_new = 0;
// 	current_dsg_keep = 0;
// 	// save_volta = 0; // 动态变化  // save voltage   should not zhushi ,want to see the data
// 	// save_soc = 0;	// save soc at this moment
// 	for (int k_clear = 0; k_clear < 3; k_clear++)
// 	{
// 		volt_keep[k_clear] = 0;
// 		curr_keep[k_clear] = 0;
// 	}

// 	f_bat_init = 0;
// }

void Dsg_Update_FCC(void)
{
	uint8_t aidx;
	uint8_t awork1, awork2, awork3, awork4;
	uint16_t twork1, twork2;
	int32_t ccwork;
	int32_t dcwork;

	uint16_t dsg_upd_facd32_inner;		 // this time dsg update factor   , use outer last time .
	uint16_t dsg_upd_factor32_last;		 // dsg factor of last time
	uint16_t FCC_up_dsg_last32bit_inner; // 	FCC  of last time for update .
	uint16_t FCC_dsg_up;				 // FCC data of this time .   use these 32 bits temperary datas for caculate .
	uint16_t temp_result;


	twork1 = (uint16_t)((long)dsg_upfcc_keep_current * 100 / D_Design_Capacity_mAh); // eg :   3600 mA.h  = 3600mA * 1h  
	// t_com18 Design  capacity

	if (twork1 <= D_CRATE_TBL[1]) // <= C-rate2 ?
	{
		aidx = 0;					  // Table index = 0
		if (twork1 <= D_CRATE_TBL[0]) // <= C-rate1 ?
		{
			awork1 = 0; // SetC-rate1
		}
		else
		{ // > C-rate1
			// Calculate value index
			awork1 = (uint8_t)(twork1 - D_CRATE_TBL[0]);
		}

		// Data area is within C-rate1 to C-rate2
		awork2 = D_CRATE_TBL[1] - D_CRATE_TBL[0];
	}
	else
	{								  // > C-rate2
		if (twork1 <= D_CRATE_TBL[2]) // <= C-rate3 ?
		{
			aidx = 5; // Table index = 5
			// Calculate value index
			awork1 = (uint8_t)(twork1 - D_CRATE_TBL[1]);
			// Data area is within C-rate2 to C-rate3
			awork2 = D_CRATE_TBL[2] - D_CRATE_TBL[1];
		}
		else
		{									  // > C-rate3
			aidx = 10;						  // Table index = 10
			twork1 = twork1 - D_CRATE_TBL[2]; // twork1 means crate:  current / designs apaity
			if (twork1 > 255)				  // bigger than 1byte value ?  twork u16 1.25
			{
				awork1 = 255; // Set max value
			}
			else
			{
				awork1 = (uint8_t)twork1; // store rate difference
			}
			// Data area is within C-rate3 to C-rate4
			awork2 = D_CRATE_TBL[3] - D_CRATE_TBL[2]; // store range difference
		}
	}

	// - Make Temperature index -
	awork3 = dsg_upfcc_keep_temp - D_TRATE_TBL[0]; // Make the value of T-rate1 base
	
	if (dsg_upfcc_keep_temp >= D_TRATE_TBL[1])	   // >= T-rate2 ?
	{
		aidx++;									   // Increment table index
		if (dsg_upfcc_keep_temp >= D_TRATE_TBL[2]) // >= T-rate3 ?
		{
			aidx++;									   // Increment table index
			if (dsg_upfcc_keep_temp >= D_TRATE_TBL[3]) // >= T-rate4 ?
			{
				aidx++; // Increment table index
						// Data area is within T-rate4 to T-rate5
				awork4 = D_TRATE_TBL[4] - D_TRATE_TBL[3];
				if (dsg_upfcc_keep_temp >= D_TRATE_TBL[4]) // >= T-rate5 ?
				{
					awork3 = awork4; // Value index is max value
				}
				else
				{ // T-rate4 <= Temp. < T-rate5
				  // Calculate value index
					awork3 = dsg_upfcc_keep_temp - D_TRATE_TBL[3];
				}
			}
			else
			{ // T-rate3 <= Temp. < T-rate4
			  // Data area is within T-rate3 to T-rate4
				awork4 = D_TRATE_TBL[3] - D_TRATE_TBL[2];
				// Calculate value index
				awork3 = dsg_upfcc_keep_temp - D_TRATE_TBL[2];
			}
		}
		else
		{ // T-rate2 <= Temp. < T-rate3
			// Data area is within T-rate2 to T-rate3
			awork4 = D_TRATE_TBL[2] - D_TRATE_TBL[1];
			awork3 = dsg_upfcc_keep_temp - D_TRATE_TBL[1]; // Calculate value index
		}
	}
	else
	{ // < T-rate2
		// Data area is within T-rate1 to T-rate2
		awork4 = D_TRATE_TBL[1] - D_TRATE_TBL[0];

		if (dsg_upfcc_keep_temp <= D_TRATE_TBL[0]) // <= T-rate1 ?
		{
			awork3 = 0; // Value index = 0
		}
	}

	if (aidx >= 10 && awork1 > awork2) // > C-Rate4 ?
	{
		// Calculate by coefficient
		// twork1 = QCAP_TBL[aidx+5] -				// Coefficient/((C-rate4 - C-rate3)*10) = 0.6(awork1-awork2)/awork2
		// 	(uint16_t)((((long)QCAP_TBL[aidx]-QCAP_TBL[aidx+5])*(awork1-awork2)*D_FCCCOE/((uint16_t)awork2*10)));
		twork1 = QCAP_TBL[aidx + 5] - // Coefficient/((C-rate4 - C-rate3)*10) = 0.6(awork1-awork2)/awork2
				 (uint16_t)((((long)QCAP_TBL[aidx] - QCAP_TBL[aidx + 5]) * (awork1 - awork2) * 6 / ((uint16_t)awork2 * 10)));

		// 0.6 (awork1 - awork2 , aworkd1 = )
		// awork1 =  twork1-D_CRATE_TBL[2] ;
		// awork2 =  D_CRATE_TBL[3]-D_CRATE_TBL[2] ;
		// awork2 - awork1 = twork1 - D_CRATE_TBL[3] ;  when high rates , change a lot ?
		// twork2 = QCAP_TBL[aidx+6] -
		// 	(uint16_t)((((long)QCAP_TBL[aidx+1]-QCAP_TBL[aidx+6])*(awork1-awork2)*D_FCCCOE/((uint16_t)awork2*10)));
		twork2 = QCAP_TBL[aidx + 6] -
				 (uint16_t)((((long)QCAP_TBL[aidx + 1] - QCAP_TBL[aidx + 6]) * (awork1 - awork2) * 6 / ((uint16_t)awork2 * 10)));
	}
	else
	{ // <= C-Rate4
		twork1 = QCAP_TBL[aidx] -
				 (uint16_t)((((long)QCAP_TBL[aidx] - QCAP_TBL[aidx + 5]) * awork1 / awork2));

		twork2 = QCAP_TBL[aidx + 1] -
				 (uint16_t)((((long)QCAP_TBL[aidx + 1] - QCAP_TBL[aidx + 6]) * awork1 / awork2));
	}
	dsg_upd_facd32_inner = twork1 + (uint16_t)((((long)twork2 - twork1) * awork3 / awork4)); // new fcc factor

	// t_com31_out =  aidx;
	// t_com8b_out = awork1  ;
	// t_com8c_out   = awork2 ;
	// t_com8d_out = awork3  ;
	// t_com8e_out   = awork4 ;
	

	// dsg_upd_facd32_inner = (dsg_upd_facd32_inner+1000)/ 2 ;

	dsg_upd_facd32_inner = (dsg_upd_facd32_inner+save_fac_dsg_upd)/ 2 ;


	t_com32_out = dsg_upd_facd32_inner;
	// old_factor = save_fac_dsg_upd;		  // to show out information   old factor
	// new_factor = dsg_upd_facd32_inner;	  // new factor
	// old_fcc = FCC_up_dsg_last32bit_inner; // to show out information    old fcc
	temp_result = (dsg_upd_facd32_inner * 10) / (save_fac_dsg_upd/ 10);

	t_com33_out = save_fac_dsg_upd ;

	FCC_dsg_up = temp_result * (save_dsg_upd_fcc/100) + temp_result * (save_dsg_upd_fcc % 100 / 10) / 10 + temp_result * (save_dsg_upd_fcc % 10) / 100;

	// if (FCC_dsg_up > D_FCCMAXLIMIT)
	// {
	// 	FCC_dsg_up = D_FCCMAXLIMIT;
	// }

	// if (FCC_dsg_up < D_FCCMINLIMIT)
	// {
	// 	FCC_dsg_up = D_FCCMINLIMIT;
	// }

	if (CellTemp > TEMPER_LIMIT_T2)
	{
		if (FCC_dsg_up > D_FCCMAXLIMIT)
		{
			FCC_dsg_up = D_FCCMAXLIMIT;
		}
	}
	if ((CellTemp >= TEMPER_LIMIT_T1) && (CellTemp <= TEMPER_LIMIT_T2))
	{
		if (FCC_dsg_up > D_FCCMAXLIMIT - TEMPER_LIMIT_CAP2)
		{
			FCC_dsg_up = D_FCCMAXLIMIT - TEMPER_LIMIT_CAP2;
		}
	}
	if (CellTemp < TEMPER_LIMIT_T1)
	{
		if (FCC_dsg_up > D_FCCMAXLIMIT - TEMPER_LIMIT_CAP1)
		{
			FCC_dsg_up = D_FCCMAXLIMIT - TEMPER_LIMIT_CAP1;
		}
	}

	if (FCC_dsg_up < D_FCCMINLIMIT)
	{
		FCC_dsg_up = D_FCCMINLIMIT;
	}

	// if (FCC_dsg_up > 4500)
	// {
	// 	FCC_dsg_up = 4500;
	// }

	// if (FCC_dsg_up < 3000)
	// {
	// 	FCC_dsg_up = 3000;
	// }

	save_fac_dsg_upd = dsg_upd_facd32_inner; // save old fcc factor
											 // save updated fcc factor to a global parameter  .    new fcc far
											 // 用函数内部变量临时计算
	save_dsg_upd_fcc = FCC_dsg_up;			 // save new  updated FCC  // save fcc
	// new_fcc = FCC_dsg_up;					 //
	t_com0f = (uint16_t)((long)FCC_dsg_up*t_com0d/100);	 // RC = fcc * soc /100 ;  // temperature will change the result when not 100% .
	Record_lrc_w = t_com0f *3600*4;					 // lrc_w = RC *3600 ;
	lrc_w_last= Record_lrc_w ;   // no need extra compare  limit condtion , after updated , FCC = FCC last , no need other extra condition 
	t_com0dsoclast = t_com0d; // no need extra  compare limit condtion , after updated , SOC  = SOC last , no need other extra condition 
	// to do 
	// RSOC  already 
	// ASOC 

	// ASOC : t_com0e

	// t_com0e = (uint16_t)((long)t_com0f*2000 / D_Design_Capacity_mAh + 10)/20; 
	
	
	t_com10 = FCC_dsg_up;
	leiji = 0;
	count_3s = 0;
	count_3s_b = 0 ;
	f_count3s_en = 0;
	f_count3s_en_b = 0;
	f_ful_chg_once = 0;
	
	
	//}
	// out parameter only   save_dsg_upd_fcc ;  save_fac_dsg_upd ;
}

void Dsg_Update_work(void)
{
	// if (f_chg_last2 == 0 && f_charge == 1) // 在任何温度？
	// {
	// 	f_start_add_chg = 1;
	// }

	// f_chg_last2 = 
	// if (f_start_add_chg == 1 && f_charge == 1)
	if ( f_charge == 1)
	{
		leiji += I_abs;
	}

	// 充着断了， 清除哪些标志位 。
	// 1. 温度设置为多少
	// 2. I_abs 设置值
	// if (CellTemp < 15)
	// {
	// f_ful_chg_once == 1 ) //(f_fullchg == ON && t_com0d == 100) // f_have_ever_fulchg

	if(t_com0d!=100)
	{
		f_ful_chg_once =0;
		if(!f_charge )
		{
			leiji = 0 ;
		}
	}
	// if ((f_ful_chg_once == 1) && (leiji/3600> t_com10*2) && (f_relax==0 && f_discharge!=0 )&&(t_com0d==100))
		 if ((f_ful_chg_once!=0 ) && (leiji/3600> t_com10*2) && (f_relax==0 && f_discharge!=0 )&&(t_com0d==100))  // test faster 
	{
		f_count3s_en = 1; // global parameter ;
	}


	// t_com3c_out =  f_ful_chg_once ;
	// t_com32_out =  count_3s_b;
	// t_com33_out =  f_count3s_en ;
	// t_com39_out = f_count3s_en_b ;
	// t_com3a_out   =  leiji/3600 ;

	if (((f_relax_last_dsgupdate_use != 0 || f_charge_last_dsgupdate_use != 0) && f_discharge != 0) && ((CellTemp_last_time_update - CellTemp >= 10) || (CellTemp - CellTemp_last_time_update >= 10)))
	{
		f_count3s_en_b = 1 ;
		// temperature condition ,no need rsoc  = 100 .
	}

	// f_discharge_last2 = f_discharge;  // put this outer if sentece will be better  ?

	if (((f_count3s_en!=0) || (f_count3s_en_b!=0) ) && (f_discharge!=0) && (I_abs > 300))
	{
		count_3s++;
		count_3s_b++;
		if((f_count3s_en_b!=0)&&(count_3s_b< 20) )  // temperature keep 5s  change > 10 degree 
		{
			if(!((CellTemp_last_time_update-CellTemp >= 10)||(CellTemp-CellTemp_last_time_update>=10)))
			{
				f_count3s_en_b = 0 ;
				count_3s_b = 0;
				count_3s = 0 ;
			}
		}

		if (count_3s >= 20 || count_3s_b >= 20 )
		{
			// save data :
			count_3s = 0;
			count_3s_b = 0 ;
			f_count3s_en = 0;
			f_count3s_en_b = 0 ;
			dsg_upfcc_keep_current = I_abs; // this time should be        save current
			// dsg_upfcc_keep_temp =  (t_com08-2731)/10; // save temperature
			dsg_upfcc_keep_temp = CellTemp  ;

			if (f_bigger_than_zero != 1) // if have dischg relearn updated ,use that conditon ,if not , use 25du condition
			{
				f_bigger_than_zero = 1;
				save_dsg_upd_fcc = t_com10;
				save_fac_dsg_upd = 1000;
			}
			Dsg_Update_FCC();
			CellTemp_last_time_update= CellTemp ;
			f_fulchg_dsg_updated = 1 ;
			// CellTemp_last_time_update= (t_com08-2731)/10 ;
			// to do function work .
			// save data  ?
		}
		// function start to work
	}
	else
	{
		count_3s = 0;
		count_3s_b = 0;
	}
	//


	f_discharge_last2 = f_discharge;
	f_relax_last = f_relax ;
	f_relax_last_dsgupdate_use = f_relax ; 
	f_charge_last_dsgupdate_use = f_charge ;

	// t_com31_out =  count_3s ;
	// t_com32_out =  count_3s_b;
	// t_com33_out =  f_count3s_en ;
	// t_com39_out = f_count3s_en_b ;
	// t_com3a_out   =  leiji/3600 ;

} 



// void Calc_Temp_Rsoc(uint16_t Voltage_temp)
// {
// 	uint8_t	aidx; 
// 	for( aidx=0;  Voltage_temp>= OCV_SOC[aidx+1] && aidx < 19; aidx++ );
// 	if( Voltage_temp <= OCV_SOC[0] )							// Smaller than 0% voltage ?
// 	{
// 		temp_Si_rsoc= 0 ;
// 	} 
// 	else 
// 	{
// 		if( Voltage_temp >= OCV_SOC[20] )						// Bigger than 100% voltage ?
// 		{
// 			// if(f_fullchg == ON)
// 			// {														
// 				temp_Si_rsoc = 100 ;
// 			// }
// 			// else
// 			// {
// 			// 	temp_rsoc = 99 ;
// 			// }
// 		} 
// 		else
// 		{													// Not 0% and Not 99%
// 			// aresult = (uint8_t)((long)(INITCAP_TBL[aidx+1] - 5*aidx)
// 			// 			* (V_min - INITV_TBL[aidx])
// 			// 			/ (INITV_TBL[aidx+1] - INITV_TBL[aidx])
// 			// 			+ 5*aidx);
// 			temp_Si_rsoc = (uint8_t)(( Voltage_temp - OCV_SOC[aidx])*5/(OCV_SOC[aidx+1] - OCV_SOC[aidx]))+(5*aidx);
// 		}
// 	}
// }

// void Calc_Vol_Cha(void)
// {
// 	float Chazuo  ;
// 	float Chayou  ;
// 	uint16_t DOD  ; 

// 	float temp_t_com31_out  ;
// 	float temp_t_com32_out  ;

// 	float Calc_Vol_Cha_a1 = -0.0568  ; 
// 	float Calc_Vol_Cha_b1 =  3.9363  ; 
// 	float Calc_Vol_Cha_c1 = 2.6427   ;

// 	float Calc_Vol_Cha_a2 =  -0.0174 ; 
// 	float Calc_Vol_Cha_b2 =  1.2454  ; 
// 	float Calc_Vol_Cha_c2 = 49.5613  ;

// 	DOD = 100 - temp_Si_rsoc  ; 
// 	temp_t_com31_out= DOD*DOD*(-0.0568) ;
// 	temp_t_com31_out = (uint16_t)(temp_t_com31_out*100) ; 
// 	// t_com31_out = (uint16_t)temp_t_com31_out ;

// 	temp_t_com32_out = DOD*(Calc_Vol_Cha_b1) ;
// 	// t_com32_out = (uint16_t)temp_t_com32_out ;

// 	Chazuo =DOD*DOD*(Calc_Vol_Cha_a1) +DOD*(Calc_Vol_Cha_b1) +Calc_Vol_Cha_c1  ;
// 	Chayou =DOD*DOD*(Calc_Vol_Cha_a2)  +DOD*(Calc_Vol_Cha_b2) +Calc_Vol_Cha_c2  ;

// 	if(DOD<=34)
// 	{
// 		Voltage_new_Si =(uint16_t) (Chazuo +Voltage() );
// 	}else
// 	{
// 		Voltage_new_Si =(uint16_t)(Chayou +Voltage() ) ;
// 	}
// }

// void Calc_Si_Soc(void)
// {
// 	Calc_Temp_Rsoc(V_min);
// 	Calc_Vol_Cha() ;
// 	Calc_Temp_Rsoc(Voltage_new_Si);
// 	// t_com39_out =  temp_Si_rsoc_out ;
// }




/*""FUNC COMMENT""**********************************************************
* ID				: 1.0
* module outline	: RelativeStateOfCharge() Calculation Function
*--------------------------------------------------------------------------
* Include			: 
*--------------------------------------------------------------------------
* Declaration		: void Calc_RSOC(void)
*--------------------------------------------------------------------------
* Function			: Calculate RelativeStateOfCharge()
*					: 
*--------------------------------------------------------------------------
* Argument			: None
*--------------------------------------------------------------------------
* Return			: None
*--------------------------------------------------------------------------
* Input			: None
*					: 
* Output			: t_com0d	: RelativeStateOfCharge()
*					: 
*--------------------------------------------------------------------------
* Used function	: 
*					: 
*--------------------------------------------------------------------------
* Caution			: 
*--------------------------------------------------------------------------
*""FUNC COMMENT END""*****************************************************/
void Calc_RSOC(void)
{
	volatile uint16_t twork;
	// RSOC = RemainingCapacity / FullChargeCapacity * 100
	// Calc RSOC and store to temporary area.
	// The result is rounded off.
	// Calc_Si_Soc();

	twork = (uint16_t)(((((long)t_com0f * 200)*10 / t_com10) + 10)/2);

	if(!f_charge)  // use on computer , if charge , sishewuru .
	{
		// twork = (uint16_t)(((((long)t_com0f * 200)*10 / t_com10 ) + 20) / 2);  
		// if jin1 , will soc will not become  0
		//  twork = (uint16_t)((((long)t_com0f *200)*10/t_com10)/ 2);
		//  if (twork >= 7)
		//  {
		// 	 twork += 3;
		//  }
		if(twork >=10)
		{	
			twork += 5 ;
		}

		// twork = (uint16_t)(((((long)t_com0f * 200)*10 / t_com10 ) + 20) / 2);   // jin 1 
		// twork = (uint16_t)((((long)t_com0f * 200)*10 / t_com10 ) / 2);   // sishewuru  1.0001-1.0000009 = 1 
	}


	if(twork > 995)
	{
		if(D_SBS_Gauging_Configuration_RSOCL == ON)							// More than 99% ?
		{
			if(f_VCT)
			{
				twork = 100;						// Set to 100% (Don't make >100)
			}
			else
			{
				twork = 99;
			}
		}
		else
		{
			twork /= 10;		
		}

	}
	else if(twork <= 10 && D_SBS_Gauging_Configuration_1PERCENT_HOLD)
	{
		if(Current() < 0 && f_discharge && f_relax == 0 )//f_discharge -->relax with delay
		{
			if(V_min > D_0PVOLT) 
			{
				if (t_com0d> 0)  // in case , when discharge , voltage raise up . still hold 1 
				{
					twork = 1;
				}else
				{
					twork = 0;
				}	
			}
			else  // V_min <= D_0PVOLTV
			{
				// if(VoltagetoRSOCcount >= D_Discharge_0_voltage_Delay-1)   // now time is 1s /time .
				// if (VoltagetoRSOCcount >= temptime_D_Discharge_0_voltage_Delay) // now time is 1s /time .
				// {
				// 	VoltagetoRSOCcount  = temptime_D_Discharge_0_voltage_Delay ;
					// VoltagetoRSOCcount = 0 ; 
					twork /= 10;
				// }
				// else
				// {
				// 	twork = 1;
				// }
				// twork = 1;
			}
		}
		else  // charge or relax 
		{
			twork /= 10;
			
		}
	}
	else
	{
		twork /= 10;
	}

	t_com0e = (uint16_t)((long)t_com0f*2000 / D_Design_Capacity_mAh + 10)/20; 

	if(t_com0e>100)
	{
		t_com0e=100 ;
	} 
	// t_com0e  ASOC 
	t_com0d = twork;							// Set to RSOC  RSOC 


	Dsg_Update_work();





	if(BatteryMode(CAPM) == ON)
	{
		t_com0fCap = (long)t_com0f*D_Design_Voltage/10000; //cWh
		// t_com10Cap = (long)t_com10*D_Design_Voltage/10000;//cWh
		if((long)t_com10*D_Design_Voltage%10000==0)
		{
			t_com10Cap = (long)t_com10*D_Design_Voltage/10000;

		}else{
			t_com10Cap = (long)t_com10*D_Design_Voltage/10000 + 1;
		}



		// t_com18 = (long)D_Design_Capacity_mAh*D_Design_Voltage/10000;//cWh  //20221110-YYT
		_DesignCapacity = (long)D_Design_Capacity_mAh*D_Design_Voltage/10000;//cWh  //20221110-YYT
		// t_com18 = (long)D_Design_Capacity_in_cWh;
		_RemainingCapacityAlarm = (long)D_Data_Remaining_Wh_Capacity_Alarm;//cWh
		BatteryMode(CAPM) = ON;
	}
	else
	{
		t_com0fCap = t_com0f;//mAh
		t_com10Cap = t_com10;//mAh
		// t_com18 = D_Design_Capacity_mAh;//mAh
		_DesignCapacity  =D_Design_Capacity_mAh ;
		_RemainingCapacityAlarm = D_Data_Remaining_Ah_Capacity_Alarm; // cWh//
		BatteryMode(CAPM) = OFF;
	}
	// if (f_discharge && f_init_first_time == 0)
	// {
	// 	if(t_com0d > t_com0dsoclast)
	// 	{
	// 		t_com0d = t_com0dsoclast;
	// 	}
	// }
	// t_com0dsoclast = t_com0d;
	// f_init_first_time = 0 ;

}

void Calc_iRSOC(void)
{
	 uint16_t twork;
	// RSOC = RemainingCapacity / FullChargeCapacity * 100
	// Calc RSOC and store to temporary area.
	// The result is rounded off.
	twork = (uint16_t)(((((long)t_com88 * 200)*10 / t_com89 ) + 10) / 2);

	if(twork > 995)
	{
		// D_SBS_Gauging_Configuration_RSOCL_gen = ON ;
		// if(D_SBS_Gauging_Configuration_RSOCL_gen == ON)							// More than 99% ?
		 if(D_SBS_Gauging_Configuration_RSOCL == ON)							// More than 99% ?  for test since 99 hold% can not write success
		{
			if(f_fullchg)
			{
				twork = 100;						// Set to 100% (Don't make >100)
			}
			else
			{
				twork = 99;
			}
		}
		else
		{
			twork /= 10;		
		}
	}
	else if(twork <= 10 && D_SBS_Gauging_Configuration_1PERCENT_HOLD)
	{
		if(Current() < 0 && f_discharge)//f_discharge_gen -->relax with delay
		{
			// if(V_min >= D_Discharge_0_voltage) // D_0PVOLT
			if(V_min >= D_0PVOLT)
			{
				twork = 1;
			}
			else
			{
				twork /= 10;
			}
		}
		else
		{
			twork /= 10;
		}
	}
	else
	{
		twork /= 10;
	}

	// t_com0e = (uint16_t)((long)t_com0f*2000 / D_Design_Capacity_mAh + 10)/20; 
	
	t_com8a = twork;							// Set to RSOC  IRsoc

	if(!f_charge)
	{
		if(t_com8a >irsoc_last)
		{
			t_com8a =irsoc_last ;
		}
	}
	irsoc_last = t_com8a;

	

	// if(D_Initial_Battery_Mode_CAPM == ON)   // to control not change 
	// {
	// 	t_com0fCap = (long)t_com0f*D_Design_Voltage/10000; //cWh
	// 	t_com10Cap = (long)t_com10*D_Design_Voltage/10000;//cWh
	// 	//t_com18 = (long)D_DCAP*D_DVOLT/10000;//cWh  //20221110-YYT
	// 	t_com18 = D_Design_Capacity_in_cWh;
	// 	_RemainingCapacityAlarm = (long)D_Data_Remaining_Wh_Capacity_Alarm*D_Design_Voltage/10000;//cWh
	// 	BatteryMode(CAPM) = ON;
	// }
	// else
	// {
	// 	t_com0fCap = t_com0f;//mAh
	// 	t_com10Cap = t_com10;//mAh
	// 	t_com18 = D_Design_Capacity_mAh_gen;//mAh
	// 	_RemainingCapacityAlarm = D_Data_Remaining_Ah_Capacity_Alarm;//cWh//
	// 	f_bm_CAPM = OFF;		
	// }
}

void chg_pinghua(void)
{
	if (f_charge == ON)
	{

		//  t_com0c  = current  t_com0a
		// t_com30 = Chargingvoltage   t_com15
		//  t_com08 = Volrage    t_com09
		// t_com2c  = rsoc   t_com0d
		//   t_com10 = RemainingCapacity  t_com0f

		if (V_max >(t_com15/4-D_PINGHUA_CHGVOL_THRESH )  && (Current()>=D_PINGHUA_CHGCUR_LOW &&Current()<=D_PINGHUA_CHGCUR_HIGH))
		{
			if (f_pinghua_conditon == 0)
			{
				temp_Current = Current();
				f_pinghua_conditon = 1;
				pinghua_soc_start = t_com0d;
			}
			//if (f_pinghua_conditon == 1 && buchang_conditon_cnt < D_PINGHUA_TIME) // must have this , or the next circle will not come in .
			if (f_pinghua_conditon == 1 && buchang_conditon_cnt < D_PINGHUA_TIME) // must have this , or the next circle will not come in .
			{
				buchang_conditon_cnt++; // condition reach  + 1
			}
			// if (f_pinghua_work == 0 && f_pinghua_conditon == 1 && buchang_conditon_cnt == 40 && (temp_Current - t_com0a >= D_PINGHUA_CUR_RANGE ))
			if (f_pinghua_work == 0 && f_pinghua_conditon == 1 && buchang_conditon_cnt >= 40 && (temp_Current - Current() >= D_PINGHUA_CUR_RANGE))
			// use conditon == 1 , in case come into again when condition reach
			{
				// about  100-t_com2c) * FCC /39
				f_pinghua_work = 1;
			}
			if (t_com0d < 100 && f_pinghua_work == 1)
			{
				// chg_pinghua_current = (uint32_t)(100 - pinghua_soc_start) * t_com0f/D_CHG_PINGHUA_FACTOR; // chg_buchang_value = (100-t_com2c) * FCC /100 *3600 /1400;
				// 	  // can not use 100 -t_com2c , it will make the real less .   cur = cap / t .
				chg_pinghua_current = (uint32_t)(100 - pinghua_soc_start) * t_com10/D_PINGHUA_CAP;
			}
			else
			{
				f_pinghua_work = 0; // control rsoc = 100  // use this control outer function ,can not delete
			}
		}
		else
		{
			f_pinghua_conditon = 0;
			f_pinghua_work = 0;
			buchang_conditon_cnt = 0;
		}
	}
	else
	{
		f_pinghua_conditon = 0;
		f_pinghua_work = 0;
		buchang_conditon_cnt = 0;
	}
}
/*""FUNC COMMENT""***************************************************
* ID			: 1.0
* module outline: Function of relearn capacity calculation while
*				:  discharging and voltage is lower than CP_H.
*-------------------------------------------------------------------
* Include		: 
*-------------------------------------------------------------------
* Declaration	: void Calc_CP1RelRC(uint32_t lrc)
*-------------------------------------------------------------------
* Function		: CP_H,CP_L
*				: It calculates relearn capacity while discharging 
*				:  and the voltage is smaller than CP_H and higher 
*				:  than CP_L.
*-------------------------------------------------------------------
* Argument		: uint32_t	: Decrease capacity
*-------------------------------------------------------------------
* Return		: None
*-------------------------------------------------------------------
* Input			: None
* Output		: lrccr_w : Charge relearning integration work
*				: lrcdr_w : Discahrge relearning integration work
*-------------------------------------------------------------------
* Used function 	: 
*-------------------------------------------------------------------
* Caution		: 
*-------------------------------------------------------------------
* History		: 2012.08.01 Ver 0.01
* 				: New create
*""FUNC COMMENT END""**********************************************/
void Calc_CP1RelRC(uint32_t lrc)
{
	long	lwork;

	lrccr_w -= lrc;								// Integrate chg relearn cap.
	if( lrccr_w < 0 )							// Underflow ?
	{
		lrccr_w = 0;							// Set 0
	}
	
	lwork = (long)t_com10  * D_CP_L * 144;		// Calculate CP_L capacity
	
	if( lrccr_w < lwork )						// Chg relearn cap. < CPL cap ?
	{
		lrccr_w = lwork;						// Chg relearn cap = CPL cap
	}
	
	if( f_study_d == ON )						// Now discharge relarning ?
	{
		lrcdr_w += lrc;							// Integrate discharge rel.cap.
	}
}

/*""FUNC COMMENT""***************************************************
* ID				: 1.0
* module outline	: Function of capacity calculation while
*					:  discharging and voltage is lower than CP_H.
*-------------------------------------------------------------------
* Include			: 
*-------------------------------------------------------------------
* Declaration		: void Calc_HoseiRC(uint32_t lrc)
*-------------------------------------------------------------------
* Function			: CP_H
*					: It calculates capacity while discharging and 
*					: the voltage is lower than CP_H.
*-------------------------------------------------------------------
* Argument			: uint32_t	: Decrease capacity
*-------------------------------------------------------------------
* Return			: None
*-------------------------------------------------------------------
* Input				: None
* Output			: Record_lrc_w		: RC integration work
*-------------------------------------------------------------------
* Used function 	: 
*-------------------------------------------------------------------
* Caution			:
*-------------------------------------------------------------------
* History			: 2012.08.01 Ver 0.01
* 					: New create
* 
*""FUNC COMMENT END""**********************************************/
void Calc_HoseiRC(uint32_t	lrc)
{
	long	lwork;
	// if( Record_lrc_w != lrccr_w )						// Correction cap. != Chg rel.cap ?
	static uint8_t  Count_13s_rsoc_2  ;
	// {
	// 	if( lrccr_w < 16 )						// Charge rel.cap = 0 ?
	// 	{
	// 		lrc *= 2;							// Correction coefficient = 2
	// 	} 
	// 	else 
	// 	{										// Calc correction coefficient
	// 		lrc = (uint16_t)(((Record_lrc_w / (lrccr_w / 16)) * lrc ) / 16);
	// 	}
	// }
	
	// Record_lrc_w -= lrc;								// Subtruct correction value


	if( f_cp_l == OFF )							// CP_L not detected ?
	{
		// Record_lrc_w -= lrc;								// Subtruct correction value
		//if (lrc_w <= t_com10 * 18) // t_com10/36 / 10 * 2 =  0.2 rsoc  FCC *3600 * /100/2=fcc*1/100/2*3600  
		//muti 18*4

		if (t_com0d <= D_CP_L)
		{
			Record_lrc_w -= (lrc*2/3); // Subtruct correction value  18*3600
		}
		else
		{
			Record_lrc_w -= lrc; // Subtruct correction value  18*3600
		}
  // can not less than 0.5 fcc , cause will cal rc / fcc , can not hold 1 
		if (Record_lrc_w <= t_com10 * 80) // t_com10/36 / 10 * 2 =  0.2 rsoc  FCC *3600 * /100/2=fcc*1/100/2*3600 
		{
			Record_lrc_w  = t_com10 * 80; // 40 is right number ,since t_com10*36/3600 ,maybe rsoc == 0 ;
		}
		if (lrc_w_last <= t_com10 * 80) // signle  (lrc_w_last <= t_com10 * 18)
		{
			lrc_w_last = t_com10 * 80; // 40 is right number ,since t_com10*36/3600 ,maybe rsoc == 0 ;
		}
		// lwork = (long)t_com10  * D_CP_L * 144;	// Calculation the CP_L capacity
		// if( Record_lrc_w < lwork )						// less than CP_L ?
		// {
		// 	Record_lrc_w = lwork;						// hold on CP_L capacity
		// }  
		// this function makes 3% to 0% directly 
	} 	
	else
	{									// CP_L detected ?


		if( f_cp_l_last == OFF)  // to do clear 0 .  / can come here , must means this time cpl ON . 
		{
			// dis_fcc = t_com0d / 5.5;    // enlarge 100 times .  100/5.5*t_com0d  = 18.2 about 18 
			// dis_fcc = (t_com0d-1 )/ 6;    // enlarge 100 times .  100/5.5*t_com0d  = 18.2 about 18 
			// dis_fac_cpl = t_com0d*18 +t_com0d/5  ;              // discharge factor when reach cpl .
			// dis_fac_cpl = (t_com0d-1)*DSG_SMOOTH_MUL +(t_com0d-1)*6/DSG_SMOOTH_DIV ;              // discharge factor when reach cpl .
			// if((t_com0d==7)||(t_com0d==6)|| (t_com0d==1))
			// {
			// 	dis_fac_cpl = 100  ;
			// }

			dis_fac_cpl = t_com0d*DSG_SMOOTH_MUL +t_com0d/DSG_SMOOTH_DIV ;   

// 	uint16_t t_com31_out ;
// uint16_t t_com32_out ;
// uint16_t t_com33_out ;
			if (t_com0d < D_CP_L) // t_com0d = rsoc  D_CP_L = 6 ;
			{
				if (dis_fac_cpl < 30)
				{
					dis_fac_cpl = 30 ; // Subtruct correction value
				}
				else if( dis_fac_cpl >= 109 ) // 5---92
				{
					dis_fac_cpl= 100 ;
				}
			}
			else if (t_com0d > D_CP_L)
			{
				if (dis_fac_cpl <= 109)
				{
					dis_fac_cpl = 100 ; // Subtruct correction value
				}
				else if (dis_fac_cpl >= 400) // 5---92
				{
					dis_fac_cpl = 400;
				}
			}else
			{
				dis_fac_cpl = 100 ;
			}
		}
 
		// t_com32_out = dis_fac_cpl ;
		// t_com33_out =lrc ;
		Record_lrc_w  -= dis_fac_cpl*lrc/100;   // muti 

		// t_com39_out = Record_lrc_w /3600/4 ;

	
		// 使用 除余的方式？

		if (t_com0d != 0)
		{
			if (Record_lrc_w <= t_com10 * 80)
			{
				Record_lrc_w = t_com10 * 80; // Set 0
			}
			if (lrc_w_last <= t_com10 * 80)
			{
				lrc_w_last = t_com10 * 80; // 40 is right number ,since t_com10*36/3600 ,maybe rsoc == 0 ;
			}
		}else
		{
			Record_lrc_w = 0 ;
			lrc_w_last  = 0 ; 
		}

		if (V_min> D_0PVOLT) // D_0PVOLT =t_com33
		{
			if (t_com0d != 0)
			{
				if (Record_lrc_w <= t_com10*80)
				{
					Record_lrc_w = t_com10 *80; // Set 0
				}
				if (lrc_w_last <= t_com10 * 80)
				{
					lrc_w_last = t_com10 * 80; // 40 is right number ,since t_com10*36/3600 ,maybe rsoc == 0 ;
				}
			}else  // t_com0d soc == 0 ; 
			{
				if (!f_charge)
				{
					Record_lrc_w = 0;
					lrc_w_last = 0;
				}
			}
		}
		else 
		{

			if (t_com0d == 0)
			{
				if (!f_charge)
				{
					Record_lrc_w = 0;
					lrc_w_last = 0;
				}
			}

			if (Record_lrc_w <= 0)
			{
				Record_lrc_w = 0; // Set 0
			}
			if(lrc_w_last  <= 0)
			{
				lrc_w_last = 0; // 40 is right number ,since t_com10*36/3600 ,maybe rsoc == 0 ;
			}
		}



		if ((V_min <= D_0PVOLT + 20) && (t_com0d > 2))
		{
			//  Count_13s_rsoc_2 =  0 ;
			Count_13s_rsoc_2++ ;
			if (Count_13s_rsoc_2 >= D_Discharge_0_voltage_Delay*4 )
			{
				Count_13s_rsoc_2 = 0;	
				// Record_lrc_w = t_com10*0.02* 3600*4;    // rc
				Record_lrc_w = t_com10 * 288; // rc  
				lrc_w_last = Record_lrc_w;
			}
		}else
		{
			// Count_13s_rsoc_1 =  0 ;
			Count_13s_rsoc_2 =  0 ;
		}





	
		if ((V_min <= D_0PVOLT + 10) && (t_com0d > 1))
		{
			Count_13s_rsoc_1++ ;
			if (Count_13s_rsoc_1 >= D_Discharge_0_voltage_Delay*4 )
			{
				Count_13s_rsoc_1 = 0;				  // Clear the counte
				Record_lrc_w = t_com10 * 144; // rc  
				lrc_w_last = Record_lrc_w;
			}

		}else
		{
			Count_13s_rsoc_1 =  0 ;
			// Count_13s_rsoc_2 =  0 ;
		}

		// if (Voltage() >= D_Discharge_0_voltage) // D_0PVOLT  D_Discharge_0_voltage
		if (V_min > D_0PVOLT)
		{
			if (t_com0d != 0)
			{
				if (Record_lrc_w <= t_com10 * 80)
				{
					Record_lrc_w = t_com10 *80; // Set 0
				}
				if (lrc_w_last <= t_com10 * 80)
				{
					lrc_w_last = t_com10 * 80; // 40 is right number ,since t_com10*36/3600 ,maybe rsoc == 0 ;
				}
			}
			else  //  (V_min > D_0PVOLT)  && soc == 0 
			{
				if (!f_charge)
				{
					Record_lrc_w = 0;
					lrc_w_last = 0;
				}
			}
		}
		else //  V_min <= D_0PVOLT 
		{
			if(t_com0d==0 )
			{
				if (!f_charge)
				{
					Record_lrc_w = 0;
					lrc_w_last = 0;
				}
			}

			if (Record_lrc_w <= 0)
			{
				Record_lrc_w = 0; // Set 0
			}
			if(lrc_w_last  <= 0)
			{
				lrc_w_last = 0; // 40 is right number ,since t_com10*36/3600 ,maybe rsoc == 0 ;
			}
		}
	}

	if (Record_lrc_w <= 0)
	{
		Record_lrc_w = 0; // Set 0
	}
	if (lrc_w_last <= 0)
	{
		lrc_w_last = 0; // 40 is right number ,since t_com10*36/3600 ,maybe rsoc == 0 ;
	}
}


void Calc_factor_of_fcc(int16_t CellTempb)
{
	uint8_t aidx;
	uint8_t awork1, awork2, awork3, awork4;
	uint16_t twork1, twork2;
	uint16_t tinreg;
	int32_t ccwork;
	int32_t dcwork;

	// Calc [C]x100 from current
	// twork1 = (uint16_t)((long)I_abs * 100 / D_DCAP); // eg :   3600 mAh  = 3600mA * 1h
	twork1 = (uint16_t)((long)I_abs * 100 / D_Design_Capacity_mAh);
	// - Make [C]index -
	// linear interporation: y = (y2-y1)*(x-x1)/(x2-x1) + y1
	//						   = y1 - (y1-y2)*(x-x1)/(x2-x1)
	// awork1: x-x1
	// awork2: x2-x1
	if (twork1 <= D_CRATE_TBL[1]) // <= C-rate2 ?
	{
		aidx = 0;					  // Table index = 0
		if (twork1 <= D_CRATE_TBL[0]) // <= C-rate1 ?
		{
			awork1 = 0; // SetC-rate1
		}
		else
		{ // > C-rate1
			// Calculate value index
			awork1 = (uint8_t)(twork1 - D_CRATE_TBL[0]);
		}

		// Data area is within C-rate1 to C-rate2
		awork2 = D_CRATE_TBL[1] - D_CRATE_TBL[0];
	}
	else
	{								  // > C-rate2
		if (twork1 <= D_CRATE_TBL[2]) // <= C-rate3 ?
		{
			aidx = 5; // Table index = 5
			// Calculate value index
			awork1 = (uint8_t)(twork1 - D_CRATE_TBL[1]);
			// Data area is within C-rate2 to C-rate3
			awork2 = D_CRATE_TBL[2] - D_CRATE_TBL[1];
		}
		else
		{			   // > C-rate3
			aidx = 10; // Table index = 10
			twork1 = twork1 - D_CRATE_TBL[2];
			if (twork1 > 255) // bigger than 1byte value ?
			{
				awork1 = 255; // Set max value
			}
			else
			{
				awork1 = (uint8_t)twork1;
			}
			// Data area is within C-rate3 to C-rate4
			awork2 = D_CRATE_TBL[3] - D_CRATE_TBL[2];
		}
	}

	// - Make Temperature index -
	awork3 = CellTempb- D_TRATE_TBL[0]; // Make the value of T-rate1 base
	if (CellTempb >= D_TRATE_TBL[1])		// >= T-rate2 ?
	{
		aidx++;							// Increment table index
		if (CellTempb >= D_TRATE_TBL[2]) // >= T-rate3 ?
		{
			aidx++;							// Increment table index
			if (CellTempb >= D_TRATE_TBL[3]) // >= T-rate4 ?
			{
				aidx++; // Increment table index
						// Data area is within T-rate4 to T-rate5
				awork4 = D_TRATE_TBL[4] - D_TRATE_TBL[3];
				if (CellTempb >= D_TRATE_TBL[4]) // >= T-rate5 ?
				{
					awork3 = awork4; // Value index is max value
				}
				else
				{ // T-rate4 <= Temp. < T-rate5
				  // Calculate value index
					awork3 = CellTempb - D_TRATE_TBL[3];
				}
			}
			else
			{ // T-rate3 <= Temp. < T-rate4
			  // Data area is within T-rate3 to T-rate4
				awork4 = D_TRATE_TBL[3] - D_TRATE_TBL[2];
				// Calculate value index
				awork3 = CellTempb - D_TRATE_TBL[2];
			}
		}
		else
		{ // T-rate2 <= Temp. < T-rate3
			// Data area is within T-rate2 to T-rate3
			awork4 = D_TRATE_TBL[2] - D_TRATE_TBL[1];
			awork3 = CellTempb - D_TRATE_TBL[1]; // Calculate value index
		}
	}
	else
	{ // < T-rate2
		// Data area is within T-rate1 to T-rate2
		awork4 = D_TRATE_TBL[1] - D_TRATE_TBL[0];

		if (CellTempb <= D_TRATE_TBL[0]) // <= T-rate1 ?
		{
			awork3 = 0; // Value index = 0
		}
	}

	if (aidx >= 10 && awork1 > awork2) // > C-Rate4 ?
	{
		// Calculate by coefficient
		// twork1 = QCAP_TBL[aidx + 5] - // Coefficient/((C-rate4 - C-rate3)*10
		// 		 (uint16_t)((((long)QCAP_TBL[aidx] - QCAP_TBL[aidx + 5]) * (awork1 - awork2) * D_FCCCOE / ((uint16_t)awork2 * 10)));

		// twork2 = QCAP_TBL[aidx + 6] -
		// 		 (uint16_t)((((long)QCAP_TBL[aidx + 1] - QCAP_TBL[aidx + 6]) * (awork1 - awork2) * D_FCCCOE / ((uint16_t)awork2 * 10)));
		twork1 = QCAP_TBL[aidx + 5] - // Coefficient/((C-rate4 - C-rate3)*10
				 (uint16_t)((((long)QCAP_TBL[aidx] - QCAP_TBL[aidx + 5]) * (awork1 - awork2) * D_CP_FCC_Coefficcient / ((uint16_t)awork2 * 10)));

		twork2 = QCAP_TBL[aidx + 6] -
				 (uint16_t)((((long)QCAP_TBL[aidx + 1] - QCAP_TBL[aidx + 6]) * (awork1 - awork2) * D_CP_FCC_Coefficcient / ((uint16_t)awork2 * 10)));
	}
	else
	{ // <= C-Rate4
		twork1 = QCAP_TBL[aidx] -
				 (uint16_t)((((long)QCAP_TBL[aidx] - QCAP_TBL[aidx + 5]) * awork1 / awork2));

		twork2 = QCAP_TBL[aidx + 1] -
				 (uint16_t)((((long)QCAP_TBL[aidx + 1] - QCAP_TBL[aidx + 6]) * awork1 / awork2));
	}

	Record_Dischargefactor = twork1 + (uint16_t)((((long)twork2 - twork1) * awork3 / awork4)); // discharge Q

	if (Record_Dischargefactor)
	{
		save_fac_dsg_upd = Record_Dischargefactor ;
		// save_dsg_upd_fcc = t_com10 ;
	}
}


/*""FUNC COMMENT""***************************************************
* ID			: 1.0
* module outline: FCC up/down limit check function
*-------------------------------------------------------------------
* Include		: 
*-------------------------------------------------------------------
* Declaration	: void FCC_Limit_Chk(void)
*-------------------------------------------------------------------
* Function		: FCC Limit
*				: Check the limit of FCC up/down
*-------------------------------------------------------------------
* Argument		: None
*-------------------------------------------------------------------
* Return		: None
*-------------------------------------------------------------------
* Input			: None
* Output		: tcom10c_w : FCC temporary
*------------------------------------------------------------------- 
* Used function : 
*-------------------------------------------------------------------
* Caution		: 
*-------------------------------------------------------------------
* History		: 2012.08.01 Ver 0.01
* 				: New create
* 
*""FUNC COMMENT END""**********************************************/
void FCC_Limit_Chk(void)
{
	uint16_t	twork;												// Calculate FCC limi												// Normal spec
	uint16_t fccmaxlimit_new ;												// Normal spec
	uint16_t IdealFcclimit_new ;	
	Calc_factor_of_fcc(CellTemp);
	twork = D_FCC_variance;
	// fccmaxlimit_new  = D_FCCMAXLIMIT *(Record_Dischargefactor/1000)
	// + D_FCCMAXLIMIT/10 *(Record_Dischargefactor%1000/100)
	// + D_FCCMAXLIMIT/100*(Record_Dischargefactor%100/10)
	// + D_FCCMAXLIMIT/1000*(Record_Dischargefactor%10/1) ;

	fccmaxlimit_new  = D_FCCMAXLIMIT ;  //  make it into  max ， prevent ,no need mutiply factor .
	// fccmaxlimit_new  = 5500*(Record_Dischargefactor/1000) \
	// + 6000 *(Record_Dischargefactor%1000/100)\uint16_t 
	// + 6000/100*(Record_Dischargefactor%100/10)\
	// + 6000/1000*(Record_Dischargefactor%10/1) ;()

	// IdealFcclimit_new  = (uint32_t)(t_com89*(Record_Dischargefactor/1000)\
	// + t_com89/10 *(Record_Dischargefactor%1000/100)\
	// + t_com89/100*(Record_Dischargefactor%100/10)\
	// + t_com89/1000*(Record_Dischargefactor%10/1) );

	if (tcom10c_w < t_com10) // relearn cap < FCC ?
	{
		if ((t_com10 - tcom10c_w) > twork) // Is diff larger than limit ?  // middle 256
		{
			tcom10c_w = t_com10 - twork; // FCC = FCC - limit
		}
			// if (tcom10c_w > fccmaxlimit_new) // 限制FCC
			// {
			// 	tcom10c_w = fccmaxlimit_new;
			// }
	}
									   // relearn cap >= FCC
										   // Normal spec
		if ((tcom10c_w - t_com10) > twork) // Is diff larger than limit ?
		{
			tcom10c_w = t_com10 + twork; // FCC = FCC + limit
			// if (tcom10c_w > IdealFcclimit_new) // 限制FCC
			// {
			// 	tcom10c_w = IdealFcclimit_new;
			// }
		}

		if (CellTemp > TEMPER_LIMIT_T2)
		{
			if (tcom10c_w > D_FCCMAXLIMIT)
			{
				tcom10c_w = D_FCCMAXLIMIT;
			}
		}
		if ((CellTemp >= TEMPER_LIMIT_T1) && (CellTemp <= TEMPER_LIMIT_T2))
		{
			if (tcom10c_w > D_FCCMAXLIMIT - TEMPER_LIMIT_CAP2)
			{
				tcom10c_w = D_FCCMAXLIMIT - TEMPER_LIMIT_CAP2;
			}
		}
		if (CellTemp < TEMPER_LIMIT_T1)
		{
			if (tcom10c_w > D_FCCMAXLIMIT - TEMPER_LIMIT_CAP1)
			{
				tcom10c_w = D_FCCMAXLIMIT - TEMPER_LIMIT_CAP1;
			}
		}

		if (tcom10c_w < D_FCCMINLIMIT)
		{
			tcom10c_w = D_FCCMINLIMIT;
		}

	// if (tcom10c_w > fccmaxlimit_new ) // IdealFcclimit_new  (normal value )<  fccmaxlimit_new (big value )
	// {
	// 	if (tcom10c_w > fccmaxlimit_new ) // 限制FCC
	// 	{
	// 		tcom10c_w = fccmaxlimit_new;
	// 	}
	// }
	// else if (tcom10c_w <  D_FCCMINLIMIT) // (tcom10c_w < D_FCCMINLIMIT) 
	// {
	// 	tcom10c_w = D_FCCMINLIMIT ;  // tcom10c_w = D_FCCMINLIMIT;
	// }
	// else
	// {
	// 	if (tcom10c_w < t_com10) // relearn cap < FCC ?  
	// 	{
	// 		if ((t_com10 - tcom10c_w) > twork) // Is diff larger than limit ?  // middle 256 
	// 		{
	// 			tcom10c_w = t_com10 - twork; // FCC = FCC - limit
	// 		}else
	// 		{
	// 			if (tcom10c_w > IdealFcclimit_new) // IdealFcclimit_new  (normal value )<  fccmaxlimit_new (big value )
	// 			{
	// 				if (tcom10c_w > IdealFcclimit_new) // 限制FCC
	// 				{
	// 					tcom10c_w = IdealFcclimit_new;
	// 				}
	// 			}
	// 		}
	// 	}
	// 	else
	// 	{									   // relearn cap >= FCC
	// 										   // Normal spec
	// 		if ((tcom10c_w - t_com10) > twork) // Is diff larger than limit ?
	// 		{
	// 			tcom10c_w = t_com10 + twork; // FCC = FCC + limit
	// 		}
	// 	}
	// }
}

/*""FUNC COMMENT""***************************************************
* ID				: 1.0
* module outline	: Discharge relearning function
*-------------------------------------------------------------------
* Include			: 
*-------------------------------------------------------------------
* Declaration		: void Make_Relearning(uint8_t acp)
*-------------------------------------------------------------------
* Function			: 
*					: Function of discharge relearning.
*-------------------------------------------------------------------
* Argument			: uint8_t	: Correction point
*-------------------------------------------------------------------
* Return			: None
*-------------------------------------------------------------------
* Input				: None
* Output			: tcom10c_w : FCC temporary
*-------------------------------------------------------------------
* Used function 	: FCC_Limit_Chk()
*-------------------------------------------------------------------
* Caution			: 
*-------------------------------------------------------------------
* History			: 2012.08.01 Ver 0.01
* 					: New create
* 
*""FUNC COMMENT END""**********************************************/
void Make_Relearning(uint8_t acp)
{
	uint16_t	twork;	
	uint16_t Fccfar;
	
	if( (f_study_d == ON && f_study_d1 == ON )						// Discharge relearning = ON
		&& (Ts_max>=D_FCC_relearn_temp_limit) )				// & Temp >= Relearn temp ?
	{
		f_relearn = OFF;						// Clear Relearn flag
		arelearn_cnt = 0;						// Clear Relearn counter
												// Calc FCC by discharge relearn capacity
		// newFCC = relearn capcity * (100 / (100-CP_x)) / 4*60*60
		//		  = relearn capacity / ( (100-CP_x) * 144 )
		// tcom10c_w = (uint16_t)(lrcdr_w/(((uint16_t)100-acp)*144));
		tcom10c_w = (uint16_t)(lrcdr_w/ 14400 +(t_com10 / 10 * acp / 10));  // leiji + fcc*rsoc
		FCC_Limit_Chk();						// FCC Limit check

		if( D_Control_flag_1_FCC_Update_delaying == OFF )					// Update FCC at CP detect ?
		{
			t_com10  = tcom10c_w;				// Set FCC
		} 
		else
		{										// Update FCC at start chg.
			f_studied = ON;						// Set studied flag
		}
		t_com17_w = _CycleCount;						// Set CycleCount
//											   	// Save CycleCount at relearn

		// cph  do not update idea fcc .
		// Fccfar = (uint32_t)tcom10c_w * 10000 / Record_Dischargefactor * 10 / t_com89;
		// t_com88 = (uint32_t)t_com88 * Fccfar / 100;
		// Record_Ilrc_w = (uint32_t)t_com88 * (60 * 60*4);   // X4  ?? 
		// t_com89 = (uint32_t)tcom10c_w * 1000 / Record_Dischargefactor;

		f_cp_h_fccupdated = 1;
		lrc_w_last  = Record_lrc_w ;
		//  clr_flg_fulchg_update();
		save_dsg_upd_fcc = tcom10c_w;
		f_bigger_than_zero = 1;
		Calc_factor_of_fcc( CellTemp); // update fcc , fcc factor and save into  save_fac_dsg_upd
		CellTemp_last_time_update= CellTemp ;
		// CellTemp_last_time_update= (t_com08-2731)/10 ;

		t_com31_out = save_fac_dsg_upd ;

	} 
	else 
	{											// Discharge relearning = OFF
												// FCC update when not relearn
												// Calculate degradation cap
		if( Record_trek_cnt != 0 && D_FCC_Deterioration_capacity != 0)		// degradation cnt is not 0 ?
		{
			twork = (uint16_t)(((long)Record_trek_cnt * D_FCC_Deterioration_capacity) / 100);
			if( t_com10  > twork )				// Under flow ?
			{
				tcom10c_w = t_com10  - twork;
			} 
			else 
			{							// Under flow
				tcom10c_w = 0;
			}
			
			f_studied = ON;						// Set studied flag
		}
	}
	Record_trek_cnt = 0;								// Clear degradation counter
	f_study_d1 = OFF;							// Clear discharge relearn flag
}


void Make_Relearning_cpl(uint8_t acp)
{
	uint16_t	twork;	
	uint16_t Fccfar;
	int16_t temperature_temp_use ; 
	uint16_t twork1 ;
	if( (f_study_d == ON && f_study_d2 == ON )						// Discharge relearning = ON
		&& (Ts_max>=D_FCC_relearn_temp_limit) )				// & Temp >= Relearn temp ?
	{
		f_relearn = OFF;						// Clear Relearn flag
		arelearn_cnt = 0;						// Clear Relearn counter
												// Calc FCC by discharge relearn capacity
		// newFCC = relearn capcity * (100 / (100-CP_x)) / 4*60*60
		//		  = relearn capacity / ( (100-CP_x) * 144 )
		tcom10c_w = (uint16_t)(lrcdr_w/(((uint16_t)100-acp)*144));
		FCC_Limit_Chk();						// FCC Limit check

		if( D_Control_flag_1_FCC_Update_delaying == OFF )					// Update FCC at CP detect ?
		{
			t_com10  = tcom10c_w;				// Set FCC
		} 
		else
		{										// Update FCC at start chg.
			f_studied = ON;						// Set studied flag
		}
		
		t_com17_w = _CycleCount;						// Set CycleCount
//												// Save CycleCount at relearn
		// Fccfar = (uint32_t)tcom10c_w * 10000 / Record_Dischargefactor * 10 / t_com89;
		// t_com88 = (uint32_t)t_com88 * Fccfar / 100;
		
		t_com89 = (uint32_t)tcom10c_w * 1000 / Record_Dischargefactor;
		t_com88  = t_com89 *t_com8a / 100 ;
		Record_Ilrc_w = (uint32_t)t_com88 * (60 * 60*4);   



		// clr_flg_fulchg_update();
		// dsg_upfcc_keep_temp = CellTemp  ;
		// dsg_upfcc_keep_current = I_abs ;  // this time should be
		f_cp_l_fccupdated = 1 ;
		lrc_w_last  = Record_lrc_w ;
		save_dsg_upd_fcc = tcom10c_w;

		twork1 = (uint16_t)((long)I_abs * 100 / D_Design_Capacity_mAh);



		Calc_factor_of_fcc(CellTemp); // update fcc , fcc factor and save into  save_fac_dsg_upd

		t_com8b_out = save_fac_dsg_upd ;
		temperature_temp_use = CellTemp- K_UPDATE_FAC*twork1/100 ;
		t_com8c_out  =  temperature_temp_use ;

		if(temperature_temp_use <= 0  )
		{
			temperature_temp_use  =  1 ;
		}
	
		Calc_factor_of_fcc(temperature_temp_use); // update fcc , fcc factor and save into  save_fac_dsg_upd

		t_com8d_out = save_fac_dsg_upd ;

		f_bigger_than_zero = 1;
		//CellTemp_last_time_update= (t_com08 -2731)/10;
		CellTemp_last_time_update= CellTemp ; // 

	} 
	else 
	{											// Discharge relearning = OFF
												// FCC update when not relearn
												// Calculate degradation cap
		if( Record_trek_cnt != 0 && D_FCC_Deterioration_capacity != 0)		// degradation cnt is not 0 ?
		{
			twork = (uint16_t)(((long)Record_trek_cnt * D_FCC_Deterioration_capacity) / 100);
			if( t_com10  > twork )				// Under flow ?
			{
				tcom10c_w = t_com10  - twork;
			} 
			else 
			{							// Under flow
				tcom10c_w = 0;
			}
			
			f_studied = ON;						// Set studied flag
		}
	}
	
	Record_trek_cnt = 0;								// Clear degradation counter
	f_study_d = OFF;							// Clear discharge relearn flag
	f_study_d2 = OFF;							// Clear discharge relearn flag

}


/*""FUNC COMMENT""***************************************************
* ID			: 1.0
* module outline: Internal resistance calculation function
*-------------------------------------------------------------------
* Include		: 
*-------------------------------------------------------------------
* Declaration	: uint16_t Calc_InReg(void)
*-------------------------------------------------------------------
* Function		: 
*				: Calculate capacity correction voltage adjusting value
*				: by increasing the internal resistance.
*-------------------------------------------------------------------
* Argument		: None
*-------------------------------------------------------------------
* Return		: uint16_t	: Correction voltage
*-------------------------------------------------------------------
* Input			: None
* Output		: None
*-------------------------------------------------------------------
* Used function : 
*-------------------------------------------------------------------
* Caution		: 
*-------------------------------------------------------------------
* History		: 2012.08.01 Ver 0.01
* 				: New create
* 
*""FUNC COMMENT END""**********************************************/
uint16_t Calc_InReg(void)
{
	uint8_t	awork1,awork2;
	uint16_t	twork1,twork2;
	uint8_t	al1;
												// Search the index
	for( al1=0; _CycleCount>=INREG_CYCLE[al1] && al1<5; al1++ );
												// Set each correction data
	if( al1 == 0 )								// First index ?
	{
		awork1 = 0;
		awork2 = INREG_TBL[0];
		twork1 = _CycleCount;
		twork2 = INREG_CYCLE[0];
	} 
	else 
	{									// 2nd or more
		al1--;
		awork1 = INREG_TBL[al1];
		awork2 = INREG_TBL[al1+1] - INREG_TBL[al1];
		twork1 = _CycleCount - INREG_CYCLE[al1];
		twork2 = INREG_CYCLE[al1+1] - INREG_CYCLE[al1];
	}
	//Correction voltage[mV] = Internal resistance x Current / 1000
	return ((((long)awork2*twork1/twork2)+awork1)*I_abs/1000);	
}



// // uint16_t Calc_InRegFcc(void) no    INREG_CYCLE undeclared 
// {
// 	uint16_t awork1, awork2;
// 	uint16_t twork1, twork2;
// 	uint8_t al1;
// 	// Search the index
// 	for (al1 = 0; _CycleCount >= INREG_CYCLE[al1] && al1 < 5; al1++)   // _CycleCount cyclecount 
// 		;
// 	// Set each correction data
// 	if (al1 == 0) // First index ?
// 	{
// 		awork1 = 0;
// 		awork2 = INREG_FCC[0];
// 		twork1 = t_com2a;
// 		twork2 = INREG_CYCLE[0];
// 	}
// 	else
// 	{ // 2nd or more
// 		al1--;
// 		awork1 = INREG_FCC[al1];
// 		awork2 = INREG_FCC[al1 + 1] - INREG_FCC[al1];
// 		twork1 = _CycleCount - INREG_CYCLE[al1];
// 		twork2 = INREG_CYCLE[al1 + 1] - INREG_CYCLE[al1];
// 	}
// 	return (((uint32_t)awork2 * twork1 * 100 / twork2) + awork1 * 100);
// }



/*""FUNC COMMENT""***************************************************
* ID			: 1.0
* module outline: Correction voltage calculation function
*-------------------------------------------------------------------
* Include		: 
*-------------------------------------------------------------------
* Declaration	: void Calc_CPVolt(void)
*-------------------------------------------------------------------
* Function		: CP_H,CP_L
*				: Calculate correction voltage CP_H and CP_L.
*-------------------------------------------------------------------
* Argument		: None
*-------------------------------------------------------------------
* Return		: None
*-------------------------------------------------------------------
* Input			: None
* Output		: CP_H : Voltage of correction point high
*				: CP_L : Voltage of correction point low
*-------------------------------------------------------------------
*Used function 	: Calc_InReg()
*-------------------------------------------------------------------
* Caution		: 
*-------------------------------------------------------------------
* History		: 2012.08.01 Ver 0.01
* 				: New create
* 
*""FUNC COMMENT END""**********************************************/
void Calc_CPVolt(void)
{
	uint8_t	aidx;
	uint8_t	awork1,awork2,awork3,awork4;
	uint16_t	twork1,twork2;
	uint16_t	tinreg;
	int32_t ccwork;
	int32_t dcwork;

	//Calc [C]x100 from current
	twork1 = (uint16_t)((long)I_abs * 100 / D_Design_Capacity_mAh);
	
	// - Make [C]index -
	// linear interporation: y = (y2-y1)*(x-x1)/(x2-x1) + y1
	//						   = y1 - (y1-y2)*(x-x1)/(x2-x1)
	// awork1: x-x1
	// awork2: x2-x1
	if( twork1 <= D_CRATE_TBL[1] )				// <= C-rate2 ?
	{
		aidx = 0;								// Table index = 0
		if( twork1 <= D_CRATE_TBL[0] )			// <= C-rate1 ?
		{
			awork1 = 0;							// SetC-rate1
		} 
		else 
		{								// > C-rate1
			// Calculate value index
			awork1 = (uint8_t)(twork1-D_CRATE_TBL[0]);
		}
		
		// Data area is within C-rate1 to C-rate2
		awork2 = D_CRATE_TBL[1] - D_CRATE_TBL[0];
	} 
	else 
	{									// > C-rate2
		if( twork1 <= D_CRATE_TBL[2] )			// <= C-rate3 ?
		{
			aidx = 5;							// Table index = 5
			// Calculate value index
			awork1 = (uint8_t)(twork1 - D_CRATE_TBL[1]);
			// Data area is within C-rate2 to C-rate3
			awork2 = D_CRATE_TBL[2] - D_CRATE_TBL[1];
		}
		else 
		{								// > C-rate3
			aidx = 10;							// Table index = 10
			twork1 = twork1 - D_CRATE_TBL[2];
			if( twork1 > 255 )					// bigger than 1uint8_t value ?
			{
				awork1 = 255;					// Set max value
			} 
			else 
			{
				awork1 = (uint8_t)twork1;
			}
			// Data area is within C-rate3 to C-rate4
			awork2 = D_CRATE_TBL[3] - D_CRATE_TBL[2];
		}
	}
	
	// - Make Temperature index -
	awork3 = Ts_max - D_TRATE_TBL[0];			// Make the value of T-rate1 base
	if( Ts_max >= D_TRATE_TBL[1] )				// >= T-rate2 ?
	{
		aidx++;									// Increment table index
		if( Ts_max >= D_TRATE_TBL[2] )			// >= T-rate3 ?
		{
			aidx++;								// Increment table index
			if( Ts_max >= D_TRATE_TBL[3] )			// >= T-rate4 ?
			{
				aidx++;							// Increment table index
												// Data area is within T-rate4 to T-rate5
				awork4 = D_TRATE_TBL[4] - D_TRATE_TBL[3];
				if( Ts_max >= D_TRATE_TBL[4] )	// >= T-rate5 ?
				{
					awork3 = awork4;			// Value index is max value
				} 
				else 
				{						// T-rate4 <= Temp. < T-rate5
												// Calculate value index
					awork3 = Ts_max - D_TRATE_TBL[3];
				}
			} 
			else 
			{							// T-rate3 <= Temp. < T-rate4
												// Data area is within T-rate3 to T-rate4
				awork4 = D_TRATE_TBL[3] - D_TRATE_TBL[2];
				// Calculate value index
				awork3 = Ts_max - D_TRATE_TBL[2];
			}
		} 
		else 
		{								// T-rate2 <= Temp. < T-rate3
			// Data area is within T-rate2 to T-rate3
			awork4 = D_TRATE_TBL[2] - D_TRATE_TBL[1];
			awork3 = Ts_max - D_TRATE_TBL[1];	// Calculate value index
		}
	} 
	else 
	{									// < T-rate2
		// Data area is within T-rate1 to T-rate2
		awork4 = D_TRATE_TBL[1] - D_TRATE_TBL[0];
		
		if( Ts_max <= D_TRATE_TBL[0] )			// <= T-rate1 ?
		{
			awork3 = 0;							// Value index = 0
		}
	}

	tinreg = Calc_InReg();						// Calc internal resistance V


	// - Calculate CP_H voltage -
	// - [C] interpolation -
	if( (aidx >= 10) && (awork1>awork2) )			// > C-Rate 4 ?
	{
		// Calculate by coefficient
		twork1 = CPH_TBL[aidx + 5] - // Coefficient/((C-rate4 - C-rate3)*10
				 (uint16_t)(((long)CPH_TBL[aidx] - CPH_TBL[aidx + 5]) * (awork1 - awork2) * D_CP_CPH_Coefficcient / ((uint16_t)awork2 * 10));

		twork2 = CPH_TBL[aidx + 6] -
				 (uint16_t)((((long)CPH_TBL[aidx + 1] - CPH_TBL[aidx + 6]) * (awork1 - awork2) * D_CP_CPH_Coefficcient / ((uint16_t)awork2 * 10)));
	}
	else 
	{									// <= C-Rate 4
		twork1 = CPH_TBL[aidx] - 
					(uint16_t)((((long)CPH_TBL[aidx]-CPH_TBL[aidx+5])*awork1/awork2));
		
		twork2 = CPH_TBL[aidx+1] - 
					(uint16_t)((((long)CPH_TBL[aidx+1]-CPH_TBL[aidx+6])*awork1/awork2));
	}
	
	// - degC interpolation -
	tcph_v = twork1 + (uint16_t)(((long)twork2 - twork1)*awork3/awork4) - tinreg;
	 //tcph_v = 4000 ;
	// - Calculate CP_L voltage -
	// - [C] interpolation -
	if( aidx>=10 && awork1>awork2 )				// > C-Rate4 ?
	{
		// Calculate by coefficient
		twork1 = CPL_TBL[aidx+5] -				// Coefficient/((C-rate4 - C-rate3)*10
			(uint16_t)((((long)CPL_TBL[aidx]-CPL_TBL[aidx+5])*(awork1-awork2)*D_CP_CPL_Coefficcient/((uint16_t)awork2*10)));
		
		twork2 = CPL_TBL[aidx+6] -
			(uint16_t)((((long)CPL_TBL[aidx+1]-CPL_TBL[aidx+6])
				*(awork1-awork2)*D_CP_CPL_Coefficcient/((uint16_t)awork2*10)));
	} 
	else 
	{									// <= C-Rate4
		twork1 = CPL_TBL[aidx] - 
					(uint16_t)((((long)CPL_TBL[aidx]-CPL_TBL[aidx+5])*awork1/awork2));
		
		twork2 = CPL_TBL[aidx+1] - 
					(uint16_t)((((long)CPL_TBL[aidx+1]-CPL_TBL[aidx+6])*awork1/awork2));
	}
	
	// - degC interpolation -
	tcpl_v = twork1 + (uint16_t)((((long)twork2 - twork1)*awork3/awork4)) - tinreg;
	//tcpl_v = 3600 ;






	t_com90_out =  aidx;  // 
	t_com91_out = awork1  ;
	t_com92_out   = awork2 ;
	t_com93_out = awork3  ;
	t_com94_out   = awork4 ;
	t_com95_out  =  tcph_v;
	t_com96_out  =  tcpl_v ;

	// t_com90_out =  P_aidx;  // 
	// t_com91_out = Pa1  ;
	// t_com92_out   = Pa2 ;
	// t_com93_out = Pa3  ;
	// t_com94_out   = Pa4 ;
	// t_com95_out  =  tcph_v;
	// t_com96_out  =  tcpl_v ;





	/*******************************IdeaRC******************************************************/
	if (aidx >= 10 && awork1 > awork2) // > C-Rate4 ?
	{
		// Calculate by coefficient
		twork1 = QCAP_TBL[aidx + 5] - // Coefficient/((C-rate4 - C-rate3)*10
				 (uint16_t)((((long)QCAP_TBL[aidx] - QCAP_TBL[aidx + 5]) * (awork1 - awork2) * D_CP_FCC_Coefficcient / ((uint16_t)awork2 * 10)));

		twork2 = QCAP_TBL[aidx + 6] -
				 (uint16_t)((((long)QCAP_TBL[aidx + 1] - QCAP_TBL[aidx + 6]) * (awork1 - awork2) * D_CP_FCC_Coefficcient / ((uint16_t)awork2 * 10)));
	}
	else
	{ // <= C-Rate4
		twork1 = QCAP_TBL[aidx] -
				 (uint16_t)((((long)QCAP_TBL[aidx] - QCAP_TBL[aidx + 5]) * awork1 / awork2));

		twork2 = QCAP_TBL[aidx + 1] -
				 (uint16_t)((((long)QCAP_TBL[aidx + 1] - QCAP_TBL[aidx + 6]) * awork1 / awork2));
	}

	Record_Dischargefactor = twork1 + (uint16_t)((((long)twork2 - twork1) * awork3 / awork4)); // discharge Q

	if (Record_Dischargefactor)
	{
		ccwork = (int32_t)I_abs * 1000 / Record_Dischargefactor; // discharge Current Q
		dcwork = ccwork - I_abs;						  //	discharge Q Cap
		Record_Ilrc_w -= ccwork;								  //  IdeaRC
		Record_Del_lrc += dcwork;								  //  DelDischargeCapacity
	}
	else
	{
		Record_Ilrc_w -= I_abs; //  IdeaRC
		Record_Del_lrc += 0;	 //  DelDischargeCapacity
	}

	if (Record_Ilrc_w < 0)
	{
		Record_Ilrc_w = 0;
	}

	if (Record_FullChargeCapacity != Record_Remainingcapacity)
	{
		if (Record_Del_lrc > 0)
		{
			// Record_Chargefactor = (long)(ABS(Record_Del_lrc) + (long)(_AverageTimeToEmpty - t_com10)*3600)*1000/((long)(_AverageTimeToEmpty - t_com10)*3600);
			Record_Chargefactor = (uint16_t)((long)ABS(Record_Del_lrc) * 10 / (long)((Record_FullChargeCapacity - Record_Remainingcapacity) * 36)) + 1000;
		}
		else
		{
			Record_Chargefactor = (long)(_AverageTimeToEmpty - t_com10) * 36000 / ((long)(Record_FullChargeCapacity - Record_Remainingcapacity )* 36 + ABS(Record_Del_lrc) / 100);
		}
	}
	else
	{
		if (Record_Del_lrc > 0)
		{
			// Record_Chargefactor = (long)(ABS(Record_Del_lrc) + 3600)*1000/3600;
			Record_Chargefactor = (uint16_t)((long)ABS(Record_Del_lrc) * 10 / 36 + 1000);
		}
		else
		{
			Record_Chargefactor = (uint16_t)(3600000 / ((long)3600 + ABS(Record_Del_lrc)));
		}
	}
	/***********************************************************************************************/

	// tinreg = Calc_InRegFcc();


	if(_CycleCount>10) //Cycle count 
	{
		// t_com2e soh   // another version t_com2f
        //t_com2f = ((uint32_T)D_DCAP*(10000-tinreg)/100+D_DCAP/2)/D_DCAP;	
		
		_SoH = ((uint32_t)D_Design_Capacity_mAh*(10000-tinreg)/100+D_Design_Capacity_mAh/2)/D_Design_Capacity_mAh;	
		if (_SoH >= 100)
		{
			_SoH = 100;	 // soh 
		}
	}

}

/*""FUNC COMMENT""**********************************************************
* ID				: 1.0
* module outline	: RemainingCapacity() calculation function
*--------------------------------------------------------------------------
* Include			: 
*--------------------------------------------------------------------------
* Declaration		: void Calc_RC(void)
*--------------------------------------------------------------------------
* Function			: It calculates RemainingCapacity()
*--------------------------------------------------------------------------
* Argument			: None
*--------------------------------------------------------------------------
* Return			: None
*--------------------------------------------------------------------------
* Input			: None
*					: 
* Output			: t_com0fc	: RemainingCapacity() [mAh]
*					: 
*--------------------------------------------------------------------------
* Used function	: Calc_NormalRC(), Make_RC()
*					: 
*--------------------------------------------------------------------------
* Caution			: 
*--------------------------------------------------------------------------
*""FUNC COMMENT END""*****************************************************/
void Calc_RC(void)
{
	static uint8_t	acpl_cnt;
	static uint8_t	acph_cnt;
	static uint8_t	adlogc;							// Power consumption 10times counter
	
	uint32_t	lwork;
	RSOC_USE_DF_test = D_Control_flag_1_RSOC_USE_DF ;
	Qmax_update_DSG_test =D_Control_flag_1_Qmax_update_DSG  ;  

	CellTemp_use_rsoc = CellTemp ;

	if ((uint16_t)((long)I_abs * 100 / D_Design_Capacity_mAh) >= 50)
	{
		if (CellTemp_use_rsoc >= 10)
		{
			D_0PVOLT = D_Discharge_0_voltage; // D_Discharge_0_voltage D_0PVOLT
		}
		if ((CellTemp_use_rsoc >= 5) && (CellTemp_use_rsoc < 10))
		{
			D_0PVOLT = D_Discharge_0_voltage-D_5_10_LIMIT; // D_0PVOLT5_Tempera_10   多串还是单串  ？   电压
		}
		else if (CellTemp_use_rsoc < 5)
		{
			// D_0PVOLT= D_0PVOLT_Tempera_less_than_5 ;
			D_0PVOLT = D_Discharge_0_voltage-D_5_LIMIT;
		}
	}
	else
	{
		D_0PVOLT = D_Discharge_0_voltage;
	}
 
	if (f_relax)   // now releax , 1 second come into 1 times .  
	{
		temptime_D_Discharge_0_voltage_Delay = D_Discharge_0_voltage_Delay; 
	}
	else
	{
		temptime_D_Discharge_0_voltage_Delay = D_Discharge_0_voltage_Delay * 4;
	}

	if (Current() > 0) // Charging ?
	{
		
		VoltagetoRSOCcount = 0 ;

		if( f_charge == ON )					// Charging ?
		{
			if( f_studied == ON )				// Studied flag = ON ?
			{
				f_studied = OFF;				// Clear studied flag
				t_com10  = tcom10c_w;			// Store relearn value to FCC
			}
			
			if( f_fullchg == OFF )				// No OVER_CHARGED_ALARM ?
			{
				f_study_d = OFF;				// Clear discharge relearn flag
				f_study_d1 = OFF;
				f_study_d2 = OFF;
				
			}
			
			if( (f_cp_h == ON)					// CP_H detected ?
				&& (t_com0d > D_CP_H) )			// & RSOC > CP_H ?
			{
				f_cp_h = OFF;					// Clear CP_H detection flag
			}
				
			if( (f_cp_l == ON)					// CP_L detected ?
				&& (t_com0d > D_CP_L) )			// & RSOC > CP_L ?
			{
				f_cp_l = OFF;					// Clear CP_L detection flag
			}
		}
		
		if( f_study_c == ON )					// Now charge relarning ?
		{
			lrccr_w += I_abs;					// Calculate chg relearn cap.
			if( f_rcsame == ON )				// Correction cap = chg relearn cap ?
			{
				Record_lrc_w = lrccr_w;				// Set same value to RC
			} 
			else 
			{									// Not same
				if( Record_lrc_w < lrccr_w )			// Chg relearn cap is bigger ?
				{
					Record_lrc_w += (I_abs << 1);		// Correction coefficient = 2
					if( Record_lrc_w >= lrccr_w )		// Inverted ?
					{
						f_rcsame = ON;			// Set same RC flag
					}
				} 
				else 
				{								// Correction cap is bigger
					Record_lrc_w += (I_abs >> 1);		// Correction coefficient = 0.5
					if( Record_lrc_w < lrccr_w )		// Inverted ?
					{
						f_rcsame = ON;			// Set same RC flag
					}
				}
			}
		} 
		else 
		{										// Not charge relarning
			chg_pinghua();
			if (f_pinghua_work == 1)
			{
				// lrc_w += chg_pinghua_current - divi_by_1k * 3;
				Record_lrc_w += chg_pinghua_current ;
			}
			else
			{
				Record_lrc_w +=  I_abs;
			}
			// Calc RC without correction			
			if( (f_cp_h == ON) || (f_cp_l == ON) )
			{
				lrccr_w += I_abs;				// Integrate chg rel.cap.
			}
		}

		if(I_abs > D_FCC_Min_current_of_cap_calc) //  D_RCCMIN
		{
			Record_Ilrc_w += (int32_t) I_abs * Record_Chargefactor / 1000;			 // IdealRc
			Record_Del_lrc -= (int32_t) I_abs * Record_Chargefactor / 1000 - I_abs; //
		}
	} 
	else  // current <= 0 ;
	{		
		firstCurrentCnt = 0;
		secondCurrentCnt = 0;
		f_firstFlg = 0;
		f_secondFlg = 0;											// Discahrging or No current
		// if(V_min < D_Discharge_0_voltage)					// lower than 0% voltage ? D_0PVOLT
		if(V_min <=  D_0PVOLT) 
		{
			VoltagetoRSOCcount++ ;// Detect more than 4 times ?
			if( D_Control_flag_1_DIS_CHG_Releaning == OFF )			// Charge relearn not disable ?
			{
				f_study_c = ON;				// Set charge relearn flag
			}
			// if(VoltagetoRSOCcount >= D_Discharge_0_voltage_Delay*4)   // now time is 1s /time . 
			if(VoltagetoRSOCcount >= temptime_D_Discharge_0_voltage_Delay)   // now time is 1s /time . 
			{
				VoltagetoRSOCcount = temptime_D_Discharge_0_voltage_Delay ;
				f_cp_h = ON;					// Set CP_H detection flag
				f_cp_l = ON;					// Set CP_L detection flag
				Record_lrc_w = 0;						// Correction capacity = 0
				lrccr_w = 0;					// Charge relearn capacity = 0
	//			f_gs_fd = ON; //20230918
				t_com0f = 0;					// RC[mAh] = 0
				lmaxerr_cnt = 0;				// Clear MaxErr integ. counter
			// 	Record_Ilrc_w = 0 ; // t_com88
				t_com88 = 0 ; 
				// t_com0c = 0;					// Clear MaxError
				// (Process to prevent fluctuation when jumping CC.)
				toldrc = 0;						// Set last RC to 0
				f_pi_pinghua = 0;
				return;
			}
		}else
		{
			VoltagetoRSOCcount = 0 ;
		}

		if( I_abs <= D_FCC_Min_current_of_cap_calc )					// Current < not count curr ?
		{
			if( adlogc == 9 )					// Consumption current piles up 10 times ?
			{
				Record_lrc_w -= D_FCC_Consum_current_of_discharge;				// Take dischg consumption curr
				if( Record_lrc_w < 0 )					// Underflow ?
				{
					Record_lrc_w = 0;					// Sst 0
				}
				
				if( f_study_c == ON )			// Now charge relarning ?
				{
					lrccr_w -= D_FCC_Consum_current_of_discharge;			// Take dischg consumption curr
					if( lrccr_w < 0 )			// Underflow ?
					{
						lrccr_w = 0;			// Set 0
					}
				}
				
				if( f_study_d == ON )			// Now discharge relearning ?
				{
					lrcdr_w  += D_FCC_Consum_current_of_discharge;			// Add dischg consumption curr
				}
			}
		} 
		else 
		{										// Now discharging
			Calc_CPVolt();						// Calculate CP_x voltage
			lwork = I_abs;						// Make data for RC integration
			if( adlogc == 9 )					// Consumption current piles up 10 times ?
			{
				lwork += D_FCC_Consum_current_of_discharge;				// Add dischg consumption curr
			}
			
			if( f_cp_h == OFF )					// Not detect CP_H voltage ?
			{
				if( f_discharge == OFF )		// Not discharging ?
				{
					Calc_NormalRC(lwork);		// Calculate normal RC
				} 
				else 
				{						// Discharging
					if( V_min < tcph_v )		// MinV < CP_H voltage ?
					{
						acph_cnt++;				// Increment CP_H det.counter
						// if( acph_cnt == 4 )		// Detect 4 times ?  // 13 seconds for dbpt 
						if( acph_cnt == D_CP_Delay *4  )   // 1 second 4 times 
						{
							acph_cnt = 0;		// Clear the counter
							f_cp_h = ON;		// Set CP_H detect flag
												// Charge relearn not disable ?
							if( D_Control_flag_1_DIS_CHG_Releaning == OFF )
							{
								f_study_c = ON; // Set charge relearn flag
							}
												// Relearn point is CP_H ?
							// dsg_point_test = D_Control_flag_1_Discharge_relearning_point ;
							if( D_Control_flag_1_Discharge_relearning_point == ON )
							{
								Make_Relearning(D_CP_H); // Relarning process
							}

							f_rcsame = OFF;		// Clear RC same flag
												// Set CP_H capacity to RC work
							// CP_H capacity = FCC*60*60*4*(D_CP_H/100)
							//               = FCC*D_CP_H*144
							lrccr_w = (long)t_com10  * t_com0d * 144;
							//  D_Control_flag_1_Correct_RCL == ON && 
							// if( D_Control_flag_1_Correct_RCL == ON && D_CP_L < t_com0d ) //if(D_CP_H < t_com0d )
							// {
							// 	Set_CP_L capacity to RC
								Record_lrc_w = lrccr_w;
								lrc_w_last  = Record_lrc_w ;
							// }
							Calc_HoseiRC(lwork);
											// Calculate RC correction
						} 
						else 
						{				// Less than 4 times
												// Calculate normal RC
							Calc_NormalRC(lwork);
						}
					} 
					else 
					{					// MinV >= CP_H voltage
						acph_cnt = 0;			// Clear CP_H detection counter
						f_study_c = OFF;		// Clear charge relearn flag
												// Calculate normal RC
						Calc_NormalRC(lwork);
					}
				}
			} 
			else 
			{							// Already CP_H is detected
				if( f_cp_l == OFF )				// Not detect CP_L ?
				{
					if( V_min < tcpl_v )		// MinV < CP_L voltage ?
					{
						acpl_cnt++;				// Increment CP_L det. counter
						// if( acpl_cnt == 4 )		// Detect 4 times ?
						if( acpl_cnt == D_CP_Delay *4 )		// Detect 4 times ?  //13 second for dbpt 
						{
							acpl_cnt = 0;		// Clear CP_L detection counter
							f_cp_l = ON;		// Set CP_L detect flag
												// Relearn point is CP_H ?
							// dsg_point_test = D_Control_flag_1_Discharge_relearning_point ;
							// if(f_cp_h==ON)
							// {
							// 	f_study_d = ON ;
							// 	f_study_d_test = f_study_d;
							// }

							if( D_Control_flag_1_Discharge_relearning_point == ON )
							{
												// Relearning process
								Make_Relearning_cpl(D_CP_L);
							}
							// CP_L capacity = FCC*60*60*4*(D_CP_L/100)
							//               = FCC*D_CP_L*144
							// lrccr_w = (long)t_com10  * D_CP_L * 144;
							lrccr_w = (long)t_com10  * t_com0d * 144;
												// Make drop at detect CP_L ?
												// & Current cap > CP_L cap ?
							// if( D_Control_flag_1_Correct_RCL==ON && D_CP_L < t_com0d )
							// {
												// Set CP_L capacity to RC
								Record_lrc_w = lrccr_w;
							// } 
							// else 
							// {
												// Clear RC same flag
								f_rcsame = OFF;
												// Calculate RC correction
								Calc_HoseiRC(lwork);
							// }
						} 
						else 
						{				// Less than 4 times
												// Calc RC at less than CP_H
							Calc_CP1RelRC(lwork);
												// Calculate RC correction
							Calc_HoseiRC(lwork);
						}
					} 
					else 
					{					// MinV >= CP_L voltage
						acpl_cnt = 0;			// Clear CP_L detection counter
												// Calc RC at less than CP_H
						Calc_CP1RelRC(lwork);
						Calc_HoseiRC(lwork);	// Calculate RC correction
					}
				} 
				else 
				{						// Already CP_L is detected
					lrccr_w -= lwork;			// Take it from Chg rel.cap.
					if( lrccr_w < 0 )			// Underflow ?
					{
						lrccr_w = 0;			// Set 0
					}
					Calc_HoseiRC(lwork);		// Calculate RC correction
				}
			}
		}
		adlogc++;								// Inc consumption curr counter
		if( adlogc == 10 )							// Count 10 ?
		{
			adlogc = 0;				// Clear the counter
		}
	}
	//if (f_discharge == ON || f_relax == ON)
	if (!f_charge)
	{
		// when not init , not cph or cpl updated , or dsg(fulchg or temp change more than 10 )
		if (f_init_first_time == 0 && f_cp_h_fccupdated == 0 && f_cp_l_fccupdated == 0 && f_fulchg_dsg_updated== 0 )
		{
			if (Record_lrc_w > lrc_w_last)
			{
				Record_lrc_w = lrc_w_last;
			}
			if (t_com0d > t_com0dsoclast) // t_com0d : rsoc
			{
				t_com0d = t_com0dsoclast;
			}
		}
	}
	f_cp_h_fccupdated = 0;
	f_cp_l_fccupdated = 0;
	f_fulchg_dsg_updated= 0;
	lrc_w_last = Record_lrc_w;
	t_com0dsoclast = t_com0d;
	f_init_first_time = 0;
	

	f_cp_l_last  = f_cp_l ;
	
	Make_RC();									// Calculate RemainingCapacity
	Make_iRC();


}

/*""FUNC COMMENT""***************************************************
* ID 			: 1.0
* module outline: MaxError() calculation function
*-------------------------------------------------------------------
* Include		: 
*-------------------------------------------------------------------
* Declaration	: void Calc_MaxErr(void)
*-------------------------------------------------------------------
* Function		: Calculate MaxError()
*-------------------------------------------------------------------
* Argument		: None
*-------------------------------------------------------------------
* Return		: None
*-------------------------------------------------------------------
* Input			: None
* Output		: t_com0c	: MaxError()
*-------------------------------------------------------------------
* Used function	: 
*-------------------------------------------------------------------
* Caution		: 
*-------------------------------------------------------------------
* History		: 2012.08.01 Ver 0.01
* 				: New create
* 
*""FUNC COMMENT END""**********************************************/
void Calc_MaxErr(void)
{
	uint16_t	twork;

	// MaxError = (Total integration cap x 0.05) / (FCC / 100)
	//          = Total integration cap x 5 / FCC
	// twork = (uint16_t)(lmaxerr_cnt * 5 / t_com10 );
	
	// if( twork >= 100 )							// MaxError > 100% ?
	// {
	// 	t_com0c = 100;
	// } 
	// else 
	// {
		
	// 	t_com0c = twork;
	// 	//t_com0c = 0x0001;
	// }
}

// Function of counting capacity of MaxError and DataFlash updating request
//  after calculating CycleCount.
void MEDF_Count(uint16_t tdata)
{
	lmaxerr_cnt += tdata;						// Add MaxError integ. counter
	Calc_MaxErr();								// Calculate MaxError()
	tdfup_cnt += tdata;							// Add DF update counter
	if( tdfup_cnt >= 500 )						// reached 500mAh ?
	{
		f_dfreq = ON;							// Set DataFlash update req.
		tdfup_cnt = 0;							// Clear the counter
	}
}

// Function of counting CycleCount
void CC_Count(uint16_t tdata)
{
	Record_tcc_cnt += tdata;							// Add CC counter
	if( Record_tcc_cnt >= tccup )						// reached CC count value ?
	{
		_CycleCount++;								// Increment CycleCount
		Record_trek_cnt++;								// Increment degradation cnt
		arelearn_cnt++;							// Increment conditioning cnt
		if( arelearn_cnt == 50 )				// reached 50 cycle ?
		{
			f_relearn = ON;						// Set RELEARN_FLAG
		}
		Record_tcc_cnt = 0;							// Clear the counter
	}
}

/*""FUNC COMMENT""***************************************************
* ID			: 1.0
* module outline: CycleCount() calculation function
*-------------------------------------------------------------------
* Include		: 
*-------------------------------------------------------------------
* Declaration	: void Calc_CC(void)
*-------------------------------------------------------------------
* Function		: Calculate CycleCount()
*-------------------------------------------------------------------
* Argument		: None
*-------------------------------------------------------------------
* Return		: None
*-------------------------------------------------------------------
* Input			: None
* Output		: _CycleCount	: CycleCount()
*-------------------------------------------------------------------
* Used function : CC_Count(), MEDF_Count()
*-------------------------------------------------------------------
* Caution		: 
*-------------------------------------------------------------------
* History		: 2012.08.01 Ver 0.01
* 			: New create
* 
*""FUNC COMMENT END""**********************************************/
void Calc_CC(void)
{
	uint16_t	twork;

	// if( D_Cycle_Count_Percentage < 0 )							// CCCC counts discharging ?
	// {
		if( Current() < 0 )						// Now discharging ?
		{
			if( t_com0f  < toldrc )				// RC reduces ?
			{
				twork = toldrc - t_com0f;
				CC_Count(twork);				// Counting CycleCount
				MEDF_Count(twork);				// Counting MaxError/DF
			}
		} 
		else 
		{								// Not discharging
			if( t_com0f  > toldrc )				// RC increasing ?
			{
				MEDF_Count(t_com0f - toldrc);	// Counting MaxError/DF
			}
		}
	// } 
	// else 
	// {									      // CC counts charging
	// 	if( Current() > 0 )						// Now charging ?
	// 	{
	// 		if( t_com0f  > toldrc )				// RC increasing ?
	// 		{
	// 			twork = t_com0f - toldrc;
	// 			CC_Count(twork);				// Counting CycleCount
	// 			MEDF_Count(twork);				// Counting MaxError/DF
	// 		}
	// 	} 
	// 	else 
	// 	{								// Not charging 
	// 		if( t_com0f  < toldrc )				// RC reducing ?
	// 		{
	// 			MEDF_Count(toldrc-t_com0f);	// Counting MaxError/DF
	// 		}
	// 	}
	// }
	
	toldrc = t_com0f;						   // Update last RC
}
		

/*""FUNC COMMENT""***************************************************
* module outline	: Initial capacity setting function
*-------------------------------------------------------------------
* Include			: 
*-------------------------------------------------------------------
* Declaration		: void Init_Cap(void)
*-------------------------------------------------------------------
* Function			: Calculate and set the initial capacity from 
*					: Voltage-Capacity table.
*-------------------------------------------------------------------
* Return			: None
*-------------------------------------------------------------------
* Input				: None
* Output			: None
*-------------------------------------------------------------------
* Used function		: ReadVolt(), Make_RC()
*-------------------------------------------------------------------
* Caution			: 
*					: 
*""FUNC COMMENT END""**********************************************/
void Init_Cap(void)
{
	uint8_t	aidx; 
	uint8_t   aresult;
	// if(_DAStatus1.CellCurrnet1 > D_Current_Chg_Current_Threshold || _DAStatus1.CellCurrnet1 < D_Current_Dsg_Current_Threshold )
	// return;
	f_init_first_time = 1 ;
														// Search using table
	for( aidx=0; V_min >= OCV_SOC[aidx+1] && aidx < 19; aidx++ );
	if( V_min <= OCV_SOC[0] )							// Smaller than 0% voltage ?
	{
		Record_lrc_w = 0;											// Set capacity to 0%
		Record_Ilrc_w = 0 ;
	} 
	else 
	{
		if( V_min >= OCV_SOC[20] )						// Bigger than 100% voltage ?
		{
			if(f_fullchg == ON)
			{
															// Set capacity to 100%
				Record_lrc_w = (long)t_com10 * 14400;					// (100/100*14400=14400)
				Record_Ilrc_w =  (long)t_com89 * 14400;
			}
			else
			{
				Record_lrc_w = (long)t_com10 * 14256;   // Set capacity to 100%
				Record_Ilrc_w =  (long)t_com89 * 14256;
			}
		} 
		else
		{													// Not 0% and Not 99%
			// aresult = (uint8_t)((long)(INITCAP_TBL[aidx+1] - 5*aidx)
			// 			* (V_min - INITV_TBL[aidx])
			// 			/ (INITV_TBL[aidx+1] - INITV_TBL[aidx])
			// 			+ 5*aidx);
			aresult = (uint8_t)((V_min - OCV_SOC[aidx])*5/(OCV_SOC[aidx+1] - OCV_SOC[aidx]))+(5*aidx);
			// RC_w = FCC * aresult / 100 * 14400
			//		= FCC * aresult * 144
			Record_lrc_w = (long)t_com10 * aresult * 144;
			Record_Ilrc_w = (long)t_com89 * aresult * 144;
		}
	}
	
//	twork = (uint16_t)(((((long)t_com88 * 200)*10 / t_com89 ) + 10) / 2);

	//t_com8a= (uint16_t)(((((long)Record_Ilrc_w /14400 /t_com89 *2000) + 10) / 2);
	t_com8a= (uint16_t)((((long)Record_Ilrc_w *5/36/t_com89) + 10) / 2);
	irsoc_last = t_com8a;

	
	lrc_w_last  = Record_lrc_w ;

	// t_com31_out  = CellTemp ;
	// t_com32_out = CellTemp_last_time_update ;
	CellTemp_last_time_update= CellTemp ;
	t_com0dsoclast = t_com0d ;  // RelativeStateOfCharge// RelativeStateOfCharge=t_com0d; 20230409 updated part 1 
	Make_RC();												// Calculate RemainingCapacity
	Calc_RSOC();											// Calculate RSOC
	Make_iRC();
	Calc_iRSOC();	
	
		
	
	if( t_com0d <= D_CP_H )								// RSOC <= CP ?
	{
		f_cp_h = ON;											// Set CCP detect flag
	}
	
	if( t_com0d <= D_CP_L )								// RSOC <= CP ?
	{
		f_cp_l = ON;											// Set CCP detect flag
	}

	f_pi_pinghua = 0;
}

// void ful_chg_acc_cap_updated(void)
// {
// 	// uint32_t after_full_cap_accmu ;
// 	if (t_com0d == 20 && t_com0a > 0 && f_charge == ON) // t_com10 FCC   t_com0d = RSOC
// 	{
// 		f_chg_update_20 = 1; // 20% to  open , in the following will be used .
// 		if(t_com0d == 20 && f_20rc_cap_detected == 0)  // when rsoc == 20 , only keep one time .
// 		{
// 			keep_rc_rsoc20  = lrc_w  ;
// 			f_20rc_cap_detected = 1 ;
// 		}
// 	}

// 	if (f_chg_update_20 == 1)  // can not combine ,with last conditon , becasue if conbine , not 20 , will cap_accmu_chg_update = 0;
// 	{
// 		cap_accmu_chg_update += t_com0a;
// 		// this time ! chg , last time rsoc== 100 && f_fullchg
// 		// use it
// 		// 20% fcc + 20---》100% ， + over 100%
// 		if (f_charge == OFF && f_chg_last_state == ON && t_com0d == 100 && f_fullchg == ON) // t_com10 FCC   t_com0d = RSOC
// 		{
// 			t_com10 = (keep_rc_rsoc20 + cap_accmu_chg_update)/60/60 ;
// 			// rc is controled by make_() , parameter lrc_w
// 			lrc_w = keep_rc_rsoc20 + cap_accmu_chg_update  ;
// 			t_com0f = t_com10 ;  // rc = fcc   in fact , no need this ,only last step is okay .
// 			t_com0d = 100 ;
// 			keep_rc_rsoc20 = 0 ;
// 			cap_accmu_chg_update = 0;
// 			f_20rc_cap_detected = 0 ;
// 		}
// 	}
// 	else
// 	{
// 		cap_accmu_chg_update = 0;
// 	}
// 	// after use  f_chg_update_20 , then close
// 	if (f_charge == OFF && t_com0a <= 0 && t_com10 != 100)
// 	{
// 		f_chg_update_20 = 0;
// 	}

// 	f_chg_last_state = f_charge;
// }

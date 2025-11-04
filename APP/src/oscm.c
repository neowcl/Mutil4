
#include "oscm.h"

OSCM_CHGSTU OSCM_ChgSta;
uint16_t OSCM_flag;
OSCM_TIME OSCMtime;
RTC_TIME RTC_Time;
OSCM_EEDATATIME OSCM_EEDataTime;
uint16_t OSCM_CC,OSCM_CV;
uint16_t OSCM_ATTF;
uint8_t OSCM_ST,OSCM_ET,OSCM_ACinT,OSCM_ACoutT;//OSCM_Start Time
uint16_t OSCM_CaliTime;
uint8_t m_oscm,Win7day_cnt;
void OvernightSafeChargeMode(uint16_t current,uint16_t voltage)
{
//   uint8_t al1; 
//   rtc_time_t rtc_time;
//   rtc_date_t rtc_date;
//   f_oscm_support = ON;//battery support OSCM  mode
//   if(D_EN_OSCM)
//   {
//	   f_oscm_en = ON;//OSCM EN status
//	   if(f_calitime || f_oscm_sync == 0x03)
//	   {		   
//       f_oscmchange = ON;
//       if(f_oscm_sync == 0x03)//SYS sync time instruction
//		   {
//			   f_oscm_sync = 0x00;//sync time finish
//		     rtc_calendar_config(23,7,11,12,0,0);
//		   }
//		   if(D_OSCM_CALTIME)
//		   {
//			   if(f_calitime)//Gauge sync time instruction
//			   {
//					 f_oscm_sync = 0x00;//sync time finish
//					 f_calitime = OFF;
//					 G_RTC_Hour = (uint8_t)(OSCM_CaliTime>>8);
//					 G_RTC_Minutes = (uint8_t)OSCM_CaliTime; 
//					 rtc_calendar_config(23,7,11,G_RTC_Hour,G_RTC_Minutes,0);
//			   }
//	      }		   
//	   }
//	   rtc_time_get(RTC_FORMAT_BIN, &rtc_time);
//       rtc_date_get(RTC_FORMAT_BIN,&rtc_date);
//	   t_com29 = (uint16_t)(rtc_time.rtc_hours<<8) | (rtc_time.rtc_minutes);//0x52 rtc time or gauge cali time
//   
//	   if(rtc_time.rtc_hours >= D_ACINMINTIME && rtc_time.rtc_hours <= D_ACINMAXTIME)
//	   {
//		   f_AC_Wflash = OFF;
//		   m_oscm = M_ACIN;	      
//	   }
//	   else if(rtc_time.rtc_hours >= D_ACOUTMINTIME && rtc_time.rtc_hours <= D_ACOUTMAXTIME)
//	   {
//		   m_oscm = M_ACOUT;		   
//	   }
//	   else if(rtc_time.rtc_hours > D_ACINMAXTIME)
//	   {
//		   m_oscm =	M_ACIN_FNF;   
//	   }
//	   else
//	   {
//	       m_oscm = M_IDEL;
//	   }
//	   switch(m_oscm)
//	   {
//		   case M_ACIN:			   
//			   if(!f_discharge)
//			   {
//				   if(f_oscm_Sys_ACsta)
//				   {
//					   f_ACinstart = ON;				   
//					   if(!f_ACinEarly)//Today first ACin
//					   {
//						   f_ACinEarly = ON;					   
//						   if(rtc_time.rtc_minutes >= 0 && rtc_time.rtc_minutes < 30)
//						   {						   
//							   OSCM_ACinT = rtc_time.rtc_hours;				     
//						   }
//						   else
//						   {
//							   OSCM_ACinT = rtc_time.rtc_hours + 1;     
//						   }
//					   }
//					   else if(f_oscmchange)//RTC calibration
//					   {
//						   f_oscmchange = OFF;
//						   if(rtc_time.rtc_hours < OSCM_ACinT)
//						   {
//							   if(rtc_time.rtc_minutes >= 0 && rtc_time.rtc_minutes < 30)
//							   {						   
//								   OSCM_ACinT = rtc_time.rtc_hours;				     
//							   }
//							   else
//							   {
//								   OSCM_ACinT = rtc_time.rtc_hours + 1;     
//							   } 					   
//						   }					   					   
//					   }					   		   
//				   }				   
//			   }
//               break;
//		   case M_ACIN_FNF:
//			   if(!f_ACinRecord)//Today ACin judge finish
//			   {
//				   if(!f_ACinstart)
//				   { 
//					   OSCM_ACinT = D_DEFACINTIME;					   
//				   }
//				   f_ACinstart = OFF;
//				   f_ACinEarly = OFF;
//				   f_ACinRecord = ON;//ACin Record to flash				   
//			   }
//			   break;
//		   case M_ACOUT:
//			   if(f_discharge || !f_oscm_Sys_ACsta)
//			   {
//					f_ACoutstart = ON;			   
//					if(!f_ACoutEarly)//Today first ACout
//					{
//					  f_ACoutEarly = ON;
//					  if(rtc_time.rtc_minutes >= 0 && rtc_time.rtc_minutes < 30)
//					  {						   
//						OSCM_ACoutT = rtc_time.rtc_hours;				     
//					  }
//					  else
//					  {
//						OSCM_ACoutT = rtc_time.rtc_hours + 1;     
//					  }					  
//					}
//					else if(f_oscmchange)//RTC calibration
//					{
//					   f_oscmchange = OFF;
//					   if(rtc_time.rtc_hours < OSCM_ACoutT)
//					   {						   
//						   if(rtc_time.rtc_minutes >= 0 && rtc_time.rtc_minutes < 30)
//						   {						   
//							 OSCM_ACoutT = rtc_time.rtc_hours;				     
//						   }
//						   else
//						   {
//							   OSCM_ACinT = rtc_time.rtc_hours + 1;     
//						   }					   
//					   }					   					   
//					}			  				   
//			   }
//			   break;
//		   case M_IDEL:	
//			   if(!f_AC_Wflash)
//			   {
//				   f_AC_Wflash = ON;
//				   if(!f_ACoutstart)
//				   {				   
//					   OSCM_ACoutT = D_DEFACOUTTIME;				     
//				   }
//				   f_ACoutEarly = OFF;
//				   f_ACoutstart = OFF;
//				   f_ACoutRecord = ON;	//ACout Record to flash
//				   if(f_ACoutRecord && f_ACinRecord)
//				   {
//					   if(Win7day_cnt < 7)
//					   {
//					     OSCM_EE_DAYTIME[Win7day_cnt] = OSCM_ACinT;
//						   OSCM_EE_DAYTIME[Win7day_cnt + 7] = OSCM_ACoutT;
//						   Win7day_cnt++;	
//               if(Win7day_cnt >= 7)
//						   {
//							   Win7day_cnt = 0;					   
//						   } 						   
//					   }					    
//				   }
//			   }
//			   if(!f_ACinRecord && !f_ACoutRecord)
//			   {
//				   if(!f_daytimeread)//read enter/exit time every
//				   {
//					   f_daytimeread = ON;
//					   OSCM_EnterExit_Read();
//					   OSCM_ST = chioce_EnterTime(&OSCM_EE_DAYTIME[0]);    
//					   OSCM_ET = chioce_ExitTime(&OSCM_EE_DAYTIME[7]);
//				   }
//			   }
//			   if(f_daytimeread)//updata 0x51 time
//			   {
//				   OSCM_EnterTime = OSCM_ST;
//				   OSCM_ExitTime = OSCM_ET;	
//			   }				   
//			   break;
//           default:	
//			  break; 
//	   }
//	   
//	   if(rtc_time.rtc_hours == OSCM_ST)
//	   {
//		   f_oscmstart = ON;		   
//	   }
//	   if(D_OSCM_T3TIME)
//	   {
//		   if(rtc_time.rtc_hours == (OSCM_ET - D_TIMETOFC_T3))
//		   {
//			   f_oscmstart = OFF;
//			   f_oscm_soc80 = OFF;
//			   f_oscm_t3 = ON;
//               f_oscm_modesta |= 0x03;			   
//		   }
//	   }
//	   else
//	   {
//		   if(rtc_time.rtc_hours == (OSCM_ET - OSCM_ATTF - D_BUFFERTIME))
//		   {
//			   f_oscmstart = OFF;
//			   f_oscm_soc80 = OFF;
//			   f_oscm_t3 = ON;
//         f_oscm_modesta |= 0x03;			   
//		   }	     
//	   }
//	   if(f_oscm_t3)
//	   {
//	     if(rtc_time.rtc_hours > OSCM_ET)
//			 {
//				 f_oscm_t3 = OFF;
//				 f_daytimeread = OFF;
//				 f_oscmstart = OFF;
//				 f_oscm_modesta &= ~0x03;//Bit5/Bit4=00 not in night charging mode;
//			 }
//	   }
//	   if(f_oscmstart)
//	   {
//		   if(!f_oscm_soc80)
//		   {
//			   if(t_com0d < D_STOPRSOC)
//			   {
//				   f_oscm_modesta |= 0x01;	
//                   if(D_CHGCURPHASE_T1 < current)
//				   {
//					   OSCM_CC = D_CHGCURPHASE_T1;                       				   
//				   }					   
//				   else
//				   {
//				       OSCM_CC = current;
//				   }
//			   }
//			   else
//			   {
//				   OSCM_CC = 0;
//				   OSCM_CC = NORMAL_CV;
//				   f_oscm_soc80 = ON;
//                   f_oscm_modesta |= 0x02;				   
//			   }
//			   OSCM_ATTF = _AverageTimeToFull;			   
//		   }
//		   else
//		   {
//			   if(t_com0d < (D_STOPRSOC - D_DELTARSOC))
//			   {			   
//				   f_oscm_soc80 = OFF;	
//                   if(D_CHGCURPHASE_T1 < current)
//				   {
//					   OSCM_CC = D_CHGCURPHASE_T1;				   
//				   }					   
//				   else
//				   {
//				       OSCM_CC = current;
//				   }				   
//			   }		   
//		   }			   
//	   }
//	   else if(f_oscm_t3)
//	   {
//		   OSCM_CC = current;
//		   OSCM_CV = voltage;
//		   OSCM_Time80TOFull = OSCM_ATTF;//0x51 updata Time of charge SOC80% TO Full
//		   if(f_gs_fc)
//		   {
//			 f_oscm_modesta |= 0x04;//complete in 5~10AM (complete OSCM or FC = 1)
//		   }
//		   else
//		   {
//			 f_oscm_modesta &= ~0x04;//not complete, or FC = 0 or reset.
//		   }		   
//	   }
//   }
//   else
//   {
//	   f_oscm_en = OFF;
//   }
}

uint8_t chioce_ExitTime(uint8_t*ExitTime)
{
	uint8_t minTime,al1;
	minTime = ExitTime[0];
	for(al1 = 0;al1 < 7;al1++)
	{
		if(minTime > ExitTime[al1])
		{
			minTime =  ExitTime[al1];
		}
	}
	return minTime;
}

uint8_t chioce_EnterTime(uint8_t*EnterTime)
{		
  	uint8_t  temp_times = 0;
    uint8_t  temp_hour = 0;
    uint8_t al1 = 0,j = 0;
    uint8_t time_hour[24] = {0};
	for (al1 = 0; al1 < 24; al1++)
	{
		for (j = 0; j < 7; j++)
		{
			if (al1 == EnterTime[j])
			{
				time_hour[al1]++;
			}
		}
	}
	for(al1=0;al1<24;al1++)
	{
		if (time_hour[al1] < 4)
		{
			if (temp_times < time_hour[al1])
			{
				temp_hour = al1;
      		    temp_times = time_hour[al1];
			}			
		}
		else
		{
			temp_hour = al1;
			break;
		}
	}
	return temp_hour ;
}

#include "Calc_Attf.h"
/************FLASHDATA****************/  
#define  CAP_FCCJUDGE  7480           // updated capacity when discharge on 7.5A 
#define  CUR_UP_LIMIT  7000           // over 7000mA ,total chg time almost same at same condition
#define  CUR_UP_MIDLE  1450           // if cur <1450mA , usd another parameters 
#define  CHG_TIME_7A   7350           // on 7000mA ,total chg time more than 7200 ,use 7350 to add same
#define  CUR_TIME      8              // 8 * 250ms = 2s        
#define  MINTIME       1    		  
#define  MAXTIME       0xFFFF  

#define  P1        2797               // p1 = 2.797e-11  (1.62e-11, 3.975e-11)
#define  P2        6256               // total attf p2 =  -6.256e-07  (-8.407e-07, -4.105e-07)
#define  P3        5264       	      // total attf p3 =  0.005264  (0.003879, 0.006649)
#define  P4        2044               // total attf p4 =  -20.44  (-24.11, -16.76)
#define  P5        40400              // total attf p5 =  4.016e+04  (3.683e+04, 4.35e+04)
									  // total attf = P1*x4+P2*x3+P3*x2+P4*x+P5
#define  FACS_0        112600         // attf = ax3+bx2+cx+d : ds  small current <= 1550mA use 
#define  FACS_1        1536           // attf = ax3+bx2+cx+d : cs  small current <= 1550mA use  
#define  FACS_2        864      	  // attf = ax3+bx2+cx+d : bs  small current <= 1550mA use    
#define  FACS_3        169       	  // attf = ax3+bx2+cx+d : as  small current <= 1550mA use   

/************************************/
char Ex_TEM =0;   		              // temperature 
char f_caltotal_attf = 0 ; 	          // calculate the total attf only one time .
short remtime1 = 0 ;
short remtime2 = 0 ;
short Cur_Clac_Totaltime ;            // the current to calcule the total attf

unsigned char 	Ex_F_CHG = 0 ;			
unsigned char 	Ex_F_FC  = 0 ;
unsigned char 	En_Cal_Total= 0 ;     // can calculate the total time 
unsigned char   Calc_Cnt_1s = 0 ;     // calculate the capcity per sec calculate 
unsigned short 	percen_Q = 0 ; 		  // (fcc-RC)/fcc*1000 
unsigned short  Calc_Cnt = 0  ; 	  // first come into attf , calculate 2s ,then use the current 
unsigned short  averagetime = 0 ;     // time / Capcity 
unsigned short  usAttf = 0; 	      // the result of attf
unsigned short  total_time_attf = 0;  // if charge from 0 , the total attf 
unsigned short  Ex_FCC = 0,Ex_RC = 0;  
unsigned short total_attf_adjtem;  // to show the attf after temperature adjust
uint32_t  usAttfLast;

void ATTF_SetTEM( char tem)
{
	Ex_TEM = tem; 
}
void ATTF_SetRC(unsigned short rc)
{
	Ex_RC  = rc;
}
void ATTF_SetFCC(unsigned short fcc)
{
	Ex_FCC  = fcc;
}
void ATTF_SetFCFlag(unsigned char f_fc)
{
	Ex_F_FC =  f_fc; 
}
 void ATTF_SetChgFlag(unsigned char fchg)
{
	Ex_F_CHG = fchg ;
}

void ATTF_clear(void)
{
	Calc_Cnt = 0 ;
	usAttfLast = 0; 
	Calc_Cnt_1s = 0;
	En_Cal_Total = 0 ; 	 	 // can cal total time
	f_caltotal_attf = 0 ;    // whether have calculated the total attf 
}

unsigned short Cal_total_time(short Cur)
{
	if(Cur> CUR_UP_LIMIT) // 7000 represents 1
	{
		return (CHG_TIME_7A - (Cur -CUR_UP_LIMIT)/500*60) ; // when CC more than 7000mA , CHG_TIME_7A = 7350s
		// more than 7200 , will be a little slower .total attf almost will not change 
	}
	else if ( Cur>= 1450 )
	{
			return ((uint32_t)P5 -(uint32_t)Cur*P4/100\
			 +(uint32_t)P3*Cur/100*Cur/10000\
			 - (uint32_t)P2*Cur/1000*Cur/1000*Cur/10000\
			 +(uint32_t)P1*Cur/1000*Cur/1000*Cur/10000*Cur/10000);
    } 
	else 
	{
		//if current <1450 , use another formula 
		return ((uint32_t)FACS_0 +(uint32_t)FACS_2*Cur/100*Cur/100\
			   -(uint32_t)FACS_3*Cur/100*Cur/100*Cur/1000 -(uint32_t)Cur*FACS_1/10) ;
	}
} 

unsigned short  Adjust_fcc(short Cur)
{
	// logic for  fccjudge = f (i)           CAP_FCCJUDGE = 6246  
	// CAP_FCCJUDGE is the capacity atfer discharge of 7.5A 
	// (FCC -6246)*0.4 is the time complement ,but at first the time we use 
	// same current for charge and discharge  , not accurately right 
	if  (Ex_FCC >= CAP_FCCJUDGE ) //real fcc >	fccjudge
	{	 //if greater , not exact match 
		 return (usAttf+(Ex_FCC-CAP_FCCJUDGE)/(9-Cur/1000)) ;  
	}
	else
	{	 // if less , every 6 maH- 1 sec
		 return (usAttf-( CAP_FCCJUDGE - Ex_FCC )*4/5/(Cur/1000)); 	
	}
}

unsigned short Adjust_temp(void)
{
	if( Ex_TEM  >= 10 )  
	{
		return (usAttf/100*96 +usAttf/100*((45-Ex_TEM )/5)) ;
	}
	else  
	{ 
		return (usAttf - usAttf/100*(10-Ex_TEM )*5 ) ;
	}
}

unsigned short Calc_ATTF1(short current)  
{
	if(!Ex_F_CHG)
	{	
		ATTF_clear();
		if (f_fullchg)   	
		{
			return MINTIME ;
		}
		return MAXTIME ;
	}	
	else
	{
		// logic: if not have calculated the total time , then f_caltotal_attf = 0
		// when reach 2 secondes ,enable to calculate .
		if(!f_caltotal_attf)    			   //  0 represents have not calculated the total attf time 
		{
			Calc_Cnt++;   					   //calculate 2 seconds 
			if (Calc_Cnt >= CUR_TIME )  	   //  every 4 represents 1 second
			{
				Calc_Cnt = 0;  //
				En_Cal_Total = 1 ; 
			}
			else
			{
				return MAXTIME;
			}
		}

		if( En_Cal_Total == 1 )
		{
			En_Cal_Total =0 ;
			f_caltotal_attf = 1 ;  
			Cur_Clac_Totaltime  = current;	    // this current to calculate total for first time 	
			// total attf :
			total_time_attf = Cal_total_time( Cur_Clac_Totaltime) ;  //to show original total time attf 
			usAttf = total_time_attf ;
			// adjust fcc :
			usAttf = Adjust_fcc( Cur_Clac_Totaltime) ;
			// adjust temp :
			usAttf =  Adjust_temp() ;
			total_attf_adjtem = usAttf;         // to show the attf after temperature adjust 
			
			// Calculate the charge progress :  beginning state : 
			percen_Q = (uint32_t)(Ex_FCC-Ex_RC)* 1000/Ex_FCC +1  ; // in case at the end it will be 0 ;
			usAttf =(uint32_t)usAttf * percen_Q /1000; 

			//SOC reach 100 , time + usattf/2.5 => RC +1 , usattf /250
			//usAttf += (rc/fcc)*100 * (usAttf/250) = (1001-percen_Q)*100 * (usAttf/250)/1000
			//=(1001-percen_Q)*(usAttf/250)/10=usAttf*(1001-percen_Q)/260/10
			//usAttf+=(uint32_t)usAttf --(wrong)f*(1001-percen_Q)/250/10;   // percentage of Q not match of time .
			usAttf+=(uint32_t)total_attf_adjtem *(1001-percen_Q)/260/10;   // percentage of Q not match of time .
		}
		//  the progress of reducing :;
		Calc_Cnt_1s++;
		//usatt_fCC_afterfcc++;
		if(Calc_Cnt_1s >= 4)
		{  	
			Calc_Cnt_1s = 0 ;
			if(usAttf>60)
			{
			  usAttf-=1 ;
			  usAttfLast = usAttf;                // save result of attf 
			}
			else
			{
			  return MINTIME ;
			}
		}
		return usAttf / 60;
	}
}


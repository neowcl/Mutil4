#include "AdvancedChargeAlgorithm.h"

uint8_t CellVoltRange;
uint16_t CHG_Algorithm;

uint16_t t_POLY_CC;
uint16_t POLY_MinCC;
uint16_t LastCellTemp;
uint16_t poly_cnt;
uint16_t poly_cnt1;
uint8_t polylock;
uint8_t poly_stepnum;
uint8_t poly_high;
uint8_t lastpolyStep;
//smart charge
int8_t asmartstep;
uint16_t stepnum;
uint16_t asmart_cnt;
uint16_t t_SmartChargeCC;
uint16_t t_SmartChargeCV;
uint16_t smartchgcrl;
uint16_t tcom14_new,tcom15_new;


void VoltageRangeJudge(void)
{
       int8_t F0;
       int8_t F1;
       if(V_min <= D_Voltage_Precharge_Start_Voltage)
       {
            nChargingStatus.data[1] &= 0xf0;
            f_PV = 1;
       }
       else
       {
              F1 = 0;
              F0 = 0;
              if(V_max <= D_Voltage_Charging_Voltage_Low)         
              {
                    if(CellVoltRange&(CV_LV|CV_MV|CV_HV)) 
                    {
                        if(V_max < (D_Voltage_Charging_Voltage_Low - D_Voltage_Charging_Voltage_Hysteresis))
                        {
                            CellVoltRange = (CellVoltRange&~CV_CVRALL)|CV_PV;
                            F1 = 1;
                        }
                        else
                            goto CVRange_LV;
                    }
                    else
                    {
                        CellVoltRange = (CellVoltRange&~CV_CVRALL)|CV_PV;
                        F1 = 1;
                    }
                    if(F1)
                    {
                        if(f_LV || f_MV || f_HV)
                        {
//                            if(f_dsg || f_relax)
													if(BatteryStatus(DSG))
                            {
                                F0 = 1;
                            }                                  
                        }
                        else
                        {
                            F0 = 1;
                        }
                        if(F0)
                        {
                            nChargingStatus.data[1] &= 0xf0;
                            f_PV = 1;
                        }
                    }
              }      
              else if(V_max <= D_Voltage_Charging_Voltage_Med)          
              {
CVRange_LV:
                    if(CellVoltRange&(CV_MV|CV_HV))    
                    {
                        if(V_max< (D_Voltage_Charging_Voltage_Med - D_Voltage_Charging_Voltage_Hysteresis))                     
                        {
                            CellVoltRange = (CellVoltRange&~CV_CVRALL)|CV_LV; 
                            F1 = 1;
                        }
                        else
                            goto CVRange_MV;
                    }
                    else
                    {
                        CellVoltRange = (CellVoltRange&~CV_CVRALL)|CV_LV;
                        F1 = 1;
                    }
                    if(F1)
                    {
                        if(f_MV || f_HV)
                        {
                            if(BatteryStatus(DSG))
                            {
                                F0 = 1;
                            }                                  
                        }
                        else if(f_PV)
                        {
                            if(V_min > D_Voltage_Charging_Voltage_Low)
                                F0 = 1;
                        }
                        else
                            F0 = 1;
                        if(F0)
                        {
                            nChargingStatus.data[1] &= 0xf0;
                            f_LV = 1;
                        }
                    }
              }
              else if(V_max <= D_Voltage_Charging_Voltage_High)         
              {
CVRange_MV:       
                    if(CellVoltRange&CV_HV)
                    {
                        if(V_max < (D_Voltage_Charging_Voltage_High - D_Voltage_Charging_Voltage_Hysteresis))                          
                        {
                            CellVoltRange = (CellVoltRange&~CV_CVRALL)|CV_MV;
                            F1 = 1;
                        }
                    }
                    else
                    {
                        CellVoltRange = (CellVoltRange&~CV_CVRALL)|CV_MV;
                        F1 = 1;
                    }
                    if(F1)
                    {
                    if(f_HV)
                    {
                        if(BatteryStatus(DSG))
                        {                           
                            F0 = 1;
                        }                                  
                    }
                    else if(f_PV)           
                    {
                        if(V_min > D_Voltage_Charging_Voltage_Low)
                            F0 = 1;
                    }
                    else
                        F0 = 1;
                    if(F0)
                    {
                        nChargingStatus.data[1] &= 0xf0;
                        f_MV = 1;
                    }
                    }
              }
              else
              {
                    CellVoltRange = (CellVoltRange&~CV_CVRALL)|CV_HV;
                    if(f_PV)
                    {
                    if(V_min > D_Voltage_Charging_Voltage_Low)
                        F0 = 1;
                    }
                    else
                    F0 = 1;
                    if(F0)
                    {
                        nChargingStatus.data[1] &= 0xf0;
                        f_HV = 1;
                    }
              }
       }
}

void TemperatureRangeJudge(void)
{
    if (Ts_max < D_Temp_T1_Temp)
    {
        nChargingStatus.data[0] = TR_UT;
    }
    else if (Ts_max < D_Temp_T2_Temp)
    {
        if (nChargingStatus.data[0] & TR_UT)
        {
        TempRange_LT:
            if (Ts_max > (D_Temp_T1_Temp + D_Temp_Hysteresis_Temp))
            {
                nChargingStatus.data[0] = TR_LT;
            }
        }
        else
        {
            nChargingStatus.data[0] = TR_LT;
        }
    }
    else if (Ts_max < D_Temp_T5_Temp)
    {
        if (nChargingStatus.data[0] & (TR_UT | TR_LT))
        {
        TempRange_STL:
            if (Ts_max > (D_Temp_T2_Temp + D_Temp_Hysteresis_Temp))
            {
                nChargingStatus.data[0] = TR_STL;
            }
            else
            {
                goto TempRange_LT;
            }
        }
        else
        {
            nChargingStatus.data[0] = TR_STL;
        }
    }
    else if (Ts_max <= D_Temp_T6_Temp)
    {
        if (nChargingStatus.data[0] & (TR_UT | TR_LT | TR_STL))
        {
            if (Ts_max > (D_Temp_T5_Temp + D_Temp_Hysteresis_Temp))
            {
                nChargingStatus.data[0] = TR_RT;
            }
            else
            {
                goto TempRange_STL;
            }
        }
        else if (nChargingStatus.data[0] & (TR_STH | TR_HT | TR_OT))
        {
            if (Ts_max < (D_Temp_T6_Temp - D_Temp_Hysteresis_Temp))
            {
                nChargingStatus.data[0] = TR_RT;
            }
            else
            {
                goto TempRange_STH;
            }
        }
        else
        {
            nChargingStatus.data[0] = TR_RT;
        }
    }
    else if (Ts_max <= D_Temp_T3_Temp)
    {
        if (nChargingStatus.data[0] & (TR_HT | TR_OT))
        {
        TempRange_STH:
            if (Ts_max < (D_Temp_T3_Temp - D_Temp_Hysteresis_Temp))
            {
                nChargingStatus.data[0] = TR_STH;
            }
            else
            {
                goto TempRange_HT;
            }
        }
        else
        {
            nChargingStatus.data[0] = TR_STH;
        }
    }
    else if (Ts_max <= D_Temp_T4_Temp)
    {
        if (nChargingStatus.data[0] & TR_OT)
        {
        TempRange_HT:
            if (Ts_max < (D_Temp_T4_Temp - D_Temp_Hysteresis_Temp))
            {
                nChargingStatus.data[0] = TR_HT;
            }
        }
        else
        {
            nChargingStatus.data[0] = TR_HT;
        }
    }
    else
    {
        nChargingStatus.data[0] = TR_OT;
    }
}

void Charge_Inhibit()
{
    // Fet_Ctrl &= CFET_OFF;
    // if(nChargingStatus.data[0] & 0x1E)  wrong , all same together 
    if(f_LT||f_STL||f_RT||f_STH)
    {
        f_IN = OFF;
        f_IN_CFET = ON;
    }
    else
    {
            if( (f_gs_dsg&& f_HT) || (!D_Charging_Config_HT_INIHIB_DIS  && f_OT ) ||  f_UT )  
            {
                f_IN = ON;
                f_SU = OFF;
                _ChargingCurrent = D_Charge_Inhibit_Current;
                if (D_FETOptions_CHGIN)
                {
                    f_IN_CFET = OFF;
                    _ChargingCurrent  = 0 ;
                    // f_xchg = 1 ;
                }
                else
                {
                    f_IN_CFET = ON;
                }
            }
            else
            {
                f_IN = OFF; // close ?
                f_IN_CFET = ON;  // should on ?
            }
    }
}

void Charge_Suspend()
{
    if(f_UT || f_OT)
    {
        f_SU = ON;
    
        //   //   _ChargingCurrent = ChargeCurrent;
             // _ChargingVoltage = ChargeVoltage;
            _ChargingCurrent =0 ;
            _ChargingVoltage = 0;
          
        if(D_FETOptions_CHGSU)
        {
            //Fet_Ctrl &= CFET_OFF;
            f_SU_CFET = OFF;
        }
        else
        {
            f_SU_CFET = ON;
        }
    }
    else
    {
        f_SU_CFET = ON;
        f_SU = OFF;
    }
}

void MaintenanceCharge()
{
    if(f_IN || f_SU || f_PV || BatteryStatus(TCA) == 0)
    {
        f_MCHG = OFF;
    }
    else
    {
        f_MCHG = ON;
    }
}

void Charging_CV_Fun(void)
{
    uint16_t ChargeVoltage = _ChargingVoltage;
    uint16_t ChargeCurrent = _ChargingCurrent;

    if (f_xchg || f_UT || f_OT || BatteryStatus(FC))
    {
        
        ChargeCurrent = 0;
        ChargeVoltage = 0;
    }
    else
    {
        switch (nChargingStatus.data[0])
        {
        case TR_LT:
        {
            if (f_LV)
            {
                ChargeCurrent = D_Low_LT_CCL;
            }
            else if (f_MV)
            {
                ChargeCurrent = D_Low_LT_CCM;
            }
            else if (f_HV)
            {
                ChargeCurrent = D_Low_LT_CCH;
            }
            ChargeVoltage = D_Low_LT_CV * NUMBER_SERIES;
            break;
        }
        case TR_STL:
        {
            if (f_LV)
            {
                ChargeCurrent = D_Standard_STL_CCL;
            }
            else if (f_MV)
            {
                ChargeCurrent = D_Standard_STL_CCM;
            }
            else if (f_HV)
            {
                ChargeCurrent = D_Standard_STL_CCH;
            }
            ChargeVoltage = D_Standard_STL_CV * NUMBER_SERIES;
            break;
        }
        case TR_RT:
        {
            if (f_LV)
            {
                ChargeCurrent = D_Rec_RT_CCL;
            }
            else if (f_MV)
            {
                if(D_Charging_Config_CRATE)
                {
                    // ChargeCurrent = D_Rec_RT_CCM * (t_com10/ t_com18);
                    ChargeCurrent = D_Rec_RT_CCM * (t_com10/ D_Design_Capacity_mAh);
                    

                }
                else
                {
                    ChargeCurrent = D_Rec_RT_CCM;
                }
            }
            else if (f_HV)
            {
                ChargeCurrent = D_Rec_RT_CCH;
            }
            ChargeVoltage = D_Rec_RT_CV * NUMBER_SERIES;
            break;
        }
        case TR_STH:
        {
            if (f_LV)
            {
                ChargeCurrent = D_Standard_STH_CCL;
            }
            else if (f_MV)
            {
                ChargeCurrent = D_Standard_STH_CCM;
            }
            else if (f_HV)
            {
                ChargeCurrent = D_Standard_STH_CCH;
            }
            ChargeVoltage = D_Standard_STH_CV * NUMBER_SERIES;
            break;
        }
        case TR_HT:
        {
            if (f_LV)
            {
                ChargeCurrent = D_High_HT_CCL;
            }
            else if (f_MV)
            {
                ChargeCurrent = D_High_HT_CCM;
            }
            else if (f_HV)
            {
                ChargeCurrent = D_High_HT_CCH;
            }
            ChargeVoltage = D_High_HT_CV * NUMBER_SERIES;
            break;
        }
        }

        if (f_PV)
        {
            ChargeCurrent = D_PreCharging_Current;
        }
    }
    if (f_MCHG)
    {
        ChargeCurrent = D_Maintenance_ChargingCurrent;
    }
    if (f_IN)
    {
        ChargeCurrent = D_Charge_Inhibit_Current;
    }

    if (f_fullchg == OFF) // 5.16改
    {
        if (!D_DA_Configuration_NR && !f_pres)
        {
            ChargeCurrent = 0;
            ChargeVoltage = 0;
        }
    }
    _ChargingCurrent = ChargeCurrent;
    _ChargingVoltage = ChargeVoltage;
    Charge_Inhibit();
    Charge_Suspend();
    // _ChargingCurrent = 0x075A;  // can not put here , becasue will be changed 
    // _ChargingVoltage = 0x3264;
}

void Poly_CC_Calc(void)
{
//	uint8_t al1;
//	// if(F_POLY_EN == ON)
//	// {
//		if(Ts_max < POLY_T[0] || Ts_max > POLY_T[9])
//		{
//			f_POLY_CHG = OFF;
//			t_POLY_CC = 0;
//			return;
//		}
//		else
//		{
//			for(al1 = 0;Ts_max >= POLY_T[al1 + 1] && al1 < 8;al1++);

//			if(polylock == ON)
//			{
//				al1 = 8;
//			}

//			if(lastpolyStep != al1)
//			{
//				poly_cnt1 = 0;
//			}

//			switch(al1)
//			{
//				case 0: 
//					if(lastpolyStep != al1)
//					{
//						if(poly_high == 1 || poly_high == 2)
//						{
//							poly_high = 1;
//							t_POLY_CC = POLY_CC[7];
//							break;
//						}				
//					}

//                    if(V_max >= POLY_V[2] && V_max <= POLY_V[4])
//					{
//						t_POLY_CC = POLY_CC[7];
//						poly_cnt1 = 0;
//						poly_high = 1;
//					}
//					else
//					{
//						if(poly_high == 1)
//						{
//							poly_cnt1++;
//							if(poly_cnt1 >= POLY_HSY_JT)
//							{
//								poly_cnt1 = 0;
//								poly_high = 0;
//								t_POLY_CC = POLY_CC[0];
//							}
//						}
//						else
//						{
//							t_POLY_CC = POLY_CC[0];
//						}
//					}
//				break;
//				case 1:
//					if(lastpolyStep != al1)
//					{
//						if(poly_high == 1 || poly_high == 2)
//						{
//							poly_high = 1;
//							t_POLY_CC = POLY_CC[9];
//							break;
//						}
//					}

//					if(V_max >= POLY_V[2] && V_max <= POLY_V[4])
//					{
//						poly_high = 1;
//						poly_cnt1 = 0;
//						t_POLY_CC = POLY_CC[9];
//					}
//					else
//					{
//						if(poly_high == 1)
//						{
//							poly_cnt1++;
//							if(poly_cnt1 >= POLY_HSY_JT)
//							{
//								poly_cnt1 = 0;
//								poly_high = 0;
//								t_POLY_CC = POLY_CC[8];
//							}
//						}
//						else
//						{
//							t_POLY_CC = POLY_CC[8];
//						}
//					}
//				break;
//				case 2: 
//					if(lastpolyStep != al1)
//					{
//						if(poly_high == 1 || poly_high == 2)
//						{
//							poly_high = 1;
//							t_POLY_CC = POLY_CC[1];
//							break;
//						}	
//					}

//					if(V_max >= POLY_V[3] && V_max <= POLY_V[4])
//					{
//						poly_high = 2;
//						poly_cnt1 = 0;
//						t_POLY_CC = POLY_CC[0];
//					}
//					else if(V_max >= POLY_V[2] && V_max < POLY_V[3])
//					{
//						if(poly_high == 2)
//						{
//							poly_cnt1++;
//							if(poly_cnt1 >= POLY_HSY_JT)
//							{
//								poly_cnt1 = 0;
//								t_POLY_CC = POLY_CC[1];
//								poly_high = 1;
//							}
//						}
//						else
//						{
//							poly_high = 1;
//							poly_cnt1 = 0;
//							t_POLY_CC = POLY_CC[1];
//						}
//					}
//					else
//					{
//						if(poly_high == 1 || poly_high == 2)
//						{
//							poly_cnt1++;
//							if(poly_cnt1 >= POLY_HSY_JT)
//							{
//								poly_high = 0;
//								poly_cnt1 = 0;
//								t_POLY_CC = POLY_CC[3];
//							}
//						}
//						else
//						{
//							poly_high = 0;
//							t_POLY_CC = POLY_CC[3];
//						}
//					}	
//				break;
//				case 3:
//					if(lastpolyStep != al1)
//					{
//						if(poly_high == 1 || poly_high == 2)
//						{
//							poly_high = 1;
//							t_POLY_CC = POLY_CC[3];
//							break;
//						}						
//					}

//					if(V_max >= POLY_V[2] && V_max <= POLY_V[4])
//					{
//						poly_high = 1;
//						poly_cnt1 = 0;
//						t_POLY_CC = POLY_CC[3];
//					}
//					else
//					{
//						if(poly_high == 1)
//						{
//							poly_cnt1++;
//							if(poly_cnt1 >= POLY_HSY_JT)
//							{
//								poly_cnt1 = 0;
//								poly_high = 0;
//								t_POLY_CC = POLY_CC[5];
//							}
//						}
//						else
//						{
//							poly_high = 0;
//							poly_cnt1 = 0;
//							t_POLY_CC = POLY_CC[5];
//						}
//					}
//				break;
//				case 4: 
//					if(lastpolyStep != al1)
//					{
//						poly_stepnum = 0;
//						poly_cnt = 0;
//					}
//					POLY_MinCC = POLY_CC[4];
//					t_POLY_CC = POLY_CC[6];
//				break;
//				case 5:
//					if(lastpolyStep != al1)
//					{
//						poly_stepnum = 0;
//						poly_cnt = 0;
//					}
//					POLY_MinCC = POLY_CC[2];
//					t_POLY_CC = POLY_CC[4];
//				break;
//				case 6: 
//					if(lastpolyStep != al1)
//					{
//						poly_stepnum = 0;
//						poly_cnt = 0;
//					}
//					POLY_MinCC = POLY_CC[1];
//					t_POLY_CC = POLY_CC[2];
//				break;
//				case 7:
//					t_POLY_CC = POLY_CC[1];
//				break;
//				case 8:
//					if(polylock == OFF)
//					{
//						if(V_max >= POLY_V[2] && V_max <= POLY_V[4])
//						{
//							t_POLY_CC = POLY_CC[10];
//							polylock = ON;
//						}
//						else
//						{
//							t_POLY_CC = POLY_CC[2];
//						}
//					}
//					else
//					{
//						if(Ts_max < POLY11_RESETTEMP || V_min < POLY11_RESETVOLT)
//						{
//							polylock = OFF;
//							poly_high = 0;
//							poly_cnt1 = 0;
//						}
//					}
//				break;
//				default:
//				break;
//			}

//			lastpolyStep = al1;
//			if(polylock == OFF)
//			{
//				if(Ts_max >= POLY_T[4] && Ts_max < POLY_T[7])
//				{
//					poly_cnt++;
//					if(poly_cnt == 1)
//					{
//						LastCellTemp = Ts_max;
//					}

//					if(poly_cnt >= POLY_CURSTEP_JT)
//					{
//						poly_stepnum++;
//						poly_cnt = 0;	
//						if(Ts_max - LastCellTemp > 0)
//						{
//							t_POLY_CC -= POLY_STEPDELTA_cur*poly_stepnum;
//						}
//						else
//						{
//							poly_stepnum--;
//							t_POLY_CC -= POLY_STEPDELTA_cur*poly_stepnum;
//						}
//						
//					}
//					else
//					{
//						t_POLY_CC -= POLY_STEPDELTA_cur*poly_stepnum;
//					}	

//					if(t_POLY_CC < POLY_MinCC)
//					{
//						t_POLY_CC = POLY_MinCC;
//					}
//				}
//				else
//				{
//					poly_stepnum = 0;
//					poly_cnt = 0;
//				}		
//			}
//			else
//			{
//				poly_stepnum = 0;
//				poly_cnt = 0;
//			}
//			f_POLY_CHG = ON;
//		}
//	// }
}

void AdvanceChargeAlgorithm_Fun(void)
{
//    uint16_t tempcc,tempcv;
//    tcom14_new = _ChargingCurrent;						// CC/CV backup
//	tcom15_new = _ChargingVoltage;
VoltageRangeJudge();
TemperatureRangeJudge();
MaintenanceCharge();
Charging_CV_Fun();
FFC_Charge();


//	Poly_CC_Calc();
   //if(D_JEITA_EN || D_POLY_EN)
//    {
//        if(f_fullchg == OFF)
//        {
//            if(f_CFET == ON)
//            {
//                if(D_JEITA_EN && D_POLY_EN)
//                {
//                    tempcc = t_POLY_CC > ChargeCurrent?ChargeCurrent:t_POLY_CC;
//                    tempcv = ( POLY_V[4]*D_SERIES) > ChargeVoltage?ChargeVoltage:( POLY_V[4]*D_SERIES);
//                }
//                else if(D_JEITA_EN)
//                {
//                    tempcc = ChargeCurrent;
//                    tempcv = ChargeVoltage;
//                }
//                else
//                {                    
//                    tempcc = t_POLY_CC;
//                    tempcv =  POLY_V[4]*D_SERIES;
//                }            
//            }
//            else
//            {
//                tempcv = NORMAL_CV*D_SERIES;
//                tempcc = 0;
//            }       
//        }
//        else
//        {
//            tempcv = NORMAL_CV*D_SERIES;
//            tempcc = 0;
//        }
//        tcom14_new = tempcc;
//        //smart charge
//        Smart_Charge();
//        if(t_com26 == 0x03)
//        {
//            tcom14_new = t_SmartChargeCC;
//        }
//    }
//    else
//    {
//        tcom14_new = NORMAL_CC;			// ChargingCurrent(Normal)
//        tcom15_new = NORMAL_CV*D_SERIES;
//    }
//    if(f_PV)
//    {
//        tcom14_new = D_PRE_CHGCUR;
//    }
//	_ChargingCurrent = tcom14_new;
//	_ChargingVoltage = tcom15_new;
//}

//void Smart_Charge(void)
//{
//	if(t_com26 == 0x03)
//	{
//		if(f_charge)
//		{
//			switch(asmartstep)
//			{
//				case 0:
//					if(V_max > SMARTCHG_MAXV && _ChargingCurrent <= SMARTCGH_MINCC)
//					{
//						asmartstep = 1;
//						stepnum = 0;
//					}
//				break;
//				case 1:
//					if(V_min > SMARTCHGCV_V2 && t_com0a <= POLY_CC[0])
//					{
//						asmartstep = 1;
//					}
//				break;
//				default:
//				break;
//			}
//		}		
//		switch(asmartstep)
//		{
//			case 0:
//			    t_SmartChargeCV = SMARTCHGCV_V1*D_SERIES;
//                t_SmartChargeCC = SMARTCGH_CC>tcom14_new?tcom14_new:SMARTCGH_CC;
//			    //t_SmartChargeCC = SMARTCGH_CC;				
//				if(t_SmartChargeCC > SMARTCGH_MINCC)
//				{
//                    t_SmartChargeCC -= SMARTCGH_STEPCUR*stepnum;
//				}
//				if(V_max >= SMARTCHG_MAXV) //20221026
//				{
//					if(t_SmartChargeCC > SMARTCGH_MINCC)
//					{
//                        asmart_cnt++;
//						if(asmart_cnt >= SMARTCGH_JT)
//						{
//							asmart_cnt = 0;
//							stepnum++;
//						}
//					}
//					else
//					{
//						asmart_cnt = 0;
//						asmartstep = 1;
//						t_SmartChargeCC = SMARTCGH_MINCC;
//					}
//				}
//				if(f_discharge == ON &&V_min >= SMARTCHGCV_V2)
//				{
//					asmartstep = 1;
//				}
//			   	if(V_max < SMARTCHG_RESETV)
//				{
//					stepnum = 0;
//				}
//			break;
//			case 1:
//				t_SmartChargeCC = SMARTCGH_MINCC;
//				t_SmartChargeCV = SMARTCHGCV_V2*D_SERIES;
//				if(V_max < SMARTCHG_RESETV)
//				{
//					asmartstep = 0;
//					stepnum = 0;
//				}

//				if(f_discharge == ON)
//				{
//					if(V_min >= SMARTCHGCV_V2)
//					{
//						asmartstep = 1;
//					}
//					else
//					{
//						asmartstep = 0;
//						stepnum = 0;
//					}
//				}
//			break;
//			default:
//			break;
//		}
//	}	
}
void Init_ChgSupport(void)
{
//	if(F_QUICKCHG == ON)
//	{
//		f_SQC_En = ON;
//	}
//	if(F_ALWAYQUICKCHG == ON)
//	{
//		f_AlwaySQC_En = ON;
//	}
//	if(F_QUICKCHG == OFF || F_ALWAYQUICKCHG == OFF)
//	{
//        f_SQC_En = OFF;
//		f_AlwaySQC_En = OFF;
//	}	 
}
void FFC_Charge(void)
{
    if(D_Manufacturing_Status_Init_FFC_EN )
    {
        if((V_max-V_min)<=D_FFC_CHARGE_CellimbalanceVoltage)
        {
          if((D_FFC_CHARGE_TemperatureTbl0<=Ts_max) && (Ts_max<D_FFC_CHARGE_TemperatureTbl1))
          {
            if(_ChargingVoltage !=0)
            {
                _ChargingVoltage += D_FFC_CHARGE_ChargeCellVoltageOffsetTbl0;
            }
             Charge_Term= D_FFC_CHARGE_ChargeTaperCurrentTbl0;
          }
          else if((D_FFC_CHARGE_TemperatureTbl1<=Ts_max) && (Ts_max<D_FFC_CHARGE_TemperatureTbl2))
          {
             if(_ChargingVoltage !=0)
            {
                _ChargingVoltage += D_FFC_CHARGE_ChargeCellVoltageOffsetTbl1;
            }
            Charge_Term= D_FFC_CHARGE_ChargeTaperCurrentTbl1;
          }
          else if((D_FFC_CHARGE_TemperatureTbl2<=Ts_max) && (Ts_max<=D_FFC_CHARGE_TemperatureTbl3))
          {
              if(_ChargingVoltage !=0)
            {
                _ChargingVoltage += D_FFC_CHARGE_ChargeCellVoltageOffsetTbl1;
                Charge_Term= D_FFC_CHARGE_ChargeTaperCurrentTbl2;
            }
          }
          else
          {
            Charge_Term=D_Termination_Charge_Term_Taper_Current;
          }

        }
    
    }
}
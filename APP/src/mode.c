#include "mode.h"

uint32_t CB_TimeCelldelta = 0; // LifeTimes_CB_Time_Cell_1
uint8_t CB_Delay_cycles;       // CB:Delay cycles
int16_t Max_Qmax_Cell, Min_Qmax_Cell, Qmax_Pack;
uint8_t QIM_Delay_times; // QIM:Delay updates
uint16_t lastQmaxcyclecount, Qmaxcyclecount;
uint8_t CD_Delay_cycles;               // CD:Delay cycles
int32_t IntTemp, MosFetTemp; // Internal Temperature
uint16_t IntTempK;

uint8_t f_rsoc_hold;


uint8_t old_rsoc;
// Qmax
uint16_t QmaxControl;
int32_t at_startqmax_cnt; // Start Count
int32_t at_endqmax_cnt;   // End  Count
int32_t QmaxCapcity_Calc; // QMax Capcity
uint8_t Qamx1InitSOC;
uint8_t Qamx2InitSOC;
uint8_t Qamx3InitSOC;
uint8_t Qamx4InitSOC;
uint8_t PackQamxInitSOC;
uint8_t Qamx1EndSOC;
uint8_t Qamx2EndSOC;
uint8_t Qamx3EndSOC;
uint8_t Qamx4EndSOC;
uint8_t PackQamxEndSOC;

int16_t g_QamxPack;
uint16_t QmaxUpdataCnt;
uint16_t Qmax1UpdataCnt;
uint16_t Qmax2UpdataCnt;
uint16_t Qmax3UpdataCnt;
uint16_t Qmax4UpdataCnt;
uint16_t LastQMaxUpdataCycle;
uint16_t LastQMaxUpdataValue;

volatile uint32_t COFF_delay = 0;
// CB
uint16_t ex_CB1Cnt = 0;
uint16_t ex_CB2Cnt = 0;
uint16_t ex_CB3Cnt = 0;
uint16_t ex_CB4Cnt = 0;
uint16_t acb_w;            // Cell balance select flag
const uint8_t acond_tbl[4] // Conditioning table
    = {DTDRV_CVBLC_CB_VC1, DTDRV_CVBLC_CB_VC2, DTDRV_CVBLC_CB_VC3, DTDRV_CVBLC_CB_VC4};

uint16_t CBstatus;

void AlarmWarning_Check(void)
{
    if (SafetyStatus(OC))
    {
        if (f_charge)
        {
            BatteryStatus(OCA) = ON;
        }
    }
    else
    {
        BatteryStatus(OCA) = OFF;
    }

    if (f_gs_tc)
    {
        // Condition: CLEAR V
        if (D_SOC_Flag_Config_A_TCCLEARV)
        {
            if (V_max <= D_TC_Clear_Voltage_Threshold)
            {
                f_gs_tc = OFF;
            }
        }
        // Condition: CLEAR RSOC
        if (D_SOC_Flag_Config_A_TCCLEARRSOC)
        {
            if (t_com0d <= D_TC_Clear_RSOC_Threshold)
            {
                f_gs_tc = OFF;
            }
        }
    }
    else
    {
        // Condition: SET V
        if (D_SOC_Flag_Config_A_TCSETV)
        {
            if (V_max >= D_TC_Set_Voltage_Threshold) // 
            {
                f_gs_tc = ON;
            }
        }
        // Condition: SET RSOC
        if (D_SOC_Flag_Config_A_TCSETRSOC)
        {
            if (t_com0d >= D_TC_Set_RSOC_Threshold)
            {
                f_gs_tc = ON;
            }
        }
        // Condition: SET VCT
        if (D_SOC_Flag_Config_A_TCSETVCT)
        {
            if (f_VCT)
            {
                f_gs_tc = ON;
            }
        }
    }

    if (f_gs_fc)
    {
        // Condition: CLEAR V
        if (D_SOC_Flag_Config_B_FCCLEARV)
        {
            if (V_max <= D_FC_Clear_Voltage_Threshold)
            {
                f_gs_fc = OFF;
            }
        }
        // Condition: CLEAR RSOC
        if (D_SOC_Flag_Config_B_FCCLEARRSOC)
        {
            if (t_com0d <= D_FC_Clear_RSOC_Threshold)
            {
                f_gs_fc = OFF;
            }
        }
    }
    else
    {
        // Condition: SET V
        if (D_SOC_Flag_Config_B_FCSETV)
        {
            if (V_max >= D_FC_Set_Voltage_Threshold)
            {
                f_gs_fc = ON;
            }
        }
        // Condition: SET RSOC
        if (D_SOC_Flag_Config_B_FCSETRSOC)
        {
            if (t_com0d >= D_FC_Set_RSOC_Threshold)
            {
                f_gs_fc = ON;
            }
        }
        // Condition: SET VCT
        if (D_SOC_Flag_Config_A_FCSETVCT)
        {
            if (f_VCT)
            {
                f_gs_fc = ON;
            }
        }
    }

    if (f_gs_td)
    {
        // Condition: CLEAR V
        if (D_SOC_Flag_Config_A_TDCLEARV)
        {
            if (V_min >= D_TD_Clear_Voltage_Threshold)
            {
                f_gs_td = OFF;
            }
        }
        // Condition: CLEAR RSOC
        if (D_SOC_Flag_Config_A_TDCLEARRSOC)
        {
            if (t_com0d >= D_TD_Clear_RSOC_Threshold)
            {
                f_gs_td = OFF;
            }
        }
    }
    else
    {
        // Condition: SET V
        if (D_SOC_Flag_Config_A_TDSETV)
        {
            if (V_min <= D_TD_Set_Voltage_Threshold)
            {
                f_gs_td = ON;
            }
        }
        // Condition: SET RSOC
        if (D_SOC_Flag_Config_A_TDSETRSOC)
        {
            if (t_com0d <= D_TD_Set_RSOC_Threshold)
            {
                f_gs_td = ON;
            }
        }
    }

    if (f_gs_fd)
    {
        // Condition: CLEAR V
        if (D_SOC_Flag_Config_B_FDCLEARV)
        {
            if (V_min >= D_FD_Clear_Voltage_Threshold)
            {
                f_gs_fd = OFF;
            }
        }
        // Condition: CLEAR RSOC
        if (D_SOC_Flag_Config_B_FDCLEARRSOC)
        {
            if (t_com0d >= D_FD_Clear_RSOC_Threshold)
            {
                f_gs_fd = OFF;
            }
        }
    }
    else
    {
        // Condition: SET V
        if (D_SOC_Flag_Config_B_FDSETV)
        {
            if (V_min <= D_FD_Set_Voltage_Threshold)
            {
                f_gs_fd = ON;
            }
        }
        // Condition: SET RSOC
        if (D_SOC_Flag_Config_B_FDSETRSOC)
        {
            if (t_com0d <= D_FD_Set_RSOC_Threshold)
            {
                f_gs_fd = ON;
            }
        }
    }
    // BatteryStatus
    if ((f_gs_td && f_discharge) || (!D_DA_Configuration_NR && !f_pres) ||  SafetyAlert(CUV) || SafetyAlert(OCD1) || SafetyAlert(OCD2) || SafetyAlert(OTF) || SafetyAlert(OTD) || SafetyStatus(UTD) || SafetyStatus(AOLD) || SafetyStatus(ASCD) || f_pf_suv_a || f_pf_socd_a || f_pf_cb_p || f_fuse_out)
    {
        BatteryStatus(TDA) = ON;
    }
    else
    {
        BatteryStatus(TDA) = OFF;
    }

    if ((f_gs_tc && f_charge) || (!D_DA_Configuration_NR && !f_pres) || SafetyAlert(COV) || SafetyAlert(OCC1) || SafetyAlert(OCC2) || SafetyStatus(ASCC) || SafetyAlert(OTC) || SafetyAlert(UTC)|| SafetyAlert(OC) || SafetyAlert(CHGC) || SafetyAlert(CHGV) || SafetyAlert(OTF) || SafetyAlert(PCHGC) || f_pf_sov_a || f_pf_socc_a || f_pf_cb_p || f_fuse_out)
    {
        BatteryStatus(TCA) = ON;
    }
    else
    {
        BatteryStatus(TCA) = OFF;
    }

    if (SafetyStatus(OTC) || SafetyStatus(OTD) || SafetyStatus(OTF) || f_pf_sot_p || f_pf_sotf_p)
    {
        BatteryStatus(OTA) = ON;
    }
    else
    {
        BatteryStatus(OTA) = OFF;
    }

    if (f_gs_fc)
    {
        BatteryStatus(FC) = ON;
    }
    else
    {
        BatteryStatus(FC) = OFF;
        // f_VCT = OFF; // battery charge termination f_VCT = ON;
        f_fullchg = OFF;
    }

    if (f_gs_fd || SafetyStatus(CUV) || f_pf_suv_p || SafetyStatus(CUVC) || f_pf_suv_p)
    {
        BatteryStatus(FD) = ON;
    }
    else
    {
        BatteryStatus(FD) = OFF;
    }

    if (t_com0fCap <= _RemainingCapacityAlarm)
    {
        if (BatteryStatus(DSG))
        {
            BatteryStatus(RCA) = ON;
        }
    }
    else
    {
        BatteryStatus(RCA) = OFF;
    }
    if (_AverageTimeToEmpty < D_Data_Remaining_Time_Alarm)
    {
        BatteryStatus(RTA) = ON;
    }
    else
    {
        BatteryStatus(RTA) = OFF;
    }
}
void QMaxUpdateReset(void)
{
    f_Qmax_start = OFF;
    f_Qmax_end = OFF;
    at_endqmax_cnt = 0;
    at_startqmax_cnt = 0;
    QmaxCapcity_Calc = 0;
}

void QMaxUpdateJudge(uint8_t InitSOC, uint8_t EndSOC, int16_t *QamxCell)
{
   uint8_t dropSoc;
   if ((InitSOC < D_Qmax_SOC_low_limit || InitSOC > D_Qmax_SOC_high_limit) && (EndSOC < D_Qmax_SOC_low_limit || EndSOC > D_Qmax_SOC_high_limit))
   {
       dropSoc = ABS(InitSOC - EndSOC);
       if (dropSoc > D_Qmax_update_min_delta_SOC)
       {
           *QamxCell = (int16_t)(QmaxCapcity_Calc / 144 / dropSoc);
           f_ltreq = ON;
           f_QmaxUpFsh = ON;
            t_com0c = 1 ;
       }
       else
       {
           QMaxUpdateReset();
       }
   }
   else
   {
       QMaxUpdateReset();
   }
}

void QMax_Calc(void)
{
    uint8_t aidx = 0;
    int8_t dropSoc;

    if (Ts_max >= D_Qmax_Temp_Low_limit && Ts_max <= D_Qmax_Temp_High_limit && _CycleCount > D_Qmax_Cycle_limit)
    {
        if (f_relax)
        {
            if (!f_Qmax_start)
            {
                at_startqmax_cnt++;
                if (at_startqmax_cnt >= 72000)
                {
                    for (aidx = 0; (aidx < 19) && (V_min > OCV_SOC[aidx + 1]); aidx++)
                        ;
                    PackQamxInitSOC = (char)aidx * 5 + (short)((short)(V_min - OCV_SOC[aidx]) * 5) / (short)(OCV_SOC[aidx + 1] - OCV_SOC[aidx]);
                    for (aidx = 0; (aidx < 19) && (_DAStatus1.CellVoltage1 > OCV_SOC[aidx + 1]); aidx++)
                        ;
                    Qamx1InitSOC = (char)aidx * 5 + (short)((short)(_DAStatus1.CellVoltage1 - OCV_SOC[aidx]) * 5) / (short)(OCV_SOC[aidx + 1] - OCV_SOC[aidx]);
                    for (aidx = 0; (aidx < 19) && (_DAStatus1.CellVoltage2 > OCV_SOC[aidx + 1]); aidx++)
                        ;
                    Qamx2InitSOC = (char)aidx * 5 + (short)((short)(_DAStatus1.CellVoltage2 - OCV_SOC[aidx]) * 5) / (short)(OCV_SOC[aidx + 1] - OCV_SOC[aidx]);
                    for (aidx = 0; (aidx < 19) && (_DAStatus1.CellVoltage3 > OCV_SOC[aidx + 1]); aidx++)
                        ;
                    Qamx3InitSOC = (char)aidx * 5 + (short)((short)(_DAStatus1.CellVoltage3 - OCV_SOC[aidx]) * 5) / (short)(OCV_SOC[aidx + 1] - OCV_SOC[aidx]);
                    for (aidx = 0; (aidx < 19) && (_DAStatus1.CellVoltage4 > OCV_SOC[aidx + 1]); aidx++)
                        ;
                    Qamx4InitSOC = (char)aidx * 5 + (short)((short)(_DAStatus1.CellVoltage4 - OCV_SOC[aidx]) * 5) / (short)(OCV_SOC[aidx + 1] - OCV_SOC[aidx]);
                    f_Qmax_start = ON;
                    f_Qmax_end = OFF;
                    at_endqmax_cnt = 0;
                    at_startqmax_cnt = 0;
                }
            }
            else
            {
                at_endqmax_cnt++;
                if (at_endqmax_cnt >= 72000)
                {
                    for (aidx = 0; (aidx < 19) && (V_min > OCV_SOC[aidx + 1]); aidx++)
                        ;
                    PackQamxEndSOC = (char)aidx * 5 + (short)((short)(V_min - OCV_SOC[aidx]) * 5) / (short)(OCV_SOC[aidx + 1] - OCV_SOC[aidx]);
                    for (aidx = 0; (aidx < 19) && (_DAStatus1.CellVoltage1 > OCV_SOC[aidx + 1]); aidx++)
                        ;
                    Qamx1EndSOC = (char)aidx * 5 + (short)((short)(_DAStatus1.CellVoltage1 - OCV_SOC[aidx]) * 5) / (short)(OCV_SOC[aidx + 1] - OCV_SOC[aidx]);
                    for (aidx = 0; (aidx < 19) && (_DAStatus1.CellVoltage2 > OCV_SOC[aidx + 1]); aidx++)
                        ;
                    Qamx2EndSOC = (char)aidx * 5 + (short)((short)(_DAStatus1.CellVoltage2 - OCV_SOC[aidx]) * 5) / (short)(OCV_SOC[aidx + 1] - OCV_SOC[aidx]);
                    for (aidx = 0; (aidx < 19) && (_DAStatus1.CellVoltage3 > OCV_SOC[aidx + 1]); aidx++)
                        ;
                    Qamx3EndSOC = (char)aidx * 5 + (short)((short)(_DAStatus1.CellVoltage3 - OCV_SOC[aidx]) * 5) / (short)(OCV_SOC[aidx + 1] - OCV_SOC[aidx]);
                    for (aidx = 0; (aidx < 19) && (_DAStatus1.CellVoltage4 > OCV_SOC[aidx + 1]); aidx++)
                        ;
                    Qamx4EndSOC = (char)aidx * 5 + (short)((short)(_DAStatus1.CellVoltage4 - OCV_SOC[aidx]) * 5) / (short)(OCV_SOC[aidx + 1] - OCV_SOC[aidx]);

                    f_Qmax_end = ON;
                    f_Qmax_start = OFF;
                    at_endqmax_cnt = 0;
                    at_startqmax_cnt = 0;
                    QmaxCapcity_Calc = 0;
                }
            }

            if (f_Qmax_end)
            {
                QMaxUpdateJudge(PackQamxInitSOC, PackQamxEndSOC, &g_QamxPack);
                QMaxUpdateJudge(Qamx1InitSOC, Qamx1EndSOC, &_GaugeStatus3.QMax0);
                QMaxUpdateJudge(Qamx2InitSOC, Qamx2EndSOC, &_GaugeStatus3.QMax1);
                QMaxUpdateJudge(Qamx3InitSOC, Qamx3EndSOC, &_GaugeStatus3.QMax2);
                QMaxUpdateJudge(Qamx4InitSOC, Qamx4EndSOC, &_GaugeStatus3.QMax3);
                if (f_QmaxUpFsh)
                {
                    f_QmaxUpFsh = OFF;
                    QmaxUpdataCnt++;
                    LastQMaxUpdataCycle = _CycleCount;
                    LastQMaxUpdataValue = g_QamxPack;
                    QMaxUpdateReset();
                }
            }
        }
        else
        {
            if (I_abs >= (long)D_Qmax_C_rate_low_limit * D_Design_Capacity_mAh / 10 && I_abs <= (long)D_Qmax_C_rate_high_limit * D_Design_Capacity_mAh / 10 && f_Qmax_start == ON) // 0.1C
            {
                if (D_Control_flag_1_Qmax_update_DSG)
                {
                    if (f_charge)
                    {
                        f_Qmax_start = OFF;
                        f_Qmax_end = OFF;
                        at_startqmax_cnt = 0;
                        QmaxCapcity_Calc = 0;
                    }
                    else
                    {
                        QmaxCapcity_Calc += I_abs;
                    }
                }

                if (D_Control_flag_1_Qmax_update_CHG)
                {
                    if (f_discharge)
                    {
                        f_Qmax_start = OFF;
                        f_Qmax_end = OFF;
                        at_startqmax_cnt = 0;
                        QmaxCapcity_Calc = 0;
                    }
                    else
                    {
                        QmaxCapcity_Calc += I_abs;
                    }
                }
            }
            else
            {
                f_Qmax_end = OFF;
                at_startqmax_cnt = 0;
            }
            at_endqmax_cnt = 0;
        }
    }
    else
    {
        QMaxUpdateReset();
    }
}
void fuse_low()
{
    FUSE_OUT(0);
    f_fuse_out = OFF;
}

void FUSE_Contrl()
{
    if(f_fuse_out)
    {
        if(D_FETOptions_PACK_FUSE)
        {
            if(PackVoltage() > D_Fuse_Min_Blow_Fuse_Voltage)
            {
                FUSE_OUT(1);
                if (!getSoftTimerStatus(SOFT_TIMER_FUSE_LOW_ID))
                {
                    StartSoftTimer(SOFT_TIMER_FUSE_LOW_ID, SINGLE_MODE, D_Fuse_Blow_Timeout * 1000, fuse_low);
                }

                // fuse_blow_flag = 1;
                // // FUSE_OUT(1);
                // if(fuse_timeout/1000 > D_Fuse_Blow_Timeout)
                // {
                //     fuse_blow_flag = 0;
                //     fuse_timeout = 0;
                //     f_fuse_out = OFF;
                //     // FUSE_OUT(0);
                // }
            }
            
        }
        else
        {
            if(Voltage() > D_Fuse_Min_Blow_Fuse_Voltage)
            {
                FUSE_OUT(1);
                if (!getSoftTimerStatus(SOFT_TIMER_FUSE_LOW_ID))
                {
                    StartSoftTimer(SOFT_TIMER_FUSE_LOW_ID, SINGLE_MODE, D_Fuse_Blow_Timeout * 1000, fuse_low);
                }
            }
        }
    }
    
}
void FET_Contrl(void)
{
    static uint8_t flag = 0;
    if (((SafetyStatus(OTD) || SafetyStatus(UTD)) && f_fullchg) || SafetyStatus(COVL) || SafetyStatus(OCDL) || SafetyStatus(OTF) || SafetyStatus(ASCD) || SafetyStatus(ASCC) || SafetyStatus(AOLD) ||
        f_ship || SafetyStatus(AOLDL) || SafetyStatus(ASCDL) || SafetyStatus(ASCCL) ||
        (_PFStatus.value & 0xFFBFFFFF)) // D-ON && C-ON
    {
        Fet_Ctrl = FET_OFF;
        // flag = 0;
    }

    if (SafetyStatus(COV) || SafetyStatus(OCC1) || SafetyStatus(OCC2) || SafetyStatus(OTC) || SafetyStatus(UTC) || SafetyStatus(HWD) || SafetyStatus(PTO) || SafetyStatus(CTO) || SafetyStatus(OC) || SafetyStatus(PCHGC) || SafetyStatus(CHGC) || SafetyStatus(CHGV) || (!f_FET_EN && !f_CHG_EN)) // D-ON && C-OFF
    {
        Fet_Ctrl &= CFET_OFF;
        // flag = 0;
    }

    if ((SafetyStatus(CUV) &&(!f_charge))|| SafetyStatus(CUVC) || SafetyStatus(OCD1) || SafetyStatus(OCD2) ||
        SafetyStatus(OTD) || SafetyStatus(UTD) || SafetyStatus(OCDL) || (!f_FET_EN && !f_DSG_EN)) // D-OFF && C-ON
    {
        Fet_Ctrl &= DFET_OFF;
        // flag = 0;
    }

if(!f_IN_CFET || !f_SU_CFET)
{
    Fet_Ctrl &= CFET_OFF;
}
/************************** Sleep Mode ******************************/
    if(!f_sleepPCFET)
    {
        Fet_Ctrl &= PCFET_OFF;
    }
    if (!f_sleepCFET)
    {
        Fet_Ctrl &= CFET_OFF;
    }
    if(!f_sleepDFET)
    {
        Fet_Ctrl &= DFET_OFF;
    }
/*************************** Shutdown ********************************/
    if(!f_sdvDFET || !f_sdmDFET)
    {
        // printf("sdv %d\nsdm %d\n",f_sdvDFET,f_sdmDFET);
        Fet_Ctrl &= DFET_OFF;
    }
    if(!f_sdmCFET || !f_sdvDFET)
    {
        Fet_Ctrl &= CFET_OFF;
    }
/*********************************************************************/
    if (D_DA_Configuration_NR == 0) // 5.16
    {
        if (!f_pres) // 5.16
        {
            Fet_Ctrl &= (DFET_OFF & CFET_OFF);
            // flag = 0;
        }
    }
    if (f_gs_fc)
    {
        if ((t_com0d == 100) && !f_discharge)
        {
            if (COFF_delay / 1000 >= 2)
            {
                COFF_delay = 0;
                flag = 1;
            }
            if (flag)
            {
                Fet_Ctrl &= CFET_OFF;
            }
        }
        else
        {
            flag = 0;
            if (!f_discharge)
            {
                Fet_Ctrl &= CFET_OFF;
                // flag = 0;
            }
        }
    }

    if(f_discharge && !(_PFStatus.value & 0xFFFFFFFF))
    {
        Fet_Ctrl |= 0x02;
    }

    Set_FET();
}

static void FullCharge(void)
{
    uint16_t twork;
    if (D_Control_flag_1_DIS_DSG_Releaning == OFF) // Dischg relearn not disable ?
    {
        f_study_d = ON; // Set discharge relearn flag
        f_study_d1 = ON;
        f_study_d2 = ON;
    }

    if (Ts_max < D_FCC_relearn_temp_limit || f_study_c == OFF) // Less than relearn limit temp  // or Charge relearn flag=OFF ?
    {
        if (Record_trek_cnt != 0 && D_FCC_Deterioration_capacity != 0) // Degradation cnt is not 0 ?
        {
            // FCC = FCC - (Degradation counter * Degradation capacity)
            twork = (uint16_t)(((long)Record_trek_cnt * D_FCC_Deterioration_capacity) / 100);
            if (t_com10 > twork) // Not Under flow ?
            {
                t_com10 = t_com10 - twork;
                tccup = (uint16_t)((long)t_com10 * ABS(D_Cycle_Count_Percentage)/100);
            }
            else
            {
                t_com10 = 10; // Under flow
                tccup = (uint16_t)((long)t_com10 * ABS(D_Cycle_Count_Percentage)/100);
            }
        }
    }
    else
    {                                            // Make relearning
        arelearn_cnt = 0;                        // Clear Relearning counter
        f_relearn = OFF;                         // Clear Relearning flag
        tcom10c_w = (uint16_t)(lrccr_w / 14400); // Calc new FCC
        FCC_Limit_Chk();                         // FCC inc/dec limit check
        t_com10 = tcom10c_w;                     // Set FullChargeCapacity()

        Record_lrc_w =  (uint32_t)t_com10 * (60 * 60*4);   // idea rc * 14400
        Record_Ilrc_w = (long)t_com89* 14400; // Calc RC integration work

        // Record_Ilrc_w =  (uint32_t)t_com88 * (60 * 60*4);   // idea rc * 14400
        tccup = (uint16_t)((long)t_com10 * ABS(D_Cycle_Count_Percentage)/100);

        t_com8a = 100 ;  // idea rsoc = 100 
        t_com0d = 100; 

        t_com0f = t_com10; // Update RemainingCapacity()
        t_com88 =  t_com89 ;  // idea rc = idea fcc 
        

    }
    Record_trek_cnt = 0; // Clear degradation counter
    f_study_c = OFF;

    if (f_fullchg == OFF) // FULLY_CHARGED == OFF ?
    {
        Record_lrc_w = (long)t_com10 * 14400; // Calc RC integration work
        Record_Ilrc_w = (long)t_com89 * 14400; // Calc RC integration work
        if (f_study_d == ON)           // Start discharge relearn ?
        {
            lrcdr_w = 0; // Clear discharge relarn cap.
        }
        t_com0d = 100;     // RSOC=100%
        t_com8a = 100 ;  // idea rsoc = 100 

        t_com0f = t_com10; // Update RemainingCapacity()
        t_com88 = t_com89 ;  // idea rc = idea fcc 
        
        // (To prevent changing CC when capacity is jumped.)
        toldrc = t_com10; // Update to RemCap value last time
                          // Update last RemCap
    }
    f_fullchg = ON; // Set FULLY_CHARGED
    f_ful_chg_once = 1 ;
    f_VCT = ON;
    //	acccv_cnt = 0;								// Clear CC/CV time counter
   // t_com0c = 0;     // Clear MaxError
    lmaxerr_cnt = 0; // Clear MaxError counter
    _ChargingCurrent = 0;     // ChargingCurrent() = 0
}

/********************************
 * Function Name: FullCharge_Chk
 * Return:        void
 * note: void
 *********************************/
void FullCharge_Chk(void)
{
    // FCC
    static uint16_t tfc_cnt = 0;
    static uint32_t rc_integral = 0;
    uint16_t twork;

    if (t_com0d < 100)
    {
        f_VCT = OFF;
    }

    // if(f_pi_mode)  // step into pimode , not dsg update .
	// {
    //     f_study_d = 0 ;
	// }
    


    // Not OVER_CHARGED_ALARMf_chg
    // if (f_chg) // C-FET = ON ?
    // {
    if (f_charge == ON && f_chg) // Charging current detection ?
    {
        if (f_fullchg == ON) // FULLY_CHARGED = ON ?
        {
            if (t_com0f >= t_com10) // RC >= FCC ?
            {
                FullCharge(); // Full Charge Processing
            }
        }
        else
        { // FULLY_CHARGED = OFF
          // MaxV >= Single cell CV-FCtaperV
          // & Full Charge Current less than ?
            // t_com3a_out = NUMBER_SERIES  ;
            if ((V_max >= (_ChargingVoltage/NUMBER_SERIES - D_Termination_Charge_Term_Voltage)) && (_AverageCurrent < Charge_Term))
            {
                tfc_cnt++; // Full Charge check count + 1
                rc_integral += I_abs;
                // Full charge determination time elapsed ?
                if (tfc_cnt >= D_Termination_Fullcharge_judgement_time * 4)
                {
                    // tfc_cnt = 0;  // Clear Full Charge check count
                    if (rc_integral / 4 / 3600 >= D_Termination_Charge_Term_Taper_Capacity)
                    {
                        tfc_cnt = 0;
                        rc_integral = 0;
                        FullCharge(); // Full Charge Processing
                    }
                    else
                    {
                        tfc_cnt = D_Termination_Fullcharge_judgement_time - 1;
                    }
                }
            }
            else if(SafetyStatus(COV))
            {
                FullCharge();
            }
            // else
            // {
            //     if (tfc_cnt != 0) // Full Charge check count = 0 ?
            //     {
            //         tfc_cnt-=Periodtime; // Full Charge check count - 1
            //     }
            //     rc_integral = 0;
            // }
        }
    }
    else
    {
        // Charging current undetected
        tfc_cnt = 0; // Clear Full Charge check count
        rc_integral = 0;
    }

   // }
}


void CellBalance_Chk(void)
{
   uint8_t i;
   uint8_t awork;
   static uint32_t balace_delay = 0;
   if (D_Balancing_Configuration_CB && (f_charge || (D_Balancing_Configuration_CBR && f_relax))) // Rest or Charging
   {
       if (V_max < D_Cell_Enable_voltage_upper_limit && V_min >= D_Cell_Enable_voltage_lower_limit) // Is voltage a cell balancing possible range ?
       {
           awork = 0;                      // Initialize work area
           if ((V_max - V_min) >= D_Cell_balancing_ON_voltage) // Is voltage "cell balancing On voltage" or more ?
           {
               for (i = 0; i < NUMBER_SERIES; i++) // Cell imbalance check loop
               {
                   // Is the voltage "cell balancing On voltage" or more ?
                   if ((afe_data.cell_vol_val[i] - V_min) >= D_Cell_balancing_ON_voltage)
                   {
                       awork |= acond_tbl[i]; // Set to cell balance list
                   }
               }
           }

           if (acb_w != 0) // Now controlling cell balance ?
           {
               for (i = 0; i < NUMBER_SERIES; i++) // imbalance check loop
               {
                   // Is it controlled cell ?
                   if ((acb_w & acond_tbl[i]) != 0)
                   {

                       lifetime_ram.cb_time_cell[i]+= Periodtime; // Cell balance time
                       // Is the voltage less than "Cell balance OFF voltage" ?
                       if ((afe_data.cell_vol_val[i] - V_min) < D_Cell_balancing_OFF_voltage)
                       {
                           // Clear it from cell balance list
                           acb_w ^= acond_tbl[i];
                       }
                   }
               }
               if (acb_w == 0 && awork == 0) // All cell stop cell balance ?
               {
                   f_cb = OFF;
                   acb_w = 0; // Clear the list
                    // balace_delay = 0; // Clear delay time
                    // printf("tuichubalancen!\n");
                   afe_dtdrv_vc_enable_ctrl(DTDRV_CVBLC_CB_VC1 | DTDRV_CVBLC_CB_VC2 | DTDRV_CVBLC_CB_VC3 | DTDRV_CVBLC_CB_VC4, DISABLE);
               }
           }

           acb_w |= awork; // Merge control and start list

           if ((acb_w != 0) )//&& (!f_cb)) // Is there cell balance control ?
           {
            //    balace_delay += Periodtime;
            //     if (balace_delay >= 30 * 1000) // Cell balancing delay time ?
            //     {
            //         printf("balancen!\n");
            //          balace_delay = 0; // Clear delay time
            //          //afe_cb_control(acb_w);
            //          afe_dtdrv_vc_enable_ctrl(DTDRV_CVBLC_CB_VC1, ENABLE);
                     
            //          f_cb = ON;
            //     }
             f_cb = ON;
               afe_dtdrv_vc_enable_ctrl(acb_w, ENABLE);

           }
       }
       else
       {
           f_cb = OFF;
           acb_w = 0;
       }
   }
   else
   {
       f_cb = OFF;
       acb_w = 0;
   }
   // a_com45[0] = acb_w;							// CellBalancing Status(Cell 1 - 4)
}

void Calc_ATTF(void)
{
    int num = 0;
    ATTF_SetChgFlag(f_charge);
    if (_AverageCurrent > 0)
    {
        ATTF_SetRC(t_com0f);
        ATTF_SetFCC(t_com10);
        ATTF_SetTEM(Ts_max); // set temperature
        ATTF_SetFCFlag(f_fullchg);

        _AverageTimeToFull = Calc_ATTF1(Current());
    }
    else
    {
        _AverageTimeToFull = 0xFFFF;
    }

    if (_AtRate > 0)
    {
        _AtRateTimeToFull = (long)(t_com10 - t_com0f) * 60 / ABS(_AtRate);
    }
    else
    {
        _AtRateTimeToFull = 0xFFFF;
    }
}

void Calc_ATTE(void)
{
    if (Current() < 0)
    {
        _RunTimeToEmpty = (long)t_com0f * 60 / ABS(Current());
    }
    else
    {
        _RunTimeToEmpty = 0xFFFF;
    }

    if (_AverageCurrent < 0)
    {
        _AverageTimeToEmpty = (long)t_com0f * 60 / ABS(_AverageCurrent);
    }
    else
    {
        _AverageTimeToEmpty = 0xFFFF;
    }

    //    if(_AverageTimeToEmpty <= t_com02)
    //    {
    //        f_rta_a = ON;
    //    }
    //    else
    //    {
    //        f_rta_a = OFF;
    //    }

    // if (_AtRate >= 0)
    // {
    //     _AtRateTimeToEmpty = 0xFFFF;
    // }
    // else
    // {
        _AtRateTimeToEmpty = (long)t_com0f * 60 / ABS(_AtRate);  
    // }

    if (_AtRate >= 0)
    {
        _AtRateOK = 0x0001;
    }

    if (_AtRate < 0 && (_AtRate + Current()) >= 0)
    {
        _AtRateOK = 0x0001;
    }

    if (_AtRate < 0 && (_AtRate + Current()) < 0)
    {
        if (((long)(t_com0f * 360) / ABS(_AtRate + Current())) != 0)
        {
            _AtRateOK = 0x0001;
        }
        else
        {
            _AtRateOK = 0x0000;
        }
    }
}


void afe_cb_control(uint8_t status)
{
    
    /* 控制vc1 */
    if(status & DTDRV_CVBLC_CB_VC1)
    {
        afe_dtdrv_vc_enable_ctrl(DTDRV_CVBLC_CB_VC1, ENABLE);
       // printf("enable cb vc1");
    }
   
    if(status & DTDRV_CVBLC_CB_VC2)
    {
        afe_dtdrv_vc_enable_ctrl(DTDRV_CVBLC_CB_VC2, ENABLE);
      // printf("enable cb vc2");
    }
 
    if(status & DTDRV_CVBLC_CB_VC3)
    {
        afe_dtdrv_vc_enable_ctrl(DTDRV_CVBLC_CB_VC3, ENABLE);
      //  printf("enable cb vc3");
    }
   
    /* 控制vc4 */
    if(status& DTDRV_CVBLC_CB_VC4)
    {
        afe_dtdrv_vc_enable_ctrl(DTDRV_CVBLC_CB_VC4, ENABLE);
       // printf("enable cb vc4");
    }
  
    #if(defined(CBM8581))
    /* 控制vc5 */
    if(status& DTDRV_CVBLC_CB_VC5)
    {
        afe_dtdrv_vc_enable_ctrl(DTDRV_CVBLC_CB_VC5, ENABLE);
        //printf("enable cb vc5");
    }
    
    #endif
}



void RSOC_HOLD(void)
{
    if (f_rsoc_hold)
    {
        if(!f_charge)
        {
            if(t_com0d>old_rsoc)
            {
                t_com0d = old_rsoc;
            }
            
        }
        old_rsoc = t_com0d;
    }
}

void pi_blance_enable(void)
{
    uint16_t awork;
    uint8_t i=0;
    for (i = 0; i < NUMBER_SERIES; i++) // Cell imbalance check loop
    {

        awork |= acond_tbl[i]; // Set to cell balance list
    }
    f_cb = ON;
    afe_dtdrv_vc_enable_ctrl(awork, ENABLE);
}

void pi_blance_disable(void)
{
    f_cb = OFF;
    afe_dtdrv_vc_enable_ctrl(DTDRV_CVBLC_CB_VC1 | DTDRV_CVBLC_CB_VC2 | DTDRV_CVBLC_CB_VC3 | DTDRV_CVBLC_CB_VC4, DISABLE);
}
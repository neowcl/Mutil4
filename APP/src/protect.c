#include "protect.h"
#include "main.h"

volatile uint8_t trip_2lvl;
volatile uint8_t shutdown_wake_flag;
volatile uint16_t ascdl_counter = 0;
volatile uint16_t asccl_counter = 0;
volatile uint16_t aoldl_counter = 0;
uint16_t Temp_Change=0;
uint16_t pi_test=1;
uint8_t  f_pi_pinghua ;

void Protect_CUV()
{
    static uint32_t delay = 0;

    if (SafetyStatus(CUV))
    {
        if (D_Protection_Configuration_CUV_RECOV_CHG)
        {
            if (PackVoltage() > D_CUV_Charge_Presen_Threshol)
            {
                if (V_min > D_CUV_Recovery)
                {
                    SafetyStatus(CUV) = OFF;
                }
            }
        }
        else
        {
            if (V_min > D_CUV_Recovery)
            {
                SafetyStatus(CUV) = OFF;
            }
        }
    }
    else
    {
        if (D_Enabled_Protections_A_CUV)
        {

            if (V_min < (D_CUV_Threshold-Temp_Change))
            {
                SafetyAlert(CUV) = ON;
                delay += Periodtime;
                if (delay / 1000 >= (D_CUV_Delay+1))
                {
                    SafetyStatus(CUV) = ON;
                    SafetyAlert(CUV) = OFF;
                    life_Time_Protect_Event(LT_CUV);
                    delay = 0;
                }
            }
            else
            {
                SafetyAlert(CUV) = OFF;
                delay = 0;
            }
        }
    }
}

void Protect_CUVC()
{
    static uint32_t delay = 0;
    if (SafetyStatus(CUVC))
    {
        if (D_Protection_Configuration_CUV_RECOV_CHG)
        {
            if (PackVoltage() > D_CUVC_CUV_Charge_Presen_Threshol) // charge status
            {
                if ((V_min - I_abs * D_CUVC_CellResistance / 1000) > D_CUVC_Recovery)
                {
                    SafetyStatus(CUVC) = OFF;
                }
            }
        }
        else
        {
            if ((V_min - I_abs * D_CUVC_CellResistance / 1000) > D_CUVC_Recovery)
            {
                SafetyStatus(CUVC) = OFF;
            }
        }
    }
    else
    {
        if (D_Enabled_Protections_B_CUVC)
        {

            if (f_discharge)
            {
                if ((V_min - I_abs * D_CUVC_CellResistance / 1000) <= D_CUVC_Threshold)
                {
                    SafetyAlert(CUVC) = ON;
                    delay += Periodtime;
                    if (delay / 1000 >= (D_CUVC_Delay+1))

                    {
                        delay = 0;
                        SafetyAlert(CUVC) = OFF;
                        SafetyStatus(CUVC) = ON;
                    }
                }
                else
                {
                    SafetyAlert(CUVC) = OFF;
                    delay = 0;
                }
            }
        }
    }
}

void Protect_COV()
{
    static uint32_t delay = 0;
    static uint8_t status = 0;
    static uint16_t covl_counter = 0;
    static uint32_t dec_delay = 0;
    static uint32_t resettime = 0;

    if (D_Enabled_Protections_A_COV)
    {
        if (!SafetyAlert(COV) && !SafetyStatus(COV)) // normal
        {
            if (f_UT || f_LT)
            {
                if (V_max >= D_COV_Threshold_Low_Temp)
                {
                    status = 1;
                }
            }
            else if (f_STL)
            {
                if (V_max >= D_COV_Threshold_Standard_Temp_Low)
                {
                    status = 2;
                }
            }
            else if (f_STH)
            {
                if (V_max >= D_COV_Threshold_Standard_Temp_High)
                {
                    status = 3;
                }
            }
            else if (f_RT)
            {
                if (V_max >= D_COV_Threshold_Rec_Temp)
                {
                    status = 4;
                }
            }
            else // OT || HT
            {
                if (V_max >= D_COV_Threshold_High_Temp)
                {
                    status = 5;
                }
            }

            if (status != 0)
            {
                SafetyAlert(COV) = ON;
            }
        }
        if (SafetyAlert(COV))
        {
            if (f_UT || f_LT)
            {
                if (status != 1 || V_max < D_COV_Threshold_Low_Temp)
                {
                    status = 0;
                }
            }
            else if (f_STL)
            {
                if (status != 2 || V_max < D_COV_Threshold_Standard_Temp_Low)
                {
                    status = 0;
                }
            }
            else if (f_STH)
            {
                if (status != 3 || V_max < D_COV_Threshold_Standard_Temp_High)
                {
                    status = 0;
                }
            }
            else if (f_RT)
            {
                if (status != 4 || V_max < D_COV_Threshold_Rec_Temp)
                {
                    status = 0;
                }
            }
            else // OT || HT
            {
                if (status != 5 || V_max < D_COV_Threshold_High_Temp)
                {
                    status = 0;
                }
            }
            if (status == 0)
            {
                SafetyAlert(COV) = OFF;
                delay = 0;
            }
            else
            {
           
                delay += Periodtime;
                
                if (delay / 1000 >= (D_COV_Delay+1))

                {
                    // printf("covprotect\n");
                    delay = 0;
                    SafetyAlert(COV) = OFF;
                    SafetyStatus(COV) = ON;
                    life_Time_Protect_Event(LT_COV);
                    covl_counter++;
                }
            }
        }
    }
    else
    {
        delay = 0;
        SafetyAlert(COV) = OFF;
    }
    if (SafetyStatus(COV))
    {
        if (f_UT || f_LT) //
        {
            if (V_max <= D_COV_Recovery_Low_Temp)
            {
                SafetyStatus(COV) = OFF;
            }
        }
        else if (f_STL)
        {
            if (V_max <= D_COV_Recovery_Standard_Temp_Low)
            {
                SafetyStatus(COV) = OFF;
            }
        }
        else if (f_STH)
        {
            if (V_max <= D_COV_Recovery_Standard_Temp_High)
            {
                SafetyStatus(COV) = OFF;
            }
        }
        else if (f_RT)
        {
            if (V_max <= D_COV_Recovery_High_Temp)
            {
                SafetyStatus(COV) = OFF;
            }
        }
        else
        {
            if (V_max <= D_COV_Recovery_Rec_Temp)
            {
                SafetyStatus(COV) = OFF;
            }
        }
    }

    if (SafetyStatus(COVL))
    {
        if (D_DA_Configuration_NR)
        {
            resettime += Periodtime;
            if (resettime / 1000 >= D_COV_Reset)
            {
                resettime = 0;
                covl_counter = 0;
                SafetyStatus(COVL) = OFF;
            }
        }
        else // Low-high-low transition on PRES pin
        {
            if (f_preslhl) // Low-high-low
            {
                resettime = 0;
                covl_counter = 0;
                SafetyStatus(COVL) = OFF;
            }
        }
    }
    else
    {
        if (!SafetyAlert(COV) && !SafetyStatus(COV))
        {
            if (covl_counter > 0)
            {
                dec_delay += Periodtime;
                if (dec_delay / 1000 >= D_COV_Cel_Overvolt_Coun_Decrem_Del) // 电压计数器减量延迟
                {
                    dec_delay = 0;
                    covl_counter--;
                }
            }
            else // covl_counter = 0
            {
                SafetyAlert(COVL) = OFF;
                f_pf_covl_a = OFF;
            }
        }
        else
        {
            dec_delay = 0;
        }
        if (D_Enabled_Protections_D_COVL && D_Enabled_Protections_A_COV)
        {
            if (covl_counter > 0 && covl_counter < D_COV_Cell_Overvoltage_Latch_Limit)
            {
                if (D_Enabled_Protections_D_COVL)
                {
                    SafetyAlert(COVL) = ON;
                }
                if (D_Enabled_PF_A_COVL && f_PF_EN)
                {
                    f_pf_covl_a = ON;
                }
            }
            else if (covl_counter >= D_COV_Cell_Overvoltage_Latch_Limit)
            {
                if (D_Enabled_Protections_D_COVL)
                {
                    SafetyStatus(COVL) = ON;
                    SafetyAlert(COVL) = OFF;
                }

                if (D_Enabled_PF_A_COVL && f_PF_EN)
                {
                    f_pf_covl_a = OFF;
                    f_pf_covl_p = ON;
                }
            }
        }
    }
}

void Protect_OCC()
{
    static uint32_t delay1 = 0;
    static uint32_t delay2 = 0;
    static uint32_t recovery_delay = 0;

    if (!SafetyStatus(OCC1))
    {
        if (D_Enabled_Protections_A_OCC1)
        {
            if (Current() >= D_OCC1_Threshold)
            {
                SafetyAlert(OCC1) = ON;
                delay1 += Periodtime;
                if (delay1 / 1000 >= (D_OCC1_Delay+1))

                {
                    delay1 = 0;    // Clear OverChgCurr release count
                    SafetyStatus(OCC1) = ON; // Set OCC Alarm
                    SafetyAlert(OCC1) = OFF;
                    life_Time_Protect_Event(LT_OCC1);
                }
            }
            else
            {
                SafetyAlert(OCC1) = OFF;
                delay1 = 0;
            }
        }
    }

    if (!SafetyStatus(OCC2))
    {
        if (D_Enabled_Protections_A_OCC2)
        {
            if (Current() >= D_OCC2_Threshold)
            {
                SafetyAlert(OCC2) = ON;
                delay2 += Periodtime;
                if (delay2 / 1000 >= (D_OCC2_Delay+1))

                {
                    delay2 = 0;    // Clear OverChgCurr release count
                    SafetyStatus(OCC2) = ON; // Set OCC Alarm
                    SafetyAlert(OCC2) = OFF;
                    SafetyAlert(OCC1) = OFF;
                    life_Time_Protect_Event(LT_OCC2);
                }
            }
            else
            {
                SafetyAlert(OCC2) = OFF;
                delay2 = 0;
            }
        }
    }

    if (SafetyStatus(OCC1) || SafetyStatus(OCC2))
    {
        if (Current() <= D_OCC_Recovery_Threshold) // Curr less than ~mA ?
        {
            recovery_delay += Periodtime;
            if (recovery_delay / 1000 >= D_OCC_Recovery_Delay)
            {
                recovery_delay = 0; // Clear OverChgCurr release count
                SafetyStatus(OCC1) = OFF;     // Clear OCC1 Alarm
                SafetyStatus(OCC2) = OFF;     // Clear OCC2 Alarm
            }
        }
        else
        {
            recovery_delay = 0;
        }
    }
}

void Protect_OCD()
{
    static uint32_t delay1 = 0;
    static uint32_t delay2 = 0;
    static uint32_t recovery_delay = 0;
    static uint32_t dec_delay1 = 0;
    static uint32_t dec_delay2 = 0;
    static uint32_t resettime = 0;
    static uint16_t ocdl1_counter = 0;
    static uint16_t ocdl2_counter = 0;

    if (!SafetyStatus(OCD1))
    {
        if (D_Enabled_Protections_A_OCD1)
        {
            if (Current() <= D_OCD1_Threshold)
            {
                SafetyAlert(OCD1) = ON;
                delay1 += Periodtime;
                if (delay1 / 1000 >= (D_OCD1_Delay+1))
                {
                    delay1 = 0;    // Clear OverChgCurr release count
                    SafetyStatus(OCD1) = ON; // Set OCC Alarm
                    ocdl1_counter++;
                    SafetyAlert(OCD1) = OFF;
                    life_Time_Protect_Event(LT_OCD1);
                }
            }
            else
            {
                SafetyAlert(OCD1) = OFF;
                delay1 = 0;
            }
        }
    }

    if (!SafetyStatus(OCD2))
    {
        if (D_Enabled_Protections_A_OCD2)
        {
            if (Current() <= D_OCD2_Threshold)
            {
                SafetyAlert(OCD2) = ON;
                delay2 += Periodtime;
                if (delay2 / 1000 >= (D_OCD2_Delay+1))
                {
                    delay2 = 0;    // Clear OverChgCurr release count
                    SafetyStatus(OCD2) = ON; // Set OCC Alarm
                    ocdl2_counter++;
                    SafetyAlert(OCD2) = OFF;
                    SafetyAlert(OCD1) = OFF;
                    life_Time_Protect_Event(LT_OCD2);
                }
            }
            else
            {
                SafetyAlert(OCD2) = OFF;
                delay2 = 0;
            }
        }
    }

    if (SafetyStatus(OCD1) || SafetyStatus(OCD2))
    {
        if (Current() >= D_OCD_Recovery_Threshold) // Curr less than ~mA ?
        {
            recovery_delay += Periodtime;
            if (recovery_delay / 1000 >= D_OCD_Recovery_Delay)
            {
                recovery_delay = 0; // Clear OverDisCurr release count
                SafetyStatus(OCD1) = OFF;     // Clear ODC Alarm
                SafetyStatus(OCD2) = OFF;     // Clear ODC Alarm
            }
        }
        else
        {
            recovery_delay = 0;
        }
    }

    if (SafetyStatus(OCDL))
    {
        if (D_DA_Configuration_NR)
        {
            resettime += Periodtime;
            if (resettime / 1000 >= D_OCD_Reset)
            {
                resettime = 0;
                ocdl1_counter = 0;
                ocdl2_counter = 0;
                SafetyStatus(OCDL) = OFF;
            }
        }
        else // Low-high-low transition on PRES pin
        {
            if (f_preslhl)
            {
                resettime = 0;
                ocdl1_counter = 0;
                ocdl2_counter = 0;
                SafetyStatus(OCDL) = OFF;
            }
        }
    }
    else
    {
        if (!SafetyAlert(OCD1) && !SafetyStatus(OCD1))
        {
            if (ocdl1_counter > 0)
            {
                dec_delay1 += Periodtime;
                if (dec_delay1 / 1000 >= D_OCD_Counter_Dec_Delay)
                {
                    dec_delay1 = 0;
                    ocdl1_counter--;
                }
            }
            else
            {
                SafetyAlert(OCDL) = OFF;
                f_pf_ocdl_a = OFF;
            }
        }
        else
        {
            dec_delay1 = 0;
        }

        if (!SafetyAlert(OCD2) && !SafetyStatus(OCD2))
        {
            if (ocdl2_counter > 0)
            {
                dec_delay2 += Periodtime;
                if (dec_delay2 / 1000 >= D_OCD_Counter_Dec_Delay)
                {
                    dec_delay2 = 0;
                    ocdl2_counter--;
                }
            }
        }
        else
        {
            dec_delay2 = 0;
        }
        if (D_Enabled_Protections_D_OCDL && (D_Enabled_Protections_A_OCD1 || D_Enabled_Protections_A_OCD2))
        {
            if ((ocdl1_counter > 0 && ocdl1_counter < D_OCD_Latch_Limit) || (ocdl2_counter > 0 && ocdl2_counter < D_OCD_Latch_Limit))
            {
                if (D_Enabled_Protections_D_OCDL)
                {
                    SafetyAlert(OCDL) = ON;
                }
                if (D_Enabled_PF_C_OCDL && f_PF_EN)
                {
                    f_pf_ocdl_a = ON;
                }
            }
            else if (ocdl1_counter >= D_OCD_Latch_Limit || ocdl2_counter >= D_OCD_Latch_Limit)
            {
                if (D_Enabled_Protections_D_OCDL)
                {
                    SafetyStatus(OCDL) = ON;
                    SafetyAlert(OCDL) = OFF;
                }
                if (D_Enabled_PF_C_OCDL && f_PF_EN)
                {
                    f_pf_ocdl_a = OFF;
                    f_pf_ocdl_p = ON;
                }
            }
        }
    }
}

void Protect_HardWare_Base()
{
    static uint16_t aoldRecovrytime = 0;
    static uint16_t aold_reset_time = 0;
    static uint16_t aoldl_dec_dalay = 0;

    static uint16_t ascdl_dec_dalay = 0;
    static uint16_t ascd_rec_delay = 0;
    static uint16_t ascdl_reset_time = 0;

    static uint16_t asccl_reset_time = 0;
    static uint16_t ascc_recovry_time = 0;
    static uint16_t asccl_dec_delay = 0;

    Hdp_Init();

    if (SafetyStatus(AOLD))
    {
        aoldRecovrytime += Periodtime;
        if (aoldRecovrytime / 1000 >= D_AOLD_Recovery)
        {
            aoldRecovrytime = 0;
            SafetyStatus(AOLD) = OFF;
        }
    }
    if (SafetyStatus(AOLDL))
    {
        if (D_DA_Configuration_NR)
        {
            aold_reset_time += Periodtime;
            if (aold_reset_time / 1000 >= D_AOLD_Reset)
            {
                aold_reset_time = 0;
                aoldl_counter = 0;
                SafetyStatus(AOLDL) = OFF;
            }
        }
        else // Low-high-low transition on PRES pin
        {
            if (f_preslhl)
            {
                aold_reset_time = 0;
                aoldl_counter = 0;
                SafetyStatus(AOLDL) = OFF;
            }
        }
    }
    else
    {
        if (!SafetyStatus(AOLD))
        {
            if (aoldl_counter > 0)
            {
                aoldl_dec_dalay += Periodtime;
                if (aoldl_dec_dalay / 1000 >= D_AOLD_Counter_Dec_Delay)
                {
                    aoldl_dec_dalay = 0;
                    aoldl_counter--;
                }
            }
            else if (!aoldl_counter)
            {
                SafetyAlert(AOLDL) = OFF;
                f_pf_aoldl_a = OFF;
            }
        }
        else
        {
            aoldl_dec_dalay = 0;
        }
        if (D_Enabled_Protections_A_AOLDL && D_Enabled_Protections_A_AOLD)
        {
            if (aoldl_counter > 0 && aoldl_counter < D_AOLD_Latch_Limit)
            {
                SafetyAlert(AOLDL) = ON;
                if (D_Enabled_PF_B_AOLDL && f_PF_EN)
                {
                    f_pf_aoldl_a = ON;
                }
            }
            else if (aoldl_counter >= D_AOLD_Latch_Limit)
            {
                SafetyStatus(AOLDL) = ON;
                SafetyAlert(AOLDL) = OFF;
                if (D_Enabled_PF_B_AOLDL && f_PF_EN)
                {
                    f_pf_aoldl_a = OFF;
                    f_pf_aoldl_p = ON;
                }
            }
        }
    }

    if (SafetyStatus(ASCD))
    {
        ascd_rec_delay += Periodtime;
        if (ascd_rec_delay / 1000 >= D_ASCD_Recovery)
        {
            ascd_rec_delay = 0;
            SafetyStatus(ASCD) = OFF;
        }
    }
    if (SafetyStatus(ASCDL))
    {
        if (D_DA_Configuration_NR)
        {
            ascdl_reset_time += Periodtime;
            if (ascdl_reset_time / 1000 >= D_ASCD_Reset)
            {
                ascdl_reset_time = 0;
                ascdl_counter = 0;
                SafetyStatus(ASCDL) = OFF;
            }
        }
        else // Low-high-low transition on PRES pin
        {
            if (f_preslhl)
            {
                ascdl_reset_time = 0;
                ascdl_counter = 0;
                SafetyStatus(ASCDL) = OFF;
            }
        }
    }
    else
    {

        if (!SafetyStatus(ASCD))
        {
            if (ascdl_counter > 0)
            {
                ascdl_dec_dalay += Periodtime;
                if (ascdl_dec_dalay / 1000 >= D_ASCD_Counter_Dec_Delay)
                {
                    ascdl_dec_dalay = 0;
                    ascdl_counter--;
                }
            }
            else if (!ascdl_counter)
            {
                SafetyAlert(ASCDL) = OFF;
                f_pf_ascdl_a = OFF;
            }
        }
        else
        {
            ascdl_dec_dalay = 0;
        }

        if (D_Enabled_Protections_B_ASCDL && D_Enabled_Protections_B_ASCD)
        {
            if (ascdl_counter > 0 && ascdl_counter < D_ASCD_Latch_Limit)
            {
                SafetyAlert(ASCDL) = ON;
                if (D_Enabled_PF_B_ASCDL && f_PF_EN)
                {
                    f_pf_ascdl_a = ON;
                }
            }
            else if (ascdl_counter >= D_ASCD_Latch_Limit)
            {
                SafetyStatus(ASCDL) = ON;
                SafetyAlert(ASCDL) = OFF;
                if (D_Enabled_PF_B_ASCDL && f_PF_EN)
                {
                    f_pf_ascdl_a = OFF;
                    f_pf_ascdl_p = ON;
                }
            }
        }
    }

    if (SafetyStatus(ASCC))
    {
        ascc_recovry_time += Periodtime;
        if (ascc_recovry_time / 1000 >= D_ASCC_Recovery)
        {
            ascc_recovry_time = 0;
            SafetyStatus(ASCC) = OFF;
        }
    }
    if (SafetyStatus(ASCCL))
    {
        if (D_DA_Configuration_NR)
        {
            asccl_reset_time += Periodtime;
            if (asccl_reset_time / 1000 >= D_ASCC_Reset)
            {
                asccl_reset_time = 0;
                asccl_counter = 0;
                SafetyStatus(ASCCL) = OFF;
            }
        }
        else // Low-high-low transition on PRES pin
        {
            if (f_preslhl)
            {
                asccl_reset_time = 0;
                asccl_counter = 0;
                SafetyStatus(ASCCL) = OFF;
            }
        }
    }
    else
    {
        if (!SafetyStatus(ASCC))
        {
            if (asccl_counter > 0)
            {
                asccl_dec_delay += Periodtime;
                if (asccl_dec_delay / 1000 >= D_ASCC_Counter_Dec_Delay)
                {
                    asccl_dec_delay = 0;
                    asccl_counter--;
                }
            }
            else if (!asccl_counter)
            {
                SafetyAlert(ASCCL) = OFF;
                f_pf_asccl_a = OFF;
            }
        }
        else
        {
            asccl_dec_delay = 0;
        }
        if (D_Enabled_Protections_B_ASCCL && D_Enabled_Protections_B_ASCCL)
        {
            if (asccl_counter > 0 && asccl_counter < D_ASCC_Latch_Limit)
            {
                SafetyAlert(ASCCL) = ON;
                if (D_Enabled_PF_B_ASCCL && f_PF_EN)
                {
                    f_pf_asccl_a = ON;
                }
            }
            else if (asccl_counter >= D_ASCC_Latch_Limit)
            {
                SafetyStatus(ASCCL) = ON;
                SafetyAlert(ASCCL) = OFF;
                if (D_Enabled_PF_B_ASCCL && f_PF_EN)
                {
                    f_pf_asccl_a = OFF;
                    f_pf_asccl_p = ON;
                }
            }
        }
    }
}

void Protect_OTC()
{
    static uint16_t delay = 0;
    if (SafetyStatus(OTC))
    {
        if (Ts_max <= D_OTC_Recovery) // TRM is not delay
        {
            SafetyStatus(OTC) = OFF; //
        }
    }
    else
    {

        if (D_Enabled_Protections_B_OTC && Ts_max >= D_OTC_Threshold && !BatteryStatus(DSG))
        {
      
            SafetyAlert(OTC) = ON;
            delay += Periodtime;

            if (delay / 1000 >= (D_OTC_Delay+1))
            {
                
                SafetyAlert(OTC) = OFF;
                delay = 0;
                SafetyStatus(OTC) = ON;
                life_Time_Protect_Event(LT_OTC);
            }
        }
        else
        {
            SafetyAlert(OTC) = OFF;
            delay = 0;
        }
    }
}

void Protect_OTD()
{
    static uint16_t delay = 0;
    if (SafetyStatus(OTD))
    {
        if (Ts_max <= D_OTD_Recovery) // TRM is not delay
        {
            SafetyStatus(OTD) = OFF; //
        }
    }
    else
    {
        if (D_Enabled_Protections_B_OTD && Ts_max >= D_OTD_Threshold && BatteryStatus(DSG))
        {
            SafetyAlert(OTD) = ON;
            delay += Periodtime;
            if (delay / 1000 >= (D_OTD_Delay+1))

            {
                SafetyAlert(OTD) = OFF;
                delay = 0;
                SafetyStatus(OTD) = ON;
                life_Time_Protect_Event(LT_OTD);
            }
        }
        else
        {
            SafetyAlert(OTD) = OFF;
            delay = 0;
        }
    }
}

void Protect_OTF()
{
    static uint16_t delay = 0;

    if (SafetyStatus(OTF))
    {
        if (FETTemp <= D_OTF_Recovery) // TRM is not delay
        {
            SafetyStatus(OTF) = OFF; //
        }
    }
    else
    {
        if (D_Enabled_Protections_C_OTF && FETTemp >= D_OTF_Threshold)
        {
            SafetyAlert(OTF) = ON;
            delay += Periodtime;
            if (delay / 1000 >= D_OTF_Delay)
            {
                SafetyAlert(OTF) = OFF;
                delay = 0;
                SafetyStatus(OTF) = ON;
                life_Time_Protect_Event(LT_OTF);
            }
        }
        else
        {
            SafetyAlert(OTF) = OFF;
            delay = 0;
        }
    }
}

void Protect_UTC()
{
    static uint16_t delay = 0;
    if (SafetyStatus(UTC))
    {
        if (Ts_min >= D_UTC_Recovery) // TRM is not delay
        {
            SafetyStatus(UTC) = OFF; //
        }
    }
    else
    {
        if (D_Enabled_Protections_D_UTC && Ts_min <= D_UTC_Threshold && !BatteryStatus(DSG))
        {
            
            SafetyAlert(UTC) = ON;
            delay += Periodtime;
            if (delay / 1000 >= (D_UTC_Delay+1))

            {
                
                SafetyAlert(UTC) = OFF;
                delay = 0;
                SafetyStatus(UTC) = ON;
            }
        }
        else
        {
            SafetyAlert(UTC) = OFF;
            delay = 0;
        }
    }
}

void Protect_UTD()
{
    static uint16_t delay = 0;
    if (SafetyStatus(UTD))
    {
        if (Ts_min >= D_UTD_Recovery) // TRM is not delay
        {
            SafetyStatus(UTD) = OFF; //
        }
    }
    else
    {
        if (D_Enabled_Protections_D_UTD && Ts_min <= D_UTD_Threshold && BatteryStatus(DSG))
        {
            SafetyAlert(UTD) = ON;
            delay += Periodtime;
            if (delay / 1000 >= (D_UTD_Delay+1))
            {
                SafetyAlert(UTD) = OFF;
                delay = 0;
                SafetyStatus(UTD) = ON;
            }
        }
        else
        {
            SafetyAlert(UTD) = OFF;
            delay = 0;
        }
    }
}

void Protect_HWD()
{
    static uint16_t delay = 0;

    if (hwd_recovery)
    {
        hwd_recovery = 0;
        SafetyStatus(HWD) = OFF;
        delay = 0;
    }
    else
    {
        if (D_Enabled_Protections_C_HWDF && !SafetyStatus(HWD))
        {
            delay += Periodtime;
            if (delay / 1000 >= (D_HWD_Delay+1))
            {
                delay = 0;
                SafetyStatus(HWD) = ON;
            }
        }
        else
        {
            delay = 0;
        }
    }
}

void Protect_PTO()
{
    static uint32_t timer = 0;
    static uint32_t resetCap = 0;

    if (D_Enabled_Protections_C_PTO)
    {
        if (!SafetyAlert(PTO) && !SafetyStatus(PTO)) // normal
        {
            if (Current() > D_PTO_Charge_Threshold)
            {
                if (f_PV)
                {
                    SafetyAlert(PTOS) = OFF;
                    SafetyAlert(PTO) = ON;
                }
            }
        }
        if (SafetyAlert(PTO)) // enable
        {
            if (!f_discharge)
            {
                if (Current() < D_PTO_Suspend_Threshold)
                {
                    SafetyAlert(PTOS) = ON;
                    SafetyAlert(PTO) = OFF;
                }

                if (Current() > D_PTO_Charge_Threshold)
                {
                    timer += Periodtime;
                    if (timer / 1000 >= (D_PTO_Delay+1))
                    {
                        timer = 0;
                        SafetyStatus(PTO) = ON;
                        SafetyAlert(PTO) = OFF;
                        resetCap = 0; // clear  PTO Recover Cap
                    }
                }
            }
            else
            {
                timer = 0;
                resetCap = 0;
                SafetyAlert(PTO) = OFF;
                SafetyAlert(PTOS) = OFF;
            }
        }
    }
    else
    {
        timer = 0;
        SafetyAlert(PTOS) = OFF;
        SafetyAlert(PTO) = OFF;
    }

    if (SafetyStatus(PTO))    // trip
    {
        if (D_DA_Configuration_NR)
        {
            if (f_discharge)
            {
                resetCap += I_abs * Periodtime;
                if ((resetCap / 1000 / (60 * 60)) >= D_PTO_Reset)
                {
                    timer = 0;
                    resetCap = 0;
                    SafetyStatus(PTO) = OFF;
                    SafetyAlert(PTOS) = OFF;
                }
            }
        }
        else
        {
            if (f_discharge) //  ||PRES low-high-low
            {
                resetCap += I_abs * Periodtime;
                if ((resetCap / 1000 / (60 * 60)) >= D_PTO_Reset)
                {
                    timer = 0;
                    resetCap = 0;
                    SafetyStatus(PTO) = OFF;
                    SafetyAlert(PTOS) = OFF;
                }
            }
            if (f_preslhl)
            {
                timer = 0;
                resetCap = 0;
                SafetyStatus(PTO) = OFF;
                SafetyAlert(PTOS) = OFF;
            }
        }
    }

    timer = BatteryStatus(FC) ? 0 : timer;
}

void Protect_CTO()
{
    static uint32_t timer = 0;
    static uint32_t resetCap = 0;

    if (D_Enabled_Protections_C_CTO)
    {
        if (!SafetyAlert(CTO) && !SafetyStatus(CTO)) // normal
        {
            if (Current() > D_CTO_Charge_Threshold)
            {
                if (!f_PV)
                {
                    SafetyAlert(CTOS) = OFF;
                    SafetyAlert(CTO) = ON;
                }
            }

            if(BatteryStatus(FC)||f_discharge)
            {
                SafetyAlert(CTO) = OFF;
                SafetyAlert(CTOS) = OFF;
            }

        }
        if (SafetyAlert(CTO)) // enable
        {
            if (!f_discharge)
            {
                if (Current() < D_CTO_Suspend_Threshold)
                {
                    SafetyAlert(CTOS) = ON;
                    SafetyAlert(CTO) = OFF;
                }

                if (Current() > D_CTO_Charge_Threshold)
                {
                    timer += Periodtime;
                    if (timer / 1000 >= (D_CTO_Delay+1))
                    {
                        timer = 0;
                        SafetyStatus(CTO) = ON;
                        SafetyAlert(CTO) = OFF;
                        resetCap = 0; // clear  PTO Recover Cap
                    }
                }
            }
            else
            {
                timer = 0;
                resetCap = 0;
                SafetyAlert(CTO) = OFF;
                SafetyAlert(CTOS) = OFF;
            }
        }
    }
    else
    {
        timer = 0;
        SafetyAlert(CTOS) = OFF;
        SafetyAlert(CTO) = OFF;
    }

    if(SafetyStatus(CTO)) // trip
    {
        if (D_DA_Configuration_NR)
        {
            if (f_discharge)
            {
                resetCap += I_abs * Periodtime;
                if ((resetCap / 1000 / (60 * 60)) >= D_CTO_Reset)
                {
                    timer = 0;
                    resetCap = 0;
                    SafetyStatus(CTO) = OFF;
                    SafetyAlert(CTOS) = OFF;
                }
            }
        }
        else
        {
            if (f_discharge) 
            {
                resetCap += I_abs * Periodtime;
                if ((resetCap / 1000 / (60 * 60)) >= D_CTO_Reset)
                {
                    timer = 0;
                    resetCap = 0;
                    SafetyStatus(CTO) = OFF;
                    SafetyAlert(CTOS) = OFF;
                }
            }
            if (f_preslhl)
            {
                timer = 0;
                resetCap = 0;
                SafetyStatus(CTO) = OFF;
                SafetyAlert(CTOS) = OFF;
            }
        }
    }
    
    // if (SafetyStatus(CTO))
    // {
    //     if (D_DA_Configuration_NR)
    //     {
    //         if (f_discharge)
    //         {
    //             resetCap += I_abs * Periodtime;
    //             if ((resetCap / 1000 / (60 * 60)) >= D_CTO_Reset)
    //             {
    //                 timer = 0;
    //                 resetCap = 0;
    //                 SafetyStatus(CTO) = OFF;
    //                 SafetyAlert(CTOS) = OFF;
    //             }
    //         }
    //     }
    //     else
    //     {
    //         if (f_discharge) //  ||PRES low-high-low
    //         {
    //             resetCap += I_abs * Periodtime;
    //             if ((resetCap / 1000 / (60 * 60)) >= D_CTO_Reset)
    //             {
    //                 timer = 0;
    //                 resetCap = 0;
    //                 SafetyStatus(CTO) = OFF;
    //                 SafetyAlert(CTOS) = OFF;
    //             }
    //         }
    //         if (f_preslhl)
    //         {
    //             timer = 0;
    //             resetCap = 0;
    //             SafetyStatus(CTO) = OFF;
    //             SafetyAlert(CTOS) = OFF;
    //         }
    //     }
    // }
    // else
    // {
    //     if (D_Enabled_Protections_C_CTO)
    //     {
    //         if (Current() > D_CTO_Charge_Threshold)
    //         {
    //             if (!f_PV)
    //             {
    //                 SafetyAlert(CTOS) = OFF;
    //                 SafetyAlert(CTO) = ON;
    //                 timer += Periodtime;
    //                 if (timer / 1000 >= D_CTO_Delay)
    //                 {
    //                     timer = 0;
    //                     SafetyStatus(CTO) = ON;
    //                     resetCap = 0; // clear  PTO Recover Cap
    //                 }
    //             }
    //         }
    //         if (SafetyAlert(CTO) && Current() < D_CTO_Suspend_Threshold)
    //         {
    //             SafetyAlert(CTOS) = ON;
    //             SafetyAlert(CTO) = OFF;
    //         }
    //     }
    //     else
    //     {
    //         SafetyAlert(CTO) = OFF;
    //         SafetyAlert(CTOS) = OFF;
    //         timer = 0;
    //     }
    // }
    timer = BatteryStatus(FC) ? 0 : timer;
}

void Protect_OC()
{
    static uint32_t chg_cap = 0;
    static uint32_t dsg_cap = 0;

    if (!SafetyAlert(OC) && !SafetyStatus(OC))
    {
        if (D_Enabled_Protections_C_OC)
        {
            if (t_com0d >= 100)
            {
                if (f_charge) // charge status
                {
                    SafetyAlert(OC) = ON;
                   // printf("OC Alert!\n");
                }
            }
        }
    }
    if (SafetyAlert(OC))
    {
        if (t_com0d < 100 || !f_charge || f_xchg)
        {
            SafetyAlert(OC) = OFF;
            chg_cap = 0;
        }
        else
        {
            chg_cap += I_abs * Periodtime;
            if (chg_cap / 1000 / (60 * 60) >= (D_OC_Threshold+1))

            {
                chg_cap = 0;
                SafetyStatus(OC) = ON;
                SafetyAlert(OC) = OFF;
               // printf("OC Trip!\n");
            }
        }
    }
    if (SafetyStatus(OC))
    {
        if (D_DA_Configuration_NR)
        {
            if (f_discharge)
            {
                dsg_cap += Periodtime * I_abs;
                if (dsg_cap / 1000 / (60 * 60) >= D_OC_Recovery)
                {
                    SafetyStatus(OC) = OFF;
                    dsg_cap = 0;
                }
            }
            else
            {
                dsg_cap = 0;
            }
            if (t_com0d < D_OC_RSOC_Recovery)
            {
                SafetyStatus(OC) = OFF;
            }
        }
        else // ||PRES low-high-low
        {
            if (f_preslhl)
            {
                SafetyStatus(OC) = OFF;
                dsg_cap = 0;
            }
        }
    }
    // else
    // {
    //     if (D_Enabled_Protections_C_OC)
    //     {
    //         if (t_com0d >= 100)
    //         {
    //             if (f_charge) // charge status
    //             {
    //                 SafetyAlert(OC) = ON;
    //                 chg_cap += I_abs * Periodtime;

    //                 if (chg_cap / 1000 / (60 * 60) >= D_OC_Threshold)
    //                 {
    //                     chg_cap = 0;
    //                     SafetyStatus(OC) = ON;
    //                     SafetyAlert(OC) = OFF;
    //                 }
    //             }
    //         }
    //         else
    //         {
    //             chg_cap = 0;
    //             SafetyAlert(OC) = OFF;
    //         }
    //     }
    // }
}

void Protect_CHGV()
{
    static uint16_t delay = 0;
    static uint16_t Charge_Voltage = 0;
    if (SafetyStatus(CHGV))
    {
        if (PackVoltage() <= (_ChargingVoltage + D_CHGV_Recovery * NUMBER_SERIES)) // TRM not delay
        {
            SafetyStatus(CHGV) = OFF;
            _ChargingVoltage = Charge_Voltage;
        }
    }
    else
    {
        if (D_Enabled_Protections_D_CHGV && f_charge)
        {

            if (PackVoltage() >= _ChargingVoltage + D_CHGV_Threshold * NUMBER_SERIES)
            {
                SafetyAlert(CHGV) = ON;
                delay += Periodtime;
                if (delay / 1000 >= (D_CHGV_Delay+1))

                {
                    SafetyAlert(CHGV) = OFF;
                    SafetyStatus(CHGV) = ON;
                    delay = 0;

                    Charge_Voltage = _ChargingVoltage;
                    _ChargingVoltage = 0;
                }
            }
            else
            {
                SafetyAlert(CHGV) = OFF;
                delay = 0;
            }
        }
    }
}

void Protect_CHGC()
{
    static uint16_t delay = 0;
    static uint16_t recovery_delay = 0;

    if (SafetyStatus(CHGC))
    {
        if (Current() <= D_CHGC_Recovery_Threshold)
        {
            recovery_delay += Periodtime;
            if (recovery_delay / 1000 >= D_CHGC_Recovery_Delay)
            {
                recovery_delay = 0;
                SafetyStatus(CHGC) = OFF;
            }
        }
        else
        {
            recovery_delay = 0;
        }
    }
    else
    {
        if (D_Enabled_Protections_C_CHGC)
        {
            if (Current() >= (_ChargingCurrent + D_CHGC_Threshold))
            {
                SafetyAlert(CHGC) = ON;
                delay += Periodtime;
                if (delay / 1000 >= (D_CHGC_Delay+1))

                {
                    SafetyAlert(CHGC) = OFF;
                    SafetyStatus(CHGC) = ON;
                    delay = 0;
                }
            }
            else
            {
                SafetyAlert(CHGC) = OFF;
                delay = 0;
            }
        }
        else
        {
            SafetyAlert(CHGC) = OFF;
            delay = 0;
        }
    }
}

void Protect_PCHGC()
{
    static uint16_t delay = 0;
    static uint16_t recovery_dalay = 0;

    if (SafetyStatus(PCHGC))
    {
        if (Current() <= D_PCHGC_Recovery_Threshold) // discharge recover
        {
            recovery_dalay += Periodtime;
            if (recovery_dalay / 1000 >= D_PCHGC_Recovery_Delay)
            {
                recovery_dalay = 0;
                SafetyStatus(PCHGC) = OFF;
            }
        }
        else
        {
            recovery_dalay = 0;
        }
    }
    else
    {
        if (D_Enabled_Protections_D_PCHGC && f_PV)
        {

            if (Current() >= (_ChargingCurrent + D_PCHGC_Threshold))
            {
                SafetyAlert(PCHGC) = ON;
                delay += Periodtime;
                if (delay / 1000 >= (D_PCHGC_Delay+1))
                {
                    SafetyAlert(PCHGC) = OFF;
                    SafetyStatus(PCHGC) = ON;
                    delay = 0;
                    f_pto_start = OFF; //
                }
            }
            else
            {
                SafetyAlert(PCHGC) = OFF;
                delay = 0;
            }
        }
        else
        {
            SafetyAlert(PCHGC) = OFF;
            delay = 0;
        }
    }
}




void PF_SUV()
{
    static uint32_t suv_mode_delay = 0;
    static uint32_t delay = 0;
    uint8_t suv_mode_flag = 1;
    
    if(D_Protection_Configuration_SUV_MODE)
    {
        if (suv_mode_delay / 1000 <= D_SUV_Delay && shutdown_wake_flag)
        {
            suv_mode_delay += Periodtime;
            suv_mode_flag = 1;
        }
        else
        {
            suv_mode_flag = 0;
        }
    }

    if (!f_pf_suv_a && !f_pf_suv_p)// normal
    {
        if (D_Enabled_PF_A_SUV)
        {
            if (V_min <= D_SUV_Threshold  && suv_mode_flag)
            {
                f_pf_suv_a = ON;
            }
        }
    }

    if (f_pf_suv_a) // alert
    {
        if (V_min > D_SUV_Threshold || !D_Enabled_PF_A_SUV)
        {
            f_pf_suv_a = OFF;
            delay = 0;
        }
        else
        {
            delay += Periodtime;
            if (delay / 1000 >= (D_SUV_Delay+1))

            {
                delay = 0;
                f_pf_suv_p = ON;
                f_pf_suv_a = OFF;
                if (f_FUSE_EN && D_Permanent_Fail_Fuse_A_SUV)
                {
                    f_fuse_out = ON;
                }
            }
        }
    }
}

void PF_SOV()
{
    static uint32_t delay = 0;
    if (D_Enabled_PF_A_SOV)
    {
        if (!f_pf_sov_p)
        {
            if (V_max >= D_SOV_Threshold)
            {
                f_pf_sov_a = ON;
                delay += Periodtime;
                if (delay / 1000 >= (D_SOV_Delay+1))

                {
                    delay = 0;
                    f_pf_sov_p = ON;
                    f_pf_sov_a = OFF;
                    if (f_FUSE_EN && D_Permanent_Fail_Fuse_A_SOV)
                    {
                        f_fuse_out = ON;
                    }
                }
            }
            else
            {
                delay = 0;
                f_pf_sov_a = OFF;
            }
        }
    }
}

void PF_SOCC()
{
    static uint32_t delay = 0;
    if (D_Enabled_PF_A_SOCC)
    {
        if (!f_pf_socc_p)
        {
            if (f_charge) // charge status
            {
                if (I_abs >= D_SOCC_Threshold)
                {

                    f_pf_socc_a = ON;
                    delay += Periodtime;
                    if (delay / 1000 >= (D_SOCC_Delay+1))

                    {
                        delay = 0;
                        f_pf_socc_p = ON;
                        f_pf_socc_a = OFF; // TRM is on
                        if (f_FUSE_EN && D_Permanent_Fail_Fuse_A_SOCC)
                        {
                            f_fuse_out = ON;
                        }
                    }
                }
                else
                {
                    delay = 0;
                    f_pf_socc_a = OFF;
                }
            }
            else
            {
                delay = 0;
                f_pf_socc_a = OFF;
            }
        }
    }
}

void PF_SOCD()
{
    static uint32_t delay = 0;
    if (D_Enabled_PF_A_SOCD)
    {
        if (!f_pf_socd_p)
        {
            if (f_discharge)
            {
                if (Current() <= D_SOCD_Threshold)
                {
                    f_pf_socd_a = ON;
                    delay += Periodtime;
                    if (delay / 1000 >= (D_SOCD_Delay+1))

                    {
                        delay = 0;
                        f_pf_socd_a = OFF; // TRM is on
                        f_pf_socd_p = ON;
                        if (f_FUSE_EN && D_Permanent_Fail_Fuse_A_SOCD)
                        {
                            f_fuse_out = ON;
                        }
                    }
                }
                else
                {
                    f_pf_socd_a = OFF;
                    delay = 0;
                }
            }
            else
            {
                f_pf_socd_a = OFF;
                delay = 0;
            }
        }
    }
}

void PF_SOT()
{
    static uint32_t delay = 0;
    if (D_Enabled_PF_A_SOT)
    {
        if (!f_pf_sot_p)
        {
            if (Ts_max >= D_SOT_Threshold) // be defferent from bq40z697
            {
                f_pf_sot_a = ON;
                delay += Periodtime;

                if (delay / 1000 >= (D_SOT_Delay+1))

                {
                    delay = 0;
                    f_pf_sot_a = OFF;
                    f_pf_sot_p = ON;
                    if (f_FUSE_EN && D_Permanent_Fail_Fuse_A_SOT)
                    {
                        f_fuse_out = ON;
                    }
                }
            }
            else
            {
                delay = 0;
                f_pf_sot_a = OFF;
            }
        }
    }
}

void PF_SOTF()
{
    static uint32_t delay = 0;
    if (D_Enabled_PF_A_SOTF)
    {
        if (!f_pf_sotf_p)
        {
            if (FETTemp >= D_SOTF_Threshold)
            {

                f_pf_sotf_a = ON;
                delay += Periodtime;
                if (delay / 1000 >= (D_SOTF_Delay+1))

                {
                    delay = 0;
                    f_pf_sotf_a = OFF;
                    f_pf_sotf_p = ON;
                    if (f_FUSE_EN && D_Permanent_Fail_Fuse_A_SOTF)
                    {
                        f_fuse_out = ON;
                    }
                }
            }
            else
            {
                f_pf_sotf_a = OFF;
                delay = 0;
            }
        }
    }
}

void PF_VIMR()
{
    static uint32_t duration = 0;
    static uint32_t delay = 0;

    // if (!f_pf_vimr_a && !f_pf_vimr_p)
    // {
    //     if (D_Enabled_PF_B_VIMR && V_max >= D_VIMR_Check_Voltage && I_abs < D_VIMR_Check_Current)
    //     {
    //         duration += Periodtime;
    //         if (duration / 1000 >= D_VIMR_Duration)
    //         {
    //             if ((V_max - V_min) >= D_VIMR_Delta_Threshold)
    //             {
    //                 duration = 0;
    //                 f_pf_vimr_a = ON;
    //             }
    //         }
    //     }
    //     else
    //     {
    //         duration = 0;
    //     }
    // }
    // if(f_pf_vimr_a)
    // {
    //     if(!D_Enabled_PF_B_VIMR || V_max < D_VIMR_Check_Voltage || I_abs >= D_VIMR_Check_Current)
    //     {
    //         f_pf_vimr_a = OFF;
    //         delay = 0;
    //     }
    //     else
    //     {
    //         delay += Periodtime;
    //         if (delay / 1000 >= D_VIMR_Delay)
    //         {
    //             delay = 0;
    //             f_pf_vimr_a = OFF;
    //             f_pf_vimr_p = ON;
                
    //         }
    //     }
    // }
    // if (f_pf_vimr_p)
    // {
    //     if (f_FUSE_EN && D_Permanent_Fail_Fuse_B_VIMR)
    //     {
    //          f_fuse_out = ON;
    //     }
    // }

    if (D_Enabled_PF_B_VIMR)
    {
        if (!f_pf_vimr_p)
        {
            if (V_max >= D_VIMR_Check_Voltage && I_abs < D_VIMR_Check_Current)
            {

                duration += Periodtime;
                if (duration / 1000 >= D_VIMR_Duration)
                {
                    if ((V_max - V_min) >= D_VIMR_Delta_Threshold)
                    {
                        f_pf_vimr_a = ON;
                        delay += Periodtime;
                        if (delay / 1000 >= (D_VIMR_Delay+1))

                        {
                            delay = 0;
                            duration = 0;
                            f_pf_vimr_a = OFF;
                            f_pf_vimr_p = ON;
                            if (f_FUSE_EN && D_Permanent_Fail_Fuse_B_VIMR)
                            {
                                f_fuse_out = ON;
                            }
                        }
                    }
                    else
                    {
                        f_pf_vimr_a = OFF;
                        delay = 0;
                    }
                }
            }
            else
            {
                f_pf_vimr_a = OFF;
                duration = 0;
                delay = 0;
            }
        }
    }
}

void PF_VIMA()
{
    static uint32_t delay = 0;

    if (D_Enabled_PF_B_VIMA)
    {
        if (!f_pf_vima_p)
        {
            if (Current() > D_VIMA_Check_Current && V_max >= D_VIMA_Check_Voltage && (V_max - V_min) >= D_VIMA_Delta_Threshold)
            {

                delay += Periodtime;
                f_pf_vima_a = ON;
                if (delay / 1000 >= (D_VIMA_Delay+1))

                {
                    delay = 0;
                    f_pf_vima_a = OFF;
                    f_pf_vima_p = ON;
                    if (f_FUSE_EN && D_Permanent_Fail_Fuse_B_VIMA)
                    {
                        f_fuse_out = ON;
                    }
                }
            }
            else
            {
                f_pf_vima_a = OFF;
                delay = 0;
            }
        }
    }
}



uint16_t oldVoltage[250];
uint8_t    CFETdex=0;
int16_t oldVoltageSum=0;
float oldTemp;
uint8_t f_temp_high=0;

void PF_CFET()
{
    static uint32_t delay = 0;
    static uint32_t tempDelay=0;
    if (D_Enabled_PF_C_CFETF)
    {
        if (!f_pf_cfetf_p)
        {
            if (!f_chg) // cfet off
            {
                if (Current() >= D_CFET_Threshold)
                {

                    f_pf_cfetf_a = ON;
                    delay += Periodtime;

                    if (delay % 40 == 0)
                    {
                        oldVoltage[CFETdex++] = Voltage();
                        if (CFETdex == 1)
                        {
                            oldTemp = FETTemp;
                           // printf("oldTemp = %f", oldTemp);
                        }
                        if (!f_temp_high)
                        {
                            if (FETTemp - oldTemp >= 1.0)
                            {
                                oldTemp = FETTemp;
                                //printf("f_temp_high_oldTemp = %f\n", oldTemp);
                                f_temp_high = 1;
                            }
                        }

                        if (f_temp_high)
                        {
                            tempDelay++;
                          //  printf("tempDelay = %d\n",tempDelay);
                        }
                        if (CFETdex >= 4)
                         {
                        //     printf("oldVoltageSum = %d", oldVoltageSum);
                        //     printf("  CFETdex= %d", CFETdex);
                            oldVoltageSum = oldVoltageSum + oldVoltage[CFETdex - 1] - oldVoltage[CFETdex - 4];
                            // printf("oldVoltageSum = %d", oldVoltageSum);
                        }
                    }

                    if (delay / 1000 >= (D_CFET_Delay+1))

                    {
                        if (t_com0d < 100)
                        {
                            // printf("enter rsoc<100\n");
                            // printf("FETTemp = %f", FETTemp);
                            // printf("oldVoltageSum = %d", oldVoltageSum);
                            if ((oldVoltageSum >= D_CFET_VoltageDifference ) || (((FETTemp - oldTemp) >= D_CFET_Temperature_difference )&&(tempDelay>=(D_CFET_Delay+1))))

                            {
                                delay = 0;
                                f_pf_cfetf_p = ON;
                                f_pf_cfetf_a = OFF;
                                if (f_FUSE_EN && D_Permanent_Fail_Fuse_C_CFETF)
                                {
                                    f_fuse_out = ON;
                                }
                                oldVoltageSum=0;
                                CFETdex = 0;
                            }
                            else if(f_temp_high && tempDelay>=(D_CFET_Delay+1))

                            {
                                tempDelay=0;
                                f_temp_high=0;
                                delay = 0;
                                CFETdex = 0;
                                oldVoltageSum = 0;
                            }
                            else if(!f_temp_high)
                            {
                                tempDelay=0;
                                f_temp_high=0;
                                delay = 0;
                                CFETdex = 0;
                                oldVoltageSum = 0;
                            }
                        }
                        else
                        {
                            delay = 0;
                            f_pf_cfetf_p = ON;
                            f_pf_cfetf_a = OFF;
                            if (f_FUSE_EN && D_Permanent_Fail_Fuse_C_CFETF)
                            {
                                f_fuse_out = ON;
                            }
                            oldVoltageSum=0;
                            CFETdex = 0;
                        }
                    }
                }
                else
                {
                    f_pf_cfetf_a = OFF;
                    delay = 0;
                    CFETdex=0;
                    oldVoltageSum=0;
                }
            }
            else
            {
                f_pf_cfetf_a = OFF;
                delay = 0;
                CFETdex=0;
                oldVoltageSum=0;
            }
        }
    }
}

void PF_DFET()
{
    static uint32_t delay = 0;
    if (D_Enabled_PF_C_DFETF)
    {
        if (!f_pf_dfetf_p)
        {
            if (!f_dsg) // dfet off
            {
                if (Current() <= D_DFET_Threshold)
                {
                    f_pf_dfetf_a = ON;
                    delay += Periodtime;
                    if (delay / 1000 >= (D_DFET_Delay+1))

                    {
                        delay = 0;
                        f_pf_dfetf_p = ON;
                        f_pf_dfetf_a = OFF;
                        if (f_FUSE_EN && D_Permanent_Fail_Fuse_C_DFETF)
                        {
                            f_fuse_out = ON;
                        }
                    }
                }
                else
                {
                    f_pf_dfetf_a = OFF;
                    delay = 0;
                }
            }
            else
            {
                f_pf_dfetf_a = OFF;
                delay = 0;
            }
        }
    }
}

void PF_FUSE()
{
    static uint32_t delay = 0;
    if (D_Enabled_PF_C_FUSE)
    {
        if (f_fuse_out && !f_pf_fuse_p)
        {
            if (I_abs >= D_FUSE_Threshold)
            {
                f_pf_fuse_a = ON;
                delay += Periodtime;
                if (delay/1000 >= (D_FUSE_Delay+1))

                {
                    delay = 0;
                    f_pf_fuse_a = OFF;
                    f_pf_fuse_p = ON;
                }
            }
            else
            {
                delay = 0;
                f_pf_fuse_a = OFF;
            }
        }
        else
        {
            f_pf_fuse_a = OFF;
            delay = 0;
        }
    }
}

void PF_2LVL()
{
    static uint32_t delay = 0;
    if (D_Enabled_PF_C_2LVL)
    {
        if (!f_fuse_out)
        {
            if (!f_pf_2lvl_p)
            {
                if (FUSE_Read())
                {
                    
                    f_pf_2lvl_a = ON;
                    delay += Periodtime;
                    if (delay / 1000 >= (D_2LVL+1))

                    {
                        delay = 0;
                        f_pf_2lvl_a = OFF;
                        f_pf_2lvl_p = ON;
                    }
                }
                else
                {
                    f_pf_2lvl_a = OFF;
                    delay = 0;
                }
            }
        }
        else
        {
            f_pf_2lvl_a = OFF;
            delay = 0;
        }
    }
}

void PF_TCO()
{
    static uint32_t delay = 0;
    if (D_Enabled_PF_D_TCO)
    {
        if(!f_pf_tco_p)
        {
            if ((V_max - V_min) >= D_TCO_Change_Voltage && V_min > D_TCO_Min_Voltage  && Ts_max >=D_TCO_Max_Temperature)
            {
                f_pf_tco_a = ON;
                delay += Periodtime;
                if(delay / 1000 >= (D_TCO_Delay+1))

                {
                    if(((V_max - V_min)/D_TCO_Cell_Impedance)>=(I_abs*D_TCO_K))
                    {
                        delay = 0;
                        f_pf_tco_p = ON;
                        f_pf_tco_a = OFF;
                        if (f_FUSE_EN && D_Permanent_Fail_Fuse_D_TCO)
                        {
                            f_fuse_out = ON;
                        }
                    }
                    else
                    {
                      delay = 0;  
                    }
                }
            
            }
            else
            {
                f_pf_tco_a = OFF;
                delay = 0;
            }
        }
    }
}

void Call_ProtectionFun()
{
    if (f_CAL_EN || f_pf)
    {
        return;
    }

    Protect_CUV();
    Protect_CUVC();
    Protect_COV();
    Protect_OCC();
    Protect_OCD();
    Protect_HardWare_Base();
    Protect_OTC();
    Protect_OTD();
    Protect_OTF();
    Protect_UTC();
    Protect_UTD();
    Protect_HWD();
    Protect_PTO();
    Protect_CTO();
    Protect_OC();
    Protect_CHGV();
    Protect_CHGC();
    Protect_PCHGC();
}


void Call_PermanentFailFun()
{

    if (!f_PF_EN || f_CAL_EN)
    {
        return;
    }

    PF_SUV();

    PF_SOV();
    PF_SOCC();
    PF_SOCD();
    PF_SOT();
    PF_SOTF();
    PF_VIMR();
    PF_VIMA();
    PF_CFET();
    PF_DFET();
    PF_FUSE();
    PF_2LVL();
    PF_TCO();

    if (_PFStatus.value)
    {
        f_pf = ON;
    }
}

void Judgment_Temp_Change()
{
    if ((uint16_t)((long)I_abs * 100 / D_Design_Capacity_mAh) >= 50)
    {
        if (CellTemp >= 10)
        {
            Temp_Change = 0; // D_Discharge_0_voltage D_0PVOLT
        }
        if ((CellTemp >= 5) && (CellTemp < 10))
        {
           Temp_Change= D_5_10_LIMIT; // D_0PVOLT5_Tempera_10   多串还是单串  ？   电压
        }
        else if (CellTemp < 5)
        {
            // D_0PVOLT= D_0PVOLT_Tempera_less_than_5 ;
            Temp_Change=D_5_LIMIT;
        }
    }
    else
    {
        Temp_Change = 0; 
    }
}

int16_t cal_average_dbpt_current(int16_t in_current)//, uint8_t interval_sec计算平均电流
{
    static int16_t current_buf[CUR_BUF_SIZE];//max_buf
    int16_t buf_out_val;
    
    static uint8_t buf_index = 0;
    static uint8_t full_flag = 0;
    static uint8_t first_flag = 1;
    static int32_t dbpt_current_sum = 0;
    
    static int16_t dbpt_average_current = 0;
    
    if(ABS(dbpt_average_current) < 50)
    {
        if(ABS(in_current) > 50)
        {
            buf_index = 0;
            full_flag = 0;
            first_flag = 1;
            dbpt_current_sum = 0;

            dbpt_average_current = in_current;
            return dbpt_average_current;
        }
    }

    if (full_flag) // buf is full
    {
        if (buf_index >= CUR_BUF_SIZE)
        {
            buf_index = 0;
        }
        buf_out_val = current_buf[buf_index];
        current_buf[buf_index++] = in_current;
        dbpt_current_sum += (in_current - buf_out_val);

        dbpt_average_current = (dbpt_current_sum) / CUR_BUF_SIZE;
    }
    else
    {
        if (buf_index < CUR_BUF_SIZE)
        {
            current_buf[buf_index++] = in_current;
            dbpt_current_sum += in_current;
            dbpt_average_current = dbpt_current_sum / buf_index;
        }
        if (buf_index >= CUR_BUF_SIZE)
        {
            full_flag = 1;
        }
    }
    return dbpt_average_current;
}


void DBPT_test(void)
{
    uint16_t  I_sim=0.2*_DesignCapacity;
    uint32_t SysVoltage=0;
    if(!f_charge)
    {
        if(Current()<0)
        {
          if(I_abs < 0.5*_DesignCapacity)
          {
            I_sim = cal_average_dbpt_current(I_abs);
          }
         
        }
        else
        {
            I_sim = 0.2*_DesignCapacity;
        }
        
        if(Ts_max >=D_DBPT_DBPT_min_temp && Ts_max<=D_DBPT_DBPT_max_temp)
        {
            uint16_t soc_ocv=Soc_OCV_Calibration(t_com0d,OCV_SOC);
            uint16_t soc_r1=Soc_OCV_Calibration(t_com0d,SOC_R1);
            uint16_t soc_r2=Soc_OCV_Calibration(t_com0d,SOC_R2);

            if (I_abs < 0.5 * _DesignCapacity)
            {
                SysVoltage = Voltage() - (soc_r1 + soc_r2) * NUMBER_SERIES * I_sim / 100 / 1000 - D_DBPT_MinSysVoltage - D_DBPT_MinSysVoltage_delta;
            }
            else
            {
                SysVoltage = soc_ocv * NUMBER_SERIES - (soc_r1 + soc_r2) * NUMBER_SERIES * I_sim / 100 / 1000 - D_DBPT_MinSysVoltage - D_DBPT_MinSysVoltage_delta;
            }

            uint32_t r2_sum = soc_r2 * NUMBER_SERIES / 100 + D_DBPT_PackResistance + D_DBPT_SystemResistance;

            uint32_t m_MPPCurrent=SysVoltage*1000 /r2_sum;
            m_MPPCurrent= m_MPPCurrent<D_DBPT_MPPCurrent_Max ? m_MPPCurrent:D_DBPT_MPPCurrent_Max;
            t_DBPT.MPPCurrent=  -m_MPPCurrent;
           
            uint32_t r1_r2_sum=(soc_r1 +soc_r2)*NUMBER_SERIES/100+D_DBPT_PackResistance+D_DBPT_SystemResistance;
           // printf("r1_r2_sum=%d\n",r1_r2_sum);
            
            uint32_t m_SPPCurrent=SysVoltage*1000/r1_r2_sum;
            m_SPPCurrent=m_SPPCurrent<D_DBPT_SPPCurrent_Max ? m_SPPCurrent:D_DBPT_SPPCurrent_Max;
            
            t_DBPT.SPPCurrent= -m_SPPCurrent;
            t_DBPT.MaxPeakPower=ABS(t_DBPT.MPPCurrent)*_DAStatus1.BatVoltage/1000;
            t_DBPT.SusPeakPower=ABS(t_DBPT.SPPCurrent)*_DAStatus1.BatVoltage/1000;
        }
        else
        {
            t_DBPT.MPPCurrent=-_DesignCapacity;
            t_DBPT.SPPCurrent=-_DesignCapacity;
        }
    }
}


uint16_t Soc_OCV_Calibration(uint16_t Rsoc_now,uint16_t *buf)
{
    uint8_t	aidx; 
    uint16_t soc_ocv= 0;
    for( aidx=0; (Rsoc_now >= (aidx+5)) && aidx < 100; aidx+=5);
    if(Rsoc_now<=0)
    {
        soc_ocv=buf[0];
    }
    else
    {
        if (Rsoc_now >= 100)
        {
            soc_ocv = buf[20];
        }
        else
        {
            soc_ocv= ((Rsoc_now-aidx)*(buf[(aidx/5)+1] - buf[aidx/5])/5)+buf[aidx/5];
        }
    }
    return soc_ocv;
}

void plugged_IN(void)
{
   static uint32_t socdelay = 0;
   static uint32_t tempdelay = 0;
   static uint32_t daydelay= 0;
   static uint32_t one_day=0;
   static uint32_t data_tt[]={0};
   static uint8_t  daydex=0;
   static uint8_t  sevendex=0;

   static uint8_t aidx_pi =0 ; 
   static uint16_t pi_count = 0 ;
   static uint16_t rsoc_pi= 0 ;
   static int32_t Record_lrc_w_pi = 0 ;
   
   f_pi_en=D_DA_Configuration_PI_EN;

   if (D_DA_Configuration_PI_EN)
   {
       if (!f_pi_mode)
       {
           if (f_pi_test)
           {
               pi_test = 3600;
           }
           else
           {
               pi_test = 1;
           }
            
           if (PackVoltage() > D_Shutdown_Charger_Present_Threshold && t_com0d > D_PI_MODE_PI_RSOC_Threshold)
           {
               socdelay +=(pi_test * Periodtime);
               
             
               if ((_DAStatus2.CellTemperature-2731)/10 > D_PI_MODE_PI_HI_Temp_Threshold)
               {
                   daydelay +=(pi_test * Periodtime);
                  
                   one_day += (pi_test * Periodtime);
               }
               
               if (((socdelay/TIME_TO_HOUR) % 24 == 0 )&& socdelay >TIME_TO_HOUR)
               {
                   
                   data_tt[daydex++] = one_day;
                   one_day = 0;
               }

               if ((socdelay /TIME_TO_HOUR >= D_PI_MODE_PI_HT_Temp_Time) && ((socdelay/TIME_TO_HOUR) % 24 == 0 ))
               {
                   if (daydelay/TIME_TO_HOUR  >= D_PI_MODE_PI_HT_Temp_Threshold )
                   {
                       
                       f_pi_mode = 1;
                   }
                   else
                   {
                       daydelay -= data_tt[sevendex++];
                   }
               }
               if (socdelay /TIME_TO_HOUR >= D_PI_MODE_PI_Time_Window)
               {
                   f_pi_mode = 1;
               }
           }
           pi_sum_time = socdelay / TIME_TO_HOUR;
           pi_temp_time = daydelay / TIME_TO_HOUR;
           if (f_pi_mode)
           {
               LifeTimes_Pi_Mode_Count++;
               f_ltreqW = ON;
           }
       }
       else
       {
           if (V_min < D_PI_MODE_Dsg_to_Voltage)
           {
               pi_blance_disable();
               f_pi_mode = 0;
           }
           else
           {
               pi_blance_enable();
               if (_ChargingVoltage >= D_PI_MODE_PI_Delte_Voltage)
               {
                   _ChargingVoltage -= D_PI_MODE_PI_Delte_Voltage;
               }
               else
               {
                   _ChargingVoltage = 0;
               }
           }
           daydelay = 0;
           socdelay = 0;
           one_day = 0;
           memset(data_tt, 0, sizeof(data_tt));
           daydex = 0;
           sevendex = 0;
       }
   }
   if (f_discharge && (!BatteryStatus(FC)))
   {

       f_pi_mode = 0;
       pi_blance_disable();
       daydelay = 0;
       socdelay = 0;
       one_day = 0;
       memset(data_tt, 0, sizeof(data_tt));
       daydex = 0;
       sevendex = 0;
   }
   

   if (f_charge)
   {
       pi_count = 0;
       f_pi_pinghua = 0;
   }





    if(f_pi_mode)  // pimode  finished，  then re evaluate . 
	{
      f_study_d = 0 ;
	//   pi_count++ ;
    //   if(pi_count >= 3600 )f_
    //   {
        //  pi_count = 3600;
        if(f_relax)
        {

          for (aidx_pi = 0; V_min >= OCV_SOC[aidx_pi + 1] && aidx_pi < 19; aidx_pi++);
          if (V_min <= OCV_SOC[0]) // Smaller than 0% voltage ?
          {
              Record_lrc_w_pi = 0; // Set capacity to 0%
              rsoc_pi = 0 ; 
          }
          else
          {
              if (V_min >= OCV_SOC[20]) // Bigger than 100% voltage ?
              {
                      // Set capacity to 100%
                      Record_lrc_w_pi = (long)t_com10 * 14400; // (100/100*14400=14400)
                      rsoc_pi = 100 ; 
              }
              else
              { // Not 0% and Not 99%
                  rsoc_pi= (uint8_t)((V_min - OCV_SOC[aidx_pi]) * 5 / (OCV_SOC[aidx_pi + 1] - OCV_SOC[aidx_pi])) + (5 * aidx_pi);
                  Record_lrc_w_pi = (long)t_com10 * rsoc_pi* 144;
              }
          }
    //   }
                
        }
    }
    else if (f_pi_mode_last) // last == 1 , this time = 0 .
    {
        f_pi_pinghua = 1;
    }

      if (f_pi_pinghua)
      {
       //  t_com0f = Record_lrc_w / 14400 ;
          if (rsoc_pi != t_com0d)
          {
            //   if ((f_discharge == 1) && (f_relax == 0))
             if ((f_discharge == 1) && (f_relax == 0))
              {
                  Record_lrc_w -=  3* I_abs;  // total -4 times , cause calute rc still - I_abs . 
                  Record_lrc_w_pi -= I_abs;

                 if (Record_lrc_w_pi >= t_com10 * 14400)
                 {
                     Record_lrc_w_pi = t_com10 * 14400;
                 }

                 if (Record_lrc_w_pi >= t_com10 * 14400)
                 {
                     Record_lrc_w_pi = t_com10 * 14400;
                 }

                  if (Record_lrc_w_pi <= 0)
                  {
                      Record_lrc_w_pi = 0;
                  }

                  if (rsoc_pi >= 100)
                  {
                      rsoc_pi = 100;
                  }
                 // rsoc_pi = Record_lrc_w_pi/14400/t_com10*100 ;
                  //  twork = (uint16_t)(((((long)t_com0f * 200)*10 / t_com10) + 10)/2);

                //   rsoc_pi = Record_lrc_w_pi*10/144/t_com10/10;
                   rsoc_pi = (Record_lrc_w_pi*5/72/t_com10+5)/10;

                //   t_com0d =  (uint16_t)(((((long)t_com0f * 100)*10 / t_com10) + 5)/10) ;
                  if (rsoc_pi == t_com0d) // maybe need to judge 2 times
                  {
                     f_pi_pinghua = 0;
                  }
              }
          }
          else
          {
              f_pi_pinghua = 0;
          }
      }

      if (f_charge)
      {
          f_pi_pinghua = 0;
      }

    t_com1d_out =  rsoc_pi   ;
    t_com1e_out = f_pi_pinghua;  
    t_com1f_out =  pi_count ;
    t_com41_out  = Record_lrc_w_pi /14400 ;
    t_com42_out  = f_pi_mode_last ;
    t_com43_out  = Record_lrc_w_pi %14400 ;
    f_pi_mode_last =   f_pi_mode ;

}
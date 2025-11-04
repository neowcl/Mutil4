#include "main.h"
#include "lifetime.h"
#define CHECK_CNT 3
#define LTW_DELAY 36000 // 10Hour

uint16_t altflg;
uint16_t lt_test = 1;

uint16_t LtW_Cnt[19] = {0};
uint16_t LtW_CntW;
uint32_t CellCBTime_Cnt[4] = {0};
uint32_t Fwrun_Cnt = 0;

uint32_t rsoc_Cnt=0;
uint32_t Data_Cnt = 0;

uint8_t icnt, tcnt;
uint16_t T_Cnt[7][8] = {0};

int16_t AvgDsgPwr = 0;
int16_t DeltaCellVol = 0;

int8_t LastTime_TS1 = 0;
int8_t DeltaTS1 = 0;
int8_t LastTime_TS2 = 0;
int8_t DeltaTS2 = 0;
int8_t MaxDeltaTS = 0;

int8_t temp_maxint8;
int16_t temp_maxin16;
int16_t Fettemp_maxin16;

static uint32_t last_PF_Status = 0;/*!< 上一次的安全状态 */
static uint32_t last_Status_Status = 0;/*!< 上一次的安全状态 */


LifeTime_t lifetime_ram;
float tempmax;

int8_t temp_minint8;
int16_t temp_minin16;
float tempmin;

static void LTMax_I(uint8_t *MaxDataLT, uint8_t *MaxParaLT, uint8_t *MaxCntLT, uint8_t LTLength)
{
    uint8_t i;
    int32_t DataLT = 0, ParaLT = 0;
    for (i = 0; i < LTLength; i++)
    {
        DataLT |= MaxDataLT[i] << i * 8;
        ParaLT |= MaxParaLT[i] << i * 8;
    }
    if (DataLT > ParaLT)
    {
        (*MaxCntLT)++;
        if (*MaxCntLT >= CHECK_CNT)
        {
            for (i = 0; i < LTLength; i++)
            {
                MaxParaLT[i] = MaxDataLT[i];
            }
            f_ltreq = ON;
            *MaxCntLT = 0;
        }
    }
    else
    {
        *MaxCntLT = 0;
    }
}

void life_Time_Protect_Event(uint8_t  type)
{
    if (f_LF_EN)
    {
       switch(type)
       {
       case LT_COV:
       {
        LifeTimes_No_Of_COV_Events++;
        LifeTimes_Last_COV_Event=_CycleCount;
        f_ltreqW=ON;
        break;
       }
       case LT_CUV:
       {
        LifeTimes_No_Of_CUV_Events++;
        LifeTimes_Last_CUV_Event=_CycleCount;
        f_ltreqW=ON;
        break;
        
        break;
       }
       case LT_OCD1:
       {
        LifeTimes_No_Of_OCD1_Events++;
        LifeTimes_Last_OCD1_Event=_CycleCount;
        f_ltreqW=ON;
        break;
      
      }
         case LT_OCD2:
         {
          LifeTimes_No_Of_OCD2_Events++;
          LifeTimes_Last_OCD2_Event=_CycleCount;
          f_ltreqW=ON;
          break;
         }
         case LT_OCC1:
         {
          LifeTimes_No_Of_OCC1_Events++;
          LifeTimes_Last_OCC1_Event=_CycleCount;
          f_ltreqW=ON;
          break;
        
        }
         case LT_OCC2:
         {
          LifeTimes_No_Of_OCC2_Events++;
          LifeTimes_Last_OCC2_Event=_CycleCount;
          f_ltreqW=ON;
          break;
         }
         case LT_AOLD:
         {
            LifeTimes_No_Of_AOLD_Events++;
            LifeTimes_Last_AOLD_Event=_CycleCount;
            f_ltreqW=ON;
          break;
         }
         case LT_ASCD:
         {
          LifeTimes_No_Of_ASCD_Events++;
          LifeTimes_Last_ASCD_Event=_CycleCount;
          f_ltreqW=ON;
          break;
         }
         case LT_ASCC:
         {
            LifeTimes_No_Of_ASCC_Events++;
            LifeTimes_Last_ASCC_Event=_CycleCount;
            f_ltreqW=ON;
          break;
         }
         case LT_OTC:
         {
            LifeTimes_No_Of_OTC_Events++;
            LifeTimes_Last_OTC_Event=_CycleCount;
            f_ltreqW=ON;
          break;
         }
         case LT_OTD:
         {
            LifeTimes_No_Of_OTD_Events++;
            LifeTimes_Last_OTD_Event=_CycleCount;
            f_ltreqW=ON;
          break;
         }
         case LT_OTF:
         {
            LifeTimes_No_Of_OTF_Events++;
            LifeTimes_Last_OTF_Event=_CycleCount;
            f_ltreqW=ON;
          break;
         }

       default:
        break;
       }
    }
}

static void LifeTime_Static_A_Check(uint32_t _a_Cnt)
{
    switch (_a_Cnt % 3)
    {
    case 0:
    {
        LifeTimes_3st_Status_Status_A = (uint8_t)(_SafetyStatus.value);
        LifeTimes_3st_Time_to_Next_Event=(LifeTimes_Total_Firmware_Runtime + (lifetime_ram._TotalFwRuntime/TIME_TO_HOUR));
        f_ltreqW = ON;
        break;
    }
    case 1:
    {
        LifeTimes_1st_Status_Status_A = (uint8_t)(_SafetyStatus.value );
        LifeTimes_1st_Time_to_Next_Event=(LifeTimes_Total_Firmware_Runtime + (lifetime_ram._TotalFwRuntime/TIME_TO_HOUR));
        f_ltreqW = ON;
        break;
    }
    case 2:
    {
        LifeTimes_2st_Status_Status_A = (uint8_t)(_SafetyStatus.value);
        LifeTimes_2st_Time_to_Next_Event=(LifeTimes_Total_Firmware_Runtime + (lifetime_ram._TotalFwRuntime/TIME_TO_HOUR));
        f_ltreqW = ON;
        break;
    }
    }
}

static void Lifetime_Static_A_status(void)
{
  
    static uint32_t a_status_Cnt=0;
    if (SafetyStatus(CUV) && ((last_Status_Status & bitSafetyStatus_CUV) == 0))
    {
        a_status_Cnt++;
        LifeTime_Static_A_Check(a_status_Cnt);
    }

    if (SafetyStatus(COV) && ((last_Status_Status & bitSafetyStatus_COV) == 0))
    {
        a_status_Cnt++;
        LifeTime_Static_A_Check(a_status_Cnt);
    }

    if(SafetyStatus(OCC1)&& ((last_Status_Status & bitSafetyStatus_OCC1) == 0))
    {
        a_status_Cnt++;
        LifeTime_Static_A_Check(a_status_Cnt);
    }
    
    if(SafetyStatus(OCC2) && ((last_Status_Status & bitSafetyStatus_OCC2) == 0))
    {
        a_status_Cnt++;
        LifeTime_Static_A_Check(a_status_Cnt);
    }

    if(SafetyStatus(OCD1) && ((last_Status_Status & bitSafetyStatus_OCD1) == 0))
    {
        a_status_Cnt++;
        LifeTime_Static_A_Check(a_status_Cnt);
    }

    if(SafetyStatus(OCD2) && ((last_Status_Status & bitSafetyStatus_OCD2) == 0))
    {
       a_status_Cnt++;
        LifeTime_Static_A_Check(a_status_Cnt);
    }
    if(SafetyStatus(AOLD) && ((last_Status_Status & bitSafetyStatus_AOLD) == 0))
    {
        a_status_Cnt++;
        LifeTime_Static_A_Check(a_status_Cnt);
    }

    if(SafetyStatus(AOLDL)  && ((last_Status_Status & bitSafetyStatus_AOLDL) == 0))
    {
        a_status_Cnt++;
        LifeTime_Static_A_Check(a_status_Cnt);
    }
}

static void LifeTime_Static_B_Check(uint32_t pf_a_Cnt)
{
    switch (pf_a_Cnt % 3)
    {
    case 0:
    {
        LifeTimes_3st_Status_Status_B = (uint8_t)(_SafetyStatus.value>>8);
        LifeTimes_3st_Time_to_Next_Event=(LifeTimes_Total_Firmware_Runtime + (lifetime_ram._TotalFwRuntime/TIME_TO_HOUR));
        f_ltreqW = ON;
        break;
    }
    case 1:
    {
        LifeTimes_1st_Status_Status_B = (uint8_t)(_SafetyStatus.value>>8 );
        LifeTimes_1st_Time_to_Next_Event=(LifeTimes_Total_Firmware_Runtime + (lifetime_ram._TotalFwRuntime/TIME_TO_HOUR));
        f_ltreqW = ON;
        break;
    }
    case 2:
    {
        LifeTimes_2st_Status_Status_B = (uint8_t)(_SafetyStatus.value>>8);
        LifeTimes_2st_Time_to_Next_Event=(LifeTimes_Total_Firmware_Runtime + (lifetime_ram._TotalFwRuntime/TIME_TO_HOUR));
        f_ltreqW = ON;
        break;
    }
    }
}

static void Lifetime_Static_B_status(void)
{
  
    static uint32_t b_status_Cnt=0;
    if (SafetyStatus(ASCC) && ((last_Status_Status & bitSafetyStatus_ASCC) == 0))
    {
        b_status_Cnt++;
        LifeTime_Static_B_Check(b_status_Cnt);
    }

    if (SafetyStatus(ASCCL) && ((last_Status_Status & bitSafetyStatus_ASCCL) == 0))
    {
        b_status_Cnt++;
        LifeTime_Static_B_Check(b_status_Cnt);
    }

    if(SafetyStatus(ASCD)&& ((last_Status_Status & bitSafetyStatus_ASCD) == 0))
    {
        b_status_Cnt++;
        LifeTime_Static_B_Check(b_status_Cnt);
    }
    
    if(SafetyStatus(ASCDL) && ((last_Status_Status & bitSafetyStatus_ASCDL) == 0))
    {
        b_status_Cnt++;
        LifeTime_Static_B_Check(b_status_Cnt);
    }

    if(SafetyStatus(OTC) && ((last_Status_Status & bitSafetyStatus_OTC) == 0))
    {
        b_status_Cnt++;
        LifeTime_Static_B_Check(b_status_Cnt);
    }

    if(SafetyStatus(OTD) && ((last_Status_Status & bitSafetyStatus_OTD) == 0))
    {
       b_status_Cnt++;
        LifeTime_Static_B_Check(b_status_Cnt);
    }
    if(SafetyStatus(CUVC) && ((last_Status_Status & bitSafetyStatus_CUCV) == 0))
    {
        b_status_Cnt++;
        LifeTime_Static_B_Check(b_status_Cnt);
    }
}


static void LifeTime_Static_C_Check(uint32_t pf_a_Cnt)
{
    switch (pf_a_Cnt % 3)
    {
    case 0:
    {
        LifeTimes_3st_Status_Status_C = (uint8_t)(_SafetyStatus.value>>16);
        LifeTimes_3st_Time_to_Next_Event=(LifeTimes_Total_Firmware_Runtime + (lifetime_ram._TotalFwRuntime/TIME_TO_HOUR));
        f_ltreqW = ON;
        break;
    }
    case 1:
    {
        LifeTimes_1st_Status_Status_C = (uint8_t)(_SafetyStatus.value>>16 );
        LifeTimes_1st_Time_to_Next_Event=(LifeTimes_Total_Firmware_Runtime + (lifetime_ram._TotalFwRuntime/TIME_TO_HOUR));
        break;
    }
    case 2:
    {
        LifeTimes_2st_Status_Status_C = (uint8_t)(_SafetyStatus.value>>16);
        LifeTimes_2st_Time_to_Next_Event=(LifeTimes_Total_Firmware_Runtime + (lifetime_ram._TotalFwRuntime/TIME_TO_HOUR));
        f_ltreqW = ON;
        break;
    }
    }
}

static void Lifetime_Static_C_status(void)
{
  
    static uint32_t c_status_Cnt=0;
    if (SafetyStatus(OTF) && ((last_Status_Status & bitSafetyStatus_OTF) == 0))
    {
        c_status_Cnt++;
        LifeTime_Static_C_Check(c_status_Cnt);
    }

    if (SafetyStatus(HWD) && ((last_Status_Status & bitSafetyStatus_HWDF) == 0))
    {
        c_status_Cnt++;
        LifeTime_Static_C_Check(c_status_Cnt);
    }

    if(SafetyStatus(PTO)&& ((last_Status_Status & bitSafetyStatus_PTO) == 0))
    {
        c_status_Cnt++;
        LifeTime_Static_C_Check(c_status_Cnt);
    }
    
    if(SafetyStatus(CTO) && ((last_Status_Status & bitSafetyStatus_CTO) == 0))
    {
        c_status_Cnt++;
        LifeTime_Static_C_Check(c_status_Cnt);
    }

    if(SafetyStatus(OC) && ((last_Status_Status & bitSafetyStatus_OC) == 0))
    {
        c_status_Cnt++;
        LifeTime_Static_C_Check(c_status_Cnt);
    }

    if(SafetyStatus(CHGC) && ((last_Status_Status & bitSafetyStatus_CHGC) == 0))
    {
       c_status_Cnt++;
        LifeTime_Static_C_Check(c_status_Cnt);
    }

}


static void LifeTime_Static_D_Check(uint32_t pf_a_Cnt)
{
    switch (pf_a_Cnt % 3)
    {
    case 0:
    {
        LifeTimes_3st_Status_Status_D = (uint8_t)(_SafetyStatus.value>>24);
        LifeTimes_3st_Time_to_Next_Event=(LifeTimes_Total_Firmware_Runtime + (lifetime_ram._TotalFwRuntime/TIME_TO_HOUR));
        f_ltreqW = ON;
        break;
    }
    case 1:
    {
        LifeTimes_1st_Status_Status_D = (uint8_t)(_SafetyStatus.value>>24 );
        LifeTimes_1st_Time_to_Next_Event=(LifeTimes_Total_Firmware_Runtime + (lifetime_ram._TotalFwRuntime/TIME_TO_HOUR));
        f_ltreqW = ON;
        break;
    }
    case 2:
    {
        LifeTimes_2st_Status_Status_D = (uint8_t)(_SafetyStatus.value>>24);
        LifeTimes_2st_Time_to_Next_Event=(LifeTimes_Total_Firmware_Runtime + (lifetime_ram._TotalFwRuntime/TIME_TO_HOUR));
        f_ltreqW = ON;
        break;
    }
    }
}

static void Lifetime_Static_D_status(void)
{
  
    static uint32_t d_status_Cnt=0;
    if (SafetyStatus(CHGV ) && ((last_Status_Status & bitSafetyStatus_CHGV) == 0))
    {
        d_status_Cnt++;
        LifeTime_Static_D_Check(d_status_Cnt);
    }

    if (SafetyStatus(PCHGC) && ((last_Status_Status & bitSafetyStatus_PCHGC) == 0))
    {
        d_status_Cnt++;
        LifeTime_Static_D_Check(d_status_Cnt);
    }

    if(SafetyStatus(UTC)&& ((last_Status_Status & bitSafetyStatus_UTC) == 0))
    {
        d_status_Cnt++;
        LifeTime_Static_D_Check(d_status_Cnt);
    }
    
    if(SafetyStatus(UTD) && ((last_Status_Status & bitSafetyStatus_UTD) == 0))
    {
        d_status_Cnt++;
        LifeTime_Static_D_Check(d_status_Cnt);
    }

    if(SafetyStatus(COVL) && ((last_Status_Status & bitSafetyStatus_COVL) == 0))
    {
        d_status_Cnt++;
        LifeTime_Static_D_Check(d_status_Cnt);
    }

    if(SafetyStatus(OCDL) && ((last_Status_Status & bitSafetyStatus_OCDL) == 0))
    {
       d_status_Cnt++;
        LifeTime_Static_D_Check(d_status_Cnt);
    }

}

static void LifeTime_PF_A_Check(uint32_t pf_a_Cnt)
{
      switch(pf_a_Cnt %3)
        {
           case 0:
           {
            LifeTimes_3st_PF_Status_A= (uint8_t)_PFStatus.value;
            f_ltreqW=ON;
            break;
           }
           case 1:
           {
            LifeTimes_1st_PF_Status_A= (uint8_t)_PFStatus.value;
            f_ltreqW=ON;
            break;
           }
           case 2:
           {
            LifeTimes_2st_PF_Status_A= (uint8_t)_PFStatus.value;
            f_ltreqW=ON;
            break;
           }
   
        }
}

static void Lifetime_PF_A_status(void)
{
    static uint32_t pf_a_status_Cnt=0;
    if (f_pf_suv_p && ((last_PF_Status & bitPFStatus_SUV) == 0))
    {
        pf_a_status_Cnt++;
        LifeTime_PF_A_Check(pf_a_status_Cnt);
    }

    if (f_pf_sov_p && ((last_PF_Status & bitPFStatus_SOV) == 0))
    {
        pf_a_status_Cnt++;
        LifeTime_PF_A_Check(pf_a_status_Cnt);
    }

    if(f_pf_socc_p && ((last_PF_Status & bitPFStatus_SOCC) == 0))
    {
        pf_a_status_Cnt++;
        LifeTime_PF_A_Check(pf_a_status_Cnt);
    }
    
    if(f_pf_socd_p && ((last_PF_Status & bitPFStatus_SOCD) == 0))
    {
        pf_a_status_Cnt++;
        LifeTime_PF_A_Check(pf_a_status_Cnt);
    }

    if(f_pf_sot_p && ((last_PF_Status & bitPFStatus_SOT) == 0))
    {
        pf_a_status_Cnt++;
        LifeTime_PF_A_Check(pf_a_status_Cnt);
    }

    if(f_pf_covl_p && ((last_PF_Status & bitPFStatus_COVL) == 0))
    {
        pf_a_status_Cnt++;
        LifeTime_PF_A_Check(pf_a_status_Cnt);
    }
    if(f_pf_sotf_p && ((last_PF_Status & bitPFStatus_SOTF) == 0))
    {
        pf_a_status_Cnt++;
        LifeTime_PF_A_Check(pf_a_status_Cnt);
    }

    if(f_pf_qim_p && ((last_PF_Status & bitPFStatus_QIM) == 0))
    {
        pf_a_status_Cnt++;
        LifeTime_PF_A_Check(pf_a_status_Cnt);
    }
    
}

static void LifeTime_PF_B_Check(uint32_t pf_a_Cnt)
{
    switch (pf_a_Cnt % 3)
    {
    case 0:
    {
        LifeTimes_3st_PF_Status_B = (uint8_t)(_PFStatus.value >> 8);
        f_ltreqW = ON;
        break;
    }
    case 1:
    {
        LifeTimes_1st_PF_Status_B = (uint8_t)(_PFStatus.value >> 8);
        f_ltreqW = ON;
        break;
    }
    case 2:
    {
        LifeTimes_2st_PF_Status_B = (uint8_t)(_PFStatus.value >> 8);
        f_ltreqW = ON;
        break;
    }
    }
}

static void Lifetime_PF_B_status(void)
{
  
    static uint32_t pf_b_status_Cnt=0;
    if (f_pf_cb_p && ((last_PF_Status & bitPFStatus_CB) == 0))
    {
        pf_b_status_Cnt++;
        LifeTime_PF_B_Check(pf_b_status_Cnt);
    }

    if (f_pf_imp_p && ((last_PF_Status & bitPFStatus_IMP) == 0))
    {
        pf_b_status_Cnt++;
        LifeTime_PF_B_Check(pf_b_status_Cnt);
    }

    if(f_pf_cd_p && ((last_PF_Status & bitPFStatus_CD) == 0))
    {
        pf_b_status_Cnt++;
        LifeTime_PF_B_Check(pf_b_status_Cnt);
    }
    
    if(f_pf_vimr_p && ((last_PF_Status & bitPFStatus_VIMR) == 0))
    {
        pf_b_status_Cnt++;
        LifeTime_PF_B_Check(pf_b_status_Cnt);
    }

    if(f_pf_vima_p && ((last_PF_Status & bitPFStatus_VIMA) == 0))
    {
        pf_b_status_Cnt++;
        LifeTime_PF_B_Check(pf_b_status_Cnt);
    }

    if(f_pf_aoldl_p && ((last_PF_Status & bitPFStatus_AOLDL) == 0))
    {
        pf_b_status_Cnt++;
        LifeTime_PF_B_Check(pf_b_status_Cnt);
    }
    if(f_pf_asccl_p && ((last_PF_Status & bitPFStatus_ASCCL) == 0))
    {
        pf_b_status_Cnt++;
        LifeTime_PF_B_Check(pf_b_status_Cnt);
    }

    if(f_pf_ascdl_p  && ((last_PF_Status & bitPFStatus_ASCDL) == 0))
    {
        pf_b_status_Cnt++;
        LifeTime_PF_B_Check(pf_b_status_Cnt);
    }
}


static void LifeTime_PF_C_Check(uint32_t pf_a_Cnt)
{
    switch (pf_a_Cnt % 3)
    {
    case 0:
    {
        LifeTimes_3st_PF_Status_C = (uint8_t)(_PFStatus.value >> 16);
        f_ltreqW = ON;
        break;
    }
    case 1:
    {
        LifeTimes_1st_PF_Status_C = (uint8_t)(_PFStatus.value >> 16);
        f_ltreqW = ON;
        break;
    }
    case 2:
    {
        LifeTimes_2st_PF_Status_C = (uint8_t)(_PFStatus.value >> 16);
        f_ltreqW = ON;
        break;
    }
    }
}

static void Lifetime_PF_C_status(void)
{
  
    static uint32_t pf_c_status_Cnt=0;
    if (f_pf_cfetf_p && ((last_PF_Status & bitPFStatus_CFETF) == 0))
    {
        pf_c_status_Cnt++;
        LifeTime_PF_C_Check(pf_c_status_Cnt);
    }

    if (f_pf_dfetf_p && ((last_PF_Status & bitPFStatus_DFETF) == 0))
    {
        pf_c_status_Cnt++;
        LifeTime_PF_C_Check(pf_c_status_Cnt);
    }

    if(f_pf_ocdl_p && ((last_PF_Status & bitPFStatus_OCDL) == 0))
    {
        pf_c_status_Cnt++;
        LifeTime_PF_C_Check(pf_c_status_Cnt);
    }
    
    if(f_pf_fuse_p && ((last_PF_Status & bitPFStatus_FUSE) == 0))
    {
        pf_c_status_Cnt++;
        LifeTime_PF_C_Check(pf_c_status_Cnt);
    }

    if(f_pf_afer_p && ((last_PF_Status & bitPFStatus_AFER) == 0))
    {
        pf_c_status_Cnt++;
        LifeTime_PF_C_Check(pf_c_status_Cnt);
    }

    if(f_pf_afec_p && ((last_PF_Status & bitPFStatus_AFEC) == 0))
    {
        pf_c_status_Cnt++;
        LifeTime_PF_C_Check(pf_c_status_Cnt);
    }
    if(f_pf_2lvl_p && ((last_PF_Status & bitPFStatus_2LVL) == 0))
    {
        pf_c_status_Cnt++;
        LifeTime_PF_C_Check(pf_c_status_Cnt);
    }

  
}

static void LifeTime_PF_D_Check(uint32_t pf_a_Cnt)
{
    switch (pf_a_Cnt % 3)
    {
    case 0:
    {
        LifeTimes_3st_PF_Status_D = (uint8_t)(_PFStatus.value >> 24);
        f_ltreqW = ON;
        break;
    }
    case 1:
    {
        LifeTimes_1st_PF_Status_D = (uint8_t)(_PFStatus.value >> 24);
        f_ltreqW = ON;
        break;
    }
    case 2:
    {
        LifeTimes_2st_PF_Status_D = (uint8_t)(_PFStatus.value >> 24);
        f_ltreqW = ON;
        break;
    }
    }
}

static void Lifetime_PF_D_status(void)
{
  
    static uint32_t pf_d_status_Cnt=0;
    if (f_pf_tco_p && ((last_PF_Status & bitPFStatus_TCO) == 0))
    {
        pf_d_status_Cnt++;
        LifeTime_PF_D_Check(pf_d_status_Cnt);
    }

    if (f_pf_vsp_p && ((last_PF_Status & bitPFStatus_VSP) == 0))
    {
        pf_d_status_Cnt++;
        LifeTime_PF_D_Check(pf_d_status_Cnt);
    }

    if(f_pf_ts1_p && ((last_PF_Status & bitPFStatus_TS1) == 0))
    {
        pf_d_status_Cnt++;
        LifeTime_PF_D_Check(pf_d_status_Cnt);
    }
    
    if(f_pf_ts2_p && ((last_PF_Status & bitPFStatus_TS2) == 0))
    {
        pf_d_status_Cnt++;
        LifeTime_PF_D_Check(pf_d_status_Cnt);
    }

    if(f_pf_ts3_p && ((last_PF_Status & bitPFStatus_TS3) == 0))
    {
        pf_d_status_Cnt++;
        LifeTime_PF_D_Check(pf_d_status_Cnt);
    }

    if(f_pf_ts4_p && ((last_PF_Status & bitPFStatus_TS4) == 0))
    {
        pf_d_status_Cnt++;
        LifeTime_PF_D_Check(pf_d_status_Cnt);
    }

  
}


static void LTMin_I(uint8_t *MinDataLT, uint8_t *MinParaLT, uint8_t *MinCntLT, uint8_t LTLength)
{
    uint8_t i;
    int32_t DataLT = 0, ParaLT = 0;
    for (i = 0; i < LTLength; i++)
    {
        DataLT |= MinDataLT[i] << i * 8;
        ParaLT |= MinParaLT[i] << i * 8;
    }
    if (DataLT < ParaLT)
    {
        (*MinCntLT)++;
        if (*MinCntLT >= CHECK_CNT)
        {
            for (i = 0; i < LTLength; i++)
            {
                MinParaLT[i] = MinDataLT[i];
            }
            f_ltreq = ON;
            *MinCntLT = 0;
        }
    }
    else
    {
        *MinCntLT = 0;
    }
}

void SocTime(uint8_t tcnt, uint8_t icnt)
{
    if (f_sleep)
    {
        T_Cnt[tcnt][icnt] += D_Sleep_Voltage_Time;
    }
    else
    {
        T_Cnt[tcnt][icnt] += 1;
    }
    if (T_Cnt[tcnt][icnt] >= (3600 / lt_test))
    {
        T_Cnt[tcnt][icnt] = 0;
        f_ltreq = ON;
        if (tcnt == 0)
        {
            UT_RSOC[icnt] += 1;
        }
        else if (tcnt == 1)
        {
            LT_RSOC[icnt] += 1;
        }
        else if (tcnt == 2)
        {
            STL_RSOC[icnt] += 1;
        }
        else if (tcnt == 3)
        {
            RT_RSOC[icnt] += 1;
        }
        else if (tcnt == 4)
        {
            STH_RSOC[icnt] += 1;
        }
        else if (tcnt == 5)
        {
            HT_RSOC[icnt] += 1;
        }
        else if (tcnt == 6)
        {
            OT_RSOC[icnt] += 1;
        }
    }
}
uint8_t f_lt_init = 1;
void LT_Init(void)
{
    // LifeTimes_Cell_1_Max_Voltage = 0;
    // LifeTimes_Cell_2_Max_Voltage = 0;
    LifeTimes_Max_Charge_Current = 0;
    LifeTimes_Cell_1_Min_Voltage = 0xFFFE;
    LifeTimes_Cell_2_Min_Voltage = 0xFFFE;
    LifeTimes_Cell_3_Min_Voltage = 0xFFFE;
    LifeTimes_Cell_4_Min_Voltage = 0xFFFE;
    LifeTimes_Max_Temp_Cell = 0;
    LifeTimes_Min_Temp_Cell = 60;
    LifeTimes_Min_Temp_Int_Sensor=60;

    // f_LF_EN = 1;
    // f_LT_TEST = 1;
}


static void Basic_LifeTime(void)
{
   LTMax_I((uint8_t *)&_DAStatus1.CellVoltage1, (uint8_t *)&LifeTimes_Cell_1_Max_Voltage, (uint8_t *)&LtW_Cnt[0], 2);
        LTMax_I((uint8_t *)&_DAStatus1.CellVoltage2, (uint8_t *)&LifeTimes_Cell_2_Max_Voltage, (uint8_t *)&LtW_Cnt[1], 2);
        LTMax_I((uint8_t *)&_DAStatus1.CellVoltage3, (uint8_t *)&LifeTimes_Cell_3_Max_Voltage, (uint8_t *)&LtW_Cnt[2], 2);
        LTMax_I((uint8_t *)&_DAStatus1.CellVoltage4, (uint8_t *)&LifeTimes_Cell_4_Max_Voltage, (uint8_t *)&LtW_Cnt[3], 2);
        // D_LifeTimes_Cell_1_Max_Voltage = LifeTimes_Cell_1_Max_Voltage ;
        LTMin_I((uint8_t *)&_DAStatus1.CellVoltage1, (uint8_t *)&LifeTimes_Cell_1_Min_Voltage, (uint8_t *)&LtW_Cnt[4], 2);
        LTMin_I((uint8_t *)&_DAStatus1.CellVoltage2, (uint8_t *)&LifeTimes_Cell_2_Min_Voltage, (uint8_t *)&LtW_Cnt[5], 2);
        LTMin_I((uint8_t *)&_DAStatus1.CellVoltage3, (uint8_t *)&LifeTimes_Cell_3_Min_Voltage, (uint8_t *)&LtW_Cnt[6], 2);
        LTMin_I((uint8_t *)&_DAStatus1.CellVoltage4, (uint8_t *)&LifeTimes_Cell_4_Min_Voltage, (uint8_t *)&LtW_Cnt[7], 2);
        DeltaCellVol = V_max - V_min;
        LTMax_I((uint8_t *)&DeltaCellVol, (uint8_t *)&LifeTimes_Max_Delta_Cell_Voltage, (uint8_t *)&LtW_Cnt[8], 2);
        // Current
        if (f_charge && Current() > 20)
        {
            LTMax_I((uint8_t *)&Current(), (uint8_t *)&LifeTimes_Max_Charge_Current, (uint8_t *)&LtW_Cnt[9], 2);
        }

        if (f_discharge && (Current() < (-30)))
        {
            // LTMax_I((uint8_t*)&Current(),(uint8_t*)&LifeTimes_Max_Discharge_Current,(uint8_t*)&LtW_Cnt[10],2);

            LifeTimes_Max_Discharge_Current = Current() < LifeTimes_Max_Discharge_Current ? Current() : LifeTimes_Max_Discharge_Current;

            LTMax_I((uint8_t *)&_AverageCurrent, (uint8_t *)&LifeTimes_Max_Avg_Dsg_Current, (uint8_t *)&LtW_Cnt[11], 2);
            AvgDsgPwr = (int32_t)_AverageCurrent * Voltage() / 1000;
            LTMin_I((uint8_t *)&AvgDsgPwr, (uint8_t *)&LifeTimes_Max_Avg_Dsg_Power, (uint8_t *)&LtW_Cnt[12], 2);
        }
        // Temperature
        //  LTMax_I((uint8_t*)&Ts_max,(uint8_t*)&LifeTimes_Max_Temp_Cell,(uint8_t*)&LtW_Cnt[13],1);
        // LTMin_I((uint8_t*)&Ts_max,(uint8_t*)&LifeTimes_Min_Temp_Cell,(uint8_t*)&LtW_Cnt[14],1);

        //  LifeTimes_Min_Temp_Cell = 6000 ;
       // temp_maxin16 = (int8_t)(Ts_max);
        //temp_minin16 = (int8_t)(Ts_min);

        LifeTimes_Max_Temp_Cell = ((int8_t)Ts_max) < LifeTimes_Max_Temp_Cell ? LifeTimes_Max_Temp_Cell : ((int8_t)Ts_max);
        LifeTimes_Min_Temp_Cell = ((int8_t)Ts_min) > LifeTimes_Min_Temp_Cell ? LifeTimes_Min_Temp_Cell : ((int8_t)Ts_min);
         
       //Fettemp_maxin16= (int16_t)(FETTemp);
        LifeTimes_Max_Temp_MOS  = ((int8_t)FETTemp) < LifeTimes_Max_Temp_MOS  ? LifeTimes_Max_Temp_MOS  : ((int8_t)FETTemp);
        LifeTimes_Min_Temp_MOS = ((int8_t)FETTemp) > LifeTimes_Min_Temp_MOS ? LifeTimes_Min_Temp_MOS : ((int8_t)FETTemp);
        LifeTimes_Max_Temp_Fet =((int8_t)FETTemp) < LifeTimes_Max_Temp_Fet ? LifeTimes_Max_Temp_Fet : ((int8_t)FETTemp);
        LifeTimes_Max_Temp_Int_Sensor = ((t_com2c-2731)/10)< LifeTimes_Max_Temp_Int_Sensor ? LifeTimes_Max_Temp_Int_Sensor : ((t_com2c-2731)/10);
        LifeTimes_Min_Temp_Int_Sensor = ((t_com2c-2731)/10) > LifeTimes_Min_Temp_Int_Sensor ? LifeTimes_Min_Temp_Int_Sensor : ((t_com2c-2731)/10);


        // temp_maxint8 = Ts_max ;
        // temp_maxin16  = LifeTimes_Max_Temp_Cell ;
        // tempmax =  LifeTimes_Max_Temp_Cell ;

        // temp_minint8 = Ts_min ;
        // temp_minin16  = LifeTimes_Min_Temp_Cell ;
        // tempmin =  LifeTimes_Min_Temp_Cell ;

        LastTime_TS1 = _DAStatus2.CellTemperature;
        DeltaTS1 = ABS(LastTime_TS1 - _DAStatus2.CellTemperature);
        LastTime_TS2 = _DAStatus2.CellTemperature;
        DeltaTS2 = ABS(LastTime_TS2 - _DAStatus2.CellTemperature);
        MaxDeltaTS = DeltaTS1 > DeltaTS2 ? DeltaTS1 : DeltaTS2;

        LifeTimes_Max_Delta_Cell_Temp = MaxDeltaTS < LifeTimes_Max_Delta_Cell_Temp ? LifeTimes_Max_Delta_Cell_Temp : MaxDeltaTS;


}

static void LT_Status(void)
{
  LifeTimes_Safety_Alert_A = _SafetyAlert.value;
            LifeTimes_Safety_Status_A = _SafetyStatus.value;
            LifeTimes_Safety_Alert_B = _SafetyAlert.value >> 8;
            LifeTimes_Safety_Status_B = _SafetyStatus.value >> 8;
            LifeTimes_Safety_Alert_C = _SafetyAlert.value >> 16;
            LifeTimes_Safety_Status_C = _SafetyStatus.value >> 16;
            LifeTimes_Safety_Alert_D = _SafetyAlert.value >> 24;
            LifeTimes_Safety_Status_D = _SafetyStatus.value >> 24;

            LifeTimes_PF_Alert_A = _PFAlert.value;
            LifeTimes_PF_Status_A = _PFStatus.value;
            LifeTimes_PF_Alert_B = _PFAlert.value >> 8;
            LifeTimes_PF_Status_B = _PFStatus.value >> 8;
            LifeTimes_PF_Alert_C = _PFAlert.value >> 16;
            LifeTimes_PF_Status_C = _PFStatus.value >> 16;
            LifeTimes_PF_Alert_D = _PFAlert.value >> 24;
            LifeTimes_PF_Status_D = _PFStatus.value >> 24;

            //LifeTimes_Fuse_Flag = (((uint32_t)D_Permanent_Fail_Fuse_A) | ((uint32_t)D_Permanent_Fail_Fuse_B << 8) | ((uint32_t)D_Permanent_Fail_Fuse_C << 16) | ((uint32_t)D_Permanent_Fail_Fuse_D << 24));
            LifeTimes_Operation_Status_A = t_com54;
            LifeTimes_Operation_Status_B = t_com54 >> 16;
            LifeTimes_Temp_Range = nChargingStatus.data[1];
            LifeTimes_Charging_Status_A = nChargingStatus.data[2];
            LifeTimes_Charging_Status_B = nChargingStatus.data[3];
            LifeTimes_Gauging_Status = t_com56;
            LifeTimes_IT_Status = (uint16_t)(((t_com56 >> 16) & 0x000F) | (t_com56 & 0x00F0));
            // Device Voltage Data
            LifeTimes_Cell_1_Voltage = _DAStatus1.CellVoltage1;
            LifeTimes_Cell_2_Voltage = _DAStatus1.CellVoltage2;
            LifeTimes_Cell_3_Voltage = _DAStatus1.CellVoltage3;
            LifeTimes_Cell_4_Voltage = _DAStatus1.CellVoltage4;
            LifeTimes_Battery_Direct_Voltage = _DAStatus1.BatVoltage;
            LifeTimes_Pack_Voltage = _DAStatus1.PackVoltage;
            // Device Current Data
            LifeTimes_Current = _DAStatus1.CellCurrnet1;
            // Device Temperature Data
            LifeTimes_Internal_Temperature = _DAStatus2.IntTemperature;
            LifeTimes_External_1_Temperature = _DAStatus2.TS1Temperature;
            LifeTimes_External_2_Temperature = _DAStatus2.TS2Temperature;
            LifeTimes_External_3_Temperature = _DAStatus2.TS3Temperature;
            LifeTimes_External_4_Temperature = _DAStatus2.TS4Temperature;
}

void LifeTime(void)
{
    
    static uint8_t vtc_Flg=0;
    if (f_lt_init)
    {
        f_lt_init = 0;
        LT_Init();
    }
    if (f_LF_EN)
    {
        if (f_LT_TEST)
        {
            lt_test = 3600;
        }
        else
        {
            lt_test = 1;
        }

        Basic_LifeTime();
        lifetime_time_period();
        Lifetime_Static_A_status();
        Lifetime_Static_B_status();
        Lifetime_Static_C_status();
        Lifetime_Static_D_status();


        Lifetime_PF_A_status();
        Lifetime_PF_B_status();
        Lifetime_PF_C_status();
        Lifetime_PF_D_status();
        
        last_Status_Status = _SafetyStatus.value;
        last_PF_Status = _PFStatus.value;
       
        LT_Status();
        
        if (f_VCT)
        {
            if (!vtc_Flg)
            {
                LifeTimes_No_Valid_Charge_Term++;
                LifeTimes_Last_Valid_Charge_Term = _CycleCount;
            }
        }
        vtc_Flg = f_VCT;

        if (f_sleep)
        {
            LtW_CntW += SleepPeriod;
        }
        else
        {
            LtW_CntW += NormalPeriod;
        }

        if ((LtW_CntW / 1000) >= (LTW_DELAY / lt_test))
        {
            f_ltreqW = ON;
            f_ltreq = OFF;
            LtW_CntW = 0;
        }

        
    }
}

void lifetime_time_period(void)
{
      if (f_sleep)
        {
            rsoc_Cnt =SleepPeriod*lt_test;
        }
        else
        {
            rsoc_Cnt = NormalPeriod*lt_test;
        }
        //printf("rsoc_Cnt= %d\n",rsoc_Cnt);
       lifetime_ram._TotalFwRuntime += rsoc_Cnt;
       //printf("LifeTimes_Total_Firmware_Runtime = %d\n",LifeTimes_Total_Firmware_Runtime);
        switch (nChargingStatus.data[0])
        {
        case TR_UT:
        {
            if (t_com0d <= D_Lifetime_TimeRSOCThresholdA)
            {
                lifetime_ram._TimeSpentInUTRSOCA += rsoc_Cnt;
            }
            else if (t_com0d <= D_Lifetime_TimeRSOCThresholdB)
            {
                lifetime_ram._TimeSpentInUTRSOCB += rsoc_Cnt ;
            }
            else if (t_com0d <= D_Lifetime_TimeRSOCThresholdC)
            {
                lifetime_ram._TimeSpentInUTRSOCC += rsoc_Cnt;
            }
            else if (t_com0d <= D_Lifetime_TimeRSOCThresholdD)
            {
                lifetime_ram._TimeSpentInUTRSOCD += rsoc_Cnt ;
            }
            else if (t_com0d <= D_Lifetime_TimeRSOCThresholdE)
            {
                lifetime_ram._TimeSpentInUTRSOCE +=rsoc_Cnt ;
            }
            else if (t_com0d <= D_Lifetime_TimeRSOCThresholdF)
            {
                lifetime_ram._TimeSpentInUTRSOCF += rsoc_Cnt ;
            }
            else if (t_com0d <= D_Lifetime_TimeRSOCThresholdG)
            {
                lifetime_ram._TimeSpentInUTRSOCG += rsoc_Cnt ;
            }
            break;
            }
        case TR_LT:
            {
                if (t_com0d <= D_Lifetime_TimeRSOCThresholdA)
                {
                    lifetime_ram._TimeSpentInLTRSOCA += rsoc_Cnt ;
                }
                else if (t_com0d <= D_Lifetime_TimeRSOCThresholdB)
                {
                    lifetime_ram._TimeSpentInLTRSOCB += rsoc_Cnt ;
                }
                else if (t_com0d <= D_Lifetime_TimeRSOCThresholdC)
                {
                    lifetime_ram._TimeSpentInLTRSOCC += rsoc_Cnt ;
                }
                else if (t_com0d <= D_Lifetime_TimeRSOCThresholdD)
                {
                    lifetime_ram._TimeSpentInLTRSOCD += rsoc_Cnt;
                }
                else if (t_com0d <= D_Lifetime_TimeRSOCThresholdE)
                {
                    lifetime_ram._TimeSpentInLTRSOCE += rsoc_Cnt;
                }
                else if (t_com0d <= D_Lifetime_TimeRSOCThresholdF)
                {
                    lifetime_ram._TimeSpentInLTRSOCF  += rsoc_Cnt;
                }
                else if (t_com0d <= D_Lifetime_TimeRSOCThresholdG)
                {
                    lifetime_ram._TimeSpentInLTRSOCG  += rsoc_Cnt;
                }
            break;
        }
        case TR_STL:
             {
                 if (t_com0d <= D_Lifetime_TimeRSOCThresholdA)
                 {
                   lifetime_ram._TimeSpentInSTLRSOCA += rsoc_Cnt;
                 }
                 else if (t_com0d <= D_Lifetime_TimeRSOCThresholdB)
                 {
                    lifetime_ram._TimeSpentInSTLRSOCB += rsoc_Cnt;
                 }
                 else if (t_com0d <= D_Lifetime_TimeRSOCThresholdC)
                 {
                    lifetime_ram._TimeSpentInSTLRSOCC += rsoc_Cnt;
                 }
                 else if (t_com0d <= D_Lifetime_TimeRSOCThresholdD)
                 {
                    lifetime_ram._TimeSpentInSTLRSOCD += rsoc_Cnt;
                 }
                 else if (t_com0d <= D_Lifetime_TimeRSOCThresholdE)
                 {
                    lifetime_ram._TimeSpentInSTLRSOCE += rsoc_Cnt;
                 }
                 else if (t_com0d <= D_Lifetime_TimeRSOCThresholdF)
                 {
                    lifetime_ram._TimeSpentInSTLRSOCF+= rsoc_Cnt;
                 }
                 else if (t_com0d <= D_Lifetime_TimeRSOCThresholdG)
                 {
                    lifetime_ram._TimeSpentInSTLRSOCG += rsoc_Cnt;
                 }
            break;
        }
        case TR_RT:
              {
                  if (t_com0d <= D_Lifetime_TimeRSOCThresholdA)
                  {
                    lifetime_ram._TimeSpentInRTRSOCA += rsoc_Cnt;
                  }
                  else if (t_com0d <= D_Lifetime_TimeRSOCThresholdB)
                  {
                    lifetime_ram._TimeSpentInRTRSOCB += rsoc_Cnt;
                  }
                  else if (t_com0d <= D_Lifetime_TimeRSOCThresholdC)
                  {
                    lifetime_ram._TimeSpentInRTRSOCC += rsoc_Cnt;
                  }
                  else if (t_com0d <= D_Lifetime_TimeRSOCThresholdD)
                  {
                     lifetime_ram._TimeSpentInRTRSOCD += rsoc_Cnt;
                  }
                  else if (t_com0d <= D_Lifetime_TimeRSOCThresholdE)
                  {
                    lifetime_ram._TimeSpentInRTRSOCE += rsoc_Cnt;
                  }
                  else if (t_com0d <= D_Lifetime_TimeRSOCThresholdF)
                  {
                     lifetime_ram._TimeSpentInRTRSOCF += rsoc_Cnt;
                  }
                  else if (t_com0d <= D_Lifetime_TimeRSOCThresholdG)
                  {
                    lifetime_ram._TimeSpentInRTRSOCG += rsoc_Cnt;
                  }
            break;
        }
        case TR_STH:
              {
                  if (t_com0d <= D_Lifetime_TimeRSOCThresholdA)
                  {
                    lifetime_ram._TimeSpentInSTHRSOCA += rsoc_Cnt;
                  }
                  else if (t_com0d <= D_Lifetime_TimeRSOCThresholdB)
                  {
                    lifetime_ram._TimeSpentInSTHRSOCB += rsoc_Cnt;
                  }
                  else if (t_com0d <= D_Lifetime_TimeRSOCThresholdC)
                  {
                     lifetime_ram._TimeSpentInSTHRSOCC += rsoc_Cnt;
                  }
                  else if (t_com0d <= D_Lifetime_TimeRSOCThresholdD)
                  {
                    lifetime_ram._TimeSpentInSTHRSOCD += rsoc_Cnt;
                  }
                  else if (t_com0d <= D_Lifetime_TimeRSOCThresholdE)
                  {
                    lifetime_ram._TimeSpentInSTHRSOCE += rsoc_Cnt;
                  }
                  else if (t_com0d <= D_Lifetime_TimeRSOCThresholdF)
                  {
                     lifetime_ram._TimeSpentInSTHRSOCF += rsoc_Cnt;
                  }
                  else if (t_com0d <= D_Lifetime_TimeRSOCThresholdG)
                  {
                    lifetime_ram._TimeSpentInSTHRSOCG += rsoc_Cnt;
                  }
            break;
        }
            
        case TR_HT:
              {
                  if (t_com0d <= D_Lifetime_TimeRSOCThresholdA)
                  {
                    lifetime_ram._TimeSpentInHTRSOCA += rsoc_Cnt;
                  }
                  else if (t_com0d <= D_Lifetime_TimeRSOCThresholdB)
                  {
                      lifetime_ram._TimeSpentInHTRSOCB += rsoc_Cnt;
                  }
                  else if (t_com0d <= D_Lifetime_TimeRSOCThresholdC)
                  {
                    lifetime_ram._TimeSpentInHTRSOCC  += rsoc_Cnt;
                  }
                  else if (t_com0d <= D_Lifetime_TimeRSOCThresholdD)
                  {
                     lifetime_ram._TimeSpentInHTRSOCD  += rsoc_Cnt;
                  }
                  else if (t_com0d <= D_Lifetime_TimeRSOCThresholdE)
                  {
                     lifetime_ram._TimeSpentInHTRSOCE  += rsoc_Cnt;
                  }
                  else if (t_com0d <= D_Lifetime_TimeRSOCThresholdF)
                  {
                     lifetime_ram._TimeSpentInHTRSOCF  += rsoc_Cnt;
                  }
                  else if (t_com0d <= D_Lifetime_TimeRSOCThresholdG)
                  {
                     lifetime_ram._TimeSpentInHTRSOCG += rsoc_Cnt;
                  }
            break;
        }
        case TR_OT:
               {
                   if (t_com0d <= D_Lifetime_TimeRSOCThresholdA)
                   {
                      lifetime_ram._TimeSpentInOTRSOCA+= rsoc_Cnt;
                   }
                   else if (t_com0d <= D_Lifetime_TimeRSOCThresholdB)
                   {
                       lifetime_ram._TimeSpentInOTRSOCB += rsoc_Cnt;
                   }
                   else if (t_com0d <= D_Lifetime_TimeRSOCThresholdC)
                   {
                      lifetime_ram._TimeSpentInOTRSOCC += rsoc_Cnt;
                   }
                   else if (t_com0d <= D_Lifetime_TimeRSOCThresholdD)
                   {
                       lifetime_ram._TimeSpentInOTRSOCD += rsoc_Cnt;
                   }
                   else if (t_com0d <= D_Lifetime_TimeRSOCThresholdE)
                   {
                       lifetime_ram._TimeSpentInOTRSOCE+= rsoc_Cnt;
                   }
                   else if (t_com0d <= D_Lifetime_TimeRSOCThresholdF)
                   {
                       lifetime_ram._TimeSpentInOTRSOCF += rsoc_Cnt;
                   }
                   else if (t_com0d <= D_Lifetime_TimeRSOCThresholdG)
                   {
                       lifetime_ram._TimeSpentInOTRSOCG += rsoc_Cnt;
                   }
            break;
        }
        default:
            break;
        }

}


void lifetime_time_store(void)
{
   LifeTimes_Total_Firmware_Runtime += (lifetime_ram._TotalFwRuntime/ TIME_TO_HOUR);

   LifeTimes_Time_Spent_in_UT_RSOC_A += (lifetime_ram._TimeSpentInUTRSOCA/TIME_TO_HOUR);
   LifeTimes_Time_Spent_in_UT_RSOC_B += (lifetime_ram._TimeSpentInUTRSOCB/TIME_TO_HOUR);
   LifeTimes_Time_Spent_in_UT_RSOC_C += (lifetime_ram._TimeSpentInUTRSOCC/TIME_TO_HOUR);
    LifeTimes_Time_Spent_in_UT_RSOC_D += (lifetime_ram._TimeSpentInUTRSOCD/TIME_TO_HOUR);
    LifeTimes_Time_Spent_in_UT_RSOC_E += (lifetime_ram._TimeSpentInUTRSOCE/TIME_TO_HOUR);
    LifeTimes_Time_Spent_in_UT_RSOC_F += (lifetime_ram._TimeSpentInUTRSOCF/TIME_TO_HOUR);
    LifeTimes_Time_Spent_in_UT_RSOC_G += (lifetime_ram._TimeSpentInUTRSOCG/TIME_TO_HOUR);

    LifeTimes_Time_Spent_in_LT_RSOC_A += (lifetime_ram._TimeSpentInLTRSOCA/TIME_TO_HOUR);
    LifeTimes_Time_Spent_in_LT_RSOC_B += (lifetime_ram._TimeSpentInLTRSOCB/TIME_TO_HOUR);
    LifeTimes_Time_Spent_in_LT_RSOC_C += (lifetime_ram._TimeSpentInLTRSOCC/TIME_TO_HOUR);
    LifeTimes_Time_Spent_in_LT_RSOC_D += (lifetime_ram._TimeSpentInLTRSOCD/TIME_TO_HOUR);
    LifeTimes_Time_Spent_in_LT_RSOC_E += (lifetime_ram._TimeSpentInLTRSOCE/TIME_TO_HOUR);
    LifeTimes_Time_Spent_in_LT_RSOC_F += (lifetime_ram._TimeSpentInLTRSOCF/TIME_TO_HOUR);
    LifeTimes_Time_Spent_in_LT_RSOC_G += (lifetime_ram._TimeSpentInLTRSOCG/TIME_TO_HOUR);

    LifeTimes_Time_Spent_in_STL_RSOC_A += (lifetime_ram._TimeSpentInSTLRSOCA/TIME_TO_HOUR);
    LifeTimes_Time_Spent_in_STL_RSOC_B += (lifetime_ram._TimeSpentInSTLRSOCB/TIME_TO_HOUR);
    LifeTimes_Time_Spent_in_STL_RSOC_C += (lifetime_ram._TimeSpentInSTLRSOCC/TIME_TO_HOUR);
    LifeTimes_Time_Spent_in_STL_RSOC_D += (lifetime_ram._TimeSpentInSTLRSOCD/TIME_TO_HOUR);
    LifeTimes_Time_Spent_in_STL_RSOC_E += (lifetime_ram._TimeSpentInSTLRSOCE/TIME_TO_HOUR);
    LifeTimes_Time_Spent_in_STL_RSOC_F += (lifetime_ram._TimeSpentInSTLRSOCF/TIME_TO_HOUR);
    LifeTimes_Time_Spent_in_STL_RSOC_G += (lifetime_ram._TimeSpentInSTLRSOCG/TIME_TO_HOUR);

    LifeTimes_Time_Spent_in_RT_RSOC_A += (lifetime_ram._TimeSpentInRTRSOCA/TIME_TO_HOUR);
    LifeTimes_Time_Spent_in_RT_RSOC_B += (lifetime_ram._TimeSpentInRTRSOCB/TIME_TO_HOUR);
    LifeTimes_Time_Spent_in_RT_RSOC_C += (lifetime_ram._TimeSpentInRTRSOCC/TIME_TO_HOUR);
    LifeTimes_Time_Spent_in_RT_RSOC_D += (lifetime_ram._TimeSpentInRTRSOCD/TIME_TO_HOUR);
    LifeTimes_Time_Spent_in_RT_RSOC_E += (lifetime_ram._TimeSpentInRTRSOCE/TIME_TO_HOUR);
    LifeTimes_Time_Spent_in_RT_RSOC_F += (lifetime_ram._TimeSpentInRTRSOCF/TIME_TO_HOUR);
    LifeTimes_Time_Spent_in_RT_RSOC_G += (lifetime_ram._TimeSpentInRTRSOCG/TIME_TO_HOUR);

    LifeTimes_Time_Spent_in_STH_RSOC_A += (lifetime_ram._TimeSpentInSTHRSOCA/TIME_TO_HOUR);
    LifeTimes_Time_Spent_in_STH_RSOC_B += (lifetime_ram._TimeSpentInSTHRSOCB/TIME_TO_HOUR);
    LifeTimes_Time_Spent_in_STH_RSOC_C += (lifetime_ram._TimeSpentInSTHRSOCC/TIME_TO_HOUR);
    LifeTimes_Time_Spent_in_STH_RSOC_D += (lifetime_ram._TimeSpentInSTHRSOCD/TIME_TO_HOUR);
    LifeTimes_Time_Spent_in_STH_RSOC_E += (lifetime_ram._TimeSpentInSTHRSOCE/TIME_TO_HOUR);
    LifeTimes_Time_Spent_in_STH_RSOC_F += (lifetime_ram._TimeSpentInSTHRSOCF/TIME_TO_HOUR);
    LifeTimes_Time_Spent_in_STH_RSOC_G += (lifetime_ram._TimeSpentInSTHRSOCG/TIME_TO_HOUR);

    LifeTimes_Time_Spent_in_HT_RSOC_A += (lifetime_ram._TimeSpentInHTRSOCA/TIME_TO_HOUR);
    LifeTimes_Time_Spent_in_HT_RSOC_B += (lifetime_ram._TimeSpentInHTRSOCB/TIME_TO_HOUR);
    LifeTimes_Time_Spent_in_HT_RSOC_C += (lifetime_ram._TimeSpentInHTRSOCC/TIME_TO_HOUR);
    LifeTimes_Time_Spent_in_HT_RSOC_D += (lifetime_ram._TimeSpentInHTRSOCD/TIME_TO_HOUR);
    LifeTimes_Time_Spent_in_HT_RSOC_E += (lifetime_ram._TimeSpentInHTRSOCE/TIME_TO_HOUR);
    LifeTimes_Time_Spent_in_HT_RSOC_F += (lifetime_ram._TimeSpentInHTRSOCF/TIME_TO_HOUR);
    LifeTimes_Time_Spent_in_HT_RSOC_G += (lifetime_ram._TimeSpentInHTRSOCG/TIME_TO_HOUR);

    LifeTimes_Time_Spent_in_OT_RSOC_A += (lifetime_ram._TimeSpentInOTRSOCA/TIME_TO_HOUR);
    LifeTimes_Time_Spent_in_OT_RSOC_B += (lifetime_ram._TimeSpentInOTRSOCB/TIME_TO_HOUR);
    LifeTimes_Time_Spent_in_OT_RSOC_C += (lifetime_ram._TimeSpentInOTRSOCC/TIME_TO_HOUR);
    LifeTimes_Time_Spent_in_OT_RSOC_D += (lifetime_ram._TimeSpentInOTRSOCD/TIME_TO_HOUR);
    LifeTimes_Time_Spent_in_OT_RSOC_E += (lifetime_ram._TimeSpentInOTRSOCE/TIME_TO_HOUR);
    LifeTimes_Time_Spent_in_OT_RSOC_F += (lifetime_ram._TimeSpentInOTRSOCF/TIME_TO_HOUR);
    LifeTimes_Time_Spent_in_OT_RSOC_G += (lifetime_ram._TimeSpentInOTRSOCG/TIME_TO_HOUR);

   
}



void lifetime_time_clear(void)
{
    lifetime_ram._TotalFwRuntime = 0;
    /* UT */
    lifetime_ram._TimeSpentInUTRSOCA = 0;
    lifetime_ram._TimeSpentInUTRSOCB = 0;
    lifetime_ram._TimeSpentInUTRSOCC = 0;
    lifetime_ram._TimeSpentInUTRSOCD = 0;
    lifetime_ram._TimeSpentInUTRSOCE = 0;
    lifetime_ram._TimeSpentInUTRSOCF = 0;
    lifetime_ram._TimeSpentInUTRSOCG = 0;
    

    /* LT */
    lifetime_ram._TimeSpentInLTRSOCA = 0;
    lifetime_ram._TimeSpentInLTRSOCB = 0;
    lifetime_ram._TimeSpentInLTRSOCC = 0;
    lifetime_ram._TimeSpentInLTRSOCD = 0;
    lifetime_ram._TimeSpentInLTRSOCE = 0;
    lifetime_ram._TimeSpentInLTRSOCF = 0;
    lifetime_ram._TimeSpentInLTRSOCG = 0;
   
    /* STL */
    lifetime_ram._TimeSpentInSTLRSOCA = 0;
    lifetime_ram._TimeSpentInSTLRSOCB = 0;
    lifetime_ram._TimeSpentInSTLRSOCC = 0;
    lifetime_ram._TimeSpentInSTLRSOCD = 0;
    lifetime_ram._TimeSpentInSTLRSOCE = 0;
    lifetime_ram._TimeSpentInSTLRSOCF = 0;
    lifetime_ram._TimeSpentInSTLRSOCG = 0;
  

    /* RT */
    lifetime_ram._TimeSpentInRTRSOCA = 0;
    lifetime_ram._TimeSpentInRTRSOCB = 0;
    lifetime_ram._TimeSpentInRTRSOCC = 0;
    lifetime_ram._TimeSpentInRTRSOCD = 0;
    lifetime_ram._TimeSpentInRTRSOCE = 0;
    lifetime_ram._TimeSpentInRTRSOCF = 0;
    lifetime_ram._TimeSpentInRTRSOCG = 0;
    

    /* STH */
    lifetime_ram._TimeSpentInSTHRSOCA = 0;
    lifetime_ram._TimeSpentInSTHRSOCB = 0;
    lifetime_ram._TimeSpentInSTHRSOCC = 0;
    lifetime_ram._TimeSpentInSTHRSOCD = 0;
    lifetime_ram._TimeSpentInSTHRSOCE = 0;
    lifetime_ram._TimeSpentInSTHRSOCF = 0;
    lifetime_ram._TimeSpentInSTHRSOCG = 0;
    

    /* HT */
    lifetime_ram._TimeSpentInHTRSOCA = 0;
    lifetime_ram._TimeSpentInHTRSOCB = 0;
    lifetime_ram._TimeSpentInHTRSOCC = 0;
    lifetime_ram._TimeSpentInHTRSOCD = 0;
    lifetime_ram._TimeSpentInHTRSOCE = 0;
    lifetime_ram._TimeSpentInHTRSOCF = 0;
    lifetime_ram._TimeSpentInHTRSOCG = 0;
   

    /* OT */
    lifetime_ram._TimeSpentInOTRSOCA = 0;
    lifetime_ram._TimeSpentInOTRSOCB = 0;
    lifetime_ram._TimeSpentInOTRSOCC = 0;
    lifetime_ram._TimeSpentInOTRSOCD = 0;
    lifetime_ram._TimeSpentInOTRSOCE = 0;
    lifetime_ram._TimeSpentInOTRSOCF = 0;
    lifetime_ram._TimeSpentInOTRSOCG = 0;

   
   
}

void lt_banlance(void)
{
    LifeTimes_CB_Time_Cell_1 += (lifetime_ram.cb_time_cell[0]/TIME_TO_HOUR);
    LifeTimes_CB_Time_Cell_2 += (lifetime_ram.cb_time_cell[1]/TIME_TO_HOUR);
    LifeTimes_CB_Time_Cell_3 += (lifetime_ram.cb_time_cell[2]/TIME_TO_HOUR);
    LifeTimes_CB_Time_Cell_4 += (lifetime_ram.cb_time_cell[3]/TIME_TO_HOUR);
    memset(lifetime_ram.cb_time_cell, 0, sizeof(lifetime_ram.cb_time_cell));
}



uint8_t lifetime_Writer()
{
    uint8_t ret;
     ret = fmc_write_flash((uint32_t)LF_BLOCK_A - FMC_DATA_FLASH_BASE_ADDR, (uint8_t *)&l_lifetimes,
                              sizeof(LifeTimes));
    return ret;
}




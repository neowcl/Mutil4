#include "hdp.h"

#include "hmac.h"
uint16_t amodeflag;
volatile uint32_t prehiegdelay = 0;
volatile uint32_t prelowdelay = 0;

volatile AFE_HDP_SETTING afe_hdp_setting = {.enable_flag = 0x3C};

void Hdp_Init(void)
{
    uint16_t aoldtime,aoldthreshold;
    hdp_change = 0;
    if (hdp_RSNS != D_AFE_Protection_Control_RSNS)
    {
        hdp_RSNS = D_AFE_Protection_Control_RSNS;
        hdp_change = 1;
    }
    if (hdp_SCDDx2 != D_AFE_Protection_Control_SCDDx2)
    {
        hdp_SCDDx2 = D_AFE_Protection_Control_SCDDx2;
        hdp_change = 1;
    }
    if (hdp_aold_en != D_Enabled_Protections_A_AOLD)
    {
        hdp_aold_en = D_Enabled_Protections_A_AOLD;
        hdp_change = 1;
    }
    if (hdp_ascc_en != D_Enabled_Protections_B_ASCC)
    {
        hdp_ascc_en = D_Enabled_Protections_B_ASCC;
        hdp_change = 1;
    }
    if (hdp_ascd_en != D_Enabled_Protections_B_ASCD)
    {
        hdp_ascd_en = D_Enabled_Protections_B_ASCD;
        hdp_change = 1;
    }

    if (hdp_aold_threshold != D_AOLD_Threshold)
    {
        hdp_aold_threshold = D_AOLD_Threshold;
        hdp_change = 1;
    }
    if (hdp_ascc_threshold != D_ASCC_Threshold)
    {
        hdp_ascc_threshold = D_ASCC_Threshold;
        hdp_change = 1;
    }
    if (hdp_ascd1_threshold != D_ASCD_Threshold1)
    {
        hdp_ascd1_threshold = D_ASCD_Threshold1;
        hdp_change = 1;
    }
    if (hdp_ascd2_threshold != D_ASCD_Threshold2)
    {
        hdp_ascd2_threshold = D_ASCD_Threshold2;
        hdp_change = 1;
    }
    if(hdp_change == 0)
    {
        return;
    }
    if (hdp_RSNS)
    { 
        if (hdp_SCDDx2)
        {
            // printf("RSNS = 1 SCDDx2 = 1\n");
            afe_hdp_hardware_protect_config(HDP_DOUBLE_SCD_DELAY_TIME, HDP_SAMPING_RES_2MOHM);
        }
        else
        {
            // printf("RSNS = 1  SCDDx2 = 0\n");
            afe_hdp_hardware_protect_config(HDP_NORMAL_SCD_DELAY_TIME, HDP_SAMPING_RES_2MOHM);
        }
    }
    else
    {
        if (hdp_SCDDx2)
        {
			// printf("RSNS = 0 SCDDx2 = 1\n");
            afe_hdp_hardware_protect_config(HDP_DOUBLE_SCD_DELAY_TIME, HDP_SAMPING_RES_1MOHM);
        }
        else
        {
			// printf("RSNS = 0 SCDDx2 = 0\n");
            afe_hdp_hardware_protect_config(HDP_NORMAL_SCD_DELAY_TIME, HDP_SAMPING_RES_1MOHM);
        }
    }

    if (hdp_aold_en)
    {
        afe_int_periph_int_enable_ctrl(INT_IE0_AOLD_INT, ENABLE);
        afe_rcc_periph_clock_enable_ctrl(RCC_PERI_HDPF_CLOCK, ENABLE);
        /* enable hardware protect comparator main switch. */
        afe_hdp_hardware_protect_enable_ctrl(ENABLE);

        while (!afe_hdp_discharge_overload_enable_ctrl(DISABLE))
            ;
        /* config aold delay time and overlaod value */
        afe_hdp_discharge_overload_config(hdp_aold_threshold >> 4, hdp_aold_threshold & 0x0F);
        /* enable aold comparator. */
        afe_hdp_discharge_overload_enable_ctrl(ENABLE);
    }
    else
    {
        afe_hdp_discharge_overload_enable_ctrl(DISABLE);
    }
    if (hdp_ascc_en)
    {
        afe_int_periph_int_enable_ctrl(INT_IE0_ASCC_INT, ENABLE);
        afe_rcc_periph_clock_enable_ctrl(RCC_PERI_HDPF_CLOCK, ENABLE);
        /* enable hardware protect comparator main switch. */
        afe_hdp_hardware_protect_enable_ctrl(ENABLE);

        while (!afe_hdp_charging_short_enable_ctrl(DISABLE))
            ;
        /* config ascc delay time and overlaod value */
        afe_hdp_charging_short_config(hdp_ascc_threshold >> 4, hdp_ascc_threshold & 0x07);
        /* enable ascc comparator. */
        afe_hdp_charging_short_enable_ctrl(ENABLE);
    }
    else
    {
        afe_hdp_charging_short_enable_ctrl(DISABLE);
    }

    if (hdp_ascd_en)
    {
        afe_int_periph_int_enable_ctrl(INT_IE0_ASCD1_INT | INT_IE0_ASCD2_INT, ENABLE);
        afe_rcc_periph_clock_enable_ctrl(RCC_PERI_HDPF_CLOCK, ENABLE);
        /* enable hardware protect comparator main switch. */
        afe_hdp_hardware_protect_enable_ctrl(ENABLE);

        while (!afe_hdp_discharge_short_1_enable_ctrl(DISABLE))
            ;
        /* config ascc delay time and overlaod value */
        afe_hdp_discharge_short_1_config(hdp_ascd1_threshold >> 4, hdp_ascd1_threshold & 0x07);
        afe_hdp_discharge_short_1_enable_ctrl(ENABLE);
        while (!afe_hdp_discharge_short_2_enable_ctrl(DISABLE))
            ;
        /* config ascc delay time and overlaod value */
        afe_hdp_discharge_short_2_config(hdp_ascd2_threshold >> 4, hdp_ascd2_threshold & 0x07);
        afe_hdp_discharge_short_2_enable_ctrl(ENABLE);
    }
    else
    {
        afe_hdp_discharge_short_1_enable_ctrl(DISABLE);
        afe_hdp_discharge_short_2_enable_ctrl(DISABLE);
    }
    /**********************AOLD******************************************
     * Setting  |  Threshold | Current  | Standard Res|
     * -----------------------------------------------------------------
     *  0x00    |   -8.30mV  | -8300mA   |    1mR      |
     * ------------------------------------------------------------------
     *  0x01    |   -11.8mV  | -11800mA  |    1mR      |
     * -----------------------------------------------------------------
     *  0x02    |   -13.86mV | -13860mA  |    1mR      |
     * ------------------------------------------------------------------
     *  0x03    |   -16.64mV | -16640mA  |    1mR      |
     * -----------------------------------------------------------------
     *  0x04    |   -19.42mV | -16640mA  |    1mR      |
     * -----------------------------------------------------------------
     *  0x05    |   -22.2mV  | -22200mA  |    1mR      |
     * ------------------------------------------------------------------
     *  0x06    |   -24.98mV | -24980mA  |    1mR      |
     * -----------------------------------------------------------------
     *  0x07    |   -27.76mV | -27760mA  |    1mR      |
     * ------------------------------------------------------------------
     *  0x08    |   -30.54mV | -30540mA  |    1mR      |
     * -----------------------------------------------------------------
     *  0x09    |   -33.32mV | -33320mV  |    1mR      |
     * ------------------------------------------------------------------
     *  0x0a    |   -36.10mV | -36100mA  |    1mR      |
     * -----------------------------------------------------------------
     *  0x0b    |   -38.88mV | -38880mA  |    1mR      |
     * ------------------------------------------------------------------
     *  0x0c    |   -41.66mV | -41660mA  |    1mR      |
     * -----------------------------------------------------------------
     *  0x0d    |   -44.44mV | -44440mA  |    1mR      |
     * ------------------------------------------------------------------
     *  0x0e    |   -47.22mV | -47220mA  |    1mR      |
     * -----------------------------------------------------------------
     *  0x0f    |   -50.00mV | -50000mA  |    1mR      |
     * ----------------------------------------------------------------
     ******************************************************************/
    /**********************AOLD Delay***********************************
     * Setting  |   Delay    |
     * -----------------------
     *  0x00    |   0.977mS  |
     * -----------------------
     *  0x01    |   2.93mS   |
     * -----------------------
     *  0x02    |   4.883mS  |
     * -----------------------
     *  0x03    |   6.836mS  |
     * -----------------------
     *  0x04    |   8.789mS  |
     * -----------------------
     *  0x05    |   10.742mS |
     * -----------------------
     *  0x06    |   12.695mS |
     * -----------------------
     *  0x07    |   14.648mS |
     * -----------------------
     *  0x08    |   16.602mS |
     * -----------------------
     *  0x09    |   18.555mS |
     * -----------------------
     *  0x0a    |   20.508mS |
     * -----------------------
     *  0x0b    |   22.461mS |
     * -----------------------
     *  0x0c    |   24.414mS |
     * -----------------------
     *  0x0d    |   26.367mS |
     * -----------------------
     *  0x0e    |   28.320mS |
     * -----------------------
     *  0x0f    |   30.273mS |
     * -----------------------
     *******************************************************************/
    /**********************ASCC******************************************
     * Setting  |  Threshold | Current   | Standard Res|
     * -----------------------------------------------------------------
     *  0x00    |   -22.2mV  | -22200mA   |    1mR      |
     * ------------------------------------------------------------------
     *  0x01    |   -33.3mV  | -33300mA   |    1mR      |
     * -----------------------------------------------------------------
     *  0x02    |   -44.4mV  | -44400mA   |    1mR      |
     * ------------------------------------------------------------------
     *  0x03    |   -55.5mV  | -55500mA   |    1mR      |
     * -----------------------------------------------------------------
     *  0x04    |   -66.65mV | -66650mA   |    1mR      |
     * -----------------------------------------------------------------
     *  0x05    |   -77.75mV | -77750mA   |    1mR      |
     * ------------------------------------------------------------------
     *  0x06    |   -88.85mV | -88850mA   |    1mR      |
     * -----------------------------------------------------------------
     *  0x07    |   -100mV   | -100000mA  |    1mR      |
     * ------------------------------------------------------------------
     *******************************************************************/
    /**********************ASCC Delay***********************************
     * Setting  |   Delay    |
     * -----------------------
     *  0x00    |   0uS      |
     * -----------------------
     *  0x01    |   61.04uS  |
     * -----------------------
     *  0x02    |   122.07uS |
     * -----------------------
     *  0x03    |   183.11uS |
     * -----------------------
     *  0x04    |   244.14uS |
     * -----------------------
     *  0x05    |   305.18uS |
     * -----------------------
     *  0x06    |   366.21uS |
     * -----------------------
     *  0x07    |   427.25uS |
     * -----------------------
     *  0x08    |   488.28uS |
     * -----------------------
     *  0x09    |   549.32uS |
     * -----------------------
     *  0x0a    |   610.35uS |
     * -----------------------
     *  0x0b    |   671.39uS |
     * -----------------------
     *  0x0c    |   732.42uS |
     * -----------------------
     *  0x0d    |   793.46uS |
     * -----------------------
     *  0x0e    |   854.49uS |
     * -----------------------
     *  0x0f    |   915.53uS |
     * -----------------------
     *******************************************************************/
    /**********************ASCD1******************************************
     * Setting  |  Threshold | Current   | Standard Res|
     * -----------------------------------------------------------------
     *  0x00    |   -22.2mV  | -22200mA   |    1mR      |
     * ------------------------------------------------------------------
     *  0x01    |   -33.3mV  | -33300mA   |    1mR      |
     * -----------------------------------------------------------------
     *  0x02    |   -44.4mV  | -44400mA   |    1mR      |
     * ------------------------------------------------------------------
     *  0x03    |   -55.5mV  | -55500mA   |    1mR      |
     * -----------------------------------------------------------------
     *  0x04    |   -66.65mV | -66650mA   |    1mR      |
     * -----------------------------------------------------------------
     *  0x05    |   -77.75mV | -7775mA   |    1mR      |
     * ------------------------------------------------------------------
     *  0x06    |   -88.85mV | -88850mA   |    1mR      |
     * -----------------------------------------------------------------
     *  0x07    |   -100mV   | -100000mA  |    1mR      |
     * ------------------------------------------------------------------
     *******************************************************************/
    /**********************ASCD1 Delay***********************************
     * Setting  |   Delay    |
     * -----------------------
     *  0x00    |   0uS      |
     * -----------------------
     *  0x01    |   61.04uS  |
     * -----------------------
     *  0x02    |   122.07uS |
     * -----------------------
     *  0x03    |   183.11uS |
     * -----------------------
     *  0x04    |   244.14uS |
     * -----------------------
     *  0x05    |   305.18uS |
     * -----------------------
     *  0x06    |   366.21uS |
     * -----------------------
     *  0x07    |   427.25uS |
     * -----------------------
     *  0x08    |   488.28uS |
     * -----------------------
     *  0x09    |   549.32uS |
     * -----------------------
     *  0x0a    |   610.35uS |
     * -----------------------
     *  0x0b    |   671.39uS |
     * -----------------------
     *  0x0c    |   732.42uS |
     * -----------------------
     *  0x0d    |   793.46uS |
     * -----------------------
     *  0x0e    |   854.49uS |
     * -----------------------
     *  0x0f    |   915.53uS |
     * -----------------------
     *******************************************************************/
    /**********************ASCD2******************************************
     * Setting  |  Threshold | Current   | Standard Res|
     * -----------------------------------------------------------------
     *  0x00    |   -22.2mV  | -22200mA   |    1mR      |
     * ------------------------------------------------------------------
     *  0x01    |   -33.3mV  | -33300mA   |    1mR      |
     * -----------------------------------------------------------------
     *  0x02    |   -44.4mV  | -44400mA   |    1mR      |
     * ------------------------------------------------------------------
     *  0x03    |   -55.5mV  | -55500mA   |    1mR      |
     * -----------------------------------------------------------------
     *  0x04    |   -66.65mV | -66650mA   |    1mR      |
     * -----------------------------------------------------------------
     *  0x05    |   -77.75mV | -7775mA    |    1mR      |
     * ------------------------------------------------------------------
     *  0x06    |   -88.85mV | -88850mA   |    1mR      |
     * -----------------------------------------------------------------
     *  0x07    |   -100mV   | -100000mA  |    1mR      |
     * ------------------------------------------------------------------
     *******************************************************************/
    /**********************ASCD2 Delay***********************************
     * Setting  |   Delay    |
     * -----------------------
     *  0x00    |   0uS      |
     * -----------------------
     *  0x01    |   30.52uS  |
     * -----------------------
     *  0x02    |   61.03uS  |
     * -----------------------
     *  0x03    |   91.55uS  |
     * -----------------------
     *  0x04    |   122.07uS |
     * -----------------------
     *  0x05    |   152.59uS |
     * -----------------------
     *  0x06    |   183.10uS |
     * -----------------------
     *  0x07    |   213.62uS |
     * -----------------------
     *  0x08    |   244.14uS |
     * -----------------------
     *  0x09    |   275.46uS |
     * -----------------------
     *  0x0a    |   305.18uS |
     * -----------------------
     *  0x0b    |   335.69uS |
     * -----------------------
     *  0x0c    |   366.21uS |
     * -----------------------
     *  0x0d    |   396.73uS |
     * -----------------------
     *  0x0e    |   427.25uS |
     * -----------------------
     *  0x0f    |   457.76uS |
     * -----------------------
     *******************************************************************/
}

void Hdp_ClearStatus(uint16_t flag)
{
    afe_int_periph_int_flag_clear(flag);
}
void Mos_init()
{
    afe_rcc_periph_clock_enable_ctrl(RCC_PERI_CDDRV_CLOCK, ENABLE);
    /* enable chg/dsg mos driver. */
    afe_cddrv_chgdsg_mos_enable_ctrl(ENABLE);
    /* enable discharge. */
    afe_cddrv_discharge_enable_ctrl(ENABLE);
    /* enable chg/dsg mos driver. */
    afe_cddrv_chgdsg_mos_enable_ctrl(ENABLE);
    /* enable charge. */
    afe_cddrv_charge_enable_ctrl(ENABLE);
}

void WakeUp_Ctrl(uint8_t status)
{
    /* config wkcp threshold and filtering time. */
    switch((D_Wake_Comparator_WK1 << 1) + D_Wake_Comparator_WK0)
    {
        case 0:
        {
            afe_wkcp_comparator_config(WKCP_THRESHOLD_0P625MV, WKCP_FILTERING_TIME_122P07US);
            break;
        }
        case 1:
        {
            afe_wkcp_comparator_config(WKCP_THRESHOLD_1P25MV, WKCP_FILTERING_TIME_122P07US);
            break;
        }
        case 2:
        {
            afe_wkcp_comparator_config(WKCP_THRESHOLD_2P5MV, WKCP_FILTERING_TIME_122P07US);
            break;
        }
        case 3:
        {
            afe_wkcp_comparator_config(WKCP_THRESHOLD_5MV, WKCP_FILTERING_TIME_122P07US);
            break;
        }
    }
    afe_int_periph_int_enable_ctrl(INT_IE0_WKCP_INT, status);
    afe_wkcp_comparator_enable_ctrl(status);
}
void WakeCp_init(void)
{
    /* enable hdf,wkcp,cddrv clock. */
    afe_rcc_periph_clock_enable_ctrl(RCC_PERI_WKCPF_CLOCK, ENABLE);

    /* config int mode: pulse trigger. */
    afe_int_mode_config(INT_IMD_PULSE_INTMODE);
    WakeUp_Ctrl(ENABLE);
}

void MCU_FWDG_init(void)
{
    /* Counter Reload Value = T * (LRC/div) */
    uint16_t fwdt_reload = 60 * 10000 / 256;//3100
    //logInfo("fwdt_reload = %d\n", fwdt_reload);
    /* Enable write access. */
	__FWDT_WRITE_ACCESS_ENABLE();  
    /* Config prescaler. */
    __FWDT_PRESCALER_CONFIG(FWDT_PRESCALER_256);  
    /* Config reload value. */
    __FWDT_RELOAD_VALUE_SET(fwdt_reload);/*!< 0--0x0FFF */
    while ((__FWDT_FLAG_STATUS_GET(FWDT_FLAG_DRF) || __FWDT_FLAG_STATUS_GET(FWDT_FLAG_UVRF)) != RESET);
    __FWDT_RELOAD_COUNTER();
    __FWDT_ENABLE();
    #if 0
    /* Enable LRC clock. */
    rcu_lrc_config(RCU_ENABLE_BIT_LRC_CLK);

    /* Check if the system has resumed from FWDT reset. */
    if (__RCU_FLAG_STATUS_GET(FWDTRST) != RESET)
    {
        __RCU_FLAG_CLEAR();
    }

    /*
        Counter Reload Value = 250ms/IWDG counter clock period
                           = 250ms / (LRC/32)
                           = 0.25s / (LRC_Freq/32)
                           = LRC_Freq/(32 * 4)
                           = LRC_Freq/128
    */
    /* Enable write access. */
    __FWDT_WRITE_ACCESS_ENABLE();

    //    /* Config prescaler. */
    //    __FWDT_PRESCALER_CONFIG(FWDT_PRESCALER_32);
    //
    //    /* Config reload value. */
    //    __FWDT_RELOAD_VALUE_SET(1284);
    __FWDT_PRESCALER_CONFIG(FWDT_PRESCALER_64);
    __FWDT_RELOAD_VALUE_SET(3100);
    while ((__FWDT_FLAG_STATUS_GET(FWDT_FLAG_DRF) || __FWDT_FLAG_STATUS_GET(FWDT_FLAG_UVRF)) != RESET)
        ;
    __FWDT_RELOAD_COUNTER();
    __FWDT_ENABLE();
    #endif
}

void MCU_FWDG_Feed(void)
{
    __FWDT_RELOAD_COUNTER();
}

void MCU_FWDG_20S(void)
{
    __FWDT_WRITE_ACCESS_ENABLE();
    __FWDT_PRESCALER_CONFIG(FWDT_PRESCALER_64);
    __FWDT_RELOAD_VALUE_SET(3100);
    while ((__FWDT_FLAG_STATUS_GET(FWDT_FLAG_DRF) || __FWDT_FLAG_STATUS_GET(FWDT_FLAG_UVRF)) != RESET)
        ;
    __FWDT_RELOAD_COUNTER();
}
void MCU_FWDG_4S(void)
{
    __FWDT_WRITE_ACCESS_ENABLE();
    __FWDT_PRESCALER_CONFIG(FWDT_PRESCALER_32);
    __FWDT_RELOAD_VALUE_SET(1284);
    while ((__FWDT_FLAG_STATUS_GET(FWDT_FLAG_DRF) || __FWDT_FLAG_STATUS_GET(FWDT_FLAG_UVRF)) != RESET)
        ;
    __FWDT_RELOAD_COUNTER();
}
void FWDG_LPT_modeCheck(void)
{
    static uint16_t period;
    if (period != Periodtime)
    {
        period = Periodtime;
        if (period == NormalPeriod)
        {
            MCU_FWDG_4S();
        }
        else if (period == SleepPeriod)
        {
            MCU_FWDG_20S();
        }
    }
}
void AFE_FWDG_Init(void)
{
    uint16_t reg = 0;

    afe_gcr_reg_unlock();

    /* iwdg clock enable. */
    afe_rcc_periph_clock_enable_ctrl(RCC_PERI_IWDT_CLOCK, ENABLE);

    /* clear iwdg reset source. */
    afe_rcc_reset_flag_clear(RCC_FLAG_IWDG_RSTS);

    /* iwdg prescaler, reload value, window set, iwdt T = (1/(clk_lfo/32))*0xfff. */
    afe_iwdg_prescaler_value_set(IWDT_PRESCALER_4);
    afe_iwdg_reload_value_set(0xfff);
    afe_iwdg_window_value_set(0xfff);

    /* waiting for iwdg config vaild. */
    while (1)
    {
        afe_iwdg_status_get(&reg);
        if ((reg & 0x07) == 0)
        {
            afe_iwdg_feed_enable();
            afe_iwdg_enable_ctrl(ENABLE);
            break;
        }
    }
}

void AFE_FWDG_Feed(void)
{
    afe_iwdg_feed_enable();
}

void FUSE_Init(void)
{
    /* enable fuse int. */
    afe_int_periph_int_enable_ctrl(INT_IE0_FUSE_INT, ENABLE);
    /* config fuse remove jitter delay time 120us. */
    afe_fuse_remove_jitter_delay_config(INT_ICTR_FUSE_DDS_120US);
    /* enable fuse remove jitter. */
    afe_remove_jitter_enable_ctrl(INT_ICTR2_FUSE_DDS_MODE, ENABLE);
    /* enable fuse fusing. */
    afe_dtdrv_fusing_enable_ctrl(DISABLE);  
}

void FUSE_OUT(uint8_t output)
{
    afe_dtdrv_fusing_enable_ctrl(output);
}

uint8_t FUSE_Read()
{
    uint8_t status = 0;
    afe_indicator_flag_get(INT_FUSE_IO_INDICATOR_FLAG, &status);
    return status;
}

void PresInit(void)
{
   
    afe_gcr_pb0_mf_config(GCR_PB_MFP_PRESN);
 
    //afe_gpio_mode_config(GPIO_PB0_PIN, GPIO_PB_MODE_OUTPUT_PP);
   
}
void PresDeInit(void)
{

    afe_gcr_pb0_mf_config(GCR_PB_MFP_PB0);
    afe_gpio_mode_config(GPIO_PB0_PIN, GPIO_PB_MODE_INPUT);
    
}

void PresToggle(void)
{
    static uint8_t CNT = 0;
    uint8_t status;
    //PresInit();
    //delay_ms(10);
    if(f_pres_en == OFF)
    {
        return;
    }
    afe_gpio_input_data_bit_read(GPIO_PB0_PIN, &status);
    //printf("status=%d\n",status);




    if (D_DA_Configuration_NR)
    {
        if (D_DA_Configuration_DISCONN_EN)
        {
            if (status)
            {
                if (PackVoltage() >= V_max * NUMBER_SERIES)
                {
                    f_disconn = OFF;
                }
                CNT = 0;
            }
            else
            {
                CNT++;
                if (CNT >= 4)
                {
                    CNT = 0;
                    f_disconn = ON;
                }
            }
        }
        else
        {
            CNT = 0;
        }
    }
    else
    {
        if (status)
        {
            if(f_pres == ON)
            {
                CNT++;
                if(CNT >= 4)
                {
                    CNT = 0;
                    f_pres = OFF;
                }
            }
            else
            {
                CNT = 0;
            }

            // prelowdelay = 0;
            // if (prehiegdelay > 1000)
            // {
            //     prehiegdelay = 0;
            //     f_pres = OFF;
            // }
        }
        else
        {
            if(f_pres == OFF)
            {
                CNT++;
                if(CNT >= 4)
                {
                    CNT = 0;
                    f_pres = ON;
                }
            }
            else
            {
                CNT = 0;
            }
            // prehiegdelay = 0;
            // if (prelowdelay > 1000)
            // {
            //     f_pres = ON;
            //     prelowdelay = 0;
            // }
        }
    }

    if (SafetyStatus(COVL) || SafetyStatus(OCDL) || SafetyStatus(AOLDL) || SafetyStatus(ASCDL) || SafetyStatus(ASCCL) || SafetyStatus(PTO) || SafetyStatus(CTO) || SafetyStatus(OC))
    {
        if(f_pres)
        {
            f_pres_l = ON;
            if(f_pres_h)
            {
                f_preslhl = ON;
            }
        }
        else
        {
            if(f_pres_l)
            {
                f_pres_h = ON;
            }
        }
    }
    else
    {
        f_preslhl = OFF;
    }
    PresDeInit();
}


uint8_t sha256_hmac_calc(uint8_t* message, uint16_t msglen, uint8_t* key, uint16_t key_len, uint8_t* mac)
{
    uint32_t ret;
    hmac_ctx_t ctx[1];
    
    rcu_hclk_config(RCU_HCLK_CFG_SYSCLK_DIV2);  //AHB Bus division
    __RCU_AHB_CLK_ENABLE(RCU_AHB_PERI_HASH);
    
    ret = hmac_init(ctx, HASH_SHA256, key, 0, key_len);
    ret |= hmac_update(ctx, message, msglen);
    ret |= hmac_final(ctx, mac);
    
    rcu_hclk_config(RCU_HCLK_CFG_SYSCLK_DIV1);  //AHB Bus division
    __RCU_AHB_CLK_DISABLE(RCU_AHB_PERI_HASH);
    
    return ret;
}
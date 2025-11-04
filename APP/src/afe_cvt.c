#include "afe_cvt.h"


Afe_data afe_data;
Afe_data afe_Calib;
uint16_t temperature;
uint8_t relaxing = 0;
uint16_t relaxingCnt = 0;

uint16_t cc_osr=65000;
uint16_t vadc_osr=2048;

/**@brief afe_cc_first_order_init
          convert time = 65000/512KHZ = 124ms
 * @return .
 */
uint8_t afe_cc_first_order_init(void)
{
    uint8_t ret;
    uint8_t status;
    cc_general_config_t cc_general_config;
    cc_normal_mode_config_t cc_normal_mode_config;

    ret = afe_cc_sarend_enable_ctrl(ENABLE);
    AFE_FUN_EXECUTE_RESULT_CHECK(ret);

    cc_general_config.cc_vcmsel    = CC_ADC_GTC_0MUL;
    cc_general_config.cc_ichop     = CC_ADC_ICHOP_1_256;
    cc_general_config.cc_echop     = CC_ADC_ECHOP_1_8;
    cc_general_config.cc_signal    = CC_ADC_SRP_SRN;
    cc_general_config.cc_fs_sel    = CC_ADC_FS_512KHZ;
    cc_general_config.cc_buf_drvn  = CC_ADC_BUFF_DISABLE;
    cc_general_config.cc_gtc       = CC_ADC_GTC_0PPM;
    cc_general_config.cc_ibt       = CC_IBT_NORMAL;
    ret = afe_cc_general_init(&cc_general_config);
    AFE_FUN_EXECUTE_RESULT_CHECK(ret);

    ret = afe_cc_chop_enable_ctrl(ENABLE);
    AFE_FUN_EXECUTE_RESULT_CHECK(ret);

    ret = afe_cc_ichop_enable_ctrl(ENABLE);
    AFE_FUN_EXECUTE_RESULT_CHECK(ret);

    cc_normal_mode_config.cc_ccosr  = cc_osr;
    cc_normal_mode_config.cc_maxosr = CC_ADC_CCOSR_1;
    cc_normal_mode_config.cc_gain   =  CC_ADC_GAIN_10;
    ret = afe_cc_normal_mode_init(&cc_normal_mode_config);
 
    ret = afe_int_mode_config(INT_IMD_PULSE_INTMODE);
    AFE_FUN_EXECUTE_RESULT_CHECK(ret);

    ret = afe_int_periph_int_enable_ctrl(INT_IE0_CC_INT,ENABLE);
    AFE_FUN_EXECUTE_RESULT_CHECK(ret);
    ret = afe_int_periph_int_flag_get(INT_ISRC0_CC_INT_FLAG,&status);
    AFE_FUN_EXECUTE_RESULT_CHECK(ret);
    if(status == SET)
    {
        ret = afe_int_periph_int_flag_clear(INT_ISRC0_CC_INT_FLAG);
    }

    ret = afe_cc_enable_ctrl(ENABLE);
    AFE_FUN_EXECUTE_RESULT_CHECK(ret);
    return SUCCESS;
}


/**@brief vadc_channel_cycle_init
          convert time = (1/(512KHZ/2)) * 2048 *11ch = 88ms
 * @return .
 */
uint8_t vadc_channel_cycle_init(void)
{
    uint8_t status;
    uint8_t ret;
    uint16_t reg;
    vadc_config_t  vadc_config;

    vadc_config.vadc_conversion_mode    = VADC_CONVER_1CYCLE_MODE;
    vadc_config.vadc_fs_frequency       = VADC_FS_512KHZ;
    vadc_config.vadc_chopper_frequency  = VADC_CHOPPER_1_48_FFS;
    #if(defined(CBM8581))
    vadc_config.vadc_vc4_select              = VADC_VCC_VC5;
    #else
    vadc_config.vadc_vc4_select              = VADC_VCC_VC4;
    #endif
    vadc_config.vadc_chopper_en         = VADC_CHOPPER_ENABLE;
    vadc_config.vadc_conversion_num     = VADC_CONVERSION_NUM_1;
    vadc_config.vadc_ibt_current        = VADC_IBT_NO_CURRENT;
    vadc_config.vadc_pack_check_en      = VADC_PACKST_DISABLE;
    vadc_config.vadc_timer_inter_en     = VADC_TIM_TRIGGER_DISABLE;
    vadc_config.vadc_vcm_voltage        = VADC_VCM_1_2_VLDO1P8V;

    ret = afe_vadc_init(&vadc_config);
    AFE_FUN_EXECUTE_RESULT_CHECK(ret);

    ret = afe_vadc_channel_enable_ctrl(VADC_CHANNEL_ALL, ENABLE);
    AFE_FUN_EXECUTE_RESULT_CHECK(ret);
    ret = afe_vadc_channel_gain_config(VADC_CHANNEL_ALL, VADC_CHANNEL_GAIN_1);
    AFE_FUN_EXECUTE_RESULT_CHECK(ret);
    ret = afe_vadc_down_sampling_rate_set(vadc_osr);
    AFE_FUN_EXECUTE_RESULT_CHECK(ret);
    /* 根据配置表来选择 */
    #if(defined(CBM8581))
    ret = afe_vadc_channel0_mode_config(VADC_VC5_VC4);
    #else
    if(D_Temperature_Enable_TSint)
    {
        ret = afe_vadc_channel0_mode_config(VADC_VTEMPP_INT);
    }
    #endif
    if(D_Temperature_Enable_TS1)
    {
        ret = afe_vadc_channel1_mode_config(VADC_V_ETS1);
    }
    if(D_Temperature_Enable_TS2)
    {
        ret = afe_vadc_channel2_mode_config(VADC_V_ETS2);
    }
    if(D_Temperature_Enable_TS3)
    {
        ret = afe_vadc_channel3_mode_config(VADC_V_ETS3);
    }
    if(D_Temperature_Enable_TS4)
    {
        ret = afe_vadc_channel4_mode_config(VADC_V_ETS4);
    }
    #if(defined(CBM8581))
    ret = afe_vadc_channel5_mode_config(VADC_VC5_DIV);
    #else
    ret = afe_vadc_channel5_mode_config(VADC_VC4_DIV);
    #endif

    ret = afe_vadc_channel6_mode_config(VADC_PACK_DIV);
    
    AFE_FUN_EXECUTE_RESULT_CHECK(ret);
    ret = afe_vadc_channel7_mode_config(VADC_VC1_0);
    AFE_FUN_EXECUTE_RESULT_CHECK(ret);
    ret = afe_vadc_channel8_mode_config(VADC_VC2_VC1);
    AFE_FUN_EXECUTE_RESULT_CHECK(ret);
    ret = afe_vadc_channel9_mode_config(VADC_VC3_VC2);
    AFE_FUN_EXECUTE_RESULT_CHECK(ret);
    ret = afe_vadc_channel10_mode_config(VADC_VC4_VC3);
    AFE_FUN_EXECUTE_RESULT_CHECK(ret);

    ret = afe_int_periph_int_enable_ctrl(INT_IE0_VADC_INT, ENABLE);
    AFE_FUN_EXECUTE_RESULT_CHECK(ret);
    ret = afe_int_periph_int_flag_get(INT_ISRC0_VADC_INT_FLAG, &status);
    AFE_FUN_EXECUTE_RESULT_CHECK(ret);
    if(status == SET)
    {
        ret = afe_int_periph_int_flag_clear(INT_ISRC0_VADC_INT_FLAG);
        AFE_FUN_EXECUTE_RESULT_CHECK(ret);
    }

    afe_vadc_enable_ctrl(ENABLE);
    return ret;
}

uint8_t CVT_Init(void)
{
    __disable_irq();
    vadc_channel_cycle_init();//电压采样模块初始化
    //printf(" vadc init\n");
    
    afe_cc_first_order_init();//电流采样模块初始化
    //printf(" afe_cc_first_order_init\n");
    
    __enable_irq();

    return 0;
}
void start_cc_convert(void)
{
    uint8_t status = 0;
    afe_cc_flag_status_get(CC_ADC_BUSY, &status);
    if(status == RESET)
    {
        afe_cc_enable_ctrl(ENABLE);
    }
}

void Enable_CVT(void)
{
    // if(task_init == 0)
    // {
    //     return;
    // }
    afe_dtdrv_vc_enable_ctrl(DTDRV_CVBLC_CB_VC1 | DTDRV_CVBLC_CB_VC2 | DTDRV_CVBLC_CB_VC3 | DTDRV_CVBLC_CB_VC4, DISABLE);
    start_cc_convert();
    afe_vadc_enable_ctrl(ENABLE);
}

void FirstCVT_Converter(void)
{
    // if(task_init == 0)
    // {
    //     return;
    // }

    while (1)
    {
        if (f_curr_en)
        {
            f_curr_en = OFF;
            Enable_CVT();
            break;
        }
    }
    while (1)
    {
        EXTI_Proc();
        if (f_CC_int && f_VADC_int)
        {
            f_CC_int = OFF;
            f_VADC_int = OFF;
            Get_CVT();
            break;
        }
    }
}

const int32_t  R_x[160] =
{
    6150,  6250,  6360,  6470,  6590,  6790,  7000,  7210,  7430,  7660,
    7850,  8050,  8250,  8450,  8660,  8870,  9090,  9320,  9550,  9790,
    10024, 10284, 10552, 10829, 11114, 11408, 11711, 12024, 12347, 12680,
    13024, 13379, 13745, 14123, 14513, 14917, 15333, 15764, 16208, 16668,
    17143, 17634, 18141, 18666, 19209, 19770, 20351, 20952, 21575, 22218,
    22885, 23575, 24290, 25030, 25797, 26592, 27416, 28269, 29155, 30072,
    31024, 32011, 33036, 34099, 35202, 36347, 37536, 38771, 40054, 41386,
    42771, 44210, 45706, 47261, 48879, 50562, 52313, 54135, 56031, 58005,
    60061, 62203, 64434, 66759, 69182, 71708, 74342, 77089, 79955, 82946,
    86068, 89327, 92731, 96286, 100000, 103882, 107940, 112182, 116620, 121262,
    126120, 131205, 136529, 142105, 147946, 154067, 160483, 167210, 174266, 181667,
    189435, 197588, 206150, 215143, 224591, 234522, 244962, 255943, 267494, 279650,
    292447, 305923, 320118, 335077, 350846, 367474, 385014, 403523, 423062, 443694,
    465491, 488524, 512875, 538628, 565874, 594711, 625243, 657584, 691854, 728183,
    737510, 775290, 815340, 857800, 902850, 949620, 999230, 1051870, 1107750,1167090,
    1231450,1299930,1372850,1450510,1533280,1620940,1714420,1814160,1926300,2034340
};
/****************************************************
* ntc-table  ;unit 0.1C
****************************************************/
const int16_t T_y[160] =
    {
        1190,1180,1170,1160,1150,1140,1130,1120,1110,1100,
        1090,1080,1070,1060,1050,1040,1030,1020,1010,1000,
        990, 980, 970, 960, 950, 940, 930, 920, 910, 900,
        890, 880, 870, 860, 850, 840, 830, 820, 810, 800,
        790, 780, 770, 760, 750, 740, 730, 720, 710, 700,
        690, 680, 670, 660, 650, 640, 630, 620, 610, 600,
        590, 580, 570, 560, 550, 540, 530, 520, 510, 500,
        490, 480, 470, 460, 450, 440, 430, 420, 410, 400,
        390, 380, 370, 360, 350, 340, 330, 320, 310, 300,
        290, 280, 270, 260, 250, 240, 230, 220, 210, 200,
        190, 180, 170, 160, 150, 140, 130, 120, 110, 100,
        90, 80, 70, 60, 50, 40, 30, 20, 10, 0, -10,
        -20, -30, -40, -50, -60, -70, -80, -90, -100, -110,
        -120, -130, -140, -150, -160, -170, -180, -190, -200,
        -210,-220, -230, -240, -250, -260, -270, -280, -290, -300,
        -310,-320, -330, -340, -350, -360, -370, -380, -390, -400};
int16_t InterpolateTableXlong(int32_t *tableX, int16_t *tableY, uint8_t len, int32_t xvalue)
{
    int32_t yvalue, y1, x1, x2;
    float k;
    int16_t i = 1;
    while((tableX[i] < xvalue) && (i < (len - 1)))
        i++;
    y1 = (tableY[i] - tableY[i - 1]);
    x1 = (xvalue - tableX[i - 1]);
    x2 = (tableX[i] - tableX[i - 1]);
    if(x2 != 0)
    {
        k = (float)x1 / x2;
        yvalue = (int32_t)(y1 * k + tableY[i - 1]);
    }
    else
        yvalue = tableY[i - 1];
    return(yvalue);
}

/*小数点一位*/
int16_t Lookup_T(int32_t Rt)
{
    int16_t v;
    v = InterpolateTableXlong((int32_t *)R_x, (int16_t *)T_y, 160, Rt);
    return(v);
}

/**
  * @brief  .
  * @param  .
  * @param  .
  * @note   unit mv.
  * @return 0-ok,-1-fail.
  */
char get_vadc_temprature_ex(uint8_t channel, int32_t *value)
{
    uint8_t ret;
    uint32_t data;
    float conver_data;
    ret = afe_vadc_second_integral_value_get(channel, &data);
    AFE_FUN_EXECUTE_RESULT_CHECK(ret);
    if(ret != 0)                // ---ok
    {
        conver_data = afe_vadc_conver_data_calc(data, vadc_osr, 1, 2000) / 1000.0;
        *value = (int32_t)((conver_data * 18 * 10000) / (2000 - conver_data)); // vol turn to 0.1om
        return 0;
    }
    return -1;
}

char get_vadc_temprature_inner(uint8_t channel, int32_t *value)
{
    uint8_t ret;
    uint32_t data;
    float conver_data;
    uint16_t TS_TRIM0_H, TS_TRIM0_L;
    uint16_t TS_TRIM1;
    uint32_t TS_TRIM0;

    ret = afe_vadc_second_integral_value_get(channel, &data);
    if(ret != 0)
    {
        conver_data = afe_vadc_conver_data_calc(data, vadc_osr, 1, 1245) / 1000.0;
        TS_TRIM0_H = GET_TRIM_VALUE(0x1FFFFC44);//获取内部温度传感器高16bit码值
        TS_TRIM0_L = GET_TRIM_VALUE(0x1FFFFC40);//获取内部温度传感器低16bit码值
        TS_TRIM0 = ((uint32_t)(TS_TRIM0_H << 16)) | TS_TRIM0_L;//合成32bit码值
        TS_TRIM1 = GET_TRIM_VALUE(0x1FFFFC64);//获取已写入的16bit环境温度码值
        float temp_in = (conver_data - (( ( ((float) TS_TRIM0) / ( 2048 * (2048 - 1) ) - 0.5) * 2 * 1000 * 1.245) / 1)) / 0.1775 + ((float)TS_TRIM1 / 100);
        *value =  (int32_t)(temp_in * 10.0);
        return 0;
    }
    return -1;
}
/**
  * @brief  . 
  * @param   channel = VADC_VC1_CH~VADC_VC4_CH
  * @param  .
  * @note   unit mv.
  * @return 0-ok,-1-fail.
  */
char get_vadc_voltage_vcx(uint8_t channel, int32_t *vol)
{
    uint8_t ret;
    uint32_t data;
    int32_t conver_data;
    ret = afe_vadc_second_integral_value_get(channel, &data);
    AFE_FUN_EXECUTE_RESULT_CHECK(ret);
    if(ret != 0){ //---ok
         conver_data = afe_vadc_conver_data_calc(data, vadc_osr, 5, 1245);
        *vol = conver_data/1000;
        return 0;
    }
    return -1;
}

/**
  * @brief  . 
  * @param   channel = VADC_VC4_DIV_CH  VADC_PACK_DIV_CH
  * @param  .
  * @note   unit mv.
  * @return 0-ok,-1-fail.
  */
char get_vadc_voltage_pack(uint8_t channel, int32_t *vol)
{
    uint8_t ret;
    uint32_t data;
    float conver_data;
    ret = afe_vadc_second_integral_value_get(channel, &data);
    AFE_FUN_EXECUTE_RESULT_CHECK(ret);
    if(ret != 0){ //---ok
        conver_data = afe_vadc_conver_data_calc(data, vadc_osr, 1, 1245)/1000.0;
        *vol = conver_data*20; //DIV 1/20 ,
        return 0;
    }
    return -1;
}

char get_cc_current(int32_t * current)
{
    *current = afe_cc_first_order_conver_data_calc(10, 1214)/1000;
    return 0;
}

/**
  * @brief  cal_average_current
  * @param  input current
  * @retval average current
  */
int16_t cal_average_current(int16_t in_current, uint32_t time_ms)
{
    static uint32_t time_cnt_ms = 0;
    static uint8_t current_cnt = 0;
    static int32_t current_sum = 0;
    static int16_t average_current = 0;

    time_cnt_ms += time_ms;
    current_sum += in_current;
    current_cnt++;
    average_current = current_sum / current_cnt;
    if(time_cnt_ms >= (10 * RT_TICK_PER_SECOND)) //one minute average current
    {
        time_cnt_ms = 0;
        current_cnt = 0;
        current_sum = 0;
    }
    return average_current;
}

/* 获取adc原始采样值 */
void get_adc_original_value(void)
{
    /* todo:改成从adc驱动里面获取采样值 */
    int32_t vadc_val = 0;
    uint8_t i = 0;
    int16_t ext_temp_value = 0;
    memset(&afe_data, 0, sizeof(afe_data));//清除上一次的采样值
    #if(!defined(CBM8581))
    //读取内温
    if(D_Temperature_Enable_TSint && (get_vadc_temprature_inner(IN_TEMP, &vadc_val) == 0))
    {
        afe_data.temprature_inner_val = vadc_val;
    }
    #endif
    //读取外温
    if(D_Temperature_Enable_TS1 && (get_vadc_temprature_ex(TS1, &vadc_val) == 0))
    {  
        ext_temp_value = Lookup_T(vadc_val);//0.1degc
        afe_data.temprature_ex_val[i] = ext_temp_value;
        afe_data.pack_temprature_valid[i] = 1;
    }
    i++;
    if(D_Temperature_Enable_TS2 && (get_vadc_temprature_ex(TS2, &vadc_val) == 0))
    {
        ext_temp_value = Lookup_T(vadc_val);//0.1degc
        afe_data.temprature_ex_val[i] = ext_temp_value;
        afe_data.pack_temprature_valid[i] = 1;
    }
    i++;
    if(D_Temperature_Enable_TS3 && (get_vadc_temprature_ex(TS3, &vadc_val) == 0))
    {
        ext_temp_value = Lookup_T(vadc_val);//0.1degc
        afe_data.temprature_ex_val[i] = ext_temp_value;
        afe_data.pack_temprature_valid[i] = 1;
    }
    i++;
    if(D_Temperature_Enable_TS4 && (get_vadc_temprature_ex(TS4, &vadc_val) == 0))
    {
        ext_temp_value = Lookup_T(vadc_val);//0.1degc
        afe_data.temprature_ex_val[i] = ext_temp_value;
        afe_data.pack_temprature_valid[i] = 1;
    }


    //读取单节电压
    for(i = 0; i < NUMBER_SERIES; i++)
    {
        if(get_vadc_voltage_vcx(CELL_1 + i, &vadc_val) == 0) //获取各节电压值
        {
            afe_data.cell_vol_val[i] = vadc_val;//mv
        }
    }

    //读取电池总电压
    if(get_vadc_voltage_pack(VC4, &vadc_val) == 0)
    {
        afe_data.bat_voltage_val = vadc_val;//mv
    }
    //读取pack端总电压
    if(get_vadc_voltage_pack(V_PACK, &vadc_val) == 0)
    {
        afe_data.pack_voltage_val = vadc_val > 0 ? vadc_val : 0; // mv
    }
    //读取电流
    if(get_cc_current(&vadc_val) == 0)
    {
        afe_data.pack_adc_current = vadc_val;
    }
    afe_Calib = afe_data;
    
}

/* 获取adc校准后的采样值 */
void get_adc_calibration_value(void)
{
    static uint32_t cali_timeout_cnt = 0;
    static uint32_t cali_cnt = 0;
    uint8_t i = 0;
    
    if(f_CAL_EN == 0)//不是校准状态要乘校准系数
    {
        if(D_Temperature_Enable_TSint)
        {
            afe_data.temprature_inner_val -= D_Calibdata_InterTOffset;/*!< 内部温度校准 */
        }
        for(i = 0; i < SYS_CELL_NUM_MAX; i++)
        {
            switch(i)//gain 应该放至数组
            {
                case 0:
                    afe_data.cell_vol_val[i] =  afe_data.cell_vol_val[i] * D_Calibdata_Cell1_vol_Gain / CALIBRATION_AMP; //mv
                    if(D_Temperature_Enable_TS1)
                    {
                        afe_data.temprature_ex_val[i] -= D_Calibdata_TS1Offset;
                        if(!D_Temperature_Mode_TS1_Mode)
                        {
                            temperature = afe_data.temprature_ex_val[i] +2731;
                        }
                    }
                    break;
                case 1:
                    afe_data.cell_vol_val[i] =  afe_data.cell_vol_val[i] * D_Calibdata_Cell2_vol_Gain / CALIBRATION_AMP; //mv
                    if(D_Temperature_Enable_TS2)
                    {
                        afe_data.temprature_ex_val[i] -= D_Calibdata_TS2Offset;
                        if(!D_Temperature_Mode_TS2_Mode)
                        {
                            temperature = afe_data.temprature_ex_val[i] +2731;
                        }
                    }
                    break;
                case 2:
                    afe_data.cell_vol_val[i] =  afe_data.cell_vol_val[i] * D_Calibdata_Cell3_vol_Gain / CALIBRATION_AMP; //mv
                    if(D_Temperature_Enable_TS3)
                    {
                        afe_data.temprature_ex_val[i] -= D_Calibdata_TS3Offset;
                        if(!D_Temperature_Mode_TS3_Mode)
                        {
                            temperature = afe_data.temprature_ex_val[i] +2731;
                        }
                    }
                    break;
                case 3:
                    afe_data.cell_vol_val[i] =  afe_data.cell_vol_val[i] * D_Calibdata_Cell4_vol_Gain / CALIBRATION_AMP; //mv
                    if(D_Temperature_Enable_TS4)
                    {
                        afe_data.temprature_ex_val[i] -= D_Calibdata_TS4Offset;
                        if(!D_Temperature_Mode_TS4_Mode)
                        {
                            temperature = afe_data.temprature_ex_val[i] +2731;
                        }
                    }
                    break;
                default:
                    break;
            }
        }
        afe_data.bat_voltage_val = (int16_t)((int32_t)(afe_data.bat_voltage_val) * D_Calibdata_Bat_Gain / CALIBRATION_AMP);
        afe_data.pack_voltage_val = (int16_t)((int32_t)(afe_data.pack_voltage_val) * D_Calibdata_Pack_Gain / CALIBRATION_AMP);
        afe_data.pack_adc_current = (afe_data.pack_adc_current - D_Calibdata_CC_Offset) * D_Calibdata_Current_Gain / CALIBRATION_AMP;/*!< 使用原始电流计算得到校准后的电流 */
        //判断电流范围，避免溢出
        afe_data.pack_current = (afe_data.pack_adc_current > CURRENT_MAX_LIMIT) ? CURRENT_MAX_LIMIT : afe_data.pack_adc_current;
        afe_data.pack_current = (afe_data.pack_adc_current < CURRENT_MIN_LIMIT) ? CURRENT_MIN_LIMIT : afe_data.pack_adc_current;
        //判断dead band
        if((ABS(afe_data.pack_current) <= D_Calibdata_Dead_Band))//避免假电流
        {
            afe_data.pack_current = 0;//把值写0
        }
    }
    else
    {
        /* 校准状态下打印测量值 */
        //("afe_data.temprature_inner_val = %d 0.1C", afe_data.temprature_inner_val);
        for(i = 0; i < SYS_CELL_NUM_MAX; i++)
        {
            //printf("afe_data.cell_vol_val[%d] = %d mV", i, afe_data.cell_vol_val[i]);
            //printf("afe_data.temprature_ex_val[%d] = %d 0.1C", i, afe_data.temprature_ex_val[i]);
        }
        
        // printf("afe_data.bat_voltage_val = %d mV", afe_data.bat_voltage_val);
        // printf("afe_data.pack_voltage_val = %d mV", afe_data.pack_voltage_val);
        // printf("afe_data.pack_adc_current = %d mA", afe_data.pack_adc_current);
        //校准超时判断
        cali_timeout_cnt += Periodtime;
        cali_cnt++;
        if(cali_timeout_cnt > CALI_TIMEOUT_MS)
        {
            // printf("cali_timeout_cnt = %d", cali_timeout_cnt);
            // printf("cali_cnt = %d", cali_cnt);
            cali_timeout_cnt = 0;
            cali_cnt = 0;
            f_CAL_EN = 0;
        }
    }
}

//all input unit
//current:mA;  voltage:mV;  Temp:0.1degree;  time:milsecond
int32_t get_min_value(int32_t*data,int len)
{
	int i=0;
	int32_t ret=data[0];
	
	for(i=1;i<len;i++)
	{
		if(ret>data[i])
		{
			ret=data[i];
		}
	}
	return ret;
}

int32_t get_max_value(int32_t*data,int len)
{
	int i=0;
	int32_t ret=data[0];
	
	for(i=1;i<len;i++)
	{
		if(ret<data[i])
		{
			ret=data[i];
		}
	}
	return ret;
}

int32_t get_average_value(int32_t*data,int len)
{
	int i=0;
	int32_t ret=0;
	
	for(i=0;i<len;i++)
	{
		ret+=data[i];
	}
	return (int32_t)(ret/len);
}

//get fet temp, if there no config fet temp ,temp[0] used; if multiy config, max temp used
int32_t get_FETtemp(int32_t *temp,int TempNum)
{
	int32_t i=0,cnt=0;
	int32_t tempfet[5];
	if(D_Temperature_Mode_TSint_Mode==1)
	{
		tempfet[cnt++]=temp[0];
    }
    if (D_Temperature_Mode_TS1_Mode == 1 && f_pf_ts1_p == 0)
    {
        tempfet[cnt++] = temp[1];
    }
    if (D_Temperature_Mode_TS2_Mode == 1 && f_pf_ts2_p == 0)
    {
        tempfet[cnt++] = temp[2];
    }
    if (D_Temperature_Mode_TS3_Mode == 1 && f_pf_ts3_p == 0)
    {
        tempfet[cnt++] = temp[3];
    }
    if (D_Temperature_Mode_TS4_Mode == 1 && f_pf_ts4_p == 0)
    {
        tempfet[cnt++] = temp[4];
    }

    if(cnt>0)
	{
		return get_max_value(tempfet,cnt);
	}
	else
	{
		return temp[0];
	}
	
}
void Get_CVT(void)
{
    volatile int32_t temp[1 + SYS_CELL_NUM_MAX] = {0};
    volatile int32_t voltage[SYS_CELL_NUM_MAX] = {0};
    volatile uint8_t TsNum = 0;
    volatile uint8_t i;
    get_adc_original_value();
    get_adc_calibration_value();
    temp[0] = afe_data.temprature_inner_val;
    for (i = 0; i < 4; i++)
    {
        temp[1 + i] = afe_data.temprature_ex_val[i];
        voltage[i] = afe_data.cell_vol_val[i];
        
        TsNum += afe_data.pack_temprature_valid[i];
    }

    aveTemp = get_average_value(&temp[1], TsNum);
    V_max = get_max_value(voltage, NUMBER_SERIES);
    V_min = get_min_value(voltage, NUMBER_SERIES);
    Ts_max = (temperature - 2731)/10.0;//get_max_value(&temp[1], TsNum);
    Ts_min = (temperature - 2731)/10.0;//get_min_value(&temp[1], TsNum);
    FETTemp = get_FETtemp(temp, TsNum + 1);

    //temperature = Ts_max + 2731;
    t_com2c = afe_data.temprature_inner_val + 2731; /*!< 内温 */

    memcpy((uint8_t *)&(_DAStatus1.CellVoltage1), (uint8_t *)&(afe_data.cell_vol_val), 8);
    _DAStatus1.BatVoltage = afe_data.bat_voltage_val;
    _DAStatus1.PackVoltage = afe_data.pack_voltage_val;
    _DAStatus1.CellCurrnet1 = afe_data.pack_current;
    _DAStatus1.CellCurrnet2 = afe_data.pack_current;
    _DAStatus1.CellCurrnet3 = afe_data.pack_current;
    _DAStatus1.CellCurrnet4 = afe_data.pack_current;
    _DAStatus1.CellPower1 = (uint32_t)_DAStatus1.CellCurrnet1 * _DAStatus1.CellVoltage1 / 10000;
    _DAStatus1.CellPower2 = (uint32_t)_DAStatus1.CellCurrnet2 * _DAStatus1.CellVoltage2 / 10000;
    _DAStatus1.CellPower3 = (uint32_t)_DAStatus1.CellCurrnet3 * _DAStatus1.CellVoltage3 / 10000;
    _DAStatus1.CellPower4 = (uint32_t)_DAStatus1.CellCurrnet4 * _DAStatus1.CellVoltage4 / 10000;
    _DAStatus1.Power = (uint32_t)Voltage() * Current() / 10000;
    _DAStatus1.AveragePower = (uint32_t)Voltage() / NUMBER_SERIES * Current() / 10000;

    _DAStatus2.IntTemperature = afe_data.temprature_inner_val + 2731;
    _DAStatus2.TS1Temperature = afe_data.temprature_ex_val[0] + 2731;
    _DAStatus2.TS2Temperature = afe_data.temprature_ex_val[1] + 2731;
    _DAStatus2.TS3Temperature = afe_data.temprature_ex_val[2] + 2731;
    _DAStatus2.TS4Temperature = afe_data.temprature_ex_val[3] + 2731;
    _DAStatus2.CellTemperature = temperature;
    _DAStatus2.FETTemperature = FETTemp + 2731;

    FETTemp /= 10;

    _AverageCurrent = cal_average_current(Current(), Periodtime);
    I_abs = ABS(Current());
    DCR_Mode();
}

void DCR_Mode(void)
{
    // CHG\DSG\RELAX三态判断,其中只有进入RELAX状态需要计时
    // DSG
    if (Current() < D_Current_Dsg_Current_Threshold)
    {
        f_discharge = ON;
        f_charge = OFF;
        f_relax = OFF;
        f_gs_dsg = ON;
        BatteryStatus(DSG) = ON;
        relaxing = 0;
        relaxingCnt = 0;
    }
    // CHG
    else if (Current() > D_Current_Chg_Current_Threshold)
    {
        f_discharge = OFF;
        f_charge = ON;
        f_relax = OFF;
        f_gs_dsg = OFF;
        BatteryStatus(DSG) = OFF;
        relaxing = 0;
        relaxingCnt = 0;
    }

    // Relax
    if ((Current() <= D_Current_Chg_Current_Threshold) && (Current() >= D_Current_Dsg_Current_Threshold))
    {
        if (relaxingCnt != 0xffff)
        {
            relaxingCnt++;
        }
    }

    if (!relaxing)
    {
        // DSG->Relax
        if ((f_gs_dsg) && (relaxingCnt >= D_Current_Dsg_Relax_Time))
        {
            relaxing = 1;
            f_discharge = OFF;
            f_gs_dsg = ON;
            BatteryStatus(DSG) = ON;
            f_charge = OFF;
            f_relax = ON;
            relaxingCnt = 0;
        }
        // CHG->Relax
        if ((!f_gs_dsg) && (relaxingCnt >= D_Current_Chg_Relax_Time))
        {
            relaxing = 1;
            f_discharge = OFF;
            f_gs_dsg = ON;
            BatteryStatus(DSG) = ON;
            f_charge = OFF;
            f_relax = ON;
            relaxingCnt = 0;
        }
    }
}

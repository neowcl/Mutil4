#include "rtc.h"


static volatile uint32_t asynch_prediv = 0;
static volatile uint32_t synch_prediv = 0x270F;
static volatile uint32_t Wakeup_Value = 1;

//
uint8_t rtc_write_bak_reg(uint32_t value)
{
    uint32_t value_r = 0;
    __RTC_WRITE_PROTECTION_DISABLE();
    __RTC_AO_REGISTER_WRITE(RTC_AO_REGISTER0, value);//RTC_AO_REGISTER0
    __RTC_WRITE_PROTECTION_ENABLE();
    
    value_r = __RTC_AO_REGISTER_READ(RTC_AO_REGISTER0);
    if(value_r != value)
     {
        // logInfo("value_r = %#X, value = %#X\n", value_r, value);
       //  logInfo("RTC_AO_REGISTER0 is not equal!\n");   
         return 0;
     }
     else
     {
         //logInfo("value_r = %#X, value = %#X\n", value_r, value);
        // logInfo("RTC_AO_REGISTER0 write and read ok!\n");
         return 1;
     }
}

//RTC鍩虹閰嶇疆
void rtc_config(void)
{	
  /* Enable the PMU clock. */
  	__RCU_APB1_CLK_ENABLE(RCU_APB1_PERI_PMU);           
    __PMU_CTR_FUNC_ENABLE(PMU_ENABLE_BIT_VBAT_WRITE);   

    __PMU_CTR_FLAG_CLEAR(PMU_CTR_CLRWUPF);  //娓呴櫎鍞ら啋鏍囧織浣�
    __PMU_CTR_FLAG_CLEAR(PMU_CTR_CLRPWDF);  //鎺夌數妯″紡鏍囧織浣�
    
    /* Reset RTC. */
    __RCU_PERI_RST_ENABLE(RTC);
    __RCU_PERI_RST_DISABLE(RTC);		
    /* Enable the LRC clock. */
	__RCU_FUNC_ENABLE(LRC_CLK); 
    /* Wait LRC stabilization. */
	while (__RCU_FLAG_STATUS_GET(LRC_STAB) == RESET);  
    /* Enable the RTC Clock. */	
	__RCU_FUNC_ENABLE(RTC_CLK); 	

    rtc_synchro_wait();

    __RTC_WRITE_PROTECTION_DISABLE();                   	
	rtc_init_t rtc_init_struct;
	rtc_init_struct.hour_format = RTC_HOUR_FORMAT_24;
	rtc_init_struct.rtc_divider1= asynch_prediv;
	rtc_init_struct.rtc_divider2= synch_prediv;
	if (rtc_init(&rtc_init_struct) == ERROR)
    {
        //logInfo("\n\r RTC Prescaler Config failed! \n\r");
    }
    
    __RTC_FLAG_CLEAR(RTC_FLAG_BIT_WAKEUP);  //娓呴櫎RTC鍞ら啋鏍囧織
    __RTC_FLAG_CLEAR(RTC_FLAG_BIT_ALARM);   //娓呴櫎RTC闂归挓鏍囧織
    __RTC_WRITE_PROTECTION_ENABLE();     
}

//閲嶆柊鍒濆鍖杛tc
void rtc_reconfig(void)
{
    /* Enable the PMU clock. */
    __RCU_APB1_CLK_ENABLE(RCU_APB1_PERI_PMU);           
    __PMU_CTR_FUNC_ENABLE(PMU_ENABLE_BIT_VBAT_WRITE); 
    __PMU_CTR_FLAG_CLEAR(PMU_CTR_CLRWUPF);  //娓呴櫎鍞ら啋鏍囧織浣�
    __PMU_CTR_FLAG_CLEAR(PMU_CTR_CLRPWDF);  //鎺夌數妯″紡鏍囧織浣�
    
    /* Enable the LRC clock. */
    __RCU_FUNC_ENABLE(LRC_CLK); 
    /* Wait LRC stabilization. */
    while (__RCU_FLAG_STATUS_GET(LRC_STAB) == RESET){}     
    /* Enable the RTC Clock. */	
    __RCU_FUNC_ENABLE(RTC_CLK); 
    __RTC_FLAG_CLEAR(RTC_FLAG_BIT_WAKEUP);  //娓呮RTC鍞ら啋鏍囧織
    __RTC_FLAG_CLEAR(RTC_FLAG_BIT_ALARM);   //娓呮RTC闂归挓鏍囧織    
}
 

/********************************************************************
function: rtc_Init
discript: RTC
entrance: none
return  : none
other   : none
********************************************************************/
void RTC_Init(void)
{
	uint32_t value_r = __RTC_AO_REGISTER_READ(RTC_AO_REGISTER0);
    // logInfo("value_r = %#X\n", value_r);
    if(value_r == 0)
    {
        rtc_config();
        // logInfo("rtc_config\n");
    }
    else
    {
        rtc_reconfig();
        // logInfo("rtc_reconfig\n");
    }
}

/**
 * @fn void rtc_time_show(void)
 * @brief  Show rtc time.
 * @param  None
 * @return None
 */
void rtc_time_show(void)
{
	static uint8_t cnt = 0;
    rtc_time_t rtc_time_struct;
    rtc_date_t rtc_date_struct;	
    /* Get the current Time and date. */
	rtc_time_get(RTC_FORMAT_BIN, &rtc_time_struct);
	rtc_date_get(RTC_FORMAT_BIN, &rtc_date_struct);

	cnt++;
	if (cnt == 1)
	{
		cnt = 0;
		//printf("\r\nDATE:weekday%d year20%d month%d data%d %02d:%02d:%02d \r\n", rtc_date_struct.rtc_weekday, rtc_date_struct.rtc_year, rtc_date_struct.rtc_month, rtc_date_struct.rtc_date, rtc_time_struct.rtc_hours, rtc_time_struct.rtc_minutes, rtc_time_struct.rtc_seconds);
	}
}
/**
 * @fn void rtc_alarmshow(void)
 * @brief  Show rtc alarm.
 * @param  None
 * @return None
 */
void rtc_alarmshow(void)
{
    rtc_alarm_t rtc_alarm_struct;

    /* Get the current alarm. */
	rtc_alarm_get(RTC_FORMAT_BIN, &rtc_alarm_struct); 
   // printf("\n\r  The current alarm is: %0.2d:%0.2d:%0.2d \n\r", rtc_alarm_struct.alarm_time.rtc_hours, rtc_alarm_struct.alarm_time.rtc_minutes, rtc_alarm_struct.alarm_time.rtc_seconds);
}


/********************************************************************
function: rtc_wakeup_test
discript: RTC
entrance: none
return  : none
other   : none
********************************************************************/
void rtc_wakeup(void)
{				
    rtc_config();	
	__RTC_WRITE_PROTECTION_DISABLE();                //闂傚倷娴囧▔鏇㈠窗閹版澘鍑犲┑鐘宠壘缁狀垶鏌ｉ幋锝呅撻柡鍛憸缁辨帡骞撻幒婵囨櫗C闂備礁鎲￠崝鏍偡閳哄懎鏋侀柟鎹愵嚙濡﹢鏌曢崼婵囶棞妞ゅ繐鐖煎铏规崉閵娿儲鐎鹃梺鍝勵儏椤兘鐛箛娑欐櫢闁跨噦鎷�
	
	/*闂傚倷娴囧▔鏇㈠窗閹版澘鍑犲┑鐘宠壘缁狀垳鈧懓瀚伴崑濠傤焽濡ゅ懏鈷戦悹鎭掑妼閺嬫垿鏌＄€ｎ亶鐓兼鐐茬箻閹粓鎳為妷锔筋仧闂備礁鎼崐鍫曞磹閺嶎偀鍋撳顒傜Ш闁哄被鍔戦幃銏ゅ川婵犲嫪绱曢梻浣告贡閸忔﹢寮ㄩ崡鐑嗘富闁稿瞼鍋為悡銉╂煟閺傛寧鍟為柣蹇ｅ櫍閺岀喖宕欓妶鍡楊伓(闂傚倷娴囧▔鏇㈠窗閺団槅鏆伴梻鍌欑贰閸犳捇宕濋幋锕€鏋侀柟鎹愬煐閸嬫ɑ淇婇妶鍌氫壕闁诲繐绻愰幊姗€鐛箛娑欏€婚柤鎭掑劜濞呫垽姊哄Ч鍥у婵☆偅绮撻、姘堪閸繄顔嗛梺缁樺灱婵倝寮查幖浣圭厸闁稿本锚閳ь剚鐗滈埀顒佽壘缂嶅﹪寮婚妸鈺傚亜闁告稑锕︽导鍕⒑閻熸澘娈╅柟鍑ゆ嫹)*/	
	rtc_date_t rtc_date_struct;	
	rtc_date_struct.rtc_year   = 23;
	rtc_date_struct.rtc_month  = MONTH_JANUARY;
	rtc_date_struct.rtc_date   = 12;
	rtc_date_struct.rtc_weekday= WEEKDAY_SUNDAY;
	while(rtc_date_set(RTC_FORMAT_BIN,&rtc_date_struct)==ERROR){}  //闂傚倷娴囧▔鏇㈠窗閹版澘鍑犲┑鐘宠壘缁狀垶鏌ｉ幋锝呅撻柡鍛倐閺岋綁顢樿娴滅偞銇勯幒鎾跺弨妤犵偛绻愰悾锟犳焽閿旂晫绋勯梻鍌欐祰濞夋洟宕伴幇鏉垮嚑濠电姵鑹剧粻顖炴煟閹达絽袚闁哄懏鎮傞弻锟犲磼濡　鍋撻弽顐熷亾濮樼偓瀚�
		
	rtc_time_t rtc_time_struct;
	rtc_time_struct.am_pm_sel  = RTC_PM_HOUR12;  	//闂傚倷娴囧▔鏇㈠窗閹版澘鍑犲┑鐘宠壘缁狀垶鏌ｉ幋锝呅撻柡鍛倐閺岋繝宕掑Ο琛″亾閺嶎偀鍋撳鐐/闂傚倷娴囧▔鏇㈠窗閹版澘鍑犲┑鐘宠壘缁狀垶鏌ｉ幋锝呅撻柡鍛倐閺岋繝宕掑Ο琛″亾閺嶎偀鍋撳鐐
	rtc_time_struct.rtc_hours  = 10;              	//闂佽绻愮换鎰崲閹存繍娓婚柨鐕傛嫹
	rtc_time_struct.rtc_minutes= 57;             	//闂傚倷娴囧▔鏇㈠窗閹版澘鍑犲┑鐘宠壘缁狀垶鏌ㄩ悤鍌涘
	rtc_time_struct.rtc_seconds= 38;            	//闂傚倷娴囧▔鏇㈠窗閹版澘鍑犲┑鐘宠壘缁狀垶鏌ㄩ悤鍌涘
	while(rtc_time_set(RTC_FORMAT_BIN,&rtc_time_struct)==ERROR){}//闂傚倷娴囧▔鏇㈠窗閹版澘鍑犲┑鐘宠壘缁狀垶鏌ｉ幋锝呅撻柡鍛倐閺岋綁顢樿娴滅偞銇勯幒鎾跺弨妤犵偛绻愰悾锟犳焽閿旂晫绋勯梻浣告惈閸燁偊鎮ユ總绋挎瀬闁规崘顕уΛ姗€鏌曢崼婵囶棞妞ゅ骏鎷�	
	
    //printf("Time:%02d:%02d:%02d\r\n",rtc_time_struct.rtc_hours,rtc_time_struct.rtc_minutes,rtc_time_struct.rtc_seconds);
	//printf("DATE:week%d year20%d month%d data%d \r\n",rtc_date_struct.rtc_weekday,rtc_date_struct.rtc_year,rtc_date_struct.rtc_month,rtc_date_struct.rtc_date);	
	/*闂傚倷娴囧▔鏇㈠窗閹版澘鍑犲┑鐘宠壘缁狀垶鏌ｉ幋锝呅撻柡鍛倐閺岋繝宕掑Ο琛″亾閺嶎偀鍋撳顒傜Ш闁哄被鍔戦幃銏ゅ川婵犲嫪绱曢梻浣哥秺椤ユ捇宕楀鈧顐﹀箻鐠囧弶顥濋梺闈涚墕濡顢旈敓锟�*/		
	__EXTI_INTR_ENABLE(EXTI_LINE_17);
    __EXTI_EDGE_ENABLE(EXTI_EDGE_RISING, EXTI_LINE_17);	

		
    /*闁诲海鏁婚崑濠冪椤忓牆鏋侀柟鎹愵嚙濡﹢鏌曢崼婵囶棞妞ゅ繐鐖煎铏规崉閵娿儲鐎鹃梺鍝勵儏椤兘鐛箛娑欏€婚柤鎭掑劜濞呫垽姊洪崫鍕偓鍫曞磹閺嶎偀鍋撳鐐*/
	uint8_t i=0;			

    __RTC_FUNC_DISABLE(WAKEUP);//闂傚倷娴囧▔鏇㈠窗閹版澘鏄ラ柛娑欐綑缁犵喖鎮楅敐搴′簻妞ゅ繒螠AKE UP
    __RTC_WRITE_PROTECTION_DISABLE();
    
    rtc_wakeup_clock_config(RTC_WAKEUP_CLOCK_SPRE_16BITS);      //闂傚倷娴囧▔鏇㈠窗閹版澘鍑犲┑鐘宠壘缁狀垶鏌ｉ幋锝呅撻柡鍛倐閺岋繝宕掑Ο琛″亾閺嶎偀鍋撳顒傜Ш鐎殿噮鍣ｅ畷濂稿即閻斿憡顏熼梻浣告惈閸婂爼宕愰弽顐熷亾濮橆剛绉洪柡灞芥噺瀵板嫰骞囬鐔割仧闂備礁鎼崐鍫曞磹閺嶎偀鍋撳鐐  	
    rtc_wakeup_reload_value_set(Wakeup_Value-1);               //闂傚倷娴囧▔鏇㈠窗閹版澘鍑犲┑鐘宠壘缁狀垶鏌ｉ幋锝呅撻柡鍛倐閺岋繝宕掑Ο琛″亾閺嶎偀鍋撳杈╂憻AKE UP闂傚倷娴囧▔鏇㈠窗閹炬枼鏋旈柡鍥╁У婵ジ鎮峰▎蹇擃仼妞ゅ繐鐖煎铏规崉閵娿儲鐎鹃梺鍝勵儏椤兘鐛箛娑欏仾妞ゆ牭绲鹃ˉ濠囨⒒娴ｈ姤纭堕柛鐘冲姍瀹曟椽宕ㄩ妤€浜鹃梻鍫熺☉椤忣剟鏌熷ú璁抽偗妤犵偛绻橀幃婊堟嚍閵夛附顏熼梻浣告惈閸婂爼宕愰弽顐熷亾濮樼偓瀚�	
                 
    __RTC_INTR_ENABLE(RTC_INTR_BIT_WAKEUP);     //
    __RTC_FUNC_ENABLE(WAKEUP);                  //

    nvic_config_t nvic_InitStructurel;	
    nvic_InitStructurel.IRQn = IRQn_RTC;
    nvic_InitStructurel.priority = 0;
    nvic_InitStructurel.enable_flag= ENABLE;	
    nvic_init(&nvic_InitStructurel);	
    
    __RTC_WRITE_PROTECTION_ENABLE();
    
   // printf("\r\n RTCWakeUp_ready\r\n");
        
//    pmu_sleep_mode_set(PMU_SLEEP_ENTRY_WFI);  
	pmu_deep_sleep_mode_enter(PMU_LDO_LOW_POWER, PMU_SLEEP_ENTRY_WFE);
//  pmu_power_down_enter();		
//  printf("\r\n RTC WAKE UP 闂傚倷娴囧▔鏇㈠窗閹版澘鍑犲┑鐘宠壘缁狀垶鏌ㄩ悤鍌涘%d闂傚倷娴囧▔鏇㈠窗閺囩喓绠鹃柛銉墯閺呮煡鐓崶銊︾叆妞ゅ繒巍r\n",i+1);

}

void rtc_calendar_config(uint8_t year,uint8_t month,uint8_t date,uint8_t hour,uint8_t min,uint8_t sec)
{	
	__RTC_WRITE_PROTECTION_DISABLE();
		
	rtc_date_t rtc_date_struct;	
	rtc_date_struct.rtc_year   = year;
	rtc_date_struct.rtc_month  = month;
	rtc_date_struct.rtc_date   = date;
	rtc_date_struct.rtc_weekday= WEEKDAY_SUNDAY;
	while(rtc_date_set(RTC_FORMAT_BIN,&rtc_date_struct)==ERROR){}	

    rtc_time_t rtc_time_struct;
	rtc_time_struct.am_pm_sel  = RTC_AM_HOUR12; 
	rtc_time_struct.rtc_hours  = hour; 
	rtc_time_struct.rtc_minutes= min;
	rtc_time_struct.rtc_seconds= sec;
	while(rtc_time_set(RTC_FORMAT_BIN,&rtc_time_struct)==ERROR){}
}

void RTC_Set_Alarm(uint8_t hour,uint8_t min,uint8_t sec)
{ 
    __RCU_APB2_CLK_ENABLE(RCU_APB2_PERI_SYSCFG);
	rtc_time_t RTC_TimeTypeInitStructure;
	rtc_alarm_t RTC_AlarmTypeInitStructure;
	
	rtc_alarm_enable_ctrl(DISABLE);
	
	RTC_TimeTypeInitStructure.rtc_hours=hour;
	RTC_TimeTypeInitStructure.rtc_minutes=min;
	RTC_TimeTypeInitStructure.rtc_seconds=sec;
	RTC_TimeTypeInitStructure.am_pm_sel=RTC_AM_HOUR12;
  
	RTC_AlarmTypeInitStructure.date_weekday=WEEKDAY_SUNDAY;
	RTC_AlarmTypeInitStructure.date_weekday_sel=RTC_DATE_WEEKDAY_SEL_WEEKDAY;
	RTC_AlarmTypeInitStructure.alarm_mask=RTC_ALARM_MASK_DATE_WEEKDAY;
	RTC_AlarmTypeInitStructure.alarm_time=RTC_TimeTypeInitStructure;
	
    rtc_alarm_set(RTC_FORMAT_BIN,&RTC_AlarmTypeInitStructure);
    __RTC_FLAG_CLEAR(RTC_FLAG_BIT_WAKEUP);
	__RTC_INTR_ENABLE(RTC_INTR_BIT_ALARM);
	rtc_alarm_enable_ctrl(ENABLE);
	
	nvic_config_t nvic_InitStructurel;
	nvic_InitStructurel.IRQn = IRQn_RTC;
	nvic_InitStructurel.priority = 0x01;
	nvic_InitStructurel.enable_flag= ENABLE;
	
	nvic_init(&nvic_InitStructurel);
}

void deepsleep_RTCalarm_wk_test(void)
{
    rtc_calendar_config(23,7,11,11,35,20);
	RTC_Set_Alarm(11,35,25);	

	//printf("RTCalarm_ready\r\n");
    while(1)
    {
        DeepSleep_Enter();
    }
}

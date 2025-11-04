/**
  * @file    LPTIM/LPTIM_Timeout/main.c
  * @brief   Main program body
  * @author  ChipSea MCU Group
  * @version V1.0.0
  * @date   2022.06.30
  * @copyright CHIPSEA TECHNOLOGIES (SHENZHEN) CORP.
  * @note
  * <h2><center>&copy; COPYRIGHT 2021 ChipSea</center></h2>
  *
  * @verbatim
  ----------------------- How to used this project---------------------------

  * @par Example Description


  This is LPTIM timeout example. It configures the LPTIM after timeout wakeup system from deepsleep.
  

  - Hardware Description

          cbm858xm
     ------------------
     |                |
     |                |
     |                |
     |              TX|-->log
     |                |
     |                |
     |                |
     ------------------

  - Test steps
      a. Rebuild the project and load the image into target memory.
      b. Run the example in debug mode.
      c. Input the pulse signal, generate an interrupt once a thousand times, and print the result.

  * @endverbatim
  *
  */
#include "lptm.h"

/**
 * @fn void lptime_config(void)
 * @brief  Configure the LPTIM.
 * @param  None
 * @return None
 */
void lptime_config(void)
{
    lptim_config_t ptr_config;
    nvic_config_t nvic_config_struct;

    __RCU_APB1_CLK_ENABLE(RCU_APB1_PERI_LPTIM1);  // LPTIM clock enable
    //zxy __RCU_AHB_CLK_ENABLE(RCU_AHB_PERI_GPIOA);    // GPIOA clock enable

    /* Enable the LRC clock*/
    rcu_lrc_config(RCU_ENABLE_BIT_LRC_CLK);
    /* Config the LPTIM use LRC clock*/   
    rcu_lptim1_config(RCU_LPTIM1_CFG_LRC);
    /* LPTIM configuration pulse counter mode:
       The LPTIM output reflects the compare results between LPTIMx_ARR and LPTIMx_CMP registers.
       Prescaler division factor is 1.*/
    ptr_config.polarity = LPTIM_OUTPUT_POLARITY_REGULAR;
    ptr_config.prescaler = LPTIM_PRESCALER_DIV1;
    ptr_config.waveform = LPTIM_OUTPUT_WAVEFORM_PWM;
    lptim_init(&ptr_config);
    
    /* The counter is incremented after each valid clock pulse on LPTIM external input1 */
    lptim_count_mode_set(LPTIM_COUNT_INTER_CLOCK); 
    // #if softtrigger
    // lptim_trigger_config(LPTIM_EXT_TRIG0, LPTIM_TRIG_FILTER_NONE, LPTIM_TRIG_POLARITY_SW);//software trigger
    // #endif
    /* Sets the LPTIM auto load match interrupt */
    //zxy __LPTIM_INTR_ENABLE(LPTIM_IER_CMPMIE);

    __LPTIM_TIMOUT_ENABLE();
    
    /* Enable the LPTIM Interrupt */
    nvic_config_struct.IRQn = IRQn_LPTIM;
    nvic_config_struct.priority = 0x02;
    nvic_config_struct.enable_flag = ENABLE;
    nvic_init(&nvic_config_struct);

     
    
    /* Enables the LPTIM */
    __LPTIM_INTR_ENABLE(LPTIM_IER_ARRMIE);
    // __LPTIM_INTR_ENABLE(LPTIM_IER_REPOKIE);
    // __LPTIM_INTR_ENABLE(LPTIM_ISR_ARROK);
    
	/* Enables the LPTIM 如果LPTIM时钟源选的LRC,定时周期=（1/10k）*(ARR+1) */  
    __LPTIM_ENABLE();
    /* Sets the LPTIM ARR Register auto reload value 10  1ms定时周期 */
    __LPTIM_AUTO_RELOAD_SET(NormalPeriod*10-1);  
    lptim_start_mode_set(LPTIM_START_MODE_CONTINUOUS);
    

}

void lptim_timer_reload(uint16_t reload_ms)
{
    if(Periodtime == reload_ms)
    {
        return;
    }
    Periodtime = reload_ms;
    __LPTIM_ENABLE();
    __LPTIM_AUTO_RELOAD_SET(reload_ms * 10 - 1);

    lptim_start_mode_set(LPTIM_START_MODE_CONTINUOUS);
}
void lptim_timer_disable(void)
{
   __LPTIM_DISABLE();
}


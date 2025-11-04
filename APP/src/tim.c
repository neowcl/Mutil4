#include"tim.h"

/**
 * @fn  void time_config(void)
 * @brief  Configure the TIM IRQ Handler.
 * @param  None
 * @return None
 */
void time_config(void)
{
    tim_base_t timer_config_struct;
    nvic_config_t nvic_config_struct;
    uint16_t prescaler_value = 0;

    rcu_hclk_config(RCU_HCLK_CFG_SYSCLK_DIV1);
    rcu_pclk_config(RCU_PCLK_CFG_HCLK_DIV1);    
    __RCU_APB1_CLK_ENABLE(RCU_APB1_PERI_TIM3); // TIM3 clock enable

    prescaler_value = (uint16_t)(SystemCoreClock / 1000000) - 1; // Compute the prescaler value

    // Time base configuration
    timer_config_struct.period = 100;
    timer_config_struct.predivider = prescaler_value;
    timer_config_struct.clk_division = 0;
    tim_base_init(TIM3, &timer_config_struct);

    // Enable the TIM3  Interrupt.
    nvic_config_struct.IRQn = IRQn_TIM3;
    nvic_config_struct.priority = 1;
    nvic_config_struct.enable_flag = ENABLE;
    nvic_init(&nvic_config_struct);

    __TIM_INTR_ENABLE(TIM3, TIM_INTR_UPDATE); /* TIM Interrupts enable */
    __TIM_ENABLE(TIM3);                                                                       // TIM3 enable
}

void time_enable(void)
{
    __TIM_ENABLE(TIM3); 
}
void time_disable(void)
{
    __TIM_DISABLE(TIM3); 
}
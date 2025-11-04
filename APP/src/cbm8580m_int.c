/**
 * @file    cbm858xm_int.c
 * @brief   Main Interrupt Service Routines. It provides template for
 *            all exceptions handler and  peripherals interrupt service routine.
 * @author  ChipSea MCU Group
 * @version V1.0.0
 * @date   2022.06.29
 * @copyright CHIPSEA TECHNOLOGIES (SHENZHEN) CORP.
 * @note
 * <h2><center>&copy; COPYRIGHT 2021 ChipSea</center></h2>
 *
 */

#include "main.h"
#include "comm_protocol.h"


volatile uint8_t get_iic_arblo = 0;
volatile uint8_t get_iic_buserr = 0;

/** @addtogroup 8580M_HAL_Examples
 * @{
 */

/** @addtogroup RTC_Calendar_Examples
 * @{
 */
volatile uint16_t init_delay;
volatile uint32_t timing_delay;
volatile uint8_t hwd_recovery;
volatile uint32_t systick_ms;
volatile uint8_t is_exti_trip = 0;

volatile uint8_t register_addr ;

volatile uint8_t is_pack_falling = 0;

volatile uint8_t write_flag = 0;
volatile uint8_t iic_rx_cnt = 0;
volatile uint8_t iic_tx_cnt = 0;
uint8_t ee_buff[17] = {0xee,0xD0, 0x0D, 0x00, 0x00, 0xF7, 0x94, 0x02, 0x43, 
                     0x42, 0x4D, 0x58, 0x35, 0x38, 0x58, 0x00, 0xBC};

void EXTI_Proc();
/**
 * @fn void NMI_Handler(void)
 * @brief  This function handles NMI exception.
 * @param  None
 * @return None
 */
void NMI_Handler(void)
{
}

/**
 * @fn void HardFault_Handler(void)
 * @brief  This function handles Hard Fault exception.
 * @param  None
 * @return None
 */
void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
    //printf("\r\n HardFault_Handler!\r\n");
  }
}

/**
 * @fn void SVC_Handler(void)
 * @brief  This function handles SVCall exception.
 * @param  None
 * @return None
 */
void SVC_Handler(void)
{
}

/**
 * @fn void PendSV_Handler(void)
 * @brief  This function handles PendSVC exception.
 * @param  None
 * @return None
 */
void PendSV_Handler(void)
{
}

/**
 * @fn void SysTick_Handler(void)
 * @brief  This function handles SysTick Handler.
 * @param  None
 * @return None  1ms
 */
void SysTick_Handler(void)
{
  if (timing_delay != 0x00)
  {
    // printf("timing = %u \n ",timing_delay);
    timing_delay--;
  }

  if (f_slvto_req) // IIC start nerver receive stop will timeout
  {
    aslvto_cnt++;
  }

  prehiegdelay++;
  if(prehiegdelay >= 250)
  {
    prehiegdelay = 0;
    f_pres_en = ON;
  }

  prelowdelay++;
}

/**
 * @fn void EXTI0_1_IRQHandler(void)
 * @brief  This function handles External line 0 interrupt request.
 * @param  None
 * @return None
 */
void EXTI0_1_IRQHandler(void)
{
  if (__EXTI_FLAG_STATUS_GET(EXTI_LINE_0) != RESET)
  {
    /* Set the new RTC configuration. */
    //		rtc_time_regulate();
    /* Clear the SEL Button EXTI line bit. */
    __EXTI_FLAG_CLEAR(EXTI_LINE_0);
  }
}

/**
 * @fn void EXTI4_15_IRQHandler(void)
 * @brief  This function handles External lines 9 to 5 interrupt request.
 * @param  None
 * @return None  1S
 */

void LPTIM_IRQHandler(void)
{
  volatile static uint16_t CNT = 0;
  uint32_t CntReg = 0;

  if (__LPTIM_FLAG_STATUS_GET(LPTIM_ISR_ARRM) == SET)
  {
    __LPTIM_FLAG_CLEAR(LPTIM_ICR_ARRMCF);

    // CNT++;
    // if (CNT * NormalPeriod >= Periodtime)
    // {
    //   CNT = 0;
      f_curr_en = 1;

      if (f_no_smbus == OFF)
      {
        no_com_cnt++;
        CntReg = no_com_cnt * Periodtime / 1000;
        if (CntReg >= D_Sleep_Bus_TimeOut)
        {
          no_com_cnt = 0;
          f_no_smbus = ON;
        }
      }

      if (f_lowBus_timout == OFF)
      {
        lowBus_cnt++;
        CntReg = lowBus_cnt * Periodtime / 1000;
        if (CntReg >= D_Sleep_Bus_TimeOut)
        {
          lowBus_cnt = 0;
          f_lowBus_timout = ON;
        }
      }

      if (f_sdv)
      {
        SDV_CNT += Periodtime;
      }
      if (f_sdm)
      {
        SDM_CNT += Periodtime;
      }
      if (SDM_CMD_CNT == 1)
      {
        systick_ms += Periodtime;
        if (systick_ms >= 4000)
        {
          systick_ms = 0;
          SDM_CMD_CNT = 0;
        }
      }
      else
      {
        systick_ms = 0;
      }
      if (timebaseflag)
      {
        timeshutdown_timer += Periodtime;
      }
      EntryExitShip_TimeOutChk();

      SoftTimerDec();
      if (t_com0d == 100)
      {
        COFF_delay += Periodtime;
      }
      else
      {
        COFF_delay = 0;
      }
    // }
    
  }
  if (__LPTIM_FLAG_STATUS_GET(LPTIM_ISR_UE) == SET)
  {
    __LPTIM_FLAG_CLEAR(LPTIM_ICR_UECF);

  }

  if (__LPTIM_FLAG_STATUS_GET(LPTIM_ISR_ARROK) == SET)
  {
    __LPTIM_FLAG_CLEAR(LPTIM_ICR_ARROKCF);
  }
  if (__LPTIM_FLAG_STATUS_GET(LPTIM_ISR_CMPM) == SET)
  {
    __LPTIM_FLAG_CLEAR(LPTIM_ISR_CMPM);
  }

  if (__LPTIM_FLAG_STATUS_GET(LPTIM_ISR_REPOK) == SET)
  {
    __LPTIM_FLAG_CLEAR(LPTIM_ICR_REPOKCF);
  }
  if (__LPTIM_FLAG_STATUS_GET(LPTIM_ISR_CMPOK) == SET)
  {
    __LPTIM_FLAG_CLEAR(LPTIM_ICR_CMPOKCF);
  }
}

void EXTI4_15_IRQHandler(void)
{
  // is_exti_trip = 1;
  if ((__EXTI_FLAG_STATUS_GET(EXTI_LINE_5) != RESET))
  {
    /* Clear the EXTI_LINE_ bit. */
    __EXTI_FLAG_CLEAR(EXTI_LINE_5);
    //("Voltage Falling!\n");
    //is_pack_falling = 1;
    // NVIC->ICER[0] = 0x800;
    // __EXTI_INTR_DISABLE(EXTI_LINE_11);
    // __GPIO_PIN_SET(GPIOA, GPIO_PIN_8);
    // __GPIO_PIN_RESET(GPIOA, GPIO_PIN_8);

  }


  if ((__EXTI_FLAG_STATUS_GET(EXTI_LINE_11) != RESET))
  {
    /* Clear the EXTI_LINE_ bit. */
    __EXTI_FLAG_CLEAR(EXTI_LINE_11);
    NVIC->ICER[0] = 0x800;
    __EXTI_INTR_DISABLE(EXTI_LINE_11);
    __GPIO_PIN_SET(GPIOA, GPIO_PIN_8);
    __GPIO_PIN_RESET(GPIOA, GPIO_PIN_8);
    // NVIC->ICER[0] =0x800;
    // NVIC->ICPR[0] =0x800;
  }
  if((__EXTI_FLAG_STATUS_GET(EXTI_LINE_13) != RESET))
  {
      __EXTI_FLAG_CLEAR(EXTI_LINE_13);
      is_exti_trip = 1;
  }
// EXTI_Proc();
  // __EXTI_FLAG_CLEAR(EXTI_LINE_13);
}

void RTC_IRQHandler(void)
{
  if (__RTC_INTR_STATUS_GET(WAKEUP) == SET) // WK_UP中断?
  {
    //        gpio_pa8_toggle();
    __RTC_FLAG_CLEAR(RTC_FLAG_BIT_WAKEUP); // 清除中断标志
    //printf("\r\nRTC_WAKEUP INTR trigger!\r\n");
  }
  else if (__RTC_INTR_STATUS_GET(ALARM) == SET)
  {
    //         gpio_pa9_toggle();
    __RTC_FLAG_CLEAR(RTC_FLAG_BIT_ALARM); // 清除中断标志
   // printf("\r\nRTC_ALARM INTR trigger!\r\n");
  }

  __EXTI_FLAG_CLEAR(EXTI_LINE_17); // 清除中断线17的中断标志
}

void I2C1_IRQHandler(void)
{
  hwd_recovery = 1;
    
  if(D_Sleep_Bus_TimeOut)
  {
    f_last_timeout_status = f_no_smbus;
    f_no_smbus = OFF;
  }
  no_com_cnt = 0;
  // __disable_irq();
  if (__I2C_INTR_STATUS_GET(I2C1, ADRM) != RESET)
  {
    if (I2C1->STS & I2C_STS_DIRF)
    {
      I2C1->STS |= I2C_STS_TXEF;
      CRC8_Calc(OWN_ADDRESS | 0x01);
      iic_tx_cnt = 0;
    }
    else
    {
      iic_rx_cnt = 0;
      apec = 0;
      CRC8_Calc(OWN_ADDRESS);
    }
    __I2C_FLAG_CLEAR(I2C1, I2C_FLAG_ADRM);
  }
  else if (__I2C_INTR_STATUS_GET(I2C1, RXNE) != RESET)
  {
    rx_buffer[iic_rx_cnt++] = __I2C_DATA_RECV(I2C1);
    if (iic_rx_cnt == 1)
    {
      CRC8_Calc(rx_buffer[0]);
      register_addr=rx_buffer[0];
      read_processmsg(rx_buffer[0]);
    }
    else if(iic_rx_cnt > BUFFER_LEN)
    {
      iic_rx_cnt = BUFFER_LEN;
    }
  }
  else if (__I2C_INTR_STATUS_GET(I2C1, TXINT) != RESET)
  {
    if(register_addr != 0xee)
    {
      if (iic_tx_cnt == nReadLen)
      {
        __I2C_DATA_SEND(I2C1, apec);
      }
      else
      {
       // tx_buffer[0]=0x30;
        __I2C_DATA_SEND(I2C1, tx_buffer[iic_tx_cnt]);
        CRC8_Calc(tx_buffer[iic_tx_cnt]);
        iic_tx_cnt++;
      }
    }
    else{
      //rx_buffer[0]=0x20;
      __I2C_DATA_SEND(I2C1,ee_buff[iic_tx_cnt++]);
    }

  }
  else if (__I2C_INTR_STATUS_GET(I2C1, STOP) != RESET)
  {
    __I2C_FLAG_CLEAR(I2C1, I2C_FLAG_STOP);
      write_flag = 1;
    write_processmsg(rx_buffer, iic_rx_cnt);
  }
  else if (__I2C_INTR_STATUS_GET(I2C1, NACK) != RESET)
  {
    __I2C_FLAG_CLEAR(I2C1, I2C_FLAG_NACK);
  }
  else if (__I2C_INTR_STATUS_GET(I2C1, ARBLO) != RESET)
  {

    __I2C_FLAG_CLEAR(I2C1, I2C_FLAG_ARBLO);
    get_iic_arblo=1;
  }
  else if (__I2C_INTR_STATUS_GET(I2C1, BUSERR) != RESET)
  {
    __I2C_FLAG_CLEAR(I2C1, I2C_FLAG_BUSERR);
     get_iic_buserr=1;
  }
  else if (__I2C_INTR_STATUS_GET(I2C1, OVR) != RESET)
  {
    __I2C_FLAG_CLEAR(I2C1, I2C_FLAG_OVR);
  }
  // __enable_irq();
}

void TIM3_IRQHandler(void)
{
  if (__TIM_INTR_STATUS_GET(TIM3, UPDATE) != RESET)
  {
    __TIM_FLAG_CLEAR(TIM3, TIM_FLAG_UPDATE);
    // prescnt++;
    // if (prescnt >= 250)
    // {
    //   prescnt = 0;
    // }
    
  }
}
/**
 * @}
 */
void EXTI_Proc()
{
  uint8_t status = 0;
  if (is_exti_trip)
  {
    is_exti_trip = 0;
    /* cc采样完成 */
    afe_int_periph_int_flag_get(INT_ISRC0_CC_INT_FLAG, &status);
    if (status == SET)
    {
      f_CC_int = 1;
      afe_int_periph_int_flag_clear(INT_ISRC0_CC_INT_FLAG);
    }
    /* adc采样完成 */
    afe_int_periph_int_flag_get(INT_ISRC0_VADC_INT_FLAG, &status);
    if (status == SET)
    {
      f_VADC_int = 1;
      afe_int_periph_int_flag_clear(INT_ISRC0_VADC_INT_FLAG);
    }
    afe_int_periph_int_flag_get(INT_ISRC0_TIMERA_INT_FLAG, &status);
    if (status == SET)
    {
      afe_int_periph_int_flag_clear(INT_ISRC0_TIMERA_INT_FLAG);
    }

    afe_int_periph_int_flag_get(INT_ISRC0_WKCP_INT_FLAG, &status);
    if (status == SET)
    {
      f_wakeup_int = 1;
      afe_wkcp_comparator_enable_ctrl(DISABLE);
      afe_int_periph_int_enable_ctrl(INT_IE0_WKCP_INT, DISABLE);
      afe_int_periph_int_flag_clear(INT_ISRC0_WKCP_INT_FLAG);
    }

    afe_int_periph_int_flag_get(INT_ISRC0_AOLD_INT_FLAG, &status);
    if (status == 1)
    {
      if (!SafetyStatus(AOLD))
      {
        SafetyStatus(AOLD) = ON;
        if(aoldl_counter == 0)
        {
          life_Time_Protect_Event(LT_AOLD);
        }
       
        aoldl_counter++; // aoldl counter
        //printf("aold is happen\r\n");
      }
      Hdp_ClearStatus(INT_ISRC0_AOLD_INT_FLAG);
    }

    afe_int_periph_int_flag_get(INT_ISRC0_ASCC_INT_FLAG, &status);
    if (status == 1)
    {
      if (!SafetyStatus(ASCC))
      {
        SafetyStatus(ASCC) = ON;
        if(asccl_counter == 0)
        {
          life_Time_Protect_Event(LT_ASCC);
        }
        asccl_counter++;
        //printf("ascc is happen\r\n");
      }

      Hdp_ClearStatus(INT_ISRC0_ASCC_INT_FLAG);
    }
    afe_int_periph_int_flag_get(INT_ISRC0_ASCD1_INT_FLAG, &status);
    if (status == 1)
    {
      if (!SafetyStatus(ASCD))
      {
        SafetyStatus(ASCD) = ON;
        if(ascdl_counter == 0)
        {
          life_Time_Protect_Event(LT_ASCD);
        }
        ascdl_counter++; // ASCDL Count
       // printf("ascd1 is happen\r\n");
      }
      Hdp_ClearStatus(INT_ISRC0_ASCD1_INT_FLAG);
    }
    afe_int_periph_int_flag_get(INT_ISRC0_ASCD2_INT_FLAG, &status);
    if (status == 1)
    {
      if (!SafetyStatus(ASCD))
      {
        SafetyStatus(ASCD) = ON;
        ascdl_counter++; // ASCDL Count
        //printf("ascd2 is happen\r\n");
      }
      Hdp_ClearStatus(INT_ISRC0_ASCD2_INT_FLAG);
    }
    afe_int_periph_int_flag_get(INT_ISRC0_FUSE_INT_FLAG, &status);
    if (status == 1)
    {
      //printf("fuse trip!\n");
      afe_int_periph_int_flag_clear(INT_ISRC0_FUSE_INT_FLAG);
    }
    // pack电压唤醒
    afe_int_periph_int_flag_get(INT_ISRC1_PACKH2P25V_INT_FLAG, &status);
    if (status == 1)
    {
      status = 0;
      afe_int_periph_int_flag_clear(INT_ISRC1_PACKH2P25V_INT_FLAG);
      //printf("INT_ISRC1_PACKH2P25V_INT_FLAG set\n");
    }
  }
}


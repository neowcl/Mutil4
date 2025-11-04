/**
* @file        cbm858xm_usart.c
* @brief       This file provides all the basic USART firmware functions.
* @author      ChipSea MCU Group
* @version     1.0.0
* @date        2022.05.23
* @copyright   CHIPSEA TECHNOLOGIES (SHENZHEN) CORP.
* @note        
****************************************************************************************************
* @par Modify record:
* <tr><th>Date          <th>Version    <th>Author     <th>Description
* <tr><td>2022.05.23    <td>1.0.0      <td>ChipSea    <td>
* -# 
* </table>
*
****************************************************************************************************
*/


/***************************************************************************************************
 * @includes
***************************************************************************************************/
#include "cbm858xm_usart.h"
#include "cbm858xm_rcu.h"


/***************************************************************************************************
 * @definitions
***************************************************************************************************/
#define USART_CTR1_CLEAR_MASK         ((uint32_t)(USART_CTR1_DL  | USART_CTR1_PEN | USART_CTR1_ODDS | \
                                      USART_CTR1_TEN | USART_CTR1_REN | USART_CTR1_DH))  /*!< USART CR1 register bits clear Mask. */

#define USART_CTR2_CLOCK_CLEAR_MASK   ((uint32_t)(USART_CTR2_CKEN | USART_CTR2_CPOL | USART_CTR2_CPHA | \
                                       USART_CTR2_CKLEN))                                /*!< USART CR2 register bits clear Mask. */

#define USART_CTR3_CLEAR_MASK         ((uint32_t)(USART_CTR3_RTSEN | USART_CTR3_CTSEN))  /*!< USART CR3 register bits clear Mask. */

#define USART_INT_MASK                ((uint32_t)0x000000FF)							 /*!< USART Interrupts mask. */


/** @addtogroup CBM858xM_StdPeriph_Driver
  * @{
  */

/** @defgroup USART USART
  * @brief    USART driver modules
  * @{
  */

///@cond

/***************************************************************************************************
 * @variables
***************************************************************************************************/


/***************************************************************************************************
 * @functions
***************************************************************************************************/
/**
  * @brief  Initializes the ptr_usart peripheral according to the specified parameters in the ptr_config.
  * @param  ptr_usart: Pointer to USARTx where x can be 1, 2.
  * @param  ptr_config: Pointer to a usart_config_t structure containing the configuration for the specified USART
  *                     peripheral.
  * @return None.
  */
void usart_init(usart_reg_t* ptr_usart, usart_config_t* ptr_config)
{
    uint32_t divider = 0;
    uint32_t freq = 0;
    uint32_t reg = 0;
    rcu_clock_t rcu_clock;
  
    ASSERT(USART_SELECT_CHECK(ptr_usart));
    ASSERT(USART_BAUD_RATE_CHECK(ptr_config->baud_rate));  
    ASSERT(USART_DATA_WIDTH_CHECK(ptr_config->data_width));
    ASSERT(USART_STOP_BIT_CHECK(ptr_config->stop_bits));
    ASSERT(USART_PARITY_CHECK(ptr_config->parity));
    ASSERT(USART_MODE_CHECK(ptr_config->usart_mode));
    ASSERT(USART_FLOW_CONTROL_CHECK(ptr_config->flow_control));
  
    /* Disable USART. */
    ptr_usart->CTR1 &= (uint32_t)~((uint32_t)USART_CTR1_UEN);  

    /* Set STOPLEN[13:12]. */   
    MODIFY_REG(ptr_usart->CTR2, USART_CTR2_STOPLEN, ptr_config->stop_bits);
    
    /* Configure the USART data width, parity and mode.  */
    MODIFY_REG(ptr_usart->CTR1, USART_CTR1_CLEAR_MASK, (uint32_t)(ptr_config->data_width | 
        ptr_config->parity | ptr_config->usart_mode));

    MODIFY_REG(ptr_usart->CTR3, USART_CTR3_CLEAR_MASK, ptr_config->flow_control);

    /* Configure the USART baud rate. */
    rcu_clk_freq_get(&rcu_clock);  
    if (ptr_usart == USART1)
    {
        freq = rcu_clock.usart1_clk_freq;
    }
    else
    {
        freq = rcu_clock.pclk_freq;
    }
  
    if ((ptr_usart->CTR1 & USART_CTR1_OVRS) != 0)
    {
        /* (divider * 10) Computing in case oversampling mode is 8 samples. */
        divider = (uint32_t)((2 * freq) / (ptr_config->baud_rate));
        reg  = (uint32_t)((2 * freq) % (ptr_config->baud_rate));
    }
    else
    {
        /* (divider * 10) Computing in case oversampling mode is 16 samples. */
        divider = (uint32_t)((freq) / (ptr_config->baud_rate));
        reg  = (uint32_t)((freq) % (ptr_config->baud_rate));
    }

    /* Round the divider : if fractional part i greater than 0.5 increment divider. */
    if (reg >=  (ptr_config->baud_rate) / 2)
    {
        divider++;
    }

    /* Implement the divider in case oversampling mode is 8 Samples */
    if ((ptr_usart->CTR1 & USART_CTR1_OVRS) != 0)
    {
        /* Get the LSB of divider and shift it to the right by 1 bit, update the divider value. */
        reg = (divider & (uint16_t)0x000F) >> 1;
        divider = (divider & (uint16_t)0xFFF0) | reg;
    }

    /* Write divider to baud rate register. */
    ptr_usart->BRT = (uint16_t)divider;
}


/**
  * @brief  Fills each ptr_config member with its default value.
  * @param  ptr_config: Pointer to a usart_config_t structure containing the configuration for the specified USART
  *                     peripheral.
  * @return None.
  */
void usart_config_struct_init(usart_config_t* ptr_config)
{
    /* ptr_config: Members initialized with default value. */
    ptr_config->baud_rate = 9600;
    ptr_config->data_width = USART_DATA_WIDTH_8;
    ptr_config->stop_bits = USART_STOP_BIT_1;
    ptr_config->parity = USART_PARITY_NO;
    ptr_config->usart_mode = USART_MODE_RX | USART_MODE_TX;
    ptr_config->flow_control = USART_FLOW_CONTROL_NONE; 
}


/**
  * @brief  Initializes the USARTx peripheral Clock according to the specified parameters in the ptr_clock.
  * @param  ptr_usart: Pointer to USARTx where x can be 1, 2.
  * @param  ptr_clock: Pointer to a usart_clock_t structure that contains the configuration information for the
  *                    specified USART peripheral.
  * @return None.  
  */
void usart_clock_init(usart_reg_t* ptr_usart, usart_clock_t* ptr_clock)
{
    /* Check the parameters. */
    ASSERT(USART_SELECT_CHECK(ptr_usart));
    ASSERT(USART_CLOCK_CHECK(ptr_clock->clock_flag));
    ASSERT(USART_CPOL_CHECK(ptr_clock->usart_cpol));
    ASSERT(USART_CPHA_CHECK(ptr_clock->usart_cpha));
    ASSERT(USART_LAST_BIT_CHECK(ptr_clock->usart_lastbit));
        
    /* Configure the USART clock, CPOL, CPHA, CKLEN. */
    MODIFY_REG(ptr_usart->CTR2, USART_CTR2_CLOCK_CLEAR_MASK, (uint32_t)(ptr_clock->clock_flag |
               ptr_clock->usart_cpol | ptr_clock->usart_cpha | ptr_clock->usart_lastbit));
}


/**
  * @brief  Fills each ptr_clock member with its default value.
  * @param  ptr_clock: Pointer to a usart_clock_t structure which will be initialized.
  * @return None.
  */
void usart_clock_struct_init(usart_clock_t* ptr_clock)
{
    /* ptr_clock: Members default value. */
    ptr_clock->clock_flag = USART_CLOCK_DISABLE;
    ptr_clock->usart_cpol = USART_CPOL_LOW;
    ptr_clock->usart_cpha = USART_CPHA_EDGE_1;
    ptr_clock->usart_lastbit = USART_LAST_BIT_DISABLE;
}


/**
  * @brief  Sets the system clock prescaler.
  * @param  ptr_usart: Pointer to USARTx where x can be 1, 2.
  * @param  value: Specifies the prescaler clock.
  * @note   This function has to be called before calling usart_enable_ctrl() function.
  * @return None.
  */
void usart_prescaler_set(usart_reg_t* ptr_usart, uint8_t value)
{
    ASSERT(USART_SELECT_CHECK(ptr_usart));

    /* Set the USART prescaler */
    MODIFY_REG(ptr_usart->GTPDIV, USART_GTPDIV_PDIV, value);
}


/**
  * @brief  Selects the USART WakeUp method for stop mode.
  * @param  ptr_usart: Pointer to USARTx where x can be 1 to select USART peripheral.
  * @param  wakeup_source: Specifies the selected USART wakeup method.
  *         It can be one of the following values:
  *           @arg USART_WAKEUP_SOURCE_ADDR_MATCH: wakeup on address match.
  *           @arg USART_WAKEUP_SOURCE_START_BIT: wakeup on Start bit detection.
  *           @arg USART_WAKEUP_SOURCE_RXNE: wakeup on RXNE.
  * @note   This function has to be called before calling usart_enable_ctrl() function.
  * @return None.
  */
void usart_stop_mode_wakeup_config(usart_reg_t* ptr_usart, uint32_t wakeup_source)
{
    ASSERT(USART_SELECT_1_CHECK(ptr_usart));
    ASSERT(USART_WAKEUP_SOURCE_CHECK(wakeup_source));

    /* Set the USART WakeUp method for stop mode. */
    MODIFY_REG(ptr_usart->CTR3, USART_CTR3_WKUPMTHD, wakeup_source);
}


/**
  * @brief  Selects the USART auto baud rate method.
  * @param  ptr_usart: Pointer to USARTx where x can be 1 to select USART peripheral.
  * @param  rate_value: Specifies the selected USART auto baud rate method.
  *          This parameter can be one of the following values:
  *            @arg USART_AUTO_RATE_MEASURE_START_BIT: Start Bit duration measurement.
  *            @arg USART_AUTO_RATE_MEASURE_FALLING_EDGE: Falling edge to falling edge measurement.
  * @note   This function has to be called before calling usart_enable_ctrl() function.
  * @return None.
  */
void usart_auto_baud_rate_config(usart_reg_t* ptr_usart, uint32_t rate_value)
{
    ASSERT(USART_SELECT_1_CHECK(ptr_usart));
    ASSERT(USART_AUTO_RATE_MEASURE_CHECK(rate_value));

    /* Set the USART auto baud rate method. */
    MODIFY_REG(ptr_usart->CTR2, USART_CTR2_ABRSEL, rate_value);
}


/**
  * @brief  Sets the address of the USART node.
  * @param  ptr_usart: Pointer to USARTx where x can be 1, 2.
  * @param  addr: Indicates the address of the USART node.
  * @return None.
  */
void usart_address_set(usart_reg_t* ptr_usart, uint8_t addr)
{
    ASSERT(USART_SELECT_CHECK(ptr_usart));

    /* Set the USART address */
    MODIFY_REG(ptr_usart->CTR2, USART_CTR2_UADR, (uint32_t)addr << 24);
}


/**
  * @brief  Selects the USART WakeUp method from mute mode.
  * @param  ptr_usart: Pointer to USARTx where x can be 1, 2.
  * @param  flag: Specifies the USART wakeup method.
  *          This parameter can be one of the following values:
  *            @arg USART_RX_WAKEUP_IDLE_LINE: WakeUp by an idle line detection.
  *            @arg USART_RX_WAKEUP_ADDR_MARK: WakeUp by an address mark.
  * @return None.
  */
void usart_recv_wakeup_config(usart_reg_t* ptr_usart, uint32_t flag)
{
    ASSERT(USART_SELECT_CHECK(ptr_usart));
    ASSERT(USART_RX_WAKEUP_CHECK(flag));

    /* Set the  USART WakeUp method from mute mode. */
    MODIFY_REG(ptr_usart->CTR1, USART_CTR1_RXWKUPS, flag);
}


/**
  * @brief  Configure the the USART Address detection length.
  * @param  ptr_usart: Pointer to USARTx where x can be 1, 2.
  * @param  addr: Specifies the USART address length detection.
  *          This parameter can be one of the following values:
  *            @arg USART_ADDRESS_4BIT: 4-bit address length detection.
  *            @arg USART_ADDRESS_7BIT: 7-bit address length detection.
  * @return None.
  */
void usart_addr_detect_config(usart_reg_t* ptr_usart, uint32_t addr)
{
    ASSERT(USART_SELECT_CHECK(ptr_usart));
    ASSERT(USART_ADDRESS_BIT_CHECK(addr));

    /* Set the USART Address detection length. */
    MODIFY_REG(ptr_usart->CTR2, USART_CTR2_ADRM7, addr);
}


/**
  * @brief  Sets the USART LIN Break detection length.
  * @param  ptr_usart: Pointer to USARTx where x can be 1 to select USART peripheral.
  * @param  value: Specifies the LIN break detection length.
  *          This parameter can be one of the following values:
  *            @arg USART_LIN_BREAK_10BIT: 10-bit break detection.
  *            @arg USART_LIN_BREAK_11BIT: 11-bit break detection.
  * @return None.
  */
void usart_lin_break_detect_config(usart_reg_t* ptr_usart, uint32_t value)
{
    ASSERT(USART_SELECT_1_CHECK(ptr_usart));
    ASSERT(USART_LIN_BREAK_BIT_CHECK(value));

    /* Set the LIN Break detection length. */
    MODIFY_REG(ptr_usart->CTR2, USART_CTR2_LINBRK11, value);
}


/**
  * @brief  Sets the specified USART guard time for smart card mode.
  * @param  ptr_usart: Pointer to USARTx where x can be 1 to select USART peripheral.
  * @param  value: Specifies the guard time.
  * @note   The value must be greater than 0x0.
  * @return None.
  */
void usart_guard_time_set(usart_reg_t* ptr_usart, uint8_t value)
{
    ASSERT(USART_SELECT_1_CHECK(ptr_usart));

    /* Set the USART guard time */
    MODIFY_REG(ptr_usart->GTPDIV, USART_GTPDIV_GUDT, (uint16_t)((uint16_t)value << 8));
}


/**
  * @brief  Sets the Smart Card number of retries in transmit and receive.
  * @param  ptr_usart: Pointer to USARTx where x can be 1 to select USART peripheral.
  * @param  value: Specifies the smart card auto retry times.
  * @return None.
  */
void usart_auto_retry_times_set(usart_reg_t* ptr_usart, uint8_t value)
{
    ASSERT(USART_SELECT_1_CHECK(ptr_usart));
    ASSERT(USART_RETRY_NUM_CHECK(value));

    /* Set the USART auto retry count. */
    MODIFY_REG(ptr_usart->CTR3, USART_CTR3_SCANUM, (uint32_t)value << 17);
}


/**
  * @brief  Sets the Smar Card Block number.
  * @param  ptr_usart: Pointer to USARTx where x can be 1 to select USART peripheral.
  * @param  block_number: Specifies the smart card block number.
  * @return None.
  */
void usart_block_value_set(usart_reg_t* ptr_usart, uint8_t block_number)
{
    ASSERT(USART_SELECT_1_CHECK(ptr_usart));

    /* Set the Smartcard block number. */
    MODIFY_REG(ptr_usart->ROT, USART_ROT_NUMBLK, (uint32_t)block_number << 24);
}


/**
  * @brief  Sets the receiver Time Out value.
  * @param  ptr_usart: Pointer to USARTx where x can be 1 to select USART peripheral.
  * @param  value: Specifies the receiver time out value.
  * @return None.
  */
void usart_recv_overtime_set(usart_reg_t* ptr_usart, uint32_t value)
{
    ASSERT(USART_SELECT_1_CHECK(ptr_usart));
    ASSERT(USART_TIMEOUT_CHECK(value));
  
    /* Set the receiver time_out value. */
    MODIFY_REG(ptr_usart->ROT, USART_ROT_RXOVR, value);
}


/**
  * @brief  Configures the USART's IrDA interface.
  * @param  ptr_usart: Pointer to USARTx where x can be 1 to select USART peripheral.
  * @param  value: Specifies the IrDA mode,it can be one of the following values:
  *          @arg USART_IRDA_MODE_LP: IRDA in low power mode.
  *          @arg USART_IRDA_MODE_NORMAL: IRDA in normal mode.
  * @return None.
  */
void usart_irda_config(usart_reg_t* ptr_usart, uint32_t value)
{
    ASSERT(USART_SELECT_1_CHECK(ptr_usart));
    ASSERT(USART_IRDA_MODE_CHECK(value));

    /* Set the new value for the IrDA interface. */
    MODIFY_REG(ptr_usart->CTR3, USART_CTR3_IRMS, value);
}


/**
  * @brief  Configures the USART's DE polarity
  * @param  ptr_usart: Pointer to USARTx where x can be 1, 2.
  * @param  value: Specifies the DE polarity
  *         It can be one of the following values:
  *          @arg USART_DE_POLARITY_LOW: DE polarity is low.
  *          @arg USART_DE_POLARITY_HIGH: DE polarity is high.
  * @return None.
  */
void usart_driver_enable_polarity_config(usart_reg_t* ptr_usart, uint32_t value)
{
    ASSERT(USART_SELECT_CHECK(ptr_usart));
    ASSERT(USART_DE_POLARITY_CHECK(value));

    /* Set the new value for the DE polarity. */
    MODIFY_REG(ptr_usart->CTR3, USART_CTR3_DEPS, value);
}


/**
  * @brief  Sets the specified RS485 DE Pre-active time 
  * @param  ptr_usart: Pointer to USARTx where x can be 1, 2.
  * @param  value: Specifies DE Pre-active time between the activation of the DE signal and the the beginning of the
  *                start bit.
  * @return None.
  */
void usart_driver_enable_preactive_time_set(usart_reg_t* ptr_usart, uint8_t value)
{
    ASSERT(USART_SELECT_CHECK(ptr_usart));
    ASSERT(USART_DE_PREACTIVE_TIME_CHECK(value)); 

    /* Set the new value for the DE Pre-active time. */
    MODIFY_REG(ptr_usart->CTR1, USART_CTR1_PRETDE, (uint32_t)value << 21);
}


/**
  * @brief  Sets the specified RS485 DE Pos-active time
  * @param  ptr_usart: Pointer to USARTx where x can be 1, 2.
  * @param  value: Specifies the time between the middle of the last stop bit in a transmitted message and the
  *                Pos_activation of the DE signal.
  * @return None.
  */
void usart_driver_enable_posactive_time_set(usart_reg_t* ptr_usart, uint8_t value)
{
    ASSERT(USART_SELECT_CHECK(ptr_usart));
    ASSERT(USART_DE_PROACTIVE_TIME_CHECK(value)); 
    
    /* Set the new value for the DE Pos-active time. */
    MODIFY_REG(ptr_usart->CTR1, USART_CTR1_POSTDE, (uint32_t)value << 16);
}

///@endcond

/**
  * @}
  */

/**
  * @}
  */

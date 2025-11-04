/**
* @file        cbm858xm_misc.c
* @brief       This file provides all the basic PPP firmware functions.
* @author      ChipSea MCU Group
* @version     1.0.0
* @date        2022.06.30
* @copyright   CHIPSEA TECHNOLOGIES (SHENZHEN) CORP.
* @note        
****************************************************************************************************
* @par Modify record:
* <tr><th>Date          <th>Version    <th>Author     <th>Description
* <tr><td>2022.06.30    <td>1.0.0      <td>ChipSea    <td>
* -# 
* </table>
*
****************************************************************************************************
*/


/***************************************************************************************************
 * @includes
***************************************************************************************************/
#include "cbm858xm_misc.h"


/***************************************************************************************************
 * @definitions
***************************************************************************************************/


/** @addtogroup CBM858xM_StdPeriph_Driver
  * @{
  */

/** @defgroup MISC MISC
  * @brief    MISC driver modules
  * @{
  */

///@cond

/***************************************************************************************************
 * @variables
***************************************************************************************************/


/***************************************************************************************************
 * @function
***************************************************************************************************/

/**
  * @brief  Initializes the NVIC peripheral according to the specified parameters in the ptr_config.
  * @param  ptr_config: pointer to a nvic_config_t structure that contains the configuration information for the specified
  *         NVIC peripheral.
  * @return None.
  */
void nvic_init(nvic_config_t* ptr_config)
{
    ASSERT(FUNCTIONAL_STATE_CHECK(ptr_config->enable_flag));
    ASSERT(NVIC_PRIORITY_CHECK(ptr_config->priority));  
    
    if (ptr_config->enable_flag != DISABLE)
    {
        MODIFY_REG(NVIC->IP[ptr_config->IRQn >> 0x02], ((uint32_t)0xFF) << ((ptr_config->IRQn & 0x03) * 8), \
                   (((uint32_t)ptr_config->priority << 6) & 0xFF) << ((ptr_config->IRQn & 0x03) * 8));
    
        /* Enable the Selected IRQ Channels */
        NVIC->ISER[0] = (uint32_t)0x01 << (ptr_config->IRQn & (uint8_t)0x1F);
    }
    else
    {
        /* Disable the Selected IRQ Channels */
        NVIC->ICER[0] = (uint32_t)0x01 << (ptr_config->IRQn & (uint8_t)0x1F);
    }
}

/**
  * @brief  Configures the SysTick clock source.
  * @param  select: specifies the SysTick clock source. It can be one of following values: 
  *         @arg SYSTICK_CLKSEL_HCLK_DIV8
  *         @arg SYSTICK_CLKSEL_HCLK
  * @return None.
  */
void systick_clock_config(uint32_t select)
{
    ASSERT(SYSTICK_CLKSEL_CHECK(select)); 
    
    MODIFY_REG(SysTick->CTRL, SYSTICK_CLKSEL_HCLK, select);
}

///@endcond

/**
  * @}
  */

/**
  * @}
  */

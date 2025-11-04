/**
* @file        cbm858xm_wwdt.c
* @brief       This file provides all the basic WWDT firmware functions.
* @author      ChipSea MCU Group
* @version     1.0.0
* @date        2022.05.16
* @copyright   CHIPSEA TECHNOLOGIES (SHENZHEN) CORP.
* @note        
****************************************************************************************************
* @par Modify record:
* <tr><th>Date          <th>Version    <th>Author     <th>Description
* <tr><td>2022.05.16    <td>1.0.0      <td>ChipSea    <td>
* -# 
* </table>
*
****************************************************************************************************
*/


/***************************************************************************************************
 * @includes
***************************************************************************************************/
#include "cbm858xm_wwdt.h"


/***************************************************************************************************
 * @definitions
***************************************************************************************************/


/** @addtogroup CBM858xM_StdPeriph_Driver
  * @{
  */

/** @defgroup WWDT WWDT
  * @brief    WWDT driver modules
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
  * @brief  Sets the WWDT prescaler.
  * @param  wwdt_prescaler: Specifies the WWDT prescaler.
  *         It can be one of the following values:
  *          @arg WWDT_PRESCALER_1: WWDT counter clock = (PCLK1/4096)/1.
  *          @arg WWDT_PRESCALER_2: WWDT counter clock = (PCLK1/4096)/2.
  *          @arg WWDT_PRESCALER_4: WWDT counter clock = (PCLK1/4096)/4.
  *          @arg WWDT_PRESCALER_8: WWDT counter clock = (PCLK1/4096)/8.
  * @return None.
  */
void wwdt_prescaler_set(uint32_t wwdt_prescaler)
{
    ASSERT(WWDT_PRESCALER_CHECK(wwdt_prescaler));

    MODIFY_REG(WWDT->CTR2, (uint32_t)WWDT_CTR2_PDIV, wwdt_prescaler);
}


/**
  * @brief  Sets the WWDT window value.
  * @param  window_value: Specifies the window value to be compared to the downcounter.
  * @note   This parameter value must be lower than 0x80.
  * @return None.
  */
void wwdt_window_value_set(uint8_t window_value)
{
    ASSERT(WWDT_WINDOW_VALUE_CHECK(window_value));

    MODIFY_REG(WWDT->CTR2, (uint32_t)WWDT_CTR2_WVAL, (uint32_t)(window_value & WWDT_BIT_MASK));
}

///@endcond

/**
  * @}
  */

/**
  * @}
  */

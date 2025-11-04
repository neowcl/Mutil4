/**
* @file        system_cbm858xm.c
* @brief       This file provides all the basic PPP firmware functions.
* @author      ChipSea MCU Group
* @version     1.0.0
* @date        2022.06.22
* @copyright   CHIPSEA TECHNOLOGIES (SHENZHEN) CORP.
* @note        
****************************************************************************************************
* @par Modify record:
* <tr><th>Date          <th>Version    <th>Author     <th>Description
* <tr><td>2022.06.22    <td>1.0.0      <td>ChipSea    <td>
* -# 
* </table>
*
****************************************************************************************************
*/


/***************************************************************************************************
 * @includes
***************************************************************************************************/
#include "cbm858xm.h"


/***************************************************************************************************
 * @definitions
***************************************************************************************************/


/** @addtogroup CBM858xM_StdPeriph_Driver
  * @{
  */

/** @defgroup CBM858xM_SYS cbm858xm system
  * @brief    CBM858xM_SYS driver modules
  * @{
  */

///@cond

/***************************************************************************************************
 * @variables
***************************************************************************************************/
uint32_t SystemCoreClock    = 24000000;

/***************************************************************************************************
 * @function
***************************************************************************************************/
/**
  * @brief  Setup the microcontroller system.   
  * @param  None
  * @note   This function is called at startup just after reset and 
  *         before branch to main program. This call is made inside
  *         the "startup_cbm858xm.s" file. 
  * @return None
  */
void systeminit (void)
{
    /*  HCLK non frequency division, use system clock 24M. */
    RCU->CFG &= 0xFFFFFF0F;
    
    /*  Flash access needs to wait for 1 clock cycle under 24M clock. */
    FLASH->WCR &= 0x00000001; 
}

///@endcond

/**
  * @}
  */

/**
  * @}
  */

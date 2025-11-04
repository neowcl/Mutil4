/**
* @file        cbm858xm_acts.c
* @brief       This file provides all the basic active shield firmware functions.
* @author      ChipSea MCU Group
* @version     1.0.0
* @date        2022.12.20
* @copyright   CHIPSEA TECHNOLOGIES (SHENZHEN) CORP.
* @note        
****************************************************************************************************
* @par Modify record:
* <tr><th>Date          <th>Version    <th>Author     <th>Description
* <tr><td>2022.12.20    <td>1.0.0      <td>ChipSea    <td>
* -# 
* </table>
*
****************************************************************************************************
*/


/***************************************************************************************************
 * @includes
***************************************************************************************************/
#include "cbm858xm_acts.h"


/***************************************************************************************************
 * @definitions
***************************************************************************************************/


/** @addtogroup CBM858xM_StdPeriph_Driver
  * @{
  */

/** @defgroup ACTS Active shield
  * @brief    ACTS driver modules
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
  * @brief  Config each ptr_struct member with its default value.
  * @param  ptr_struct: pointer to an acts_config_t structure which will be initialized.
  * @return None.
  */
void active_shield_struct_init(acts_config_t* ptr_struct)
{
    ptr_struct->wait_time = 0x03E8;
    ptr_struct->comp_time = 0x00C8;
    ptr_struct->mis_thld =  0x64;
}

/**
  * @brief  Initializes the active shield peripheral according to the specified parameters.
  * @param  ptr_config: pointer to an acts_config_t structure that contains 
  *         the configuration information for the specified Active shield peripheral.
  * @return None
  */
void active_shield_init(acts_config_t* ptr_config)
{
    MODIFY_REG(ACTS->CTR1, ACTS_WAIT_TIME, (uint32_t)(ptr_config->wait_time));
    MODIFY_REG(ACTS->CTR1, ACTS_COMP_TIME, (uint32_t)(ptr_config->comp_time<<16));
    MODIFY_REG(ACTS->CTR2, ACTS_MIS_THLD, (uint32_t)(ptr_config->mis_thld));
}

///@endcond

/**
  * @}
  */

/**
  * @}
  */

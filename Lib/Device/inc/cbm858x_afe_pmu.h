/**
* @file        cbm858x_afe_pmu.h
* @brief       This file contains all the functions prototypes for the PMU firmware library. 
* @author      ChipSea MCU Group
* @version     1.0.0
* @date        2022.10.30
* @copyright   CHIPSEA TECHNOLOGIES (SHENZHEN) CORP.
* @note        
****************************************************************************************************
* @par Modify record:
* <tr><th>Date          <th>Version    <th>Author     <th>Description
* <tr><td>2022.10.30    <td>1.0.0      <td>ChipSea    <td>
* -# 
* </table>
*
****************************************************************************************************
*/


#ifndef __CBM858x_AFE_PMU_H__
#define __CBM858x_AFE_PMU_H__


#ifdef __cplusplus
 extern "C" {
#endif


/***************************************************************************************************
 * @includes
***************************************************************************************************/
#include "cbm858x_afe_transimit.h"


/** @addtogroup AFE_StdPeriph_Driver
  * @{
  */

/** @addtogroup AFE_PMU
  * @{
  */

/***************************************************************************************************
 * @definitions
***************************************************************************************************/
/** @defgroup AFE_PMU_Types AFE_PMU Types
  * @{
  */

//Fill the content
/**
  * @}
  */


/** @defgroup AFE_PMU_Constants AFE_PMU Constants
  * @{
  */
/* PACK pull-down 100uA definition. */
#define PMU_PACK_PULL_DOWN_100UA             (uint16_t)0x0010     /*!< PACK pull-down 100uA enable. */

/* PMU voltage indicator. */
#define PMU_PMUCON_PACKH2P25V			     (uint16_t)0x0004     /*!< PMU PACK higher 2.5v flag. */
#define PMU_PMUCON_VBATH3P1V			     (uint16_t)0x0008     /*!< PMU VBAT higher 3.1v flag. */

/* PMU delay time definition. */
#define PMU_PMUDDS_DELAY_70US      			 (uint16_t)0x0000     /*!< PMU shutdown delay 70us. */
#define PMU_PMUDDS_DELAY_101US      		 (uint16_t)0x0001     /*!< PMU shutdown delay 101us. */
#define PMU_PMUDDS_DELAY_148US      		 (uint16_t)0x0002     /*!< PMU shutdown delay 148us. */
#define PMU_PMUDDS_DELAY_210US      		 (uint16_t)0x0003     /*!< PMU shutdown delay 210us. */
#define PMU_PMUDDS_DELAY_MASK       		 (uint16_t)0x0003     /*!< PMU shutdown delay mask. */

/* PMU awaken enable definition. */
#define PMU_PMUWCTRL_SW_AWAKEN      		 (uint16_t)0x0001     /*!< PMU SW pin shutdown awaken. */

/**
  * @}
  */


/***************************************************************************************************
 * @functions
***************************************************************************************************/
/** @defgroup AFE_PMU_Functions AFE_PMU Functions
  * @{
  */

/**
  * @brief  Enables or disables the pack pull-down 100uA.
  * @param  enable_flag: It can be ENABLE or DISABLE.
  * @note   None.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_pmu_pack_pull_down_enable_ctrl(uint8_t enable_flag);

/**
  * @brief  Get pmu voltage status.
  * @param	flag: Specifies the voltage type to get.
  *               It can be one of the following values:
  *				   PMU_PMUCON_PACKH2P25V: PACK voltage higher 2.25v flag.
  *				   PMU_PMUCON_VBATH3P1V:  VBAT voltage higher 3.1v flag.
  * @param	status: Specifies the voltage status.
  * @note   None.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_pmu_voltage_status_get(uint16_t flag, uint8_t *status);

/**
  * @brief  Config the delay time when receive shutdown.
  * @param	value: Specifies the delay value.
  *               It can be one of the following values:
  *				   PMU_PMUDDS_DELAY_70US: 70us delay.  
  *				   PMU_PMUDDS_DELAY_101US: 101us delay.
  *				   PMU_PMUDDS_DELAY_148US: 148us delay.
  *				   PMU_PMUDDS_DELAY_210US: 210us delay.
  * @note   None.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_pmu_shutdown_dds_config(uint16_t value);

/**@brief  Enables or disables the SW awaken. 
 * @param  enable_flag: It can be ENABLE or DISABLE.
 * @note   None.
 * @return Function execution result, 0:ERROR, 1:SUCCESS.
 */
uint8_t afe_pmu_sw_awaken_enable_ctrl(uint8_t enable_flag);

/**
  * @}
  */


#ifdef __cplusplus
}
#endif

#endif /* cbm858x_afe_pmu.h */


/**
  * @}
  */

/**
  * @}
  */

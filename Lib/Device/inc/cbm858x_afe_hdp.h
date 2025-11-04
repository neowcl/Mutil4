/**
* @file        cbm858x_afe_hdp.h
* @brief       This file contains all the functions prototypes for the HDP firmware library. 
* @author      ChipSea MCU Group
* @version     1.0.0
* @date        2022.11.03
* @copyright   CHIPSEA TECHNOLOGIES (SHENZHEN) CORP.
* @note        
****************************************************************************************************
* @par Modify record:
* <tr><th>Date          <th>Version    <th>Author     <th>Description
* <tr><td>2022.11.03    <td>1.0.0      <td>ChipSea    <td>
* -# 
* </table>
*
****************************************************************************************************
*/


#ifndef __CS_PPP_H__
#define __CS_PPP_H__


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

/** @addtogroup AFE_HDP
  * @{
  */

/***************************************************************************************************
 * @definitions
***************************************************************************************************/
/** @defgroup AFE_HDP_Types AFE_HDP Types
  * @{
  */

//Fill the content
/**
  * @}
  */


/** @defgroup AFE_HDP_Constants AFE_HDP Constants
  * @{
  */
/* SCD delay time */
#define HDP_NORMAL_SCD_DELAY_TIME       0x0000          /*!< Normal SCD delay time */ 
#define HDP_DOUBLE_SCD_DELAY_TIME       0x0002          /*!< Double SCD delay time */ 

/* Current sampling resistance value setting */
#define HDP_SAMPING_RES_1MOHM           0x0000         /*!< Sampling resistance value 1mΩ */ 
#define HDP_SAMPING_RES_2MOHM           0x0001         /*!< Sampling resistance value 2mΩ */

/**
  * @}
  */


/***************************************************************************************************
 * @functions
***************************************************************************************************/
/** @defgroup AFE_HDP_Functions AFE_HDP Functions
  * @{
  */
/**
  * @brief  Hardware protection configuration.
  * @param  delaytime: Double SCD delay time, it can be one of the following values:
  *          @arg HDP_NORMAL_SCD_DELAY_TIME(Normal SCD delay time)
  *          @arg HDP_DOUBLE_SCD_DELAY_TIME(Double SCD delay time)
  * @param  res: Current sampling resistance value setting, it can be one of the following values:
  *          @arg HDP_SAMPING_RES_1MOHM(Sampling resistance value 1mΩ)
  *          @arg HDP_SAMPING_RES_2MOHM(Sampling resistance value 2mΩ)
  * @note   None
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_hdp_hardware_protect_config(uint16_t delaytime, uint16_t res);

/**
  * @brief  Enables or disables total hardware protection.
  * @param  enable_flag: It can be: ENABLE or DISABLE.
  * @note   This need configure afe_gcr_reg_unlock() function first.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_hdp_hardware_protect_enable_ctrl(uint8_t enable_flag);

/**
  * @brief  Discharge overload configuration.
  * @param  time: Discharge overload trigger delay time.
  * @param  threshold: Discharge overload threshold.
  * @note   None
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_hdp_discharge_overload_config(uint16_t time, uint16_t threshold);

/**
  * @brief  Enables or disables discharge overload hardware protection.
  * @param  enable_flag: It can be: ENABLE or DISABLE.
  * @note   This need configure afe_gcr_reg_unlock() function first.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_hdp_discharge_overload_enable_ctrl(uint8_t enable_flag);

/**
  * @brief  Check whether the discharge overload exceeds the threshold.
  * @param  status: Get the flag status,1: Threshold exceeded, 0:No threshold exceeded.
  * @note   None.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
*/
uint8_t afe_hdp_discharge_threshold_status_get(uint8_t* status);

/**
  * @brief  Charging short  configuration.
  * @param  time: Charging short  trigger delay time.
  * @param  threshold: Charging short circuit threshold.
  * @note   None
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_hdp_charging_short_config(uint16_t time, uint16_t threshold);

/**
  * @brief  Enables or disables charging short hardware protection.
  * @param  enable_flag: It can be: ENABLE or DISABLE.
  * @note   This need configure afe_gcr_reg_unlock() function first.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_hdp_charging_short_enable_ctrl(uint8_t enable_flag);

/**
  * @brief  Check whether the charging short exceeds the threshold.
  * @param  status: Get the flag status,1: Threshold exceeded, 0:No threshold exceeded.
  * @note   None.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
*/
uint8_t afe_hdp_charging_short_threshold_status_get(uint8_t* status);

/**
  * @brief  Discharge short 1 configuration.
  * @param  time: Discharge short  trigger delay time.
  * @param  threshold: Discharge short circuit threshold.
  * @note   None
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_hdp_discharge_short_1_config(uint16_t time, uint16_t threshold);

/**
  * @brief  Check whether the discharge short 1 exceeds the threshold.
  * @param  status: Get the flag status,1: Threshold exceeded, 0:No threshold exceeded.
  * @note   None.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
*/
uint8_t afe_hdp_discharge_short_1_threshold_status_get(uint8_t* status);

/**
  * @brief  Enables or disables discharge short hardware protection.
  * @param  enable_flag: It can be: ENABLE or DISABLE.
  * @note   This need configure afe_gcr_reg_unlock() function first.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_hdp_discharge_short_1_enable_ctrl(uint8_t enable_flag);

/**
  * @brief  Discharge short 1 configuration.
  * @param  time: Discharge short trigger delay time.
  * @param  threshold: Discharge short circuit threshold.
  * @note   None
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_hdp_discharge_short_2_config(uint16_t time, uint16_t threshold);

/**
  * @brief  Enables or disables discharge short hardware protection.
  * @param  enable_flag: It can be: ENABLE or DISABLE.
  * @note   This need configure afe_gcr_reg_unlock() function first.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_hdp_discharge_short_2_enable_ctrl(uint8_t enable_flag);

/**
  * @brief  Check whether the discharge short 2 exceeds the threshold.
  * @param  status: Get the flag status,1: Threshold exceeded, 0:No threshold exceeded.
  * @note   None.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
*/
uint8_t afe_hdp_discharge_short_2_threshold_status_get(uint8_t* status);

/**
  * @}
  */


#ifdef __cplusplus
}
#endif

#endif /* cbm858x_afe_hdp.h */


/**
  * @}
  */

/**
  * @}
  */

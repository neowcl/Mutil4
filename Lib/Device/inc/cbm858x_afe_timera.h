/**
* @file        cbm858x_afe_timera.h
* @brief       This file contains all the functions prototypes for the TIMERA firmware library. 
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


#ifndef __CBM858x_AFE_TIMERA_H__
#define __CBM858x_AFE_TIMERA_H__


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

/** @addtogroup AFE_TIMERA
  * @{
  */

/***************************************************************************************************
 * @definitions
***************************************************************************************************/
/** @defgroup AFE_TIMERA_Types AFE_TIMERA Types
  * @{
  */

//Fill the content
/**
  * @}
  */


/** @defgroup AFE_TIMERA_Constants AFE_TIMERA Constants
  * @{
  */

/* TIMERA working mode definition */
#define TIMERA_WORK_MODE_ONE_SHOT        	(uint16_t)0x0000     /*!< TIMERA working in one-shot mode. */
#define TIMERA_WORK_MODE_PERIOD        	    (uint16_t)0x0800     /*!< TIMERA working in period mode. */
#define TIMERA_WORK_MODE_CONTINUOUS        	(uint16_t)0x1800     /*!< TIMERA working in continuous mode. */

/**
  * @}
  */


/***************************************************************************************************
 * @functions
***************************************************************************************************/
/** @defgroup AFE_TIMERA_Functions AFE_TIMERA Functions
  * @{
  */

/**
  * @brief	Enable or disable timera timer reset.
  * @param	enable_flag: It can be ENABLE or DISABLE.
  * @note	None.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_timera_timer_reset(uint8_t enable_flag);

/**
  * @brief	Config timera timer workong mode.
  * @param	work_mode: TIMERA workong mode.
  * 			  It can be one of the following values:
  * 			   @arg TIMERA_WORK_MODE_ONE_SHOT(Default config). 
  * 			   @arg TIMERA_WORK_MODE_PERIOD.
  * 			   @arg TIMERA_WORK_MODE_CONTINUOUS.
  * @note	None.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_timera_timer_mode_config(uint16_t work_mode);

/**
  * @brief	Enable or disable timera module.
  * @param	enable_flag: It can be ENABLE or DISABLE.
  * @note	None.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_timera_timer_enable_ctrl(uint8_t enable_flag);

/**
  * @brief	Enable or disable timera timer count update.
  * @param	enable_flag: It can be ENABLE or DISABLE.
  * @note	None.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_timera_timer_update_enable_ctrl(uint8_t enable_flag);

/**
  * @brief	Enable or disable timera timer periodic mode select.
  * @param	enable_flag: It can be ENABLE or DISABLE.
  * @note	None.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_timera_periodic_select_enable_ctrl(uint8_t enable_flag);

/**
  * @brief  Set timera timer prescaler value.
  * @param  value: Specifies the prescaler timer value, must be a number between 0 and 0xFF(Default value:0x05).
  * @note   The actual timer frequency division = clock_source/(value + 1).
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_timera_prescaler_value_set(uint8_t value);

/**
  * @brief	Set timera module timer comparision value.
  * @param  cmp_value: comparision value, must be a number between 2 and 0xFFFF.
  * @note	None.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_timera_timer_comparison_value_set(uint16_t cmp_value);

/**
  * @brief	Get timera timer working status.
  * @param  work_status: Timera timer working status, 0:not work 1:working.
  * @note	None.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_timera_timer_working_status_get(uint8_t *work_status);

/**
  * @brief	Get timera timer counter value.
  * @param  count_value: Timera timer count value.
  * @note	None.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_timera_timer_count_value_get(uint16_t *count_value);



/**
  * @}
  */


#ifdef __cplusplus
}
#endif

#endif /* cbm858x_afe_timera.h */


/**
  * @}
  */

/**
  * @}
  */

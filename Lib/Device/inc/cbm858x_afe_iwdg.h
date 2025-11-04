/**
* @file        cbm858x_afe_iwdg.h
* @brief       This file contains all the functions prototypes for the IWDG firmware library. 
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


#ifndef __CBM858x_AFE_IWDG_H__
#define __CBM858x_AFE_IWDG_H__


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

/** @addtogroup AFE_IWDG
  * @{
  */

/***************************************************************************************************
 * @definitions
***************************************************************************************************/
/** @defgroup AFE_IWDG_Types AFE_IWDG Types
  * @{
  */

//Fill the content
/**
  * @}
  */


/** @defgroup AFE_IWDG_Constants AFE_IWDG Constants
  * @{
  */

#define IWDT_PRESCALER_4        			((uint8_t)0x00)         /*!< IWDT prescaler divider 4. */
#define IWDT_PRESCALER_8        			((uint8_t)0x01)         /*!< IWDT prescaler divider 8. */
#define IWDT_PRESCALER_16       			((uint8_t)0x02)         /*!< IWDT prescaler divider 16. */
#define IWDT_PRESCALER_32       			((uint8_t)0x03)         /*!< IWDT prescaler divider 32. */
#define IWDT_PRESCALER_64       			((uint8_t)0x04)         /*!< IWDT prescaler divider 64. */
#define IWDT_PRESCALER_128      			((uint8_t)0x05)         /*!< IWDT prescaler divider 128. */
#define IWDT_PRESCALER_256      			((uint8_t)0x06)         /*!< IWDT prescaler divider 256. */
/**
  * @}
  */


/***************************************************************************************************
 * @functions
***************************************************************************************************/
/** @defgroup AFE_IWDG_Functions AFE_IWDG Functions
  * @{
  */

/**
  * @brief	Enable or disable iwdg.
  * @param  enable_flag: It can be ENABLE or DISABLE.
  * @note	None.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_iwdg_enable_ctrl(uint8_t enable_flag);

/**
  * @brief  Sets the IWDG window value.
  * @param	value: Window value, must be a number between 0 and 0x0FFF(Default value--0x0FFF).
  * @note   None.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_iwdg_window_value_set(uint16_t value);

/**
  * @brief  Sets the IWDG reload value.
  * @param	value: Reload value, must be a number between 0 and 0x0FFF.
  * @note   None.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_iwdg_reload_value_set(uint16_t value);

/**
  * @brief  Sets IWDG prescaler value.
  * @param  VALUE: Specifies the IWDT prescaler value.
  *		  It can be one of the following values:
  *		   @arg IWDT_PRESCALER_4: IWDT prescaler set to 4.
  *		   @arg IWDT_PRESCALER_8: IWDT prescaler set to 8.
  *		   @arg IWDT_PRESCALER_16: IWDT prescaler set to 16.
  *		   @arg IWDT_PRESCALER_32: IWDT prescaler set to 32.
  *		   @arg IWDT_PRESCALER_64: IWDT prescaler set to 64(Default).
  *		   @arg IWDT_PRESCALER_128: IWDT prescaler set to 128.
  *		   @arg IWDT_PRESCALER_256: IWDT prescaler set to 256.
  * @note   None.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_iwdg_prescaler_value_set(uint16_t value);

/**
  * @brief  Sets IWDG feed dog.
  * @param  None.
  * @note   None.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_iwdg_feed_enable(void);

/**
  * @brief  Gets IWDG status.
  * @param  status: IWDG status.
  *                 @arg status' bit0: Watchdog counter pre-split value update.
  *                 @arg status' bit1: Watchdog counter overload value update.        
  *                 @arg status' bit2: Watchdog counter window value update.     
  * @note   None.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_iwdg_status_get(uint16_t* status);
/**
  * @}
  */


#ifdef __cplusplus
}
#endif

#endif /* cbm858x_afe_iwdg.h */


/**
  * @}
  */

/**
  * @}
  */

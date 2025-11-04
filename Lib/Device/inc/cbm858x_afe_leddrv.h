/**
* @file        cbm858x_afe_leddrv.h
* @brief       This file contains all the functions prototypes for the LEDDRV firmware library. 
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


#ifndef __CBM858x_AFE_LEDDRV_H__
#define __CBM858x_AFE_LEDDRV_H__


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

/** @addtogroup AFE_LEDDRV
  * @{
  */

/***************************************************************************************************
 * @definitions
***************************************************************************************************/
/** @defgroup AFE_LEDDRV_Types AFE_LEDDRV Types
  * @{
  */

//Fill the content
/**
  * @}
  */


/** @defgroup AFE_LEDDRV_Constants AFE_LEDDRV Constants
  * @{
  */

/* LEDDRV led working mode definition */
#define LEDDRV_LEDDRC_MODE_MANUAL        	(uint16_t)0x0000     /*!< LED manual working mode. */
#define LEDDRV_LEDDRC_MODE_AUTO          	(uint16_t)0x0010     /*!< LED manual working mode. */

/* Auto mode led number definition. */
#define LEDDRV_LEDDRC_AUTOMODE_6LED         (uint16_t)0x0000     /*!< 6 LED. */
#define LEDDRV_LEDDRC_AUTOMODE_5LED         (uint16_t)0x0004     /*!< 5 LED. */
#define LEDDRV_LEDDRC_AUTOMODE_4LED         (uint16_t)0x0008     /*!< 4 LED. */


/* Auto mode led Frequency division. */
#define LEDDRV_LEDDRC_AUTOMODE_PDIV_1       (uint16_t)0x0000     /*!< LED divided by 1. */
#define LEDDRV_LEDDRC_AUTOMODE_PDIV_2       (uint16_t)0x0001     /*!< LED divided by 2. */
#define LEDDRV_LEDDRC_AUTOMODE_PDIV_4       (uint16_t)0x0002     /*!< LED divided by 4. */

/* LEDDRV led light definition */
#define LEDDRV_HAND_LIGHT_LED1        	    (uint16_t)0x0084     /*!< LED1 light. */
#define LEDDRV_HAND_LIGHT_LED2          	(uint16_t)0x0108     /*!< LED2 light. */
#define LEDDRV_HAND_LIGHT_LED3        	    (uint16_t)0x0102     /*!< LED3 light. */
#define LEDDRV_HAND_LIGHT_LED4          	(uint16_t)0x0204     /*!< LED4 light. */
#define LEDDRV_HAND_LIGHT_LED5        	    (uint16_t)0x0202     /*!< LED5 light. */
#define LEDDRV_HAND_LIGHT_LED6          	(uint16_t)0x0088     /*!< LED6 light. */

/* Duty control LED number definition */
#define LEDDRV_DUTY_NUM_LED1                (uint8_t)0x00        /*!< LED number 1*/
#define LEDDRV_DUTY_NUM_LED2                (uint8_t)0x01        /*!< LED number 2*/
#define LEDDRV_DUTY_NUM_LED3                (uint8_t)0x02        /*!< LED number 3*/
#define LEDDRV_DUTY_NUM_LED4                (uint8_t)0x03        /*!< LED number 4*/
#define LEDDRV_DUTY_NUM_LED5                (uint8_t)0x04        /*!< LED number 5*/
#define LEDDRV_DUTY_NUM_LED6                (uint8_t)0x05        /*!< LED number 6*/


/**
  * @}
  */


/***************************************************************************************************
 * @functions
***************************************************************************************************/
/** @defgroup AFE_LEDDRV_Functions AFE_LEDDRV Functions
  * @{
  */

/**
  * @brief	Config led workong mode.
  * @param  work_mode: LED workong mode.
  *               It can be one of the following values:
  *				   @arg LEDDRV_LEDDRC_MODE_MANUAL(Default config). 
  *				   @arg LEDDRV_LEDDRC_MODE_AUTO.
  * @note	None.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_leddrv_mode_config(uint16_t work_mode);

/**
  * @brief	Config led number and prescaler in atuo mode.
  * @param  led_number: LED number.
  *               It can be one of the following values:
  *				   @arg LEDDRV_LEDDRC_AUTOMODE_6LED(Default config). 
  *				   @arg LEDDRV_LEDDRC_AUTOMODE_5LED.
  *				   @arg LEDDRV_LEDDRC_AUTOMODE_4LED.
  * @param  prescaler: Prescaler value.
  *               It can be one of the following values:
  *				   @arg LEDDRV_LEDDRC_AUTOMODE_PDIV_1(Default config). 
  *				   @arg LEDDRV_LEDDRC_AUTOMODE_PDIV_2.
  *				   @arg LEDDRV_LEDDRC_AUTOMODE_PDIV_4.
  * @note	None.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_leddrv_auto_mode_config(uint16_t led_number, uint16_t prescaler);

/**
  * @brief	Enable or disable led driver.
  * @param  enable_flag: It can be ENABLE or DISABLE.
  * @note	None.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_leddrv_working_enable_ctrl(uint8_t enable_flag);

/**
  * @brief	Light the specific led.
  * @param  led: LED which should be light.
  *               It can be one of the following values:
  *				   @arg LEDDRV_LIGHT_LED1. 
  *				   @arg LEDDRV_LIGHT_LED2.
  *				   @arg LEDDRV_LIGHT_LED3. 
  *				   @arg LEDDRV_LIGHT_LED4.
  *				   @arg LEDDRV_LIGHT_LED5. 
  *				   @arg LEDDRV_LIGHT_LED6.
  * @note	None.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_leddrv_led_light_config(uint16_t led);

/**
  * @brief	Automatic mode LED brightness duty control.
  * @param  led_num: LED number selection.
  *               It can be one of the following values:
  *				   @arg LEDDRV_DUTY_NUM_LED1. 
  *				   @arg LEDDRV_DUTY_NUM_LED2.
  *				   @arg LEDDRV_DUTY_NUM_LED3. 
  *				   @arg LEDDRV_DUTY_NUM_LED4.
  *				   @arg LEDDRV_DUTY_NUM_LED5. 
  *				   @arg LEDDRV_DUTY_NUM_LED6.
  * @param  led_duty: LED brightness duty control, it can be set 0~255. Brightness increases as the value increases.
  * @note	None.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_leddrv_duty_config(uint8_t led_num, uint8_t led_duty);

/**
  * @}
  */


#ifdef __cplusplus
}
#endif

#endif /* cbm858x_afe_leddrv.h */


/**
  * @}
  */

/**
  * @}
  */

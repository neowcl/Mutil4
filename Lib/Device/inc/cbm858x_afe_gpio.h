/**
* @file        cbm858x_afe_gpio.h
* @brief       This file contains all the functions prototypes for the GPIO firmware library. 
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


#ifndef __CBM858x_AFE_GPIO_H__
#define __CBM858x_AFE_GPIO_H__


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

/** @addtogroup AFE_GPIO
  * @{
  */

/***************************************************************************************************
 * @definitions
***************************************************************************************************/
/** @defgroup AFE_GPIO_Types AFE_GPIO Types
  * @{
  */

//Fill the content
/**
  * @}
  */


/** @defgroup AFE_GPIO_Constants AFE_GPIO Constants
  * @{
  */
/* GPIO PB pin definition. */
#define GPIO_PB0_PIN         		   (uint16_t)0x0001              /*!< GPIO PB0 pin. */
#define GPIO_PB1_PIN          		   (uint16_t)0x0002              /*!< GPIO PB1 pin. */

/* GPIO PB pin mode. */
#define GPIO_PB_MODE_INPUT    	 	   (uint8_t)0x00                 /*!< GPIO input mode. */
#define GPIO_PB_MODE_OUTPUT_PP    	   (uint8_t)0x01                 /*!< GPIO push-pull output mode. */
#define GPIO_PB_INPUT_MODE_OD    	   (uint8_t)0x02                 /*!< GPIO open drain output mode. */
            
/* GPIO PB pin voltage threshold. */
#define GPIO_PB_VOLT_THRESHOLD_1P2V    (uint8_t)0x00                 /*!< GPIO voltage threshold 1.2v. */
#define GPIO_PB_VOLT_THRESHOLD_1P8V    (uint8_t)0x01                 /*!< GPIO voltage threshold 1.8v. */

/**
  * @}
  */


/***************************************************************************************************
 * @functions
***************************************************************************************************/
/** @defgroup AFE_GPIO_Functions AFE_GPIO Functions
  * @{
  */

/**
  * @brief  Config the gpio int mode.
  * @param 	pin: Specifies the PB pin.
  *               It can be one of the following values:
  *				   @arg GPIO_PB0_PIN: PB0.  
  *				   @arg GPIO_PB1_PIN: PB1.
  * @param  gpio_mode: Specifies the PB mode.
  *               It can be one of the following values:
  *				   @arg GPIO_PB_MODE_INPUT: GPIO input(Default config). 
  *				   @arg GPIO_PB_MODE_OUTPUT_PP: GPIO push-pull output.
  *				   @arg GPIO_PB_INPUT_MODE_OD: GPIO open drain output.
  * @note   None.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_gpio_mode_config(uint16_t pin, uint8_t gpio_mode);

/**
  * @brief  Control the gpio digital channel close.
  * @param  pin: Specifies the PB pin.
  *               It can be one of the following values:
  *				   @arg GPIO_PB0_PIN: PB0.  
  *				   @arg GPIO_PB1_PIN: PB1.
  * @param	enable_flag: It can be ENABLE or DISABLE.
  * @note   None.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_gpio_digital_channel_close_ctrl(uint16_t pin, uint8_t enable_flag);

/**
  * @brief  Read the gpio input value.
  * @param	pin: Specifies the PB pin.
  *               It can be one of the following values:
  *				   @arg GPIO_PB0_PIN: PB0.
  *				   @arg GPIO_PB1_PIN: PB1.
  * @param 	status: Specifies the input bit value.
  * @note   None.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_gpio_input_data_bit_read(uint16_t pin, uint8_t *status);

/**
  * @brief  Read the gpio output value.
  * @param	pin: Specifies the PB pin.
  *               It can be one of the following values:
  *				   @arg GPIO_PB0_PIN: PB0.
  *				   @arg GPIO_PB1_PIN: PB1.
  * @param  status: Specifies the output bit value.
  * @note   None.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_gpio_output_data_bit_read(uint16_t pin, uint8_t *status);

/**
  * @brief  Set the gpio output value.
  * @param	pin: Specifies the PB pin.
  *               It can be one of the following values:
  *				   @arg GPIO_PB0_PIN: PB0.  
  *				   @arg GPIO_PB1_PIN: PB1.
  * @note   None.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_gpio_output_data_bit_set(uint16_t pin);

/**
  * @brief  Reset the gpio output value.
  * @param	pin: Specifies the PB pin.
  *               It can be one of the following values:
  *				   @arg GPIO_PB0_PIN: PB0.  
  *				   @arg GPIO_PB1_PIN: PB1.
  * @note   None.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_gpio_output_data_bit_reset(uint16_t pin);

/**
  * @brief  Enable or disable pb_dout reg to update.
  * @param	pin: Specifies the pb pin.
  *               It can be one of the following values:
  *				   @arg GPIO_PB0_PIN: PB0.  
  *				   @arg GPIO_PB1_PIN: PB1.
  * @param	enable_flag: It can be ENABLE or DISABLE.
  * @note   None.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_gpio_output_write_enable_ctrl(uint16_t pin, uint8_t enable_flag);

/**
  * @brief  Control the gpio pull-up enable.
  * @param	pin: Specifies the PB pin, it only can be GPIO_PB0_PIN.
  * @param	enable_flag: It can be ENABLE or DISABLE.
  * @note   None.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_gpio_pull_up_enable_ctrl(uint16_t pin, uint8_t enable_flag);

/**
  * @brief  Control the gpio pull-down enable.
  * @param	pin: Specifies the PB pin.
  *               It can be one of the following values:
  *				   @arg GPIO_PB0_PIN: PB0. 
  *				   @arg GPIO_PB1_PIN: PB1.
  * @param[in]	enable_flag: It can be ENABLE or DISABLE.
  * @note   None.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_gpio_pull_down_enable_ctrl(uint16_t pin, uint8_t enable_flag);

/**
  * @brief  Config the gpio threshold.
  * @param	pin: Specifies the PB pin.
  *               It can be one of the following values:
  *				   @arg GPIO_PB0_PIN: PB0. 
  *				   @arg GPIO_PB1_PIN: PB1.
  * @param	vth: Gpio threshold.
  *               It can be one of the following values:
  *				   @arg GPIO_PB_VOLT_THRESHOLD_1P2V: Voltage threshold 1.2v(Default config). 
  *                @arg GPIO_PB_VOLT_THRESHOLD_1P8V: Voltage threshold 1.8v. 
  * @note   None.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_gpio_threshold_config(uint8_t vth);

/**
  * @brief  Gpio output write not mask.
  * @param	pin: Specifies the PB pin.
  *               It can be one of the following values:
  *				   @arg GPIO_PB0_PIN: PB0.  
  *				   @arg GPIO_PB1_PIN: PB1.
  * @param	bit_value: Specifies the PB level, can be 1 or 0.
  * @note   None.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_gpio_pb_write(uint16_t pin, uint8_t bit_value);


/**
  * @}
  */


#ifdef __cplusplus
}
#endif

#endif /* cbm858x_afe_gpio.h */


/**
  * @}
  */

/**
  * @}
  */

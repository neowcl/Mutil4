/**
* @file        cbm858xm_gpio.h
* @brief       This file contains all the functions prototypes for the GPIO firmware library. 
* @author      ChipSea MCU Group
* @version     1.0.0
* @date        2022.05.18
* @copyright   CHIPSEA TECHNOLOGIES (SHENZHEN) CORP.
* @note        
****************************************************************************************************
* @par Modify record:
* <tr><th>Date          <th>Version    <th>Author     <th>Description
* <tr><td>2022.05.18    <td>1.0.0      <td>ChipSea    <td>
* -# 
* </table>
*
****************************************************************************************************
*/


#ifndef __CBM858xM_GPIO_H__
#define __CBM858xM_GPIO_H__


#ifdef __cplusplus
 extern "C" {
#endif


/***************************************************************************************************
 * @includes
***************************************************************************************************/
#include "cbm858xm.h"
#include "cbm858xm_rcu.h"


/** @addtogroup CBM858xM_StdPeriph_Driver
  * @{
  */

/** @addtogroup GPIO
  * @{
  */

/***************************************************************************************************
 * @definitions
***************************************************************************************************/
/** @defgroup GPIO_Exported_Types GPIO Exported Types
  * @{
  */

/** @enum  gpio_speed_t
  * @brief GPIO output maximum frequency enumeration.
  */
typedef enum
{
    GPIO_SPEED_LOW    = 0x00,        	    /*!< I/O output speed: Low 2 MHz. */
    GPIO_SPEED_MEDIUM = 0x01,        	    /*!< I/O output speed: Medium 10 MHz. */
    GPIO_SPEED_HIGH   = 0x03        	    /*!< I/O output speed: High 50 MHz. */
}gpio_speed_t;
/**
  * @}
  */


/** @defgroup GPIO_Exported_Constants GPIO Exported Constants
  * @{
  */

/*! Check GPIO speed definition. */
#define GPIO_SPEED_CHECK(flag)      		(((flag) == GPIO_SPEED_LOW) || ((flag) == GPIO_SPEED_MEDIUM) || \
                                    		((flag) == GPIO_SPEED_HIGH))

/*! Check GPIO port definition. */
#define GPIO_PORT_LIST1_CHECK(port)     	((port) == GPIOA)      /*!< Only GPIOA. */

/*! Check GPIO all port definition. */
#define GPIO_ALL_PORT_CHECK(port)       	((port) == GPIOA)      /*!< Only GPIOA. */


/** @defgroup  GPIO_pin GPIO pin definition
  * @{
  */

#define GPIO_PIN_0          				((uint16_t)0x0001)      /*!< Select pin 0. */
#define GPIO_PIN_1          				((uint16_t)0x0002)      /*!< Select pin 1. */
#define GPIO_PIN_2          				((uint16_t)0x0004)      /*!< Select pin 2. */
#define GPIO_PIN_3          				((uint16_t)0x0008)      /*!< Select pin 3. */
#define GPIO_PIN_4          				((uint16_t)0x0010)      /*!< Select pin 4. */
#define GPIO_PIN_5          				((uint16_t)0x0020)      /*!< Select pin 5. */
#define GPIO_PIN_6          				((uint16_t)0x0040)      /*!< Select pin 6. */
#define GPIO_PIN_7          				((uint16_t)0x0080)      /*!< Select pin 7. */
#define GPIO_PIN_8          				((uint16_t)0x0100)      /*!< Select pin 8. */
#define GPIO_PIN_9          				((uint16_t)0x0200)      /*!< Select pin 9. */
#define GPIO_PIN_10         				((uint16_t)0x0400)      /*!< Select pin 10. */
#define GPIO_PIN_11         				((uint16_t)0x0800)      /*!< Select pin 11. */
#define GPIO_PIN_12         				((uint16_t)0x1000)      /*!< Select pin 12. */
#define GPIO_PIN_13         				((uint16_t)0x2000)      /*!< Select pin 13. */
#define GPIO_PIN_ALL        				((uint16_t)0xFFFF)      /*!< Select pin all. */
/**
  * @}
  */

/*! Checks GPIO pins. */
#define GPIO_PIN_CHECK(pin)                 ((pin & 0x3FFF) != 0)
#define GPIO_PIN_LIST_CHECK(pin)            (((pin) == GPIO_PIN_0) || ((pin) == GPIO_PIN_1)  || ((pin) == GPIO_PIN_2)  || \
                                            ((pin) == GPIO_PIN_3)  || ((pin) == GPIO_PIN_4)  || ((pin) == GPIO_PIN_5)  || \
                                            ((pin) == GPIO_PIN_6)  || ((pin) == GPIO_PIN_7)  || ((pin) == GPIO_PIN_8)  || \
                                            ((pin) == GPIO_PIN_9)  || ((pin) == GPIO_PIN_10) || ((pin) == GPIO_PIN_11) || \
                                            ((pin) == GPIO_PIN_12) || ((pin) == GPIO_PIN_13))


/** @defgroup  GPIO_mode GPIO mode definition
  * @{
  */
#define GPIO_MODE_ANALOG                	(0xC0)                	/*!< GPIO analog in/out Mode. */
#define GPIO_MODE_IN_FLOAT             	    (0x00)                	/*!< GPIO input. */
#define GPIO_MODE_IN_PU                	    (0x10)                	/*!< GPIO input pull up. */
#define GPIO_MODE_IN_PD                 	(0x20)                	/*!< GPIO input pull down. */
#define GPIO_MODE_OUT_PP(SPEED)         	(0x48 + SPEED)      	/*!< GPIO output no pull push-pull. */
#define GPIO_MODE_OUT_PP_PU(SPEED)      	(0x58 + SPEED)      	/*!< GPIO output pull up push-pull. */
#define GPIO_MODE_OUT_PP_PD(SPEED)      	(0x68 + SPEED)      	/*!< GPIO output pull down push-pull. */
#define GPIO_MODE_OUT_OD(SPEED)         	(0x4C + SPEED)      	/*!< GPIO output no pull open drain. */
#define GPIO_MODE_OUT_OD_PU(SPEED)      	(0x5C + SPEED)      	/*!< GPIO output pull up open drain. */
#define GPIO_MODE_OUT_OD_PD(SPEED)      	(0x6C + SPEED)      	/*!< GPIO output pull down open drain. */
#define GPIO_MODE_MF_PP(SPEED)          	(0x88 + SPEED)      	/*!< GPIO multiplex no pull push-pull. */
#define GPIO_MODE_MF_PP_PU(SPEED)       	(0x98 + SPEED)      	/*!< GPIO multiplex pull up push-pull. */
#define GPIO_MODE_MF_PP_PD(SPEED)       	(0xA8 + SPEED)      	/*!< GPIO multiplex pull down push-pull. */
#define GPIO_MODE_MF_OD(SPEED)          	(0x8C + SPEED)      	/*!< GPIO multiplex no pull open drain. */
#define GPIO_MODE_MF_OD_PU(SPEED)       	(0x9C + SPEED)      	/*!< GPIO multiplex pull up open drain. */
#define GPIO_MODE_MF_OD_PD(SPEED)       	(0xAC + SPEED)      	/*!< GPIO multiplex pull down open drain. */
/**
  * @}
  */

/*! Checks GPIO mode. */
#define GPIO_MODE_CHECK(mode)       		(((mode) == GPIO_MODE_IN_FLOAT)         || ((mode) == GPIO_MODE_IN_PU)  || \
                                     		((mode) == GPIO_MODE_IN_PD)             || ((mode) == GPIO_MODE_ANALOG) || \
                                     		(((mode) <= 0x4F) && ((MODE) >= 0x48)) || \
                                     		(((mode) <= 0x5F) && ((MODE) >= 0x58)) || \
                                     		(((mode) <= 0x6F) && ((MODE) >= 0x68)) || \
                                     		(((mode) <= 0x8F) && ((MODE) >= 0x88)) || \
                                     		(((mode) <= 0x9F) && ((MODE) >= 0x98)) || \
                                     		(((mode) <= 0xAF) && ((MODE) >= 0xA8)))


/** @defgroup  GPIO_mf GPIO mode definition
  * @{
  */

#define GPIO_MF_SEL0        				((uint8_t)0x00)     	/*!< GPIO MF0(multi-function 0 selection) definition. */
#define GPIO_MF_SEL1        				((uint8_t)0x01)     	/*!< GPIO MF1(multi-function 1 selection) definition. */
#define GPIO_MF_SEL2        				((uint8_t)0x02)     	/*!< GPIO MF2(multi-function 2 selection) definition. */
#define GPIO_MF_SEL3        				((uint8_t)0x03)     	/*!< GPIO MF3(multi-function 3 selection) definition. */
#define GPIO_MF_SEL4        				((uint8_t)0x04)     	/*!< GPIO MF4(multi-function 4 selection) definition. */
#define GPIO_MF_SEL5        				((uint8_t)0x05)    	    /*!< GPIO MF5(multi-function 5 selection) definition. */
#define GPIO_MF_SEL6        				((uint8_t)0x06)     	/*!< GPIO MF6(multi-function 6 selection) definition. */
#define GPIO_MF_SEL7        				((uint8_t)0x07)     	/*!< GPIO MF7(multi-function 7 selection) definition. */
/**
  * @}
  */

/*! Checks GPIO mode. */
#define GPIO_MF_CHECK(sel)      			(((sel) == GPIO_MF_SEL0) || ((sel) == GPIO_MF_SEL1) || ((sel) == GPIO_MF_SEL2) || \
                                 			((sel) == GPIO_MF_SEL3) || ((sel) == GPIO_MF_SEL4) || ((sel) == GPIO_MF_SEL5) || \
                                 			((sel) == GPIO_MF_SEL6) || ((sel) == GPIO_MF_SEL7))
/**
  * @}
  */


/***************************************************************************************************
 * @functions
***************************************************************************************************/
/** @defgroup GPIO_Exported_Functions GPIO Exported Functions
  * @{
  */

/**
  * @brief  Reads the specified input port pin.
  * @param  PORT: Pointer to GPIOx, where x only can be A.
  * @return The input port pin value.
  */
#define __GPIO_INPUT_DATA_GET(PORT)         ((uint16_t)PORT->DI)

/**
  * @brief  Checks the specified input data port bit is set or not.
  * @param  PORT: Pointer to GPIOx, where x only can be A.
  * @param  PIN: Specifies the port bits to be check (one of the GPIO_PIN_0 to GPIO_PIN_13).
  * @return Input data port bit status.
  */
#define __GPIO_INPUT_PIN_GET(PORT, PIN)     ((PORT->DI & (uint16_t)PIN) ? SET : RESET)

/**
  * @brief  Reads the specified output port data.
  * @param  PORT: Pointer to GPIOx, where x only can be A.
  * @return The input port output value.
  */
#define __GPIO_OUTPUT_DATA_GET(PORT)        ((uint16_t)PORT->DO)

/**
  * @brief  Checks the specified output data port bit is set or not.
  * @param  PORT: Pointer to GPIOx, where x only can be A.
  * @param  PIN: Specifies the port bits to be check (one of the GPIO_PIN_0 to GPIO_PIN_13).
  * @return Output data port bit status.
  */
#define __GPIO_OUTPUT_PIN_GET(PORT, PIN)    ((PORT->DO & (uint16_t)PIN) ? SET : RESET)

/**
  * @brief  Writes data to the specified GPIO data port.
  * @param  PORT: Pointer to GPIOx, where x only can be A.
  * @param  DATA: Specifies the value to be written to the port output data register.
  * @return None.
  */
#define __GPIO_DATA_SET(PORT, DATA)         (PORT->DO = DATA)

/**
  * @brief  Sets the selected data port bits.
  * @param  PORT: Pointer to GPIOx, where x only can be A.
  * @param  PIN: Specifies the port bits to be set (support any combination of GPIO_PIN_0 to GPIO_PIN_13).
  * @return None.
  */
#define __GPIO_PIN_SET(PORT, PIN)           (PORT->SCR = (uint32_t)PIN)

/**
  * @brief  Clears the selected data port bits.
  * @param  PORT: Pointer to GPIOx, where x only can be A.
  * @param  PIN: Specifies the port bits to be clear (support any combination of GPIO_PIN_0 to GPIO_PIN_13).
  * @return None.
  */
#define __GPIO_PIN_RESET(PORT, PIN)         (PORT->CLRR = (uint32_t)PIN)

/**
  * @brief  Deinitializes the GPIOx peripheral registers to their default reset values.
  * @param  PORT: Pointer to GPIOx, where x only can be A.
  * @return None.
  */
#define __GPIO_DEF_INIT(PORT)               do{ \
                                                __RCU_PERI_RST_ENABLE(PORT); \
                                                __RCU_PERI_RST_DISABLE(PORT); \
                                            }while(0)

/**
  * @brief  Sets the specified IO as specified mode.
  * @param  ptr_gpio: Pointer to GPIOx, where x only can be A.
  * @param  pin: Specifies the port bits to be clear (support any combination of GPIO_PIN_0 to GPIO_PIN_13).
  * @param  mode: Mode selection.
  *         It can be one of the following values:
  *          @arg GPIO_MODE_ANALOG: GPIO analog in/out mode.
  *          @arg GPIO_MODE_IN_FLOAT: GPIO input.
  *          @arg GPIO_MODE_IN_PU: GPIO input pull up.
  *          @arg GPIO_MODE_IN_PD: GPIO input pull down.
  *          @arg GPIO_MODE_OUT_PP(SPEED): GPIO output no pull push-pull.
  *          @arg GPIO_MODE_OUT_PP_PU(SPEED): GPIO output pull up push-pull.
  *          @arg GPIO_MODE_OUT_PP_PD(SPEED): GPIO output pull down push-pull.
  *          @arg GPIO_MODE_OUT_OD(SPEED): GPIO output no pull open drain.
  *          @arg GPIO_MODE_OUT_OD_PU(SPEED): GPIO output pull up open drain.
  *          @arg GPIO_MODE_OUT_OD_PD(SPEED): GPIO output pull down open drain.
  *          @arg GPIO_MODE_MF_PP(SPEED): GPIO multiplex no pull push-pull.
  *          @arg GPIO_MODE_MF_PP_PU(SPEED): GPIO multiplex pull up push-pull.
  *          @arg GPIO_MODE_MF_PP_PD(SPEED): GPIO multiplex pull down push-pull.
  *          @arg GPIO_MODE_MF_OD(SPEED): GPIO multiplex no pull open drain.
  *          @arg GPIO_MODE_MF_OD_PU(SPEED): GPIO multiplex pull up open drain.
  *          @arg GPIO_MODE_MF_OD_PD(SPEED): GPIO multiplex pull down open drain.
  * @return None.
  */
void gpio_mode_set(gpio_reg_t * ptr_gpio, uint16_t pin, uint32_t mode);

/**
  * @brief  Locks GPIO pins configuration registers(PFR, PODENR, POSR, PUPDR, MFSELL, MFSELH).
  * @param  ptr_gpio: Pointer to GPIOx where x only can be A.
  * @param  pin: Specifies the port bits to be clear (support any combination of GPIO_PIN_0 to GPIO_PIN_13).
  * @note   The configuration of the locked GPIO pins can not be modified until the device reset.
  * @return None.
  */
void gpio_pin_lock_config(gpio_reg_t * ptr_gpio, uint16_t pin);

/**
  * @brief  Config the specified GPIO data port multi-function selection.
  * @param ptr_gpio: Pointer to GPIOx, where x only can be A.
  * @param  pin: Specifies the port bits to be clear (support any combination of GPIO_PIN_0 to GPIO_PIN_13).
  * @param  select: Selects the pin to used as multi-function selection.
  *         It can be one of the following values:
  *          @arg GPIO_MF_SEL0: Multi-function 0(See the data sheet for specific multiplexing functions).
  *          @arg GPIO_MF_SEL1: Multi-function 1(See the data sheet for specific multiplexing functions).
  *          @arg GPIO_MF_SEL2: Multi-function 2(See the data sheet for specific multiplexing functions).
  *          @arg GPIO_MF_SEL3: Multi-function 3(See the data sheet for specific multiplexing functions).
  *          @arg GPIO_MF_SEL4: Multi-function 4(See the data sheet for specific multiplexing functions).
  *          @arg GPIO_MF_SEL5: Multi-function 5(See the data sheet for specific multiplexing functions).
  *          @arg GPIO_MF_SEL6: Multi-function 6(See the data sheet for specific multiplexing functions).
  *          @arg GPIO_MF_SEL7: Multi-function 7(See the data sheet for specific multiplexing functions).
  * @return None.
  */
void gpio_mf_config(gpio_reg_t* ptr_gpio, uint16_t pin, uint8_t select);
/**
  * @}
  */


#ifdef __cplusplus
}
#endif

#endif /* cbm858xm_gpio.h */


/**
  * @}
  */

/**
  * @}
  */

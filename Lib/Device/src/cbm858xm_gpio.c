/**
* @file        cbm858xm_gpio.c
* @brief       This file provides all the basic GPIO firmware functions.
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


/***************************************************************************************************
 * @includes
***************************************************************************************************/
#include "cbm858xm_gpio.h"


/***************************************************************************************************
 * @definitions
***************************************************************************************************/
#define GPIO_MODE_MASK          ((uint8_t)0xC0)     /*!< GPIO mode masks. */
#define GPIO_PUPD_MASK          ((uint8_t)0x30)     /*!< GPIO pull up/down masks. */
#define GPIO_OUTYPE_MASK        ((uint8_t)0x0C)     /*!< GPIO output type masks. */
#define GPIO_SPEED_MASK         ((uint8_t)0x03)     /*!< GPIO speed masks. */


/** @addtogroup CBM858xM_StdPeriph_Driver
  * @{
  */

/** @defgroup GPIO GPIO
  * @brief    GPIO driver modules
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
void gpio_mode_set(gpio_reg_t * ptr_gpio, uint16_t pin, uint32_t mode)
{
    uint8_t pos = 0;
    uint32_t clearmask   = 0x00;
    uint32_t setmask[3]  = {0x00};
    uint32_t mode_temp   = (mode & GPIO_MODE_MASK) >> 6;
    uint32_t pupd_temp   = (mode & GPIO_PUPD_MASK) >> 4;
    uint32_t outype_temp = (mode & GPIO_OUTYPE_MASK);

    ASSERT(GPIO_ALL_PORT_CHECK(ptr_gpio));
    ASSERT(GPIO_PIN_CHECK(pin));
    ASSERT(GPIO_MODE_CHECK(mode));
    
    /* mode,bit3:output; bit2:reg PODENR open drain. */
    if(outype_temp == GPIO_OUTYPE_MASK)
    {
        ptr_gpio->PODENR |= pin;
    }
    else if(outype_temp == 0x08)
    {
        ptr_gpio->PODENR &= ~pin;
    }

    while(pin)
    {
        if(pin & 0x01)
        {
            /* mode,bit1~bit0:reg POSR; bit4~bit5:reg pupd_temp; bit6~bit7:reg PFR . */
            clearmask  |= (uint32_t)GPIO_SPEED_MASK << (pos *2);
            setmask[0] |= (uint32_t)((mode & GPIO_SPEED_MASK) << (pos * 2));
            setmask[1] |= (uint32_t)(mode_temp << (pos * 2));
            setmask[2] |= (uint32_t)(pupd_temp << (pos * 2));
        }
        pos++;
        pin = pin >> 1;
    }

    MODIFY_REG(ptr_gpio->POSR,  clearmask, setmask[0]);
    MODIFY_REG(ptr_gpio->PFR,   clearmask, setmask[1]);
    MODIFY_REG(ptr_gpio->PUPDR, clearmask, setmask[2]);
}


/**
  * @brief  Locks GPIO pins configuration registers(PFR, PODENR, POSR, PUPDR, MFSELL, MFSELH).
  * @param  ptr_gpio: Pointer to GPIOx where x only can be A.
  * @param  pin: Specifies the port bits to be clear (support any combination of GPIO_PIN_0 to GPIO_PIN_13).
  * @note   The configuration of the locked GPIO pins can not be modified until the device reset.
  * @return None.
  */
void gpio_pin_lock_config(gpio_reg_t * ptr_gpio, uint16_t pin)
{
    __IO uint32_t temp = 0x00010000;

    ASSERT(GPIO_PORT_LIST1_CHECK(ptr_gpio));
    ASSERT(GPIO_PIN_CHECK(pin));
    
    temp |= pin;
    /* Set lock. */  
    ptr_gpio->LOCK = temp;  
    /* Reset lock. */ 
    ptr_gpio->LOCK = pin;
    /* Set lock. */ 
    ptr_gpio->LOCK = temp; 
    /* Get lock. */  
    (void)ptr_gpio->LOCK;
    /* Get lock. */
    (void)ptr_gpio->LOCK;
}


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
void gpio_mf_config(gpio_reg_t* ptr_gpio, uint16_t pin, uint8_t select)
{
    uint8_t pos = 0;
    uint32_t reg[2] = {ptr_gpio->MFSEL[0], ptr_gpio->MFSEL[1]};

    ASSERT(GPIO_PORT_LIST1_CHECK(ptr_gpio));
    ASSERT(GPIO_PIN_CHECK(pin));
    ASSERT(GPIO_MF_CHECK(select));

    while(pin)
    {
        if(pin & 0x01)
        {
            /* 4bit config. */
            reg[pos >> 3] &= ~(uint32_t)((0x07) << (pos & 0x07) * 4);
            reg[pos >> 3] |= (uint32_t)((select) << (pos & 0x07) * 4);
        }
        pos++;
        pin = pin >> 1;
    }
    ptr_gpio->MFSEL[0] = reg[0];
    ptr_gpio->MFSEL[1] = reg[1];
}

///@endcond

/**
  * @}
  */

/**
  * @}
  */

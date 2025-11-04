/**
* @file        cbm858xm_syscfg.c
* @brief       This file provides all the basic SYSCFG firmware functions.
* @author      ChipSea MCU Group
* @version     1.0.0
* @date        2022.06.07
* @copyright   CHIPSEA TECHNOLOGIES (SHENZHEN) CORP.
* @note        
****************************************************************************************************
* @par Modify record:
* <tr><th>Date          <th>Version    <th>Author     <th>Description
* <tr><td>2022.06.07    <td>1.0.0      <td>ChipSea    <td>
* -# 
* </table>
*
****************************************************************************************************
*/


/***************************************************************************************************
 * @includes
***************************************************************************************************/
#include "cbm858xm_syscfg.h"


/***************************************************************************************************
 * @definitions
***************************************************************************************************/


/** @addtogroup CBM858xM_StdPeriph_Driver
  * @{
  */

/** @defgroup SYSCFG SYSCFG
  * @brief    SYSCFG driver modules
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
  * @brief  Deinitializes the SYSCFG registers to their default reset values.
  * @param  None.
  * @note   MEM_REMAP and ERRLOCK are not affected by APB reset.
  * @return None.
  */
void syscfg_def_init(void)
{
    /* Set SYSCFG_CFGR1 register to reset value without affecting MEM_RMAP bit. */
    SYSCFG->RMAPCFG &= SYSCFG_RMAPCFG_MEM_RMAP;
    SYSCFG->EXTISRC[0] = 0;
    SYSCFG->EXTISRC[1] = 0;
    SYSCFG->EXTISRC[2] = 0;
    SYSCFG->EXTISRC[3] = 0;
	
    /* Clear SRAM parity error flag. */
    SYSCFG->ERRLOCK |= SYSCFG_ERRLOCK_SRAM_PRTY_ERR;
}

/**
  * @brief  Set the memory mapping at address 0x00000000.
  * @param  value: selects the memory remapping, it can be:
  *          @arg SYSCFG_MEM_REMAP_FLASH(Main Flash memory mapped at 0x00000000)
  *          @arg SYSCFG_MEM_REMAP_SYS_MEMORY(System Flash memory mapped at 0x00000000)
  *          @arg SYSCFG_MEM_REMAP_SRAM(Embedded SRAM mapped at 0x00000000)
  * @return None.
  */
void syscfg_memory_remap_set(uint32_t value)
{
    ASSERT(SYSCFG_MEM_REMAP_CHECK(value));

    /* Set the memory remap value. */
	MODIFY_REG(SYSCFG->RMAPCFG, SYSCFG_RMAPCFG_MEM_RMAP, value);
}


/**
  * @brief	forbid ram boot.
  * @param	status: It can be ENABLE or DISABLE.
  * @return None.
  */
void syscfg_forbid_ram_boot_enable(enable_state_t status)
{
	ASSERT(FUNCTIONAL_STATE_CHECK(status));

	if(status != DISABLE)
    {
		SYSCFG->RAMBT |= SYSCFG_RAMBOOT_FORBID;
	}
	else
	{
		SYSCFG->RAMBT &= ~SYSCFG_RAMBOOT_FORBID;
	}
}


/**
  * @brief  Congig the fast driver capability on specific pin.
  * @param  pin: Specifies the fast mode driver pin.
  *			It can be one of the following values: 
  *          @arg SYSCFG_I2C_FMP_PIN_10: Configure fast mode for PA10.
  *          @arg SYSCFG_I2C_FMP_PIN_11: Configure fast mode for PA11.

  * @param  pin: Specifies the fast mode capbility.
  *			It can be one of the following values: 
  *          @arg SYSCFG_I2C_FMP_CAPABLITY_3MA: Configure standard mode 3mA driving capability.
  *          @arg SYSCFG_I2C_FMP_CAPABLITY_6MA: Configure fast mode 6mA driving capability.
  *          @arg SYSCFG_I2C_FMP_CAPABLITY_9MA: Configure fast mode 9mA driving capability.
  *          @arg SYSCFG_I2C_FMP_CAPABLITY_20MA: Configure fast mode 20mA driving capability.
  * @return None.
  */
void syscfg_fast_mode_config(uint8_t pin, uint32_t capbility)
{
    ASSERT(SYSCFG_FMP_PIN_CHECK(pin));
	ASSERT(SYSCFG_FMP_CAPABLITY_CHECK(capbility));

	if(pin == SYSCFG_I2C_FMP_PIN_10)
	{
	    SYSCFG->RMAPCFG &= ~SYSCFG_RMAPCFG_I2C_FMPEN_PA10_MASK;
		SYSCFG->RMAPCFG |= (capbility<<20);
	}
	else
	{
	    SYSCFG->RMAPCFG &= ~SYSCFG_RMAPCFG_I2C_FMPEN_PA11_MASK;
		SYSCFG->RMAPCFG |= (capbility<<22);
	}
}

/**
  * @brief  Selects the GPIO pin used as EXTI Line.
  * @param  port: Selects the GPIO port to be used as source for EXTI lines. It can be one of following values:
  *                 @arg SYSCFG_EXTI_PORT_PA
  * @param  pin: Specifies the EXTI line to be configured. 
  *              It can be a value between SYSCFG_EXTI_PIN_0 ~ SYSCFG_EXTI_PIN_15.
  * @return None.
  */
void syscfg_exti_line_config(uint8_t port, uint8_t pin)
{
	uint8_t idx   = 0x00;
	uint8_t shift = 0x00;

    ASSERT(SYSCFG_EXTI_PORT_CHECK(port));
    ASSERT(SYSCFG_EXTI_PIN_CHECK(pin));

	idx   = pin >> 2;
	shift = (pin & 0x03) * 4;
	
	MODIFY_REG(SYSCFG->EXTISRC[idx], (uint32_t)0x0F << shift, (uint32_t)port << shift);	
}

/**
  * @brief  Configures the GPIO threshold voltage.
  * @param  port: Specifies the GPIO port to configure,only can SYSCFG_VTH_PORT_PA.                    
  * @param  pin: Specifies the GPIO pin to configure.
  * 		 It can be one of the following values:
  *		  @arg SYSCFG_EXTI_PIN_10
  *		  @arg SYSCFG_EXTI_PIN_11
  * @param  volt: Specifies the threshold voltage to configure. 
  *			It can be one of the following values:
  *          @arg SYSCFG_GPIO_VTH_VDD (Set threshold voltage is VDD).
  *          @arg SYSCFG_GPIO_VTH_1V8 (Set threshold voltage is 1.8V).
  *          @arg SYSCFG_GPIO_VTH_1V2 (Set threshold voltage is 1.2V).
  * @note  None.
  * @return None.
  */
void syscfg_gpio_vth_config(uint8_t port, uint8_t pin, uint32_t volt)
{
    ASSERT(SYSCFG_VTH_PORT_CHECK(port));
    ASSERT(SYSCFG_VTH_PIN_CHECK(pin));	
	ASSERT(SYSCFG_GPIO_VTH_CHECK(volt));

	MODIFY_REG(SYSCFG->GPIO_VTH, (uint32_t)0x03 << (pin * 2), (uint32_t)volt << (pin * 2));
}

/**
  * @brief  Configures the trng clock.
  * @param  clock: Specifies the clock select. 
  *			It can be one of the following values:
  *          @arg SYSCFG_TRNG_SYSCLK
  *          @arg SYSCFG_TRNG_ROCLK
  * @return None.
  */
void syscfg_trng_clock_select(uint32_t clock)
{
	ASSERT(SYSCFG_TRNG_CLOCK_CHECK(clock));
	MODIFY_REG(SYSCFG->TRNG, SYSCFG_TRNG_KEY|SYSCFG_TRNG_CKS, SYSCFG_TRNG_KEY_VALUE|clock);
}

/**
  * @brief	Trng bypass enable.
  * @param	status: It can be ENABLE or DISABLE.
  * @return None.
  */
void syscfg_trng_bypass_enable(enable_state_t status)
{
	ASSERT(FUNCTIONAL_STATE_CHECK(status));

	if(status != DISABLE)
    {
		MODIFY_REG(SYSCFG->TRNG, SYSCFG_TRNG_KEY|SYSCFG_TRNG_BYEN, SYSCFG_TRNG_KEY_VALUE|0x01);
	}
	else
	{
        MODIFY_REG(SYSCFG->TRNG, SYSCFG_TRNG_KEY|SYSCFG_TRNG_BYEN, SYSCFG_TRNG_KEY_VALUE|0x00);
	}
}

/**
  * @brief	AFE charge mos enable.
  * @param	status: It can be ENABLE or DISABLE.
  * @return None.
  */
void syscfg_afe_con_enable(enable_state_t status)
{
    ASSERT(FUNCTIONAL_STATE_CHECK(status));

	if(status != DISABLE)
    {
		MODIFY_REG(SYSCFG->AFE, SYSCFG_AFE_KEY|SYSCFG_AFE_CON, SYSCFG_AFE_KEY_VALUE|0x01);
	}
	else
	{
        MODIFY_REG(SYSCFG->AFE, SYSCFG_AFE_KEY|SYSCFG_AFE_CON, SYSCFG_AFE_KEY_VALUE|0x00);
	}
}

/**
  * @brief	AFE discharge mos enable.
  * @param	status: It can be ENABLE or DISABLE.
  * @return None.
  */
void syscfg_afe_don_enable(enable_state_t status)
{
    ASSERT(FUNCTIONAL_STATE_CHECK(status));

	if(status != DISABLE)
    {
		MODIFY_REG(SYSCFG->AFE, SYSCFG_AFE_KEY|SYSCFG_AFE_DON, SYSCFG_AFE_KEY_VALUE|0x02);
	}
	else
	{
        MODIFY_REG(SYSCFG->AFE, SYSCFG_AFE_KEY|SYSCFG_AFE_DON, SYSCFG_AFE_KEY_VALUE|0x00);
	}
}

/**
  * @brief	AFE reset.
  * @param	status: It can be ENABLE or DISABLE.
  * @return None.
  */
void syscfg_afe_rst_enable(enable_state_t status)
{
    ASSERT(FUNCTIONAL_STATE_CHECK(status));

	if(status != DISABLE)
    {
		MODIFY_REG(SYSCFG->AFE, SYSCFG_AFE_KEY|SYSCFG_AFE_RST, SYSCFG_AFE_KEY_VALUE|0x04);
	}
	else
	{
        MODIFY_REG(SYSCFG->AFE, SYSCFG_AFE_KEY|SYSCFG_AFE_RST, SYSCFG_AFE_KEY_VALUE|0x00);
	}
}


///@endcond

/**
  * @}
  */

/**
  * @}
  */

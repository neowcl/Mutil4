/**
* @file        cbm858xm_misc.h
* @brief       This file contains all the functions prototypes for the PPP firmware library. 
* @author      ChipSea MCU Group
* @version     1.0.0
* @date        2022.06.30
* @copyright   CHIPSEA TECHNOLOGIES (SHENZHEN) CORP.
* @note        
****************************************************************************************************
* @par Modify record:
* <tr><th>Date          <th>Version    <th>Author     <th>Description
* <tr><td>2022.06.30    <td>1.0.0      <td>ChipSea    <td>
* -# 
* </table>
*
****************************************************************************************************
*/


#ifndef __CBM858xM_MISC_H__
#define __CBM858xM_MISC_H__


#ifdef __cplusplus
 extern "C" {
#endif


/***************************************************************************************************
 * @includes
***************************************************************************************************/
#include "cbm858xm.h"


/** @addtogroup CBM858xM_StdPeriph_Driver
  * @{
  */

/** @addtogroup MISC
  * @{
  */

/***************************************************************************************************
 * @definitions
***************************************************************************************************/
/** @defgroup MISC_Exported_Types MISC Exported Types
  * @{
  */

/** @struct nvic_config_t
  * @brief  NVIC config Structure definition  
  */
typedef struct
{
    uint8_t IRQn;           		/*!< Specifies the IRQ number to be enabled or disabled */
    uint8_t priority;      			/*!< Specifies the priority level(0~3) for the IRQ channel */
    enable_state_t enable_flag;    	/*!< Enabled or disabled the IRQ channel */                                                                                        
}nvic_config_t;

/**
  * @}
  */


/** @defgroup MISC_Exported_Constants MISC Exported Constants
  * @{
  */

/**
  * @}
  */

/** @defgroup MISC_System_LP MISC system LP(low power) definition
  * @{
  */
#define NVIC_LP_SEVONPEND           ((uint8_t)0x10)         /*!< Specifies low power sev on pend */ 
#define NVIC_LP_SLEEPDEEP           ((uint8_t)0x04)         /*!< Low power deep_sleep request */ 
#define NVIC_LP_SLEEPONEXIT         ((uint8_t)0x02)         /*!< Low power sleep on exit */      
/**
  * @}
  */

/*! MISC preemption priority group definition */
#define NVIC_PRIORITY_CHECK(value)  ((value) < 0x04)

/** @defgroup MISC_SysTick_clock_select MISC SysTick clock select definition
  * @{
  */
#define SYSTICK_CLKSEL_HCLK_DIV8    ((uint32_t)0x00000000)  /*!< SysTick clock source select HCLK/8 */
#define SYSTICK_CLKSEL_HCLK         ((uint32_t)0x00000004)  /*!< SysTick clock source select HCLK */
/**
  * @}
  */
#define SYSTICK_CLKSEL_CHECK(value) (((value) == SYSTICK_CLKSEL_HCLK) || ((value) == SYSTICK_CLKSEL_HCLK_DIV8))

/** @defgroup RCU_Macro_function RCU Macro function definition
  * @{
  */

/**
  * @brief  Enables low power SEV on pend.
  * @param  None.
  * @return None.
  */
#define LP_SEVONPEND_ENABLE()       (SCB->SCR |= NVIC_LP_SEVONPEND)

/**
  * @brief  Disables low power SEV on pend.
  * @param  None.
  * @return None.
  */
#define LP_SEVONPEND_DISABLE()      (SCB->SCR &= ~NVIC_LP_SEVONPEND)

/**
  * @brief  Enables low power DEEPSLEEP request.
  * @param  None.
  * @return None.
  */
#define LP_SLEEPDEEP_ENABLE()       (SCB->SCR |= NVIC_LP_SLEEPDEEP)

/**
  * @brief  Disables low power DEEPSLEEP request.
  * @param  None.
  * @return None.
  */
#define LP_SLEEPDEEP_DISABLE()      (SCB->SCR &= ~NVIC_LP_SLEEPDEEP)

/**
  * @brief  Enables low power sleep on exit.
  * @param  None.
  * @return None.
  */
#define LP_SLEEPONEXIT_ENABLE()     (SCB->SCR |= NVIC_LP_SLEEPONEXIT)

/**
  * @brief  Disables low power sleep on exit.
  * @param  None.
  * @return None.
  */
#define LP_SLEEPONEXIT_DISABLE()    (SCB->SCR &= ~NVIC_LP_SLEEPONEXIT)

/**
  * @}
  */

/***************************************************************************************************
 * @functions
***************************************************************************************************/
/** @defgroup MISC_Exported_Functions MISC Exported Functions
  * @{
  */

/**
  * @brief  Initializes the NVIC peripheral according to the specified parameters in the ptr_config.
  * @param  ptr_config: pointer to a nvic_config_t structure that contains the configuration information for the specified
  *         NVIC peripheral.
  * @return None.
  */
void nvic_init(nvic_config_t* ptr_config);

/**
  * @brief  Configures the SysTick clock source.
  * @param  select: specifies the SysTick clock source. It can be one of following values: 
  *         @arg SYSTICK_CLKSEL_HCLK_DIV8
  *         @arg SYSTICK_CLKSEL_HCLK
  * @return None.
  */
void systick_clock_config(uint32_t select);

/**
  * @}
  */


#ifdef __cplusplus
}
#endif

#endif /* cbm858xm_misc.h */


/**
  * @}
  */

/**
  * @}
  */

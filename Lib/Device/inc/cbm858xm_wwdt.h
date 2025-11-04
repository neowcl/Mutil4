/**
* @file        cbm858xm_wwdt.h
* @brief       This file contains all the functions prototypes for the WWDT firmware library. 
* @author      ChipSea MCU Group
* @version     1.0.0
* @date        2022.05.16
* @copyright   CHIPSEA TECHNOLOGIES (SHENZHEN) CORP.
* @note        
****************************************************************************************************
* @par Modify record:
* <tr><th>Date          <th>Version    <th>Author     <th>Description
* <tr><td>2022.05.16    <td>1.0.0      <td>ChipSea    <td>
* -# 
* </table>
*
****************************************************************************************************
*/


#ifndef __CBM858xM_WWDT_H__
#define __CBM858xM_WWDT_H__


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

/** @addtogroup WWDT
  * @{
  */

/***************************************************************************************************
 * @definitions
***************************************************************************************************/
/** @defgroup WWDT_Exported_Constants WWDT Exported Constants
  * @{
  */

#define WWDT_BIT_MASK                   	((uint8_t)0x7F)

/** @defgroup  WWDT_prescaler WWDT prescaler
  * @{
  */

#define WWDT_PRESCALER_1        			((uint32_t)0x00000000)
#define WWDT_PRESCALER_2        			((uint32_t)0x00000080)
#define WWDT_PRESCALER_4        			((uint32_t)0x00000100)
#define WWDT_PRESCALER_8        			((uint32_t)0x00000180)
/**
  * @}
  */

/*! Checks WWDT prescaler. */
#define WWDT_PRESCALER_CHECK(prescaler)     (((prescaler) == WWDT_PRESCALER_1) || ((prescaler) == WWDT_PRESCALER_2) || \
                                            ((prescaler) == WWDT_PRESCALER_4) || ((prescaler) == WWDT_PRESCALER_8))


/*! Checks WWDT window value. */
#define WWDT_WINDOW_VALUE_CHECK(value)      ((value) <= 0x7F)
/**
  * @}
  */


/***************************************************************************************************
 * @functions
***************************************************************************************************/
/** @defgroup WWDT_Exported_Functions WWDT Exported Functions
  * @{
  */

/**
  * @brief  Deinitializes the WWDT peripheral registers to their default reset values.
  * @param  None.
  * @return None.
  */
#define __WWDT_DEF_INIT()                   do{ \
                                                __RCU_PERI_RST_ENABLE(WWDT); \
                                                __RCU_PERI_RST_DISABLE(WWDT); \
                                            }while(0)

/**
  * @brief  Sets the WWDT counter value.
  * @param  VALUE: Specifies the watchdog counter value.
  * @note   This parameter must be a number between 0x40 and 0x7F (to prevent generating an immediate reset).
  * @return None.
  */
#define __WWDT_COUNTER_SET(VALUE)           (WWDT->CTR1 = ((VALUE) & WWDT_CTR1_CVAL))

/**
  * @brief  Enables WWDT.
  * @param  COUNTER: Specifies the initial counter value.
  * @return None.
  */
#define __WWDT_ENABLE(COUNTER)              (WWDT->CTR1 = (WWDT_CTR1_WWDTEN | COUNTER))

/**
  * @brief  Enables the WWDT wakeup interrupt.
  * @param  None.
  * @note   Once enabled, this interrupt cannot be disabled except by a system reset.
  * @return None.
  */
#define __WWDT_INTR_ENABLE()                (WWDT->CTR2 |= WWDT_CTR2_RMDIE)

/**
  * @brief  Checks whether the early wakeup interrupt flag is set or not.
  * @param  None.
  * @return The new state of the early wakeup interrupt flag (SET or RESET).
  */
#define __WWDT_FLAG_STATUS_GET()            ((WWDT->STS & WWDT_STS_RMDIF) ? SET : RESET)

/**
  * @brief  Clears early wakeup interrupt flag.
  * @param  None.
  * @return None.
  */
#define __WWDT_FLAG_CLEAR()                 (WWDT->STS = (uint32_t)RESET)

/**
  * @brief  Sets the WWDT prescaler.
  * @param  wwdt_prescaler: Specifies the WWDT prescaler.
  *         It can be one of the following values:
  *          @arg WWDT_PRESCALER_1: WWDT counter clock = (PCLK1/4096)/1.
  *          @arg WWDT_PRESCALER_2: WWDT counter clock = (PCLK1/4096)/2.
  *          @arg WWDT_PRESCALER_4: WWDT counter clock = (PCLK1/4096)/4.
  *          @arg WWDT_PRESCALER_8: WWDT counter clock = (PCLK1/4096)/8.
  * @return None.
  */
void wwdt_prescaler_set(uint32_t wwdt_prescaler);

/**
  * @brief  Sets the WWDT window value.
  * @param  window_value: Specifies the window value to be compared to the downcounter..
  * @note   This parameter value must be lower than 0x80.
  * @return None.
  */
void wwdt_window_value_set(uint8_t window_value);
/**
  * @}
  */


#ifdef __cplusplus
}
#endif

#endif /* cbm858xm_wwdt.h */


/**
  * @}
  */

/**
  * @}
  */

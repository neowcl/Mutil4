/**
* @file        cbm858xm_rngck.h
* @brief       This file contains all the functions prototypes for the RNGCK firmware library. 
* @author      ChipSea MCU Group
* @version     1.0.0
* @date        2022.06.15
* @copyright   CHIPSEA TECHNOLOGIES (SHENZHEN) CORP.
* @note        
****************************************************************************************************
* @par Modify record:
* <tr><th>Date          <th>Version    <th>Author     <th>Description
* <tr><td>2022.06.15    <td>1.0.0      <td>ChipSea    <td>
* -# 
* </table>
*
****************************************************************************************************
*/


#ifndef __CBM858xM_RNGCK_H__
#define __CBM858xM_RNGCK_H__


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

/** @addtogroup RNGCK
  * @{
  */

/***************************************************************************************************
 * @definitions
***************************************************************************************************/
/** @defgroup RNGCK_Exported_Types RNGCK Exported Types
  * @{
  */

//Fill the content
/**
  * @}
  */


/** @defgroup RNGCK_Exported_Constants RNGCK Exported Constants
  * @{
  */
#define RNGCK_MODE_0           0x00            /*!< Output clock long cycle without gate status. */
#define RNGCK_MODE_1           0x01            /*!< Output clock long cycle with 1/32 gate status. */
#define RNGCK_MODE_2           0x02            /*!< Output clock long cycle with 1/16 gate status. */
#define RNGCK_MODE_3           0x03            /*!< Output clock long cycle with 1/8 gate status. */

#define RNGCK_LFSR_0           0x01            /*!< LFSR is in all zero status, and an interrupt is generated. */
/**
  * @}
  */


/***************************************************************************************************
 * @functions
***************************************************************************************************/
/** @defgroup RNGCK_Exported_Functions RNGCK Exported Functions
  * @{
  */

//Fill the content
/**
  * @}
  */

/** @defgroup RNGCK_Macro_function I2C Macro function definition
  * @{
  */

/**
  * @brief  Set the random seed.
  * @param  value: The random seed, 32bits.
  * @return None.
  */
#define __RNGCK_SEED_SET(value)         (RNGCK->SEED = (uint32_t)value)

/**
  * @brief  Set the random mode.
  * @param  value: The random mode.It can be any combination of the following value:
  *          @arg: RNGCK_MODE_0(Output clock long cycle without gate status)
  *          @arg: RNGCK_MODE_1(Output clock long cycle with 1/32 gate status)
  *          @arg: RNGCK_MODE_2(Output clock long cycle with 1/16 gate status)
  *          @arg: RNGCK_MODE_3(Output clock long cycle with 1/8 gate status)
  * @return None.
  */
#define __RNGCK_MODE_SET(value)         (RNGCK->MODE = (uint8_t)value)

/**
  * @brief  Get the Random clcok IRQ status.
  * @param  None.
  * @return 0: LFSR is not in all zero status and no interrupt is generated.
  *         1: LFSR is in all zero status, and an interrupt is generated.
  */
#define __RNGCK_IRQ_STATUS_GET()        ((RNGCK->IRQ  & RNGCK_LFSR_0) ? SET : RESET)
/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* cbm858xm_rngck.h */


/**
  * @}
  */

/**
  * @}
  */

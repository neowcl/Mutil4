/**
* @file        cbm858x_afe_gcr.h
* @brief       This file contains all the functions prototypes for the GCR firmware library. 
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


#ifndef __CBM858x_AFE_GCR_H__
#define __CBM858x_AFE_GCR_H__


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

/** @addtogroup AFE_GCR
  * @{
  */

/***************************************************************************************************
 * @definitions
***************************************************************************************************/
/** @defgroup AFE_GCR_Types AFE_GCR Types
  * @{
  */

//Fill the content
/**
  * @}
  */


/** @defgroup AFE_GCR_Constants AFE_GCR Constants
  * @{
  */
#define GCR_PB_MFP_PB0      (uint16_t)0x0000                      /*!< PB0 function selection as PB0. */
#define GCR_PB_MFP_INT      (uint16_t)0x0001                      /*!< PB0 function selection as INT. */
#define GCR_PB_MFP_MCO      (uint16_t)0x0002                      /*!< PB0 function selection as MCO. */
#define GCR_PB_MFP_PRESN    (uint16_t)0x0003                      /*!< PB0 function selection as PRESN. */
#define GCR_PB_MFP_SHUTDOWN (uint16_t)0x0004                      /*!< PB0 function selection as SHUTDOWN. */
#define GCR_PB_MFP_LDO3V3   (uint16_t)0x0005                      /*!< PB0 function selection as LED3V3. */

/* Unlock the register write protection */
#define GCR_UNLOCK1_KEY1    (uint16_t)0x0059
#define GCR_UNLOCK1_KEY2    (uint16_t)0x0016
#define GCR_UNLOCK1_KEY3    (uint16_t)0x0088

/* Lock the register write protection */
#define GCR_LOCK_KEY        (uint16_t)0x0000                     

/**
  * @}
  */


/***************************************************************************************************
 * @functions
***************************************************************************************************/
/** @defgroup AFE_GCR_Functions AFE_GCR Functions
  * @{
  */
/**
  * @brief  Configure the PB0 multiplexed mode.
  * @param  select: Mode selection.It can be one of the following values:
  *          @arg GCR_PB_MFP_PB0: PB0 function selection as PB0
  *          @arg GCR_PB_MFP_INT: PB0 function selection as INT
  *          @arg GCR_PB_MFP_MCO: PB0 function selection as MCO
  *          @arg GCR_PB_MFP_PRESN: PB0 function selection as PRESN
  *          @arg GCR_PB_MFP_SHUTDOWN: PB0 function selection as SHUTDOWN
  *          @arg GCR_PB_MFP_LDO3V3: PB0 function selection as LED3V3
  * @note   None.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_gcr_pb0_mf_config(uint16_t select);


/**
  * @brief  Unlock the register write protection.
  * @param  None.
  * @note   None.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_gcr_reg_unlock(void);

/**
  * @brief  Lock the register write protection.
  * @param  None.
  * @note   None.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_gcr_reg_lock(void);
/**
  * @}
  */


#ifdef __cplusplus
}
#endif

#endif /* cbm858x_afe_gcr.h */


/**
  * @}
  */

/**
  * @}
  */

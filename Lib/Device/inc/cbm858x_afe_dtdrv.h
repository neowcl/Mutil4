/**
* @file        cbm858x_afe_dtdtv.h
* @brief       This file contains all the functions prototypes for the DTDRV firmware library. 
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


#ifndef __CBM858x_AFE_DTDTV_H__
#define __CBM858x_AFE_DTDTV_H__


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

/** @addtogroup AFE_DTDRV
  * @{
  */

/***************************************************************************************************
 * @definitions
***************************************************************************************************/
/** @defgroup AFE_DTDRV_Types AFE_DTDRV Types
  * @{
  */

//Fill the content
/**
  * @}
  */


/** @defgroup AFE_DTDRV_Constants AFE_DTDRV Constants
  * @{
  */
/* DTDRV VC definition */
#ifdef CBM8581
#define DTDRV_CVBLC_CB_VC5                   (uint16_t)0x0010     /*!< DTDRV CV5 enable. */
#endif
#define DTDRV_CVBLC_CB_VC4                   (uint16_t)0x0008     /*!< DTDRV CV4 enable. */
#define DTDRV_CVBLC_CB_VC3                   (uint16_t)0x0004     /*!< DTDRV CV3 enable. */
#define DTDRV_CVBLC_CB_VC2                   (uint16_t)0x0002     /*!< DTDRV CV2 enable. */
#define DTDRV_CVBLC_CB_VC1                   (uint16_t)0x0001     /*!< DTDRV CV1 enable. */

/* DTDRV ZVCHGC definition */
#define DTDRV_ZVCHGC_THREE_DIODE             (uint16_t)0x0006     /*!< Zero volt charge three diode. */
#define DTDRV_ZVCHGC_TWO_DIODE               (uint16_t)0x0004     /*!< Zero volt charge two diode. */
#define DTDRV_ZVCHGC_ONE_DIODE               (uint16_t)0x0002     /*!< Zero volt charge one diode. */
#define DTDRV_ZVCHGC_BYPASS                  (uint16_t)0x0000     /*!< Zero volt charge bypass. */

/**
  * @}
  */


/***************************************************************************************************
 * @functions
***************************************************************************************************/
/** @defgroup AFE_DTDRV_Functions AFE_DTDRV Functions
  * @{
  */
/**
  * @brief  Enable or disable battery voltage equalization.
  * @param	vc: Specifies the VC type.
  *               It can be one of the following values:
  *          	   @arg DTDRV_CVBLC_CB_VC5: VC5(Only for CBM8581). 
  *          	   @arg DTDRV_CVBLC_CB_VC4: VC4. 
  *				   @arg DTDRV_CVBLC_CB_VC3: VC3.
  *				   @arg DTDRV_CVBLC_CB_VC2: VC2.
  *				   @arg DTDRV_CVBLC_CB_VC1: VC1.
  * @param	enable_flag: It can be ENABLE or DISABLE.
  * @note   None.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_dtdrv_vc_enable_ctrl(uint16_t vc, uint8_t enable_flag);

/**
  * @brief  Get the DTDRV battery voltage equalization enable status.
  * @param	vc: Specifies the VC type.
  *               It can be one of the following values:
  *          	   @arg DTDRV_CVBLC_CB_VC5: VC5(Only for CBM8581). 
  *                @arg DTDRV_CVBLC_CB_VC4: VC4. 
  *				   @arg DTDRV_CVBLC_CB_VC3: VC3.
  *				   @arg DTDRV_CVBLC_CB_VC2: VC2.
  *				   @arg DTDRV_CVBLC_CB_VC1: VC1.
  * @param	status: enable status,1: enbale; 0: disable.
  * @note   None.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_dtdrv_vc_enable_status_get(uint16_t vc,uint8_t* status);

/**
  * @brief  Enable or disable battery connection check .
  * @param	vc: Specifies the the VC type.
  *               It can be one of the following values:
  *          	   @arg DTDRV_CVBLC_CB_VC5: VC5(Only for CBM8581). 
  *                @arg DTDRV_CVBLC_CB_VC4: VC4.
  *				   @arg DTDRV_CVBLC_CB_VC3: VC3. 
  *				   @arg DTDRV_CVBLC_CB_VC2: VC2.
  *				   @arg DTDRV_CVBLC_CB_VC1: VC1.
  * @param	enable_flag: It can be ENABLE or DISABLE.
  * @note   None.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_dtdrv_vc_connect_check_ctrl(uint16_t vc, uint8_t enable_flag);

/**
  * @brief  Get the DTDRV battery connection check enable status.
  * @param	vc: Specifies the VC type.
  *               It can be one of the following values:
  *          	   @arg DTDRV_CVBLC_CB_VC5: VC5(Only for CBM8581). 
  *                @arg DTDRV_CVBLC_CB_VC4: VC4. 
  *				   @arg DTDRV_CVBLC_CB_VC3: VC3.
  *				   @arg DTDRV_CVBLC_CB_VC2: VC2.
  *				   @arg DTDRV_CVBLC_CB_VC1: VC1.
  * @param	status: enable status,1: enbale; 0: disable.
  * @note   None.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_dtdrv_vc_connect_check_status_get(uint16_t vc,uint8_t* status);

/**
  * @brief  Enable or disable fuse fusing .
  * @param	enable_flag: It can be ENABLE or DISABLE.
  * @note   None.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_dtdrv_fusing_enable_ctrl(uint8_t enable_flag);

/**
  * @brief  Enable or disable zero voltage charge.
  * @param	enable_flag: It can be ENABLE or DISABLE.
  * @note   None.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_dtdrv_zvcharge_enable_ctrl(uint8_t enable_flag);

/**
  * @brief  Config current balance value.
  * @param	current_value: Specifies the current value to config.
  *                it can be one of the following values:
  *				   @arg DTDRV_ZVCHGC_THREE_DIODE: Three diode in series(Default config).
  *                @arg DTDRV_ZVCHGC_TWO_DIODE: Two diode in series.
  *				   @arg DTDRV_ZVCHGC_ONE_DIODE: One diode in series.
  *				   @arg DTDRV_ZVCHGC_BYPASS: Bypass.
  * @note   None.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_dtdrv_zvcharge_diode_serial_config(uint16_t current_value);



/**
  * @}
  */


#ifdef __cplusplus
}
#endif

#endif /* cbm858x_afe_dtdtv.h */


/**
  * @}
  */

/**
  * @}
  */

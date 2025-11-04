/**
* @file        cbm858x_afe_cddrv.h
* @brief       This file contains all the functions prototypes for the CDDRV firmware library. 
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


#ifndef __CBM858x_AFE_CDDRV_H__
#define __CBM858x_AFE_CDDRV_H__


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

/** @addtogroup AFE_CDDRV
  * @{
  */

/***************************************************************************************************
 * @definitions
***************************************************************************************************/
/** @defgroup AFE_CDDRV_Types AFE_CDDRV Types
  * @{
  */

//Fill the content
/**
  * @}
  */


/** @defgroup AFE_CDDRV_Constants AFE_CDDRV Constants
  * @{
  */

/**
  * @}
  */


/***************************************************************************************************
 * @functions
***************************************************************************************************/
/** @defgroup AFE_CDDRV_Functions AFE_CDDRV Functions
  * @{
  */
/**
  * @brief	Enable or disable CHG/DSG MOS.
  * @param  enable_flag: It can be ENABLE or DISABLE.
  * @note	None.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_cddrv_chgdsg_mos_enable_ctrl(uint8_t enable_flag);

/**
  * @brief	Enable or disable cddrv charge.
  * @param  enable_flag: It can be ENABLE or DISABLE.
  * @note	None.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_cddrv_charge_enable_ctrl(uint8_t enable_flag);

/**
  * @brief	Get the cddrv charge enable status.
  * @param	status: enable status,1: enbale; 0: disable.
  * @note	None.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_cddrv_charge_enable_status_get(uint8_t* status);

/**
  * @brief	Enable or disable cddrv discharge.
  * @param	enable_flag: It can be ENABLE or DISABLE.
  * @note	None.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_cddrv_discharge_enable_ctrl(uint8_t enable_flag);

/**
  * @brief	Get the cddrv discharge enable status.
  * @param	status: enable status,1: enbale; 0: disable.
  * @note	None.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_cddrv_discharge_enable_status_get(uint8_t* status);

/**
  * @brief	Enable or disable cddrv prepare charge.
  * @param 	enable_flag: It can be ENABLE or DISABLE.
  * @note	None.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_cddrv_precharge_enable_ctrl(uint8_t enable_flag);

/**
  * @brief	Get the cddrv precharge enable status.
  * @param	status: enable status,1: enbale; 0: disable.
  * @note	None.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_cddrv_precharge_enable_status_get(uint8_t* status);

/**
  * @brief	Enable or disable cddrv forbid charge.
  * @param	enable_flag: It can be ENABLE or DISABLE.
  * @note	None.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_cddrv_forbid_charge_ctrl(uint8_t enable_flag);

/**
  * @brief	Get the cddrv forbid charge status.
  * @param	status: enable status,1: enbale; 0: disable.
  * @note	None.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_cddrv_forbid_charge_status_get(uint8_t* status);

/**
  * @brief	Enable or disable cddrv fly mode.
  * @param	enable_flag: It can be ENABLE or DISABLE.
  * @note	None.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_cddrv_fly_mode_enable_ctrl(uint8_t enable_flag);

/**
  * @brief	Get the cddrv fly mode enable status.
  * @param	status: enable status,1: enbale; 0: disable.
  * @note	None.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_cddrv_fly_mode_enable_status_get(uint8_t* status);


/**
  * @brief	Enable or disable C_ON/D_ON signal.
  * @param	enable_flag: It can be ENABLE or DISABLE.
  * @note	None.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_cddrv_cdon_enable_ctrl(uint8_t enable_flag);
/**
  * @}
  */


#ifdef __cplusplus
}
#endif

#endif /* cbm858x_afe_cddrv.h */


/**
  * @}
  */

/**
  * @}
  */

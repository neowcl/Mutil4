/**
* @file        cbm858x_afe_wkcp.h
* @brief       This file contains all the functions prototypes for the WKCP firmware library. 
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


#ifndef __CBM858x_AFE_WKCP_H__
#define __CBM858x_AFE_WKCP_H__


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

/** @addtogroup AFE_WKCP
  * @{
  */

/***************************************************************************************************
 * @definitions
***************************************************************************************************/
/** @defgroup AFE_WKCP_Types AFE_WKCP Types
  * @{
  */

//Fill the content
/**
  * @}
  */


/** @defgroup AFE_WKCP_Constants AFE_WKCP Constants
  * @{
  */

/* WKCP comparator threshold definition */
#define WKCP_THRESHOLD_0P625MV        (uint16_t)0x0000     /*!< WKCP comparator threshold 0.625mv. */
#define WKCP_THRESHOLD_1P25MV         (uint16_t)0x0001     /*!< WKCP comparator threshold 1.25mv. */
#define WKCP_THRESHOLD_2P5MV          (uint16_t)0x0002     /*!< WKCP comparator threshold 2.5mv. */
#define WKCP_THRESHOLD_5MV            (uint16_t)0x0003     /*!< WKCP comparator threshold 5mv. */

/* WKCP comparator filtering time definition */
#define WKCP_FILTERING_TIME_0US       (uint16_t)0x0000    /*!< WKCP comparator filtering time 0us. */
#define WKCP_FILTERING_TIME_61P04US   (uint16_t)0x0010    /*!< WKCP comparator filtering time 61.04us. */
#define WKCP_FILTERING_TIME_122P07US  (uint16_t)0x0020    /*!< WKCP comparator filtering time 122.07us. */
#define WKCP_FILTERING_TIME_183P11US  (uint16_t)0x0030    /*!< WKCP comparator filtering time 183.11us. */
#define WKCP_FILTERING_TIME_244P14US  (uint16_t)0x0040    /*!< WKCP comparator filtering time 244.14us. */
#define WKCP_FILTERING_TIME_305P18US  (uint16_t)0x0050    /*!< WKCP comparator filtering time 305.18us. */
#define WKCP_FILTERING_TIME_366P21US  (uint16_t)0x0060    /*!< WKCP comparator filtering time 366.21us. */
#define WKCP_FILTERING_TIME_427P25US  (uint16_t)0x0070    /*!< WKCP comparator filtering time 427.25us. */
#define WKCP_FILTERING_TIME_488P28US  (uint16_t)0x0080    /*!< WKCP comparator filtering time 488.28us. */
#define WKCP_FILTERING_TIME_549P32US  (uint16_t)0x0090    /*!< WKCP comparator filtering time 549.32us. */
#define WKCP_FILTERING_TIME_610P35US  (uint16_t)0x00a0    /*!< WKCP comparator filtering time 610.35us. */
#define WKCP_FILTERING_TIME_671P39US  (uint16_t)0x00b0    /*!< WKCP comparator filtering time 671.39us. */
#define WKCP_FILTERING_TIME_732P42US  (uint16_t)0x00c0    /*!< WKCP comparator filtering time 732.42us. */
#define WKCP_FILTERING_TIME_794P46US  (uint16_t)0x00d0    /*!< WKCP comparator filtering time 793.46us. */
#define WKCP_FILTERING_TIME_854P49US  (uint16_t)0x00e0    /*!< WKCP comparator filtering time 854.49us. */
#define WKCP_FILTERING_TIME_915P53US  (uint16_t)0x00f0    /*!< WKCP comparator filtering time 915.53us. */
/**
  * @}
  */


/***************************************************************************************************
 * @functions
***************************************************************************************************/
/** @defgroup AFE_WKCP_Functions AFE_WKCP Functions
  * @{
  */

/**
  * @brief  Enable or disable wkcp analog comparator.
  * @param voltage: voltage comparison value.
  *                it can be one of the following values:
  *				   @arg WKCP_COMPARATOR_THRESHOLD_0P625MV(Default config). 
  *				   @arg WKCP_COMPARATOR_THRESHOLD_1P25MV.
  *				   @arg WKCP_COMPARATOR_THRESHOLD_2P5MV.
  *				   @arg WKCP_COMPARATOR_THRESHOLD_5MV.
  * @paramfiltering_period: comparator filtering period.
  *                it can be one of the following values:
  *				   @arg WKCP_COMPARATOR_FILTERING_TIME_0US(Default config). 
  *				   @arg WKCP_COMPARATOR_FILTERING_TIME_61P04US.
  *				   @arg WKCP_COMPARATOR_FILTERING_TIME_122P07US.
  *				   @arg WKCP_COMPARATOR_FILTERING_TIME_183P11US.
  *                @arg WKCP_COMPARATOR_FILTERING_TIME_244P14US.
  *				   @arg WKCP_COMPARATOR_FILTERING_TIME_305P18US.
  *				   @arg WKCP_COMPARATOR_FILTERING_TIME_366P21US. 
  *                @arg WKCP_COMPARATOR_FILTERING_TIME_427P25US.
  *				   @arg WKCP_COMPARATOR_FILTERING_TIME_488P28US.
  *				   @arg WKCP_COMPARATOR_FILTERING_TIME_549P32US.
  *                @arg WKCP_COMPARATOR_FILTERING_TIME_610P35US.
  *				   @arg WKCP_COMPARATOR_FILTERING_TIME_671P39US.
  *				   @arg WKCP_COMPARATOR_FILTERING_TIME_732P42US. 
  *                @arg WKCP_COMPARATOR_FILTERING_TIME_794P46US.
  *				   @arg WKCP_COMPARATOR_FILTERING_TIME_854P49US.
  *				   @arg WKCP_COMPARATOR_FILTERING_TIME_915P53US.
  * @note   None.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_wkcp_comparator_config(uint16_t voltage, uint16_t filtering_period);

/**
  * @brief  Enable or disable wkcp analog comparator.
  * @param  enable_flag: It can be ENABLE or DISABLE.
  * @note   None.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_wkcp_comparator_enable_ctrl(uint8_t enable_flag);

/**
  * @brief  Get wkcp analog comparator value.
  * @param	cmp_value: Comparator value, it can be SET or RESET.
  * @note   None.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_wkcp_comparator_value_get(uint8_t *cmp_value);


/**
  * @}
  */


#ifdef __cplusplus
}
#endif

#endif /* cbm858x_afe_wkcp.h */


/**
  * @}
  */

/**
  * @}
  */

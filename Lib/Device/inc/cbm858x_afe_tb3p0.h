/**
* @file        cbm858x_afe_tb3p0.h
* @brief       This file contains all the functions prototypes for the TB3P0 firmware library. 
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


#ifndef __CBM858x_AFE_TB3P0_H__
#define __CBM858x_AFE_TB3P0_H__


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

/** @addtogroup AFE_TB3P0
  * @{
  */

/***************************************************************************************************
 * @definitions
***************************************************************************************************/
/** @defgroup AFE_TB3P0_Types AFE_TB3P0 Types
  * @{
  */

//Fill the content
/**
  * @}
  */


/** @defgroup AFE_TB3P0_Constants AFE_TB3P0 Constants
  * @{
  */

/* TP3P0 comparator threshold definition(RSNS=0). */
#define TB3P0_THRESHOLD_5P55MV         (uint16_t)0x0000     /*!< WKCP comparator threshold 5.55mv. */
#define TB3P0_THRESHOLD_8P33MV         (uint16_t)0x0001     /*!< WKCP comparator threshold 8.33mv. */
#define TB3P0_THRESHOLD_11P05MV        (uint16_t)0x0002     /*!< WKCP comparator threshold 11.05mv. */
#define TB3P0_THRESHOLD_13P8MV         (uint16_t)0x0003     /*!< WKCP comparator threshold 13.8mv. */
#define TB3P0_THRESHOLD_16P53MV        (uint16_t)0x0004     /*!< WKCP comparator threshold 16.53mv. */
#define TB3P0_THRESHOLD_19P3MV         (uint16_t)0x0005     /*!< WKCP comparator threshold 19.3mv. */
#define TB3P0_THRESHOLD_22P05MV        (uint16_t)0x0006     /*!< WKCP comparator threshold 22.05mv. */
#define TB3P0_THRESHOLD_25MV           (uint16_t)0x0007     /*!< WKCP comparator threshold 25mv. */

/* TP3P0 comparator threshold definition(RSNS=1). */
#define TB3P0_THRESHOLD_11P1MV         (uint16_t)0x0000     /*!< WKCP comparator threshold 11.1mv. */
#define TB3P0_THRESHOLD_16P66MV        (uint16_t)0x0001     /*!< WKCP comparator threshold 16.66mv. */
#define TB3P0_THRESHOLD_22P2MV         (uint16_t)0x0002     /*!< WKCP comparator threshold 22.2mv. */
#define TB3P0_THRESHOLD_27P77MV        (uint16_t)0x0003     /*!< WKCP comparator threshold 27.7mv. */
#define TB3P0_THRESHOLD_33P33MV        (uint16_t)0x0004     /*!< WKCP comparator threshold 33.33mv. */
#define TB3P0_THRESHOLD_38P88MV        (uint16_t)0x0005     /*!< WKCP comparator threshold 38.88mv. */
#define TB3P0_THRESHOLD_44P44MV        (uint16_t)0x0006     /*!< WKCP comparator threshold 44.44mv. */
#define TB3P0_THRESHOLD_50MV           (uint16_t)0x0007     /*!< WKCP comparator threshold 50mv. */

/* WKCP comparator filtering time definition. */
#define TB3P0_FILTERING_TIME_0US       (uint16_t)0x0000     /*!< WKCP comparator filtering time 0us. */
#define TB3P0_FILTERING_TIME_61P04US   (uint16_t)0x0010     /*!< WKCP comparator filtering time 61.04us. */
#define TB3P0_FILTERING_TIME_122P07US  (uint16_t)0x0020     /*!< WKCP comparator filtering time 122.07us. */
#define TB3P0_FILTERING_TIME_183P11US  (uint16_t)0x0030     /*!< WKCP comparator filtering time 183.11us. */
#define TB3P0_FILTERING_TIME_244P14US  (uint16_t)0x0040     /*!< WKCP comparator filtering time 244.14us. */
#define TB3P0_FILTERING_TIME_305P18US  (uint16_t)0x0050     /*!< WKCP comparator filtering time 305.18us. */
#define TB3P0_FILTERING_TIME_366P21US  (uint16_t)0x0060     /*!< WKCP comparator filtering time 366.21us. */
#define TB3P0_FILTERING_TIME_427P25US  (uint16_t)0x0070     /*!< WKCP comparator filtering time 427.25us. */
#define TB3P0_FILTERING_TIME_488P28US  (uint16_t)0x0080     /*!< WKCP comparator filtering time 488.28us. */
#define TB3P0_FILTERING_TIME_549P32US  (uint16_t)0x0090     /*!< WKCP comparator filtering time 549.32us. */
#define TB3P0_FILTERING_TIME_610P35US  (uint16_t)0x00a0     /*!< WKCP comparator filtering time 610.35us. */
#define TB3P0_FILTERING_TIME_671P39US  (uint16_t)0x00b0     /*!< WKCP comparator filtering time 671.39us. */
#define TB3P0_FILTERING_TIME_732P42US  (uint16_t)0x00c0     /*!< WKCP comparator filtering time 732.42us. */
#define TB3P0_FILTERING_TIME_794P46US  (uint16_t)0x00d0     /*!< WKCP comparator filtering time 793.46us. */
#define TB3P0_FILTERING_TIME_854P49US  (uint16_t)0x00e0     /*!< WKCP comparator filtering time 854.49us. */
#define TB3P0_FILTERING_TIME_915P53US  (uint16_t)0x00f0     /*!< WKCP comparator filtering time 915.53us. */
/**
  * @}
  */


/***************************************************************************************************
 * @functions
***************************************************************************************************/
/** @defgroup AFE_TB3P0_Functions AFE_TB3P0 Functions
  * @{
  */

/**
  * @brief  Enable or disable wkcp analog comparator.
  * @param voltage: voltage comparison value.
  *               It can be one of the following values when RSNS=0:
  *				   @arg TB3P0_THRESHOLD_5P55MV(Default config). 
  *				   @arg TB3P0_THRESHOLD_8P33MV.
  *				   @arg TB3P0_THRESHOLD_11P05MV.
  *				   @arg TB3P0_THRESHOLD_13P8MV.
  *                @arg TB3P0_THRESHOLD_16P53MV.
  *				   @arg TB3P0_THRESHOLD_19P3MV.
  *				   @arg TB3P0_THRESHOLD_22P05MV.
  *				   @arg TB3P0_THRESHOLD_25MV.
  *               It can be one of the following values when RSNS=1:
  *				   @arg TB3P0_THRESHOLD_11P1MV(Default config). 
  *				   @arg TB3P0_THRESHOLD_16P66MV.
  *				   @arg TB3P0_THRESHOLD_22P2MV.
  *				   @arg TB3P0_THRESHOLD_27P77MV.
  *                @arg TB3P0_THRESHOLD_33P33MV.
  *				   @arg TB3P0_THRESHOLD_38P88MV.
  *				   @arg TB3P0_THRESHOLD_44P44MV.
  *				   @arg TB3P0_THRESHOLD_50MV.
  * @param filtering_period: comparator filtering period.
  *               It can be one of the following values:
  *				   @arg TB3P0_FILTERING_TIME_0US(Default config). 
  *				   @arg TB3P0_FILTERING_TIME_61P04US.
  *				   @arg TB3P0_FILTERING_TIME_122P07US.
  *				   @arg TB3P0_FILTERING_TIME_183P11US.
  *                @arg TB3P0_FILTERING_TIME_244P14US.
  *				   @arg TB3P0_FILTERING_TIME_305P18US.
  *				   @arg TB3P0_FILTERING_TIME_366P21US. 
  *                @arg TB3P0_FILTERING_TIME_427P25US.
  *				   @arg TB3P0_FILTERING_TIME_488P28US.
  *				   @arg TB3P0_FILTERING_TIME_549P32US.
  *                @arg TB3P0_FILTERING_TIME_610P35US.
  *				   @arg TB3P0_FILTERING_TIME_671P39US.
  *				   @arg TB3P0_FILTERING_TIME_732P42US. 
  *                @arg TB3P0_FILTERING_TIME_794P46US.
  *				   @arg TB3P0_FILTERING_TIME_854P49US.
  *				   @arg TB3P0_FILTERING_TIME_915P53US.
  * @note   None.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */

uint8_t afe_tb3p0_comparator_config(uint16_t voltage, uint16_t filtering_period);

/**
  * @brief	Enable or disable tb3p0 analog comparator.
  * @param	enable_flag: It can be ENABLE or DISABLE.
  * @note	None.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_tb3p0_comparator_enable_ctrl(uint8_t enable_flag);

/**
  * @brief	Enable or disable tb3p0 module.
  * @param	enable_flag: It can be ENABLE or DISABLE.
  * @note	None.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_tb3p0_enable_ctrl(uint8_t enable_flag);

/**
  * @brief	Get tb3p0 analog comparator value.
  * @param  cmp_value: Comparator value, it can be SET or RESET.
  * @note	None.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_tb3p0_comparator_value_get(uint8_t *cmp_value);

/**
  * @}
  */


#ifdef __cplusplus
}
#endif

#endif /* cbm858x_afe_tb3p0.h */


/**
  * @}
  */

/**
  * @}
  */

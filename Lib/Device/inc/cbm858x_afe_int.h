/**
* @file        cbm858x_afe_int.h
* @brief       This file contains all the functions prototypes for the INT firmware library. 
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


#ifndef __CBM858x_AFE_INT_H__
#define __CBM858x_AFE_INT_H__


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

/** @addtogroup AFE_INT
  * @{
  */

/***************************************************************************************************
 * @definitions
***************************************************************************************************/
/** @defgroup AFE_INT_Types AFE_INT Types
  * @{
  */

//Fill the content
/**
  * @}
  */


/** @defgroup AFE_INT_Constants AFE_INT Constants
  * @{
  */
/* INT mode definition. */
#define INT_IMD_PULSE_INTMODE         			 (uint16_t)0x0000     /*!< Pulse int mode. */
#define INT_IMD_LEVEL_INTMODE         			 (uint16_t)0x0001     /*!< Level int mode. */

/* IE0 int enable definition. */
#define INT_IE0_VADC_TB3P0_INT         			 (uint16_t)0x8000     /*!< VADC TB3P0 int. */
#define INT_IE0_TIMERA_INT         			     (uint16_t)0x4000     /*!< TIMERA int. */
#define INT_IE0_DISP_INT         			     (uint16_t)0x1000     /*!< DISP int. */
#define INT_IE0_EM_SHUTDOWN_INT         		 (uint16_t)0x0800     /*!< EM shutdown int. */
#define INT_IE0_FUSE_INT         			     (uint16_t)0x0400     /*!< PUSE int. */
#define INT_IE0_AOLD_INT         			     (uint16_t)0x0200     /*!< AOLD int. */
#define INT_IE0_ASCC_INT         			     (uint16_t)0x0100     /*!< ASCC int. */
#define INT_IE0_ASCD1_INT         			     (uint16_t)0x0080     /*!< ASCD1 int. */
#define INT_IE0_ASCD2_INT         			     (uint16_t)0x0040     /*!< ASCD2 int. */
#define INT_IE0_CC_INT         			     	 (uint16_t)0x0020     /*!< CC int. */
#define INT_IE0_VADC_INT         			     (uint16_t)0x0010     /*!< VADC int. */
#define INT_IE0_TB3P0_INT         			     (uint16_t)0x0008     /*!< TB3P0 int. */
#define INT_IE0_WKCP_INT         			     (uint16_t)0x0004     /*!< WKCP int. */
#define INT_IE0_CC_TB3P0_INT         			 (uint16_t)0x0002     /*!< CC_TB3P0 int. */

/* IE1 int enable definition. */
#define INT_IE1_PACKH2P25V_INT         			 (uint16_t)0x0001     /*!< PACKH2P25V int. */

/* ISRC0 int status definition .*/
#define INT_ISRC0_VADC_TB3P0_INT_FLAG    		 (uint16_t)0x8000     /*!< VADC TB3P0 int flag. */
#define INT_ISRC0_TIMERA_INT_FLAG   			 (uint16_t)0x4000     /*!< TIMERA int flag. */
#define INT_ISRC0_DISP_INT_FLAG    			     (uint16_t)0x1000     /*!< DISP int flag. */
#define INT_ISRC0_EM_SHUTDOWN_INT_FLAG     		 (uint16_t)0x0800     /*!< EM shutdown int flag. */
#define INT_ISRC0_FUSE_INT_FLAG     			 (uint16_t)0x0400     /*!< PUSE int flag. */
#define INT_ISRC0_AOLD_INT_FLAG      			 (uint16_t)0x0200     /*!< AOLD int flag. */
#define INT_ISRC0_ASCC_INT_FLAG      			 (uint16_t)0x0100     /*!< ASCC int flag. */
#define INT_ISRC0_ASCD1_INT_FLAG     			 (uint16_t)0x0080     /*!< ASCD1 int flag. */
#define INT_ISRC0_ASCD2_INT_FLAG    			 (uint16_t)0x0040     /*!< ASCD2 int flag. */
#define INT_ISRC0_CC_INT_FLAG   			     (uint16_t)0x0020     /*!< CC int flag. */
#define INT_ISRC0_VADC_INT_FLAG   			     (uint16_t)0x0010     /*!< VADC int flag. */
#define INT_ISRC0_TB3P0_INT_FLAG     			 (uint16_t)0x0008     /*!< TB3P0 int flag. */
#define INT_ISRC0_WKCP_INT_FLAG    			     (uint16_t)0x0004     /*!< WKCP int flag. */
#define INT_ISRC0_CC_TB3P0_INT_FLAG    			 (uint16_t)0x0002     /*!< CC_TB3P0 int flag. */

/* ISRC1 int status definition */
#define INT_ISRC1_PACKH2P25V_INT_FLAG         	 (uint16_t)0x0001     /*!< PACKH2P25V int flag. */
#define INT_ISRC1_PB0_INT_FLAG         	         (uint16_t)0x0004     /*!< PB0 int flag. */
#define INT_ISRC1_PB1_INT_FLAG         	         (uint16_t)0x0008     /*!< PB1 int flag. */

/* ICTR2 int enable definition */
#define INT_ICTR2_FUSE_DDS_MODE              	 (uint16_t)0x0004     /*!< FUSE DDS enable. */
#define INT_ICTR2_DISP_DDS_MODE   			     (uint16_t)0x0002     /*!< DISP DDS enable. */
#define INT_ICTR2_EMSHUTDOWN_DDS_MODE   	     (uint16_t)0x0001     /*!< EM shutdown DDS enable. */

/* ICTR int remove jitter definition */
#define INT_ICTR_FUSE_DDS_480US                  (uint16_t)0x0030     /*!< FUSE DDS 480us. */
#define INT_ICTR_FUSE_DDS_240US   	 			 (uint16_t)0x0020     /*!< FUSE DDS 240us. */
#define INT_ICTR_FUSE_DDS_120US   	 			 (uint16_t)0x0010     /*!< FUSE DDS 120us. */
#define INT_ICTR_FUSE_DDS_60US   	 			 (uint16_t)0x0000     /*!< FUSE DDS 60us. */
#define INT_ICTR_DISP_DDS_100MS                  (uint16_t)0x000C     /*!< DISP DDS 100ms. */
#define INT_ICTR_DISP_DDS_70MS   	 			 (uint16_t)0x0008     /*!< DISP DDS 70ms. */
#define INT_ICTR_DISP_DDS_40MS   	 			 (uint16_t)0x0004     /*!< DISP DDS 40ms. */
#define INT_ICTR_DISP_DDS_10MS   	 			 (uint16_t)0x0000     /*!< DISP DDS 10ms. */
#define INT_ICTR_EMSHUTDOWN_1P25S                (uint16_t)0x0003     /*!< EM shutdown 1.25s. */
#define INT_ICTR_EMSHUTDOWN_1S   	 	         (uint16_t)0x0002     /*!< EM shutdown 1s. */
#define INT_ICTR_EMSHUTDOWN_0P5S   	     	     (uint16_t)0x0001     /*!< EM shutdown 0.5s. */
#define INT_ICTR_EMSHUTDOWN_0P25S   	 	     (uint16_t)0x0000     /*!< EM shutdown 0.25s. */

/* PB int enable definition. */
#define INT_PB0_PIN                              (uint8_t)0x00        /*!< PB0 pin. */
#define INT_PB1_PIN                              (uint8_t)0x01        /*!< PB1 pin. */
#define PB_INT_EDGE_TRIGGER                      (uint8_t)0x00        /*!< PB edge trigger. */
#define PB_INT_LEVEL_TRIGGER                     (uint8_t)0x01        /*!< PB level trigger. */
#define PB_INT_HIGH_LEVEL_RISE                   (uint8_t)0x00        /*!< PB high level or rising int. */
#define PB_INT_LOW_LEVEL_FALL                    (uint8_t)0x01        /*!< PB low level or falling int. */

/* PB int flag definition. */
#define INT_FUSE_IO_INDICATOR_FLAG               (uint16_t)0x0004     /*!< FUSE indicator flag. */
#define INT_DISP_IO_INDICATOR_FLAG               (uint16_t)0x0002     /*!< DISP indicator flag. */     

/**
  * @}
  */


/***************************************************************************************************
 * @functions
***************************************************************************************************/
/** @defgroup AFE_INT_Functions AFE_INT Functions
  * @{
  */

/**
  * @brief  Config the int mode.
  * @param	value: Specifies the int mode.
  *               it can be one of the following values:
  *				   @arg INT_IMD_PULSE_INTMODE: pulse mode(Default config).  
  *				   @arg INT_IMD_LEVEL_INTMODE:level mode.
  * @note   None.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_int_mode_config(uint16_t value);

/**
  * @brief  Enable or disable periph int.
  * @param	intsrc: Specifies the int module.
  *               it can be one of the following values:
  *				   @arg INT_IE0_VADC_TB3P0_INT: VADC TB3P0 int.
  *				   @arg INT_IE0_TIMERA_INT: TIMERA int.
  *				   @arg INT_IE0_DISP_INT: DISP int.  
  *				   @arg INT_IE0_EM_SHUTDOWN_INT: EM shutdown int.
  *				   @arg INT_IE0_FUSE_INT: FUSE int. 
  *				   @arg INT_IE0_AOLD_INT: AOLD int.
  *				   @arg INT_IE0_ASCC_INT: ASCC int. 
  *				   @arg INT_IE0_ASCD1_INT: ASCD1 int.
  *				   @arg INT_IE0_ASCD2_INT: ASCD2 int. 
  *				   @arg INT_IE0_CC_INT: CC int.
  *				   @arg INT_IE0_VADC_INT: VADC int. 
  *				   @arg INT_IE0_TB3P0_INT: TB3P0 int.
  *				   @arg INT_IE0_WKCP_INT: WKCP int. 
  *				   @arg INT_IE0_CC_TB3P0_INT: CC TB3P0 int. 
  *				   @arg INT_IE1_PACKH2P25V_INT: PACKH2P25V int.
  * @note   None.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_int_periph_int_enable_ctrl(uint16_t intsrc, uint8_t enable_flag);

/**
  * @brief  Get the int status.
  * @param	intsrc: Specifies the int module.
  *               it can be one of the following values:
  *				   @arg INT_ISRC0_VADC_TB3P0_INT_FLAG: VADC TB3P0 int flag.  
  *				   @arg INT_ISRC0_TIMERA_INT_FLAG: TIMERA int flag.
  *				   @arg INT_ISRC0_DISP_INT_FLAG: DISP int flag.  
  *				   @arg INT_ISRC0_EM_SHUTDOWN_INT_FLAG: EM shutdown int flag.
  *				   @arg INT_ISRC0_FUSE_INT_FLAG: PUSE int flag.  
  *				   @arg INT_ISRC0_AOLD_INT_FLAG: AOLD int flag.
  *				   @arg INT_ISRC0_ASCC_INT_FLAG: ASCC int flag.  
  *				   @arg INT_ISRC0_ASCD1_INT_FLAG: ASCD1 int flag.
  *				   @arg INT_ISRC0_ASCD2_INT_FLAG: ASCD2 int flag. 
  *				   @arg INT_ISRC0_CC_INT_FLAG: CC int flag.
  *				   @arg INT_ISRC0_VADC_INT_FLAG: VADC int flag. 
  *				   @arg INT_ISRC0_TB3P0_INT_FLAG: TB3P0 int flag.
  *				   @arg INT_ISRC0_WKCP_INT_FLAG: WKCP int flag. 
  *				   @arg INT_ISRC0_CC_TB3P0_INT_FLAG: CC TB3P0 int flag.
  *				   @arg INT_ISRC1_PACKH2P25V_INT_FLAG: PACKH2P25V int flag.
  * @param	status: Specifies the int status.
  * @note   None.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_int_periph_int_flag_get(uint16_t intflag, uint8_t *status);

/**
  * @brief  Clear the int status.
  * @param	intflag: Specifies the int module.
  *               it can be one of the following values:
  *				   @arg INT_ISRC0_VADC_TB3P0_INT_FLAG: VADC TB3P0 int flag.  
  *				   @arg INT_ISRC0_TIMERA_INT_FLAG: TIMERA int flag.
  *				   @arg INT_ISRC0_DISP_INT_FLAG: DISP int flag. 
  *				   @arg INT_ISRC0_EM_SHUTDOWN_INT_FLAG: EM shutdown int flag.
  *				   @arg INT_ISRC0_FUSE_INT_FLAG: PUSE int flag.  
  *				   @arg INT_ISRC0_AOLD_INT_FLAG: AOLD int flag.
  *				   @arg INT_ISRC0_ASCC_INT_FLAG: ASCC int flag.  
  *				   @arg INT_ISRC0_ASCD1_INT_FLAG: ASCD1 int flag.
  *				   @arg INT_ISRC0_ASCD2_INT_FLAG: ASCD2 int flag.  
  *				   @arg INT_ISRC0_CC_INT_FLAG: CC int flag.
  *				   @arg INT_ISRC0_VADC_INT_FLAG: VADC int flag.  
  *				   @arg INT_ISRC0_TB3P0_INT_FLAG: TB3P0 int flag.
  *				   @arg INT_ISRC0_WKCP_INT_FLAG: WKCP int flag.  
  *				   @arg INT_ISRC0_CC_TB3P0_INT_FLAG: CC TB3P0 int flag.
  *				   @arg INT_ISRC1_PACKH2P25V_INT_FLAG: PACKH2P25V int flag.
  * @note   None.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_int_periph_int_flag_clear(uint16_t intflag);

/**
  * @brief  Enable or disable the remove jitter.
  * @param	jitter_mode: Specifies the remove jitter type.
  *               it can be one of the following values:
  *				   @arg INT_ICTR2_FUSE_DDS_MODE: FUSE DDS MODE.  
  *				   @arg INT_ICTR2_DISP_DDS_MODE: DISP DDS MODE.
  *				   @arg INT_ICTR2_EMSHUTDOWN_DDS_MODE: EM shutdown DDS MODE.
  * @param	enable_flag: It can be ENABLE or DISABLE.
  * @note   None.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_remove_jitter_enable_ctrl(uint16_t jitter_mode, uint8_t enable_flag);

/**
  * @brief  Config the fuse remove jitter delay time.
  * @param	delay_time: fuse remove jitter delay time.
  *               It can be one of the following values:
  *                @arg INT_ICTR_FUSE_DDS_480US.
  *                @arg INT_ICTR_FUSE_DDS_240US.
  *                @arg INT_ICTR_FUSE_DDS_120US(Default config).
  *                @arg INT_ICTR_FUSE_DDS_60US.
  * @note   None.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_fuse_remove_jitter_delay_config(uint16_t delay_time);

/**
  * @brief  Config the disp remove jitter delay time.
  * @param	delay_time: disp remove jitter delay time.
  *               It can be one of the following values:
  *                @arg INT_ICTR_DISP_DDS_100MS.
  *                @arg INT_ICTR_DISP_DDS_70MS.
  *                @arg INT_ICTR_DISP_DDS_40MS(Default config).
  *                @arg INT_ICTR_DISP_DDS_10MS.
  * @note   None.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_disp_remove_jitter_delay_config(uint16_t delay_time);

/**
  * @brief  Config the em shutdown remove jitter delay time.
  * @param	delay_time: emshutdown remove jitter delay time.
  *               It can be one of the following values:
  *                @arg INT_ICTR_EMSHUTDOWN_1P25S.
  *                @arg INT_ICTR_EMSHUTDOWN_1S(Default config).
  *                @arg INT_ICTR_EMSHUTDOWN_0P5S.
  *                @arg INT_ICTR_EMSHUTDOWN_0P25S.
  * @note   None.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_emshutdown_remove_jitter_delay_config(uint16_t delay_time);

/**
  * @brief  Config the pb int mode.
  * @param	pb_pin: Specifies the pb pin.
  *               It can be one of the following values:
  *				   @arg INT_PB0_PIN: PB0. 
  *				   @arg INT_PB1_PIN: PB1.
  * @param	int_mode: Specifies the pb int mode.
  *               It can be one of the following values:
  *				   @arg PB_INT_EDGE_TRIGGER: edge trigger(Default config).  
  *				   @arg PB_INT_LEVEL_TRIGGER: level trigger.
  * @note   None.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_pb_int_mode_ctrl(uint8_t pb_pin, uint8_t int_mode);

/**
  * @brief  Config the pb0 int enable.
  * @param	enable_mode: Specifies the pb0 int enable mode.
  *               It can be one of the following values:
  *				   @arg PB_INT_HIGH_LEVEL_RISE: high level or rising edge trigger. 
  *				   @arg PB_INT_LOW_LEVEL_FALL: low level or falling edge trigger.
  * @param	enable_flag: It can be ENABLE or DISABLE.
  * @note   None.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_pb0_int_enable_ctrl(uint8_t enable_mode, uint8_t enable_flag);

/**
  * @brief  Config the pb1 int enable.
  * @param	enable_mode: Specifies the pb1 int enable mode.
  *               It can be one of the following values:
  *				   @arg PB_INT_HIGH_LEVEL_RISE: high level or rising edge trigger.
  *				   @arg PB_INT_LOW_LEVEL_FALL: low level or falling edge trigger.
  * @param	enable_flag: It can be ENABLE or DISABLE.
  * @note   None.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_pb1_int_enable_ctrl(uint8_t enable_mode, uint8_t enable_flag);

/**
  * @brief  Get the pb int status.
  * @param	intflag: Specifies the pb int flag.
  *               It can be one of the following values:
  *				   @arg INT_ISRC1_PB0_INT_FLAG: PB0 int flag. 
  *				   @arg INT_ISRC1_PB1_INT_FLAG: PB1 int flag.
  * @param  status: Specifies the voltage status.
  * @note   None.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_int_pb_int_flag_get(uint16_t intflag, uint8_t *status);

/**
  * @brief  Clear the pb int status.
  * @param	intflag: Specifies the pb int flag.
  *               It can be one of the following values:
  *				   @arg INT_ISRC1_PB0_INT_FLAG: PB0 int flag. 
  *				   @arg INT_ISRC1_PB1_INT_FLAG:PB1 int flag.
  * @note   None.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_int_pb_int_flag_clear(uint16_t intflag);

/**
  * @brief  Get the indicator status.
  * @param	indicator_flag: Specifies the indicator flag.
  *               It can be one of the following values:
  *				   @arg INT_FUSE_IO_INDICATOR_FLAG: FUSE indicator flag. 
  *				   @arg INT_DISP_IO_INDICATOR_FLAG: DISP indicator flag.
  * @param	status: Specifies the voltage status.
  * @note   None.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_indicator_flag_get(uint16_t indicator_flag, uint8_t *status);


/**
  * @}
  */


#ifdef __cplusplus
}
#endif

#endif /* cbm858x_afe_int.h */


/**
  * @}
  */

/**
  * @}
  */

/**
* @file        cbm858x_afe_rcc.h
* @brief       This file contains all the functions prototypes for the RCC firmware library. 
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


#ifndef __CBM858x_AFE_RCC_H__
#define __CBM858x_AFE_RCC_H__


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

/** @addtogroup AFE_RCC
  * @{
  */

/***************************************************************************************************
 * @definitions
***************************************************************************************************/
/** @defgroup AFE_RCC_Types AFE_RCC Types
  * @{
  */

//Fill the content
/**
  * @}
  */


/** @defgroup AFE_RCC_Constants AFE_RCC Constants
  * @{
  */
/* CLKCON reg peripherals clock bit. */
#define RCC_PERI_IWDT_CLOCK        	 ((uint16_t)0x0400)       /*!< RCC peripheral IWDT clock enable */
#define RCC_PERI_CDDRV_CLOCK     	 ((uint16_t)0x0200)       /*!< RCC peripheral CDDRV clock enable */
#define RCC_PERI_TB3P0F_CLOCK     	 ((uint16_t)0x0100)       /*!< RCC peripheral TB3P0 clock enable */
#define RCC_PERI_WKCPF_CLOCK      	 ((uint16_t)0x0080)       /*!< RCC peripheral WKCP clock enable */
#define RCC_PERI_HDPF_CLOCK        	 ((uint16_t)0x0040)       /*!< RCC peripheral HDP clock enable */
#define RCC_PERI_LEDDRVF_CLOCK     	 ((uint16_t)0x0020)       /*!< RCC peripheral LEDDRV clock enable */
#define RCC_PERI_TIMERAF_CLOCK   	 ((uint16_t)0x0010)       /*!< RCC peripheral TIMERA clock enable */                

/* IPRSTC1 reg peripherals reset bit. */
#define RCC_IPRSTC1_LEDDRV      	 ((uint16_t)0x0020)       /*!< LEDDRV RESET */
#define RCC_IPRSTC1_TIMERA      	 ((uint16_t)0x0010)       /*!< TIMERA RESET */
#define RCC_IPRSTC1_ADC         	 ((uint16_t)0x0004)       /*!< ADC RESET */

/* RSTSRC reg reset bit. */
#define RCC_FLAG_PIN_RSTS    	 	 ((uint16_t)0x0008)       /*!< RCC pin reset flag */ 
#define RCC_FLAG_IWDG_RSTS    	 	 ((uint16_t)0x0004)       /*!< RCC iwdg reset flag */ 
#define RCC_FLAG_COMMD_RSTS   	 	 ((uint16_t)0x0002)    	  /*!< RCC command reset flag */ 
#define RCC_FLAG_POR_RSTS    	 	 ((uint16_t)0x0001)    	  /*!< RCC power on reset flag */

/* RCC clock output selection definition. */
#define RCC_CLKOUT_SEL_NO_CLK        ((uint16_t)0x0000)       /*!< RCC CLKOUT select no clock source */
#define RCC_CLKOUT_SEL_VADC          ((uint16_t)0x0001)       /*!< RCC CLKOUT select VADC as clock source */
#define RCC_CLKOUT_SEL_CCADC         ((uint16_t)0x0003)       /*!< RCC CLKOUT select SYSCLK as clock source */
#define RCC_CLKOUT_SEL_LFO           ((uint16_t)0x0005)       /*!< RCC CLKOUT select LFO CLK clock source */

/* RCC clock output prescaler definition. */
#define RCC_CLKOUT_PDIV_1            ((uint16_t)0x0000)       /*!< RCC CLKOUT is divided by 1 */
#define RCC_CLKOUT_PDIV_2            ((uint16_t)0x0008)       /*!< RCC CLKOUT is divided by 2 */
#define RCC_CLKOUT_PDIV_4            ((uint16_t)0x0010)       /*!< RCC CLKOUT is divided by 4 */
#define RCC_CLKOUT_PDIV_8            ((uint16_t)0x0018)       /*!< RCC CLKOUT is divided by 8 */

/* RCC CLKOUT mask definition. */
#define  RCC_CLKCON_MCOPRE           ((uint16_t)0x0018)       /*!< Microcontroller clock output prescaler bit */
#define  RCC_CLKCON_MCO_S            ((uint16_t)0x0007)       /*!< Microcontroller clock output bit */

/**
  * @}
  */


/***************************************************************************************************
 * @functions
***************************************************************************************************/
/** @defgroup AFE_RCC_Functions AFE_RCC Functions
  * @{
  */

/**@brief  Enables or disables the peripheral clock. 
 * @param  value: Specifies the APB peripheral clock.
 *					 It can be one of the following values:
 *					  RCC_PERI_IWDT_CLOCK: IWDT clock enable.
 *					  RCC_PERI_CDDRV_CLOCK: CDDRV clock enable.
 *					  RCC_PERI_TB3P0F_CLOCK: TB3P0 clock enable.
 *					  RCC_PERI_WKCPF_CLOCK: WKCP clock enable.
 *					  RCC_PERI_HDPF_CLOCK: HDP clock enable.
 *					  RCC_PERI_LEDDRVF_CLOCK: LEDDRV clock enable.
 *					  RCC_PERI_TIMERAF_CLOCK: TIMERA clock enable.
 * @param  enable_flag: It can be ENABLE or DISABLE.
 * @note None.
 * @return Function execution result, 0:ERROR, 1:SUCCESS.
 */
uint8_t afe_rcc_periph_clock_enable_ctrl(uint16_t value, uint8_t enable_flag);

/**@brief  Reset or restore peripherals.   
 * @param  value: Specifies the peripheral to reset.
 *                   It can be one of the following values:
 *          	      RCC_IPRSTC1_LEDDRV: LEDDRV reset.
 *          	      RCC_IPRSTC1_TIMERA: TIMERA reset.
 *          	      RCC_IPRSTC1_ADC: ADC reset.
 * @param  enable_flag: It can be ENABLE or DISABLE.
 * @return Function execution result, 0:ERROR, 1:SUCCESS.
 */
uint8_t afe_rcc_periph_reset_enable_ctrl(uint16_t value, uint8_t enable_flag);

/**@brief  Checks whether the specified RCC reset flag is set or not.
 * @param  flag: Specifies the flag to check, it can be one of the following values:
 *                   RCC_FLAG_PIN_RSTS: PIN reset. 
 *                   RCC_FLAG_IWDG_RSTS: nRST Pin reset.
 *                   RCC_FLAG_POR_RSTS: POR reset.
 *                   RCC_FLAG_COMMD_RSTS: WWDG reset.
 * @param status: Specifies the rcc reset status.
 * @return Function execution result, 0:ERROR, 1:SUCCESS.
 */
uint8_t afe_rcc_reset_flag_get(uint16_t flag, uint8_t *status);

/**@brief  Clear the specified RCC reset flag.
 * @param  flag: Specifies the reset flag to clear.
 *                 it can be one of the following values(Support combination of below value):
 *                   RCC_FLAG_PIN_RSTS: PIN reset. 
 *                   RCC_FLAG_IWDG_RSTS: nRST Pin reset.
 *                   RCC_FLAG_POR_RSTS: POR reset.
 *                   RCC_FLAG_COMMD_RSTS: WWDG reset.
 * @return Function execution result, 0:ERROR, 1:SUCCESS.
 */
uint8_t afe_rcc_reset_flag_clear(uint16_t flag);

/** @brief  Selects the clock source to output on CLKOUT pin (PA0). 
 * @param  sel_value: Specifies the clock source to intput.
 *                       It can be one of the following values:
 *          	          RCC_CLKOUT_SEL_NO_CLK: No clock selected.
 *          	          RCC_CLKOUT_SEL_VADC: VADC oscillator clock selected.
 *          	          RCC_CLKOUT_SEL_CCADC: CCADC clock selected.
 *          	          RCC_CLKOUT_SEL_LFO: LFO clock selected.
 * @param  prescaler: Specifies the prescaler on CLKOUT pin. 
 *                       It can be one of the following values:
 *          	          RCC_CLKOUT_PDIV_1: CLKOUT clock is divided by 1(Default config).
 *          	          RCC_CLKOUT_PDIV_2: CLKOUT clock is divided by 2.
 *         	              RCC_CLKOUT_PDIV_4: CLKOUT clock is divided by 4.
 *          	          RCC_CLKOUT_PDIV_8: CLKOUT clock is divided by 8. 
 * @return Function execution result, 0:ERROR, 1:SUCCESS.
 */
uint8_t afe_rcc_clkout_config(uint16_t sel_value, uint16_t prescaler);



/**
  * @}
  */


#ifdef __cplusplus
}
#endif

#endif /* cbm858x_afe_rcc.h */


/**
  * @}
  */

/**
  * @}
  */

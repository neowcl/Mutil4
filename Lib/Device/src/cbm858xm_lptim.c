/**
* @file        cbm858xm_lptim.c
* @brief       This file provides all the basic LPTIM firmware functions.
* @author      ChipSea MCU Group
* @version     1.0.0
* @date        2022.04.26
* @copyright   CHIPSEA TECHNOLOGIES (SHENZHEN) CORP.
* @note        
****************************************************************************************************
* @par Modify record:
* <tr><th>Date          <th>Version    <th>Author     <th>Description
* <tr><td>2022.04.26    <td>1.0.0      <td>ChipSea    <td>
* -# 
* </table>
*
****************************************************************************************************
*/


/***************************************************************************************************
 * @includes
***************************************************************************************************/
#include "cbm858xm_lptim.h"


/***************************************************************************************************
 * @definitions
***************************************************************************************************/


/** @addtogroup CBM858xM_StdPeriph_Driver
  * @{
  */

/** @defgroup LPTIM
  * @brief    LPTIM driver modules
  * @{
  */
///@cond
/***************************************************************************************************
 * @variables
***************************************************************************************************/


/***************************************************************************************************
 * @function
***************************************************************************************************/
/**
 * @brief       Initializes the LPTIM config parameters according to the specified parameters in the lptim_config.
 *              lptim_init() can only be called when the LPTIM is disabled.
 * @param       ptr_config: pointer to a lptim_config_t structure that contains the configuration information for the
 *              specified LPTIM peripheral.
 * @return      None.
 */
void lptim_init(lptim_config_t* ptr_config)
{
    /* Check the parameters */
    ASSERT(LPTIM_CLOCK_PRESCALER_CHECK(ptr_config->prescaler));
    ASSERT(LPTIM_WAVEFORM_CHECK(ptr_config->waveform));
    ASSERT(LPTIM_OUTPUT_POLARITY_CHECK(ptr_config->polarity));
    
    /* Set CKSEL bitfield according to clock_source value */
    /* Set PRESC bitfield according to prescaler value */
    /* Set WAVE bitfield according to waveform value */
    /* Set WAVEPOL bitfield according to polarity value */
    MODIFY_REG(LPTIM->CFGR, 
            (LPTIM_CFGR_PRESC | LPTIM_CFGR_WAVE| LPTIM_CFGR_WAVPOL), 
             ptr_config->prescaler    | \
             ptr_config->waveform     | \
             ptr_config->polarity);
}

/**
 * @brief       Set the startup mode of the LPTIM counter. LPTIM must be enabled before starting the counter.
 * @param       start_mode:the startup mode of the LPTIM counter, It can be LPTIM_START_MODE_CONTINUOUS or
 *              LPTIM_START_MODE_SINGLEPULSE. 
 * @return      None.
 */
void lptim_start_mode_set(uint32_t start_mode)
{
    ASSERT(LPTIM_START_MODE_CHECK(start_mode)); 
    
    MODIFY_REG(LPTIM->CR, LPTIM_CR_CNTSTRT | LPTIM_CR_SNGSTRT, start_mode);
}

/**
 * @brief       Set the update mode of the LPTIM counter. LPTIM must be disabled before calling this function.
 * @param       update_mode:the update mode of the LPTIM counter, It can be LPTIM_UPDATE_MODE_IMMEDIATE or
 *              LPTIM_UPDATE_MODE_ENDOFPERIOD. 
 * @return      None.
 */
void lptim_update_mode_set(uint32_t  update_mode)
{
    ASSERT(LPTIM_UPDATE_MODE_CHECK(update_mode)); 
    
    MODIFY_REG(LPTIM->CFGR, LPTIM_CFGR_PRELOAD, update_mode);
}

/**
 * @brief       Set the update mode of the LPTIM counter. LPTIM must be disabled before calling this function.
 * @param       count_mode:the count mode of the LPTIM counter, It can be LPTIM_COUNT_INTER_CLOCK or
 *              LPTIM_COUNT_EXTER_CLOCK. 
 * @return      None.
 */
void lptim_count_mode_set(uint32_t  count_mode)
{
    ASSERT(LPTIM_COUNT_MODE_CHECK(count_mode)); 
    
    MODIFY_REG(LPTIM->CFGR, LPTIM_CFGR_COUNTMODE, count_mode);
}

/**
 * @brief       Configure the external trigger used as a trigger event for the LPTIM. LPTIM must be disabled before 
 *              calling this function.
 * @param       trigger_source: external trigger source, It can be LPTIM_EXT_TRIGx, where x can be 0 - 7. Used as GPIO 
 *              pin (PA2) of multiplexing function
 * @param       filter:Trigger filter filtering mode, It can be one of the following values: @ref LPTIM_tri_flt.
 * @param       trigger_polarity:Trigger polarity, It can be one of the following values: @ref LPTIM_tri_polarity.
 * @return      None.
 */
void lptim_trigger_config(uint32_t trigger_source, uint32_t filter, uint32_t trigger_polarity)
{
    ASSERT(LPTIM_EXT_TRIG0_CHECK(trigger_source)); 
    ASSERT(LPTIM_TRIG_FILTER_CHECK(filter)); 
    ASSERT(LPTIM_TRIG_POLARITY_CHECK(trigger_polarity)); 

    MODIFY_REG(LPTIM->CFGR, LPTIM_CFGR_TRIGSEL | LPTIM_CFGR_TRGFLT | LPTIM_CFGR_TRIGEN, trigger_source | filter | \
               trigger_polarity);
}

///@endcond
/**
  * @}
  */

/**
  * @}
  */

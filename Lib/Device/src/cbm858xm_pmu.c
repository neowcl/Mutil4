/**
* @file        cbm858xm_pmu.c
* @brief       This file provides all the basic PMU firmware functions.
* @author      ChipSea MCU Group
* @version     1.0.0
* @date        2022.06.07
* @copyright   CHIPSEA TECHNOLOGIES (SHENZHEN) CORP.
* @note        
****************************************************************************************************
* @par Modify record:
* <tr><th>Date          <th>Version    <th>Author     <th>Description
* <tr><td>2022.06.07    <td>1.0.0      <td>ChipSea    <td>
* -# 
* </table>
*
****************************************************************************************************
*/


/***************************************************************************************************
 * @includes
***************************************************************************************************/
#include "cbm858xm_pmu.h"
#include "cbm858xm_rcu.h"


/***************************************************************************************************
 * @definitions
***************************************************************************************************/


/** @addtogroup CBM858xM_StdPeriph_Driver
  * @{
  */

/** @defgroup PMU PMU
  * @brief    PMU driver modules
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
  * @brief  Enters Sleep mode.
  * @param  value: Specifies if sleep mode in entered with WFI or WFE instruction.
  *          This parameter can be one of the following values:
  *            @arg PMU_SLEEP_ENTRY_WFI (enter SLEEP mode with WFI instruction)
  *            @arg PMU_SLEEP_ENTRY_WFE (enter SLEEP mode with WFE instruction)
  * @note   In Sleep mode, all I/O pins keep the same state as in Run mode.
  * @return None.
  */
void pmu_sleep_mode_set(uint8_t value)
{
    ASSERT(PMU_SLEEP_ENTRY_CHECK(value));

    /* Clear sleepdeep bit. */
    SCB->SCR &= (uint32_t)~((uint32_t)SCB_SCR_SLEEPDEEP_Msk);
  
    if(value == PMU_SLEEP_ENTRY_WFI)
    {
        /* Request wait for interrupt. */
        __WFI();
    }
    else
    {
        /* Request wait for event. */
        __SEV();
        __WFE(); 
        __WFE();
    }
}

/**
  * @brief  Enters deep sleep mode.
  * @param  value: Specifies the regulator state in deep sleep mode. It only can be:
  *         PMU_LDO_LOW_POWER.
  * @param  flag: Specifies if sleep mode in entered with WFI or WFE instruction.
  *         It can be one of the following values: 
  *            @arg PMU_DSM_ENTRY_WFI(enter sleep mode mode with WFI instruction)
  *            @arg PMU_DSM_ENTRY_WFE(enter sleep mode mode with WFE instruction)
  *            @arg PMU_DSM_ENTRY_SLEEPONEXIT(enter STOP mode with SLEEPONEXIT instruction)
  * @return None.
  */
void pmu_deep_sleep_mode_enter(uint32_t value, uint8_t flag)
{
    ASSERT(PMU_LDO_CHECK(value));
    ASSERT(PMU_STOP_ENTRY_CHECK(flag));
  
    MODIFY_REG(PMU->CTR, PMU_CTR_LDOLM, value);
    
    /* Set sleepdeep bit of Cortex-M0 system control register. */
    SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;
    
    if(flag == PMU_DSM_ENTRY_WFI)
    {
        /* Request wait for interrupt. */
        __WFI();
        /* Reset sleepdeep bit of Cortex system control register. */
        SCB->SCR &= (uint32_t)~((uint32_t)SCB_SCR_SLEEPDEEP_Msk); 
    }
    else if (flag == PMU_DSM_ENTRY_WFE)
    {
        /* Request wait for event */
        __WFE();
        /* Reset sleepdeep bit of Cortex system control register. */
        SCB->SCR &= (uint32_t)~((uint32_t)SCB_SCR_SLEEPDEEP_Msk);   
    }
    else
    {
        /* Set sleep on exit bit of Cortex-M0 system control register. */
        SCB->SCR |= SCB_SCR_SLEEPONEXIT_Msk;
    }
}

/**
  * @brief  Enters power down mode. The Wakeup flag (WUF) need to be cleared
  *         at application level before to call this function.    
  * @param  None.
  * @return None.
  */
void pmu_power_down_enter(void)
{
    PMU->CTR |= PMU_CTR_DSMODE;

    /* Set sleepdeep bit of Cortex-M0 cystem control register. */
    SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;
    /* Request wait for interrupt. */
    __WFI();
}

/**
  * @brief  Selection lvd filter.
  * @param  value: Specifies the LVD filter time, it can be one of
  *         the following values:
  *            @arg PMU_LVD_FILTER0
  *            @arg PMU_LVD_FILTER1
  *            @arg PMU_LVD_FILTER2
  *            @arg PMU_LVD_FILTER3
  *            @arg PMU_LVD_FILTER4
  *            @arg PMU_LVD_FILTER5
  *            @arg PMU_LVD_FILTER6
  *            @arg PMU_LVD_FILTER7
  * @return None.
  */
void pmu_lvd_filter_config(uint32_t value)
{
    ASSERT(PMU_LVD_FILTER_CHECK(value));
    MODIFY_REG(PMU->CTR, PMU_CTR_LVD_FTR, value);
}

/**
  * @brief  Selection HVD filter.
  * @param  value: Specifies the HVD filter time, it can be one of
  *         the following values:
  *            @arg PMU_HVD_FILTER0
  *            @arg PMU_HVD_FILTER1
  *            @arg PMU_HVD_FILTER2
  *            @arg PMU_HVD_FILTER3
  *            @arg PMU_HVD_FILTER4
  *            @arg PMU_HVD_FILTER5
  *            @arg PMU_HVD_FILTER6
  *            @arg PMU_HVD_FILTER7
  * @return None.
  */
void pmu_hvd_filter_config(uint32_t value)
{
    ASSERT(PMU_HVD_FILTER_CHECK(value));
    MODIFY_REG(PMU->CTR, PMU_CTR_HVD_FTR, value);
}

/**
  * @brief  Get the PMU CTR relevant cnt.
  * @param  ppd_type: Specifies the ppd type. It can be:
  *          PMU_PPD0 or PMU_PPD1.
  * @param  count_type: Specifies the relevant cnt, it can be one of the following values:
  *            @arg PMU_CNT_BIT_LPPD
  *            @arg PMU_CNT_BIT_LPPD_VTH
  *            @arg PMU_CNT_BIT_HPPD
  *            @arg PMU_CNT_BIT_HPPD_VTH
  * @return The count of ppd.
  */
uint32_t pmu_ppd_cnt_get(uint8_t ppd_type, uint32_t count_type)
{
    ASSERT(PMU_PPD_CHECK(ppd_type));
	ASSERT(PMU_CNT_TYPE_CHECK(count_type));

	uint32_t cnt_value = 0;

	if(ppd_type == PMU_PPD0)
	{
	    if(count_type == PMU_CNT_BIT_LPPD)
	    {
	    	cnt_value = (((PMU->CTR2) & (count_type)) >> 4);
	    }
		else if(count_type == PMU_CNT_BIT_LPPD_VTH)
		{
	    	cnt_value = (((PMU->CTR2) & (count_type)) >> 8);
	    }
		else if(count_type == PMU_CNT_BIT_HPPD)
		{
	    	cnt_value = (((PMU->CTR2) & (count_type)) >> 20);
	    }
		else if(count_type == PMU_CNT_BIT_HPPD_VTH)
		{
	    	cnt_value = (((PMU->CTR2) & (count_type)) >> 24);
	    }
	}
	else
	{
	    if(count_type == PMU_CNT_BIT_LPPD)
	    {
	    	cnt_value = (((PMU->CTR3) & (count_type)) >> 4);
	    }
		else if(count_type == PMU_CNT_BIT_LPPD_VTH)
		{
	    	cnt_value = (((PMU->CTR3) & (count_type)) >> 8);
	    }
		else if(count_type == PMU_CNT_BIT_HPPD)
		{
	    	cnt_value = (((PMU->CTR3) & (count_type)) >> 20);
	    }
		else if(count_type == PMU_CNT_BIT_HPPD_VTH)
		{
	    	cnt_value = (((PMU->CTR3) & (count_type)) >> 24);
	    }
	}

	return cnt_value;
}

/**
  * @brief  Checks whether the specified PMU flag is set or not.
  * @param  value: Specifies the flag to check, it can be one of the following values:
  *            @arg PMU_TS_HIGH_TEMPERATURE_105
  *            @arg PMU_TS_HIGH_TEMPERATURE_125
  * @return None.
  */
void pmu_ts_high_temperature_select(uint32_t value)
{
	ASSERT(PMU_TS_HIGH_TEMPERATURE_CHECK(value));
	
	MODIFY_REG(PMU->TS, PMU_TS_HSEL, value);
}

///@endcond

/**
  * @}
  */

/**
  * @}
  */

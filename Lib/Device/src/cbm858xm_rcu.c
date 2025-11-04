/**
* @file        cbm858xm_rcu.c
* @brief       This file provides all the basic RCU firmware functions.
* @author      ChipSea MCU Group
* @version     1.0.0
* @date        2022.05.19
* @copyright   CHIPSEA TECHNOLOGIES (SHENZHEN) CORP.
* @note        
****************************************************************************************************
* @par Modify record:
* <tr><th>Date          <th>Version    <th>Author     <th>Description
* <tr><td>2022.05.19    <td>1.0.0      <td>ChipSea    <td>
* -# 
* </table>
*
****************************************************************************************************
*/


/***************************************************************************************************
 * @includes
***************************************************************************************************/
#include "cbm858xm_rcu.h"


/***************************************************************************************************
 * @definitions
***************************************************************************************************/


/** @addtogroup CBM858xM_StdPeriph_Driver
  * @{
  */

/** @defgroup RCU RCU
  * @brief    RCU driver modules
  * @{
  */

///@cond

/***************************************************************************************************
 * @variables
***************************************************************************************************/
static __I uint8_t APBAHBPrescTable[16] = {0, 0, 0, 0, 1, 2, 3, 4, 1, 2, 3, 4, 6, 7, 8, 9};

/***************************************************************************************************
 * @function
***************************************************************************************************/

/**
  * @brief  Resets the RCU clock configuration to the default reset state.
  * @note   The default reset state including HRC ON and used as system clock source and OFF AHB, APB 
  *         prescaler is set to 1, CSS and CLKOUT is off.  All interrupts is disabled, but it doesn't modify the
  *         configuration of the peripheral clocks LRC and RTC clocks.
  * @param  None.
  * @return None.
  */
void rcu_def_init(void)
{
    /* Set HRCEN bit */
    RCU->CTR |= RCU_CTR_HRCEN;

    /* Set HRC_IOPSEL bits */
    RCU->CTR |= 0x30000000;

    /* Reset SYSSW[1:0], HCLKPDIV[3:0], PCLKPDIV[2:0], ADCPDIV, CKOSEL[2:0], CKOPDIV[2:0]  bits */
    RCU->CFG &= ~(RCU_CFG_HCLKPDIV | RCU_CFG_PCLKPDIV | RCU_CFG_CKOSEL | \
                  RCU_CFG_CKOPDIV );

    /*HCLK default prescale SYSCLK/4*/
    RCU->CFG |= RCU_CFG_HCLKPDIV_DIV4;


    /* Reset HRCSEL bit， default HRC is 24MHz */
    RCU->CTR &= ~RCU_CTR_HRCSEL;

    /* Reset USARTSEL[1:0], I2CSEL and LPTIM1SEL bits */
    RCU->CFG3 &= ~(RCU_CFG3_USART1SEL | RCU_CFG3_I2C1SEL | RCU_CFG3_LPTIM1SEL);

    /* Disable all interrupts */
    RCU->INTR = 0x00000000;
}

/**
  * @brief  HRC clock set, the HRC can be set to 24M/32M.
  * @param  value: specifies the HRC clock value, it can be one of the following values:
  *                @arg RCU_CTR_HRC_24M (24MHz)
  *                @arg RCU_CTR_HRC_32M (32MHz)
  * @note   1. When the HRC clock is switched from 24MHz to 32MHz, should configure the Flash API
  *            flash_wait_counter_set(FMC_WCR_WCNT_1) to ensure the Flash function is normal.
  *         2. When the HRC clock is switched from 32MHz to 24MHz, should configure the Flash API
  *            flash_wait_counter_set(FMC_WCR_WCNT_0) to ensure the Flash function is normal.    
  * @return None.
  */
void rcu_hrc_clock_set(uint32_t value)
{
    ASSERT(RCU_CTR_HRCSEL_CHECK(value));
    
    MODIFY_REG(RCU->CTR, RCU_CTR_HRCSEL, value);
}

/**
  * @brief Configures the wait clock after HRC timer change. 
  * @param  value: specifies the wait clock value, it can be one of the following values:
  *                @arg RCU_CTR_HRCRDY_CNT_4CLK (Wait 4 clocks when HRC starts,then the chip starts working)
  *                @arg RCU_CTR_HRCRDY_CNT_16CLK (Wait 16 clocks when HRC starts,then the chip starts working)
  *                @arg RCU_CTR_HRCRDY_CNT_64CLK (Wait 64 clocks when HRC starts,then the chip starts working)
  *                @arg RCU_CTR_HRCRDY_CNT_128CLK (Wait 128 clocks when HRC starts,then the chip starts working)
  * @note   When change the internal HRC clock through software, it is recommended to configure it as RCU_CTR_HRCRDY_CNT_64CLK or RCU_CTR_HRCRDY_CNT_128CLK.
  * @return None.
  */
void rcu_hrc_ready_time_set(uint32_t value)
{
    ASSERT(RCU_CTR_HRCRDY_CNT_CHECK(value));
    
    MODIFY_REG(RCU->CTR, RCU_CTR_HRCRDY_CNT, value);
}

/**
  * @brief  Selects the clock source to output on CLKOUT pin (PA8). It should be configured in  multi-function mode.
  * @param  sel_value: specifies the clock source to output, it can be one of the following values:
  *          @arg RCU_CLKOUT_SEL_NO_CLK(No clock selected)
  *          @arg RCU_CLKOUT_SEL_LRC(LRC oscillator clock selected)
  *          @arg RCU_CLKOUT_SEL_SYSCLK(System clock selected)
  *          @arg RCU_CLKOUT_SEL_HRC(HRC oscillator clock selected)
  * @param  prescaler: specifies the prescaler on CLKOUT pin, it can be one of the following values:
  *          @arg RCU_CLKOUT_PDIV_1(CLKOUT clock is divided by 1)
  *          @arg RCU_CLKOUT_PDIV_2(CLKOUT clock is divided by 2)
  *          @arg RCU_CLKOUT_PDIV_4(CLKOUT clock is divided by 4)
  *          @arg RCU_CLKOUT_PDIV_8(CLKOUT clock is divided by 8)
  *          @arg RCU_CLKOUT_PDIV_16(CLKOUT clock is divided by 16)
  *          @arg RCU_CLKOUT_PDIV_32(CLKOUT clock is divided by 32)
  *          @arg RCU_CLKOUT_PDIV_64(CLKOUT clock is divided by 64)
  *          @arg RCU_CLKOUT_PDIV_128(CLKOUT clock is divided by 128)   
  * @return None.
  */
void rcu_clkout_config(uint8_t sel_value, uint32_t prescaler)
{
    ASSERT(RCU_CLKOUT_SEL_CHECK(sel_value));
    ASSERT(RCU_CLKOUT_PDIV_CHECK(prescaler));
    
    MODIFY_REG(RCU->CFG, (RCU_CFG_CKOPDIV | RCU_CFG_CKOSEL),  prescaler | ((uint32_t)sel_value << 24));
}

/**
  * @brief  Configures the AHB clock (HCLK).
  * @param  value: defines HCLK divider. It is derived from SYSCLK (the system clock). It can be one of the following 
  *         values:
  *          @arg RCU_HCLK_CFG_SYSCLK_DIV1 (HCLK = SYSCLK)
  *          @arg RCU_HCLK_CFG_SYSCLK_DIV2 (HCLK = SYSCLK/2)   
  *          @arg RCU_HCLK_CFG_SYSCLK_DIV4 (HCLK = SYSCLK/4)
  *          @arg RCU_HCLK_CFG_SYSCLK_DIV8 (HCLK = SYSCLK/8)
  *          @arg RCU_HCLK_CFG_SYSCLK_DIV16 (HCLK = SYSCLK/16)
  *          @arg RCU_HCLK_CFG_SYSCLK_DIV64 (HCLK = SYSCLK/64)
  *          @arg RCU_HCLK_CFG_SYSCLK_DIV128 (HCLK = SYSCLK/128)
  *          @arg RCU_HCLK_CFG_SYSCLK_DIV256 (HCLK = SYSCLK/256)
  *          @arg RCU_HCLK_CFG_SYSCLK_DIV512 (HCLK = SYSCLK/512)
  * @return None.
  */
void rcu_hclk_config(uint32_t value)
{ 
    ASSERT(RCU_HCLK_CFG_CHECK(value));
    
    MODIFY_REG(RCU->CFG, RCU_CFG_HCLKPDIV, value);
}

/**
  * @brief  Configures the APB clock (PCLK).
  * @param  value: defines the APB clock divider which is derived from HCLK (the AHB clock). It can be one of the 
  *         following values:
  *          @arg RCU_PCLK_CFG_HCLK_DIV1 (APB clock = HCLK) 
  *          @arg RCU_PCLK_CFG_HCLK_DIV2 (APB clock = HCLK/2)
  *          @arg RCU_PCLK_CFG_HCLK_DIV4 (APB clock = HCLK/4)
  *          @arg RCU_PCLK_CFG_HCLK_DIV8 (APB clock = HCLK/8)
  *          @arg RCU_PCLK_CFG_HCLK_DIV16 (APB clock = HCLK/16)
  * @return None.
  */
void rcu_pclk_config(uint32_t value)
{
    ASSERT(RCU_PCLK_CFG_CHECK(value));

    MODIFY_REG(RCU->CFG, RCU_CFG_PCLKPDIV, value);
}

/**
  * @brief  Configures the I2C1 clock (I2C1CLK).
  * @param  value: defines the I2C1 clock source which is derived from the HRC or system clock. It can be one of the 
  *         following values:
  *          @arg RCU_I2C1CLK_CFG_HRC (I2C1 clock = HRC)
  *          @arg RCU_I2C1CLK_CFG_SYSCLK (I2C1 clock = System Clock)
  * @return None.
  */
void rcu_i2cclk_config(uint32_t value)
{   
    ASSERT(RCU_I2C1CLK_CFG_CHECK(value));
    
    MODIFY_REG(RCU->CFG3, RCU_CFG3_I2C1SEL, value); 
}

/**
  * @brief  Configures the USART1 clock (USART1CLK).
  * @param  value: defines the USART clock source. It can be one of the
  *         following values:
  *          @arg RCU_USART1CLK_CFG_PCLK (USART1 clock = PCLK)
  *          @arg RCU_USART1CLK_CFG_SYSCLK (USART1 clock = System Clock)
  *          @arg RCU_USART1CLK_CFG_HRC (USART1 clock = HRC Clock) 
  * @return None.
  */
void rcu_usartclk_config(uint32_t value)
{
    ASSERT(RCU_USARTxCLK_CFG_CHECK(value));

    MODIFY_REG(RCU->CFG3, RCU_CFG3_USART1SEL, value); 
}

/**
  * @brief  Configures the LPTIM1 clock (LPTIM1CLK).
  * @param  value: defines the LPTIM1 clock source. It can be one of the
  *         following values:
  *          @arg RCU_LPTIM1_CFG_LRC (LPTIM1 clock = LRC)
  *          @arg RCU_LPTIM1_CFG_SYSCLK(LPTIM1 clock = SYSCLK)
  * @return None.
  */
void rcu_lptim1_config(uint32_t value)
{
    ASSERT(RCU_LPTIM1_CFG_CHECK(value));

    MODIFY_REG(RCU->CFG3, RCU_CFG3_LPTIM1SEL, value); 
}

/**
  * @brief  Get the HRC calibration 1, it's coarse adjustment value.           
  * @param  None                              
  * @return Coarse adjustment value.
  */
int32_t get_hrc_calib1(void)
{
    int32_t ret;
    ret = ((RCU->CTR>>10) & 0x0000003F);
    return ret;
}

/**
  * @brief  Get the HRC calibration 2, it's fine adjustment value.           
  * @param  None                              
  * @return Fine adjustment value.
  */
int32_t get_hrc_calib2(void)
{
    int32_t ret;
    ret = ((RCU->CTR>>4) & 0x0000003F);
    return ret;
}

/**
  * @brief  Configures the LRC clock.
  * @param  value: defines the LRC clock source. It can be one of the
  *         following values:
  *          @arg RCU_DISABLE_BIT_LRC_CLK (Disable LRC)
  *          @arg RCU_ENABLE_BIT_LRC_CLK (Enable LRC)
  * @return None.
  */
void rcu_lrc_config(uint32_t value)
{
    ASSERT(RCU_LRC_CLK_CHECK(value));

    MODIFY_REG(RCU->STS, RCU_STS_LRCEN, value); 
}

/**
  * @brief  Returns the frequencies of the System, AHB and APB busses clocks.             
  * @param  ptr_clock: pointer to a rcu_clock_t structure which will hold the clocks frequencies.  
  * @return None.
  */
void rcu_clk_freq_get(rcu_clock_t* ptr_clock)
{
    uint32_t temp = 0;
    uint32_t presc = 0;
    
    /* Get HRC clock */
    temp = (RCU->CTR >> 30)&0x03;
    ptr_clock->system_clk_freq = (uint32_t)(HRC_VALUE_24M + (uint32_t)((temp*8000000)));
  
    /* Get HCLK prescaler */
    temp = RCU->CFG & RCU_CFG_HCLKPDIV;
    temp = temp >> 4;
    presc = APBAHBPrescTable[temp]; 
    /* HCLK clock frequency */
    ptr_clock->hclk_freq = ptr_clock->system_clk_freq >> presc;

    /* Get PCLK prescaler */
    temp = RCU->CFG & RCU_CFG_PCLKPDIV;
    temp = temp >> 8;
    presc = APBAHBPrescTable[temp];
    /* PCLK clock frequency */
    ptr_clock->pclk_freq = ptr_clock->hclk_freq >> presc;

    /* I2C1CLK clock frequency */
    if((RCU->CFG3 & RCU_CFG3_I2C1SEL) != RCU_CFG3_I2C1SEL)
    {
        /* I2C1 Clock is HRC Osc. */
        ptr_clock->i2c1_clk_freq = ptr_clock->system_clk_freq ;
    }
    else
    {
        /* I2C1 Clock is System Clock */
        ptr_clock->i2c1_clk_freq = ptr_clock->system_clk_freq;
    }

    /* USART1CLK clock frequency */
    if((RCU->CFG3 & RCU_CFG3_USART1SEL) == 0x0)
    {
        /* USART1 Clock is PCLK */
        ptr_clock->usart1_clk_freq = ptr_clock->pclk_freq;
    }
    else if((RCU->CFG3 & RCU_CFG3_USART1SEL) == RCU_CFG3_USART1SEL_0)
    {
        /* USART1 Clock is System Clock */
        ptr_clock->usart1_clk_freq = ptr_clock->system_clk_freq;
    }
    else if((RCU->CFG3 & RCU_CFG3_USART1SEL) == RCU_CFG3_USART1SEL)
    {
        /* USART1 Clock is HRC Osc. */
        ptr_clock->usart1_clk_freq = ptr_clock->system_clk_freq ;
    }
    
    /* LPTIM1 clock frequency */
    if((RCU->CFG3 & RCU_CFG3_LPTIM1SEL) == RCU_LPTIM1_CFG_LRC)
    {
        /* LPTIM1 Clock is LRC Osc. */
        ptr_clock->lptim_clk_freq = LRC_VALUE;
    }
    else if((RCU->CFG3 & RCU_CFG3_LPTIM1SEL) == RCU_LPTIM1_CFG_SYSCLK)
    {
        /* LPTIM1 Clock is System Clock */
        ptr_clock->lptim_clk_freq = ptr_clock->system_clk_freq;
    }
}
///@endcond

/**
  * @}
  */

/**
  * @}
  */

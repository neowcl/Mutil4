/**
* @file        cbm858xm_rcu.h
* @brief       This file contains all the functions prototypes for the RCU firmware library. 
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


#ifndef __CBM858xM_RCU_H__
#define __CBM858xM_RCU_H__


#ifdef __cplusplus
 extern "C" {
#endif


/***************************************************************************************************
 * @includes
***************************************************************************************************/
#include "cbm858xm.h"


/** @addtogroup CBM858xM_StdPeriph_Driver
  * @{
  */

/** @addtogroup RCU
  * @{
  */

/***************************************************************************************************
 * @definitions
***************************************************************************************************/
/** @defgroup RCU_Exported_Types RCU Exported Types
  * @{
  */

/** @struct rcu_clock_t
  * @brief  RCU clock structures definition  
  */ 
typedef struct
{
    uint32_t system_clk_freq;           /*!< System clock frequency */
    uint32_t hclk_freq;                 /*!< HCLK frequency */
    uint32_t pclk_freq;                 /*!< PCLK frequency */
    uint32_t i2c1_clk_freq;             /*!< I2C1 clock frequency */
    uint32_t usart1_clk_freq;           /*!< Usart1 clock frequency */
    uint32_t lptim_clk_freq;            /*!< LPTIM1 clock frequency */
}rcu_clock_t;

/**
  * @}
  */


/** @defgroup RCU_Exported_Constants RCU Exported Constants
  * @{
  */
/*!< Check the HRC Clock*/
#define RCU_CTR_HRCSEL_CHECK(value)         (((value) == RCU_CTR_HRC_24M) || ((value) == RCU_CTR_HRC_32M))   
/*!< Check the wait clock value */
#define  RCU_CTR_HRCRDY_CNT_CHECK(value)    (((value) == RCU_CTR_HRCRDY_CNT_4CLK) || ((value) == RCU_CTR_HRCRDY_CNT_16CLK) || \
                                             ((value) == RCU_CTR_HRCRDY_CNT_64CLK) || ((value) == RCU_CTR_HRCRDY_CNT_128CLK))   

/**
  * @}
  */


/** @defgroup RCU_AHB_peripherals RCU AHB peripherals enable definition
  * @{
  */
#define RCU_AHB_PERI_GPIOA                  RCU_AHBEN_PAEN          /*!< RCU GPIOA clock enable */
#define RCU_AHB_PERI_TRNG                   RCU_AHBEN_TRNGEN        /*!< RCU TRNG clock enable */
#define RCU_AHB_PERI_HASH                   RCU_AHBEN_HASHEN        /*!< RCU HASH clock enable */
#define RCU_AHB_PERI_PKE                    RCU_AHBEN_PKEEN         /*!< RCU PKE clock enable */
#define RCU_AHB_PERI_HDIV                   RCU_AHBEN_HDIVEN        /*!< RCU HDIV clock enable */
#define RCU_AHB_PERI_CRC                    RCU_AHBEN_CRCEN         /*!< RCU CRC clock enable */
#define RCU_AHB_PERI_FMC                    RCU_AHBEN_FMCEN         /*!< RCU FMC clock enable */ 
#define RCU_AHB_PERI_SRAM                   RCU_AHBEN_RMCEN         /*!< RCU SRAM clock enable */ 
#define RCU_AHB_PERI_SDMA                   RCU_AHBEN_SDMAEN        /*!< RCU SDMA clock enable */ 
#define RCU_AHB_PERI_DMA                    RCU_AHBEN_DMAEN         /*!< RCU DMA clock enable */ 
/**
  * @}
  */

/** @defgroup RCU_APB1_peripherals RCU APB1 peripherals enable definition
  * @{
  */
#define RCU_APB1_PERI_TIM3                  RCU_APB1EN_TIM3EN       /*!< RCU APB1 peripheral TIM3 clock enable */
#define RCU_APB1_PERI_TIM14                 RCU_APB1EN_TIM14EN      /*!< RCU APB1 peripheral TIM14 clock enable */
#define RCU_APB1_PERI_WWDT                  RCU_APB1EN_WWDTEN       /*!< RCU APB1 peripheral WWDT clock enable */
#define RCU_APB1_PERI_SPI2                  RCU_APB1EN_SPI2EN       /*!< RCU APB1 peripheral SPI2 clock enable */
#define RCU_APB1_PERI_USART2                RCU_APB1EN_USART2EN     /*!< RCU APB1 peripheral USART2 clock enable */
#define RCU_APB1_PERI_I2C1                  RCU_APB1EN_I2C1EN       /*!< RCU APB1 peripheral I2C1 clock enable */
#define RCU_APB1_PERI_PMU                   RCU_APB1EN_PMUEN        /*!< RCU APB1 peripheral PMU clock enable */
#define RCU_APB1_PERI_LPTIM1                RCU_APB1EN_LPTIM1EN     /*!< RCU APB1 peripheral LPTIM1 clock enable */
/**
  * @}
  */

/** @defgroup RCU_APB2_peripherals RCU APB2 peripherals enable definition
  * @{
  */ 
#define RCU_APB2_PERI_SYSCFG                RCU_APB2EN_SYSCFGEN     /*!< RCU APB2 peripheral system clock enable */
#define RCU_APB2_PERI_ACTS                  RCU_APB2EN_ACTSEN       /*!< RCU APB2 peripheral active shield clock enable */
#define RCU_APB2_PERI_TIM1                  RCU_APB2EN_TIM1EN       /*!< RCU APB2 peripheral TIM1 clock enable */
#define RCU_APB2_PERI_SPI1                  RCU_APB2EN_SPI1EN       /*!< RCU APB2 peripheral SPI1 clock enable */
#define RCU_APB2_PERI_USART1                RCU_APB2EN_USART1EN     /*!< RCU APB2 peripheral USART1 clock enable */
#define RCU_APB2_PERI_DBG                   RCU_APB2EN_DBGEN        /*!< RCU APB2 peripheral DBG clock enable */ 
/**
  * @}
  */

/** @defgroup RCU_peripheral_reset_register RCU peripheral reset register definition
  * @{
  */ 
#define RCU_PERI_RST_REG_SDMA               RCU->AHBRST             /*!< SDMA reset */
#define RCU_PERI_RST_REG_CRC                RCU->AHBRST             /*!< CRC reset */
#define RCU_PERI_RST_REG_HDIV               RCU->AHBRST             /*!< HDIV reset */
#define RCU_PERI_RST_REG_PKE                RCU->AHBRST             /*!< PKE reset */
#define RCU_PERI_RST_REG_HASH               RCU->AHBRST             /*!< HASH reset */
#define RCU_PERI_RST_REG_TRNG               RCU->AHBRST             /*!< TRNG reset */
#define RCU_PERI_RST_REG_GPIOA              RCU->AHBRST             /*!< GPIOA reset */
                                                                    
#define RCU_PERI_RST_REG_TIM3               RCU->APB1RST            /*!< Timer 3 reset */
#define RCU_PERI_RST_REG_TIM14              RCU->APB1RST            /*!< Timer 14 reset */
#define RCU_PERI_RST_REG_WWDT               RCU->APB1RST            /*!< Window watchdog */
#define RCU_PERI_RST_REG_SPI2               RCU->APB1RST            /*!< SPI2 reset */
#define RCU_PERI_RST_REG_USART2             RCU->APB1RST            /*!< USART 2 reset */
#define RCU_PERI_RST_REG_I2C1               RCU->APB1RST            /*!< I2C 1 reset */
#define RCU_PERI_RST_REG_PMU                RCU->APB1RST            /*!< PMU reset */
#define RCU_PERI_RST_REG_LPTIM1             RCU->APB1RST            /*!< LPTIM1 reset */
                                                                    
#define RCU_PERI_RST_REG_SYSCFG             RCU->APB2RST            /*!< SYSCFG reset */
#define RCU_PERI_RST_REG_ACTS               RCU->APB2RST            /*!< Active shield reset */
#define RCU_PERI_RST_REG_TIM1               RCU->APB2RST            /*!< TIM1 reset */
#define RCU_PERI_RST_REG_SPI1               RCU->APB2RST            /*!< SPI1 reset */
#define RCU_PERI_RST_REG_USART1             RCU->APB2RST            /*!< USART1 reset */
#define RCU_PERI_RST_REG_DBG                RCU->APB2RST            /*!< DBGMCU reset */

#define RCU_PERI_RST_REG_RTC                RCU->VBDC               /*!< RTC reset */

/**
  * @}
  */

/** @defgroup RCU_peripheral_reset_bit RCU peripheral reset bit definition
  * @{
  */ 
#define RCU_PERI_RST_BIT_SDMA               RCU_AHBRST_SDMARST      /*!< SDMA reset */
#define RCU_PERI_RST_BIT_CRC                RCU_AHBRST_CRCRST      /*!< CRC reset */
#define RCU_PERI_RST_BIT_HDIV               RCU_AHBRST_HDIVRST      /*!< HDIV reset */
#define RCU_PERI_RST_BIT_PKE                RCU_AHBRST_PKERST       /*!< PKE reset */
#define RCU_PERI_RST_BIT_HASH               RCU_AHBRST_HASHRST      /*!< HASH reset */
#define RCU_PERI_RST_BIT_TRNG               RCU_AHBRST_TRNGRST      /*!< TRNG reset */
#define RCU_PERI_RST_BIT_GPIOA              RCU_AHBRST_PARST        /*!< GPIOA reset */

#define RCU_PERI_RST_BIT_TIM3               RCU_APB1RST_TIM3RST     /*!< Timer 3 reset */
#define RCU_PERI_RST_BIT_TIM14              RCU_APB1RST_TIM14RST    /*!< Timer 14 reset */
#define RCU_PERI_RST_BIT_WWDT               RCU_APB1RST_WWDTRST     /*!< Window Watchdog reset */
#define RCU_PERI_RST_BIT_SPI2               RCU_APB1RST_SPI2RST     /*!< SPI2 reset */
#define RCU_PERI_RST_BIT_USART2             RCU_APB1RST_USART2RST   /*!< USART 2 reset */
#define RCU_PERI_RST_BIT_I2C1               RCU_APB1RST_I2C1RST     /*!< I2C 1 reset */
#define RCU_PERI_RST_BIT_PMU                RCU_APB1RST_PMURST      /*!< PMU reset */
#define RCU_PERI_RST_BIT_LPTIM1             RCU_APB1RST_LPTIM1RST   /*!< LPTIM1 reset */
        
#define RCU_PERI_RST_BIT_SYSCFG             RCU_APB2RST_SYSCFGRST   /*!< SYSCFG reset */
#define RCU_PERI_RST_BIT_ACTS               RCU_APB2RST_ACTSRST     /*!< Active shield reset */
#define RCU_PERI_RST_BIT_TIM1               RCU_APB2RST_TIM1RST     /*!< TIM1 reset */
#define RCU_PERI_RST_BIT_SPI1               RCU_APB2RST_SPI1RST     /*!< SPI1 reset */
#define RCU_PERI_RST_BIT_USART1             RCU_APB2RST_USART1RST   /*!< USART1 reset */
#define RCU_PERI_RST_BIT_DBG                RCU_APB2RST_DBGRST      /*!< DBGMCU reset */

#define RCU_PERI_RST_BIT_RTC                RCU_VBDC_RTCRST         /*!< RTC reset */
/**
  * @}
  */

/** @defgroup RCU_CLKOUT RCU CLKOUT select definition
  * @{
  */ 
#define RCU_CLKOUT_SEL_NO_CLK               ((uint8_t)0x00)         /*!< RCU CLKOUT select no clock source */
#define RCU_CLKOUT_SEL_LRC                  ((uint8_t)0x02)         /*!< RCU CLKOUT select LRC as clock source */
#define RCU_CLKOUT_SEL_SYSCLK               ((uint8_t)0x04)         /*!< RCU CLKOUT select SYSCLK as clock source */
#define RCU_CLKOUT_SEL_HRC                  ((uint8_t)0x05)         /*!< RCU CLKOUT select HRC as clock source */
/**
  * @}
  */                                              
#define RCU_CLKOUT_SEL_CHECK(value)         (((value) == RCU_CLKOUT_SEL_NO_CLK) || ((value) == RCU_CLKOUT_SEL_LRC) || \
                                             ((value) == RCU_CLKOUT_SEL_SYSCLK) || ((value) == RCU_CLKOUT_SEL_HRC))   

/** @defgroup RCU_CLKOUT_prescaler RCU CLKOUT prescaler definition
  * @{
  */                                                 
#define RCU_CLKOUT_PDIV_1                   ((uint32_t)0x00000000)  /*!< RCU CLKOUT is divided by 1 */
#define RCU_CLKOUT_PDIV_2                   ((uint32_t)0x10000000)  /*!< RCU CLKOUT is divided by 2 */
#define RCU_CLKOUT_PDIV_4                   ((uint32_t)0x20000000)  /*!< RCU CLKOUT is divided by 4 */
#define RCU_CLKOUT_PDIV_8                   ((uint32_t)0x30000000)  /*!< RCU CLKOUT is divided by 8 */
#define RCU_CLKOUT_PDIV_16                  ((uint32_t)0x40000000)  /*!< RCU CLKOUT is divided by 16 */
#define RCU_CLKOUT_PDIV_32                  ((uint32_t)0x50000000)  /*!< RCU CLKOUT is divided by 32 */
#define RCU_CLKOUT_PDIV_64                  ((uint32_t)0x60000000)  /*!< RCU CLKOUT is divided by 64 */
#define RCU_CLKOUT_PDIV_128                 ((uint32_t)0x70000000)  /*!< RCU CLKOUT is divided by 128 */
/**
  * @}
  */
#define RCU_CLKOUT_PDIV_CHECK(value)        (((value) == RCU_CLKOUT_PDIV_1)  ||((value) == RCU_CLKOUT_PDIV_2)      || \
                                             ((value) == RCU_CLKOUT_PDIV_4)  || ((value) == RCU_CLKOUT_PDIV_8)     || \
                                             ((value) == RCU_CLKOUT_PDIV_16) || ((value) == RCU_CLKOUT_PDIV_32)    || \
                                             ((value) == RCU_CLKOUT_PDIV_64) ||  ((value) == RCU_CLKOUT_PDIV_128)) 

/** @defgroup RCU_HCLK_source RCU HCLK source definition
  * @{
  */
#define RCU_HCLK_CFG_SYSCLK_DIV1            ((uint32_t)0x00000000)  /*!< SYSCLK not divided */
#define RCU_HCLK_CFG_SYSCLK_DIV2            ((uint32_t)0x00000080)  /*!< SYSCLK divided by 2 */
#define RCU_HCLK_CFG_SYSCLK_DIV4            ((uint32_t)0x00000090)  /*!< SYSCLK divided by 4 */
#define RCU_HCLK_CFG_SYSCLK_DIV8            ((uint32_t)0x000000A0)  /*!< SYSCLK divided by 8 */
#define RCU_HCLK_CFG_SYSCLK_DIV16           ((uint32_t)0x000000B0)  /*!< SYSCLK divided by 16 */
#define RCU_HCLK_CFG_SYSCLK_DIV64           ((uint32_t)0x000000C0)  /*!< SYSCLK divided by 64 */
#define RCU_HCLK_CFG_SYSCLK_DIV128          ((uint32_t)0x000000D0)  /*!< SYSCLK divided by 128 */
#define RCU_HCLK_CFG_SYSCLK_DIV256          ((uint32_t)0x000000E0)  /*!< SYSCLK divided by 256 */
#define RCU_HCLK_CFG_SYSCLK_DIV512          ((uint32_t)0x000000F0)  /*!< SYSCLK divided by 512 */
/**
  * @}
  */

#define RCU_HCLK_CFG_CHECK(value)           (((value) == RCU_HCLK_CFG_SYSCLK_DIV1)   || ((value) == RCU_HCLK_CFG_SYSCLK_DIV2)   || \
                                             ((value) == RCU_HCLK_CFG_SYSCLK_DIV4)   || ((value) == RCU_HCLK_CFG_SYSCLK_DIV8)   || \
                                             ((value) == RCU_HCLK_CFG_SYSCLK_DIV16)  || ((value) == RCU_HCLK_CFG_SYSCLK_DIV64)  || \
                                             ((value) == RCU_HCLK_CFG_SYSCLK_DIV128) || ((value) == RCU_HCLK_CFG_SYSCLK_DIV256) || \
                                             ((value) == RCU_HCLK_CFG_SYSCLK_DIV512))

/** @defgroup RCU_PCLK_source RCU PCLK source definition
  * @{
  */
#define RCU_PCLK_CFG_HCLK_DIV1              ((uint32_t)0x00000000)  /*!< HCLK not divied */ 
#define RCU_PCLK_CFG_HCLK_DIV2              ((uint32_t)0x00000400)  /*!< HCLK divided by 2 */
#define RCU_PCLK_CFG_HCLK_DIV4              ((uint32_t)0x00000500)  /*!< HCLK divided by 4 */
#define RCU_PCLK_CFG_HCLK_DIV8              ((uint32_t)0x00000600)  /*!< HCLK divided by 8 */
#define RCU_PCLK_CFG_HCLK_DIV16             ((uint32_t)0x00000700)  /*!< HCLK divided by 16 */
/**
  * @}
  */
#define RCU_PCLK_CFG_CHECK(pclk)            (((pclk) == RCU_PCLK_CFG_HCLK_DIV1) || ((pclk) == RCU_PCLK_CFG_HCLK_DIV2) || \
                                             ((pclk) == RCU_PCLK_CFG_HCLK_DIV4) || ((pclk) == RCU_PCLK_CFG_HCLK_DIV8) || \
                                             ((pclk) == RCU_PCLK_CFG_HCLK_DIV16))

/** @defgroup RCU_USART_source RCU USART source definition
  * @{
  */
#define RCU_USART1CLK_CFG_PCLK              ((uint32_t)0x00000000)  /*!< RCU USART1 select PCLK as clock source */ 
#define RCU_USART1CLK_CFG_SYSCLK            ((uint32_t)0x00000001)  /*!< RCU USART1 select SYSCLK as clock source */
#define RCU_USART1CLK_CFG_HRC               ((uint32_t)0x00000003)  /*!< RCU USART1 select HRC as clock source */
/**
  * @}
  */

#define RCU_USARTxCLK_CFG_CHECK(value)      (((value) == RCU_USART1CLK_CFG_PCLK) || ((value) == RCU_USART1CLK_CFG_SYSCLK) || \
                                            ((value) == RCU_USART1CLK_CFG_HRC))

/** @defgroup RCU_I2C1_clock RCU I2C1 clock source definition
  * @{
  */
#define RCU_I2C1CLK_CFG_HRC                 ((uint32_t)0x00000000)  /*!< RCU I2C1 clock source is HRC */
#define RCU_I2C1CLK_CFG_SYSCLK              RCU_CFG3_I2C1SEL        /*!< RCU I2C1 clock source is SYSCLK */ 
/**
  * @}
  */
#define RCU_I2C1CLK_CFG_CHECK(value)        (((value) == RCU_I2C1CLK_CFG_HRC) || ((value) == RCU_I2C1CLK_CFG_SYSCLK))

#define RCU_HRC_CALI_VALUE_CHECK(value)     ((value) <= 0x1F)


/** @defgroup RCU_LPTIM1_clock RCU LPTIM1 clock definition
  * @{
  */
#define RCU_LPTIM1_CFG_LRC                  ((uint32_t)0x00000000)   /*!< LPTIM1 clock use LRC clock */
#define RCU_LPTIM1_CFG_SYSCLK               RCU_CFG3_LPTIM1SEL_SCLK  /*!< LPTIM1 clock use systick clock */
/**
  * @}
  */
#define RCU_LPTIM1_CFG_CHECK(clk)           (((clk) == RCU_LPTIM1_CFG_LRC) || ((clk) == RCU_LPTIM1_CFG_SYSCLK))


/** @defgroup RCU_function_register RCU function register definition
  * @{
  */
#define RCU_ENABLE_REG_HRC_CLK              RCU->CTR                /*!< HRC clock */ 
#define RCU_ENABLE_REG_RTC_CLK              RCU->VBDC               /*!< RTCCLK */ 
#define RCU_ENABLE_REG_LRC_CLK              RCU->STS                /*!< LRC CLK */
/**
  * @}
  */

/** @defgroup RCU_function_bit RCU function bit definition
  * @{
  */
#define RCU_DISABLE_BIT_LRC_CLK             ((uint32_t)0x00000000)  /*!< Disable LRC Clock */
#define RCU_ENABLE_BIT_HRC_CLK              RCU_CTR_HRCEN           /*!< HRC clock */
#define RCU_ENABLE_BIT_RTC_CLK              RCU_VBDC_RTCCLKEN       /*!< RTCCLK */
#define RCU_ENABLE_BIT_LRC_CLK              RCU_STS_LRCEN           /*!< LRC CLK */               
#define RCU_ENABLE_BIT_RTC_RESET            RCU_VBDC_VBTRST         /*!< RTC RESET */
/**
  * @}
  */
#define RCU_LRC_CLK_CHECK(en)           (((en) == RCU_DISABLE_BIT_LRC_CLK) || ((en) == RCU_ENABLE_BIT_LRC_CLK))

/** @defgroup RCU_interrupt RCU interrupt definition
  * @{
  */
#define RCU_INTR_LRC_STAB                   RCU_INTR_LRCSTABIE      /*!< RCU LRC stabilization interrupt */
#define RCU_INTR_HRC_STAB                   RCU_INTR_HRCSTABIE      /*!< RCU HRC stabilization interrupt */
/**
  * @}
  */

/** @defgroup RCU_interrupt_flag RCU interrupt flag definition
  * @{
  */
#define RCU_INTR_FLAG_LRC_STAB              RCU_INTR_LRCSTABIF      /*!< RCU LRC stabilization interrupt flag */
#define RCU_INTR_FLAG_HRC_STAB              RCU_INTR_HRCSTABIF      /*!< RCU HRC stabilization interrupt flag */ 
/**
  * @}
  */

/** @defgroup RCU_interrupt_flag_clear RCU interrupt flag clear definition
  * @{
  */
#define RCU_INTR_FLAG_CLR_LRC_STAB          RCU_INTR_LRCSTABIC      /*!< RCU LRC stabilization interrupt flag clear */
#define RCU_INTR_FLAG_CLR_HRC_STAB          RCU_INTR_HRCSTABIC      /*!< RCU HRC stabilization interrupt flag clear */
/**
  * @}
  */

/** @defgroup RCU_flag_register RCU flag register definition
  * @{
  */
#define RCU_FLAG_REG_HRC_STAB               RCU->CTR                /*!< RCU HRC stabilization flag */
#define RCU_FLAG_REG_LRC_STAB               RCU->STS                /*!< RCU LRC stabilization flag */
#define RCU_FLAG_REG_REGERRRST              RCU->STS                /*!< RCU register error reset flag */
#define RCU_FLAG_REG_V15RST                 RCU->STS                /*!< RCU 1.5V domain system reset flag */ 
#define RCU_FLAG_REG_OBURST                 RCU->STS                /*!< RCU option byte update reset flag */
#define RCU_FLAG_REG_NRST                   RCU->STS                /*!< RCU nRST pin reset flag */
#define RCU_FLAG_REG_PORRST                 RCU->STS                /*!< RCU POR/PDR reset flag */ 
#define RCU_FLAG_REG_SWRST                  RCU->STS                /*!< RCU software reset flag */ 
#define RCU_FLAG_REG_FWDTRST                RCU->STS                /*!< RCU FWDT reset flag */ 
#define RCU_FLAG_REG_WWDTRST                RCU->STS                /*!< RCU WWDT reset flag */ 
#define RCU_FLAG_REG_LPERST                 RCU->STS                /*!< RCU low-power mode enter reset flag */ 
/**
  * @}
  */

/** @defgroup RCU_clock_stabilization_flag RCU clock stabilization flag definition
  * @{
  */
#define RCU_FLAG_BIT_HRC_STAB               RCU_CTR_HRCSTAB         /*!< RCU HRC stabilization flag */ 
#define RCU_FLAG_BIT_LRC_STAB               RCU_STS_LRCSTAB         /*!< RCU LRC stabilization flag */
#define RCU_FLAG_BIT_REGERRRST              RCU_STS_REGERRRSTF      /*!< RCU register error reset flag */
#define RCU_FLAG_BIT_V15RST                 RCU_STS_V15RSTF         /*!< RCU 1.5V domain system reset flag */
#define RCU_FLAG_BIT_OBURST                 RCU_STS_OBURSTF         /*!< RCU option byte update reset flag */ 
#define RCU_FLAG_BIT_NRST                   RCU_STS_NRSTF           /*!< RCU nRST pin reset flag */ 
#define RCU_FLAG_BIT_PORRST                 RCU_STS_PORRSTF         /*!< RCU POR/PDR reset flag */ 
#define RCU_FLAG_BIT_SWRST                  RCU_STS_SWRSTF          /*!< RCU software reset flag */ 
#define RCU_FLAG_BIT_FWDTRST                RCU_STS_FWDTRSTF        /*!< RCU FWDT reset flag */ 
#define RCU_FLAG_BIT_WWDTRST                RCU_STS_WWDTRSTF        /*!< RCU WWDT reset flag */ 
#define RCU_FLAG_BIT_LPERST                 RCU_STS_LPERSTF         /*!< RCU low-power mode enter reset flag */ 
/**
  * @}
  */

/** @defgroup RCU_Macro_function RCU Macro function definition
  * @{
  */

/**
  * @brief  Resets the RCU clock configuration to the default reset state.
  * @note   The default reset state including HRC ON and used as system clock source and OFF AHB, APB 
  *         prescaler is set to 1, CSS and CLKOUT is off. All interrupts is disabled, but it doesn't modify the
  *         configuration of the peripheral clocks LRC and RTC clocks.
  * @param  None.
  * @return None.
  */
#define __RCU_DEF_INIT()                rcu_def_init()

/**
  * @brief  Enables the AHB peripheral clock.
  * @note   After reset, the peripheral clock (used for registers read/write access) is disabled and the application 
  *         software has to enable this clock before using it.    
  * @param  PERI: specifies the AHB peripheral to gates its clock. It can be any combination of the following values:
  *          @arg RCU_AHB_PERI_GPIOA (GPIOA clock)
  *          @arg RCU_AHB_PERI_TRNG (TRNG clock)
  *          @arg RCU_AHB_PERI_HASH (HASH clock)
  *          @arg RCU_AHB_PERI_PKE (PKE clock)
  *          @arg RCU_AHB_PERI_HDIV (HDIV clock)
  *          @arg RCU_AHB_PERI_CRC (CRC clock)
  *          @arg RCU_AHB_PERI_FMC (has effect only when the Flash memory is in power down mode)  
  *          @arg RCU_AHB_PERI_SRAM (SRAM clock)
  *          @arg RCU_AHB_PERI_SDMA (SDMA clock)
  *          @arg RCU_AHB_PERI_DMA (DMA clock)
  * @return None.
  */
#define __RCU_AHB_CLK_ENABLE(PERI)      (RCU->AHBEN |= PERI)

/**
  * @brief  Disables the AHB peripheral clock.   
  * @param  PERI: specifies the AHB peripheral to gates its clock. It can be any combination of the following values:
  * @param  PERI: specifies the AHB peripheral to gates its clock. It can be any combination of the following values:
  *          @arg RCU_AHB_PERI_GPIOA (GPIOA clock)
  *          @arg RCU_AHB_PERI_TRNG (TRNG clock)
  *          @arg RCU_AHB_PERI_HASH (HASH clock)
  *          @arg RCU_AHB_PERI_PKE (PKE clock)
  *          @arg RCU_AHB_PERI_HDIV (HDIV clock)
  *          @arg RCU_AHB_PERI_CRC (CRC clock)
  *          @arg RCU_AHB_PERI_FMC (has effect only when the Flash memory is in power down mode)  
  *          @arg RCU_AHB_PERI_SRAM (SRAM clock)
  *          @arg RCU_AHB_PERI_SDMA (SDMA clock)
  *          @arg RCU_AHB_PERI_DMA (DMA clock)
  * @return None.
  */
#define __RCU_AHB_CLK_DISABLE(PERI)     (RCU->AHBEN &= ~(PERI))
                                                                                                            
/**
  * @brief  Enables the APB1 peripheral clock.
  * @note   After reset, the peripheral clock (used for registers read/write access) is disabled and the application 
  *         software has to enable this clock before using it.    
  * @param  PERI: specifies the APB1 peripheral to gates its clock. It can be any combination of the following values:
  *          @arg RCU_APB1_PERI_TIM3 (TIM3 clock)
  *          @arg RCU_APB1_PERI_TIM14 (TIM14 clock)
  *          @arg RCU_APB1_PERI_WWDT (WWDT clock)
  *          @arg RCU_APB1_PERI_SPI2 (SPI2 clock)
  *          @arg RCU_APB1_PERI_USART2 (USART2 clock)     
  *          @arg RCU_APB1_PERI_I2C1 (I2C1 clock)
  *          @arg RCU_APB1_PERI_PMU (PMU clock)
  *          @arg RCU_APB1_PERI_LPTIM1 (LPTIM1 clock) 
  * @return None.
  */
#define __RCU_APB1_CLK_ENABLE(PERI)     (RCU->APB1EN |= PERI)

/**
  * @brief  Disables the APB1 peripheral clock.   
  * @param  PERI: specifies the APB1 peripheral to gates its clock. It can be any combination of the following values:
  *          @arg RCU_APB1_PERI_TIM3 (TIM3 clock)
  *          @arg RCU_APB1_PERI_TIM14 (TIM14 clock)
  *          @arg RCU_APB1_PERI_WWDT (WWDT clock)
  *          @arg RCU_APB1_PERI_SPI2 (SPI2 clock)
  *          @arg RCU_APB1_PERI_USART2 (USART2 clock)     
  *          @arg RCU_APB1_PERI_I2C1 (I2C1 clock)
  *          @arg RCU_APB1_PERI_PMU (PMU clock)
  *          @arg RCU_APB1_PERI_LPTIM1 (LPTIM1 clock) 
  * @return None.
  */
#define __RCU_APB1_CLK_DISABLE(PERI)    (RCU->APB1EN &= ~(PERI)) 
                                                                                                                          
/**
  * @brief  Enables the APB2 peripheral clock.
  * @note   After reset, the peripheral clock (used for registers read/write access) is disabled and the application
  *         software has to enable this clock before using it.    
  * @param  PERI: specifies the APB2 peripheral to gates its clock. It can be any combination of the following values:
  *          @arg RCU_APB2_PERI_SYSCFG (SYSCFG clock)
  *          @arg RCU_APB2_PERI_ACTS (Active shield clock)
  *          @arg RCU_APB2_PERI_TIM1 (TIM1 clock)
  *          @arg RCU_APB2_PERI_SPI1 (SPI1 clock)
  *          @arg RCU_APB2_PERI_USART1 (USART1 clock)
  *          @arg RCU_APB2_PERI_DBG (DBGMCU clock)
  * @return None.
  */
#define __RCU_APB2_CLK_ENABLE(PERI)     (RCU->APB2EN |= PERI) 

/**
  * @brief  Disables the APB2 peripheral clock.  
  * @param  PERI: specifies the APB2 peripheral to gates its clock. It can be any combination of the following values:
  *          @arg RCU_APB2_PERI_SYSCFG (SYSCFG clock)
  *          @arg RCU_APB2_PERI_ACTS (Active shield clock)
  *          @arg RCU_APB2_PERI_TIM1 (TIM1 clock)
  *          @arg RCU_APB2_PERI_SPI1 (SPI1 clock)
  *          @arg RCU_APB2_PERI_USART1 (USART1 clock)  
  *          @arg RCU_APB2_PERI_DBG (DBGMCU clock)
  * @return None.
  */
#define __RCU_APB2_CLK_DISABLE(PERI)    (RCU->APB2EN &= ~(PERI)) 

/**
  * @brief  Enables the specified peripheral reset.   
  * @param  PERI: specifies peripheral. It can be one of the following values:
  *         SDMA, CRC, HDIV, PKE, HASH, TRNG, GPIOA, LPTIM1,
  *			    TIM3, TIM14, WWDT, SPI2, USART2, 
  *         I2C1, PMU, SYSCFG, TIM1, SPI1, USART1, DBG, RTC.
  * @return None.
  */
#define __RCU_PERI_RST_ENABLE(PERI)     ((RCU_PERI_RST_REG_##PERI) |= (RCU_PERI_RST_BIT_##PERI))

/**
  * @brief  Enables the specified peripheral reset.   
  * @param  PERI: specifies peripheral. It can be one of the following values:
  *         SDMA, CRC, HDIV, PKE, HASH, TRNG, GPIOA, LPTIM1,
  *			    TIM3, TIM14, WWDT, SPI2, USART2, 
  *         I2C1, PMU, SYSCFG, TIM1, SPI1, USART1, DBG, RTC.
  * @return None.
  */
#define __RCU_PERI_RST_DISABLE(PERI)    ((RCU_PERI_RST_REG_##PERI) &= ~(RCU_PERI_RST_BIT_##PERI))

/**
  * @brief  Reset the specified peripheral.   
  * @param  PERI: specifies peripheral. It can be one of the following values:
  *         SDMA, CRC, HDIV, PKE, HASH, TRNG, GPIOA, LPTIM1,
  *			    TIM3, TIM14, WWDT, SPI2, USART2, 
  *         I2C1, PMU, SYSCFG, TIM1, SPI1, USART1, DBG, RTC.
  * @return None.
  */
#define __RCU_PERI_RESET(PERI)    do{                                                            \
                                      ((RCU_PERI_RST_REG_##PERI) |= (RCU_PERI_RST_BIT_##PERI));  \
                                      ((RCU_PERI_RST_REG_##PERI) &= ~(RCU_PERI_RST_BIT_##PERI)); \
                                    }while(0)

/**
  * @brief  Enables the specified RCU function.           
  * @param  VALUE: specifies the RCU function, it can be one of the following values:
  *          @arg HRC_CLK (HRC clock)  
  *          @arg RTC_CLK (RTC clock)  
  *          @arg LRC_CLK (LRC clock)    
  * @return None.
  */
#define __RCU_FUNC_ENABLE(VALUE)        ((RCU_ENABLE_REG_##VALUE) |= (RCU_ENABLE_BIT_##VALUE))

/**
  * @brief  Disables the specified RCU function.           
  * @param  VALUE: specifies the RCU function, it can be one of the following values:
  *          @arg HRC_CLK (HRC clock)  
  *          @arg RTC_CLK (RTC clock)    
  *          @arg LRC_CLK (LRC clock)   
  * @return None.
  */
#define __RCU_FUNC_DISABLE(VALUE)       ((RCU_ENABLE_REG_##VALUE) &= ~(RCU_ENABLE_BIT_##VALUE))  

/**
  * @brief  Enables the specified RCU interrupts.
  * @param  INT: specifies the RCU interrupt sources to be enabled. It can be any combination of the following values:
  *          @arg RCU_INTR_LRC_STAB (LRC stabilization interrupt)
  *          @arg RCU_INTR_HRC_STAB (HRC stabilization interrupt)
  * @return None.
  */
#define __RCU_INTR_ENABLE(INT)          (RCU->INTR |= INT)

/**
  * @brief  Diasables the specified RCU interrupts.
  * @param  INT: specifies the RCU interrupt sources to be enabled. It can be any combination of the following values:
  *          @arg RCU_INTR_LRC_STAB (LRC stabilization interrupt)
  *          @arg RCU_INTR_HRC_STAB (HRC stabilization interrupt)
  * @return None.
  */
#define __RCU_INTR_DISABLE(INT)         (RCU->INTR &= ~(INT))

/**
  * @brief  Checks whether the specified RCU interrupt has occurred or not.
  * @param  FLAG: specifies the RCU interrupt source to check. It can be one of the following values:
  *          @arg HRC_STAB (HRC oscillator clock interrupt)
  *          @arg LRC_STAB (LRC oscillator clock interrupt) 
  * @return The new state of flag (SET or RESET).
  */
#define __RCU_INTR_STATUS_GET(FLAG)     ((RCU->INTR & (RCU_INTR_FLAG_##FLAG)) ? SET : RESET)

/**
  * @brief  Clears the RCU's interrupt pending bits.
  * @param  FLAG: specifies the interrupt pending bit to clear. It can be any combination of the following values:
  *          @arg RCU_INTR_FLAG_CLR_HRC_STAB (HRC oscillator clock interrupt flag)
  *          @arg RCU_INTR_FLAG_CLR_LRC_STAB (LRC oscillator clock interrupt flag)
  * @return None.
  */
#define __RCU_INTR_FLAG_CLEAR(FLAG)     (RCU->INTR = FLAG)

/**
  * @brief  Checks whether the specified RCU stabilization flag is set or not.
  * @param  FLAG: specifies the reset flag to check, it can be one of the following values:
  *          @arg OBURST (Option Byte Update reset )
  *          @arg NRST (nRST Pin reset)
  *          @arg V15RST (the 1.5V domain reset)
  *          @arg PORRST (POR/PDR reset)
  *          @arg SWRST (Software reset)
  *          @arg FWDTRST (FWDT reset)
  *          @arg WWDTRST (WWDT reset)
  *          @arg LPERST (Low-power mode enter-reset)
  *          @arg REGERRRST (Register error reset)
  *          @arg HRC_STAB (HRC oscillator clock stabilization)
  *          @arg LRC_STAB (LRC oscillator clock stabilization)
  * @return The new state of flag (SET or RESET).
  */
#define __RCU_FLAG_STATUS_GET(FLAG)     (((RCU_FLAG_REG_##FLAG) & (RCU_FLAG_BIT_##FLAG)) ? SET : RESET)

/**
  * @brief  Clears the RCU flags. The flags are: RCU_FLAG_BIT_OBURSTF, RCU_FLAG_BIT_NRST, RCU_FLAG_BIT_V15RSTF,
  *         RCU_FLAG_BIT_PORRST, RCU_FLAG_BIT_SWRST, RCU_FLAG_BIT_FWDTRST, RCU_FLAG_BIT_WWDTRST, RCU_FLAG_BIT_LPERST.
  * @param  None.
  * @return None.
  */
#define __RCU_FLAG_CLEAR()              (RCU->STS |= RCU_STS_CRSTF)

/**
  * @}
  */
 
/***************************************************************************************************
 * @functions
***************************************************************************************************/
/** @defgroup RCU_Exported_Functions RCU Exported Functions
  * @{
  */

/**
  * @brief  Resets the RCU clock configuration to the default reset state.
  * @note   The default reset state including HRC ON and used as system clock source and OFF AHB, APB 
  *         prescaler is set to 1, CSS and CLKOUT is off.  All interrupts is disabled, but it doesn't modify the
  *         configuration of the peripheral clocks LRC and RTC clocks.
  * @param  None.
  * @return None.
  */
void rcu_def_init(void);

/**
  * @brief  HRC clock set, the HRC can be set to 24M/32M.
  * @param  value: specifies the HRC clock value, it can be one of the following values:
  *                @arg RCU_CTR_HRC_24M (24MHz)
  *                @arg RCU_CTR_HRC_32M (32MHz)
  * @note   1. When the HRC clock is switched from 24MHz to 32MHz , should configure the Flash API
  *            flash_wait_counter_set(FMC_WCR_WCNT_1) to ensure the Flash function is normal.
  *         2. When the HRC clock is switched from 32MHz to 24MHz, should configure the Flash API
  *            flash_wait_counter_set(FMC_WCR_WCNT_0) to ensure the Flash function is normal.    
  * @return None.
  */
void rcu_hrc_clock_set(uint32_t value);

/**
  * @brief Configures the wait clock after HRC clock change. 
  * @param  value: specifies the wait clock value, it can be one of the following values:
  *                @arg RCU_CTR_HRCRDY_CNT_4CLK (Wait 4 clocks when HRC starts,then the chip starts working)
  *                @arg RCU_CTR_HRCRDY_CNT_16CLK (Wait 16 clocks when HRC starts,then the chip starts working)
  *                @arg RCU_CTR_HRCRDY_CNT_64CLK (Wait 64 clocks when HRC starts,then the chip starts working)
  *                @arg RCU_CTR_HRCRDY_CNT_128CLK (Wait 128 clocks when HRC starts,then the chip starts working)
  * @note   When change the internal HRC clock through software, it is recommended to configure it as RCU_CTR_HRCRDY_CNT_64CLK or RCU_CTR_HRCRDY_CNT_128CLK.    
  * @return None.
  */
void rcu_hrc_ready_time_set(uint32_t value);

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
void rcu_clkout_config(uint8_t sel_value, uint32_t prescaler);

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
void rcu_hclk_config(uint32_t value);

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
void rcu_pclk_config(uint32_t value);

/**
  * @brief  Configures the I2C1 clock (I2C1CLK).
  * @param  value: defines the I2C1 clock source which is derived from the HRC or system clock. It can be one of the 
  *         following values:
  *          @arg RCU_I2C1CLK_CFG_HRC (I2C1 clock = HRC)
  *          @arg RCU_I2C1CLK_CFG_SYSCLK (I2C1 clock = System Clock)
  * @return None.
  */
void rcu_i2cclk_config(uint32_t value);

/**
  * @brief  Configures the USART1 clock (USART1CLK).
  * @param  value: defines the USART clock source. It can be one of the
  *         following values:
  *          @arg RCU_USART1CLK_CFG_PCLK (USART1 clock = PCLK)
  *          @arg RCU_USART1CLK_CFG_SYSCLK (USART1 clock = System Clock)
  *          @arg RCU_USART1CLK_CFG_HRC (USART1 clock = HRC Clock) 
  * @return None.
  */
void rcu_usartclk_config(uint32_t value);

/**
  * @brief  Configures the LPTIM1 clock (LPTIM1CLK).
  * @param  value: defines the LPTIM1 clock source. It can be one of the
  *         following values:
  *          @arg RCU_LPTIM1_CFG_LRC (LPTIM1 clock = LRC)
  *          @arg RCU_LPTIM1_CFG_SYSCLK(LPTIM1 clock = SYSCLK)
  * @return None.
  */
void rcu_lptim1_config(uint32_t value);

/**
  * @brief  Get the HRC calibration 1, it's coarse adjustment value.           
  * @param  None                              
  * @return Coarse adjustment value.
  */
int32_t get_hrc_calib1(void);

/**
  * @brief  Get the HRC calibration 2, it's fine adjustment value.           
  * @param  None                              
  * @return Fine adjustment value.
  */
int32_t get_hrc_calib2(void);

/**
  * @brief  Configures the LRC clock.
  * @param  value: defines the LRC clock source. It can be one of the
  *         following values:
  *          @arg RCU_DISABLE_BIT_LRC_CLK (Disable LRC)
  *          @arg RCU_ENABLE_BIT_LRC_CLK (Enable LRC)
  * @return None.
  */
void rcu_lrc_config(uint32_t value);

/**
  * @brief  Returns the frequencies of the System, AHB and APB busses clocks.             
  * @param  ptr_clock: pointer to a rcu_clock_t structure which will hold the clocks frequencies.  
  * @return None.
  */
void rcu_clk_freq_get(rcu_clock_t* ptr_clock);
/**
  * @}
  */


#ifdef __cplusplus
}
#endif

#endif /* cbm858xm_rcu.h */


/**
  * @}
  */

/**
  * @}
  */

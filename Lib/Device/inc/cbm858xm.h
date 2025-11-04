/**
* @file        cbm858xm.h
* @brief       This file contains all the functions prototypes for the CBM858xM firmware library. 
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


#ifndef __CBM858xM_H__
#define __CBM858xM_H__


#ifdef __cplusplus
 extern "C" {
#endif


/***************************************************************************************************
 * @includes
***************************************************************************************************/
#include <stdint.h>
#include "RTE_Components.h"             /*!< Component selection */


/** @addtogroup CMSIS
  * @{
  */

/** @addtogroup CBM858xM
  * @{
  */
 
/***************************************************************************************************
 * @definitions
***************************************************************************************************/
/** @addtogroup Library_configuration_section
  * @{
  */

/**
  * @brief CBM858xM Standard Peripheral Librar version number V1.0.0
  */
#define CBM858xM_STDPERIPH_VERSION_MAIN   	(0x01) /*!< [31:24] main version */
#define CBM858xM_STDPERIPH_VERSION_SUB1   	(0x00) /*!< [23:16] sub1 version */
#define CBM858xM_STDPERIPH_VERSION_SUB2   	(0x00) /*!< [15:8]  sub2 version */
#define CBM858xM_STDPERIPH_VERSION_RC     	(0x00) /*!< [7:0]  release candidate */
#define CBM858xM_STDPERIPH_VERSION        	((CBM858xM_STDPERIPH_VERSION_MAIN << 24)| \
											(CBM858xM_STDPERIPH_VERSION_SUB1 << 16)	| \
                                            (CBM858xM_STDPERIPH_VERSION_SUB2 << 8)	| \
                                            (CBM858xM_STDPERIPH_VERSION_RC))
/**
 * @}
 */


/** @addtogroup Configuration_section_for_CMSIS
  * @{
  */

/**
  * @brief CBM858xM Interrupt Number Definition, according to the selected device
  *        in @ref Library_configuration_section
 */
#define __CM0_REV                 0             /*!< Core Revision r0p0 */
#define __MPU_PRESENT             0             /*!< CBM858xM do not provide MPU */
#define __FPU_PRESENT             0             /*!< FPU present or not */ 
#define __NVIC_PRIO_BITS          2             /*!< CBM858xM uses 2 Bits for the oity Levels */
#define __Vendor_SysTickConfig    0             /*!< Set to 1 if different SysTicknig is used */

/**
 * @}
 */

/** @defgroup CBM858xM_Exported_Types CBM858xM Exported Types
  * @{
  */

/** @enum  IRQn_Type 
  * @brief Interrupt Number definition.
  */
typedef enum
{
    NMI_IRQn                    = -14,          /*!< 2 Non Maskable Interrupt */
    HardFault_IRQn              = -13,          /*!< 3 Cortex-M0 Hard Fault Interrupt */
    SVC_IRQn                    = -5,           /*!< 11 Cortex-M0 SV Call Interrupt */
    PendSV_IRQn                 = -2,           /*!< 14 Cortex-M0 Pend SV Interrupt */
    SysTick_IRQn                = -1,           /*!< 15 Cortex-M0 System Tick Interrupt */
    IRQn_WWDT					= 0,	        /*!< Window WatchDog Interrupt */
    IRQn_LVD					= 1,	        /*!< LVD, HVD, LPPD, HPPD and temperature sensor through EXTI Line16 detect Intrrupt */
    IRQn_RTC					= 2,	        /*!< RTC, EXTI Line 17/19/20 Intrrupt */
    IRQn_FLASH					= 3,	        /*!< FLASH Interrupt */
    IRQn_RCU					= 4,	        /*!< RCU Interrupt */
    IRQn_EXTI0_1				= 5,	        /*!< EXTI Line 0 and 1 Interrupts */
    IRQn_EXTI2_3				= 6,	        /*!< EXTI Line 2 and 3 Interrupts */
    IRQn_EXTI4_15				= 7,	        /*!< EXTI Line 4 to 15 Interrupts */
	IRQn_DMA1_CHANNEL1			= 9,	        /*!< DMA1 Channel 1 Interrupt */
	IRQn_DMA1_CHANNEL2_3		= 10,	        /*!< DMA1 Channel 2 and Channel 3 Intrrupts */
	IRQn_DMA1_CHANNEL4_5		= 11,	        /*!< DMA1 Channel 4 and Channel 5 Intrrupts */ 
    IRQn_TIM1_BRK_UP_TRG_COM	= 13,	        /*!< TIM1 Break, Update, Trigger and ommutation Interrupts */
	IRQn_TIM1_CC				= 14,	        /*!< TIM1 Capture Compare Interrupt */
    IRQn_TIM3					= 16,	        /*!< TIM3 Interrupt */
    IRQn_LPTIM					= 17,	        /*!< LPTIM Interrupt and EXTI Line 22 Interrupt */
    IRQn_SDMA					= 18,	        /*!< SDMA Interrupt */
	  IRQn_TIM14					= 19,	        /*!< TIM14 Interrupt */
	  IRQn_TRNG					= 20,	        /*!< TRNG Interrupt */   
	  IRQn_HASH					= 21,	        /*!< HASH Interrupt */ 
	  IRQn_PKE					= 22,	        /*!< PKE Interrupt */  
    IRQn_I2C1                   = 23,           /*!< I2C1 Interrupt and EXTI 23 Interrupt */  
    IRQn_SPI1                   = 25,           /*!< SPI1 Interrupt */
    IRQn_SPI2                   = 26,           /*!< SPI2 Interrupt */
	IRQn_USART1 				= 27,	        /*!< USART1 Interrupt and EXTI 25 Interrupt */
	IRQn_USART2 				= 28,	        /*!< USART2 Interrupt */
	IRQn_ACTIVE_SHIELD 			= 31,	        /*!< ACTIVE SHIELD Interrupt */
}IRQn_Type;

#include "core_cm0.h"


/** @enum  error_status_t  
  * @brief Error status definition.
  */
typedef enum 
{
    ERROR   = 0,                                /*!< Error definition */
    SUCCESS = !ERROR                            /*!< Success definition */
} error_status_t;

/** @enum bit_status_t
  * @brief bit flag set or status get definitoin
  */
typedef enum 
{
    RESET   = 0,                                /*!< Reset definition */
    SET     = !RESET                            /*!< Set definition */
}bit_status_t;

/** @enum enable_state_t
  * @brief enable or disable  definition
  */
typedef enum 
{
    DISABLE   = 0,                              /*!< Disable definition */
    ENABLE    = !DISABLE                        /*!< Enable definition */
}enable_state_t;

/** @struct acts_reg_t
  * @brief Active Shield structure definition
  */
typedef struct 
{
    __IO    uint32_t CTR0;         /*!< Active Shield control register 0 */
    __IO    uint32_t CTR1;         /*!< Active Shield control register 1 */
    __IO    uint32_t CTR2;         /*!< Active Shield control register 2 */
    __IO    uint32_t SEED;              /*!< Active Shield seed register */
    __IO    uint32_t STATUS;            /*!< Active Shield status register */
    __IO    uint32_t IRQ;               /*!< Active Shield IRQ register */
    __IO    uint32_t IRQ_MSK;           /*!< Active Shield IRQ mask register */
    __IO    uint32_t MISMATCH0;        /*!< Active Shield mismatch 0 register */
}acts_reg_t;

/** @struct  crc_reg_t 
  * @brief   CRC Registers structure definition.
  */
typedef struct
{
    __IO    uint32_t DATA;              /*!< CRC data register. */
    __IO    uint32_t FREDATA;           /*!< CRC independent data register. */
    __IO    uint32_t CTR;               /*!< CRC control register. */
    __IO    uint32_t RESERVED;          /*!< Reserved(0x00C ~ 0x00F). */
    __IO    uint32_t INITCFG;           /*!< Initial CRC value register. */
    __IO    uint32_t POL;               /*!< CRC polynomial register. */
}crc_reg_t;

/** @struct dma_channel_reg_t
  * @brief DMA channel register structure defiition
  */
typedef struct
{
    __IO    uint32_t CHxCTR;            /*!< DMA channel x controller register */
    __IO    uint32_t CHxNUM;            /*!< Transfer data number register of DMA cannel x */
    __IO    uint32_t CHxPA;             /*!< Peripheral address register of DMA chanel x */
    __IO    uint32_t CHxMA;             /*!< Memory address register of DMA channelx */
}dma_channel_reg_t;

/** @struct dma_reg_t
  * @brief DMA  register structure definition
  */
typedef struct 
{
    __IO    uint32_t STS;               /*!< DMA interrupt status register */
    __IO    uint32_t INTFC;             /*!< DMA interrupt flag clear register */
}dma_reg_t;


/** @struct efuse_reg_t
  * @brief eFuse register structure definition
  */
typedef struct 
{
    __IO    uint32_t LCS1;              /*!< eFuse lifecycle option bytes 1 */
    __IO    uint32_t LCS2;              /*!< eFuse lifecycle option bytes 2 */
    __IO    uint32_t LCS3;              /*!< eFuse lifecycle option bytes 3 */
    __IO    uint32_t CTR;               /*!< eFuse option area lock control */
    __IO    uint32_t RESERVED[4];       /*!< Reserved */
    __IO    uint32_t KEY1_VALID;        /*!< eFuse secure key valid register 1 */
    __IO    uint32_t KEY2_VALID;        /*!< eFuse secure key valid register 2 */
    __IO    uint32_t KEY3_VALID;        /*!< eFuse secure key valid register 3 */
}efuse_reg_t;

/** @struct exti_reg_t
  * @brief External Interrupt/Event Controller structure definition
  */
typedef struct 
{
    __IO    uint32_t INTEN;             /*!< Interrupt enable register */
    __IO    uint32_t EVTEN;             /*!< Event enable register */
    __IO    uint32_t RTEN;              /*!< Rising edge trigger enable register */
    __IO    uint32_t FTEN;              /*!< Falling edge trigger enable register */
    __IO    uint32_t SWTIEN;            /*!< Software trigger interrupt/event enabe register */
    __IO    uint32_t PDF;               /*!< Pending flag register */
}exti_reg_t;


/** @struct fmc_reg_t
  * @brief FMC (FLASH Memory Control )Register structure definition
  */
typedef struct 
{
    __IO    uint32_t WCR;               /*!< FMC Wait control register */
    __IO    uint32_t CCODE;             /*!< FMC Control code register */
    __IO    uint32_t OBCCODE;           /*!< FMC Option Byte Control code register */
    __IO    uint32_t STS;               /*!< FMC status register */
    __IO    uint32_t CTR;               /*!< FMC Control register */
    __IO    uint32_t ERSADR;            /*!< Flash erase address register */
    __IO    uint32_t RESERVED;          /*!< Reserved */
    __IO    uint32_t OBSTS;             /*!< Option byte status register */
    __IO    uint32_t WPSTS;             /*!< Write protection status register */
    __IO    uint32_t CFG;               /*!< Config register */
    __IO    uint32_t CFGU;              /*!< Config register  */  
    __IO    uint32_t STS2;              /*!< FMC status register 2 */
    __O     uint32_t CRC32;             /*!< Flash CRC value */
}fmc_reg_t;

/** @struct  fwdt_reg_t 
  * @brief   FWDT Registers structure definition.
  */
typedef struct
{
    __IO    uint32_t CCODE;             /*!< FWDT control code register. */
    __IO    uint32_t PDIV;              /*!< FWDT pre-divider register. */
    __IO    uint32_t UVAL;              /*!< FWDT update register. */
    __IO    uint32_t STS;               /*!< FWDT status register. */
    __IO    uint32_t WINVAL;            /*!< FWDT window value register. */
}fwdt_reg_t;

/** @struct gpio_reg_t
  * @brief GPIO registers structure definition.
  */
typedef struct
{
    __IO    uint32_t PFR;               /*!< GPIO port function register. */
    __IO    uint32_t PODENR;            /*!< GPIO port output open-drain enable regiser. */
    __IO    uint32_t POSR;              /*!< GPIO port output speed register. */
    __IO    uint32_t PUPDR;             /*!< GPIO port pull-up/pull-down register. */
    __IO    uint32_t DI;                /*!< GPIO port data input register. */
    __IO    uint32_t DO;                /*!< GPIO port output data register. */
    __IO    uint32_t SCR;               /*!< GPIO port set/clear register. */
    __IO    uint32_t LOCK;              /*!< GPIO port lock register. */
    __IO    uint32_t MFSEL[2];          /*!< GPIO multi-function selection register. */
    __IO    uint32_t CLRR;              /*!< GPIO port clear register. */
}gpio_reg_t;

/** @struct  hdiv_reg_t 
  * @brief   HDIV registers structure definition.
  */
typedef struct
{
    __IO    uint32_t DIVIDEND0;         /*!< HDIV dividend source register0. */
    __IO    uint32_t DIVIDEND1;         /*!< HDIV dividend source register1. */
    __IO    uint32_t DIVISOR;           /*!< HDIV divisor source register. */
    __IO    uint32_t DIVQUO0;           /*!< HDIV quotient result register0. */
    __IO    uint32_t DIVQUO1;           /*!< HDIV quotient result register1. */
    __IO    uint32_t DIVREM;            /*!< HDIV remainder result register. */
    __IO    uint32_t DIVSTS;            /*!< HDIV divisor status register. */
}hdiv_reg_t;

/** @struct i2c_reg_t
  * @brief Inter-integrated Circuit Interface egisters structure definition
  */
typedef struct
{
    __IO    uint32_t CTR1;              /*!< I2C Control register 1 */
    __IO    uint32_t CTR2;              /*!< I2C Control register 2 */
    __IO    uint32_t SADR1;             /*!< I2C slave address 1 register */
    __IO    uint32_t SADR2;             /*!< I2C slave address 2 register */
    __IO    uint32_t TMR;               /*!< I2C Timing register */
    __IO    uint32_t OVRT;              /*!< I2C overtime register */
    __IO    uint32_t STS;               /*!< I2C status register */
    __IO    uint32_t STSC;              /*!< I2C status clear register */
    __IO    uint32_t PECCODE;           /*!< I2C received PEC code register */
    __IO    uint32_t RXBUF;             /*!< I2C Receive buffer register */
    __IO    uint32_t TXBUF;             /*!< I2C Transmit buffer register */
    __IO    uint32_t CTR3;              /*!< I2C Control register 3 */
    __IO    uint32_t STS1;              /*!< I2C status register 1 */
    __IO    uint32_t CTR4;              /*!< I2C Control register 4 */
}i2c_reg_t;

/** @struct lptim_reg_t
  * @brief LPTIM Registers structure definition
  */
typedef struct 
{
    __IO    uint32_t ISR;               /*!< LPTIM Interrupt and Status register */
    __IO    uint32_t ICR;               /*!< LPTIM Interrupt Clear register */
    __IO    uint32_t IER;               /*!< LPTIM Interrupt Enable register */
    __IO    uint32_t CFGR;              /*!< LPTIM Configuration register */
    __IO    uint32_t CR;                /*!< LPTIM Control register */
    __IO    uint32_t CMP;               /*!< LPTIM Compare register */
    __IO    uint32_t ARR;               /*!< LPTIM Autoreload register */
    __IO    uint32_t CNT;               /*!< LPTIM Counter register */
    __IO    uint32_t CFGR2;             /*!< LPTIM Configuration2 register */
    __IO    uint32_t RESERVED0;         /*!< Reserved */
    __IO    uint32_t RCR;               /*!< LPTIM repeat count register */
}lptim_reg_t;

/** @struct ob_reg_t
  * @brief Option Bytes Registers structure deinition
  */
typedef struct
{
    __IO uint16_t USERRDP1;             /*!< FLASH option byte user options 1 and read protection */
    __IO uint16_t USERRDP2;             /*!< FLASH option byte user options 1 and read protection */
    __IO uint16_t DATA0;                /*!< FLASH option byte user data 0*/
    __IO uint16_t DATA1;                /*!< FLASH option byte user data 1*/
    __IO uint16_t WPROTOB1;             /*!< FLASH option byte write protection 1 */
    __IO uint16_t WPROTOB2;             /*!< FLASH option byte write protection 2 */
    __IO uint16_t WPROTOB3;             /*!< FLASH option byte write protection 3 */
    __IO uint16_t WPROTOB4;             /*!< FLASH option byte write protection 4 */
    __IO uint16_t USER2_1;              /*!< FLASH option byte user options 2 */
    __IO uint16_t USER2_2;              /*!< FLASH option byte user options 2 */
}ob_reg_t;

/** @struct  pmu_reg_t 
  * @brief   PMU registers structure definition.
  */
typedef struct
{
    __IO    uint32_t CTR;               /*!< PMU control register. */
    __IO    uint32_t CS;                /*!< PMU control and status register. */
	__IO    uint32_t CTR2;              /*!< PMU control register2. */
	__IO    uint32_t CTR3;              /*!< PMU control register3. */
	__IO    uint32_t TS;                /*!< PMU temperature sending register. */
}pmu_reg_t;

/** @struct rcu_reg_t
  * @brief Reset and Clock Control Registers sructure definition
  */
typedef struct 
{
    __IO    uint32_t CTR;               /*!< clock control register */
    __IO    uint32_t CFG;               /*!< clock configuration register */
    __IO    uint32_t INTR;              /*!< clock interrupt register */
    __IO    uint32_t APB2RST;           /*!< APB2 peripheral reset register */
    __IO    uint32_t APB1RST;           /*!< APB1 peripheral reset register */
    __IO    uint32_t AHBEN;             /*!< AHB peripheral clock register */
    __IO    uint32_t APB2EN;            /*!< APB2 peripheral clock enable register */
    __IO    uint32_t APB1EN;            /*!< APB1 peripheral clock enable register */
    __IO    uint32_t VBDC;              /*!< VBAT domain control register */
    __IO    uint32_t STS;               /*!< status register */
    __IO    uint32_t AHBRST;            /*!< AHB  reset register */
    __IO    uint32_t RESERVED0;         /*!< Reserved */    
    __IO    uint32_t CFG3;              /*!< clock configuration register 3 */
}rcu_reg_t;

/** @struct rngck_reg_t
  * @brief RNGCK Registers structure definition
  */
typedef struct 
{
    __IO    uint32_t SEED;               /*!< Random seed register */
    __IO    uint32_t MODE;               /*!< Mode selection register */
    __IO    uint32_t IRQ;                /*!< Interrupt status register */
}rngck_reg_t;

/** @struct rtc_reg_t
  * @brief Real-Time Clock Registers structure definition
  */
typedef struct 
{
    __IO    uint32_t TIME;              /*!< RTC time register. */
    __IO    uint32_t DATE;              /*!< RTC date register. */
    __IO    uint32_t CTR;               /*!< RTC control register. */
    __IO    uint32_t STS;               /*!< RTC status register. */
    __IO    uint32_t PDIV;              /*!< RTC pre-divider register. */
    __IO    uint32_t WUTR;              /*!< RTC wakeup timer register. */
    __IO    uint32_t RESERVED0;         /*!< Reserved:(0x18 ~ 0x1b). */
    __IO    uint32_t ACFG1;             /*!< RTC alarm config1 register. */
    __IO    uint32_t RESERVED1;         /*!< Reserved. */
    __IO    uint32_t CCODE;             /*!< RTC control code registerr. */
    __IO    uint32_t SSEC;              /*!< RTC sub second register. */
	__IO    uint32_t RESERVED2;         /*!< Reserved:(0x2c ~ 0x2f). */
    __IO    uint32_t RESERVED3;         /*!< Reserved:(0x30 ~ 0x33). */
	__IO    uint32_t RESERVED4;         /*!< Reserved:(0x34 ~ 0x37). */
    __IO    uint32_t RESERVED5;         /*!< Reserved:(0x38 ~ 0x3b). */
	__IO    uint32_t RESERVED6;         /*!< Reserved:(0x3c ~ 0x3f). */
    __IO    uint32_t MF;                /*!< RTC multiplex function register. */
    __IO    uint32_t ACFG2;             /*!< RTC alarm config2 register. */
    __IO    uint32_t RESERVED7;         /*!< Reserved:(0x48 ~ 0x4b). */
    __IO    uint32_t RESERVED8;         /*!< Reserved:(0x4c ~ 0x4f). */
    __IO    uint32_t AO0;               /*!< RTC always on registers 0. */
    __IO    uint32_t AO1;               /*!< RTC always on registers 1. */
    __IO    uint32_t AO2;               /*!< RTC always on registers 2. */
    __IO    uint32_t AO3;               /*!< RTC always on registers 3. */
    __IO    uint32_t AO4;               /*!< RTC always on registers 4. */
}rtc_reg_t;

/** @struct spi_reg_t
  * @brief Serial peripheral interface registers structure definition
  */
typedef struct 
{
    __IO    uint16_t CTR1;              /*!< SPI control register 1. */
    __IO    uint16_t RESERVED0;         /*!< Reserved. */
    __IO    uint16_t CTR2;              /*!< SPI control register 2. */
    __IO    uint16_t RESERVED1;         /*!< Reserved. */
    __IO    uint16_t STS;               /*!< SPI status register. */
    __IO    uint16_t RESERVED2;         /*!< Reserved. */
    __IO    uint16_t DATA;              /*!< SPI data register. */
    __IO    uint16_t RESERVED3;         /*!< Reserved. */
    __IO    uint16_t CRCPOLYR;          /*!< SPI CRC polynomial register. */
    __IO    uint16_t RESERVED4;         /*!< Reserved. */
    __IO    uint16_t RCRC;              /*!< SPI rx CRC register. */
    __IO    uint16_t RESERVED5;         /*!< Reserved. */
    __IO    uint16_t TCRC;              /*!< SPI tx CRC register. */
    __IO    uint16_t RESERVED6;         /*!< Reserved. */
}spi_reg_t;

/** @struct syscfg_reg_t
  * @brief System config structure definition
  */
typedef struct 
{
    __IO    uint32_t RMAPCFG;           /*!< SYSCFG remap configuration. */
    __IO    uint16_t RAMBT;             /*!< SYSCFG ram boot configuration. */
	__IO    uint16_t RESERVED0;         /*!< Reserved. */
    __IO    uint32_t EXTISRC[4];        /*!< SYSCFG external interrupt source seection register. */
    __IO    uint32_t ERRLOCK;           /*!< SYSCFG error and timer break lock. */
    __IO    uint32_t GPIO_VTH;		    /*!< SYSCFG GPIOA Voltage configuration. */
    __IO    uint32_t TRNG;			    /*!< SYSCFG trng config register. */
    __IO    uint32_t AFE;			    /*!< SYSCFG bms register. */
}syscfg_reg_t;

/** @struct tim_reg_t
  * @brief TIM Registers structure definition
  */
typedef struct 
{
    __IO    uint32_t CTR1;              /*!< TIMx control register 1 */
    __IO    uint32_t CTR2;              /*!< TIMx control register 2 */
    __IO    uint32_t SMCFG;             /*!< TIMx slave mode configuration registr */
    __IO    uint32_t DIEN;              /*!< TIMx DMA and interrupt enable registr */
    __IO    uint32_t STS;               /*!< TIMx status register */
    __IO    uint32_t SWEGR;             /*!< TIMx software event generation regiser */
    __IO    uint32_t CHxCFGR[2];        /*!< TIMx channel 1~4 configuation register */
    __IO    uint32_t CCCTR;             /*!< TIMx channel capture compare controeister */
    __IO    uint32_t CNT;               /*!< TIMx counter register */
    __IO    uint32_t PDIV;              /*!< TIMx pre-divider register */
    __IO    uint32_t UVAL;              /*!< TIMx counter update register */
    __IO    uint32_t UVALREP;           /*!< TIMx counter update repetition regiser */
    __IO    uint32_t CHxCCVAL[4];       /*!< TIMx channel 1~4 capture compare value register */
    __IO    uint32_t CHOPR;             /*!< TIMx channel output protect register */
    __IO    uint32_t DMAACR;            /*!< TIMx DMA access configuration registr */
    __IO    uint32_t DMAIR;             /*!< TIMx DMA access interface register */
    __IO    uint32_t REMAP;             /*!< TIM14 remap register */
}tim_reg_t;

/** @struct usart_reg_t
  * @brief USART registers structure definition.
  */
typedef struct 
{
    __IO    uint32_t CTR1;              /*!< USART control register 1. */
    __IO    uint32_t CTR2;              /*!< USART control register 2. */
    __IO    uint32_t CTR3;              /*!< USART control register 3. */
    __IO    uint16_t BRT;               /*!< USART baud rate register. */
    __IO    uint16_t RESERVED0;         /*!< Reserved. */
    __IO    uint16_t GTPDIV;            /*!< Guard time and pre-divider register. */
    __IO    uint16_t RESERVED1;         /*!< Reserved. */
    __IO    uint32_t ROT;               /*!< Receiver timeout register. */
    __IO    uint16_t SWTR;              /*!< Software trigger register. */
    __IO    uint16_t RESERVED2;         /*!< Reserved. */
    __IO    uint32_t STS;               /*!< USART interrupt and status register. */
    __IO    uint32_t IFCLR;             /*!< USART interrupt flag clear register. */
    __IO    uint16_t RXBUF;             /*!< Receive buffer register. */
    __IO    uint16_t RESERVED3;         /*!< Reserved. */
    __IO    uint16_t TXBUF;             /*!< Transmit buffer register. */
    __IO    uint16_t RESERVED4;         /*!< Reserved. */
}usart_reg_t;

/** @struct wwdt_reg_t
  * @brief WWDT registers structure definition.
  */
typedef struct
{
    __IO    uint32_t CTR1;              /*!< WWDT control register 1. */
    __IO    uint32_t CTR2;              /*!< WWDT control register 2. */
    __IO    uint32_t STS;               /*!< WWDT status register. */
}wwdt_reg_t;

/**
  * @}
  */


/** @defgroup CBM858xM_Exported_Constants CBM858xM Exported Constants
  * @{
  */

/**
  * @brief the Internal High Speed oscillator HRC Startup Timeout value
  */
#if !defined  (HRC_STARTUP_TIMEOUT)
    #define HRC_STARTUP_TIMEOUT     ((uint16_t)05000)       /*!< Time out for HRC start u. */
#endif

/**
  * @brief the Internal High Speed oscillator HRC value
  */
#if !defined  (HRC_VALUE)
    #define HRC_VALUE_24M       ((uint32_t)24000000)     /*!< Value of the Internal igh Speed oscillator in 24Hz. */
    #define HRC_VALUE_32M       ((uint32_t)32000000)     /*!< Value of the Internal igh Speed oscillator in 32Hz. */
#endif

/**
  * @brief the Internal Low Speed oscillator LRC value
  */
#if !defined  (LRC_VALUE)
    #define LRC_VALUE           ((uint32_t)40000)       /*!< Value of the InternalLow Speed oscillator in Hz. */
#endif

/*! Check enable  definition */
#define FUNCTIONAL_STATE_CHECK(STATE)          (((STATE) == DISABLE) || ((STATE == ENABLE)))

/*! Register modify macro */
#define MODIFY_REG(REG, CLEARMASK, SETMASK)	    ((REG) = ((REG) & (~(CLEARMASK))) | (SETMASK))

/**
  * @}
  */

/** @addtogroup Peripheral_memory_map
  * @{
  */
#ifdef UNIT_TEST

#define FLASH_BASE              ((uint32_t)0x08000000)        /*!< FLASH base address in the alias region */
#define SRAM_BASE               ((uint32_t)0x20000000)        /*!< SRAM base address in the alias region */
#define PERIPH_BASE             ((uint32_t)0x20001000)        /*!< Peripheral base address in the alias region */
#define EFUSE_BASE              ((uint32_t)PERIPH_BASE+0x400)        /*!< eFuse-key base address */
#define OB_BASE                 (PERIPH_BASE  + 0x500)     /*!< FLASH option bytes base address */

#else

#define FLASH_BASE              ((uint32_t)0x08000000)        /*!< FLASH base address in the alias region */
#define SRAM_BASE               ((uint32_t)0x20000000)        /*!< SRAM base address in the alias region */
#define PERIPH_BASE             ((uint32_t)0x40000000)        /*!< Peripheral base address in the alias region */
#define EFUSE_BASE              ((uint32_t)0x1F001E00)        /*!< eFuse-key base address */
#define OB_BASE                 ((uint32_t)0x1FFFF800)        /*!< FLASH option bytes base address */



/**
  * @brief Peripheral memory map definition 
*/
#define APB_PERIPH_BASE         PERIPH_BASE                         /*!< APB peripheral base address */
#define AHB_PERIPH_BASE         (PERIPH_BASE      + 0x00020000)     /*!< AHB peripheral base address */

#define TIM3_BASE               (APB_PERIPH_BASE  + 0x00000400)     /*!< TIM3 register base address */
#define TIM14_BASE              (APB_PERIPH_BASE  + 0x00002000)     /*!< TIM14 register base address */
#define RTC_BASE                (APB_PERIPH_BASE  + 0x00002800)     /*!< RTC register base address */
#define WWDT_BASE               (APB_PERIPH_BASE  + 0x00002C00)     /*!< WWDT register base address */
#define FWDT_BASE               (APB_PERIPH_BASE  + 0x00003000)     /*!< FWDT register base address */
#define SPI2_BASE               (APB_PERIPH_BASE  + 0x00003800)     /*!< SPI2 register base address */
#define USART2_BASE             (APB_PERIPH_BASE  + 0x00004400)     /*!< USART2 register base address */
#define I2C1_BASE               (APB_PERIPH_BASE  + 0x00005400)     /*!< I2C1 register base address */
#define PMU_BASE                (APB_PERIPH_BASE  + 0x00007000)     /*!< PMU register base address */
#define LPTIM_BASE              (APB_PERIPH_BASE  + 0x00007C00)     /*!< LPTIM register base address */
#define SYSCFG_BASE             (APB_PERIPH_BASE  + 0x00010000)     /*!< SYSCFG register base address */
#define EXTI_BASE               (APB_PERIPH_BASE  + 0x00010400)     /*!< EXTI register base address */
#define TIM1_BASE               (APB_PERIPH_BASE  + 0x00012C00)     /*!< TIM1 register base address */
#define SPI1_BASE               (APB_PERIPH_BASE  + 0x00013000)     /*!< SPI1 register base address */
#define USART1_BASE             (APB_PERIPH_BASE  + 0x00013800)     /*!< USART1 register base address */
#define RNGCK_BASE              (APB_PERIPH_BASE  + 0x00015000)     /*!< RNGCK register base address */
#define ACTS_BASE               (APB_PERIPH_BASE  + 0x00015400)     /*!< Active Shield register base address */

#define DMA1_BASE               (AHB_PERIPH_BASE  + 0x00000000)     /*!< DMA1 register base address */
#define DMA1_CHANNEL1_BASE      (DMA1_BASE        + 0x00000008)     /*!< DMA1 channel1 register base address */
#define DMA1_CHANNEL2_BASE      (DMA1_BASE        + 0x0000001C)     /*!< DMA1 channel2 register base address */
#define DMA1_CHANNEL3_BASE      (DMA1_BASE        + 0x00000030)     /*!< DMA1 channel3 register base address */
#define DMA1_CHANNEL4_BASE      (DMA1_BASE        + 0x00000044)     /*!< DMA1 channel4 register base address */
#define DMA1_CHANNEL5_BASE      (DMA1_BASE        + 0x00000058)     /*!< DMA1 channel5 register base address */

#define RCU_BASE                (AHB_PERIPH_BASE  + 0x00001000)     /*!< RCU register base address */
#define FMC_BASE                (AHB_PERIPH_BASE  + 0x00002000)     /*!< FMC register base address */
#define CRC_BASE                (AHB_PERIPH_BASE  + 0x00003000)     /*!< CRC register base address */
#define HDIV_BASE               (AHB_PERIPH_BASE  + 0x00003400)     /*!< HDIV register base address */

#define GPIOA_BASE              (PERIPH_BASE      + 0x08000000)     /*!< GPIOA register base address */

#endif /*UNIT_TEST*/
/**
  * @}
  */

/** @addtogroup Peripheral_declaration
  * @{
  */
#define TIM3                    ((tim_reg_t *)          TIM3_BASE)     /*!< TIM3 module base address. */ 
#define TIM14                   ((tim_reg_t *)          TIM14_BASE)    /*!< TIM14 module base address. */  
#define I2C1                    ((i2c_reg_t *)          I2C1_BASE)     /*!< I2C1 module base address. */ 
#define LPTIM                   ((lptim_reg_t *)        LPTIM_BASE)    /*!< LPTIM module base address. */  
#define EXTI                    ((exti_reg_t *)         EXTI_BASE)     /*!< EXTI module base address. */  
#define TIM1                    ((tim_reg_t *)          TIM1_BASE)     /*!< TIM1 module base address. */ 
#define RNGCK                   ((rngck_reg_t *)        RNGCK_BASE)    /*!< RNGCK module base address. */ 
#define ACTS                    ((acts_reg_t *)         ACTS_BASE)    /*!< Active shield module base address. */ 

#define DMA1                    ((dma_reg_t *)          DMA1_BASE)          /*!< DMA1 module base address. */  
#define DMA1_CHANNEL1           ((dma_channel_reg_t *)  DMA1_CHANNEL1_BASE) /*!< DMA1 channel1 module base address. */
#define DMA1_CHANNEL2           ((dma_channel_reg_t *)  DMA1_CHANNEL2_BASE) /*!< DMA1 channel2 module base address. */
#define DMA1_CHANNEL3           ((dma_channel_reg_t *)  DMA1_CHANNEL3_BASE) /*!< DMA1 channel3 module base address. */
#define DMA1_CHANNEL4           ((dma_channel_reg_t *)  DMA1_CHANNEL4_BASE) /*!< DMA1 channel4 module base address. */
#define DMA1_CHANNEL5           ((dma_channel_reg_t *)  DMA1_CHANNEL5_BASE) /*!< DMA1 channel5 module base address. */

#define RCU                     ((rcu_reg_t *)          RCU_BASE)      /*!< RCU module base address. */ 
#define OB                      ((ob_reg_t *)           OB_BASE)       /*!< OB module base address. */   
#define EFUSE                   ((efuse_reg_t *)        EFUSE_BASE)    /*!< EFUSE module base address. */  
#define FLASH                   ((fmc_reg_t *)          FMC_BASE)      /*!< FMC module base address. */  
#define RTC                     ((rtc_reg_t *)          RTC_BASE)      /*!< RTC module base address. */
#define WWDT                    ((wwdt_reg_t *)         WWDT_BASE)     /*!< WWDT module base address. */
#define FWDT                    ((fwdt_reg_t *)         FWDT_BASE)     /*!< FWDT module base address. */
#define SPI2                    ((spi_reg_t *)          SPI2_BASE)     /*!< SPI2 module base address. */
#define USART2                  ((usart_reg_t *)        USART2_BASE)   /*!< USART2 module base address. */
#define PMU                     ((pmu_reg_t *)          PMU_BASE)      /*!< PMU module base address. */
#define SYSCFG                  ((syscfg_reg_t *)       SYSCFG_BASE)   /*!< SYSCFG module base address. */
#define SPI1                    ((spi_reg_t *)          SPI1_BASE)     /*!< SPI1 module base address. */
#define USART1                  ((usart_reg_t *)        USART1_BASE)   /*!< USART1 module base address. */
#define CRC                     ((crc_reg_t *)          CRC_BASE)      /*!< CRC module base address. */
#define HDIV                    ((hdiv_reg_t *)         HDIV_BASE)     /*!< HDIV module base address. */
#define GPIOA                   ((gpio_reg_t *)         GPIOA_BASE)    /*!< GPIOA module base address. */
/**
  * @}
  */

/** @addtogroup Peripheral_Registers_Bits_Deinition
  * @{
  */

/*------------------------------------------ --------------------------------*/
/*                         Active shield unit(ACTS)                        */
/*------------------------------------------ --------------------------------*/
/**
  * @brief Active shield register Bit definition
  */
#define ACTS_WAIT_TIME                  ((uint32_t)0x0000FFFF)      /*!< Waiting time before excitation signal comparison register bits. */
#define ACTS_COMP_TIME                  ((uint32_t)0xFFFF0000)      /*!< Number of excitation signal comparison. */
#define ACTS_MIS_THLD                   ((uint32_t)0x0000FFFF)      /*!< threshold value of excitation signal comparison failure register bits. */

#define ACTS_CTR0_EN                    ((uint32_t)0x00000001)      /*!< Active shield enable register bits. */

/*------------------------------------------ --------------------------------*/
/*                         CRC calculation unit (CRC)                        */
/*------------------------------------------ --------------------------------*/

/**
  * @brief CRC_DATA register Bit definition
  */
#define CRC_DATA_DATA                		((uint32_t)0xFFFFFFFF)      /*!< Data register bits. */

/**
  * @brief CRC_FREDATA register Bit definition
  */
#define CRC_FREDATA_FREDATA          		((uint32_t)0x000000FF)      /*!< Free data register bits. */

/**
  * @brief CRC_CTR register Bit definition
  */
#define CRC_CTR_RST                  		((uint32_t)0x00000001)      /*!< RESET the CRC computation unit bit. */
#define CRC_CTR_DINREVMOD            		((uint32_t)0x00000060)      /*!< Input data reverse mode selection. */
#define CRC_CTR_DINREVMOD_0          		((uint32_t)0x00000020)      /*!< Bit 0. */
#define CRC_CTR_DINREVMOD_1          		((uint32_t)0x00000040)      /*!< Bit 1. */
#define CRC_CTR_DOREVEN              		((uint32_t)0x00000080)      /*!< Output ata reverse enable. */

/**
  * @brief CRC_INITCFG register Bit definition
  */
#define CRC_INITCFG_INITCFG          		((uint32_t)0xFFFFFFFF)      /*!< CRC iniial value configuration bits. */

/**
  * @brief CRC_POL register Bit definition
  */
#define CRC_POL_POL                  		((uint32_t)0xFFFFFFFF)      /*!< CRC polynomial value bits. */

/*--------------------------------------------------------------------------*/
/*              DMA Controller (DMA)                                        */
/*--------------------------------------------------------------------------*/

/**
  * @brief DMA_STS register Bit definition
  */
#define DMA_STS_GIF1                        ((uint32_t)0x00000001)     /*!< lobal interrupt flag of Channel 1 */
#define DMA_STS_CMPIF1                      ((uint32_t)0x00000002)     /*!< ransfer complete flag of Channel 1 */
#define DMA_STS_HLFIF1                      ((uint32_t)0x00000004)     /*!< alf transfer flag of Channel 1 */
#define DMA_STS_ERRIF1                      ((uint32_t)0x00000008)     /*!< ransfer error flag of Channel 1 */

#define DMA_STS_GIF2                        ((uint32_t)0x00000010)     /*!< lobal interrupt flag of Channel 2 */
#define DMA_STS_CMPIF2                      ((uint32_t)0x00000020)     /*!< ransfer complete flag of Channel 2 */
#define DMA_STS_HLFIF2                      ((uint32_t)0x00000040)     /*!< alf transfer flag of Channel 2 */
#define DMA_STS_ERRIF2                      ((uint32_t)0x00000080)     /*!< ransfer error flag of Channel 2 */

#define DMA_STS_GIF3                        ((uint32_t)0x00000100)     /*!< lobal interrupt flag of Channel 3 */
#define DMA_STS_CMPIF3                      ((uint32_t)0x00000200)     /*!< ransfer complete flag of Channel 3 */
#define DMA_STS_HLFIF3                      ((uint32_t)0x00000400)     /*!< alf transfer flag of Channel 3 */
#define DMA_STS_ERRIF3                      ((uint32_t)0x00000800)     /*!< ransfer error flag of Channel 3 */

#define DMA_STS_GIF4                        ((uint32_t)0x00001000)     /*!< lobal interrupt flag of Channel 4 */
#define DMA_STS_CMPIF4                      ((uint32_t)0x00002000)     /*!< ransfer complete flag of Channel 4 */
#define DMA_STS_HLFIF4                      ((uint32_t)0x00004000)     /*!< alf transfer flag of Channel 4 */
#define DMA_STS_ERRIF4                      ((uint32_t)0x00008000)     /*!< ransfer error flag of Channel 4 */

#define DMA_STS_GIF5                        ((uint32_t)0x00010000)     /*!< lobal interrupt flag of Channel 5 */
#define DMA_STS_CMPIF5                      ((uint32_t)0x00020000)     /*!< ransfer complete flag of Channel 5 */
#define DMA_STS_HLFIF5                      ((uint32_t)0x00040000)     /*!< alf transfer flag of Channel 5 */
#define DMA_STS_ERRIF5                      ((uint32_t)0x00080000)     /*!< ransfer error flag of Channel 5 */

/**
  * @brief DMA_INTFC register  Bit definition
  */
#define DMA_INTFC_GIFC1                     ((uint32_t)0x00000001)     /*!< Global interrupt flag clear of Channel 1 */
#define DMA_INTFC_CMPIFC1                   ((uint32_t)0x00000002)     /*!< Transfer complete flag clear of Channe 1 */
#define DMA_INTFC_HLFIFC1                   ((uint32_t)0x00000004)     /*!< Half transfer flag clear of Channel 1 */
#define DMA_INTFC_ERRIFC1                   ((uint32_t)0x00000008)     /*!< Transfer error flag clear of Channel 1 */

#define DMA_INTFC_GIFC2                     ((uint32_t)0x00000010)     /*!< Global interrupt flag clear of Channel 2 */
#define DMA_INTFC_CMPIFC2                   ((uint32_t)0x00000020)     /*!< Transfer complete flag clear of Channe 2 */
#define DMA_INTFC_HLFIFC2                   ((uint32_t)0x00000040)     /*!< Half transfer flag clear of Channel 2 */
#define DMA_INTFC_ERRIFC2                   ((uint32_t)0x00000080)     /*!< Transfer error flag clear of Channel 2 */

#define DMA_INTFC_GIFC3                     ((uint32_t)0x00000100)     /*!< Global interrupt flag clear of Channel 3 */
#define DMA_INTFC_CMPIFC3                   ((uint32_t)0x00000200)     /*!< Transfer complete flag clear of Channe 3 */
#define DMA_INTFC_HLFIFC3                   ((uint32_t)0x00000400)     /*!< Half transfer flag clear of Channel 3 */
#define DMA_INTFC_ERRIFC3                   ((uint32_t)0x00000800)     /*!< Transfer error flag clear of Channel 3 */

#define DMA_INTFC_GIFC4                     ((uint32_t)0x00001000)     /*!< Global interrupt flag clear of Channel 4 */
#define DMA_INTFC_CMPIFC4                   ((uint32_t)0x00002000)     /*!< Transfer complete flag clear of Channe 4 */
#define DMA_INTFC_HLFIFC4                   ((uint32_t)0x00004000)     /*!< Half transfer flag clear of Channel 4 */
#define DMA_INTFC_ERRIFC4                   ((uint32_t)0x00008000)     /*!< Transfer error flag clear of Channel 4 */

#define DMA_INTFC_GIFC5                     ((uint32_t)0x00010000)     /*!< Global interrupt flag clear of Channel 5 */
#define DMA_INTFC_CMPIFC5                   ((uint32_t)0x00020000)     /*!< Transfer complete flag clear of Channe 5 */
#define DMA_INTFC_HLFIFC5                   ((uint32_t)0x00040000)     /*!< Half transfer flag clear of Channel 5 */
#define DMA_INTFC_ERRIFC5                   ((uint32_t)0x00080000)     /*!< Transfer error flag clear of Channel 5 */

/**
  * @brief DMA_CHxCTR register Bit definition
  */
#define DMA_CHxCTR_CEN                      ((uint32_t)0x00000001)     /*!< Channel enable */
#define DMA_CHxCTR_CMPIE                    ((uint32_t)0x00000002)     /*!< Enable bit for Transfer complete interrupt */
#define DMA_CHxCTR_HLFIE                    ((uint32_t)0x00000004)     /*!< Enable bit for Half transfer interrupt */
#define DMA_CHxCTR_ERRIE                    ((uint32_t)0x00000008)     /*!< Enable bit for Transfer error interrupt */
#define DMA_CHxCTR_DIR                      ((uint32_t)0x00000010)     /*!< Direction of transfer */
#define DMA_CHxCTR_CIRM                     ((uint32_t)0x00000020)     /*!< Circular mode */
#define DMA_CHxCTR_PAGM                     ((uint32_t)0x00000040)     /*!< Peripheral address generation mode */
#define DMA_CHxCTR_MAGM                     ((uint32_t)0x00000080)     /*!< Memory address generation mode */

#define DMA_CHxCTR_PWDH                     ((uint32_t)0x00000300)     /*!< Peripheral width PWDH[1:0] bits */
#define DMA_CHxCTR_PWDH_0                   ((uint32_t)0x00000100)     /*!< Bit 0 */
#define DMA_CHxCTR_PWDH_1                   ((uint32_t)0x00000200)     /*!< Bit 1 */

#define DMA_CHxCTR_MWDH                     ((uint32_t)0x00000C00)     /*!< Memory width MWDH[1:0] bits */
#define DMA_CHxCTR_MWDH_0                   ((uint32_t)0x00000400)     /*!< Bit 0 */
#define DMA_CHxCTR_MWDH_1                   ((uint32_t)0x00000800)     /*!< Bit 1 */

#define DMA_CHxCTR_PRIL                     ((uint32_t)0x00003000)     /*!< Priority level of Channel PRIL[1:0]bits */
#define DMA_CHxCTR_PRIL_0                   ((uint32_t)0x00001000)     /*!< Bit 0 */
#define DMA_CHxCTR_PRIL_1                   ((uint32_t)0x00002000)     /*!< Bit 1 */

#define DMA_CHxCTR_M2MM                     ((uint32_t)0x00004000)     /*!< Memory to memory mode */

/**
  * @brief DMA_CHxNUM register Bit definition
  */
#define DMA_CHxNUM_NUM                      ((uint32_t)0x0000FFFF)     /*!< Number of data to Transfer */

/**
  * @brief DMA_CHxPA register Bit definition
  */
#define DMA_CHxPA_PADR                      ((uint32_t)0xFFFFFFFF)     /*!< Peripheral Address */

/**
  * @brief DMA_CHxMA register Bit definition
  */
#define DMA_CHxMA_MADR                      ((uint32_t)0xFFFFFFFF)     /*!< Memory Address */

/*---------------------------------------------------------------------------*/
/*          External Interrupt/Event Controler (EXTI)                        */
/*---------------------------------------------------------------------------*/

/**
  * @brief EXTI_INTEN register Bit definition
  */
#define EXTI_INTEN_INTEN0                  ((uint32_t)0x00000001)        /*!< Interrupt enable for line0 */
#define EXTI_INTEN_INTEN1                  ((uint32_t)0x00000002)        /*!< Interrupt enable for line1 */
#define EXTI_INTEN_INTEN2                  ((uint32_t)0x00000004)        /*!< Interrupt enable for line2 */
#define EXTI_INTEN_INTEN3                  ((uint32_t)0x00000008)        /*!< Interrupt enable for line3 */
#define EXTI_INTEN_INTEN4                  ((uint32_t)0x00000010)        /*!< Interrupt enable for line4 */
#define EXTI_INTEN_INTEN5                  ((uint32_t)0x00000020)        /*!< Interrupt enable for line5 */
#define EXTI_INTEN_INTEN6                  ((uint32_t)0x00000040)        /*!< Interrupt enable for line6 */
#define EXTI_INTEN_INTEN7                  ((uint32_t)0x00000080)        /*!< Interrupt enable for line7 */
#define EXTI_INTEN_INTEN8                  ((uint32_t)0x00000100)        /*!< Interrupt enable for line8 */
#define EXTI_INTEN_INTEN9                  ((uint32_t)0x00000200)        /*!< Interrupt enable for line9 */
#define EXTI_INTEN_INTEN10                 ((uint32_t)0x00000400)        /*!< Interrupt enable for line10 */
#define EXTI_INTEN_INTEN11                 ((uint32_t)0x00000800)        /*!< Interrupt enable for line11 */
#define EXTI_INTEN_INTEN12                 ((uint32_t)0x00001000)        /*!< Interrupt enable for line12 */
#define EXTI_INTEN_INTEN13                 ((uint32_t)0x00002000)        /*!< Interrupt enable for line13 */
#define EXTI_INTEN_INTEN14                 ((uint32_t)0x00004000)        /*!< Interrupt enable for line14 */
#define EXTI_INTEN_INTEN15                 ((uint32_t)0x00008000)        /*!< Interrupt enable for line15 */
#define EXTI_INTEN_INTEN16                 ((uint32_t)0x00010000)        /*!< Interrupt enable for line16 */
#define EXTI_INTEN_INTEN17                 ((uint32_t)0x00020000)        /*!< Interrupt enable for line17 */
#define EXTI_INTEN_INTEN18                 ((uint32_t)0x00040000)        /*!< Interrupt enable for line18 */
#define EXTI_INTEN_INTEN19                 ((uint32_t)0x00080000)        /*!< Interrupt enable for line19 */
#define EXTI_INTEN_INTEN20                 ((uint32_t)0x00100000)        /*!< Interrupt enable for line20 */
#define EXTI_INTEN_INTEN21                 ((uint32_t)0x00200000)        /*!< Interrupt enable for line21 */
#define EXTI_INTEN_INTEN22                 ((uint32_t)0x00400000)        /*!< Interrupt enable for line22 */
#define EXTI_INTEN_INTEN23                 ((uint32_t)0x00800000)        /*!< Interrupt enable for line23 */
#define EXTI_INTEN_INTEN24                 ((uint32_t)0x01000000)        /*!< Interrupt enable for line24 */
#define EXTI_INTEN_INTEN25                 ((uint32_t)0x02000000)        /*!< Interrupt enable for line25 */
#define EXTI_INTEN_INTEN26                 ((uint32_t)0x04000000)        /*!< Interrupt enable for line26 */
#define EXTI_INTEN_INTEN27                 ((uint32_t)0x08000000)        /*!< Interrupt enable for line27 */
#define EXTI_INTEN_INTEN28                 ((uint32_t)0x10000000)        /*!< Interrupt enable for line28 */
#define EXTI_INTEN_INTEN29                 ((uint32_t)0x20000000)        /*!< Interrupt enable for line29 */
#define EXTI_INTEN_INTEN30                 ((uint32_t)0x40000000)        /*!< Interrupt enable for line30 */
#define EXTI_INTEN_INTEN31                 ((uint32_t)0x80000000)        /*!< Interrupt enable for line31 */

/**
  * @brief EXTI_EVTEN register Bit definition
  */
#define EXTI_EVTEN_EVTEN0                  ((uint32_t)0x00000001)        /*!< Event enable for line0 */
#define EXTI_EVTEN_EVTEN1                  ((uint32_t)0x00000002)        /*!< Event enable for line1 */
#define EXTI_EVTEN_EVTEN2                  ((uint32_t)0x00000004)        /*!< Event enable for line2 */
#define EXTI_EVTEN_EVTEN3                  ((uint32_t)0x00000008)        /*!< Event enable for line3 */
#define EXTI_EVTEN_EVTEN4                  ((uint32_t)0x00000010)        /*!< Event enable for line4 */
#define EXTI_EVTEN_EVTEN5                  ((uint32_t)0x00000020)        /*!< Event enable for line5 */
#define EXTI_EVTEN_EVTEN6                  ((uint32_t)0x00000040)        /*!< Event enable for line6 */
#define EXTI_EVTEN_EVTEN7                  ((uint32_t)0x00000080)        /*!< Event enable for line7 */
#define EXTI_EVTEN_EVTEN8                  ((uint32_t)0x00000100)        /*!< Event enable for line8 */
#define EXTI_EVTEN_EVTEN9                  ((uint32_t)0x00000200)        /*!< Event enable for line9 */
#define EXTI_EVTEN_EVTEN10                 ((uint32_t)0x00000400)        /*!< Event enable for line10 */
#define EXTI_EVTEN_EVTEN11                 ((uint32_t)0x00000800)        /*!< Event enable for line11 */
#define EXTI_EVTEN_EVTEN12                 ((uint32_t)0x00001000)        /*!< Event enable for line12 */
#define EXTI_EVTEN_EVTEN13                 ((uint32_t)0x00002000)        /*!< Event enable for line13 */
#define EXTI_EVTEN_EVTEN14                 ((uint32_t)0x00004000)        /*!< Event enable for line14 */
#define EXTI_EVTEN_EVTEN15                 ((uint32_t)0x00008000)        /*!< Event enable for line15 */
#define EXTI_EVTEN_EVTEN16                 ((uint32_t)0x00010000)        /*!< Event enable for line16 */
#define EXTI_EVTEN_EVTEN17                 ((uint32_t)0x00020000)        /*!< Event enable for line17 */
#define EXTI_EVTEN_EVTEN18                 ((uint32_t)0x00040000)        /*!< Event enable for line18 */
#define EXTI_EVTEN_EVTEN19                 ((uint32_t)0x00080000)        /*!< Event enable for line19 */
#define EXTI_EVTEN_EVTEN20                 ((uint32_t)0x00100000)        /*!< Event enable for line20 */
#define EXTI_EVTEN_EVTEN21                 ((uint32_t)0x00200000)        /*!< Event enable for line21 */
#define EXTI_EVTEN_EVTEN22                 ((uint32_t)0x00400000)        /*!< Event enable for line22 */
#define EXTI_EVTEN_EVTEN23                 ((uint32_t)0x00800000)        /*!< Event enable for line23 */
#define EXTI_EVTEN_EVTEN24                 ((uint32_t)0x01000000)        /*!< Event enable for line24 */
#define EXTI_EVTEN_EVTEN25                 ((uint32_t)0x02000000)        /*!< Event enable for line25 */
#define EXTI_EVTEN_EVTEN26                 ((uint32_t)0x04000000)        /*!< Event enable for line26 */
#define EXTI_EVTEN_EVTEN27                 ((uint32_t)0x08000000)        /*!< Event enable for line27 */
#define EXTI_EVTEN_EVTEN28                 ((uint32_t)0x10000000)        /*!< Event enable for line28 */
#define EXTI_EVTEN_EVTEN29                 ((uint32_t)0x20000000)        /*!< Event enable for line29 */
#define EXTI_EVTEN_EVTEN30                 ((uint32_t)0x40000000)        /*!< Event enable for line30 */
#define EXTI_EVTEN_EVTEN31                 ((uint32_t)0x80000000)        /*!< Event enable for line31 */

/**
  * @brief  EXTI_RTEN register Bit definition
  */
#define EXTI_RTEN_RTEN0                    ((uint32_t)0x00000001)        /*!< Rising edge trigger enable for line0 */
#define EXTI_RTEN_RTEN1                    ((uint32_t)0x00000002)        /*!< Rising edge trigger enable for line1 */
#define EXTI_RTEN_RTEN2                    ((uint32_t)0x00000004)        /*!< Rising edge trigger enable for line2 */
#define EXTI_RTEN_RTEN3                    ((uint32_t)0x00000008)        /*!< Rising edge trigger enable for line3 */
#define EXTI_RTEN_RTEN4                    ((uint32_t)0x00000010)        /*!< Rising edge trigger enable for line4 */
#define EXTI_RTEN_RTEN5                    ((uint32_t)0x00000020)        /*!< Rising edge trigger enable for line5 */
#define EXTI_RTEN_RTEN6                    ((uint32_t)0x00000040)        /*!< Rising edge trigger enable for line6 */
#define EXTI_RTEN_RTEN7                    ((uint32_t)0x00000080)        /*!< Rising edge trigger enable for line7 */
#define EXTI_RTEN_RTEN8                    ((uint32_t)0x00000100)        /*!< Rising edge trigger enable for line8 */
#define EXTI_RTEN_RTEN9                    ((uint32_t)0x00000200)        /*!< Rising edge trigger enable for line9 */
#define EXTI_RTEN_RTEN10                   ((uint32_t)0x00000400)        /*!< Rising edge trigger enable for line10 */
#define EXTI_RTEN_RTEN11                   ((uint32_t)0x00000800)        /*!< Rising edge trigger enable for line11 */
#define EXTI_RTEN_RTEN12                   ((uint32_t)0x00001000)        /*!< Rising edge trigger enable for line12 */
#define EXTI_RTEN_RTEN13                   ((uint32_t)0x00002000)        /*!< Rising edge trigger enable for line13 */
#define EXTI_RTEN_RTEN14                   ((uint32_t)0x00004000)        /*!< Rising edge trigger enable for line14 */
#define EXTI_RTEN_RTEN15                   ((uint32_t)0x00008000)        /*!< Rising edge trigger enable for line15 */
#define EXTI_RTEN_RTEN16                   ((uint32_t)0x00010000)        /*!< Rising edge trigger enable for line16 */
#define EXTI_RTEN_RTEN17                   ((uint32_t)0x00020000)        /*!< Rising edge trigger enable for line17 */
#define EXTI_RTEN_RTEN18                   ((uint32_t)0x00040000)        /*!< Rising edge trigger enable for line18 */
#define EXTI_RTEN_RTEN19                   ((uint32_t)0x00080000)        /*!< Rising edge trigger enable for line19 */
#define EXTI_RTEN_RTEN20                   ((uint32_t)0x00100000)        /*!< Rising edge trigger enable for line20 */
#define EXTI_RTEN_RTEN21                   ((uint32_t)0x00200000)        /*!< Rising edge trigger enable for line21 */
#define EXTI_RTEN_RTEN22                   ((uint32_t)0x00400000)        /*!< Rising edge trigger enable for line22 */
#define EXTI_RTEN_RTEN23                   ((uint32_t)0x00800000)        /*!< Rising edge trigger enable for line23 */
#define EXTI_RTEN_RTEN24                   ((uint32_t)0x01000000)        /*!< Rising edge trigger enable for line24 */
#define EXTI_RTEN_RTEN25                   ((uint32_t)0x02000000)        /*!< Rising edge trigger enable for line25 */
#define EXTI_RTEN_RTEN26                   ((uint32_t)0x04000000)        /*!< Rising edge trigger enable for line26 */
#define EXTI_RTEN_RTEN27                   ((uint32_t)0x08000000)        /*!< Rising edge trigger enable for line27 */
#define EXTI_RTEN_RTEN28                   ((uint32_t)0x10000000)        /*!< Rising edge trigger enable for line28 */
#define EXTI_RTEN_RTEN29                   ((uint32_t)0x20000000)        /*!< Rising edge trigger enable for line29 */
#define EXTI_RTEN_RTEN30                   ((uint32_t)0x40000000)        /*!< Rising edge trigger enable for line30 */
#define EXTI_RTEN_RTEN31                   ((uint32_t)0x80000000)        /*!< Rising edge trigger enable for line31 */

/**
  * @brief EXTI_FTEN register Bit definition
  */
#define EXTI_FTEN_FTEN0                    ((uint32_t)0x00000001)        /*!< Falling edge trigger enable for line0 */
#define EXTI_FTEN_FTEN1                    ((uint32_t)0x00000002)        /*!< Falling edge trigger enable for line1 */
#define EXTI_FTEN_FTEN2                    ((uint32_t)0x00000004)        /*!< Falling edge trigger enable for line2 */
#define EXTI_FTEN_FTEN3                    ((uint32_t)0x00000008)        /*!< Falling edge trigger enable for line3 */
#define EXTI_FTEN_FTEN4                    ((uint32_t)0x00000010)        /*!< Falling edge trigger enable for line4 */
#define EXTI_FTEN_FTEN5                    ((uint32_t)0x00000020)        /*!< Falling edge trigger enable for line5 */
#define EXTI_FTEN_FTEN6                    ((uint32_t)0x00000040)        /*!< Falling edge trigger enable for line6 */
#define EXTI_FTEN_FTEN7                    ((uint32_t)0x00000080)        /*!< Falling edge trigger enable for line7 */
#define EXTI_FTEN_FTEN8                    ((uint32_t)0x00000100)        /*!< Falling edge trigger enable for line8 */
#define EXTI_FTEN_FTEN9                    ((uint32_t)0x00000200)        /*!< Falling edge trigger enable for line9 */
#define EXTI_FTEN_FTEN10                   ((uint32_t)0x00000400)        /*!< Falling edge trigger enable for line10 */
#define EXTI_FTEN_FTEN11                   ((uint32_t)0x00000800)        /*!< Falling edge trigger enable for line11 */
#define EXTI_FTEN_FTEN12                   ((uint32_t)0x00001000)        /*!< Falling edge trigger enable for line12 */
#define EXTI_FTEN_FTEN13                   ((uint32_t)0x00002000)        /*!< Falling edge trigger enable for line13 */
#define EXTI_FTEN_FTEN14                   ((uint32_t)0x00004000)        /*!< Falling edge trigger enable for line14 */
#define EXTI_FTEN_FTEN15                   ((uint32_t)0x00008000)        /*!< Falling edge trigger enable for line15 */
#define EXTI_FTEN_FTEN16                   ((uint32_t)0x00010000)        /*!< Falling edge trigger enable for line16 */
#define EXTI_FTEN_FTEN17                   ((uint32_t)0x00020000)        /*!< Falling edge trigger enable for line17 */
#define EXTI_FTEN_FTEN18                   ((uint32_t)0x00040000)        /*!< Falling edge trigger enable for line18 */
#define EXTI_FTEN_FTEN19                   ((uint32_t)0x00080000)        /*!< Falling edge trigger enable for line19 */
#define EXTI_FTEN_FTEN20                   ((uint32_t)0x00100000)        /*!< Falling edge trigger enable for line20 */
#define EXTI_FTEN_FTEN21                   ((uint32_t)0x00200000)        /*!< Falling edge trigger enable for line21 */
#define EXTI_FTEN_FTEN22                   ((uint32_t)0x00400000)        /*!< Falling edge trigger enable for line22 */
#define EXTI_FTEN_RTEN23                   ((uint32_t)0x00800000)        /*!< Falling edge trigger enable for line23 */
#define EXTI_FTEN_RTEN24                   ((uint32_t)0x01000000)        /*!< Falling edge trigger enable for line24 */
#define EXTI_FTEN_RTEN25                   ((uint32_t)0x02000000)        /*!< Falling edge trigger enable for line25 */
#define EXTI_FTEN_RTEN26                   ((uint32_t)0x04000000)        /*!< Falling edge trigger enable for line26 */
#define EXTI_FTEN_RTEN27                   ((uint32_t)0x08000000)        /*!< Falling edge trigger enable for line27 */
#define EXTI_FTEN_RTEN28                   ((uint32_t)0x10000000)        /*!< Falling edge trigger enable for line28 */
#define EXTI_FTEN_RTEN29                   ((uint32_t)0x20000000)        /*!< Falling edge trigger enable for line29 */
#define EXTI_FTEN_RTEN30                   ((uint32_t)0x40000000)        /*!< Falling edge trigger enable for line30 */
#define EXTI_FTEN_FTEN31                   ((uint32_t)0x80000000)        /*!< Falling edge trigger enable for line31 */

/**
  * @brief EXTI_SWTIEN register Bit definition
  */
#define EXTI_SWTIEN_SWTIEN0                ((uint32_t)0x00000001)        /*!< Software trigger interrupt/event for line0 */
#define EXTI_SWTIEN_SWTIEN1                ((uint32_t)0x00000002)        /*!< Software trigger interrupt/event for line1 */
#define EXTI_SWTIEN_SWTIEN2                ((uint32_t)0x00000004)        /*!< Software trigger interrupt/event for line2 */
#define EXTI_SWTIEN_SWTIEN3                ((uint32_t)0x00000008)        /*!< Software trigger interrupt/event for line3 */
#define EXTI_SWTIEN_SWTIEN4                ((uint32_t)0x00000010)        /*!< Software trigger interrupt/event for line4 */
#define EXTI_SWTIEN_SWTIEN5                ((uint32_t)0x00000020)        /*!< Software trigger interrupt/event for line5 */
#define EXTI_SWTIEN_SWTIEN6                ((uint32_t)0x00000040)        /*!< Software trigger interrupt/event for line6 */
#define EXTI_SWTIEN_SWTIEN7                ((uint32_t)0x00000080)        /*!< Software trigger interrupt/event for line7 */
#define EXTI_SWTIEN_SWTIEN8                ((uint32_t)0x00000100)        /*!< Software trigger interrupt/event for line8 */
#define EXTI_SWTIEN_SWTIEN9                ((uint32_t)0x00000200)        /*!< Software trigger interrupt/event for line9 */
#define EXTI_SWTIEN_SWTIEN10               ((uint32_t)0x00000400)        /*!< Software trigger interrupt/event for line10 */
#define EXTI_SWTIEN_SWTIEN11               ((uint32_t)0x00000800)        /*!< Software trigger interrupt/event for line11 */
#define EXTI_SWTIEN_SWTIEN12               ((uint32_t)0x00001000)        /*!< Software trigger interrupt/event for line12 */
#define EXTI_SWTIEN_SWTIEN13               ((uint32_t)0x00002000)        /*!< Software trigger interrupt/event for line13 */
#define EXTI_SWTIEN_SWTIEN14               ((uint32_t)0x00004000)        /*!< Software trigger interrupt/event for line14 */
#define EXTI_SWTIEN_SWTIEN15               ((uint32_t)0x00008000)        /*!< Software trigger interrupt/event for line15 */
#define EXTI_SWTIEN_SWTIEN16               ((uint32_t)0x00010000)        /*!< Software trigger interrupt/event for line16 */
#define EXTI_SWTIEN_SWTIEN17               ((uint32_t)0x00020000)        /*!< Software trigger interrupt/event for line17 */
#define EXTI_SWTIEN_SWTIEN18               ((uint32_t)0x00040000)        /*!< Software trigger interrupt/event for line18 */
#define EXTI_SWTIEN_SWTIEN19               ((uint32_t)0x00080000)        /*!< Software trigger interrupt/event for line19 */
#define EXTI_SWTIEN_SWTIEN20               ((uint32_t)0x00100000)        /*!< Software trigger interrupt/event for line20 */
#define EXTI_SWTIEN_SWTIEN21               ((uint32_t)0x00200000)        /*!< Software trigger interrupt/event for line21 */
#define EXTI_SWTIEN_SWTIEN22               ((uint32_t)0x00400000)        /*!< Software trigger interrupt/event for line22 */
#define EXTI_SWTIEN_SWTIEN23               ((uint32_t)0x00800000)        /*!< Software trigger interrupt/event for line23 */
#define EXTI_SWTIEN_SWTIEN24               ((uint32_t)0x01000000)        /*!< Software trigger interrupt/event for line24 */
#define EXTI_SWTIEN_SWTIEN25               ((uint32_t)0x02000000)        /*!< Software trigger interrupt/event for line25 */
#define EXTI_SWTIEN_SWTIEN26               ((uint32_t)0x04000000)        /*!< Software trigger interrupt/event for line26 */
#define EXTI_SWTIEN_SWTIEN27               ((uint32_t)0x08000000)        /*!< Software trigger interrupt/event for line27 */
#define EXTI_SWTIEN_SWTIEN28               ((uint32_t)0x10000000)        /*!< Software trigger interrupt/event for line28 */
#define EXTI_SWTIEN_SWTIEN29               ((uint32_t)0x20000000)        /*!< Software trigger interrupt/event for line29 */
#define EXTI_SWTIEN_SWTIEN30               ((uint32_t)0x40000000)        /*!< Software trigger interrupt/event for line30 */
#define EXTI_SWTIEN_SWTIEN31               ((uint32_t)0x80000000)        /*!< Software trigger interrupt/event for line31 */

/**
  * @brief EXTI_PDF register Bit definition
  */
#define EXTI_PDF_PDF0                      ((uint32_t)0x00000001)        /*!< Pending interrupt flag for line 0 */
#define EXTI_PDF_PDF1                      ((uint32_t)0x00000002)        /*!< Pending interrupt flag for line 1 */
#define EXTI_PDF_PDF2                      ((uint32_t)0x00000004)        /*!< Pending interrupt flag for line 2 */
#define EXTI_PDF_PDF3                      ((uint32_t)0x00000008)        /*!< Pending interrupt flag for line 3 */
#define EXTI_PDF_PDF4                      ((uint32_t)0x00000010)        /*!< Pending interrupt flag for line 4 */
#define EXTI_PDF_PDF5                      ((uint32_t)0x00000020)        /*!< Pending interrupt flag for line 5 */
#define EXTI_PDF_PDF6                      ((uint32_t)0x00000040)        /*!< Pending interrupt flag for line 6 */
#define EXTI_PDF_PDF7                      ((uint32_t)0x00000080)        /*!< Pending interrupt flag for line 7 */
#define EXTI_PDF_PDF8                      ((uint32_t)0x00000100)        /*!< Pending interrupt flag for line 8 */
#define EXTI_PDF_PDF9                      ((uint32_t)0x00000200)        /*!< Pending interrupt flag for line 9 */
#define EXTI_PDF_PDF10                     ((uint32_t)0x00000400)        /*!< Pending interrupt flag for line 10 */
#define EXTI_PDF_PDF11                     ((uint32_t)0x00000800)        /*!< Pending interrupt flag for line 11 */
#define EXTI_PDF_PDF12                     ((uint32_t)0x00001000)        /*!< Pending interrupt flag for line 12 */
#define EXTI_PDF_PDF13                     ((uint32_t)0x00002000)        /*!< Pending interrupt flag for line 13 */
#define EXTI_PDF_PDF14                     ((uint32_t)0x00004000)        /*!< Pending interrupt flag for line 14 */
#define EXTI_PDF_PDF15                     ((uint32_t)0x00008000)        /*!< Pending interrupt flag for line 15 */
#define EXTI_PDF_PDF16                     ((uint32_t)0x00010000)        /*!< Pending interrupt flag for line 16 */
#define EXTI_PDF_PDF17                     ((uint32_t)0x00020000)        /*!< Pending interrupt flag for line 17 */
#define EXTI_PDF_PDF18                     ((uint32_t)0x00040000)        /*!< Pending interrupt flag for line 18 */
#define EXTI_PDF_PDF19                     ((uint32_t)0x00080000)        /*!< Pending interrupt flag for line 19 */
#define EXTI_PDF_PDF20                     ((uint32_t)0x00100000)        /*!< Pending interrupt flag for line 20 */
#define EXTI_PDF_PDF21                     ((uint32_t)0x00200000)        /*!< Pending interrupt flag for line 21 */
#define EXTI_PDF_PDF22                     ((uint32_t)0x00400000)        /*!< Pending interrupt flag for line 22 */
#define EXTI_PDF_PDF23                     ((uint32_t)0x00800000)        /*!< Pending interrupt flag for line23 */
#define EXTI_PDF_PDF24                     ((uint32_t)0x01000000)        /*!< Pending interrupt flag for line24 */
#define EXTI_PDF_PDF25                     ((uint32_t)0x02000000)        /*!< Pending interrupt flag for line25 */
#define EXTI_PDF_PDF26                     ((uint32_t)0x04000000)        /*!< Pending interrupt flag for line26 */
#define EXTI_PDF_PDF27                     ((uint32_t)0x08000000)        /*!< Pending interrupt flag for line27 */
#define EXTI_PDF_PDF28                     ((uint32_t)0x10000000)        /*!< Pending interrupt flag for line28 */
#define EXTI_PDF_PDF29                     ((uint32_t)0x20000000)        /*!< Pending interrupt flag for line29 */
#define EXTI_PDF_PDF30                     ((uint32_t)0x40000000)        /*!< Pending interrupt flag for line30 */
#define EXTI_PDF_PDF31                     ((uint32_t)0x80000000)        /*!< Pending interrupt flag for line 31 */

/*---------------------------------------------------------------------------*/
/*   FMC(FLASH Memory Control) and Option Byes Registers                     */
/*---------------------------------------------------------------------------*/

/**
  * @brief FMC_WCR register Bit definition
  */
#define FMC_WCR_WCNT                         ((uint32_t)0x00000001)        /*!< NT bit (FMC wait conuter) */
#define FMC_WCR_WE                           ((uint32_t)0x00000010)        /*!< MC wait enable */
#define FMC_WCR_WS                           ((uint32_t)0x00000020)        /*!< MC wait status(read only) */

/**
  * @brief FMC_CCODE register Bit definition
  */
#define FMC_CCODE_CCODE                      ((uint32_t)0xFFFFFFFF)        /*!< MC Control code */

/**
  * @brief FMC_OBCCODE register Bit definition
  */
#define FMC_OBCCODE_OBCCODE                  ((uint32_t)0xFFFFFFFF)        /*!< FMC Option Byte Control code */

/**
  * @brief FMC CCODE Bit definition
  */
#define FMC_CCODE_VALUE1                     ((uint32_t)0x45670123)        /*!< Flash program erase key1 */
#define FMC_CCODE_VALUE2                     ((uint32_t)0xCDEF89AB)        /*!< Flash program erase key2 */
#define FMC_OBCCODE_VALUE1                   ((uint32_t)0x45670123)        /*!< Flash option key1 */
#define FMC_OBCCODE_VALUE2                   ((uint32_t)0xCDEF89AB)        /*!< Flash option key2 */

/**
  * @brief FMC_STS register Bit definition
  */
#define FMC_STS_BUSY                         ((uint32_t)0x00000001)        /*!< Busy */
#define FMC_STS_PGERR                        ((uint32_t)0x00000004)        /*!< Programming Error */
#define FMC_STS_WPERR                        ((uint32_t)0x00000010)        /*!< Write Protection Error */
#define FMC_STS_ENDF                         ((uint32_t)0x00000020)        /*!< End of operation */

/**
  * @brief FMC_CTR register Bit definition
  */
#define FMC_CTR_PG                           ((uint32_t)0x00000001)        /*!< Main flash program */
#define FMC_CTR_PERS                         ((uint32_t)0x00000002)        /*!< Flash page erase */
#define FMC_CTR_CHIPERS                      ((uint32_t)0x00000004)        /*!< Mass flash CHIP ERASE */
#define FMC_CTR_EFSPG                        ((uint32_t)0x00000008)        /*!< EFuse program command */
#define FMC_CTR_OBPG                         ((uint32_t)0x00000010)        /*!< Option byte program command */
#define FMC_CTR_OBERS                        ((uint32_t)0x00000020)        /*!< Option bytes erase command */
#define FMC_CTR_START                        ((uint32_t)0x00000040)        /*!< Start of erase */
#define FMC_CTR_LOCK                         ((uint32_t)0x00000080)        /*!< Lock */
#define FMC_CTR_STARTCRC                     ((uint32_t)0x00000100)        /*!< Start CRC32 command */
#define FMC_CTR_OBWEN                        ((uint32_t)0x00000200)        /*!< Option byte erase/program enable */
#define FMC_CTR_ERRIE                        ((uint32_t)0x00000400)        /*!< Error interrupt enable */
#define FMC_CTR_ENDIE                        ((uint32_t)0x00001000)        /*!< End of operation interrupt enable */
#define FMC_CTR_OBUPDATE                     ((uint32_t)0x00002000)        /*!< Update option byte */
#define FMC_CTR_EFSERS                       ((uint32_t)0x00020000)        /*!< eFuse-key erase command */
#define FMC_CTR_EFSSKCRC                     ((uint32_t)0x00100000)        /*!< eFuse-key  and Secure-key CRC32 check command */

/**
  * @brief FMC_ERSADR register Bit definition
  */
#define FMC_ERSADR_ERSADR                    ((uint32_t)0xFFFFFFFF)        /* lash erase address */

/**
  * @brief FMC_OBSTS register Bit definition
  */
#define FMC_OBSTS_OBERR                      ((uint32_t)0x00000001)        /*!< OBERR */
#define FMC_OBSTS_FWDT_AO                    ((uint32_t)0x00000100)        /*!< FWDT_ALWAYSON */
#define FMC_OBSTS_nRST_DSM                   ((uint32_t)0x00000200)        /*!< nRST_DSM  */
#define FMC_OBSTS_nRST_PWD                   ((uint32_t)0x00000400)        /*!< nRST_PWD */
#define FMC_OBSTS_BOOTCFG0                   ((uint32_t)0x00000800)        /*!< BOOTCFG[0] */
#define FMC_OBSTS_nBOOT1                     ((uint32_t)0x00001000)        /*!< nBOOT1 */
#define FMC_OBSTS_VDDA_DET                   ((uint32_t)0x00002000)        /*!< VDDA_DETECT */
#define FMC_OBSTS_RAM_PCHK                   ((uint32_t)0x00004000)        /*!< RAM_PARITY_CHECK */
#define FMC_OBSTS_BOOTCFG1                   ((uint32_t)0x00008000)        /*!< BOOTCFG[1] */
#define FMC_OBSTS_DATA0                      ((uint32_t)0x00FF0000)        /*!< DATA0 */
#define FMC_OBSTS_DATA1                      ((uint32_t)0xFF000000)        /*!< DATA1 */

/**
  * @brief FMC_WPSTS register Bit definition
  */
#define FMC_WPSTS_WPROT                      ((uint32_t)0xFFFFFFFF)        /*!<  Write Protect */

/**
  * @brief FMC_CFG register Bit definition
  */
#define FMC_CFG_PGWORD              		  ((uint32_t)0x00000001)        /*!<  Support word program */

/**
  * @brief FMC_CFGU register Bit definition
  */
#define FMC_CFGU_FWUP_EN              		  ((uint32_t)0x00000001)        /*!<  FLASH fast wake-up in deepsleep mode */

/**
  * @brief FMC_STS2 register Bit definition
  */
#define FMC_STS2_SWDLK_STS                   ((uint32_t)0x00000001)        /*!<  SWD disabled */
#define FMC_STS2_BTWRP_STS                   ((uint32_t)0x00000002)        /*!<  Bootloader write protect */
#define FMC_STS2_FBSEAL_STS                  ((uint32_t)0x00000010)        /*!<  Flash BIST inoperable */
#define FMC_STS2_PDSEAL_STS                  ((uint32_t)0x00000020)        /*!<  Product information area inoperable */

#define FMC_STS2_LCSSTS_LEVEL0               ((uint32_t)0x00000000)        /*!<  Lifecycle chip manufacturing */
#define FMC_STS2_LCSSTS_LEVEL1               ((uint32_t)0x00010000)        /*!<  Lifecycle product development */
#define FMC_STS2_LCSSTS_LEVEL2               ((uint32_t)0x00020000)        /*!<  Lifecycle user phase */
#define FMC_STS2_LCSSTS_LEVEL3               ((uint32_t)0x00030000)        /*!<  Lifecycle self destruction phase */

#define FMC_STS2_TRNG_STS                    ((uint32_t)0x00080000)        /*!<  TRNG power on self-test status bit */

/**
  * @brief OB_WPROT0 register Bit definition
  */
#define OB_WPROT0_WPROT0                     ((uint32_t)0x000000FF)        /*!<  Flash memory write protection option bytes */
#define OB_WPROT0_nWPROT0                    ((uint32_t)0x0000FF00)        /*!<  Flash memory write protection complemented option bytes */

/**
  * @brief OB_WPROT1 register Bit definition
  */
#define OB_WPROT1_WPROT1                     ((uint32_t)0x00FF0000)        /*!<  Flash memory write protection option bytes */
#define OB_WPROT1_nWPROT1                    ((uint32_t)0xFF000000)        /*!<  Flash memory write protection complemented option bytes */

/**
  * @brief OB_WPROT2 register Bit definition
  */
#define OB_WPROT2_WPROT2                     ((uint32_t)0x000000FF)        /*!<  Flash memory write protection option bytes */
#define OB_WPROT2_nWPROT2                    ((uint32_t)0x0000FF00)        /*!<  Flash memory write protection complemented option bytes */

/**
  * @brief OB_WPROT3 register Bit definition
  */
#define OB_WPROT3_WPROT3                     ((uint32_t)0x00FF0000)        /*!<  Flash memory write protection option bytes */
#define OB_WPROT3_nWPROT3                    ((uint32_t)0xFF000000)        /*!<  Flash memory write protection complemented option bytes */

/*--------------------------------------------------------------------------*/
/*                         FWDT(Free Watchdog Timer)                        */
/*--------------------------------------------------------------------------*/

/**
  * @brief FWDT_CCODE register Bit definition
  */
#define FWDT_CCODE_CCODE             		((uint32_t)0x0000FFFF)      /*!< Control code (write only, read 0000h). */

/**
  * @brief FWDT_PDIV register Bit definition
  */
#define FWDT_PDIV_PDIV               		((uint32_t)0x00000007)      /*!< PDIV[2:0] (Pre-divider). */
#define FWDT_PDIV_PDIV_0             		((uint32_t)0x00000001)      /*!< Bit 0. */
#define FWDT_PDIV_PDIV_1             		((uint32_t)0x00000002)      /*!< Bit 1. */
#define FWDT_PDIV_PDIV_2             		((uint32_t)0x00000004)      /*!< Bit 2. */

/**
  * @brief FWDT_UVAL register Bit definition
  */
#define FWDT_UVAL_UVAL               		((uint32_t)0x00000FFF)      /*!< Watchdog counter update value. */

/**
  * @brief FWDT_STS register Bit definition
  */
#define FWDT_STS_DRF                 		((uint32_t)0x00000001)      /*!< FWDT divider refresh flag. */
#define FWDT_STS_UVRF                		((uint32_t)0x00000002)      /*!< FWDT update value refresh flag. */
#define FWDT_STS_WRF                 		((uint32_t)0x00000004)      /*!< FWDT divider refresh flag. */

/**
  * @brief FWDT_WINVAL register Bit definition
  */
#define FWDT_WINVAL_WINVAL           		((uint32_t)0x00000FFF)      /*!< IWDT window value. */

/*--------------------------------------------------------------------------*/
/*                           HDIV(Hardware Divider)                         */
/*--------------------------------------------------------------------------*/

/**
  * @brief HDIV_DIVIDEND0 register bit definition
  */
#define HDIV_DIVIDEND0_DIVIDEND      		((uint32_t)0xFFFFFFFF)      /*!< HDIV dividend bit. */

/**
  * @brief HDIV_DIVIDEND1 register bit definition
  */
#define HDIV_DIVIDEND1_DIVIDEND      		((uint32_t)0xFFFFFFFF)      /*!< HDIV dividend bit. */

/**
  * @brief HDIV_DIVISOR register bit definition
  */
#define HDIV_DIVISOR_DIVISOR         		((uint32_t)0xFFFFFFFF)      /*!< HDIV divisor bit. */

/**
  * @brief HDIV_DIVQUO0 register bit definition
  */
#define HDIV_DIVQUO0_QUOTIENT        		((uint32_t)0xFFFFFFFF)      /*!< HDIV quotient bit. */

/**
  * @brief HDIV_DIVQUO1 register bit definition
  */
#define HDIV_DIVQUO1_QUOTIENT        		((uint32_t)0xFFFFFFFF)      /*!< HDIV quotient bit. */

/**
  * @brief HDIV_DIVREM register bit definition
  */
#define HDIV_DIVREM_REMAINDER        		((uint32_t)0xFFFFFFFF)      /*!< HDIV remainder bit. */

/**
  * @brief HDIV_DIVSTS register bit definition
  */
#define HDIV_DIVSTS_DIV0             		((uint32_t)0x00000002)      /*!< HDIV divisor is 0 warning bit. */
#define HDIV_DIVSTS_OVR              		((uint32_t)0x00000004)      /*!< HDIV calculation result overflow bit. */

/*--------------------------------------------------------------------------*/
/*                    GPIO(General Purpose Input/Output)                    */
/*--------------------------------------------------------------------------*/

/**
  * @brief GPIO_PFR register Bit definition
  */
#define GPIO_PFR_FUNC0               		((uint32_t)0x00000003)      /*!< FUNC[1:0] port function bits. */
#define GPIO_PFR_FUNC0_0             		((uint32_t)0x00000001)      /*!< Bit 0. */
#define GPIO_PFR_FUNC0_1             		((uint32_t)0x00000002)      /*!< Bit 1. */
#define GPIO_PFR_FUNC1               		((uint32_t)0x0000000C)      /*!< FUNC[1:0] port function bits. */
#define GPIO_PFR_FUNC1_0             		((uint32_t)0x00000004)      /*!< Bit 0. */
#define GPIO_PFR_FUNC1_1             		((uint32_t)0x00000008)      /*!< Bit 1. */
#define GPIO_PFR_FUNC2               		((uint32_t)0x00000030)      /*!< FUNC[1:0] port function bits. */
#define GPIO_PFR_FUNC2_0             		((uint32_t)0x00000010)      /*!< Bit 0. */
#define GPIO_PFR_FUNC2_1             		((uint32_t)0x00000020)      /*!< Bit 1. */
#define GPIO_PFR_FUNC3               		((uint32_t)0x000000C0)      /*!< FUNC[1:0] port function bits. */
#define GPIO_PFR_FUNC3_0             		((uint32_t)0x00000040)      /*!< Bit 0. */
#define GPIO_PFR_FUNC3_1             		((uint32_t)0x00000080)      /*!< Bit 1. */
#define GPIO_PFR_FUNC4               		((uint32_t)0x00000300)      /*!< FUNC[1:0] port function bits. */
#define GPIO_PFR_FUNC4_0             		((uint32_t)0x00000100)      /*!< Bit 0. */
#define GPIO_PFR_FUNC4_1             		((uint32_t)0x00000200)      /*!< Bit 1. */
#define GPIO_PFR_FUNC5               		((uint32_t)0x00000C00)      /*!< FUNC[1:0] port function bits. */
#define GPIO_PFR_FUNC5_0             		((uint32_t)0x00000400)      /*!< Bit 0. */
#define GPIO_PFR_FUNC5_1             		((uint32_t)0x00000800)      /*!< Bit 1. */
#define GPIO_PFR_FUNC6               		((uint32_t)0x00003000)      /*!< FUNC[1:0] port function bits. */
#define GPIO_PFR_FUNC6_0             		((uint32_t)0x00001000)      /*!< Bit 0. */
#define GPIO_PFR_FUNC6_1             		((uint32_t)0x00002000)      /*!< Bit 1. */
#define GPIO_PFR_FUNC7               		((uint32_t)0x0000C000)      /*!< FUNC[1:0] port function bits. */
#define GPIO_PFR_FUNC7_0             		((uint32_t)0x00004000)      /*!< bit 0. */
#define GPIO_PFR_FUNC7_1             		((uint32_t)0x00008000)      /*!< bit 1. */
#define GPIO_PFR_FUNC8               		((uint32_t)0x00030000)      /*!< FUNC[1:0] port function bits. */
#define GPIO_PFR_FUNC8_0             		((uint32_t)0x00010000)      /*!< Bit 0. */
#define GPIO_PFR_FUNC8_1             		((uint32_t)0x00020000)      /*!< Bit 1. */
#define GPIO_PFR_FUNC9               		((uint32_t)0x000C0000)      /*!< FUNC[1:0] port function bits. */
#define GPIO_PFR_FUNC9_0             		((uint32_t)0x00040000)      /*!< Bit 0. */
#define GPIO_PFR_FUNC9_1             		((uint32_t)0x00080000)      /*!< Bit 1. */
#define GPIO_PFR_FUNC10              		((uint32_t)0x00300000)      /*!< FUNC0[1:0] port function bits. */
#define GPIO_PFR_FUNC10_0            		((uint32_t)0x00100000)      /*!< Bit 0. */
#define GPIO_PFR_FUNC10_1            		((uint32_t)0x00200000)      /*!< Bit 1. */
#define GPIO_PFR_FUNC11              		((uint32_t)0x00C00000)      /*!< FUNC1[1:0] port function bits. */
#define GPIO_PFR_FUNC11_0            		((uint32_t)0x00400000)      /*!< Bit 0. */
#define GPIO_PFR_FUNC11_1            		((uint32_t)0x00800000)      /*!< Bit 1. */
#define GPIO_PFR_FUNC12              		((uint32_t)0x03000000)      /*!< FUNC2[1:0] port function bits. */
#define GPIO_PFR_FUNC12_0            		((uint32_t)0x01000000)      /*!< Bit 0. */
#define GPIO_PFR_FUNC12_1            		((uint32_t)0x02000000)      /*!< Bit 1. */
#define GPIO_PFR_FUNC13              		((uint32_t)0x0C000000)      /*!< FUNC3[1:0] port function bits. */
#define GPIO_PFR_FUNC13_0            		((uint32_t)0x04000000)      /*!< Bit 0. */
#define GPIO_PFR_FUNC13_1            		((uint32_t)0x08000000)      /*!< Bit 1. */

/**
  * @brief GPIO_PODENR register Bit definition
  */
#define GPIO_PODENR_ODEN_0           		((uint32_t)0x00000001)      /*!< Portbit 0 output open-drain enable. */
#define GPIO_PODENR_ODEN_1           		((uint32_t)0x00000002)      /*!< Portbit 1 output open-drain enable. */
#define GPIO_PODENR_ODEN_2           		((uint32_t)0x00000004)      /*!< Portbit 2 output open-drain enable. */
#define GPIO_PODENR_ODEN_3           		((uint32_t)0x00000008)      /*!< Portbit 3 output open-drain enable. */
#define GPIO_PODENR_ODEN_4           		((uint32_t)0x00000010)      /*!< Portbit 4 output open-drain enable. */
#define GPIO_PODENR_ODEN_5           		((uint32_t)0x00000020)      /*!< Portbit 5 output open-drain enable. */
#define GPIO_PODENR_ODEN_6           		((uint32_t)0x00000040)      /*!< Portbit 6 output open-drain enable. */
#define GPIO_PODENR_ODEN_7           		((uint32_t)0x00000080)      /*!< Portbit 7 output open-drain enable. */
#define GPIO_PODENR_ODEN_8           		((uint32_t)0x00000100)      /*!< Portbit 8 output open-drain enable. */
#define GPIO_PODENR_ODEN_9           		((uint32_t)0x00000200)      /*!< Portbit 9 output open-drain enable. */
#define GPIO_PODENR_ODEN_10          		((uint32_t)0x00000400)      /*!< Portbit 10 output open-drain enable. */
#define GPIO_PODENR_ODEN_11          		((uint32_t)0x00000800)      /*!< Portbit 11 output open-drain enable. */
#define GPIO_PODENR_ODEN_12          		((uint32_t)0x00001000)      /*!< Portbit 12 output open-drain enable. */
#define GPIO_PODENR_ODEN_13          		((uint32_t)0x00002000)      /*!< Portbit 13 output open-drain enable. */

/**
  * @brief GPIO_POSR register Bit definition
  */
#define GPIO_POSR_OS0                		((uint32_t)0x00000003)      /*!< OS0[:0] (output speed). */
#define GPIO_POSR_OS0_0              		((uint32_t)0x00000001)      /*!< Bit 0. */
#define GPIO_POSR_OS0_1              		((uint32_t)0x00000002)      /*!< Bit 1. */
#define GPIO_POSR_OS1                		((uint32_t)0x0000000C)      /*!<OS1[10] (output speed). */
#define GPIO_POSR_OS1_0              		((uint32_t)0x00000004)      /*!< Bit 0. */
#define GPIO_POSR_OS1_1              		((uint32_t)0x00000008)      /*!< Bit 1. */
#define GPIO_POSR_OS2                		((uint32_t)0x00000030)      /*!< OS2[1:0] (output speed). */
#define GPIO_POSR_OS2_0              		((uint32_t)0x00000010)      /*!< Bit 0. */
#define GPIO_POSR_OS2_1              		((uint32_t)0x00000020)      /*!< Bit 1. */
#define GPIO_POSR_OS3                		((uint32_t)0x000000C0)      /*!< OS3[1:0] (output speed). */
#define GPIO_POSR_OS3_0              		((uint32_t)0x00000040)      /*!< Bit 0. */
#define GPIO_POSR_OS3_1              		((uint32_t)0x00000080)      /*!< Bit 1. */
#define GPIO_POSR_OS4                		((uint32_t)0x00000300)      /*!< OS4[1:0] (output speed). */
#define GPIO_POSR_OS4_0              		((uint32_t)0x00000100)      /*!< Bit 0. */
#define GPIO_POSR_OS4_1              		((uint32_t)0x00000200)      /*!< Bit 1. */
#define GPIO_POSR_OS5                		((uint32_t)0x00000C00)      /*!< OS5[1:0] (output speed). */
#define GPIO_POSR_OS5_0              		((uint32_t)0x00000400)      /*!< Bit 0. */
#define GPIO_POSR_OS5_1              		((uint32_t)0x00000800)      /*!< Bit 1. */
#define GPIO_POSR_OS6                		((uint32_t)0x00003000)      /*!< OS6[1:0] (output speed). */
#define GPIO_POSR_OS6_0              		((uint32_t)0x00001000)      /*!< Bit 0. */
#define GPIO_POSR_OS6_1              		((uint32_t)0x00002000)      /*!< Bit 1. */
#define GPIO_POSR_OS7                		((uint32_t)0x0000C000)      /*!< OS7[1:0] (output speed). */
#define GPIO_POSR_OS7_0              		((uint32_t)0x00004000)      /*!< Bit 0. */
#define GPIO_POSR_OS7_1              		((uint32_t)0x00008000)      /*!< Bit 1. */
#define GPIO_POSR_OS8                		((uint32_t)0x00030000)      /*!< OS8[1:0] (output speed). */
#define GPIO_POSR_OS8_0              		((uint32_t)0x00010000)      /*!< Bit 0. */
#define GPIO_POSR_OS8_1              		((uint32_t)0x00020000)      /*!< Bit 1. */
#define GPIO_POSR_OS9                		((uint32_t)0x000C0000)      /*!< OS9[1:0] (output speed). */
#define GPIO_POSR_OS9_0              		((uint32_t)0x00040000)      /*!< Bit 0. */
#define GPIO_POSR_OS9_1              		((uint32_t)0x00080000)      /*!< Bit 1. */
#define GPIO_POSR_OS10               		((uint32_t)0x00300000)      /*!< OS10[1:0] (output speed). */
#define GPIO_POSR_OS10_0             		((uint32_t)0x00100000)      /*!< Bit 0. */
#define GPIO_POSR_OS10_1             		((uint32_t)0x00200000)      /*!< Bit 1. */
#define GPIO_POSR_OS11               		((uint32_t)0x00C00000)      /*!< OS11[1:0] (output speed). */
#define GPIO_POSR_OS11_0             		((uint32_t)0x00400000)      /*!< Bit 0. */
#define GPIO_POSR_OS11_1             		((uint32_t)0x00800000)      /*!< Bit 1. */
#define GPIO_POSR_OS12               		((uint32_t)0x03000000)      /*!< OS12[1:0] (output speed). */
#define GPIO_POSR_OS12_0             		((uint32_t)0x01000000)      /*!< Bit 0. */
#define GPIO_POSR_OS12_1             		((uint32_t)0x02000000)      /*!< Bit 1. */
#define GPIO_POSR_OS13               		((uint32_t)0x0C000000)      /*!< OS13[1:0] (output speed). */
#define GPIO_POSR_OS13_0             		((uint32_t)0x04000000)      /*!< Bit 0. */
#define GPIO_POSR_OS13_1             		((uint32_t)0x08000000)      /*!< Bit 1. */

/**
  * @brief GPIO_PUPDR register Bit definition
  */
#define GPIO_PUPDR_PUPD0            		((uint32_t)0x00000003)      /*!< PUPD0[1:0]config (pull-up/pull-down ). */
#define GPIO_PUPDR_PUPD0_0          		((uint32_t)0x00000001)      /*!< Bit 0. */
#define GPIO_PUPDR_PUPD0_1          		((uint32_t)0x00000002)      /*!< Bit 1. */
#define GPIO_PUPDR_PUPD1            		((uint32_t)0x0000000C)      /*!< PUPD1[1:0]config (pull-up/pull-down ). */
#define GPIO_PUPDR_PUPD1_0          		((uint32_t)0x00000004)      /*!< Bit 0. */
#define GPIO_PUPDR_PUPD1_1          		((uint32_t)0x00000008)      /*!< Bit 1. */
#define GPIO_PUPDR_PUPD2            		((uint32_t)0x00000030)      /*!< PUPD2[1:0]config (pull-up/pull-down ). */
#define GPIO_PUPDR_PUPD2_0          		((uint32_t)0x00000010)      /*!< Bit 0. */
#define GPIO_PUPDR_PUPD2_1          		((uint32_t)0x00000020)      /*!< Bit 1. */
#define GPIO_PUPDR_PUPD3            		((uint32_t)0x000000C0)      /*!< PUPD3[1:0]config (pull-up/pull-down ). */
#define GPIO_PUPDR_PUPD3_0          		((uint32_t)0x00000040)      /*!< Bit 0. */
#define GPIO_PUPDR_PUPD3_1          		((uint32_t)0x00000080)      /*!< bit 1. */
#define GPIO_PUPDR_PUPD4            		((uint32_t)0x00000300)      /*!< PUPD4[1:0]config (pull-up/pull-down ). */
#define GPIO_PUPDR_PUPD4_0          		((uint32_t)0x00000100)      /*!< Bit 0. */
#define GPIO_PUPDR_PUPD4_1          		((uint32_t)0x00000200)      /*!< Bit 1. */
#define GPIO_PUPDR_PUPD5            		((uint32_t)0x00000C00)      /*!< PUPD5[1:0]config (pull-up/pull-down ). */
#define GPIO_PUPDR_PUPD5_0          		((uint32_t)0x00000400)      /*!< Bit 0. */
#define GPIO_PUPDR_PUPD5_1          		((uint32_t)0x00000800)      /*!< Bit 1. */
#define GPIO_PUPDR_PUPD6            		((uint32_t)0x00003000)      /*!< PUPD6[1:0]config (pull-up/pull-down ). */
#define GPIO_PUPDR_PUPD6_0          		((uint32_t)0x00001000)      /*!< Bit 0. */
#define GPIO_PUPDR_PUPD6_1          		((uint32_t)0x00002000)      /*!< Bit 1. */
#define GPIO_PUPDR_PUPD7            		((uint32_t)0x0000C000)      /*!< PUPD7[1:0]config (pull-up/pull-down ). */
#define GPIO_PUPDR_PUPD7_0          		((uint32_t)0x00004000)      /*!< Bit 0. */
#define GPIO_PUPDR_PUPD7_1          		((uint32_t)0x00008000)      /*!< Bit 1. */
#define GPIO_PUPDR_PUPD8            		((uint32_t)0x00030000)      /*!< PUPD8[1:0]config (pull-up/pull-down ). */
#define GPIO_PUPDR_PUPD8_0          		((uint32_t)0x00010000)      /*!< bit 0. */
#define GPIO_PUPDR_PUPD8_1          		((uint32_t)0x00020000)      /*!< Bit 1. */
#define GPIO_PUPDR_PUPD9            		((uint32_t)0x000C0000)      /*!< PUPD9[1:0]config (pull-up/pull-down ). */
#define GPIO_PUPDR_PUPD9_0          		((uint32_t)0x00040000)      /*!< Bit 0. */
#define GPIO_PUPDR_PUPD9_1          		((uint32_t)0x00080000)      /*!< Bit 1. */
#define GPIO_PUPDR_PUPD10           		((uint32_t)0x00300000)      /*!< PUPD10[1:0]config (pull-up/pull-down ). */
#define GPIO_PUPDR_PUPD10_0         		((uint32_t)0x00100000)      /*!< Bit 0. */
#define GPIO_PUPDR_PUPD10_1         		((uint32_t)0x00200000)      /*!< Bit 1. */
#define GPIO_PUPDR_PUPD11           		((uint32_t)0x00C00000)      /*!< PUPD11[1:0]config (pull-up/pull-down ). */
#define GPIO_PUPDR_PUPD11_0         		((uint32_t)0x00400000)      /*!< Bit 0. */
#define GPIO_PUPDR_PUPD11_1         		((uint32_t)0x00800000)      /*!< Bit 1. */
#define GPIO_PUPDR_PUPD12           		((uint32_t)0x03000000)      /*!< PUPD12[1:0]config (pull-up/pull-down ). */
#define GPIO_PUPDR_PUPD12_0         		((uint32_t)0x01000000)      /*!< Bit 0. */
#define GPIO_PUPDR_PUPD12_1         		((uint32_t)0x02000000)      /*!< Bit 1. */
#define GPIO_PUPDR_PUPD13           		((uint32_t)0x0C000000)      /*!< PUPD13[1:0]config (pull-up/pull-down ). */
#define GPIO_PUPDR_PUPD13_0         		((uint32_t)0x04000000)      /*!< Bit 0. */
#define GPIO_PUPDR_PUPD13_1         		((uint32_t)0x08000000)      /*!< Bit 1. */

/**
  * @brief GPIO_DI register Bit definition
  */
#define GPIO_DI_0                   		((uint32_t)0x00000001)      /*!< Portx bit 0 data input. */
#define GPIO_DI_1                   		((uint32_t)0x00000002)      /*!< Portx bit 1 data input. */
#define GPIO_DI_2                   		((uint32_t)0x00000004)      /*!< Portx bit 2 data input. */
#define GPIO_DI_3                   		((uint32_t)0x00000008)      /*!< Portx bit 3 data input. */
#define GPIO_DI_4                   		((uint32_t)0x00000010)      /*!< Portx bit 4 data input. */
#define GPIO_DI_5                   		((uint32_t)0x00000020)      /*!< Portx bit 5 data input. */
#define GPIO_DI_6                   		((uint32_t)0x00000040)      /*!< Portx bit 6 data input. */
#define GPIO_DI_7                   		((uint32_t)0x00000080)      /*!< Portx bit 7 data input. */
#define GPIO_DI_8                   		((uint32_t)0x00000100)      /*!< Portx bit 8 data input. */
#define GPIO_DI_9                   		((uint32_t)0x00000200)      /*!< Portx bit 9 data input. */
#define GPIO_DI_10                  		((uint32_t)0x00000400)      /*!< Portx bit 10 data input. */
#define GPIO_DI_11                  		((uint32_t)0x00000800)      /*!< Portx bit 11 data input. */
#define GPIO_DI_12                  		((uint32_t)0x00001000)      /*!< Portx bit 12 data input. */
#define GPIO_DI_13                  		((uint32_t)0x00002000)      /*!< Portx bit 13 data input. */

/**
  * @brief GPIO_DO register Bit definition
  */
#define GPIO_DO_0                   		((uint32_t)0x00000001)      /*!< Portx bit 0 data output. */
#define GPIO_DO_1                   		((uint32_t)0x00000002)      /*!< Portx bit 1 data output. */
#define GPIO_DO_2                   		((uint32_t)0x00000004)      /*!< Portx bit 2 data output. */
#define GPIO_DO_3                   		((uint32_t)0x00000008)      /*!< Portx bit 3 data output. */
#define GPIO_DO_4                   		((uint32_t)0x00000010)      /*!< Portx bit 4 data output. */
#define GPIO_DO_5                   		((uint32_t)0x00000020)      /*!< Portx bit 5 data output. */
#define GPIO_DO_6                   		((uint32_t)0x00000040)      /*!< Portx bit 6 data output. */
#define GPIO_DO_7                   		((uint32_t)0x00000080)      /*!< Portx bit 7 data output. */
#define GPIO_DO_8                   		((uint32_t)0x00000100)      /*!< Portx bit 8 data output. */
#define GPIO_DO_9                   		((uint32_t)0x00000200)      /*!< Portx bit 9 data output. */
#define GPIO_DO_10                  		((uint32_t)0x00000400)      /*!< Portx bit 10 data output. */
#define GPIO_DO_11                  		((uint32_t)0x00000800)      /*!< Portx bit 11 data output. */
#define GPIO_DO_12                  		((uint32_t)0x00001000)      /*!< Portx bit 12 data output. */
#define GPIO_DO_13                  		((uint32_t)0x00002000)      /*!< Portx bit 13 data output. */

/**
  * @brief GPIO_SCR register Bit definition
  */
#define GPIO_SCR_BS_0               		((uint32_t)0x00000001)      /*!< Portx bit 0 set. */
#define GPIO_SCR_BS_1               		((uint32_t)0x00000002)      /*!< Portx bit 1 set. */
#define GPIO_SCR_BS_2               		((uint32_t)0x00000004)      /*!< Portx bit 2 set. */
#define GPIO_SCR_BS_3               		((uint32_t)0x00000008)      /*!< Portx bit 3 set. */
#define GPIO_SCR_BS_4               		((uint32_t)0x00000010)      /*!< Portx bit 4 set. */
#define GPIO_SCR_BS_5               		((uint32_t)0x00000020)      /*!< Portx bit 5 set. */
#define GPIO_SCR_BS_6               		((uint32_t)0x00000040)      /*!< Portx bit 6 set. */
#define GPIO_SCR_BS_7               		((uint32_t)0x00000080)      /*!< Portx bit 7 set. */
#define GPIO_SCR_BS_8               		((uint32_t)0x00000100)      /*!< Portx bit 8 set. */
#define GPIO_SCR_BS_9               		((uint32_t)0x00000200)      /*!< Portx bit 9 set. */
#define GPIO_SCR_BS_10              		((uint32_t)0x00000400)      /*!< Portx bit 10 set. */
#define GPIO_SCR_BS_11              		((uint32_t)0x00000800)      /*!< Portx bit 11 set. */
#define GPIO_SCR_BS_12              		((uint32_t)0x00001000)      /*!< Portx bit 12 set. */
#define GPIO_SCR_BS_13              		((uint32_t)0x00002000)      /*!< Portx bit 13 set. */
#define GPIO_SCR_BC_0               		((uint32_t)0x00010000)      /*!< Portx bit 0 clear. */
#define GPIO_SCR_BC_1               		((uint32_t)0x00020000)      /*!< Portx bit 1 clear. */
#define GPIO_SCR_BC_2               		((uint32_t)0x00040000)      /*!< Portx bit 2 clear. */
#define GPIO_SCR_BC_3               		((uint32_t)0x00080000)      /*!< Portx bit 3 clear. */
#define GPIO_SCR_BC_4               		((uint32_t)0x00100000)      /*!< Portx bit 4 clear. */
#define GPIO_SCR_BC_5               		((uint32_t)0x00200000)      /*!< Portx bit 5 clear. */
#define GPIO_SCR_BC_6               		((uint32_t)0x00400000)      /*!< Portx bit 6 clear. */
#define GPIO_SCR_BC_7               		((uint32_t)0x00800000)      /*!< Portx bit 7 clear. */
#define GPIO_SCR_BC_8               		((uint32_t)0x01000000)      /*!< Portx bit 8 clear. */
#define GPIO_SCR_BC_9               		((uint32_t)0x02000000)      /*!< Portx bit 9 clear. */
#define GPIO_SCR_BC_10              		((uint32_t)0x04000000)      /*!< Portx bit 10 clear. */
#define GPIO_SCR_BC_11              		((uint32_t)0x08000000)      /*!< Portx bit 11 clear. */
#define GPIO_SCR_BC_12              		((uint32_t)0x10000000)      /*!< Portx bit 12 clear. */
#define GPIO_SCR_BC_13              		((uint32_t)0x20000000)      /*!< Portx bit 13 clear. */

/**
  * @brief GPIO_LOCK register Bit definition
  */
#define GPIO_LOCK_LOCK0             		((uint32_t)0x00000001)      /*!< Portx lock bit 0. */
#define GPIO_LOCK_LOCK1             		((uint32_t)0x00000002)      /*!< Portx lock bit 1. */
#define GPIO_LOCK_LOCK2             		((uint32_t)0x00000004)      /*!< Portx lock bit 2. */
#define GPIO_LOCK_LOCK3             		((uint32_t)0x00000008)      /*!< Portx lock bit 3. */
#define GPIO_LOCK_LOCK4             		((uint32_t)0x00000010)      /*!< Portx lock bit 4. */
#define GPIO_LOCK_LOCK5             		((uint32_t)0x00000020)      /*!< Portx lock bit 5. */
#define GPIO_LOCK_LOCK6             		((uint32_t)0x00000040)      /*!< Portx lock bit 6. */
#define GPIO_LOCK_LOCK7             		((uint32_t)0x00000080)      /*!< Portx lock bit 7. */
#define GPIO_LOCK_LOCK8             		((uint32_t)0x00000100)      /*!< Portx lock bit 8. */
#define GPIO_LOCK_LOCK9             		((uint32_t)0x00000200)      /*!< Portx lock bit 9. */
#define GPIO_LOCK_LOCK10            		((uint32_t)0x00000400)      /*!< Portx lock bit 10. */
#define GPIO_LOCK_LOCK11            		((uint32_t)0x00000800)      /*!< Portx lock bit 11. */
#define GPIO_LOCK_LOCK12            		((uint32_t)0x00001000)      /*!< Portx lock bit 12. */
#define GPIO_LOCK_LOCK13            		((uint32_t)0x00002000)      /*!< Portx lock bit 13. */
#define GPIO_LOCK_LOCKK             		((uint32_t)0x00010000)      /*!< Lock sequence key. */

/**
  * @brief GPIO_MFSELL register Bit definition
  */
#define GPIO_MFSELL_MFSELL0         		((uint32_t)0x0000000F)      /*!< Port xmulti-function selection 0. */
#define GPIO_MFSELL_MFSELL1         		((uint32_t)0x000000F0)      /*!< Port xmulti-function selection 1. */
#define GPIO_MFSELL_MFSELL2         		((uint32_t)0x00000F00)      /*!< Port xmulti-function selection 2. */
#define GPIO_MFSELL_MFSELL3         		((uint32_t)0x0000F000)      /*!< Port xmulti-function selection 3. */
#define GPIO_MFSELL_MFSELL4         		((uint32_t)0x000F0000)      /*!< Port xmulti-function selection 4. */
#define GPIO_MFSELL_MFSELL5         		((uint32_t)0x00F00000)      /*!< Port xmulti-function selection 5. */
#define GPIO_MFSELL_MFSELL6         		((uint32_t)0x0F000000)      /*!< Port xmulti-function selection 6. */
#define GPIO_MFSELL_MFSELL7         		((uint32_t)0xF0000000)      /*!< Port xmulti-function selection 7. */

/**
  * @brief GPIO_MFSELH register Bit definition
  */
#define GPIO_MFSELH_MFSELH0         		((uint32_t)0x0000000F)      /*!< Port xmulti-function selection 0. */
#define GPIO_MFSELH_MFSELH1         		((uint32_t)0x000000F0)      /*!< Port xmulti-function selection 1. */
#define GPIO_MFSELH_MFSELH2         		((uint32_t)0x00000F00)      /*!< Port xmulti-function selection 2. */
#define GPIO_MFSELH_MFSELH3         		((uint32_t)0x0000F000)      /*!< Port xmulti-function selection 3. */
#define GPIO_MFSELH_MFSELH4         		((uint32_t)0x000F0000)      /*!< Port xmulti-function selection 4. */
#define GPIO_MFSELH_MFSELH5         		((uint32_t)0x00F00000)      /*!< Port xmulti-function selection 5. */
#define GPIO_MFSELH_MFSELH6         		((uint32_t)0x0F000000)      /*!< Port xmulti-function selection 6. */
#define GPIO_MFSELH_MFSELH7         		((uint32_t)0xF0000000)      /*!< Port xmulti-function selection 7. */

/**
  * @brief GPIO_CLRR register Bit definition
  */
#define GPIO_CLRR_BCLR_0            		((uint32_t)0x00000001)      /*!< Port x bit clear 0. */
#define GPIO_CLRR_BCLR_1            		((uint32_t)0x00000002)      /*!< Port x bit clear 1. */
#define GPIO_CLRR_BCLR_2            		((uint32_t)0x00000004)      /*!< Port x bit clear 2. */
#define GPIO_CLRR_BCLR_3            		((uint32_t)0x00000008)      /*!< Port x bit clear 3. */
#define GPIO_CLRR_BCLR_4            		((uint32_t)0x00000010)      /*!< Port x bit clear 4. */
#define GPIO_CLRR_BCLR_5            		((uint32_t)0x00000020)      /*!< Port x bit clear 5. */
#define GPIO_CLRR_BCLR_6            		((uint32_t)0x00000040)      /*!< Port x bit clear 6. */
#define GPIO_CLRR_BCLR_7            		((uint32_t)0x00000080)      /*!< Port x bit clear 7. */
#define GPIO_CLRR_BCLR_8            		((uint32_t)0x00000100)      /*!< Port x bit clear 8. */
#define GPIO_CLRR_BCLR_9            		((uint32_t)0x00000200)      /*!< Port x bit clear 9. */
#define GPIO_CLRR_BCLR_10           		((uint32_t)0x00000400)      /*!< Port x bit clear 10. */
#define GPIO_CLRR_BCLR_11           		((uint32_t)0x00000800)      /*!< Port x bit clear 11. */
#define GPIO_CLRR_BCLR_12           		((uint32_t)0x00001000)      /*!< Port x bit clear 12. */
#define GPIO_CLRR_BCLR_13           		((uint32_t)0x00002000)      /*!< Port x bit clear 13. */

/*---------------------------------------------------------------------------*/
/*            Inter-integrated Circuit Interace (I2C)                        */
/*---------------------------------------------------------------------------*/

/**
  * @brief I2C_CTR1 register Bit definition 
*/
#define I2C_CTR1_I2CEN                       ((uint32_t)0x00000001)    /*!< I2C enable */
#define I2C_CTR1_TXINTFIE                    ((uint32_t)0x00000002)    /*!< Enable bit for TX interrupt */
#define I2C_CTR1_RXNEIE                      ((uint32_t)0x00000004)    /*!< Enable bit for RX interrupt */
#define I2C_CTR1_ADRMIE                      ((uint32_t)0x00000008)    /*!< Enable bit for Address match interrupt */
#define I2C_CTR1_NACKRIE                     ((uint32_t)0x00000010)    /*!< Enable bit for Not acknowledge received interrupt */
#define I2C_CTR1_STOPDIE                     ((uint32_t)0x00000020)    /*!< Enable bit for STOP detection interrupt */
#define I2C_CTR1_CMPIE                       ((uint32_t)0x00000040)    /*!< Enable bit for Transfer complete interrupt */
#define I2C_CTR1_ERRDIE                      ((uint32_t)0x00000080)    /*!< Enable bit for Error detection interrupt */
#define I2C_CTR1_DFCFG                       ((uint32_t)0x00000F00)    /*!< Digital filter configuration */
#define I2C_CTR1_AFDIS                       ((uint32_t)0x00001000)    /*!< Analog filter Disable */
#define I2C_CTR1_TXDMAREQEN                  ((uint32_t)0x00004000)    /*!< Enable bit for Transmission DMA requests */
#define I2C_CTR1_RXDMAREQEN                  ((uint32_t)0x00008000)    /*!< Enable bit for Reception DMA requests */
#define I2C_CTR1_SLVRC                       ((uint32_t)0x00010000)    /*!< Slave response control */
#define I2C_CTR1_DISSTRETCH                  ((uint32_t)0x00020000)    /*!< Disable clock stretching */
#define I2C_CTR1_WKUPEN                      ((uint32_t)0x00040000)    /*!< Enable bit for Stop mode Wakeup */
#define I2C_CTR1_GCEN                        ((uint32_t)0x00080000)    /*!< Enable bit for General call */
#define I2C_CTR1_SMBHAEN                     ((uint32_t)0x00100000)    /*!< Enable bit for SMBus Host address */
#define I2C_CTR1_SMBDDAEN                    ((uint32_t)0x00200000)    /*!< Enable bit for SMBus Device Default address */
#define I2C_CTR1_SMBAEN                      ((uint32_t)0x00400000)    /*!< SMBus alter enable */
#define I2C_CTR1_PECMEN                      ((uint32_t)0x00800000)    /*!< PEC mode enable */

/**
  * @brief I2C_CTR2 register Bit definition 
*/
#define I2C_CTR2_MTADR                       ((uint32_t)0x000003FF)    /*!< Master transfer address on I2C bus */
#define I2C_CTR2_TDIR                        ((uint32_t)0x00000400)    /*!< Direction of Transfer (master mode) */
#define I2C_CTR2_ADRFMT                      ((uint32_t)0x00000800)    /*!< Addressing format (master mode) */
#define I2C_CTR2_HEAD10AR                    ((uint32_t)0x00001000)    /*!< 10-bit address header only read direction */
#define I2C_CTR2_STARTGEN                    ((uint32_t)0x00002000)    /*!< Generate a Start on I2C bus */
#define I2C_CTR2_STOPGEN                     ((uint32_t)0x00004000)    /*!< Generate a Stop on I2C bus(master mode) */
#define I2C_CTR2_NACKGEN                     ((uint32_t)0x00008000)    /*!< Generate a NACK on I2C bus(slave mode) */
#define I2C_CTR2_BNUM                        ((uint32_t)0x00FF0000)    /*!< Bytes number */
#define I2C_CTR2_RELOADM                     ((uint32_t)0x01000000)    /*!< Bytes number reload mode */
#define I2C_CTR2_TENDSEL                     ((uint32_t)0x02000000)    /*!< Tranfer end mode selection(master mode) */
#define I2C_CTR2_PECCTR                      ((uint32_t)0x04000000)    /*!< PEC byte control */

/**
  * @brief I2C_SADR1 register Bit definition 
*/
#define I2C_SADR1_SADR1                      ((uint32_t)0x000003FF)    /*!< Slave Address 1 */
#define I2C_SADR1_SADR1MODE                  ((uint32_t)0x00000400)    /*!< Slave Address 1 10-bit mode */
#define I2C_SADR1_SADR1EN                    ((uint32_t)0x00008000)    /*!< Slave Address 1 enable */

/** 
  * @brief I2C_SADR2 register Bit definition    
*/  
#define I2C_SADR2_SADR2                      ((uint32_t)0x000000FE)    /*!<Slave Address 2 */
#define I2C_SADR2_SADR2MSK                   ((uint32_t)0x00000700)    /*!<Slave Address 2 masks */
#define I2C_SADR2_SADR2EN                    ((uint32_t)0x00008000)    /*!<Slave Address 2 enable */

/** 
  * @brief I2C_TMR register Bit definition  
*/  
#define I2C_TMR_SCLLT                        ((uint32_t)0x000000FF)    /*!< Master mode SCL low time */
#define I2C_TMR_SCLHT                        ((uint32_t)0x0000FF00)    /*!< Master mode SCL high time */
#define I2C_TMR_SDAHT                        ((uint32_t)0x000F0000)    /*!< SDA hold time */
#define I2C_TMR_SDAST                        ((uint32_t)0x00F00000)    /*!< SDA setup time */
#define I2C_TMR_TPDIV                        ((uint32_t)0xF0000000)    /*!< Timing pre-divider */

/**
  * @brief I2C_OVRT register Bit definition 
*/
#define I2C_OVRT_TIMA                        ((uint32_t)0x00000FFF)    /*!< Bus overtime A */
#define I2C_OVRT_IDLEDEN                     ((uint32_t)0x00001000)    /*!< Idle clock overtime detection */
#define I2C_OVRT_TIMAEN                      ((uint32_t)0x00008000)    /*!< timer A enable */
#define I2C_OVRT_TIMB                        ((uint32_t)0x0FFF0000)    /*!< Bus overtime B */
#define I2C_OVRT_TIMBEN                      ((uint32_t)0x80000000)    /*!< timer B enable */

/** 
  * @brief I2C_STS register Bit definition  
*/  
#define I2C_STS_TXEF                         ((uint32_t)0x00000001)    /*!< Data register empty flag in transmitting mode */
#define I2C_STS_TXINTF                       ((uint32_t)0x00000002)    /*!< Transmit interrupt flag */
#define I2C_STS_RXNEF                        ((uint32_t)0x00000004)    /*!< Data register not empty in receiving mode */
#define I2C_STS_ADRF                         ((uint32_t)0x00000008)    /*!< Slave mode Address matched flag */
#define I2C_STS_NACKF                        ((uint32_t)0x00000010)    /*!< NACK received flag */
#define I2C_STS_STOPF                        ((uint32_t)0x00000020)    /*!< Stop detection flag */
#define I2C_STS_CMPF                         ((uint32_t)0x00000040)    /*!< Master mode Transfer Complete flag */
#define I2C_STS_RLDF                         ((uint32_t)0x00000080)    /*!< Reload flag */
#define I2C_STS_BUSERRF                      ((uint32_t)0x00000100)    /*!< Bus error flag */
#define I2C_STS_ARBLOF                       ((uint32_t)0x00000200)    /*!< Arbitration lost flag */
#define I2C_STS_OVRF                         ((uint32_t)0x00000400)    /*!< Overtime or tLOW detection flag */
#define I2C_STS_PECERRF                      ((uint32_t)0x00000800)    /*!< PEC Error flag */
#define I2C_STS_TIMEOUT                      ((uint32_t)0x00001000)    /*!< Overtime or tLOW detection flag */
#define I2C_STS_SMBAF                        ((uint32_t)0x00002000)    /*!< SMBus alert flag */
#define I2C_STS_BUSYF                        ((uint32_t)0x00008000)    /*!< Bus busy flag */
#define I2C_STS_DIRF                         ((uint32_t)0x00010000)    /*!< Slave Transfer direction flag */
#define I2C_STS_MSLVA                        ((uint32_t)0x00FE0000)    /*!< Matched Slave Address */

/**
  * @brief I2C_STSC register Bit definition 
*/
#define I2C_STSC_ADRFC                       ((uint32_t)0x00000008)    /*!< Slave mode Address matched flag clear */
#define I2C_STSC_NACKFC                      ((uint32_t)0x00000010)    /*!< NACK received flag clear */
#define I2C_STSC_STOPFC                      ((uint32_t)0x00000020)    /*!< Stop detection flag clear */
#define I2C_STSC_BUSERRFC                    ((uint32_t)0x00000100)    /*!< Bus error flag clear */
#define I2C_STSC_ARLOFC                      ((uint32_t)0x00000200)    /*!< Arbittration Lost flag clear */
#define I2C_STSC_OVRFC                       ((uint32_t)0x00000400)    /*!< Slave Overflow/Underflow flag clear */
#define I2C_STSC_PECERRFC                    ((uint32_t)0x00000800)    /*!< PEC Error flag clear */
#define I2C_STSC_OVRTFC                      ((uint32_t)0x00001000)    /*!< Overtime detection flag clear */
#define I2C_STSC_SMBAFC                      ((uint32_t)0x00002000)    /*!< SMBus alert flag clear */

/**
  * @brief I2C_PECCODE register Bit definition 
*/
#define I2C_PECCODE_PECCODE                  ((uint32_t)0x000000FF)    /*!< Received PEC code */

/**
  * @brief I2C_RXBUF register Bit definition 
*/
#define I2C_RXBUF_RXBUF                      ((uint32_t)0x000000FF)    /*!< Receive buffer register */

/**
  * @brief I2C_TXBUF register Bit definition 
*/
#define I2C_TXBUF_TXBUF                      ((uint32_t)0x000000FF)    /*!< Transmit buffer register */

/**
  * @brief I2C_CTR3 register Bit definition 
*/
#define I2C_CTR3_BUSYHCLREN                  ((uint32_t)0x00000800)    /*!< Busy hardware clear enable */
#define I2C_CTR3_ADDRCNTEN                   ((uint32_t)0x00001000)    /*!< Address match timeout enable */


/**
  * @brief I2C_STS1 register Bit definition 
*/
#define I2C_STS1_ADDR_NOREC                  ((uint32_t)0x00000100)    /*!< Address accecpt abnormal flag */
#define I2C_STS1_BUSY_HCLR                   ((uint32_t)0x00000200)    /*!< Bus busy hardware check clear flag */

/**
  * @brief I2C_CTR4 register Bit definition 
*/
#define I2C_CTR4_TMOEN                       ((uint32_t)0x00000001)    /*!< I2c hardware check timeout enable */
#define I2C_CTR4_TMOM_CUMULATE               ((uint32_t)0x00000002)    /*!< I2c hardware cumulative check */
#define I2C_CTR4_TMOSEL_SCL_HIGH             ((uint32_t)0x00000004)    /*!< I2c hardware check signal SCL high level */
#define I2C_CTR4_TMOSEL_SDA_LOW              ((uint32_t)0x00000008)    /*!< I2c hardware check signal SDA low level */
#define I2C_CTR4_TMOSEL_SDA_HIGH             ((uint32_t)0x0000000C)    /*!< I2c hardware check signal SDA high level */
#define I2C_CTR4_TMOSEL_SCL_SDA_LOW          ((uint32_t)0x00000010)    /*!< I2c hardware check signal SCL and SDA low level */
#define I2C_CTR4_TMOSEL_SCL_SDA_HIGH         ((uint32_t)0x00000014)    /*!< I2c hardware check signal SCL and SDA high level */
#define I2C_CTR4_TMOSEN                      ((uint32_t)0x40000000)    /*!< I2c hardware check timeout enter error interrupt enable */
#define I2C_CTR4_FLAG_TMOS                   ((uint32_t)0x80000000)    /*!< I2c hardware check timeout flag */

/*----------------------------------------------------------------------------*/
/*                        Low Power Timer (LPTTIM)                            */
/*----------------------------------------------------------------------------*/

/**
  * @brief LPTIM_ISR register Bit definition
  */                                                                                                                      
#define LPTIM_ISR_CMPM                     ((uint32_t)0x00000001)       /*!< Compare match  */
#define LPTIM_ISR_ARRM                     ((uint32_t)0x00000002)       /*!< Autoreload match  */
#define LPTIM_ISR_EXTTRIG                  ((uint32_t)0x00000004)       /*!< External trigger edge event  */
#define LPTIM_ISR_CMPOK                    ((uint32_t)0x00000008)       /*!< Compare register update OK   */
#define LPTIM_ISR_ARROK                    ((uint32_t)0x00000010)       /*!< Autoreload register update OK   */
#define LPTIM_ISR_UP                       ((uint32_t)0x00000020)       /*!< Counter direction change down to up   */
#define LPTIM_ISR_DOWN                     ((uint32_t)0x00000040)       /*!< Counter direction change up to down   */
#define LPTIM_ISR_UE                       ((uint32_t)0x00000080)       /*!< Upadate event occured   */
#define LPTIM_ISR_REPOK                    ((uint32_t)0x00000100)       /*!< Repeat register update succeeded   */

/**
  * @brief LPTIM_ICR register Bit definition
  */ 
#define LPTIM_ICR_CMPMCF                   ((uint32_t)0x00000001)       /*!< Compare match Clear Flag   */
#define LPTIM_ICR_ARRMCF                   ((uint32_t)0x00000002)       /*!< Autoreload match Clear Flag   */
#define LPTIM_ICR_EXTTRIGCF                ((uint32_t)0x00000004)       /*!< External trigger edge event Clear Flag   */
#define LPTIM_ICR_CMPOKCF                  ((uint32_t)0x00000008)       /*!< Compare register update OK Clear Flag   */
#define LPTIM_ICR_ARROKCF                  ((uint32_t)0x00000010)       /*!< Autoreload register update OK Clear Flag   */
#define LPTIM_ICR_UPCF                     ((uint32_t)0x00000020)       /*!< Counter direction change down to up Clear Flag   */
#define LPTIM_ICR_DOWNCF                   ((uint32_t)0x00000040)       /*!< Counter direction change up to down Clear Flag   */
#define LPTIM_ICR_UECF                     ((uint32_t)0x00000080)       /*!< Upadate event occured Clear Flag   */
#define LPTIM_ICR_REPOKCF                  ((uint32_t)0x00000100)       /*!< Repeat register update succeeded Clear Flag   */

/**
  * @brief LPTIM_IER register Bit definition
  */ 
#define LPTIM_IER_CMPMIE                   ((uint32_t)0x00000001)       /*!< Compare match Interrupt Enable   */
#define LPTIM_IER_ARRMIE                   ((uint32_t)0x00000002)       /*!< Autoreload match Interrupt Enable   */
#define LPTIM_IER_EXTTRIGIE                ((uint32_t)0x00000004)       /*!< External trigger edge event Interrupt Enable   */
#define LPTIM_IER_CMPOKIE                  ((uint32_t)0x00000008)       /*!< Compare register update OK Interrupt Enable   */
#define LPTIM_IER_ARROKIE                  ((uint32_t)0x00000010)       /*!< Autoreload register update OK Interrupt Enable   */
#define LPTIM_IER_UPIE                     ((uint32_t)0x00000020)       /*!< Counter direction change down to up Interrupt Enable   */
#define LPTIM_IER_DOWNIE                   ((uint32_t)0x00000040)       /*!< Counter direction change up to down Interrupt Enable   */
#define LPTIM_IER_UEIE                     ((uint32_t)0x00000080)       /*!< Upadate event occured Interrupt Enable   */
#define LPTIM_IER_REPOKIE                  ((uint32_t)0x00000100)       /*!< Repeat register update succeeded Interrupt Enable   */
#define LPTIM_IER_ARRUFIE                  ((uint32_t)0x00000200)       /*!< Automatic overload counter underflow interrupt Enable   */

/**
  * @brief LPTIM_CFGR register Bit definition
  */
#define LPTIM_CFGR_CKSEL                   ((uint32_t)0x00000001)       /*!< Clock selector   */
#define LPTIM_CFGR_CKPOL                   ((uint32_t)0x00000006)       /*!< CKPOL[1:0] bits (Clock polarity)   */
#define LPTIM_CFGR_CKPOL_0                 ((uint32_t)0x00000002)       /*!< Bit 0 */
#define LPTIM_CFGR_CKPOL_1                 ((uint32_t)0x00000004)       /*!< Bit 1 */
#define LPTIM_CFGR_CKFLT                   ((uint32_t)0x00000018)       /*!< CKFLT[1:0] bits (Configurable digital filter for external clock)  */
#define LPTIM_CFGR_CKFLT_0                 ((uint32_t)0x00000008)       /*!< Bit 0 */
#define LPTIM_CFGR_CKFLT_1                 ((uint32_t)0x00000010)       /*!< Bit 1 */
#define LPTIM_CFGR_TRGFLT                  ((uint32_t)0x000000C0)       /*!< TRGFLT[1:0] bits (Configurable digital filter for trigger) */
#define LPTIM_CFGR_TRGFLT_0                ((uint32_t)0x00000040)       /*!< Bit 0 */
#define LPTIM_CFGR_TRGFLT_1                ((uint32_t)0x00000080)       /*!< Bit 1 */
#define LPTIM_CFGR_PRESC                   ((uint32_t)0x00000E00)       /*!< PRESC[2:0] bits (Clock prescaler)   */
#define LPTIM_CFGR_PRESC_0                 ((uint32_t)0x00000200)       /*!< Bit 0 */
#define LPTIM_CFGR_PRESC_1                 ((uint32_t)0x00000400)       /*!< Bit 1 */
#define LPTIM_CFGR_PRESC_2                 ((uint32_t)0x00000800)       /*!< Bit 2 */
#define LPTIM_CFGR_TRIGSEL                 ((uint32_t)0x0000E000)       /*!< TRIGSEL[2:0]] bits (Trigger selector)  */
#define LPTIM_CFGR_TRIGSEL_0               ((uint32_t)0x00002000)       /*!< Bit 0 */
#define LPTIM_CFGR_TRIGSEL_1               ((uint32_t)0x00004000)       /*!< Bit 1 */
#define LPTIM_CFGR_TRIGSEL_2               ((uint32_t)0x00008000)       /*!< Bit 2 */
#define LPTIM_CFGR_TRIGEN                  ((uint32_t)0x00060000)       /*!< TRIGEN[1:0] bits (Trigger enable and polarity) */
#define LPTIM_CFGR_TRIGEN_0                ((uint32_t)0x00020000)       /*!< Bit 0 */
#define LPTIM_CFGR_TRIGEN_1                ((uint32_t)0x00040000)       /*!< Bit 1 */
#define LPTIM_CFGR_TIMOUT                  ((uint32_t)0x00080000)       /*!< Timout enable */
#define LPTIM_CFGR_WAVE                    ((uint32_t)0x00100000)       /*!< Waveform shape */
#define LPTIM_CFGR_WAVPOL                  ((uint32_t)0x00200000)       /*!< Waveform shape polarity */
#define LPTIM_CFGR_PRELOAD                 ((uint32_t)0x00400000)       /*!< Reg update mode */
#define LPTIM_CFGR_COUNTMODE               ((uint32_t)0x00800000)       /*!< Counter mode enable */
#define LPTIM_CFGR_ENC                     ((uint32_t)0x01000000)       /*!< Encoder mode enable */

/**
  * @brief LPTIM_CR register Bit definition
  */
#define LPTIM_CR_ENABLE                    ((uint32_t)0x00000001)       /*!< LPTIMer enable */
#define LPTIM_CR_SNGSTRT                   ((uint32_t)0x00000002)       /*!< Timer start in single mode */
#define LPTIM_CR_CNTSTRT                   ((uint32_t)0x00000004)       /*!< Timer start in continuous mode */
#define LPTIM_CR_COUNTRST                  ((uint32_t)0x00000008)       /*!< Count reset */
#define LPTIM_CR_RSTARE                    ((uint32_t)0x00000010)       /*!< Reset enable after read operation */
                                                         
/**
  * @brief LPTIM_CMP register Bit definition
  */
#define LPTIM_CMP_CMP                      ((uint32_t)0x0000FFFF)       /*!< Compare register */
                                                                     
/**                                                                  
  * @brief LPTIM_ARR register Bit definition                         
  */                                                                 
#define LPTIM_ARR_ARR                      ((uint32_t)0x0000FFFF)       /*!< Auto reload register */
                                                                     
/**                                                                  
  * @brief LPTIM_CNT register Bit definition                         
  */                                                                 
#define LPTIM_CNT_CNT                      ((uint32_t)0x0000FFFF)       /*!< Counter register */
  
/**
  * @brief LPTIM_CFGR2 register Bit definition
  */  
#define LPTIM_CFGR2_IN1SEL                 ((uint32_t)0x00000003)       /*!< LPTIM input 1 selection */
#define LPTIM_CFGR2_IN2SEL                 ((uint32_t)0x00000030)       /*!< LPTIM input 2 selection */
   
/**
  * @brief LPTIM_RCR register Bit definition
  */  
#define LPTIM_RCR_REP                      ((uint32_t)0x000000FF)       /*!< Repeat count register */

/*--------------------------------------------------------------------------*/
/*                       PMU(Power management unit)                         */
/*--------------------------------------------------------------------------*/

/**
  * @brief PMU_CTR register Bit definition
  */
#define PMU_CTR_LDOLM                        ((uint32_t)0x00000001)      /*!< LDO low power control. */
#define PMU_CTR_DSMODE                       ((uint32_t)0x00000002)      /*!< Deepsleep mode or power down selection. */
#define PMU_CTR_CLRWUPF                      ((uint32_t)0x00000004)      /*!< Clear wakup flag. */
#define PMU_CTR_CLRPWDF                      ((uint32_t)0x00000008)      /*!< Clear power down flag. */
#define PMU_CTR_LVDEN                        ((uint32_t)0x00000010)      /*!< Low vlotage detector Enable. */

#define PMU_CTR_VBTWEN                       ((uint32_t)0x00000100)      /*!< Low vlotage detector Enable. */
#define PMU_CTR_HVDEN                        ((uint32_t)0x00000200)      /*!< Low vlotage detector Enable. */
#define PMU_CTR_LDOLVDEN                     ((uint32_t)0x00000400)      /*!< Low vlotage detector Enable. */
#define PMU_CTR_LDOHVDEN                     ((uint32_t)0x00000800)      /*!< Low vlotage detector Enable. */

#define PMU_CTR_LVDIE                        ((uint32_t)0x00001000)      /*!< Low vlotage detector Enable. */
#define PMU_CTR_HVDIE                        ((uint32_t)0x00002000)      /*!< Low vlotage detector Enable. */
#define PMU_CTR_LDOLVDIN                     ((uint32_t)0x00004000)      /*!< Low vlotage detector Enable. */
#define PMU_CTR_LDOHVDIN                     ((uint32_t)0x00008000)      /*!< Low vlotage detector Enable. */
#define PMU_CTR_LVD_FTR                      ((uint32_t)0x000E0000)      /*!< Low vlotage detector Enable. */
#define PMU_CTR_HVD_FTR                      ((uint32_t)0x00700000)      /*!< Low vlotage detector Enable. */


/**                                                                      
  * @brief PMU_CS register Bit definition                                
  */                                                                     
#define PMU_CS_WUPF                          ((uint32_t)0x00000001)      /*!< Wakeup flag. */
#define PMU_CS_PWDF                          ((uint32_t)0x00000002)      /*!< Power down flag. */
#define PMU_CS_LVD_VDD                       ((uint32_t)0x00000004)      /*!< AVDD/DVDD low vlotage detector. */
#define PMU_CS_WUPF1                         ((uint32_t)0x00000010)      /*!< Wkup1 awaken flag. */
#define PMU_CS_WUPF3                         ((uint32_t)0x00000040)      /*!< Wkup3 awaken flag. */
#define PMU_CS_WUPF4                         ((uint32_t)0x00000080)      /*!< Wkup4 awaken flag. */
#define PMU_CS_WUPEN1                        ((uint32_t)0x00000100)      /*!< Enable wkup pin 1. */
#define PMU_CS_WUPEN3                        ((uint32_t)0x00000400)      /*!< Enable wkup pin 3. */
#define PMU_CS_WUPEN4                        ((uint32_t)0x00000800)      /*!< Enable wkup pin 4. */
#define PMU_CS_WUPEN1_CFG                    ((uint32_t)0x00001000)      /*!< Wkup1 pin polarity cfg. */
#define PMU_CS_WUPEN3_CFG                    ((uint32_t)0x00004000)      /*!< Wkup3 pin polarity cfg. */
#define PMU_CS_WUPEN4_CFG                    ((uint32_t)0x00008000)      /*!< Wkup4 pin polarity cfg. */
#define PMU_CS_LVD_LDO                       ((uint32_t)0x00010000)      /*!< LDO lower 1.35V. */
#define PMU_CS_HVD_LDO                       ((uint32_t)0x00020000)      /*!< LDO higher 1.65V. */
#define PMU_CS_HVD_VDD                       ((uint32_t)0x00040000)      /*!< AVDD/DVDD higher HVD. */
#define PMU_CS_LDOLVDF                       ((uint32_t)0x01000000)      /*!< LDO low voltage occured. */
#define PMU_CS_LDOHVDF                       ((uint32_t)0x02000000)      /*!< LDO high voltage occured. */
#define PMU_CS_LVDF                          ((uint32_t)0x04000000)      /*!< AVDD/DVDD low voltage occured. */
#define PMU_CS_HVDF                          ((uint32_t)0x08000000)      /*!< AVDD/DVDD high voltage occured. */
#define PMU_CS_LPPD1IF                       ((uint32_t)0x10000000)      /*!< LDO low voltage int. */
#define PMU_CS_HPPD1IF                       ((uint32_t)0x20000000)      /*!< LDO high voltage int. */
#define PMU_CS_LPPD0IF                       ((uint32_t)0x40000000)      /*!< AVDD/DVDD low voltage int. */
#define PMU_CS_HPPD0IF                       ((uint32_t)0x80000000)      /*!< AVDD/DVDD high voltage int. */


/**                                                                      
  * @brief PMU_CTR2 register Bit definition                              
  */                                                                     
#define PMU_CTR2_LPPDEN                      ((uint32_t)0x00000001)      /*!< AVDD/DVDD low voltage dec enable. */
#define PMU_CTR2_LPPD_CLR                    ((uint32_t)0x00000008)      /*!< LPPD_CNT clear. */
#define PMU_CTR2_LPPD_CNT                    ((uint32_t)0x000000F0)      /*!< AVDD/DVDD low voltage pulse CNT. */
#define PMU_CTR2_LPPD_VTH                    ((uint32_t)0x00000F00)      /*!< AVDD/DVDD low voltage pulse VTH. */
#define PMU_CTR2_LPPDIE                      ((uint32_t)0x00001000)      /*!< AVDD/DVDD low voltage pulse INT enable. */

#define PMU_CTR2_HPPDEN                      ((uint32_t)0x00010000)      /*!< AVDD/DVDD high voltage dec enable. */
#define PMU_CTR2_HPPD_CLR                    ((uint32_t)0x00080000)      /*!< HPPD_CNT clear. */
#define PMU_CTR2_HPPD_CNT                    ((uint32_t)0x00F00000)      /*!< AVDD/DVDD high voltage pulse CNT. */
#define PMU_CTR2_HPPD_VTH                    ((uint32_t)0x0F000000)      /*!< AVDD/DVDD high voltage pulse VTH. */
#define PMU_CTR2_HPPDIE                      ((uint32_t)0x10000000)      /*!< AVDD/DVDD high voltage pulse INT enable. */


/**                                                                      
  * @brief PMU_CTR3 register Bit definition                              
  */                                                                     
#define PMU_CTR3_LPPD1EN                     ((uint32_t)0x00000001)     /*!< LDO low voltage dec enable. */
#define PMU_CTR3_LPPD1_CLR                   ((uint32_t)0x00000008)     /*!< LPPD1_CNT clear. */
#define PMU_CTR3_LPPD1_CNT                   ((uint32_t)0x000000F0)     /*!< LDO low voltage pulse CNT. */
#define PMU_CTR3_LPPD1_VTH                   ((uint32_t)0x00000F00)     /*!< LDO low voltage pulse VTH. */
#define PMU_CTR3_LPPD1IE                     ((uint32_t)0x00001000)     /*!< LDO low voltage pulse INT enable. */

#define PMU_CTR3_HPPD1EN                     ((uint32_t)0x00010000)     /*!< LDO high voltage dec enable. */
#define PMU_CTR3_HPPD1_CLR                   ((uint32_t)0x00080000)     /*!< HPPD1_CNT clear. */
#define PMU_CTR3_HPPD1_CNT                   ((uint32_t)0x00F00000)     /*!< LDO high voltage pulse CNT. */
#define PMU_CTR3_HPPD1_VTH                   ((uint32_t)0x0F000000)     /*!< LDO high voltage pulse VTH. */
#define PMU_CTR3_HPPD1IE                     ((uint32_t)0x10000000)     /*!< LDO high voltage pulse INT enable. */


/**                                                                      
  * @brief PMU_TS register Bit definition                                
  */                                                                     
#define PMU_TS_EN                            ((uint32_t)0x00000001)     /*!< Temperature sensor enable. */
#define PMU_TS_HSEL                          ((uint32_t)0x00000002)     /*!< Sensor high temperature threshold value. */
#define PMU_TS_LO                            ((uint32_t)0x00000004)     /*!< Sensor low temperature state. */
#define PMU_TS_HO                            ((uint32_t)0x00000008)     /*!< Sensor high temperature state. */
#define PMU_TS_LIE                           ((uint32_t)0x00000010)     /*!< Sensor low temperature INT enable. */
#define PMU_TS_HIE                           ((uint32_t)0x00000020)     /*!< Sensor high temperature INT enable. */
#define PMU_TS_CMPEN                         ((uint32_t)0x00000040)     /*!< Temperature sensor comparator enable. */
#define PMU_TS_LIF                           ((uint32_t)0x00000100)     /*!< Sensor low temperature INT flag. */
#define PMU_TS_HIF                           ((uint32_t)0x00000200)     /*!< Sensor high temperature INT flag. */

/*---------------------------------------------------------------------------*/
/*               Reset and Clock Control                                     */
/*---------------------------------------------------------------------------*/

/**
  * @brief RCU_CTR register Bit definition
  */
#define RCU_CTR_HRCEN                         ((uint32_t)0x00000001)       /*!< HRC Enable */
#define RCU_CTR_HRCSTAB                       ((uint32_t)0x00000002)       /*!< HRC Stabilization flag */
#define RCU_CTR_HRCCALIB                      ((uint32_t)0x0000FFF0)       /*!< HRC Internal 8MHz RC calibration */
#define RCU_CTR_HRC_IOPSEL                    ((uint32_t)0x30000000)       /*!< HRC internal current selection */
/*!< HRCRDY_CNT configuration */
#define RCU_CTR_HRCRDY_CNT                    ((uint32_t)0x0C000000)      /*!< HRCRDY_CNT[1:0] bits  */
#define RCU_CTR_HRCRDY_CNT_4CLK               ((uint32_t)0x00000000)      /*!< Wait 4 clocks when HRC starts,then the chip starts working */
#define RCU_CTR_HRCRDY_CNT_16CLK              ((uint32_t)0x04000000)      /*!< Wait 16 clocks when HRC starts,then the chip starts working */
#define RCU_CTR_HRCRDY_CNT_64CLK              ((uint32_t)0x08000000)      /*!< Wait 64 clocks when HRC starts,then the chip starts working */
#define RCU_CTR_HRCRDY_CNT_128CLK             ((uint32_t)0x0C000000)      /*!< Wait 128 clocks when HRC starts,then the chip starts working  */
/*!< HRCSEL configuration */
#define RCU_CTR_HRCSEL                        ((uint32_t)0xC0000000)      /*!< HRC[1:0] bits  */
#define RCU_CTR_HRC_24M                       ((uint32_t)0x00000000)      /*!< HRC clock 24M */
#define RCU_CTR_HRC_32M                       ((uint32_t)0x40000000)      /*!< HRC clock 32M */

/**
  * @brief RCU_CFG register Bit definition
  */
#define RCU_CFG_HCLKPDIV                      ((uint32_t)0x000000F0)       /*!< HCLKPDIV[3:0] bits (HCLK Pre-divider) */
#define RCU_CFG_HCLKPDIV_0                    ((uint32_t)0x00000010)       /*!< Bit 0 */
#define RCU_CFG_HCLKPDIV_1                    ((uint32_t)0x00000020)       /*!< Bit 1 */
#define RCU_CFG_HCLKPDIV_2                    ((uint32_t)0x00000040)       /*!< Bit 2 */
#define RCU_CFG_HCLKPDIV_3                    ((uint32_t)0x00000080)       /*!< Bit 3 */
#define RCU_CFG_PCLKPDIV                      ((uint32_t)0x00000700)       /*!< PCLKPDIV[2:0] bits (PCLK Pre-divider) */
/*!< HCLKPDIV configuration */
#define RCU_CFG_HCLKPDIV_DIV1                 ((uint32_t)0x00000000)       /*!< not divided */
#define RCU_CFG_HCLKPDIV_DIV2                 ((uint32_t)0x00000080)       /*!< divided by 2 */
#define RCU_CFG_HCLKPDIV_DIV4                 ((uint32_t)0x00000090)       /*!< divided by 4 */
#define RCU_CFG_HCLKPDIV_DIV8                 ((uint32_t)0x000000A0)       /*!< divided by 8 */
#define RCU_CFG_HCLKPDIV_DIV16                ((uint32_t)0x000000B0)       /*!< divided by 16 */
#define RCU_CFG_HCLKPDIV_DIV64                ((uint32_t)0x000000C0)       /*!< divided by 64 */
#define RCU_CFG_HCLKPDIV_DIV128               ((uint32_t)0x000000D0)       /*!< divided by 128 */
#define RCU_CFG_HCLKPDIV_DIV256               ((uint32_t)0x000000E0)       /*!< divided by 256 */
#define RCU_CFG_HCLKPDIV_DIV512               ((uint32_t)0x000000F0)       /*!< divided by 512 */

#define RCU_CFG_PCLKPDIV_0                    ((uint32_t)0x00000100)       /*!< Bit 0 */
#define RCU_CFG_PCLKPDIV_1                    ((uint32_t)0x00000200)       /*!< Bit 1 */
#define RCU_CFG_PCLKPDIV_2                    ((uint32_t)0x00000400)       /*!< Bit 2 */
/*!< PCLKPDIV configuration */
#define RCU_CFG_PCLKPDIV_DIV1                 ((uint32_t)0x00000000)       /*!< HCLK not divided */
#define RCU_CFG_PCLKPDIV_DIV2                 ((uint32_t)0x00000400)       /*!< HCLK divided by 2 */
#define RCU_CFG_PCLKPDIV_DIV4                 ((uint32_t)0x00000500)       /*!< HCLK divided by 4 */
#define RCU_CFG_PCLKPDIV_DIV8                 ((uint32_t)0x00000600)       /*!< HCLK divided by 8 */
#define RCU_CFG_PCLKPDIV_DIV16                ((uint32_t)0x00000700)       /*!< HCLK divided by 16 */

#define RCU_CFG_CKOSEL                        ((uint32_t)0x0F000000)       /*!< CLKOUT[2:0] bits CLKOUT Source Selection */
#define RCU_CFG_CKOSEL_0                      ((uint32_t)0x01000000)       /*!< Bit 0 */
#define RCU_CFG_CKOSEL_1                      ((uint32_t)0x02000000)       /*!< Bit 1 */
#define RCU_CFG_CKOSEL_2                      ((uint32_t)0x04000000)       /*!< Bit 2 */
#define RCU_CFG_CKOSEL_3                      ((uint32_t)0x08000000)       /*!< Bit 3 */
#define RCU_CFG_CKOPDIV                       ((uint32_t)0x70000000)       /*!< CLKOUT prescaler */
#define RCU_CFG_CKOPDIV_0                     ((uint32_t)0x10000000)       /*!< Bit 0 */
#define RCU_CFG_CKOPDIV_1                     ((uint32_t)0x20000000)       /*!< Bit 1 */
#define RCU_CFG_CKOPDIV_2                     ((uint32_t)0x40000000)       /*!< Bit 2 */

/**
  * @brief RCU_INTR register Bit definition
  */
#define RCU_INTR_LRCSTABIF                    ((uint32_t)0x00000001)       /*!< LRC stabilization Interrupt Flag */
#define RCU_INTR_HRCSTABIF                    ((uint32_t)0x00000004)       /*!< HRC stabilization Interrupt Flag */

#define RCU_INTR_LRCSTABIE                    ((uint32_t)0x00000100)       /*!< LRC stabilization Interrupt Enable */
#define RCU_INTR_HRCSTABIE                    ((uint32_t)0x00000400)       /*!< HRC stabilization Interrupt Enable */

#define RCU_INTR_LRCSTABIC                    ((uint32_t)0x00010000)       /*!< LRC stabilization Interrupt Clear */
#define RCU_INTR_HRCSTABIC                    ((uint32_t)0x00040000)       /*!< HRC stabilization Interrupt Clear */


/**
  * @brief RCU_APB2RST register Bit definition
  */
#define RCU_APB2RST_SYSCFGRST                 ((uint32_t)0x00000001)       /*!< SYSCFG reset */
#define RCU_APB2RST_ACTSRST                   ((uint32_t)0x00000002)       /*!< Active shield reset */
#define RCU_APB2RST_TIM1RST                   ((uint32_t)0x00000800)       /*!< TIM1 clock reset */
#define RCU_APB2RST_SPI1RST                   ((uint32_t)0x00001000)       /*!< SPI1 clock reset */
#define RCU_APB2RST_USART1RST                 ((uint32_t)0x00004000)       /*!< USART1 clock reset */
#define RCU_APB2RST_DBGRST                    ((uint32_t)0x00400000)       /*!< DBGMCU clock reset */

/**
  * @brief RCU_APB1RST register Bit definition
  */
#define RCU_APB1RST_TIM3RST                   ((uint32_t)0x00000002)       /*!< Timer 3 clock reset */
#define RCU_APB1RST_TIM14RST                  ((uint32_t)0x00000100)       /*!< Timer 14 clock reset */
#define RCU_APB1RST_WWDTRST                   ((uint32_t)0x00000800)       /*!< Window Watchdog clock reset */
#define RCU_APB1RST_SPI2RST                   ((uint32_t)0x00004000)       /*!< SPI2 clock reset */
#define RCU_APB1RST_USART2RST                 ((uint32_t)0x00020000)       /*!< USART 2 clock reset */
#define RCU_APB1RST_I2C1RST                   ((uint32_t)0x00200000)       /*!< I2C 1 clock reset */
#define RCU_APB1RST_PMURST                    ((uint32_t)0x10000000)       /*!< PMU clock reset */
#define RCU_APB1RST_LPTIM1RST                 ((uint32_t)0x80000000)       /*!< LPTIM1 clock reset */

/**
  * @brief RCU_AHBEN register Bit definition
  */
#define RCU_AHBEN_DMAEN                       ((uint32_t)0x00000001)       /*!< DMA clock enable */
#define RCU_AHBEN_SDMAEN                      ((uint32_t)0x00000002)       /*!< SDMA clock enable */
#define RCU_AHBEN_RMCEN                       ((uint32_t)0x00000004)       /*!< SRAM interface clock enable */
#define RCU_AHBEN_FMCEN                       ((uint32_t)0x00000010)       /*!< FMC clock enable */
#define RCU_AHBEN_CRCEN                       ((uint32_t)0x00000040)       /*!< CRC clock enable */
#define RCU_AHBEN_HDIVEN                      ((uint32_t)0x00000080)       /*!< HDIV clock enable */
#define RCU_AHBEN_PKEEN                       ((uint32_t)0x00000400)       /*!< PKE clock enable */
#define RCU_AHBEN_HASHEN                      ((uint32_t)0x00000800)       /*!< HASH clock enable */
#define RCU_AHBEN_TRNGEN                      ((uint32_t)0x00001000)       /*!< TRNG clock enable */
#define RCU_AHBEN_PAEN                        ((uint32_t)0x00020000)       /*!< GPIOA clock enable */

/**
  * @brief RCU_APB2EN register Bit definition
  */
#define RCU_APB2EN_SYSCFGEN                   ((uint32_t)0x00000001)       /*!< SYSCFG clock enable */
#define RCU_APB2EN_ACTSEN                     ((uint32_t)0x00000002)       /*!< Active shield clock enable */
#define RCU_APB2EN_RNGCKEN                    ((uint32_t)0x00000004)       /*!< RNG clock enable */
#define RCU_APB2EN_TIM1EN                     ((uint32_t)0x00000800)       /*!< TIM1 clock enable */
#define RCU_APB2EN_SPI1EN                     ((uint32_t)0x00001000)       /*!< SPI1 clock enable */
#define RCU_APB2EN_USART1EN                   ((uint32_t)0x00004000)       /*!< USART1 clock enable */
#define RCU_APB2EN_DBGEN                      ((uint32_t)0x00400000)       /*!< DBGMCU clock enable */

/**
  * @brief RCU_APB1EN register Bit definition
  */
#define RCU_APB1EN_TIM3EN                     ((uint32_t)0x00000002)       /*!< Timer 3 clock enable */
#define RCU_APB1EN_TIM14EN                    ((uint32_t)0x00000100)       /*!< Timer 14 clock enable */
#define RCU_APB1EN_WWDTEN                     ((uint32_t)0x00000800)       /*!< Window Watchdog clock enable */
#define RCU_APB1EN_SPI2EN                     ((uint32_t)0x00004000)       /*!< SPI2 clock enable */
#define RCU_APB1EN_USART2EN                   ((uint32_t)0x00020000)       /*!< USART2 clock enable */
#define RCU_APB1EN_I2C1EN                     ((uint32_t)0x00200000)       /*!< I2C1 clock enable */
#define RCU_APB1EN_PMUEN                      ((uint32_t)0x10000000)       /*!< PMU clock enable */
#define RCU_APB1EN_LPTIM1EN                   ((uint32_t)0x80000000)       /*!< LPTIM1 clock reset */

/**
  * @brief RCU_VBDC register Bit definition
  */

#define RCU_VBDC_RTCCLKEN                     ((uint32_t)0x00008000)       /*!< RTC clock enable */
#define RCU_VBDC_RTCRST                       ((uint32_t)0x00010000)       /*!< RTC reset */

/**
  * @brief RCU_STS register Bit definition
  */
#define RCU_STS_LRCEN                         ((uint32_t)0x00000001)       /*!< LRC enable */
#define RCU_STS_LRCSTAB                       ((uint32_t)0x00000002)       /*!< LRC Stabilization flag */
#define RCU_STS_REGERRRSTF                    ((uint32_t)0x00400000)       /*!< register error reset flag */
#define RCU_STS_V15RSTF                       ((uint32_t)0x00800000)       /*!< Reset flag from the 1.5V domain */
#define RCU_STS_CRSTF                         ((uint32_t)0x01000000)       /*!< Clear reset Flag */
#define RCU_STS_OBURSTF                       ((uint32_t)0x02000000)       /*!< Option byte Update reset flag */
#define RCU_STS_NRSTF                         ((uint32_t)0x04000000)       /*!< reset flag of pin nRST */
#define RCU_STS_PORRSTF                       ((uint32_t)0x08000000)       /*!< POR/PDR reset flag */
#define RCU_STS_SWRSTF                        ((uint32_t)0x10000000)       /*!< Software reset flag */
#define RCU_STS_FWDTRSTF                      ((uint32_t)0x20000000)       /*!< FWDT reset flag */
#define RCU_STS_WWDTRSTF                      ((uint32_t)0x40000000)       /*!< WWDT reset flag */
#define RCU_STS_LPERSTF                       ((uint32_t)0x80000000)       /*!< Low power enter reset flag */

/**
  * @brief RCU_AHBRST register Bit definition
  */
#define RCU_AHBRST_SDMARST                    ((uint32_t)0x00000002)       /*!< SDMA clock reset */
#define RCU_AHBRST_CRCRST                     ((uint32_t)0x00000040)       /*!< CRC clock reset */
#define RCU_AHBRST_HDIVRST                    ((uint32_t)0x00000080)       /*!< HDIV clock reset */
#define RCU_AHBRST_PKERST                     ((uint32_t)0x00000400)       /*!< PKE clock reset */
#define RCU_AHBRST_HASHRST                    ((uint32_t)0x00000800)       /*!< HASH clock reset */
#define RCU_AHBRST_TRNGRST                    ((uint32_t)0x00001000)       /*!< TRNG clock reset */
#define RCU_AHBRST_PARST                      ((uint32_t)0x00020000)       /*!< PORT A clock reset */


/**
  * @brief RCU_CFG3 register Bit definition
  */
#define RCU_CFG3_USART1SEL                    ((uint32_t)0x00000003)       /*!< USART1SEL[1:0] bits */
#define RCU_CFG3_USART1SEL_0                  ((uint32_t)0x00000001)       /*!< Bit 0 */
#define RCU_CFG3_USART1SEL_1                  ((uint32_t)0x00000002)       /*!< Bit 1 */
#define RCU_CFG3_I2C1SEL                      ((uint32_t)0x00000010)       /*!< I2C1SEL bits */
#define RCU_CFG3_LPTIM1SEL                    ((uint32_t)0xC0000000)       /*!< LPTIM1SEL[1:0] bits */
#define RCU_CFG3_LPTIM1SEL_SCLK               ((uint32_t)0x40000000)       /*!< LPTIM1 clock use systick clock */  


/*--------------------------------------------------------------------------*/
/*                           RTC(Real-Time Clock)                           */
/*--------------------------------------------------------------------------*/

/**
  * @brief RTC_TIME register Bit definition
  */
#define RTC_TIME_PM                 		((uint32_t)0x00400000)      /*!< AM/PM notation. */
#define RTC_TIME_HORTEN             		((uint32_t)0x00300000)      /*!< HORTEN[1:0] (hour tens (BCD)). */
#define RTC_TIME_HORTEN_0           		((uint32_t)0x00100000)      /*!< Bit 0. */
#define RTC_TIME_HORTEN_1           		((uint32_t)0x00200000)      /*!< Bit 1. */
#define RTC_TIME_HORUNT             		((uint32_t)0x000F0000)      /*!< HORUNT[3:0] (hour units (BCD)). */
#define RTC_TIME_HORUNT_0           		((uint32_t)0x00010000)      /*!< Bit 0. */
#define RTC_TIME_HORUNT_1           		((uint32_t)0x00020000)      /*!< Bit 1. */
#define RTC_TIME_HORUNT_2           		((uint32_t)0x00040000)      /*!< Bit 2. */
#define RTC_TIME_HORUNT_3           		((uint32_t)0x00080000)      /*!< Bit 3. */
#define RTC_TIME_MINTEN             		((uint32_t)0x00007000)      /*!< MINTEN[2:0] (minute tens (BCD)). */
#define RTC_TIME_MINTEN_0           		((uint32_t)0x00001000)      /*!< Bit 0. */
#define RTC_TIME_MINTEN_1           		((uint32_t)0x00002000)      /*!< Bit 1. */
#define RTC_TIME_MINTEN_2           		((uint32_t)0x00004000)      /*!< Bit 2. */
#define RTC_TIME_MINUNT             		((uint32_t)0x00000F00)      /*!< MINUNT[3:0] (minute units (BCD)). */
#define RTC_TIME_MINUNT_0           		((uint32_t)0x00000100)      /*!< Bit 0. */
#define RTC_TIME_MINUNT_1           		((uint32_t)0x00000200)      /*!< Bit 1. */
#define RTC_TIME_MINUNT_2           		((uint32_t)0x00000400)      /*!< Bit 2. */
#define RTC_TIME_MINUNT_3           		((uint32_t)0x00000800)      /*!< Bit 3. */
#define RTC_TIME_SECTEN             		((uint32_t)0x00000070)      /*!< SECTEN[2:0] (second tens (BCD)). */
#define RTC_TIME_SECTEN_0           		((uint32_t)0x00000010)      /*!< Bit 0. */
#define RTC_TIME_SECTEN_1           		((uint32_t)0x00000020)      /*!< Bit 1. */
#define RTC_TIME_SECTEN_2           		((uint32_t)0x00000040)      /*!< Bit 2. */
#define RTC_TIME_SECUNT             		((uint32_t)0x0000000F)      /*!< SECUNT[3:0]. */
#define RTC_TIME_SECUNT_0           		((uint32_t)0x00000001)      /*!< Bit 0. */
#define RTC_TIME_SECUNT_1           		((uint32_t)0x00000002)      /*!< Bit 1. */
#define RTC_TIME_SECUNT_2           		((uint32_t)0x00000004)      /*!< Bit 2. */
#define RTC_TIME_SECUNT_3           		((uint32_t)0x00000008)      /*!< Bit 3. */
  
/**                                                                    
  * @brief RTC_DATE register Bit definition                            
  */                                                                   
#define RTC_DATE_YTEN               		((uint32_t)0x00F00000)      /*!< YTEN[3:0] (year tens (BCD)). */
#define RTC_DATE_YTEN_0             		((uint32_t)0x00100000)      /*!< Bit 0. */
#define RTC_DATE_YTEN_1             		((uint32_t)0x00200000)      /*!< Bit 1. */
#define RTC_DATE_YTEN_2             		((uint32_t)0x00400000)      /*!< Bit 2. */
#define RTC_DATE_YTEN_3             		((uint32_t)0x00800000)      /*!< Bit 3. */
#define RTC_DATE_YUNT               		((uint32_t)0x000F0000)      /*!< YUNT[3:0] (year units (BCD)). */
#define RTC_DATE_YUNT_0             		((uint32_t)0x00010000)      /*!< Bit  0. */
#define RTC_DATE_YUNT_1             		((uint32_t)0x00020000)      /*!< Bit  1. */
#define RTC_DATE_YUNT_2             		((uint32_t)0x00040000)      /*!< Bit   2. */
#define RTC_DATE_YUNT_3             		((uint32_t)0x00080000)      /*!< Bit  3. */
#define RTC_DATE_WUNT               		((uint32_t)0x0000E000)      /*!< WUNT[2:0] (week day units). */
#define RTC_DATE_WUNT_0             		((uint32_t)0x00002000)      /*!< Bit 0. */
#define RTC_DATE_WUNT_1             		((uint32_t)0x00004000)      /*!< Bit 1. */
#define RTC_DATE_WUNT_2             		((uint32_t)0x00008000)      /*!< Bit 2. */
#define RTC_DATE_MTEN               		((uint32_t)0x00001000)      /*!< MTEN (month tens (BCD)). */
#define RTC_DATE_MUNT               		((uint32_t)0x00000F00)      /*!< MUNT[3:0] (month units (BCD)). */
#define RTC_DATE_MUNT_0             		((uint32_t)0x00000100)      /*!< Bit 0. */
#define RTC_DATE_MUNT_1             		((uint32_t)0x00000200)      /*!< Bit 1. */
#define RTC_DATE_MUNT_2             		((uint32_t)0x00000400)      /*!< Bit 2. */
#define RTC_DATE_MUNT_3             		((uint32_t)0x00000800)      /*!< Bit 3. */
#define RTC_DATE_DTEN               		((uint32_t)0x00000030)      /*!< DTEN[1:0] (date tens (BCD)). */
#define RTC_DATE_DTEN_0             		((uint32_t)0x00000010)      /*!< Bit 0. */
#define RTC_DATE_DTEN_1             		((uint32_t)0x00000020)      /*!< Bit 1. */
#define RTC_DATE_DUNT               		((uint32_t)0x0000000F)      /*!< DUNT[3:0] (date units (BCD)). */
#define RTC_DATE_DUNT_0             		((uint32_t)0x00000001)      /*!< Bit 0. */
#define RTC_DATE_DUNT_1             		((uint32_t)0x00000002)      /*!< Bit 1. */
#define RTC_DATE_DUNT_2             		((uint32_t)0x00000004)      /*!< Bit 2. */
#define RTC_DATE_DUNT_3             		((uint32_t)0x00000008)      /*!< Bit 3. */
  
/**                                                                    
  * @brief RTC_CTR register Bit definition                             
  */                                                                   
#define RTC_CTR_OUTSRC              		((uint32_t)0x00600000)      /*!< Output source. */
#define RTC_CTR_OUTSRC_0            		((uint32_t)0x00200000)      /*!< Bit 0. */
#define RTC_CTR_OUTSRC_1            		((uint32_t)0x00400000)      /*!< Bit 1. */
#define RTC_CTR_APOL                		((uint32_t)0x00100000)      /*!< Alarm Output polarity. */
#define RTC_CTR_SAVEF               		((uint32_t)0x00040000)      /*!< Saving time flag. */
#define RTC_CTR_DEC1H               		((uint32_t)0x00020000)      /*!< Decrease 1 hour. */
#define RTC_CTR_INC1H               		((uint32_t)0x00010000)      /*!< Increase 1 hour. */
#define RTC_CTR_WUTIE               		((uint32_t)0x00004000)      /*!< Wakeup time interrupt enable. */
#define RTC_CTR_ALRIE               		((uint32_t)0x00001000)      /*!< Alarm interrupt enable. */
#define RTC_CTR_WUTE                		((uint32_t)0x00000400)      /*!< Wakeup timer enable. */
#define RTC_CTR_ALRE                		((uint32_t)0x00000100)      /*!< Alarm enable. */
#define RTC_CTR_FMT12               		((uint32_t)0x00000040)      /*!< Hour format. */
#define RTC_CTR_DAR                 		((uint32_t)0x00000020)      /*!< Direct access register. */
#define RTC_CTR_WUCKSEL             		((uint32_t)0x00000007)      /*!< Wakeup clock select. */
  
/**                                                                    
  * @brief RTC_STS register Bit definition                             
  */                                                                   
#define RTC_STS_WUTF                		((uint32_t)0x00000400)      /*!< Wakeup timer flag. */
#define RTC_STS_ALRF                		((uint32_t)0x00000100)      /*!< Alarm flag. */
#define RTC_STS_INITE               		((uint32_t)0x00000080)      /*!< Initialization mode enbale. */
#define RTC_STS_INITF               		((uint32_t)0x00000040)      /*!< Initialization mode endter flag. */
#define RTC_STS_RSF                 		((uint32_t)0x00000020)      /*!< Registers synchronization flag. */
#define RTC_STS_INITS               		((uint32_t)0x00000010)      /*!< Initialization status flag. */
#define RTC_STS_SHF_BUSY            		((uint32_t)0x00000008)      /*!< Shift busy. */
#define RTC_STS_WUTWF               		((uint32_t)0x00000004)      /*!< Wakeup timer write flag. */
#define RTC_STS_ALRWAF              		((uint32_t)0x00000001)      /*!<  Alarm write access flag. */
 
/**
  * @brief RTC_PDIV register Bit definition
  */
#define RTC_PDIV_PDIV1              		((uint32_t)0x007F0000)      /*!< Dirst pre-divider factor. */
#define RTC_PDIV_PDIV2              		((uint32_t)0x00007FFF)      /*!< Second pre-divider factor. */
 
 /**
   * @brief RTC_WUTR register Bit definition
   */
#define RTC_WUTR_WUT                		((uint32_t)0x0000FFFF)      /*!< Wakeup reload value. */
 
/**
  * @brief RTC_ACFG1 register Bit definition
  */
#define RTC_ACFG1_WDBYP             		((uint32_t)0x80000000)      /*!< Week/Date bypass. */
#define RTC_ACFG1_WDSEL             		((uint32_t)0x40000000)      /*!< Week/Date selection. */
#define RTC_ACFG1_DTEN              		((uint32_t)0x30000000)      /*!< DTEN[1:0] date tens (BCD). */
#define RTC_ACFG1_DTEN_0            		((uint32_t)0x10000000)      /*!< Bit 0. */
#define RTC_ACFG1_DTEN_1            		((uint32_t)0x20000000)      /*!< Bit 1. */
#define RTC_ACFG1_DUNT              		((uint32_t)0x0F000000)      /*!< DUNT[3:0] date units (BCD). */
#define RTC_ACFG1_DUNT_0            		((uint32_t)0x01000000)      /*!< Bit 0. */
#define RTC_ACFG1_DUNT_1            		((uint32_t)0x02000000)      /*!< Bit 1. */
#define RTC_ACFG1_DUNT_2            		((uint32_t)0x04000000)      /*!< Bit 2. */
#define RTC_ACFG1_DUNT_3            		((uint32_t)0x08000000)      /*!< Bit 3. */
#define RTC_ACFG1_HORBYP            		((uint32_t)0x00800000)      /*!< hours bypass. */
#define RTC_ACFG1_PM                		((uint32_t)0x00400000)      /*!< AM/PM notation. */
#define RTC_ACFG1_HORTEN            		((uint32_t)0x00300000)      /*!< HORTEN[1:0] hour tens (BCD). */
#define RTC_ACFG1_HORTEN_0          		((uint32_t)0x00100000)      /*!< Bit 0. */
#define RTC_ACFG1_HORTEN_1          		((uint32_t)0x00200000)      /*!< Bit 1. */
#define RTC_ACFG1_HORUNT            		((uint32_t)0x000F0000)      /*!< HORUNT[3:0] hour units (BCD). */
#define RTC_ACFG1_HORUNT_0          		((uint32_t)0x00010000)      /*!< Bit 0. */
#define RTC_ACFG1_HORUNT_1          		((uint32_t)0x00020000)      /*!< Bit 1. */
#define RTC_ACFG1_HORUNT_2          		((uint32_t)0x00040000)      /*!< Bit 2. */
#define RTC_ACFG1_HORUNT_3          		((uint32_t)0x00080000)      /*!< Bit 3. */
#define RTC_ACFG1_MINBYP            		((uint32_t)0x00008000)      /*!< Minutes bypass. */
#define RTC_ACFG1_MINTEN            		((uint32_t)0x00007000)      /*!< MINTEN[2:0] minute tens (BCD). */
#define RTC_ACFG1_MINTEN_0          		((uint32_t)0x00001000)      /*!< Bit 0. */
#define RTC_ACFG1_MINTEN_1          		((uint32_t)0x00002000)      /*!< Bit 1. */
#define RTC_ACFG1_MINTEN_2          		((uint32_t)0x00004000)      /*!< Bit 2. */
#define RTC_ACFG1_MINUNT            		((uint32_t)0x00000F00)      /*!< MINUNT[3:0] minute units (BCD). */
#define RTC_ACFG1_MINUNT_0          		((uint32_t)0x00000100)      /*!< Bit 0. */
#define RTC_ACFG1_MINUNT_1          		((uint32_t)0x00000200)      /*!< Bit 1. */
#define RTC_ACFG1_MINUNT_2          		((uint32_t)0x00000400)      /*!< Bit 2. */
#define RTC_ACFG1_MINUNT_3          		((uint32_t)0x00000800)      /*!< Bit 3. */
#define RTC_ACFG1_SECBYP            		((uint32_t)0x00000080)      /*!< Seconds bypass. */
#define RTC_ACFG1_SECTEN            		((uint32_t)0x00000070)      /*!< SECTEN[2:0] second tens (BCD). */
#define RTC_ACFG1_SECTEN_0          		((uint32_t)0x00000010)      /*!< Bit 0. */
#define RTC_ACFG1_SECTEN_1          		((uint32_t)0x00000020)      /*!< Bit 1. */
#define RTC_ACFG1_SECTEN_2          		((uint32_t)0x00000040)      /*!< Bit 2. */
#define RTC_ACFG1_SECUNT            		((uint32_t)0x0000000F)      /*!< SECUNT[3:0] second units (BCD). */
#define RTC_ACFG1_SECUNT_0          		((uint32_t)0x00000001)      /*!< Bit 0. */
#define RTC_ACFG1_SECUNT_1          		((uint32_t)0x00000002)      /*!< Bit 1. */
#define RTC_ACFG1_SECUNT_2          		((uint32_t)0x00000004)      /*!< Bit 2. */
#define RTC_ACFG1_SECUNT_3          		((uint32_t)0x00000008)      /*!< Bit 3. */
 
 /**
   * @brief RTC_CCODE register Bit definition
   */
#define RTC_CCODE_CCODE             		((uint32_t)0x000000FF)      /*!< Control code. */

/**
  * @brief RTC_SSEC register Bit definition
  */
#define RTC_SSEC_SSEC               		((uint32_t)0x0000FFFF)      /*!< Subsecond. */

/**
  * @brief RTC_MF register Bit definition
  */
#define RTC_MF_PC12CFG                      ((uint32_t)0x00080000)      /*!< PA12 config. */
#define RTC_MF_PC12DATA                     ((uint32_t)0x00040000)      /*!< RTC_ALARM output type/PA12 output data. */

/**
  * @brief RTC_ACFG2 register Bit definition
  */
#define RTC_ACFG2_SSECBYP                   ((uint32_t)0x0F000000)      /*!< SSECBYP[3:0] subsecond bypass. */
#define RTC_ACFG2_SSECBYP_0                 ((uint32_t)0x01000000)      /*!< Bit 0. */
#define RTC_ACFG2_SSECBYP_1                 ((uint32_t)0x02000000)      /*!< Bit 1. */
#define RTC_ACFG2_SSECBYP_2                 ((uint32_t)0x04000000)      /*!< Bit 2. */
#define RTC_ACFG2_SSECBYP_3                 ((uint32_t)0x08000000)      /*!< Bit 3. */
#define RTC_ACFG2_SSEC                      ((uint32_t)0x00007FFF)      /*!< Subsecond. */

/**
  * @brief RTC_AO0 register Bit definition
  */
#define RTC_AO0                     	 	((uint32_t)0xFFFFFFFF)      /*!< RTC always on registers 0. */

/**
  * @brief RTC_AO1 register Bit definition
  */
#define RTC_AO1                     	 	((uint32_t)0xFFFFFFFF)      /*!< RTC always on registers 1. */

/**
  * @brief RTC_AO2 register Bit definition
  */
#define RTC_AO2                     	 	((uint32_t)0xFFFFFFFF)      /*!< RTC always on registers 2. */


/**
  * @brief RTC_AO3 register Bit definition
  */
#define RTC_AO3                      	 	((uint32_t)0xFFFFFFFF)      /*!< RTC always on registers 3. */

/**
  * @brief RTC_AO4 register Bit definition
  */
#define RTC_AO4                      	 	((uint32_t)0xFFFFFFFF)      /*!< RTC always on registers 4. */

/*--------------------------------------------------------------------------*/
/*                     SPI(Serial Peripheral Interface)                     */
/*--------------------------------------------------------------------------*/

/**
  * @brief SPI_CTR1 register Bit definition
  */
#define SPI_CTR1_CPHA              		    ((uint16_t)0x0001)          /*!< Clock Phase. */
#define SPI_CTR1_CPOL              		    ((uint16_t)0x0002)          /*!< Clock Polarity. */
#define SPI_CTR1_SPIM              			((uint16_t)0x0004)          /*!< SPI mode. */
#define SPI_CTR1_CRSEL             			((uint16_t)0x0038)          /*!< Communication rate selection. */
#define SPI_CTR1_CRSEL_0           			((uint16_t)0x0008)          /*!< Bit 0. */
#define SPI_CTR1_CRSEL_1           			((uint16_t)0x0010)          /*!< Bit 1. */
#define SPI_CTR1_CRSEL_2           			((uint16_t)0x0020)          /*!< Bit 2. */
#define SPI_CTR1_SPIEN             			((uint16_t)0x0040)          /*!< SPI enable. */
#define SPI_CTR1_LSBF              			((uint16_t)0x0080)          /*!< LSB first. */
#define SPI_CTR1_NVSWNSSM          			((uint16_t)0x0100)          /*!< NSS value in software NSS mode. */
#define SPI_CTR1_SWNSSM            			((uint16_t)0x0200)          /*!< software NSS mode. */
#define SPI_CTR1_ROM               			((uint16_t)0x0400)          /*!< Receive only mode. */
#define SPI_CTR1_CRC16             			((uint16_t)0x0800)          /*!< 16-bit CRC enable. */
#define SPI_CTR1_NXTCRC            			((uint16_t)0x1000)          /*!< Next CRC transfer. */
#define SPI_CTR1_CRCEN             			((uint16_t)0x2000)          /*!< CRC calculation enable. */
#define SPI_CTR1_SBOEN             			((uint16_t)0x4000)          /*!< Single-wire bidirectional output enable. */
#define SPI_CTR1_SBMODE            			((uint16_t)0x8000)          /*!< Single-wire bidirectional mode. */
 
 /**                                                                    
   * @brief SPI_CTR2 register Bit definition                            
   */                                                                   
#define SPI_CTR2_DMARXEN           			((uint16_t)0x0001)          /*!< DMA enable for receive. */
#define SPI_CTR2_DMATXEN           			((uint16_t)0x0002)          /*!< DMA enable for transmit. */
#define SPI_CTR2_NSSOEN            			((uint16_t)0x0004)          /*!< NSS output enable. */
#define SPI_CTR2_NSSPM             			((uint16_t)0x0008)          /*!< NSS pulse mode. */
#define SPI_CTR2_TIEN              			((uint16_t)0x0010)          /*!< SPI TI mode enable. */
#define SPI_CTR2_ERRINTEN          			((uint16_t)0x0020)          /*!< Enable bit for error interrupt. */
#define SPI_CTR2_RXNEINTEN         			((uint16_t)0x0040)          /*!< Enable bit for receive buffer Not Empty Interrupt. */
#define SPI_CTR2_TXEINTEN          			((uint16_t)0x0080)          /*!< Enable bit for transmit Buffer Empty Interrupt. */
#define SPI_CTR2_DLEN              			((uint16_t)0x0F00)          /*!< DLEN data length. */
#define SPI_CTR2_DLEN_0            			((uint16_t)0x0100)          /*!< Bit 0. */
#define SPI_CTR2_DLEN_1            			((uint16_t)0x0200)          /*!< Bit 1. */
#define SPI_CTR2_DLEN_2            			((uint16_t)0x0400)          /*!< Bit 2. */
#define SPI_CTR2_DLEN_3            			((uint16_t)0x0800)          /*!< Bit 3. */
#define SPI_CTR2_RXNE8             			((uint16_t)0x1000)          /*!< RXNE generate condition selection. */
#define SPI_CTR2_DMARXODD          			((uint16_t)0x2000)          /*!< Number of data to receive with DMA is odd. */
#define SPI_CTR2_DMATXODD          			((uint16_t)0x4000)          /*!< Number of data to transmit with DMA is odd. */
   
 /**                                                                    
   * @brief SPI_STS register Bit definition                             
   */                                                                   
#define SPI_STS_RXNE              	 		((uint16_t)0x0001)          /*!< Receive buffer not empty. */
#define SPI_STS_TXE                			((uint16_t)0x0002)          /*!< Transmit buffer empty. */
#define SPI_STS_I2SCSF             			((uint16_t)0x0004)          /*!< I2S Channel side flag. */
#define SPI_STS_TXUFERR            			((uint16_t)0x0008)          /*!< Transmitter data underflow error. */
#define SPI_STS_CRCERR             			((uint16_t)0x0010)          /*!< CRC error. */
#define SPI_STS_MMERR              			((uint16_t)0x0020)          /*!< Multi-master error. */
#define SPI_STS_RXOFERR            			((uint16_t)0x0040)          /*!< Receiver data overflow error. */
#define SPI_STS_BUSY               			((uint16_t)0x0080)          /*!< Busy. */
#define SPI_STS_NWERR              			((uint16_t)0x0100)          /*!< Error of SPI NSS or I2S ws. */
#define SPI_STS_RXFIFOS            			((uint16_t)0x0600)          /*!< Receive FIFO status. */
#define SPI_STS_RXFIFOS_0          			((uint16_t)0x0200)          /*!< Bit 0. */
#define SPI_STS_RXFIFOS_1          			((uint16_t)0x0400)          /*!< Bit 1. */
#define SPI_STS_TXFIFOS            			((uint16_t)0x1800)          /*!< Transmit FIFO status. */
#define SPI_STS_TXFIFOS_0          			((uint16_t)0x0800)          /*!< Bit 0. */
#define SPI_STS_TXFIFOS_1          			((uint16_t)0x1000)          /*!< Bit 1. */

/**
  * @brief SPI_DATA register Bit definition
  */
#define SPI_DATA_DATA               		((uint16_t)0xFFFF)          /*!< Transfer data. */

/**
  * @brief SPI_CRCPOLYR register Bit definition 
  */
#define SPI_CRCPOLYR_CRCPR          		((uint16_t)0xFFFF)          /*!< CRC polynomial register. */

/**                                                                     
  * @brief SPI_RCRC register Bit definition                             
  */                                                                    
#define SPI_RCRC_RCR                		((uint16_t)0xFFFF)          /*!< RX CRC register. */

/**                                                                     
  * @brief SPI_TCRC register Bit definition                             
  */                                                                    
#define SPI_TCRC_TCR                		((uint16_t)0xFFFF)          /*!< TX CRC register. */

/*--------------------------------------------------------------------------*/
/*                       SYSCFG(System Configuration)                       */
/*--------------------------------------------------------------------------*/

/**
  * @brief SYSCFG_RMAPCFG register Bit definition
  */
#define SYSCFG_RMAPCFG_MEM_RMAP              ((uint32_t)0x00000003)      /*!< Memory remapping selection. */
#define SYSCFG_RMAPCFG_MEM_RMAP_0            ((uint32_t)0x00000001)      /*!< SYSCFG_Memory remap bit 0. */
#define SYSCFG_RMAPCFG_MEM_RMAP_1            ((uint32_t)0x00000002)      /*!< SYSCFG_Memory remap bit 1. */

#define SYSCFG_RMAPCFG_USART1TX_DMA_CHRMAP   ((uint32_t)0x00000200)      /*!< USART1 tx DMA remap. */
#define SYSCFG_RMAPCFG_USART1RX_DMA_CHRMAP   ((uint32_t)0x00000400)      /*!< USART1 rx DMA remap. */

#define SYSCFG_RMAPCFG_I2C_FMPEN_PA10_MASK   ((uint32_t)0x00300000)      /*!< Fast mode mask on PA10. */
#define SYSCFG_RMAPCFG_I2C_FMPEN_PA11_MASK   ((uint32_t)0x00C00000)      /*!< Fast mode mask on PA11. */


/**                                                                     
  * @brief SYSCFG_RAMBOOT register Bit definition                       
  */                                                                    
#define SYSCFG_RAMBOOT_FORBID                ((uint32_t)0x00000001)      /*!< Memory remapping selection. */


/**                                                                     
  * @brief SYSCFG_EXTISRC1 register Bit definition                      
  */                                                                    
#define SYSCFG_EXTISRC1_EXTI0SEL0            ((uint16_t)0x000F) 		 /*!< EXTI0SEL 0 configuration. */

/**                                                                     
  * @brief  EXTI0SEL0  configuration                                    
  */                                                                    
#define SYSCFG_EXTISRC1_EXTI0SEL0_PA         ((uint16_t)0x0000) 		 /*!< PA[0] pin. */

/**                                                                     
  * @brief  EXTI0SEL1 configuration                                     
  */                                                                    
#define SYSCFG_EXTISRC1_EXTI0SEL1_PA         ((uint16_t)0x0000) 		 /*!< PA[1] pin. */

/**                                                                     
  * @brief  EXTI0SEL2 configuration                                     
  */                                                                    
#define SYSCFG_EXTISRC1_EXTI0SEL2_PA         ((uint16_t)0x0000)		 	 /*!< PA[2] pin. */

/**                                                                     
  * @brief  EXTI0SEL3 configuration                                     
  */                                                                    
#define SYSCFG_EXTISRC1_EXTI0SEL3_PA         ((uint16_t)0x0000) 		 /*!< PA[3] pin. */

/**                                                                     
  * @brief SYSCFG_EXTISRC2 register Bit definition                      
  */                                                                    
#define SYSCFG_EXTISRC2_EXTI0SEL4            ((uint16_t)0x000F) 		 /*!< EXTI0SEL 4 configuration. */

/**                                                                     
  * @brief  EXTI0SEL4 configuration                                     
  */                                                                    
#define SYSCFG_EXTISRC2_EXTI0SEL4_PA         ((uint16_t)0x0000) 		 /*!< PA[4] pin. */


/**                                                                     
  * @brief  EXTI0SEL5 configuration                                     
  */                                                                    
#define SYSCFG_EXTISRC2_EXTI0SEL5_PA         ((uint16_t)0x0000) 		 /*!< PA[5] pin. */

/**                                                                     
  * @brief  EXTI0SEL6 configuration                                     
  */                                                                    
#define SYSCFG_EXTISRC2_EXTI0SEL6_PA         ((uint16_t)0x0000) 		 /*!< PA[6] pin. */

/**                                                                     
  * @brief  EXTI0SEL7 configuration                                     
  */                                                                    
#define SYSCFG_EXTISRC2_EXTI0SEL7_PA         ((uint16_t)0x0000) 		 /*!< PA[7] pin. */


/**                                                                     
  * @brief SYSCFG_EXTISRC3 register Bit definition                      
  */                                                                    
#define SYSCFG_EXTISRC3_EXTI0SEL8            ((uint16_t)0x000F) 		 /*!< EXTI0SEL 8 configuration. */

/**                                                                     
  * @brief  EXTI8 configuration                                         
  */                                                                    
#define SYSCFG_EXTISRC3_EXTI0SEL8_PA         ((uint16_t)0x0000) 		 /*!< PA[8] pin. */

/**                                                                     
  * @brief  EXTI9 configuration                                         
  */                                                                    
#define SYSCFG_EXTISRC3_EXTI0SEL9_PA         ((uint16_t)0x0000) 		 /*!< PA[9] pin. */

/**                                                                     
  * @brief  EXTI10 configuration                                        
  */                                                                    
#define SYSCFG_EXTISRC3_EXTI0SEL10_PA        ((uint16_t)0x0000) 		 /*!< PA[10] pin. */

/**                                                                     
  * @brief EXTI11 configuration                                         
  */                                                                    
#define SYSCFG_EXTISRC3_EXTI0SEL11_PA        ((uint16_t)0x0000) 		 /*!< PA[11] pin. */


/**                                                                     
  * @brief SYSCFG_EXTISRC4 register Bit definition                      
  */                                                                    
#define SYSCFG_EXTISRC4_EXTI0SEL12           ((uint16_t)0x000F) 		 /*!< EXTI0SEL 12 configuration. */

/**                                                                     
  * @brief  EXTI12 configuration                                        
  */                                                                    
#define SYSCFG_EXTISRC4_EXTI0SEL12_PA        ((uint16_t)0x0000) 		 /*!< PA[12] pin. */

/**
  * @brief  EXTI13 configuration
  */
#define SYSCFG_EXTISRC4_EXTI0SEL13_PA        ((uint16_t)0x0000) 		 /*!< PA[13] pin. */

/**                                                                     
  * @brief  EXTI14 configuration                                        
  */                                                                    
#define SYSCFG_EXTISRC4_EXTI0SEL14_PA        ((uint16_t)0x0000) 		 /*!< PA[14] pin. */

/**                                                                      
  * @brief  EXTI15 configuration                                         
  */                                                                     
#define SYSCFG_EXTISRC4_EXTI0SEL15_PA        ((uint16_t)0x0000) 		 /*!< PA[15] pin. */


/**                                                                      
  * @brief SYSCFG_ERRLOCK register Bit definition                        
  */                                                                     
#define SYSCFG_ERRLOCK_LOCKUP_TIMBRK_LOCK    ((uint32_t)0x00000001) 	 /*!< Cortex-M0 LOCKUP lock to tim break enable. */
#define SYSCFG_ERRLOCK_SRAM_PRTY_TIMBRK_LOCK ((uint32_t)0x00000002) 	 /*!< SRAM parity lock to tim break. */
#define SYSCFG_ERRLOCK_LVD_TIMBRK_LOCK       ((uint32_t)0x00000004) 	 /*!< PVD output lock to tim break enable. */
#define SYSCFG_ERRLOCK_SRAM_PRTY_ERR         ((uint32_t)0x00000100) 	 /*!< SRAM parity error flag. */


/**                                                                      
  * @brief SYSCFG_GPIOA register Bit definition                          
  */                                                                     
#define SYSCFG_GPIOA_VTH_PA10				 ((uint32_t)0x00030000) 	 /*!< SYSCFG PA10 voltage threshold configuration. */
#define SYSCFG_GPIOA_VTH_PA11				 ((uint32_t)0x000C0000) 	 /*!< SYSCFG PA11 voltage threshold configuration. */


/**                                                                      
  * @brief SYSCFG_TRNG register Bit definition                           
  */                                                                     
#define SYSCFG_TRNG_BYEN					 ((uint32_t)0x00000001) 	 /*!< SYSCFG trng bypass enable. */
#define SYSCFG_TRNG_CKS            		     ((uint32_t)0x00000004) 	 /*!< SYSCFG trng clock select. */
#define SYSCFG_TRNG_KEY					     ((uint32_t)0xFFFF0000) 	 /*!< SYSCFG trng key. */


/**                                                                      
  * @brief SYSCFG_AFE register Bit definition                            
  */                                                                     
#define SYSCFG_AFE_CON					     ((uint32_t)0x00000001) 	 /*!< SYSCFG AFE charge. */
#define SYSCFG_AFE_DON            		     ((uint32_t)0x00000002) 	 /*!< SYSCFG AFE discharge. */
#define SYSCFG_AFE_RST					     ((uint32_t)0x00000004) 	 /*!< SYSCFG AFE reset. */
#define SYSCFG_AFE_KEY					     ((uint32_t)0xFFFF0000) 	 /*!< SYSCFG AFE key. */


/*----------------------------------------------------------------------------*/
/*                     Timers (TIMx)                                          */
/*----------------------------------------------------------------------------*/

/**
  * @brief TIMx_CTR1 register Bit definition
  */
#define TIM_CTR1_CEN                        ((uint16_t)0x0001)         /*!< Counter enable */
#define TIM_CTR1_UPD                        ((uint16_t)0x0002)         /*!< Update disable */
#define TIM_CTR1_URSEL                      ((uint16_t)0x0004)         /*!< Update request selection */
#define TIM_CTR1_SPEN                       ((uint16_t)0x0008)         /*!< Single pulse enable */
#define TIM_CTR1_DIR                        ((uint16_t)0x0010)         /*!< Direction */

#define TIM_CTR1_CPS                        ((uint16_t)0x0060)         /*< Count pattern selection */
#define TIM_CTR1_CPS_0                      ((uint16_t)0x0020)         /*< Bit 0 */
#define TIM_CTR1_CPS_1                      ((uint16_t)0x0040)         /*< Bit 1 */

#define TIM_CTR1_UVALSEN                    ((uint16_t)0x0080)         /*< UVAL shadow enable */

#define TIM_CTR1_CKDIV                      ((uint16_t)0x0300)         /*< Clock division */
#define TIM_CTR1_CKDIV_0                    ((uint16_t)0x0100)         /*< Bit 0 */
#define TIM_CTR1_CKDIV_1                    ((uint16_t)0x0200)         /*< Bit 1 */

/**
  * @brief TIMx_CTR2 register Bit definition
  */
#define TIM_CTR2_CHPSEN                     ((uint16_t)0x0001)         /*< Preload shadow enable of channel */
#define TIM_CTR2_CHPUS                      ((uint16_t)0x0004)         /*< Preload update source of channel */
#define TIM_CTR2_CHDMARS                    ((uint16_t)0x0008)         /*< DMA request source of channel */

#define TIM_CTR2_MMTOC                      ((uint16_t)0x0070)         /*< Master mode trigger out control */
#define TIM_CTR2_MMTOC_0                    ((uint16_t)0x0010)         /*< Bit 0 */
#define TIM_CTR2_MMTOC_1                    ((uint16_t)0x0020)         /*< Bit 1 */
#define TIM_CTR2_MMTOC_2                    ((uint16_t)0x0040)         /*< Bit 2 */

#define TIM_CTR2_TI1XOR                     ((uint16_t)0x0080)         /*< XOR input for TI1 */
#define TIM_CTR2_IVO1                       ((uint16_t)0x0100)         /*< Idle value output of channel 1 */
#define TIM_CTR2_IVO1N                      ((uint16_t)0x0200)         /*< Idle value output of channel 1 complementary */
#define TIM_CTR2_IVO2                       ((uint16_t)0x0400)         /*< Idle value output of channel 2 */
#define TIM_CTR2_IVO2N                      ((uint16_t)0x0800)         /*< Idle value output of channel 2 complementary */
#define TIM_CTR2_IVO3                       ((uint16_t)0x1000)         /*< Idle value output of channel 3 */
#define TIM_CTR2_IVO3N                      ((uint16_t)0x2000)         /*< Idle value output of channel 3 complementary */
#define TIM_CTR2_IVO4                       ((uint16_t)0x4000)         /*!< Idle value output of channel 4 */

/**
  * @brief TIMx_SMCFG register Bit definition
  */
#define TIM_SMCFG_SMCFG                     ((uint16_t)0x0007)         /*!< SMCFG[2:0] bits (Slave mode configuration) */
#define TIM_SMCFG_SMCFG_0                   ((uint16_t)0x0001)         /*!< Bit 0 */
#define TIM_SMCFG_SMCFG_1                   ((uint16_t)0x0002)         /*!< Bit 1 */
#define TIM_SMCFG_SMCFG_2                   ((uint16_t)0x0004)         /*!< Bit 2 */

#define TIM_SMCFG_TRIGS                     ((uint16_t)0x0070)         /*!< TRIGS[2:0] bits (Trigger source selection) */
#define TIM_SMCFG_TRIGS_0                   ((uint16_t)0x0010)         /*!< Bit 0 */
#define TIM_SMCFG_TRIGS_1                   ((uint16_t)0x0020)         /*!< Bit 1 */
#define TIM_SMCFG_TRIGS_2                   ((uint16_t)0x0040)         /*!< Bit 2 */

#define TIM_SMCFG_MSM                       ((uint16_t)0x0080)         /*!< Master/slave mode */

#define TIM_SMCFG_ETFLT                     ((uint16_t)0x0F00)         /*!< ETFLT[3:0] bits (External trigger filter) */
#define TIM_SMCFG_ETFLT_0                   ((uint16_t)0x0100)         /*!< Bit 0 */
#define TIM_SMCFG_ETFLT_1                   ((uint16_t)0x0200)         /*!< Bit 1 */
#define TIM_SMCFG_ETFLT_2                   ((uint16_t)0x0400)         /*!< Bit 2 */
#define TIM_SMCFG_ETFLT_3                   ((uint16_t)0x0800)         /*!< Bit 3 */

#define TIM_SMCFG_ETPDIV                    ((uint16_t)0x3000)         /*!< ETPDIV[1:0] bits (External trigger pre-divide) */
#define TIM_SMCFG_ETPDIV_0                  ((uint16_t)0x1000)         /*!< Bit 0 */
#define TIM_SMCFG_ETPDIV_1                  ((uint16_t)0x2000)         /*!< Bit 1 */

#define TIM_SMCFG_ECMODE2                   ((uint16_t)0x4000)         /*!< External clock mode 2 enable */
#define TIM_SMCFG_ETRINV                    ((uint16_t)0x8000)         /*!< ETR invert */

/**
  * @brief TIMx_DIEN register Bit definition
  */
#define TIM_DIEN_UPINTEN                    ((uint16_t)0x0001)         /*!<Enable bit for update interrupt */
#define TIM_DIEN_CH1INTEN                   ((uint16_t)0x0002)         /*!< Enable bit for channel 1 interrupt */
#define TIM_DIEN_CH2INTEN                   ((uint16_t)0x0004)         /*!< Enable bit for channel 2 interrupt */
#define TIM_DIEN_CH3INTEN                   ((uint16_t)0x0008)         /*!< Enable bit for channel 3 interrupt */
#define TIM_DIEN_CH4INTEN                   ((uint16_t)0x0010)         /*!< Enable bit for channel 4 interrupt */
#define TIM_DIEN_COMINTEN                   ((uint16_t)0x0020)         /*!< Enable bit for COM event interrupt */
#define TIM_DIEN_TINTEN                     ((uint16_t)0x0040)         /*!< Enable bit for trigger interrupt */
#define TIM_DIEN_BRKINTEN                   ((uint16_t)0x0080)         /*!< Enable bit for break interrupt */
#define TIM_DIEN_UPDEN                      ((uint16_t)0x0100)         /*!< Enable bit for update DMA request */
#define TIM_DIEN_CH1DEN                     ((uint16_t)0x0200)         /*!< Enable bit for channel 1 DMA request */
#define TIM_DIEN_CH2DEN                     ((uint16_t)0x0400)         /*!< Enable bit for channel 2 DMA request */
#define TIM_DIEN_CH3DEN                     ((uint16_t)0x0800)         /*!< Enable bit for channel 3 DMA request */
#define TIM_DIEN_CH4DEN                     ((uint16_t)0x1000)         /*!< Enable bit for channel 4 DMA request */
#define TIM_DIEN_COMDEN                     ((uint16_t)0x2000)         /*!< Enable bit for COM event DMA request */
#define TIM_DIEN_TDREN                      ((uint16_t)0x4000)         /*!< Enable bit for trigger DMA request */

/**
  * @brief TIMx_STS register Bit definition
  */
#define TIM_STS_UPIF                       ((uint16_t)0x0001)          /*!< Interrupt flag of update */
#define TIM_STS_CH1CCIF                    ((uint16_t)0x0002)          /*!< Channel 1 capture compare interrupt flag */
#define TIM_STS_CH2CCIF                    ((uint16_t)0x0004)          /*!< Channel 2 capture compare interrupt flag */
#define TIM_STS_CH3CCIF                    ((uint16_t)0x0008)          /*!< Channel 3 capture compare interrupt flag */
#define TIM_STS_CH4CCIF                    ((uint16_t)0x0010)          /*!< Channel 4 capture compare interrupt flag */
#define TIM_STS_CHCOMIF                    ((uint16_t)0x0020)          /*!< channel communication event interrupt flag */
#define TIM_STS_TRIGIF                     ((uint16_t)0x0040)          /*!< Interrupt flag of trigger */
#define TIM_STS_BRKIF                      ((uint16_t)0x0080)          /*!< Interrupt flag of break */
#define TIM_STS_CH1ICOF                    ((uint16_t)0x0200)          /*!< Channel 1 input capture overflow */
#define TIM_STS_CH2ICOF                    ((uint16_t)0x0400)          /*!< Channel 2 input capture overflow */
#define TIM_STS_CH3ICOF                    ((uint16_t)0x0800)          /*!< Channel 3 input capture overflow */
#define TIM_STS_CH4ICOF                    ((uint16_t)0x1000)          /*!< Channel 4 input capture overflow */

/**
  * @brief TIMx_SWEGR register Bit definition
  */
#define TIM_SWEGR_UEG                      ((uint16_t)0x0001)          /*!< Update event generation */
#define TIM_SWEGR_CH1CCG                   ((uint16_t)0x0002)          /*!< Channel 1 capture compare event generation */
#define TIM_SWEGR_CH2CCG                   ((uint16_t)0x0004)          /*!< Channel 2 capture compare event generation */
#define TIM_SWEGR_CH3CCG                   ((uint16_t)0x0008)          /*!< Channel 3 capture compare event generation */
#define TIM_SWEGR_CH4CCG                   ((uint16_t)0x0010)          /*!< Channel 4 capture compare event generation */
#define TIM_SWEGR_COMEG                    ((uint16_t)0x0020)          /*!< COM event generation */
#define TIM_SWEGR_TRIGEG                   ((uint16_t)0x0040)          /*!< Trigger event generation */
#define TIM_SWEGR_BRKEG                    ((uint16_t)0x0080)          /*!< Break event generation */

/**
  * @brief TIMx_CH12CFGR register Bit definition
  */
#define TIM_CH12CFGR_CH1FS                 ((uint16_t)0x0003)          /*!<CH1FS[1:0] bits (Channel 1 function selection) */
#define TIM_CH12CFGR_CH1FS_0               ((uint16_t)0x0001)          /*!<Bit 0 */
#define TIM_CH12CFGR_CH1FS_1               ((uint16_t)0x0002)          /*!<Bit 1 */

#define TIM_CH12CFGR_CH1OCFEN              ((uint16_t)0x0004)          /*!< Channel 1 output compare fast enable */
#define TIM_CH12CFGR_CH1OCVPEN             ((uint16_t)0x0008)          /*!< Channel 1 output compare value preload enable */

#define TIM_CH12CFGR_CH1OCMSEL             ((uint16_t)0x0070)          /*!<CH1OCMSEL[2:0] bits (Channel 1 output compare mode selection) */
#define TIM_CH12CFGR_CH1OCMSEL_0           ((uint16_t)0x0010)          /*!<Bit 0 */
#define TIM_CH12CFGR_CH1OCMSEL_1           ((uint16_t)0x0020)          /*!<Bit 1 */
#define TIM_CH12CFGR_CH1OCMSEL_2           ((uint16_t)0x0040)          /*!<Bit 2 */

#define TIM_CH12CFGR_CH1OCCEN              ((uint16_t)0x0080)          /*!< Channel 1 output compare clear enable */

#define TIM_CH12CFGR_CH2FS                 ((uint16_t)0x0300)          /*!<CH2FS[1:0] bits (Channel 2 function selection) */
#define TIM_CH12CFGR_CH2FS_0               ((uint16_t)0x0100)          /*!<Bit 0 */
#define TIM_CH12CFGR_CH2FS_1               ((uint16_t)0x0200)          /*!<Bit 1 */

#define TIM_CH12CFGR_CH2OCFEN              ((uint16_t)0x0400)          /*!< Channel 2 output compare fast enable */
#define TIM_CH12CFGR_CH2OCVPEN             ((uint16_t)0x0800)          /*!< Channel 2 output compare value preload enable */

#define TIM_CH12CFGR_CH2OCMSEL             ((uint16_t)0x7000)          /*!<CH2OCMSEL[2:0] bits (Channel 2 output compare mode selection) */
#define TIM_CH12CFGR_CH2OCMSEL_0           ((uint16_t)0x1000)          /*!<Bit 0 */
#define TIM_CH12CFGR_CH2OCMSEL_1           ((uint16_t)0x2000)          /*!<Bit 1 */
#define TIM_CH12CFGR_CH2OCMSEL_2           ((uint16_t)0x4000)          /*!<Bit 2 */

#define TIM_CH12CFGR_CH2OCCEN              ((uint16_t)0x8000)          /*!< Channel 2 output compare clear enable */

/*----------------------------------------------------------------------------*/

#define TIM_CH12CFGR_CH1ICPDIV             ((uint16_t)0x000C)          /*!<CH1ICPDIV[1:0] bits (Channel 1 input capture pre-divide) */
#define TIM_CH12CFGR_CH1ICPDIV_0           ((uint16_t)0x0004)          /*!<Bit 0 */
#define TIM_CH12CFGR_CH1ICPDIV_1           ((uint16_t)0x0008)          /*!<Bit 1 */

#define TIM_CH12CFGR_CH1ICFLT              ((uint16_t)0x00F0)          /*!<CH1ICFLT[3:0] bits (Channel 1 input capture filter) */
#define TIM_CH12CFGR_CH1ICFLT_0            ((uint16_t)0x0010)          /*!<Bit 0 */
#define TIM_CH12CFGR_CH1ICFLT_1            ((uint16_t)0x0020)          /*!<Bit 1 */
#define TIM_CH12CFGR_CH1ICFLT_2            ((uint16_t)0x0040)          /*!<Bit 2 */
#define TIM_CH12CFGR_CH1ICFLT_3            ((uint16_t)0x0080)          /*!<Bit 3 */

#define TIM_CH12CFGR_CH2ICPDIV             ((uint16_t)0x0C00)          /*!<CH2ICPDIV[1:0] bits (Channel 2 input capture pre-divide) */
#define TIM_CH12CFGR_CH2ICPDIV_0           ((uint16_t)0x0400)          /*!<Bit 0 */
#define TIM_CH12CFGR_CH2ICPDIV_1           ((uint16_t)0x0800)          /*!<Bit 1 */

#define TIM_CH12CFGR_CH2ICFLT              ((uint16_t)0xF000)          /*!<CH2ICFLT[3:0] bits (Channel 2 input capture filter) */
#define TIM_CH12CFGR_CH2ICFLT_0            ((uint16_t)0x1000)          /*!<Bit 0 */
#define TIM_CH12CFGR_CH2ICFLT_1            ((uint16_t)0x2000)          /*!<Bit 1 */
#define TIM_CH12CFGR_CH2ICFLT_2            ((uint16_t)0x4000)          /*!<Bit 2 */
#define TIM_CH12CFGR_CH2ICFLT_3            ((uint16_t)0x8000)          /*!<Bit 3 */

/**
  * @brief TIMx_CH34CFGR register Bit definition
  */
#define TIM_CH34CFGR_CH3FS                 ((uint16_t)0x0003)          /*!< CH3FS[1:0] bits (Channel 3 function selection) */
#define TIM_CH34CFGR_CH3FS_0               ((uint16_t)0x0001)          /*!<Bit 0 */
#define TIM_CH34CFGR_CH3FS_1               ((uint16_t)0x0002)          /*!<Bit 1 */

#define TIM_CH34CFGR_CH3OCFEN              ((uint16_t)0x0004)          /*!< Channel 3 output compare fast enable */
#define TIM_CH34CFGR_CH3OCVPEN             ((uint16_t)0x0008)          /*!< Channel 3 output compare value preload enable */

#define TIM_CH34CFGR_CH3OCMSEL             ((uint16_t)0x0070)          /*!<CH3OCMSEL[2:0] bits (Channel 3 output compare mode selection) */
#define TIM_CH34CFGR_CH3OCMSEL_0           ((uint16_t)0x0010)          /*!<Bit 0 */
#define TIM_CH34CFGR_CH3OCMSEL_1           ((uint16_t)0x0020)          /*!<Bit 1 */
#define TIM_CH34CFGR_CH3OCMSEL_2           ((uint16_t)0x0040)          /*!<Bit 2 */

#define TIM_CH34CFGR_CH3OCCEN              ((uint16_t)0x0080)          /*!< Channel 3 output compare clear enable */

#define TIM_CH34CFGR_CH4FS                 ((uint16_t)0x0300)          /*!<CH4FS[1:0] bits (Channel 4 function selection */
#define TIM_CH34CFGR_CH4FS_0               ((uint16_t)0x0100)          /*!<Bit 0 */
#define TIM_CH34CFGR_CH4FS_1               ((uint16_t)0x0200)          /*!<Bit 1 */

#define TIM_CH34CFGR_CH4OCFEN              ((uint16_t)0x0400)          /*!< Channel 4 output compare fast enable */
#define TIM_CH34CFGR_CH4OCVPEN             ((uint16_t)0x0800)          /*!< Channel 4 output compare value preload enable */

#define TIM_CH34CFGR_CH4OCMSEL             ((uint16_t)0x7000)          /*!<CH4OCMSEL[2:0] bits (Channel 4 output compare mode selection) */
#define TIM_CH34CFGR_CH4OCMSEL_0           ((uint16_t)0x1000)          /*!<Bit 0 */
#define TIM_CH34CFGR_CH4OCMSEL_1           ((uint16_t)0x2000)          /*!<Bit 1 */
#define TIM_CH34CFGR_CH4OCMSEL_2           ((uint16_t)0x4000)          /*!<Bit 2 */

#define TIM_CH34CFGR_CH4OCCEN              ((uint16_t)0x8000)          /*!< Channel 4 output compare clear enable */

/*----------------------------------------------------------------------------*/

#define TIM_CH34CFGR_CH3ICPDIV             ((uint16_t)0x000C)          /*!< CH3ICPDIV[1:0] bits (Channel 3 input capture pre-divide) */
#define TIM_CH34CFGR_CH3ICPDIV_0           ((uint16_t)0x0004)          /*!< Bit 0 */
#define TIM_CH34CFGR_CH3ICPDIV_1           ((uint16_t)0x0008)          /*!< Bit 1 */

#define TIM_CH34CFGR_CH3ICFLT              ((uint16_t)0x00F0)          /*!< CH3ICFLT[3:0] bits (Channel 3 input capture filter) */
#define TIM_CH34CFGR_CH3ICFLT_0            ((uint16_t)0x0010)          /*!< Bit 0 */
#define TIM_CH34CFGR_CH3ICFLT_1            ((uint16_t)0x0020)          /*!< Bit 1 */
#define TIM_CH34CFGR_CH3ICFLT_2            ((uint16_t)0x0040)          /*!< Bit 2 */
#define TIM_CH34CFGR_CH3ICFLT_3            ((uint16_t)0x0080)          /*!< Bit 3 */

#define TIM_CH34CFGR_CH4ICPDIV             ((uint16_t)0x0C00)          /*!< CH4ICPDIV[1:0] bits (Channel 4 input capture pre-divide) */
#define TIM_CH34CFGR_CH4ICPDIV_0           ((uint16_t)0x0400)          /*!< Bit 0 */
#define TIM_CH34CFGR_CH4ICPDIV_1           ((uint16_t)0x0800)          /*!< Bit 1 */

#define TIM_CH34CFGR_CH4ICFLT              ((uint16_t)0xF000)          /*!<CH4ICFLT[3:0] bits (Channel 4 input capture filter) */
#define TIM_CH34CFGR_CH4ICFLT_0            ((uint16_t)0x1000)          /*!<Bit 0 */
#define TIM_CH34CFGR_CH4ICFLT_1            ((uint16_t)0x2000)          /*!<Bit 1 */
#define TIM_CH34CFGR_CH4ICFLT_2            ((uint16_t)0x4000)          /*!<Bit 2 */
#define TIM_CH34CFGR_CH4ICFLT_3            ((uint16_t)0x8000)          /*!<Bit 3 */

/**
  * @brief TIMx_CCCTR register Bit definition
  */
#define TIM_CCCTR_CH1CCEN                  ((uint16_t)0x0001)          /*!< Channel 1 capture compare enable */
#define TIM_CCCTR_CH1CCP                   ((uint16_t)0x0002)          /*!< Channel 1 capture compare polarity */
#define TIM_CCCTR_CH1NCCEN                 ((uint16_t)0x0004)          /*!< Channel 1 complementary capture compare enable */
#define TIM_CCCTR_CH1NCCP                  ((uint16_t)0x0008)          /*!< Channel 1 complementary capture compare polarity */
#define TIM_CCCTR_CH2CCEN                  ((uint16_t)0x0010)          /*!< Channel 2 capture compare enable */
#define TIM_CCCTR_CH2CCP                   ((uint16_t)0x0020)          /*!< Channel 2 capture compare polarity */
#define TIM_CCCTR_CH2NCCEN                 ((uint16_t)0x0040)          /*!< Channel 2 complementary capture compare enable */
#define TIM_CCCTR_CH2NCCP                  ((uint16_t)0x0080)          /*!< Channel 2 complementary capture compare polarity */
#define TIM_CCCTR_CH3CCEN                  ((uint16_t)0x0100)          /*!< Channel 3 capture compare enable */
#define TIM_CCCTR_CH3CCP                   ((uint16_t)0x0200)          /*!< Channel 3 capture compare polarity */
#define TIM_CCCTR_CH3NCCEN                 ((uint16_t)0x0400)          /*!< Channel 3 complementary capture compare enable */
#define TIM_CCCTR_CH3NCCP                  ((uint16_t)0x0800)          /*!< Channel 3 complementary capture compare polarity */
#define TIM_CCCTR_CH4CCEN                  ((uint16_t)0x1000)          /*!< Channel 4 capture compare enable */
#define TIM_CCCTR_CH4CCP                   ((uint16_t)0x2000)          /*!< Channel 4 capture compare polarity */
#define TIM_CCCTR_CH4NCCP                  ((uint16_t)0x8000)          /*!< Channel 4 complementary capture compare polarity */

/**
  * @brief TIMx_CNT register Bit definition
  */
#define TIM_CNT_CNT                        ((uint16_t)0xFFFF)          /*!< Counter Value */

/** 
  * @brief TIMx_PDIV register Bit definition    
  */    
#define TIM_PDIV_PDIV                      ((uint16_t)0xFFFF)          /*!< Pre-divider Value */

/** 
  * @brief TIMx_UVAL register Bit definition    
  */    
#define TIM_UVAL_UVAL                      ((uint16_t)0xFFFF)          /*!< Counter update value */

/** 
  * @brief TIMx_UVALREP register Bit definition 
  */    
#define TIM_UVALREP_UVALREP                ((uint8_t)0xFF)             /*!< Counter update repetition value */

/** 
  * @brief TIMx_CH1CCVAL register Bit definition    
  */    
#define TIM_CH1CCVAL_CH1CCVAL              ((uint16_t)0xFFFF)          /*!< Channel 1 capture compare value */

/** 
  * @brief TIMx_CH2CCVAL register Bit definition    
  */    
#define TIM_CH2CCVAL_CH2CCVAL              ((uint16_t)0xFFFF)          /*!< Channel 2 capture compare value */

/** 
  * @brief TIMx_CH3CCVAL register Bit definition    
  */    
#define TIM_CH3CCVAL_CH3CCVAL              ((uint16_t)0xFFFF)          /*!< Channel 3 capture compare value */

/** 
* @brief TIMx_CH4CCVAL register Bit definition  
*/  
#define TIM_CH4CCVAL_CH4CCVAL              ((uint16_t)0xFFFF)          /*!< Channel 4 capture compare value */

/**
  * @brief TIMx_CHOPR register Bit definition
  */
#define TIM_CHOPR_DTCFG                    ((uint16_t)0x00FF)          /*!< DTCFG[0:7] bits (Dead-time configuration) */
#define TIM_CHOPR_DTCFG_0                  ((uint16_t)0x0001)          /*!< Bit 0 */
#define TIM_CHOPR_DTCFG_1                  ((uint16_t)0x0002)          /*!< Bit 1 */
#define TIM_CHOPR_DTCFG_2                  ((uint16_t)0x0004)          /*!< Bit 2 */
#define TIM_CHOPR_DTCFG_3                  ((uint16_t)0x0008)          /*!< Bit 3 */
#define TIM_CHOPR_DTCFG_4                  ((uint16_t)0x0010)          /*!< Bit 4 */
#define TIM_CHOPR_DTCFG_5                  ((uint16_t)0x0020)          /*!< Bit 5 */
#define TIM_CHOPR_DTCFG_6                  ((uint16_t)0x0040)          /*!< Bit 6 */
#define TIM_CHOPR_DTCFG_7                  ((uint16_t)0x0080)          /*!< Bit 7 */

#define TIM_CHOPR_LCKLV                    ((uint16_t)0x0300)          /*!< LCKLV[1:0] bits (Lock level control) */
#define TIM_CHOPR_LCKLV_0                  ((uint16_t)0x0100)          /*!< Bit 0 */
#define TIM_CHOPR_LCKLV_1                  ((uint16_t)0x0200)          /*!< Bit 1 */

#define TIM_CHOPR_IDLEOS                   ((uint16_t)0x0400)          /*!< Idle mode off-state control */
#define TIM_CHOPR_RUNOS                    ((uint16_t)0x0800)          /*!< Run mode off-state control */
#define TIM_CHOPR_BRKEN                    ((uint16_t)0x1000)          /*!< Break enable */
#define TIM_CHOPR_BRKPOL                   ((uint16_t)0x2000)          /*!< Break Polarity */
#define TIM_CHOPR_CHOPAEN                  ((uint16_t)0x4000)          /*!< Channel output pad auto enable */
#define TIM_CHOPR_CHOPEN                   ((uint16_t)0x8000)          /*!< Channel output pad enable */

/**
  * @brief TIMx_DMAACR register Bit definition
  */
#define TIM_DMAACR_DMASA                   ((uint16_t)0x001F)          /*!< DMASA[4:0] (DMA start address) */
#define TIM_DMAACR_DMASA_0                 ((uint16_t)0x0001)          /*!< Bit 0 */
#define TIM_DMAACR_DMASA_1                 ((uint16_t)0x0002)          /*!< Bit 1 */
#define TIM_DMAACR_DMASA_2                 ((uint16_t)0x0004)          /*!< Bit 2 */
#define TIM_DMAACR_DMASA_3                 ((uint16_t)0x0008)          /*!< Bit 3 */
#define TIM_DMAACR_DMASA_4                 ((uint16_t)0x0010)          /*!< Bit 4 */

#define TIM_DMAACR_DMATL                   ((uint16_t)0x1F00)          /*!< DMATL[4:0](DMA transfer length) */
#define TIM_DMAACR_DMATL_0                 ((uint16_t)0x0100)          /*!< Bit 0 */
#define TIM_DMAACR_DMATL_1                 ((uint16_t)0x0200)          /*!< Bit 1 */
#define TIM_DMAACR_DMATL_2                 ((uint16_t)0x0400)          /*!< Bit 2 */
#define TIM_DMAACR_DMATL_3                 ((uint16_t)0x0800)          /*!< Bit 3 */
#define TIM_DMAACR_DMATL_4                 ((uint16_t)0x1000)          /*!< Bit 4 */

/**
  * @brief TIMx_DMAIR register Bit definition
  */
#define TIM_DMAIR_DMAI                     ((uint16_t)0xFFFF)          /*!< DMA access interface */

/**
  * @brief TIM14_REMAP register Bit definition
  */
#define TIM14_REMAP_CH1IS                   ((uint16_t)0x0003)          /*!< CH1IS[1:0] bits (Channel 1 input selection) */
#define TIM14_REMAP_CH1IS_0                 ((uint16_t)0x0001)          /*!< Bit 0 */
#define TIM14_REMAP_CH1IS_1                 ((uint16_t)0x0002)          /*!< Bit 1 */


/*--------------------------------------------------------------------------*/
/*      USART(Universal Synchronous Asynchronous Receiver Transmitter)      */
/*--------------------------------------------------------------------------*/

/**
  * @brief USART_CTR1 register Bit definition
  */
#define USART_CTR1_UEN             			((uint32_t)0x00000001)      /*!< USART enable. */
#define USART_CTR1_WKUPDSM         			((uint32_t)0x00000002)      /*!< Wakeup mcu from deepsleep mode enabl. */
#define USART_CTR1_REN             			((uint32_t)0x00000004)      /*!< Receiver enable. */
#define USART_CTR1_TEN             			((uint32_t)0x00000008)      /*!< Transmitter enable. */
#define USART_CTR1_IDLEIE          			((uint32_t)0x00000010)      /*!< Enable bit for IDLE interrupt. */
#define USART_CTR1_RXNEIE          			((uint32_t)0x00000020)      /*!< Enable bit for RXNE interrupt. */
#define USART_CTR1_TCIE            			((uint32_t)0x00000040)      /*!< Enable bit for transmit complete interrupt. */
#define USART_CTR1_TXEIE           			((uint32_t)0x00000080)      /*!< Enable bit for transmit empty interrupt. */
#define USART_CTR1_PERRIE          			((uint32_t)0x00000100)      /*!< Enable bit for parity err interrupt. */
#define USART_CTR1_ODDS            			((uint32_t)0x00000200)      /*!< Odd parity selection. */
#define USART_CTR1_PEN             			((uint32_t)0x00000400)      /*!< Parity enable. */
#define USART_CTR1_RXWKUPS         			((uint32_t)0x00000800)      /*!< Receiver wakeup selection. */
#define USART_CTR1_DL              			((uint32_t)0x00001000)      /*!< Data length. */
#define USART_CTR1_RXMSKEN         			((uint32_t)0x00002000)      /*!< Reception mask mode enable. */
#define USART_CTR1_CMIE            			((uint32_t)0x00004000)      /*!< Enable bit for character match interrupt. */
#define USART_CTR1_OVRS            			((uint32_t)0x00008000)      /*!< Oversampling selection. */
#define USART_CTR1_POSTDE          			((uint32_t)0x001F0000)      /*!< Pos-active time for Driver Enable POSTDE[4:0]. */
#define USART_CTR1_POSTDE_0        			((uint32_t)0x00010000)      /*!< POSTDE[0]. */
#define USART_CTR1_POSTDE_1        			((uint32_t)0x00020000)      /*!< POSTDE[1]. */
#define USART_CTR1_POSTDE_2        			((uint32_t)0x00040000)      /*!< POSTDE[2]. */
#define USART_CTR1_POSTDE_3        			((uint32_t)0x00080000)      /*!< POSTDE[3]. */
#define USART_CTR1_POSTDE_4        			((uint32_t)0x00100000)      /*!< POSTDE[4]. */
#define USART_CTR1_PRETDE          			((uint32_t)0x03E00000)      /*!< Pre-active time for Driver Enable PRETDE[4:0]. */
#define USART_CTR1_PRETDE_0        			((uint32_t)0x00200000)      /*!< Bit 0. */
#define USART_CTR1_PRETDE_1        			((uint32_t)0x00400000)      /*!< Bit 1. */
#define USART_CTR1_PRETDE_2        			((uint32_t)0x00800000)      /*!< Bit 2. */
#define USART_CTR1_PRETDE_3        			((uint32_t)0x01000000)      /*!< Bit 3. */
#define USART_CTR1_PRETDE_4        			((uint32_t)0x02000000)      /*!< Bit 4. */
#define USART_CTR1_OVRTIE          			((uint32_t)0x04000000)      /*!< Enable bit for Receiver overtime interrupt. */
#define USART_CTR1_BTCIE           			((uint32_t)0x08000000)      /*!< Block transmit complete interrupt enable. */
#define USART_CTR1_DH              			((uint32_t)0x10000000)      /*!< Data length. */

/**
  * @brief USART_CTR2 register Bit definition
  */
#define USART_CTR2_ADRM7           			((uint32_t)0x00000010)      /*!< 4bit/7bit address detection selection. */
#define USART_CTR2_LINBRK11        			((uint32_t)0x00000020)      /*!< 11-bit break frame detection. */
#define USART_CTR2_LBDIE           			((uint32_t)0x00000040)      /*!< LIN break frame detection interrupt enable. */
#define USART_CTR2_CKLEN           			((uint32_t)0x00000100)      /*!< CK length. */
#define USART_CTR2_CPHA            			((uint32_t)0x00000200)      /*!< Clock phase. */
#define USART_CTR2_CPOL            			((uint32_t)0x00000400)      /*!< Clock polarity. */
#define USART_CTR2_CKEN            			((uint32_t)0x00000800)      /*!< CK pin enable. */
#define USART_CTR2_STOPLEN         			((uint32_t)0x00003000)      /*!< STOP bits length STOPLEN[1:0]. */
#define USART_CTR2_STOPLEN_0       			((uint32_t)0x00001000)      /*!< Bit 0. */
#define USART_CTR2_STOPLEN_1       			((uint32_t)0x00002000)      /*!< Bit 1. */
#define USART_CTR2_LINEN           			((uint32_t)0x00004000)      /*!< LIN mode enable. */
#define USART_CTR2_TXRXSWAP        			((uint32_t)0x00008000)      /*!< TX/RX pins swap enable. */
#define USART_CTR2_RXINV           			((uint32_t)0x00010000)      /*!< RX pin inversion. */
#define USART_CTR2_TXINV           			((uint32_t)0x00020000)      /*!< TX pin inversion. */
#define USART_CTR2_DINV            			((uint32_t)0x00040000)      /*!< Data bit inversion. */
#define USART_CTR2_MSBF            			((uint32_t)0x00080000)      /*!< MSB first. */
#define USART_CTR2_ABREN           			((uint32_t)0x00100000)      /*!< Auto baud rate enable. */
#define USART_CTR2_ABRSEL          			((uint32_t)0x00600000)      /*!< Auto baud rate mode selection ABRSEL[1:0]. */
#define USART_CTR2_ABRSEL_0        			((uint32_t)0x00200000)      /*!< Bit 0. */
#define USART_CTR2_ABRSEL_1        			((uint32_t)0x00400000)      /*!< Bit 1. */
#define USART_CTR2_ROTEN           			((uint32_t)0x00800000)      /*!< Receiver overtime enable. */
#define USART_CTR2_UADR            			((uint32_t)0xFF000000)      /*!< USART address. */

/**
  * @brief USART_CTR3 register Bit definition
  */
#define USART_CTR3_ERRIE           			((uint32_t)0x00000001)      /*!< Enable bit for Error interrupt. */
#define USART_CTR3_IRDAEN          			((uint32_t)0x00000002)      /*!< IrDA mode enable. */
#define USART_CTR3_IRMS            			((uint32_t)0x00000004)      /*!< IrDA mode selection. */
#define USART_CTR3_HDEN            			((uint32_t)0x00000008)      /*!< Half-duplex enable. */
#define USART_CTR3_SCNACK          			((uint32_t)0x00000010)      /*!< Smartcard transmit nack in parity error. */
#define USART_CTR3_SCEN            			((uint32_t)0x00000020)      /*!< Smartcard mode enable. */
#define USART_CTR3_RXDMA           			((uint32_t)0x00000040)      /*!< Receive with DMA. */
#define USART_CTR3_TXDMA           			((uint32_t)0x00000080)      /*!< Transmit with DMA. */
#define USART_CTR3_RTSEN           			((uint32_t)0x00000100)      /*!< RTS enable. */
#define USART_CTR3_CTSEN           			((uint32_t)0x00000200)      /*!< CTS enable. */
#define USART_CTR3_CTSIE           			((uint32_t)0x00000400)      /*!< Enable bit for CTS interrupt. */
#define USART_CTR3_SPMS            			((uint32_t)0x00000800)      /*!< Sample method selection. */
#define USART_CTR3_NORXOF          			((uint32_t)0x00001000)      /*!< No Receive overflow detection. */
#define USART_CTR3_DRMRE           			((uint32_t)0x00002000)      /*!< DMA request mask on Reception error. */
#define USART_CTR3_DEN             			((uint32_t)0x00004000)      /*!< DE enable. */
#define USART_CTR3_DEPS            			((uint32_t)0x00008000)      /*!< DE polarity selection. */
#define USART_CTR3_SCANUM          			((uint32_t)0x000E0000)      /*!< Number of smartcard auto-retry times. */
#define USART_CR3_SCARCNT_0        			((uint32_t)0x00020000)      /*!< Bit 0. */
#define USART_CTR3_SCANUM_1        			((uint32_t)0x00040000)      /*!< Bit 1. */
#define USART_CTR3_SCANUM_2        			((uint32_t)0x00080000)      /*!< Bit 2. */
#define USART_CTR3_WKUPMTHD        			((uint32_t)0x00300000)      /*!< Wakeup from stop mode method WKUPMTHD[1:0]. */
#define USART_CTR3_WKUPMTHD_0      			((uint32_t)0x00100000)      /*!< Bit 0. */
#define USART_CTR3_WKUPMTHD_1      			((uint32_t)0x00200000)      /*!< Bit 1. */
#define USART_CTR3_WKUPIE          			((uint32_t)0x00400000)      /*!< Enable bit for wakeup from stop mode interrupt. */

/**
  * @brief USART_BRT register Bit definition
  */
#define USART_BRT_FRADIV            		((uint16_t)0x000F)          /*!< DIV fraction value. */
#define USART_BRT_INTDIV            		((uint16_t)0xFFF0)          /*!< DIV int value. */

/**
  * @brief USART_GTPDIV register Bit definition
  */
#define USART_GTPDIV_PDIV           		((uint16_t)0x00FF)          /*!< Pre-divider value PDIV[7:0]. */
#define USART_GTPDIV_GUDT           		((uint16_t)0xFF00)          /*!< Guard time value GUDT[7:0]. */

/**
  * @brief USART_ROT register Bit definition
  */
#define USART_ROT_RXOVR             		((uint32_t)0x00FFFFFF)      /*!< Receiver overtime value RXOVR[23:0]. */
#define USART_ROT_NUMBLK            		((uint32_t)0xFF000000)      /*!< Unit number of block NUMBLK[7:0]. */

/**
  * @brief USART_SWTR register Bit definition
  */
#define USART_SWTR_ABRT            			((uint16_t)0x0001)          /*!< Auto baud rate trigger. */
#define USART_SWTR_BRKFST          			((uint16_t)0x0002)          /*!< Break frame send trigger. */
#define USART_SWTR_RXMSKT          			((uint16_t)0x0004)          /*!< Reception mask mode trigger. */
#define USART_SWTR_RXNECLR         			((uint16_t)0x0008)          /*!< RXNE clear trigger. */
#define USART_SWTR_TXESET          			((uint16_t)0x0010)          /*!< TXE set trigger. */

/**
  * @brief USART_STS register Bit definition
  */
#define USART_STS_PERRF            			((uint32_t)0x00000001)      /*!< Parity error flag. */
#define USART_STS_FERRF            			((uint32_t)0x00000002)      /*!< Frame error flag. */
#define USART_STS_NF               			((uint32_t)0x00000004)      /*!< Noise flag. */
#define USART_STS_OVRERRF          			((uint32_t)0x00000008)      /*!< Reception overflow error flag. */
#define USART_STS_IDLEF            			((uint32_t)0x00000010)      /*!< Idle frame detected flag. */
#define USART_STS_RXNE             			((uint32_t)0x00000020)      /*!< receiver buffer not empty flag. */
#define USART_STS_TCF              			((uint32_t)0x00000040)      /*!< Transmission complete flag. */
#define USART_STS_TXE              			((uint32_t)0x00000080)      /*!< transmit buffer empty flag. */
#define USART_STS_LINBKF           			((uint32_t)0x00000100)      /*!< LIN break frame detection flag. */
#define USART_STS_CTSIF            			((uint32_t)0x00000200)      /*!< CTS interrupt flag. */
#define USART_STS_CTSF             			((uint32_t)0x00000400)      /*!< CTS flag. */
#define USART_STS_ROTF             			((uint32_t)0x00000800)      /*!< Receiver overtime flag. */
#define USART_STS_ENDBLKF          			((uint32_t)0x00001000)      /*!< End of block flag. */
#define USART_STS_ABRTERRF         			((uint32_t)0x00004000)      /*!< Auto baud rate error flag. */
#define USART_STS_ABRTF            			((uint32_t)0x00008000)      /*!< Auto baud rate flag. */
#define USART_STS_BSYF             			((uint32_t)0x00010000)      /*!< Busy flag. */
#define USART_STS_CMF              			((uint32_t)0x00020000)      /*!< Character match flag. */
#define USART_STS_BRKSF            			((uint32_t)0x00040000)      /*!< Break frame send flag. */
#define USART_STS_RXMSKF           			((uint32_t)0x00080000)      /*!< Reception mask mode flag. */
#define USART_STS_WKUPF            			((uint32_t)0x00100000)      /*!< Wakeup from Stop mode flag. */
#define USART_STS_TENACTF          			((uint32_t)0x00200000)      /*!< TEN active flag. */
#define USART_STS_RENACTF          			((uint32_t)0x00400000)      /*!< REN active flag. */

/**
  * @brief USART_IFCLR register Bit definition
  */
#define USART_IFCLR_PERRC          			((uint32_t)0x00000001)      /*!< Parity error flag clear. */
#define USART_IFCLR_FERRC          			((uint32_t)0x00000002)      /*!< Frame error flag clear. */
#define USART_IFCLR_STARTNFC       			((uint32_t)0x00000004)      /*!< Start bit noise detected flag clear. */
#define USART_IFCLR_OVRERRC        			((uint32_t)0x00000008)      /*!< Overrun error flag clear. */
#define USART_IFCLR_IDLEFC         			((uint32_t)0x00000010)      /*!< Idle frame detected flag clear. */
#define USART_IFCLR_TCFC           			((uint32_t)0x00000040)      /*!< Transmission complete flag clear. */
#define USART_IFCLR_LINBKFC        			((uint32_t)0x00000100)      /*!< LIN break frame detection flag clear. */
#define USART_IFCLR_CTSFC          			((uint32_t)0x00000200)      /*!< CTS flag clear. */
#define USART_IFCLR_ROTFC          			((uint32_t)0x00000800)      /*!< Receiver overtime flag clear. */
#define USART_IFCLR_ENDBLKFC       			((uint32_t)0x00001000)      /*!< End of block flag clear. */
#define USART_IFCLR_CMFC           			((uint32_t)0x00020000)      /*!< Character match flag clear. */
#define USART_IFCLR_WKUPFC         			((uint32_t)0x00100000)      /*!< Wakeup from stop mode flag clear. */

/**
  * @brief USART_RXBUF register Bit definition
  */
#define USART_RXBUF_RXBUF           		((uint16_t)0x01FF)          /*!< Receive buffer RXBUF[8:0]. */

/**
  * @brief USART_TXBUF register Bit definition
  */
#define USART_TXBUF_TXBUF           		((uint16_t)0x01FF)          /*!< Transmit buffer TXBUF[8:0]. */

/*--------------------------------------------------------------------------*/
/*                           WWDT(Window Watchdog)                          */
/*--------------------------------------------------------------------------*/

/**
  * @brief WWDT_CTR1 register bit definition
  */
#define WWDT_CTR1_CVAL               		((uint32_t)0x0000007F)      /*!< Window watchdog timer value. */
#define WWDT_CTR1_WWDTEN             		((uint32_t)0x00000080)      /*!< Window watchdog enable bit. */

/**
  * @brief WWDT_CTR2 register bit definition
  */
#define WWDT_CTR2_WVAL               		((uint32_t)0x0000007F)      /*!< Window value. */
#define WWDT_CTR2_PDIV               		((uint32_t)0x00000180)      /*!< Prescale value. */
#define WWDT_CTR2_RMDIE              		((uint32_t)0x00000200)      /*!< Reminder interrupt enable bit. */

/**
  * @brief WWDT_STS register bit definition
  */
#define WWDT_STS_RMDIF               		((uint32_t)0x00000001)      /*!< Reminder interrupt flag bit. */

/**
  * @}
  */

/***************************************************************************************************
 * @functions
***************************************************************************************************/
/* #define USE_FULL_ASSERT      1 */
#ifdef  USE_FULL_ASSERT

/**@brief The ASSERT macro is used for function's parameters check.
 * @param[in] expr: If expr is false, it calls assert_failed function which reports 
 *                  the name of the source file and the source line number of the call 
 *                  that failed. If expr is true, it returns no value.
 * @return  None.
 */
#define ASSERT(expr) ((expr) ? (void)0 : assert_failed((uint8_t *)__FILE__, __LINE__))

/**@brief Reports the name of the file and the line number error.
 * @param[in]  file: Pointer to the  file name.
 * @param[in]  line: Error line  number.
 * @return  None.
 */
void assert_failed(uint8_t* file, uint32_t line);
#else
#define ASSERT(expr) ((void)0)
#endif

#ifdef USE_STDPERIPH_DRIVER
    #include "CBM858xM_conf.h"
#endif

#ifdef __cplusplus
}
#endif

#endif /* cbm858xm.h */


/**
  * @}
  */

/**
  * @}
  */

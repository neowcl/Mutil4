/**
* @file 	   cbm858xm_pmu.h
* @brief	   This file contains all the functions prototypes for the PMU firmware. 
* @author	   ChipSea MCU Group
* @version	   1.0.0
* @date 	   2022.05.16
* @copyright   CHIPSEA TECHNOLOGIES (SHENZHEN) CORP.
* @note 	   
****************************************************************************************************
* @par Modify record:
* <tr><th>Date			<th>Version    <th>Author	  <th>Description
* <tr><td>2022.05.16	<td>1.0.0	   <td>ChipSea	  <td>
* -# 
* </table>
*
****************************************************************************************************
*/


#ifndef __CBM858xM_PMU_H__
#define __CBM858xM_PMU_H__


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

/** @addtogroup PMU
  * @{
  */

/***************************************************************************************************
 * @definitions
***************************************************************************************************/
/** @defgroup PPP_Exported_Types PMU Exported Types
  * @{
  */

//Fill the content
/**
  * @}
  */


/** @defgroup PPP_Exported_Constants PMU Exported Constants
  * @{
  */

/**
  * @brief The PMU CTR function enable bits.
  */
#define PMU_ENABLE_BIT_LVD                   (PMU_CTR_LVDEN)        /*!< PMU LVD enable bit. */
#define PMU_ENABLE_BIT_VBAT_WRITE            (PMU_CTR_VBTWEN)       /*!< PMU VBAT write enable bit. */
#define PMU_ENABLE_BIT_HVD           		 (PMU_CTR_HVDEN)        /*!< PMU HVD enable bit. */
#define PMU_ENABLE_BIT_LDOLVD           	 (PMU_CTR_LDOLVDEN)     /*!< PMU LDO low volt detection enable bit. */
#define PMU_ENABLE_BIT_LDOHVD           	 (PMU_CTR_LDOHVDEN)     /*!< PMU LDO high volt detection enable bit. */
#define PMU_ENABLE_BIT_LVDINT           	 (PMU_CTR_LVDIE)        /*!< PMU AVDD/DVDD LVD int enable bit. */
#define PMU_ENABLE_BIT_HVDINT           	 (PMU_CTR_HVDIE)        /*!< PMU AVDD/DVDD HVD int enable bit. */
#define PMU_ENABLE_BIT_LDOLVDINT             (PMU_CTR_LDOLVDIN)     /*!< PMU LDO LVD int enable reg. */
#define PMU_ENABLE_BIT_LDOHVDINT             (PMU_CTR_LDOHVDIN)     /*!< PMU LDO HVD int enable reg. */

/**
  * @brief The PMU CS wakeup function enable bits.
  */
#define PMU_ENABLE_BIT_WAKEUP_PIN1           (PMU_CS_WUPEN1)        /*!< PMU wake up pin1 enable bit. */
#define PMU_ENABLE_BIT_WAKEUP_PIN3           (PMU_CS_WUPEN3)        /*!< PMU wake up pin3 enable bit. */
#define PMU_ENABLE_BIT_WAKEUP_PIN4           (PMU_CS_WUPEN4)        /*!< PMU wake up pin4 enable bit. */

/**
  * @brief The PMU CS wakeup pin polarity bits.
  */
#define PMU_POLARITY_BIT_WAKEUP_PIN1         (PMU_CS_WUPEN1_CFG)    /*!< PMU wake up pin1 polarity bit. */
#define PMU_POLARITY_BIT_WAKEUP_PIN3         (PMU_CS_WUPEN3_CFG)    /*!< PMU wake up pin1 polarity bit. */
#define PMU_POLARITY_BIT_WAKEUP_PIN4         (PMU_CS_WUPEN4_CFG)    /*!< PMU wake up pin1 polarity bit. */

/** 
  * @brief PMU CS reg flag definition
  */
#define PMU_FLAG_WUPF                        (PMU_CS_WUPF)          /*!< PMU wakeup flag. */
#define PMU_FLAG_PWDF                        (PMU_CS_PWDF)          /*!< PMU power down flag. */
#define PMU_FLAG_LVD_VDD                     (PMU_CS_LVD_VDD)       /*!< PMU DVDD low volt flag. */
#define PMU_FLAG_WUPF1                       (PMU_CS_WUPF1)         /*!< PMU wakeup1 awaken flag. */
#define PMU_FLAG_WUPF3                       (PMU_CS_WUPF3)         /*!< PMU wakeup3 awaken flag. */
#define PMU_FLAG_WUPF4                       (PMU_CS_WUPF4)         /*!< PMU wakeup4 awaken flag. */
#define PMU_FLAG_LVD_LDO                     (PMU_CS_LVD_LDO)		/*!< PMU LDO low volt flag. */
#define PMU_FLAG_HVD_LDO                     (PMU_CS_HVD_LDO)		/*!< PMU LDO high volt flag. */
#define PMU_FLAG_HVD_VDD                     (PMU_CS_HVD_VDD)		/*!< PMU VDD high volt flag. */
#define PMU_FLAG_LDOLVDF                     (PMU_CS_LDOLVDF)		/*!< PMU LDO low volt int flag. */
#define PMU_FLAG_LDOHVDF                     (PMU_CS_LDOHVDF)		/*!< PMU LDO high volt int flag. */
#define PMU_FLAG_LVDF                        (PMU_CS_LVDF)			/*!< PMU AVDD/DVDD low volt int flag. */
#define PMU_FLAG_HVDF                        (PMU_CS_HVDF)		    /*!< PMU AVDD/DVDD high volt int flag. */
#define PMU_FLAG_LPPD1IF                     (PMU_CS_LPPD1IF)		/*!< PMU LDO low volt pulse delection int flag. */
#define PMU_FLAG_HPPD1IF                     (PMU_CS_HPPD1IF)		/*!< PMU LDO high volt pulse delection int flag. */
#define PMU_FLAG_LPPD0IF                     (PMU_CS_LPPD0IF)	    /*!< PMU AVDD/DVDD low volt pulse delection int flag. */
#define PMU_FLAG_HPPD0IF                     (PMU_CS_HPPD0IF)		/*!< PMU AVDD/DVDD low volt pulse delection int flag. */

/**
  * @brief The PMU CTR2 function enable bits.
  */
#define PMU_ENABLE_BIT_LPPD                  (PMU_CTR2_LPPDEN)      /*!< PMU AVDD/DVDD low power pulse detection enable. */
#define PMU_ENABLE_BIT_LPPDINT               (PMU_CTR2_LPPDIE)      /*!< PMU AVDD/DVDD low power pulse int enable. */
#define PMU_ENABLE_BIT_HPPD                  (PMU_CTR2_HPPDEN)      /*!< PMU AVDD/DVDD high power pulse detection enable. */
#define PMU_ENABLE_BIT_HPPDINT               (PMU_CTR2_HPPDIE)      /*!< PMU AVDD/DVDD high power pulse int enable. */

/**
  * @brief The PMU CTR2 clear bits.
  */
#define PMU_CNT_CLR_BIT_LPPD                 (PMU_CTR2_LPPD_CLR)    /*!< PMU AVDD/DVDD low power pulse cnt clear. */
#define PMU_CNT_CLR_BIT_HPPD                 (PMU_CTR2_HPPD_CLR)    /*!< PMU AVDD/DVDD high power pulse cnt clear. */

/**
  * @brief The PMU CTR3 function enable bits.
  */
#define PMU_ENABLE_BIT_LPPD1                 (PMU_CTR3_LPPD1EN)     /*!< PMU LDO low power pulse detection enable. */
#define PMU_ENABLE_BIT_LPPD1INT              (PMU_CTR3_LPPD1IE)     /*!< PMU LDO low power pulse int enable. */
#define PMU_ENABLE_BIT_HPPD1                 (PMU_CTR3_HPPD1EN)     /*!< PMU LDO high power pulse detection enable. */
#define PMU_ENABLE_BIT_HPPD1INT              (PMU_CTR3_HPPD1IE)     /*!< PMU LDO high power pulse int enable. */

/**
  * @brief The PMU CTR3 clear bits.
  */
#define PMU_CNT_CLR_BIT_LPPD1                (PMU_CTR3_LPPD1_CLR)   /*!< PMU LDO low power pulse cnt clear. */
#define PMU_CNT_CLR_BIT_HPPD1                (PMU_CTR3_HPPD1_CLR)   /*!< PMU LDO high power pulse cnt clear. */

/**
  * @brief The PMU ts en bits.
  */
#define PMU_ENABLE_BIT_TS             	     (PMU_TS_EN)         	/*!< PMU temperature tensor enable. */
#define PMU_ENABLE_BIT_TSLOW_INT             (PMU_TS_LIE)         	/*!< PMU sensor low temperature int enable. */
#define PMU_ENABLE_BIT_TSHIGH_INT            (PMU_TS_HIE)         	/*!< PMU sensor high temperature int enable. */
#define PMU_ENABLE_BIT_COMPARATOR            (PMU_TS_CMPEN)         /*!< PMU sensor comparator enable. */


/**
  * @brief The PMU ts flag bits.
  */
#define PMU_FLAG_BIT_TS_LO             	     (PMU_TS_LO)            /*!< PMU sensor low temperature flag bit. */
#define PMU_FLAG_BIT_TS_HO                   (PMU_TS_HO)         	/*!< PMU sensor high temperature flag bit. */
#define PMU_FLAG_BIT_TS_LOW_INT              (PMU_TS_LIF)         	/*!< PMU sensor low temperature int flag. */
#define PMU_FLAG_BIT_TS_HIGH_INT             (PMU_TS_HIF)         	/*!< PMU sensor high temperature int flag. */

/**
  * @brief The PMU ts high temperature choice.
  */
#define PMU_TS_HIGH_TEMPERATURE_105          (0x00000000)          	/*!< PMU sensor high temperature select 105C. */
#define PMU_TS_HIGH_TEMPERATURE_125          (PMU_TS_HSEL)         	/*!< PMU sensor high temperature select 125. */

/*! Check PMU ts high temperature choice. */
#define PMU_TS_HIGH_TEMPERATURE_CHECK(value) (((value) == PMU_TS_HIGH_TEMPERATURE_105) || ((value) == PMU_TS_HIGH_TEMPERATURE_125))

/**
  * @brief The PMU CNT type.
  */
#define PMU_CNT_BIT_LPPD                     (PMU_CTR2_LPPD_CNT)    /*!< PMU PPD cnt. */
#define PMU_CNT_BIT_LPPD_VTH                 (PMU_CTR2_LPPD_VTH)    /*!< PMU PPD VTH cnt. */
#define PMU_CNT_BIT_HPPD                     (PMU_CTR2_HPPD_CNT)    /*!< PMU HDDP cnt. */
#define PMU_CNT_BIT_HPPD_VTH                 (PMU_CTR2_HPPD_VTH)    /*!< PMU PPD VTH cnt. */

/*! Check PMU CNT type. */
#define PMU_CNT_TYPE_CHECK(value)            (((value) == PMU_CNT_BIT_LPPD) || ((value) == PMU_CNT_BIT_LPPD_VTH) || \
                                             ((value) == PMU_CNT_BIT_HPPD))|| ((value) == PMU_CNT_BIT_HPPD_VTH)

/** 
  * @brief PMU LDO low power Control definition
  */
#define PMU_LDO_LOW_POWER                    PMU_CTR_LDOLM          /*!< LDO lower power in deepsleep. */

/*! Check PMU LDO low power Control. */
#define PMU_LDO_CHECK(flag)                  ((flag) == PMU_LDO_LOW_POWER)

/** 
  * @brief PMU SLEEP mode entry 
  */
#define PMU_SLEEP_ENTRY_WFI                  ((uint8_t)0x01)        /*!< Enter sleep mode with WFI instruction. */
#define PMU_SLEEP_ENTRY_WFE                  ((uint8_t)0x02)        /*!< Enter sleep mode with WFE instruction. */

/*! Check PMU SLEEP mode entry. */
#define PMU_SLEEP_ENTRY_CHECK(value)         (((value) == PMU_SLEEP_ENTRY_WFI) || ((value) == PMU_SLEEP_ENTRY_WFE))

/** 
  * @brief PMU PPD definition 
  */
#define PMU_PPD0                  			 ((uint8_t)0x00)        /*!< PMU PDD0. */
#define PMU_PPD1                 			 ((uint8_t)0x01)        /*!< PMU PDD1. */

/*! Check PMU PPD definition. */
#define PMU_PPD_CHECK(value)                 (((value) == PMU_PPD0) || ((value) == PMU_PPD1))

/** 
  * @brief PMU STOP mode entry
  */
#define PMU_DSM_ENTRY_WFI                    ((uint8_t)0x01)        /*!< Enter stop mode with WFI instruction. */
#define PMU_DSM_ENTRY_WFE                    ((uint8_t)0x02)        /*!< Enter stop mode with WFE instruction. */
#define PMU_DSM_ENTRY_SLEEPONEXIT            ((uint8_t)0x03)        /*!< Enter stop mode with sleeponexit instruction. */
    
/*! Check PMU STOP mode entry. */
#define PMU_STOP_ENTRY_CHECK(value)          (((value) == PMU_DSM_ENTRY_WFI) || ((value) == PMU_DSM_ENTRY_WFE) || \
                                             ((value) == PMU_DSM_ENTRY_SLEEPONEXIT))
/** 
  * @brief PMU LVD filter definition 
  */ 
#define PMU_LVD_FILTER0                      0x00000000   			/*!< PMU LVD (low voltage detector) level 0. */ 
#define PMU_LVD_FILTER1                      0x00020000   			/*!< PMU LVD (low voltage detector) level 1. */ 
#define PMU_LVD_FILTER2                      0x00040000   			/*!< PMU LVD (low voltage detector) level 2. */ 
#define PMU_LVD_FILTER3                      0x00060000   			/*!< PMU LVD (low voltage detector) level 3. */ 
#define PMU_LVD_FILTER4                      0x00080000   			/*!< PMU LVD (low voltage detector) level 4. */ 
#define PMU_LVD_FILTER5                      0x000A0000   			/*!< PMU LVD (low voltage detector) level 5. */ 
#define PMU_LVD_FILTER6                      0x000C0000   			/*!< PMU LVD (low voltage detector) level 6. */ 
#define PMU_LVD_FILTER7                      0x000E0000   			/*!< PMU LVD (low voltage detector) level 7. */

/*! Check PMU LVD filter definition. */
#define PMU_LVD_FILTER_CHECK(value)          (((value) == PMU_LVD_FILTER0) || ((value) == PMU_LVD_FILTER1)|| \
                                             ((value) == PMU_LVD_FILTER2)   || ((value) == PMU_LVD_FILTER3)|| \
                                             ((value) == PMU_LVD_FILTER4)   || ((value) == PMU_LVD_FILTER5)|| \
                                             ((value) == PMU_LVD_FILTER6)   || ((value) == PMU_LVD_FILTER7))

/** 
  * @brief PMU HVD filter definition 
  */ 
#define PMU_HVD_FILTER0                      0x00000000   			/*!< PMU LVD (low voltage detector) level 0. */
#define PMU_HVD_FILTER1                      0x00100000   			/*!< PMU LVD (low voltage detector) level 1. */
#define PMU_HVD_FILTER2                      0x00200000   			/*!< PMU LVD (low voltage detector) level 2. */
#define PMU_HVD_FILTER3                      0x00300000   			/*!< PMU LVD (low voltage detector) level 3. */
#define PMU_HVD_FILTER4                      0x00400000   			/*!< PMU LVD (low voltage detector) level 4. */
#define PMU_HVD_FILTER5                      0x00500000   			/*!< PMU LVD (low voltage detector) level 5. */
#define PMU_HVD_FILTER6                      0x00600000   			/*!< PMU LVD (low voltage detector) level 6. */
#define PMU_HVD_FILTER7                      0x00700000   			/*!< PMU LVD (low voltage detector) level 7. */

/*! Check PMU HVD filter definition. */
#define PMU_HVD_FILTER_CHECK(value)          (((value) == PMU_HVD_FILTER0) || ((value) == PMU_HVD_FILTER1)|| \
                                             ((value) == PMU_HVD_FILTER2)   || ((value) == PMU_HVD_FILTER3)|| \
                                             ((value) == PMU_HVD_FILTER4)   || ((value) == PMU_HVD_FILTER5)|| \
                                             ((value) == PMU_HVD_FILTER6)   || ((value) == PMU_HVD_FILTER7))
/**
  * @}
  */


/***************************************************************************************************
 * @functions
***************************************************************************************************/
/** @defgroup PMU_Exported_Functions PMU Exported Functions
  * @{
  */

/**
  * @brief  Deinitializes the PMU peripheral registers to their default reset values.
  * @param  None.
  * @return None.
  */
#define __PMU_DEF_INIT()                	do{ \
                                            	(RCU->APB1RST |= RCU_PERI_RST_BIT_PMU); \
                                            	(RCU->APB1RST &= ~RCU_PERI_RST_BIT_PMU); \
                                     		}while(0U)

/**
  * @brief  Enables the PMU CTR functionality.
  * @param  value: Specifies the function, it can be one of the following values:
  *            @arg PMU_ENABLE_BIT_LVD
  *            @arg PMU_ENABLE_BIT_VBAT_WRITE
  *            @arg PMU_ENABLE_BIT_HVD
  *            @arg PMU_ENABLE_BIT_LDOLVD
  *            @arg PMU_ENABLE_BIT_LDOHVD
  *            @arg PMU_ENABLE_BIT_LVDINT
  *            @arg PMU_ENABLE_BIT_HVDINT
  *            @arg PMU_ENABLE_BIT_LDOLVDINT
  *            @arg PMU_ENABLE_BIT_LDOHVDINT  
  * @return None.
  */
#define __PMU_CTR_FUNC_ENABLE(value)         (PMU->CTR |= (value))
           
/**
  * @brief  Disables the PMU CTR functionality.
  * @param  FUNC: Specifies the function, it can be one of the following values:
  *            @arg PMU_ENABLE_BIT_LVD
  *            @arg PMU_ENABLE_BIT_VBAT_WRITE
  *            @arg PMU_ENABLE_BIT_HVD
  *            @arg PMU_ENABLE_BIT_LDOLVD
  *            @arg PMU_ENABLE_BIT_LDOHVD
  *            @arg PMU_ENABLE_BIT_LVDINT
  *            @arg PMU_ENABLE_BIT_HVDINT
  *            @arg PMU_ENABLE_BIT_LDOLVDINT
  *            @arg PMU_ENABLE_BIT_LDOHVDINT
  * @return None.
  */                                  
#define __PMU_CTR_FUNC_DISABLE(value)        (PMU->CTR &= ~(value))

/**
  * @brief  Clears the PMU's pending flags.
  * @param  FLAG: Specifies the flag to clear, it can be one of the following values:
  *            @arg PMU_CTR_CLRWUPF(Wake Up flag)
  *            @arg PMU_CTR_CLRPWDF(power down flag)
  * @return None.
  */
#define __PMU_CTR_FLAG_CLEAR(FLAG)           (PMU->CTR |= (FLAG))

/**
  * @brief  Enables the PMU CTR2 functionality.
  * @param  value: Specifies the function, it can be one of the following values:
  *            @arg PMU_ENABLE_BIT_LPPD
  *            @arg PMU_ENABLE_BIT_LPPDINT
  *            @arg PMU_ENABLE_BIT_HPPD
  *            @arg PMU_ENABLE_BIT_HPPDINT
  * @return None.
  */
#define __PMU_CTR2_FUNC_ENABLE(value)        (PMU->CTR2 |= (value))
           
/**
  * @brief  Disables the PMU CTR2 functionality.
  * @param  FUNC: Specifies the function, it can be one of the following values:
  *            @arg PMU_ENABLE_BIT_LPPD
  *            @arg PMU_ENABLE_BIT_LPPDINT
  *            @arg PMU_ENABLE_BIT_HPPD
  *            @arg PMU_ENABLE_BIT_HPPDINT
  * @return None.
  */                                  
#define __PMU_CTR2_FUNC_DISABLE(value)       (PMU->CTR2 &= ~(value))

/**
  * @brief  Get the PMU CTR2 relevant cnt clear.
  * @param  value: Specifies the relevant cnt clear, it can be one of the following values:
  *            @arg PMU_CNT_CLR_BIT_LPPD
  *            @arg PMU_CNT_CLR_BIT_HPPD
  * @return None.
  */
#define __PMU_CTR2_CNT_CLEAR(value)          (PMU->CTR2 |= (value))

/**
  * @brief  Enables the PMU CTR3 functionality.
  * @param  value: Specifies the function, it can be one of the following values:
  *            @arg PMU_ENABLE_BIT_LPPD1
  *            @arg PMU_ENABLE_BIT_LPPD1INT
  *            @arg PMU_ENABLE_BIT_HPPD1
  *            @arg PMU_ENABLE_BIT_HPPD1INT
  * @return None.
  */
#define __PMU_CTR3_FUNC_ENABLE(value)        (PMU->CTR3 |= (value))
           
/**
  * @brief  Disables the PMU CTR3 functionality.
  * @param  FUNC: Specifies the function, it can be one of the following values:
  *            @arg PMU_ENABLE_BIT_LPPD1
  *            @arg PMU_ENABLE_BIT_LPPD1INT
  *            @arg PMU_ENABLE_BIT_HPPD1
  *            @arg PMU_ENABLE_BIT_HPPD1INT
  * @return None.
  */                                  
#define __PMU_CTR3_FUNC_DISABLE(value)       (PMU->CTR3 &= ~(value))

/**
  * @brief  Get the PMU CTR3 relevant cnt clear.
  * @param  value: Specifies the relevant cnt clear, it can be one of the following values:
  *            @arg PMU_CNT_CLR_BIT_LPPD1
  *            @arg PMU_CNT_CLR_BIT_HPPD1
  * @return None.
  */
#define __PMU_CTR3_CNT_CLEAR(value)          (PMU->CTR3 |= (value))

/**
  * @brief  Enables the PMU CS functionality.
  * @param  FUNC: Specifies the function, it can be one of the following values:
  *            @arg PMU_ENABLE_BIT_WAKEUP_PIN1
  *            @arg PMU_ENABLE_BIT_WAKEUP_PIN3
  *            @arg PMU_ENABLE_BIT_WAKEUP_PIN4
  * @return None.
  */
#define __PMU_CS_FUNC_ENABLE(value)          (PMU->CS |= (value))
           
/**
  * @brief  Disables the PMU CS functionality.
  * @param  FUNC: Specifies the function, it can be one of the following values:
  *            @arg PMU_ENABLE_BIT_WAKEUP_PIN1
  *            @arg PMU_ENABLE_BIT_WAKEUP_PIN3
  *            @arg PMU_ENABLE_BIT_WAKEUP_PIN4
  * @return None.
  */                                  
#define __PMU_CS_FUNC_DISABLE(value)         (PMU->CS &= ~(value))

/**
  * @brief  PULL_UP the PMU wakeup pin.
  * @param  PIN: Specifies the wakeup pin, it can be one of the following values:
  *            @arg PMU_POLARITY_BIT_WAKEUP_PIN1
  *            @arg PMU_POLARITY_BIT_WAKEUP_PIN3
  *            @arg PMU_POLARITY_BIT_WAKEUP_PIN4
  * @return None.
  */
#define __PMU_CS_POLARITY_PULL_UP(PIN)       (PMU->CS |= (PIN))
           
/**
  * @brief  PULL_DOWN the PMU wakeup pin.
  * @param  PIN: Specifies the wakeup pin, it can be one of the following values:
  *            @arg PMU_POLARITY_BIT_WAKEUP_PIN1
  *            @arg PMU_POLARITY_BIT_WAKEUP_PIN3
  *            @arg PMU_POLARITY_BIT_WAKEUP_PIN4
  * @return None.
  */                                  
#define __PMU_CS_POLARITY_PULL_DOWN(value)   (PMU->CS &= ~(value))

/**
  * @brief  Checks whether the specified PMU flag is set or not.
  * @param  value: Specifies the flag to check, it can be one of the following values:
  *            @arg PMU_FLAG_WUPF
  *            @arg PMU_FLAG_PWDF
  *            @arg PMU_FLAG_LVD_VDD
  *            @arg PMU_FLAG_WUPF1
  *            @arg PMU_FLAG_WUPF3
  *            @arg PMU_FLAG_WUPF4
  *            @arg PMU_FLAG_LVD_LDO
  *            @arg PMU_FLAG_HVD_LDO
  *            @arg PMU_FLAG_HVD_VDD  
  *            @arg PMU_FLAG_LDOLVDF
  *            @arg PMU_FLAG_LDOHVDF
  *            @arg PMU_FLAG_LVDF
  *            @arg PMU_FLAG_HVDF
  *            @arg PMU_FLAG_LPPD1IF
  *            @arg PMU_FLAG_HPPD1IF
  *            @arg PMU_FLAG_LPPD0IF
  *            @arg PMU_FLAG_HPPD0IF
  * @return SET or RESET.
  */
#define __PMU_CS_FLAG_STATUS_GET(value)      ((PMU->CS & (value)) ? SET : RESET)

/**
  * @brief  Clear the specified PMU flag.
  * @param  value: Specifies the flag to clear, it can be one of the following values:
  *            @arg PMU_FLAG_LDOLVDF
  *            @arg PMU_FLAG_LDOHVDF
  *            @arg PMU_FLAG_LVDF
  *            @arg PMU_FLAG_HVDF
  *            @arg PMU_FLAG_LPPD1IF
  *            @arg PMU_FLAG_HPPD1IF
  *            @arg PMU_FLAG_LPPD0IF
  *            @arg PMU_FLAG_HPPD0IF
  * @return None.
  */
#define __PMU_CS_FLAG_STATUS_CLEAR(value)     (PMU->CS |= (value))


/**
  * @brief  Enables the PMU TS functionality.
  * @param  FUNC: Specifies the function, it can be one of the following values:
  *            @arg PMU_ENABLE_BIT_TS
  *            @arg PMU_ENABLE_BIT_TSLOW_INT
  *            @arg PMU_ENABLE_BIT_TSHIGH_INT
  *            @PMU_ENABLE_BIT_COMPARATOR
  * @return None.
  */
#define __PMU_TS_FUNC_ENABLE(value)          (PMU->TS |= (value))
           
/**
  * @brief  Disables the PMU CS functionality.
  * @param  FUNC: Specifies the function, it can be one of the following values:
  *            @arg PMU_ENABLE_BIT_TS
  *            @arg PMU_ENABLE_BIT_TSLOW_INT
  *            @arg PMU_ENABLE_BIT_TSHIGH_INT
  *            @PMU_ENABLE_BIT_COMPARATOR
  * @return None.
  */                                  
#define __PMU_TS_FUNC_DISABLE(value)         (PMU->TS &= ~(value))

/**
  * @brief  Checks whether the specified PMU flag is set or not.
  * @param  value: Specifies the flag to check, it can be one of the following values:
  *            @arg PMU_FLAG_BIT_TS_LO
  *            @arg PMU_FLAG_BIT_TS_HO
  *            @arg PMU_FLAG_BIT_TS_LOW_INT
  *            @arg PMU_FLAG_BIT_TS_HIGH_INT
  * @return SET or RESET.
  */
#define __PMU_TS_FLAG_STATUS_GET(value)      ((PMU->TS & (value)) ? SET : RESET)

/**
  * @brief  Enters Sleep mode.
  * @param  value: Specifies if sleep mode in entered with WFI or WFE instruction.
  *          This parameter can be one of the following values:
  *            @arg PMU_SLEEP_ENTRY_WFI (enter SLEEP mode with WFI instruction)
  *            @arg PMU_SLEEP_ENTRY_WFE (enter SLEEP mode with WFE instruction)
  * @note   In Sleep mode, all I/O pins keep the same state as in Run mode.
  * @return None.
  */
void pmu_sleep_mode_set(uint8_t value);

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
void pmu_deep_sleep_mode_enter(uint32_t value, uint8_t flag);

/**
  * @brief  Enters power down mode. The Wakeup flag (WUF) need to be cleared
  *         at application level before to call this function.    
  * @param  None.
  * @return None.
  */
void pmu_power_down_enter(void);

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
void pmu_lvd_filter_config(uint32_t value);

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
void pmu_hvd_filter_config(uint32_t value);

/**
  * @brief  Get the PMU CTR relevant cnt.
  * @param  ppd_type: Specifies the ppd type. It can be:
  *          PMU_LPPD or PMU_LPPD.
  * @param  count_type: Specifies the relevant cnt, it can be one of the following values:
  *            @arg PMU_ENABLE_BIT_LPPD_CNT
  *            @arg PMU_ENABLE_BIT_LPPD_VTH
  *            @arg PMU_ENABLE_BIT_HPPD_CNT
  *            @arg PMU_ENABLE_BIT_HPPD_VTH
  * @return The count of ppd.
  */
uint32_t pmu_ppd_cnt_get(uint8_t ppd_type, uint32_t count_type);

/**
  * @brief  Checks whether the specified PMU flag is set or not.
  * @param  value: Specifies the flag to check, it can be one of the following values:
  *            @arg PMU_TS_HIGH_TEMPERATURE_105
  *            @arg PMU_TS_HIGH_TEMPERATURE_125
  * @return None.
  */
void pmu_ts_high_temperature_select(uint32_t value);
/**
  * @}
  */


#ifdef __cplusplus
}
#endif

#endif /* cbm858xm_pmu.h */


/**
  * @}
  */

/**
  * @}
  */

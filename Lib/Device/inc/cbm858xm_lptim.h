/**
* @file        cbm858xm_lptim.h
* @brief       This file contains all the functions prototypes for the lptim firmware library. 
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


#ifndef __CBM858xM_LPTIM_H__
#define __CBM858xM_LPTIM_H__


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

/** @addtogroup LPTIM
  * @{
  */

/***************************************************************************************************
 * @definitions
***************************************************************************************************/
/** @defgroup Lptim_Exported_Types Lptim Exported Types
  * @{
  */
/** @struct lptim_config_t  
  * @brief LPTIM init structure definition
  */
typedef struct
{
    uint32_t        prescaler;      /*!< Specifies the counter clock Prescaler. */
    uint32_t        polarity;       /*!< Specifies the Output polarity. */
    uint32_t        waveform;       /*!< Specifies the waveform shape. */                                                 
} lptim_config_t;

/**
  * @}
  */


/** @defgroup Lptim_Exported_Constants Lptim Exported Constants
  * @{
  */

//Fill the content
/**
  * @}
  */

/** @defgroup Lptim_Prescaler_Value LPTIM Prescaler Value definition
  * @{
  */
#define LPTIM_PRESCALER_DIV1                    ((uint32_t)0x00000000)                          /*!< Prescaler division factor is 1. */
#define LPTIM_PRESCALER_DIV2                    LPTIM_CFGR_PRESC_0                              /*!< Prescaler division factor is 2. */
#define LPTIM_PRESCALER_DIV4                    LPTIM_CFGR_PRESC_1                              /*!< Prescaler division factor is 4. */
#define LPTIM_PRESCALER_DIV8                    (LPTIM_CFGR_PRESC_1 | LPTIM_CFGR_PRESC_0)       /*!< Prescaler division factor is 8. */
#define LPTIM_PRESCALER_DIV16                   LPTIM_CFGR_PRESC_2                              /*!< Prescaler division factor is 16. */
#define LPTIM_PRESCALER_DIV32                   (LPTIM_CFGR_PRESC_2 | LPTIM_CFGR_PRESC_0)       /*!< Prescaler division factor is 32. */
#define LPTIM_PRESCALER_DIV64                   (LPTIM_CFGR_PRESC_2 | LPTIM_CFGR_PRESC_1)       /*!< Prescaler division factor is 64. */
#define LPTIM_PRESCALER_DIV128                  LPTIM_CFGR_PRESC                                /*!< Prescaler division factor is 128. */
/**
  * @}
  */

/*! Checks LPTIM Prescaler Value definition. */
#define LPTIM_CLOCK_PRESCALER_CHECK(value)      (((value) == LPTIM_PRESCALER_DIV1)  || ((value) == LPTIM_PRESCALER_DIV2)  || \
                                                 ((value) == LPTIM_PRESCALER_DIV4)  || ((value) == LPTIM_PRESCALER_DIV8)  || \
                                                 ((value) == LPTIM_PRESCALER_DIV16) || ((value) == LPTIM_PRESCALER_DIV32) || \
                                                 ((value) == LPTIM_PRESCALER_DIV64) || ((value) == LPTIM_PRESCALER_DIV128))

/** @defgroup Lptim_Output_Waveform_Type LPTIM Output Waveform Type definition
  * @{
  */
#define LPTIM_OUTPUT_WAVEFORM_PWM               ((uint32_t)0x00000000)      /*!< LPTIM  generates either a PWM waveform or \
                                                                             a One pulse waveform depending on chosen  \
                                                                             operating mode CONTINOUS or SINGLE. */
#define LPTIM_OUTPUT_WAVEFORM_SETONCE           LPTIM_CFGR_WAVE             /*!< LPTIM  generates a Set Once waveform. */
/**
  * @}
  */

/*! Checks LPTIM Output Waveform Type definition. */
#define LPTIM_WAVEFORM_CHECK(value)             (((value) == LPTIM_OUTPUT_WAVEFORM_PWM) || \
                                                ((value) == LPTIM_OUTPUT_WAVEFORM_SETONCE))


/** @defgroup Lptim_count_mode LPTIM count mode definition
  * @{
  */
#define LPTIM_COUNT_INTER_CLOCK                 ((uint32_t)0x00000000) /*!< The counter is incremented after each  \
                                                                            internal clock pulse. */
#define LPTIM_COUNT_EXTER_CLOCK                 ((uint32_t)0x00800000) /*!< The counter is incremented after each  \
                                                                            valid clock pulse on LPTIM external input1 */
/**
  * @}
  */
/*! Checks LPTIM count mode definition. */
#define LPTIM_COUNT_MODE_CHECK(value)           (((value) == LPTIM_COUNT_INTER_CLOCK) || \
                                                ((value) == LPTIM_COUNT_EXTER_CLOCK))


/** @defgroup Lptim_Output_Polarity LPTIM Output Polarity definition
  * @{
  */
#define LPTIM_OUTPUT_POLARITY_REGULAR           ((uint32_t)0x00000000)      /*!< The LPTIM output reflects the compare      \
                                                                             results between LPTIMx_ARR and LPTIMx_CMP  \
                                                                             registers. */
#define LPTIM_OUTPUT_POLARITY_INVERSE           LPTIM_CFGR_WAVPOL           /*!< The LPTIM output reflects the inverse of   \
                                                                             the compare results between LPTIMx_ARR and \
                                                                             LPTIMx_CMP registers. */
/**
  * @}
  */

/*! Checks LPTIM Output Polarity definition. */
#define LPTIM_OUTPUT_POLARITY_CHECK(value)      (((value) == LPTIM_OUTPUT_POLARITY_REGULAR) || \
                                                 ((value) == LPTIM_OUTPUT_POLARITY_INVERSE))

/** @defgroup Lptim_start_mode LPTIM start mode definition
  * @{
  */
#define LPTIM_START_MODE_CONTINUOUS             LPTIM_CR_CNTSTRT        /*!< Start in continuous mode. */
#define LPTIM_START_MODE_SINGLEPULSE            LPTIM_CR_SNGSTRT        /*!< Start in single pulse mode. */
/**
  * @}
  */

/*! Checks LPTIM start mode definition. */
#define LPTIM_START_MODE_CHECK(mode)            (((mode) == LPTIM_START_MODE_CONTINUOUS) || \
                                                ((mode) == LPTIM_START_MODE_SINGLEPULSE))

/** @defgroup Lptim_update_mode LPTIM update mode definition
  * @{
  */
#define LPTIM_UPDATE_MODE_IMMEDIATE             ((uint32_t)0x00000000)      /*!< Register is updated after each APB bus \
                                                                             write operation. */
#define LPTIM_UPDATE_MODE_ENDOFPERIOD           LPTIM_CFGR_PRELOAD          /*!< The register is updated at the end of the \
                                                                             current LPTIM cycle. */
/**
  * @}
  */

/*! Checks LPTIM update mode definition. */
#define LPTIM_UPDATE_MODE_CHECK(mode)           (((mode) == LPTIM_UPDATE_MODE_IMMEDIATE) || \
                                                ((mode) == LPTIM_UPDATE_MODE_ENDOFPERIOD))

/** @defgroup Lptim_trigger_source LPTIM trigger source definition
  * @{
  */
#define LPTIM_EXT_TRIG0                         ((uint32_t)0x00000000)                              /*!< Used as GPIO pin (PA2) of multiplexing function. */
#define LPTIM_EXT_TRIG1                         LPTIM_CFGR_TRIGSEL_0                                /*!< RTC alarm clock A. */
#define LPTIM_EXT_TRIG2                         LPTIM_CFGR_TRIGSEL_1                                /*!< RTC alarm clock B. */
#define LPTIM_EXT_TRIG3                         (LPTIM_CFGR_TRIGSEL_1 | LPTIM_CFGR_TRIGSEL_0)       /*!< TAMP1 input detection. */
#define LPTIM_EXT_TRIG4                         LPTIM_CFGR_TRIGSEL_2                                /*!< TAMP2 input detection. */
#define LPTIM_EXT_TRIG5                         (LPTIM_CFGR_TRIGSEL_2 | LPTIM_CFGR_TRIGSEL_0)       /*!< Reserved. */
#define LPTIM_EXT_TRIG6                         (LPTIM_CFGR_TRIGSEL_2 | LPTIM_CFGR_TRIGSEL_1)       /*!< COMP1_OUT. */
#define LPTIM_EXT_TRIG7                         LPTIM_CFGR_TRIGSEL                                  /*!< COMP2_OUT. */
/**             
  * @}
  */
  
/*! Checks LPTIM trigger source definition. */
#define LPTIM_EXT_TRIG_CHECK(value)             (((value) == LPTIM_EXT_TRIG0) || ((value) == LPTIM_EXT_TRIG1) || \
                                                ((value) == LPTIM_EXT_TRIG2) || ((value) == LPTIM_EXT_TRIG3) || \
                                                ((value) == LPTIM_EXT_TRIG4) || ((value) == LPTIM_EXT_TRIG5) || \
                                                ((value) == LPTIM_EXT_TRIG6) || ((value) == LPTIM_EXT_TRIG7))

#define LPTIM_EXT_TRIG0_CHECK(value)            ((value) == LPTIM_EXT_TRIG0)

/** @defgroup LPTIM_tri_flt Lptim trig filter
  * @{
  */
#define LPTIM_TRIG_FILTER_NONE                  ((uint32_t)0x00000000)      /*!< Any trigger signal is regarded as an effective trigger. */  
#define LPTIM_TRIG_FILTER_2                     LPTIM_CFGR_TRGFLT_0         /*!< At least 2 clock cycles shall be stabilized before     \
                                                                                 it can be regarded as a valid trigger. */
#define LPTIM_TRIG_FILTER_4                     LPTIM_CFGR_TRGFLT_1         /*!< At least 4 clock cycles shall be stabilized before     \
                                                                                 it can be regarded as a valid trigger. */
#define LPTIM_TRIG_FILTER_8                     LPTIM_CFGR_TRGFLT           /*!< At least 8 clock cycles shall be stabilized before     \
                                                                                 it can be regarded as a valid trigger. */
/**
  * @}
  */

/*! Checks LPTIM trigger filter definition. */
#define LPTIM_TRIG_FILTER_CHECK(value)          (((value) == LPTIM_TRIG_FILTER_NONE) || ((value) == LPTIM_TRIG_FILTER_2) || \
                                                ((value) == LPTIM_TRIG_FILTER_4)    || ((value) == LPTIM_TRIG_FILTER_8))


/** @defgroup LPTIM_tri_polarity Lptim trig polarity
  * @{  
  */    
#define LPTIM_TRIG_POLARITY_SW                  ((uint32_t)0x00000000)  /*!< The software trigger. */
#define LPTIM_TRIG_POLARITY_RISING              LPTIM_CFGR_TRIGEN_0     /*!< The rising edge is the effective edger. */  
#define LPTIM_TRIG_POLARITY_FALLING             LPTIM_CFGR_TRIGEN_1     /*!< The falling edge is the effective edger. */  
#define LPTIM_TRIG_POLARITY_RISING_FALLING      LPTIM_CFGR_TRIGEN       /*!< The rising or fallingedge is the effective edger. */  
/**
  * @}
  */

/*! Checks LPTIM trigger polarity definition. */
#define LPTIM_TRIG_POLARITY_CHECK(value)        (((value) == LPTIM_TRIG_POLARITY_SW)      || \
                                                 ((value) == LPTIM_TRIG_POLARITY_RISING)  || \
                                                 ((value) == LPTIM_TRIG_POLARITY_FALLING) || \
                                                 ((value) == LPTIM_TRIG_POLARITY_RISING_FALLING))

/** @defgroup LPTIM_input1_multiplexer_selection LPTIM input1 multiplexer selection
  * @{  
  */   
#define LPTIM_IN_MUX0       ((uint32_t)0x00000000)      /*!< LPTIM input1 MUX0. */
#define LPTIM_IN_MUX1       ((uint32_t)0x00000001)          /*!< LPTIM input1 MUX1. */
#define LPTIM_IN_MUX2       ((uint32_t)0x00000002)      /*!< LPTIM input1 MUX2. */
#define LPTIM_IN_MUX3       LPTIM_CFGR2_IN1SEL          /*!< LPTIM input1 MUX3. */
/**
  * @}
  */

/** @defgroup LPTIM_Macro_function LPTIM Macro function definition
  * @{
  */

/**
  * @brief	Deinitializes the LPTIM peripheral registers to their default reset values.   
  * @param  None                               
  * @return None
  */
#define __LPTIM_DEF_INIT()					  do{ \
													((RCU_PERI_RST_REG_LPTIM) |= (RCU_PERI_RST_BIT_LPTIM)); \
													((RCU_PERI_RST_REG_LPTIM) &= ~(RCU_PERI_RST_BIT_LPTIM)); \
												}while(0U)

/**
  * @brief  Enables the specified LPTIM interrupts.                                                                        
  * @param  INT: enabled specifies the LPTIM interrupts sources.
  *          It can be any combination of the following values:
  *          @arg LPTIM_IER_CMPMIE (Compare match interrupt)
  *          @arg LPTIM_IER_ARRMIE (Auto load match interrupt)
  *          @arg LPTIM_IER_EXTTRIGIE (External trigger edge event interrupt)
  *          @arg LPTIM_IER_CMPOKIE (Comparison register update complete interrupt)
  *          @arg LPTIM_IER_ARROKIE (Auto load register update complete interrupt)
  *          @arg LPTIM_IER_UPIE (Counter direction change down to up Interrupt Enable )
  *          @arg LPTIM_IER_DOWNIE (Counter direction change up to down Interrupt Enable )
  *          @arg LPTIM_IER_UEIE (LPTIM update event occurs interrupt)
  *          @arg LPTIM_IER_REPOKIE (LPTIM REP register updata success interrupt)
  *          @arg LPTIM_IER_ARRUFIE (Automatic overload counter underflow interrupt Enable)
  * @return None
  */
#define __LPTIM_INTR_ENABLE(INT)			    (LPTIM->IER |= INT)

/**
  * @brief  Disables the specified LPTIM interrupts.                                                                        
  * @param  INT: Disabled specifies the LPTIM interrupts sources.
  *          It can be any combination of the following values:
  *          @arg LPTIM_IER_CMPMIE (Compare match interrupt)
  *          @arg LPTIM_IER_ARRMIE (Auto load match interrupt)
  *          @arg LPTIM_IER_EXTTRIGIE (External trigger edge event interrupt)
  *          @arg LPTIM_IER_CMPOKIE (Comparison register update complete interrupt)
  *          @arg LPTIM_IER_ARROKIE (Auto load register update complete interrupt)
  *          @arg LPTIM_IER_UPIE (Counter direction change down to up Interrupt Enable )
  *          @arg LPTIM_IER_DOWNIE (Counter direction change up to down Interrupt Enable )
  *          @arg LPTIM_IER_UEIE (LPTIM update event occurs interrupt)
  *          @arg LPTIM_IER_REPOKIE (LPTIM REP register updata success interrupt)
  *          @arg LPTIM_IER_ARRUFIE (Automatic overload counter underflow interrupt Enable)
  * @return None
  */
#define __LPTIM_INTR_DISABLE(INT)			    (LPTIM->IER &= ~(INT))

/**
  * @brief  Checks whether the LPTIM interrupt has enabled or not.
  * @param  INT: specifies the LPTIM interrupt source.
  *			It can be one of the following values:
  *          @arg LPTIM_IER_CMPMIE (Compare match interrupt)
  *          @arg LPTIM_IER_ARRMIE (Auto load match interrupt)
  *          @arg LPTIM_IER_EXTTRIGIE (External trigger edge event interrupt)
  *          @arg LPTIM_IER_CMPOKIE (Comparison register update complete interrupt)
  *          @arg LPTIM_IER_ARROKIE (Auto load register update complete interrupt)
  *          @arg LPTIM_IER_UPIE (Counter direction change down to up Interrupt Enable )
  *          @arg LPTIM_IER_DOWNIE (Counter direction change up to down Interrupt Enable )
  *          @arg LPTIM_IER_UEIE (LPTIM update event occurs interrupt)
  *          @arg LPTIM_IER_REPOKIE (LPTIM REP register updata success interrupt)
  *          @arg LPTIM_IER_ARRUFIE (Automatic overload counter underflow interrupt Enable)
  * @return SET or RESET.
  */
#define __LPTIM_INTR_ENABLE_STATUS_GET(INT)     (((LPTIM->IER) & (INT)) ? SET : RESET)

/**
  * @brief  Checks whether the specified LPTIM flag is set or not.                                                         
  * @param  FLAG: specifies the flag to check, it can be one of the following values:
  *          @arg LPTIM_ISR_CMPM (Compare match)
  *          @arg LPTIM_ISR_ARRM (Auto load match)
  *          @arg LPTIM_ISR_EXTTRIG (External trigger edge event)
  *          @arg LPTIM_ISR_CMPOK (Comparison register update complete)
  *          @arg LPTIM_ISR_ARROK (Auto load register update complete)
  *          @arg LPTIM_ISR_UE (LPTIM update event occurs)
  *          @arg LPTIM_ISR_REPOK (LPTIM REP register updata success)
  * @return SET or RESET.
  */
#define __LPTIM_FLAG_STATUS_GET(FLAG)		    (((LPTIM->ISR) & (FLAG)) ? SET : RESET)

/**
  * @brief  Clears the LPTIM's flags.                                                                                      
  * @param  FLAG: specifies the flag to clear,it can be any combination of the following values:
  *          @arg LPTIM_ICR_CMPMCF (Compare match flag)
  *          @arg LPTIM_ICR_ARRMCF (Auto load match flag)
  *          @arg LPTIM_ICR_EXTTRIGCF (External trigger edge event flag)
  *          @arg LPTIM_ICR_CMPOKCF (Comparison register update complete flag)
  *          @arg LPTIM_ICR_ARROKCF (Auto load register update complete flag)
  *          @arg LPTIM_ICR_UECF (LPTIM update event occurs flag)
  *          @arg LPTIM_ICR_REPOK (LPTIM REP register updata success flag)
  * @return None
  */
#define __LPTIM_FLAG_CLEAR(FLAG)			    (LPTIM->ICR = FLAG)

/**
  * @brief  Enables the specified LPTIM timeout.
  * @param  None
  * @return None
  */
#define __LPTIM_TIMOUT_ENABLE()		            (LPTIM->CFGR |= LPTIM_CFGR_TIMOUT)

/**
  * @brief  Disables the specified LPTIM timeout.
  * @param  None
  * @return None
  */
#define __LPTIM_TIMOUT_DISABLE()		        (LPTIM->CFGR &= ~LPTIM_CFGR_TIMOUT)

/**
  * @brief  Enables the function that any read access to the CNT register will asynchronously reset the contents of CNT register.                                                                         
  * @param  None        
  * @return None
  */
#define __LPTIM_COUNTER_READ_RESET_ENABLE()	    ((LPTIM->CR) |= LPTIM_CR_RSTARE)

/**
  * @brief  Disables the function that any read access to the CNT register will asynchronously reset the contents of CNT register.                                                                         
  * @param  None        
  * @return None
  */
#define __LPTIM_COUNTER_READ_RESET_DISABLE()    ((LPTIM->CR) &= ~LPTIM_CR_RSTARE)

/**
  * @brief  Trigger LPTIM Synchronous reset of CNT counter register.  
  * @note   It should be checked whether COUNTRST bit has been cleared by using __LPTIM_COUNTRST_FLAG_STATUS_GET() 
              before calling __LPTIM_COUNTER_RESET().  
  * @param  None        
  * @return None
  */
#define __LPTIM_COUNTER_RESET()	                ((LPTIM->CR) |= LPTIM_CR_COUNTRST)

/**
  * @brief  Get the status of LPTIM LPTIM_CR_COUNTRST bit.                                                                         
  * @note   It should be checked whether COUNTRST bit has been cleared before calling __LPTIM_COUNTER_RESET().
  * @param  None        
  * @return None
  */
#define __LPTIM_COUNTRST_FLAG_STATUS_GET()	    ((LPTIM->CR & LPTIM_CR_COUNTRST) ? SET : RESET)

/**
  * @brief  Indicates whether the LPTIM is enabled.
  * @return SET or RESET
  */
#define __LPTIM_ENABLE_STATUS_GET()		        (((LPTIM->CR) & (LPTIM_CR_ENABLE)) ? SET : RESET)

/**
  * @brief  Enables the LPTIM peripheral.
  * @return None
  */
#define __LPTIM_ENABLE()			            (LPTIM->CR |= LPTIM_CR_ENABLE)

/**
  * @brief  Disables the LPTIM peripheral.
  * @return None
  */
#define __LPTIM_DISABLE()			            (LPTIM->CR &= ~(LPTIM_CR_ENABLE)) 

/**
  * @brief  Sets the LPTIM COMPARE Register campare value
  * @param  VALUE: specifies the COMPARE register new campare value.
  * @note   LPTIM must be enabled before Setting the new camparevalue.
  * @note   Compare value VALUE between Min_Data=0x00 and Max_Data=0xFFFF
  * @return None
  */
#define __LPTIM_COMPARE_SET(VALUE)		        (LPTIM->CMP = VALUE)

/**
  * @brief  Gets the LPTIM COMPARE Register campare value
  * @param  None.
  * @return LPTIM COMPARE Register campare value
  */
#define __LPTIM_COMPARE_GET()                   (LPTIM->CMP)

/**
  * @brief  Sets the LPTIM ARR Register auto reload value
  * @param  VALUE: specifies the ARR register new auto reload value.
  * @note   LPTIM must be enabled before Setting the LPTIM ARR Register auto reload value
  * @note   This value must be strictly greater than the value of CMP [15:0].
  * @note   AutoReload value VALUE between Min_Data=0x00 and Max_Data=0xFFFF
  * @return None
  */
#define __LPTIM_AUTO_RELOAD_SET(VALUE)	        (LPTIM->ARR = VALUE)

/**
  * @brief  Gets the LPTIM ARR Register auto reload value
  * @param  None.
  * @return LPTIM ARR Register auto reload value
  */
#define __LPTIM_AUTO_RELOAD_GET()	            (LPTIM->ARR)

/**
  * @brief  Gets the LPTIM Counter value.
  * @param  None.
  * @return Counter Register value.
  */
#define __LPTIM_COUNTER_GET()			        (LPTIM->CNT)

/**
  * @brief  Sets LPTIM input multiplexer, This interface is only called when LPTIM needs an external clock as input.                                                                       
  * @param  MUX: multiplexer selection. It can be LPTIM_IN_MUXx, where x can be 0, 1, 2, 3.
  * @return None
  */
#define __LPTIM_INPUT_SET(MUX)			        (MODIFY_REG(LPTIM->CFGR2, LPTIM_CFGR2_IN1SEL, MUX))

/**
  * @brief  Sets the LPTIM RCR Register value
  * @param  VALUE: specifies the RCR register value.
  * @note   Only when LPTIM is enabled the RCR Register can be set.
  * @note   This value VALUE between Min_Data=0x00 and Max_Data=0xFF
  * @return None
  */
#define __LPTIM_REP_SET(VALUE)		        (LPTIM->RCR = (VALUE & 0xFF))

/**
  * @brief  Gets the LPTIM RCR Register value
  * @param  None.
  * @return LPTIM RCR Register value
  */
#define __LPTIM_REP_GET()                   (LPTIM->RCR & 0xFF)

/**
  * @}
  */

/***************************************************************************************************
 * @functions
***************************************************************************************************/
/** @defgroup Lptim_Exported_Functions Lptim Exported Functions
  * @{
  */

/**
 * @brief       Initializes the LPTIM config parameters according to the specified parameters in the lptim_config.
 *              lptim_init() can only be called when the LPTIM is disabled.
 * @param       ptr_config: pointer to a lptim_config_t structure that contains the configuration information for the
 *              specified LPTIM peripheral.
 * @return      None.
 */
void lptim_init(lptim_config_t* ptr_config);

/**
 * @brief       Set the startup mode of the LPTIM counter. LPTIM must be enabled before starting the counter.
 * @param       start_mode:the startup mode of the LPTIM counter, It can be LPTIM_START_MODE_CONTINUOUS or
 *              LPTIM_START_MODE_SINGLEPULSE. 
 * @return      None.
 */
void lptim_start_mode_set(uint32_t start_mode);

/**
 * @brief       Set the update mode of the LPTIM counter. LPTIM must be disabled before calling this function.
 * @param       update_mode:the update mode of the LPTIM counter, It can be LPTIM_UPDATE_MODE_IMMEDIATE or
 *              LPTIM_UPDATE_MODE_ENDOFPERIOD. 
 * @return      None.
 */
void lptim_update_mode_set(uint32_t  update_mode);

/**
 * @brief       Set the update mode of the LPTIM counter. LPTIM must be disabled before calling this function.
 * @param       count_mode:the count mode of the LPTIM counter, It can be LPTIM_COUNT_INTER_CLOCK or
 *              LPTIM_COUNT_EXTER_CLOCK. 
 * @return      None.
 */
void lptim_count_mode_set(uint32_t  count_mode);

/**
 * @brief       Configure the external trigger used as a trigger event for the LPTIM. LPTIM must be disabled before 
 *              calling this function.
 * @param       trigger_source: external trigger source, It can be LPTIM_EXT_TRIGx, where x can be 0 - 7. Used as GPIO 
 *              pin (PA2) of multiplexing function
 * @param       filter:Trigger filter filtering mode, It can be one of the following values: @ref LPTIM_tri_flt.
 * @param       trigger_polarity:Trigger polarity, It can be one of the following values: @ref LPTIM_tri_polarity.
 * @return      None.
 */
void lptim_trigger_config(uint32_t trigger_source, uint32_t filter, uint32_t trigger_polarity);

/**
  * @}
  */


#ifdef __cplusplus
}
#endif

#endif /* cbm858xm_lptim.h */


/**
  * @}
  */

/**
  * @}
  */

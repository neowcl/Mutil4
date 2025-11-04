/**
* @file        cbm858xm_acts.h
* @brief       This file contains all the functions prototypes for the active shield firmware library. 
* @author      ChipSea MCU Group
* @version     1.0.0
* @date        2022.12.20
* @copyright   CHIPSEA TECHNOLOGIES (SHENZHEN) CORP.
* @note        
****************************************************************************************************
* @par Modify record:
* <tr><th>Date          <th>Version    <th>Author     <th>Description
* <tr><td>2022.12.20    <td>1.0.0      <td>ChipSea    <td>
* -# 
* </table>
*
****************************************************************************************************
*/


#ifndef __CBM858xM_ACTS_H__
#define __CBM858xM_ACTS_H__


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

/** @addtogroup ACTS
  * @{
  */

/***************************************************************************************************
 * @definitions
***************************************************************************************************/
/** @defgroup ACTS_Exported_Types Active shield Exported Types
  * @{
  */
/** @struct acts_config_t
  * @brief Active shield config struct definition  
  */ 
typedef struct
{
    uint16_t wait_time;                         /*!< Active shield waiting time before excitation signal comparison. */
    uint16_t comp_time;      	                /*!< Active shield number of excitation signal comparison. */
    uint16_t mis_thld;                          /*!< Active shield threshold value of excitation signal comparison failure. */                                       
}acts_config_t;

/**
  * @}
  */


/** @defgroup ACTS_Exported_Constants Active shield Exported Constants
  * @{
  */
#define ACTS_INT_FSM            0x0008                  /*!< FSM enters abnormal state. */
#define ACTS_INT_LFSR           0x0004                  /*!< LFSR all 0. */
#define ACTS_INT_MIS            0x0002                  /*!< Warning for failure of excitation signal comparison. */
#define ACTS_INT_FAIL           0x0001                  /*!< Active shield failure, the excitation signal comparison failure is greater than the threshold. */

#define ACTS_INT_FSM_MASK       0x0008                  /*!< FSM enters abnormal state. */
#define ACTS_INT_LFSR_MASK      0x0004                  /*!< LFSR all 0. */
#define ACTS_INT_MIS_MASK       0x0002                  /*!< Warning for failure of excitation signal comparison. */
#define ACTS_INT_FAIL_MASK      0x0001                  /*!< Active shield failure, the excitation signal comparison failure is greater than the threshold. */


/**
  * @}
  */

/** @defgroup I2C_Macro_function I2C Macro function definition
  * @{
  */

/**
  * @brief  Enables active shield.
  * @param  None.
  * @return None.
  */
#define __ACTS_ENABLE()                        (ACTS->CTR0 |= ACTS_CTR0_EN)

/**
  * @brief  Disables active shield.
  * @param  None.
  * @return None.
  */
#define __ACTS_DISABLE()                       (ACTS->CTR0 &= ~ACTS_CTR0_EN)

/**
  * @brief  Active shield incentive to renew seed.
  * @param  VALUE: seed value.
  * @return None
  */
#define __ACTS_SEED_RENEW(VALUE)               (ACTS->SEED = (uint32_t)VALUE)

/**
  * @brief  Get the Active shield number of fail excitation signal comparison.
  * @param  None
  * @return Number of fail excitation signal comparison.
  */
#define __ACTS_MIS_COUNT_GET()                 ((uint16_t)(ACTS->STATUS))

/**
  * @brief  Get the active shield interrupt status.
  * @param  INT: specifies the interrupt status to check. It can be any combination of the following values:
  *          @arg ACTS_INT_FSM (FSM enters abnormal state)
  *          @arg ACTS_INT_LFSR (LFSR all 0)
  *          @arg ACTS_INT_MIS (Warning for failure of excitation signal comparison)
  *          @arg ACTS_INT_FAIL (Active shield failure, the excitation signal comparison failure is greater than the threshold.)
  * @return None.
  */
#define __ACTS_INT_STATUS_GET(INT)             ((ACTS->IRQ & INT) ? SET : RESET) 

/**
  * @brief  Enable the active shield interrupt mask.
  * @param  INT: specifies the interrupt status to check. It can be any combination of the following values:
  *          @arg ACTS_INT_FSM_MASK (FSM enters abnormal state interrupt mask)
  *          @arg ACTS_INT_LFSR_MASK (LFSR all 0 interrupt mask)
  *          @arg ACTS_INT_MIS_MASK (Warning for failure of excitation signal comparison interrupt mask)
  *          @arg ACTS_INT_FAIL_MASK (Active shield failure, the excitation signal comparison failure is greater than the threshold interrupt mask)
  * @return None.
  */
#define __ACTS_INT_MASK_ENABLE(INT)             (ACTS->IRQ_MSK |= INT)

/**
  * @brief  Disable the active shield interrupt mask.
  * @param  INT: specifies the interrupt status to check. It can be any combination of the following values:
  *          @arg ACTS_INT_FSM_MASK (FSM enters abnormal state interrupt mask)
  *          @arg ACTS_INT_LFSR_MASK (LFSR all 0 interrupt mask)
  *          @arg ACTS_INT_MIS_MASK (Warning for failure of excitation signal comparison interrupt mask)
  *          @arg ACTS_INT_FAIL_MASK (Active shield failure, the excitation signal comparison failure is greater than the threshold interrupt mask)
  * @return None.
  */
#define __ACTS_INT_MASK_DISABLE(INT)             (ACTS->IRQ_MSK &= ~INT)

/**
  * @brief  Get the Active shield protection line status.
  * @param  None
  * @return Active shield protection line status.Active protection line incentive comparison failure sign, corresponding to the first to the eighth line.
  */
#define __ACTS_MISMATCH0_GET()                   ((uint16_t)(ACTS->MISMATCH0))   

/**
  * @}
  */

/***************************************************************************************************
 * @functions
***************************************************************************************************/
/** @defgroup ACTS_Exported_Functions Active shield Exported Functions
  * @{
  */

/**
  * @brief  Config each ptr_struct member with its default value.
  * @param  ptr_struct: pointer to an acts_config_t structure which will be initialized.
  * @return None.
  */
void active_shield_struct_init(acts_config_t* ptr_struct);

/**
  * @brief  Initializes the active shield peripheral according to the specified parameters.
  * @param  ptr_config: pointer to an acts_config_t structure that contains 
  *         the configuration information for the specified Active shield peripheral.
  * @return None
  */
void active_shield_init(acts_config_t* ptr_config);
/**
  * @}
  */


#ifdef __cplusplus
}
#endif

#endif /* cbm858xm_acts.h */


/**
  * @}
  */

/**
  * @}
  */

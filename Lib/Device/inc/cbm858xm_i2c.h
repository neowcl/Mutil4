/**
* @file        cbm858xm_i2c.h
* @brief       This file contains all the functions prototypes for the I2C firmware library. 
* @author      ChipSea MCU Group
* @version     1.0.0
* @date        2022.05.12
* @copyright   CHIPSEA TECHNOLOGIES (SHENZHEN) CORP.
* @note        
****************************************************************************************************
* @par Modify record:
* <tr><th>Date          <th>Version    <th>Author     <th>Description
* <tr><td>2022.05.12    <td>1.0.0      <td>ChipSea    <td>
* -# 
* </table>
*
****************************************************************************************************
*/


#ifndef __CBM858xM_I2C_H__
#define __CBM858xM_I2C_H__


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

/** @addtogroup I2C
  * @{
  */

/***************************************************************************************************
 * @definitions
***************************************************************************************************/
/** @defgroup I2C_Exported_Types I2C Exported Types
  * @{
  */

/** @struct  i2c_config_t
  * @brief   I2C Init structure definition.
  */
typedef struct
{
    uint32_t tmr_value;     /*!< Specifies the I2C_TMR register value(referring to I2C Timing). */
    uint32_t analog_flag;   /*!< Enables or disables analog noise filter. */                                      
    uint32_t digital_value; /*!< Sets the digital noise filter. range in 0x00 ~ 0x0F. */                                        
    uint32_t mode;          /*!< Sets the I2C mode. */                                        
    uint32_t slave_addr1;   /*!< Sets slave address 1. It can be a 7bits or 10bits address. */                                       
    uint32_t ack_flag;      /*!< Enables or disables the acknowledgement. */                                    
    uint32_t ack_addr;      /*!< Sets acknowledge address.It can be a 7bits or 10bits address. */                                       
}i2c_config_t;

/**
  * @}
  */


/** @defgroup I2C_Exported_Constants I2C Exported Constants
  * @{
  */

/*! I2C bus check definition */
#define I2C1_BUS_CHECK(bus)                 ((bus) == I2C1)  /*!< Only I2C1 support SMBus */

/**
  * @}
  */

/** @defgroup I2C_analog_filter I2C analog filter definition
  * @{
  */
#define I2C_ANALOG_FILTER_ENABLE            ((uint32_t)0x00000000)   /*!< enable analog Filter */
#define I2C_ANALOG_FILTER_DISABLE           I2C_CTR1_AFDIS           /*!< disable analog Filter */
/**
  * @}
  */

#define I2C_ANALOG_FILTER_CHECK(flag)       (((flag) == I2C_ANALOG_FILTER_ENABLE) || ((flag) == I2C_ANALOG_FILTER_DISABLE))

/*! I2C digital filter value check */
#define I2C_DIGITAL_FILTER_CHECK(filter)    ((filter) <= 0x0000000F)

/** @defgroup I2C_bus_mode I2C bus mode definition
  * @{
  */
#define I2C_BUS_MODE_I2C                    ((uint32_t)0x00000000)  /*!< I2C mode */
#define I2C_BUS_MODE_SMBUS_DEVICE           I2C_CTR1_SMBDDAEN       /*!< SMBus Device mode */
#define I2C_BUS_MODE_SMBUS_HOST             I2C_CTR1_SMBHAEN        /*!< SMBus Host mode */
/**
  * @}
  */

#define I2C_BUS_MODE_CHECK(mode)            (((mode) == I2C_BUS_MODE_I2C) || ((mode) == I2C_BUS_MODE_SMBUS_DEVICE) || \
											((mode) == I2C_BUS_MODE_SMBUS_HOST))

/** @defgroup I2C_ACK_enable I2C ACK enable definition
  * @{
  */
#define I2C_ACK_ENABLE                      ((uint32_t)0x00000000)  /*!< enable ACK */
#define I2C_ACK_DISABLE                     I2C_CTR2_NACKGEN        /*!< disable ACK */
/**
  * @}
  */

#define I2C_ACK_CONFIG_CHECK(ACK)           (((ACK) == I2C_ACK_ENABLE) || ((ACK) == I2C_ACK_DISABLE))  

/** @defgroup I2C_Addressing_format I2C Addressing format definition
  * @{
  */
#define I2C_ACK_ADDR_7BITS                  ((uint32_t)0x00000000)  /*!< Slave Address 7bits */
#define I2C_ACK_ADDR_10BITS                 I2C_SADR1_SADR1MODE     /*!< Slave Address 10bits */
/**
  * @}
  */

#define I2C_ACK_ADDR_CHECK(addr)            (((addr) == I2C_ACK_ADDR_7BITS) || ((addr) == I2C_ACK_ADDR_10BITS))
                                          
/*! I2C slave addr1 check definition */
#define I2C_SLAVE_ADDR1_CHECK(addr)         ((addr) <= (uint32_t)0x000003FF) 

/*! I2C slave addr2 check definition */
#define I2C_SLAVE_ADDR2_CHECK(addr)         ((addr) <= (uint16_t)0x00FF)

/** @defgroup I2C_data_Tx/Rx_direction I2C data Tx/Rx direction definition
  * @{
  */
#define I2C_DIRECTION_TX                    ((uint16_t)0x0000)      /*!<set data Transfer direction for writing */
#define I2C_DIRECTION_RX                    ((uint16_t)0x0400)      /*!<set data Transfer direction for reading */ 
/**
  * @}
  */

#define I2C_DIRECTION_CHECK(direct)         (((direct) == I2C_DIRECTION_TX) || ((direct) == I2C_DIRECTION_RX))
                                         
/*! check  I2c slave address2 mask value definition */
#define I2C_SLAVE_ADDR2_MASK_CHECK(mask)    ((mask) < ((uint8_t)0x08)) 
                                         
/*! I2C  timer overtime value check definition */
#define I2C_OVERTIME_CHECK(value)           ((value) <= (uint16_t)0x0FFF)

/** @defgroup I2C_interrupts I2C interrupts definition
  * @{
  */
#define I2C_INTR_TXINT                      I2C_CTR1_TXINTFIE       /*!< Enable bit for TX interrupt */
#define I2C_INTR_RXNE                       I2C_CTR1_RXNEIE         /*!< Enable bit for RX interrupt */
#define I2C_INTR_ADRM                       I2C_CTR1_ADRMIE         /*!< Enable bit for address match interrupt */
#define I2C_INTR_NACK                       I2C_CTR1_NACKRIE        /*!< Enable bit for not acknowledge received interrupt */
#define I2C_INTR_STOP                       I2C_CTR1_STOPDIE        /*!< Enable bit for STOP detection interrupt */
#define I2C_INTR_CMP                        I2C_CTR1_CMPIE          /*!< Enable bit for transfer complete interrupt */
#define I2C_INTR_RLD                        I2C_CTR1_CMPIE          /*!< Enable bit for transfer complete reload interrupt */
#define I2C_INTR_BUSERR                     I2C_CTR1_ERRDIE         /*!< Enable bit for bus error detection interrupt */
#define I2C_INTR_ARBLO                      I2C_CTR1_ERRDIE         /*!< Enable bit for arbitration lost interrupt */
#define I2C_INTR_OVR                        I2C_CTR1_ERRDIE         /*!< Enable bit for overflow or underflow interrupt */
#define I2C_INTR_PECERR                     I2C_CTR1_ERRDIE         /*!< Enable bit for PEC error interrupt */
#define I2C_INTR_TIMEOUT                    I2C_CTR1_ERRDIE         /*!< Enable bit for overtime or tLOW detection interrupt */
#define I2C_INTR_SMBA                       I2C_CTR1_ERRDIE         /*!< Enable bit for SMBus alert interrupt */
/**
  * @}
  */

/** @defgroup I2C_flags I2C flags definition
  * @{
  */
#define I2C_FLAG_TXE                        I2C_STS_TXEF            /*!< Data register empty flag in transmitting mode */       
#define I2C_FLAG_TXINT                      I2C_STS_TXINTF          /*!< Transmit interrupt flag */
#define I2C_FLAG_RXNE                       I2C_STS_RXNEF           /*!< Data register not empty in receiving mode */
#define I2C_FLAG_ADRM                       I2C_STS_ADRF            /*!< Slave mode address matched flag */
#define I2C_FLAG_NACK                       I2C_STS_NACKF           /*!< NACK received flag */
#define I2C_FLAG_STOP                       I2C_STS_STOPF           /*!< Stop detection flag */
#define I2C_FLAG_CMP                        I2C_STS_CMPF            /*!< Master mode transfer complete flag */
#define I2C_FLAG_RLD                        I2C_STS_RLDF            /*!< Reload flag */
#define I2C_FLAG_BUSERR                     I2C_STS_BUSERRF         /*!< Bus error flag */
#define I2C_FLAG_ARBLO                      I2C_STS_ARBLOF          /*!< Arbitration lost flag */
#define I2C_FLAG_OVR                        I2C_STS_OVRF            /*!< overflow or underflow flag */
#define I2C_FLAG_PECERR                     I2C_STS_PECERRF         /*!< PEC Error flag */
#define I2C_FLAG_TIMEOUT                    I2C_STS_TIMEOUT         /*!< Overtime or tLOW detection flag */
#define I2C_FLAG_SMBA                       I2C_STS_SMBAF           /*!< SMBus alert flag */
#define I2C_FLAG_BUSY                       I2C_STS_BUSYF           /*!< Bus busy flag */
#define I2C_FLAG_BUSY_HCLR                  I2C_STS1_BUSY_HCLR      /*!< Bus busy hardware check clear flag */
#define I2C_FLAG_ADDR_NOREC                 I2C_STS1_ADDR_NOREC     /*!< Address accecpt abnormal flag */
/**
  * @}
  */

/** @defgroup I2C_transfer_end_mode I2C transfer end mode definition
  * @{
  */
#define I2C_RELOAD_MODE                    I2C_CTR2_RELOADM        /*!<  bytes number reload mode */
#define I2C_TRANFER_END_MODE               I2C_CTR2_TENDSEL        /*!< tranfer end mode */
#define I2C_SOFTWARE_END_MODE              ((uint32_t)0x00000000)  /*!< software end mode */
/**
  * @}
  */

#define I2C_END_MODE_CHECK(mode)            (((mode) == I2C_RELOAD_MODE) || ((mode) == I2C_TRANFER_END_MODE) || \
											((mode) == I2C_SOFTWARE_END_MODE))

/** @defgroup I2C_bus_operation_config I2C bus operation config definition
  * @{
  */
#define I2C_RELEASE_CONFIG                 ((uint32_t)0x00000000)  /*!< I2C BUS release */
#define I2C_STOP_CONFIG                    I2C_CTR2_STOPGEN        /*!< I2C BUS stop config */
#define I2C_WRITE_CONFIG                   I2C_CTR2_STARTGEN       /*!< I2C BUS  write config */                
#define I2C_READ_CONFIG                    (uint32_t)(I2C_CTR2_STARTGEN | I2C_CTR2_TDIR)  /*!<I2C BUS read config */
/**
  * @}
  */

#define I2C_OPERATE_CONFIG_CHECK(mode)      (((mode) == I2C_STOP_CONFIG) || ((mode) == I2C_READ_CONFIG) || \
											((mode) == I2C_WRITE_CONFIG) || ((mode) == I2C_RELEASE_CONFIG))

/** @defgroup I2C_function_register I2C function register definition
  * @{
  */
#define I2C_ENABLE_REG_CLK_DISSTRETCH       CTR1                    /*!< clock stretching disable */
#define I2C_ENABLE_REG_WAKEUP               CTR1                    /*!< Wakeup from deepsleep mode enable */
#define I2C_ENABLE_REG_GENERAL_CALL         CTR1                    /*!< General call */
#define I2C_ENABLE_REG_SLV_RESPONSE         CTR1                    /*!< Slave response */
#define I2C_ENABLE_REG_ALERT                CTR1                    /*!< SMBus alert enable */
#define I2C_ENABLE_REG_PEC_MODE             CTR1                    /*!< PEC mode enable */
#define I2C_ENABLE_REG_RELOAD_MODE          CTR2                    /*!< Reload mode enable */
#define I2C_ENABLE_REG_AUTO_END_MODE        CTR2                    /*!< Automatic end mode */
#define I2C_ENABLE_REG_SLAVE_ADDR2          SADR2                   /*!< Slave address 2 */
#define I2C_ENABLE_REG_OVERTIME_A           OVRT                    /*!< Overtime A enable */
#define I2C_ENABLE_REG_OVERTIME_B           OVRT                    /*!< Overtime B enable */
#define I2C_ENABLE_REG_OVERTIME_IDLE        OVRT                    /*!< Idle overtime enable */
#define I2C_ENABLE_REG_ADDR_CNT_EN          CTR3                    /*!< Address match timeout enable, only use for sleep mode */
#define I2C_ENABLE_REG_BUSY_HCLR_EN         CTR3                    /*!< Busy hardware clear enable, only use for sleep mode. */
/**
  * @}
  */

/** @defgroup I2C_function_bit_definition I2C function bit definition
  * @{
  */
#define I2C_ENABLE_BIT_CLK_DISSTRETCH       I2C_CTR1_DISSTRETCH     /*!< clock stretching disable */
#define I2C_ENABLE_BIT_WAKEUP               I2C_CTR1_WKUPEN         /*!< Wakeup from deepsleep mode enable */
#define I2C_ENABLE_BIT_GENERAL_CALL         I2C_CTR1_GCEN           /*!< General call */ 
#define I2C_ENABLE_BIT_SLV_RESPONSE         I2C_CTR1_SLVRC          /*!< Slave response */
#define I2C_ENABLE_BIT_ALERT                I2C_CTR1_SMBAEN         /*!< SMBus alert enable */
#define I2C_ENABLE_BIT_PEC_MODE             I2C_CTR1_PECMEN         /*!< PEC mode enable */
#define I2C_ENABLE_BIT_RELOAD_MODE          I2C_CTR2_RELOADM        /*!< Reload mode enable */
#define I2C_ENABLE_BIT_AUTO_END_MODE        I2C_CTR2_TENDSEL        /*!< Automatic end mode */
#define I2C_ENABLE_BIT_SLAVE_ADDR2          I2C_SADR2_SADR2EN       /*!< Slave address 2 */
#define I2C_ENABLE_BIT_OVERTIME_A           I2C_OVRT_TIMAEN         /*!< Overtime A enable */
#define I2C_ENABLE_BIT_OVERTIME_B           I2C_OVRT_TIMBEN         /*!< Overtime B enable */
#define I2C_ENABLE_BIT_OVERTIME_IDLE        I2C_OVRT_IDLEDEN        /*!< Idle overtime enable */
#define I2C_ENABLE_BIT_ADDR_CNT_EN          I2C_CTR3_ADDRCNTEN      /*!< Address match timeout enable, only use for sleep mode */
#define I2C_ENABLE_BIT_BUSY_HCLR_EN         I2C_CTR3_BUSYHCLREN     /*!< Busy hardware clear enable, only use for sleep mode */
/**
  * @}
  */

/** @defgroup I2C_DMA_transfer_requests I2C DMA transfer requests
  * @{
  */
#define I2C_DMA_TX_REQUEST                  I2C_CTR1_TXDMAREQEN     /*!< Enable  transmission DMA requests */
#define I2C_DMA_RX_REQUEST                  I2C_CTR1_RXDMAREQEN     /*!< Enable bit for reception DMA requests */
/**
  * @}
  */

/** @defgroup I2C_hardware_check_mode I2C hardware check mode 
  * @{
  */
#define I2C_HARDCHK_COUNTINU                ((uint32_t)0x00000000)   /*!< I2c hardware countinuous check */
#define I2C_HARDCHK_CUMULATE                I2C_CTR4_TMOM_CUMULATE   /*!< I2c hardware cumulative check */
/**
  * @}
  */

/** @defgroup I2C_hardware_check_signal I2C hardware check signal 
  * @{
  */
#define I2C_SIGNAL_SCL_LOW                  ((uint32_t)0x00000000)        /*!< I2c hardware check signal SCL low level */
#define I2C_SIGNAL_SCL_HIGH                 I2C_CTR4_TMOSEL_SCL_HIGH      /*!< I2c hardware check signal SCL high level */
#define I2C_SIGNAL_SDA_LOW                  I2C_CTR4_TMOSEL_SDA_LOW       /*!< I2c hardware check signal SDA low level */
#define I2C_SIGNAL_SDA_HIGH                 I2C_CTR4_TMOSEL_SDA_HIGH      /*!< I2c hardware check signal SDA high level */
#define I2C_SIGNAL_SCL_SDA_LOW              I2C_CTR4_TMOSEL_SCL_SDA_LOW   /*!< I2c hardware check signal SCL and SDA low level */
#define I2C_SIGNAL_SCL_SDA_HIGH             I2C_CTR4_TMOSEL_SCL_SDA_HIGH  /*!< I2c hardware check signal SCL and SDA high level */
/**
  * @}
  */

/** @defgroup I2C_hardware_check_timeout I2C hardware check timeout 
  * @{
  */
#define I2C_HARDCHK_TIMOUT_EN               I2C_CTR4_TMOEN                /*!< I2c hardware check timeout enable */
#define I2C_HARDCHK_INT_TMOSEN              I2C_CTR4_TMOSEN               /*!< I2c hardware check timeout enter error interrupt enable */
#define I2C_HARDCHK_FLAG_TMOS               I2C_CTR4_FLAG_TMOS            /*!< I2c hardware check timeout flag */
/**
  * @}
  */


/** @defgroup I2C_Macro_function I2C Macro function definition
  * @{
  */

/**
  * @brief  Configures the I2C registers to their default reset values.
  * @param  I2Cx: pointer to I2C1 to select I2C peripheral.
  * @return None.
  */
#define __I2C_DEF_INIT(I2Cx)                    do{ \
                                                    ((RCU_PERI_RST_REG_##I2Cx) |= (RCU_PERI_RST_BIT_##I2Cx)); \
                                                    ((RCU_PERI_RST_REG_##I2Cx) &= ~(RCU_PERI_RST_BIT_##I2Cx)); \
                                                }while(0)

/**
  * @brief  Sends a data byte through the I2C bus.
  * @param  I2Cx: pointer to I2C1 to select I2C peripheral.
  * @param  VALUE: Byte to be transmitted.
  * @return None
  */
#define __I2C_DATA_SEND(I2Cx, VALUE)            ((I2Cx)->TXBUF = (uint8_t)VALUE)

/**
  * @brief  Returns the most recent received data by the I2C bus..
  * @param  I2Cx: pointer to I2C1 to select I2C peripheral.
  * @return The value of the received data.
  */
#define __I2C_DATA_RECV(I2Cx)                   ((uint8_t)((I2Cx)->RXBUF))

/**
  * @brief  Generates I2Cx communication START condition.
  * @param  I2Cx: pointer to I2C1 to select I2C peripheral.
  * @return None
  */
#define __I2C_START_GENERATE(I2Cx)              ((I2Cx)->CTR2 |= I2C_CTR2_STARTGEN)

/**
  * @brief  Generates I2Cx communication STOP condition.
  * @param  I2Cx: pointer to I2C1 to select I2C peripheral.
  * @return None
  */
#define __I2C_STOP_GENERATE(I2Cx)               ((I2Cx)->CTR2 |= I2C_CTR2_STOPGEN)

/**
  * @brief  Generates NACK.
  * @param  I2Cx: pointer to I2C1 to select I2C peripheral.
  * @return None
  */
#define __I2C_NACK_GENERATE(I2Cx)               ((I2Cx)->CTR2 |= I2C_CTR2_NACKGEN)

/**
  * @brief  Request PECCODE transfer.
  * @param  I2Cx: pointer to I2C1 to select I2C peripheral.
  * @return None
  */
#define __I2C_PEC_REQUEST(I2Cx)                 ((I2Cx)->CTR2 |= I2C_CTR2_PECCTR)

/**
  * @brief  Enables the specified I2C peripheral.
  * @param  I2Cx: pointer to I2C1 to select I2C peripheral.
  * @return None.
  */
#define __I2C_ENABLE(I2Cx)                      ((I2Cx)->CTR1 |= I2C_CTR1_I2CEN)

/**
  * @brief  Disables the specified I2C peripheral.
  * @param  I2Cx: pointer to I2C1 to select I2C peripheral.
  * @return None.
  */
#define __I2C_DISABLE(I2Cx)                     ((I2Cx)->CTR1 &= ~I2C_CTR1_I2CEN)

/**
  * @brief  Returns the I2C slave received request.
  * @param  I2Cx: pointer to I2C1 to select I2C peripheral.
  * @return The value of the received request. It can be a value of the following values:
  *          @arg I2C_DIRECTION_RX (the slave is to transmit data)
  *          @arg I2C_DIRECTION_TX (the slave is to receive data)  
  */                                              
#define __I2C_TRANSFER_DIR_GET(I2Cx)            (((I2Cx)->STS & I2C_STS_DIRF) ? I2C_DIRECTION_RX : I2C_DIRECTION_TX)

/**
  * @brief  Returns the I2C matched slave address.
  * @param  I2Cx: pointer to I2C1 to select I2C peripheral.
  * @return The value of the slave matched address.
  */
#define __I2C_MATCH_ADDR_GET(I2Cx)              ((uint8_t)(((I2Cx)->STS & I2C_STS_MSLVA) >> 16))

/**
  * @brief  Returns the I2C received PEC value .
  * @param  I2Cx: pointer to I2C1 to select I2C peripheral.
  * @return The value of the PEC .
  */
#define __I2C_PECCODE_GET(I2Cx)                 ((uint8_t)((I2Cx)->PECCODE & I2C_PECCODE_PECCODE))

/**
  * @brief  Enables the specified I2C function.           
  * @param  I2Cx: pointer to I2C1 to select I2C peripheral.
  * @param  FUNC: specifies the I2C function, it can be one of the following values:
  *          @arg CLK_DISSTRETCH (clock stretching disable)
  *          @arg WAKEUP (wakeup from deepsleep mode oly for I2C1)
  *          @arg SLAVE_ADDR2 (salve address 2)     
  *          @arg GENERAL_CALL (general call)  
  *          @arg SLV_RESPONSE (slave response)  
  *          @arg RELOAD_MODE (reload mode) 
  *          @arg AUTO_END_MODE (automatic end mode)   
  *          @arg OVERTIME_A (overtime A only for SMBus)  
  *          @arg OVERTIME_B (overtime B only for SMBus) 
  *          @arg OVERTIME_IDLE (overtime only for SMBus)
  *          @arg ALERT (SMBus alert)
  *          @arg PEC_MODE (SMBus PEC mode)       
  *          @arg ADDR_CNT_EN (Address match timed out)
  *          @arg BUSY_HCLR_EN (Busy hardware clear)
  * @return None.
  */
#define __I2C_FUNC_ENABLE(I2Cx, FUNC)           ((I2Cx)->I2C_ENABLE_REG_##FUNC |= (I2C_ENABLE_BIT_##FUNC))

/**
  * @brief  Disables the specified I2C function. 
  * @param  I2Cx: pointer to I2C1 to select I2C peripheral.
  * @param  FUNC: specifies the I2C function, it can be one of the following values:
  *          @arg CLK_DISSTRETCH (clock stretching disable)
  *          @arg WAKEUP (wakeup from deepsleep mode oly for I2C1)
  *          @arg SLAVE_ADDR2 (salve address 2)     
  *          @arg GENERAL_CALL (general call)  
  *          @arg SLV_RESPONSE (slave response)  
  *          @arg RELOAD_MODE (reload mode) 
  *          @arg AUTO_END_MOE (automatic end mode)  
  *          @arg OVERTIME_A (overtime A only for SMBus)  
  *          @arg OVERTIME_B (overtime B only for SMBus) 
  *          @arg OVERTIME_IDLE (overtime IDLE oly for I2C1)
  *          @arg ALERT (SMBus alert)
  *          @arg PEC_MODE (SMBus PEC mode)
  *          @arg ADDR_CNT_EN (Address match timed out)
  *          @arg BUSY_HCLR_EN (Busy hardware clear)  
  * @return None.
  */
#define __I2C_FUNC_DISABLE(I2Cx, FUNC)          ((I2Cx)->I2C_ENABLE_REG_##FUNC &= ~(I2C_ENABLE_BIT_##FUNC))

/**
  * @brief  Enables the I2C DMA transfer.
  * @param  I2Cx: pointer to I2C1 to select I2C peripheral.
  * @param  REQ: specifies the I2C DMA transfer request to be enabled. This parameter can be any combination of the
  *         following values:
  *          @arg I2C_DMA_TX_REQUEST(Tx DMA transfer request)
  *          @arg I2C_DMA_RX_REQUEST(Rx DMA transfer request)
  * @return None.
  */
#define __I2C_DMA_ENABLE(I2Cx, REQ)             ((I2Cx)->CTR1 |= REQ) 

/**
  * @brief  Disables the I2C DMA transfer.
  * @param  I2Cx: pointer to I2C1 to select I2C peripheral.
  * @param  REQ: specifies the I2C DMA transfer request to be disabled. This parameter can be any combination of the
  *         following values:
  *          @arg I2C_DMA_TX_REQUEST(Tx DMA transfer request)
  *          @arg I2C_DMA_RX_REQUEST(Rx DMA transfer request)
  * @return None.
  */
#define __I2C_DMA_DISABLE(I2Cx, REQ)            ((I2Cx)->CTR1 &= ~(REQ))

/**
  * @brief  Enables the specified I2C interrupts.
  * @param  I2Cx: pointer to I2C1 to select I2C peripheral.
  * @param  INT: specifies the I2C interrupts sources to be enabled. It can be any combination of the following values:
  *          @arg I2C_INTR_TXINT (TX interrupt)
  *          @arg I2C_INTR_RXNE (RX interrupt)
  *          @arg I2C_INTR_ADRM (Address match interrupt)
  *          @arg I2C_INTR_NACK (Not acknowledge received interrupt)
  *          @arg I2C_INTR_STOP (STOP detection interrupt)
  *          @arg I2C_INTR_CMP (Transfer complete interrupt)
  *          @arg I2C_INTR_RLD (Transfer complete reload interrupt)
  *          @arg I2C_INTR_BUSERR (Bus error detection interrupt)
  *          @arg I2C_INTR_ARBLO (Arbitration lost interrupt)
  *          @arg I2C_INTR_OVR (overflow or underflow interrupt)
  *          @arg I2C_INTR_PECERR (PEC error interrupt)
  *          @arg I2C_INTR_TIMEOUT (Overtime or tLOW detection interrupt)
  *          @arg I2C_INTR_SMBA (SMBus alert interrupt)

  * @return None.
  */
#define __I2C_INTR_ENABLE(I2Cx, INT)            ((I2Cx)->CTR1 |= INT)

/**
  * @brief  Disables the specified I2C interrupts.
  * @param  I2Cx: pointer to I2C1 to select I2C peripheral.
  * @param  INT: specifies the I2C interrupts sources to be disabled. It can be any combination of the following values:
  *          @arg I2C_INTR_TXINT (TX interrupt)
  *          @arg I2C_INTR_RXNE (RX interrupt)
  *          @arg I2C_INTR_ADRM (Address match interrupt)
  *          @arg I2C_INTR_NACK (Not acknowledge received interrupt)
  *          @arg I2C_INTR_STOP (STOP detection interrupt)
  *          @arg I2C_INTR_CMP (Transfer complete interrupt)
  *          @arg I2C_INTR_RLD (Transfer complete reload interrupt)
  *          @arg I2C_INTR_BUSERR (Bus error detection interrupt)
  *          @arg I2C_INTR_ARBLO (Arbitration lost interrupt)
  *          @arg I2C_INTR_OVR (overflow or underflow interrupt)
  *          @arg I2C_INTR_PECERR (PEC error interrupt)
  *          @arg I2C_INTR_TIMEOUT (Overtime or tLOW detection interrupt)
  *          @arg I2C_INTR_SMBA (SMBus alert interrupt)
  * @return None.
  */
#define __I2C_INTR_DISABLE(I2Cx, INT)           ((I2Cx)->CTR1 &= ~(INT))

/**
  * @brief  Checks whether the specified I2C interrupt enable bit is set or not.
  * @param  I2Cx: pointer to I2C1 to select I2C peripheral.
  * @param  INT: specifies the I2C interrupts sources. It can be any combination of the following values:
  *          @arg TXINT (TX interrupt)
  *          @arg RXNE (RX interrupt)
  *          @arg ADRM (Address match interrupt)
  *          @arg NACK (Not acknowledge received interrupt)
  *          @arg STOP (STOP detection interrupt)
  *          @arg CMP (Transfer complete interrupt)
  *          @arg RLD (Transfer complete reload interrupt)
  *          @arg BUSERR (Bus error detection interrupt)
  *          @arg ARBLO (Arbitration lost interrupt)
  *          @arg OVR (overflow or underflow interrupt)
  *          @arg PECERR (PEC error interrupt)
  *          @arg TIMEOUT (Overtime or tLOW detection interrupt)
  *          @arg SMBA (SMBus alert interrupt)
  * @return The state (SET or RESET).
  */
#define __I2C_INTR_ENABLE_STATUS_GET(I2Cx, INT) (((I2Cx)->CTR1 & (I2C_INTR_##INT)) ? SET : RESET)

/**
  * @brief  Checks whether the specified I2C interrupt has occurred or not.
  * @param  I2Cx: pointer to I2C1 to select I2C peripheral.  
  * @param  INT: specifies the I2C interrupt source to check. It can be one of the following values:
  *          @arg TXINT (Transmit interrupt status flag)
  *          @arg RXNE (Receive data register not empty)
  *          @arg ADRM (Slave mode Address matched flag)
  *          @arg NACK (NACK received flag)
  *          @arg STOP (STOP detection flag)
  *          @arg CMP (Transfer complete, master mode)
  *          @arg RLD (Transfer complete reload)
  *          @arg BUSERR (Bus error)
  *          @arg ARBLO (Arbitration lost)
  *          @arg OVR (Slave Overflow/Underflow)
  *          @arg PECERR (PEC error in reception)
  *          @arg TIMEOUT (Overtime or tLOW detection flag)
  *          @arg SMBA (SMBus Alert)
  * @return SET or RESET.
  */
#define __I2C_INTR_STATUS_GET(I2Cx, INT)        (__I2C_INTR_ENABLE_STATUS_GET(I2Cx, INT) && __I2C_FLAG_STATUS_GET(I2Cx, INT))

/**
  * @brief  Checks whether the specified I2C flag is set or not.
  * @param  I2Cx: pointer to I2C1 to select I2C peripheral.
  * @param  FLAG: specifies the flag to check. It can be one of the following values:
  *          @arg TXE (Data register empty flag in transmitting mode)
  *          @arg TXINT (Transmit interrupt status flag)
  *          @arg RXNE (Receive data register not empty)
  *          @arg ADRM (Slave mode Address matched flag)
  *          @arg NACK (NACK received flag)
  *          @arg STOP (STOP detection flag)
  *          @arg CMP (Transfer complete, master mode)
  *          @arg RLD (Transfer complete reload)
  *          @arg BUSERR (Bus error)
  *          @arg ARBLO (Arbitration lost)
  *          @arg OVR (Slave Overflow/Underflow)
  *          @arg PECERR (PEC error in reception)
  *          @arg TIMEOUT (Overtime or tLOW detection flag)
  *          @arg SMBA (SMBus Alert)
  *          @arg BUSY (Bus busy)
  * @return The state (SET or RESET).
  */
#define __I2C_FLAG_STATUS_GET(I2Cx, FLAG)       (((I2Cx)->STS & (I2C_FLAG_##FLAG)) ? SET : RESET)

/**
  * @brief  Clears the I2Cx's pending flags.
  * @param  I2Cx: pointer to I2C1 to select I2C peripheral.
  * @param  FLAG: specifies the flag to check. It can be any combination of the following values:
  *          @arg I2C_FLAG_ADRM (Slave mode Address matched flag)
  *          @arg I2C_FLAG_NACK (NACK received flag)
  *          @arg I2C_FLAG_STOP (STOP detection flag)
  *          @arg I2C_FLAG_BUSERR (Bus error)
  *          @arg I2C_FLAG_ARBLO (Arbitration lost)
  *          @arg I2C_FLAG_OVR (Slave Overflow/Underflow)
  *          @arg I2C_FLAG_PECERR (PEC error in reception)
  *          @arg I2C_FLAG_TIMEOUT (Overtime or tLOW detection flag)
  *          @arg I2C_FLAG_SMBA (SMBus Alert)
  * @return None.
  */
#define __I2C_FLAG_CLEAR(I2Cx, FLAG)            ((I2Cx)->STSC = FLAG)

/**
  * @brief  Set the I2Cx address match timeout count value,this function only use for sleep mode.
  * @param  I2Cx: pointer to I2C1 to select I2C peripheral.
  * @param  COUNT: specifies the value for address match time out,maximum value 0xFFFF.
  * @return None.
  */
#define __I2C_ADDR_CONT_VALUE_SET(I2Cx, COUNT) do{ \
                                                    ((I2Cx)->CTR3 &= 0x0000FFFF); \
                                                    ((I2Cx)->CTR3 |= ((COUNT & 0xFFFF)<<16)); \
                                                }while(0)

/**
  * @brief  Set the I2Cx busy clear timeout value,this function only use for sleep mode.
  * @param  I2Cx: pointer to I2C1 to select I2C peripheral.
  * @param  COUNT: specifies the value for address match time out
  * @return None.
  */
#define __I2C_BUSY_CLEAR_VALUE_SET(I2Cx, VALUE) do{ \
                                                    ((I2Cx)->CTR3 &= 0xFFFFF800); \
                                                    ((I2Cx)->CTR3 |= (VALUE & 0x7FF)); \
                                                }while(0)

/**
  * @brief  Get the I2Cx flag in STS1 register, this function only use for sleep mode.
  * @param  I2Cx: pointer to I2C1 to select I2C peripheral.
  * @param  FLAG: specifies the flag to check. It can be any combination of the following values:
  *          @arg STS1_BUSY_HCLR (In slave mode, busy hardware check clear flag)
  *          @arg STS1_ADDR_NOREC (In slave mode, address accecpt abnormal flag)
  * @return The state (SET or RESET).
  */
#define __I2C_DEBUG_FLAG_GET(I2Cx, FLAG)       (((I2Cx)->STS1 & (I2C_FLAG_##FLAG)) ? SET : RESET)

/**
  * @brief  Clears the I2Cx's pending flags in STS1 register.
  * @param  I2Cx: pointer to I2C1 to select I2C peripheral.
  * @param  FLAG: specifies the flag to check. It can be any combination of the following values:
  *          @arg I2C_FLAG_BUSY_HCLR (In slave mode, busy hardware check clear flag)
  *          @arg I2C_FLAG_ADDR_NOREC (In slave mode, address accecpt abnormal flag)
  * @return None.
  */
#define __I2C_DEBUG_FLAG_CLEAR(I2Cx, FLAG)              ((I2Cx)->STS1 = FLAG)

/**
  * @brief  Enable the I2Cx's hardware check.
  * @param  I2Cx: pointer to I2C1 to select I2C peripheral.
  * @return None.
  */
#define __I2C_HARDWARE_CHCK_ENABLE(I2Cx)                ((I2Cx)->CTR4 |= I2C_CTR4_TMOEN)  

/**
  * @brief  Disable the I2Cx's hardware check.
  * @param  I2Cx: pointer to I2C1 to select I2C peripheral.
  * @return None.
  */
#define __I2C_HARDWARE_CHCK_DISABLE(I2Cx)               ((I2Cx)->CTR4 &= (~I2C_CTR4_TMOEN))  

/**
  * @brief  Configure the I2Cx's hardware check.
  * @param  I2Cx: pointer to I2C1 to select I2C peripheral.
  * @param  MODE: specifies the mode to set. It can be any combination of the following values:
  *          @arg I2C_HARDCHK_COUNTINU (I2c hardware countinuous check )
  *          @arg I2C_HARDCHK_CUMULATE (I2c hardware cumulative check )
  * @param  SIGNAL: specifies the hardware check timeout signal to set. It can be any combination of the following values:
  *          @arg I2C_SIGNAL_SCL_LOW (I2c hardware check signal SCL low level)
  *          @arg I2C_SIGNAL_SCL_HIGH (I2c hardware check signal SCL high level)
  *          @arg I2C_SIGNAL_SDA_LOW (I2c hardware check signal SDA low level)
  *          @arg I2C_SIGNAL_SDA_HIGH (I2c hardware check signal SDA high level)
  *          @arg I2C_SIGNAL_SCL_SDA_LOW (I2c hardware check signal SCL and SDA low level)
  *          @arg I2C_SIGNAL_SCL_SDA_HIGH (I2c hardware check signal SCL and SDA high level)
  * @param  TIME: specifies the mode to set. It can be the values 0x01~0x7FF.
  * @return None.
  */
#define __I2C_HARDWARE_CHCK_SET(I2Cx, MODE, SIGNAL, TIME)   do{ \
                                                                ((I2Cx)->CTR4 &= 0xFFFF0001); \
                                                                ((I2Cx)->CTR4 |= MODE); \
                                                                ((I2Cx)->CTR4 |= SIGNAL); \
                                                                ((I2Cx)->CTR4 |= ((TIME&0x7FF)<<5)); \
                                                            }while(0)

/**
  * @brief  Enable the I2Cx's hardware check timeout enter error interrupt.
  * @param  I2Cx: pointer to I2C1 to select I2C peripheral.
  * @return None.
  */
#define __I2C_HARDWARE_CHCK_TIMEOUT_INT_ENABLE(I2Cx)    ((I2Cx)->CTR4 |= I2C_HARDCHK_INT_TMOSEN)  

/**
  * @brief  Disable the I2Cx's hardware check timeout enter error interrupt.
  * @param  I2Cx: pointer to I2C1 to select I2C peripheral.
  * @return None.
  */
#define __I2C_HARDWARE_CHCK_TIMEOUT_INT_DISABLE(I2Cx)   ((I2Cx)->CTR4 &= (~I2C_HARDCHK_INT_TMOSEN))    

/**
  * @brief  Get the I2Cx's hardware check timeout flag.
  * @param  I2Cx: pointer to I2C1 to select I2C peripheral.
  * @return The state (SET or RESET).
  */
#define __I2C_HARDWARE_CHCK_TIMEOUT_FLAG_GET(I2Cx)      (((I2Cx)->CTR4 & (I2C_HARDCHK_FLAG_TMOS)) ? SET : RESET)

/**
  * @brief  Clear the I2Cx's hardware check timeout flag.
  * @param  I2Cx: pointer to I2C1 to select I2C peripheral.
  * @return None.
  */
#define __I2C_HARDWARE_CHCK_TIMEOUT_FLAG_CLEAR(I2Cx)    ((I2Cx)->CTR4 &= (~I2C_HARDCHK_FLAG_TMOS))    
/**
  * @}
  */

/***************************************************************************************************
 * @functions
***************************************************************************************************/
/** @defgroup I2c_Exported_Functions I2C Exported Functions
  * @{
  */

/**
  * @brief Config each ptr_struct member with its default value.
  * @param  ptr_struct: pointer to an i2c_config_t structure which will be initialized.
  * @return None.
  */
void i2c_struct_init(i2c_config_t* ptr_struct);

/**
  * @brief  Initializes the ptr_i2c peripheral according to  the ptr_struct.
  * @param  ptr_i2c: pointer to I2C1 to select I2C peripheral.
  * @param  ptr_struct: pointer to a i2c_config_t structure containing configuration value.          
  * @return None.
  */
void i2c_init(i2c_reg_t* ptr_i2c, i2c_config_t* ptr_struct);

/**
  * @brief  Active the specified I2C software reset.
  * @param  ptr_i2c: pointer to I2C1 to select I2C peripheral.
  * @return None.
  */
void i2c_software_reset(i2c_reg_t* ptr_i2c);

/**
  * @brief  Configures the I2C slave  address 2 and mask.
  * @param  ptr_i2c: pointer to I2C1 to select I2C peripheral.
  * @param  addr: specifies the slave address.
  * @param  mask: specifies own address 2 mask to be programmed.
  * @return None.
  */
void i2c_slave_address2_config(i2c_reg_t* ptr_i2c, uint16_t addr, uint8_t mask);

/**
  * @brief  Configures the slave address to be transmitted after start generation.
  * @param  ptr_i2c: pointer to I2C1 to select I2C peripheral. 
  * @param  addr: specifies the slave address.
  * @note   This function should be called before generating start condition.
  * @return None.
  */
void i2c_slave_address_config(i2c_reg_t* ptr_i2c, uint32_t addr);

/**
  * @brief  Configures the type of transfer request for the master.
  * @param  ptr_i2c: pointer to I2C1 to select I2C peripheral.
  * @param  direction: specifies the transfer request direction, it can be one of the following values:
  *          @arg I2C_DIRECTION_TX (Master request a write transfer)
  *          @arg I2C_DIRECTION_RX (Master request a read transfer)  
  * @return None.
  */
void i2c_request_direction_config(i2c_reg_t* ptr_i2c, uint16_t direction);

/**
  * @brief  Configures the number of bytes to be transmitted/received.
  * @param  ptr_i2c: pointer to I2C1 to select I2C peripheral.
  * @param  counter: specifies the number of bytes.
  * @return None.
  */
void i2c_bytes_number_config(i2c_reg_t* ptr_i2c, uint8_t counter);

/**
  * @brief  Handles I2C communication when starting transfer or during transfer.
  * @param  ptr_i2c: pointer to I2C1 to select I2C peripheral.
  * @param  addr: specifies the slave address to be programmed.
  * @param  counter: specifies the number of bytes between 0 and 255.
  * @param  end_select: It can be one of the following values:
  *          @arg I2C_RELOAD_MODE (Enable Reload mode)
  *          @arg I2C_TRANFER_END_MODE (Enable Automatic end mode)
  *          @arg I2C_SOFTWARE_END_MODE (Enable Software end mode)
  * @param  operate_set: It can be one of the following values:
  *          @arg I2C_RELEASE_CONFIG(Don't Generate stop and start condition)
  *          @arg I2C_STOP_CONFIG (Generate stop condition, Number_Bytes should be set to 0)
  *          @arg I2C_READ_CONFIG (Generate Restart for read request)
  *          @arg I2C_WRITE_CONFIG (Generate Restart for write request).
  * @return 0 is fail. 1 is successful.
  */
uint32_t i2c_transfer_handle(i2c_reg_t* ptr_i2c, uint32_t addr, uint8_t counter, uint32_t end_select, uint32_t operate_set);

/**
  * @brief  Configures I2C timer A  for overtime control .
  * @param  ptr_i2c: pointer to I2C1 to select I2C peripheral.
  * @param  value: specifies the overtime value. 
  * @return None
  */
void i2c_overtime_a_config(i2c_reg_t* ptr_i2c, uint16_t value);

/**
  * @brief  Configures I2C timer B  for overtime control .
  * @param  ptr_i2c: pointer to I2C1 to select I2C peripheral.
  * @param  value: specifies the TimeoutB value. 
  * @return None
  */
void i2c_overtime_b_config(i2c_reg_t* ptr_i2c, uint16_t value);

/**
  * @brief  Enables or disables I2C PEC calculation.
  * @param  ptr_i2c: pointer to I2C1 to select I2C peripheral.
  * @param  enable_flag: It can be ENABLE or DISABLE.
  * @return None
  */
void i2c_pec_enable_ctrl(i2c_reg_t* ptr_i2c, enable_state_t enable_flag);

/**
  * @}
  */


#ifdef __cplusplus
}
#endif

#endif /* cbm858xm_i2c.h */


/**
  * @}
  */

/**
  * @}
  */

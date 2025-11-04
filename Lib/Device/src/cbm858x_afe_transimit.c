/**
* @file        cbm858x_afe_transimit.c
* @brief       This file provides all the basic PPP firmware functions.
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


/***************************************************************************************************
 * @includes
***************************************************************************************************/
#include "cbm858x_afe_transimit.h"
#include "cbm858xm_spi.h"
#include "cbm858xm_gpio.h"
#include "cbm858xm.h"

/***************************************************************************************************
 * @definitions
***************************************************************************************************/


/** @addtogroup AFE_StdPeriph_Driver
  * @{
  */

/** @defgroup PPP PPP
  * @brief    PPP driver modules
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
 * @brief  Configures the SPI Peripheral.
 * @param  None
 * @return None
 */
void spi1_master_config(void)
{
    spi_config_t spi_config_struct;

    /* Enable the SPI clk. */
    __RCU_APB2_CLK_ENABLE(RCU_APB2_PERI_SPI1);

    __SPI_DEF_INIT(SPI1);
    spi_config_struct.spi_direct = SPI_DIR_2LINES_FULL_DUPLEX;
    spi_config_struct.data_width = SPI_DATA_WIDTH_8BIT;
    spi_config_struct.spi_cpol = SPI_CPOL_LOW;
    spi_config_struct.spi_cpha = SPI_CPHA_1EDGE;
    spi_config_struct.spi_nss = SPI_SSM_SW;
    spi_config_struct.spi_predivid = SPI_BAUD_RATE_PDIV_8;
    spi_config_struct.first_bit = SPI_FIRST_BIT_MSB;
    spi_config_struct.crc_polynomial = 7;

    spi_config_struct.spi_mode = SPI_MODE_MASTER;

    spi_init(SPI1, &spi_config_struct);
    /* Initialize the FIFO threshold. */
    spi_fifo_recv_threshold_config(SPI1, SPI_FIFO_RX_THRESHOLD_QF);
}

uint8_t spi_transimit_data(uint8_t* tx_buf, uint8_t* rx_buf, uint8_t len)
{
    uint8_t i = 0;
    volatile uint32_t tim = 0;

    for(i=0; i<len; i++)
    {
        tim = 0;
        while(__SPI_FLAG_STATUS_GET(SPI1, TXE) != SET)
        {
            tim++;
            if(tim == TRANSIMIT_TIMEOUT_MAX)
            {
                return 0;
            }
        }
        tim = 0;
        __SPI_8BITS_DATA_SEND(SPI1, tx_buf[i]);
        while(__SPI_FLAG_STATUS_GET(SPI1, RXNE) != SET)
        {
            tim++;
            if(tim == TRANSIMIT_TIMEOUT_MAX)
            {
                return 0;
            }
        }
        rx_buf[i] = __SPI_8BITS_DATA_RECV(SPI1);
    }
    return 1;
}

/**
  * @brief  Write data to afe chip. 
  * @param  reg_addr: The afe register address.
  * @param  data: Configure the register data.
  * @note   None.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_write_data(uint16_t reg_addr, uint16_t data)
{
    uint8_t ret = 0;
    uint8_t i = 0;
    uint8_t tx_buf[8] = {0};
    uint8_t rx_buf[8] = {0};

    __disable_irq();

    if(TRANS_CHECK_LEVEL == 0)
    {
        tx_buf[i] = NO_VERIFY_WRITE_SINGLE;
        i++;
    }
    tx_buf[i] = (uint8_t)((reg_addr>>8)&0xFF);
    i++;
    tx_buf[i] = (uint8_t)(reg_addr&0xFF);
    i++;
    tx_buf[i] = (uint8_t)((data>>8)&0xFF);
    i++;
    tx_buf[i] = (uint8_t)(data&0xFF);
    i++;
    if(TRANS_MODE_SPI_I2C == 1)
    {
        __SPI_ENABLE(SPI1);
        ret = spi_transimit_data(tx_buf,rx_buf,i); //if ret !=0 how to handle, need reset SPI1?.
        __SPI_DISABLE(SPI1);
        if(tx_buf[0] != rx_buf[1])
        {
            ret =0;
        }
        
    }
    else
    {

    }
    __enable_irq();
    return ret;
}

/**
  * @brief  Read data from afe chip. 
  * @param  reg_addr: The afe register address.
  * @param  data: Read the register data.
  * @note   None.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_read_data( uint16_t reg_addr,uint16_t* data)
{
    uint8_t ret = 0;
    uint8_t i = 0;
    uint8_t tx_buf[8] = {0};
    uint8_t rx_buf[8] = {0};

    __disable_irq();
  
    if(TRANS_CHECK_LEVEL == 0)
    {
        tx_buf[i] = NO_VERIFY_READ_SINGLE;
        i++;
    }
    tx_buf[i] = (uint8_t)((reg_addr>>8)&0xFF);
    i++;
    tx_buf[i] = (uint8_t)(reg_addr&0xFF);
    i++;
    i+=2;
    if(TRANS_MODE_SPI_I2C == 1)
    {   
        __SPI_ENABLE(SPI1);
        ret = spi_transimit_data(tx_buf,rx_buf,i); //if ret !=0 how to handle, need reset SPI1?.
        __SPI_DISABLE(SPI1);
        if(ret == 1)
        {
            if(tx_buf[0] != rx_buf[1])
            {
                ret=0;
                __enable_irq();
                return ret;
            }
            *data = (uint16_t)((rx_buf[i-2]<<8)|rx_buf[i-1]);
        }
    }  
    else
    {

    } 
    __enable_irq();
    return ret;
}

/**
  * @brief  CRC8 check function.
  * @param  data: CRC8 calculate data.
  * @param  len: CRC8 data len.
  * @note   None.
  * @return CRC8 value.
  */
uint8_t boot_crc8_check(unsigned char *data,unsigned char len)
{
    uint8_t crc = 0;    
    uint8_t i;    
    
    while(len--)
    {
        crc ^= *data++;       
        for(i = 0;i < 8;i++)       
        {
            if(crc & 0x80)           
            {
                crc = (uint8_t)((crc << 1) ^ 0x07);           
            }
            else 
            {
                crc <<= 1;
            }
        }
    }
    return crc;
}

/**
  * @brief  Enter shuntdown mode
  * @param  None.
  * @note   If PACK voltage is greater than 2.25V, unable to enter shutdown.
  * @return Function execution result, 0:ERROR, 1:SUCCESS, 2: PACK voltage is greater than 2.25V.
  */
uint8_t afe_enter_shutdown(void)
{
    uint8_t ret = 0;    
    uint8_t tx_buf[8] = {0};
    uint8_t rx_buf[8] = {0};
	uint16_t reg = 0;
	
    __disable_irq();
	afe_read_data(0x0080,&reg);
    
	if(reg&0x0004)
	{
		return 2;
	}
	
    tx_buf[0] = 0x92;
    tx_buf[1] = boot_crc8_check(&tx_buf[0],1);
    __SPI_ENABLE(SPI1);
    ret = spi_transimit_data(tx_buf,rx_buf,3); //if ret !=0 how to handle, need reset SPI1?.
    __SPI_DISABLE(SPI1);
    if((ret != 1) || (rx_buf[2] != 0x6B))
    {
        __enable_irq();
        return ret;
    }

    tx_buf[0] = 0x8F;
    tx_buf[1] = boot_crc8_check(&tx_buf[0],1);
    __SPI_ENABLE(SPI1);
    ret = spi_transimit_data(tx_buf,rx_buf,3); //if ret !=0 how to handle, need reset SPI1?.
    __SPI_DISABLE(SPI1);
    if((ret != 1) || (rx_buf[2] != 0x6B))
    {
        __enable_irq();
        return ret;
    }
    __enable_irq();
    return ret;
}

///@endcond

/**
  * @}
  */

/**
  * @}
  */

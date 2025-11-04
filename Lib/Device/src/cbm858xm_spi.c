/**
* @file        cbm858xm_spi.c
* @brief       This file provides all the basic SPI firmware functions.
* @author      ChipSea MCU Group
* @version     1.0.0
* @date        2022.05.24
* @copyright   CHIPSEA TECHNOLOGIES (SHENZHEN) CORP.
* @note        
****************************************************************************************************
* @par Modify record:
* <tr><th>Date          <th>Version    <th>Author     <th>Description
* <tr><td>2022.05.24    <td>1.0.0      <td>ChipSea    <td>
* -# 
* </table>
*
****************************************************************************************************
*/


/***************************************************************************************************
 * @includes
***************************************************************************************************/
#include "cbm858xm_spi.h"
#include "cbm858xm_rcu.h"


/***************************************************************************************************
 * @definitions
***************************************************************************************************/
/*! SPI register masks. */
#define SPI_CTR1_CLEAR_MASK     ((uint16_t)0x3040)      /*!< SPI clear mask. */
#define CR1_CLEAR_MASK2         ((uint16_t)0xFFFB)      /*!< SPI clear mask2. */


/** @addtogroup CBM858xM_StdPeriph_Driver
  * @{
  */

/** @defgroup SPI SPI
  * @brief    SPI driver modules
  * @{
  */

///@cond

/***************************************************************************************************
 * @variables
***************************************************************************************************/


/***************************************************************************************************
 * @functions
***************************************************************************************************/
/**
  * @brief  Fills each spi_config_t member with its default value.
  * @param  ptr_config: Pointer to a spi_config_t structure which will be initialized.
  * @return None.
  */
void spi_struct_init(spi_config_t* ptr_config)
{
    ptr_config->spi_direct = SPI_DIR_2LINES_FULL_DUPLEX;
    ptr_config->spi_mode   = SPI_MODE_SLAVE;
    ptr_config->data_width = SPI_DATA_WIDTH_8BIT;
    
    ptr_config->spi_cpol   = SPI_CPOL_LOW;
    ptr_config->spi_cpha   = SPI_CPHA_1EDGE;
    ptr_config->spi_nss    = SPI_SSM_HW;
  
    ptr_config->spi_predivid = SPI_BAUD_RATE_PDIV_2;
    ptr_config->first_bit = SPI_FIRST_BIT_MSB;
    ptr_config->crc_polynomial = 7;
}


/**
  * @brief  Initializes the SPIx peripheral according to the ptr_config.
  * @param  ptr_spi: Pointer to SPIx (x can be 1 or 2) peripheral .
  * @param  ptr_config: Pointer to a spi_config_t structure that contains the configuration for SPI peripheral.
  * @return None.
  */
void spi_init(spi_reg_t* ptr_spi, spi_config_t* ptr_config)
{
    ASSERT(SPI_LIST_CHECK(ptr_spi));

    ASSERT(SPI_DIR_LINES_CHECK(ptr_config->spi_direct));
    ASSERT(SPI_MODE_CHECK(ptr_config->spi_mode));
    ASSERT(IS_SPI_DATA_SIZE(ptr_config->data_width));
    ASSERT(SPI_CPOL_CHECK(ptr_config->spi_cpol));
    ASSERT(SPI_CPHA_CHECK(ptr_config->spi_cpha));
    ASSERT(SPI_SSM_CHECK(ptr_config->spi_nss));
    ASSERT(SPI_BAUD_RATE_PDIV_CHECK(ptr_config->spi_predivid));
    ASSERT(SPI_FIRST_BIT_CHECK(ptr_config->first_bit));
    ASSERT(SPI_CRC_POLYNOMIAL_CHECK(ptr_config->crc_polynomial));

    MODIFY_REG(ptr_spi->CTR1, ~SPI_CTR1_CLEAR_MASK, (ptr_config->spi_direct | ptr_config->first_bit |
               ptr_config->spi_cpol | ptr_config->spi_cpha | ptr_config->spi_nss | ptr_config->spi_predivid));

    MODIFY_REG(ptr_spi->CTR2, SPI_CTR2_DLEN, ptr_config->data_width);

    ptr_spi->CRCPOLYR = ptr_config->crc_polynomial;
    
    MODIFY_REG(ptr_spi->CTR1, ~CR1_CLEAR_MASK2, ptr_config->spi_mode);
}


/**
  * @brief  Config the data transfer direction.
  * @param  ptr_spi: Pointer to SPIx (x can be 1 or 2) peripheral.
  * @param  value: Specifies the data transfer direction.
  *         It can be one of the following values:
  *          @arg SPI_TRANSMIT_DIR_TX: SPI selects Tx transmit direction.
  *          @arg SPI_TRANSMIT_DIR_RX: SPI selects Rx receive direction.
  * @return None.
  */
void spi_transmit_direct_config(spi_reg_t* ptr_spi, uint16_t value)
{
    ASSERT(SPI_LIST_CHECK(ptr_spi));
    ASSERT(SPI_TRANSMIT_DIR_CHECK(value));

    MODIFY_REG(ptr_spi->CTR1, SPI_TRANSMIT_DIR_TX, value);
}


/**
  * @brief  Configures NSS value in software NSS mode.
  * @note   It can be called only after the spi_init() function has  been called.
  * @param  ptr_spi: Pointer to SPIx (x can be 1 or 2) peripheral.
  * @param  value: Specifies the SPI NSS internal state.
  *         It can be one of the following values:
  *          @arg SPI_SOFTWARE_NSS_SET: Set NSS pin internally.
  *          @arg SPI_SOFTWARE_NSS_RESET: Reset NSS pin internally.
  * @return None.
  */
void spi_software_nss_config(spi_reg_t* ptr_spi, uint16_t value)
{
    ASSERT(SPI_LIST_CHECK(ptr_spi));
    ASSERT(SPI_SOFTWARE_NSS_CHECK(value));

    MODIFY_REG(ptr_spi->CTR1, SPI_SOFTWARE_NSS_SET, value);
}


/**
  * @brief  Configures the CRC calculation length. 
  * @param  ptr_spi: Pointer to SPIx (x can be 1 or 2) peripheral.
  * @param  value: Specifies the SPI CRC calculation length.
  *         It can be one of the following values:
  *          @arg SPI_CRC_LEN_8BIT: Set CRC Calculation to 8 bits.
  *          @arg SPI_CRC_LEN_16BIT: Set CRC Calculation to 16 bits.
  * @return None.
  */
void spi_crc_length_config(spi_reg_t* ptr_spi, uint16_t value)
{
    ASSERT(SPI_LIST_CHECK(ptr_spi));
    ASSERT(SPI_CRC_LEN_CHECK(value));
  
    MODIFY_REG(ptr_spi->CTR1, SPI_CTR1_CRC16, value);
}


/**
  * @brief  Configures the data width for the selected SPI.
  * @param  ptr_spi: Pointer to SPIx (x can be 1 or 2) peripheral.
  * @param  value: Specifies the SPI data size.
  *         It can be one of the following values:
  *          @arg SPI_DATA_WIDTH_4BIT: Specifies data width is 4 bits.
  *          @arg SPI_DATA_WIDTH_5BIT: Specifies data width is 5 bits.
  *          @arg SPI_DATA_WIDTH_6BIT: Specifies data width is 6 bits.
  *          @arg SPI_DATA_WIDTH_7BIT: Specifies data width is 7 bits.
  *          @arg SPI_DATA_WIDTH_8BIT: Specifies data width is 8 bits.
  *          @arg SPI_DATA_WIDTH_9BIT: Specifies data width is 9 bits.
  *          @arg SPI_DATA_WIDTH_10BIT: Specifies data width is 10 bits.
  *          @arg SPI_DATA_WIDTH_11BIT: Specifies data width is 11 bits.
  *          @arg SPI_DATA_WIDTH_12BIT: Specifies data width is 12 bits.
  *          @arg SPI_DATA_WIDTH_13BIT: Specifies data width is 13 bits.
  *          @arg SPI_DATA_WIDTH_14BIT: Specifies data width is 14 bits.
  *          @arg SPI_DATA_WIDTH_15BIT: Specifies data width is 15 bits.
  *          @arg SPI_DATA_WIDTH_16BIT: Specifies data width is 16 bits.
  * @return None.
  */
void spi_data_width_config(spi_reg_t * ptr_spi, uint16_t value)
{
    ASSERT(SPI_LIST_CHECK(ptr_spi));
    ASSERT(IS_SPI_DATA_SIZE(value));
  
    MODIFY_REG(ptr_spi->CTR2, SPI_CTR2_DLEN, value);
}


/**
  * @brief  Configures the FIFO reception threshold for the selected SPI.
  * @param  ptr_spi: Pointer to SPIx (x can be 1 or 2) peripheral .
  * @param  value: Specifies the FIFO reception threshold.
  *         It can be one of the following values:
  *          @arg SPI_FIFO_RX_THRESHOLD_HF: Event is generated if the FIFO level is greater or equal to 1/2.
  *          @arg SPI_FIFO_RX_THRESHOLD_QF: Event is generated if the FIFO  level is greater or equal to 1/4.
  * @return None.
  */
void spi_fifo_recv_threshold_config(spi_reg_t* ptr_spi, uint16_t value)
{
    ASSERT(SPI_LIST_CHECK(ptr_spi));
    ASSERT(SPI_FIFO_RX_THRESHOLD_CHECK(value));

    MODIFY_REG(ptr_spi->CTR2, SPI_CTR2_RXNE8, value);
}


/**
  * @brief  Configures the number of data Even/Odd for the DMA transfers.
  * @param  ptr_spi: Pointer to SPIx (x can be 1 or 2) peripheral.
  * @param  value: Specifies the SPI last DMA transfers state.
  *         It can be one of the following values:
  *          @arg SPI_DMA_TX_EVEN_RX_EVEN: TX and rx transmission data number are all even.
  *          @arg SPI_DMA_TX_ODD_RX_EVEN: TX data number is odd, rx data number is even.
  *          @arg SPI_DMA_TX_EVEN_RX_ODD: TX data number is even, rx data number is odd.
  *          @arg SPI_DMA_TX_ODD_RX_ODD: TX data number is odd, rx data number is odd.
  * @return None.
  */
void spi_dma_odd_even_config(spi_reg_t* ptr_spi, uint16_t value)
{
    ASSERT(SPI_LIST_CHECK(ptr_spi));
    ASSERT(SPI_DMA_TX_RX_NUMBER_CHECK(value));

    MODIFY_REG(ptr_spi->CTR2, SPI_DMA_TX_ODD_RX_ODD, value);
}

///@endcond

/**
  * @}
  */

/**
  * @}
  */

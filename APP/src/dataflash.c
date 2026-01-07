#include "dataflash.h"
typedef union
{
	uint32_t data[256];
	uint8_t sec_array[1024];
} BYTE_TO_LONG;
BYTE_TO_LONG df_write_u32;
#define df_sec_array df_write_u32.sec_array
#define df_sec_array1 df_write_u32.data

volatile uint8_t *G_pFlashAddr; // DataFlash address pointer
volatile uint8_t G_index;	  // DataFlash index

uint16_t adfflg;
DFUpdate_T DFUpdate;

int8_t DataFlash_Write(uint32_t flash_addr, uint8_t *data, uint16_t length)
{
	flash_status_t status = FLASH_STATUS_COMPLETE;
	int8_t error;
	uint16_t i;
	uint8_t index;
	uint16_t offset;
	uint32_t psec_startaddr, Flashwrite32;
	__disable_irq();
	if (length >= FLASH_PAGE_SIZE || flash_addr < FLASH_START_ADDR)
	{
		return -1;
		__enable_irq();
	}

	flash_unlock();

	index = (uint8_t)(((flash_addr - FLASH_START_ADDR) & 0xFFFFFFFF) / FLASH_PAGE_SIZE);
	offset = (uint16_t)(((flash_addr - FLASH_START_ADDR) & 0xFFFFFFFF) % FLASH_PAGE_SIZE);
	psec_startaddr = (uint32_t)((index * FLASH_PAGE_SIZE) + FLASH_START_ADDR);

	for (i = 0; i < FLASH_PAGE_SIZE; i++)
	{
		df_sec_array[i] = *(uint8_t *)(psec_startaddr + i);
	}

	for (i = 0; i < length; i++)
	{
		df_sec_array[offset + i] = *(uint8_t *)(data + i);
	}

	error = Flash_Erase(index);
	if (error != 0) //
	{
		__enable_irq();
		return -1;
	}

	for (i = 0; i < FLASH_PAGE_SIZE; i += 4)
	{
		status = flash_word_program((uint32_t)(psec_startaddr + i), df_sec_array1[i / 4]);
		if (status != FLASH_STATUS_COMPLETE)
		{
			__enable_irq();
			return -1;
		}
	}

	flash_lock();
	__enable_irq();
	return 0;
}

int8_t Flash_Erase(uint8_t index)
{
	flash_status_t error = FLASH_STATUS_COMPLETE;
	int i = 0;
	flash_unlock();
	if (index >= (uint8_t)(FLASH_END_ADDR / FLASH_PAGE_SIZE))
	{
		return -1;
	}

	error = flash_page_erase(FLASH_START_ADDR + index * FLASH_PAGE_SIZE);
	if (error != FLASH_STATUS_COMPLETE)
	{
		return -1;
	}

	for (i = 0; i < FLASH_PAGE_SIZE; i += 4)
	{
		if (*(volatile uint32_t *)(FLASH_START_ADDR + (index * FLASH_PAGE_SIZE) + i) != 0xffffffff)
		{
			error = FLASH_STATUS_ERROR;
		}
	}

	if (error != FLASH_STATUS_COMPLETE)
	{
		return -1;
	}
	return 0;
}

void flash_decode(void) // Flash unseal and erase is 0xFF
{
	uint32_t ret;
	ret = *(uint32_t *)(CIPHER_CONFIG_ADDR);
	if (ret != FORBID_CIPHER_RAM_ROM)
	{
		flash_unlock();
		flash_option_bytes_unlock();
		ret = flash_word_program(CIPHER_CONFIG_ADDR, FORBID_CIPHER_RAM_ROM);
		if (ret != FLASH_STATUS_COMPLETE)
		{
			//("write cipher address failed\r\n");
		}
		flash_option_bytes_lock();
		flash_lock();
		__FLASH_OPT_UPDATE();
	}
}
int8_t Block_Erase(uint32_t Block_Addr)
{
	flash_unlock();
	uint8_t index;
	int8_t ret;
	f_dfe = ON; // Set DataFlash erasing flag
	index = (uint8_t)((Block_Addr - FLASH_START_ADDR) / FLASH_PAGE_SIZE);
	ret = Flash_Erase(index); // Erase data flash block1
	flash_lock();
	return ret;
}

void DF_IndexW(uint32_t data)
{
	flash_unlock(); // Data flash access enable
	delay_ms(1);

	if (G_pFlashAddr[G_index] == 0xFF) // index is empty ?
	{
		__disable_irq();
		flash_word_program((uint32_t)&G_pFlashAddr[G_index], data);
		__enable_irq();
	}
	flash_lock();
}

void DFW_Index(void)
{
	uint8_t aidxA, aidxB;

	delay_ms(1);

	G_pFlashAddr = (uint8_t *)BLOCK_A; // Search BlockA
	for (aidxA = 0; aidxA < DFBLOCK && G_pFlashAddr[aidxA] != 0xFF; aidxA += 4)
		;

	G_pFlashAddr = (uint8_t *)BLOCK_B; // Search BlockB
	for (aidxB = 0; aidxB < DFBLOCK && G_pFlashAddr[aidxB] != 0xFF; aidxB += 4)
		;

	if (aidxB == 0) // Block B is empty ?
	{
		if (aidxA >= DFBLOCK) // Block A is full ?
		{
			G_pFlashAddr = (uint8_t *)BLOCK_B; // Use BlockB
			G_index = 0;
		}
		else
		{								  // Block A is not full
			G_pFlashAddr = (uint8_t *)BLOCK_A; // Use BlockA
			G_index = aidxA;
		}
	}
	else
	{					// Block B is not empty
		if (aidxA == 0) // Block A is empty ?
		{
			if (aidxB >= DFBLOCK) // Block B is full ?
			{
				G_pFlashAddr = (uint8_t *)BLOCK_A; // Use BlockA
				G_index = 0;
			}
			else
			{								  // Block B is not full
				G_pFlashAddr = (uint8_t *)BLOCK_B; // Use BlockB
				G_index = aidxB;
			}
		}
		else
		{					   // Block A & B are not empty
			if (aidxA < aidxB) // Number of A less than B ?
			{
				G_pFlashAddr = (uint8_t *)BLOCK_A; // Use BlockA
				G_index = aidxA;
				if (aidxA >= (DFBLOCK - 1 * 4)) // Block A is last 3 area ?
				{
					f_dfe_breq = ON; // Set BlockB erase request
				}
			}
			else
			{								  // B equals A or less
				G_pFlashAddr = (uint8_t *)BLOCK_B; // Use BlockB
				G_index = aidxB;
				if (aidxB >= (DFBLOCK - 1 * 4)) // Block B is last 3 area ?
				{
					f_dfe_areq = ON; // Set BlockA erase request
				}
			}
		}
	}
}

uint8_t DF_Write(void)
{
	#if 1
	uint8_t al1;
	uint8_t *apwork1, *apwork2;
	uint8_t aret;
	uint32_t data;

	flash_unlock();
	
	
	DFW_Index();		   // Search write area
	if (G_index >= DFBLOCK) // Index Abnormal?
	{
		return FALSE; // Abort
	}
	delay_ms(1);
	// Make write address
	apwork1 = (uint8_t *)(G_pFlashAddr + DF_ST_OFF + ((uint16_t)(G_index / 4) * DF_LEN));
	apwork2 = apwork1;

	for (al1 = 0; al1 < DF_LEN; al1++) // Write area empty check
	{
		if (*apwork1 != 0xFF) // Not empty ?
		{
			DF_IndexW(AREA_NG); // Write index(area NG)
			return FALSE;		// Abort
		}
		apwork1++; // To next data
	}
	__disable_irq();
	flash_unlock();
	
	for (al1 = 0; al1 < sizeof(Record); al1 += 4)
	{
		memcpy(&data,(uint8_t*)(&t_record) + al1,4);
		aret = flash_word_program((uint32_t)(apwork2 + al1),data);
		if (aret != FLASH_STATUS_COMPLETE)
		{
			break;
		}
	}
	__enable_irq();

	if (aret == 1) // OK ?
	{
		DF_IndexW(W_OK); // Write index(Write OK)
	}
	else
	{	//printf("%#p Record Write Error!\n",apwork2 + al1);				 // NG
		DF_IndexW(W_NG); // Write index (Write NG)
	}
	if (f_dfe_breq) // BlockB Erase request exist ?
	{
		if (!Block_Erase(BLOCK_B)) // BlockB erase)
		{
			f_dfe_breq = OFF; // Clear BlockB erase request
			f_dfe = OFF;
		}
	}
	else
	{
		if (f_dfe_areq) // BlockA Erase request exist ?
		{
			if (!Block_Erase(BLOCK_A)) // BlockA erase)
			{
				f_dfe_areq = OFF; // Clear BlockA erase request
				f_dfe = OFF;
			}
			delay_ms(1);
		}
	}

	flash_lock();
	return TRUE;
	#endif
	// return DataFlash_Write((uint32_t)&(flashdata.b_Staging_Area.s_Record), udfdata, sizeof(S_Record));
}

/*""FUNC COMMENT""**********************************************************
 * ID				: 1.0
 * module outline	: DataFlash read index search function
 *--------------------------------------------------------------------------
 * Include			:
 *--------------------------------------------------------------------------
 * Declaration		: void DFR_Index(void)
 *--------------------------------------------------------------------------
 * Function			: Search latest data area index of DataFlash.
 *					:
 *--------------------------------------------------------------------------
 * Argument			: None
 *--------------------------------------------------------------------------
 * Return			: None
 *--------------------------------------------------------------------------
 * Input			: None
 *					:
 * Output			: G_pFlashAddr	: Latest data address
 *--------------------------------------------------------------------------
 * Used function	:
 *					:
 *--------------------------------------------------------------------------
 * Caution			:
 *--------------------------------------------------------------------------
 * History			: 2023.05.17 V1.00
 *******************************************************************/

void DFR_Index(void)
{
	uint8_t aidx1 = 0xFF, aidx2 = 0xFF;
	uint8_t aidx_w;

	G_pFlashAddr = (uint8_t *)BLOCK_B; // Search from BlockB
	if (*G_pFlashAddr == 0xFF)		  // BlockB is not used ?
	{
		G_pFlashAddr = (uint8_t *)BLOCK_A; // Search BlockA
		if (*G_pFlashAddr != 0xFF)		  // BlockA is used ?
		{
			// Search blank index
			for (aidx_w = 0; aidx_w < DFBLOCK && *G_pFlashAddr != 0xFF; aidx_w += 4, G_pFlashAddr += 4)
			{
				if (*G_pFlashAddr == W_OK) // Valid data ?
				{
					aidx1 = aidx_w / 4; // Set as DFindex
				}
			}

			if (aidx1 == 0xFF) // Not exist valid data ?
			{
				G_pFlashAddr = NULL; // Set address to NULL
			}
			else
			{ // Valid data exist
			  // Calculate data address
				G_pFlashAddr = (uint8_t *)(BLOCK_A_ST + ((uint16_t)aidx1 * DF_LEN));
			}
		}
		else
		{					// BlockA also not used
			G_pFlashAddr = NULL; // Set address to NULL
		}
	}
	else
	{ // BlockB is used
	  // Search blank index
		for (aidx_w = 0; aidx_w < DFBLOCK && *G_pFlashAddr != 0xFF; aidx_w += 4, G_pFlashAddr += 4)
		{
			if (*G_pFlashAddr == W_OK) // Valid data ?
			{
				aidx2 = aidx_w / 4; // Set as DFindex
			}
		}
		if (*(uint8_t *)BLOCK_A == 0xFF) // BlockA is not used ?
		{
			if (aidx2 == 0xFF) // Not exist valid data ?
			{
				G_pFlashAddr = NULL; // Set address to NULL
			}
			else
			{ // Exist valid data
				G_pFlashAddr = (uint8_t *)(BLOCK_B_ST + ((uint16_t)aidx2 * DF_LEN));
			}
		}
		else
		{								  // BlockA also used
			G_pFlashAddr = (uint8_t *)BLOCK_A; // also Search BlockA
			for (aidx_w = 0; aidx_w < DFBLOCK && *G_pFlashAddr != 0xFF; aidx_w += 4, G_pFlashAddr += 4)
			{
				if (*G_pFlashAddr == W_OK) // Valid data ?
				{
					aidx1 = aidx_w / 4; // Tentative save as DFindex
				}
			}
			if (aidx2 == 0xFF) // Not exist valid data on BlockB ?
			{
				if (aidx1 == 0xFF) // BlockA also not exist ?
				{
					G_pFlashAddr = NULL; // Set address to NULL
				}
				else
				{ // BlockA has valid data
				  // Calc data address by BlockA
					G_pFlashAddr = (uint8_t *)(BLOCK_A_ST + ((uint16_t)aidx1 * DF_LEN));
				}
			}
			else
			{					   // BlockB is valid
				if (aidx1 == 0xFF) // Not exist valid data on BlockA ?
				{
					// Calc data address by BlockB
					G_pFlashAddr = (uint8_t *)(BLOCK_B_ST + ((uint16_t)aidx2 * DF_LEN));
				}
				else
				{					   // Both block are valid
					if (aidx1 < aidx2) // BlockA is less than B ?
					{
						// Use BlockA
						G_pFlashAddr = (uint8_t *)(BLOCK_A_ST + ((uint16_t)aidx1 * DF_LEN));
					}
					else
					{ // Same or B is less than A
					  // Use BlockB
						G_pFlashAddr = (uint8_t *)(BLOCK_B_ST + ((uint16_t)aidx2 * DF_LEN));
					}
				}
			}
		}
	}
}

void DF_Read(void)
{
	#if 1
	flash_unlock();								 // Data flash access enable
												 //	delay_ms(1);
	DFR_Index();								 // Search read area
	if ((G_pFlashAddr != NULL) && (*G_pFlashAddr != 0xFF)) // DataFlash is not empty ?
	{
		memcpy(&t_record,G_pFlashAddr,sizeof(Record));
	}
	else
	{									   // DataFlash is empty
		memset(&t_record,0,sizeof(Record));
	}
	flash_lock(); // Data flash access disable
	#endif
	// memcpy(udfdata,(uint8_t*)&(flashdata.b_Staging_Area.s_Record),sizeof(S_Record));
	//memcpy(udfdata,(uint8_t*)&(flashdata.b_LifeTimes.s_LifeTimes),sizeof(S_LifeTimes));
}

uint8_t MfgSCfg;
uint16_t offset;
uint16_t advanceLen, remainLen, fdLenW;
uint16_t Accaddress;
uint16_t fdLimitW; // flash data write limit
void DFUdata_Chk(void)
{

	if (DFUpdate.FLAG)
	{
		

		if (DFUpdate.DataFlash)
		{

			Accaddress = eMac.MAC_T.nAltManufacturerAccess;
			offset = (uint16_t)(Accaddress & 0x0FFF) + (MACDataLength - 2);

			if ((Accaddress & 0x0FFF) <= FDSIZE)
			{
				fdLimitW = FDSIZE - (Accaddress & 0x0FFF); // Description Write the flash address out of range
				if (fdLimitW >= (MACDataLength - 2))
				{
					fdLenW = MACDataLength - 2;
				}
				else
				{
					fdLenW = fdLimitW;
				}
				__disable_irq();
				if (Accaddress >= 0x4000 && Accaddress < 0x4800)
				{
					if ((offset >= FLASH_PAGE_SIZE) && ((Accaddress & 0x0FFF) < FLASH_PAGE_SIZE))
					{
						advanceLen = FLASH_PAGE_SIZE - (Accaddress & 0x0FFF);
						remainLen = fdLenW - advanceLen;
						DataFlash_Write((DF_FLASH_OFFSET + Accaddress), &eMac.MAC_T.nMACData[0], advanceLen);
						DataFlash_Write((DF_FLASH_OFFSET + Accaddress + advanceLen), &eMac.MAC_T.nMACData[advanceLen], remainLen);
					}
					else
					{
						DataFlash_Write((DF_FLASH_OFFSET + Accaddress), &eMac.MAC_T.nMACData[0], fdLenW);
					}
				}
			}
			calc_DFSignature();
			DFUpdate.FLAG = 0;
			__enable_irq();
		}

		if (DFUpdate.SecKeys)
		{
			//printf("MACDataLength = %d\r\n",MACDataLength);
			if (MACDataLength - 2 ==0x08)
			{
			
			__disable_irq();
			DataFlash_Write((uint32_t)&D_US_KEY1, &eMac.MAC_T.nMACData[0], 0x08);
			__enable_irq();
			}
			DFUpdate.SecKeys = 0;
		}

		
	}
	// if (DFUpdate.PcmbCode)
	// {
	// 	if (MACDataLength - 2 > sizeof(D_AUTHKEY))
	// 	{
	// 		MACDataLength = sizeof(D_AUTHKEY) + 2;
	// 	}
	// 	__disable_irq();
	// 	DataFlash_Write((uint32_t)(D_Manufacturer_ManufacturerInfo), &rx_buffer[1], 33);
	// 	__enable_irq();
	// 	DFUpdate.PcmbCode = 0;
	// }
}

void LFW_Index(void)
{
	uint8_t aidxA, aidxB;

	delay_ms(1);

	G_pFlashAddr = (uint8_t *)LF_BLOCK_A; // Search BlockA
	for (aidxA = 0; aidxA < LTBLOCK && G_pFlashAddr[aidxA] != 0xFF; aidxA += 4)
		;

	G_pFlashAddr = (uint8_t *)LF_BLOCK_B; // Search BlockB
	for (aidxB = 0; aidxB < LTBLOCK && G_pFlashAddr[aidxB] != 0xFF; aidxB += 4)
		;

	if (aidxB == 0) // Block B is empty ?
	{
		if (aidxA >= LTBLOCK) // Block A is full ?
		{
			G_pFlashAddr = (uint8_t *)LF_BLOCK_B; // Use BlockB
			G_index = 0;
		}
		else
		{									 // Block A is not full
			G_pFlashAddr = (uint8_t *)LF_BLOCK_A; // Use BlockA
			G_index = aidxA;
		}
	}
	else
	{					// Block B is not empty
		if (aidxA == 0) // Block A is empty ?
		{
			if (aidxB >= LTBLOCK) // Block B is full ?
			{
				G_pFlashAddr = (uint8_t *)LF_BLOCK_A; // Use BlockA
				G_index = 0;
			}
			else
			{									 // Block B is not full
				G_pFlashAddr = (uint8_t *)LF_BLOCK_B; // Use BlockB
				G_index = aidxB;
			}
		}
		else
		{					   // Block A & B are not empty
			if (aidxA < aidxB) // Number of A less than B ?
			{
				G_pFlashAddr = (uint8_t *)LF_BLOCK_A; // Use BlockA
				G_index = aidxA;
				if (aidxA >= LTBLOCK - 1 * 4) // Block A is last 3 area ?
				{
					f_lf_breq = ON;
				}
			}
			else
			{									 // B equals A or less
				G_pFlashAddr = (uint8_t *)LF_BLOCK_B; // Use BlockB
				if (aidxB >= LTBLOCK - 1 * 4)	 // Block B is full ?
				{								 // (It means some error.)
					G_index = aidxB;
					f_lf_areq = ON;
				}
			}
		}
	}
}

void LTR_Index(void)
{
	uint8_t aidx1 = 0xFF, aidx2 = 0xFF;
	uint8_t aidx_w;
	G_pFlashAddr = (uint8_t *)LF_BLOCK_B; // Search from BlockB
	if (*G_pFlashAddr == 0xFF)			 // BlockB is not used ?
	{
		G_pFlashAddr = (uint8_t *)LF_BLOCK_A; // Search BlockA
		if (*G_pFlashAddr != 0xFF)			 // BlockA is used ?
		{
			// Search blank index
			for (aidx_w = 0; aidx_w < LTBLOCK && *G_pFlashAddr != 0xFF; aidx_w += 4, G_pFlashAddr += 4)
			{
				if (*G_pFlashAddr == W_OK) // Valid data ?
				{
					aidx1 = aidx_w / 4; // Set as DFindex
				}
			}

			if (aidx1 == 0xFF) // Not exist valid data ?
			{
				G_pFlashAddr = NULL; // Set address to NULL
			}
			else
			{ // Valid data exist
			  // Calculate data address
				G_pFlashAddr = (uint8_t *)(LIFETIME_A_ST + ((uint16_t)aidx1 * LT_LEN));
			}
		}
		else
		{					// BlockA also not used
			G_pFlashAddr = NULL; // Set address to NULL
		}
	}
	else
	{ // BlockB is used
	  // Search blank index
		for (aidx_w = 0; aidx_w < LTBLOCK && *G_pFlashAddr != 0xFF; aidx_w += 4, G_pFlashAddr += 4)
		{
			if (*G_pFlashAddr == W_OK) // Valid data ?
			{
				aidx2 = aidx_w / 4; // Set as DFindex
			}
		}
		if (*(uint8_t *)LF_BLOCK_A == 0xFF) // BlockA is not used ?
		{
			if (aidx2 == 0xFF) // Not exist valid data ?
			{
				G_pFlashAddr = NULL; // Set address to NULL
			}
			else
			{ // Exist valid data
				G_pFlashAddr = (uint8_t *)(LIFETIME_B_ST + ((uint16_t)aidx2 * LT_LEN));
			}
		}
		else
		{									 // BlockA also used
			G_pFlashAddr = (uint8_t *)LF_BLOCK_A; // also Search BlockA
			for (aidx_w = 0; aidx_w < LTBLOCK && *G_pFlashAddr != 0xFF; aidx_w += 4, G_pFlashAddr += 4)
			{
				if (*G_pFlashAddr == W_OK) // Valid data ?
				{
					aidx1 = aidx_w / 4; // Tentative save as DFindex
				}
			}
			if (aidx2 == 0xFF) // Not exist valid data on BlockB ?
			{
				if (aidx1 == 0xFF) // BlockA also not exist ?
				{
					G_pFlashAddr = NULL; // Set address to NULL
				}
				else
				{ // BlockA has valid data
				  // Calc data address by BlockA
					G_pFlashAddr = (uint8_t *)(BLOCK_A_ST + ((uint16_t)aidx1 * LT_LEN));
				}
			}
			else
			{					   // BlockB is valid
				if (aidx1 == 0xFF) // Not exist valid data on BlockA ?
				{
					// Calc data address by BlockB
					G_pFlashAddr = (uint8_t *)(LIFETIME_B_ST + ((uint16_t)aidx2 * LT_LEN));
				}
				else
				{					   // Both block are valid
					if (aidx1 < aidx2) // BlockA is less than B ?
					{
						// Use BlockA
						G_pFlashAddr = (uint8_t *)(LIFETIME_A_ST + ((uint16_t)aidx1 * LT_LEN));
					}
					else
					{ // Same or B is less than A
					  // Use BlockB
						G_pFlashAddr = (uint8_t *)(LIFETIME_B_ST + ((uint16_t)aidx2 * LT_LEN));
					}
				}
			}
		}
	}
}

void LifeTimeData_ReadDF(void)
{
	uint16_t al1;
	uint8_t aidx_w;
	uint8_t aidx1 = 0;

	flash_unlock(); // Data flash access enable
	delay_ms(1);

	LTR_Index();
	if ((G_pFlashAddr != NULL) && (*G_pFlashAddr != 0xFF))
	{
		memcpy(&l_lifetimes,G_pFlashAddr,sizeof(LifeTimes));
	}
	else
	{ // DataFlash is empty
		lifetime_init();
	}
	
	flash_lock();
}

uint8_t LifeTimeData_WriteDF(void)
{
	uint16_t al1;
	uint8_t aret;
	uint8_t *apwork1, *apwork2;
	uint32_t data;

	flash_unlock();

	LFW_Index();

	apwork1 = (uint8_t *)((G_pFlashAddr + LF_DATA_OFFSET) + ((uint16_t)(G_index / 4) * LT_LEN));
	apwork2 = apwork1;

	flash_unlock();

	for (al1 = 0; al1 < LT_LEN; al1++) // Write area empty check
	{
		if (*apwork1 != 0xFF) // Not empty ?
		{
			DF_IndexW(AREA_NG); // Write index(area NG)
			flash_lock();
			return FALSE; // Abort
		}
		apwork1++; // To next data
	}
	//    aret = DataFlash_Write( (uint32_t)apwork2, altdat, LTSIZE);

	__disable_irq();
	flash_unlock();
	for (al1 = 0; al1 < sizeof(LifeTimes); al1 += 4)
	{
		memcpy(&data, (uint8_t *)(&l_lifetimes) + al1, 4);
		aret = flash_word_program((uint32_t)(apwork2 + al1), data);
		if (aret != FLASH_STATUS_COMPLETE)
		{
			break;
		}
	}
	__enable_irq();

	// aret = DataFlash_Write((uint32_t)apwork2, lfarr, LTSIZE);
	if (aret == 1) // OK ?
	{
		DF_IndexW(W_OK); // Write index(Write OK)
	}
	else
	{					 // NG
		DF_IndexW(W_NG); // Write index (Write NG)
	}

	if (f_lf_breq) // BlockB Erase request exist ?
	{
		if (!Block_Erase(LF_BLOCK_B)) // BlockB erase)
		{
			f_lf_breq = OFF; // Clear BlockB erase request
			f_dfe = OFF;
		}
	}
	else
	{
		if (f_lf_areq) // BlockA Erase request exist ?
		{
			if (!Block_Erase(LF_BLOCK_A)) // BlockA erase)
			{
				f_lf_areq = OFF; // Clear BlockA erase request
				f_dfe = OFF;
			}
			delay_ms(1);
		}
	}

	flash_lock();
	return TRUE;
}

void DF_Erase_Para(void)
{
	Block_Erase(BLOCK_A);
	Block_Erase(BLOCK_B);
	Block_Erase(LF_BLOCK_A);
	Block_Erase(LF_BLOCK_B);
	Block_Erase(UF_START_ADDR);
}


void DF_Erase_Record(void)
{
	Block_Erase(BLOCK_A);
	Block_Erase(BLOCK_B);
}

void lifetime_init(void)
{
	memset(&l_lifetimes,0,sizeof(LifeTimes));
		LifeTimes_Cell_1_Min_Voltage = 0xFFFF;
		LifeTimes_Cell_2_Min_Voltage = 0xFFFF;
		LifeTimes_Cell_3_Min_Voltage = 0xFFFF;
		LifeTimes_Cell_4_Min_Voltage = 0xFFFF;
		LifeTimes_Min_Temp_Cell = 0x40;
		LifeTimes_Min_Temp_MOS = 0x40;
}

uint8_t efuse_key_write(uint8_t *key)
{
	flash_status_t flash_status_flag = FLASH_STATUS_COMPLETE;
	uint8_t rev_key[USER_KEY_LEN] = {0x12, 0x34, 0x56, 0x78, 0xAA, 0xBB, 0xCC, 0xDD};
	uint32_t temp, i, j = 0;
	memcpy(rev_key, key, USER_KEY_LEN);
	flash_unlock();
	flash_status_flag = efuse_page_erase(USER_KEY_REGION);
	if (flash_status_flag != FLASH_STATUS_COMPLETE)
	{
		flash_lock();
		return 1;
	}
	for(i = 0; i < USER_KEY_LEN; i = i + 4)
	{
		temp = *(uint32_t *)&rev_key[j];
		if (efuse_word_program(USER_KEY_REGION + j, temp) != FLASH_STATUS_COMPLETE)
		{
			flash_lock();
			return 1;
		}
		j = j + 4;
	}
	flash_lock();
	return 0;
}

void revision_stage(void)
{
	if (__FLASH_PDSEAL_STAT_GET(FMC_STS2_PDSEAL_STS) != SET)
	{
		//printf("Product information not sealed !!!\r\n");
		flash_unlock();
		__FLASH_FLAG_CLEAR(FLASH_FLAG_ENDF | FLASH_FLAG_PGERR | FLASH_FLAG_WPERR);
		flash_word_program(0x1FFFFC58, 0xBC43AC53);
		flash_lock();
		NVIC_SystemReset();
	}
	// 进入level2

	flash_unlock();
	flash_option_bytes_unlock();
	__FLASH_FLAG_CLEAR(FLASH_FLAG_ENDF | FLASH_FLAG_PGERR | FLASH_FLAG_WPERR);
	efuse_lifecycle_set(FMC_STS2_LCSSTS_LEVEL2);
	flash_option_bytes_lock();
	flash_lock();
	//printf("tttttt \r\n");
	// 复位芯片
	NVIC_SystemReset();
}
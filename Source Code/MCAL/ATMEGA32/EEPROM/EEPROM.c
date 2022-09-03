/*
 * EEPROM.c
 *
 * Created: 14/10/2021 04:59:09 pm
 *  Author: mohamed nasser
 */

#include <avr/io.h>
#include "EEPROM.h"

void EEPROM_EnableInterrupt(void)
{
	SET_BIT(EECR,EERIE);
}
void EEPROM_DisableInterrupt(void)
{
	CLR_BIT(EECR,EERIE);
}
void EEPROM_WriteByte(const ptr_uint8_t address,uint8_t data)
{
	INTERRUPT_DisableGlobalINT();
	//set up address register
	EEAR = (uint16_t)address;
	//set up data register
	EEDR = data;
	//write logical one to EEMWE
	SET_BIT(EECR,EEMWE);
	//start EEPROM write by setting EEWE
	SET_BIT(EECR,EEWE);
	INTERRUPT_EnableGlobalINT();
	//wait for completion of  write operation
	while(READ_BIT(EECR,EEWE) == 1);
}
uint8_t EEPROM_ReadByte(const ptr_uint8_t address)
{
	//set up address register
	EEAR = (uint16_t)address;
	//start EEPROM read by setting EERE
	SET_BIT(EECR,EERE);
	//return data from data register
	return EEDR;
}
void EEPROM_WriteWord(const ptr_uint8_t address,uint16_t data)
{
	uint8_t index_of_byte;
	for (index_of_byte = 0;index_of_byte < 2;index_of_byte++)
	{
		INTERRUPT_DisableGlobalINT();;
		//set up address register for i-th byte
		EEAR = (uint16_t)(address+index_of_byte);
		//set up data register for i-th byte
		EEDR = (uint8_t)(data>>(8*index_of_byte));
		//write logical one to EEMWE for i-th byte
		SET_BIT(EECR,EEMWE);
		//start EEPROM write by setting EEWE for i-th byte
		SET_BIT(EECR,EEWE);
		INTERRUPT_EnableGlobalINT();
		//wait for completion of  write operation for i-th byte
		while(READ_BIT(EECR,EEWE) == 1);
	}
}
uint16_t EEPROM_ReadWord(const ptr_uint8_t address)
{
	uint16_t return_word = 0x0000;
	uint8_t index_of_byte;
	for(index_of_byte = 0;index_of_byte < 2;index_of_byte++)
	{
		//set up address register for i-th byte
		EEAR = (uint16_t)(address+index_of_byte);
		//start EEPROM read by setting EERE for i byte
		SET_BIT(EECR,EERE);
		//load data from data register for i-th byte
		return_word |= ((uint16_t)EEDR<<(8*index_of_byte));
	}
	//return the over all word
	return return_word;
}
void EEPROM_WriteDWord(const ptr_uint8_t address,uint32_t data)
{
	uint8_t index_of_byte;
	for (index_of_byte = 0;index_of_byte < 4;index_of_byte++)
	{
		INTERRUPT_DisableGlobalINT();;
		//set up address register for i-th byte
		EEAR = (uint16_t)(address+index_of_byte);
		//set up data register for i-th byte
		EEDR = (unsigned char)(data>>(8*index_of_byte));
		//write logical one to EEMWE for i-th byte
		SET_BIT(EECR,EEMWE);
		//start EEPROM write by setting EEWE for i-th byte
		SET_BIT(EECR,EEWE);
		INTERRUPT_EnableGlobalINT();
		//wait for completion of  write operation for i-th byte
		while(READ_BIT(EECR,EEWE) == 1);
	}	
}
uint32_t EEPROM_ReadDWord(const ptr_uint8_t address)
{
	uint32_t return_double_word = 0x00000000;
	uint8_t index_of_byte;
	for(index_of_byte = 0;index_of_byte < 4;index_of_byte++)
	{
		//set up address register for i byte
		EEAR = (uint16_t)(address+index_of_byte);
		//start EEPROM read by setting EERE for i byte
		SET_BIT(EECR,EERE);
		//load data from data register for i byte
		return_double_word |= ((uint32_t)EEDR<<(8*index_of_byte));
	}
	//return the over all double word
	return return_double_word;
}
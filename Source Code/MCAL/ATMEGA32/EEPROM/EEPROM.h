/*
 * EEPROM.h
 *
 * Created: 14/10/2021 04:53:50 pm
 * Author: Mohamed Nasser
 */


#ifndef EEPROM_H_
#define EEPROM_H_



#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "INTERRUPT.h"

void EEPROM_EnableInterrupt(void);
void EEPROM_DisableInterrupt(void);
void EEPROM_WriteByte(const ptr_uint8_t address,uint8_t data);
uint8_t EEPROM_ReadByte(const ptr_uint8_t address);
void EEPROM_WriteWord(const ptr_uint8_t address,uint16_t data);
uint16_t EEPROM_ReadWord(const ptr_uint8_t address);
void EEPROM_WriteDWord(const ptr_uint8_t address,uint32_t data);
uint32_t EEPROM_ReadDWord(const ptr_uint8_t address);

#endif /* EEPROM_H_ */
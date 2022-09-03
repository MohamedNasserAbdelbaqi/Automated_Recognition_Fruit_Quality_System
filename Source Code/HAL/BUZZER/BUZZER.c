/*
 * BUZZER.c
 * Created: 02/10/2021 03:25:54 am
 * Author: Mohamed Nasser
 */ 
 
#include "BUZZER.h"

/* APIs for buzzer module */
error_state_t BUZZER_Init(uint8_t port_name,uint8_t bit_number)
{
	return DIO_SetPinDirection(port_name,bit_number,OUTPUT_PIN);
}
error_state_t BUZZER_TurnOn(uint8_t port_name,uint8_t bit_number)
{
	return DIO_WritePin(port_name,bit_number,BIT_HIGH);
}
error_state_t BUZZER_TurnOff(uint8_t port_name,uint8_t bit_number)
{
	return DIO_WritePin(port_name,bit_number,BIT_LOW);
}
error_state_t BUZZER_Toggle(uint8_t port_name,uint8_t bit_number)
{
	return DIO_TogglePin(port_name,bit_number);
}
error_state_t BUZZER_ReadStatus(uint8_t port_name,uint8_t bit_number,ptr_uint8_t function_return)
{
	return DIO_ReadPin(port_name,bit_number,function_return);
}
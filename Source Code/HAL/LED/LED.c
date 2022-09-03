/*
 * LED.c
 * Created: 02/10/2021 02:19:59 am
 * Author: Mohamed Nasser
 */ 
 
#include "LED.h"

/* APIs for LED module */
error_state_t LED_Init(uint8_t port_name,uint8_t bit_number)
{
	return DIO_SetPinDirection(port_name,bit_number,OUTPUT_PIN);
}
error_state_t LED_TurnOn(uint8_t port_name,uint8_t bit_number)
{
	return DIO_WritePin(port_name,bit_number,BIT_HIGH);
}
error_state_t LED_TurnOff(uint8_t port_name,uint8_t bit_number)
{
	return DIO_WritePin(port_name,bit_number,BIT_LOW);
}
error_state_t LED_Toggle(uint8_t port_name,uint8_t bit_number)
{
	return DIO_TogglePin(port_name,bit_number);
}
error_state_t LED_ReadStatus(uint8_t port_name,uint8_t bit_number,ptr_uint8_t function_return)
{
	return DIO_ReadPin(port_name,bit_number,function_return);
}
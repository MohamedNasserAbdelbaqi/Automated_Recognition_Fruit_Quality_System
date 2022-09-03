/*
 * BUTTON.c
 * Created: 03/10/2021 12:37:45 am
 * Author: Mohamed Nasser
 */ 
 
#include "BUTTON.h"

/* APIs for button module */
error_state_t BUTTON_Init(uint8_t port_name,uint8_t bit_number)
{
	return DIO_SetPinDirection(port_name,bit_number,INPUT_PIN);
}
error_state_t BUTTON_Read(uint8_t port_name,uint8_t bit_number,ptr_uint8_t function_return)
{
	return DIO_ReadPin(port_name,bit_number,function_return);
}
error_state_t BUTTON_EnableInternalPullUpRes(uint8_t port_name,uint8_t bit_number,uint8_t enable){
	return DIO_EnablePinInternalPullUpRes(port_name,bit_number,enable);
}
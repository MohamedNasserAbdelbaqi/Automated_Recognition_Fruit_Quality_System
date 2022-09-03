/*
 * LED.h
 * Created: 02/10/2021 02:19:17 am
 * Author: Mohamed Nasser
 */ 


#ifndef LED_H_
#define LED_H_

/* file includes */
#include "STD_TYPES.h"
#include "DIO.h"

/* LED status */
#define OFF   0
#define ON    1

/* APIs for LED module */
error_state_t LED_Init(uint8_t port_name,uint8_t bit_number);
error_state_t LED_TurnOn(uint8_t port_name,uint8_t bit_number);
error_state_t LED_TurnOff(uint8_t port_name,uint8_t bit_number);
error_state_t LED_Toggle(uint8_t port_name,uint8_t bit_number);
error_state_t LED_ReadStatus(uint8_t port_name,uint8_t bit_number,ptr_uint8_t function_return);

#endif /* LED_H_ */
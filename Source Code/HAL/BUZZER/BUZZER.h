/*
 * BUZZER.h
 * Created: 02/10/2021 03:25:40 am
 * Author:	Mohamed Nasser
 */ 


#ifndef BUZZER_H_
#define BUZZER_H_

/* file includes */
#include "STD_TYPES.h"
#include "DIO.h"

/* buzzer status */
#define OFF   0
#define ON    1

 /* APIs for buzzer module */
error_state_t BUZZER_Init(uint8_t port_name,uint8_t bit_number);
error_state_t BUZZER_TurnOn(uint8_t port_name,uint8_t bit_number);
error_state_t BUZZER_TurnOff(uint8_t port_name,uint8_t bit_number);
error_state_t BUZZER_Toggle(uint8_t port_name,uint8_t bit_number);
error_state_t BUZZER_ReadStatus(uint8_t port_name,uint8_t bit_number,ptr_uint8_t function_return);

#endif /* BUZZER_H_ */
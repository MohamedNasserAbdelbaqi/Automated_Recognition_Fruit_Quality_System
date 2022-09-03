/*
 * BUTTON.h
 * Created: 03/10/2021 12:38:05 am
 * Author: Mohamed Nasser
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

/* file includes */
#include "STD_TYPES.h"
#include "DIO.h"

/* APIs for button module */
error_state_t BUTTON_Init(uint8_t port_name,uint8_t bit_number);
error_state_t BUTTON_Read(uint8_t port_name,uint8_t bit_number,ptr_uint8_t function_return);
error_state_t BUTTON_EnableInternalPullUpRes(uint8_t port_name,uint8_t bit_number,uint8_t enable);

#endif /* BUTTON_H_ */
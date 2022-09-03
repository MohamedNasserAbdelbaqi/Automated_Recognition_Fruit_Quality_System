/*
 * DC_MOTOR.h
 *
 * Created: 2/27/2022 6:43:10 AM
 * Author: Mohamed Nasser
 */ 


#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

/* file includes */
#include "PWM.h"

/* APIs for DC motor */

/* APIs for controlling constant DC speed motor */
void DC_MOTOR_InitWithConstSpeed(uint8_t port_name,uint8_t bit_number);
void DC_MOTOR_TurnONWithConstSpeed(uint8_t port_name,uint8_t bit_number);
void DC_MOTOR_TurnOFFWithConstSpeed(uint8_t port_name,uint8_t bit_number);

/* APIs for controlling variable DC speed motor */
void DC_MOTOR_InitWithVarSpeed(uint8_t port_name,uint8_t bit_number,uint8_t enable_channel);
void DC_MOTOR_TurnONWithVarSpeed(uint8_t port_name,uint8_t bit_number,uint8_t enable_channel);
void DC_MOTOR_SetSpeed(uint8_t port_name,uint8_t bit_number,uint8_t enable_channel,uint8_t speed);
void DC_MOTOR_TurnOFFWithVarSpeed(uint8_t port_name,uint8_t bit_number,uint8_t enable_channel);
void DC_MOTOR_ChangeStateWithVarSpeed(uint8_t port_name,uint8_t bit_number,uint8_t enable_channel);
/* APIs for controlling both constant DC speed motor and variable DC speed motor */
void DC_MOTOR_ChangeDirection(uint8_t port_name,uint8_t bit_number);

#endif /* DC_MOTOR_H_ */
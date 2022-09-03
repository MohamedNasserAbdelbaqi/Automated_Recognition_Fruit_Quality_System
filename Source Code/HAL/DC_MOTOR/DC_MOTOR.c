/*
 * DC_MOTOR.c
 *
 * Created: 2/27/2022 6:42:57 AM
 * Author: Mohamed Nasser
 */ 

#include "DC_MOTOR.h"

/* APIs for DC motor */
void DC_MOTOR_InitWithConstSpeed(uint8_t port_name,uint8_t bit_number)
{
	DIO_SetPinDirection(port_name,bit_number,OUTPUT_PIN);
	DIO_SetPinDirection(port_name,bit_number+1,OUTPUT_PIN);
}
void DC_MOTOR_TurnON(uint8_t port_name,uint8_t bit_number)
{
	DIO_WritePin(port_name,bit_number,BIT_LOW);
	DIO_WritePin(port_name,bit_number+1,BIT_HIGH);
}
void DC_MOTOR_TurnOFF(uint8_t port_name,uint8_t bit_number)
{
	DIO_WritePin(port_name,bit_number,BIT_LOW);
	DIO_WritePin(port_name,bit_number+1,BIT_LOW);
}
void DC_MOTOR_ChangeDirection(uint8_t port_name,uint8_t bit_number)
{
	DIO_TogglePin(port_name,bit_number);
	DIO_TogglePin(port_name,bit_number+1);
}
void DC_MOTOR_InitWithVarSpeed(uint8_t port_name,uint8_t bit_number,uint8_t enable_channel)
{
	DIO_SetPinDirection(port_name,bit_number,OUTPUT_PIN);
	DIO_SetPinDirection(port_name,bit_number+1,OUTPUT_PIN);
	switch(enable_channel)
	{
		case OC0_CHANNEL:
			PWM_InitWithConstFreq(enable_channel,OC0_FAST_PWM,NON_INVERTING,OC0_PRESCALER_1,100);
			break;
		case OC1A_CHANNEL:
			PWM_InitWithConstFreq(enable_channel,OC1_FAST_PWM_8_BITS,NON_INVERTING,OC1_PRESCALER_1,100);
			break;
		case OC1B_CHANNEL:
			PWM_InitWithConstFreq(enable_channel,OC1_FAST_PWM_8_BITS,NON_INVERTING,OC1_PRESCALER_1,100);
			break;
		case OC2_CHANNEL:
			PWM_InitWithConstFreq(enable_channel,OC2_FAST_PWM,NON_INVERTING,OC2_PRESCALER_1,100);
			break;
		default:
			break;
	}
}
void DC_MOTOR_TurnONWithVarSpeed(uint8_t port_name,uint8_t bit_number,uint8_t enable_channel)
{
	DIO_WritePin(port_name,bit_number,BIT_LOW);
	DIO_WritePin(port_name,bit_number+1,BIT_HIGH);
	PWM_Start(enable_channel);
}
void DC_MOTOR_TurnOFFWithVarSpeed(uint8_t port_name,uint8_t bit_number,uint8_t enable_channel)
{
	DIO_WritePin(port_name,bit_number,BIT_LOW);
	DIO_WritePin(port_name,bit_number+1,BIT_LOW);
	PWM_Stop(enable_channel);
}
void DC_MOTOR_SetSpeed(uint8_t port_name,uint8_t bit_number,uint8_t enable_channel,uint8_t speed)
{
	uint8_t duty_cycle;
	duty_cycle = speed;
	switch(enable_channel)
	{
		case OC0_CHANNEL:
			PWM_ChangePWMProperties(enable_channel,NON_INVERTING,duty_cycle);
			break;
		case OC1A_CHANNEL:
			PWM_ChangePWMProperties(enable_channel,NON_INVERTING,duty_cycle);
			break;
		case OC1B_CHANNEL:
			PWM_ChangePWMProperties(enable_channel,NON_INVERTING,duty_cycle);
			break;
		case OC2_CHANNEL:
			PWM_ChangePWMProperties(enable_channel,NON_INVERTING,duty_cycle);
			break;
		default:
			break;
	}
}
void DC_MOTOR_ChangeStateWithVarSpeed(uint8_t port_name,uint8_t bit_number,uint8_t enable_channel)
{
	uint8_t motor_first_pole,motor_second_pole;
	DIO_ReadPin(port_name,bit_number,&motor_first_pole);
	DIO_ReadPin(port_name,bit_number+1,&motor_second_pole);
	if (motor_first_pole == 1 || motor_second_pole == 1)
	{
		DIO_WritePin(port_name,bit_number,BIT_LOW);
		DIO_WritePin(port_name,bit_number+1,BIT_LOW);
		PWM_Stop(enable_channel);
	}
	else
	{
		DIO_WritePin(port_name,bit_number,BIT_LOW);
		DIO_WritePin(port_name,bit_number+1,BIT_HIGH);
		PWM_Start(enable_channel);
	}
}
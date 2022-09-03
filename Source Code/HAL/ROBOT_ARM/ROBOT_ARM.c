/*
 * ROBOT_ARM.c
 *
 * Created: 3/6/2022 5:10:20 PM
 * Author: Mohamed Nasser
 */ 

/* file includes */
#include "DIO.h"
#include "ROBOT_ARM.h"


/* APIs for robot arm */
void ROBOT_ARM_Init(uint8_t port_name,uint8_t bit_number)
{
	/* set two pin as output pin for selection lines of DEMUX */
	DIO_SetPinDirection(port_name,bit_number,OUTPUT_PIN);
	DIO_SetPinDirection(port_name,bit_number+1,OUTPUT_PIN);
	
	/* move first servo of robot arm */
	/* select first channel of DEMUX */
	DIO_WritePin(port_name,bit_number,BIT_LOW);
	DIO_WritePin(port_name,bit_number+1,BIT_LOW);
	SERVO_Init(OC1B_CHANNEL,90);
	_delay_ms(557);
	
	/* move second servo of robot arm */
	SERVO_Init(OC1A_CHANNEL,70);
	_delay_ms(557);
	
	/* move third servo of robot arm */
	/* select second channel of DEMUX */
	DIO_WritePin(port_name,bit_number,BIT_HIGH);
	DIO_WritePin(port_name,bit_number+1,BIT_LOW);
	SERVO_Init(OC1B_CHANNEL,0);
	_delay_ms(557);
	
	/* move clipper servo of robot arm */
	/* select third channel of DEMUX */
	DIO_WritePin(port_name,bit_number,BIT_LOW);
	DIO_WritePin(port_name,bit_number+1,BIT_HIGH);
	SERVO_Init(OC1B_CHANNEL,CLIPPER_OPEN);
	_delay_ms(557);
}
void ROBOT_ARM_Move(uint8_t port_name,uint8_t bit_number,float32_t angle_1,float32_t angle_2,float32_t angle_3,float32_t clipper_angel)
{	
	/* move first servo of robot arm */
	/* select first channel of DEMUX */
	DIO_WritePin(port_name,bit_number,BIT_LOW);
	DIO_WritePin(port_name,bit_number+1,BIT_LOW);
	SERVO_SetAngle(OC1B_CHANNEL,angle_1);
	_delay_ms(557);
	
	/* move second servo of robot arm */
	SERVO_SetAngle(OC1A_CHANNEL,angle_2);
	_delay_ms(557);
	
	/* move third servo of robot arm */
	/* select second channel of DEMUX */
	DIO_WritePin(port_name,bit_number,BIT_HIGH);
	DIO_WritePin(port_name,bit_number+1,BIT_LOW);
	SERVO_SetAngle(OC1B_CHANNEL,angle_3);
	_delay_ms(557);
	
	/* move clipper servo of robot arm */
	/* select third channel of DEMUX */
	DIO_WritePin(port_name,bit_number,BIT_LOW);
	DIO_WritePin(port_name,bit_number+1,BIT_HIGH);
	SERVO_SetAngle(OC1B_CHANNEL,clipper_angel);
	_delay_ms(557);
	
	/*_delay_ms(557);*/
}
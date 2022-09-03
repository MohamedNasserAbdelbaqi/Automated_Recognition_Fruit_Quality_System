/*
 * TestApplication.c
 * Created: 2/8/2022 1:37:58 AM
 * Author : Mohamed Nasser
 */ 
#include "ROBOT_ARM.h"
#include "DC_MOTOR.h"
#include "USART.h"
#include "INTERRUPT.h"

#define ROTTEN           '0'
#define FRESH            '1'
#define READY            'R'
#define FINISH           'F'

//extern volatile uint8_t unclassified_banana;

void CONVEY_ChangeState(void)
{
	DC_MOTOR_ChangeStateWithVarSpeed(PORT_A,0,OC0_CHANNEL);
}
void USART_Transmit_Wrapper(void)
{
	USART_Transmit(READY);
}
void Nothing(void)
{
}
int main(void)
{
	/* for motor of convey (take PA0 - PA1 - PB3) */
	DC_MOTOR_InitWithVarSpeed(PORT_A,0,OC0_CHANNEL);
	DC_MOTOR_TurnONWithVarSpeed(PORT_A,0,OC0_CHANNEL);
	DC_MOTOR_SetSpeed(PORT_A,0,OC0_CHANNEL,77);
	/* for UART (take PD0 - PD1) */
	USART_InitReceiver(ASYNCHRONOUS_NORMAL_MODE,_8_BIT_CHAR,DISABLE_PARITY,ONE_STOP_BIT,9600);
	USART_InitTransmitter(ASYNCHRONOUS_NORMAL_MODE,_8_BIT_CHAR,DISABLE_PARITY,ONE_STOP_BIT,9600);
	/* for external interrupt (take PB2) */
	INTERRUPT_SetCallBackFun(INTERRUPT_2,CONVEY_ChangeState,Nothing,USART_Transmit_Wrapper);
	INTERRUPT_SetSenceControlINT2(FALLING_EDGE);
	INTERRUPT_EnableINT2();
	INTERRUPT_EnableGlobalINT();
	/* for robotic arm (take PD2 - PD3 - PD4 - PD5) */
	ROBOT_ARM_Init(PORT_D,2);
	
	uint8_t fruit_state;
	
	while (1)
	{			
		/*if (unclassified_banana > 0)
		{
			USART_Transmit_Wrapper();
		}*/
		
		fruit_state = (uint8_t)USART_Receive();
		
		INTERRUPT_DisableGlobalINT();
		
		/* clip position */
		ROBOT_ARM_Move(PORT_D,2,90,125,0,CLIPPER_HALF_CLOSE);
		/* default position */
		ROBOT_ARM_Move(PORT_D,2,90,70,0,CLIPPER_HALF_CLOSE);
		
		
		if (ROTTEN == fruit_state)
		{
			/* left cup position */
			ROBOT_ARM_Move(PORT_D,2,180,90,0,CLIPPER_OPEN);
			/* default position */
			ROBOT_ARM_Move(PORT_D,2,180,70,0,CLIPPER_OPEN);
		} 
		else if (FRESH == fruit_state)
		{
			/* right cup position */
			ROBOT_ARM_Move(PORT_D,2,15,90,0,CLIPPER_OPEN);
			/* default position */
			ROBOT_ARM_Move(PORT_D,2,15,70,0,CLIPPER_OPEN);
		}		
		
		/* default position */
		ROBOT_ARM_Move(PORT_D,2,90,70,0,CLIPPER_OPEN);	
		
		USART_Transmit(FINISH);	

		INTERRUPT_EnableGlobalINT();
		//unclassified_banana--;
	}	
}

/*********************************************************************************/
/* clip position */
//ROBOT_ARM_Move(PORT_D,0,90,135,0,CLIPPER_HALF_CLOSE);
//_delay_ms(500);
/* back cup position */
//ROBOT_ARM_Move(PORT_D,0,90,40,180,CLIPPER_HALF_CLOSE);
//_delay_ms(500);
/* default position */
//ROBOT_ARM_Move(PORT_D,0,90,40,180,CLIPPER_OPEN);
//_delay_ms(500);
/* default position */
//ROBOT_ARM_Move(PORT_D,0,90,90,0,CLIPPER_OPEN);
//_delay_ms(500);

/*90 90 0 CLIPPER_OPEN */
/*90 90 145 CLIPPER_HALF_CLOSE */
/*6.35 cm */


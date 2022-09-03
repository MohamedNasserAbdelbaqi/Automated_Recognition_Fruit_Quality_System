/*
 * PWM.c
 *
 * Created: 2/24/2022 12:11:18 AM
 * Author: Mohamed Nasser
 */ 
 #include <avr/io.h>
 #include "PWM.h"
 
volatile uint8_t OC0_prescaler;
volatile uint8_t OC1_prescaler;
volatile uint8_t OC2_prescaler;

volatile uint8_t OC0_PWM_mode;
volatile uint8_t OC1A_PWM_mode;
volatile uint8_t OC1B_PWM_mode;
volatile uint8_t OC2_PWM_mode;

volatile float32_t OC1A_frequency;
volatile float32_t OC1B_frequency;


void PWM_InitWithConstFreq(uint8_t channel,uint8_t PWM_mode,uint8_t connection_mode,uint8_t prescaler,float32_t duty_cycle)
{
	switch(channel)
	 {
		 case OC0_CHANNEL:
			 DIO_SetPinDirection(PORT_B,3,OUTPUT_PIN);
			 TWO_BITS_WRITE(TCCR0,COM00,connection_mode);
			 OC0_prescaler = prescaler;
			 OC0_PWM_mode = PWM_mode;
			 switch(PWM_mode)
			 {
				 case OC0_PHASE_CORRECT_PWM:
					 SET_BIT(TCCR0,WGM00);
					 CLR_BIT(TCCR0,WGM01);
					 switch(connection_mode)
					 {
						 case NON_INVERTING:
							 OCR0 = (uint8_t)(((duty_cycle/100.0)*255.0));
							 break;
						 case INVERTING:
							 OCR0 = (uint8_t)(255-((duty_cycle/100.0)*255.0));
							 break;
						 default:
							break;
					 }
					 break;
				 case OC0_FAST_PWM:
					 SET_BIT(TCCR0,WGM00);
					 SET_BIT(TCCR0,WGM01);
					 switch(connection_mode)
					 {
						 case NON_INVERTING:
							 OCR0 = (uint8_t)(((duty_cycle/100.0)*256.0)-1);
							 break;
						 case INVERTING:
							 OCR0 = (uint8_t)(255-((duty_cycle/100.0)*256.0));
							 break;
						 default:
							break;
					 }
					 break;
				 default:
					break;
			 }
			 break;
		 case OC1A_CHANNEL:
			 DIO_SetPinDirection(PORT_D,5,OUTPUT_PIN);
			 TWO_BITS_WRITE(TCCR1A,COM1A0,connection_mode);
			 OC1_prescaler = prescaler;
			 OC1A_PWM_mode = PWM_mode;
			 switch(PWM_mode)
			 {
				 case OC1_PHASE_CORRECT_8_BITS:
					 TWO_BITS_WRITE(TCCR1A,WGM10,1);
					 TWO_BITS_WRITE(TCCR1B,WGM12,0);
					 switch(connection_mode)
					 {
						 case NON_INVERTING:
							 OCR1A = (uint16_t)(((duty_cycle/100.0)*255.0));
							 break;
						 case INVERTING:
							 OCR1A = (uint16_t)(255-((duty_cycle/100.0)*255.0));
							 break;
						 default:
							 break;
					 }
					 break;
				 case OC1_PHASE_CORRECT_9_BITS:
					 TWO_BITS_WRITE(TCCR1A,WGM10,2);
					 TWO_BITS_WRITE(TCCR1B,WGM12,0);
					 switch(connection_mode)
					 {
						 case NON_INVERTING:
							 OCR1A = (uint16_t)(((duty_cycle/100.0)*511.0));
							 break;
						 case INVERTING:
							 OCR1A = (uint16_t)(511-((duty_cycle/100.0)*511.0));
							 break;
						 default:
							 break;
					 }
					 break;
				 case OC1_PHASE_CORRECT_10_BITS:
					 TWO_BITS_WRITE(TCCR1A,WGM10,3);
					 TWO_BITS_WRITE(TCCR1B,WGM12,0);
					 switch(connection_mode)
					 {
						 case NON_INVERTING:
							 OCR1A = (uint16_t)(((duty_cycle/100.0)*1023.0));
							 break;
						 case INVERTING:
							 OCR1A = (uint16_t)(1023-((duty_cycle/100.0)*1023.0));
							 break;
						 default:
							 break;
					 }
					 break;
				 case OC1_FAST_PWM_8_BITS:
					 TWO_BITS_WRITE(TCCR1A,WGM10,1);
					 TWO_BITS_WRITE(TCCR1B,WGM12,1);
					 switch(connection_mode)
					 {
						 case NON_INVERTING:
							 OCR1A = (uint16_t)(((duty_cycle/100.0)*256.0)-1);
							 break;
						 case INVERTING:
							 OCR1A = (uint16_t)(255-((duty_cycle/100.0)*256.0));
							 break;
						 default:
							 break;
					 }
					 break;
				 case OC1_FAST_PWM_9_BITS:
					 TWO_BITS_WRITE(TCCR1A,WGM10,2);
					 TWO_BITS_WRITE(TCCR1B,WGM12,1);
					 switch(connection_mode)
					 {
						 case NON_INVERTING:
							 OCR1A = (uint16_t)(((duty_cycle/100.0)*512.0)-1);
							 break;
						 case INVERTING:
							 OCR1A = (uint16_t)(511-((duty_cycle/100.0)*512.0));
							 break;
						 default:
							 break;
					 }
					 break;
				 case OC1_FAST_PWM_10_BITS:
					 TWO_BITS_WRITE(TCCR1A,WGM10,3);
					 TWO_BITS_WRITE(TCCR1B,WGM12,1);
					 switch(connection_mode)
					 {
						 case NON_INVERTING:
							 OCR1A = (uint16_t)(((duty_cycle/100.0)*1024.0)-1);
							 break;
						 case INVERTING:
							 OCR1A = (uint16_t)(1023-((duty_cycle/100.0)*1024.0));
							 break;
						 default:
							 break;
					 }
					 break;
				 default:
					 break;
			 }
			 break;
		 case OC1B_CHANNEL:
			 DIO_SetPinDirection(PORT_D,4,OUTPUT_PIN);
			 TWO_BITS_WRITE(TCCR1A,COM1B0,connection_mode);
			 OC1_prescaler = prescaler;
			 OC1B_PWM_mode = PWM_mode;
			 switch(PWM_mode)
			 {
				 case OC1_PHASE_CORRECT_8_BITS:
					 TWO_BITS_WRITE(TCCR1A,WGM10,1);
					 TWO_BITS_WRITE(TCCR1B,WGM12,0);
					 switch(connection_mode)
					 {
						 case NON_INVERTING:
							 OCR1B = (uint16_t)(((duty_cycle/100.0)*255.0));
							 break;
						 case INVERTING:
							 OCR1B = (uint16_t)(255-((duty_cycle/100.0)*255.0));
							 break;
						 default:
							 break;
					 }
					 break;
				 case OC1_PHASE_CORRECT_9_BITS:
					 TWO_BITS_WRITE(TCCR1A,WGM10,2);
					 TWO_BITS_WRITE(TCCR1B,WGM12,0);
					 switch(connection_mode)
					 {
						 case NON_INVERTING:
							 OCR1B = (uint16_t)(((duty_cycle/100.0)*511.0));
							 break;
						 case INVERTING:
							 OCR1B = (uint16_t)(511-((duty_cycle/100.0)*511.0));
							 break;
						 default:
							 break;
					 }
					 break;
				 case OC1_PHASE_CORRECT_10_BITS:
					 TWO_BITS_WRITE(TCCR1A,WGM10,3);
					 TWO_BITS_WRITE(TCCR1B,WGM12,0);
					 switch(connection_mode)
					 {
						 case NON_INVERTING:
							 OCR1B = (uint16_t)(((duty_cycle/100.0)*1023.0));
							 break;
						 case INVERTING:
							 OCR1B = (uint16_t)(1023-((duty_cycle/100.0)*1023.0));
							 break;
						 default:
							 break;
					 }
					 break;
				 case OC1_FAST_PWM_8_BITS:
					 TWO_BITS_WRITE(TCCR1A,WGM10,1);
					 TWO_BITS_WRITE(TCCR1B,WGM12,1);
					 switch(connection_mode)
					 {
						 case NON_INVERTING:
							 OCR1B = (uint16_t)(((duty_cycle/100.0)*256.0)-1);
							 break;
						 case INVERTING:
							 OCR1B = (uint16_t)(255-((duty_cycle/100.0)*256.0));
							 break;
						 default:
							 break;
					 }
					 break;
				 case OC1_FAST_PWM_9_BITS:
					 TWO_BITS_WRITE(TCCR1A,WGM10,2);
					 TWO_BITS_WRITE(TCCR1B,WGM12,1);
					 switch(connection_mode)
					 {
						 case NON_INVERTING:
							 OCR1B = (uint16_t)(((duty_cycle/100.0)*512.0)-1);
							 break;
						 case INVERTING:
							 OCR1B = (uint16_t)(511-((duty_cycle/100.0)*512.0));
							 break;
						 default:
							 break;
					 }
					 break;
				 case OC1_FAST_PWM_10_BITS:
					 TWO_BITS_WRITE(TCCR1A,WGM10,3);
					 TWO_BITS_WRITE(TCCR1B,WGM12,1);
					 switch(connection_mode)
					 {
						 case NON_INVERTING:
							 OCR1B = (uint16_t)(((duty_cycle/100.0)*1024.0)-1);
							 break;
						 case INVERTING:
							 OCR1B = (uint16_t)(1023-((duty_cycle/100.0)*1024.0));
							 break;
						 default:
							 break;
					 }
					 break;
				 default:
					break;
			 }
			 break;
		 case OC2_CHANNEL:
			 DIO_SetPinDirection(PORT_D,7,OUTPUT_PIN);
			 TWO_BITS_WRITE(TCCR2,COM20,connection_mode);
			 OC2_prescaler = prescaler;
			 OC2_PWM_mode = PWM_mode;
			 switch(PWM_mode)
			 {
				 case OC2_PHASE_CORRECT_PWM:
					 SET_BIT(TCCR2,WGM20);
					 CLR_BIT(TCCR2,WGM21);
					 switch(connection_mode)
					 {
						 case NON_INVERTING:
							 OCR2 = (uint8_t)(((duty_cycle/100.0)*255.0));
							 break;
						 case INVERTING:
							 OCR2 = (uint8_t)(255-((duty_cycle/100.0)*255.0));
							 break;
						 default:
							break;
					 }
					 break;
				 case OC2_FAST_PWM:
					 SET_BIT(TCCR2,WGM20);
					 SET_BIT(TCCR2,WGM21);
					 switch(connection_mode)
					 {
						 case NON_INVERTING:
							 OCR2 = (uint8_t)(((duty_cycle/100.0)*256.0)-1);
							 break;
						 case INVERTING:
							 OCR2 = (uint8_t)(255-((duty_cycle/100.0)*256.0));
							 break;
						 default:
							break;
					 }
					 break;
				 default:
					break;
			 }
			 break;
		 default:
			 break;
	} 
}
void PWM_InitWithVarFreq(uint8_t channel,uint8_t PWM_mode,uint8_t connection_mode,uint8_t prescaler,float32_t frequency,float32_t duty_cycle)
 {
	 uint16_t temp_prescaler = 1;
	 switch(prescaler)
	 {
		 case OC1_PRESCALER_1:
			temp_prescaler = 1;
			break;
		 case OC1_PRESCALER_8:
			temp_prescaler = 8;
			break;
		 case OC1_PRESCALER_64:
			temp_prescaler = 64;
			break;
		 case OC1_PRESCALER_256:
			temp_prescaler = 256;
			break;
		 case OC1_PRESCALER_1024:
			temp_prescaler = 1024;
			break;
		 default:
			break;
	 }
	 switch(channel)
	 {
		 case OC1A_CHANNEL:
			 DIO_SetPinDirection(PORT_D,5,OUTPUT_PIN);
			 TWO_BITS_WRITE(TCCR1A,COM1A0,connection_mode);
			 OC1_prescaler = prescaler;
			 OC1A_PWM_mode = PWM_mode;
			 OC1A_frequency = frequency;
			 switch(PWM_mode)
			 {
				 case OC1_PHASE_FREQUENCY_CORRECT_ICR1:
					 TWO_BITS_WRITE(TCCR1A,WGM10,0);
					 TWO_BITS_WRITE(TCCR1B,WGM12,2);
					 ICR1 = (uint16_t)(F_CPU/(frequency * 2.0 * temp_prescaler));
					 switch(connection_mode)
					 {
						 case NON_INVERTING:
							 OCR1A = (uint16_t)(((duty_cycle/100.0)*ICR1));
							 break;
						 case INVERTING:
							 OCR1A = (uint16_t)(ICR1-(uint16_t)((duty_cycle/100.0)*ICR1));
							 break;
						 default:
							 break;
					 }
					 break;
				 case OC1_PHASE_CORRECT_ICR1:
					 TWO_BITS_WRITE(TCCR1A,WGM10,2);
					 TWO_BITS_WRITE(TCCR1B,WGM12,2);
					 ICR1 = (uint16_t)(F_CPU/(frequency * 2.0 * temp_prescaler));
					 switch(connection_mode)
					 {
						 case NON_INVERTING:
							 OCR1A = (uint16_t)(((duty_cycle/100.0)*ICR1));
							 break;
						 case INVERTING:
							 OCR1A = (uint16_t)(ICR1-(uint16_t)((duty_cycle/100.0)*ICR1));
							 break;
						 default:
							 break;
					 }
					 break;
				 case OC1_FAST_PWM_ICR1:
					 TWO_BITS_WRITE(TCCR1A,WGM10,2);
					 TWO_BITS_WRITE(TCCR1B,WGM12,3);
					 ICR1 = (uint16_t)((F_CPU/((float32_t)(frequency * temp_prescaler)))-1);
					 switch(connection_mode)
					 {
						 case NON_INVERTING:
							 OCR1A = (uint16_t)(((duty_cycle/100.0)*(ICR1+1))-1);
							 break;
						 case INVERTING:
							 OCR1A = (uint16_t)(ICR1-(uint16_t)((duty_cycle/100.0)*(ICR1+1)));
							 break;
						 default:
							 break;
					 }
					 break;
				 default:
					 break;
			 }
			 break;
		 case OC1B_CHANNEL:
			 DIO_SetPinDirection(PORT_D,4,OUTPUT_PIN);
			 TWO_BITS_WRITE(TCCR1A,COM1B0,connection_mode);
			 OC1_prescaler = prescaler;
			 OC1B_PWM_mode = PWM_mode;
			 OC1B_frequency = frequency;
			 switch(PWM_mode)
			 {
				 case OC1_PHASE_FREQUENCY_CORRECT_ICR1:
					 TWO_BITS_WRITE(TCCR1A,WGM10,0);
					 TWO_BITS_WRITE(TCCR1B,WGM12,2);
					 ICR1 = (uint16_t)(F_CPU/(frequency * 2.0 * temp_prescaler));
					 switch(connection_mode)
					 {
						 case NON_INVERTING:
							 OCR1B = (uint16_t)(((duty_cycle/100.0)*ICR1));
							 break;
						 case INVERTING:
							 OCR1B = (uint16_t)(ICR1-(uint16_t)((duty_cycle/100.0)*ICR1));
							 break;
						 default:
							 break;
					 }
					 break;
				 case OC1_PHASE_FREQUENCY_CORRECT_OCR1A:
					 TWO_BITS_WRITE(TCCR1A,WGM10,1);
					 TWO_BITS_WRITE(TCCR1B,WGM12,2);
					 OCR1A = (uint16_t)(F_CPU/(frequency * 2.0 * temp_prescaler));
					 switch(connection_mode)
					 {
						 case NON_INVERTING:
							 OCR1B = (uint16_t)(((duty_cycle/100.0)*OCR1A));
							 break;
						 case INVERTING:
							 OCR1B = (uint16_t)(OCR1A-(uint16_t)((duty_cycle/100.0)*OCR1A));
							 break;
						 default:
							 break;
					 }
					 break;
				 case OC1_PHASE_CORRECT_ICR1:
					 TWO_BITS_WRITE(TCCR1A,WGM10,2);
					 TWO_BITS_WRITE(TCCR1B,WGM12,2);
					 ICR1 = (uint16_t)(F_CPU/(frequency * 2.0 * temp_prescaler));
					 switch(connection_mode)
					 {
						 case NON_INVERTING:
							 OCR1B = (uint16_t)(((duty_cycle/100.0)*ICR1));
							 break;
						 case INVERTING:
							 OCR1B = (uint16_t)(ICR1-(uint16_t)((duty_cycle/100.0)*ICR1));
							 break;
						 default:
							 break;
					 }
					 break;
				 case OC1_PHASE_CORRECT_OCR1A:
					 TWO_BITS_WRITE(TCCR1A,WGM10,3);
					 TWO_BITS_WRITE(TCCR1B,WGM12,2);
					 OCR1A = (uint16_t)(F_CPU/(frequency * 2.0 * temp_prescaler));
					 switch(connection_mode)
					 {
						 case NON_INVERTING:
							 OCR1B = (uint16_t)(((duty_cycle/100.0)*OCR1A));
							 break;
						 case INVERTING:
							 OCR1B = (uint16_t)(OCR1A-(uint16_t)((duty_cycle/100.0)*OCR1A));
							 break;
						 default:
							 break;
					 }
					 break;
				 case OC1_FAST_PWM_ICR1:
					 TWO_BITS_WRITE(TCCR1A,WGM10,2);
					 TWO_BITS_WRITE(TCCR1B,WGM12,3);
					 ICR1 = (uint16_t)((F_CPU/((float32_t)(frequency * temp_prescaler)))-1);
					 switch(connection_mode)
					 {
						 case NON_INVERTING:
							 OCR1B = (uint16_t)(((duty_cycle/100.0)*(ICR1+1))-1);
							 break;
						 case INVERTING:
							 OCR1B = (uint16_t)(ICR1-(uint16_t)((duty_cycle/100.0)*(ICR1+1)));
							 break;
						 default:
							 break;
					 }
					 break;
				 case OC1_FAST_PWM_OCR1A:
					 TWO_BITS_WRITE(TCCR1A,WGM10,3);
					 TWO_BITS_WRITE(TCCR1B,WGM12,3);
					 OCR1A = (uint16_t)((F_CPU/((float32_t)(frequency * temp_prescaler)))-1);
					 switch(connection_mode)
					 {
						 case NON_INVERTING:
							 OCR1B = (uint16_t)(((duty_cycle/100.0)*(OCR1A+1))-1);
							 break;
						 case INVERTING:
							 OCR1B = (uint16_t)(OCR1A-(uint16_t)((duty_cycle/100.0)*(OCR1A+1)));
							 break;
						 default:
							 break;
					 }
					 break;
				 default:
					break;
			 }
			 break;
		 default:
			break;
	 }
 }
void PWM_Start(uint8_t channel)
 {
	switch(channel)
	{
		case OC0_CHANNEL:
			switch(OC0_prescaler)
			{
				case OC0_PRESCALER_1:
					THREE_BITS_WRITE(TCCR0,CS00,OC0_PRESCALER_1);
					break;
				case OC0_PRESCALER_8:
					THREE_BITS_WRITE(TCCR0,CS00,OC0_PRESCALER_8);
					break;
				case OC0_PRESCALER_64:
					THREE_BITS_WRITE(TCCR0,CS00,OC0_PRESCALER_64);
					break;
				case OC0_PRESCALER_256:
					THREE_BITS_WRITE(TCCR0,CS00,OC0_PRESCALER_256);
					break;
				case OC0_PRESCALER_1024:
					THREE_BITS_WRITE(TCCR0,CS00,OC0_PRESCALER_1024);
					break;
				default:
					break;
			}
			break;
		case OC1A_CHANNEL:
		case OC1B_CHANNEL:
			switch(OC1_prescaler)
			{
				case OC1_PRESCALER_1:
					THREE_BITS_WRITE(TCCR1B,CS10,OC1_PRESCALER_1);
					break;
				case OC1_PRESCALER_8:
					THREE_BITS_WRITE(TCCR1B,CS10,OC1_PRESCALER_8);
					break;
				case OC1_PRESCALER_64:
					THREE_BITS_WRITE(TCCR1B,CS10,OC1_PRESCALER_64);
					break;
				case OC1_PRESCALER_256:
					THREE_BITS_WRITE(TCCR1B,CS10,OC1_PRESCALER_256);
					break;
				case OC1_PRESCALER_1024:
					THREE_BITS_WRITE(TCCR1B,CS10,OC1_PRESCALER_1024);
					break;
				default:
					break;
			}
			break;
		case OC2_CHANNEL:
			switch(OC2_prescaler)
			{
				case OC2_PRESCALER_1:
					THREE_BITS_WRITE(TCCR2,CS20,OC2_PRESCALER_1);
					break;
				case OC2_PRESCALER_8:
					THREE_BITS_WRITE(TCCR2,CS20,OC2_PRESCALER_8);
					break;
				case OC2_PRESCALER_32:
					THREE_BITS_WRITE(TCCR2,CS20,OC2_PRESCALER_32);
					break;
				case OC2_PRESCALER_64:
					THREE_BITS_WRITE(TCCR2,CS20,OC2_PRESCALER_64);
					break;
				case OC2_PRESCALER_128:
					THREE_BITS_WRITE(TCCR2,CS20,OC2_PRESCALER_128);
					break;
				case OC2_PRESCALER_256:
					THREE_BITS_WRITE(TCCR2,CS20,OC2_PRESCALER_256);
					break;
				case OC2_PRESCALER_1024:
					THREE_BITS_WRITE(TCCR2,CS20,OC2_PRESCALER_1024);
					break;
				default:
					break;
			}
			break;
		default:
			break;
	}
 }
void PWM_Stop(uint8_t channel)
{
	 switch(channel)
	 {
		 case OC0_CHANNEL:
			 THREE_BITS_WRITE(TCCR0,CS00,OC0_NO_CLK);
			 break;
		 case OC1A_CHANNEL:
		 case OC1B_CHANNEL:
			 THREE_BITS_WRITE(TCCR1B,CS10,OC1_NO_CLK);
			 break;
		 case OC2_CHANNEL:
			 THREE_BITS_WRITE(TCCR2,CS20,OC2_NO_CLK);
			 break;
		 default:
			break;
	 }
 } 
void PWM_ChangePWMProperties(uint8_t channel,uint8_t connection_mode,float32_t duty_cycle)
 {
	 uint16_t temp_prescaler = 1;
	 switch(OC1_prescaler)
	 {
		 case OC1_PRESCALER_1:
			 temp_prescaler = 1;
			 break;
		 case OC1_PRESCALER_8:
			 temp_prescaler = 8;
			 break;
		 case OC1_PRESCALER_64:
			 temp_prescaler = 64;
			 break;
		 case OC1_PRESCALER_256:
			 temp_prescaler = 256;
			 break;
		 case OC1_PRESCALER_1024:
			 temp_prescaler = 1024;
			 break;
		 default:
			 break;
	 }
	 switch(channel)
	 {
		 case OC0_CHANNEL:
			 TWO_BITS_WRITE(TCCR0,COM00,connection_mode);
			 switch(OC0_PWM_mode)
			 {
				 case OC0_PHASE_CORRECT_PWM:
					 switch(connection_mode)
					 {
						 case NON_INVERTING:
							 OCR0 = (uint8_t)(((duty_cycle/100.0)*255.0));
							 break;
						 case INVERTING:
							 OCR0 = (uint8_t)(255-((duty_cycle/100.0)*255.0));
							 break;
						 default:
							 break;
					 }
					 break;
				 case OC0_FAST_PWM:
					 switch(connection_mode)
					 {
						 case NON_INVERTING:
							 OCR0 = (uint8_t)(((duty_cycle/100.0)*256.0)-1);
							 break;
						 case INVERTING:
							 OCR0 = (uint8_t)(255-((duty_cycle/100.0)*256.0));
							 break;
						 default:
							 break;
					 }
					 break;
				 default:
					 break;
			 }
			 break;
		 case OC1A_CHANNEL:
			 TWO_BITS_WRITE(TCCR1A,COM1A0,connection_mode);
			 switch(OC1A_PWM_mode)
			 {
				 case OC1_PHASE_CORRECT_8_BITS:
					 switch(connection_mode)
					 {
						 case NON_INVERTING:
							 OCR1A = (uint16_t)(((duty_cycle/100.0)*255.0));
							 break;
						 case INVERTING:
							 OCR1A = (uint16_t)(255-((duty_cycle/100.0)*255.0));
							 break;
						 default:
							 break;
					 }
					 break;
				 case OC1_PHASE_CORRECT_9_BITS:
					 switch(connection_mode)
					 {
						 case NON_INVERTING:
							 OCR1A = (uint16_t)(((duty_cycle/100.0)*511.0));
							 break;
						 case INVERTING:
							 OCR1A = (uint16_t)(511-((duty_cycle/100.0)*511.0));
							 break;
						 default:
							 break;
					 }
					 break;
				 case OC1_PHASE_CORRECT_10_BITS:
					 switch(connection_mode)
					 {
						 case NON_INVERTING:
							 OCR1A = (uint16_t)(((duty_cycle/100.0)*1023.0));
							 break;
						 case INVERTING:
							 OCR1A = (uint16_t)(1023-((duty_cycle/100.0)*1023.0));
							 break;
						 default:
							 break;
					 }
					 break;
				 case OC1_FAST_PWM_8_BITS:;
					 switch(connection_mode)
					 {
						 case NON_INVERTING:
							 OCR1A = (uint16_t)(((duty_cycle/100.0)*256.0)-1);
							 break;
						 case INVERTING:
							 OCR1A = (uint16_t)(255-((duty_cycle/100.0)*256.0));
							 break;
						 default:
							 break;
					 }
					 break;
				 case OC1_FAST_PWM_9_BITS:
					 switch(connection_mode)
					 {
						 case NON_INVERTING:
							 OCR1A = (uint16_t)(((duty_cycle/100.0)*512.0)-1);
							 break;
						 case INVERTING:
							 OCR1A = (uint16_t)(511-((duty_cycle/100.0)*512.0));
							 break;
						 default:
							 break;
					 }
					 break;
				 case OC1_FAST_PWM_10_BITS:
					 switch(connection_mode)
					 {
						 case NON_INVERTING:
							 OCR1A = (uint16_t)(((duty_cycle/100.0)*1024.0)-1);
							 break;
						 case INVERTING:
							 OCR1A = (uint16_t)(1023-((duty_cycle/100.0)*1024.0));
							 break;
						 default:
							 break;
					 }
					 break;
				 case OC1_PHASE_FREQUENCY_CORRECT_ICR1:
					 ICR1 = (uint16_t)(F_CPU/(OC1A_frequency * 2.0 * temp_prescaler));
					 switch(connection_mode)
					 {
						 case NON_INVERTING:
							 OCR1A = (uint16_t)(((duty_cycle/100.0)*ICR1));
							 break;
						 case INVERTING:
							 OCR1A = (uint16_t)(ICR1-(uint16_t)((duty_cycle/100.0)*ICR1));
							 break;
						 default:
							 break;
					 }
					 break;
				 case OC1_PHASE_CORRECT_ICR1:
					 ICR1 = (uint16_t)(F_CPU/(OC1A_frequency * 2.0 * temp_prescaler));
					 switch(connection_mode)
					 {
						 case NON_INVERTING:
							 OCR1A = (uint16_t)(((duty_cycle/100.0)*ICR1));
							 break;
						 case INVERTING:
							 OCR1A = (uint16_t)(ICR1-(uint16_t)((duty_cycle/100.0)*ICR1));
							 break;
						 default:
							 break;
					 }
					 break;
				 case OC1_FAST_PWM_ICR1:
					 ICR1 = (uint16_t)(F_CPU/((float32_t)(OC1A_frequency * temp_prescaler))-1);
					 switch(connection_mode)
					 {
						 case NON_INVERTING:
							 OCR1A = (uint16_t)(((duty_cycle/100.0)*(ICR1+1))-1);
							 break;
						 case INVERTING:
							 OCR1A = (uint16_t)(ICR1-(uint16_t)((duty_cycle/100.0)*(ICR1+1)));
							 break;
						 default:
							break;
					 }
					 break;
				 default:
					break;
			 }
			 break;
		 case OC1B_CHANNEL:
			 TWO_BITS_WRITE(TCCR1A,COM1B0,connection_mode);
			 switch(OC1B_PWM_mode)
			 {
				 case OC1_PHASE_CORRECT_8_BITS:
					 switch(connection_mode)
					 {
						 case NON_INVERTING:
							 OCR1B = (uint16_t)(((duty_cycle/100.0)*255.0));
							 break;
						 case INVERTING:
							 OCR1B = (uint16_t)(255-((duty_cycle/100.0)*255.0));
							 break;
						 default:
							 break;
					 }
					 break;
				 case OC1_PHASE_CORRECT_9_BITS:
					 switch(connection_mode)
					 {
						 case NON_INVERTING:
							 OCR1B = (uint16_t)(((duty_cycle/100.0)*511.0));
							 break;
						 case INVERTING:
							 OCR1B = (uint16_t)(511-((duty_cycle/100.0)*511.0));
							 break;
						 default:
							 break;
					 }
					 break;
				 case OC1_PHASE_CORRECT_10_BITS:
					 switch(connection_mode)
					 {
						 case NON_INVERTING:
							 OCR1B = (uint16_t)(((duty_cycle/100.0)*1023.0));
							 break;
						 case INVERTING:
							 OCR1B = (uint16_t)(1023-((duty_cycle/100.0)*1023.0));
							 break;
						 default:
							 break;
					 }
					 break;
				 case OC1_FAST_PWM_8_BITS:
					 switch(connection_mode)
					 {
						 case NON_INVERTING:
							 OCR1B = (uint16_t)(((duty_cycle/100.0)*256.0)-1);
							 break;
						 case INVERTING:
							 OCR1B = (uint16_t)(255-((duty_cycle/100.0)*256.0));
							 break;
						 default:
							 break;
					 }
					 break;
				 case OC1_FAST_PWM_9_BITS:
					 switch(connection_mode)
					 {
						 case NON_INVERTING:
							 OCR1B = (uint16_t)(((duty_cycle/100.0)*512.0)-1);
							 break;
						 case INVERTING:
							 OCR1B = (uint16_t)(511-((duty_cycle/100.0)*512.0));
							 break;
						 default:
							 break;
					 }
					 break;
				 case OC1_FAST_PWM_10_BITS:
					 switch(connection_mode)
					 {
						 case NON_INVERTING:
							 OCR1B = (uint16_t)(((duty_cycle/100.0)*1024.0)-1);
							 break;
						 case INVERTING:
							 OCR1B = (uint16_t)(1023-((duty_cycle/100.0)*1024.0));
							 break;
						 default:
							 break;
					 }
					 break;
				 case OC1_PHASE_FREQUENCY_CORRECT_ICR1:
					 ICR1 = (uint16_t)(F_CPU/(OC1B_frequency * 2.0 * temp_prescaler));
					 switch(connection_mode)
					 {
						 case NON_INVERTING:
							 OCR1B = (uint16_t)(((duty_cycle/100.0)*ICR1));
							 break;
						 case INVERTING:
							 OCR1B = (uint16_t)(ICR1-(uint16_t)((duty_cycle/100.0)*ICR1));
							 break;
						 default:
							 break;
					 }
					 break;
				 case OC1_PHASE_FREQUENCY_CORRECT_OCR1A:
					 OCR1A = (uint16_t)(F_CPU/(OC1B_frequency * 2.0 * temp_prescaler));
					 switch(connection_mode)
					 {
						 case NON_INVERTING:
							 OCR1B = (uint16_t)(((duty_cycle/100.0)*OCR1A));
							 break;
						 case INVERTING:
							 OCR1B = (uint16_t)(OCR1A-(uint16_t)((duty_cycle/100.0)*OCR1A));
							 break;
						 default:
							 break;
					 }
					 break;
				 case OC1_PHASE_CORRECT_ICR1:
					 ICR1 = (uint16_t)(F_CPU/(OC1B_frequency * 2.0 * temp_prescaler));
					 switch(connection_mode)
					 {
						 case NON_INVERTING:
							 OCR1B = (uint16_t)(((duty_cycle/100.0)*ICR1));
							 break;
						 case INVERTING:
							 OCR1B = (uint16_t)(ICR1-(uint16_t)((duty_cycle/100.0)*ICR1));
							 break;
						 default:
							 break;
					 }
					 break;
				 case OC1_PHASE_CORRECT_OCR1A:
					 OCR1A = (uint16_t)(F_CPU/(OC1B_frequency * 2.0 * temp_prescaler));
					 switch(connection_mode)
					 {
						 case NON_INVERTING:
							 OCR1B = (uint16_t)(((duty_cycle/100.0)*OCR1A));
							 break;
						 case INVERTING:
							 OCR1B = (uint16_t)(OCR1A-(uint16_t)((duty_cycle/100.0)*OCR1A));
							 break;
						 default:
							 break;
					 }
					 break;
				 case OC1_FAST_PWM_ICR1:
					 ICR1 = (uint16_t)(F_CPU/((float32_t)(OC1B_frequency * temp_prescaler))-1);
					 switch(connection_mode)
					 {
						 case NON_INVERTING:
							 OCR1B = (uint16_t)(((duty_cycle/100.0)*(ICR1+1))-1);
							 break;
						 case INVERTING:
							 OCR1B = (uint16_t)(ICR1-(uint16_t)((duty_cycle/100.0)*(ICR1+1)));
							 break;
						 default:
							 break;
					 }
					 break;
				 case OC1_FAST_PWM_OCR1A:
					 OCR1A = (uint16_t)(F_CPU/((float32_t)(OC1B_frequency * temp_prescaler))-1);
					 switch(connection_mode)
					 {
						 case NON_INVERTING:
							 OCR1B = (uint16_t)(((duty_cycle/100.0)*(OCR1A+1))-1);
							 break;
						 case INVERTING:
							 OCR1B = (uint16_t)(OCR1A-(uint16_t)((duty_cycle/100.0)*(OCR1A+1)));
							 break;
						 default:
							 break;
					 }
					 break;			 
				 default:
					 break;
			 }
			 break;
		 case OC2_CHANNEL:
			 TWO_BITS_WRITE(TCCR2,COM20,connection_mode);
			 switch(OC2_PWM_mode)
			 {
				 case OC2_PHASE_CORRECT_PWM:
					 switch(connection_mode)
					 {
						 case NON_INVERTING:
							 OCR2 = (uint8_t)(((duty_cycle/100.0)*255.0));
							 break;
						 case INVERTING:
							 OCR2 = (uint8_t)(255-((duty_cycle/100.0)*255.0));
							 break;
						 default:
							 break;
					 }
					 break;
				 case OC2_FAST_PWM:
					 switch(connection_mode)
					 {
						 case NON_INVERTING:
							 OCR2 = (uint8_t)(((duty_cycle/100.0)*256.0)-1);
							 break;
						 case INVERTING:
							 OCR2 = (uint8_t)(255-((duty_cycle/100.0)*256.0));
							 break;
						 default:
							 break;
					 }
					 break;
				 default:
					 break;
			 }
			 break;
		 default:
			break;
	 }
 }
 
 
 

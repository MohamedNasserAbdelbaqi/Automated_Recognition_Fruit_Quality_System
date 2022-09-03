/*
 * ADC.c
 * Created: 11/21/2021 8:18:58 pm
 * Author: Mohamed Nasser
 */ 

#include <avr/io.h>
#include "ADC.h"


error_state_t ADC_Init(uint8_t channel,uint8_t prescaler)
{
	error_state_t error_state = ERROR_OK;
	//by default
	//right adjustment
	CLR_BIT(ADMUX,ADLAR);
	//AREF = AVCC
	SET_BIT(ADMUX,REFS0);
	CLR_BIT(ADMUX,REFS1);

	switch(channel)
	{
		case ADC0:
			//set ADC0 channel as input pin
			CLR_BIT(DDRA,PA0);
			
			CLR_BIT(ADMUX,MUX0);
			CLR_BIT(ADMUX,MUX1);
			CLR_BIT(ADMUX,MUX2);
			CLR_BIT(ADMUX,MUX3);
			CLR_BIT(ADMUX,MUX4);
			break;
		case ADC1:
			//set ADC1 channel as input pin
			CLR_BIT(DDRA,PA1);
			
			SET_BIT(ADMUX,MUX0);
			CLR_BIT(ADMUX,MUX1);
			CLR_BIT(ADMUX,MUX2);
			CLR_BIT(ADMUX,MUX3);
			CLR_BIT(ADMUX,MUX4);
			break;
		case ADC2:
			//set ADC2 channel as input pin
			CLR_BIT(DDRA,PA2);
			
			CLR_BIT(ADMUX,MUX0);
			SET_BIT(ADMUX,MUX1);
			CLR_BIT(ADMUX,MUX2);
			CLR_BIT(ADMUX,MUX3);
			CLR_BIT(ADMUX,MUX4);
			break;
		case ADC3:
			//set ADC3 channel as input pin
			CLR_BIT(DDRA,PA3);
			
			SET_BIT(ADMUX,MUX0);
			SET_BIT(ADMUX,MUX1);
			CLR_BIT(ADMUX,MUX2);
			CLR_BIT(ADMUX,MUX3);
			CLR_BIT(ADMUX,MUX4);
			break;
		case ADC4:
			//set ADC4 channel as input pin
			CLR_BIT(DDRA,PA4);
			
			CLR_BIT(ADMUX,MUX0);
			CLR_BIT(ADMUX,MUX1);
			SET_BIT(ADMUX,MUX2);
			CLR_BIT(ADMUX,MUX3);
			CLR_BIT(ADMUX,MUX4);
			break;
		case ADC5:
			//set ADC5 channel as input pin
			CLR_BIT(DDRA,PA5);
			
			SET_BIT(ADMUX,MUX0);
			CLR_BIT(ADMUX,MUX1);
			SET_BIT(ADMUX,MUX2);
			CLR_BIT(ADMUX,MUX3);
			CLR_BIT(ADMUX,MUX4);
			break;
		case ADC6:
			//set ADC6 channel as input pin
			CLR_BIT(DDRA,PA6);
			
			CLR_BIT(ADMUX,MUX0);
			SET_BIT(ADMUX,MUX1);
			SET_BIT(ADMUX,MUX2);
			CLR_BIT(ADMUX,MUX3);
			CLR_BIT(ADMUX,MUX4);
			break;
		case ADC7:
			//set ADC7 channel as input pin
			CLR_BIT(DDRA,PA7);
			
			SET_BIT(ADMUX,MUX0);
			SET_BIT(ADMUX,MUX1);
			SET_BIT(ADMUX,MUX2);
			CLR_BIT(ADMUX,MUX3);
			CLR_BIT(ADMUX,MUX4);
			break;
		case DIFFERENIAL_MODE_ADC0_ADC0_x10:
			//set ADC0 channel as input pin
			CLR_BIT(DDRA,PA0);
			
			CLR_BIT(ADMUX,MUX0);
			CLR_BIT(ADMUX,MUX1);
			CLR_BIT(ADMUX,MUX2);
			SET_BIT(ADMUX,MUX3);
			CLR_BIT(ADMUX,MUX4);
			break;
		case DIFFERENIAL_MODE_ADC1_ADC0_x10:
			//set ADC1 & ADC0 channel as input pin
			CLR_BIT(DDRA,PA0);
			CLR_BIT(DDRA,PA1);
		
			SET_BIT(ADMUX,MUX0);
			CLR_BIT(ADMUX,MUX1);
			CLR_BIT(ADMUX,MUX2);
			SET_BIT(ADMUX,MUX3);
			CLR_BIT(ADMUX,MUX4);
			break;
		case DIFFERENIAL_MODE_ADC0_ADC0_x200:
			//set ADC0 channel as input pin
			CLR_BIT(DDRA,PA0);
		
			CLR_BIT(ADMUX,MUX0);
			SET_BIT(ADMUX,MUX1);
			CLR_BIT(ADMUX,MUX2);
			SET_BIT(ADMUX,MUX3);
			CLR_BIT(ADMUX,MUX4);
			break;
		case DIFFERENIAL_MODE_ADC1_ADC0_x200:
			//set ADC1 & ADC0 channel as input pin
			CLR_BIT(DDRA,PA0);
			CLR_BIT(DDRA,PA1);
		
			SET_BIT(ADMUX,MUX0);
			SET_BIT(ADMUX,MUX1);
			CLR_BIT(ADMUX,MUX2);
			SET_BIT(ADMUX,MUX3);
			CLR_BIT(ADMUX,MUX4);
			break;
		case DIFFERENIAL_MODE_ADC2_ADC2_x10:
			//set ADC2 channel as input pin
			CLR_BIT(DDRA,PA2);
			
			CLR_BIT(ADMUX,MUX0);
			CLR_BIT(ADMUX,MUX1);
			SET_BIT(ADMUX,MUX2);
			SET_BIT(ADMUX,MUX3);
			CLR_BIT(ADMUX,MUX4);
			break;
		case DIFFERENIAL_MODE_ADC3_ADC2_x10:
			//set ADC3 & ADC2 channel as input pin
			CLR_BIT(DDRA,PA2);
			CLR_BIT(DDRA,PA3);
			
			SET_BIT(ADMUX,MUX0);
			CLR_BIT(ADMUX,MUX1);
			SET_BIT(ADMUX,MUX2);
			SET_BIT(ADMUX,MUX3);
			CLR_BIT(ADMUX,MUX4);
			break;
		case DIFFERENIAL_MODE_ADC2_ADC2_x200:
			//set ADC2 channel as input pin
			CLR_BIT(DDRA,PA2);
			
			CLR_BIT(ADMUX,MUX0);
			SET_BIT(ADMUX,MUX1);
			SET_BIT(ADMUX,MUX2);
			SET_BIT(ADMUX,MUX3);
			CLR_BIT(ADMUX,MUX4);
			break;
		case DIFFERENIAL_MODE_ADC3_ADC2_x200:
			//set ADC3 & ADC2 channel as input pin
			CLR_BIT(DDRA,PA2);
			CLR_BIT(DDRA,PA3);
			
			SET_BIT(ADMUX,MUX0);
			SET_BIT(ADMUX,MUX1);
			SET_BIT(ADMUX,MUX2);
			SET_BIT(ADMUX,MUX3);
			CLR_BIT(ADMUX,MUX4);
			break;
		case DIFFERENIAL_MODE_ADC0_ADC1_x1:
			//set ADC0 & ADC1 channel as input pin
			CLR_BIT(DDRA,PA0);
			CLR_BIT(DDRA,PA1);
			
			CLR_BIT(ADMUX,MUX0);
			CLR_BIT(ADMUX,MUX1);
			CLR_BIT(ADMUX,MUX2);
			CLR_BIT(ADMUX,MUX3);
			SET_BIT(ADMUX,MUX4);
			break;
		case DIFFERENIAL_MODE_ADC1_ADC1_x1:
			//set ADC1 channel as input pin
			CLR_BIT(DDRA,PA1);
		
			SET_BIT(ADMUX,MUX0);
			CLR_BIT(ADMUX,MUX1);
			CLR_BIT(ADMUX,MUX2);
			CLR_BIT(ADMUX,MUX3);
			SET_BIT(ADMUX,MUX4);
			break;
		case DIFFERENIAL_MODE_ADC2_ADC1_x1:
			//set ADC1 channel as input pin
			CLR_BIT(DDRA,PA1);
			CLR_BIT(DDRA,PA2);
			
			CLR_BIT(ADMUX,MUX0);
			SET_BIT(ADMUX,MUX1);
			CLR_BIT(ADMUX,MUX2);
			CLR_BIT(ADMUX,MUX3);
			SET_BIT(ADMUX,MUX4);
			break;
		case DIFFERENIAL_MODE_ADC3_ADC1_x1:
			//set ADC3 & ADC1 channel as input pin
			CLR_BIT(DDRA,PA1);
			CLR_BIT(DDRA,PA3);
		
			SET_BIT(ADMUX,MUX0);
			SET_BIT(ADMUX,MUX1);
			CLR_BIT(ADMUX,MUX2);
			CLR_BIT(ADMUX,MUX3);
			SET_BIT(ADMUX,MUX4);
			break;
		case DIFFERENIAL_MODE_ADC4_ADC1_x1:
			//set ADC4 & ADC1 channel as input pin
			CLR_BIT(DDRA,PA1);
			CLR_BIT(DDRA,PA4);
		
			CLR_BIT(ADMUX,MUX0);
			CLR_BIT(ADMUX,MUX1);
			SET_BIT(ADMUX,MUX2);
			CLR_BIT(ADMUX,MUX3);
			SET_BIT(ADMUX,MUX4);
			break;
		case DIFFERENIAL_MODE_ADC5_ADC1_x1:
			//set ADC5 & ADC1 channel as input pin
			CLR_BIT(DDRA,PA1);
			CLR_BIT(DDRA,PA5);
		
			SET_BIT(ADMUX,MUX0);
			CLR_BIT(ADMUX,MUX1);
			SET_BIT(ADMUX,MUX2);
			CLR_BIT(ADMUX,MUX3);
			SET_BIT(ADMUX,MUX4);
			break;
		case DIFFERENIAL_MODE_ADC6_ADC1_x1:
			//set ADC6 & ADC1 channel as input pin
			CLR_BIT(DDRA,PA1);
			CLR_BIT(DDRA,PA6);
		
			CLR_BIT(ADMUX,MUX0);
			SET_BIT(ADMUX,MUX1);
			SET_BIT(ADMUX,MUX2);
			CLR_BIT(ADMUX,MUX3);
			SET_BIT(ADMUX,MUX4);
			break;
		case DIFFERENIAL_MODE_ADC7_ADC1_x1:
			//set ADC7 & ADC1 channel as input pin
			CLR_BIT(DDRA,PA1);
			CLR_BIT(DDRA,PA7);
		
			SET_BIT(ADMUX,MUX0);
			SET_BIT(ADMUX,MUX1);
			SET_BIT(ADMUX,MUX2);
			CLR_BIT(ADMUX,MUX3);
			SET_BIT(ADMUX,MUX4);
			break;
		case DIFFERENIAL_MODE_ADC0_ADC2_x1:
			//set ADC0 & ADC2 channel as input pin
			CLR_BIT(DDRA,PA0);
			CLR_BIT(DDRA,PA2);
		
			CLR_BIT(ADMUX,MUX0);
			CLR_BIT(ADMUX,MUX1);
			CLR_BIT(ADMUX,MUX2);
			SET_BIT(ADMUX,MUX3);
			SET_BIT(ADMUX,MUX4);
			break;
		case DIFFERENIAL_MODE_ADC1_ADC2_x1:
			//set ADC1 & ADC2 channel as input pin
			CLR_BIT(DDRA,PA1);
			CLR_BIT(DDRA,PA2);
		
			SET_BIT(ADMUX,MUX0);
			CLR_BIT(ADMUX,MUX1);
			CLR_BIT(ADMUX,MUX2);
			SET_BIT(ADMUX,MUX3);
			SET_BIT(ADMUX,MUX4);
			break;
		case DIFFERENIAL_MODE_ADC2_ADC2_x1:
			//set ADC2 channel as input pin
			CLR_BIT(DDRA,PA2);
		
			CLR_BIT(ADMUX,MUX0);
			SET_BIT(ADMUX,MUX1);
			CLR_BIT(ADMUX,MUX2);
			SET_BIT(ADMUX,MUX3);
			SET_BIT(ADMUX,MUX4);
			break;
		case DIFFERENIAL_MODE_ADC3_ADC2_x1:
			//set ADC3 & ADC2 channel as input pin
			CLR_BIT(DDRA,PA2);
			CLR_BIT(DDRA,PA3);
		
			SET_BIT(ADMUX,MUX0);
			SET_BIT(ADMUX,MUX1);
			CLR_BIT(ADMUX,MUX2);
			SET_BIT(ADMUX,MUX3);
			SET_BIT(ADMUX,MUX4);
			break;
		case DIFFERENIAL_MODE_ADC4_ADC2_x1:
			//set ADC4 & ADC2 channel as input pin
			CLR_BIT(DDRA,PA2);
			CLR_BIT(DDRA,PA4);
		
			CLR_BIT(ADMUX,MUX0);
			CLR_BIT(ADMUX,MUX1);
			SET_BIT(ADMUX,MUX2);
			SET_BIT(ADMUX,MUX3);
			SET_BIT(ADMUX,MUX4);
			break;
		case DIFFERENIAL_MODE_ADC5_ADC2_x1:
			//set ADC5 & ADC2 channel as input pin
			CLR_BIT(DDRA,PA2);
			CLR_BIT(DDRA,PA5);
		
			SET_BIT(ADMUX,MUX0);
			CLR_BIT(ADMUX,MUX1);
			SET_BIT(ADMUX,MUX2);
			SET_BIT(ADMUX,MUX3);
			SET_BIT(ADMUX,MUX4);
			break;
		case VBG_1_22:
			CLR_BIT(ADMUX,MUX0);
			SET_BIT(ADMUX,MUX1);
			SET_BIT(ADMUX,MUX2);
			SET_BIT(ADMUX,MUX3);
			SET_BIT(ADMUX,MUX4);
			break;
		case GND:
			SET_BIT(ADMUX,MUX0);
			SET_BIT(ADMUX,MUX1);
			SET_BIT(ADMUX,MUX2);
			SET_BIT(ADMUX,MUX3);
			SET_BIT(ADMUX,MUX4);
			break;
		default:
			error_state = ADC_ERROR_INVALID_CHANNEL;
			break;
	}
	
	switch(prescaler)
	{
		case _2_DIVISION_FACTOR:
			CLR_BIT(ADCSRA ,ADPS0);
			CLR_BIT(ADCSRA ,ADPS1);
			CLR_BIT(ADCSRA ,ADPS2);
			break;
		case _4_DIVISION_FACTOR:
			CLR_BIT(ADCSRA ,ADPS0);
			SET_BIT(ADCSRA ,ADPS1);
			CLR_BIT(ADCSRA ,ADPS2);
			break;
		case _8_DIVISION_FACTOR:
			SET_BIT(ADCSRA ,ADPS0);
			SET_BIT(ADCSRA ,ADPS1);
			CLR_BIT(ADCSRA ,ADPS2);
			break;
		case _16_DIVISION_FACTOR:
			CLR_BIT(ADCSRA ,ADPS0);
			CLR_BIT(ADCSRA ,ADPS1);
			SET_BIT(ADCSRA ,ADPS2);
			break;
		case _32_DIVISION_FACTOR:
			SET_BIT(ADCSRA ,ADPS0);
			CLR_BIT(ADCSRA ,ADPS1);
			SET_BIT(ADCSRA ,ADPS2);
			break;
		case _64_DIVISION_FACTOR:
			CLR_BIT(ADCSRA ,ADPS0);
			SET_BIT(ADCSRA ,ADPS1);
			SET_BIT(ADCSRA ,ADPS2);
			break;
		case _128_DIVISION_FACTOR:
			SET_BIT(ADCSRA ,ADPS0);
			SET_BIT(ADCSRA ,ADPS1);
			SET_BIT(ADCSRA ,ADPS2);
			break;
		default:
			error_state = ADC_ERROR_INVALID_PRESCALER;
			break;
	}
	//disable ADC interrupt
	CLR_BIT(ADCSRA,ADIE);
	//disable auto trigger mode
	CLR_BIT(ADCSRA,ADATE);	
	//enable ADC
	SET_BIT(ADCSRA,ADEN);
	return error_state;
}
error_state_t ADC_SetReferenceVoltage(uint8_t reference_voltage)
{
	error_state_t error_state = ERROR_OK;
	switch(reference_voltage)
	{
		case AREF:
			CLR_BIT(ADMUX,REFS0);
			CLR_BIT(ADMUX,REFS1);
			break;
		case AVCC:                  //default option
			SET_BIT(ADMUX,REFS0);
			CLR_BIT(ADMUX,REFS1);
			break;
		case INTERNAL:			    //INTERNAL = 2.56 volt
			SET_BIT(ADMUX,REFS0);
			SET_BIT(ADMUX,REFS1);
			break;
		default:
			error_state = ADC_ERROR_INVALID_REFERENCE_VOLTAGE;
			break;
	}
	return error_state;
}	
error_state_t ADC_SetResultAdjustment(uint8_t result_adjustment)
{
	error_state_t error_state = ERROR_OK;
	switch(result_adjustment)
	{
		case RIGHT_ADJUSTMENT:					//default option
			CLR_BIT(ADMUX,ADLAR);
			break;
		case LEFT_ADJUSTMENT:
			SET_BIT(ADMUX,ADLAR);
			break;
		default:
			error_state = ADC_ERROR_INVALID_RESULT_ADJUSTMENT;
			break;
	}
	return error_state;
}
unsigned short ADC_ReadResult(void)
{
	uint16_t adc_reading = 0x0000;
	//start conversion
	SET_BIT(ADCSRA,ADSC);
	//wait for completeness of conversion
	while(READ_BIT(ADCSRA,ADIF) == 0);
	//clear ADC flag
	SET_BIT(ADCSRA,ADIF);
	//read ADC register
	if(READ_BIT(ADMUX,ADLAR) == 0)
	{
		adc_reading = ADC;
	}
	else
	{
		adc_reading = ADC>>6;
	}
	//return ADC reading
	return adc_reading;
}
void ADC_EnableInterrupt(void)
{
	SET_BIT(ADCSRA,ADIE);
}
void ADC_DisableInterrupt(void)
{
	CLR_BIT(ADCSRA,ADIE);
}

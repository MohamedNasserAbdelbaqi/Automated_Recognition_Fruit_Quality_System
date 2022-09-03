/*
 * ADC.h
 * Created: 11/21/2021 8:19:16 pm
 * Author: MohamedNnasser
 */ 


#ifndef ADC_H_
#define ADC_H_

/* file includes */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* ADC channels (MUX output) */
#define ADC0                                   0
#define ADC1                                   1
#define ADC2                                   2
#define ADC3                                   3
#define ADC4                                   4
#define ADC5                                   5
#define ADC6                                   6
#define ADC7                                   7
#define DIFFERENIAL_MODE_ADC0_ADC0_x10         8
#define DIFFERENIAL_MODE_ADC1_ADC0_x10         9
#define DIFFERENIAL_MODE_ADC0_ADC0_x200        10
#define DIFFERENIAL_MODE_ADC1_ADC0_x200        11
#define DIFFERENIAL_MODE_ADC2_ADC2_x10         12
#define DIFFERENIAL_MODE_ADC3_ADC2_x10         13
#define DIFFERENIAL_MODE_ADC2_ADC2_x200        14
#define DIFFERENIAL_MODE_ADC3_ADC2_x200        15
#define DIFFERENIAL_MODE_ADC0_ADC1_x1          16
#define DIFFERENIAL_MODE_ADC1_ADC1_x1          17
#define DIFFERENIAL_MODE_ADC2_ADC1_x1          18
#define DIFFERENIAL_MODE_ADC3_ADC1_x1          19
#define DIFFERENIAL_MODE_ADC4_ADC1_x1          20
#define DIFFERENIAL_MODE_ADC5_ADC1_x1          21
#define DIFFERENIAL_MODE_ADC6_ADC1_x1          22
#define DIFFERENIAL_MODE_ADC7_ADC1_x1          23
#define DIFFERENIAL_MODE_ADC0_ADC2_x1          24
#define DIFFERENIAL_MODE_ADC1_ADC2_x1          25
#define DIFFERENIAL_MODE_ADC2_ADC2_x1          26
#define DIFFERENIAL_MODE_ADC3_ADC2_x1          27
#define DIFFERENIAL_MODE_ADC4_ADC2_x1          28
#define DIFFERENIAL_MODE_ADC5_ADC2_x1          29
#define VBG_1_22                               30
#define GND                                    31	
							       
/* result adjustment */					       
#define RIGHT_ADJUSTMENT                       0
#define LEFT_ADJUSTMENT                        1
							       
/* reference voltage */					       
#define AREF                                   0
#define AVCC                                   1
#define INTERNAL                               2
								       
/* prescaler */							       
#define _2_DIVISION_FACTOR                     0
#define _4_DIVISION_FACTOR                     1
#define _8_DIVISION_FACTOR                     2
#define _16_DIVISION_FACTOR                    3
#define _32_DIVISION_FACTOR                    4
#define _64_DIVISION_FACTOR                    5
#define _128_DIVISION_FACTOR                   6

/* ADC error types */					       
#define ADC_ERROR_INVALID_CHANNEL              15
#define ADC_ERROR_INVALID_PRESCALER            16
#define ADC_ERROR_INVALID_REFERENCE_VOLTAGE    17
#define ADC_ERROR_INVALID_RESULT_ADJUSTMENT    18

/*
recommended prescaler (gives better 10-bit resolution):
    F_CPU	|		prescaler
	---------------------------------------------
	1MHZ	|		16  or 8  (faster conversion)
	2MHZ	|		32  or 16 (faster conversion)
	4MHZ	|		64  or 32 (faster conversion)
	8MHZ	|		128 or 64 (faster conversion)
	---------------------------------------------
*/
error_state_t ADC_Init(uint8_t channel,uint8_t prescaler);
/*	
reference_voltage:
	option		|		description                               |  AVref
	---------------------------------------------------------------------------------
	AREF		|		selectable voltage connected to AREF pin  |	selected voltage		
	AVCC		|		capacitor connected to AREF pin			  |	MC Vcc				
	INTERNAL	|		capacitor connected to AREF pin			  |	2.56 volt
	---------------------------------------------------------------------------------
	note:
	for all option the GND and AVCC pins of ADC connected to MC GND and VCC pins.
*/
error_state_t ADC_SetReferenceVoltage(uint8_t reference_voltage);
error_state_t ADC_SetResultAdjustment(uint8_t result_adjustment);
unsigned short ADC_ReadResult(void);
void ADC_EnableInterrupt(void);
void ADC_DisableInterrupt(void);
#endif /* ADC_H_ */
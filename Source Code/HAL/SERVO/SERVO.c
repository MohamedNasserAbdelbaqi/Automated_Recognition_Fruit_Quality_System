/*
 * SERVO.c
 *
 * Created: 2/27/2022 8:54:54 AM
 * Author: Mohamed Nasser
 */ 

#include "SERVO.h"

/* servo macros */
#define MAX_DEGREE 180

/*
duty cycle equation :
									(2 ms - 1 ms)
				            1 ms  + ------------ * angle
									 MAX_DEGREE                       (MAX_DEGREE + angle) * 5.0
			duty_cycle =   ------------------------------  * 100 %  = ---------------------------
							          20 ms								      MAX_DEGREE
		or
									(2.5 ms - 0.5 ms)
				            0.5 ms + ---------------- * angle
									   MAX_DEGREE                       (0.5 * MAX_DEGREE + 2 * angle) * 5.0
			duty_cycle =   --------------------------------  * 100 %  = -------------------------------------
							           20 ms								     MAX_DEGREE

*/

/* APIs for servo motor */

void SERVO_Init(uint8_t channel,float32_t inial_angle)
{
	float32_t duty_cycle;
	/*duty_cycle = ((MAX_DEGREE+inial_angle)*5.0)/MAX_DEGREE;*///therotical
	/*duty_cycle = ((0.7 * MAX_DEGREE+ 1.9 * inial_angle)*5.0)/MAX_DEGREE;*///the best
	duty_cycle = ((0.388 * MAX_DEGREE + 1.752 * inial_angle)*5.0)/MAX_DEGREE;//the second best
	switch(channel)
	{
		case OC1A_CHANNEL:
			PWM_InitWithVarFreq(OC1A_CHANNEL,OC1_FAST_PWM_ICR1,NON_INVERTING,OC1_PRESCALER_1,50,duty_cycle);
			break;
		case OC1B_CHANNEL:
			PWM_InitWithVarFreq(OC1B_CHANNEL,OC1_FAST_PWM_ICR1,NON_INVERTING,OC1_PRESCALER_1,50,duty_cycle);
			break;
		default:
			break;
	}
	PWM_Start(channel);
	/*_delay_ms(1000);
	PWM_Stop(channel);*/
}
void SERVO_SetAngle(uint8_t channel,float32_t angle)
{
	float32_t duty_cycle;
	/*duty_cycle = ((MAX_DEGREE +angle)*5.0)/MAX_DEGREE;*/
	/*duty_cycle = ((0.7 * MAX_DEGREE + 1.9 * angle)*5.0)/MAX_DEGREE;*/
	duty_cycle = ((0.388 * MAX_DEGREE + 1.752 * angle)*5.0)/MAX_DEGREE;
	switch(channel)
	{
		case OC1A_CHANNEL:
			PWM_ChangePWMProperties(OC1A_CHANNEL,NON_INVERTING,duty_cycle);
			break;
		case OC1B_CHANNEL:
			PWM_ChangePWMProperties(OC1B_CHANNEL,NON_INVERTING,duty_cycle);
			break;
		default:
			break;
	}
	/*PWM_Start(channel);
	_delay_ms(1000);
	PWM_Stop(channel);*/
}



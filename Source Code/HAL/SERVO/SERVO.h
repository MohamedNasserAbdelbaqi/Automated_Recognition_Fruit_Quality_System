/*
 * SERVO.h
 *
 * Created: 2/27/2022 8:54:26 AM
 * Author: Mohamed Nasser
 */ 


#ifndef SERVO_H_
#define SERVO_H_

/* file includes */
#include "PWM.h"
#include <util/delay.h>

/*
important notes:
----------------
- only available channel is OC1A_CHANNEL & OC1B_CHANNEL because there are only support variable frequency.
- for OC1A_CHANNEL , the ICU (input capture unit) is not available because it is used with servo 
  (we use the OC1_FAST_PWM_ICR1 because OC1_FAST_PWM_OCR1A mode is not available with OC1A_CHANNEL).
- for OC1B_CHANNEL , the ICU (input capture unit) is available because we use the OC1_FAST_PWM_OCR1A not OC1_FAST_PWM_ICR1.
*/

/* APIs for servo motor */
void SERVO_Init(uint8_t channel,float32_t inial_angle);
void SERVO_SetAngle(uint8_t channel,float32_t angle);




#endif /* SERVO_H_ */
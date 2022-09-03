/*
 * ROBOT_ARM.h
 *
 * Created: 3/6/2022 4:41:57 PM
 * Author: Mohamed Nasser
 */ 


#ifndef ROBOT_ARM_H_
#define ROBOT_ARM_H_

/* file includes */
#include "SERVO.h"

/* clipper states or angles */
#define CLIPPER_OPEN            110
#define CLIPPER_COMPLETE_CLOSE  180
#define CLIPPER_HALF_CLOSE      145

/* APIs for robot arm */
void ROBOT_ARM_Init(uint8_t port_name,uint8_t bit_number);
void ROBOT_ARM_Move(uint8_t port_name,uint8_t bit_number,float32_t angle_1,float32_t angle_2,float32_t angle_3,float32_t clipper_angel);



#endif /* ROBOT_ARM_H_ */
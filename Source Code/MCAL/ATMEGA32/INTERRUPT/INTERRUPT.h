/*
 * INTERRUPT.h
 * Created: 15/10/2021 10:41:31 pm
 * Author: Mohamed Nasser
 */ 


#ifndef INTERRUPT_H_
#define INTERRUPT_H_

/* file includes */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* global interrupt bit (I) */
#define I                                       7

/* interrupt sense controls */
#define LOW_LEVEL                               0
#define ANY_LOGICAL_CHANGE                      1
#define FALLING_EDGE                            2
#define RISING_EDGE                             3

/* global interrupt status */
#define OFF                                     0
#define ON                                      1

/* interrupt error types */
#define INTERRUPT_ERROR_INVALID_SENSE_CONTROL   15

/* APIs for enable external interrupt */
void INTERRUPT_EnableINT0(void);
void INTERRUPT_EnableINT1(void);
void INTERRUPT_EnableINT2(void);

/* APIs for disable external interrupt */
void INTERRUPT_DisableINT0(void);
void INTERRUPT_DisableINT1(void);
void INTERRUPT_DisableINT2(void);

/* APIs for set external interrupt sense control */
error_state_t INTERRUPT_SetSenceControlINT0(uint8_t interrupt_sense_control);
error_state_t INTERRUPT_SetSenceControlINT1(uint8_t interrupt_sense_control);
error_state_t INTERRUPT_SetSenceControlINT2(uint8_t interrupt_sense_control);

/* APIs for read external interrupt flag */
uint8_t INTERRUPT_ReadINT0Flag(void);
uint8_t INTERRUPT_ReadINT1Flag(void);
uint8_t INTERRUPT_ReadINT2Flag(void);

/* APIs for clear external interrupt flag */
void INTERRUPT_ClearINT0Flag(void);
void INTERRUPT_ClearINT1Flag(void);
void INTERRUPT_ClearINT2Flag(void);

/* APIs for control global interrupt bit */
void INTERRUPT_EnableGlobalINT(void);
void INTERRUPT_DisableGlobalINT(void);
uint8_t INTERRUPT_ReadGlobalINTStatus(void);

/* API for call back functions */

/* interrupt numbers */
#define INTERRUPT_0                             0
#define INTERRUPT_1                             1
#define INTERRUPT_2                             2
typedef void(*ptr_fun_t)(void);
void INTERRUPT_SetCallBackFun(uint8_t interrupt_number,ptr_fun_t rising_falling_call_back_fun,ptr_fun_t rising_call_back_fun,ptr_fun_t falling_call_back_fun);

#endif /* INTERRUPT_H_ */
/*
 * WATCH_DOG.h
 *
 * Created: 2/23/2022 10:25:39 PM
 * Author: Mohamed Nasser
 */ 


#ifndef WATCH_DOG_H_
#define WATCH_DOG_H_

/* file includes */
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "INTERRUPT.h"

/* watch dog timer error types */
#define WATCH_DOG_ERROR_UNDER_RANGE_TIME            15
#define WATCH_DOG_ERROR_OVER_RANGE_TIME             16


/* APIs for watch dog timer */

/* sleeping time range (16.3 : 2100 ms)*/
error_state_t WATCH_DOG_Sleep(float32_t sleeping_time);
void WATCH_DOG_Disable(void);

#endif /* WATCH_DOG_H_ */
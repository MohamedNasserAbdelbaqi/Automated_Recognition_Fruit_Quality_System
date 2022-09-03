/*
 * USART.h
 *
 * Created: 3/22/2022 11:45:19 PM
 *  Author: Mohamed Nasser
 */ 


#ifndef USART_H_
#define USART_H_
/* file includes */
#include <stdint.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* USART modes */
#define ASYNCHRONOUS_NORMAL_MODE        0
#define SYNCHRONOUS_MODE                1
#define ASYNCHRONOUS_DOUBLE_SPEED_MODE  2

/* parity modes */
#define DISABLE_PARITY                  0
#define EVEN_PARITY					    2
#define ODD_PARITY                      3

/* data size */
#define _5_BIT_CHAR                     0 
#define _6_BIT_CHAR                     1
#define _7_BIT_CHAR                     2
#define _8_BIT_CHAR                     3
#define _9_BIT_CHAR                     7

/* stop bit(s) size */
#define ONE_STOP_BIT                    0
#define TWO_STOP_BITS                   1

/* USART error types */
#define DIO_ERROR_PARITY_ERROR          15
#define DIO_ERROR_DATA_OVERRUN_ERROR    16
#define DIO_ERROR_FRAME_ERROR           17

/* APIs for USART */
void USART_InitTransmitter(uint8_t USART_mode,uint8_t char_size,uint8_t parity_mode,uint8_t stop_bit_size,uint32_t baud_rate);
void USART_InitReceiver(uint8_t USART_mode,uint8_t char_size,uint8_t parity_mode,uint8_t stop_bit_size,uint32_t baud_rate);
void USART_Transmit(uint16_t data);
uint16_t USART_Receive(void);
void USART_StopTransmitter(void);
void USART_StopReceiver(void);



#endif /* USART_H_ */
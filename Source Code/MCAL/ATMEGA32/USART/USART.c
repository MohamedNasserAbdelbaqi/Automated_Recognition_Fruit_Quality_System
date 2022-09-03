/*
 * USART.c
 *
 * Created: 3/22/2022 11:45:37 PM
 *  Author: Mohamed Nasser
 */ 
#define F_CPU 2000000UL
#include <avr/io.h>
#include "USART.h"


volatile uint8_t USART_char_size;

/* USART transmit and receive flag states */
#define TRANSMIT_BUFFER_NOT_READY_TO_BE_WRITTEN  0
#define TRANSMIT_BUFFER_READY_TO_BE_WRITTEN      1
#define RECEIVE_BUFFER_DONT_HAVE_UNREAD_DATA     0
#define RECEIVE_BUFFER_HAVE_UNREAD_DATA          1


void USART_InitTransmitter(uint8_t USART_mode,uint8_t char_size,uint8_t parity_mode,uint8_t stop_bit_size,uint32_t baud_rate)
{
	USART_char_size = char_size;
	uint8_t UCSRC_value = 0x00;
	uint16_t UBRR = 0x0000;
	
	/* set URSEL bit to select UCSRC register to access */
	SET_BIT(UCSRC_value,URSEL);
	
	/* configure USART mode */
	switch(USART_mode)
	{
		case ASYNCHRONOUS_NORMAL_MODE:
			CLR_BIT(UCSRC_value,UMSEL);
			CLR_BIT(UCSRA,U2X);
			/* prepare the baud rate */
			UBRR = (F_CPU/(16*baud_rate))-1;
			break;
		case SYNCHRONOUS_MODE:
			SET_BIT(UCSRC_value,UMSEL);
			CLR_BIT(UCSRA,U2X);
			/* set the clock as transmit at rising edge and receive at falling edge */
			CLR_BIT(UCSRC_value,UCPOL);
			/* prepare the baud rate */
			UBRR = (F_CPU/(2*baud_rate))-1;
			break;
		case ASYNCHRONOUS_DOUBLE_SPEED_MODE:
			CLR_BIT(UCSRC_value,UMSEL);
			SET_BIT(UCSRA,U2X);
			/* prepare the baud rate */
			UBRR = (F_CPU/(8*baud_rate))-1;
			break;
		default:
			break;
	}
	
	/* configure parity mode */
	switch(parity_mode)
	{
		case DISABLE_PARITY:
			TWO_BITS_WRITE(UCSRC_value,UPM0,DISABLE_PARITY);
			break;
		case EVEN_PARITY:
			TWO_BITS_WRITE(UCSRC_value,UPM0,EVEN_PARITY);
			break;
		case ODD_PARITY:
			TWO_BITS_WRITE(UCSRC_value,UPM0,ODD_PARITY);
			break;
		default:
			break;
	}
	
	/* configure stop bit size */
	switch(stop_bit_size)
	{
		case ONE_STOP_BIT:
			CLR_BIT(UCSRC_value,USBS);
			break;
		case TWO_STOP_BITS:
			SET_BIT(UCSRC_value,USBS);
			break;
		default:
			break;
	}
	
	/* configure char size */
	switch(char_size)
	{
		case _5_BIT_CHAR:
			TWO_BITS_WRITE(UCSRC_value,UCSZ0,0);
			CLR_BIT(UCSRB,UCSZ2);
			break;
		case _6_BIT_CHAR:
			TWO_BITS_WRITE(UCSRC_value,UCSZ0,1);
			CLR_BIT(UCSRB,UCSZ2);
			break;
		case _7_BIT_CHAR:
			TWO_BITS_WRITE(UCSRC_value,UCSZ0,2);
			CLR_BIT(UCSRB,UCSZ2);
			break;
		case _8_BIT_CHAR:
			TWO_BITS_WRITE(UCSRC_value,UCSZ0,3);
			CLR_BIT(UCSRB,UCSZ2);
			break;
		case _9_BIT_CHAR:
			TWO_BITS_WRITE(UCSRC_value,UCSZ0,3);
			SET_BIT(UCSRB,UCSZ2);
			break;
		default:
			break;
	}
	/* set the baud rate */
	UBRRH = (uint8_t)(UBRR>>REGISTER_SIZE);
	UBRRL = (uint8_t)(UBRR);
	/* assign the UCSRC_value to UCSRC register */
	UCSRC = UCSRC_value;
	/* enable USART transmitter */
	SET_BIT(UCSRB,TXEN);
}
void USART_InitReceiver(uint8_t USART_mode,uint8_t char_size,uint8_t parity_mode,uint8_t stop_bit_size,uint32_t baud_rate)
{
	USART_char_size = char_size;
	uint8_t UCSRC_value = 0x00;
	uint16_t UBRR = 0x0000;
	
	/* set URSEL bit to select UCSRC register to access */
	SET_BIT(UCSRC_value,URSEL);
	
	/* configure USART mode */
	switch(USART_mode)
	{
		case ASYNCHRONOUS_NORMAL_MODE:
			CLR_BIT(UCSRC_value,UMSEL);
			CLR_BIT(UCSRA,U2X);
			/* prepare the baud rate */
			UBRR = (F_CPU/(16*baud_rate))-1;
			break;
		case SYNCHRONOUS_MODE:
			SET_BIT(UCSRC_value,UMSEL);
			CLR_BIT(UCSRA,U2X);
			/* set the clock as transmit at rising edge and receive at falling edge */
			CLR_BIT(UCSRC_value,UCPOL);
			/* prepare the baud rate */
			UBRR = (F_CPU/(2*baud_rate))-1;
			break;
		case ASYNCHRONOUS_DOUBLE_SPEED_MODE:
			CLR_BIT(UCSRC_value,UMSEL);
			SET_BIT(UCSRA,U2X);
			/* prepare the baud rate */
			UBRR = (F_CPU/(8*baud_rate))-1;
			break;
		default:
			break;
	}
	
	/* configure parity mode */
	switch(parity_mode)
	{
		case DISABLE_PARITY:
			TWO_BITS_WRITE(UCSRC_value,UPM0,DISABLE_PARITY);
			break;
		case EVEN_PARITY:
			TWO_BITS_WRITE(UCSRC_value,UPM0,EVEN_PARITY);
			break;
		case ODD_PARITY:
			TWO_BITS_WRITE(UCSRC_value,UPM0,ODD_PARITY);
			break;
		default:
			break;
	}
	
	/* configure stop bit size */
	switch(stop_bit_size)
	{
		case ONE_STOP_BIT:
			CLR_BIT(UCSRC_value,USBS);
			break;
		case TWO_STOP_BITS:
			SET_BIT(UCSRC_value,USBS);
			break;
		default:
			break;
	}
	
	/* configure char size */
	switch(char_size)
	{
		case _5_BIT_CHAR:
			TWO_BITS_WRITE(UCSRC_value,UCSZ0,0);
			CLR_BIT(UCSRB,UCSZ2);
			break;
		case _6_BIT_CHAR:
			TWO_BITS_WRITE(UCSRC_value,UCSZ0,1);
			CLR_BIT(UCSRB,UCSZ2);
			break;
		case _7_BIT_CHAR:
			TWO_BITS_WRITE(UCSRC_value,UCSZ0,2);
			CLR_BIT(UCSRB,UCSZ2);
			break;
		case _8_BIT_CHAR:
			TWO_BITS_WRITE(UCSRC_value,UCSZ0,3);
			CLR_BIT(UCSRB,UCSZ2);
			break;
		case _9_BIT_CHAR:
			TWO_BITS_WRITE(UCSRC_value,UCSZ0,3);
			SET_BIT(UCSRB,UCSZ2);
			break;
		default:
			break;
	}
	/* set the baud rate */
	UBRRH = (uint8_t)(UBRR>>REGISTER_SIZE);
	UBRRL = (uint8_t)(UBRR);
	/* assign the UCSRC_value to UCSRC register */
	UCSRC = UCSRC_value;
	/* enable USART receiver */
	SET_BIT(UCSRB,RXEN);
}
void USART_Transmit(uint16_t data)
{
	/* wait for UDR transmit buffer to be empty */
	while(READ_BIT(UCSRA,UDRE) == TRANSMIT_BUFFER_NOT_READY_TO_BE_WRITTEN);
	/* put data to UDR transmit buffer */
	switch(USART_char_size)
	{
		case _5_BIT_CHAR:
		case _6_BIT_CHAR:
		case _7_BIT_CHAR:
		case _8_BIT_CHAR:
			UDR = (uint8_t)data;
			break;
		case _9_BIT_CHAR:
			BIT_WRITE(UCSRB,TXB8,READ_BIT(data,9));
			UDR = (uint8_t)data;
			break;
		default:
			break;		
	}
}
uint16_t USART_Receive(void)
{
	uint16_t received_data = 0x00;
	/* wait for UDR receive buffer to have unread data */
	while(READ_BIT(UCSRA,RXC) == RECEIVE_BUFFER_DONT_HAVE_UNREAD_DATA);
	/* check for errors */
	/*
	if (READ_BIT(UCSRA,FE) == 1)
	{
		DIO_ERROR_FRAME_ERROR;
	}
	if (READ_BIT(UCSRA,PE) == 1)
	{
		DIO_ERROR_PARITY_ERROR;
	}
	if (READ_BIT(UCSRA,DOR) == 1)
	{
		DIO_ERROR_DATA_OVERRUN_ERROR;
	}*/
	/* receive data from UDR receive buffer */
	switch(USART_char_size)
	{
		case _5_BIT_CHAR:
		case _6_BIT_CHAR:
		case _7_BIT_CHAR:
		case _8_BIT_CHAR:
			received_data = (uint16_t)UDR;
			break;
		case _9_BIT_CHAR:
			BIT_WRITE(received_data,9,READ_BIT(UCSRB,RXB8));
			EIGHT_BITS_WRITE(received_data,0,UDR);
			break;
		default:
			break;
	}
	return received_data;
}
void USART_StopTransmitter(void)
{
	/* disable USART transmitter */
	CLR_BIT(UCSRB,TXEN);
}
void USART_StopReceiver(void)
{
	/* disable USART receiver */
	CLR_BIT(UCSRB,RXEN);
}




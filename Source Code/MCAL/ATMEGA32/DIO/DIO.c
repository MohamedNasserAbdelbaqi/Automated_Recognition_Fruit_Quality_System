/*
 * DIO.c
 * Created: 01/10/2021 11:19:36 pm
 * Author: Mohamed Nasser
 */

#include <avr/io.h>
#include "DIO.h"

#define  DIO_PORT_BIT_NUMBERS     7
#define  DIO_NIBBLE_BIT_NUMBERS   4

/* APIs for bit in register */
error_state_t DIO_SetPinDirection(uint8_t port_name,uint8_t bit_number,uint8_t direction)
{
	error_state_t error_state = ERROR_OK;
	if (bit_number > DIO_PORT_BIT_NUMBERS)
	{
		error_state = DIO_ERROR_INVALID_BIT;
	}
	else
	{
		switch(port_name)
		{
			case 'A':
			case 'a':
				switch(direction)
				{
					case 0:
						CLR_BIT(DDRA,bit_number);
						break;
					case 1:
						SET_BIT(DDRA,bit_number);
						break;
					default:
						error_state = DIO_ERROR_INVALID_BIT_DIRECTION;
						break;
				}
				break;
			case 'B':
			case 'b':
				switch(direction)
				{
					case 0:
						CLR_BIT(DDRB,bit_number);
						break;
					case 1:
						SET_BIT(DDRB,bit_number);
						break;
					default:
						error_state = DIO_ERROR_INVALID_BIT_DIRECTION;
						break;
				}
				break;
			case 'C':
			case 'c':
				switch(direction)
				{
					case 0:
						CLR_BIT(DDRC,bit_number);
						break;
					case 1:
						SET_BIT(DDRC,bit_number);
						break;
					default:
						error_state = DIO_ERROR_INVALID_BIT_DIRECTION;
						break;
				}
				break;
			case 'D':
			case 'd':
				switch(direction)
				{
					case 0:
						CLR_BIT(DDRD,bit_number);
						break;
					case 1:
						SET_BIT(DDRD,bit_number);
						break;
					default:
						error_state = DIO_ERROR_INVALID_BIT_DIRECTION;
						break;
				}
				break;
			default:
				error_state = ERROR_INVALID_CHANNEL;
				break;		
		}
	}
	return error_state;
}
error_state_t DIO_WritePin(uint8_t port_name,uint8_t bit_number,uint8_t output_value)
{
	error_state_t error_state = ERROR_OK;
	if (bit_number > DIO_PORT_BIT_NUMBERS)
	{
		error_state = DIO_ERROR_INVALID_BIT;
	} 
	else
	{
		switch(port_name)
		{
			case 'A':
			case 'a':
				switch(output_value)
				{
					case 0:
						CLR_BIT(PORTA,bit_number);
						break;
					case 1:
						SET_BIT(PORTA,bit_number);
						break;
					default:
						error_state = DIO_ERROR_INVALID_BIT_OUTPUT;
						break;
				}
				break;
			case 'B':
			case 'b':
				switch(output_value)
				{
					case 0:
						CLR_BIT(PORTB,bit_number);
						break;
					case 1:
						SET_BIT(PORTB,bit_number);
						break;
					default:
						error_state = DIO_ERROR_INVALID_BIT_OUTPUT;
						break;
				}
				break;
			case 'C':
			case 'c':
				switch(output_value)
				{
					case 0:
						CLR_BIT(PORTC,bit_number);
						break;
					case 1:
						SET_BIT(PORTC,bit_number);
						break;
					default:
						error_state = DIO_ERROR_INVALID_BIT_OUTPUT;
						break;
				}
				break;
			case 'D':
			case 'd':
				switch(output_value)
				{
					case 0:
						CLR_BIT(PORTD,bit_number);
						break;
					case 1:
						SET_BIT(PORTD,bit_number);
						break;
					default:
						error_state = DIO_ERROR_INVALID_BIT_OUTPUT;
						break;
				}
				break;
			default:
				error_state = ERROR_INVALID_CHANNEL;
				break;
		}
	}
	return error_state;
}
error_state_t DIO_ReadPin(uint8_t port_name,uint8_t bit_number,ptr_uint8_t function_return)
{
	error_state_t error_state = ERROR_OK;
	if (NULL == function_return)
	{
		error_state = ERROR_NULL_POINTER;
	}
	else if (bit_number > DIO_PORT_BIT_NUMBERS)
	{
		error_state = DIO_ERROR_INVALID_BIT;
	} 
	else
	{
		switch(port_name)
		{
			case 'A':
			case 'a':
				*function_return = READ_BIT(PINA,bit_number);
				break;
			case 'B':
			case 'b':
				*function_return = READ_BIT(PINB,bit_number);
				break;
			case 'C':
			case 'c':
				*function_return = READ_BIT(PINC,bit_number);
				break;
			case 'D':
			case 'd':
				*function_return = READ_BIT(PIND,bit_number);
				break;
			default:
				*function_return = 0xFF;
				error_state = ERROR_INVALID_CHANNEL;
				break;
		}
	}
	return error_state;
}
error_state_t DIO_TogglePin(uint8_t port_name,uint8_t bit_number)
{
	error_state_t error_state = ERROR_OK;
	if (bit_number > DIO_PORT_BIT_NUMBERS)
	{
		error_state = DIO_ERROR_INVALID_BIT;
	} 
	else
	{
		switch(port_name)
		{
			case 'A':
			case 'a':
				TOG_BIT(PORTA,bit_number);
				break;
			case 'B':
			case 'b':
				TOG_BIT(PORTB,bit_number);
				break;
			case 'C':
			case 'c':
				TOG_BIT(PORTC,bit_number);
				break;
			case 'D':
			case 'd':
				TOG_BIT(PORTD,bit_number);
				break;
			default:
				error_state = ERROR_INVALID_CHANNEL;
				break;
		}
	}
	return error_state;
}
/* APIs for all of register */
error_state_t DIO_SetPortDirection(uint8_t port_name,uint8_t direction)
{
	error_state_t error_state = ERROR_OK;
	switch(port_name)
	{
		case 'A':
		case 'a':
			DDRA = direction;
			break;
		case 'B':
		case 'b':
			DDRB = direction;
			break;
		case 'C':
		case 'c':
			DDRC = direction;
			break;
		case 'D':
		case 'd':
			DDRD = direction;
			break;
		default:
			error_state = ERROR_INVALID_CHANNEL;
			break;
	}
	return error_state;
}
error_state_t DIO_WritePort(uint8_t port_name,uint8_t output_value)
{
	error_state_t error_state = ERROR_OK;
	switch(port_name)
	{
		case 'A':
		case 'a':
			PORTA = output_value;
			break;
		case 'B':
		case 'b':
			PORTB = output_value;
			break;
		case 'C':
		case 'c':
			PORTC = output_value;
			break;
		case 'D':
		case 'd':
			PORTD = output_value;
			break;
		default:
			error_state = ERROR_INVALID_CHANNEL;
			break;
	}
	return error_state;
}
error_state_t DIO_ReadPort(uint8_t port_name,ptr_uint8_t function_return)
{
	error_state_t error_state = ERROR_OK;
	if (NULL == function_return)
	{
		error_state = ERROR_NULL_POINTER;
	}
	else
	{
		switch(port_name)
		{
			case 'A':
			case 'a':
				*function_return = PINA;
				break;
			case 'B':
			case 'b':
				*function_return = PINB;
				break;
			case 'C':
			case 'c':
				*function_return = PINC;
				break;
			case 'D':
			case 'd':
				*function_return = PIND;
				break;
			default:
				*function_return = 0xFF;
				error_state = ERROR_INVALID_CHANNEL;
				break;
		}
	}
	return error_state;
}
error_state_t DIO_TogglePort(uint8_t port_name)
{
	error_state_t error_state = ERROR_OK;
	switch(port_name)
	{
		case 'A':
		case 'a':
			PORTA = ~PORTA;//PORTA ^= 0xFF;
			break;
		case 'B':
		case 'b':
			PORTB = ~PORTA;//PORTB ^= 0xFF;
			break;
		case 'C':
		case 'c':
			PORTC = ~PORTA;//PORTC ^= 0xFF;
			break;
		case 'D':
		case 'd':
			PORTD = ~PORTA;//PORTD ^= 0xFF;
			break;
		default:
			error_state = ERROR_INVALID_CHANNEL;
			break;
	}
	return error_state;
}
/* APIs for nibble of register */
error_state_t DIO_SetNibbleDirection(uint8_t port_name,uint8_t start_bit,uint8_t direction)
{
	error_state_t error_state = ERROR_OK;
	uint8_t bit_number;
	if (start_bit > DIO_NIBBLE_BIT_NUMBERS)
	{
		error_state = DIO_ERROR_INVALID_NIBBLE;
	} 
	else if (direction > 0x0F)
	{
		error_state = DIO_ERROR_INVALID_NIBBLE_DIRECTION;
	}
	else
	{
		switch(port_name)
		{
			case 'A':
			case 'a':
				for (bit_number=start_bit;bit_number<=start_bit+3;bit_number++)
				{
					switch(READ_BIT(direction,(bit_number-start_bit)))
					{
						case 0:
							CLR_BIT(DDRA,bit_number);
							break;
						case 1:
							SET_BIT(DDRA,bit_number);
							break;
						default:
							break;
					}
				}
				break;
			case 'B':
			case 'b':
				for (bit_number=start_bit;bit_number<=start_bit+3;bit_number++)
				{
					switch(READ_BIT(direction,(bit_number-start_bit)))
					{
						case 0:
							CLR_BIT(DDRB,bit_number);
							break;
						case 1:
							SET_BIT(DDRB,bit_number);
							break;
						default:
							break;
					}
				}
				break;
			case 'C':
			case 'c':
				for (bit_number=start_bit;bit_number<=start_bit+3;bit_number++)
				{
					switch(READ_BIT(direction,(bit_number-start_bit)))
					{
						case 0:
							CLR_BIT(DDRC,bit_number);
							break;
						case 1:
							SET_BIT(DDRC,bit_number);
							break;
						default:
							break;
					}
				}
				break;
			case 'D':
			case 'd':
				for (bit_number=start_bit;bit_number<=start_bit+3;bit_number++)
				{
					switch(READ_BIT(direction,(bit_number-start_bit)))
					{
						case 0:
							CLR_BIT(DDRD,bit_number);
							break;
						case 1:
							SET_BIT(DDRD,bit_number);
							break;
						default:
							break;
					}
				}
				break;
			default:
				error_state = ERROR_INVALID_CHANNEL;
				break;
		}
	}
	return error_state;
}
error_state_t DIO_WriteNibble(uint8_t port_name,uint8_t start_bit,uint8_t output_value)
{
	error_state_t error_state = ERROR_OK;
	uint8_t bit_number;
	if (start_bit > DIO_NIBBLE_BIT_NUMBERS)
	{
		error_state = DIO_ERROR_INVALID_NIBBLE;
	}
	else if (output_value > 0x0F)
	{
		error_state = DIO_ERROR_INVALID_NIBBLE_OUTPUT;
	} 
	else
	{
		switch(port_name)
		{
			case 'A':
			case 'a':
				for (bit_number=start_bit;bit_number<=start_bit+3;bit_number++)
				{
					switch(READ_BIT(output_value,(bit_number-start_bit)))
					{
						case 0:
							CLR_BIT(PORTA,bit_number);
							break;
						case 1:
							SET_BIT(PORTA,bit_number);
							break;
						default:
							break;
					}
				}
				break;
			case 'B':
			case 'b':
				for (bit_number=start_bit;bit_number<=start_bit+3;bit_number++)
				{
					switch(READ_BIT(output_value,(bit_number-start_bit)))
					{
						case 0:
							CLR_BIT(PORTB,bit_number);
							break;
						case 1:
							SET_BIT(PORTB,bit_number);
							break;
						default:
							break;
					}
				}
				break;
			case 'C':
			case 'c':
				for (bit_number=start_bit;bit_number<=start_bit+3;bit_number++)
				{
					switch(READ_BIT(output_value,(bit_number-start_bit)))
					{
						case 0:
							CLR_BIT(PORTC,bit_number);
							break;
						case 1:
							SET_BIT(PORTC,bit_number);
							break;
						default:
							break;
					}
				}
				break;
			case 'D':
			case 'd':
				for (bit_number=start_bit;bit_number<=start_bit+3;bit_number++)
				{
					switch(READ_BIT(output_value,(bit_number-start_bit)))
					{
						case 0:
							CLR_BIT(PORTD,bit_number);
							break;
						case 1:
							SET_BIT(PORTD,bit_number);
							break;
						default:
							break;
					}
				}
				break;
			default:
				error_state = ERROR_INVALID_CHANNEL;
				break;
		}
	}
	return error_state;
}
error_state_t DIO_ReadNibble(uint8_t port_name,uint8_t start_bit,ptr_uint8_t function_return)
{
	error_state_t error_state = ERROR_OK;
	uint8_t bit_number;
	if (NULL == function_return)
	{
		error_state = ERROR_NULL_POINTER;
	}
	else if (start_bit > DIO_NIBBLE_BIT_NUMBERS)
	{
		error_state = DIO_ERROR_INVALID_NIBBLE;
	}
	switch(port_name)
	{
		case 'A':
		case 'a':
			for (bit_number=start_bit;bit_number<=start_bit+3;bit_number++)
			{
				switch(READ_BIT(PINA,bit_number))
				{
					case 0:
						CLR_BIT(*function_return,(bit_number-start_bit));
						break;
					case 1:
						SET_BIT(*function_return,(bit_number-start_bit));
						break;
					default:
						break;
				}
			}
			break;
		case 'B':
		case 'b':
			for (bit_number=start_bit;bit_number<=start_bit+3;bit_number++)
			{
				switch(READ_BIT(PINB,bit_number))
				{
					case 0:
						CLR_BIT(*function_return,(bit_number-start_bit));
						break;
					case 1:
						SET_BIT(*function_return,(bit_number-start_bit));
						break;
					default:
						break;
				}
			}
			break;
		case 'C':
		case 'c':
			for (bit_number=start_bit;bit_number<=start_bit+3;bit_number++)
			{
				switch(READ_BIT(PINC,bit_number))
				{
					case 0:
						CLR_BIT(*function_return,(bit_number-start_bit));
						break;
					case 1:
						SET_BIT(*function_return,(bit_number-start_bit));
						break;
					default:
						break;
				}
			}
			break;
		case 'D':
		case 'd':
			for (bit_number=start_bit;bit_number<=start_bit+3;bit_number++)
			{
				switch(READ_BIT(PIND,bit_number))
				{
					case 0:
						CLR_BIT(*function_return,(bit_number-start_bit));
						break;
					case 1:
						SET_BIT(*function_return,(bit_number-start_bit));
						break;
					default:
						break;
				}
			}
			break;
		default:
			*function_return = 0xFF;
			error_state = ERROR_INVALID_CHANNEL;
			break;
	}
	return error_state;
}
error_state_t DIO_ToggleNibble(uint8_t port_name,uint8_t start_bit)
{
	error_state_t error_state = ERROR_OK;
	uint8_t bit_number;
	if (start_bit > DIO_NIBBLE_BIT_NUMBERS)
	{
		error_state = DIO_ERROR_INVALID_NIBBLE;
	} 
	else
	{
		switch(port_name)
		{
			case 'A':
			case 'a':
				for (bit_number=start_bit;bit_number<=start_bit+3;bit_number++)
				{
					TOG_BIT(PORTA,bit_number);
				}
				break;
			case 'B':
			case 'b':
				for (bit_number=start_bit;bit_number<=start_bit+3;bit_number++)
				{
					TOG_BIT(PORTB,bit_number);
				}
				break;
			case 'C':
			case 'c':
				for (bit_number=start_bit;bit_number<=start_bit+3;bit_number++)
				{
					TOG_BIT(PORTC,bit_number);
				}
				break;
			case 'D':
			case 'd':
				for (bit_number=start_bit;bit_number<=start_bit+3;bit_number++)
				{
					TOG_BIT(PORTD,bit_number);
				}
				break;
			default:
				error_state = ERROR_INVALID_CHANNEL;
				break;
		}
	}
	return error_state;
}
/* APIs internal pull up resistance */
error_state_t DIO_EnablePinInternalPullUpRes(uint8_t port_name,uint8_t bit_number,uint8_t enable)
{
	error_state_t error_state = ERROR_OK;
	if (bit_number > DIO_PORT_BIT_NUMBERS)
	{
		error_state = DIO_ERROR_INVALID_BIT;
	}
	else
	{
		switch(port_name)
		{
			case 'A':
			case 'a':
				switch(enable)
				{
					case 0:
						CLR_BIT(PORTA,bit_number);
						break;
					case 1:
						SET_BIT(PORTA,bit_number);
						break;
					default:
						error_state = DIO_ERROR_INVALID_BIT_PU_ENABLE;
						break;
				}
				break;
			case 'B':
			case 'b':
				switch(enable)
				{
					case 0:
						CLR_BIT(PORTB,bit_number);
						break;
					case 1:
						SET_BIT(PORTB,bit_number);
						break;
					default:
						error_state = DIO_ERROR_INVALID_BIT_PU_ENABLE;
						break;
				}
				break;
			case 'C':
			case 'c':
				switch(enable)
				{
					case 0:
						CLR_BIT(PORTC,bit_number);
						break;
					case 1:
						SET_BIT(PORTC,bit_number);
						break;
					default:
						error_state = DIO_ERROR_INVALID_BIT_PU_ENABLE;
						break;
				}
				break;
			case 'D':
			case 'd':
				switch(enable)
				{
					case 0:
						CLR_BIT(PORTD,bit_number);
						break;
					case 1:
						SET_BIT(PORTD,bit_number);
						break;
					default:
						error_state = DIO_ERROR_INVALID_BIT_PU_ENABLE;
						break;
				}
				break;
			default:
				error_state = ERROR_INVALID_CHANNEL;
				break;
		}
	}
	return error_state;
}
error_state_t DIO_EnablePortInternalPullUpRes(uint8_t port_name,uint8_t enable)
{
	error_state_t error_state = ERROR_OK;
	switch(port_name)
	{
		case 'A':
		case 'a':
			PORTA = enable;
			break;
		case 'B':
		case 'b':
			PORTB = enable;
		case 'C':
		case 'c':
			PORTC = enable;
			break;
		case 'D':
		case 'd':
			PORTD = enable;
			break;
		default:
			error_state = ERROR_INVALID_CHANNEL;
			break;
	}
	return error_state;
}
error_state_t DIO_EnableNibbleInternalPullUpRes(uint8_t port_name,uint8_t start_bit,uint8_t enable)
{
	error_state_t error_state = ERROR_OK;
	uint8_t bit_number;
	if (start_bit > DIO_NIBBLE_BIT_NUMBERS)
	{
		error_state = DIO_ERROR_INVALID_NIBBLE;
	} 
	else if (enable > 0x0F)
	{
		error_state = DIO_ERROR_INVALID_NIBBLE_PU_ENABLE;
	}
	else
	{
		switch(port_name)
		{
			case 'A':
			case 'a':
				for (bit_number=start_bit;bit_number<=start_bit+3;bit_number++)
				{
					switch(READ_BIT(enable,(bit_number-start_bit)))
					{
						case 0:
							CLR_BIT(PORTA,bit_number);
							break;
						case 1:
							SET_BIT(PORTA,bit_number);
							break;
						default:
							break;
					}
				}
				break;
			case 'B':
			case 'b':
				for (bit_number=start_bit;bit_number<=start_bit+3;bit_number++)
				{
					switch(READ_BIT(enable,(bit_number-start_bit)))
					{
						case 0:
							CLR_BIT(PORTB,bit_number);
							break;
						case 1:
							SET_BIT(PORTB,bit_number);
							break;
						default:
							break;
					}
				}
				break;
			case 'C':
			case 'c':
				for (bit_number=start_bit;bit_number<=start_bit+3;bit_number++)
				{
					switch(READ_BIT(enable,(bit_number-start_bit)))
					{
						case 0:
							CLR_BIT(PORTC,bit_number);
							break;
						case 1:
							SET_BIT(PORTC,bit_number);
							break;
						default:
							break;
					}
				}
				break;
			case 'D':
			case 'd':
				for (bit_number=start_bit;bit_number<=start_bit+3;bit_number++)
				{
					switch(READ_BIT(enable,(bit_number-start_bit)))
					{
						case 0:
							CLR_BIT(PORTD,bit_number);
							break;
						case 1:
							SET_BIT(PORTD,bit_number);
							break;
						default:
							break;
					}
				}
				break;
			default:
				error_state = ERROR_INVALID_CHANNEL;
				break;
		}
	}
	return error_state;
}
/*
 * DIO.h
 * Created: 01/10/2021 10:50:28 pm
 * Author: Mohamed Nasser
 */ 

#ifndef DIO_H_
#define DIO_H_

/* file includes */
#include "BIT_MATH.h"
#include "STD_TYPES.h"

/* directions */
#define INPUT_PIN                                   0
#define OUTPUT_PIN                                  1
#define INPUT_PORT                                  0x00
#define OUTPUT_PORT                                 0xFF
#define INPUT_NIBBLE                                0x00
#define OUTPUT_NIBBLE                               0x0F
												    
/* output values */						                            
#define BIT_LOW                                     0
#define BIT_HIGH                                    1
#define PORT_LOW                                    0x00
#define PORT_HIGH                                   0xFF
#define NIBBLE_LOW                                  0x00
#define NIBBLE_HIGH                                 0x0F
												    
/* internal pull up resistor */					    	                        
#define DISABLE_PU_PIN                              0
#define ENABLE_PU_PIN  	                            1
#define DISABLE_PU_PORT                             0x00
#define ENABLE_PU_PORT                              0xFF
#define DISABLE_PU_NIBBLE                           0x00
#define ENABLE_PU_NIBBLE                            0x0F

/* start bit of nibble */						                            
#define LOW_NIBBLE 		                            0
#define HIGH_NIBBLE                                 4
												    
/* port names */					                            
#define PORT_A                                      'a'
#define PORT_B                                      'b'
#define PORT_C                                      'c'
#define PORT_D                                      'd'
												    
/* DIO error types */							    
#define DIO_ERROR_INVALID_BIT_DIRECTION             15
#define DIO_ERROR_INVALID_BIT                       16
#define DIO_ERROR_INVALID_BIT_OUTPUT                17
#define DIO_ERROR_INVALID_NIBBLE_DIRECTION          18
#define DIO_ERROR_INVALID_NIBBLE                    19
#define DIO_ERROR_INVALID_NIBBLE_OUTPUT             20
#define DIO_ERROR_INVALID_BIT_PU_ENABLE             21
#define DIO_ERROR_INVALID_NIBBLE_PU_ENABLE          22

/* APIs for bit in register */
/*
	API Name        : DIO_SetPinDirection
	API Return      : error_state_t
	API Arguments   : input one:
						    name : port_name
						    type : uint8_t
						    range: PORT_A (0) , PORT_B (1) , PORT_C (2) , PORT_D (3)				
					  input two:
						    name : bit_number
						    type : uint8_t
						    range: from 0 to 7				  
					  input three:
						    name : direction
						    type : uint8_t
						    range: INPUT_PIN (0) , OUTPUT_PIN (1)
	API Description : Set the direction of the given pin in the given port.
*/
error_state_t DIO_SetPinDirection(uint8_t port_name,uint8_t bit_number,uint8_t direction);
/*
	API Name        : DIO_WritePin
	API Return      : error_state_t
	API Arguments   : input one:
						    name : port_name
						    type : uint8_t
						    range: PORT_A (0) , PORT_B (1) , PORT_C (2) , PORT_D (3)				
					  input two:
						    name : bit_number
						    type : uint8_t
						    range: from 0 to 7				  
					  input three:
						    name : output_value
						    type : uint8_t
						    range: BIT_LOW (0) , BIT_HIGH (1)
	API Description : Write a given value of the given pin in the given port.
*/
error_state_t DIO_WritePin(uint8_t port_name,uint8_t bit_number,uint8_t output_value);
/*
	API Name        : DIO_ReadPin
	API Return      : error_state_t
	API Arguments   : input one:
						    name : port_name
						    type : uint8_t
						    range: PORT_A (0) , PORT_B (1) , PORT_C (2) , PORT_D (3)				
					  input two:
						    name : bit_number
						    type : uint8_t
						    range: from 0 to 7				  
					  input three:
						    name : function_return
						    type : ptr_uint8_t
						    range: available address
	API Description : Read the value of the given pin in the given port.
*/
error_state_t DIO_ReadPin(uint8_t port_name,uint8_t bit_number,ptr_uint8_t function_return);
/*
	API Name        : DIO_TogglePin
	API Return      : error_state_t
	API Arguments   : input one:
						    name : port_name
						    type : uint8_t
						    range: PORT_A (0) , PORT_B (1) , PORT_C (2) , PORT_D (3)				
					  input two:
						    name : bit_number
						    type : uint8_t
						    range: from 0 to 7				  
	API Description : Toggle the state of the given pin in the given port.
*/
error_state_t DIO_TogglePin(uint8_t port_name,uint8_t bit_number);


/* APIs for all of register */
/*
	API Name        : DIO_SetPortDirection
	API Return      : error_state_t
	API Arguments   : input one:
						    name : port_name
						    type : uint8_t
						    range: PORT_A (0) , PORT_B (1) , PORT_C (2) , PORT_D (3)				
					  input two:
						    name : direction
						    type : uint8_t
						    range: from (0x00) to (0xFF)				  
	API Description : Set the direction of the given port.
*/
error_state_t DIO_SetPortDirection(uint8_t port_name,uint8_t direction);
/*
	API Name        : DIO_WritePort
	API Return      : error_state_t
	API Arguments   : input one:
						    name : port_name
						    type : uint8_t
						    range: PORT_A (0) , PORT_B (1) , PORT_C (2) , PORT_D (3)			  
					  input two:
						    name : output_value
						    type : uint8_t
						    range: from (0x00) to (0xFF)
	API Description : Write a given value in the given port.
*/
error_state_t DIO_WritePort(uint8_t port_name,uint8_t output_value);
/*
	API Name        : DIO_ReadPort
	API Return      : error_state_t
	API Arguments   : input one:
						    name : port_name
						    type : uint8_t
						    range: PORT_A (0) , PORT_B (1) , PORT_C (2) , PORT_D (3)				
					  input two:
						    name : function_return
						    type : ptr_uint8_t
						    range: available address
	API Description : Read the value of the given port.
*/
error_state_t DIO_ReadPort(uint8_t port_name,ptr_uint8_t function_return);
/*
	API Name        : DIO_TogglePort
	API Return      : error_state_t
	API Arguments   : input one:
						    name : port_name
						    type : uint8_t
						    range: PORT_A (0) , PORT_B (1) , PORT_C (2) , PORT_D (3)
	API Description : Toggle the state of the given port.
*/
error_state_t DIO_TogglePort(uint8_t port_name);


/* APIs for nibble of register */
/*
	API Name        : DIO_SetNibbleDirection
	API Return      : error_state_t
	API Arguments   : input one:
						    name : port_name
						    type : uint8_t
						    range: PORT_A (0) , PORT_B (1) , PORT_C (2) , PORT_D (3)
					  input two:
						    name : start_bit
						    type : uint8_t
						    range: from 0 to 4							
					  input three:
						    name : direction
						    type : uint8_t
						    range: from (0x00) to (0x0F)				  
	API Description : Set the direction of the given nibble in the given port.
*/
error_state_t DIO_SetNibbleDirection(uint8_t port_name,uint8_t start_bit,uint8_t direction);
/*
	API Name        : DIO_WriteNibble
	API Return      : error_state_t
	API Arguments   : input one:
						    name : port_name
						    type : uint8_t
						    range: PORT_A (0) , PORT_B (1) , PORT_C (2) , PORT_D (3)
					  input two:
						    name : start_bit
						    type : uint8_t
						    range: from 0 to 4							
					  input three:
						    name : output_value
						    type : uint8_t
						    range: from (0x00) to (0x0F)				  
	API Description : Write a given value in the given nibble in the given port.
*/
error_state_t DIO_WriteNibble(uint8_t port_name,uint8_t start_bit,uint8_t output_value);
/*
	API Name        : DIO_ReadNibble
	API Return      : error_state_t
	API Arguments   : input one:
						    name : port_name
						    type : uint8_t
						    range: PORT_A (0) , PORT_B (1) , PORT_C (2) , PORT_D (3)
					  input two:
						    name : start_bit
						    type : uint8_t
						    range: from 0 to 4							
					  input three:
						    name : function_return
						    type : ptr_uint8_t
						    range: available address				  
	API Description : Read the value of the given nibble in the given port.
*/
error_state_t DIO_ReadNibble(uint8_t port_name,uint8_t start_bit,ptr_uint8_t function_return);
/*
	API Name        : DIO_ToggleNibble
	API Return      : error_state_t
	API Arguments   : input one:
						    name : port_name
						    type : uint8_t
						    range: PORT_A (0) , PORT_B (1) , PORT_C (2) , PORT_D (3)
					  input two:
						    name : start_bit
						    type : uint8_t
						    range: from 0 to 4				  
	API Description : Toggle the state of the given nibble in the given port.
*/
error_state_t DIO_ToggleNibble(uint8_t port_name,uint8_t start_bit);


/* APIs internal pull up resistance */
/*
	API Name        : DIO_EnablePinInternalPullUpRes
	API Return      : error_state_t
	API Arguments   : input one:
						    name : port_name
						    type : uint8_t
						    range: PORT_A (0) , PORT_B (1) , PORT_C (2) , PORT_D (3)				
					  input two:
						    name : bit_number
						    type : uint8_t
						    range: from 0 to 7				  
					  input three:
						    name : enable
						    type : uint8_t
						    range: DISABLE_PU_PIN (0) , ENABLE_PU_PIN (1)
	API Description : Set the enable of the given pin in the given port.
*/
error_state_t DIO_EnablePinInternalPullUpRes(uint8_t port_name,uint8_t bit_number,uint8_t enable);
/*
	API Name        : DIO_EnablePortInternalPullUpRes
	API Return      : error_state_t
	API Arguments   : input one:
						    name : port_name
						    type : uint8_t
						    range: PORT_A (0) , PORT_B (1) , PORT_C (2) , PORT_D (3)				  
					  input two:
						    name : enable
						    type : uint8_t
						    range: DISABLE_PU_PORT (0x00) , ENABLE_PU_PORT (0xFF)
	API Description : Set the enable of the given port.
*/
error_state_t DIO_EnablePortInternalPullUpRes(uint8_t port_name,uint8_t enable);
/*
	API Name        : DIO_EnableNibbleInternalPullUpRes
	API Return      : error_state_t
	API Arguments   : input one:
						    name : port_name
						    type : uint8_t
						    range: PORT_A (0) , PORT_B (1) , PORT_C (2) , PORT_D (3)
					  input two:
						    name : start_bit
						    type : uint8_t
						    range: from 0 to 4							
					  input three:
						    name : enable
						    type : uint8_t
						    range: DISABLE_PU_NIBBLE (0x00) , ENABLE_PU_NIBBLE (0x0F)
	API Description : Set the enable of the given nibble.
*/
error_state_t DIO_EnableNibbleInternalPullUpRes(uint8_t port_name,uint8_t start_bit,uint8_t enable);

#endif /* DIO_H_ */
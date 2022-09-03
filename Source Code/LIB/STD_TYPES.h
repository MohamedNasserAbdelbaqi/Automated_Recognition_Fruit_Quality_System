/*
 * STD_TYPES.h
 * Created: 12/18/2021 4:12:43 pm
 * Author: Mohamed Nasser
 */ 


#ifndef STD_TYPES_H_
#define STD_TYPES_H_

/* unsigned integer typedefs */
typedef unsigned char				uint8_t;
/*typedef unsigned short int			uint16_t;*/
typedef unsigned long int			uint32_t;
typedef unsigned long long int		uint64_t;

/* signed integer typedefs */
typedef signed char					sint8_t;
typedef signed short int			sint16_t;
typedef signed long int				sint32_t;
typedef signed long long int		sint64_t;

/* float typedefs */
typedef float					    float32_t;
typedef double					    double64_t;

/* pointer */
typedef uint8_t *                   ptr_uint8_t;
/*typedef uint16_t *                  ptr_uint16_t;*/

/* error state typedef */
typedef uint8_t                     error_state_t;

/* common macros*/
#define NULL      ((void*)(0))


/* error states */
#define ERROR_NOK					0
#define ERROR_OK					1
/* error types */
#define ERROR_INVALID_CHANNEL       2
#define ERROR_NULL_POINTER          3

#endif /* STD_TYPES_H_ */
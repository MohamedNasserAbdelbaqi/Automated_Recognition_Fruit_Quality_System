/*
 * BIT_MATH.h
 * Created: 02/10/2021 03:07:16 am
 * Author: Mohamed Nasser
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_



#define REGISTER_SIZE					       8
#define SET_BIT(reg,bit_number)			       reg |= (1<<bit_number)										
#define CLR_BIT(reg,bit_number)			       reg &= (~(1<<bit_number))
#define TOG_BIT(reg,bit_number)				   reg ^= (1<<bit_number)
#define READ_BIT(reg,bit_number)			   ((reg&(1<<bit_number))>>bit_number)
#define IS_BIT_SET(reg,bit_number)		       ((reg&(1<<bit_number))>>bit_number)
#define IS_BIT_CLR(reg,bit_number)             !((reg&(1<<bit_number))>>bit_number)
#define ROR_REG(reg,num_of_rotation)           reg = (reg<<(REGISTER_SIZE-num_of_rotation))|(reg>>(num_of_rotation))
#define ROL_REG(reg,num_of_rotation)           reg = (reg>>(REGISTER_SIZE-num_of_rotation))|(reg<<(num_of_rotation))



#define BIT_HIGH                            1
#define TWO_BITS_HIGH                       3
#define THREE_BITS_HIGH                     7
#define FOUR_BITS_HIGH                      15
#define FIVE_BITS_HIGH                      31
#define SIX_BITS_HIGH                       63
#define SEVEN_BITS_HIGH                     127
#define EIGHT_BITS_HIGH                     255

#define BIT_WRITE(reg,bit_no,val)                 reg = (reg&(~(BIT_HIGH<<bit_no)))|(val<<bit_no)
#define TWO_BITS_WRITE(reg,first_bit_no,val)      reg = (reg&(~(TWO_BITS_HIGH<<first_bit_no)))|(val<<first_bit_no)
#define THREE_BITS_WRITE(reg,first_bit_no,val)    reg = (reg&(~(THREE_BITS_HIGH<<first_bit_no)))|(val<<first_bit_no)
#define FOUR_BITS_WRITE(reg,first_bit_no,val)     reg = (reg&(~(FOUR_BITS_HIGH<<first_bit_no)))|(val<<first_bit_no)
#define FIVE_BITS_WRITE(reg,first_bit_no,val)     reg = (reg&(~(FIVE_BITS_HIGH<<first_bit_no)))|(val<<first_bit_no)
#define SIX_BITS_WRITE(reg,first_bit_no,val)      reg = (reg&(~(SIX_BITS_HIGH<<first_bit_no)))|(val<<first_bit_no)
#define SEVEN_BITS_WRITE(reg,first_bit_no,val)    reg = (reg&(~(SEVEN_BITS_HIGH<<first_bit_no)))|(val<<first_bit_no)
#define EIGHT_BITS_WRITE(reg,first_bit_no,val)    reg = (reg&(~(EIGHT_BITS_HIGH<<first_bit_no)))|(val<<first_bit_no)
#endif /* BIT_MATH_H_ */
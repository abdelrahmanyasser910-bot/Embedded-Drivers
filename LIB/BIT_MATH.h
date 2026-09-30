/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    BIT_MATH.h    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Abdelrahman Yasser
 *  Layer  : LIB
 *  SWC    : BIT_MATH
 *
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_


#define SET_BIT(reg,bit)      reg |= (1<<bit)
#define CLR_BIT(reg,bit)      reg &= (~(1<<bit)) 
#define TOG_BIT(reg,bit)      reg ^= (1<<bit)
#define GET_BIT(reg,bit)      (reg>>bit) & 1

#define IS_BIT_SET(reg,bit)    (reg>>bit) & 1
#define IS_BIT_CLR(reg,bit)   !((reg>>bit) & 1)

#define ROL(reg,bit)      reg = (reg<<bit) | (reg>>(8-bit))
#define ROR(reg,bit)      reg = (reg>>bit) | (reg<<(8-bit))


#endif s
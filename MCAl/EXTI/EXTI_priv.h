/*
 * EXTI_priv.h
 *
 *  Created on: Sep 6, 2024
 *      Author: DELL
 */

#ifndef MCAL_EXTI_EXTI_PRIV_H_
#define MCAL_EXTI_EXTI_PRIV_H_

#define EXTI_GICR_REG           *((volatile u8*)(0x5b))

#define EXTI_GICR_INT1          7
#define EXTI_GICR_INT0          6
#define EXTI_GICR_INT2          5

#define EXTI_GIFR_REG           *((volatile u8*)(0x5a))

#define EXTI_GIFR_INT1          7
#define EXTI_GIFR_INT0          6
#define EXTI_GIFR_INT2          5

#define EXTI_MCUCR_REG          *((volatile u8*)(0x55))

#define EXTI_MCUCR_ISC00        0
#define EXTI_MCUCR_ISC01        1
#define EXTI_MCUCR_ISC10        2
#define EXTI_MCUCR_ISC11        3

#define EXTI_MCUCSR_REG         *((volatile u8*)(0x54))

#define EXTI_MCUCSR_ISC2        6

#define EXTI_RISING_EDGE        0
#define EXTI_FALLING_EDGE       1
#define EXTI_ANY_CHANGE         2
#define EXTI_LOW_LEVEL          3

#endif /* MCAL_EXTI_EXTI_PRIV_H_ */

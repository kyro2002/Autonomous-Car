/*
 * TIMER1_priv.h
 *
 *  Created on: 2 Feb 2025
 *      Author: AMIT
 */

#ifndef MCAL_TIMER1_TIMER1_PRIV_H_
#define MCAL_TIMER1_TIMER1_PRIV_H_

// Timer1 Registers
#define TIMER1_OCR1A_REG        *((volatile u16 *)(0x4A))
#define TIMER1_TCNT1_REG        *((volatile u16 *)(0x4C))
#define TIMER1_TCCR1A_REG       *((volatile u8 *)(0x4F))
#define TIMER1_TCCR1B_REG       *((volatile u8 *)(0x4E))
#define TIMER1_TIMSK_REG        *((volatile u8 *)(0x59))
#define TIMER1_TIFR_REG         *((volatile u8 *)(0x58))
#define TIMER1_TCR1_REG         *((volatile u16 *)(0x46))

// Clock Select Bits
#define TIMER1_TCCR1B_CS10        0
#define TIMER1_TCCR1B_CS11        1
#define TIMER1_TCCR1B_CS12        2

// Waveform Generation Mode
#define TIMER1_TCCR1A_WGM10       0
#define TIMER1_TCCR1A_WGM11       1
#define TIMER1_TCCR1B_WGM12       3
#define TIMER1_TCCR1B_WGM13       4

// Compare Match Output Mode
#define TIMER1_TCCR1A_COM1A0      6
#define TIMER1_TCCR1A_COM1A1      7

// Timer1 Prescaler Options
#define TIMER1_NO_CLK_SRC         0
#define TIMER1_NO_PRESCALER       1
#define TIMER1_NO_DIV_8           2
#define TIMER1_NO_DIV_64          3
#define TIMER1_NO_DIV_256         4
#define TIMER1_NO_DIV_1024        5
#define TIMER1_EXT_FALLING        6
#define TIMER1_EXT_RISING         7

#define TIMER1_PRESCALER_MASK     0b11111000

// Timer1 Modes
#define TIMER1_NORMAL_MODE        0
#define TIMER1_CTC_MODE           1
#define TIMER1_FAST_PWM_MODE      2
#define TIMER1_PC_PWM_MODE        3

#if TIMER1_MODE == TIMER1_CTC_MODE
#define TIMER1_OC1_DISCONNECTED   0
#define TIMER1_OC1_TOGGLE_ON_CM   1
#define TIMER1_OC1_CLR_ON_CM      2
#define TIMER1_OC1_SET_ON_CM      3
#endif

#if TIMER1_MODE == TIMER1_FAST_PWM_MODE
#define TIMER1_DISCONNECTED       0
#define TIMER1_NONINVERTING       1
#define TIMER1_INVERTING          2
#endif

#endif /* MCAL_TIMER1_TIMER1_PRIV_H_ */

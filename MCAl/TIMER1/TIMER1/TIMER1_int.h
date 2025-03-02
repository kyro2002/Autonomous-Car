/*
 * TIMER1_int.h
 *
 *  Created on: 2 Feb 2025
 *      Author: AMIT
 */

#ifndef MCAL_TIMER1_TIMER1_INT_H_
#define MCAL_TIMER1_TIMER1_INT_H_

void TIMER1_voidInit();
void TIMER1_voidSetPreloadValue(u16 Copy_u16PreLoad);
void TIMER1_voidSetOCRValue(u16 Copy_u16value);
void TIMER1_voidSetCallBack_COMP(void (*pf)(void));
void TIMER1_voidSetCallBack_OV(void (*pf)(void));
void TIMER1_voidGenPWM(u8 Copy_u8pwm);

#endif /* MCAL_TIMER1_TIMER1_INT_H_ */

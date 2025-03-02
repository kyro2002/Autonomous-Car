/*
 * EXTI_int.h
 *
 *  Created on: Sep 6, 2024
 *      Author: DELL
 */

#ifndef MCAL_EXTI_EXTI_INT_H_
#define MCAL_EXTI_EXTI_INT_H_

void EXTI_EnableINT0();
void EXTI_EnableINT1();
void EXTI_EnableINT2();

void EXTI_DisableINT0();
void EXTI_DisableINT1();
void EXTI_DisableINT2();

void EXTI_InitINT0();
void EXTI_InitINT1();
void EXTI_InitINT2();

void EXTI_voidSetINT0_Callback(void (*pf)(void));
void EXTI_voidSetINT1_Callback(void (*pf)(void));
void EXTI_voidSetINT2_Callback(void (*pf)(void));

#endif /* MCAL_EXTI_EXTI_INT_H_ */

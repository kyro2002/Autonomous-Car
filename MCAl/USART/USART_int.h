/*
 * USART_int.h
 *
 *  Created on: 28 Sep 2024
 *      Author: AMIT
 */

#ifndef MCAL_USART_USART_INT_H_
#define MCAL_USART_USART_INT_H_

void USART_voidInit();
void USART_voidSend(u16 Copy_u8DataToSend);
u16  USART_u16_Receive();
void USART_voidSetCallBack_RXC(void (*pf)(void));
void USART_voidSetCallBack_TXC(void (*pf)(void));
void USART_voidSetCallBack_UDRE(void (*pf)(void));
void USART_voidReceiveData(u8* Copy_u8DataAdress);
void USART_voidSendString(const u8 * Copy_pu8str);
#endif /* MCAL_USART_USART_INT_H_ */

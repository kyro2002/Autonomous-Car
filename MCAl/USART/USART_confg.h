/*
 * USART_confg.h
 *
 *  Created on: 28 Sep 2024
 *      Author: AMIT
 */

#ifndef MCAL_USART_USART_CONFG_H_
#define MCAL_USART_USART_CONFG_H_

/*
 * USART_CHAR_SIZE_5_BIT
 * USART_CHAR_SIZE_6_BIT
 * USART_CHAR_SIZE_7_BIT
 * USART_CHAR_SIZE_8_BIT
 * USART_CHAR_SIZE_9_BIT
 */


#define USART_CHAR_SIZE      USART_CHAR_SIZE_8_BIT
/*
 * USART_STOP_BIT_1
 * USART_STOP_BIT_2
 *
 */
#define USART_NO_OF_STOP_BIT   USART_STOP_BIT_1

/*
 * USART_PARITY_DIS
 * USART_PARITY_EVEN
 * USART_PARITY_ODD
 */

#define USART_PARITY_MODE     USART_PARITY_DIS
/*
 * choose
 * 0 for Disabled
 * 1 for Enabled
 */
#define USART_SENDER_EN     1
#define USART_RECEIV_EN     1

#endif /* MCAL_USART_USART_CONFG_H_ */

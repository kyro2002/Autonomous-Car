/*
 * UASRT_priv.h
 *
 *  Created on: 28 Sep 2024
 *      Author: AMIT
 */

#ifndef MCAL_USART_UASRT_PRIV_H_
#define MCAL_USART_UASRT_PRIV_H_

/* MCAL_USART_UASRT_PRIV_H_ */

//$0C ($2C) UDR USART I/O Data Register 159
#define USART_UDR_REG          *((volatile u8 *)(0x2C))

//$09 ($29) UBRRL USART Baud Rate Register Low Byte 164
#define USART_UBRRL_REG        *((volatile u8 *)(0x29))
//$20 ($40) UBRRH URSEL – – – UBRR[11:8] 164
#define USART_UBRRH_REG        *((volatile u8 *)(0x40))

//$0B ($2B) UCSRA RXC TXC UDRE FE DOR PE U2X MPCM 160
#define USART_UCSRA_REG        *((volatile u8 *)(0x2B))

#define USART_UCSRA_RXC            7        //USART Receive Complete FLAG
#define USART_UCSRA_TXC            6        //USART Transmit Complete FLAG
#define USART_UCSRA_UDRE           5        //USART Data Register Empty FLAG
#define USART_UCSRA_FE             4        //Frame Error
#define USART_UCSRA_DOR            3        //Data OverRun
#define USART_UCSRA_PE             2	    //Parity Error
#define USART_UCSRA_U2X            1	    //Double the USART Transmission Speed
#define USART_UCSRA_MPCM           0        //Multi-processor Communication Mode

//$0A ($2A) UCSRB RXCIE TXCIE UDRIE RXEN TXEN UCSZ2 RXB8 TXB8 161
#define USART_UCSRB_REG        *((volatile u8 *)(0x2A))

#define USART_UCSRB_RXCIE          7		//RX Complete Interrupt Enable
#define USART_UCSRB_TXCIE          6		//TX Complete Interrupt Enable
#define USART_UCSRB_UDRIE          5		//USART Data Register Empty Interrupt Enable
#define USART_UCSRB_RXEN           4		//Receiver Enable
#define USART_UCSRB_TXEN           3		//Transmitter Enable
#define USART_UCSRB_UCSZ2          2		//Character Size
#define USART_UCSRB_RXB8           1        //Receive Data Bit 8
#define USART_UCSRB_TXB8           0        //Transmit Data Bit 8

//UCSRC URSEL UMSEL UPM1 UPM0 USBS UCSZ1 UCSZ0 UCPOL 16
#define USART_UCSRC_REG        *((volatile u8 *)(0x40))

#define USART_UCSRC_URSEL           7		//Register Select UCSRC / UBRRH
#define USART_UCSRC_UMSEL           6       //USART Mode Select  SYNCHRONOUS / ASYNCHRONOUS
#define USART_UCSRC_UPM1            5       //Parity Mode
#define USART_UCSRC_UPM0            4       //Parity Mode
#define USART_UCSRC_USBS            3       //Stop Bit Select
#define USART_UCSRC_UCSZ1           2	    //Character Size
#define USART_UCSRC_UCSZ0           1       //Character Size
#define USART_UCSRC_UCPOL           0       //Clock Polarity



//NO OF DATA BITS
#define  USART_CHAR_SIZE_5_BIT   0
#define  USART_CHAR_SIZE_6_BIT   1
#define  USART_CHAR_SIZE_7_BIT   2
#define  USART_CHAR_SIZE_8_BIT   3
#define  USART_CHAR_SIZE_9_BIT   4

//NO OF STOP BITS
#define USART_STOP_BIT_1          0
#define USART_STOP_BIT_2          1

//PARITY MODE
#define  USART_PARITY_DIS    0
#define  USART_PARITY_EVEN   1
#define  USART_PARITY_ODD    2


#endif


#include "../../Service/STD_types.h"
#include "../../Service/bit_math.h"
#include "UASRT_priv.h"
#include "USART_confg.h"
#include "USART_int.h"
static  void (*USART_CallBack_RXC)() = NULL;
static  void (*USART_CallBack_TXC)() = NULL;
static  void (*USART_CallBack_UDRE)()= NULL;


void USART_voidInit(){

	u8 USART_UCSRC_BUFFER = 0x00;
	//	disable double baud rate
	CLR_BIT(USART_UCSRA_REG,USART_UCSRA_U2X);
	//	9600 ====> 103
	USART_UBRRL_REG = 103 ;
	//	char size ===> 8
	SET_BIT(USART_UCSRC_BUFFER ,USART_UCSRC_URSEL );
#if USART_CHAR_SIZE    ==   USART_CHAR_SIZE_5_BIT
	CLR_BIT(USART_UCSRC_BUFFER ,USART_UCSRC_UCSZ0 );
	CLR_BIT(USART_UCSRC_BUFFER ,USART_UCSRC_UCSZ1 );
	CLR_BIT(USART_UCSRB_REG ,USART_UCSRB_UCSZ2 );

#elif USART_CHAR_SIZE  ==   USART_CHAR_SIZE_6_BIT
	SET_BIT(USART_UCSRC_BUFFER ,USART_UCSRC_UCSZ0 );
	CLR_BIT(USART_UCSRC_BUFFER ,USART_UCSRC_UCSZ1 );
	CLR_BIT(USART_UCSRB_REG ,USART_UCSRB_UCSZ2 );

#elif USART_CHAR_SIZE  ==   USART_CHAR_SIZE_7_BIT
	CLR_BIT(USART_UCSRC_BUFFER ,USART_UCSRC_UCSZ0 );
	SET_BIT(USART_UCSRC_BUFFER ,USART_UCSRC_UCSZ1 );
	CLR_BIT(USART_UCSRB_REG ,USART_UCSRB_UCSZ2 );

#elif USART_CHAR_SIZE  ==   USART_CHAR_SIZE_8_BIT
	SET_BIT(USART_UCSRC_BUFFER ,USART_UCSRC_UCSZ0 );
	SET_BIT(USART_UCSRC_BUFFER ,USART_UCSRC_UCSZ1 );
	CLR_BIT(USART_UCSRB_REG ,USART_UCSRB_UCSZ2 );

#elif USART_CHAR_SIZE  ==   USART_CHAR_SIZE_9_BIT
	SET_BIT(USART_UCSRC_BUFFER ,USART_UCSRC_UCSZ0 );
	SET_BIT(USART_UCSRC_BUFFER ,USART_UCSRC_UCSZ1 );
	SET_BIT(USART_UCSRB_REG ,USART_UCSRB_UCSZ2 );

#else
#endif

	//	stop bit 1 ,, parity no
	SET_BIT(USART_UCSRC_BUFFER ,USART_UCSRC_URSEL );
#if USART_NO_OF_STOP_BIT   == USART_STOP_BIT_1
	CLR_BIT(USART_UCSRC_BUFFER ,USART_UCSRC_USBS);
#elif USART_NO_OF_STOP_BIT   == USART_STOP_BIT_2
	SET_BIT(USART_UCSRC_BUFFER ,USART_UCSRC_USBS);
#else
#endif
	//select PARITY MODE
#if  USART_PARITY_MODE == USART_PARITY_DIS
	CLR_BIT(USART_UCSRC_BUFFER,USART_UCSRC_UPM0);
	CLR_BIT(USART_UCSRC_BUFFER,USART_UCSRC_UPM1);
#elif  USART_PARITY_MODE == USART_PARITY_EVEN
	CLR_BIT(USART_UCSRC_BUFFER,USART_UCSRC_UPM0);
	SET_BIT(USART_UCSRC_BUFFER,USART_UCSRC_UPM1);

#elif  USART_PARITY_MODE == USART_PARITY_ODD
	SET_BIT(USART_UCSRC_BUFFER,USART_UCSRC_UPM0);
	SET_BIT(USART_UCSRC_BUFFER,USART_UCSRC_UPM1);

#else
#endif
	//select USART MODE ==> ASYNCHRONOUS
	CLR_BIT(USART_UCSRC_BUFFER,USART_UCSRC_UMSEL);

	//	enable send && Recieve
#if USART_SENDER_EN   ==   0
	SET_BIT(USART_UCSRB_REG,USART_UCSRB_TXEN);
#elif USART_SENDER_EN == 1
	SET_BIT(USART_UCSRB_REG,USART_UCSRB_TXEN);
#endif
#if USART_RECEIV_EN  ==   0
	CLR_BIT(USART_UCSRB_REG,USART_UCSRB_RXEN);
#elif USART_RECEIV_EN== 1
	SET_BIT(USART_UCSRB_REG,USART_UCSRB_RXEN);
#endif

	SET_BIT(USART_UCSRC_BUFFER,USART_UCSRC_URSEL);
	USART_UCSRC_REG=USART_UCSRC_BUFFER; // 0b10000110

}
void USART_voidSend(u16 Copy_u8DataToSend){
	//	wait on UDR Empty flag
	while(GET_BIT(USART_UCSRA_REG ,USART_UCSRA_UDRE ) == 0 )
	{
		//		do nothing
	}
	//	clear flag
	SET_BIT(USART_UCSRA_REG ,USART_UCSRA_UDRE );
#if USART_CHAR_SIZE  ==   USART_CHAR_SIZE_9_BIT    //3lshan al 9 bit special case
	u8 Local_u8_bit8 = GET_BIT(Copy_u8DataToSend , 8);   //bya5od al bit al 9 3ndo
	CLR_BIT(USART_UCSRB_REG ,USART_UCSRB_TXB8);    //3lshan ytaked anha fadya al awel
	USART_UCSRB_REG  |= Local_u8_bit8  ;           //y7ot al bitaya fy maknha USART_UCSRB_TXB8
#endif
	//	put data in UDR
	USART_UDR_REG = Copy_u8DataToSend ;  //save data gawa UDR_REG
}




u16   USART_u16_Receive(){
	u16 Local_u16DataToRec = 0x0000  ;
	//	wait on RXC flag (Busy wait )
	while(GET_BIT(USART_UCSRA_REG ,USART_UCSRA_RXC ) == 0 ){
		//		wait
	}
	//	clear flag
	SET_BIT(USART_UCSRA_REG ,USART_UCSRA_RXC );
#if USART_CHAR_SIZE  ==   USART_CHAR_SIZE_9_BIT
	u8 Local_u8_bit8 = GET_BIT(USART_UCSRB_REG ,USART_UCSRB_RXB8);
	Local_u16DataToRec |= Local_u8_bit8 << 8 ;

#endif
	Local_u16DataToRec |= USART_UDR_REG ;
	//	retrun UDR data
	return Local_u16DataToRec ;
}


void USART_voidReceiveData(u8* Copy_u8DataAdress){
	if(Copy_u8DataAdress != NULL){
		while(GET_BIT(USART_UCSRA_REG,USART_UCSRA_RXC) ==0 );
		* Copy_u8DataAdress=USART_UDR_REG;
	}
}




void USART_voidSendString(const u8 * Copy_pu8str)
{
	while(*Copy_pu8str != '\0')
		USART_voidSend(*Copy_pu8str++);
}


void USART_voidSendAsych(u16 Copy_u8DataToSend , void (*pf)(void)){

}
void USART_voidRecvAsych(u16* Copy_pu16DataToRecv, void (*pf)(void)){

}
void USART_voidSetCallBack_RXC(void (*pf)(void)){
	USART_CallBack_RXC = pf ;

}
void USART_voidSetCallBack_TXC(void (*pf)(void)){
	USART_CallBack_TXC = pf ;

}
void USART_voidSetCallBack_UDRE(void (*pf)(void)){
	USART_CallBack_UDRE= pf;
}

//rx compelete
void __vector_13  (void) __attribute__((signal));
void __vector_13  (void){
	if( USART_CallBack_RXC != NULL)
		{
			USART_CallBack_RXC();
		}
			}


//register empty
void __vector_14  (void) __attribute__((signal));
void __vector_14  (void){
	if( USART_CallBack_UDRE != NULL)
		{
			USART_CallBack_UDRE();
		}
			}


// tx compelte
void __vector_15  (void) __attribute__((signal));
void __vector_15  (void){
	if( USART_CallBack_TXC != NULL)
		{
			USART_CallBack_TXC();
		}
			}


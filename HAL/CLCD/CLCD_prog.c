#include "../../Service/STD_types.h"
#include "../../Service/bit_math.h"
#include "../../MCAl/DIO/DIO_int.h"
#include "CLCD_config.h"
#include "CLCD_int.h"
#include "CLCD_priv.h"
#include "util/delay.h"

static void CLCD_voidSendEnablePulse(){
	DIO_voidSetPinValue(CLCD_U8_CTRL_PORT , CLCD_U8_E_PIN , DIO_PIN_HIGH);
	_delay_ms(10);                                                             //E setting
	DIO_voidSetPinValue(CLCD_U8_CTRL_PORT , CLCD_U8_E_PIN , DIO_PIN_LOW);
}
#if CLCD_U8_MODE == CLCD_U8_4_BIT_MODE
static void CLCD_voidSetHalfPort(u8 Copy_u8Data){
	DIO_voidSetPinValue(CLCD_U8_DATA_PORT , CLCD_U8_DATA_PIN_0 , GET_BIT(Copy_u8Data,0));
	DIO_voidSetPinValue(CLCD_U8_DATA_PORT , CLCD_U8_DATA_PIN_1 , GET_BIT(Copy_u8Data,1));
	DIO_voidSetPinValue(CLCD_U8_DATA_PORT , CLCD_U8_DATA_PIN_2 , GET_BIT(Copy_u8Data,2));
	DIO_voidSetPinValue(CLCD_U8_DATA_PORT , CLCD_U8_DATA_PIN_3 , GET_BIT(Copy_u8Data,3));
}
#endif

void CLCD_voidSendData(u8 Copy_u8Data){
	DIO_voidSetPinValue(CLCD_U8_CTRL_PORT , CLCD_U8_RW_PIN , DIO_PIN_LOW);     //R/w setting
	DIO_voidSetPinValue(CLCD_U8_CTRL_PORT , CLCD_U8_RS_PIN , DIO_PIN_HIGH);    //R/s setting
#if CLCD_U8_MODE == CLCD_U8_8_BIT_MODE
	DIO_voidSetPortValue(CLCD_U8_DATA_PORT , Copy_u8Data);                     //Data
	CLCD_voidSendEnablePulse();
#elif CLCD_U8_MODE == CLCD_U8_4_BIT_MODE
	CLCD_voidSetHalfPort(Copy_u8Data>>4);
	CLCD_voidSendEnablePulse();
	CLCD_voidSetHalfPort(Copy_u8Data);
	CLCD_voidSendEnablePulse();
#endif
}

void CLCD_voidSendInstruction(u8 Copy_u8Instruction){
	DIO_voidSetPinValue(CLCD_U8_CTRL_PORT , CLCD_U8_RW_PIN , DIO_PIN_LOW);     //R/W Setting
	DIO_voidSetPinValue(CLCD_U8_CTRL_PORT , CLCD_U8_RS_PIN , DIO_PIN_LOW);     //R/S Setting
#if CLCD_U8_MODE == CLCD_U8_8_BIT_MODE
	DIO_voidSetPortValue(CLCD_U8_DATA_PORT , Copy_u8Instruction);              //Data
	CLCD_voidSendEnablePulse();
#elif CLCD_U8_MODE == CLCD_U8_4_BIT_MODE
	CLCD_voidSetHalfPort(Copy_u8Instruction>>4);
	CLCD_voidSendEnablePulse();
	CLCD_voidSetHalfPort(Copy_u8Instruction);
	CLCD_voidSendEnablePulse();
#endif
}

void CLCD_voidInit(void){
	_delay_ms(30);
#if CLCD_U8_MODE == CLCD_U8_8_BIT_MODE
	CLCD_voidSendInstruction(0b00111000);    //function set
#elif  CLCD_U8_MODE == CLCD_U8_4_BIT_MODE
	CLCD_voidSetHalfPort(0b0010);
	CLCD_voidSendEnablePulse();

	CLCD_voidSetHalfPort(0b0010);
	CLCD_voidSendEnablePulse();

	CLCD_voidSetHalfPort(0b1000);
	CLCD_voidSendEnablePulse();
#endif
	CLCD_voidSendInstruction(0b00001111);    //Display on/off
	CLCD_voidSendInstruction(0b00000001);             //clear

}

void CLCD_voidClearDisplay(){
	CLCD_voidSendInstruction(1);    //clear
}

void CLCD_voidSendString(char *str){
	u8 i = 0;
	while(str[i]!='\0'){
		CLCD_voidSendData(str[i]);
		i++;
	}
}

void CLCD_voidSendNumber(u16 Copy_u16num){
	u16 local_temp=0 , counter=0;
	if(Copy_u16num == 0){
		CLCD_voidSendData('0');
		return;
	}
	else{
	while((Copy_u16num%10)==0){
		Copy_u16num/=10;
		counter++;
	}
	while(Copy_u16num>0){
		local_temp = local_temp*10 + Copy_u16num%10;
		Copy_u16num/=10;
	}
	Copy_u16num = local_temp;
	while(Copy_u16num>0){
		CLCD_voidSendData(Copy_u16num%10 + '0');
		Copy_u16num/=10;
	}
	for(u8 i=0;i<counter;i++){
		CLCD_voidSendData('0');
	}
	}
}

void CLCD_voidSetCursorPosition(u8 Copy_u8x , u8 Copy_u8y){
	u8 Local_u8Address;
	Local_u8Address = Copy_u8x + Copy_u8y * 0x40;
	SET_BIT(Local_u8Address,7);
	CLCD_voidSendInstruction(Local_u8Address);
}

void CLCD_voidSendSpecialCharacter(u8 * Copy_Buffer , u8 Copy_Num , u8 Copy_u8x , u8 Copy_u8y){
	u8 Local_u8Address , Local_u8Counter = 0;
	Local_u8Address = Copy_Num * 8;
	SET_BIT(Local_u8Address ,6);
	CLCD_voidSendInstruction(Local_u8Address);
	for(Local_u8Counter=0;Local_u8Counter<8;Local_u8Counter++){
		CLCD_voidSendData(Copy_Buffer[Local_u8Counter]);
	}
	CLCD_voidSetCursorPosition(Copy_u8x , Copy_u8y);
	CLCD_voidSendData(Copy_Num);
}



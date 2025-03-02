#ifndef HAL_CLCD_CLCD_INT_H_
#define HAL_CLCD_CLCD_INT_H_

void CLCD_voidInit(void);
void CLCD_voidSendData(u8 Copy_u8Data);
void CLCD_voidSendInstruction(u8 Copy_u8Instruction);
void CLCD_voidSendString(char *);
void CLCD_voidSendNumber(u16 Copy_u16Num);
void CLCD_voidSetCursorPosition(u8 Copy_u8x , u8 Copy_u8y);
void CLCD_voidSendSpecialCharacter(u8 * Copy_Buffer , u8 Copy_Num , u8 Copy_u8x , u8 Copy_u8y);
void CLCD_voidClearDisplay();

#endif /* HAL_CLCD_CLCD_INT_H_ */

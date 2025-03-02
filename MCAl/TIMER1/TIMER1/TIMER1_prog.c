#include "../../../Service/STD_types.h"
#include "../../../Service/bit_math.h"
#include "TIMER1_priv.h"
#include "TIMER1_int.h"


void TIMER1_voidInit(){
	SET_BIT(TIMER1_TCCR1A_REG,TIMER1_TCCR1A_COM1A1);
	SET_BIT(TIMER1_TCCR1A_REG,TIMER1_TCCR1A_WGM11);
	SET_BIT(TIMER1_TCCR1B_REG,TIMER1_TCCR1B_WGM13);
	SET_BIT(TIMER1_TCCR1B_REG,TIMER1_TCCR1B_WGM12);
	SET_BIT(TIMER1_TCCR1B_REG,TIMER1_TCCR1B_CS11);
	TIMER1_TCR1_REG= 39999;

}

void TIMER1_voidSetPreloadValue(u16 Copy_u16PreLoad){
    TIMER1_TCNT1_REG = Copy_u16PreLoad;
}

void TIMER1_voidSetOCRValue(u16 Copy_u16value){
    TIMER1_OCR1A_REG = Copy_u16value;
}

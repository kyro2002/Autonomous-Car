#include "../../Service/STD_types.h"
#include "../../Service/bit_math.h"
#include "ADC_priv.h"
#include "ADC_int.h"

static u16* ADC_Res = NULL;
static void (*ADC_callBack)(void) = NULL;

void ADC_voidInit(){
	//set prescaler
	//choose 128   111
	SET_BIT(ADC_ADCSRA_REG,ADC_ADCSRA_ADPS0);
	SET_BIT(ADC_ADCSRA_REG,ADC_ADCSRA_ADPS1);
	SET_BIT(ADC_ADCSRA_REG,ADC_ADCSRA_ADPS2);
	//select ADC Reference
	//AVCC , AREF , 2.56
	//choose AVCC
	SET_BIT(ADC_ADMUX_REG,ADC_ADMUX_REFS0);
	CLR_BIT(ADC_ADMUX_REG,ADC_ADMUX_REFS1);
	//enable ADC
	SET_BIT(ADC_ADCSRA_REG,ADC_ADCSRA_ADEN);
}

u16 ADC_u16StartConversionSynch(u8 Copy_u8ChannelID ){ //TAKE CHANNEL TO READ FROM
	if(Copy_u8ChannelID <= 0b00011111){
	//select channel
	ADC_ADMUX_REG &= ADC_PRESCALER_MASK;
	ADC_ADMUX_REG |= Copy_u8ChannelID;
	}
	//start conversion
	SET_BIT(ADC_ADCSRA_REG,ADC_ADCSRA_ADSC);
	//wait on flag
	while(GET_BIT(ADC_ADCSRA_REG,ADC_ADCSRA_ADIF) == 0);
	//clear flag "set ADIF"
	SET_BIT(ADC_ADCSRA_REG,ADC_ADCSRA_ADIF);
	//return ADC data register
	return ADC_ADC_REG;
}

void ADC_voidStartConversionAsynch(u8 Copy_u8ChannelID,u16* Copy_u8Res,void (*pf)(void)){
	ADC_Res = Copy_u8Res;
	ADC_callBack = pf;
	//enable interrupt
	SET_BIT(ADC_ADCSRA_REG,ADC_ADCSRA_ADIE);
	if(Copy_u8ChannelID <= 0b00011111){
	//select channel
	ADC_ADMUX_REG &= ADC_PRESCALER_MASK;
	ADC_ADMUX_REG |= Copy_u8ChannelID;
	}
	//start conversion
	SET_BIT(ADC_ADCSRA_REG,ADC_ADCSRA_ADSC);

}

void __vector_16(void) __attribute__((signal));
void __vector_16(void){
	*ADC_Res = ADC_ADC_REG;
	if(ADC_callBack != NULL){
		ADC_callBack();
	}
}

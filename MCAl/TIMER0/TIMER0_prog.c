#include "../../Service/STD_types.h"
#include "../../Service/bit_math.h"
#include "TIMER0_config.h"
#include "TIMER0_priv.h"
#include "TIMER0_int.h"
static void (*TIMER0_OV_Callback)() = NULL;    //function global intialized with null
static void (*TIMER0_COMP_Callback)() = NULL;  //function global intialized with null
void TIMER0_voidInit(){
	//select prescalar
	TIMER0_TCCR0_REG &= TIMER0_PRESCALER_MASK ; //clear value of previous pre scaler and save the value of the remain bits
	TIMER0_TCCR0_REG |= TIMER0_PRESCALER ;   //OR with the new value from the config. file


#if TIMER0_MODE  == TIMER0_NORMAL_MODE
	//	choose normal mode
	CLR_BIT(TIMER0_TCCR0_REG , TIMER0_TCCR0_WGM00);
	CLR_BIT(TIMER0_TCCR0_REG , TIMER0_TCCR0_WGM01);
	//	enable to timer0 Overflow interrupt
	SET_BIT(TIMER0_TIMSK_REG, TIMER0_TIMSK_TOIE0);
	//	set intial value of TCNT
	TIMER0_TCNT0_REG = TIMER0_TCNT0_INITIAL_VAL ;
#elif TIMER0_MODE  == TIMER0_CTC_MODE
	//select CTC_MODE
	SET_BIT(TIMER0_TCCR0_REG , TIMER0_TCCR0_WGM01);
	CLR_BIT(TIMER0_TCCR0_REG , TIMER0_TCCR0_WGM00);
	//	enable to timer0 Overflow interrupt
	SET_BIT(TIMER0_TIMSK_REG, TIMER0_TIMSK_OCIE0);
	//	SET Initial value of OCR (compare value)
	TIMER0_OCR0_REG  = TIMER0_OCR0_INITIAL_VAL ;
#if    TIMER0_OC0_MODE    ==         TIMER0_OC0_DISCONNECTED
	CLR_BIT(TIMER0_TCCR0_REG , TIMER0_TCCR0_COM01);
	CLR_BIT(TIMER0_TCCR0_REG , TIMER0_TCCR0_COM00);
#elif  TIMER0_OC0_MODE    ==         TIMER0_OC0_TOGGLE_ON_CM
	SET_BIT(TIMER0_TCCR0_REG , TIMER0_TCCR0_COM00);
	CLR_BIT(TIMER0_TCCR0_REG , TIMER0_TCCR0_COM01);
#elif  TIMER0_OC0_MODE    ==         TIMER0_OC0_CLR_ON_CM
	CLR_BIT(TIMER0_TCCR0_REG , TIMER0_TCCR0_COM00);
	SET_BIT(TIMER0_TCCR0_REG , TIMER0_TCCR0_COM01);
#elif  TIMER0_OC0_MODE    ==         TIMER0_OC0_SET_ON_CM
	SET_BIT(TIMER0_TCCR0_REG , TIMER0_TCCR0_COM00);
	SET_BIT(TIMER0_TCCR0_REG , TIMER0_TCCR0_COM01);
#else
#warning " wronge OC0 mode"
#endif
#elif TIMER0_MODE  == TIMER0_FAST_PWM_MODE
	//SELECT FAST PWM MODE
	SET_BIT(TIMER0_TCCR0_REG , TIMER0_TCCR0_WGM01);
	SET_BIT(TIMER0_TCCR0_REG , TIMER0_TCCR0_WGM00);
	//SELECT OC0 MODE
#if  TIMER0_OC0_MODE    ==         TIMER0_INVERTING
	SET_BIT(TIMER0_TCCR0_REG , TIMER0_TCCR0_COM00);
	SET_BIT(TIMER0_TCCR0_REG , TIMER0_TCCR0_COM01);
#elif  TIMER0_OC0_MODE    ==         TIMER0_NONINVERTING
	CLR_BIT(TIMER0_TCCR0_REG , TIMER0_TCCR0_COM00);
	SET_BIT(TIMER0_TCCR0_REG , TIMER0_TCCR0_COM01);
#elif  TIMER0_OC0_MODE    ==         TIMER0_OC0_SET_ON_CM
	SET_BIT(TIMER0_TCCR0_REG , TIMER0_TCCR0_COM00);
	SET_BIT(TIMER0_TCCR0_REG , TIMER0_TCCR0_COM01);
#endif
#else
#warning "Wronge timer 0 mode "
#endif

}
void TIMER0_voidSetPreloadValue(u8 Copy_u8PreLoad){
	//
	TIMER0_TCNT0_REG = Copy_u8PreLoad ;
}
void TIMER0_voidSetOCRValue(u8 Copy_u8value){
	//
	TIMER0_OCR0_REG = Copy_u8value ;
}
/*
 * 20 *256
 */
void TIMER0_voidGenPWM(u8 Copy_u8pwm)  //take kam percent fy al PWM
{
#if TIMER0_OC0_MODE == TIMER0_NONINVERTING
	u8 local_pwm = ((Copy_u8pwm * 256) / 100)-1 ;
	TIMER0_OCR0_REG =  local_pwm ;
#elif TIMER0_OC0_MODE == TIMER0_INVERTING
	Copy_u8pwm=100-Copy_u8pwm;
	u8 local_pwm = ((Copy_u8pwm * 256) / 100)-1 ;
	TIMER0_OCR0_REG =  local_pwm ;
#endif
}
void TIMER0_voidSetCallBack_COMP(void (*pf)(void)){    //function take pointer to function
	TIMER0_COMP_Callback = pf ;
}
void TIMER0_voidSetCallBack_OV(void (*pf)(void)){      //function take pointer to function
	TIMER0_OV_Callback = pf ;
}

void __vector_10(void)  __attribute__((signal));   //ISR CODE
void __vector_10(void)  {
	//
	if(TIMER0_COMP_Callback != NULL)
	{
		TIMER0_COMP_Callback();
	}
		}

void __vector_11(void)  __attribute__((signal));   //ISR CODE
void __vector_11(void)  {
	//
	if(TIMER0_OV_Callback != NULL)
	{
		TIMER0_OV_Callback();
	}


}

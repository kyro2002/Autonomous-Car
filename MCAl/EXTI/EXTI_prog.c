#include "../../Service/STD_types.h"
#include "../../Service/bit_math.h"
#include "EXTI_priv.h"
#include "EXTI_config.h"
#include "EXTI_int.h"

static void (*INT0_Handler)(void);
static void (*INT1_Handler)(void);
static void (*INT2_Handler)(void);

void EXTI_EnableINT0(void){
    SET_BIT(EXTI_GICR_REG,EXTI_GICR_INT0);

}
void EXTI_EnableINT1(void){
	SET_BIT(EXTI_GICR_REG,EXTI_GICR_INT1);

}
void EXTI_EnableINT2(void){
	SET_BIT(EXTI_GICR_REG,EXTI_GICR_INT2);

}

void EXTI_DisableINT0(void){
	CLR_BIT(EXTI_GICR_REG,EXTI_GICR_INT0);
}
void EXTI_DisableINT1(void){
	CLR_BIT(EXTI_GICR_REG,EXTI_GICR_INT1);

}
void EXTI_DisableINT2(void){
	CLR_BIT(EXTI_GICR_REG,EXTI_GICR_INT2);

}

void EXTI_InitINT0(){
//	choose sense control
#if    EXTI_INT_0_SENSE == EXTI_RISIG_EDGE
	       SET_BIT(EXTI_MCUCR_REG,EXTI_MCUCR_ISC00);
	       SET_BIT(EXTI_MCUCR_REG,EXTI_MCUCR_ISC01);
#elif  EXTI_INT_0_SENSE == EXTI_FALLING_EDGE
	       CLR_BIT(EXTI_MCUCR_REG,EXTI_MCUCR_ISC00);
	       SET_BIT(EXTI_MCUCR_REG,EXTI_MCUCR_ISC01);
#elif  EXTI_INT_0_SENSE == EXTI_ANY_CHANGE
	       SET_BIT(EXTI_MCUCR_REG,EXTI_MCUCR_ISC00);
	       CLR_BIT(EXTI_MCUCR_REG,EXTI_MCUCR_ISC01);
#elif  EXTI_INT_0_SENSE == EXTI_LOW_LEVEL
	       CLR_BIT(EXTI_MCUCR_REG,EXTI_MCUCR_ISC00);
	       CLR_BIT(EXTI_MCUCR_REG,EXTI_MCUCR_ISC01);
#else
#Warming "worng sense int0 control"
#endif
//	enable
	       EXTI_EnableINT0();
}
void EXTI_InitINT1(){
//	choose sense control
#if    EXTI_INT_1_SENSE == EXTI_RISIG_EDGE
	       SET_BIT(EXTI_MCUCR_REG,EXTI_MCUCR_ISC10);
	       SET_BIT(EXTI_MCUCR_REG,EXTI_MCUCR_ISC11);
#elif  EXTI_INT_1_SENSE == EXTI_FALLING_EDGE
	       CLR_BIT(EXTI_MCUCR_REG,EXTI_MCUCR_ISC10);
	       SET_BIT(EXTI_MCUCR_REG,EXTI_MCUCR_ISC11);
#elif  EXTI_INT_1_SENSE == EXTI_ANY_CHANGE
	       SET_BIT(EXTI_MCUCR_REG,EXTI_MCUCR_ISC10);
	       CLR_BIT(EXTI_MCUCR_REG,EXTI_MCUCR_ISC11);
#elif  EXTI_INT_1_SENSE == EXTI_LOW_LEVEL
	       CLR_BIT(EXTI_MCUCR_REG,EXTI_MCUCR_ISC10);
	       CLR_BIT(EXTI_MCUCR_REG,EXTI_MCUCR_ISC11);
#else
#Warning "worng sense int1 control"
#endif
	       EXTI_EnableINT1();
}
void EXTI_InitINT2(){
//	choose sense control
#if    EXTI_INT_2_SENSE == EXTI_RISIG_EDGE
	       SET_BIT(EXTI_MCUCSR_REG,EXTI_MCUCSR_ISC2);
#elif  EXTI_INT_2_SENSE == EXTI_FALLING_EDGE
	       CLR_BIT(EXTI_MCUCSR_REG,EXTI_MCUCSR_ISC2);

#else
#Warning "worng sense int2 control"
#endif
	       EXTI_EnableINT2();
}

void EXTI_voidChangeSenseControl(u8 Copy_u8IntNum,u8 Copy_u8SenseNum){


}

void EXTI_voidSetINT0_Callback(void (*pf)(void)){
		INT0_Handler = pf;
}

void EXTI_voidSetINT1_Callback(void (*pf)(void)){
		INT1_Handler = pf;
}

void EXTI_voidSetINT2_Callback(void (*pf)(void)){
		INT2_Handler = pf;
}

void __vector_1(void) __attribute__((signal));  //hna da amr fy al ISR VECTOR 1 da rakmo fy al vector table w al goz2 al tany by3raf al linker an da ISR
void __vector_1(void){
	if(INT0_Handler != NULL){
		INT0_Handler();
	}
}

void __vector_2(void) __attribute__((signal));
void __vector_2(void){
	if(INT1_Handler != NULL){
		INT1_Handler();
	}
}

void __vector_3(void) __attribute__((signal));
void __vector_3(void){
	if(INT2_Handler != NULL){
		INT2_Handler();
	}
}


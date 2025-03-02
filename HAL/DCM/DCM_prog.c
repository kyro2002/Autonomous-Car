/*
 * DCM_prog.c
 *
 *  Created on: Oct 14, 2024
 *      Author: mario
 */

#include "../../Service/STD_types.h"
#include "../../Service/bit_math.h"
#include "../../MCAl/DIO/DIO_int.h"
#include "../../MCAl/TIMER0/TIMER0_int.h"
#include "DCM_int.h"
#include "DCM_config.h"

void DCM_u8MotorInit(u8 Copy_MotorId ,u8 Copy_MotorDir){
	if(Copy_MotorId == DCM_MOTOR_ID_A){
		DIO_voidSetPinValue(DIO_PORTD,DIO_PIN4,DIO_PIN_HIGH);
	}else if(Copy_MotorId == DCM_MOTOR_ID_B){
		DIO_voidSetPinValue(DIO_PORTD,DIO_PIN5,DIO_PIN_HIGH);
	}else{

	}
	if(Copy_MotorDir == DCM_MOTOR_DIR_CLOCKISE){
		DIO_voidSetPinValue(DIO_PORTC,DIO_PIN3,DIO_PIN_HIGH);
		DIO_voidSetPinValue(DIO_PORTC,DIO_PIN4,DIO_PIN_LOW);
	}else if(Copy_MotorDir == DCM_MOTOR_DIR_ANTICLOCKWISE){
		DIO_voidSetPinValue(DIO_PORTC,DIO_PIN5,DIO_PIN_LOW);
		DIO_voidSetPinValue(DIO_PORTC,DIO_PIN6,DIO_PIN_HIGH);
	}else{

	}
}
void DCM_u8MotorInitWithControlSpeed(u8 Copy_MotorId ,u8 Copy_MotorDir,u8 Copy_ControlSpeed){

}
void DCM_u8MotorTurnOff(u8 Copy_MotorId){
	if(Copy_MotorId == DCM_MOTOR_ID_A){
		DIO_voidSetPinValue(DIO_PORTD,DIO_PIN4,DIO_PIN_LOW);
	}else if(Copy_MotorId == DCM_MOTOR_ID_B){
		DIO_voidSetPinValue(DIO_PORTD,DIO_PIN5,DIO_PIN_LOW);
	}else{

	}
}






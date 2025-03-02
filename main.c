/*
 * main.c
 *
 *  Created on: Oct 1, 2024
 *      Author: Mario
 */

#include <util/delay.h>
#include "Service/STD_types.h"
#include "Service/bit_math.h"
#include "MCAl/DIO/DIO_int.h"
#include "MCAl/PORT/PORT_int.h"
#include "MCAl/TIMER1/TIMER1/TIMER1_int.h"
#include "MCAl/TIMER1/TIMER1/TIMER1_priv.h"
#include "HAL/CLCD/CLCD_int.h"
#include "HAL/ULTRASONIC/ultrasonic.h"
#include "HAL/SERVO/SERVO.h"
#define F_CPU 16000000UL

#define OBSTACLE_DISTANCE 20 // Minimum safe distance in cm

// Motor Control Pins
#define MOTOR1_F DIO_PIN3
#define MOTOR1_B DIO_PIN4
#define MOTOR2_F DIO_PIN5
#define MOTOR2_B DIO_PIN6

void MoveForward();
void StopCar();
void Turn_HalfLeft();
void Turn_Left();
void Turn_HalfRight();
void Turn_Right();
void Backward();

int main() {
    // System initialization
    PORT_voidInit();     // Initialize ports and directions
    CLCD_voidInit();     // Initialize LCD display
    TIMER1_voidInit();
    setServoAngle(90);
    CLCD_voidSendString("AUTONUMUS CAR");
    _delay_ms(1000);
    while (1) {
        	f32 distance = Ultrasonic_GetDistance();
        	if (distance < OBSTACLE_DISTANCE) {
            StopCar();
            _delay_ms(500);
            Backward();

            // Scan left and right with servo
            setServoAngle(0);   // Look right
            _delay_ms(500);
            f32 rightDistance = Ultrasonic_GetDistance();
            _delay_ms(500);

            setServoAngle(45);   // Look half right
            _delay_ms(500);
            f32 halfrightDistance = Ultrasonic_GetDistance();
            _delay_ms(500);

            setServoAngle(135);   // Look half left
            _delay_ms(500);
            f32 halfleftDistance = Ultrasonic_GetDistance();
            _delay_ms(500);

            setServoAngle(180); // Look left
            _delay_ms(500);
            f32 leftDistance = Ultrasonic_GetDistance();
            _delay_ms(500);

            setServoAngle(90);  // Center the servo
            _delay_ms(500);

            // Decide turn direction
            if (leftDistance > halfleftDistance && leftDistance > rightDistance && leftDistance > halfrightDistance) {
                Turn_Left();
            }
            else if (rightDistance > halfrightDistance && rightDistance > leftDistance && rightDistance > halfleftDistance){
                Turn_Right();
            }
            else if (halfleftDistance > leftDistance && halfleftDistance > halfrightDistance && halfleftDistance > rightDistance ){
                 Turn_HalfLeft();
            }
            else if (halfrightDistance > rightDistance && halfrightDistance > halfleftDistance && halfrightDistance > leftDistance){
                 Turn_HalfRight();
            }
        } else {
            MoveForward();
        }
    }
}
// Function to move the car forward
void MoveForward() {
	CLCD_voidClearDisplay();
	CLCD_voidSendString("THE CAR MOVING ");
	CLCD_voidSetCursorPosition(2,7);
	CLCD_voidSendString("FORWARD");
    DIO_voidSetPinValue(DIO_PORTC,MOTOR1_F,DIO_PIN_HIGH);
	DIO_voidSetPinValue(DIO_PORTC,MOTOR1_B,DIO_PIN_LOW);
	DIO_voidSetPinValue(DIO_PORTC,MOTOR2_F,DIO_PIN_HIGH);
	DIO_voidSetPinValue(DIO_PORTC,MOTOR2_B,DIO_PIN_LOW);
}

// Function to stop the car
void StopCar() {

	CLCD_voidClearDisplay();
	CLCD_voidSendString("THE CAR STOPPED ");
	DIO_voidSetPinValue(DIO_PORTC,MOTOR1_F,DIO_PIN_LOW);
	DIO_voidSetPinValue(DIO_PORTC,MOTOR1_B,DIO_PIN_LOW);
	DIO_voidSetPinValue(DIO_PORTC,MOTOR2_F,DIO_PIN_LOW);
	DIO_voidSetPinValue(DIO_PORTC,MOTOR2_B,DIO_PIN_LOW);

}
void Backward() {
	CLCD_voidClearDisplay();
	CLCD_voidSendString("THE CAR MOVING ");
	CLCD_voidSetCursorPosition(2,7);
	CLCD_voidSendString("BACKWARD");
	DIO_voidSetPinValue(DIO_PORTC,MOTOR1_F,DIO_PIN_LOW);
	DIO_voidSetPinValue(DIO_PORTC,MOTOR1_B,DIO_PIN_HIGH);
	DIO_voidSetPinValue(DIO_PORTC,MOTOR2_F,DIO_PIN_LOW);
	DIO_voidSetPinValue(DIO_PORTC,MOTOR2_B,DIO_PIN_HIGH);
    _delay_ms(500);
    StopCar();
}

// Function to turn the car half left
void Turn_HalfLeft() {
	CLCD_voidClearDisplay();
	CLCD_voidSendString("THE CAR MOVING ");
	CLCD_voidSetCursorPosition(2,1);
	CLCD_voidSendString("TO HALFLEFT");
	DIO_voidSetPinValue(DIO_PORTC,MOTOR1_F,DIO_PIN_HIGH);
	DIO_voidSetPinValue(DIO_PORTC,MOTOR1_B,DIO_PIN_LOW);
	DIO_voidSetPinValue(DIO_PORTC,MOTOR2_F,DIO_PIN_LOW);
	DIO_voidSetPinValue(DIO_PORTC,MOTOR2_B,DIO_PIN_HIGH);
    _delay_ms(500);
    StopCar();
}

// Function to turn the car left
void Turn_Left() {
	CLCD_voidClearDisplay();
	CLCD_voidSendString("THE CAR MOVING ");
	CLCD_voidSetCursorPosition(2,7);
	CLCD_voidSendString("TO LEFT");
	DIO_voidSetPinValue(DIO_PORTC,MOTOR1_F,DIO_PIN_HIGH);
	DIO_voidSetPinValue(DIO_PORTC,MOTOR1_B,DIO_PIN_LOW);
	DIO_voidSetPinValue(DIO_PORTC,MOTOR2_F,DIO_PIN_LOW);
	DIO_voidSetPinValue(DIO_PORTC,MOTOR2_B,DIO_PIN_HIGH);
    _delay_ms(1000);
    StopCar();
}

// Function to turn the car half right
void Turn_HalfRight() {
	CLCD_voidClearDisplay();
	CLCD_voidSendString("THE CAR MOVING ");
	CLCD_voidSetCursorPosition(2,1);
	CLCD_voidSendString("TO HALFRIGHT");
	DIO_voidSetPinValue(DIO_PORTC,MOTOR1_F,DIO_PIN_LOW);
	DIO_voidSetPinValue(DIO_PORTC,MOTOR1_B,DIO_PIN_HIGH);
	DIO_voidSetPinValue(DIO_PORTC,MOTOR2_F,DIO_PIN_HIGH);
	DIO_voidSetPinValue(DIO_PORTC,MOTOR2_B,DIO_PIN_LOW);
    _delay_ms(500);
    StopCar();
}


// Function to turn the car right
void Turn_Right() {
	CLCD_voidClearDisplay();
	CLCD_voidSendString("THE CAR MOVING ");
	CLCD_voidSetCursorPosition(2,7);
	CLCD_voidSendString("TO RIGHT");
	DIO_voidSetPinValue(DIO_PORTC,MOTOR1_F,DIO_PIN_LOW);
	DIO_voidSetPinValue(DIO_PORTC,MOTOR1_B,DIO_PIN_HIGH);
	DIO_voidSetPinValue(DIO_PORTC,MOTOR2_F,DIO_PIN_HIGH);
	DIO_voidSetPinValue(DIO_PORTC,MOTOR2_B,DIO_PIN_LOW);
    _delay_ms(1000);
    StopCar();
}

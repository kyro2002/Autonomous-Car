/*
 * ultrasonic.h
 *
 *  Created on: Jan 27, 2025
 *      Author: mario
 */

#ifndef HAL_ULTRASONIC_ULTRASONIC_H_
#define HAL_ULTRASONIC_ULTRASONIC_H_

#define TRIGGER_PIN    DIO_PIN1  // Example Trigger Pin
#define ECHO_PIN       DIO_PIN0  // Example Echo Pin
#define SOUND_SPEED 343 // Speed of sound in m/s
#define F_CPU 16000000UL

//void Ultrasonic_Init(void);
void Ultrasonic_Trigger(void);
u16 Ultrasonic_GetEcho(void);
float Ultrasonic_GetDistance(void);

#endif /* HAL_ULTRASONIC_ULTRASONIC_H_ */

/*
 * ultrasonic.c
 *
 *  Created on: Jan 27, 2025
 *      Author: mario
 */
#define F_CPU 16000000UL

#include "../../Service/STD_types.h"
#include "../../Service/bit_math.h"
#include "../../MCAl/DIO/DIO_int.h"
#include "../../MCAl/TIMER1/TIMER1/TIMER1_int.h"
#include "../../MCAl/TIMER1/TIMER1/TIMER1_priv.h"
#include "ultrasonic.h"
#include <util/delay.h>
// Function to send trigger pulse to ultrasonic sensor
void Ultrasonic_Trigger(void) {
    DIO_voidSetPinValue(DIO_PORTD, TRIGGER_PIN, DIO_PIN_LOW);  // Set trigger pin low
    _delay_us(2);  // Wait for 2us
    DIO_voidSetPinValue(DIO_PORTD, TRIGGER_PIN, DIO_PIN_HIGH); // Set trigger pin high
    _delay_us(10); // Send 10us pulse
    DIO_voidSetPinValue(DIO_PORTD, TRIGGER_PIN, DIO_PIN_LOW);  // Set trigger pin low
}

// Function to measure distance using ultrasonic sensor
f32 Ultrasonic_GetDistance(void) {
    Ultrasonic_Trigger();  // Trigger the ultrasonic sensor
    u16 count = 0;

    // Wait for echo to go HIGH
    while ((DIO_u8GetPinValue(DIO_PORTD,ECHO_PIN )) == 0) {
        count++;
        if (count > 30000) return 400; // No obstacle detected
    }

    // Measure the HIGH duration
    TIMER1_voidSetPreloadValue(0);
    while (DIO_u8GetPinValue(DIO_PORTD,ECHO_PIN) == 1) {
        if (TIMER1_TCNT1_REG > 60000) break; // Timeout
    }
    u16 duration = TIMER1_TCNT1_REG;

    // Calculate distance in cm
    u16 distance = (duration / 58);
    return distance;
}



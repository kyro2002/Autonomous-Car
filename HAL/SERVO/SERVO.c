/*
33 * SERVO.c
 *
 *  Created on: Jan 28, 2025
 *      Author: mario
 */


#include"SERVO.h"
void setServoAngle(u8 angle) {
    if (angle > 180) angle = 180; // Clamp to valid range
    TIMER1_OCR1A_REG = 1000 + (angle * (4000 / 180));
}


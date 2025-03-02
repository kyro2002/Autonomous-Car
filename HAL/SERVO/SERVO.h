/*
 * SERVO.h
 *
 *  Created on: Jan 28, 2025
 *      Author: mario
 */

#ifndef MCAL_SERVO_SERVO_H_
#define MCAL_SERVO_SERVO_H_

#define F_CPU 16000000UL
#include"../../Service/STD_types.h"
#include "../../Service/bit_math.h"
#include "../../MCAl/DIO/DIO_int.h"
#include "../../MCAl/TIMER1/TIMER1/TIMER1_int.h"
#include "../../MCAl/TIMER1/TIMER1/TIMER1_priv.h"
void setServoAngle(u8 angle);

#endif /* MCAL_SERVO_SERVO_H_ */

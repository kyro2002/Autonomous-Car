/*
 * DCM_int.h
 *
 *  Created on: Oct 14, 2024
 *      Author: mario
 */

#ifndef HAL_DCM_DCM_INT_H_
#define HAL_DCM_DCM_INT_H_

void DCM_u8MotorInit(u8 Copy_MotorId ,u8 Copy_MotorDir);
void DCM_u8MotorInitWithControlSpeed(u8 Copy_MotorId ,u8 Copy_MotorDir,u8 Copy_ControlSpeed);
void DCM_u8MotorTurnOff(u8 Copy_MotorId);

#endif /* HAL_DCM_DCM_INT_H_ */

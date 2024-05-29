/*
 * steering.h
 *
 *  Created on: May 28, 2024
 *      Author: M S I
 */

#ifndef INC_STEERING_H_
#define INC_STEERING_H_

#include "main.h"

void ProcessLidarData();
float CalculateSteeringAngle(float x, float y, float z);
void ControlServo(float SteeringAngle);

#endif /* INC_STEERING_H_ */

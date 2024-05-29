/*
 * steering.c
 *
 *  Created on: May 28, 2024
 *      Author: M S I
 */

#include "main.h"
#include "steering.h"
#include "stdint.h"
#include "stdio.h"
#include "math.h"


extern TIM_HandleTypeDef htim3;

#define pi 3.14159265358979323846

void ProcessLidarData(uint8_t *data){
	//Chuyển dữ liệu lidar từ dạng byte sang x,y,z
	float x,y,z;
	sscanf((char *)data, "%f,%f,%f", &x, &y, &z);
	// Tính toán góc lái từ dữ liệu LiDAR
	float SteeringAngle = CalculateSteeringAngle(x, y, z);
	// Điều khiển servo lái
	ControlServo(SteeringAngle);
}

float CalculateSteeringAngle(float x, float y, float z){
	float angle = atan2(x,y); // xe đi theo trục y
	return angle*(180.0/pi);
}

void ControlServo(float angle){
	uint32_t PWM = angle*1.5+75; // 0 độ là 75
	__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_2,PWM);
}

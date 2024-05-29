/*
 * button.c
 *
 *  Created on: Mar 11, 2024
 *      Author: M S I
 */

#include "button.h"

int KeyReg0  = NORMAL_STATE;
int KeyReg1  = NORMAL_STATE;
int KeyReg2  = NORMAL_STATE;
int KeyReg3  = NORMAL_STATE;

int KeyReg4  = NORMAL_STATE;
int KeyReg5  = NORMAL_STATE;
int KeyReg6  = NORMAL_STATE;
int KeyReg7  = NORMAL_STATE;

int KeyReg8  = NORMAL_STATE;
int KeyReg9  = NORMAL_STATE;
int KeyReg10 = NORMAL_STATE;
int KeyReg11 = NORMAL_STATE;


int button1_flag = 0;
int button2_flag = 0;
int button3_flag = 0;

int isButton1Pressed(){
	if(button1_flag == 1){
		button1_flag = 0;
		return 1;
	}
	return 0;
}
int isButton2Pressed(){
	if(button2_flag == 1){
		button2_flag = 0;
		return 1;
	}
	return 0;
}
int isButton3Pressed(){
	if(button3_flag == 1){
		button3_flag = 0;
		return 1;
	}
	return 0;
}

void getKeyInput(){
	KeyReg0 = KeyReg1;
	KeyReg1 = KeyReg2;
	KeyReg2 = HAL_GPIO_ReadPin(START_GPIO_Port, START_Pin);
	if((KeyReg0 == KeyReg1) && (KeyReg1 == KeyReg2)){
		if(KeyReg3 != KeyReg2){
			KeyReg3 = KeyReg2;
			if(KeyReg2 == PRESSED_STATE){
				button1_flag = 1;
			}
		}
	}
	KeyReg4 = KeyReg5;
	KeyReg5 = KeyReg6;
	KeyReg6 = HAL_GPIO_ReadPin(VIBE_GPIO_Port, VIBE_Pin);
	if((KeyReg4 == KeyReg5) && (KeyReg5 == KeyReg6)){
		if(KeyReg7 != KeyReg6){
			KeyReg7 = KeyReg6;
			if(KeyReg6 == PRESSED_STATE){
				button2_flag = 1;
			}
		}
	}
	KeyReg8 = KeyReg9;
	KeyReg9 = KeyReg10;
	KeyReg10 = HAL_GPIO_ReadPin(STOP_GPIO_Port,STOP_Pin);
	if((KeyReg8 == KeyReg9) && (KeyReg9 == KeyReg10)){
		if(KeyReg11 != KeyReg10){
			KeyReg11 = KeyReg10;
			if(KeyReg10 == PRESSED_STATE){
				button3_flag = 1;
			}
		}
	}
}


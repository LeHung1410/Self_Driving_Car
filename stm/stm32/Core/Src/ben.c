/*
 * ben.c
 *
 *  Created on: Mar 12, 2024
 *      Author: M S I
 */

#include "ben.h"
#include "button.h"
#include "global.h"

void nangha(){
	switch(status){
	case INIT:
		//HAL_GPIO_WritePin(ENA_GPIO_Port,ENA_Pin,RESET);
		HAL_GPIO_WritePin(IN1_GPIO_Port,IN1_Pin,RESET);
		HAL_GPIO_WritePin(IN2_GPIO_Port,IN2_Pin,RESET);
		if(isButton1Pressed() == 1){
			status = START;
		}
		break;
	case START:
		//HAL_GPIO_WritePin(ENA_GPIO_Port,ENA_Pin,SET);
		HAL_GPIO_WritePin(IN1_GPIO_Port,IN1_Pin,SET);
		HAL_GPIO_WritePin(IN2_GPIO_Port,IN2_Pin,RESET);

		if(isButton2Pressed() == 1){
			status = VIBE;
			setTimer1(100);
		}
		break;
	case VIBE:
		//HAL_GPIO_WritePin(ENA_GPIO_Port,ENA_Pin,SET);
		HAL_GPIO_WritePin(IN1_GPIO_Port,IN1_Pin,RESET);
		HAL_GPIO_WritePin(IN2_GPIO_Port,IN2_Pin,SET);
		if(timer1_flag == 1){
			int i = 0;
			while(i < 20){
				//HAL_GPIO_WritePin(ENA_GPIO_Port,ENA_Pin,SET);
				HAL_GPIO_WritePin(IN1_GPIO_Port,IN1_Pin,SET);
				HAL_GPIO_WritePin(IN2_GPIO_Port,IN2_Pin,RESET);

					HAL_Delay(250);

				HAL_GPIO_WritePin(IN1_GPIO_Port,IN1_Pin,RESET);
				HAL_GPIO_WritePin(IN2_GPIO_Port,IN2_Pin,SET);

					HAL_Delay(250);
				i++;
			}
		status = STOP;
		}
		break;
	case STOP:
		//HAL_GPIO_WritePin(ENA_GPIO_Port,ENA_Pin,SET);
		HAL_GPIO_WritePin(IN1_GPIO_Port,IN1_Pin,RESET);
		HAL_GPIO_WritePin(IN2_GPIO_Port,IN2_Pin,SET);
		if(isButton3Pressed() == 1){
			status = INIT;
		}
		break;
	default:
		break;
	}
}

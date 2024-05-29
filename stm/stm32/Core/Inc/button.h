/*
 * button.h
 *
 *  Created on: Mar 11, 2024
 *      Author: M S I
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NORMAL_STATE SET
#define PRESSED_STATE RESET

int isButton1Pressed();
int isButton2Pressed();
int isButton3Pressed();

void getKeyInput();

#endif /* INC_BUTTON_H_ */

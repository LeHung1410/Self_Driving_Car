/*
 * software_timer.c
 *
 *  Created on: Mar 12, 2024
 *      Author: M S I
 */

int timer1_counter = 0;
int timer1_flag = 0;

void setTimer1(int duration){
	timer1_counter = duration;
	timer1_flag = 0;
}
void timerRun(){
	if(timer1_counter > 0) timer1_counter--;
	if(timer1_counter == 0) timer1_flag = 1;
}

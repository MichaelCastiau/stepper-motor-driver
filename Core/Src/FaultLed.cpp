/*
 * FaultLed.cpp
 *
 *  Created on: Feb 8, 2020
 *      Author: michael
 */

#include "FaultLed.h"

FaultLed::FaultLed() {
	// TODO Auto-generated constructor stub

}

FaultLed::~FaultLed() {
	// TODO Auto-generated destructor stub
}

void FaultLed::tick() {
	if (this->status == BLINKING) {
		HAL_GPIO_TogglePin(FAULT_LED_PORT, FAULT_LED_PIN);
	}
}

void FaultLed::turnOff(void) {
	this->status = OFF;
	HAL_GPIO_WritePin(FAULT_LED_PORT, FAULT_LED_PIN, GPIO_PIN_SET);
}
void FaultLed::turnOn(void) {
	this->status = ON;
	HAL_GPIO_WritePin(FAULT_LED_PORT, FAULT_LED_PIN, GPIO_PIN_RESET);
}
void FaultLed::blink(void) {
	this->status = BLINKING;
}

/*
 * StepperMotor.cpp
 *
 *  Created on: Feb 8, 2020
 *      Author: michael
 */

#include "StepperMotor.h"

StepperMotor::StepperMotor() {
	// TODO Auto-generated constructor stub

}

StepperMotor::~StepperMotor() {
	// TODO Auto-generated destructor stub
}

Direction StepperMotor::getDirection() {
	return this->direction;
}
void StepperMotor::setDirection(Direction direction) {
	this->direction = direction;
}

void StepperMotor::onFault(callback *fn) {
	this->onFaultCallback = fn;
}

void StepperMotor::onRecoverFromFault(callback *fn) {
	this->onRecoverFromFaultCallback = fn;
}

void StepperMotor::tick(void) {
	//Read the fault status
	const GPIO_PinState fault = HAL_GPIO_ReadPin(FAULT_PORT, FAULT_PIN);
	if (fault == GPIO_PIN_SET && this->status == NORMAL) {
		//Oops, there is a problem!!
		this->status = FAULT;
		if (this->onFaultCallback)
			this->onFaultCallback();
	} else if (fault == GPIO_PIN_RESET && this->status == FAULT) {
		this->status = NORMAL;
		if (this->onRecoverFromFaultCallback)
			this->onRecoverFromFaultCallback();
	}
}


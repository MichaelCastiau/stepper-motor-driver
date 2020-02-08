/*
 * MotorController.cpp
 *
 *  Created on: Feb 8, 2020
 *      Author: michael
 */

#include "MotorController.h"

MotorController::MotorController(StepperMotor *motor, FaultLed* led) {
	this->faultLed = led;
	this->motor = motor;

	//By default the led will turn on since the module is not initialized yet
	this->faultLed->turnOn();
}

MotorController::~MotorController() {
	delete this->faultLed;
	delete this->motor;
}

void MotorController::initialize(void) {
	//TODO initialize the module

	this->faultLed->turnOff();
}

void MotorController::tick(void) {
	this->motor->tick();
}

void MotorController::fault(void) {
	this->stop();
	this->faultLed->blink();
}

void MotorController::setDirection(Direction direction) {
	this->motor->setDirection(direction);
}
Direction MotorController::getDirection(void) {
	return this->motor->getDirection();
}

void MotorController::start(uint32_t speed, Direction direction) {
	this->motor->setDirection(direction);
	this->speed = speed;
	this->status = RUNNING;
}

void MotorController::stop(void) {
	this->status = STOPPED;
	// TODO stop the steps!!
}


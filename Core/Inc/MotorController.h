#include "FaultLed.h"
#include "StepperMotor.h"
/*
 * MotorController.h
 *
 *  Created on: Feb 8, 2020
 *      Author: michael
 */

#ifndef MOTORCONTROLLER_H_
#define MOTORCONTROLLER_H_

enum Status {
	STOPPED = 0, RUNNING = 1
};

class MotorController {
private:
	Status status = STOPPED;
	uint32_t speed = 0;
	FaultLed *faultLed;
	StepperMotor *motor;
public:
	MotorController(StepperMotor* motor, FaultLed* led);
	virtual ~MotorController();

	/**
	 * This method should be called every 1ms
	 * for good performance of the motor.
	 * Set a timer in interrupt mode ;)
	 */
	void tick(void);
	/*
	 * Blocking action! Initializes the necessary
	 * hardware for motor operation.
	 */
	void initialize(void);

	void setDirection(Direction direction);
	void stop();
	/**
	 * Starts the motor by setting the speed in rotations/minute
	 * Default direction of the motor is clockwise
	 */
	void start(uint32_t speed, Direction direction = CLOCKWISE);
	void fault(void);

	Direction getDirection();
};

#endif /* MOTORCONTROLLER_H_ */

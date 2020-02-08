#include <stdint.h>
#include "definitions.h"
#include "system_ports.h"

/*
 * StepperMotor.h
 *
 *  Created on: Feb 8, 2020
 *      Author: michael
 */

#ifndef STEPPERMOTOR_H_
#define STEPPERMOTOR_H_

enum Direction {
	CLOCKWISE = 0, COUNTERCLOCKWISE = 1
};

enum MotorStatus {
	NORMAL = 0, FAULT = 1
};

class StepperMotor {
private:
	Direction direction = CLOCKWISE;
	MotorStatus status = NORMAL;
	callback *onFaultCallback;
	callback *onRecoverFromFaultCallback;
public:
	StepperMotor();
	virtual ~StepperMotor();

	void tick(void);

	void step(void);
	void setDirection(Direction direction);

	Direction getDirection(void);
	void onFault(callback *fn);
	void onRecoverFromFault(callback* fn);
};

#endif /* STEPPERMOTOR_H_ */

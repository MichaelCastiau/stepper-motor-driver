#include "system_ports.h"

/*
 * FaultLed.h
 *
 *  Created on: Feb 8, 2020
 *      Author: michael
 */

#ifndef FAULTLED_H_
#define FAULTLED_H_

enum LedStatus {
	OFF = 0, ON = 1, BLINKING = 2
};

class FaultLed {
private:
	LedStatus status = OFF;
public:
	FaultLed();
	virtual ~FaultLed();

	void tick(void);
	void turnOn(void);
	void turnOff(void);
	void blink(void);
};

#endif /* FAULTLED_H_ */

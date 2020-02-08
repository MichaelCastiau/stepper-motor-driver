#include "stm32f0xx.h"

/*
 * ports.h
 *
 *  Created on: Feb 8, 2020
 *      Author: michael
 */

#ifndef INC_SYSTEM_PORTS_H_
#define INC_SYSTEM_PORTS_H_


#define ENABLE_LEVEL_SHIFTER_PORT GPIOA
#define ENABLE_LEVEL_SHIFTER_PIN GPIO_PIN_7

#define FAULT_PORT GPIOB
#define FAULT_PIN GPIO_PIN_0

#define SLEEP_PORT GPIOB
#define SLEEP_PIN GPIO_PIN_1

#define DIRECTION_PORT GPIOB
#define DIRECTION_PIN GPIO_PIN_2

#define FN1_PORT GPIOB
#define FN1_PIN GPIO_PIN_6

#define RESET_PORT GPIOB
#define RESET_PIN GPIO_PIN_7

#define STEP_PORT GPIOB
#define STEP_PIN GPIO_PIN_10

#define FAULT_LED_PORT GPIOB
#define FAULT_LED_PIN GPIO_PIN_12

#endif /* INC_SYSTEM_PORTS_H_ */

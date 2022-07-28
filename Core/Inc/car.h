#ifndef __CAR_H

#include "stm32f4xx_hal.h"
#include "gpio.h"

void Car_Move(uint8_t direction, uint16_t Times);
void Car_Turn(uint8_t direction, uint16_t Times);

#endif
#include "stm32f4xx_hal.h"
#include "tim.h"
#include "car.h"
#include "math.h"

short GetSpeed();
short PID_Cal(short Speed,short *error);
void SetMotorVoltageAndDirection(int Pwm);
#include "pid.h"


int Timer = 0;			//时间
uint8_t speed = 0;		//当前PWM
short TargetSpeed = 10; //目标速度

/*PID参数*/
#define kp 0.86
#define ki 0.012
#define kd 0.005


/******************************
	功能：每5ms在定时器中执行一次，
				获取电机速度SPEED
	返回值：电机速度SPEED
	形参：无
*******************************/
short GetSpeed()
{
	short SPEED = 0;
//	static short last = 0;
	SPEED = (short)(__HAL_TIM_GET_COUNTER(&htim3)*100)/(4*16*10);
	__HAL_TIM_SET_COUNTER(&htim3,0);
	return SPEED;
}


/******************************
	功能：每5ms在定时器中执行一次，
				计算pwm返回值
	返回值：电机速度SPEED
	形参：无
*******************************/
short PID_Cal(short Speed,short *error)
{
	short Error = TargetSpeed - Speed;
	static short Error_last = 0,Error_prev = 0;
	short pwm_add=0;
	*error = Error;
	pwm_add = kp*(Error - Error_last) + ki*Error + kd*(Error-2.0f*Error_last+Error_prev);
	
	Error_prev = Error_last;	  	    // 保存上上次误差
  Error_last = Error;	              // 保存上次偏差
	
	
	return pwm_add;
}
/******************************
	功能：判断电机正反转，
			并将计算所得的PWM数值
			写入单片机中
	返回值：无
	形参：无
*******************************/
void SetMotorVoltageAndDirection(int Pwm)
{
	if(Pwm<0)
	{
		Car_Move(0, 1000);
	}
	else if(Pwm>0)
	{
		Car_Move(1, 1000);
	}
	Pwm = fabs(Pwm);
  TIM1->CCR1 = Pwm;
}
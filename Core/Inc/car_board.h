#ifndef __CAR_BOARD_H

#include "i2c.h"
#include "stdint.h"

//器件地址宏定义
#define Board_Addr                      0x34        //驱动板的I2C地址

//内部寄存器地址宏定义
#define ADC_Bat_Addr                    0x00        //电池电压寄存器地址
#define Motor_Type_Addr                 0x20        //马达类型寄存器地址
#define Motor_Encoder_Polarity_Addr     0x21
#define Motor_Fixed_Pwm_Addr            0x31
#define Motor_Fixed_Speed_Addr          0x51
#define Motor_Encoder_Total_Addr        0x60

//马达类型宏定义
#define MOTOR_TYPE_WITHOUT_ENCODER        0 		//无编码器的电机,磁环每转是44个脉冲减速比:90  默认
#define MOTOR_TYPE_TT                     1 		//TT编码电机
#define MOTOR_TYPE_N20                    2 		//N20编码电机
#define MOTOR_TYPE_JGB37_520_12V_110RPM   3         //磁环每转是44个脉冲   减速比:90  默认

uint8_t I2C_Read_Len(uint8_t Reg, uint8_t *Buf, uint8_t Len);
uint8_t I2C_Write_Len(uint8_t Reg, uint8_t *Buf, uint8_t Len);
void Set_Motor_Type(uint8_t Motor_Type);
void Set_Motor_Polarity(uint8_t Polarity);
uint8_t Read_Encoder();
void Motor_Go_Fixed(uint8_t Speed[4]);
void Motor_Go_NoFixed(uint8_t Speed[4]);

#endif
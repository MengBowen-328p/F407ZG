#include "car.h"

uint8_t I2C_Read_Len(uint8_t Reg, uint8_t *Buf, uint8_t Len)
{
    uint8_t i = 0;

    for (i = 0; i <= Len; i++)
    {
        if (i <= Len)
        {
            HAL_I2C_Mem_Read(&hi2c1, (Board_Addr | 1), Reg, I2C_MEMADD_SIZE_8BIT, &Buf[i], Len, 0xff);
            HAL_Delay(10);
            if(HAL_I2C_Mem_Read(&hi2c1, (Board_Addr | 1), Reg, I2C_MEMADD_SIZE_8BIT, &Buf[i], Len, 0xff)==HAL_OK)
            {
                return 0;
            }
            else
            {
                return 1;
            }
        }
    }
    return 0;
}

uint8_t I2C_Write_Len(uint8_t Reg, uint8_t *Buf, uint8_t Len)
{
    uint8_t i = 0;
    for (i = 0; i <= Len; i++)
    {
        if (i <= Len)
        {
            HAL_I2C_Mem_Write(&hi2c1, (Board_Addr | 0), Reg, I2C_MEMADD_SIZE_8BIT, &Buf[i], Len, 0xff);
            HAL_Delay(10);
            if(HAL_I2C_Mem_Write(&hi2c1, (Board_Addr | 0), Reg, I2C_MEMADD_SIZE_8BIT, &Buf[i], Len, 0xff)==HAL_OK)
            {
                return 0;
            }
            else
            {
                return 1;
            }
        }
    }
    return 0;
}

void Set_Motor_Type(uint8_t Motor_Type)
{
    I2C_Write_Len(Motor_Type_Addr, &Motor_Type, 1);
    HAL_Delay(10);
}
//说明：设定电机类型,

void Set_Motor_Polarity(uint8_t Polarity)
{
    I2C_Write_Len(Motor_Encoder_Polarity_Addr, &Polarity, 1);
    HAL_Delay(10);
}
//说明：设定电机编码器极性

uint8_t Read_Encoder()
{
    static uint8_t EncoderTotal[4];//设置静态变量，防止返回值消失,
    I2C_Read_Len(Motor_Encoder_Total_Addr, (uint8_t*)EncoderTotal, 16);
    HAL_Delay(10);
    return EncoderTotal;//强制返回数组
}
//说明：读取四颗电机编码器信息

void Motor_Go_Fixed(uint8_t Speed[4])
{
    I2C_Write_Len(Motor_Fixed_Speed_Addr, &Speed[4], 4);
    HAL_Delay(10);
}
//说明：四颗电机速度环闭环控制（无PID）

void Motor_Go_NoFixed(uint8_t Speed[4])
{
    I2C_Write_Len(Motor_Fixed_Pwm_Addr, &Speed[4], 4);
    HAL_Delay(10);
}
//说明：四颗电机PWM开环控制（无PID）

uint8_t Read_Bat_Voltage()
{
    uint8_t data[2];
    uint8_t v;
	I2C_Read_Len(ADC_Bat_Addr,data,2);									//读取电机电压
	v = data[0] + (data[1]<<8);
    return v;    
}





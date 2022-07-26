#include "led.h"


void Led_Flash(void)
{
    HAL_GPIO_WritePin(BSP_LED_GPIO_Port,BSP_LED_Pin,GPIO_PIN_SET);
    HAL_Delay(1000);
    HAL_GPIO_WritePin(BSP_LED_GPIO_Port,BSP_LED_Pin,GPIO_PIN_RESET);
    HAL_Delay(1000);
    HAL_GPIO_WritePin(BSP_LED_GPIO_Port,BSP_LED_Pin,GPIO_PIN_SET);
    HAL_Delay(100);
    HAL_GPIO_WritePin(BSP_LED_GPIO_Port,BSP_LED_Pin,GPIO_PIN_RESET);
    HAL_Delay(100);
}
#include "task.h"
extern IWDG_HandleTypeDef hiwdg;
volatile uint32_t tick = 0;

void Task_Init(void){
    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);
}

#ifdef __cplusplus
extern "C"{
#endif

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
    if(htim -> Instance == TIM2){
        tick++;
        HAL_IWDG_Refresh(&hiwdg);
    }
}
#ifdef __cplusplus
}
#endif
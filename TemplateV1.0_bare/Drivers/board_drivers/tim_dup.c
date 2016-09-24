/**
  * @file    tim_dup.c 
  * @author  Z B T
  * @version V0.1
  * @date    2016-03-31
  * @brief   ͨ�ö�ʱ�����ú���
  *
  */  

/* Includes ------------------------------------------------------------------*/
#include "tim_dup.h"
//#include "delay.h"
//#include "led.h"

/* Private define ------------------------------------------------------------*/
#define NUM_BASE_TIMx      (sizeof(timer_x) / sizeof(timer_x[0]))
    
/* External variables --------------------------------------------------------*/


/* Private variables ---------------------------------------------------------*/

const struct BASE_TIMER_X timer_x[] = 
{   /**< ��ʱ�� Ԥ��Ƶֵ ���� ʱ�ӷ�Ƶ ����ģʽ �жϷ�ʽ ʹ�� */
    TIM2, 5000, 7199, 0, TIM_CounterMode_Up, TIM_IT_Update, ENABLE,
    TIM3, 5000, 7199, 0, TIM_CounterMode_Up, TIM_IT_Update, ENABLE,
//    TIM4, 5000, 7199, 0, TIM_CounterMode_Up, TIM_IT_Update, ENABLE,  
};
   
static uint8_t timer_flag[] = {0, 0, 0,};

/* Public function prototypes -----------------------------------------------*/

/**
 *  @brief  �����ⲿ�жϵ�GPIO NVIC EXTI��ز���
 *  @param	None
 *  @return None
 */
void set_timer_flag(enum BASE_TIM_N timer_n)
{
    timer_flag[timer_n] = 1;
}

/**
 *  @brief  �����ⲿ�жϵ�GPIO NVIC EXTI��ز���
 *  @param	None
 *  @return None
 */
uint8_t read_timer_flag(enum BASE_TIM_N timer_n)
{
    uint8_t tmp_flag = 0;
    
    tmp_flag = timer_flag[timer_n];
    timer_flag[timer_n] = 0;          /**< ����жϱ�־λ */
    
    return tmp_flag;
}

/**
 *  @brief  �����ⲿ�жϵ�GPIO NVIC EXTI��ز���
 *  @param	None
 *  @return None
 */
void BASE_TIM_config(void)
{
    uint8_t i = 0;
	TIM_TimeBaseInitTypeDef		TIM_TimeBaseStructure;
   
    /**< ��ʱ����ʼ������ */
    for (i = 0; i < NUM_BASE_TIMx; i++)
    {
        TIM_TimeBaseStructure.TIM_Period        = timer_x[i].period;
        TIM_TimeBaseStructure.TIM_Prescaler     = timer_x[i].prescaler;
        TIM_TimeBaseStructure.TIM_ClockDivision = timer_x[i].clk_div;
        TIM_TimeBaseStructure.TIM_CounterMode   = timer_x[i].cnt_mode;
        TIM_TimeBaseInit(timer_x[i].TIMx, &TIM_TimeBaseStructure);
        TIM_Cmd(timer_x[i].TIMx, timer_x[i].cmd);
        TIM_ITConfig(timer_x[i].TIMx, timer_x[i].tim_it, timer_x[i].cmd);
    }
}

/* Private function prototypes -----------------------------------------------*/


/**
*  @brief   ������ʱ��2�жϴ������
*  @param	None
*  @return 	None
*/
void TIM2_IRQHandler(void)
{
    uint8_t i = 0;
    
    if (TIM_GetITStatus(timer_x[i].TIMx, timer_x[i].tim_it) != RESET)
    {
        set_timer_flag(TIMER_2);
        TIM_ClearITPendingBit(timer_x[i].TIMx, timer_x[i].tim_it);
    }  
}

/**
*  @brief   ������ʱ��3�жϴ������
*  @param	None
*  @return 	None
*/
void TIM3_IRQHandler(void)
{
    uint8_t i = 0;
    
    if (TIM_GetITStatus(timer_x[i].TIMx, timer_x[i].tim_it) != RESET)
    {
        set_timer_flag(TIMER_3);
        TIM_ClearITPendingBit(timer_x[i].TIMx, timer_x[i].tim_it);
    }        
    
}

/**
*  @brief   ������ʱ��4�жϴ������
*  @param	None
*  @return 	None
*/
void TIM4_IRQHandler(void)
{
    
}

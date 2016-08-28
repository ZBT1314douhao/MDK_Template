/**
  * @file    led.c 
  * @author  Z B T
  * @version V0.1
  * @date    2016-01-29
  * @brief   
  */  

/* Includes ------------------------------------------------------------------*/
#include "led.h"

/* Private function prototypes ------------------------------------------------*/


/**
  *  @brief  led��ʼ������
  *  @param  None
  *  @retval None
  */
void LED_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    
    GPIO_InitStructure.GPIO_Pin   = GPIO_LED_All;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP;
    /** GPIOB Periphʱ��ʹ�� */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    GPIO_Init(GPIO_LED, &GPIO_InitStructure);                 /**< ��ʼ����������led�Ķ˿� */
    
    GPIO_ResetBits(GPIO_LED, GPIO_Pin_All);                      /**< �رտ����������е�(8��)led */
}

/**
  *  @brief  ����led
  *  @param  None
  *  @retval None
  */
void LED_On(GPIO_TypeDef* GPIOx, uint16_t GPIO_LED_x)
{
    GPIO_SetBits(GPIOx, GPIO_LED_x); 
}

/**
  *  @brief  Ϩ��led
  *  @param  None
  *  @retval None
  */
void LED_Off(GPIO_TypeDef* GPIOx, uint16_t GPIO_LED_x)
{
    GPIO_ResetBits(GPIOx, GPIO_LED_x);
}


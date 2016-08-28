/**
  * @file    key.c 
  * @author  Z B T
  * @version V0.1
  * @date    2016-01-29
  * @brief   
  */  

/* Includes ------------------------------------------------------------------*/
#include "key.h"


/**
  *  @brief  ����������ʼ������
  *  @param  None
  *  @retval None
  */
void KEY_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    
    GPIO_InitStructure.GPIO_Pin   = GPIO_KEY_All;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_IN_FLOATING;      /**< ���ó�����ʽ���� */
    /** GPIOB Periphʱ��ʹ�� */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
    GPIO_Init(GPIO_KEY, &GPIO_InitStructure);                 /**< ��ʼ����������led�Ķ˿� */
}

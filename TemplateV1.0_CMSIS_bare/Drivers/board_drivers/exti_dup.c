/**
  * @file    exti_dup.c 
  * @author  Z B T
  * @version V0.1
  * @date    2016-03-16
  * @brief   
  */  

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x_exti.h"
#include "exti_dup.h"
#include "delay.h"
#include "led.h"

/* Private define ------------------------------------------------------------*/


/* External variables --------------------------------------------------------*/


/* Private variables ---------------------------------------------------------*/


/* Private function prototypes -----------------------------------------------*/



/**
  *  @brief  ��ʼ���ⲿ�ж�
  *  @param  None
  *  @retval None
  */
void EXTIx_Init(void)
{
    GPIO_InitTypeDef    GPIO_InitStructure;
 	EXTI_InitTypeDef    EXTI_InitStructure;
 	NVIC_InitTypeDef    NVIC_InitStructure;
    
    GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable , ENABLE);                   /**< �ر�JTAG */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB
                                                | RCC_APB2Periph_AFIO, ENABLE); /**< ��������Ҫ����AFIOʱ�� */
    /** ����GPIOB ��6��8������Ϊ�ж�Դ */
    GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_8;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
    
    GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_6;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
    
    /**< �ж��ߺ��жϳ�ʼ������ */
    GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource6);             /**< EXTI��6����PB6 */
    EXTI_InitStructure.EXTI_Line    = EXTI_Line6;
    EXTI_InitStructure.EXTI_Mode    = EXTI_Mode_Interrupt;
    EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
    EXTI_InitStructure.EXTI_LineCmd = ENABLE;
    EXTI_Init(&EXTI_InitStructure);                             

    EXTI_GenerateSWInterrupt(EXTI_Line6);                                   /**< EXTI_Line6 �ж����� */
    
    /**< ��ռ���ȼ�1λ ��ռ���ȼ�3λ */
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);                         
    NVIC_InitStructure.NVIC_IRQChannel                   = EXTI9_5_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;               /**< ����NVIC_IRQChannel����ռ���ȼ� */   
    NVIC_InitStructure.NVIC_IRQChannelSubPriority        = 0;               /**< ����NVIC_IRQChannel�Ĵ�ռ���ȼ� */
    NVIC_InitStructure.NVIC_IRQChannelCmd                = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
    
}

/**
  *  @brief  �ⲿ�ж�9-5�жϴ������
  *  @param	 None
  *  @retval None
  */
void EXTI9_5_IRQHandler(void)
{
    delay_n_ms(20);
    
    if (EXTI_GetITStatus(EXTI_Line6))
    {
        LED_On(GPIO_LED, GPIO_LED_0);
        delay_n_ms(1000);
        LED_Off(GPIO_LED, GPIO_LED_All);
        delay_n_ms(1000);
        LED_On(GPIO_LED, GPIO_LED_0);
        delay_n_ms(1000);
        LED_Off(GPIO_LED, GPIO_LED_All);
    }
    
    EXTI_ClearITPendingBit(EXTI_Line6);             /**< �����·6�жϹ���λ */
}

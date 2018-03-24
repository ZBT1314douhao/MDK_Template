/**
  * @file    digitron.c 
  * @author  Z B T
  * @version V0.1
  * @date    2016-03-16
  * @brief   ������������������� ���������п�����
  */  

/* Includes ------------------------------------------------------------------*/
#include "digitron.h"
#include "delay.h"

/* Private define ------------------------------------------------------------*/
/**< 8������ܽӿڶ��� */
#define GPIO_DIGITRON_DATA      GPIOB
#define GPIO_DIGITRON           GPIOA      

/* External variables --------------------------------------------------------*/


/* Private variables ---------------------------------------------------------*/
//const uint8_t digitron_map[] = 
//{   /** ����������ܶ�ѡ */
//    ~0x3F, ~0x06, ~0x5B, ~0x4F, ~0x66, ~0x6D, ~0x7D, ~0x07,
//    ~0x7F, ~0x6F, ~0x77, ~0x7C, ~0x39, ~0x5E, ~0x79, ~0x71,
//};
const uint8_t digitron_map[] = 
{   /** ����������ܶ�ѡ */
    0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07,
    0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71,
};
/** �����λѡ�� */
const uint8_t digitron_select[] = 
{
    0xfe, 0xfd, 0xfb, 0xf7, 0xef, 0xdf, 0xbf, 0x7f
};

/* Private function prototypes -----------------------------------------------*/


/**
  *  @brief  ������������ú���
  *  @param	 None
  *  @retval None
  */
void digitron_config(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    
    GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_All;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP;
    
    /** GPIOB Periphʱ��ʹ�� */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB, ENABLE);
    GPIO_Init(GPIOA, &GPIO_InitStructure);                          /**< ��ʼ�� LS138 �������Ķ˿� */
    GPIO_Init(GPIOB, &GPIO_InitStructure);                          /**< ��ʼ��������������ܵĶ˿� */
}

/**
  *  @brief  �������ʾ����
  *  @param	 None
  *  @retval None
  */
void digitron_display(void)
{
    uint8_t i;
    
    for (i = 0; i < 8; i++)
    {
        GPIO_Write(GPIO_DIGITRON, digitron_select[i]);
        GPIO_Write(GPIO_DIGITRON_DATA, digitron_map[i] << 8);
        delay_n_us(500);
        GPIO_Write(GPIO_DIGITRON_DATA, 0x0000);
    }
}


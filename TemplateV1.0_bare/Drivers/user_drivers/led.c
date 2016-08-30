/**
  * @file    led.c 
  * @author  Z B T
  * @version V0.1    Lib STM32_V3.5
  * @date    2016-01-29
  * @brief   led��������
  *
  */  

#include "led.h"

const struct GPIO_PIN_LED led_pin[] = 
{
    GPIOA, GPIO_Pin_0, GPIO_Speed_2MHz, GPIO_Mode_Out_PP,
    GPIOA, GPIO_Pin_1, GPIO_Speed_2MHz, GPIO_Mode_Out_PP,
    GPIOA, GPIO_Pin_2, GPIO_Speed_2MHz, GPIO_Mode_Out_PP,
    GPIOA, GPIO_Pin_3, GPIO_Speed_2MHz, GPIO_Mode_Out_PP,
    GPIOA, GPIO_Pin_4, GPIO_Speed_2MHz, GPIO_Mode_Out_PP,
    GPIOA, GPIO_Pin_5, GPIO_Speed_2MHz, GPIO_Mode_Out_PP,
    GPIOA, GPIO_Pin_6, GPIO_Speed_2MHz, GPIO_Mode_Out_PP,
    GPIOA, GPIO_Pin_7, GPIO_Speed_2MHz, GPIO_Mode_Out_PP,
};

#define NUM_LEDS    (sizeof(led_pin) / sizeof(led_pin[0]))
    
/**
 *  @brief ledc��ʼ������
 *  @param None
 *  @return None
 */
void GPIO_led_config(void)
{
    uint8_t i = 0;
    GPIO_InitTypeDef    GPIO_InitStructure;
    
    for (i = 0; i < NUM_LEDS; i++)
    {
        GPIO_InitStructure.GPIO_Pin   = led_pin[i].pin;
        GPIO_InitStructure.GPIO_Speed = led_pin[i].speed;
        GPIO_InitStructure.GPIO_Mode  = led_pin[i].mode;
        GPIO_Init(led_pin[i].port, &GPIO_InitStructure);
    }
    
    /**< �趨LED�ĳ�ʼ״̬ */
    for (i = 0; i < NUM_LEDS; i++)
    {    /**< �رտ����������е�(8��)led */
         GPIO_ResetBits(led_pin[i].port, led_pin[i].pin);         
    }
   
}

/**
 *  @brief  ����led   ����������led
 *  @param  [in]led_num  e.g LED_0 
 *  @return None
 */
void led_on(uint16_t led_num)
{
    uint8_t i;
    
    for (i = 0; i < NUM_LEDS; i++)
    {
        if (led_num & (1 << i))
        {
            /**< ��led������0������1����ѡ�� */
//            GPIO_WriteBit(led_pin[i].port, led_pin[i].pin, Bit_RESET);
            GPIO_WriteBit(led_pin[i].port, led_pin[i].pin, Bit_SET);
        }

    }
}

/**
 *  @brief  Ϩ��led   ����������led
 *  @param  [in]led_num  e.g LED_0 
 *  @return None
 */
void led_off(uint16_t led_num)
{
    uint8_t i;
    
    for (i = 0; i < NUM_LEDS; i++)
    {
        if (led_num & (1 << i))
        {
            /**< ��led������0������1����ѡ�� */
//            GPIO_WriteBit(led_pin[i].port, led_pin[i].pin, Bit_RESET);
            GPIO_WriteBit(led_pin[i].port, led_pin[i].pin, Bit_RESET);
        }

    }
}


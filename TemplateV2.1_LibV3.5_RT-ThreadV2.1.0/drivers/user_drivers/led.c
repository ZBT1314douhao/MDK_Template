/**
  * @file  led.c
  * @brief led��������
  * @par   date        version    author    remarks
  *        2016-09-22  v1.0       zbt       ���δ���
  *
  */
  
/** ͷ�ļ������� --------------------------------------------------- */
#include "common.h"

/** ˽�к�(���Ͷ���) ----------------------------------------------- */ 
#define NUM_LEDS    (sizeof(led_pin) / sizeof(led_pin[0]))

/** ˽�б��� ------------------------------------------------------- */
const struct GPIO_PIN_LED led_pin[] = 
{
    GPIOD, GPIO_Pin_2,  GPIO_Speed_50MHz, GPIO_Mode_Out_PP,
    GPIOD, GPIO_Pin_3,  GPIO_Speed_50MHz, GPIO_Mode_Out_PP,
    GPIOD, GPIO_Pin_4,  GPIO_Speed_50MHz, GPIO_Mode_Out_PP,
    GPIOD, GPIO_Pin_7,  GPIO_Speed_50MHz, GPIO_Mode_Out_PP,

};

/** �ⲿ���� ------------------------------------------------------- */

/** ˽�к���ԭ�� --------------------------------------------------- */

/** ���к��� ------------------------------------------------------- */
    
/**
  * @brief ledc��ʼ������
  * @param None
  * @return None
  */
void led_init(void)
{
    uint8_t i = 0;
    GPIO_InitTypeDef GPIO_InitStructure;
    
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);
    
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
  * @brief  ����led   ����������led
  * @param  [in]led_id  e.g LED_0 
  * @return None
  */
void led_on(uint16_t led_id)
{
    uint8_t i;
    
    for (i = 0; i < NUM_LEDS; i++)
    {
        if (led_id & (1 << i))
        {
            /**< ��led������0������1����ѡ�� */
//            GPIO_WriteBit(led_pin[i].port, led_pin[i].pin, Bit_RESET);
            GPIO_WriteBit(led_pin[i].port, led_pin[i].pin, Bit_SET);
        }

    }
}

/**
  * @brief  Ϩ��led   ����������led
  * @param  [in]led_id  e.g LED_0 
  * @return None
  */
void led_off(uint16_t led_id)
{
    uint8_t i;
    
    for (i = 0; i < NUM_LEDS; i++)
    {
        if (led_id & (1 << i))
        {
            /**< ��led������0������1����ѡ�� */
//            GPIO_WriteBit(led_pin[i].port, led_pin[i].pin, Bit_RESET);
            GPIO_WriteBit(led_pin[i].port, led_pin[i].pin, Bit_RESET);
        }

    }
}

/**
  *  @brief  ��תled״̬   ����������led
  *  @param  [in]led_id  e.g LED_0 
  *  @return None
  */
void led_toggle(uint16_t led_id)
{
    uint8_t i;
    uint8_t pin_status = 0x00;
    
    for (i = 0; i < NUM_LEDS; i++)
    {
        if (led_id & (1 << i))
        {
            pin_status = GPIO_ReadInputDataBit(led_pin[i].port, led_pin[i].pin);
            GPIO_WriteBit(led_pin[i].port, led_pin[i].pin, ((BitAction)!pin_status));
        }

    }
}

/** ˽�к��� ------------------------------------------------------- */

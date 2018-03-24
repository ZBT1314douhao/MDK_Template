/**
  * @file    delay.c 
  * @author  Z B T
  * @version V0.1
  * @date    2016-01-29
  * @brief   ��ʱ����
  */  

/* ͷ�ļ������� --------------------------------------------------*/
#include "delay.h"

/* �ļ�˽�б��� ------------------------------------------------- */
static __IO uint32_t s_tick;

/* ˽�к���ԭ�� ------------------------------------------------- */
static void delay_task(void);

/* ���к��� ----------------------------------------------------- */
/**
  *  @brief  systick��ʼ��
  *  @param  None
  *  @retval None
  */
void systick_init(void)
{
    /** ���ö�ʱ����
        SystemCoreClock / 1000 ��ʾ��ʱƵ�� 1000hz���ɵö�ʱ����1ms
        SystemCoreClock / 100 ��ʾ��ʱƵ��  100hz���ɵö�ʱ����10ms
    */
    SysTick_Config(SystemCoreClock / 1000);
    /** ����systick�ж� */
    
}

/**
  *  @brief  ����tickֵ
  *  @param  None
  *  @retval None
  */
void inc_tick(void)
{
    s_tick++;
}

/**
  *  @brief  ������ʱn us
  *  @param  None
  *  @retval s_tick��ֵ
  */
uint32_t get_tick(void)
{
    return s_tick;
}


/**
  *  @brief  ����systick������ȷ��ʱ
  *  @param  ms��Ҫ��ʱ��ʱ�� ��λ��ms
  *  @retval None
  */
void systick_delay(__IO uint32_t ms)
{
    uint32_t tick_start = 0;
    
    tick_start = get_tick();
    
    while (get_tick() - tick_start < ms)
    {
        delay_task();
    }
}

/**
  *  @brief  ������ʱn us
  *  @param  None
  *  @retval None
  */
void delay_n_us(uint16_t n_us)
{
    uint8_t i = 0;

    while (n_us--)
    {
        i = 10;
        while (i--);
    }
}

/**
  * @brief  ������ʱn ms
  * @param  None
  * @retval None
  */
void delay_n_ms(uint16_t n_ms)
{
    uint16_t i = 0;

    while (n_ms--)
    {
        i = 12000;
        while (i--);
    }
}

/* ˽�к��� ----------------------------------------------------- */
/**
  * @brief  ����ʱ�в������񣬱�����ʱ�յ�
  * @param  None
  * @retval None
  * @note   �ɲ���STemwin��ʾ�����ι����
  */
static void delay_task(void)
{
    
}

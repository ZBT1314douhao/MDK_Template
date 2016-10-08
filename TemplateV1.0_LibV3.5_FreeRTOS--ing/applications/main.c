/**
  * @file    main.c 
  * @author  Z B T
  * @version V1.1
  * @date    2016-01-29
  * @brief   Main program body 
  */  

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
/* freertos includes */
#include "FreeRTOS.h"
#include "task.h"

/* applications includes */
#include "thread.h"

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes ------------------------------------------------*/


int main(void)
{
	/*!< At this stage the microcontroller clock setting is already configured, 
	this is done through SystemInit() function which is called from startup
	file (startup_stm32f10x_xx.s) before to branch to application main.
	To reconfigure the default setting of SystemInit() function, refer to
	system_stm32f10x.c file
	*/ 
    /* Declare variables ------------------------------------------------------*/
    
    
    /*  Function call ---------------------------------------------------------*/
    user_task_create();
    
    vTaskStartScheduler();      /* �������ȿ�ʼִ������ */
    
    while (1)
    {
        /* ���ϵͳ���������ǲ������е�����ģ�
            ���е����Ｋ�п����ǿ�������heap�ռ䲻����ɴ���ʧ�� */
    }

}



/* ���Ӻ��� ------------------------------------------------------------------- */
/**
  * @brief  ջ������Ӻ���
  * @param  pxTask������ջ�����������
  * @param  *pcTaskName������ջ�����������
  * @retval None
  * @note   ��һ������Ӹ������ջ���ʱ���˺��������á��������ǳ�
            ���أ�������������ϢҲ�����Ǵ���ģ�����������¿���ֱ��
            ���pxCurrentTCB����
            �Ƽ����ڿ�����or���԰�ʹ��ջ�����飬��Ϊ�������������
            ����
  */
void vApplicationStackOverflowHook(TaskHandle_t pxTask, char *pcTaskName)
{
    ( void ) pxTask;
	( void ) pcTaskName;
    
    while (1);
}

/**
  * @brief  �����жϹ��Ӻ���������ʵ�ֶ�ʱ������
  * @param  None
  * @retval None
  * @note   ʹ�ô˺�����Ҫ��FreeRTOSConfig.h�н�configUSE_TICK_HOOK�궨���Ϊ1
            �˺������жϷ�����������У����Դ˺��������С������ʹ�ô�����ջ��
            ���ܵ�����From_ISR or FROM_ISR��β�ĺ���
  */
void vApplicationTickHook(void)
{
    
}

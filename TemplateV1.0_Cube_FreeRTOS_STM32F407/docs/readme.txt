/**
  * @file  readme.txt
  * @brief ��Ŀ����ʹ�ñض���������Ŀ��������˵������Ŀ����˵������Ϣ
  * @par   date        version    author    remarks
  *        2016-10-06  v1.0       zbt       ���δ���
  *
  */ 

  1. �ܽ�����Ŀ��������˵��
    Ӳ��ƽ̨��   STM32F407ZGT6
    ���ƽ̨��   MDK V5.20 + STM32Cube4.14
    ���ļ��汾�� HAL Lib + STemwin5.22
    ����ϵͳ��   FreeRTOS8.20 
    
    1.1 STM32F407ZGT6���ŷ���˵��
		���ط�ʽ��SWD -> SWDIO SWCLK
		���ڴ�ӡ��USART1 -> USART_TX��PA9�� + USART_RX��PA10��
		Һ��������
				SPI1 -> SCK��PA5�� + MISO��PA6�� + MOSI��PA7��
				CS��PA4�� + RESET��PC5��+ INT��PC4��
	
	1.2 ��Ŀ�����ļ��ܹ�˵��
		Application/MDK_ARM				--------	STM32�����ļ�		
		Application/User 				--------  	���Ӧ�ò����
		Drivers/CMSIS					--------	M4�ں�����ӿڲ�ϵͳԴ�ļ�
		Drivers/STM32F4xx_HAL_Drivers	--------	STM32F4��HAL��Դ�ļ�
		Drviers/User     				-------- 	��ŷ�STM32Ƭ��������������
		Drivers/Board   				--------  	���STM32Ƭ�����������������
		Middlewares/FreeRTOS			--------	FreeRTOS����ļ�
		Docs							--------  	�����Ŀ����˵���ļ�
		
  2. ��Ŀ����˵��

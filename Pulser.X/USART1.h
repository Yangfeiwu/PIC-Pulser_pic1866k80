/* 
 * File:   USART1.h
 * Author: Administrator
 *
 * Created on 2018��8��6��, ����9:03
 */

#ifndef USART1_H
#define	USART1_H

#ifdef	__cplusplus
extern "C" {
#endif
#define RX_SIZE 8   

    bit RX_flag ;   //���ձ�־��RX_flag=1�����ݽ������ ��
    unsigned char RX[RX_SIZE];  //Usart1���ջ�����
    unsigned char RX_C=0;//���ڽ��ռ���
    void UartInit();
    void USART_RX();    //���ڽ����ӳ���
    void Usart_CL();                 //���ڽ�����ɴ����ӳ���

   
#ifdef	__cplusplus
}
#endif

#endif	/* USART1_H */


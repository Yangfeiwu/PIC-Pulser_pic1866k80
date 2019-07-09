/* 
 * File:   USART1.h
 * Author: 杨飞武
 * Created on 20180808
 */

#ifndef USART1_H
#define	USART1_H

#ifdef	__cplusplus
extern "C" {
#endif
#define RX_SIZE 8   

    bit RX_flag ;   //接收标志（RX_flag=1，数据接收完成 ）
    unsigned char RX[RX_SIZE];  //Usart1接收缓存区
    unsigned char RX_C=0;//串口接收计数
    void UartInit();
    void USART_RX();    //串口接收子程序
    void Usart_CL();   //串口接收完成处理子程序

   
#ifdef	__cplusplus
}
#endif

#endif	/* USART1_H */



/* 
 * File:   USART1.c
 * Author: 杨飞武
 * Created on 20180808
 */
#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include "USART1.h"
#include "Config.h"
#include "Register.h"
#include "Pulser_param.h"
#include "MC_EVENT.h"
#include "PARM_CL.h"

void UartInit(void)
{
TRISG=0xFF;
RCSTA1bits.SPEN=1;// ����ʹ��
// TXSTA1������״̬�Ϳ��ƼĴ���
TXSTA1bits.SYNC=0;// �첽ģʽ
TXSTA1bits.TX9=0;// ѡ��8 λ����
TXSTA1bits.TXEN=1;// ʹ�ܷ���
TXSTA1bits.BRGH=1;// ���ٲ�����
TXSTA1bits.TXEN=1;// ʹ�ܷ���
// RCSTA1������״̬�Ϳ��ƼĴ���
RCSTA1bits.RX9=0;// ѡ��8λ����
RCSTA1bits.CREN=1;// ʹ�ܽ�����
// BAUDCON1�������ʿ��ƼĴ���
BAUDCON1bits.BRG16=0;// 8λ�����ʷ�����??SPBRGHx ��SPBRGx
SPBRG1=68;  //Set BRG 57600 (16MHZ crystal oscillator ,  BRG mode in High speed )
INTCON=0;
//�ж�����
INTCONbits.GIE=1;      //ʹ��ȫ���ж�    
INTCONbits.PEIE=1;     //ʹ���ⲿ�ж�      
PIE1bits.RCIE=1;         //ʹ�ܽ����ж�   

}

    void Usart_CL()
    {
        RX_flag=Free;
//     printf("Rx success!\r\n");
  //----------�������ݷ���------------------   
   Current_RX=RX[1];
   
 switch(Current_RX)
 {
/*------------------------------------------------------------------*/     
     case  0x01:   //MC1��������
       for(int i=0; i<MC_PARM_SIZE;i++) MC1_PARM[i] =  RX[i];
        MC1_PARM_CL(); 
//        printf("MC1_PARM Rx success!\r\n");
         break;
/*------------------------------------------------------------------*/            
      case  0x02: //MC2��������
       for(int i=0; i<MC_PARM_SIZE;i++) MC2_PARM[i] =  RX[i];
         MC2_PARM_CL();
//        printf("MC2_PARM Rx success!\r\n");
         break;     
/*------------------------------------------------------------------*/           
      case  0x03:  //MC3��������
       for(int i=0; i<MC_PARM_SIZE;i++) MC3_PARM[i] =  RX[i];
         MC3_PARM_CL();       
//        printf("MC3_PARM Rx success!\r\n");
         break;         
 /*------------------------------------------------------------------*/          
        case  0x04:  //MC4��������          
       for(int i=0; i<MC_PARM_SIZE;i++) MC4_PARM[i] =  RX[i];
         MC4_PARM_CL();       
//        printf("MC4_PARM Rx success!\r\n");
         break;       
/*------------------------------------------------------------------*/           
         case  0x11:  //MC������������
       for(int i=0; i<MC_START_PARM_SIZE;i++) McStart_PARM[i] =  RX[i];
        McStart_PARM_CL();
        MC_EVENT_Trigge();
//        printf("McStart_PARM Rx success!\r\n");
         break;  
         
         
 /*------------------------------------------------------------------*/          
         case  0x31: //IO���Ʋ�������
       for(int i=0; i<IOKZ_PARM_SIZE;i++) RX_IO_PARM[i] =  RX[i];
        RX_IOKZ_PARM();
//        printf("IOKZ_PARM Rx success!\r\n");
         break;  
/*------------------------------------------------------------------*/  
     default:       
         printf("Rx FAIL,Command format error!\r\n");
         break;
     
 
     }
    
  }

void USART_RX()
{
 //   unsigned char data;
    if(RC1IE&&RC1IF)            //�ж��Ƿ�Ϊ���ڽ����ж�    
    {  
      
 //         data=RCREG1;
           RX[RX_C++]= RCREG1;    //��������   
    //       	TXREG1=data;

       if(RX[0]!=0XD0)RX_C=0;  
         
           if(RX_C>=RX_SIZE)//���ݽ������
            {   
                RX_C=0; 
                RX_flag=Finish;
             }
    } 

}


    
    
    
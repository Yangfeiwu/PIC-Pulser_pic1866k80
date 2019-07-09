/*
 * File:   PARM_CL.c
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
#include "PORT_Filter_OUT.h"

 void MC1_PARM_CL()
    {
     
    if( MC1_Start_BZ==FALSE)
    {
    
     MC1_Channel= MC1_PARM[2];  //����1ͨ������
     MC1_FZ_C= MC1_PARM[3];    //�������
     MC1_TIME_H =   MC1_PARM[4]*255+MC1_PARM[5];  //����ߵ�ƽʱ��
     MC1_TIME_L =   MC1_PARM[6]*255+MC1_PARM[7]; //����͵�ƽʱ��
       //printf("MC1_PARM Write success!\r\n"); 
     
    } 
       else printf("MC1_PARM Write Fail!\r\n"); 
    
    }
      void MC2_PARM_CL()
    {
   if( MC2_Start_BZ==FALSE)    
   {       
     MC2_Channel= MC2_PARM[2];  //����1ͨ������
     MC2_FZ_C= MC2_PARM[3];    //�������
     MC2_TIME_H =   MC2_PARM[4]*255+MC2_PARM[5];  //����ߵ�ƽʱ��
     MC2_TIME_L =   MC2_PARM[6]*255+MC2_PARM[7]; //����͵�ƽʱ�� 
          //    printf("MC2_PARM Write success!\r\n"); 
   }
   else printf("MC2_PARM Write Fail!\r\n"); 
    
    }
      
      void MC3_PARM_CL()
    {
    if( MC3_Start_BZ==FALSE)  
    {    
     MC3_Channel= MC3_PARM[2];  //����1ͨ������
     MC3_FZ_C= MC3_PARM[3];    //�������
     MC3_TIME_H =   MC3_PARM[4]*255+MC3_PARM[5];  //����ߵ�ƽʱ��
     MC3_TIME_L =   MC3_PARM[6]*255+MC3_PARM[7]; //����͵�ƽʱ��  
     //  printf("MC3_PARM Write success!\r\n"); 
    }
    else  printf("MC3_PARM Write Fail!\r\n"); 
    
    }    
      
      void MC4_PARM_CL()
    {
     if( MC4_Start_BZ==FALSE)  
     {        
     MC4_Channel= MC4_PARM[2];  //����1ͨ������
     MC4_FZ_C= MC4_PARM[3];    //�������
     MC4_TIME_H =   MC4_PARM[4]*255+MC4_PARM[5];  //����ߵ�ƽʱ��
     MC4_TIME_L =   MC4_PARM[6]*255+MC4_PARM[7]; //����͵�ƽʱ��    
     //  printf("MC4_PARM Write success!\r\n"); 
     }
     else    printf("MC4_PARM Write Fail!\r\n"); 
    
    }    
   void McStart_PARM_CL()
   {
    MC1_START_Signal=McStart_PARM[2];
    MC2_START_Signal=McStart_PARM[3];
    MC3_START_Signal=McStart_PARM[4];  
    MC4_START_Signal=McStart_PARM[5];
    
    
    
    
    
    
    
           
   }
      
   void RX_IOKZ_PARM()
   {
       
    /*�жϵ�ǰMCִ�е����ţ�ִ���н�ֹ��MCռ��IO����*/   
      uchar MC_Occupy_Channel,RC_PB_BIT;
      MC_Occupy_Channel=MC_Start_BZ & 0x0F;
        /*MCռ��IO����*/
     switch (MC_Occupy_Channel)
     {
         case  0x00: //��ͨ����ռ��  
                     RC_PB_BIT=0;
                   break;
         
         case  0x01: //ͨ��1��ռ��  
                      RC_PB_BIT=MC1_Channel; 
       
//                      printf("ռ��PORTC%x!\r\n",RC_PB_BIT);       
                   break;
     
         case  0x02: //ͨ��2��ռ��  
                      RC_PB_BIT=MC2_Channel;
//                      printf("ռ��PORTC%x!\r\n",RC_PB_BIT);        
                   break;    
     
         case  0x03: //ͨ��12��ռ��  
                     RC_PB_BIT=MC1_Channel+MC2_Channel;
//                      printf("ռ��PORTC%x!\r\n",RC_PB_BIT);    
                   break;    
         
         case  0x04: //ͨ��3��ռ��  
                     RC_PB_BIT=MC3_Channel;
//                      printf("ռ��PORTC%x!\r\n",RC_PB_BIT);    
                   break;             
         case  0x05: //ͨ��13��ռ��  
                     RC_PB_BIT=MC1_Channel+MC3_Channel;
//                      printf("ռ��PORTC%x!\r\n",RC_PB_BIT);  
                   break;
     
         case  0x06: //ͨ��23��ռ��  
                     RC_PB_BIT=MC2_Channel+MC3_Channel;
//                      printf("ռ��PORTC%x!\r\n",RC_PB_BIT);  
 
                   break;    
     
         case  0x07: //ͨ��123��ռ��  
                     RC_PB_BIT=MC1_Channel+MC2_Channel+MC3_Channel;
//                      printf("ռ��PORTC%x!\r\n",RC_PB_BIT);  
     
                   break;    
         
         case  0x08: //ͨ��4��ռ�� 
                    RC_PB_BIT=MC4_Channel;
//                      printf("ռ��PORTC%x!\r\n",RC_PB_BIT); 
  
                   break;            
         case  0x09: //ͨ��14��ռ��  
                    RC_PB_BIT=MC1_Channel+MC4_Channel;
//                      printf("ռ��PORTC%x!\r\n",RC_PB_BIT);  
         
                   break;
     
         case  0x0A: //ͨ��24��ռ��
             RC_PB_BIT=MC2_Channel+MC4_Channel;
//                      printf("ռ��PORTC%x!\r\n",RC_PB_BIT);  
   
                   break;    
                      
         case  0x0B: //ͨ��124��ռ��  
             RC_PB_BIT=MC1_Channel+MC2_Channel+MC4_Channel;
//                      printf("ռ��PORTC%x!\r\n",RC_PB_BIT);  
            
                   break;    
         
         case  0x0C: //ͨ��34��ռ��  
              RC_PB_BIT=MC3_Channel+MC4_Channel;
//                      printf("ռ��PORTC%x!\r\n",RC_PB_BIT);  
             
                   break;    
         
         case  0x0D: //ͨ��134��ռ��  
             RC_PB_BIT=MC1_Channel+MC3_Channel+MC4_Channel;
//                      printf("ռ��PORTC%x!\r\n",RC_PB_BIT);  

                  break;
     
         case  0x0E: //ͨ��234��ռ�� 
             RC_PB_BIT=MC2_Channel+MC3_Channel+MC4_Channel;
//                     printf("ռ��PORTC%x!\r\n",RC_PB_BIT);  
        
                  break;    
     
         case  0x0F: //ͨ��1234��ռ�� 
             RC_PB_BIT=MC1_Channel+MC2_Channel+MC3_Channel+MC4_Channel;
//                     printf("ռ��PORTC%x!\r\n",RC_PB_BIT); 

                 break;    
                     
        default:       
         printf("ͨ��1ռ��IO��������!\r\n");
         break;
          

     
     }
        
   IOKZ_Filter(RC,RC_PB_BIT,RX_IO_PARM[2]);
   LATD=RX_IO_PARM[3];
   LATF=RX_IO_PARM[4];
  
   }
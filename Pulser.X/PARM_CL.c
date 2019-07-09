/*
 * File:   PARM_CL.c
 * Author: Administrator
 *
 * Created on 2018年8月8日, 下午3:43
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
    
     MC1_Channel= MC1_PARM[2];  //脉冲1通道配置
     MC1_FZ_C= MC1_PARM[3];    //脉冲次数
     MC1_TIME_H =   MC1_PARM[4]*255+MC1_PARM[5];  //脉冲高电平时间
     MC1_TIME_L =   MC1_PARM[6]*255+MC1_PARM[7]; //脉冲低电平时间
       //printf("MC1_PARM Write success!\r\n"); 
     
    } 
       else printf("MC1_PARM Write Fail!\r\n"); 
    
    }
      void MC2_PARM_CL()
    {
   if( MC2_Start_BZ==FALSE)    
   {       
     MC2_Channel= MC2_PARM[2];  //脉冲1通道配置
     MC2_FZ_C= MC2_PARM[3];    //脉冲次数
     MC2_TIME_H =   MC2_PARM[4]*255+MC2_PARM[5];  //脉冲高电平时间
     MC2_TIME_L =   MC2_PARM[6]*255+MC2_PARM[7]; //脉冲低电平时间 
          //    printf("MC2_PARM Write success!\r\n"); 
   }
   else printf("MC2_PARM Write Fail!\r\n"); 
    
    }
      
      void MC3_PARM_CL()
    {
    if( MC3_Start_BZ==FALSE)  
    {    
     MC3_Channel= MC3_PARM[2];  //脉冲1通道配置
     MC3_FZ_C= MC3_PARM[3];    //脉冲次数
     MC3_TIME_H =   MC3_PARM[4]*255+MC3_PARM[5];  //脉冲高电平时间
     MC3_TIME_L =   MC3_PARM[6]*255+MC3_PARM[7]; //脉冲低电平时间  
     //  printf("MC3_PARM Write success!\r\n"); 
    }
    else  printf("MC3_PARM Write Fail!\r\n"); 
    
    }    
      
      void MC4_PARM_CL()
    {
     if( MC4_Start_BZ==FALSE)  
     {        
     MC4_Channel= MC4_PARM[2];  //脉冲1通道配置
     MC4_FZ_C= MC4_PARM[3];    //脉冲次数
     MC4_TIME_H =   MC4_PARM[4]*255+MC4_PARM[5];  //脉冲高电平时间
     MC4_TIME_L =   MC4_PARM[6]*255+MC4_PARM[7]; //脉冲低电平时间    
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
       
    /*判断当前MC执行的引脚，执行中禁止对MC占用IO控制*/   
      uchar MC_Occupy_Channel,RC_PB_BIT;
      MC_Occupy_Channel=MC_Start_BZ & 0x0F;
        /*MC占用IO计算*/
     switch (MC_Occupy_Channel)
     {
         case  0x00: //无通道被占用  
                     RC_PB_BIT=0;
                   break;
         
         case  0x01: //通道1被占用  
                      RC_PB_BIT=MC1_Channel; 
       
//                      printf("占用PORTC%x!\r\n",RC_PB_BIT);       
                   break;
     
         case  0x02: //通道2被占用  
                      RC_PB_BIT=MC2_Channel;
//                      printf("占用PORTC%x!\r\n",RC_PB_BIT);        
                   break;    
     
         case  0x03: //通道12被占用  
                     RC_PB_BIT=MC1_Channel+MC2_Channel;
//                      printf("占用PORTC%x!\r\n",RC_PB_BIT);    
                   break;    
         
         case  0x04: //通道3被占用  
                     RC_PB_BIT=MC3_Channel;
//                      printf("占用PORTC%x!\r\n",RC_PB_BIT);    
                   break;             
         case  0x05: //通道13被占用  
                     RC_PB_BIT=MC1_Channel+MC3_Channel;
//                      printf("占用PORTC%x!\r\n",RC_PB_BIT);  
                   break;
     
         case  0x06: //通道23被占用  
                     RC_PB_BIT=MC2_Channel+MC3_Channel;
//                      printf("占用PORTC%x!\r\n",RC_PB_BIT);  
 
                   break;    
     
         case  0x07: //通道123被占用  
                     RC_PB_BIT=MC1_Channel+MC2_Channel+MC3_Channel;
//                      printf("占用PORTC%x!\r\n",RC_PB_BIT);  
     
                   break;    
         
         case  0x08: //通道4被占用 
                    RC_PB_BIT=MC4_Channel;
//                      printf("占用PORTC%x!\r\n",RC_PB_BIT); 
  
                   break;            
         case  0x09: //通道14被占用  
                    RC_PB_BIT=MC1_Channel+MC4_Channel;
//                      printf("占用PORTC%x!\r\n",RC_PB_BIT);  
         
                   break;
     
         case  0x0A: //通道24被占用
             RC_PB_BIT=MC2_Channel+MC4_Channel;
//                      printf("占用PORTC%x!\r\n",RC_PB_BIT);  
   
                   break;    
                      
         case  0x0B: //通道124被占用  
             RC_PB_BIT=MC1_Channel+MC2_Channel+MC4_Channel;
//                      printf("占用PORTC%x!\r\n",RC_PB_BIT);  
            
                   break;    
         
         case  0x0C: //通道34被占用  
              RC_PB_BIT=MC3_Channel+MC4_Channel;
//                      printf("占用PORTC%x!\r\n",RC_PB_BIT);  
             
                   break;    
         
         case  0x0D: //通道134被占用  
             RC_PB_BIT=MC1_Channel+MC3_Channel+MC4_Channel;
//                      printf("占用PORTC%x!\r\n",RC_PB_BIT);  

                  break;
     
         case  0x0E: //通道234被占用 
             RC_PB_BIT=MC2_Channel+MC3_Channel+MC4_Channel;
//                     printf("占用PORTC%x!\r\n",RC_PB_BIT);  
        
                  break;    
     
         case  0x0F: //通道1234被占用 
             RC_PB_BIT=MC1_Channel+MC2_Channel+MC3_Channel+MC4_Channel;
//                     printf("占用PORTC%x!\r\n",RC_PB_BIT); 

                 break;    
                     
        default:       
         printf("通道1占用IO发生错误!\r\n");
         break;
          

     
     }
        
   IOKZ_Filter(RC,RC_PB_BIT,RX_IO_PARM[2]);
   LATD=RX_IO_PARM[3];
   LATF=RX_IO_PARM[4];
  
   }
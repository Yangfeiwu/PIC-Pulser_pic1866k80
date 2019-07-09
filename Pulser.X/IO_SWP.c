/*
 * File:   IO_SWP.c
 * Author: Administrator
 *
 * Created on 2018年8月7日, 上午10:12
 */


#include <xc.h>
#include "IO_SWP.h"
#include "Config.h"
#include <stdio.h>
#include <stdlib.h>
#include "MC_EVENT.h"
/*--------------------------------------------是否允许开启脉冲------------------------------------------------*/
void MC1_SWP_Decision()
{
    if(MC1_Start_BZ==TRUE) /*启动脉冲1翻转吗*/
    {
    MC1_SwapDelay--;
          if(MC1_SwapDelay==0)/*延迟时间到执行一次IO翻转*/
         {
               if(MC1_FZ_C>=1) /*翻转次数大于1，执行一次IO翻转*/
              {
               MC1_FZ_C--; /*翻转次数减1*/
               MC1_FZ_BZ=TRUE;    /*允许MC1_IO翻转1次*/ 
               }
               else 
               {   
                   MC1_Start_BZ=FALSE; //MC1翻转结束
                   MC1_END_FLAT=1;
//                  printf("81");  
               }                             
         }
                                                
     }
}

void MC2_SWP_Decision()
{
    if(MC2_Start_BZ==TRUE) /*启动脉冲1翻转吗*/
    {
    MC2_SwapDelay--;
          if(MC2_SwapDelay==0)/*延迟时间到执行一次IO翻转*/
         {
               if(MC2_FZ_C>=1) /*翻转次数大于1，执行一次IO翻转*/
              {
               MC2_FZ_C--; /*翻转次数减1*/
               MC2_FZ_BZ=TRUE;    /*允许MC1_IO翻转1次*/ 
               }
              else 
              {
                   MC2_Start_BZ=FALSE; //MC2翻转结束
                    MC2_END_FLAT=1;
//                   printf("82");  
              }                              
         }
                                                
     }
}

void MC3_SWP_Decision()
{
    if(MC3_Start_BZ==TRUE) /*启动脉冲1翻转吗*/
    {
    MC3_SwapDelay--;
          if(MC3_SwapDelay==0)/*延迟时间到执行一次IO翻转*/
         {
               if(MC3_FZ_C>=1) /*翻转次数大于1，执行一次IO翻转*/
              {
               MC3_FZ_C--; /*翻转次数减1*/
               MC3_FZ_BZ=TRUE;    /*允许MC1_IO翻转1次*/ 
               }
            else 
            {
                   MC3_Start_BZ=FALSE; //MC3翻转结束
                   MC3_END_FLAT=1;
//               printf("83");  
            }                                
         }
                                                
     }
}

void MC4_SWP_Decision()
{
    if(MC4_Start_BZ==TRUE) /*启动脉冲1翻转吗*/
    {
    MC4_SwapDelay--;
          if(MC4_SwapDelay==0)/*延迟时间到执行一次IO翻转*/
         {
               if(MC4_FZ_C>=1) /*翻转次数大于1，执行一次IO翻转*/
              {
               MC4_FZ_C--; /*翻转次数减1*/
               MC4_FZ_BZ=TRUE;    /*允许MC1_IO翻转1次*/ 
               }
             else
             {   
              MC4_Start_BZ=FALSE; //MC4翻转结束
               MC4_END_FLAT=1;
                 //           printf("84");  
             }                               
         }
                                                
     }
}

/*---------------------------------------------MC??I0翻转-----------------------------------------------------*/
void MC1_IO_SWP()
{
switch (MC1_Channel)
{
    case 0x01:
        LATC0=!LATC0; /*MC1??IO翻转操作*/
        break;
     case 0x02:
        LATC1=!LATC1; /*MC1??IO翻转操作*/
        break;       
//    case 0x04:
//        LATC2=!LATC2; /*MC1??IO翻转操作*/
//        break;
//     case 0x08:
//        LATC3=!LATC3; /*MC1??IO翻转操作*/
//        break;   
//     case 0x10:
//        LATC4=!LATC4; /*MC1??IO翻转操作*/
//        break;
//     case 0x20:
//        LATC5=!LATC5; /*MC1??IO翻转操作*/
//        break;       
//    case 0x40:
//        LATC6=!LATC6; /*MC1??IO翻转操作*/
//        break;
//     case 0x80:
//        LATC7=!LATC7; /*MC1??IO翻转操作*/
//        break;  
       default:
       printf("禁用MC1通道!\r\n");      
        break;       
}


if(MC1_IO_STATE==1) /*当前IO状态为高电平？*/
{
 MC1_SwapDelay=MC1_TIME_L; /*低电平时间赋值*/
MC1_IO_STATE=0;    /*当前IO状态置0*/
MC1_FZ_BZ=FALSE;    /*允许翻转标志清空*/
}
else      /*当前IO状态为低电平？*/
{

MC1_SwapDelay=MC1_TIME_H;
MC1_IO_STATE=1;    /*当前IO状态置1*/
MC1_FZ_BZ=FALSE;    /*允许翻转标志清空*/

}
}

void MC2_IO_SWP()
{
switch (MC2_Channel)
{
//    case 0x01:
//        LATC0=!LATC0; /*MC1??IO翻转操作*/
//        break;
//     case 0x02:
//        LATC1=!LATC1; /*MC1??IO翻转操作*/
//        break;       
    case 0x04:
        LATC2=!LATC2; /*MC1??IO翻转操作*/
        break;
     case 0x08:
        LATC3=!LATC3; /*MC1??IO翻转操作*/
        break;   
//     case 0x10:
//        LATC4=!LATC4; /*MC1??IO翻转操作*/
//        break;
//     case 0x20:
//        LATC5=!LATC5; /*MC1??IO翻转操作*/
//        break;       
//    case 0x40:
//        LATC6=!LATC6; /*MC1??IO翻转操作*/
//        break;
//     case 0x80:
//        LATC7=!LATC7; /*MC1??IO翻转操作*/
//        break;  
       default:
       printf("禁用MC2通道!\r\n");      
        break;       
}
  /*RD0??1?*/
if(MC2_IO_STATE==1) /*当前IO状态为高电平？*/
{
 MC2_SwapDelay=MC2_TIME_L; /*低电平时间赋值*/
MC2_IO_STATE=0;    /*当前IO状态置0*/
MC2_FZ_BZ=FALSE;    /*允许翻转标志清空*/
}
else      /*当前IO状态为低电平？*/
{

MC2_SwapDelay=MC2_TIME_H;
MC2_IO_STATE=1;    /*当前IO状态置1*/
MC2_FZ_BZ=FALSE;    /*允许翻转标志清空*/

}


}

void MC3_IO_SWP()
{
switch (MC3_Channel)
{
//    case 0x01:
//        LATC0=!LATC0; /*MC1??IO翻转操作*/
//        break;
//     case 0x02:
//        LATC1=!LATC1; /*MC1??IO翻转操作*/
//        break;       
//    case 0x04:
//        LATC2=!LATC2; /*MC1??IO翻转操作*/
//        break;
//     case 0x08:
//        LATC3=!LATC3; /*MC1??IO翻转操作*/
//        break;   
     case 0x10:
        LATC4=!LATC4; /*MC1??IO翻转操作*/
        break;
     case 0x20:
        LATC5=!LATC5; /*MC1??IO翻转操作*/
        break;       
//    case 0x40:
//        LATC6=!LATC6; /*MC1??IO翻转操作*/
//        break;
//     case 0x80:
//        LATC7=!LATC7; /*MC1??IO翻转操作*/
//        break;  
       default:
       printf("禁用MC3通道!\r\n");      
        break;       
}
  /*RD0??1?*/
if(MC3_IO_STATE==1) /*当前IO状态为高电平？*/
{
 MC3_SwapDelay=MC3_TIME_L; /*低电平时间赋值*/
MC3_IO_STATE=0;    /*当前IO状态置0*/
MC3_FZ_BZ=FALSE;    /*允许翻转标志清空*/
}
else      /*当前IO状态为低电平？*/
{

MC3_SwapDelay=MC3_TIME_H;
MC3_IO_STATE=1;    /*当前IO状态置1*/
MC3_FZ_BZ=FALSE;    /*允许翻转标志清空*/

}


}


void MC4_IO_SWP()
{
switch (MC4_Channel)
{     
    case 0x40:
        LATC6=!LATC6; /*MC1??IO翻转操作*/
        break;
     case 0x80:
        LATC7=!LATC7; /*MC1??IO翻转操作*/
        break;  
       default:
       printf("禁用MC4通道!\r\n");      
        break;       
}
  /*RD0??1?*/
if(MC4_IO_STATE==1) /*当前IO状态为高电平？*/
{
 MC4_SwapDelay=MC4_TIME_L; /*低电平时间赋值*/
MC4_IO_STATE=0;    /*当前IO状态置0*/
MC4_FZ_BZ=FALSE;    /*允许翻转标志清空*/

}
else      /*当前IO状态为低电平？*/
{

 MC4_SwapDelay=MC4_TIME_H;
MC4_IO_STATE=1;    /*当前IO状态置1*/
MC4_FZ_BZ=FALSE;    /*允许翻转标志清空*/   

}






}


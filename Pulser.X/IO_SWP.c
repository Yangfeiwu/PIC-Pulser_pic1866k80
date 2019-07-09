/*
 * File:   IO_SWP.c
 * Author: 杨飞武
 * Created on 20180808
 */


#include <xc.h>
#include "IO_SWP.h"
#include "Config.h"
#include <stdio.h>
#include <stdlib.h>
#include "MC_EVENT.h"
/*--------------------------------------------�Ƿ�������������------------------------------------------------*/
void MC1_SWP_Decision()
{
    if(MC1_Start_BZ==TRUE) /*��������1��ת��*/
    {
    MC1_SwapDelay--;
          if(MC1_SwapDelay==0)/*�ӳ�ʱ�䵽ִ��һ��IO��ת*/
         {
               if(MC1_FZ_C>=1) /*��ת��������1��ִ��һ��IO��ת*/
              {
               MC1_FZ_C--; /*��ת������1*/
               MC1_FZ_BZ=TRUE;    /*����MC1_IO��ת1��*/ 
               }
               else 
               {   
                   MC1_Start_BZ=FALSE; //MC1��ת����
                   MC1_END_FLAT=1;
//                  printf("81");  
               }                             
         }
                                                
     }
}

void MC2_SWP_Decision()
{
    if(MC2_Start_BZ==TRUE) /*��������1��ת��*/
    {
    MC2_SwapDelay--;
          if(MC2_SwapDelay==0)/*�ӳ�ʱ�䵽ִ��һ��IO��ת*/
         {
               if(MC2_FZ_C>=1) /*��ת��������1��ִ��һ��IO��ת*/
              {
               MC2_FZ_C--; /*��ת������1*/
               MC2_FZ_BZ=TRUE;    /*����MC1_IO��ת1��*/ 
               }
              else 
              {
                   MC2_Start_BZ=FALSE; //MC2��ת����
                    MC2_END_FLAT=1;
//                   printf("82");  
              }                              
         }
                                                
     }
}

void MC3_SWP_Decision()
{
    if(MC3_Start_BZ==TRUE) /*��������1��ת��*/
    {
    MC3_SwapDelay--;
          if(MC3_SwapDelay==0)/*�ӳ�ʱ�䵽ִ��һ��IO��ת*/
         {
               if(MC3_FZ_C>=1) /*��ת��������1��ִ��һ��IO��ת*/
              {
               MC3_FZ_C--; /*��ת������1*/
               MC3_FZ_BZ=TRUE;    /*����MC1_IO��ת1��*/ 
               }
            else 
            {
                   MC3_Start_BZ=FALSE; //MC3��ת����
                   MC3_END_FLAT=1;
//               printf("83");  
            }                                
         }
                                                
     }
}

void MC4_SWP_Decision()
{
    if(MC4_Start_BZ==TRUE) /*��������1��ת��*/
    {
    MC4_SwapDelay--;
          if(MC4_SwapDelay==0)/*�ӳ�ʱ�䵽ִ��һ��IO��ת*/
         {
               if(MC4_FZ_C>=1) /*��ת��������1��ִ��һ��IO��ת*/
              {
               MC4_FZ_C--; /*��ת������1*/
               MC4_FZ_BZ=TRUE;    /*����MC1_IO��ת1��*/ 
               }
             else
             {   
              MC4_Start_BZ=FALSE; //MC4��ת����
               MC4_END_FLAT=1;
                 //           printf("84");  
             }                               
         }
                                                
     }
}

/*---------------------------------------------MC??I0��ת-----------------------------------------------------*/
void MC1_IO_SWP()
{
switch (MC1_Channel)
{
    case 0x01:
        LATC0=!LATC0; /*MC1??IO��ת����*/
        break;
     case 0x02:
        LATC1=!LATC1; /*MC1??IO��ת����*/
        break;       
//    case 0x04:
//        LATC2=!LATC2; /*MC1??IO��ת����*/
//        break;
//     case 0x08:
//        LATC3=!LATC3; /*MC1??IO��ת����*/
//        break;   
//     case 0x10:
//        LATC4=!LATC4; /*MC1??IO��ת����*/
//        break;
//     case 0x20:
//        LATC5=!LATC5; /*MC1??IO��ת����*/
//        break;       
//    case 0x40:
//        LATC6=!LATC6; /*MC1??IO��ת����*/
//        break;
//     case 0x80:
//        LATC7=!LATC7; /*MC1??IO��ת����*/
//        break;  
       default:
       printf("����MC1ͨ��!\r\n");      
        break;       
}


if(MC1_IO_STATE==1) /*��ǰIO״̬Ϊ�ߵ�ƽ��*/
{
 MC1_SwapDelay=MC1_TIME_L; /*�͵�ƽʱ�丳ֵ*/
MC1_IO_STATE=0;    /*��ǰIO״̬��0*/
MC1_FZ_BZ=FALSE;    /*������ת��־���*/
}
else      /*��ǰIO״̬Ϊ�͵�ƽ��*/
{

MC1_SwapDelay=MC1_TIME_H;
MC1_IO_STATE=1;    /*��ǰIO״̬��1*/
MC1_FZ_BZ=FALSE;    /*������ת��־���*/

}
}

void MC2_IO_SWP()
{
switch (MC2_Channel)
{
//    case 0x01:
//        LATC0=!LATC0; /*MC1??IO��ת����*/
//        break;
//     case 0x02:
//        LATC1=!LATC1; /*MC1??IO��ת����*/
//        break;       
    case 0x04:
        LATC2=!LATC2; /*MC1??IO��ת����*/
        break;
     case 0x08:
        LATC3=!LATC3; /*MC1??IO��ת����*/
        break;   
//     case 0x10:
//        LATC4=!LATC4; /*MC1??IO��ת����*/
//        break;
//     case 0x20:
//        LATC5=!LATC5; /*MC1??IO��ת����*/
//        break;       
//    case 0x40:
//        LATC6=!LATC6; /*MC1??IO��ת����*/
//        break;
//     case 0x80:
//        LATC7=!LATC7; /*MC1??IO��ת����*/
//        break;  
       default:
       printf("����MC2ͨ��!\r\n");      
        break;       
}
  /*RD0??1?*/
if(MC2_IO_STATE==1) /*��ǰIO״̬Ϊ�ߵ�ƽ��*/
{
 MC2_SwapDelay=MC2_TIME_L; /*�͵�ƽʱ�丳ֵ*/
MC2_IO_STATE=0;    /*��ǰIO״̬��0*/
MC2_FZ_BZ=FALSE;    /*������ת��־���*/
}
else      /*��ǰIO״̬Ϊ�͵�ƽ��*/
{

MC2_SwapDelay=MC2_TIME_H;
MC2_IO_STATE=1;    /*��ǰIO״̬��1*/
MC2_FZ_BZ=FALSE;    /*������ת��־���*/

}


}

void MC3_IO_SWP()
{
switch (MC3_Channel)
{
//    case 0x01:
//        LATC0=!LATC0; /*MC1??IO��ת����*/
//        break;
//     case 0x02:
//        LATC1=!LATC1; /*MC1??IO��ת����*/
//        break;       
//    case 0x04:
//        LATC2=!LATC2; /*MC1??IO��ת����*/
//        break;
//     case 0x08:
//        LATC3=!LATC3; /*MC1??IO��ת����*/
//        break;   
     case 0x10:
        LATC4=!LATC4; /*MC1??IO��ת����*/
        break;
     case 0x20:
        LATC5=!LATC5; /*MC1??IO��ת����*/
        break;       
//    case 0x40:
//        LATC6=!LATC6; /*MC1??IO��ת����*/
//        break;
//     case 0x80:
//        LATC7=!LATC7; /*MC1??IO��ת����*/
//        break;  
       default:
       printf("����MC3ͨ��!\r\n");      
        break;       
}
  /*RD0??1?*/
if(MC3_IO_STATE==1) /*��ǰIO״̬Ϊ�ߵ�ƽ��*/
{
 MC3_SwapDelay=MC3_TIME_L; /*�͵�ƽʱ�丳ֵ*/
MC3_IO_STATE=0;    /*��ǰIO״̬��0*/
MC3_FZ_BZ=FALSE;    /*������ת��־���*/
}
else      /*��ǰIO״̬Ϊ�͵�ƽ��*/
{

MC3_SwapDelay=MC3_TIME_H;
MC3_IO_STATE=1;    /*��ǰIO״̬��1*/
MC3_FZ_BZ=FALSE;    /*������ת��־���*/

}


}


void MC4_IO_SWP()
{
switch (MC4_Channel)
{     
    case 0x40:
        LATC6=!LATC6; /*MC1??IO��ת����*/
        break;
     case 0x80:
        LATC7=!LATC7; /*MC1??IO��ת����*/
        break;  
       default:
       printf("����MC4ͨ��!\r\n");      
        break;       
}
  /*RD0??1?*/
if(MC4_IO_STATE==1) /*��ǰIO״̬Ϊ�ߵ�ƽ��*/
{
 MC4_SwapDelay=MC4_TIME_L; /*�͵�ƽʱ�丳ֵ*/
MC4_IO_STATE=0;    /*��ǰIO״̬��0*/
MC4_FZ_BZ=FALSE;    /*������ת��־���*/

}
else      /*��ǰIO״̬Ϊ�͵�ƽ��*/
{

 MC4_SwapDelay=MC4_TIME_H;
MC4_IO_STATE=1;    /*��ǰIO״̬��1*/
MC4_FZ_BZ=FALSE;    /*������ת��־���*/   

}






}


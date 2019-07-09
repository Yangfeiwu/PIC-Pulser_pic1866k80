/*
 * File:   MC_EVENT.c
 * Author: Administrator
 *
 * Created on 2018年8月7日, 下午12:58
 */

#include <xc.h>
#include "MC_EVENT.h"
#include <stdio.h>
#include <stdlib.h>
#include "Config.h"
#include "Register.h"


void MC_EVENT_Trigge()
{
/*对MC1操作*/   
     if(MC1_START_Signal==MC_START)   //启动操作
     {  
             if(MC1_Start_BZ==TRUE) printf("MC1_working,ERROR!\r\n");      
             else{
                             MC1_IO_STATE=0;           //IO状态置0
                             MC1_SwapDelay=10;          /*第一次翻转延迟用*/
                             if(MC1_TIME_H==0)MC1_Start_BZ=FALSE;
                              else
                               {
                                      MC1_Start_BZ=TRUE;
                                   //   printf("MC1_Start success!\r\n");  
                                 }
                   }
     }
     else if(MC1_START_Signal==MC_STOP)
     {
         if(MC1_Start_BZ==FALSE) printf("MC1_stopped,ERROR!\r\n");       
         else{
             
         MC1_Start_BZ=FALSE;
         MC1_FZ_C=0;
         MC1_TIME_H=0;
          printf("MC1_stop success!\r\n");  
         }
         
     }
     
     
        
 /*对MC2操作*/   
     if(MC2_START_Signal==MC_START)   //启动操作
     {  
                                if(MC2_Start_BZ==TRUE) printf("MC2_working,ERROR!\r\n");           
                                 else{  
                                            MC2_IO_STATE=0;           //IO状态置0
                                            MC2_SwapDelay=10;          /*第一次翻转延迟用*/
                                            if(MC2_TIME_H==0)MC2_Start_BZ=FALSE;
                                            else 
                                            {
                                              MC2_Start_BZ=TRUE;
                                             // printf("MC2_Start success!\r\n");    
                                            }
                                     }
     }    
          else if(MC2_START_Signal==MC_STOP)
     {
                                    if(MC2_Start_BZ==FALSE) printf("MC2_stopped,ERROR!\r\n");            
                                    else{      
                                    MC2_Start_BZ=FALSE;
                                    MC2_FZ_C=0;
                                    MC2_TIME_H=0;
                                            printf("MC2_stop success!\r\n");  
                                          }

         
     }
     
     
    /*对MC3操作*/   
     if(MC3_START_Signal==MC_START)   //启动操作
     {  
            if(MC3_Start_BZ==TRUE) printf("MC3_working,ERROR!\r\n");           
            else{     
                          MC3_IO_STATE=0;           //IO状态置0
                          MC3_SwapDelay=10;          /*第一次翻转延迟用*/
                          if(MC3_TIME_H==0)MC3_Start_BZ=FALSE;
                          else 
                          {
                              MC3_Start_BZ=TRUE;
                              //    printf("MC3_Start success!\r\n");  
                          }
                 }
     } 
     else if(MC3_START_Signal==MC_STOP)
     {
  if(MC3_Start_BZ==FALSE) printf("MC3_stopped,ERROR!\r\n");       
  else{
         MC3_Start_BZ=FALSE;
         MC3_FZ_C=0;
         MC3_TIME_H=0;
                 printf("MC3_stop success!\r\n");  
  }   
     }
     
     /*对MC4操作*/   
     if(MC4_START_Signal==MC_START)   //启动操作
       {  
               if(MC4_Start_BZ==TRUE) printf("MC4_working,ERROR!\r\n");           
               else{       

                                MC4_IO_STATE=0;           //IO状态置0
                                MC4_SwapDelay=10;          /*第一次翻转延迟用*/
                                if(MC4_TIME_H==0)MC4_Start_BZ=FALSE;
                                else
                                {
                                       MC4_Start_BZ=TRUE;
                                     //   printf("MC4_Start success!\r\n");  
                                }   
                   }
       }             
      else if(MC4_START_Signal==MC_STOP)
     {
                                if(MC4_Start_BZ==FALSE) printf("MC4_stopped,ERROR!\r\n");       
                               else{    
                                      MC4_Start_BZ=FALSE;
                                      MC4_FZ_C=0;
                                      MC4_TIME_H=0;
                                              printf("MC4_stop success!\r\n");  
                               }
         
     }


}

void MC_END_EVENT()
{
    if(MC1_END_FLAT) 
    { MC1_END_FLAT=0;
        printf("MC1_End success!\r\n"); 
    }
    if(MC2_END_FLAT)   
    {  MC2_END_FLAT=0;
        printf("MC2_End success!\r\n");  
    }
    if(MC3_END_FLAT)   
    {   MC3_END_FLAT=0;
        printf("MC3_End success!\r\n"); 
    }
    if(MC4_END_FLAT)  
    { MC4_END_FLAT=0;
        printf("MC4_End success!\r\n"); 
    }

}
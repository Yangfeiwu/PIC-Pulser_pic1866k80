/*
 * File:   PORT_Filter_OUT.c
 * Author: Administrator
 *
 * Created on 2018年8月8日, 下午3:49
 */


#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include "Config.h"
#include "PORT_Filter_OUT.h"
    void IOKZ_Filter(unsigned char RX,unsigned char PB_BIT,unsigned char PORTX_KZ)
    {

   if(RX==RC) 
   {         
    if(( PB_BIT & 0x01)==!1) LATC0= PORTX_KZ & 0x01;
//    else   printf("RC0被MC1占用中\r\n");   
    if( (PB_BIT>>1 & 0x01)==!1) LATC1= PORTX_KZ>>1 & 0x01;
//    else   printf("RC1被MC1占用中\r\n");   
    if( (PB_BIT>>2 & 0x01)==!1) LATC2= PORTX_KZ>>2 & 0x01; 
//    else   printf("RC2被MC2占用中\r\n");   
    if( (PB_BIT>>3 & 0x01)==!1) LATC3= PORTX_KZ>>3 & 0x01;  
//    else   printf("RC3被MC2占用中\r\n");   
    if( (PB_BIT>>4 & 0x01)==!1) LATC4= PORTX_KZ>>4 & 0x01;
//    else   printf("RC4被MC3占用中\r\n");   
    if( (PB_BIT>>5 & 0x01)==!1) LATC5= PORTX_KZ>>5 & 0x01;
//    else   printf("RC5被MC3占用中\r\n");   
    if( (PB_BIT>>6 & 0x01)==!1) LATC6= PORTX_KZ>>6 & 0x01;   
//    else   printf("RC6被MC4占用中\r\n");
    if( (PB_BIT>>7 & 0x01)==!1) LATC7= PORTX_KZ>>7 & 0x01;
//    else   printf("RC7被MC4占用中\r\n");
    
  
   }
   
      if(RX==RD) 
   {
    if(( PB_BIT & 0x01)==!1) LATD0= PORTX_KZ & 0x01;
    else   printf("RD0被MC1占用中\r\n");   
    if( (PB_BIT>>1 & 0x01)==!1) LATD1= PORTX_KZ>>1 & 0x01;
    else   printf("RD1被MC1占用中\r\n");   
    if( (PB_BIT>>2 & 0x01)==!1) LATD2= PORTX_KZ>>2 & 0x01; 
    else   printf("RD2被MC2占用中\r\n");   
    if( (PB_BIT>>3 & 0x01)==!1) LATD3= PORTX_KZ>>3 & 0x01;  
    else   printf("RD3被MC2占用中\r\n");   
    if( (PB_BIT>>4 & 0x01)==!1) LATD4= PORTX_KZ>>4 & 0x01;
    else   printf("RD4被MC3占用中\r\n");   
    if( (PB_BIT>>5 & 0x01)==!1) LATD5= PORTX_KZ>>5 & 0x01;
    else   printf("RD5被MC3占用中\r\n");   
    if( (PB_BIT>>6 & 0x01)==!1) LATD6= PORTX_KZ>>6 & 0x01;   
    else   printf("RD6被MC4占用中\r\n");
    if( (PB_BIT>>7 & 0x01)==!1) LATD7= PORTX_KZ>>7 & 0x01;
    else   printf("RD7被MC4占用中\r\n");  
   }
   
      if(RX==RF) 
   {
    if(( PB_BIT & 0x01)==!1) LATF0= PORTX_KZ & 0x01;
    else   printf("RF0被MC1占用中\r\n");   
    if( (PB_BIT>>1 & 0x01)==!1) LATF1= PORTX_KZ>>1 & 0x01;
    else   printf("RF1被MC1占用中\r\n");   
    if( (PB_BIT>>2 & 0x01)==!1) LATF2= PORTX_KZ>>2 & 0x01; 
    else   printf("RF2被MC2占用中\r\n");   
    if( (PB_BIT>>3 & 0x01)==!1) LATF3= PORTX_KZ>>3 & 0x01;  
    else   printf("RF3被MC2占用中\r\n");   
    if( (PB_BIT>>4 & 0x01)==!1) LATF4= PORTX_KZ>>4 & 0x01;
    else   printf("RF4被MC3占用中\r\n");   
    if( (PB_BIT>>5 & 0x01)==!1) LATF5= PORTX_KZ>>5 & 0x01;
    else   printf("RF5被MC3占用中\r\n");   
    if( (PB_BIT>>6 & 0x01)==!1) LATF6= PORTX_KZ>>6 & 0x01;   
    else   printf("RF6被MC4占用中\r\n");
    if( (PB_BIT>>7 & 0x01)==!1) LATF7= PORTX_KZ>>7 & 0x01;
    else   printf("RF7被MC4占用中\r\n");  
   }
   

    }
    
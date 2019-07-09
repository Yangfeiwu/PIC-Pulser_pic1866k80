/* 
 * File:   TMR1.c
 * Author: 杨飞武
 * Created on 20180808
 */
#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include "TMR1.h"
#include "Register.h"
#include "Config.h"
#include "IO_SWP.h"
void tmr1_int()
{
     T1CON  =  0X02;                //ָ��ʱ�ӣ�Ԥ��Ƶ��Ϊ1:1
     TMR1H  =  (65536-1560)/256;   //100uS��ʱ
     TMR1L  =  (65536-1560)%256;
     PMD1bits.TMR1MD  =  0;
     T1CONbits.TMR1ON  =  1;        //�ر�������ʱ
     PIE1bits.TMR1IE = 1;         //�ض�ʱ���ж�
     PIR1bits.TMR1IF = 0;
     
}

void tmr1()
{
if(PIR1bits.TMR1IF ==1 &&  PIE1bits.TMR1IE ==1){    
        PIR1bits.TMR1IF =  0;
        TMR1H  =  (65536-1560)/256;   //��ʱ100us
        TMR1L  =  (65536-1560)%256;   //��ʱ100us 
 MC1_SWP_Decision();
 MC2_SWP_Decision();
 MC3_SWP_Decision();
 MC4_SWP_Decision();                  
  if(ct++==2000)
  {
  ct=0;
  LATF7=!LATF7;
//     	TXREG1=0x88;
  }
    }
}



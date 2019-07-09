/*
 * File:   IO_INT.c
 * Author: 杨飞武
 * Created on 20180808
 */


#include <xc.h>
#include "IO_Int.h"
void IO_INT()
{
 /*--------------------C������----------------------*/   
    
PORTC=0X00;   //��RC
LATC=0X00;
TRISC=0x00;    //����RC��ȫΪ�����
//LATC=0xff;       //RC��1����  V_LED

 /*--------------------D������----------------------*/   

PORTD=0X00;   //��RC
LATD=0X00;
TRISD=0x00;    //����RC��ȫΪ�����
//LATD=0xff;       //RC��1����  V_LED

/*--------------------F������----------------------*/   

PORTF=0X00;   //��RC
LATF=0X00;
TRISF=0x00;    //����RC��ȫΪ�����
//LATF=0xff;       //RC��1����  V_LED

}
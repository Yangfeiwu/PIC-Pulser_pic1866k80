/*
 * File:   IO_INT.c
 * Author: Administrator
 *
 * Created on 2017年9月1日, 下午4:21
 */


#include <xc.h>
#include "IO_Int.h"
void IO_INT()
{
 /*--------------------C口配置----------------------*/   
    
PORTC=0X00;   //清RC
LATC=0X00;
TRISC=0x00;    //配置RC口全为输出口
//LATC=0xff;       //RC置1点亮  V_LED

 /*--------------------D口配置----------------------*/   

PORTD=0X00;   //清RC
LATD=0X00;
TRISD=0x00;    //配置RC口全为输出口
//LATD=0xff;       //RC置1点亮  V_LED

/*--------------------F口配置----------------------*/   

PORTF=0X00;   //清RC
LATF=0X00;
TRISF=0x00;    //配置RC口全为输出口
//LATF=0xff;       //RC置1点亮  V_LED

}
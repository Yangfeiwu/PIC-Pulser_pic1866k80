/* 
 * File:   main.c
 * Author: Administrator
 *
 * Created on 20180808
 */

#include <stdio.h>
#include <stdlib.h>
#include "Config.h"

void putch(char data)  // #include <stdio.h> +  #include <stdlib.h> + void putch(char data)   调用printf()，rand()函数。
{
    while(!TXIF)
        continue;
    TXREG=data;
}

int main(int argc, char** argv) {
IO_INT();     //IO初始化 
UartInit();   //串口初始化
tmr1_int(); 
 MC_Start_BZ=0x00;
 MC_IO_STATE=0x00;
  while(TRUE)
  {
      if(RX_flag==Finish)Usart_CL();  //Usart rx finish
      if(MC1_FZ_BZ)MC1_IO_SWP();
      if(MC2_FZ_BZ)MC2_IO_SWP();
      if(MC3_FZ_BZ)MC3_IO_SWP();
      if(MC4_FZ_BZ)MC4_IO_SWP();      
       MC_END_EVENT(); 
  
  }  
    return (EXIT_SUCCESS);  
}


void interrupt  ISR()
{ 
USART_RX(); //串口接收中断子程序
tmr1();  //TRM1子程序（1ms定时时间到）

}    


/* 
 * File:   USART1.c
 * Author: 杨飞武
 * Created on 20180808
 */
 
void UartInit(void)
{
TRISG=0xFF;
RCSTA1bits.SPEN=1;// 串口使能
// TXSTA1：发送状态和控制寄存器
TXSTA1bits.SYNC=0;// 异步模式
TXSTA1bits.TX9=0;// 选择8 位发送
TXSTA1bits.TXEN=1;// 使能发送
TXSTA1bits.BRGH=1;// 高速波特率
TXSTA1bits.TXEN=1;// 使能发送
// RCSTA1：接收状态和控制寄存器
RCSTA1bits.RX9=0;// 选择8位接收
RCSTA1bits.CREN=1;// 使能接收器
// BAUDCON1：波特率控制寄存器
BAUDCON1bits.BRG16=0;// 8位波特率发生器??SPBRGHx 和SPBRGx
SPBRG1=68;  //Set BRG 57600 (16MHZ crystal oscillator ,  BRG mode in High speed )
INTCON=0;
//中断配置
INTCONbits.GIE=1;      //使能全局中断    
INTCONbits.PEIE=1;     //使能外部中断      
PIE1bits.RCIE=1;         //使能接收中断   

}

    void Usart_CL()
    {
        RX_flag=Free;
//     printf("Rx success!\r\n");
  //----------接收数据分类------------------   
   Current_RX=RX[1];
   
 switch(Current_RX)
 {
/*------------------------------------------------------------------*/     
     case  0x01:   //MC1参数接收
       for(int i=0; i<MC_PARM_SIZE;i++) MC1_PARM[i] =  RX[i];
        MC1_PARM_CL(); 
//        printf("MC1_PARM Rx success!\r\n");
         break;
/*------------------------------------------------------------------*/            
      case  0x02: //MC2参数接收
       for(int i=0; i<MC_PARM_SIZE;i++) MC2_PARM[i] =  RX[i];
         MC2_PARM_CL();
//        printf("MC2_PARM Rx success!\r\n");
         break;     
/*------------------------------------------------------------------*/           
      case  0x03:  //MC3参数接收
       for(int i=0; i<MC_PARM_SIZE;i++) MC3_PARM[i] =  RX[i];
         MC3_PARM_CL();       
//        printf("MC3_PARM Rx success!\r\n");
         break;         
 /*------------------------------------------------------------------*/          
        case  0x04:  //MC4参数接收          
       for(int i=0; i<MC_PARM_SIZE;i++) MC4_PARM[i] =  RX[i];
         MC4_PARM_CL();       
//        printf("MC4_PARM Rx success!\r\n");
         break;       
/*------------------------------------------------------------------*/           
         case  0x11:  //MC启动参数接收
       for(int i=0; i<MC_START_PARM_SIZE;i++) McStart_PARM[i] =  RX[i];
        McStart_PARM_CL();
        MC_EVENT_Trigge();
//        printf("McStart_PARM Rx success!\r\n");
         break;  
         
         
 /*------------------------------------------------------------------*/          
         case  0x31: //IO控制参数接收
       for(int i=0; i<IOKZ_PARM_SIZE;i++) RX_IO_PARM[i] =  RX[i];
        RX_IOKZ_PARM();
//        printf("IOKZ_PARM Rx success!\r\n");
         break;  
/*------------------------------------------------------------------*/  
     default:       
         printf("Rx FAIL,Command format error!\r\n");
         break;
     
 
     }
    
  }

void USART_RX()
{
 //   unsigned char data;
    if(RC1IE&&RC1IF)            //判断是否为串口接收中断    
    {  
      
 //         data=RCREG1;
           RX[RX_C++]= RCREG1;    //接收数据   
    //       	TXREG1=data;

       if(RX[0]!=0XD0)RX_C=0;  
         
           if(RX_C>=RX_SIZE)//数据接收完成
            {   
                RX_C=0; 
                RX_flag=Finish;
             }
    } 

}


    
    
    
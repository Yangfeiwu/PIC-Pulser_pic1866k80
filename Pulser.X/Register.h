/* 
 * File:   Register.h
 * Author: 杨飞武
 * Created on 20180808
 */

#ifndef REGISTER_H
#define	REGISTER_H

#ifdef	__cplusplus
extern "C" {
#endif
#define uchar unsigned char    
#define uint unsigned int 

volatile unsigned char MC_Start_BZ @ 0x021 ;  //定义标识寄存器
volatile bit MC1_Start_BZ    @ ((unsigned)&MC_Start_BZ)*8+0;  /*MC1启动标志*/
volatile bit MC2_Start_BZ    @ ((unsigned)&MC_Start_BZ)*8+1;  /*MC2启动标志*/
volatile bit MC3_Start_BZ    @ ((unsigned)&MC_Start_BZ)*8+2;  /*MC3启动标志*/
volatile bit MC4_Start_BZ    @ ((unsigned)&MC_Start_BZ)*8+3;  /*MC4启动标志*/
volatile bit MC1_FZ_BZ    @ ((unsigned)&MC_Start_BZ)*8+4;  
volatile bit MC2_FZ_BZ    @ ((unsigned)&MC_Start_BZ)*8+5;  
volatile bit MC3_FZ_BZ    @ ((unsigned)&MC_Start_BZ)*8+6;  
volatile bit MC4_FZ_BZ    @ ((unsigned)&MC_Start_BZ)*8+7;


volatile unsigned char MC_IO_STATE @ 0x022 ;        
volatile bit MC1_IO_STATE    @ ((unsigned)&MC_IO_STATE)*8+0; 
volatile bit MC2_IO_STATE    @ ((unsigned)&MC_IO_STATE)*8+1;
volatile bit MC3_IO_STATE    @ ((unsigned)&MC_IO_STATE)*8+2; 
volatile bit MC4_IO_STATE    @ ((unsigned)&MC_IO_STATE)*8+3;  
volatile bit MC1_END_FLAT    @ ((unsigned)&MC_IO_STATE)*8+4;  
volatile bit MC2_END_FLAT    @ ((unsigned)&MC_IO_STATE)*8+5; 
volatile bit MC3_END_FLAT    @ ((unsigned)&MC_IO_STATE)*8+6;  
volatile bit MC4_END_FLAT    @ ((unsigned)&MC_IO_STATE)*8+7; 







 uint ct = 0; 

#ifdef	__cplusplus
}
#endif

#endif	/* REGISTER_H */


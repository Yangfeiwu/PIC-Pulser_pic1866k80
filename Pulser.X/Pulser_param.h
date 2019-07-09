/* 
 * File:   Pulser_param.h
 * Author: 杨飞武
 * Created on 20180808
 */

#ifndef PULSER_PARAM_H
#define	PULSER_PARAM_H

#ifdef	__cplusplus
extern "C" {
#endif
#define uchar unsigned char    
#define uint unsigned int     
#define RX_MC1_PARM 0X01;   //接收脉冲1参数
#define RX_MC2_PARM 0X02;   //接收脉冲1参数
#define RX_MC3_PARM 0X03;   //接收脉冲1参数
#define RX_MC4_PARM 0X04;   //接收脉冲1参数    
#define MC_START_PARM 0X11; //接收脉冲启动参数    
#define RX_IOKZ 0X31;   //接收IO控制参数


    
#define MC_PARM_SIZE 8
#define MC_START_PARM_SIZE    6
#define IOKZ_PARM_SIZE    5
#define MC_Channel_NUM 4      //脉冲通道数量(系统限定)
    
 uchar Current_RX=0;  //当前指定接受项
 uchar MC1_START_Signal=0,MC2_START_Signal=0, MC3_START_Signal=0,MC4_START_Signal=0;    //脉冲启动信号
 
 
     uchar    MC1_PARM[MC_PARM_SIZE]={0}, MC2_PARM[MC_PARM_SIZE]={0}, MC3_PARM[MC_PARM_SIZE]={0}, MC4_PARM[MC_PARM_SIZE]={0};  //MC参数接收存储缓存
     uchar    McStart_PARM[MC_START_PARM_SIZE]={0};  //MC启动参数接收存储缓存
     uchar    RX_IO_PARM[IOKZ_PARM_SIZE]={0};     //IO参数接收存储缓存
     uchar    MC_Channel_IO_PARM[MC_Channel_NUM]={0};  //脉冲IO存储
     uchar    MC1_FZ_C=0,MC2_FZ_C=0,MC3_FZ_C=0,MC4_FZ_C=0;  //脉冲次数
     uchar    MC1_Channel=1,MC2_Channel=2,MC3_Channel=4,MC4_Channel=8;  //脉冲通道选择(默认1234通道对应 LATC0 LATC1 LATC2 LATC3)
     uint     MC1_TIME_H=0,MC2_TIME_H=0,MC3_TIME_H=0,MC4_TIME_H=0;  //脉冲高电平时间
     uint     MC1_TIME_L=0,MC2_TIME_L=0,MC3_TIME_L=0,MC4_TIME_L=0; //脉冲低电平时间
 
     uint     MC1_SwapDelay=0,MC2_SwapDelay=0,MC3_SwapDelay=0,MC4_SwapDelay=0;


#ifdef	__cplusplus
}
#endif

#endif	/* PULSER_PARAM_H */


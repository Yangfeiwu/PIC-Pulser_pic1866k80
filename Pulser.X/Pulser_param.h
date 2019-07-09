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
#define RX_MC1_PARM 0X01;   //��������1����
#define RX_MC2_PARM 0X02;   //��������1����
#define RX_MC3_PARM 0X03;   //��������1����
#define RX_MC4_PARM 0X04;   //��������1����    
#define MC_START_PARM 0X11; //����������������    
#define RX_IOKZ 0X31;   //����IO���Ʋ���


    
#define MC_PARM_SIZE 8
#define MC_START_PARM_SIZE    6
#define IOKZ_PARM_SIZE    5
#define MC_Channel_NUM 4      //����ͨ������(ϵͳ�޶�)
    
 uchar Current_RX=0;  //��ǰָ��������
 uchar MC1_START_Signal=0,MC2_START_Signal=0, MC3_START_Signal=0,MC4_START_Signal=0;    //���������ź�
 
 
     uchar    MC1_PARM[MC_PARM_SIZE]={0}, MC2_PARM[MC_PARM_SIZE]={0}, MC3_PARM[MC_PARM_SIZE]={0}, MC4_PARM[MC_PARM_SIZE]={0};  //MC�������մ洢����
     uchar    McStart_PARM[MC_START_PARM_SIZE]={0};  //MC�����������մ洢����
     uchar    RX_IO_PARM[IOKZ_PARM_SIZE]={0};     //IO�������մ洢����
     uchar    MC_Channel_IO_PARM[MC_Channel_NUM]={0};  //����IO�洢
     uchar    MC1_FZ_C=0,MC2_FZ_C=0,MC3_FZ_C=0,MC4_FZ_C=0;  //�������
     uchar    MC1_Channel=1,MC2_Channel=2,MC3_Channel=4,MC4_Channel=8;  //����ͨ��ѡ��(Ĭ��1234ͨ����Ӧ LATC0 LATC1 LATC2 LATC3)
     uint     MC1_TIME_H=0,MC2_TIME_H=0,MC3_TIME_H=0,MC4_TIME_H=0;  //����ߵ�ƽʱ��
     uint     MC1_TIME_L=0,MC2_TIME_L=0,MC3_TIME_L=0,MC4_TIME_L=0; //����͵�ƽʱ��
 
     uint     MC1_SwapDelay=0,MC2_SwapDelay=0,MC3_SwapDelay=0,MC4_SwapDelay=0;


#ifdef	__cplusplus
}
#endif

#endif	/* PULSER_PARAM_H */


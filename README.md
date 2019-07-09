
 # PIC-Pulser_pic1866k80
 * Author: 杨飞武
 * Created on 20180808
 * 基于PIC18F66K80多路可控脉冲输出，及IO控制的下位机程序


# 功能说明：
* PORTC可做脉冲输出通道，在脉冲工作期间会失去对MC占用IO的控制(脉冲结束后释放控制权)
* 24路IO控制。
* 8路脉冲控制， 脉冲个数，宽度可调，控制精度0.1ms。
# Labview上位机展示
![mahua](https://github.com/Yangfeiwu/PIC-Pulser_pic1866k80/blob/master/img/Labview%E4%B8%8A%E4%BD%8D%E6%9C%BA.png)
# 通讯协议

![mahua](https://github.com/Yangfeiwu/PIC-Pulser_pic1866k80/blob/master/img/%E9%80%9A%E4%BF%A1%E5%8D%8F%E8%AE%AE.png)

# PIC18f66k80下位机程序目录结构
## 头文件：
* Config.h
* IO_Int.h
* IO_SWP.h
* MC_EVENT.h
* PARM_CL.h
* PORT_Filter_OUT.h
* TMR1.h
* USART1.h
* Register.h
* Pulser_param.h

## 源文件
* main.c
* IO_INT.c
* IO_SWP.c
* MC_EVENT.c
* PARM_CL.c
* PORT_Filter_OUT.c
* TMR1.c
* USART1.c

# 有问题反馈
在使用中有任何问题，欢迎反馈给我，可以用以下联系方式跟我交流

* 邮件：898109004@qq.com
* QQ: 898109004





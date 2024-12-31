#ifndef __M_H__
#define __M_H__

#include <stdio.h>
#include <dos.h>

extern int M_x, M_y, M_s,M_sc;
/*显示鼠标,参数+1，参数>0时显示鼠标*/
int show_mouse(void);

/*隐藏鼠标,参数-1，参数<=0时隐藏鼠标*/
int hide_mouse(void);

/*检测鼠标驱动是否存在并初始化
dosbox填写0，winxp填写1*/
int initmouse(int x);

/*限制鼠标的运动范围*/
int setmouserange(int xi, int yi, int xa, int ya);

/*得到鼠标的信息，包括位置和按键状态
    M_s检测当前按键状态，M_sc检测按键切换状态
    M_s左键为1右键为2，左右键同时按为3
    弹起则M_sc为相应正数;按下则M_sc为相应负数;否则为0*/
int getmouse(void);//用M_x,M_y,M_s,M_sc分别读取鼠标的横纵坐标、按键状态、按键触发器状态

/*设置鼠标位置*/
void setmouse(int x, int y);

/*检测鼠标是否在矩形区域内*/
int pd(int x,int y,int w,int h);
#endif
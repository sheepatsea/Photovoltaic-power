#ifndef __MYGRAPH_H__
#define __MYGRAPH_H__

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <bios.h>
#include <dos.h>
#include <graphics.h>
#include <stdlib.h>
#include "mouse.h"
#include "hanzi.h"

/*打开vga并检测是否成功打开*/
int initscreen(void);

/*bar的宽高版，mode默认等于-1，否则bar以mode为颜色进行纯色填充*/
void barxy(int x, int y, int w, int h, int mode = -1);

/*弹出信息框，第一个参数为标题，第二个参数为内容*/
void message_box(char *str1 = "", char *str2 = "");
/*弹出中文信息框，第一个str为标题，第二个str为内容*/
void message_box(unsigned int str1[], int n1, unsigned int str2[], int n2);

/*截取屏幕图片并存储
str参数省略则用默认位置
malloc失败返回0；读取失败返回-1
正确运行返回图片内存大小*/
int get_im_txt(int x1, int y1, int w, int h, char *str = "MOREN");
/*取出图片，配合get_im_txt使用
str参数省略则用默认位置
malloc失败返回0；打开失败返回-1
正确运行返回1,mode为复制写/异或等参数*/
int put_im_txt(int x1, int y1, char *str = "MOREN", int mode = 0);

/*在相应的地方画出矩形块，并添加红色边框
并在矩形上输出字符串，字符串内容可空*/
void button(int x, int y, int w, int h, char *str = "");
/*button中文版，yjj为汉字距离顶部的间距,fp为汉字字体*/
void button(int x, int y, int w, int h, unsigned int str[], int n, FILE *&fp = H_z_00, char yjj = 1);

/*输入框的输入函数(保留记录版）
xywh为输入框的参数
name为储存字符串的数组，i储存name的长度
n为输入框可输入最大字符数，请根据输入框大小确定合适的n
s=1则原文显示否则密码显示*/
int write(int x, int y, int w, int h, int s, char *name, int &i, int n);
/*输入框的输入函数(清空记录版) */
int write(int x, int y, int w, int h, int s, char *name, int n);

/*鼠标跟随显示中文信息,w,h为输出框宽高，yjj为汉字距离顶部的间距*/
int withm_message(int w, int h, unsigned int str[], int n, FILE *&fp = H_z_00, char yjj = 1);
/*鼠标跟随显示英文信息*/
int withm_message(int w, int h, char str[]);

#endif
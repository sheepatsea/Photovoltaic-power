#ifndef __HANZI_H__
#define __HANZI_H__

#include <stdio.h>
#include <string.h>
extern FILE *H_z_00;
#include "mygraph.h"

/*传入字符的unicode码，在（x，y）处
输出一个字符，颜色可缺省为背景色，fp为汉字的文件指针，h不用管*/
int put_a_hz(int x, int y, long cha_uni, FILE *&fp = H_z_00, int color = 0, char h = -1);

/*传入字符串的unicode码数组，在（x，y）处
输出列间隔x_jj行间隔y_jj的字符串，颜色可缺省为背景色
并可将字符串限制在宽w高h的矩形中，fp为汉字的文件指针
string数组中0代表终止，1代表换行
kong为行首空格数，juzhong为1则居中*/
void put_s_hz(int x, int y, unsigned int string[], int n, FILE *&fp = H_z_00, int color = 0,
              int x_jj = 2, int y_jj = 4, int w_max = -1, int h_max = -1, unsigned char kong = 0, char juzhong = 0);

/*传入文件指针，打开相应汉字库，默认为32仿宋*/
int sethzmode(FILE *&fp = H_z_00, char *s = "FS32");


#endif
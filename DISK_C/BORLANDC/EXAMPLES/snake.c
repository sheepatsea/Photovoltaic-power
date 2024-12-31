#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>
#include <dos.h> 
#define LEFT 0x4b00
#define RIGHT 0x4d00
#define DOWN 0x5000
#define UP 0x4800
#define ESC 0x011b
#define N 200
#include <graphics.h>
#include <stdlib.h>
#include <dos.h>
#define LEFT 0x4b00
#define RIGHT 0x4d00
#define DOWN 0x5000
#define UP 0x4800
#define ESC 0x011b
int i,key;
int score=0;
int gamespeed=1000;
struct Food
{
   int x;
   int y;
   int yes;
}food;
struct Snake
{
   int x[N];
   int y[N];
   int node;
   int direction;
   int life;
}snake;
void Init(void);
void Close(void);
void DrawK(void);
void GameOver(void);
void GamePlay(void);
void PrScore(void);

void main(void)
{
   Init();
   DrawK();
   GamePlay();
   Close();
}

void Init(void)
{
   int gd=DETECT,gm;
   initgraph(&gd,&gm,"c:\\borlandc\\bgi");
   cleardevice();
}

void DrawK(void)
{

   setcolor(11);
   setlinestyle(SOLID_LINE,0,THICK_WIDTH);
   for(i=50;i<=600;i+=10)
   {
      rectangle(i,40,i+10,49);
      rectangle(i,451,i+10,460);
   }
  for(i=40;i<=450;i+=10)
  {
     rectangle(50,i,59,i+10);
     rectangle(601,i,610,i+10);
  }
}

void GamePlay(void)
{
   randomize();
   food.yes=1;
   snake.life=0;
   snake.direction=1;
   snake.x[0]=100;snake.y[0]=100;
   snake.x[1]=110;snake.y[1]=100;
   snake.node=2;
   PrScore();
   while(1)
   {
      while(!kbhit())
      {
  if(food.yes==1)
  {
      food.x=rand()%400+60;
      food.y=rand()%350+60;
      while(food.x%10!=0)
  food.x++;
      while(food.y%10!=0)
  food.y++;
  food.yes=0;
  }
  if(food.yes==0)
  {
              setcolor(GREEN);
              rectangle(food.x,food.y,food.x+10,food.y-10);
  }
         for(i=snake.node-1;i>0;i--)
         {
            snake.x[i]=snake.x[i-1];
     snake.y[i]=snake.y[i-1];
  }
      
  switch(snake.direction)
  {
     case 1:snake.x[0]+=10;break;
     case 2: snake.x[0]-=10;break;
     case 3: snake.y[0]-=10;break;
     case 4: snake.y[0]+=10;break;
  }
  for(i=3;i<snake.node;i++)
  {
     if(snake.x[i]==snake.x[0]&&snake.y[i]==snake.y[0])
     {
               GameOver();
               snake.life=1;
               break;
     }
        }
 if(snake.x[0]<55||snake.x[0]>595||snake.y[0]<55||
    snake.y[0]>455)
 {
     GameOver();
     snake.life=1;
 }
 if(snake.life==1)
           break;
 if(snake.x[0]==food.x&&snake.y[0]==food.y)
 {
           setcolor(0);
           rectangle(food.x,food.y,food.x+10,food.y-10);
    snake.x[snake.node]=-20;snake.y[snake.node]=-20;
         
    snake.node++;
    food.yes=1;
    score+=10;
    PrScore();
 }
 setcolor(4);
 for(i=0;i<snake.node;i++)
    rectangle(snake.x[i],snake.y[i],snake.x[i]+10,
               snake.y[i]-10);
 delay(gamespeed);
 setcolor(0);
 rectangle(snake.x[snake.node-1],snake.y[snake.node-1],
 snake.x[snake.node-1]+10,snake.y[snake.node-1]-10);
     } 
    if(snake.life==1)
        break;
    key=bioskey(0);
    if(key==ESC)
       break;
    else
       if(key==UP&&snake.direction!=4)

   snake.direction=3;
       else
   if(key==RIGHT&&snake.direction!=2)
      snake.direction=1;
   else
      if(key==LEFT&&snake.direction!=1)
  snake.direction=2;
      else
  if(key==DOWN&&snake.direction!=3)
     snake.direction=4;
   }
}

void GameOver(void)
{
    cleardevice();
    PrScore();
   setcolor(RED);
   settextstyle(0,0,4);
   outtextxy(200,200,"GAME OVER");
   getch();
}

void PrScore(void)
{  
   char str[10];
   setfillstyle(SOLID_FILL,YELLOW);
   bar(50,15,220,35);
   setcolor(6);
   settextstyle(0,0,2);
   sprintf(str,"score:%d",score);
   outtextxy(55,20,str);
}

void Close(void)
{  
    getch();
    closegraph();
}
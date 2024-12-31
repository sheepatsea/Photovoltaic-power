#include"main.h"
#include"public.h"
#include"night.h"

extern int MouseX;
extern int MouseY;
extern int MouseS;
extern int press;

/********************************/
//»­³öÒ¹ÍíÍ¼Ïñ 
/********************************/
void night_show()
{
	int i;
	int star_0[18]={82,75,77,90,64,94,78,99,82,112,86,99,100,94,86,89,82,75},star[3][18]; 
	if(inbutton(158,40,483,328))
	{
		clrmous(MouseX,MouseY);
	}
	setcolor(BLUE);
	setfillstyle(1,BLUE);
	bar(158,40,483,328); 
	draw_cloud();
	realtime_show();
	for(i=0;i<18;i++)
	{
		if(i%2==0)
		{
			star[0][i]=star_0[i]+65;
			star[1][i]=star_0[i]+250;
			star[2][i]=star_0[i]+429;
		}
		else
		{
			star[0][i]=star_0[i]+115;
			star[1][i]=star_0[i]+159;
			star[2][i]=star_0[i]+83;
		}
	}
} 

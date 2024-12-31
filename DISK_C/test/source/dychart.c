#include"main.h"
#include"public.h"
#include"dychart.h"

//*************rectangle(158,328,483,480);  //中二  功率图 

//***********************画出图表背景及坐标 
void chart_show(int plant_mode)
{
	setlinestyle(0,0,NORM_WIDTH);
	setcolor(WHITE);
	setfillstyle(7,LIGHTBLUE);
	settextstyle(0,HORIZ_DIR,0); 
	bar(160,330,480,479);
	line(185,465,185,345);
	line(185,465,475,465);
	outtextxy(175,465,"0");
    outtextxy(450,470,"t(h)");
	outtextxy(240,470,"1");
	outtextxy(300,470,"2");
	outtextxy(360,470,"3");
	outtextxy(420,470,"4");
	switch(plant_mode)
	{
		case 0:
		    outtextxy(160,340,"P(KW)");
	        outtextxy(160,435,"150");
	        outtextxy(160,405,"300");
	        outtextxy(160,375,"450");
	        break;
	    case 1:
		    outtextxy(162,340,"P(KW)");
	        outtextxy(162,435,"10");
	        outtextxy(162,405,"20");
	        outtextxy(162,375,"30");
	        break;
		case 2:
		    outtextxy(162,340,"P(KW)");
	        outtextxy(162,435,"10");
	        outtextxy(162,405,"20");
	        outtextxy(162,375,"30");
	        break;
	    case 3:
		    outtextxy(162,340,"P(KW)");
	        outtextxy(162,435,"100");
	        outtextxy(162,405,"200");
	        outtextxy(162,375,"300");
	        break;
	}

}


//***************更新图表 
void new_chart(int mode,float *dydata,int plant_mode)
{
	int i,cnt;  //计数用 
	static float chart[4][290]={0};  //纵坐标点 
    for(i=0;i<4;i++)
    {
    	for(cnt=289;cnt>0;cnt--)
        {
    	   chart[i][cnt]=chart[i][cnt-1];  //向前传递数组元素，实现曲线的动画 
	    }
	    switch(i)
	    {
	    	case 0:
	            chart[i][0]=dydata[i]/5;  //赋给新产生的数据
				break;
			case 1:
	            chart[i][0]=dydata[i]*3;  //赋给新产生的数据
				break;
			case 2:
	            chart[i][0]=dydata[i]*3;  //赋给新产生的数据
				break;
			case 3:
	            chart[i][0]=dydata[i]*0.3;  //赋给新产生的数据
				break; 		
		}
	}
	
	
	//*************根据所处区域判断是否需要画出图表 
	if(mode==1)  //判断是否在日照变化主页面内 
	{
	   chart_show(plant_mode);
	   setcolor(WHITE);
	   setlinestyle(0,0,NORM_WIDTH);  
	   for(cnt=0;cnt<289;cnt++)
	   {
		   line(185+cnt,465-chart[plant_mode][cnt],185+(cnt+1),465-chart[plant_mode][cnt+1]);
	   }
	}
	
	
}

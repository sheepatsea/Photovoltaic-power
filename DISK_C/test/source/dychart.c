#include"main.h"
#include"public.h"
#include"dychart.h"

//*************rectangle(158,328,483,480);  //�ж�  ����ͼ 

//***********************����ͼ���������� 
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


//***************����ͼ�� 
void new_chart(int mode,float *dydata,int plant_mode)
{
	int i,cnt;  //������ 
	static float chart[4][290]={0};  //������� 
    for(i=0;i<4;i++)
    {
    	for(cnt=289;cnt>0;cnt--)
        {
    	   chart[i][cnt]=chart[i][cnt-1];  //��ǰ��������Ԫ�أ�ʵ�����ߵĶ��� 
	    }
	    switch(i)
	    {
	    	case 0:
	            chart[i][0]=dydata[i]/5;  //�����²���������
				break;
			case 1:
	            chart[i][0]=dydata[i]*3;  //�����²���������
				break;
			case 2:
	            chart[i][0]=dydata[i]*3;  //�����²���������
				break;
			case 3:
	            chart[i][0]=dydata[i]*0.3;  //�����²���������
				break; 		
		}
	}
	
	
	//*************�������������ж��Ƿ���Ҫ����ͼ�� 
	if(mode==1)  //�ж��Ƿ������ձ仯��ҳ���� 
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

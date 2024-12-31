#include"public.h"
#include"main.h"
#include"error.h"
#define N1 2000  //一个光伏板有两块板
#define N2 70
#define N3 120
#define N4 700
struct ERRORS{
	int plant_0;
	int mount_0;
	int mount_1;
	int condition;
    int time[2][4];
};

extern int MouseX;
extern int MouseY;
extern int MouseS;
extern int press;

void error_file_read(struct ERRORS *perr)
{
	FILE *fp;
	int i,j,k;
	for(i=0;i<10;i++)
	{
		switch(i)
		{
			case 0:
				fp=fopen("error\\error1.txt","rt");
				break;
			case 1:
				fp=fopen("error\\error2.txt","rt");
				break;
			case 2:
				fp=fopen("error\\error3.txt","rt");
				break;
			case 3:
				fp=fopen("error\\error4.txt","rt");
				break;
			case 4:
				fp=fopen("error\\error5.txt","rt");
				break;
			case 5:
				fp=fopen("error\\error6.txt","rt");
				break;
			case 6:
				fp=fopen("error\\error7.txt","rt");
				break;
			case 7:
				fp=fopen("error\\error8.txt","rt");
				break;
			case 8:
				fp=fopen("error\\error9.txt","rt");
				break;
			case 9:
				fp=fopen("error\\error10.txt","rt");
				break;
	
		}
		fscanf(fp,"%d%d%d%d",&perr[i].plant_0,&perr[i].mount_0,&perr[i].mount_1,&perr[i].condition);
		for(j=0;j<2;j++)
		{
			for(k=0;k<4;k++)
			{
				fscanf(fp,"%d",&perr[i].time[j][k]);
			}
		}
		fclose(fp);
	    
	}
}
void error_file_print(struct ERRORS *perr)
{
	FILE *fp;
	int i,j,k;
	for(i=0;i<10;i++)
	{
			switch(i)
		{
			case 0:
				fp=fopen("error\\error1.txt","wt+");
				break;
			case 1:
				fp=fopen("error\\error2.txt","wt+");
				break;
			case 2:
				fp=fopen("error\\error3.txt","wt+");
				break;
			case 3:
				fp=fopen("error\\error4.txt","wt+");
				break;
			case 4:
				fp=fopen("error\\error5.txt","wt+");
				break;
			case 5:
				fp=fopen("error\\error6.txt","wt+");
				break;
			case 6:
				fp=fopen("error\\error7.txt","wt+");
				break;
			case 7:
				fp=fopen("error\\error8.txt","wt+");
				break;
			case 8:
				fp=fopen("error\\error9.txt","wt+");
				break;
			case 9:
				fp=fopen("error\\error10.txt","wt+");
				break;
	
		}
		fprintf(fp,"%d\t%d\t%d\t%d\t",perr[i].plant_0,perr[i].mount_0,perr[i].mount_1,perr[i].condition);
		for(j=0;j<2;j++)
		{
			for(k=0;k<4;k++)
			{
				fprintf(fp,"%d\t",perr[i].time[j][k]);
			}
		}
		fclose(fp);
	}
}

void error_init()
{
 	int cnt;
 	clrmous(MouseX,MouseY);
    setlinestyle(0,0,NORM_WIDTH);
    setcolor(LIGHTCYAN);
    rectangle(5,340,155,480);  //左三   报错 
    line(5,360,115,360);
    line(115,360,155,340);
    puthz(10,342,"故障检测",16,32,LIGHTCYAN);
    setcolor(LIGHTCYAN);
    setlinestyle(0,0,NORM_WIDTH);
    line(5,380,155,380);
   	line(5,405,155,405);
   	line(5,430,155,430);
   	line(5,455,155,455);
   	puthz(10,362,"站点",16,16,LIGHTCYAN);
   	puthz(60,362,"数量",16,16,LIGHTCYAN);
   	puthz(110,362,"状态",16,16,LIGHTCYAN);
   	for(cnt=0;cnt<4;cnt++)
   	{
   		if(cnt%2==0)
	    {
	      	setfillstyle(7,LIGHTBLUE);
	    }
	    else
    	{   
	    	setfillstyle(1,CYAN);
     	}
			bar(5,380+cnt*25,155,405+cnt*25);
			rectangle(5,380+cnt*25,155,405+cnt*25);
	}	
}

void init_error_file(struct ERRORS *perr)
{
	FILE *fp;
	int i,j,k,a[4]={0,0,0,0};
	for(i=0;i<10;i++)
	{
		switch(i)
		{
			case 0:
				fp=fopen("error\\error1.txt","wt+");
				break;
			case 1:
				fp=fopen("error\\error2.txt","wt+");
				break;
			case 2:
				fp=fopen("error\\error3.txt","wt+");
				break;
			case 3:
				fp=fopen("error\\error4.txt","wt+");
				break;
			case 4:
				fp=fopen("error\\error5.txt","wt+");
				break;
			case 5:
				fp=fopen("error\\error6.txt","wt+");
				break;
			case 6:
				fp=fopen("error\\error7.txt","wt+");
				break;
			case 7:
				fp=fopen("error\\error8.txt","wt+");
				break;
			case 8:
				fp=fopen("error\\error9.txt","wt+");
				break;
			case 9:
				fp=fopen("error\\error10.txt","wt+");
				break;
	
		}
		fprintf(fp,"%d\t%d\t%d\t%d\t",a[0],a[1],a[2],a[3]);
		for(j=0;j<2;j++)
		{
			for(k=0;k<4;k++)
			{
				fprintf(fp,"%d\t",a[0]);
			}
		}
		fclose(fp);
	}
}



void error_monitor(int mode,int *perrors,int daytime,struct DAYDATA date)  //perror存储站点和数量，对实际发电做出影响 
{
	static int engage_point=0,standard;  //point变化，达到standard就产生故障 
	static struct ERRORS err[10];  //存储字符串和状态来显示 
	static int cnt=0;  //故障数 
	static int repair_time[10]={0,0,0,0,0,0,0,0};	
	int i;
	for(i=0;i<=cnt;i++)
	{
		perrors[err[i].plant_0]=0;
	}
	if(cnt==0)
	{
		init_error_file(err);  //故障文件初始化 
		
	}
	if(engage_point==0)
	{
	    srand((unsigned)time(NULL));
	    standard=rand()%720+720;   //生成错误的标准时长  
	}
	engage_point++;
	if(daytime==0)
	{
		error_file_read(err);  //读取故障信息 
		cnt=error_list_new(err);  //更新故障数目及文件信息 
	
		if(mode==1)  //显示 
		{
		  error_init();
		  error_show(err);	  
		}
		else if(mode==6)
		{
			in_error_init();
			in_error_show(err);
		}
		
	}
	  error_file_read(err);
	for(i=0;i<10;i++)
	{
		if(err[i].condition==2)   //正在维修 
		{
			repair_time[i]++;
		}
		if(repair_time[i]==120)  //维修完成 
		{
			repair_time[i]=0;
			err[i].condition=3;
			err[i].mount_0=0; 
			err[i].time[1][0]=date.year;
			err[i].time[1][1]=date.month;
			err[i].time[1][2]=date.day;
			err[i].time[1][3]=daytime;
			error_file_print(err);
			if(mode==1)
			{
			   error_init();
			   error_show(err);	
			}
			else if(mode==6)
		   {
			in_error_init();
			in_error_show(err);
	    	}
		}
    }
    
	for(i=0;i<=cnt;i++)
	{
		perrors[err[i].plant_0]+=err[i].mount_0;
	}
	
	if(engage_point==standard)
	{
		if(cnt<10)
		{
			
			error_engage(err,cnt,daytime,date);  //故障发生 
			if(mode==1)
	    {
	    	error_init();
	    	error_show(err);  //发生故障显示 
     	}
     	else if(mode==6)
		{
			in_error_init();
			in_error_show(err);
		}
	    engage_point=0;
	    standard=0; 
	    cnt++;  //计数加一
		}
	    else
	    {
	    	engage_point=0;
		}
	}
	
}

int error_list_new(struct ERRORS *perr)
{
	int i,j,k,temp;
	struct ERRORS medium;
	for(i=0;i<10;i++)
		{
			if(perr[i].condition==3)
			{
				perr[i].condition=0;
				perr[i].mount_0=0;
				perr[i].mount_1=0;
				perr[i].plant_0=0;
				for(j=0;j<2;j++)
				{
					for(k=0;k<4;k++)
					{
						perr[i].time[j][k]=0;
					}
				}
			 } 
		}
		error_file_print(perr);
		for(i=0;i<10;i++)
		{
			for(j=i+1;j<10;j++)
			{
				if(perr[i].condition==0&&perr[j].condition!=0)
			{
				medium=perr[i];
				perr[i]=perr[j];
				perr[j]=medium;
				break;
			}
			}
		}
		error_file_print(perr);
		for(temp=0;temp<10;temp++)
		{
			if(perr[temp].condition==0)
			{
				return temp;
			}
		}
		return temp;
}

void time_transfer(int year,int month,int day,int daytime,char *p_time)
{
	char str_year[20];
    char str_month[5];
    char str_day[5];
	int minute,hour;
	int i; 
	int a[4];
	char str[4][3];
    year+=2000;
	itoa(year,str_year,10);
    year-=2000;
	itoa(month,str_month,10);
	itoa(day,str_day,10);
    strcat(str_year,".");
	strcat(str_year,str_month);
    strcat(str_year,".");
	strcat(str_year,str_day);
	
	
	minute=daytime%60;
    a[3]=minute%10;
	a[2]=minute/10;
	hour=daytime/60;
	a[1]=hour%10;
	a[0]=hour/10;
	

	for(i=0;i<4;i++)
	  {
		 itoa(a[i],str[i],10);
	  }
	  strcat(str[0],str[1]);
	  strcat(str[0],":");
	  strcat(str[0],str[2]);
	  strcat(str[0],str[3]);
	  strcpy(p_time,str_year); 
	  strcat(p_time," "); 
	  strcat(p_time,str[0]);
}

void error_engage(struct ERRORS *perr,int cnt,int daytime,struct DAYDATA date)
{
	FILE *fp;
	int j,k;
	srand((unsigned)time(NULL));
	perr[cnt].plant_0=rand()%4;	
	switch(perr[cnt].plant_0)
	{
		case 0:
			perr[cnt].mount_0=rand()%(N1/20);
			break;
		case 1:
			perr[cnt].mount_0=rand()%(N2/20);
			break;
		case 2:
			perr[cnt].mount_0=rand()%(N3/20);
			break;
		case 3:
			perr[cnt].mount_0=rand()%(N4/20);
			break;
		}
		if(perr[cnt].mount_0==0)
		{
			perr[cnt].mount_0++;
		}
	perr[cnt].mount_1=perr[cnt].mount_0;
	perr[cnt].condition=1;
	perr[cnt].time[0][0]=date.year;
	perr[cnt].time[0][1]=date.month;
	perr[cnt].time[0][2]=date.day;
	perr[cnt].time[0][3]=daytime;
	switch(cnt)
	{
			case 0:
				fp=fopen("error\\error1.txt","wt+");
				break;
			case 1:
				fp=fopen("error\\error2.txt","wt+");
				break;
			case 2:
				fp=fopen("error\\error3.txt","wt+");
				break;
			case 3:
				fp=fopen("error\\error4.txt","wt+");
				break;
			case 4:
				fp=fopen("error\\error5.txt","wt+");
				break;
			case 5:
				fp=fopen("error\\error6.txt","wt+");
				break;
			case 6:
				fp=fopen("error\\error7.txt","wt+");
				break;
			case 7:
				fp=fopen("error\\error8.txt","wt+");
				break;
			case 8:
				fp=fopen("error\\error9.txt","wt+");
				break;
			case 9:
				fp=fopen("error\\error10.txt","wt+");
				break;
	}
	fprintf(fp,"%d\t%d\t%d\t%d\t",perr[cnt].plant_0,perr[cnt].mount_0,perr[cnt].mount_1,perr[cnt].condition);
	for(j=0;j<2;j++)
		{
			for(k=0;k<4;k++)
			{
				fprintf(fp,"%d\t",perr[cnt].time[j][k]);
			}
		}
	fclose(fp);
}

void error_show(struct ERRORS *perr)
{
	int cnt;
	char plant[4][20],mount[4][20];
	clrmous(MouseX,MouseY);
	setcolor(LIGHTCYAN);
	settextstyle(0,0,1);
	for(cnt=0;cnt<4;cnt++)
	{
		itoa(perr[cnt].mount_1,mount[cnt],10);
	    itoa(perr[cnt].plant_0,plant[cnt],10);
		plant[cnt][0]+=1;
	}
	for(cnt=0;cnt<4;cnt++)
	{
			if(perr[cnt].condition!=0)
		    {
			    outtextxy(20,385+25*cnt,plant[cnt]);
			    outtextxy(70,385+25*cnt,mount[cnt]);
		        outtextxy(125,385+25*cnt,"X");
			}
	}
}

void in_error_show(struct ERRORS *perr)
{
	int cnt;
	char p1[10][20],p2[10][20];
	char mount[10];
	clrmous(MouseX,MouseY);
	setcolor(LIGHTCYAN);
	setlinestyle(0,0,NORM_WIDTH);
	settextstyle(0,0,1);
	for(cnt=0;cnt<10;cnt++)
	{
			if(perr[cnt].condition!=0)
		    {
			    switch(perr[cnt].plant_0)
			    {
			    	case 0:
			    		puthz(30,87+32*cnt,"一号站点",16,16,LIGHTCYAN);
			    		break;
			    	case 1:
			    		puthz(30,87+32*cnt,"二号站点",16,16,LIGHTCYAN);
			    		break;
			    	case 2:
			    		puthz(30,87+32*cnt,"三号站点",16,16,LIGHTCYAN);
			    		break;
			    	case 3:
			    		puthz(30,87+32*cnt,"四号站点",16,16,LIGHTCYAN);
			    		break;
				}
				itoa(perr[cnt].mount_1,mount,10);
			    outtextxy(153,92+32*cnt,mount);
				time_transfer(perr[cnt].time[0][0],perr[cnt].time[0][1],perr[cnt].time[0][2],perr[cnt].time[0][3],p1[cnt]);
			   	time_transfer(perr[cnt].time[1][0],perr[cnt].time[1][1],perr[cnt].time[1][2],perr[cnt].time[1][3],p2[cnt]);
			    if(perr[cnt].condition==1)
			    {
			        puthz(242,90+32*cnt,"待修",16,16,LIGHTCYAN);
			        outtextxy(325,92+32*cnt,p1[cnt]); 
			    }
			    else if(perr[cnt].condition==2)
			    {
			    	puthz(237,90+32*cnt,"处理中",16,16,LIGHTCYAN);
			    	outtextxy(325,92+32*cnt,p1[cnt]); 
				}
			    else if(perr[cnt].condition==3)
			   	{
			   		
			   		puthz(242,87+32*cnt,"已修",16,16,LIGHTCYAN);
			   		outtextxy(325,92+32*cnt,p1[cnt]);  
				    outtextxy(500,92+32*cnt,p2[cnt]);
				}   
			}
	}
	
}
void error()
{
	static struct ERRORS err[10]; 
	int meaningless_menu=5,meaningless_plant=5;
	int change=0; 
    clrmous(MouseX,MouseY);
	cleardevice();
	in_error_init(); 
	error_file_read(err);
	in_error_show(err);
	while(1)
	{
		if(change<9999)
		{
			change++;
		}
		else
		{
			change=0;
			error_file_read(err);
		}
		func(6,&meaningless_plant,&meaningless_menu);
		newmouse(&MouseX,&MouseY,&press);
		if(inbutton(210,80,310,112))
		{
		    if(err[0].condition==1)
		    {
		        MouseS=1;
				if(mouse_press(210,80,310,112)==1)	
				{
					error_condition_new(err,0);
				}
			}
		} 
		else if(inbutton(210,112,310,144))
		{
		    if(err[1].condition==1)
		    {
		        MouseS=1;
				if(mouse_press(210,112,310,144)==1)	
				{
					error_condition_new(err,1);
				}
			}
		} 
		else if(inbutton(210,144,310,176))
		{
		    if(err[2].condition==1)
		    {
		        MouseS=1;
				if(mouse_press(210,144,310,176)==1)	
				{
					error_condition_new(err,2);
				}
			}
		} 
		else if(inbutton(210,176,310,208))
		{
		    if(err[3].condition==1)
		    {
		        MouseS=1;
				if(mouse_press(210,176,310,208)==1)	
				{
					error_condition_new(err,3);
				}
			}
		} 
		else if(inbutton(210,208,310,240))
		{
		    if(err[4].condition==1)
		    {
		        MouseS=1;
				if(mouse_press(210,208,310,240)==1)	
				{
					error_condition_new(err,4);
				}
			}
		} 
		else if(inbutton(210,240,310,272))
		{
		    if(err[5].condition==1)
		    {
		        MouseS=1;
				if(mouse_press(210,240,310,272)==1)	
				{
					error_condition_new(err,5);
				}
			}
		} 
		else if(inbutton(210,272,310,304))
		{
		    if(err[6].condition==1)
		    {
		        MouseS=1;
				if(mouse_press(210,272,310,304)==1)	
				{
					error_condition_new(err,6);
				}
			}
		} 
		else if(inbutton(210,304,310,336))
		{
		    if(err[7].condition==1)
		    {
		        MouseS=1;
				if(mouse_press(210,304,310,336)==1)	
				{
					error_condition_new(err,7);
				}
			}
		} 
		else if(inbutton(210,336,310,368))
		{
		    if(err[8].condition==1)
		    {
		        MouseS=1;
				if(mouse_press(210,336,310,368)==1)	
				{
					error_condition_new(err,8);
				}
			}
		}
		else if(inbutton(210,368,310,400))
		{
		    if(err[9].condition==1)
		    {
		        MouseS=1;
				if(mouse_press(210,368,310,400)==1)	
				{
					error_condition_new(err,9);
				}
			}
		}  
		else if(inbutton(560,420,630,450)) 
		{
			MouseS=1;
			if(mouse_press(560,420,630,450)==1)
			{
				return ;
			}
		}
		else
		{
			MouseS=0;
		}
    }
}

void error_condition_new(struct ERRORS *perr,int error_number)
{
    if(perr[error_number].condition==1)
    {
    	perr[error_number].condition=2;
     	error_file_print(perr);
     	clrmous(MouseX,MouseY);
    	in_error_init();
    	in_error_show(perr);
    	newmouse(&MouseX,&MouseY,&press);
	}
}

void in_error_init()
{
	int i;
	clrmous(MouseX,MouseY);
	setbkcolor(BLUE);
	setfillstyle(7,LIGHTBLUE);
	setlinestyle(0,0,NORM_WIDTH);
	setcolor(LIGHTCYAN);
	bar(0,0,640,480);

	setfillstyle(1,CYAN);
	
	rectangle(10,50,630,400);
	
	rectangle(560,420,630,450);
	puthz(572,428,"返回",16,32,LIGHTCYAN); 
	
	rectangle(10,50,630,400);

	
	for(i=0;i<10;i++)
	{
		if(i%2==0)
		{
		  bar(10,80+32*i,630,112+i*32);	
		}
		rectangle(10,80+32*i,630,112+i*32);
	}
	line(110,50,110,400);
	line(210,50,210,400);
	line(310,50,310,400);
	line(470,50,470,400);
	puthz(30,57,"站点编号",16,16,LIGHTCYAN);
	puthz(130,57,"故障数目",16,16,LIGHTCYAN);
    puthz(230,57,"当前状态",16,16,LIGHTCYAN);
    puthz(360,57,"产生时间",16,16,LIGHTCYAN);
    puthz(520,57,"解决时间",16,16,LIGHTCYAN);
}
	
	



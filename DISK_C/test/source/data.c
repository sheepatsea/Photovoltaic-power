#include"public.h"
#include"data.h"
#define PI 3.141592653589793
#define E_sc 1367
#define P0 1013
extern struct DAYDATA{
	int year;
	int month;
	int day;
    float plant[4][49];
	char file_name[4][50];
	int weekday;
	int weather_mode[4]; 
	float energy[4]; 
};

extern struct SUNDATA
{
    int N;  //日序
    float Fai;  //纬度 
    float Delta;  //赤纬角 
	float Omega_S;  //日出角 
	float Gamma;  //太阳系数 
	float E_0;  //当天辐射 
	float E_sb;   //实时辐射 
	float h;  //高度角 
	float a;  //透明度 
	float m;  //大气质量 
	float Omega; 
	float p;
};

void calculate_N(struct DAYDATA date,struct SUNDATA *psunpower)
{
	int cnt,day=0;
	switch(date.month)
	{
		case 12: 
		   day+=30;
		case 11: 
		   day+=31;
		case 10: 
		   day+=30;
		case 9: 
		   day+=31;
		case 8: 
		   day+=31;
		case 7: 
		   day+=30;
		case 6: 
		   day+=31;
		case 5: 
		   day+=30;
		case 4: 
		   day+=31;
		case 3: 
		   if((date.year%400==0)||(date.year%4==0&&date.year%100!=0))
		   {
		     day+=29;	
		   }
		   else
		   {
		   	 day+=28;
		   }
		case 2:
		   day+=31;
		case 1: 
		   day+=date.day;
		   break;
	}
	for(cnt=0;cnt<4;cnt++)
	{
		psunpower[cnt].N=day;
	}
}
//**************************************根据天气与季节获取每天的发电功率 
void get_data(struct DAYDATA *pdate,struct SUNDATA *psunpower)
{
	int i,cnt;  //计数用 
	psunpower[0].Fai=30.3464;
	psunpower[1].Fai=28.9738;
	psunpower[2].Fai=41.5307;
	psunpower[3].Fai=35.6663;
	
	psunpower[0].p=1016;
	psunpower[1].p=982;
	psunpower[2].p=990;
	psunpower[3].p=1010;
	
    calculate_N(*pdate,psunpower);	
    for(i=0;i<4;i++)
    {
    	psunpower[i].Delta=23.45*sin(2*PI*(284+1.0*psunpower[i].N)/365);
    	psunpower[i].Gamma=1+0.033*cos(2*PI*(psunpower[i].N-3)/365);
    	
		psunpower[i].Omega_S=-acos(-tan(psunpower[i].Fai/180*PI)*tan(psunpower[i].Delta/180*PI))/PI*180;
		psunpower[i].E_0=E_sc*psunpower[i].Gamma;
		switch(pdate->weather_mode[i])
	    {
		case 0:
			psunpower[i].a=0.820;
			break;
		case 1:
			psunpower[i].a=0.740;
			break;
		case 2:
			psunpower[i].a=0.650;
			break;
	    }
	    
	}
}

 void dynamic_data(int daytime,struct DAYDATA *pdate,float *pdydata,struct SUNDATA *psunpower,int perrors[4])
 {
    float S[4]={1.25,1.8,2.58,1.95};  //光伏板面积 
	int N[4]={2000,70,120,700};  //光伏板数目 
	float P[4]={0.225,0.235,0.237,0.235};  //正面功率 
    static float sum[4]={0,0,0,0};
    int i;
    float medium; 
    for(i=0;i<4;i++)
    {
        psunpower[i].Omega=(daytime-720)*0.25;
    	psunpower[i].h=asin(sin(psunpower[i].Fai*PI/180)*sin(psunpower[i].Delta*PI/180)+cos(psunpower[i].Fai*PI/180)*cos(psunpower[i].Delta*PI/180)*cos(psunpower[i].Omega*PI/180))*180/PI; 
        if(psunpower[i].Omega<=psunpower[i].Omega_S||psunpower[i].Omega>=-psunpower[i].Omega_S)
        {
        	psunpower[i].E_sb=0;
        	psunpower[i].m=0; 
		}
		else 
		{
    	psunpower[i].m=psunpower[i].p/P0/sin(psunpower[i].h*PI/180);
		psunpower[i].E_sb=psunpower[i].E_0*pow(psunpower[i].a,psunpower[i].m)*sin(psunpower[i].h*PI/180);
		}
    
	
		
		N[i]-=perrors[i];
    	//**********计算实时功率
		pdydata[i]=P[i]*N[i]*psunpower[i].E_sb/1000;
	   sum[i]+=pdydata[i];  
	}

	if((daytime%30==0)&&daytime!=0)
	{
		 for(i=0;i<4;i++)
	    {
	    	pdate->plant[i][daytime/30-1]=sum[i]/30;
	    	sum[i]=0;
		}
	}
 }
 


void putin_data(struct DAYDATA date)
{
	FILE *fpdata;
	int i,cnt;
   for(i=0;i<4;i++)
		{
		    fpdata=fopen(date.file_name[i],"wt+");
		    fprintf(fpdata,"%d\t%d\t",date.weekday,date.weather_mode[i]);
	   	    for(cnt=0;cnt<49;cnt++)
	        {
		        fprintf(fpdata,"%.2f\t",date.plant[i][cnt]);
	        }
	        fclose(fpdata);	
		}	
}		 

void putin_last(struct DAYDATA date)
{
	FILE *fplast;
	    fplast=fopen("DATA\\last.txt","wt+");
	    {
		    fprintf(fplast,"%d\t%d\t%d\t%s\t%s\t%s\t%s\t",date.year,date.month,date.day,date.file_name[0],date.file_name[1],date.file_name[2],date.file_name[3]);
	    }
	    fclose(fplast);
}

void putin_start(struct DAYDATA date)
{
	FILE *fpstart;
	int cnt;
	fpstart=fopen("DATA\\start.txt","wt+");
	{
		fprintf(fpstart,"%d\t%d\t%d\t%s\t%s\t%s\t%s\t%d\t",date.year,date.month,date.day,date.file_name[0],date.file_name[1],date.file_name[2],date.file_name[3],date.weekday);
	}
	for(cnt=0;cnt<4;cnt++)
	{
		fprintf(fpstart,"%d\t",date.weather_mode[cnt]);
	}
	fclose(fpstart);
}
void putin_day(struct DAYDATA date)
{
	FILE *fpday;
	char STR[40]="DAY\\",s_year[30],s_month[4],s_day[4];
	float sum[4]={0};
	int cnt,i;
	for(i=0;i<4;i++)
	{
	  for(cnt=0;cnt<49;cnt++)
	  {
	     sum[i]+=date.plant[i][cnt]*0.5;	
	  }
	}
	
	itoa(date.year,s_year,10);
	itoa(date.month,s_month,10);
	itoa(date.day,s_day,10);
	strcat(s_year,"_");
	strcat(s_year,s_month);
	strcat(s_year,"_");
	strcat(s_year,s_day);
	strcat(s_year,".txt");
	strcat(STR,s_year);
	fpday=fopen(STR,"wt+");
	for(i=0;i<4;i++)
	{
		fprintf(fpday,"%.2f\t",sum[i]);
	}
	fclose(fpday);
	
}

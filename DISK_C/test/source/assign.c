#include"public.h"
#include"main.h"
#include"assign.h"

void weekago_search(struct DAYDATA *pyesterday,struct DAYDATA *pweekago)
{
	if(pyesterday->day>6)
	{
		pweekago->day=pyesterday->day-6;
		pweekago->month=pyesterday->month;
		pweekago->year=pyesterday->year;
	}
	else
	{
		switch(pyesterday->month)
		{
			case 2:
			case 4:
			case 6:
			case 8:
			case 9:
			case 11:
				pweekago->month=pyesterday->month-1;
				pweekago->year=pyesterday->year;
				pweekago->day=pyesterday->day+25;
				break;
			case 5:
			case 7:
			case 10:
			case 12:
				pweekago->month=pyesterday->month-1;
				pweekago->year=pyesterday->year;
				pweekago->day=pyesterday->day+24;
				break;
			case 3:
			    pweekago->month=2;
				pweekago->year=pyesterday->year;
				if(pyesterday->year%400==0||(pyesterday->year%4==0&&pyesterday->year%100!=0))
				{
					pweekago->day=pyesterday->day+23;
				}
				else
				{
					pweekago->day=pyesterday->day+22;
				}
				break;
			case 1:
				pweekago->month=12;
				pweekago->year=pyesterday->year-1;
				pweekago->day=pyesterday->day+25;
				break;
	    }
	}
}

void threedayago_search(struct DAYDATA *pyesterday,struct DAYDATA *pdaysago)
{
	if(pyesterday->day>2)
	{
		pdaysago->day=pyesterday->day-2;
		pdaysago->month=pyesterday->month;
		pdaysago->year=pyesterday->year;
	}
	else
	{
		switch(pyesterday->month)
		{
			case 2:
			case 4:
			case 6:
			case 8:
			case 9:
			case 11:
				pdaysago->month=pyesterday->month-1;
				pdaysago->year=pyesterday->year;
				pdaysago->day=pyesterday->day+29;
				break;
			case 5:
			case 7:
			case 10:
			case 12:
				pdaysago->month=pyesterday->month-1;
				pdaysago->year=pyesterday->year;
				pdaysago->day=pyesterday->day+28;
				break;
			case 3:
			    pdaysago->month=2;
				pdaysago->year=pyesterday->year;
				if(pyesterday->year%400==0||(pyesterday->year%4==0&&pyesterday->year%100!=0))
				{
					pdaysago->day=pyesterday->day+27;
				}
				else
				{
					pdaysago->day=pyesterday->day+26;
				}
				break;
			case 1:
				pdaysago->month=12;
				pdaysago->year=pyesterday->year-1;
				pdaysago->day=pyesterday->day+29;
				break;
	    }
	}
	search_data(pdaysago);
}

void monthago_search(struct DAYDATA *pyesterday,struct DAYDATA *pmonthago)
{
	switch(pyesterday->month)
	{
		case 3:
			if(pyesterday->year%400==0||(pyesterday->year%4==0&&pyesterday->month%100!=0))
			{
				if(pyesterday->day==31||pyesterday->day==30)
				{
					pmonthago->month=2;
					pmonthago->year=pyesterday->year;
					pmonthago->day=29;
				}
				else
				{
					pmonthago->month=2;
					pmonthago->year=pyesterday->year;
					pmonthago->day=pyesterday->day;
				}
			}
			else
			{
				if(pyesterday->day==31||pyesterday->day==30||pyesterday->day==29)
				{
					pmonthago->month=2;
					pmonthago->year=pyesterday->year;
					pmonthago->day=28;
				}
				else
				{
					pmonthago->month=2;
					pmonthago->year=pyesterday->year;
					pmonthago->day=pyesterday->day;
				}
			}
			break;
		case 5:
		case 7:
		case 10:
		case 12:
			if(pyesterday->day==31)
			{
				pmonthago->month=pyesterday->month-1;
				pmonthago->day=30;
				pmonthago->year=pyesterday->year;
			}
			else
			{
				pmonthago->month=pyesterday->month-1;
				pmonthago->day=pyesterday->day;
				pmonthago->year=pyesterday->year;
			}
			break;
		case 2:
		case 4:
		case 6:
		case 8:
		case 9:
		case 11:
			pmonthago->month=pyesterday->month-1;
			pmonthago->day=pyesterday->day;
			pmonthago->year=pyesterday->year;
			break;
		case 1:
			pmonthago->month=12;
			pmonthago->day=pyesterday->day;
			pmonthago->year=pyesterday->year-1;
			break;
	}
} 

int orderjudge(struct DAYDATA *pdate_data,struct DAYDATA *pyesterday)
{
	if(pdate_data->year>pyesterday->year)
	{
		return 0;
	}
	else if(pdate_data->year<pyesterday->year)
	{
		return 1;
	}
	else
	{
		if(pdate_data->month>pyesterday->month)
		{
			return 0;
		}
		else if(pdate_data->month<pyesterday->month)
		{
			return 1;
		}
		else
		{
			if(pdate_data->day>=pyesterday->day)
			{
				return 0;
			}
			else
			{
				return 1;
			}
		}
	}
}

void search_data(struct DAYDATA *pdate_data)
{
	int medium,i,j;
	float n=0.0;//承接发电量 
	FILE *fp;
	char ss[40],s0[20]="C:\\test\\",s2[5],s3[3],s4[3],s5[2]="_",s6[5]=".txt",s1[4][8]={"plant1\\","plant2\\","plant3\\","plant4\\"}; 
	medium=pdate_data->year-2000;
	itoa(medium,s2,10);
	itoa(pdate_data->month,s3,10);
	itoa(pdate_data->day,s4,10);
	for(i=0;i<4;i++)
	{
		n=0.0;
		strcpy(ss,s0);
		strcat(ss,s1[i]);
		strcat(ss,s2);
		strcat(ss,s5);
		strcat(ss,s3);
		strcat(ss,s5);
		strcat(ss,s4);
		strcat(ss,s6);
		strcpy(pdate_data->file_name[i],ss);
		fp=fopen(pdate_data->file_name[i],"rt");
		fscanf(fp,"%d%d",&pdate_data->weekday,&pdate_data->weather_mode[i]);
		for(j=0;j<49;j++)
		{
			fscanf(fp,"%f",&pdate_data->plant[i][j]);
		}
		fclose(fp);
		for(j=0;j<49;j++)
		{
			n+=pdate_data->plant[i][j]/2;
		}
		pdate_data->energy[i]=n;
	}
}

void nextday(struct DAYDATA *plast,struct DAYDATA *pnext)
{
	switch(plast->month)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
			if(plast->day==31)
			{
				pnext->month=plast->month+1;
				pnext->day=1;
				pnext->year=plast->year;
			}
			else
			{
				pnext->month=plast->month;
				pnext->day=plast->day+1;
				pnext->year=plast->year;
			}
			break;
		case 2:
			if(plast->year%400==0||(plast->year%4==0&&plast->year%100!=0))
			{
				if(plast->day==29)
				{
					pnext->month=3;
					pnext->year=plast->year;
					pnext->day=1;
				}
				else
				{
					pnext->month=2;
					pnext->day=plast->day+1;
					pnext->year=plast->year;
				}
			}
			else
			{
				if(plast->day==28)
				{
					pnext->month=3;
					pnext->year=plast->year;
					pnext->day=1;
				}
				else
				{
					pnext->month=2;
					pnext->day=plast->day+1;
					pnext->year=plast->year;
				}
			}
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			if(plast->day==30)
			{
				pnext->month=plast->month+1;
				pnext->day=1;
				pnext->year=plast->year;
			}
			else
			{
				pnext->month=plast->month;
				pnext->day=plast->day+1;
				pnext->year=plast->year;
			}
			break;
		case 12:
			if(plast->day==31)
			{
				pnext->month=1;
				pnext->day=1;
				pnext->year=plast->year+1;
			}
			else
			{
				pnext->month=12;
				pnext->day=plast->day+1;
				pnext->year=plast->year;
			}
			break;
	}
	search_data(pnext);
}

int judge_record(struct DAYDATA *pyesterday)
{
	switch(pyesterday->day)
	{
		case 31:
			return 1;
		case 30:
			if(pyesterday->month==4||pyesterday->month==6||pyesterday->month==9||pyesterday->month==11)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		case 29:
			if(pyesterday->month==2)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		case 28:
			if(pyesterday->month==2&&(pyesterday->year%400!=0&&(pyesterday->year%4!=0||pyesterday->year%100==0)))
			{
				return 1;
			}
			else
			{
				return 0;
			}
	}
	return 0;
}

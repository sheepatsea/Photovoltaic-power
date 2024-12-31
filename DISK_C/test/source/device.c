#include"public.h"
#include"device.h"
#define PI 3.1415926
#define r 70
#define length 60
#define board_length 80
#define board_width 30
#define little_board_length 15
#define little_board_width 7

extern struct DATA             //坐标及角度 
{
   int x_sun;
   int y_sun;
   int x_device[3];
   int y_device[3];
   float angle_fact;	
   int angle_fact_0;
   int move_edge[12]; //运动主杆的两端位置 
   int link[10];   //连接方块的位置 
   int linkbar[10];  //连接杆的位置 
   int linkbar_end[2];  //连接杆末端 
   int spinbar[14];  //旋转棒位置 
   int assistant[12];  //辅助旋转棒位置 
   int board[10];  //光伏板版面的位置 
   int little_device_x[4][3];
   int little_device_y[4][3];
   int little_board[4][10];
   
}; 

//**********************获取光伏板的各部件位置参数 
void get_device(struct DATA *p,int mode)
{
	int i;
	int middle_x[2],middle_y[2];
	int little_middle_x[4][2],little_middle_y[4][2];
	
    
    if(mode==1)
    {
    	p->little_device_x[0][0]=290;
    p->little_device_y[0][0]=192;
    p->little_device_x[1][0]=340;
    p->little_device_y[1][0]=192;
    p->little_device_x[2][0]=270;
    p->little_device_y[2][0]=198;
    p->little_device_x[3][0]=320;
    p->little_device_y[3][0]=198;
     
	 for(i=0;i<4;i++)
    {
   	p->little_device_x[i][1]=p->little_device_x[i][0]-8*cos(1.0*p->angle_fact_0/180*PI);
	p->little_device_x[i][2]=p->little_device_x[i][0]-4*cos(1.0*p->angle_fact_0/180*PI);
	p->little_device_y[i][1]=p->little_device_y[i][0]-8*sin(1.0*p->angle_fact_0/180*PI);
    p->little_device_y[i][2]=p->little_device_y[i][0]-4*sin(1.0*p->angle_fact_0/180*PI);
    
    p->little_board[i][8]=p->little_board[i][0]=(p->little_device_x[i][2]-sin(1.0*p->angle_fact_0/180*PI)*little_board_length)+cos(1.0*p->angle_fact_0/180*PI)*little_board_width;
	p->little_board[i][9]=p->little_board[i][1]=(p->little_device_y[i][2]+cos(1.0*p->angle_fact_0/180*PI)*little_board_length)+sin(1.0*p->angle_fact_0/180*PI)*little_board_width;
	p->little_board[i][2]=(p->little_device_x[i][2]-sin(1.0*p->angle_fact_0/180*PI)*little_board_length)-cos(1.0*p->angle_fact_0/180*PI)*little_board_width;
	p->little_board[i][3]=(p->little_device_y[i][2]+cos(1.0*p->angle_fact_0/180*PI)*little_board_length)-sin(1.0*p->angle_fact_0/180*PI)*little_board_width;
    p->little_board[i][6]=(p->little_device_x[i][2]+sin(1.0*p->angle_fact_0/180*PI)*little_board_length)+cos(1.0*p->angle_fact_0/180*PI)*little_board_width;
	p->little_board[i][7]=(p->little_device_y[i][2]-cos(1.0*p->angle_fact_0/180*PI)*little_board_length)+sin(1.0*p->angle_fact_0/180*PI)*little_board_width;
	p->little_board[i][4]=(p->little_device_x[i][2]+sin(1.0*p->angle_fact_0/180*PI)*little_board_length)-cos(1.0*p->angle_fact_0/180*PI)*little_board_width;
	p->little_board[i][5]=(p->little_device_y[i][2]-cos(1.0*p->angle_fact_0/180*PI)*little_board_length)-sin(1.0*p->angle_fact_0/180*PI)*little_board_width;
	little_middle_x[i][0]=(19*p->little_board[i][6]+p->little_board[i][8])/20;
    little_middle_y[i][0]=(19*p->little_board[i][7]+p->little_board[i][9])/20;
    little_middle_x[i][1]=(p->little_board[i][6]+19*p->little_board[i][8])/20;
    little_middle_y[i][1]=(p->little_board[i][7]+19*p->little_board[i][9])/20;
    p->little_board[i][6]=little_middle_x[i][0];
    p->little_board[i][7]=little_middle_y[i][0];
	p->little_board[i][8]=p->little_board[i][0]=little_middle_x[i][1];
    p->little_board[i][9]=p->little_board[i][1]=little_middle_y[i][1];
	}
    
	}
	else if(mode==3)
	{
		p->x_device[0]=295;
	p->y_device[0]=388+20;
	p->x_device[1]=p->x_device[0]-10*cos(1.0*p->angle_fact_0/180*PI);
	p->x_device[2]=p->x_device[0]-15*cos(1.0*p->angle_fact_0/180*PI);
	p->y_device[1]=p->y_device[0]-10*sin(1.0*p->angle_fact_0/180*PI)+5;
    p->y_device[2]=p->y_device[0]-15*sin(1.0*p->angle_fact_0/180*PI);
    
   

    
    


    p->move_edge[0]=p->x_device[0]-sin(1.0*p->angle_fact_0/180*PI)*length;
	p->move_edge[1]=p->y_device[0]+cos(1.0*p->angle_fact_0/180*PI)*length;
	p->move_edge[2]=p->x_device[1]-sin(1.0*p->angle_fact_0/180*PI)*length;
	p->move_edge[3]=p->y_device[1]+cos(1.0*p->angle_fact_0/180*PI)*length;
	p->move_edge[4]=p->x_device[2]-sin(1.0*p->angle_fact_0/180*PI)*length;
	p->move_edge[5]=p->y_device[2]+cos(1.0*p->angle_fact_0/180*PI)*length;
	p->move_edge[6]=p->x_device[2]+sin(1.0*p->angle_fact_0/180*PI)*length;
	p->move_edge[7]=p->y_device[2]-cos(1.0*p->angle_fact_0/180*PI)*length;
    p->move_edge[8]=p->x_device[1]+sin(1.0*p->angle_fact_0/180*PI)*length;
	p->move_edge[9]=p->y_device[1]-cos(1.0*p->angle_fact_0/180*PI)*length;
	p->move_edge[10]=p->x_device[0]+sin(1.0*p->angle_fact_0/180*PI)*length;
	p->move_edge[11]=p->y_device[0]-cos(1.0*p->angle_fact_0/180*PI)*length;
	
    p->board[8]=p->board[0]=(p->x_device[2]-sin(1.0*p->angle_fact_0/180*PI)*board_length)+cos(1.0*p->angle_fact_0/180*PI)*board_width;
	p->board[9]=p->board[1]=(p->y_device[2]+cos(1.0*p->angle_fact_0/180*PI)*board_length)+sin(1.0*p->angle_fact_0/180*PI)*board_width;
	p->board[2]=(p->x_device[2]-sin(1.0*p->angle_fact_0/180*PI)*board_length)-cos(1.0*p->angle_fact_0/180*PI)*board_width;
	p->board[3]=(p->y_device[2]+cos(1.0*p->angle_fact_0/180*PI)*board_length)-sin(1.0*p->angle_fact_0/180*PI)*board_width;
    p->board[6]=(p->x_device[2]+sin(1.0*p->angle_fact_0/180*PI)*board_length)+cos(1.0*p->angle_fact_0/180*PI)*board_width;
	p->board[7]=(p->y_device[2]-cos(1.0*p->angle_fact_0/180*PI)*board_length)+sin(1.0*p->angle_fact_0/180*PI)*board_width;
	p->board[4]=(p->x_device[2]+sin(1.0*p->angle_fact_0/180*PI)*board_length)-cos(1.0*p->angle_fact_0/180*PI)*board_width;
	p->board[5]=(p->y_device[2]-cos(1.0*p->angle_fact_0/180*PI)*board_length)-sin(1.0*p->angle_fact_0/180*PI)*board_width;
	middle_x[0]=(19*p->board[6]+p->board[8])/20;
    middle_y[0]=(19*p->board[7]+p->board[9])/20;
    middle_x[1]=(p->board[6]+19*p->board[8])/20;
    middle_y[1]=(p->board[7]+19*p->board[9])/20;
    p->board[6]=middle_x[0];
    p->board[7]=middle_y[0];
	p->board[8]=p->board[0]=middle_x[1];
    p->board[9]=p->board[1]=middle_y[1];

	p->link[8]=p->link[0]=(p->x_device[0]+p->move_edge[10])/2-sin(1.0*p->angle_fact_0/180*PI)*10;
    p->link[9]=p->link[1]=(p->y_device[0]+p->move_edge[11])/2+cos(1.0*p->angle_fact_0/180*PI)*10;
    p->link[2]=p->link[0]+cos(1.0*p->angle_fact_0/180*PI)*10;
    p->link[3]=p->link[1]+sin(1.0*p->angle_fact_0/180*PI)*10;
    p->link[6]=(p->x_device[0]+p->move_edge[10])/2+sin(1.0*p->angle_fact_0/180*PI)*10;
    p->link[7]=(p->y_device[0]+p->move_edge[11])/2-cos(1.0*p->angle_fact_0/180*PI)*10;
    p->link[4]=p->link[6]+cos(1.0*p->angle_fact_0/180*PI)*10;
    p->link[5]=p->link[7]+sin(1.0*p->angle_fact_0/180*PI)*10;
   
    p->linkbar[8]=p->linkbar[2]=p->linkbar[0]=(p->link[2]+p->link[4])/2-sin(1.0*p->angle_fact_0/180*PI)*5;
    p->linkbar[9]=p->linkbar[1]=(p->link[3]+p->link[5])/2+cos(1.0*p->angle_fact_0/180*PI)*5;
    p->linkbar[3]=p->linkbar[1]+30;
    p->linkbar[4]=p->linkbar[6]=(p->link[2]+p->link[4])/2+sin(1.0*p->angle_fact_0/180*PI)*5;
    p->linkbar[7]=(p->link[3]+p->link[5])/2-cos(1.0*p->angle_fact_0/180*PI)*5;
    p->linkbar[5]=p->linkbar[7]+30;
    
    p->linkbar_end[0]=p->linkbar[0]/3+p->linkbar[6]*2/3;
	p->linkbar_end[1]=p->linkbar[1]/3+p->linkbar[7]*2/3+30;
    
    p->spinbar[12]=p->spinbar[0]=p->linkbar_end[0]-8;
    p->spinbar[13]=p->spinbar[1]=p->linkbar_end[1];
    p->spinbar[2]=p->spinbar[0]+7;
	p->spinbar[3]=p->spinbar[1]-4;
	p->spinbar[4]=p->spinbar[2]+8;
	p->spinbar[5]=p->spinbar[3];
	p->spinbar[6]=p->spinbar[4];
	p->spinbar[7]=p->spinbar[5]+25;
	p->spinbar[8]=p->spinbar[6]-7;
	p->spinbar[9]=p->spinbar[7]+4;
	p->spinbar[10]=p->spinbar[8]-8;
	p->spinbar[11]=p->spinbar[9];
	
	p->assistant[10]=p->assistant[0]=296;
	p->assistant[11]=p->assistant[1]=426+25;
	p->assistant[2]=299;
	p->assistant[3]=424+25;
	p->assistant[4]=(p->spinbar[10]+p->spinbar[8])/2; 
	p->assistant[5]=(p->spinbar[1]+p->spinbar[11])/2;
	p->assistant[6]=p->assistant[4];
	p->assistant[7]=p->assistant[5]+9;
	p->assistant[8]=296;
	p->assistant[9]=433+25;
	}
    
    
 } 
 
 //****************************光伏板的初始位置 

//*****************************光伏板图像更新（sunny and cloudy） 
void new_device(struct DATA system,int mode,int menu_mode)  
{
	int i;
	int bottom_1[10]={200,480+20,240,428+20,390,428+20,390,480+20,200,480+20};  //最下层底座 
	int bottom_2[12]={236,480+20,264,441+20,346,441+20,346,461+20,331,480+20,236,480+20};  //次下层底座 
	int support[14]={287,465+20,287,381+20,292,376+20,301,376+20,301,460+20,295,465+20,287,465+20};  //支撑杆 
    if(mode==1&&menu_mode==0)
    {
    	for(i=0;i<4;i++)
	{
	  setcolor(DARKGRAY);
	  setlinestyle(0,0,THICK_WIDTH);
	  setfillstyle(1,DARKGRAY);
	  line(system.little_device_x[i][0],system.little_device_y[i][0],system.little_device_x[i][0],system.little_device_y[i][0]+15);
	  line(system.little_device_x[i][0]-8,system.little_device_y[i][0]+15,system.little_device_x[i][0]+8,system.little_device_y[i][0]+15);
	  setcolor(WHITE);
	  setlinestyle(0,0,NORM_WIDTH);
	  fillpoly(5,system.little_board[i]);
	}
	}
	//************画出两个底座 
	else if(mode==3)
	{
		setcolor(WHITE);
	setlinestyle(0,0,NORM_WIDTH);
	setfillstyle(1,DARKGRAY);
	fillpoly(5,bottom_1);
	line(390,428+20,350,480+20);
	fillpoly(6,bottom_2);
	line(346,441+20,314,480+20);
	//****************先画板面再画支撑杆（正面朝南，由地理位置决定） 
	fillpoly(5,system.board);
	fillpoly(7,support);
	line(295,381+20,287,381+20);
	line(295,381+20,301,376+20);
	line(295,381+20,295,465+20);
	//**************画主杆 
	fillpoly(6,system.move_edge);
	line(system.move_edge[2],system.move_edge[3],system.move_edge[8],system.move_edge[9]);
	line(system.move_edge[6],system.move_edge[7],system.move_edge[10],system.move_edge[11]);
	//***************依次画其余部分 
	fillpoly(5,system.link);
	fillpoly(5,system.linkbar);
	line(system.linkbar[0]/3+system.linkbar[6]*2/3,system.linkbar[1]/3+system.linkbar[7]*2/3,system.linkbar_end[0],system.linkbar_end[1]);
    fillpoly(7,system.spinbar);
    line(system.spinbar[8],system.spinbar[1],system.spinbar[0],system.spinbar[1]);
	line(system.spinbar[8],system.spinbar[1],system.spinbar[4],system.spinbar[5]);
    line(system.spinbar[8],system.spinbar[1],system.spinbar[8],system.spinbar[9]);
    fillpoly(6,system.assistant);

	}

    else 
    {
    	return ;
	}

}

//***************************删除旧光伏板图像
void clear_device(struct DATA system,int mode,int menu_mode)  
{
	int i;
	if(mode==1&&menu_mode==0)
	{
		setcolor(LIGHTGRAY);
	setlinestyle(0,0,NORM_WIDTH);
	setfillstyle(1,LIGHTGRAY);
			for(i=0;i<4;i++)
	{
	  fillpoly(5,system.little_board[i]);
	}
	}
	 else if(mode==3)
	 {
	 	setcolor(LIGHTGRAY);
	setfillstyle(1,LIGHTGRAY);
	setlinestyle(0,0,THICK_WIDTH);
	bar(175,333-30,420,480);
	 }
	 else 
	 {
	 	return ;
	  } 
	
}

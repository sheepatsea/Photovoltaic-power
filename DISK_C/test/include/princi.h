#ifndef princi_h_
#define princi_h_

void principle();  //原理主控 
void principle_show();  //页面初始化 
void chemical_principle(struct SUNDATA *psunpower,int mode,int plant_mode);  //化学原理 
void chemical_clear(int x[4][2],int plant_mode);  //动态清除 
void chemical_change(struct SUNDATA *psunpower,int x[4][2]);  //参数变化 
void chemical_new(int x[4][2],int plant_mode);  //动态画出 
void draw_positive(int x,int y);  //画出空穴 
void clean_positive(int x,int y);  //清除空穴 
void draw_negtive(int x,int y);  //画出电子 
void clean_negtive(int x,int y);  //清除电子 
void draw_positive_arrow(int x,int y);  //画出空穴方向箭头 
void draw_negtive_arrow(int x,int y);  //画出电子方向箭头 
void draw_light(int x,int y);  //画出阳光 

#endif

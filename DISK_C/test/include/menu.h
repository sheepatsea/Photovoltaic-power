#ifndef menu_h_
#define menu_h_
void switch_menu(int *pmenu_mode,struct ERRORS *perr,int *pweather_mode,int *pplant_mode);
void menu_init(void); 
void pitch_on_menu(int plant_mode);
void pitch_off_menu(int plant_mode);
#endif

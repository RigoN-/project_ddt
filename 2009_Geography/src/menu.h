#ifndef __MENU_H__
#define __MENU_H__
#include "SDL_geog.h"

#define MENU_COUNT 4
#define menu_size_coef  (SCREEN_WIDTH/1024);

enum menu_position  {top,botom, leftt, rightt};
typedef enum  menu_position  menu_position;



extern GLint scena_draw;


GLvoid menu_init();
GLvoid menu_create_tex();
GLvoid menu_create_coords(menu_position ps);
GLvoid menu_draw();
GLvoid menu_mouse_motion(SDL_MouseMotionEvent *motion);
GLvoid menu_mouse_button_pressed(SDL_MouseButtonEvent *button);

#endif

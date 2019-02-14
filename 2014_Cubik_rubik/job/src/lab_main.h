#ifndef _LAB_MAIN_H
#define _LAB_MAIN_H
#include "lab_common.h"
#include "lab_info.h"
#include "lab_ogl.h"
#include "lab_win.h"
#include "lab_callback.h"

#define W_CAPTION "OpenGL 3.3 with GLFW"
#define W_WIDTH 1024
#define W_HEIGHT 768
#define SWAP_INT 0
#define F_TIME 3000

GLFWwindow *w_handle;
int done=1;
int gl_info=0, glfw_info=0, /*help_info=0,*/ w_mode=0, fps_enable=0;
//переменные для подсчета fps
double frame=0.0, frame_sum=0.0, old_time=0.0, current_time=0.0;
char str_title[128];
float w_const=1024.0;
float h_const=768.0;
//GL_POINTS=0, GL_LINES=1, GL_LINE_LOOP=2, GL_LINE_STRIP=3, GL_TRIANGLES=4, GL_TRIANGLE_FAN=5,
//GL_TRIANGLE_STRIP=6, GL_QUADS=7, GL_QUAD_STRIP=8, GL_POLYGON=9
#endif
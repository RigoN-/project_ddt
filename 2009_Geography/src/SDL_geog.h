#ifndef __SDL_GEOG_H__
#define __SDL_GEOG_H__
#include <stdio.h>
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <SDL/SDL.h>
#include <math.h>


#include "tools/texture.h"
#include "tools/textglut.h"

#define SCREEN_CAPTION  "OpenGL with SDL : Stable"
#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 768
#define SCREEN_BPP    24
#define EVENT_FPS 1
#define EVENT_ANIM 2
#define REDRAW_TIME    10
#define FPS_TIME    1000
#define ANIM_TIME    20
#define GL_PROJECTION_ORTHO   101
#define GL_PROJECTION_PERSPECTIVE    102
#define ANGLE_PERSPECTIVE 60

extern GLint menu_activ_button;
#endif

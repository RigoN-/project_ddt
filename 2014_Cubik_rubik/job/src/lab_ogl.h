#ifndef _LAB_OGL_H
#define _LAB_OGL_H
#include "lab_common.h"
/*Объявление структур -------------------------------------*/
struct vertex_b{
	float texture_x;
	float texture_y;
};
typedef struct vertex_b vertex_b_t;
struct cub_c{
	vertex_b_t t[6];
};
typedef struct cub_c black_t;
struct vertex{
	float x;
	float y;
	float z;
	float colorR;
	float colorG;
	float colorB;
	float texture_x;
	float texture_y;
};
typedef struct vertex vertex_t;
struct cub{
	vertex_t m[36];
};
typedef struct cub cube_t;
struct cubik{
	cube_t mass[3][3][3];
};
typedef struct cubik cubik_t;

/*----------------------------------------------------------*/
extern int draw_mode;
extern void ogl_init(void);
extern void ogl_draw(void);
extern void	glew_init(void);
extern void change_pos_point(cubik_t *b);
extern void copy_mass(cubik_t *b, cubik_t *c);
#endif
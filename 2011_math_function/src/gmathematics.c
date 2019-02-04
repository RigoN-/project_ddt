#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <math.h>
#include <GL/glut.h>
#include "./tools/rglTexture.h"

char *Txf02="../data/texture/okno_1.bmp";
char *Txf03="../data/texture/okno_2.bmp";
char *Txf04="../data/texture/help.bmp";
char *Txf05="../data/texture/help_2.bmp";


char *Txf06="../data/texture/f_2.bmp";
char *Txf07="../data/texture/f_3.bmp";
char *Txf08="../data/texture/f_4.bmp";
char *Txf09="../data/texture/f_5.bmp";
char *Txf10="../data/texture/f_8.bmp";
char *Txf11="../data/texture/f_9.bmp";
char *Txf12="../data/texture/f_1.bmp";
char *Txf13="../data/texture/f_6.bmp";
char *Txf14="../data/texture/f_7.bmp";
char *Txf15="../data/texture/f_10.bmp";

char *ftf01="../data/texture/b_2.bmp";
char *ftf02="../data/texture/b_3.bmp";
char *ftf03="../data/texture/b_4.bmp";
char *ftf04="../data/texture/b_5.bmp";
char *ftf05="../data/texture/b_8.bmp";
char *ftf06="../data/texture/b_9.bmp";
char *ftf07="../data/texture/b_1.bmp";
char *ftf08="../data/texture/b_6.bmp";
char *ftf09="../data/texture/b_7.bmp";
char *ftf10="../data/texture/b_10.bmp";

unsigned  int okno_1,okno_2,help,help_2,f_1,f_2,f_3,f_4,f_5,f_6,f_7,f_8,f_9,f_10;
unsigned  int ft_01,ft_02,ft_03,ft_04,ft_05,ft_06,ft_07,ft_08,ft_09,ft_10;

int flag_func=1;
float M_PI=3.14;
float R,R1,phi,teta,cam_x,cam_y,cam_z;
float world_x,world_y,world_z;
void redisplay_all(void);
GLuint window, world, screen, command;
GLuint sub_width = 256, sub_height = 256;
int old_y;
GLuint c_width, c_height,m_width, m_height;
GLuint world_sub_width, world_sub_height, screen_sub_width, screen_sub_height;

//------------------------------------------------------------------------
typedef struct _cell {
    int id;
    int x, y;
    float min, max;
    float value;
    float step;
    char* info;
    char* format;
} cell;
//------------------------------------------------------------------------
cell fank_1[1] = {
    { 1, 40, 40, -10.0, 10.0, 5.0, 0.09,
        "Specifies X coordinate of fank_1 vector.", "%.2f" },
};
//------------------------------------------------------------------------
cell fank_2[1] = {
    { 2, 40, 40, -10.0, 10.0, 5.0, 0.01,
        "Specifies X coordinate of fank_2 vector.", "%.2f" },
};
//------------------------------------------------------------------------
cell fank_3[5] = {
    { 3, 40, 40, -10, 10, 2, 1,
        "Specifies X coordinate of fank_3 vector.", "%.0f" },
	{ 4, 80, 40, -10.0, 10.0, 5.0, 0.09,
        "Specifies X coordinate of fank_3 vector.", "%.2f" },
	{ 5, 155, 40, -10.0, 10.0, 10.0, 1,
        "Specifies X coordinate of fank_3 vector.", "%.0f" },
	{ 4, 205, 40, -10.0, 10.0, 5.0, 0.09,
        "Specifies X coordinate of fank_3 vector.", "%.2f" },
	{ 7, 275, 40, -10.0, 10.0, 4.0, 1,
        "Specifies X coordinate of fank_3 vector.", "%.0f" },	
};
//------------------------------------------------------------------------
cell fank_4[3] = {
    { 8, 34, 40, -16.0, 16.0, 1.0, 0.09,
        "Specifies X coordinate of fank_4 vector.", "%.0f" },
	{ 9, 120, 40, -16.0, 16.0, 1.0, 0.09,
        "Specifies X coordinate of fank_4 vector.", "%.0f" },
	{ 10, 170, 40, -16.0, 16.0, 10.0, 0.09,
        "Specifies X coordinate of fank_4 vector.", "%.2f" },
};
//------------------------------------------------------------------------
cell fank_5[1] = {
    { 11, 80, 40, -17.0, 17.0, 10.0, 0.09,
        "Specifies X coordinate of fank_5 vector.", "%.2f" },
};
//------------------------------------------------------------------------
cell fank_6[1] = {
    { 11, 80, 40, 0.0, 18.0, 5.0, 0.09,
        "Specifies X coordinate of fank_6 vector.", "%.2f" },
};
//------------------------------------------------------------------------
cell fank_7[1] = {
    { 12, 80, 40, -20.0, 20.0, 10.0, 0.09,
        "Specifies X coordinate of fank_7 vector.", "%.2f" },	
		
};
//------------------------------------------------------------------------
cell fank_8[3] = {
    { 13, 40, 40, -17.0, 17.0, 2.0, 0.09,
        "Specifies X coordinate of fank_8 vector.", "%.0f" },
	{ 14, 130, 40, -9.0, 9.0, 4.0, 0.09,
        "Specifies X coordinate of fank_8 vector.", "%.0f" },
	{ 15, 180, 40, -17.0, 17.0, 5.0, 0.09,
        "Specifies X coordinate of fank_8 vector.", "%.2f" },	
};
//------------------------------------------------------------------------
cell fank_9[1] = {
    { 16, 80, 40, -18.0, 18.0, 5.0, 0.09,
        "Specifies X coordinate of fank_9 vector.", "%.2f" },
};
//------------------------------------------------------------------------
cell fank_10[1] = {
    { 17, 50, 40, -20.0, 20.0, 5.0, 0.09,
        "Specifies X coordinate of fank_10 vector.", "%.2f" },
};
//------------------------------------------------------------------------
GLint selection = 0;
GLboolean swapped = GL_FALSE;
GLvoid *font_style = GLUT_BITMAP_TIMES_ROMAN_10;

void setfont(char* name, int size)
{
    font_style = GLUT_BITMAP_HELVETICA_10;
    if (strcmp(name, "helvetica") == 0) {
        if (size == 12) 
            font_style = GLUT_BITMAP_HELVETICA_12;
        else if (size == 18)
            font_style = GLUT_BITMAP_HELVETICA_18;
    } else if (strcmp(name, "times roman") == 0) {
        font_style = GLUT_BITMAP_TIMES_ROMAN_10;
        if (size == 24)
            font_style = GLUT_BITMAP_TIMES_ROMAN_24;
    } else if (strcmp(name, "8x13") == 0) {
        font_style = GLUT_BITMAP_8_BY_13;
    } else if (strcmp(name, "9x15") == 0) {
        font_style = GLUT_BITMAP_9_BY_15;
    }
}
//------------------------------------------------------------------------
void drawstr(GLuint x, GLuint y, char* format, ...)
{
    va_list args;
    char buffer[255], *s;
    
    va_start(args, format);
    vsprintf(buffer, format, args);
    va_end(args);
    
    glRasterPos2i(x, y);
    for (s = buffer; *s; s++)
        glutBitmapCharacter(font_style, *s);
}

void drawstr_2(GLuint x, GLuint y, GLuint z,char* s)
{
	int i;
    
    glRasterPos3i(x, y, z);
    for (i = 0; i<strlen(s); i++)
        glutBitmapCharacter(font_style, s[i]);
}
//------------------------------------------------------------------------
void cell_draw(cell* cell)
{
    glColor3ub(0, 255, 128);
    if (selection == cell->id) {
        glColor3ub(255, 255, 0);
       // drawstr(10, 240, cell->info);
        glColor3ub(255, 0, 0);
    }
    
    drawstr(cell->x, cell->y, cell->format, cell->value);
}
//------------------------------------------------------------------------
void cell_draw_const(cell* cell)
{
    glColor3ub(254, 254, 1);
    if (selection == cell->id) {
        glColor3ub(255, 255, 0);
       // drawstr(10, 240, cell->info);
        glColor3ub(255, 0, 0);
    }
    
    drawstr(cell->x, cell->y, cell->format, cell->value);
}
//------------------------------------------------------------------------

int
cell_hit(cell* cell, int x, int y)
{
    if (x > cell->x && x < cell->x+50 &&
        y > cell->y-20 && y < cell->y+10)
		{printf("cell->id=%i\n",cell->id);
        return cell->id;}
    return 0;
}
//------------------------------------------------------------------------
void cell_update(cell* cell, int update)
{
    if (selection != cell->id)
        return;
    
    cell->value += update * cell->step;
   // printf ("%i\n",cell->value);
    if (cell->value < cell->min)
        cell->value = cell->min;
    else if (cell->value > cell->max) 
        cell->value = cell->max;
    
}
//------------------------------------------------------------------------
void cell_vector(float* dst, cell* cell, int num)
{
    while (--num >= 0)
        dst[num] = cell[num].value;
}

//------------------------------------------------------------------------
void main_reshape(int width,  int height) 
{
	width=1024; height=768;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, width, height, 0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();	
    
#define GAP  5           
    sub_width = (width-GAP*3)/3;
    sub_height = (height-GAP*3)/2;
    
	
	//правое нижнее
    glutSetWindow(screen);
    glutPositionWindow( GAP+sub_width+GAP+sub_width, sub_height+GAP-100);
    glutReshapeWindow(sub_width, sub_height+100);
	
	
	//для графика
	glutSetWindow(world);
	glutPositionWindow(GAP, GAP);	
	glutReshapeWindow(sub_width*2, sub_height*2);
  
	
	//правое верхнее
    glutSetWindow(command);
    glutPositionWindow(GAP+sub_width+GAP+sub_width, GAP+GAP-5);
    glutReshapeWindow(sub_width, sub_height+GAP-120);
	
}
//------------------------------------------------------------------------
void init (void) 
{
   glClearColor (0.0, 0.0, 0.0, 0.0);
  
   glPolygonMode (GL_FRONT_AND_BACK, GL_FILL);
   glShadeModel (GL_SMOOTH);
   phi=M_PI/3.0;
   teta=M_PI/3.0;
   R=5.0;
   R1=R*sin(teta);
	cam_y=R*cos(teta);
	cam_x=R1*cos(phi);
	cam_z=R1*sin(phi);
	
	//printf("point1\n");
  
   rglLoad_Texture (ftf01, &ft_01, txAnisotropic_16, GL_DECAL, GL_REPEAT,txGL_COMPRESS,GL_TRUE);
   rglLoad_Texture (ftf02, &ft_02, txAnisotropic_16, GL_DECAL, GL_REPEAT,txGL_COMPRESS,GL_TRUE);
   rglLoad_Texture (ftf03, &ft_03, txAnisotropic_16, GL_DECAL, GL_REPEAT,txGL_COMPRESS,GL_TRUE);
   rglLoad_Texture (ftf04, &ft_04, txAnisotropic_16, GL_DECAL, GL_REPEAT,txGL_COMPRESS,GL_TRUE);
   rglLoad_Texture (ftf05, &ft_05, txAnisotropic_16, GL_DECAL, GL_REPEAT,txGL_COMPRESS,GL_TRUE);
   rglLoad_Texture (ftf06, &ft_06, txAnisotropic_16, GL_DECAL, GL_REPEAT,txGL_COMPRESS,GL_TRUE);
   rglLoad_Texture (ftf07, &ft_07, txAnisotropic_16, GL_DECAL, GL_REPEAT,txGL_COMPRESS,GL_TRUE);
   rglLoad_Texture (ftf08, &ft_08, txAnisotropic_16, GL_DECAL, GL_REPEAT,txGL_COMPRESS,GL_TRUE);
   rglLoad_Texture (ftf09, &ft_09, txAnisotropic_16, GL_DECAL, GL_REPEAT,txGL_COMPRESS,GL_TRUE);
   rglLoad_Texture (ftf10, &ft_10, txAnisotropic_16, GL_DECAL, GL_REPEAT,txGL_COMPRESS,GL_TRUE);
   
   rglLoad_Texture (Txf02, &okno_1, txAnisotropic_16, GL_DECAL, GL_REPEAT,txGL_COMPRESS,GL_TRUE);
   rglLoad_Texture (Txf03, &okno_2, txAnisotropic_16, GL_DECAL, GL_REPEAT,txGL_COMPRESS,GL_TRUE);
   rglLoad_Texture (Txf04, &help, txAnisotropic_16, GL_DECAL, GL_REPEAT,txGL_COMPRESS,GL_TRUE);
   rglLoad_Texture (Txf05, &help_2, txAnisotropic_16, GL_DECAL, GL_REPEAT,txGL_COMPRESS,GL_TRUE);
   rglLoad_Texture (Txf06, &f_1, txAnisotropic_16, GL_DECAL, GL_REPEAT,txGL_COMPRESS,GL_TRUE);
   rglLoad_Texture (Txf07, &f_2, txAnisotropic_16, GL_DECAL, GL_REPEAT,txGL_COMPRESS,GL_TRUE);
   rglLoad_Texture (Txf08, &f_3, txAnisotropic_16, GL_DECAL, GL_REPEAT,txGL_COMPRESS,GL_TRUE);
   rglLoad_Texture (Txf09, &f_4, txAnisotropic_16, GL_DECAL, GL_REPEAT,txGL_COMPRESS,GL_TRUE);
   rglLoad_Texture (Txf10, &f_5, txAnisotropic_16, GL_DECAL, GL_REPEAT,txGL_COMPRESS,GL_TRUE);
   rglLoad_Texture (Txf11, &f_6, txAnisotropic_16, GL_DECAL, GL_REPEAT,txGL_COMPRESS,GL_TRUE);
   rglLoad_Texture (Txf12, &f_7, txAnisotropic_16, GL_DECAL, GL_REPEAT,txGL_COMPRESS,GL_TRUE);
   rglLoad_Texture (Txf13, &f_8, txAnisotropic_16, GL_DECAL, GL_REPEAT,txGL_COMPRESS,GL_TRUE);
   rglLoad_Texture (Txf14, &f_9, txAnisotropic_16, GL_DECAL, GL_REPEAT,txGL_COMPRESS,GL_TRUE);   
   rglLoad_Texture (Txf15, &f_10, txAnisotropic_16, GL_DECAL, GL_REPEAT,txGL_COMPRESS,GL_TRUE);
   
	gluLookAt (cam_x, cam_y, cam_z, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	
}
//------------------------------------------------------------------------
void init_texture()
{
 glEnable(GL_TEXTURE_2D);
   rglLoad_Texture (ftf01, &ft_01, txAnisotropic_16, GL_DECAL, GL_REPEAT,txGL_COMPRESS,GL_TRUE);
   rglLoad_Texture (ftf02, &ft_02, txAnisotropic_16, GL_DECAL, GL_REPEAT,txGL_COMPRESS,GL_TRUE);
   rglLoad_Texture (ftf03, &ft_03, txAnisotropic_16, GL_DECAL, GL_REPEAT,txGL_COMPRESS,GL_TRUE);
   rglLoad_Texture (ftf04, &ft_04, txAnisotropic_16, GL_DECAL, GL_REPEAT,txGL_COMPRESS,GL_TRUE);
   rglLoad_Texture (ftf05, &ft_05, txAnisotropic_16, GL_DECAL, GL_REPEAT,txGL_COMPRESS,GL_TRUE);
   rglLoad_Texture (ftf06, &ft_06, txAnisotropic_16, GL_DECAL, GL_REPEAT,txGL_COMPRESS,GL_TRUE);
   rglLoad_Texture (ftf07, &ft_07, txAnisotropic_16, GL_DECAL, GL_REPEAT,txGL_COMPRESS,GL_TRUE);
   rglLoad_Texture (ftf08, &ft_08, txAnisotropic_16, GL_DECAL, GL_REPEAT,txGL_COMPRESS,GL_TRUE);
   rglLoad_Texture (ftf09, &ft_09, txAnisotropic_16, GL_DECAL, GL_REPEAT,txGL_COMPRESS,GL_TRUE);
   rglLoad_Texture (ftf10, &ft_10, txAnisotropic_16, GL_DECAL, GL_REPEAT,txGL_COMPRESS,GL_TRUE);
   
   rglLoad_Texture (Txf05, &help_2, txAnisotropic_16, GL_DECAL, GL_REPEAT,txGL_COMPRESS,GL_TRUE);
 glDisable(GL_TEXTURE_2D);     
 }  
//------------------------------------------------------------------------   
void init_texture_1()
{
	glEnable(GL_TEXTURE_2D);
	rglLoad_Texture (Txf02, &okno_1, txAnisotropic_16, GL_DECAL, GL_REPEAT,txGL_COMPRESS,GL_TRUE);
	rglLoad_Texture (Txf03, &okno_2, txAnisotropic_16, GL_DECAL, GL_REPEAT,txGL_COMPRESS,GL_TRUE);
	glDisable(GL_TEXTURE_2D);   
 }  
//------------------------------------------------------------------------   
void init_texture_2()
{
	glEnable(GL_TEXTURE_2D);
	rglLoad_Texture (Txf04, &help, txAnisotropic_16, GL_DECAL, GL_REPEAT,txGL_COMPRESS,GL_TRUE);
	glDisable(GL_TEXTURE_2D);   
 }  
//------------------------------------------------------------------------  
 void init_texture_3()
{
	glEnable(GL_TEXTURE_2D);
	rglLoad_Texture (Txf06, &f_1, txAnisotropic_16, GL_DECAL, GL_REPEAT,txGL_COMPRESS,GL_TRUE);
	rglLoad_Texture (Txf07, &f_2, txAnisotropic_16, GL_DECAL, GL_REPEAT,txGL_COMPRESS,GL_TRUE);
	rglLoad_Texture (Txf08, &f_3, txAnisotropic_16, GL_DECAL, GL_REPEAT,txGL_COMPRESS,GL_TRUE);
	rglLoad_Texture (Txf09, &f_4, txAnisotropic_16, GL_DECAL, GL_REPEAT,txGL_COMPRESS,GL_TRUE);
	rglLoad_Texture (Txf10, &f_5, txAnisotropic_16, GL_DECAL, GL_REPEAT,txGL_COMPRESS,GL_TRUE);
	rglLoad_Texture (Txf11, &f_6, txAnisotropic_16, GL_DECAL, GL_REPEAT,txGL_COMPRESS,GL_TRUE);
	rglLoad_Texture (Txf12, &f_7, txAnisotropic_16, GL_DECAL, GL_REPEAT,txGL_COMPRESS,GL_TRUE);
	rglLoad_Texture (Txf13, &f_8, txAnisotropic_16, GL_DECAL, GL_REPEAT,txGL_COMPRESS,GL_TRUE);
	rglLoad_Texture (Txf14, &f_9, txAnisotropic_16, GL_DECAL, GL_REPEAT,txGL_COMPRESS,GL_TRUE);
	rglLoad_Texture (Txf15, &f_10, txAnisotropic_16, GL_DECAL, GL_REPEAT,txGL_COMPRESS,GL_TRUE);
	glDisable(GL_TEXTURE_2D);   
 }  
//------------------------------------------------------------------------  

void main_display(void)
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glLoadIdentity ();    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);    
    glutSwapBuffers();
}
//------------------------------------------------------------------------
void Mouse(int button, int state, int x, int y)
{
	glutPostRedisplay();    
}
//------------------------------------------------------------------------
void Keyboard( unsigned char key, int x, int y )
{
#define ESCAPE '\033'
    if( key == ESCAPE )
        exit(0);	
		
}
//------------------------------------------------------------------------

void OSkord(float x, float y, float z)
{
glLineWidth (2.0);
    glEnable(GL_LINE_SMOOTH); 
   glBegin(GL_LINES);
		// ось X
	  glColor3f(1.0, 0.0, 0.0);
      glVertex3f (x, 0.0, 0.0);
      glVertex3f (-x, 0.0, 0.0); 
	  // ось Y
	  glColor3f (0.0, 1.0, 0.0);
      glVertex3f (0.0, y, 0.0);  
	  glVertex3f (0.0, -y, 0.0);
	  // ось Z
	  glColor3f (0.0, 0.0, 1.0);
	  glVertex3f (0.0, 0.0,-z);  
	  glVertex3f (0.0, 0.0, z); 
	  // стрелочка для оси X
	  glColor3f (1.0,0.0,0.0);
	  glVertex3f (x, 0.0, 0.0);
      glVertex3f (x-x/42, y/67.14, 0.0);	  

	  glColor3f (1.0,0.0,0.0);
	  glVertex3f (x, 0.0, 0.0);
      glVertex3f (x-x/42, -y/67.14, 0.0);
	  // стрелочка для оси Y
	  glColor3f (0.0,1.0,0.0);
	  glVertex3f (0.0, y, 0.0);
      glVertex3f (-x/60, y-y/47, 0.0);	  

	  glColor3f (0.0,1.0,0.0);
	  glVertex3f (0.0, y, 0.0);
      glVertex3f (x/60, y-y/47, 0.0);
	  // стрелочка для оси Z
	  glColor3f (0.0,0.0,1.0);
	  glVertex3f (0.0, 0.0, z);
      glVertex3f (x/60, 0.0, z-z/47);	  

	  glColor3f (0.0,0.0,1.0);
	  glVertex3f (0.0, 0.0, z);
      glVertex3f (-x/60, 0.0, z-z/47);
	  
   glEnd(); 
   glColor3f (1.0,0.0,0.0);
   drawstr_2(x,0.1,0.0,"X");
   
   glColor3f (0.0,1.0,0.0);
   drawstr_2(0.1,y,0.0,"Y");
   
   glColor3f (0.0,0.0,1.0);
   drawstr_2(-0.2,0.1,z,"Z");
   glDisable (GL_POINT_SMOOTH); 
 }
//------------------------------------------------------------------------	
void setka (void)
{
	int i;
	glLineWidth (2.0);
    glEnable(GL_LINE_SMOOTH); 
   glBegin(GL_LINES);
   glColor3f(0.05, 0.1, 0.05);
		for (i=-50;i<=50;i++)
	{	  
      glVertex3f (i, 100.0, -5.0);
      glVertex3f (i, -100.0, -5.0); 
	}
	glEnd();
	 glBegin(GL_LINES);
   glColor3f(0.05, 0.1, 0.05);
		for (i=-50;i<=50;i++)
	{	  
      glVertex3f (-100.0, i, -5.0);
      glVertex3f (100.0, i, -5.0); 
	}
	glEnd();
}
 //------------------------------------------------------------------------	
 void FANC1(float x_0, float step)//y=x*x
{
float y,x;
	glColor3f(1.0, 1.0, 1.0);
	glLineWidth (1.0);
	glEnable(GL_LINE_SMOOTH);   
    glBegin(GL_LINE_STRIP);
   		for (x=-abs(x_0);x<=abs(x_0);x+=step) 
		{ 
		y=x*x;
		glVertex3f (x,y,-2.0);	
		}
   glEnd();   
   glDisable (GL_POINT_SMOOTH); 
}
//------------------------------------------------------------------------
void FANC2(float x_0, float step)//y=x*x*x
{
float y,x;
	glColor3f(1.0, 1.0, 1.0);
	glLineWidth (1.0);
	glEnable(GL_LINE_SMOOTH);   
    glBegin(GL_LINE_STRIP);
   		for (x=-abs(x_0);x<=abs(x_0);x+=step) 
		{ 
		y=x*x*x;
		glVertex3f (x,y,0.0);	
		}
   glEnd();   
   glDisable (GL_POINT_SMOOTH); 
}
//------------------------------------------------------------------------
void FANC3(int a,int b,int c,float x_0,float step)//y=a*x*x-b*x+c
//FANC3(fank_3[0].value,fank_3[2].value,fank_3[4].value,fank_3[1].value,fank_3[0].step,fank_3[1].step);
{
float x,y;
	glColor3f(1.0, 1.0, 1.0);
	glLineWidth (1.0);
	glEnable(GL_LINE_SMOOTH);   
   glBegin(GL_LINE_STRIP);
   		for (x=-abs(x_0);x<=abs(x_0);x+=step)
		{		
		y=a*x*x-b*x+c;		
		glVertex3f (x,y,-2.0);			
		}
   glEnd();
   glDisable (GL_POINT_SMOOTH); 
}
//-----------------------------------------------------------------------
void FANC4(float a,float b,float x_0, float step)//y=sin(x)
{
float x,y;
	glColor3f(1.0, 1.0, 1.0);
	glLineWidth (1.0);
	glEnable(GL_LINE_SMOOTH);   
   glBegin(GL_LINE_STRIP);
   		for (x=-abs(x_0);x<=abs(x_0);x+=step)
		{		
		y=a*sin(b*x);	
		glVertex3f (x,y,0.0);	
		}   
   glEnd();
   glDisable (GL_POINT_SMOOTH); 
}
//-----------------------------------------------------------------------
void FANC5(float a, float x_0, float step)//y=log x
{
float x,y;
	glColor3f(1.0, 1.0, 1.0);
	glLineWidth (1.0);
	glEnable(GL_LINE_SMOOTH);   
   glBegin(GL_LINE_STRIP);
   		for (x=-abs(x_0);x<=abs(x_0);x+=step)
		{		
		y=log(x)/log(a);	
		glVertex3f (x,y,0.0);	
		}   
   glEnd();
   glDisable (GL_POINT_SMOOTH); 
}
//-----------------------------------------------------------------------
void FANC6(float x_0, float step)//y=sqrt(x) 
{
float x,y;
	glColor3f(1.0, 1.0, 1.0);
	glLineWidth (1.0);
	glEnable(GL_LINE_SMOOTH);   
   glBegin(GL_LINE_STRIP);
   		for (x=-abs(x_0);x<=abs(x_0);x+=step)
		{		
		y=sqrt(x);	
		glVertex3f (x,y,0.0);	
		}   
   glEnd();
   glDisable (GL_POINT_SMOOTH); 
}
//-----------------------------------------------------------------------
void FANC7(float x_0, float step)//y=1/x 
{
float y,x;
	glColor3f(1.0, 1.0, 1.0);
	glLineWidth (1.0);
	glEnable(GL_LINE_SMOOTH);   
    glBegin(GL_LINE_STRIP);	
   		for (x=-abs(x_0);x<0 ;x+=step) 
		{ 
		y=1.0/x;					
		glVertex3f (x,y,0.0);		
		}
	glEnd();	
     
	 glBegin(GL_LINE_STRIP);
	 for (x=step;x<=abs(x_0);x+=step) 
	 {
	 y=1.0/x;
	 glVertex3f (x,y,0.0);
	 }
	 glEnd();
	 
   glDisable (GL_POINT_SMOOTH); 
}
//-----------------------------------------------------------------------
void FANC8(float a,float b,float x_0, float step)//y=cos(x)
{
float x,y;
	glColor3f(1.0, 1.0, 1.0);
	glLineWidth (1.0);
	glEnable(GL_LINE_SMOOTH);   
   glBegin(GL_LINE_STRIP);
   		for (x=-abs(x_0);x<=abs(x_0);x+=step)
		{		
		y=a*cos(b*x);	
		glVertex3f (x,y,0.0);	
		}   
   glEnd();
   glDisable (GL_POINT_SMOOTH); 
}
//-----------------------------------------------------------------------
void FANC9(float x_0, float step)//y=tan(x) не прально рисует
{
float x, y;
	glColor3f(1.0, 1.0, 1.0);
	glLineWidth (1.0);
	glEnable(GL_LINE_SMOOTH);  
	
	for (x=-abs(x_0);x<=abs(x_0);x+=step) 
	
			{ 
			glBegin(GL_LINES);
					y=tan(x);	
					if (y>0.0)	
						glVertex3f (x,y,0.0);	
					y=tan(x+step);		
					if (y>0.0)														
						glVertex3f (x+step,y,0.0);
					
				
			glEnd();	
			}
		for (x=-abs(x_0);x<=abs(x_0);x+=step) 
	
			{ 
			glBegin(GL_LINES);
					y=tan(x);	
					if (y<0.0)	
						glVertex3f (x,y,0.0);	
					y=tan(x+step);		
					if (y<0.0)														
						glVertex3f (x+step,y,0.0);
					
				
			glEnd();	
			}	
   
   glDisable (GL_POINT_SMOOTH); 
}
//-----------------------------------------------------------------------
void FANC10(float x_0, float step)//y=|x|
{
float x,y;
	glColor3f(1.0, 1.0, 1.0);
	glLineWidth (1.0);
	glEnable(GL_LINE_SMOOTH);   
   glBegin(GL_LINE_STRIP);
   		for (x=-abs(x_0);x<=abs(x_0);x+=step)
		{		
		y=sqrt(x*x);	
		glVertex3f (x,y,0.0);	
		}   
   glEnd();
   glDisable (GL_POINT_SMOOTH); 
}
//-----------------------------------------------------------------------
//для графика
void world_reshape(int width, int height)
{
	world_sub_width=width, world_sub_height=height,
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//gluPerspective (60.0, (float)width/(float)height, 0.25, 200.0);	
	glOrtho(-width/40, width/40,-height/40 ,height/40 , height/40+1.0, -height/40-1.0);	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

  world_x=width/40;world_y=height/40;world_z=height/40;
}
//------------------------------------------------------------------------
//правое нижнее
void screen_reshape(int width, int height)
{   
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, width, 0,height , 1, -10);	
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
//------------------------------------------------------------------------
//правое верхнее
void command_reshape(int width, int height)
{
	c_width=width;
	c_height=height;
	
	glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, width, height, 0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();    
}
//------------------------------------------------------------------------

//правое верхнее
void fank_1_command_display()
{
/*
	if (swapped) {
        fank_1[0].y = 60;		
    } else {
        fank_1[0].y = 60;
    } 
*/	
    glColor3ub(255, 255, 255);
    setfont("helvetica", 18);    
    drawstr(10, fank_1[0].y, "y=");
	setfont("helvetica", 14);  
    drawstr(100, fank_1[0].y-10, "2");    
    setfont("helvetica", 18); 
	drawstr(110, fank_1[0].y, ";");
    cell_draw(&fank_1[0]);
}

void fank_2_command_display()
{
	glColor3ub(255, 255, 255);
    setfont("helvetica", 18);    
    drawstr(10, fank_2[0].y, "y=");
	setfont("helvetica", 14);  
    drawstr(100, fank_2[0].y-10, "3");    
    setfont("helvetica", 18); 
	drawstr(110, fank_2[0].y, ";");
    cell_draw(&fank_2[0]);	
}

void fank_3_command_display()
{
	glColor3ub(255, 255, 255);
    setfont("9x15", 12);    
    drawstr(10, fank_3[0].y, "y=");
	setfont("9x15", 12);    
    drawstr(70, fank_3[0].y, "*");
	setfont("helvetic", 10);  
    drawstr(134, fank_2[0].y-10, "2");  
	setfont("9x15", 12);    
    drawstr(140, fank_3[0].y, "-");
	drawstr(190, fank_3[0].y, "*");
    drawstr(260, fank_3[0].y, "+");
	
	cell_draw_const(&fank_3[0]);	//a
	cell_draw(&fank_3[1]);	//x
	cell_draw_const(&fank_3[2]);	//b
	cell_draw(&fank_3[3]);	//x
	cell_draw_const(&fank_3[4]);	//c
}

void fank_4_command_display()
{	   
	glColor3ub(255, 255, 255);
    setfont("helvetica", 18);    
    drawstr(10, fank_4[0].y, "y=");
	setfont("helvetica", 18);    
    drawstr(60, fank_4[0].y+2, "*");
    setfont("helvetica", 18); 
	drawstr(80, fank_4[0].y, "sin (");
	setfont("helvetica", 18); 
	drawstr(154, fank_4[0].y, "*");
	setfont("helvetica", 18); 
	drawstr(225, fank_4[0].y, ");");
	
	cell_draw_const(&fank_4[0]);	//a
	cell_draw_const(&fank_4[1]);	//b
	cell_draw(&fank_4[2]);	//x
}

void fank_5_command_display()
{
	if (swapped) {
		fank_5[0].y = 100;			
	} else {
		fank_5[0].y = 60;			
	}   
	glColor3ub(255, 255, 255);
    setfont("helvetica", 18);    
    drawstr(10, fank_5[0].y, "y= log (");	
    setfont("helvetica", 18); 
	drawstr(140, fank_5[0].y, ") ;");
    cell_draw(&fank_5[0]);	
}

void fank_6_command_display()
{
	if (swapped) {
		fank_6[0].y = 100;			
	} else {
		fank_6[0].y = 60;			
	}   
	glColor3ub(255, 255, 255);
    setfont("helvetica", 18);    
    drawstr(10, fank_6[0].y, "y= sqrt (");	
    setfont("helvetica", 18); 
	drawstr(140, fank_6[0].y, ") ;");
    cell_draw(&fank_6[0]);	
}

void fank_7_command_display()
{
	if (swapped) {
		fank_7[0].y = 100;			
	} else {
		fank_7[0].y = 60;			
	}   
	glColor3ub(255, 255, 255);
    setfont("helvetica", 18);    
    drawstr(10, fank_7[0].y, "y= 1 / ");	
    setfont("helvetica", 18); 
	drawstr(140, fank_7[0].y, ";");
    cell_draw(&fank_7[0]);	
}

void fank_8_command_display()
{
	glColor3ub(255, 255, 255);
    setfont("helvetica", 18);    
    drawstr(10, fank_8[0].y, "y=");	
    setfont("helvetica", 18); 
	drawstr(70, fank_8[0].y, "* cos (");
	
	setfont("helvetica", 18); 
	drawstr(160, fank_8[0].y, "*");
	setfont("helvetica", 18); 
	drawstr(230, fank_8[0].y, ");");
	
    cell_draw_const(&fank_8[0]);	//a
	cell_draw_const(&fank_8[1]);	//b
	cell_draw(&fank_8[2]);	//x
}

void fank_9_command_display()
{
	if (swapped) {
		fank_9[0].y = 100;			
	} else {
		fank_9[0].y = 60;			
	}   
	glColor3ub(255, 255, 255);
    setfont("helvetica", 18);    
    drawstr(10, fank_9[0].y, "y= tan (");	
    setfont("helvetica", 18); 
	drawstr(140, fank_9[0].y, ");");
    cell_draw(&fank_9[0]);	
}

void fank_10_command_display()
{
	
	glColor3ub(255, 255, 255);
    setfont("helvetica", 18);    
    drawstr(10, fank_10[0].y, "y= |");	
    setfont("helvetica", 18); 
	drawstr(110, fank_10[0].y, "| ;");
    cell_draw(&fank_10[0]);	
}
//--------------------------------------------------------------------------------------
void fank_11_command_display()
{
	glColor3ub(121, 3, 252);
    setfont("helvetica", 18);    
    drawstr(10, fank_10[0].y+190, "Window of Management");	   	
}
void fank_12_command_display()
{
	glColor3ub(254, 235, 1);
    setfont("helvetica", 18);    
    drawstr(10, fank_10[0].y, "Window of Information");	   	
}

//--------------------------------------------------------------------------------------
void prim (int flag) //текстура фунуции
{   
	glEnable(GL_TEXTURE_2D);
	glColor3f(1.0,0.0,0.0);
	if (flag==1)
	glBindTexture(GL_TEXTURE_2D, ft_01); 
	if (flag==2)
	glBindTexture(GL_TEXTURE_2D, ft_02); 
	if (flag==3)
	glBindTexture(GL_TEXTURE_2D, ft_03); 
	if (flag==4)
	glBindTexture(GL_TEXTURE_2D, ft_04); 
	if (flag==5)
	glBindTexture(GL_TEXTURE_2D, ft_05); 
	if (flag==6)
	glBindTexture(GL_TEXTURE_2D, ft_06); 
	if (flag==7)
	glBindTexture(GL_TEXTURE_2D, ft_07); 
	if (flag==8)
	glBindTexture(GL_TEXTURE_2D, ft_08); 
	if (flag==9)
	glBindTexture(GL_TEXTURE_2D, ft_09); 
	if (flag==10)
	glBindTexture(GL_TEXTURE_2D, ft_10); 
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 1.0);  glVertex3f(5.0,70.0,0.0);
    glTexCoord2f(1.0, 1.0);  glVertex3f(c_width/2.5,70.0,0.0);
    glTexCoord2f(1.0, 0.0); glVertex3f(c_width/2.5,50.0+c_height/2,0.0);
    glTexCoord2f(0.0, 0.0);  glVertex3f(5.0,50.0+c_height/2,0.0);
    glEnd(); 
	
   glDisable(GL_TEXTURE_2D);   
}
//------------------------------------------------------------------------

void prim_1 (void) //название окна управления
{   
	glEnable(GL_TEXTURE_2D);       //m_width, m_height
	glColor3f(1.0,0.0,0.0);
	glBindTexture(GL_TEXTURE_2D, okno_1); 
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 1.0);  glVertex3f(700.0,3.0,0.0);
    glTexCoord2f(0.0, 0.0);  glVertex3f(700,35.0,0.0);
    glTexCoord2f(1.0, 0.0); glVertex3f(1000.0,35.0,0.0);
    glTexCoord2f(1.0, 1.0);  glVertex3f(1000.0,3.0,0.0);
    glEnd(); 
	
	glDisable(GL_TEXTURE_2D);   
}
//------------------------------------------------------------------------

void prim_2 (void) //название окна информации
{   
	glEnable(GL_TEXTURE_2D);
	glColor3f(1.0,0.0,0.0);
	glBindTexture(GL_TEXTURE_2D, okno_2); 
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 1.0);  glVertex3f(700.0,245.0,0.0);
    glTexCoord2f(0.0, 0.0);  glVertex3f(700.0,275.0,0.0);
    glTexCoord2f(1.0, 0.0); glVertex3f(1000.0,275.0,0.0);
    glTexCoord2f(1.0, 1.0);  glVertex3f(1000.0,245.0,0.0);
    glEnd(); 
	
	glDisable(GL_TEXTURE_2D);   
}
//------------------------------------------------------------------------
void prim_3 (void) //окно подсказки
{   
	glEnable(GL_TEXTURE_2D);
	glColor3f(1.0,0.0,0.0);
	glBindTexture(GL_TEXTURE_2D, help); 
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0);  glVertex3f(-16.0,-18.0,0.0);
    glTexCoord2f(1.0, 0.0);  glVertex3f(17.0,-18.0,0.0);
    glTexCoord2f(1.0, 1.0); glVertex3f(17.0,-13.0,0.0);
    glTexCoord2f(0.0, 1.0);  glVertex3f(-16.0,-13.0,0.0);
    glEnd(); 
	
	glDisable(GL_TEXTURE_2D);   
}
//------------------------------------------------------------------------
void prim_4 (void) //окно подсказки 2
{   
	glEnable(GL_TEXTURE_2D);
	glColor3f(1.0,0.0,0.0);
	glBindTexture(GL_TEXTURE_2D, help_2); 
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 1.0);  glVertex3f(150.0,90.0,0.0);
    glTexCoord2f(1.0, 1.0);  glVertex3f(c_width,90.0,0.0);
    glTexCoord2f(1.0, 0.0); glVertex3f(c_width,90.0+c_height/2,0.0);
    glTexCoord2f(0.0, 0.0);  glVertex3f(150.0,90.0+c_height/2,0.0);
    glEnd(); 
	
	glDisable(GL_TEXTURE_2D);   
}
//------------------------------------------------------------------------
void func_1 (void) //y=1/x
{   
	glEnable(GL_TEXTURE_2D);
	glColor3f(1.0,0.0,0.0);
	glBindTexture(GL_TEXTURE_2D, f_1); 
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 1.0);  glVertex3f(10.0,370.0,0.0);
    glTexCoord2f(1.0, 1.0);  glVertex3f(330.0,370.0,0.0);
    glTexCoord2f(1.0, 0.0); glVertex3f(330.0,-40.0,0.0);
    glTexCoord2f(0.0, 0.0);  glVertex3f(10.0,-40.0,0.0);
	
    glEnd(); 
	
	glDisable(GL_TEXTURE_2D);   
}
//------------------------------------------------------------------------
void func_2 (void) //y=x*x
{   
	glEnable(GL_TEXTURE_2D);
	glColor3f(1.0,0.0,0.0);
	glBindTexture(GL_TEXTURE_2D, f_2); 
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 1.0);  glVertex3f(10.0,370.0,0.0);
    glTexCoord2f(1.0, 1.0);  glVertex3f(340.0,370.0,0.0);
    glTexCoord2f(1.0, 0.0); glVertex3f(340.0,-40.0,0.0);
    glTexCoord2f(0.0, 0.0);  glVertex3f(10.0,-40.0,0.0);
	
    glEnd(); 
	
	glDisable(GL_TEXTURE_2D);   
}
//------------------------------------------------------------------------
void func_3 (void) //y=x*x*x
{   
	glEnable(GL_TEXTURE_2D);
	glColor3f(1.0,0.0,0.0);
	glBindTexture(GL_TEXTURE_2D, f_3); 
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 1.0);  glVertex3f(10.0,370.0,0.0);
    glTexCoord2f(1.0, 1.0);  glVertex3f(340.0,370.0,0.0);
    glTexCoord2f(1.0, 0.0); glVertex3f(340.0,-80.0,0.0);
    glTexCoord2f(0.0, 0.0);  glVertex3f(10.0,-80.0,0.0);
	
    glEnd(); 
	
	glDisable(GL_TEXTURE_2D);   
}
//------------------------------------------------------------------------
void func_4 (void) //y=ax*x-b*x+c
{   
	glEnable(GL_TEXTURE_2D);
	glColor3f(1.0,0.0,0.0);
	glBindTexture(GL_TEXTURE_2D, f_4); 
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 1.0);  glVertex3f(10.0,370.0,0.0);
    glTexCoord2f(1.0, 1.0);  glVertex3f(340.0,370.0,0.0);
    glTexCoord2f(1.0, 0.0); glVertex3f(340.0,-80.0,0.0);
    glTexCoord2f(0.0, 0.0);  glVertex3f(10.0,-80.0,0.0);
	
    glEnd(); 
	
	glDisable(GL_TEXTURE_2D);   
}
//------------------------------------------------------------------------
void func_5 (void) //y=sinx
{   
	glEnable(GL_TEXTURE_2D);
	glColor3f(1.0,0.0,0.0);
	glBindTexture(GL_TEXTURE_2D, f_5); 
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 1.0);  glVertex3f(10.0,370.0,0.0);
    glTexCoord2f(1.0, 1.0);  glVertex3f(340.0,370.0,0.0);
    glTexCoord2f(1.0, 0.0); glVertex3f(340.0,-80.0,0.0);
    glTexCoord2f(0.0, 0.0);  glVertex3f(10.0,-80.0,0.0);
	
    glEnd(); 	
	glDisable(GL_TEXTURE_2D);   
}
//------------------------------------------------------------------------
void func_6 (void) //y=cosx
{   
	glEnable(GL_TEXTURE_2D);
	glColor3f(1.0,0.0,0.0);
	glBindTexture(GL_TEXTURE_2D, f_6); 
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 1.0);  glVertex3f(10.0,370.0,0.0);
    glTexCoord2f(1.0, 1.0);  glVertex3f(340.0,370.0,0.0);
    glTexCoord2f(1.0, 0.0); glVertex3f(340.0,-80.0,0.0);
    glTexCoord2f(0.0, 0.0);  glVertex3f(10.0,-80.0,0.0);
	
    glEnd(); 
	
	glDisable(GL_TEXTURE_2D);   
}
//------------------------------------------------------------------------
void func_7 (void) //y=tanx
{   
	glEnable(GL_TEXTURE_2D);
	glColor3f(1.0,0.0,0.0);
	glBindTexture(GL_TEXTURE_2D, f_7); 
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 1.0);  glVertex3f(10.0,370.0,0.0);
    glTexCoord2f(1.0, 1.0);  glVertex3f(340.0,370.0,0.0);
    glTexCoord2f(1.0, 0.0); glVertex3f(340.0,-80.0,0.0);
    glTexCoord2f(0.0, 0.0);  glVertex3f(10.0,-80.0,0.0);
	
    glEnd(); 
	
	glDisable(GL_TEXTURE_2D);   
}
//------------------------------------------------------------------------
void func_8 (void) //y=logx
{   
	glEnable(GL_TEXTURE_2D);
	glColor3f(1.0,0.0,0.0);
	glBindTexture(GL_TEXTURE_2D, f_8); 
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 1.0);  glVertex3f(10.0,370.0,0.0);
    glTexCoord2f(1.0, 1.0);  glVertex3f(340.0,370.0,0.0);
    glTexCoord2f(1.0, 0.0); glVertex3f(340.0,-80.0,0.0);
    glTexCoord2f(0.0, 0.0);  glVertex3f(10.0,-80.0,0.0);
	
    glEnd(); 
	
	glDisable(GL_TEXTURE_2D);   
}
//------------------------------------------------------------------------
void func_9 (void) //y=sqrtx
{   
	glEnable(GL_TEXTURE_2D);
	glColor3f(1.0,0.0,0.0);
	glBindTexture(GL_TEXTURE_2D, f_9); 
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 1.0);  glVertex3f(10.0,370.0,0.0);
    glTexCoord2f(1.0, 1.0);  glVertex3f(340.0,370.0,0.0);
    glTexCoord2f(1.0, 0.0); glVertex3f(340.0,-80.0,0.0);
    glTexCoord2f(0.0, 0.0);  glVertex3f(10.0,-80.0,0.0);
	
    glEnd(); 
	
	glDisable(GL_TEXTURE_2D);   
}
//------------------------------------------------------------------------
void func_10 (void) //y=|x|
{   
	glEnable(GL_TEXTURE_2D);
	glColor3f(1.0,0.0,0.0);
	glBindTexture(GL_TEXTURE_2D, f_10); 
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 1.0);  glVertex3f(10.0,370.0,0.0);
    glTexCoord2f(1.0, 1.0);  glVertex3f(340.0,370.0,0.0);
    glTexCoord2f(1.0, 0.0); glVertex3f(340.0,-80.0,0.0);
    glTexCoord2f(0.0, 0.0);  glVertex3f(10.0,-80.0,0.0);
	
    glEnd(); 
	
	glDisable(GL_TEXTURE_2D);   
}
//------------------------------------------------------------------------
void screen_display(void)
{
	glClearColor(0.0, 0.0, 0.0, 1.0); 
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  
	glLoadIdentity ();	
	if (flag_func==1){
	func_1();
	fank_12_command_display();
	}
	if (flag_func==2){
	func_2();
	fank_12_command_display();
	}
	if (flag_func==3){
	func_3();
	fank_12_command_display();
	}
	if (flag_func==4){
	func_4();
	fank_12_command_display();
	}
	if (flag_func==5){
	func_5();
	fank_12_command_display();
	}
	if (flag_func==6){
	func_6();
	fank_12_command_display();
	}
	if (flag_func==7){
	func_7();
	fank_12_command_display();
	}
	if (flag_func==8){
	func_8();
	fank_12_command_display();
	}
	if (flag_func==9){
	func_9();
	fank_12_command_display();
	}
	if (flag_func==10){
	func_10();
	fank_12_command_display();
	}
	glutSwapBuffers ();	
	
}
//------------------------------------------------------------------------
void command_display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);    
    if (flag_func==1){
	fank_1_command_display();
	fank_11_command_display();	
	}
	if (flag_func==2){
	fank_2_command_display();
	fank_11_command_display();	
	}
	if (flag_func==3){
	fank_3_command_display();
	fank_11_command_display();	
	}
	if (flag_func==4){
	fank_4_command_display();
	fank_11_command_display();	
	}
	if (flag_func==5){
	fank_5_command_display();
	fank_11_command_display();	
	}
	if (flag_func==6){
	fank_6_command_display();
	fank_11_command_display();	
	}
	if (flag_func==7){
	fank_7_command_display();
	fank_11_command_display();	
	}
	if (flag_func==8){
	fank_8_command_display();
	fank_11_command_display();	
	}
	if (flag_func==9){
	fank_9_command_display();
	fank_11_command_display();	
	}
	if (flag_func==10){
	fank_10_command_display();
	fank_11_command_display();	
	}
	
	prim(flag_func);
	prim_4();  
	
    glutSwapBuffers();	
}
//------------------------------------------------------------------------
//основное
void display(void)
{
	glClearColor(0.725, 0.725, 0.725, 1.0);     
	glLoadIdentity ();
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  
	//prim_1();
	//prim_2();
	glutSwapBuffers ();	
}
//------------------------------------------------------------------------
void world_display(void)
{
	glClearColor(0.0, 0.0, 0.0, 1.0); 
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
	glLoadIdentity ();
	setka ();
	
	gluLookAt (cam_x, cam_y, cam_z, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);    
		
	OSkord(world_x,world_y,world_z);		
	if (flag_func==1)
	FANC1(fank_1[0].value,fank_1[0].step); 
	if (flag_func==2)
	FANC2(fank_2[0].value,fank_2[0].step);
	if (flag_func==3)
	FANC3(fank_3[0].value,fank_3[2].value,fank_3[4].value,fank_3[1].value,fank_3[1].step);
	if (flag_func==4)
	FANC4(fank_4[0].value,fank_4[1].value,fank_4[2].value,fank_4[0].step);
	if (flag_func==5)
	FANC5(2.0,fank_5[0].value,fank_5[0].step);
	if (flag_func==6)
	FANC6(fank_6[0].value,fank_6[0].step);
	if (flag_func==7)
	FANC7(fank_7[0].value,fank_7[0].step);	
	if (flag_func==8)
	FANC8(fank_8[0].value,fank_8[1].value,fank_8[2].value,fank_8[0].step);
	if (flag_func==9)
	FANC9(fank_9[0].value,fank_9[0].step);
	if (flag_func==10)
	FANC10(fank_10[0].value,fank_10[0].step);
	glLoadIdentity ();	
	prim_3();	
	
    glutSwapBuffers();
}
//------------------------------------------------------------------------
void command_mouse(int button, int state, int x, int y)
{
    selection = 0;
    //printf ("x=%i y=%i\n",x,y);
    if (state == GLUT_DOWN)
	{    
		if (flag_func==1)
        selection += cell_hit(&fank_1[0], x, y);
		if (flag_func==2)
		selection += cell_hit(&fank_2[0], x, y);
		if (flag_func==3){
		selection += cell_hit(&fank_3[0], x, y);		
		selection += cell_hit(&fank_3[1], x, y);		
		selection += cell_hit(&fank_3[2], x, y);		
		selection += cell_hit(&fank_3[3], x, y);
		selection += cell_hit(&fank_3[4], x, y);
		}
		if (flag_func==4)
		{
		selection += cell_hit(&fank_4[0], x, y);
		selection += cell_hit(&fank_4[1], x, y);
		selection += cell_hit(&fank_4[2], x, y);
		}
		if (flag_func==5)
		selection += cell_hit(&fank_5[0], x, y);
		if (flag_func==6)
		selection += cell_hit(&fank_6[0], x, y);
		if (flag_func==7)
		selection += cell_hit(&fank_7[0], x, y);
		if (flag_func==8){
		selection += cell_hit(&fank_8[0], x, y);
		selection += cell_hit(&fank_8[1], x, y);
		selection += cell_hit(&fank_8[2], x, y);}
		if (flag_func==9)
		selection += cell_hit(&fank_9[0], x, y);
		if (flag_func==10)
		selection += cell_hit(&fank_10[0], x, y);
    }
    
    old_y = y;    
    redisplay_all();
}
//------------------------------------------------------------------------
void
command_motion(int x, int y)
{
	if (flag_func==1)
    cell_update(&fank_1[0], old_y-y);
	if (flag_func==2)
    cell_update(&fank_2[0], old_y-y);	
	if (flag_func==3)
	{
	cell_update(&fank_3[0], old_y-y);
	cell_update(&fank_3[1], old_y-y);
	cell_update(&fank_3[2], old_y-y);
	cell_update(&fank_3[3], old_y-y);
	cell_update(&fank_3[4], old_y-y);
	}	
	if (flag_func==4){
	cell_update(&fank_4[0], old_y-y);
	cell_update(&fank_4[1], old_y-y);
	cell_update(&fank_4[2], old_y-y);
	}
	if (flag_func==5)
    cell_update(&fank_5[0], old_y-y);
	if (flag_func==6)
	cell_update(&fank_6[0], old_y-y);
	if (flag_func==7)
	cell_update(&fank_7[0], old_y-y);
	if (flag_func==8)
	cell_update(&fank_8[0], old_y-y);
	cell_update(&fank_8[1], old_y-y);
	cell_update(&fank_8[2], old_y-y);
	if (flag_func==9)
	cell_update(&fank_9[0], old_y-y);
	if (flag_func==10)
	cell_update(&fank_10[0], old_y-y);
	
    old_y = y;    
    redisplay_all();
}
//------------------------------------------------------------------------
void redisplay_all(void)
{
    glutSetWindow(command);
    glutPostRedisplay();
    glutSetWindow(world);
    world_reshape(world_sub_width, world_sub_height);
    glutPostRedisplay();
    glutSetWindow(screen);
    screen_reshape(sub_width, sub_height);
    glutPostRedisplay();
}
//------------------------------------------------------------------------
void keyboard_spec(int key, int x, int y)
{
   switch (key)
   {
    case GLUT_KEY_LEFT:
			phi+=0.1;
			cam_y=R*cos(teta);
			cam_x=R1*cos(phi);
			cam_z=R1*sin(phi);
        glutPostRedisplay();
         break;
	case GLUT_KEY_RIGHT:
			phi-=0.1;
			cam_y=R*cos(teta);
			cam_x=R1*cos(phi);
			cam_z=R1*sin(phi);
        glutPostRedisplay();
         break;
	case GLUT_KEY_UP: 	
			teta+=0.1;	
			cam_y=R*cos(teta);
			R1=R*sin(teta);
			cam_x=R1*cos(phi);
			cam_z=R1*sin(phi);
        glutPostRedisplay();
         break;	
	case GLUT_KEY_DOWN: 	
		teta-=0.1;	
		cam_y=R*cos(teta);
		R1=R*sin(teta);
		cam_x=R1*cos(phi);
		cam_z=R1*sin(phi);
        glutPostRedisplay();
         break;	
	/*case GLUT_KEY_PAGE_UP:
           R=sqrt((R-10.1)*(R-10.1));
		   if (R<3){
		   R=3;
		   }	   
		   R1=R*sin(teta);
		   cam_y=R*cos(teta);
			cam_x=R1*cos(phi);
			cam_z=R1*sin(phi);
           glutPostRedisplay();
         break;
	case GLUT_KEY_PAGE_DOWN:
           R=R+10.1;
		   if (R>90){
		   R=90;
		   }		   
		   R1=R*sin(teta);
		   cam_y=R*cos(teta);
			cam_x=R1*cos(phi);
			cam_z=R1*sin(phi);
           glutPostRedisplay();
         break;	*/
		 
	
//------------------------------------------------------------------------
	case GLUT_KEY_F1:
		flag_func=1;
		break;
	case GLUT_KEY_F2:
		flag_func=2;
		break;
	case GLUT_KEY_F3:
		flag_func=3;
		break;
	case GLUT_KEY_F4:
		flag_func=4;
		break;
	case GLUT_KEY_F5:
		flag_func=5;
		break;
	case GLUT_KEY_F6:
		flag_func=6;
		break;
	case GLUT_KEY_F7:
		flag_func=7;
		break;
	case GLUT_KEY_F8:
		flag_func=8;
		break;
	case GLUT_KEY_F9:
		flag_func=9;
		break;
	case GLUT_KEY_F10:
		flag_func=10;
		break;	
	case GLUT_KEY_F11:
		flag_func=10;
		break;
	case GLUT_KEY_F12:
		flag_func=10;
		break;	
	} 
	redisplay_all();
   }		 
//------------------------------------------------------------------------
int main(int argc, char** argv)
{ 
	   glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	   glutInitWindowSize(1024,768);
	   glutInitWindowPosition (100, 100);  
	   glutInit (&argc, argv);
	   window=glutCreateWindow ("Math_develop_Alekseenko_Michael");
	    init (); 
	  
	   glutReshapeFunc (main_reshape);
	   glutKeyboardFunc (Keyboard); 	   
	   glutDisplayFunc (display); 
	   init_texture_1();	   
    
    world = glutCreateSubWindow(window, GAP+20+GAP, GAP+30+GAP, 620, 750);
    glutReshapeFunc(world_reshape);
    glutDisplayFunc(world_display); 
	glutSpecialFunc (keyboard_spec);
	glutKeyboardFunc (Keyboard); 	
	init_texture_2();	
	
    screen = glutCreateSubWindow(window, GAP+20+GAP, GAP+30+GAP, 50, 20);
    glutReshapeFunc(screen_reshape);
    glutDisplayFunc(screen_display);
	glutSpecialFunc (keyboard_spec);
	glutKeyboardFunc (Keyboard); 	
	init_texture_3();
  
    command = glutCreateSubWindow(window, GAP+20+GAP, GAP+450+GAP, 380, 290);
    glutReshapeFunc(command_reshape);
    glutDisplayFunc(command_display);
    glutMotionFunc(command_motion);
    glutMouseFunc(command_mouse); 
	glutKeyboardFunc (Keyboard); 	
	glutSpecialFunc (keyboard_spec); 
    init_texture();	
    redisplay_all();
    
   glutMainLoop();
   return 0;
}

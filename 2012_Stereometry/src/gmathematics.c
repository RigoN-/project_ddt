#include <GL/glut.h>
#include <GL/glu.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <math.h>
#include "./tools/rglTexture.h"

//Размеры окна
#define win_width 1024
#define win_height 768
#define window_x 100
#define window_y 100
char *prog_name =(char*) "OpenGL with GLUT init";
int window = 0;
int frame = 0;
float fps =0;
char s[50];
int *font=(int*)GLUT_BITMAP_8_BY_13;
float rcube=0.0;
float rcube_x=-60.0;
float rcube_y=30.0;
int flag_func=1;

char *Txf01="../data/texture/help1.bmp";
char *Txf02="../data/texture/help1_1.bmp";
char *Txf03="../data/texture/help2.bmp";
char *Txf04="../data/texture/help2_2.bmp";
char *Txf05="../data/texture/help3.bmp";
char *Txf06="../data/texture/help3_3.bmp";
char *Txf07="../data/texture/help4.bmp";
char *Txf08="../data/texture/help4_4.bmp";
char *Txf09="../data/texture/help5.bmp";
char *Txf10="../data/texture/help5_5.bmp";
char *Txf11="../data/texture/help6.bmp";
char *Txf12="../data/texture/help6_6.bmp";
char *Txf13="../data/texture/help7.bmp";
char *Txf14="../data/texture/help7_7.bmp";
char *Txf15="../data/texture/help8.bmp";
char *Txf16="../data/texture/help8_8.bmp";
char *Txf17="../data/texture/help9.bmp";
char *Txf18="../data/texture/help9_9.bmp";
char *Txf19="../data/texture/help10.bmp";
char *Txf20="../data/texture/help10_10.bmp";
char *Txf21="../data/texture/nazv.bmp";

unsigned  int help1,help1_1,help2,help2_2,help3,help3_3,help4,help4_4,help5,help5_5,help6,help6_6,help7,help7_7,help8,help8_8,help9,help9_9,help10,help10_10,nazv;

GLint selection = 0;
GLboolean swapped = GL_FALSE;
GLvoid *font_style = GLUT_BITMAP_TIMES_ROMAN_10;
//-------------------------------------------------------------------------------------------------- 
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
//-------------------------------------------------------------------------------------------------- 
void ogl_init(void)
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClearDepth(1.0);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glPolygonMode (GL_FRONT_AND_BACK, GL_LINE);
	glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
}
//-------------------------------------------------------------------------------------------------- 
void ogl_reshape(int width, int height)
{
	if (height == 0)
			height = 1;
		glViewport(0, 0, width, height);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		//gluPerspective(45.0, (float)width/(float)height, 1.0, 100.0);
		glOrtho(-width/2, width/2, -height/2, height/2, -1000.0, 1000.0);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
}
//-------------------------------------------------------------------------------------------------- 
void renderBitmapString(float x, float y, float z, void *font,char *string)
{

  char *c;
  glRasterPos3f(x, y, z);
  for (c=string; *c != '\0'; c++) {
    glutBitmapCharacter(font, *c);
  }
}
//-------------------------------------------------------------------------------------------------- 
void  draw_title(float x, float y,float z)
{
	glLoadIdentity();
	glColor3f(0.0f,1.0f,1.0f);
	renderBitmapString(x,y,z,(void *)font,prog_name);
	renderBitmapString(x,y-0.1,z,(void *)font,s);
	renderBitmapString(x,y-0.2,z,(void *)font,"Esc - Quit");
}
//-------------------------------------------------------------------------------------------------- 
void init_texture_1()
{
	glEnable(GL_TEXTURE_2D);
	rglLoad_Texture (Txf01, &help1, txAnisotropic_16, GL_DECAL, GL_REPEAT,txGL_COMPRESS,GL_TRUE);
	rglLoad_Texture (Txf02, &help1_1, txAnisotropic_16, GL_DECAL, GL_REPEAT,txGL_COMPRESS,GL_TRUE);
	rglLoad_Texture (Txf03, &help2, txAnisotropic_16, GL_DECAL, GL_REPEAT,txGL_COMPRESS,GL_TRUE);
	rglLoad_Texture (Txf04, &help2_2, txAnisotropic_16, GL_DECAL, GL_REPEAT,txGL_COMPRESS,GL_TRUE);
	rglLoad_Texture (Txf05, &help3, txAnisotropic_16, GL_DECAL, GL_REPEAT,txGL_COMPRESS,GL_TRUE);
	rglLoad_Texture (Txf06, &help3_3, txAnisotropic_16, GL_DECAL, GL_REPEAT,txGL_COMPRESS,GL_TRUE);
	rglLoad_Texture (Txf07, &help4, txAnisotropic_16, GL_DECAL, GL_REPEAT,txGL_COMPRESS,GL_TRUE);
	rglLoad_Texture (Txf08, &help4_4, txAnisotropic_16, GL_DECAL, GL_REPEAT,txGL_COMPRESS,GL_TRUE);
	rglLoad_Texture (Txf09, &help5, txAnisotropic_16, GL_DECAL, GL_REPEAT,txGL_COMPRESS,GL_TRUE);
	rglLoad_Texture (Txf10, &help5_5, txAnisotropic_16, GL_DECAL, GL_REPEAT,txGL_COMPRESS,GL_TRUE);
	rglLoad_Texture (Txf11, &help6, txAnisotropic_16, GL_DECAL, GL_REPEAT,txGL_COMPRESS,GL_TRUE);
	rglLoad_Texture (Txf12, &help6_6, txAnisotropic_16, GL_DECAL, GL_REPEAT,txGL_COMPRESS,GL_TRUE);
	rglLoad_Texture (Txf13, &help7, txAnisotropic_16, GL_DECAL, GL_REPEAT,txGL_COMPRESS,GL_TRUE);
	rglLoad_Texture (Txf14, &help7_7, txAnisotropic_16, GL_DECAL, GL_REPEAT,txGL_COMPRESS,GL_TRUE);
	rglLoad_Texture (Txf15, &help8, txAnisotropic_16, GL_DECAL, GL_REPEAT,txGL_COMPRESS,GL_TRUE);
	rglLoad_Texture (Txf16, &help8_8, txAnisotropic_16, GL_DECAL, GL_REPEAT,txGL_COMPRESS,GL_TRUE);
	rglLoad_Texture (Txf17, &help9, txAnisotropic_16, GL_DECAL, GL_REPEAT,txGL_COMPRESS,GL_TRUE);
	rglLoad_Texture (Txf18, &help9_9, txAnisotropic_16, GL_DECAL, GL_REPEAT,txGL_COMPRESS,GL_TRUE);
	rglLoad_Texture (Txf19, &help10, txAnisotropic_16, GL_DECAL, GL_REPEAT,txGL_COMPRESS,GL_TRUE);
	rglLoad_Texture (Txf20, &help10_10, txAnisotropic_16, GL_DECAL, GL_REPEAT,txGL_COMPRESS,GL_TRUE);
	rglLoad_Texture (Txf21, &nazv, txAnisotropic_16, GL_DECAL, GL_REPEAT,txGL_COMPRESS,GL_TRUE);
	glDisable(GL_TEXTURE_2D);   
 }  
 //-------------------------------------------------------------------------------------------------
 void setka (void)
{
	int i;
	glPolygonMode (GL_FRONT_AND_BACK, GL_LINE);
	glLineWidth (1.0);
    glEnable(GL_LINE_SMOOTH); 
	glBegin(GL_LINES);
	glColor3f(0.05, 0.1, 0.05);
		for (i=-500;i<=500;i+=15)
	{	  
      glVertex3f (i, 250.0, -300.0);
      glVertex3f (i, -250.0, -300.0); 
	}
	glEnd();
	 glBegin(GL_LINES);
   glColor3f(0.05, 0.1, 0.05);
		for (i=-250;i<=250;i+=15)
	{	  
      glVertex3f (-500.0, i, -300.0);
      glVertex3f (500.0, i, -300.0); 
	}
	glEnd();
}
//-----------------------------------------------------------------------------------------------
void prim_0 (void) //окно подсказки для 1
{   	
	glPolygonMode (GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1.0,0.0,1.0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, nazv); 
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 1.0);  glVertex3f(-500.0,380.0,-2.0);
    glTexCoord2f(1.0, 1.0);  glVertex3f(500.0,380.0,-2.0);
    glTexCoord2f(1.0, 0.0); glVertex3f(500.0,340.0,-2.0);
    glTexCoord2f(0.0, 0.0);  glVertex3f(-500.0,340.0,-2.0);
    glEnd(); 
	
	glDisable(GL_TEXTURE_2D);   
	glPolygonMode (GL_FRONT_AND_BACK, GL_LINE);
}
//-----------------------------------------------------------------------------------------------
 void prim_1 (void) //окно подсказки для 1
{   	
	glPolygonMode (GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1.0,0.0,1.0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, help1); 
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 1.0);  glVertex3f(-500.0,335.0,-2.0);
    glTexCoord2f(1.0, 1.0);  glVertex3f(500.0,335.0,-2.0);
    glTexCoord2f(1.0, 0.0); glVertex3f(500.0,225.0,-2.0);
    glTexCoord2f(0.0, 0.0);  glVertex3f(-500.0,225.0,-2.0);
    glEnd(); 
	
	glDisable(GL_TEXTURE_2D);   
	glPolygonMode (GL_FRONT_AND_BACK, GL_LINE);
}

 void prim_2 (void) //окно подсказки для 1
{   
	glEnable(GL_TEXTURE_2D);
	glPolygonMode (GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1.0,0.0,1.0);
	glBindTexture(GL_TEXTURE_2D, help1_1); 
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 1.0);  glVertex3f(-500.0,-250.0,-2.0);
    glTexCoord2f(1.0, 1.0);  glVertex3f(500.0,-250.0,-2.0);
    glTexCoord2f(1.0, 0.0); glVertex3f(500.0,-370.0,-2.0);
    glTexCoord2f(0.0, 0.0);  glVertex3f(-500.0,-370.0,-2.0);
    glEnd(); 
	
	glDisable(GL_TEXTURE_2D);   
	glPolygonMode (GL_FRONT_AND_BACK, GL_LINE);
}
//-------------------------------------------------------------------------------------------------- 
 void prim_3 (void) //окно подсказки для 2
{   
	glEnable(GL_TEXTURE_2D);
	glPolygonMode (GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1.0,0.0,1.0);
	glBindTexture(GL_TEXTURE_2D, help2); 
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 1.0);  glVertex3f(-500.0,335.0,-2.0);
    glTexCoord2f(1.0, 1.0);  glVertex3f(500.0,335.0,-2.0);
    glTexCoord2f(1.0, 0.0); glVertex3f(500.0,225.0,-2.0);
    glTexCoord2f(0.0, 0.0);  glVertex3f(-500.0,225.0,-2.0);
    glEnd(); 
	
	glDisable(GL_TEXTURE_2D);   
	glPolygonMode (GL_FRONT_AND_BACK, GL_LINE);
}
 void prim_4 (void) //окно подсказки для 2
{   
	glEnable(GL_TEXTURE_2D);
	glPolygonMode (GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1.0,0.0,1.0);
	glBindTexture(GL_TEXTURE_2D, help2_2); 
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 1.0);  glVertex3f(-500.0,-250.0,-2.0);
    glTexCoord2f(1.0, 1.0);  glVertex3f(500.0,-250.0,-2.0);
    glTexCoord2f(1.0, 0.0); glVertex3f(500.0,-370.0,-2.0);
    glTexCoord2f(0.0, 0.0);  glVertex3f(-500.0,-370.0,-2.0);
    glEnd(); 
	
	glDisable(GL_TEXTURE_2D);   
	glPolygonMode (GL_FRONT_AND_BACK, GL_LINE);
}
//-------------------------------------------------------------------------------------------------- 
 void prim_5 (void) //окно подсказки для 3
{   
	glEnable(GL_TEXTURE_2D);
	glPolygonMode (GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1.0,0.0,1.0);
	glBindTexture(GL_TEXTURE_2D, help3); 
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 1.0);  glVertex3f(-500.0,335.0,-2.0);
    glTexCoord2f(1.0, 1.0);  glVertex3f(500.0,335.0,-2.0);
    glTexCoord2f(1.0, 0.0); glVertex3f(500.0,225.0,-2.0);
    glTexCoord2f(0.0, 0.0);  glVertex3f(-500.0,225.0,-2.0);
    glEnd(); 
	
	glDisable(GL_TEXTURE_2D);   
	glPolygonMode (GL_FRONT_AND_BACK, GL_LINE);
}
 void prim_6 (void) //окно подсказки для 3
{   
	glEnable(GL_TEXTURE_2D);
	glPolygonMode (GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1.0,0.0,1.0);
	glBindTexture(GL_TEXTURE_2D, help3_3); 
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 1.0);  glVertex3f(-500.0,-250.0,-2.0);
    glTexCoord2f(1.0, 1.0);  glVertex3f(500.0,-250.0,-2.0);
    glTexCoord2f(1.0, 0.0); glVertex3f(500.0,-370.0,-2.0);
    glTexCoord2f(0.0, 0.0);  glVertex3f(-500.0,-370.0,-2.0);
    glEnd(); 
	
	glDisable(GL_TEXTURE_2D);   
	glPolygonMode (GL_FRONT_AND_BACK, GL_LINE);
}
//-------------------------------------------------------------------------------------------------- 
 void prim_7 (void) //окно подсказки для 4
{   
	glEnable(GL_TEXTURE_2D);
	glPolygonMode (GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1.0,0.0,1.0);
	glBindTexture(GL_TEXTURE_2D, help4); 
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 1.0);  glVertex3f(-500.0,335.0,-2.0);
    glTexCoord2f(1.0, 1.0);  glVertex3f(500.0,335.0,-2.0);
    glTexCoord2f(1.0, 0.0); glVertex3f(500.0,225.0,-2.0);
    glTexCoord2f(0.0, 0.0);  glVertex3f(-500.0,225.0,-2.0);
    glEnd(); 
	
	glDisable(GL_TEXTURE_2D);   
	glPolygonMode (GL_FRONT_AND_BACK, GL_LINE);
}
 void prim_8 (void) //окно подсказки для 4-
{   
	glEnable(GL_TEXTURE_2D);
	glPolygonMode (GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1.0,0.0,1.0);
	glBindTexture(GL_TEXTURE_2D, help4_4); 
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 1.0);  glVertex3f(-500.0,-250.0,-2.0);
    glTexCoord2f(1.0, 1.0);  glVertex3f(500.0,-250.0,-2.0);
    glTexCoord2f(1.0, 0.0); glVertex3f(500.0,-370.0,-2.0);
    glTexCoord2f(0.0, 0.0);  glVertex3f(-500.0,-370.0,-2.0);
    glEnd(); 
	
	glDisable(GL_TEXTURE_2D);   
	glPolygonMode (GL_FRONT_AND_BACK, GL_LINE);
}
//-------------------------------------------------------------------------------------------------
 void prim_9 (void) //окно подсказки для 5
{   
	glEnable(GL_TEXTURE_2D);
	glPolygonMode (GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1.0,0.0,1.0);
	glBindTexture(GL_TEXTURE_2D, help5); 
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 1.0);  glVertex3f(-500.0,335.0,-2.0);
    glTexCoord2f(1.0, 1.0);  glVertex3f(500.0,335.0,-2.0);
    glTexCoord2f(1.0, 0.0); glVertex3f(500.0,225.0,-2.0);
    glTexCoord2f(0.0, 0.0);  glVertex3f(-500.0,225.0,-2.0);
    glEnd(); 
	
	glDisable(GL_TEXTURE_2D);   
	glPolygonMode (GL_FRONT_AND_BACK, GL_LINE);
}
 void prim_10 (void) //окно подсказки для 5
{   
	glEnable(GL_TEXTURE_2D);
	glPolygonMode (GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1.0,0.0,1.0);
	glBindTexture(GL_TEXTURE_2D, help5_5); 
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 1.0);  glVertex3f(-500.0,-250.0,-2.0);
    glTexCoord2f(1.0, 1.0);  glVertex3f(500.0,-250.0,-2.0);
    glTexCoord2f(1.0, 0.0); glVertex3f(500.0,-370.0,-2.0);
    glTexCoord2f(0.0, 0.0);  glVertex3f(-500.0,-370.0,-2.0);
    glEnd(); 
	
	glDisable(GL_TEXTURE_2D);   
	glPolygonMode (GL_FRONT_AND_BACK, GL_LINE);
}
//-------------------------------------------------------------------------------------------------- 
 void prim_11 (void) //окно подсказки для 6
{   
	glEnable(GL_TEXTURE_2D);
	glPolygonMode (GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1.0,0.0,1.0);
	glBindTexture(GL_TEXTURE_2D, help6); 
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 1.0);  glVertex3f(-500.0,335.0,-2.0);
    glTexCoord2f(1.0, 1.0);  glVertex3f(500.0,335.0,-2.0);
    glTexCoord2f(1.0, 0.0); glVertex3f(500.0,225.0,-2.0);
    glTexCoord2f(0.0, 0.0);  glVertex3f(-500.0,225.0,-2.0);
    glEnd(); 
	
	glDisable(GL_TEXTURE_2D);   
	glPolygonMode (GL_FRONT_AND_BACK, GL_LINE);
}
 void prim_12 (void) //окно подсказки для 6
{   
	glEnable(GL_TEXTURE_2D);
	glPolygonMode (GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1.0,0.0,1.0);
	glBindTexture(GL_TEXTURE_2D, help6_6); 
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 1.0);  glVertex3f(-500.0,-250.0,-2.0);
    glTexCoord2f(1.0, 1.0);  glVertex3f(500.0,-250.0,-2.0);
    glTexCoord2f(1.0, 0.0); glVertex3f(500.0,-370.0,-2.0);
    glTexCoord2f(0.0, 0.0);  glVertex3f(-500.0,-370.0,-2.0);
    glEnd(); 
	
	glDisable(GL_TEXTURE_2D);   
	glPolygonMode (GL_FRONT_AND_BACK, GL_LINE);
}
//-------------------------------------------------------------------------------------------------- 
 void prim_13 (void) //окно подсказки для 7
{   
	glEnable(GL_TEXTURE_2D);
	glPolygonMode (GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1.0,0.0,1.0);
	glBindTexture(GL_TEXTURE_2D, help7); 
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 1.0);  glVertex3f(-500.0,335.0,-2.0);
    glTexCoord2f(1.0, 1.0);  glVertex3f(500.0,335.0,-2.0);
    glTexCoord2f(1.0, 0.0); glVertex3f(500.0,225.0,-2.0);
    glTexCoord2f(0.0, 0.0);  glVertex3f(-500.0,225.0,-2.0);
    glEnd(); 
	
	glDisable(GL_TEXTURE_2D);   
	glPolygonMode (GL_FRONT_AND_BACK, GL_LINE);
}
 void prim_14 (void) //окно подсказки для 7
{   
	glEnable(GL_TEXTURE_2D);
	glPolygonMode (GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1.0,0.0,1.0);
	glBindTexture(GL_TEXTURE_2D, help7_7); 
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 1.0);  glVertex3f(-500.0,-250.0,-2.0);
    glTexCoord2f(1.0, 1.0);  glVertex3f(500.0,-250.0,-2.0);
    glTexCoord2f(1.0, 0.0); glVertex3f(500.0,-370.0,-2.0);
    glTexCoord2f(0.0, 0.0);  glVertex3f(-500.0,-370.0,-2.0);
    glEnd(); 
	
	glDisable(GL_TEXTURE_2D);   
	glPolygonMode (GL_FRONT_AND_BACK, GL_LINE);
}
//-------------------------------------------------------------------------------------------------- 
 void prim_15 (void) //окно подсказки для 8
{   
	glEnable(GL_TEXTURE_2D);
	glPolygonMode (GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1.0,0.0,1.0);
	glBindTexture(GL_TEXTURE_2D, help8); 
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 1.0);  glVertex3f(-500.0,335.0,-2.0);
    glTexCoord2f(1.0, 1.0);  glVertex3f(500.0,335.0,-2.0);
    glTexCoord2f(1.0, 0.0); glVertex3f(500.0,225.0,-2.0);
    glTexCoord2f(0.0, 0.0);  glVertex3f(-500.0,225.0,-2.0);
    glEnd(); 
	
	glDisable(GL_TEXTURE_2D);   
	glPolygonMode (GL_FRONT_AND_BACK, GL_LINE);
}
 void prim_16 (void) //окно подсказки для 8
{   
	glEnable(GL_TEXTURE_2D);
	glPolygonMode (GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1.0,0.0,1.0);
	glBindTexture(GL_TEXTURE_2D, help8_8); 
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 1.0);  glVertex3f(-500.0,-250.0,-2.0);
    glTexCoord2f(1.0, 1.0);  glVertex3f(500.0,-250.0,-2.0);
    glTexCoord2f(1.0, 0.0); glVertex3f(500.0,-370.0,-2.0);
    glTexCoord2f(0.0, 0.0);  glVertex3f(-500.0,-370.0,-2.0);
    glEnd(); 
	
	glDisable(GL_TEXTURE_2D);   
	glPolygonMode (GL_FRONT_AND_BACK, GL_LINE);
}
//-------------------------------------------------------------------------------------------------- 
 void prim_17 (void) //окно подсказки для 9
{   
	glEnable(GL_TEXTURE_2D);
	glPolygonMode (GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1.0,0.0,1.0);
	glBindTexture(GL_TEXTURE_2D, help9); 
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 1.0);  glVertex3f(-500.0,335.0,-2.0);
    glTexCoord2f(1.0, 1.0);  glVertex3f(500.0,335.0,-2.0);
    glTexCoord2f(1.0, 0.0); glVertex3f(500.0,225.0,-2.0);
    glTexCoord2f(0.0, 0.0);  glVertex3f(-500.0,225.0,-2.0);
    glEnd(); 
	
	glDisable(GL_TEXTURE_2D);   
	glPolygonMode (GL_FRONT_AND_BACK, GL_LINE);
}
 void prim_18 (void) //окно подсказки для 9
{   
	glEnable(GL_TEXTURE_2D);
	glPolygonMode (GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1.0,0.0,1.0);
	glBindTexture(GL_TEXTURE_2D, help9_9); 
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 1.0);  glVertex3f(-500.0,-250.0,-2.0);
    glTexCoord2f(1.0, 1.0);  glVertex3f(500.0,-250.0,-2.0);
    glTexCoord2f(1.0, 0.0); glVertex3f(500.0,-370.0,-2.0);
    glTexCoord2f(0.0, 0.0);  glVertex3f(-500.0,-370.0,-2.0);
    glEnd(); 
	
	glDisable(GL_TEXTURE_2D);   
	glPolygonMode (GL_FRONT_AND_BACK, GL_LINE);
}
//-------------------------------------------------------------------------------------------------- 
 void prim_19 (void) //окно подсказки для 10
{   
	glEnable(GL_TEXTURE_2D);
	glPolygonMode (GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1.0,0.0,1.0);
	glBindTexture(GL_TEXTURE_2D, help10); 
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 1.0);  glVertex3f(-500.0,335.0,-2.0);
    glTexCoord2f(1.0, 1.0);  glVertex3f(500.0,335.0,-2.0);
    glTexCoord2f(1.0, 0.0); glVertex3f(500.0,225.0,-2.0);
    glTexCoord2f(0.0, 0.0);  glVertex3f(-500.0,225.0,-2.0);
    glEnd(); 
	
	glDisable(GL_TEXTURE_2D);   
	glPolygonMode (GL_FRONT_AND_BACK, GL_LINE);
}
 void prim_20 (void) //окно подсказки для 10
{   
	glEnable(GL_TEXTURE_2D);
	glPolygonMode (GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1.0,0.0,1.0);
	glBindTexture(GL_TEXTURE_2D, help10_10); 
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 1.0);  glVertex3f(-500.0,-250.0,-2.0);
    glTexCoord2f(1.0, 1.0);  glVertex3f(500.0,-250.0,-2.0);
    glTexCoord2f(1.0, 0.0); glVertex3f(500.0,-370.0,-2.0);
    glTexCoord2f(0.0, 0.0);  glVertex3f(-500.0,-370.0,-2.0);
    glEnd(); 
	
	glDisable(GL_TEXTURE_2D);   
	glPolygonMode (GL_FRONT_AND_BACK, GL_LINE);
}
//-------------------------------------------------------------------------------------------------- 
void draw_cube(float x, float y, float z)
{
			glLineWidth (1.0);
			glBegin(GL_QUADS);

			glColor3f(255.0,0.0,0.0);
			glVertex3f(-x, -y, z);
			glColor3f(255.0,0.0,0.0);
			glVertex3f(-x, y, z) ;
			glColor3f(255.0,0.0,0.0);
			glVertex3f(x, y, z);
			glColor3f(255.0,0.0,0.0);
			glVertex3f(x, -y, z);

	  		glColor3f(255.0,0.0,0.0);
			glVertex3f(-x, -y, z);
			glColor3f(255.0,0.0,0.0);
			glVertex3f(-x, -y, -z);
			glColor3f(255.0,0.0,0.0);
			glVertex3f(-x, y, -z) ;
			glColor3f(255.0,0.0,0.0);
			glVertex3f(-x, y, z);

			glColor3f(255.0,0.0,0.0);
			glVertex3f(-x, -y, -z);
			glColor3f(255.0,0.0,0.0);
			glVertex3f(-x, y, -z) ;
			glColor3f(255.0,0.0,0.0);
			glVertex3f(x, y, -z);
			glColor3f(255.0,0.0,0.0);
			glVertex3f(x, -y, -z);

			glColor3f(255.0,0.0,0.0);
			glVertex3f(x, -y, z);
			glColor3f(255.0,0.0,0.0);
			glVertex3f(x, y, z);
			glColor3f(255.0,0.0,0.0);
			glVertex3f(x, y, -z);
			glColor3f(255.0,0.0,0.0);
			glVertex3f(x, -y, -z);

			glColor3f(255.0,0.0,0.0);
			glVertex3f(-x, y, z);
			glColor3f(255.0,0.0,0.0);
			glVertex3f(-x, y, -z);
			glColor3f(255.0,0.0,0.0);
			glVertex3f(x, y, -z);
			glColor3f(255.0,0.0,0.0);
			glVertex3f(x, y, z);

			glColor3f(255.0,0.0,0.0);
			glVertex3f(-x, -y, z);
			glColor3f(255.0,0.0,0.0);
			glVertex3f(-x, -y, -z);
			glColor3f(255.0,0.0,0.0);
			glVertex3f(x, -y, -z);
			glColor3f(255.0,0.0,0.0);
			glVertex3f(x, -y, z);
			glEnd() ;
			glEnable (GL_POINT_SMOOTH); 
			glPointSize(5.0);
			
			glBegin(GL_POINTS);
			
			glColor3f(0.0,1.0,0.0);
			
			glVertex3f(-x, -y, z);
			glVertex3f(x, y, -z);
			glVertex3f(-x, y, z) ;
			glVertex3f(-x, y, -z) ;
			glVertex3f(x, -y, -z);
			glVertex3f(x, -y, z);
			glVertex3f(-x, -y, -z);
			glVertex3f(x, y, z);
			glEnd() ;
			renderBitmapString(-x+10,-y+10,z,(void *)font,"A");
			renderBitmapString(x+10,y+10,-z,(void *)font,"C1");
			renderBitmapString(-x+10,y+10,z,(void *)font,"A1");
			renderBitmapString(-x+10,y+10,-z,(void *)font,"B1");
			renderBitmapString(x+10,-y+10,-z,(void *)font,"C");
			renderBitmapString(x+10,-y+10,z,(void *)font,"D");
			renderBitmapString(-x+10,-y+10,-z,(void *)font,"B");
			renderBitmapString(x+10,y+10,z,(void *)font,"D1");
			glDisable (GL_POINT_SMOOTH); 
}
//-------------------------------------------------------------------------------------------------- 
void draw_tring(float x, float y, float z)
{
	glLineWidth (2.0);
	glBegin(GL_LINES);	

	glColor3f(1.0,0.0,1.0);
	glVertex3f(-x, -y, z);
	glVertex3f(x, y, -z);
	
	glVertex3f(-x, y, z);
	glVertex3f(x, y, -z);
	
	glVertex3f(-x, y, z);
	glVertex3f(-x, -y, z);	
	
	glEnd() ;
}
//-------------------------------------------------------------------------------------------------- 
void draw_rast(float x, float y, float z)
{
	glLineWidth (2.0);
	glBegin(GL_LINES);	

	glColor3f(1.0,0.0,1.0);
	glVertex3f(-x, -y, z);
	glVertex3f(0, y, 0);
	
	glVertex3f(-x, y, 0);
	glVertex3f(x, y, 0);
	
	glVertex3f(-x, -y, z);
	glVertex3f(-x, y, 0);	
	
	glEnd() ;
	
	glPointSize(5.0);	
	glBegin(GL_POINTS);			
	glColor3f(0.0,1.0,0.0);
	glVertex3f(0, y, 0);
	glVertex3f(-x, y, 0);	
	glEnd() ;
	renderBitmapString(0+10,y+10,0,(void *)font,"O1");
	renderBitmapString(-x+10,y+10,0,(void *)font,"M");
}
//-------------------------------------------------------------------------------------------------- 
void draw_rast_2(float x, float y, float z)
{
	glLineWidth (2.0);
	glBegin(GL_LINES);	

	glColor3f(1.0,0.0,1.0);
	glVertex3f(x, -y, z);
	glVertex3f(x, y, -z);
	
	glVertex3f(x, -y, z);
	glVertex3f(0, y, -z);
	
	glVertex3f(0, y, -z);
	glVertex3f(x, y, -z);	
	
	glEnd() ;
	
	glPointSize(5.0);	
	glBegin(GL_POINTS);			
	glColor3f(0.0,1.0,0.0);
	glVertex3f(0, y, -z);
	glEnd() ;
	renderBitmapString(0+10,y+10,-z,(void *)font,"O1");
}
//-------------------------------------------------------------------------------------------------- 
void draw_rast_3(float x, float y, float z)
{
	glLineWidth (2.0);
	glBegin(GL_LINES);	

	glColor3f(1.0,0.0,1.0);
	glVertex3f(-x, -y, z);
	glVertex3f(0, y, 0);
	
	glVertex3f(-x, -y, z);
	glVertex3f(0, -y, 0);
	
	glVertex3f(0, y, 0);
	glVertex3f(0, -y, 0);
	
	glEnd() ;
	
	glPointSize(5.0);	
	glBegin(GL_POINTS);			
	glColor3f(0.0,1.0,0.0);
	glVertex3f(0, y, 0);
	glVertex3f(0, -y, 0);
	glEnd() ;
	renderBitmapString(0+10,y+10,0,(void *)font,"O1");
	renderBitmapString(0+10,-y+10,0,(void *)font,"O");
}
//-------------------------------------------------------------------------------------------------- 
void draw_rast_4(float x, float y, float z)
{
	glLineWidth (2.0);
	glBegin(GL_LINES);	

	glColor3f(1.0,0.0,1.0);
	glVertex3f(-x, -y, z);
	glVertex3f(x, 0, z);
	
	glVertex3f(-x, -y, -z);
	glVertex3f(x, 0, -z);
	
	glVertex3f(-x, -y, z);
	glVertex3f(-x, -y, -z);
	
	glVertex3f(x, 0, 0);
	glVertex3f(x, -y, 0);
	
	glVertex3f(x, 0, z);
	glVertex3f(x, 0, -z);
	
	glVertex3f(x, -y, 0);
	glVertex3f(-x, -y, 0);
	
	glVertex3f(-x, -y, 0);
	glVertex3f(x, 0, 0);	
	
	glEnd() ;
	
	glPointSize(5.0);	
	glBegin(GL_POINTS);			
	glColor3f(0.0,1.0,0.0);
	glVertex3f(x, 0, z);
	glVertex3f(x, 0, -z);
	glVertex3f(x, 0, 0);
	glVertex3f(x, -y, 0);
	glVertex3f(-x, -y, 0);
	glEnd() ;
	renderBitmapString(x+10,0+10,z,(void *)font,"M");
	renderBitmapString(x+10,0+10,-z,(void *)font,"N");
	renderBitmapString(x+10,0+10,0,(void *)font,"O");
	renderBitmapString(x+10,-y+10,0,(void *)font,"O1");
	renderBitmapString(-x+10,-y+10,0,(void *)font,"K");
}
//-------------------------------------------------------------------------------------------------- 
void draw_rast_5(float x, float y, float z)
{
	glLineWidth (2.0);
	glBegin(GL_LINES);	

	glColor3f(1.0,0.0,1.0);
	glVertex3f(-x, -y, z);
	glVertex3f(x, y, z);
	
	glVertex3f(x, y, z);
	glVertex3f(x, -y, -z);
	
	glVertex3f(-x, -y, z);
	glVertex3f(x, -y, -z);
	
	glVertex3f(x, -y, -z);
	glVertex3f(0, 0, z);
	
	glEnd() ;
	
	glPointSize(5.0);	
	glBegin(GL_POINTS);			
	glColor3f(0.0,1.0,0.0);
	glVertex3f(0, 0, z);
	glEnd() ;
	renderBitmapString(0+10,0+10,z,(void *)font,"H");
}
//-------------------------------------------------------------------------------------------------- 
void draw_rast_6(float x, float y, float z)
{
	glLineWidth (2.0);
	glBegin(GL_LINES);	

	glColor3f(1.0,0.0,1.0);
	glVertex3f(-x, -y, z);
	glVertex3f(x, y, z);
	
	glVertex3f(-x, -y, z);
	glVertex3f(-x, -y, -z);
	
	glVertex3f(-x, -y, -z);
	glVertex3f(x, y, -z);
	
	glVertex3f(x, y, -z);
	glVertex3f(x, y, z);
	
	glVertex3f(x, -y, z);
	glVertex3f(-x, y, z);
	
	glVertex3f(-x, y, z);
	glVertex3f(-x, y, -z);
	
	glVertex3f(-x, y, -z);
	glVertex3f(x, -y, -z);
	
	glVertex3f(x, -y, -z);
	glVertex3f(x, -y, z);
	
	
	glEnd() ;
	
	glPointSize(5.0);	
	glBegin(GL_POINTS);			
	glColor3f(0.0,1.0,0.0);
	glVertex3f(0, 0, z);
	glVertex3f(0, 0, -z);
	glEnd() ;
	renderBitmapString(0+10,0+10,z,(void *)font,"O1");
	renderBitmapString(0+10,0+10,-z,(void *)font,"O");
}
//-------------------------------------------------------------------------------------------------- 
void draw_rast_7(float x, float y, float z)
{
	glLineWidth (2.0);
	glBegin(GL_LINES);	

	glColor3f(1.0,0.0,1.0);
	glVertex3f(-x,0, z);
	glVertex3f(-x, 0, -z);
	
	glVertex3f(-x,0, -z);
	glVertex3f(x, 0, -z);
	
	glVertex3f(x, 0, -z);
	glVertex3f(x, 0, z);
	
	glVertex3f(x, 0, z);
	glVertex3f(-x, 0, z);
	
	glVertex3f(-x, 0, z);
	glVertex3f(x, 0, -z);
	
	glVertex3f(0, 0, 0);
	glVertex3f(x, y, -z);
	
	glVertex3f(x, y, -z);
	glVertex3f(x, 0, -z);
	
	glEnd() ;
	
	glPointSize(5.0);	
	glBegin(GL_POINTS);			
	glColor3f(0.0,1.0,0.0);
	glVertex3f(-x,0, z);
	glVertex3f(-x,0, -z);
	glVertex3f(x, 0, -z);
	glVertex3f(x, 0, z);
	glVertex3f(0, 0, 0);
	glEnd() ;
	renderBitmapString(-x+10,0+10,z,(void *)font,"M");
	renderBitmapString(-x+10,0+10,-z,(void *)font,"N");
	renderBitmapString(x+10,0+10,-z,(void *)font,"K");
	renderBitmapString(x+10,0+10,z,(void *)font,"L");
	renderBitmapString(0+10,0+10,0,(void *)font,"O");
}
//-------------------------------------------------------------------------------------------------- 
void draw_rast_8(float x, float y, float z)
{
	glLineWidth (2.0);
	glBegin(GL_LINES);	

	glColor3f(1.0,0.0,1.0);
	glVertex3f(-x,-y, z);
	glVertex3f(x, y, 0);
	
	glVertex3f(-x,-y, -z);
	glVertex3f(x, y, 0);
	
	glVertex3f(-x,-y, z);
	glVertex3f(-x,-y, -z);
	
	glVertex3f(x, y, 0);
	glVertex3f(x, -y, 0);
	
	glVertex3f(x, -y, 0);
	glVertex3f(-x, -y, 0);
	
	glVertex3f(x, y, 0);
	glVertex3f(-x, -y, 0);
	
	glEnd() ;
	
	glPointSize(5.0);	
	glBegin(GL_POINTS);			
	glColor3f(0.0,1.0,0.0);
	glVertex3f(x, y, 0);
	glVertex3f(x, -y, 0);
	glVertex3f(-x, -y, 0);
	glEnd() ;
	renderBitmapString(x+10,y+10,0,(void *)font,"O1");
	renderBitmapString(x+10,-y+10,0,(void *)font,"O");
	renderBitmapString(-x+10,-y+10,0,(void *)font,"N");
}
//-------------------------------------------------------------------------------------------------- 
void draw_rast_9(float x, float y, float z)
{
	glLineWidth (2.0);
	glBegin(GL_LINES);	

	glColor3f(1.0,0.0,1.0);
	glVertex3f(-x,-y, z);
	glVertex3f(-x, y, z);
	
	glVertex3f(-x, y, z);
	glVertex3f(x, y, -z);
	
	glVertex3f(x, y, -z);
	glVertex3f(x, -y, -z);
	
	glVertex3f(x, -y, -z);
	glVertex3f(-x, -y, z);	
	
	glVertex3f(x, -y, z);
	glVertex3f(0, -y, 0);
	
	glVertex3f(0, 0, 0);
	glVertex3f(x, -y, z);
	
	glVertex3f(0, -y, 0);
	glVertex3f(0, y, 0);
	
	glEnd() ;
	
	glPointSize(5.0);	
	glBegin(GL_POINTS);			
	glColor3f(0.0,1.0,0.0);
	glVertex3f(0, 0, 0);
	glVertex3f(0, -y, 0);
	glEnd() ;
	renderBitmapString(0+10,0+10,0,(void *)font,"O");
	renderBitmapString(0+10,-y+10,0,(void *)font,"O1");
}
//-------------------------------------------------------------------------------------------------- 
void  ogl_draw(void)
{	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//draw_title(-1.6,1.1);
	
	glLoadIdentity();
	setka (); 
	if (flag_func==1)
	{
	prim_1();
	prim_2();
	}
	if (flag_func==2)
	{
	prim_3();
	prim_4();
	}
	if (flag_func==3)
	{
	prim_5();
	prim_6();
	}
	if (flag_func==4)
	{
	prim_7();
	prim_8();
	}
	if (flag_func==5)
	{
	prim_9();
	prim_10();
	}
	if (flag_func==6)
	{
	prim_11();
	prim_12();
	}
	if (flag_func==7)
	{
	prim_13();
	prim_14();
	}
	if (flag_func==8)
	{
	prim_15();
	prim_16();
	}
	if (flag_func==9)
	{
	prim_17();
	prim_18();
	}
	if (flag_func==10)
	{
	prim_19();
	prim_20();
	}	
	prim_0();
	
	glRotatef(rcube_y,1.0,0.0,0.0);
	glRotatef(rcube_x,0.0,1.0,0.0);
	
	glColor3f(0.0,1.0,0.0);
	draw_cube(100.0, 100.0, 100.0);
	if (flag_func==1)
	{
	draw_tring(100.0, 100.0, 100.0);
	}
	if (flag_func==2)
	{
	draw_rast(100.0, 100.0, 100.0);
	}	
	if (flag_func==3)
	{
	draw_rast_2(100.0, 100.0, 100.0);
	}	
	if (flag_func==4)
	{
	draw_rast_3(100.0, 100.0, 100.0);
	}	
	if (flag_func==5)
	{
	draw_rast_4(100.0, 100.0, 100.0);
	}	
	if (flag_func==6)
	{
	draw_rast_5(100.0, 100.0, 100.0);
	}	
	if (flag_func==7)
	{
	draw_rast_6(100.0, 100.0, 100.0);
	}
	if (flag_func==8)
	{
	draw_rast_7(100.0, 100.0, 100.0);
	}
	if (flag_func==9)
	{
	draw_rast_8(100.0, 100.0, 100.0);
	}
	if (flag_func==10)
	{
	draw_rast_9(100.0, 100.0, 100.0);
	}
	
	glFlush();
	glutSwapBuffers();
	frame+=1;
}
//-------------------------------------------------------------------------------------------------- 
void keyPressed(unsigned char key,int x, int y)
{
	if ( key == 27 || key == 'q' || key == 'Q' )		
      exit ( 0 );  
}
//-------------------------------------------------------------------------------------------------- 
void keyboard_spec(int key, int x, int y)
{
   switch (key)
   {
    case GLUT_KEY_LEFT:
			rcube_x-=0.8;        
         break;
	case GLUT_KEY_RIGHT:
			rcube_x+=0.8;        
         break;
	case GLUT_KEY_UP: 	
			rcube_y+=0.8;       
         break;	
	case GLUT_KEY_DOWN: 	
			rcube_y-=0.8;       
         break;	
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
glutPostRedisplay();
}
//-------------------------------------------------------------------------------------------------- 
void ogl_timer(int timer)
{
	rcube+=0.5;
	glutPostRedisplay();
	glutTimerFunc(2, ogl_timer, 0);
}
//-------------------------------------------------------------------------------------------------- 
void ogl_timer_fps(int timer)
{
		fps= frame*1000 /  glutGet(GLUT_ELAPSED_TIME) ;
		sprintf(s,"FPS:%4.2f",fps);
		glutTimerFunc(50, ogl_timer_fps, 1);
}
//-------------------------------------------------------------------------------------------------- 
void ogl_idle(void)
{
	glutPostRedisplay();
}
//-------------------------------------------------------------------------------------------------- 
int main(int argc, char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(win_width,win_height);
	glutInitWindowPosition(window_x, window_x);
	
	window = glutCreateWindow("Math_develop_Alekseenko_Michael");
	ogl_init();
	init_texture_1();
	glutDisplayFunc(ogl_draw);
	
	glutTimerFunc(2, ogl_timer, 0);
	glutTimerFunc(2, ogl_timer_fps, 1);
	glutReshapeFunc(ogl_reshape);
	glutKeyboardFunc(keyPressed);
	glutSpecialFunc (keyboard_spec);
	
	glutMainLoop();
	return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
//#include <GL/glut.h>
#include <SDL/SDL.h>
#include <math.h>


#include "tools/texture.h"



#define SCREEN_CAPTION  "OpenGL with SDL : Stable"
#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 768
#define SCREEN_BPP    24
#define EVENT_FPS 1
#define EVENT_ANIM 2
#define REDRAW_TIME    10
#define FPS_TIME    1000
#define ANIM_TIME    20
const SDL_VideoInfo *VideoInfo;
const char * ICON="../data/icons/sdl.bmp";



SDL_Surface *screen;
GLuint VideoFlags;
GLuint VideoFlagsFullscreen;
GLboolean done = GL_TRUE;
SDL_Event event;
GLboolean fullscreen = GL_FALSE;
SDL_TimerID fps_timer;
SDL_TimerID anim_timer;
GLint frame_avr=0;
GLint frame_sec=0;
GLfloat fps_avr=0.0;
GLfloat fps=0.0;
char fps_str[70]="";
char Blend_str [70]="";
char caption[70]=SCREEN_CAPTION;
GLfloat tx=0.0;
GLfloat ty=0.0;
GLfloat tz=-15.0;
GLfloat sx=1.0;
GLfloat sy=1.0;
GLfloat sz=1.0;
GLfloat rx=0.0;
GLfloat ry=0.0;
GLfloat rz=0.0;
GLfloat angle=0.0;
GLUquadricObj *quadric;
GLuint tex_01;
GLuint tex_02;
GLuint tex_03;
GLuint tex_04;
GLuint tex_05;
GLint blend_func = 0;
GLuint tex_06;
GLuint tex_07;
GLuint tex_08;
GLuint tex_09;
GLuint tex_10;
GLuint tex_12;
GLuint tex_13;
GLuint tex_14;
GLuint tex_15;
GLuint tex_16;
GLuint tex_17;
GLuint tex_18;
GLuint tex_19;
GLuint tex_20;
GLuint tex_21;
GLuint tex_22;
GLuint tex_23;
GLuint tex_24;
GLuint tex_25;
GLuint tex_26;



GLint b;
GLint scena_draw=0;


GLuint help_r_tex,help_l_tex, title_tex;
GLuint load_tex, load_0_tex, load_1_tex, load_2_tex, load_3_tex, load_4_tex, load_5_tex;
GLuint tex_obl_face_1,tex_obl_torec_1, tex_obl_back;
GLint book_state;


GLboolean rotate_page_right=GL_FALSE;
GLboolean rotate_page_left=GL_FALSE;
GLfloat rqxr1,rqyr1,rqxr2,rqyr2;
GLfloat lqxr0,lqyr0,lqxr3,lqyr3;
GLfloat rqx0,rqy0,rqx1,rqy1,rqx2,rqy2,rqx3,rqy3;
GLfloat lqx0,lqy0,lqx1,lqy1,lqx2,lqy2,lqx3,lqy3;
GLfloat lqxr1,lqyr1,lqxr2,lqyr2;
GLfloat alfa_left=0;
GLfloat alfa_right=0;
GLfloat delta_tx_left=0.0;
GLfloat delta_tx_right=0.0;
GLfloat delta_angle=0.5;
GLfloat scena0_tx;
GLfloat scena1_tx;
GLfloat scena2_tx;
GLfloat scena3_tx;
GLfloat scena4_tx;
GLfloat scena5_tx;
GLfloat scena6_tx;
GLfloat scena7_tx;
GLfloat scena8_tx;





GLfloat angle_book;
GLfloat oblojka_z0, oblojka_z1, pages_left_z0, pages_left_z1, pages_right_z0, pages_right_z1, page_book_z0, page_book_z1;

GLuint anim_timer_callback(GLuint interval, GLvoid *param)
{
//SDL_Event user_event_1;
event.type = SDL_USEREVENT;
event.user.code = EVENT_ANIM;
event.user.data1 = NULL;
event.user.data2 = NULL;
SDL_PushEvent(&event);
return interval;
}




GLuint fps_timer_callback(GLuint interval, GLvoid *param)
{
//SDL_Event user_event_1;
event.type = SDL_USEREVENT;
event.user.code = EVENT_FPS;
event.user.data1 = NULL;
event.user.data2 = NULL;
SDL_PushEvent(&event);
return interval;
}




/*GLvoid fps_counter(void)
{
	
	fps_avr=frame_avr*1000/SDL_GetTicks();
	fps=frame_sec*1.0;
	frame_sec=0;
	sprintf(caption,"%s  FPS_avr : %5.2f  FPS_sec : %5.2f" , SCREEN_CAPTION, fps_avr,fps);
	SDL_WM_SetCaption(caption,NULL);
}*/




GLvoid anim_proc( void)
{  
	angle=angle-0.6;
	
	if (rotate_page_right == GL_TRUE)
	{			
			alfa_right=alfa_right+0.5;	
			scena0_tx=scena0_tx + 1.0/(180.0/0.5);		
	        delta_tx_right=delta_tx_right+0.04/(180.0/0.5);
	        scena7_tx=scena7_tx + 1.0/(180.0/0.5);	
	if (alfa_right >= 180 ) 
		{
		rotate_page_right=GL_FALSE;
		alfa_right=0;
		delta_tx_right=0;
		if (scena_draw != 8)
		scena_draw=scena_draw+1;	
		scena0_tx=-1;
		scena7_tx=0;
	
		
	}	
	}	
	
	if (rotate_page_left == GL_TRUE)
	{	
		alfa_left=alfa_left+0.5;
		//scena0_tx=scena0_tx - 1.0/(180.0/0.5);	
	    delta_tx_left=delta_tx_left+0.04/(180.0/0.5);
	    scena1_tx=scena1_tx -  1.0/(180.0/0.5);	
	    scena8_tx=scena8_tx - 1.0/(180.0/0.5);	
	
	if (alfa_left >= 180 ) 
		{
		rotate_page_left=GL_FALSE;
		alfa_left=0;
		delta_tx_left=0;
		if (scena_draw != 0)
		scena_draw=scena_draw-1;
		scena0_tx=-1;	
		scena1_tx=0;
		scena8_tx=1;
		
	}
    }
}







GLvoid Quit( GLint returnCode )
{  
	SDL_RemoveTimer(anim_timer);
	SDL_RemoveTimer(fps_timer);
	SDL_Quit( );  
	exit( returnCode );
}








GLvoid ogl_init(  )
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClearDepth(1.0);
	glShadeModel(GL_SMOOTH);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc( GL_LEQUAL );
	glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST );

	/////////////////////////////////////////////////////////////////////////////////////////////
	rqx0=0.0; rqy0=-1.0;	rqx1=2.0; rqy1=-1.0; rqx2=2.0; rqy2=1.0; rqx3=0.0; rqy3=1.0; 
	rqxr1=1.0; rqyr1=-1.0; rqxr2=1.0; rqyr2=1.0;
	
	lqx0=-2.0; lqy0=-1.0;	lqx1=0.0; lqy1=-1.0; lqx2=0.0; lqy2=1.0; lqx3=-2.0; lqy3=1.0; 
	lqxr1=1.0; lqyr1=-1.0; lqxr2=1.0; lqyr2=1.0;
	oblojka_z0=0.0; oblojka_z1=-0.02, pages_left_z0=0.0; pages_left_z1=-0.001; pages_right_z0=0.0; pages_right_z1=-0.001, page_book_z0=0.0; page_book_z1=0.0005;
	scena0_tx=-1;
	scena1_tx=0;
	scena2_tx=0;
	scena3_tx=0;
	scena4_tx=0;
	scena5_tx=0;
	scena6_tx=0;
	scena7_tx=0;
	scena8_tx=1;
	angle_book=-10;
	OGL_Load_Texture("../data/textures/load/load.bmp", &load_tex, txTrilinear, GL_MODULATE, GL_REPEAT, txNoCompressed,GL_TRUE);
	OGL_Load_Texture("../data/textures/load/load_0.bmp", &load_0_tex, txTrilinear, GL_MODULATE, GL_REPEAT, txNoCompressed,GL_TRUE);
	OGL_Load_Texture("../data/textures/load/load_1.bmp", &load_1_tex, txTrilinear, GL_MODULATE, GL_REPEAT, txNoCompressed,GL_TRUE);
	OGL_Load_Texture("../data/textures/load/load_2.bmp", &load_2_tex, txTrilinear, GL_MODULATE, GL_REPEAT, txNoCompressed,GL_TRUE);
	OGL_Load_Texture("../data/textures/load/load_3.bmp", &load_3_tex, txTrilinear, GL_MODULATE, GL_REPEAT, txNoCompressed,GL_TRUE);
	OGL_Load_Texture("../data/textures/load/load_4.bmp", &load_4_tex, txTrilinear, GL_MODULATE, GL_REPEAT, txNoCompressed,GL_TRUE);
	OGL_Load_Texture("../data/textures/load/load_5.bmp", &load_5_tex, txTrilinear, GL_MODULATE, GL_REPEAT, txNoCompressed,GL_TRUE);
}


void  load_draw(GLfloat size_x,GLfloat size_y)
{

	glBegin(GL_QUADS);
		glTexCoord2f(0.0,0.0);glColor3ub(255,255,255);glVertex3f(-1.0*size_x,-1.0*size_y, 0.0);			
		glTexCoord2f(1.0,0.0);glColor3ub(255,255,255);glVertex3f( 1.0*size_x,-1.0*size_y, 0.0);	 		
		glTexCoord2f(1.0,1.0);glColor3ub(255,255,255);glVertex3f( 1.0*size_x, 1.0*size_y, 0.0);
		glTexCoord2f(0.0,1.0);glColor3ub(255,255,255);glVertex3f(-1.0*size_x, 1.0*size_y, 0.0);		
   	glEnd();
}

GLvoid splash_draw(GLuint texture1,GLuint texture2)
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();	
	glEnable(GL_TEXTURE_2D);	
    glBindTexture(GL_TEXTURE_2D, texture1);	
    glPushMatrix();
    glTranslatef(0.0,0.0,0.0);
     load_draw(0.2,0.10);
    glPopMatrix();	
    
    glBindTexture(GL_TEXTURE_2D, texture2);	
    glTranslatef(0.0,-0.2,0.0);
    glPushMatrix();
     load_draw(0.3,0.1);
    glPopMatrix();
    SDL_GL_SwapBuffers( );
}

GLvoid load_textures()

{

	splash_draw(load_tex, load_0_tex);
	SDL_Delay(1000 );
	OGL_Load_Texture("../data/textures/left.bmp", &tex_01, txTrilinear, GL_MODULATE, GL_CLAMP, txNoCompressed,GL_TRUE);
	OGL_Load_Texture("../data/textures/right.bmp", &tex_02, txTrilinear, GL_MODULATE, GL_REPEAT, txNoCompressed,GL_TRUE);
	OGL_Load_Texture("../data/textures/scena0/fon.bmp", &tex_26, txTrilinear, GL_MODULATE, GL_REPEAT, txNoCompressed,GL_TRUE);
	splash_draw(load_tex, load_1_tex);
	SDL_Delay(1000 );
	OGL_Load_Texture("../data/textures/scena1/page1.1.bmp", &tex_13, txTrilinear, GL_MODULATE, GL_REPEAT, txNoCompressed,GL_TRUE);
	OGL_Load_Texture("../data/textures/scena2/page2.1.bmp", &tex_14, txTrilinear, GL_MODULATE, GL_REPEAT, txNoCompressed,GL_TRUE);
	OGL_Load_Texture("../data/textures/scena2/page3.1.bmp", &tex_15, txTrilinear, GL_MODULATE, GL_REPEAT, txNoCompressed,GL_TRUE);
	splash_draw(load_tex, load_2_tex);
	SDL_Delay(1000 );
	OGL_Load_Texture("../data/textures/scena3/page4.1.bmp", &tex_16, txTrilinear, GL_MODULATE, GL_REPEAT, txNoCompressed,GL_TRUE);
	OGL_Load_Texture("../data/textures/scena3/page5.1.bmp", &tex_17, txTrilinear, GL_MODULATE, GL_REPEAT, txNoCompressed,GL_TRUE);
	OGL_Load_Texture("../data/textures/scena4/page6.1.bmp", &tex_23, txTrilinear, GL_MODULATE, GL_REPEAT, txNoCompressed,GL_TRUE);
	OGL_Load_Texture("../data/textures/scena4/page7.1.bmp", &tex_24, txTrilinear, GL_MODULATE, GL_REPEAT, txNoCompressed,GL_TRUE);
	splash_draw(load_tex, load_3_tex);
	SDL_Delay(1000 );
	OGL_Load_Texture("../data/textures/scena5/page8.1.bmp", &tex_20, txTrilinear, GL_MODULATE, GL_REPEAT, txNoCompressed,GL_TRUE);
	OGL_Load_Texture("../data/textures/scena5/page9.1.bmp", &tex_21, txTrilinear, GL_MODULATE, GL_REPEAT, txNoCompressed,GL_TRUE);	
	OGL_Load_Texture("../data/textures/scena6/page11.1.bmp", &tex_19, txTrilinear, GL_MODULATE, GL_REPEAT, txNoCompressed,GL_TRUE);
	splash_draw(load_tex, load_4_tex);
	SDL_Delay(1000 );
	OGL_Load_Texture("../data/textures/scena6/page10.1.bmp", &tex_18, txTrilinear, GL_MODULATE, GL_REPEAT, txNoCompressed,GL_TRUE);
	 OGL_Load_Texture("../data/textures/scena7/page12.1.bmp", &tex_22, txTrilinear, GL_MODULATE, GL_REPEAT, txNoCompressed,GL_TRUE);
	OGL_Load_Texture("../data/textures/scena8/oblojka_2_back.bmp", &tex_25, txTrilinear, GL_MODULATE, GL_REPEAT, txNoCompressed,GL_TRUE);
	OGL_Load_Texture("../data/textures/oblojka_1_face.bmp", &tex_obl_face_1, txTrilinear, GL_MODULATE, GL_CLAMP, txNoCompressed,GL_TRUE);
	OGL_Load_Texture("../data/textures/oblojka_1_back.bmp", &tex_obl_back, txTrilinear, GL_MODULATE, GL_CLAMP, txNoCompressed,GL_TRUE);
	splash_draw(load_tex, load_5_tex);
	SDL_Delay(1000 );
	OGL_Load_Texture("../data/textures/torec.bmp", &tex_obl_torec_1, txTrilinear, GL_MODULATE, GL_REPEAT, txNoCompressed,GL_TRUE);
	OGL_Load_Texture("../data/textures/help_r.bmp", &help_r_tex, txTrilinear, GL_MODULATE, GL_REPEAT, txNoCompressed,GL_TRUE);
	OGL_Load_Texture("../data/textures/help_l.bmp", &help_l_tex, txTrilinear, GL_MODULATE, GL_REPEAT, txNoCompressed,GL_TRUE);
	OGL_Load_Texture("../data/textures/title.bmp", &title_tex, txTrilinear, GL_MODULATE, GL_REPEAT, txNoCompressed,GL_TRUE);
}




GLvoid ogl_reshape(GLint width, GLint height)
{
	if (height == 0)
		height = 1;
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, ((GLfloat) width) /((GLfloat) height) , 1.0, 100.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
}


/////////////////DRAW/////////////////////



void  quads_draw(void)
{
	glBegin(GL_QUADS);
		/*glTexCoord2f(0.0,0.0);glColor3ub(255,255,255);glVertex3f(-1.0,-1.0, 0.0);			
		glTexCoord2f(1.0,0.0);glColor3ub(255,255,255);glVertex3f( 1.0,-1.0, 0.0);	 		
		glTexCoord2f(1.0,1.0);glColor3ub(255,255,255);glVertex3f( 1.0, 1.0, 0.0);
		glTexCoord2f(0.0,1.0);glColor3ub(255,255,255);glVertex3f(-1.0, 1.0, 0.0);	*/
		
		glTexCoord2f(0.0,0.0);glColor3ub(255,255,255);glVertex3f( 2.0,-2.0, 0.0);			
		glTexCoord2f(1.0,0.0);glColor3ub(255,255,255);glVertex3f( 2.0,-2.0,-3.0);	 		
		glTexCoord2f(1.0,1.0);glColor3ub(255,255,255);glVertex3f( 2.0, 2.0, 0.0);
		glTexCoord2f(0.0,1.0);glColor3ub(255,255,255);glVertex3f( 2.0, 2.0,-3.0);	
		
		glTexCoord2f(0.0,0.0);glColor3ub(255,255,255);glVertex3f(-2.0,-2.0,-3.0);			
		glTexCoord2f(1.0,0.0);glColor3ub(255,255,255);glVertex3f( 2.0,-2.0,-3.0);	 		
		glTexCoord2f(1.0,1.0);glColor3ub(255,255,255);glVertex3f( 2.0, 2.0,-3.0);
		glTexCoord2f(0.0,1.0);glColor3ub(255,255,255);glVertex3f(-2.0, 2.0,-3.0);
		
		glTexCoord2f(0.0,0.0);glColor3ub(255,255,255);glVertex3f(-2.0,-2.0, 0.0);			
		glTexCoord2f(1.0,0.0);glColor3ub(255,255,255);glVertex3f(-2.0,-2.0,-3.0);	 		
		glTexCoord2f(1.0,1.0);glColor3ub(255,255,255);glVertex3f(-2.0, 2.0, 0.0);
		glTexCoord2f(0.0,1.0);glColor3ub(255,255,255);glVertex3f(-2.0, 2.0,-3.0);
		
		glTexCoord2f(0.0,0.0);glColor3ub(255,255,255);glVertex3f(-2.0, 2.0, 0.0);			
		glTexCoord2f(1.0,0.0);glColor3ub(255,255,255);glVertex3f(-2.0, 2.0,-3.0);	 		
		glTexCoord2f(1.0,1.0);glColor3ub(255,255,255);glVertex3f( 2.0, 2.0, 0.0);
		glTexCoord2f(0.0,1.0);glColor3ub(255,255,255);glVertex3f( 2.0, 2.0,-3.0);
		
		glTexCoord2f(0.0,0.0);glColor3ub(255,255,255);glVertex3f(-2.0,-2.0, 0.0);			
		glTexCoord2f(1.0,0.0);glColor3ub(255,255,255);glVertex3f(-2.0,-2.0,-3.0);	 		
		glTexCoord2f(1.0,1.0);glColor3ub(255,255,255);glVertex3f( 2.0,-2.0, 0.0);
		glTexCoord2f(0.0,1.0);glColor3ub(255,255,255);glVertex3f( 2.0,-2.0,-3.0);			
		
			
   	glEnd();
}

////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////


void oblojka_draw(GLfloat x0, GLfloat y0, GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLfloat x3, GLfloat y3, GLfloat z0,  GLfloat z1, GLuint face, GLuint back, GLuint torec)
//void oblojka_draw(GLfloat x0,  GLfloat y0,  GLfloat x1,  GLfloat y1,  GLfloat x2,  GLfloat y2,  GLfloat x3,  GLfloat y3, GLfloat  z0,   GLfloat z1, GLuint face, GLuint back, GLuint torec)
{
	glEnable(GL_TEXTURE_2D);	
    glBindTexture(GL_TEXTURE_2D, back);		
	//back
	
	glBegin(GL_QUADS);   
		glTexCoord2f(1.0,0.0);glColor3ub(255,255,255);glVertex3f( x0*0.78,y0, z1);
		glTexCoord2f(0.0,0.0);glColor3ub(255,255,255);glVertex3f(x1*0.78,y1, z1);	
		glTexCoord2f(0.0,1.0);glColor3ub(255,255,255);glVertex3f(x2*0.78, y2, z1);			 		
		glTexCoord2f(1.0,1.0);glColor3ub(255,255,255);glVertex3f( x3*0.78, y3, z1);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, torec); 
	//left
	glBegin(GL_QUADS);   
		glTexCoord2f(0.0,0.0);glColor3ub(255,255,255);glVertex3f(x0*0.78,y0, z1);	
		glTexCoord2f(1.0,0.0);glColor3ub(255,255,255);glVertex3f(x0*0.78,y0, z0);	
		glTexCoord2f(1.0,1.0);glColor3ub(255,255,255);glVertex3f(x3*0.78, y3, z0);
		glTexCoord2f(0.0,1.0);glColor3ub(255,255,255);glVertex3f(x3*0.78, y3, z1);	
	glEnd();
	
	glBindTexture(GL_TEXTURE_2D, torec); 
	//right
	glBegin(GL_QUADS);   
		glTexCoord2f(0.0,0.0);glColor3ub(255,255,255);glVertex3f( x1*0.78,y1,z1);
		glTexCoord2f(1.0,0.0);glColor3ub(255,255,255);glVertex3f( x1*0.78,y1, z0);	 
		glTexCoord2f(1.0,1.0);glColor3ub(255,255,255);glVertex3f( x2*0.78, y2, z0);
		glTexCoord2f(0.0,1.0);glColor3ub(255,255,255);glVertex3f(x2*0.78, y2, z1);			
	 glEnd();  
	
	
	glBindTexture(GL_TEXTURE_2D, torec); 
	//top
	glBegin(GL_QUADS);
		glTexCoord2f(0.0,0.0);glColor3ub(255,255,255);glVertex3f(x3*0.78, y3, z0);
		glTexCoord2f(1.0,0.0);glColor3ub(255,255,255);glVertex3f( x2*0.78, y2, z0);
		glTexCoord2f(1.0,1.0);glColor3ub(255,255,255);glVertex3f( x2*0.78, y2, z1);	
		glTexCoord2f(0.0,1.0);glColor3ub(255,255,255);glVertex3f(x3*0.78, y3, z1);			 		
	 glEnd();
	
	glBindTexture(GL_TEXTURE_2D, torec); 	
	//butom	
	glBegin(GL_QUADS);
		glTexCoord2f(0.0,0.0);glColor3ub(255,255,255);glVertex3f(x0*0.78,y0, z1);	
		glTexCoord2f(1.0,0.0);glColor3ub(255,255,255);glVertex3f( x1*0.78,y1, z1);
		glTexCoord2f(1.0,1.0);glColor3ub(255,255,255);glVertex3f( x1*0.78,y1, z0);	
		glTexCoord2f(0.0,1.0);glColor3ub(255,255,255);glVertex3f(x0*0.78,y0, z0);		
	glEnd();
	
	glBindTexture(GL_TEXTURE_2D, face);
	//face
	glBegin(GL_QUADS);
		glTexCoord2f(0.0,0.0);glColor3ub(255,255,255);glVertex3f(x0*0.78,y0, z0);			
		glTexCoord2f(1.0,0.0);glColor3ub(255,255,255);glVertex3f( x1*0.78,y1, z0);	 		
		glTexCoord2f(1.0,1.0);glColor3ub(255,255,255);glVertex3f( x2*0.78, y2, z0);
		glTexCoord2f(0.0,1.0);glColor3ub(255,255,255);glVertex3f(x3*0.78, y3, z0);	
	glEnd();	
	
	 glDisable(GL_TEXTURE_2D); 	
   
}


////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////




void page_draw(GLfloat x0, GLfloat y0, GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLfloat x3, GLfloat y3, GLfloat z0,  GLfloat z1, GLuint face, GLuint back, GLuint torec)
//void oblojka_draw(GLfloat x0,  GLfloat y0,  GLfloat x1,  GLfloat y1,  GLfloat x2,  GLfloat y2,  GLfloat x3,  GLfloat y3, GLfloat  z0,   GLfloat z1, GLuint face, GLuint back, GLuint torec)
{
	glEnable(GL_TEXTURE_2D);	
    glBindTexture(GL_TEXTURE_2D, back);		
	//back
	
	glBegin(GL_QUADS);   
		glTexCoord2f(1.0,0.0);glColor3ub(255,255,255);glVertex3f( x0*0.76,y0*0.98, z1);
		glTexCoord2f(0.0,0.0);glColor3ub(255,255,255);glVertex3f(x1*0.76,y1*0.98, z1);	
		glTexCoord2f(0.0,1.0);glColor3ub(255,255,255);glVertex3f(x2*0.76, y2*0.98, z1);			 		
		glTexCoord2f(1.0,1.0);glColor3ub(255,255,255);glVertex3f( x3*0.76, y3*0.98, z1);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, torec); 
	//left
	glBegin(GL_QUADS);   
		glTexCoord2f(0.0,0.0);glColor3ub(255,255,255);glVertex3f(x0*0.76,y0*0.98, z1);	
		glTexCoord2f(1.0,0.0);glColor3ub(255,255,255);glVertex3f(x0*0.76,y0*0.98, z0);	
		glTexCoord2f(1.0,1.0);glColor3ub(255,255,255);glVertex3f(x3*0.76, y3*0.98, z0);
		glTexCoord2f(0.0,1.0);glColor3ub(255,255,255);glVertex3f(x3*0.76, y3*0.98, z1);	
	glEnd();
	
	glBindTexture(GL_TEXTURE_2D, torec); 
	//right
	glBegin(GL_QUADS);   
		glTexCoord2f(0.0,0.0);glColor3ub(255,255,255);glVertex3f( x1*0.76,y1*0.98,z1);
		glTexCoord2f(1.0,0.0);glColor3ub(255,255,255);glVertex3f( x1*0.76,y1*0.98, z0);	 
		glTexCoord2f(1.0,1.0);glColor3ub(255,255,255);glVertex3f( x2*0.76, y2*0.98, z0);
		glTexCoord2f(0.0,1.0);glColor3ub(255,255,255);glVertex3f(x2*0.76, y2*0.98, z1);			
	 glEnd();  
	
	
	glBindTexture(GL_TEXTURE_2D, torec); 
	//top
	glBegin(GL_QUADS);
		glTexCoord2f(0.0,0.0);glColor3ub(255,255,255);glVertex3f(x3*0.76, y3*0.98, z0);
		glTexCoord2f(1.0,0.0);glColor3ub(255,255,255);glVertex3f( x2*0.76, y2*0.98, z0);
		glTexCoord2f(1.0,1.0);glColor3ub(255,255,255);glVertex3f( x2*0.76, y2*0.98, z1);	
		glTexCoord2f(0.0,1.0);glColor3ub(255,255,255);glVertex3f(x3*0.76, y3*0.98, z1);			 		
	 glEnd();
	
	glBindTexture(GL_TEXTURE_2D, torec); 	
	//butom	
	glBegin(GL_QUADS);
		glTexCoord2f(0.0,0.0);glColor3ub(255,255,255);glVertex3f(x0*0.76,y0*0.98, z1);	
		glTexCoord2f(1.0,0.0);glColor3ub(255,255,255);glVertex3f( x1*0.76,y1*0.98, z1);
		glTexCoord2f(1.0,1.0);glColor3ub(255,255,255);glVertex3f( x1*0.76,y1*0.98, z0);	
		glTexCoord2f(0.0,1.0);glColor3ub(255,255,255);glVertex3f(x0*0.76,y0*0.98, z0);		
	glEnd();
	
	glBindTexture(GL_TEXTURE_2D, face);
	//face
	glBegin(GL_QUADS);
		glTexCoord2f(0.0,0.0);glColor3ub(255,255,255);glVertex3f(x0*0.76,y0*0.98, z0);			
		glTexCoord2f(1.0,0.0);glColor3ub(255,255,255);glVertex3f( x1*0.76,y1*0.98, z0);	 		
		glTexCoord2f(1.0,1.0);glColor3ub(255,255,255);glVertex3f( x2*0.76, y2*0.98, z0);
		glTexCoord2f(0.0,1.0);glColor3ub(255,255,255);glVertex3f(x3*0.76, y3*0.98, z0);	
	glEnd();	
	
	 glDisable(GL_TEXTURE_2D); 	
   
}

////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////


void  scena0(void)
{
   
  if (rotate_page_right ==GL_TRUE)
  {
	glPushMatrix();
	glTranslatef(scena0_tx,0.0,-1.49);
	glRotatef(angle_book, 1.0,0.0,0.0);
    glRotatef(-alfa_right,0.0,1.0,0.0);		
	oblojka_draw(rqx0,rqy0,rqx1,rqy1,rqx2,rqy2,rqx3,rqy3,oblojka_z0,oblojka_z1, tex_obl_face_1, tex_obl_back, tex_obl_torec_1);
	glPopMatrix();	
	
	glPushMatrix();
	glTranslatef(scena0_tx+0.02,0.0,-1.491);
	glRotatef(angle_book, 1.0,0.0,0.0);
   	page_draw(rqx0,rqy0,rqx1,rqy1,rqx2,rqy2,rqx3,rqy3,pages_left_z0,pages_left_z1, tex_13, tex_13, tex_13);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(scena0_tx,0.0,-1.492);
	glRotatef(angle_book, 1.0,0.0,0.0);
   // glRotatef(-alfa_right,0.0,1.0,0.0);		
	oblojka_draw(rqx0,rqy0,rqx1,rqy1,rqx2,rqy2,rqx3,rqy3,oblojka_z0,oblojka_z1, tex_obl_back, tex_obl_face_1, tex_obl_torec_1);
	glPopMatrix();
	
	}
else	

		{
			glPushMatrix();
			glTranslatef(scena0_tx,0.0,-1.49);
			glRotatef(angle_book, 1.0,0.0,0.0);    	
			oblojka_draw(rqx0,rqy0,rqx1,rqy1,rqx2,rqy2,rqx3,rqy3,oblojka_z0,oblojka_z1, tex_obl_face_1, tex_obl_back, tex_obl_torec_1);
			glPopMatrix();
			
				glPushMatrix();
			glTranslatef(scena0_tx-0.02,0.0,-1.49);
			glRotatef(angle_book, 1.0,0.0,0.0);
			//glRotatef(-alfa_right,0.0,1.0,0.0);		
		//	oblojka_draw(rqx0,rqy0,rqx1,rqy1,rqx2,rqy2,rqx3,rqy3,oblojka_z0,oblojka_z1, tex_obl_back, tex_obl_face_1, tex_obl_torec_1);
			glPopMatrix();
	
			}

	
	/*
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, tex_03);
	glPushMatrix();
	glTranslatef(scena0_tx+0.02,0.0,-1.48);
	glRotatef(angle_book, 1.0,0.0,0.0);
    //glRotatef(alfa_right,0.0,1.0,0.0);		
	page_draw(rqx0,rqy0,rqx1,rqy1,rqx2,rqy2,rqx3,rqy3,pages_left_z0,pages_left_z1, tex_13, tex_13, tex_13);
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);*/
      		
}

          
       
void  scena1(void)
 {

	
	if (rotate_page_right ==GL_TRUE)
  {
	glPushMatrix();
	glTranslatef(scena1_tx,0.0,-1.49);
	glRotatef(angle_book, 1.0,0.0,0.0);  	
	oblojka_draw(rqx0,rqy0,rqx1,rqy1,rqx2,rqy2,rqx3,rqy3,oblojka_z0,oblojka_z1, tex_obl_back, tex_obl_face_1, tex_obl_torec_1);
	glPopMatrix();
 	
 	
 	glPushMatrix();
	glTranslatef(scena1_tx,0.0,-1.49);
	glRotatef(angle_book, 1.0,0.0,0.0);
    oblojka_draw(lqx0,lqy0,lqx1,lqy1,lqx2,lqy2,lqx3,lqy3,oblojka_z0,oblojka_z1, tex_obl_back, tex_obl_face_1, tex_obl_torec_1);
	glPopMatrix(); 	
 	
	glPushMatrix();
	glTranslatef(scena1_tx+0.02-delta_tx_right,0.0,-1.4788);
	glRotatef(angle_book, 1.0,0.0,0.0);
    glRotatef(-alfa_right,0.0,1.0,0.0);		
	page_draw(rqx0,rqy0,rqx1,rqy1,rqx2,rqy2,rqx3,rqy3,pages_right_z0,pages_right_z1, tex_13, tex_14, tex_13);
	
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(scena2_tx+0.02,0.0,-1.48);
	glRotatef(angle_book, 1.0,0.0,0.0);
    //glRotatef(-alfa_right,0.0,1.0,0.0);		
	page_draw(rqx0,rqy0,rqx1,rqy1,rqx2,rqy2,rqx3,rqy3,pages_right_z0,pages_right_z1, tex_15, tex_15, tex_15);
	glPopMatrix();
	

}
else	
	{
	 if (rotate_page_left ==GL_TRUE)
  {
	glPushMatrix();
	glTranslatef(scena1_tx,0.0,-1.49);
	glRotatef(angle_book, 1.0,0.0,0.0);
   // glRotatef(-alfa_right,0.0,1.0,0.0);		
	oblojka_draw(rqx0,rqy0,rqx1,rqy1,rqx2,rqy2,rqx3,rqy3,oblojka_z0,oblojka_z1, tex_obl_back, tex_obl_face_1, tex_obl_torec_1);
	glPopMatrix();
 	
 	
 	glPushMatrix();
	glTranslatef(scena1_tx,0.0,-1.49);
	glRotatef(angle_book, 1.0,0.0,0.0);
    glRotatef(alfa_left,0.0,1.0,0.0);		
	oblojka_draw(lqx0,lqy0,lqx1,lqy1,lqx2,lqy2,lqx3,lqy3,oblojka_z0,oblojka_z1, tex_obl_back, tex_obl_face_1, tex_obl_torec_1);
	glPopMatrix(); 	
 	
	glPushMatrix();
	glTranslatef(scena1_tx+0.02,0.0,-1.48);
	glRotatef(angle_book, 1.0,0.0,0.0);
    //glRotatef(-alfa_right,0.0,1.0,0.0);		
	page_draw(rqx0,rqy0,rqx1,rqy1,rqx2,rqy2,rqx3,rqy3,pages_right_z0,pages_right_z1, tex_13, tex_13, tex_13);
	glPopMatrix();

	
	
	}
	else
	{
	glPushMatrix();
	glTranslatef(scena1_tx,0.0,-1.49);
	glRotatef(angle_book, 1.0,0.0,0.0);
   // glRotatef(-alfa_right,0.0,1.0,0.0);		
	oblojka_draw(rqx0,rqy0,rqx1,rqy1,rqx2,rqy2,rqx3,rqy3,oblojka_z0,oblojka_z1, tex_obl_back, tex_obl_face_1, tex_obl_torec_1);
	glPopMatrix();
 	
 	
 	glPushMatrix();
	glTranslatef(scena1_tx,0.0,-1.49);
	glRotatef(angle_book, 1.0,0.0,0.0);
    //glRotatef(-alfa_right,0.0,1.0,0.0);		
	oblojka_draw(lqx0,lqy0,lqx1,lqy1,lqx2,lqy2,lqx3,lqy3,oblojka_z0,oblojka_z1, tex_obl_back, tex_obl_face_1, tex_obl_torec_1);
	glPopMatrix(); 	
 	
	glPushMatrix();
	glTranslatef(scena1_tx+0.02,0.0,-1.48);
	glRotatef(angle_book, 1.0,0.0,0.0);
    //glRotatef(-alfa_right,0.0,1.0,0.0);		
	page_draw(rqx0,rqy0,rqx1,rqy1,rqx2,rqy2,rqx3,rqy3,pages_right_z0,pages_right_z1, tex_13, tex_13, tex_13);
	glPopMatrix();
}
}	
 }


void  scena2(void)

 {
 	if (rotate_page_right ==GL_TRUE)
 	{
 	
 	glPushMatrix();
	glTranslatef(scena2_tx,0.0,-1.49);
	glRotatef(angle_book, 1.0,0.0,0.0);
    //glRotatef(-alfa_right,0.0,1.0,0.0);		
	oblojka_draw(lqx0,lqy0,lqx1,lqy1,lqx2,lqy2,lqx3,lqy3,oblojka_z0,oblojka_z1, tex_obl_back, tex_obl_face_1, tex_obl_torec_1);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(scena2_tx,0.0,-1.49);
	glRotatef(angle_book, 1.0,0.0,0.0);
   // glRotatef(-alfa_right,0.0,1.0,0.0);		
	oblojka_draw(rqx0,rqy0,rqx1,rqy1,rqx2,rqy2,rqx3,rqy3,oblojka_z0,oblojka_z1, tex_obl_back, tex_obl_face_1, tex_obl_torec_1);
	glPopMatrix();
	
 	
	glPushMatrix();
	glTranslatef(scena2_tx+0.02-delta_tx_right,0.0,-1.4788);
	glRotatef(angle_book, 1.0,0.0,0.0);
    glRotatef(-alfa_right,0.0,1.0,0.0);		
	page_draw(rqx0,rqy0,rqx1,rqy1,rqx2,rqy2,rqx3,rqy3,pages_right_z0,pages_right_z1, tex_15, tex_16, tex_15);
	glPopMatrix();
	
	
	
	glPushMatrix();
	glTranslatef(scena2_tx-0.02,0.0,-1.48);
	glRotatef(angle_book, 1.0,0.0,0.0);
    //glRotatef(-alfa_right,0.0,1.0,0.0);		
	page_draw(lqx0,lqy0,lqx1,lqy1,lqx2,lqy2,lqx3,lqy3,pages_left_z0,pages_left_z1, tex_14, tex_14, tex_14);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(scena2_tx+0.02,0.0,-1.48);
	glRotatef(angle_book, 1.0,0.0,0.0);
    //glRotatef(-alfa_right,0.0,1.0,0.0);		
	page_draw(rqx0,rqy0,rqx1,rqy1,rqx2,rqy2,rqx3,rqy3,pages_right_z0,pages_right_z1, tex_17, tex_17, tex_17);
	glPopMatrix();
	
	
}

else
{
	if (rotate_page_left ==GL_TRUE)
	{
    glPushMatrix();
	glTranslatef(scena2_tx,0.0,-1.49);
	glRotatef(angle_book, 1.0,0.0,0.0);
    //glRotatef(-alfa_right,0.0,1.0,0.0);		
	oblojka_draw(lqx0,lqy0,lqx1,lqy1,lqx2,lqy2,lqx3,lqy3,oblojka_z0,oblojka_z1, tex_obl_back, tex_obl_face_1, tex_obl_torec_1);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(scena2_tx,0.0,-1.49);
	glRotatef(angle_book, 1.0,0.0,0.0);
   // glRotatef(-alfa_right,0.0,1.0,0.0);		
	oblojka_draw(rqx0,rqy0,rqx1,rqy1,rqx2,rqy2,rqx3,rqy3,oblojka_z0,oblojka_z1, tex_obl_back, tex_obl_face_1, tex_obl_torec_1);
	glPopMatrix();
	
 	
	glPushMatrix();
	glTranslatef(scena2_tx+0.02,0.0,-1.48);
	glRotatef(angle_book, 1.0,0.0,0.0);
    //glRotatef(-alfa_right,0.0,1.0,0.0);		
	page_draw(rqx0,rqy0,rqx1,rqy1,rqx2,rqy2,rqx3,rqy3,pages_right_z0,pages_right_z1, tex_15, tex_15, tex_15);
	glPopMatrix();
	
	
	glPushMatrix();
	glTranslatef(scena2_tx-0.02+delta_tx_left,0.0,-1.48);
	glRotatef(angle_book, 1.0,0.0,0.0);
    glRotatef(alfa_left,0.0,1.0,0.0);		
	page_draw(lqx0,lqy0,lqx1,lqy1,lqx2,lqy2,lqx3,lqy3,pages_left_z0,pages_left_z1, tex_14, tex_13, tex_14);
	glPopMatrix();
	
  }
  else
  {
  	
  	glPushMatrix();
	glTranslatef(scena2_tx,0.0,-1.49);
	glRotatef(angle_book, 1.0,0.0,0.0);
    //glRotatef(-alfa_right,0.0,1.0,0.0);		
	oblojka_draw(lqx0,lqy0,lqx1,lqy1,lqx2,lqy2,lqx3,lqy3,oblojka_z0,oblojka_z1, tex_obl_back, tex_obl_face_1, tex_obl_torec_1);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(scena2_tx,0.0,-1.49);
	glRotatef(angle_book, 1.0,0.0,0.0);
   // glRotatef(-alfa_right,0.0,1.0,0.0);		
	oblojka_draw(rqx0,rqy0,rqx1,rqy1,rqx2,rqy2,rqx3,rqy3,oblojka_z0,oblojka_z1, tex_obl_back, tex_obl_face_1, tex_obl_torec_1);
	glPopMatrix();
	
 	
	glPushMatrix();
	glTranslatef(scena2_tx+0.02,0.0,-1.48);
	glRotatef(angle_book, 1.0,0.0,0.0);
    //glRotatef(-alfa_right,0.0,1.0,0.0);		
	page_draw(rqx0,rqy0,rqx1,rqy1,rqx2,rqy2,rqx3,rqy3,pages_right_z0,pages_right_z1, tex_15, tex_15, tex_15);
	glPopMatrix();
	
	
	glPushMatrix();
	glTranslatef(scena2_tx-0.02,0.0,-1.48);
	glRotatef(angle_book, 1.0,0.0,0.0);
    //glRotatef(-alfa_right,0.0,1.0,0.0);		
	page_draw(lqx0,lqy0,lqx1,lqy1,lqx2,lqy2,lqx3,lqy3,pages_left_z0,pages_left_z1, tex_14, tex_14, tex_14);
	glPopMatrix();
}
  
}

 }
 
void  scena3(void)
 {
 	if (rotate_page_right ==GL_TRUE)
 	{
 	glPushMatrix();
	glTranslatef(scena3_tx,0.0,-1.49);
	glRotatef(angle_book, 1.0,0.0,0.0);
    //glRotatef(-alfa_right,0.0,1.0,0.0);		
	oblojka_draw(lqx0,lqy0,lqx1,lqy1,lqx2,lqy2,lqx3,lqy3,oblojka_z0,oblojka_z1, tex_obl_back, tex_obl_face_1, tex_obl_torec_1);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(scena3_tx,0.0,-1.49);
	glRotatef(angle_book, 1.0,0.0,0.0);
   // glRotatef(-alfa_right,0.0,1.0,0.0);		
	oblojka_draw(rqx0,rqy0,rqx1,rqy1,rqx2,rqy2,rqx3,rqy3,oblojka_z0,oblojka_z1, tex_obl_back, tex_obl_face_1, tex_obl_torec_1);
	glPopMatrix();
	
 	
	glPushMatrix();
	glTranslatef(scena3_tx+0.02-delta_tx_right,0.0,-1.4788);
	glRotatef(angle_book, 1.0,0.0,0.0);
    glRotatef(-alfa_right,0.0,1.0,0.0);		
	page_draw(rqx0,rqy0,rqx1,rqy1,rqx2,rqy2,rqx3,rqy3,pages_right_z0,pages_right_z1, tex_17, tex_24, tex_17);
	glPopMatrix();
	
	
	
	glPushMatrix();
	glTranslatef(scena3_tx-0.02,0.0,-1.48);
	glRotatef(angle_book, 1.0,0.0,0.0);
    //glRotatef(-alfa_right,0.0,1.0,0.0);		
	page_draw(lqx0,lqy0,lqx1,lqy1,lqx2,lqy2,lqx3,lqy3,pages_left_z0,pages_left_z1, tex_16, tex_16, tex_16);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(scena3_tx+0.02,0.0,-1.48);
	glRotatef(angle_book, 1.0,0.0,0.0);
   // glRotatef(-alfa_right,0.0,1.0,0.0);		
	page_draw(rqx0,rqy0,rqx1,rqy1,rqx2,rqy2,rqx3,rqy3,pages_right_z0,pages_right_z1, tex_23, tex_23, tex_23);
	glPopMatrix();
}
else
{
	if (rotate_page_left ==GL_TRUE)
	{
	glPushMatrix();
	glTranslatef(scena3_tx,0.0,-1.49);
	glRotatef(angle_book, 1.0,0.0,0.0);
    //glRotatef(-alfa_right,0.0,1.0,0.0);		
	oblojka_draw(lqx0,lqy0,lqx1,lqy1,lqx2,lqy2,lqx3,lqy3,oblojka_z0,oblojka_z1, tex_obl_back, tex_obl_face_1, tex_obl_torec_1);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(scena3_tx,0.0,-1.49);
	glRotatef(angle_book, 1.0,0.0,0.0);
   // glRotatef(-alfa_right,0.0,1.0,0.0);		
	oblojka_draw(rqx0,rqy0,rqx1,rqy1,rqx2,rqy2,rqx3,rqy3,oblojka_z0,oblojka_z1, tex_obl_back, tex_obl_face_1, tex_obl_torec_1);
	glPopMatrix();
	
 	
	glPushMatrix();
	glTranslatef(scena3_tx-0.02,0.0,-1.48);
	glRotatef(angle_book, 1.0,0.0,0.0);
    //glRotatef(-alfa_right,0.0,1.0,0.0);		
	page_draw(lqx0,lqy0,lqx1,lqy1,lqx2,lqy2,lqx3,lqy3,pages_left_z0,pages_left_z1, tex_14, tex_14, tex_14);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(scena3_tx+0.02,0.0,-1.48);
	glRotatef(angle_book, 1.0,0.0,0.0);
    //glRotatef(-alfa_right,0.0,1.0,0.0);		
	page_draw(rqx0,rqy0,rqx1,rqy1,rqx2,rqy2,rqx3,rqy3,pages_right_z0,pages_right_z1, tex_17, tex_17, tex_17);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(scena3_tx-0.02+delta_tx_left,0.0,-1.48);
	glRotatef(angle_book, 1.0,0.0,0.0);
    glRotatef(alfa_left,0.0,1.0,0.0);		
	page_draw(lqx0,lqy0,lqx1,lqy1,lqx2,lqy2,lqx3,lqy3,pages_left_z0,pages_left_z1, tex_16, tex_15, tex_16);
	glPopMatrix();
}
else
{
     glPushMatrix();
     glTranslatef(scena3_tx,0.0,-1.49);
     glRotatef(angle_book, 1.0,0.0,0.0);
     //glRotatef(-alfa_right,0.0,1.0,0.0);		
     oblojka_draw(lqx0,lqy0,lqx1,lqy1,lqx2,lqy2,lqx3,lqy3,oblojka_z0,oblojka_z1, tex_obl_back, tex_obl_face_1, tex_obl_torec_1);
     glPopMatrix();
	
     glPushMatrix();
     glTranslatef(scena3_tx,0.0,-1.49);
     glRotatef(angle_book, 1.0,0.0,0.0);
     // glRotatef(-alfa_right,0.0,1.0,0.0);		
     oblojka_draw(rqx0,rqy0,rqx1,rqy1,rqx2,rqy2,rqx3,rqy3,oblojka_z0,oblojka_z1, tex_obl_back, tex_obl_face_1, tex_obl_torec_1);
     glPopMatrix();
	
 	
	glPushMatrix();
	glTranslatef(scena3_tx+0.02,0.0,-1.48);
	glRotatef(angle_book, 1.0,0.0,0.0);
    //glRotatef(-alfa_right,0.0,1.0,0.0);		
	page_draw(rqx0,rqy0,rqx1,rqy1,rqx2,rqy2,rqx3,rqy3,pages_right_z0,pages_right_z1, tex_17, tex_18, tex_17);
	glPopMatrix();
	
	
	
	glPushMatrix();
	glTranslatef(scena3_tx-0.02,0.0,-1.48);
	glRotatef(angle_book, 1.0,0.0,0.0);
    //glRotatef(-alfa_right,0.0,1.0,0.0);		
	page_draw(lqx0,lqy0,lqx1,lqy1,lqx2,lqy2,lqx3,lqy3,pages_left_z0,pages_left_z1, tex_16, tex_16, tex_16);
	glPopMatrix();	
	
}
	
}
	
 }
 
 


 
 void  scena4(void)
 {
 	if (rotate_page_right ==GL_TRUE)
 	{
 	glPushMatrix();
	glTranslatef(scena4_tx,0.0,-1.49);
	glRotatef(angle_book, 1.0,0.0,0.0);
    //glRotatef(-alfa_right,0.0,1.0,0.0);		
	oblojka_draw(lqx0,lqy0,lqx1,lqy1,lqx2,lqy2,lqx3,lqy3,oblojka_z0,oblojka_z1, tex_obl_back, tex_obl_face_1, tex_obl_torec_1);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(scena4_tx,0.0,-1.49);
	glRotatef(angle_book, 1.0,0.0,0.0);
   // glRotatef(-alfa_right,0.0,1.0,0.0);		
	oblojka_draw(rqx0,rqy0,rqx1,rqy1,rqx2,rqy2,rqx3,rqy3,oblojka_z0,oblojka_z1, tex_obl_back, tex_obl_face_1, tex_obl_torec_1);
	glPopMatrix();
	
 	
	glPushMatrix();
	glTranslatef(scena4_tx+0.02-delta_tx_right,0.0,-1.4788);
	glRotatef(angle_book, 1.0,0.0,0.0);
    glRotatef(-alfa_right,0.0,1.0,0.0);		
	page_draw(rqx0,rqy0,rqx1,rqy1,rqx2,rqy2,rqx3,rqy3,pages_right_z0,pages_right_z1, tex_23, tex_18, tex_23);
	glPopMatrix();
	
	
	
	glPushMatrix();
	glTranslatef(scena4_tx-0.02,0.0,-1.48);
	glRotatef(angle_book, 1.0,0.0,0.0);
   // glRotatef(alfa_right,0.0,1.0,0.0);		
	page_draw(lqx0,lqy0,lqx1,lqy1,lqx2,lqy2,lqx3,lqy3,pages_left_z0,pages_left_z1, tex_24, tex_24, tex_24);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(scena4_tx+0.02,0.0,-1.48);
	glRotatef(angle_book, 1.0,0.0,0.0);
  //  glRotatef(-alfa_right,0.0,1.0,0.0);		
	page_draw(rqx0,rqy0,rqx1,rqy1,rqx2,rqy2,rqx3,rqy3,pages_right_z0,pages_right_z1, tex_19, tex_19, tex_19);
	glPopMatrix();

	
 }
 
else
{
	if (rotate_page_left ==GL_TRUE)
	{
	glPushMatrix();
	glTranslatef(scena4_tx,0.0,-1.49);
	glRotatef(angle_book, 1.0,0.0,0.0);
    //glRotatef(-alfa_right,0.0,1.0,0.0);		
	oblojka_draw(lqx0,lqy0,lqx1,lqy1,lqx2,lqy2,lqx3,lqy3,oblojka_z0,oblojka_z1, tex_obl_back, tex_obl_face_1, tex_obl_torec_1);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(scena4_tx,0.0,-1.49);
	glRotatef(angle_book, 1.0,0.0,0.0);
   // glRotatef(-alfa_right,0.0,1.0,0.0);		
	oblojka_draw(rqx0,rqy0,rqx1,rqy1,rqx2,rqy2,rqx3,rqy3,oblojka_z0,oblojka_z1, tex_obl_back, tex_obl_face_1, tex_obl_torec_1);
	glPopMatrix();
	
 	
	glPushMatrix();
	glTranslatef(scena4_tx+0.02,0.0,-1.48);
	glRotatef(angle_book, 1.0,0.0,0.0);
    //glRotatef(-alfa_right,0.0,1.0,0.0);		
	page_draw(rqx0,rqy0,rqx1,rqy1,rqx2,rqy2,rqx3,rqy3,pages_right_z0,pages_right_z1, tex_23, tex_18, tex_23);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(scena4_tx-0.02+delta_tx_left,0.0,-1.4788);
	glRotatef(angle_book, 1.0,0.0,0.0);
    glRotatef(alfa_left,0.0,1.0,0.0);		
	page_draw(lqx0,lqy0,lqx1,lqy1,lqx2,lqy2,lqx3,lqy3,pages_left_z0,pages_left_z1, tex_24, tex_17, tex_24);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(scena4_tx-0.02,0.0,-1.48);
	glRotatef(angle_book, 1.0,0.0,0.0);
    //glRotatef(alfa_left,0.0,1.0,0.0);		
	page_draw(lqx0,lqy0,lqx1,lqy1,lqx2,lqy2,lqx3,lqy3,pages_left_z0,pages_left_z1, tex_16, tex_16, tex_16);
	glPopMatrix();
}
else
{
glPushMatrix();
	glTranslatef(scena4_tx,0.0,-1.49);
	glRotatef(angle_book, 1.0,0.0,0.0);
    //glRotatef(-alfa_right,0.0,1.0,0.0);		
	oblojka_draw(lqx0,lqy0,lqx1,lqy1,lqx2,lqy2,lqx3,lqy3,oblojka_z0,oblojka_z1, tex_obl_back, tex_obl_face_1, tex_obl_torec_1);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(scena4_tx,0.0,-1.49);
	glRotatef(angle_book, 1.0,0.0,0.0);
   // glRotatef(-alfa_right,0.0,1.0,0.0);		
	oblojka_draw(rqx0,rqy0,rqx1,rqy1,rqx2,rqy2,rqx3,rqy3,oblojka_z0,oblojka_z1, tex_obl_back, tex_obl_face_1, tex_obl_torec_1);
	glPopMatrix();
	
 	
	glPushMatrix();
	glTranslatef(scena4_tx+0.02,0.0,-1.48);
	glRotatef(angle_book, 1.0,0.0,0.0);
    //glRotatef(-alfa_right,0.0,1.0,0.0);		
	page_draw(rqx0,rqy0,rqx1,rqy1,rqx2,rqy2,rqx3,rqy3,pages_right_z0,pages_right_z1, tex_23, tex_18, tex_23);
	glPopMatrix();
	
	
	
	glPushMatrix();
	glTranslatef(scena4_tx-0.02,0.0,-1.48);
	glRotatef(angle_book, 1.0,0.0,0.0);
    //glRotatef(-alfa_right,0.0,1.0,0.0);		
	page_draw(lqx0,lqy0,lqx1,lqy1,lqx2,lqy2,lqx3,lqy3,pages_left_z0,pages_left_z1, tex_24, tex_24, tex_24);
	glPopMatrix();	
	
}
	
}
}

void  scena5(void)
 {
 	if (rotate_page_right ==GL_TRUE)
 	{
 	glPushMatrix();
	glTranslatef(scena5_tx,0.0,-1.49);
	glRotatef(angle_book, 1.0,0.0,0.0);
    //glRotatef(-alfa_right,0.0,1.0,0.0);		
	oblojka_draw(lqx0,lqy0,lqx1,lqy1,lqx2,lqy2,lqx3,lqy3,oblojka_z0,oblojka_z1, tex_obl_back, tex_obl_face_1, tex_obl_torec_1);
	glPopMatrix();
	
	
	glPushMatrix();
	glTranslatef(scena5_tx,0.0,-1.49);
	glRotatef(angle_book, 1.0,0.0,0.0);
   // glRotatef(-alfa_right,0.0,1.0,0.0);		
	oblojka_draw(rqx0,rqy0,rqx1,rqy1,rqx2,rqy2,rqx3,rqy3,oblojka_z0,oblojka_z1, tex_obl_back, tex_obl_face_1, tex_obl_torec_1);
	glPopMatrix();
	
 	
	glPushMatrix();
	glTranslatef(scena5_tx+0.02-delta_tx_right,0.0,-1.4788);
	glRotatef(angle_book, 1.0,0.0,0.0);
    glRotatef(-alfa_right,0.0,1.0,0.0);		
	page_draw(rqx0,rqy0,rqx1,rqy1,rqx2,rqy2,rqx3,rqy3,pages_right_z0,pages_right_z1, tex_19, tex_20, tex_19);
	glPopMatrix();
	
	
	
	glPushMatrix();
	glTranslatef(scena5_tx-0.02,0.0,-1.48);
	glRotatef(angle_book, 1.0,0.0,0.0);
    //glRotatef(-alfa_right,0.0,1.0,0.0);		
	page_draw(lqx0,lqy0,lqx1,lqy1,lqx2,lqy2,lqx3,lqy3,pages_left_z0,pages_left_z1, tex_18, tex_18, tex_18);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(scena5_tx+0.02,0.0,-1.48);
	glRotatef(angle_book, 1.0,0.0,0.0);
   // glRotatef(-alfa_right,0.0,1.0,0.0);		
	page_draw(rqx0,rqy0,rqx1,rqy1,rqx2,rqy2,rqx3,rqy3,pages_right_z0,pages_right_z1, tex_21, tex_21, tex_21);
	glPopMatrix();
}
else
{
	if (rotate_page_left ==GL_TRUE)
	{
    glPushMatrix();
	glTranslatef(scena5_tx,0.0,-1.49);
	glRotatef(angle_book, 1.0,0.0,0.0);
    //glRotatef(-alfa_right,0.0,1.0,0.0);		
	oblojka_draw(lqx0,lqy0,lqx1,lqy1,lqx2,lqy2,lqx3,lqy3,oblojka_z0,oblojka_z1, tex_obl_back, tex_obl_face_1, tex_obl_torec_1);
	glPopMatrix();
	
	
	glPushMatrix();
	glTranslatef(scena5_tx,0.0,-1.49);
	glRotatef(angle_book, 1.0,0.0,0.0);
   // glRotatef(-alfa_right,0.0,1.0,0.0);		
	oblojka_draw(rqx0,rqy0,rqx1,rqy1,rqx2,rqy2,rqx3,rqy3,oblojka_z0,oblojka_z1, tex_obl_back, tex_obl_face_1, tex_obl_torec_1);
	glPopMatrix();
	
 	
	glPushMatrix();
	glTranslatef(scena5_tx+0.02,0.0,-1.48);
	glRotatef(angle_book, 1.0,0.0,0.0);
    //glRotatef(-alfa_right,0.0,1.0,0.0);		
	page_draw(rqx0,rqy0,rqx1,rqy1,rqx2,rqy2,rqx3,rqy3,pages_right_z0,pages_right_z1, tex_19, tex_20, tex_19);
	glPopMatrix();
	
	
	
	glPushMatrix();
	glTranslatef(scena5_tx-0.02+delta_tx_left,0.0,-1.4788);
	glRotatef(angle_book, 1.0,0.0,0.0);
    glRotatef(alfa_left,0.0,1.0,0.0);		
	page_draw(lqx0,lqy0,lqx1,lqy1,lqx2,lqy2,lqx3,lqy3,pages_left_z0,pages_left_z1, tex_18, tex_23, tex_18);
	glPopMatrix();	
	
	glPushMatrix();
	glTranslatef(scena5_tx-0.02,0.0,-1.48);
	glRotatef(angle_book, 1.0,0.0,0.0);
   // glRotatef(alfa_left,0.0,1.0,0.0);		
	page_draw(lqx0,lqy0,lqx1,lqy1,lqx2,lqy2,lqx3,lqy3,pages_left_z0,pages_left_z1, tex_24, tex_24, tex_24);
	glPopMatrix();	
}
else
{
glPushMatrix();
	glTranslatef(scena5_tx,0.0,-1.49);
	glRotatef(angle_book, 1.0,0.0,0.0);
    //glRotatef(-alfa_right,0.0,1.0,0.0);		
	oblojka_draw(lqx0,lqy0,lqx1,lqy1,lqx2,lqy2,lqx3,lqy3,oblojka_z0,oblojka_z1, tex_obl_back, tex_obl_face_1, tex_obl_torec_1);
	glPopMatrix();
	
	
	glPushMatrix();
	glTranslatef(scena5_tx,0.0,-1.49);
	glRotatef(angle_book, 1.0,0.0,0.0);
   // glRotatef(-alfa_right,0.0,1.0,0.0);		
	oblojka_draw(rqx0,rqy0,rqx1,rqy1,rqx2,rqy2,rqx3,rqy3,oblojka_z0,oblojka_z1, tex_obl_back, tex_obl_face_1, tex_obl_torec_1);
	glPopMatrix();
	
 	
	glPushMatrix();
	glTranslatef(scena5_tx+0.02,0.0,-1.48);
	glRotatef(angle_book, 1.0,0.0,0.0);
    //glRotatef(-alfa_right,0.0,1.0,0.0);		
	page_draw(rqx0,rqy0,rqx1,rqy1,rqx2,rqy2,rqx3,rqy3,pages_right_z0,pages_right_z1, tex_19, tex_20, tex_19);
	glPopMatrix();
	
	
	
	glPushMatrix();
	glTranslatef(scena5_tx-0.02,0.0,-1.48);
	glRotatef(angle_book, 1.0,0.0,0.0);
    //glRotatef(-alfa_right,0.0,1.0,0.0);		
	page_draw(lqx0,lqy0,lqx1,lqy1,lqx2,lqy2,lqx3,lqy3,pages_left_z0,pages_left_z1, tex_18, tex_18, tex_18);
	glPopMatrix();		
}
	
}
 }


void  scena6(void)
 {
 if (rotate_page_right ==GL_TRUE)
 {
 	glPushMatrix();
	glTranslatef(scena6_tx,0.0,-1.49);
	glRotatef(angle_book, 1.0,0.0,0.0);
    //glRotatef(-alfa_right,0.0,1.0,0.0);		
	oblojka_draw(lqx0,lqy0,lqx1,lqy1,lqx2,lqy2,lqx3,lqy3,oblojka_z0,oblojka_z1, tex_obl_back, tex_obl_face_1, tex_obl_torec_1);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(scena6_tx,0.0,-1.49);
	glRotatef(angle_book, 1.0,0.0,0.0);
   // glRotatef(-alfa_right,0.0,1.0,0.0);		
	oblojka_draw(rqx0,rqy0,rqx1,rqy1,rqx2,rqy2,rqx3,rqy3,oblojka_z0,oblojka_z1, tex_obl_back, tex_obl_face_1, tex_obl_torec_1);
	glPopMatrix();
	
 	
	glPushMatrix();
	glTranslatef(scena6_tx+0.02-delta_tx_right,0.0,-1.4788);
	glRotatef(angle_book, 1.0,0.0,0.0);
    glRotatef(-alfa_right,0.0,1.0,0.0);		
	page_draw(rqx0,rqy0,rqx1,rqy1,rqx2,rqy2,rqx3,rqy3,pages_right_z0,pages_right_z1, tex_21, tex_22, tex_21);
	glPopMatrix();
	
	
	glPushMatrix();
	glTranslatef(scena6_tx-0.02,0.0,-1.48);
	glRotatef(angle_book, 1.0,0.0,0.0);
    //glRotatef(-alfa_right,0.0,1.0,0.0);		
	page_draw(lqx0,lqy0,lqx1,lqy1,lqx2,lqy2,lqx3,lqy3,pages_left_z0,pages_left_z1, tex_20, tex_20, tex_20);
	glPopMatrix();
}
else
{
	if (rotate_page_left ==GL_TRUE)
	{
		glPushMatrix();
	glTranslatef(scena6_tx,0.0,-1.49);
	glRotatef(angle_book, 1.0,0.0,0.0);
    //glRotatef(-alfa_right,0.0,1.0,0.0);		
	oblojka_draw(lqx0,lqy0,lqx1,lqy1,lqx2,lqy2,lqx3,lqy3,oblojka_z0,oblojka_z1, tex_obl_back, tex_obl_face_1, tex_obl_torec_1);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(scena6_tx,0.0,-1.49);
	glRotatef(angle_book, 1.0,0.0,0.0);
   // glRotatef(-alfa_right,0.0,1.0,0.0);		
	oblojka_draw(rqx0,rqy0,rqx1,rqy1,rqx2,rqy2,rqx3,rqy3,oblojka_z0,oblojka_z1, tex_obl_back, tex_obl_face_1, tex_obl_torec_1);
	glPopMatrix();
	
 	
	glPushMatrix();
	glTranslatef(scena6_tx+0.02,0.0,-1.48);
	glRotatef(angle_book, 1.0,0.0,0.0);
    //glRotatef(-alfa_right,0.0,1.0,0.0);		
	page_draw(rqx0,rqy0,rqx1,rqy1,rqx2,rqy2,rqx3,rqy3,pages_right_z0,pages_right_z1, tex_21, tex_22, tex_21);
	glPopMatrix();
	
	
	glPushMatrix();
	glTranslatef(scena6_tx-0.02+delta_tx_left,0.0,-1.4788);
	glRotatef(angle_book, 1.0,0.0,0.0);
    glRotatef(alfa_left,0.0,1.0,0.0);		
	page_draw(lqx0,lqy0,lqx1,lqy1,lqx2,lqy2,lqx3,lqy3,pages_left_z0,pages_left_z1, tex_20, tex_19, tex_20);
	glPopMatrix();
	
	
	glPushMatrix();
	glTranslatef(scena6_tx-0.02,0.0,-1.48);
	glRotatef(angle_book, 1.0,0.0,0.0);
    //glRotatef(alfa_left,0.0,1.0,0.0);		
	page_draw(lqx0,lqy0,lqx1,lqy1,lqx2,lqy2,lqx3,lqy3,pages_left_z0,pages_left_z1, tex_18, tex_18, tex_18);
	glPopMatrix();
		
	}	
		else
		{
			glPushMatrix();
	glTranslatef(scena6_tx,0.0,-1.49);
	glRotatef(angle_book, 1.0,0.0,0.0);
    //glRotatef(-alfa_right,0.0,1.0,0.0);		
	oblojka_draw(lqx0,lqy0,lqx1,lqy1,lqx2,lqy2,lqx3,lqy3,oblojka_z0,oblojka_z1, tex_obl_back, tex_obl_face_1, tex_obl_torec_1);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(scena6_tx,0.0,-1.49);
	glRotatef(angle_book, 1.0,0.0,0.0);
   // glRotatef(-alfa_right,0.0,1.0,0.0);		
	oblojka_draw(rqx0,rqy0,rqx1,rqy1,rqx2,rqy2,rqx3,rqy3,oblojka_z0,oblojka_z1, tex_obl_back, tex_obl_face_1, tex_obl_torec_1);
	glPopMatrix();
	
 	
	glPushMatrix();
	glTranslatef(scena6_tx+0.02,0.0,-1.48);
	glRotatef(angle_book, 1.0,0.0,0.0);
    //glRotatef(-alfa_right,0.0,1.0,0.0);		
	page_draw(rqx0,rqy0,rqx1,rqy1,rqx2,rqy2,rqx3,rqy3,pages_right_z0,pages_right_z1, tex_21, tex_22, tex_21);
	glPopMatrix();
	
	
	glPushMatrix();
	glTranslatef(scena6_tx-0.02,0.0,-1.48);
	glRotatef(angle_book, 1.0,0.0,0.0);
    //glRotatef(-alfa_right,0.0,1.0,0.0);		
	page_draw(lqx0,lqy0,lqx1,lqy1,lqx2,lqy2,lqx3,lqy3,pages_left_z0,pages_left_z1, tex_20, tex_20, tex_20);
	glPopMatrix();
	
	
		}
	}
}
	
 

void  scena7(void)
 {

	
	if (rotate_page_right ==GL_TRUE)
	{
	glPushMatrix();
	glTranslatef(scena7_tx,0.0,-1.49);
	glRotatef(angle_book, 1.0,0.0,0.0);
    //glRotatef(-alfa_right,0.0,1.0,0.0);		
	oblojka_draw(lqx0,lqy0,lqx1,lqy1,lqx2,lqy2,lqx3,lqy3,oblojka_z0,oblojka_z1, tex_obl_back, tex_obl_face_1, tex_obl_torec_1);
	glPopMatrix();
		
	glPushMatrix();
	glTranslatef(scena7_tx,0.0,-1.49);
	glRotatef(angle_book, 1.0,0.0,0.0);
    glRotatef(-alfa_right,0.0,1.0,0.0);			
	oblojka_draw(rqx0,rqy0,rqx1,rqy1,rqx2,rqy2,rqx3,rqy3,oblojka_z0,oblojka_z1, tex_obl_back, tex_25, tex_obl_torec_1);
	glPopMatrix();
	
 	//-delta_tx_right/3.0
	glPushMatrix();
	glTranslatef(scena7_tx-0.02,0.0,-1.48);
	glRotatef(angle_book, 1.0,0.0,0.0);
    //glRotatef(alfa_left,0.0,1.0,0.0);		
	page_draw(lqx0,lqy0,lqx1,lqy1,lqx2,lqy2,lqx3,lqy3,pages_left_z0,pages_left_z1, tex_22, tex_22, tex_22);
	glPopMatrix();
}

else
{
	if (rotate_page_left ==GL_TRUE)
	{
	 glPushMatrix();	
	glTranslatef(scena7_tx,0.0,-1.49);
	glRotatef(angle_book, 1.0,0.0,0.0);
    //glRotatef(-alfa_right,0.0,1.0,0.0);		
	oblojka_draw(lqx0,lqy0,lqx1,lqy1,lqx2,lqy2,lqx3,lqy3,oblojka_z0,oblojka_z1, tex_obl_back, tex_obl_face_1, tex_obl_torec_1);
	glPopMatrix();
		
   glPushMatrix();
	glTranslatef(scena7_tx,0.0,-1.49);
	glRotatef(angle_book, 1.0,0.0,0.0);
   // glRotatef(-alfa_right,0.0,1.0,0.0);		
	oblojka_draw(rqx0,rqy0,rqx1,rqy1,rqx2,rqy2,rqx3,rqy3,oblojka_z0,oblojka_z1, tex_obl_back, tex_obl_face_1, tex_obl_torec_1);
	glPopMatrix();
	
 	
	glPushMatrix();
	glTranslatef(scena7_tx-0.02+delta_tx_left,0.0,-1.4788);
	glRotatef(angle_book, 1.0,0.0,0.0);
   glRotatef(alfa_left,0.0,1.0,0.0);		
	page_draw(lqx0,lqy0,lqx1,lqy1,lqx2,lqy2,lqx3,lqy3,pages_left_z0,pages_left_z1, tex_22, tex_21, tex_22);
	glPopMatrix();	
	
	glPushMatrix();
	glTranslatef(scena7_tx-0.02,0.0,-1.48);
	glRotatef(angle_book, 1.0,0.0,0.0);
  // glRotatef(alfa_left,0.0,1.0,0.0);		
	page_draw(lqx0,lqy0,lqx1,lqy1,lqx2,lqy2,lqx3,lqy3,pages_left_z0,pages_left_z1, tex_20, tex_20, tex_20);
	glPopMatrix();	
}

else
{
	glPushMatrix();
	glTranslatef(scena7_tx,0.0,-1.49);
	glRotatef(angle_book, 1.0,0.0,0.0);
    //glRotatef(-alfa_right,0.0,1.0,0.0);		
	oblojka_draw(lqx0,lqy0,lqx1,lqy1,lqx2,lqy2,lqx3,lqy3,oblojka_z0,oblojka_z1, tex_obl_back, tex_obl_face_1, tex_obl_torec_1);
	glPopMatrix();
	
    glPushMatrix();
	glTranslatef(scena7_tx,0.0,-1.49);
	glRotatef(angle_book, 1.0,0.0,0.0);
   // glRotatef(-alfa_right,0.0,1.0,0.0);		
	oblojka_draw(rqx0,rqy0,rqx1,rqy1,rqx2,rqy2,rqx3,rqy3,oblojka_z0,oblojka_z1, tex_obl_back, tex_obl_face_1, tex_obl_torec_1);
	glPopMatrix();
	
 	
	glPushMatrix();
	glTranslatef(scena7_tx-0.02,0.0,-1.48);
	glRotatef(angle_book, 1.0,0.0,0.0);
   // glRotatef(-alfa_right,0.0,1.0,0.0);		
	page_draw(lqx0,lqy0,lqx1,lqy1,lqx2,lqy2,lqx3,lqy3,pages_left_z0,pages_left_z1, tex_22, tex_22, tex_22);
	glPopMatrix();		
}
	
}
	
	
 }
 
        
 
void  scena8(void)
{
   if (rotate_page_left ==GL_TRUE)
   {
   		glPushMatrix();
	glTranslatef(scena8_tx,0.0,-1.49);
	glRotatef(angle_book, 1.0,0.0,0.0);    	
	oblojka_draw(lqx0,lqy0,lqx1,lqy1,lqx2,lqy2,lqx3,lqy3,oblojka_z0,oblojka_z1,  tex_obl_back, tex_obl_face_1, tex_obl_torec_1);
	glPopMatrix();
	
		glPushMatrix();
	glTranslatef(scena8_tx-0.02,0.0,-1.48);
	glRotatef(angle_book, 1.0,0.0,0.0);
   // glRotatef(-alfa_right,0.0,1.0,0.0);		
	page_draw(lqx0,lqy0,lqx1,lqy1,lqx2,lqy2,lqx3,lqy3,pages_left_z0,pages_left_z1, tex_22, tex_22, tex_22);
	glPopMatrix();	
   	
	glPushMatrix();
	glTranslatef(scena8_tx,0.0,-1.4788);
	glRotatef(angle_book, 1.0,0.0,0.0);
    glRotatef(alfa_left,0.0,1.0,0.0);		
	oblojka_draw(lqx0,lqy0,lqx1,lqy1,lqx2,lqy2,lqx3,lqy3,oblojka_z0,oblojka_z1,tex_25,  tex_obl_back, tex_obl_torec_1);
	glPopMatrix();	
	

}

else
{
  
  	glPushMatrix();
	glTranslatef(scena8_tx,0.0,-1.491);
	glRotatef(angle_book, 1.0,0.0,0.0);
  	oblojka_draw(lqx0,lqy0,lqx1,lqy1,lqx2,lqy2,lqx3,lqy3,oblojka_z0,oblojka_z1, tex_obl_back, tex_obl_face_1, tex_obl_torec_1);
	glPopMatrix();
  
	glPushMatrix();
	glTranslatef(scena8_tx,0.0,-1.49);
	glRotatef(angle_book, 1.0,0.0,0.0);	
	oblojka_draw(lqx0,lqy0,lqx1,lqy1,lqx2,lqy2,lqx3,lqy3,oblojka_z0,oblojka_z1,tex_25, tex_25, tex_obl_torec_1);
	glPopMatrix();
	
}

	
	}

void quads(void)
{
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, tex_26);	


glRotatef(angle_book, 1.0,0.0,0.0);    	
quads_draw();
	
glDisable(GL_TEXTURE_2D);	
	
	
	
}


GLvoid  ogl_draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();	
	/*info_draw(-2.2,1.6,-3.0);*/
		
	glTranslatef(0.0,0.0,-1.2);
	
	glPushMatrix();
	glTranslatef(0.0,0.0,-1.0);	
	quads();
	glPopMatrix();	
	


	

if (scena_draw ==0)
{
	scena0();
}

if (scena_draw ==1)
{
	scena1();	
}

if (scena_draw ==2)
{
	scena2();
}

if (scena_draw ==3)
{
	scena3();
}

if (scena_draw ==4)
{
	scena4();
}

if (scena_draw ==5)
{
	scena5();
}

if (scena_draw ==6)
{
	scena6();
}

if (scena_draw ==7)
{
	scena7();
}
if (scena_draw ==8)
{
	scena8();
}

glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, help_l_tex);	
   glEnable(GL_BLEND);
   glBlendFunc(GL_ONE, GL_ONE);
    glPushMatrix();
      glTranslatef(-1.2,-1.2,-1.0);
     load_draw(0.3,0.02);
    glPopMatrix();
    
	    glBindTexture(GL_TEXTURE_2D, help_r_tex);	
    
    glPushMatrix();
    glTranslatef(1.2,-1.2,-1.0);
     load_draw(0.3,0.02);
    glPopMatrix();
    
     glBindTexture(GL_TEXTURE_2D, title_tex);	
    
    glPushMatrix();
    glTranslatef(0.0,1.2,-1.0);
     load_draw(1.6,0.06);
    glPopMatrix();
 glDisable(GL_TEXTURE_2D);
   glDisable(GL_BLEND);


   
glFlush();
glFinish();
frame_avr=frame_avr+1;
frame_sec=frame_sec+1;
SDL_GL_SwapBuffers( );
}


//////////////////////////////////////////////////////////////



GLint keyPressed(SDL_keysym *keysym)
{	
switch ( keysym->sym )
{
	case SDLK_ESCAPE:
		Quit( 0 );
	break;
	/* case SDLK_F1:
		if ( fullscreen == GL_TRUE ) 
		{
			screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, VideoFlags );
			 fullscreen = GL_FALSE;
		}
		else
			{
			screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, VideoFlagsFullscreen );
			fullscreen = GL_TRUE;
			}
	 break;*/
	 case SDLK_0:scena_draw=0;break;
	 case SDLK_1:scena_draw=1 ;break;
	 case SDLK_2:scena_draw=2;break;
	 case SDLK_3:scena_draw=3;break;
	 case SDLK_4:scena_draw=4;break;
	 case SDLK_5:scena_draw=5;break;
	 case SDLK_6:scena_draw=6;break;
	 case SDLK_7:scena_draw=7;break;
	 case SDLK_8:scena_draw=8;break;

	 case SDLK_b: blend_func=blend_func+1;
	 		if (blend_func > 109) 
				{blend_func=0;} break;
	 case SDLK_LEFT: 
	 		if (rotate_page_left==GL_FALSE) 
	 			rotate_page_right=GL_TRUE;
	 break;
	case SDLK_RIGHT: if (rotate_page_right==GL_FALSE) 
	 			rotate_page_left=GL_TRUE;
	 break;				
	default:
		break;
}
    return 1;
}

GLint mouse_button_pressed(SDL_MouseButtonEvent *button)
{	
switch ( button->button )
{
	    case SDL_BUTTON_LEFT :;break;
		case SDL_BUTTON_MIDDLE :;break;
		case SDL_BUTTON_RIGHT :;break;
		case SDL_BUTTON_WHEELUP :tz=tz-0.4;break;
		case SDL_BUTTON_WHEELDOWN :tz=tz+0.4;break;			
}
  return 1;
}

GLint mouse_motion(SDL_MouseMotionEvent *motion)
{	
  return 1;
}



SDL_Surface *SDL_ogl_init( )
{
	SDL_Surface *surface;
    if ( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_TIMER ) < 0 )	{
	   SDL_GetError( ) ;
	    Quit( 1 );	}
    VideoInfo = SDL_GetVideoInfo( );
    if ( !VideoInfo )	{
	   SDL_GetError( ) ;
	    Quit( 1 );	}
    VideoFlags  = SDL_OPENGL;         
    VideoFlags |= SDL_GL_DOUBLEBUFFER; 
    VideoFlags |= SDL_HWPALETTE;       
    //VideoFlags |= SDL_RESIZABLE;     
    if ( VideoInfo->hw_available )
	VideoFlags |= SDL_HWSURFACE;
    else
	VideoFlags |= SDL_SWSURFACE;
    if ( VideoInfo->blit_hw )
	VideoFlags |= SDL_HWACCEL;
	VideoFlagsFullscreen =VideoFlags;
	 VideoFlagsFullscreen |= SDL_FULLSCREEN;
   SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );
   surface = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, VideoFlagsFullscreen );
	SDL_WM_SetCaption(SCREEN_CAPTION,NULL);
	SDL_WM_SetIcon(SDL_LoadBMP(ICON), NULL);
    if ( !surface )
	    Quit( 1 );
    return surface;
   SDL_FreeSurface(surface);
}






GLvoid AppEvents(void)
{
  while ( SDL_PollEvent( &event ) )
	{
		switch( event.type )
		{	
		case SDL_QUIT:
			Quit( 0 );
		break;
		case SDL_VIDEORESIZE:
			screen = SDL_SetVideoMode( event.resize.w, event.resize.h,SCREEN_BPP, VideoFlags );
			ogl_reshape( event.resize.w, event.resize.h );
			break;
		case SDL_KEYDOWN:
		  keyPressed( &event.key.keysym );
		break;
		case SDL_MOUSEBUTTONDOWN:
		  mouse_button_pressed( &event.button );
		break;
		case SDL_MOUSEBUTTONUP:
		 mouse_button_pressed( &event.button );
		break;
		case SDL_MOUSEMOTION:
		   mouse_motion( &event.motion);
		break;

		case SDL_USEREVENT:
				switch (event.user.code)
				{
					/*case EVENT_FPS:
					fps_counter();				
					break;*/
					case EVENT_ANIM:
					anim_proc();	
					break;
				}
				break;
		default:
			break;
		}
	}
}





GLint main( GLint argc, char **argv )
{

screen = SDL_ogl_init(); 	
ogl_init();	
 load_textures();
ogl_reshape( SCREEN_WIDTH,SCREEN_HEIGHT);	
fps_timer = SDL_AddTimer(FPS_TIME,  fps_timer_callback, NULL);
anim_timer = SDL_AddTimer(ANIM_TIME,  anim_timer_callback, NULL);

while ( done )
	{	  
	
	AppEvents(); 
  
    ogl_draw();
    SDL_Delay(REDRAW_TIME );
   	}




    Quit( 0 );
    return( 0 );



}

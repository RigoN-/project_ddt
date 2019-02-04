#include <GL/glew.h>

#include "rglScena_Draw_01.h"
#include "rglScena_Draw_03.h"
#include "rglScena_Draw_book.h"
#include "rglFigures.h"
#include "rglMesh3D.h"
#include "rglShader.h"
#include <SDL/SDL.h>




GLfloat angle;
GLint scena_draw=0;
GLint scena_ddraw_book=0;
GLfloat rotate_page_left, rotate_page_right;

GLfloat shader;

GLint book_state;

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

GLfloat oblojka_z0, oblojka_z1, pages_left_z0, pages_left_z1, pages_right_z0, pages_right_z1, page_book_z0, page_book_z1;
GLfloat rqx0=0.0, rqy0=-1.0,	rqx1=2.0, rqy1=-1.0, rqx2=2.0, rqy2=1.0, rqx3=0.0, rqy3=1.0, 
	rqxr1=1.0, rqyr1=-1.0, rqxr2=1.0, rqyr2=1.0,lqx0=-2.0, lqy0=-1.0,	lqx1=0.0, lqy1=-1.0, lqx2=0.0, lqy2=1.0, lqx3=-2.0, lqy3=1.0, 
	lqxr1=1.0, lqyr1=-1.0, lqxr2=1.0, lqyr2=1.0;
GLfloat	oblojka_z0=0.0, oblojka_z1=-0.02, pages_left_z0=0.0, pages_left_z1=-0.001, pages_right_z0=0.0, pages_right_z1=-0.001, page_book_z0=0.0, page_book_z1=0.0005;


GLfloat scena0_tx=-1;
GLfloat	scena1_tx=0;
GLfloat	scena2_tx=0;
GLfloat	scena3_tx=0;
GLfloat	scena4_tx=0;
GLfloat	scena5_tx=0;
GLfloat	scena6_tx=0;
GLfloat	scena7_tx=0;
GLfloat	scena8_tx=1;
GLfloat	angle_book=-10;


char *Txf20="../data/textures/scena1/page1.1.bmp";
char *Txf21="../data/textures/scena2/page2.1.bmp";
char *Txf22="../data/textures/scena2/page3.1.bmp";

char *Txf23="../data/textures/scena3/page4.1.bmp";
char *Txf24="../data/textures/scena3/page5.1.bmp";
char *Txf25="../data/textures/scena4/page6.1.bmp";
char *Txf26="../data/textures/scena4/page7.1.bmp";

char *Txf31="../data/textures/scena4/page7.1.bmp";
char *Txf32="../data/textures/scena8/oblojka_2_back.bmp";
char *Txf33="../data/textures/oblojka_1_face.bmp";
char *Txf34="../data/textures/oblojka_1_back.bmp";

	
GLuint tex_01,tex_02,tex_13,tex_14,tex_15,tex_16,tex_17,tex_23,tex_24,tex_20,tex_21,tex_19,tex_18,tex_22,tex_25,tex_obl_face_1,tex_obl_back,tex_obl_torec_1,help_r_tex,help_l_tex,title_tex;

GLint Scena_Draw_book_key_pressed(SDL_keysym *keysym)
{	
	
switch ( keysym->sym )
{
     
	 case SDLK_0:scena_ddraw_book=0; break;
	 case SDLK_1:scena_ddraw_book=1; break;
	 case SDLK_2:scena_ddraw_book=2; break;
	 case SDLK_3:scena_ddraw_book=3; break;
	 case SDLK_4:scena_ddraw_book=4; break;
	 case SDLK_5:scena_ddraw_book=5; break;
	
	
	 case SDLK_LEFT: 
	 		if (rotate_page_left==GL_FALSE) 
	 			rotate_page_right=GL_TRUE;
	 break;
	case SDLK_RIGHT: if (rotate_page_right==GL_FALSE) 
	 			rotate_page_left=GL_TRUE;
	 break;		
	
	 
	default:		break;
}
    return 1;
}

void Scena_book(rglMat4 mvm, rglMat4 pvm, GLuint shader)
{
	glUseProgram( shader); 
	glUniformMatrix4fv(glGetUniformLocation(shader,"pmatrix"), 1,GL_FALSE, &pvm[0]);
	glUniformMatrix4fv(glGetUniformLocation(shader,"mvmatrix"), 1,GL_FALSE,&mvm[0]);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D,info_tx01);
	glUniform1i(glGetUniformLocation(shader,"Texture"), 0);
	switch (scena_ddraw_book)
	{
	case 0:scena0(mvm, shader);break;
	case 1:scena1(mvm, shader);break;
	case 2:scena2(mvm, shader);break;
	case 3:scena3(mvm, shader);break;	
	case 4:scena4(mvm, shader);break;
	case 5:scena5(mvm, shader);break;
	
	
	
		default: 
		break;
		
	}

	glUseProgram(0);
}

void oblojka_draw(GLfloat x0, GLfloat y0, GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLfloat x3, GLfloat y3, GLfloat z0,  GLfloat z1, GLuint face, GLuint back, GLuint torec)
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

void page_draw(GLfloat x0, GLfloat y0, GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLfloat x3, GLfloat y3, GLfloat z0,  GLfloat z1, GLuint face, GLuint back, GLuint torec)
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

GLvoid book_anim_proc( void)
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
		if (scena_ddraw_book != 5)
		scena_ddraw_book=scena_ddraw_book+1;	
		scena0_tx=-1;
		scena5_tx=0;
	
		
	}	
	}	
	
	if (rotate_page_left == GL_TRUE)
	{	
		alfa_left=alfa_left+0.5;
	    delta_tx_left=delta_tx_left+0.04/(180.0/0.5);
	    scena1_tx=scena1_tx -  1.0/(180.0/0.5);	
	    scena8_tx=scena8_tx - 1.0/(180.0/0.5);	
	
	if (alfa_left >= 180 ) 
		{
		rotate_page_left=GL_FALSE;
		alfa_left=0;
		delta_tx_left=0;
		if (scena_ddraw_book != 0)
		scena_ddraw_book=scena_ddraw_book-1;
		scena0_tx=-1;	
		scena1_tx=0;
		scena5_tx=1;
		
	}
    }
}


GLvoid book_ogl_init_textures(  )
{
	
	rglLoad_Texture(Txf20, &tex_13, txAnisotropic_16, GL_DECAL, GL_REPEAT,txGL_COMPRESS,GL_TRUE);
	rglLoad_Texture(Txf21, &tex_14, txAnisotropic_16, GL_DECAL, GL_REPEAT,txGL_COMPRESS,GL_TRUE);
	rglLoad_Texture(Txf22, &tex_15, txAnisotropic_16, GL_DECAL, GL_REPEAT,txGL_COMPRESS,GL_TRUE);
	rglLoad_Texture(Txf23, &tex_16, txAnisotropic_16, GL_DECAL, GL_REPEAT,txGL_COMPRESS,GL_TRUE);
	rglLoad_Texture(Txf24, &tex_17, txAnisotropic_16, GL_DECAL, GL_REPEAT,txGL_COMPRESS,GL_TRUE);
	rglLoad_Texture(Txf25, &tex_23, txAnisotropic_16, GL_DECAL, GL_REPEAT,txGL_COMPRESS,GL_TRUE);
	rglLoad_Texture(Txf26, &tex_24, txAnisotropic_16, GL_DECAL, GL_REPEAT,txGL_COMPRESS,GL_TRUE);
	rglLoad_Texture(Txf31, &tex_22, txAnisotropic_16, GL_DECAL, GL_REPEAT,txGL_COMPRESS,GL_TRUE);
	rglLoad_Texture(Txf32, &tex_25, txAnisotropic_16, GL_DECAL, GL_REPEAT,txGL_COMPRESS,GL_TRUE);
	rglLoad_Texture(Txf33, &tex_obl_face_1, txAnisotropic_16, GL_DECAL, GL_REPEAT,txGL_COMPRESS,GL_TRUE);
	rglLoad_Texture(Txf34, &tex_obl_back, txAnisotropic_16, GL_DECAL, GL_REPEAT,txGL_COMPRESS,GL_TRUE);
}





void  scena0(rglMat4 mvm, GLuint shader)
{
   rglMat4 mvm_scena_0;
   rglMat4 mvm_work;
	
	
  if (rotate_page_right ==GL_TRUE)
  {
	rglMatrix4Identity(mvm_scena_0);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_scena_0,scena0_tx,0.0,-1.49);
	rglRotate(mvm_scena_0,angle_book,1.0,0.0,0.0);
    rglRotate(mvm_scena_0,-alfa_right,0.0,1.0,0.0);	
	rglMatrix4Multiply(mvm_work,mvm_scena_0);
	rglPushMatrix(mvm_work,shader);	
	oblojka_draw(rqx0,rqy0,rqx1,rqy1,rqx2,rqy2,rqx3,rqy3,oblojka_z0,oblojka_z1, tex_obl_face_1, tex_obl_back, tex_obl_torec_1);
	
	
	rglMatrix4Identity(mvm_scena_0);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_scena_0,scena0_tx+0.02,0.0,-1.491);
	rglRotate(mvm_scena_0,angle_book, 1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_scena_0);
	rglPushMatrix(mvm_work,shader);	
   	page_draw(rqx0,rqy0,rqx1,rqy1,rqx2,rqy2,rqx3,rqy3,pages_left_z0,pages_left_z1, tex_13, tex_13, tex_13);
	
	
	rglMatrix4Identity(mvm_scena_0);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_scena_0,scena0_tx,0.0,-1.492);
	rglRotate(mvm_scena_0,angle_book,1.0,0.0,0.0);
   rglMatrix4Multiply(mvm_work,mvm_scena_0);
	rglPushMatrix(mvm_work,shader);			
	oblojka_draw(rqx0,rqy0,rqx1,rqy1,rqx2,rqy2,rqx3,rqy3,oblojka_z0,oblojka_z1, tex_obl_back, tex_obl_face_1, tex_obl_torec_1);

	
	}
	
else	

			{
			rglMatrix4Identity(mvm_scena_0);
	        rglMatrix4Copy(mvm_work,mvm);
			rglTranslate(mvm_scena_0,scena0_tx,0.0,-1.49);
			rglRotate(mvm_scena_0,angle_book, 1.0,0.0,0.0);
			 rglMatrix4Multiply(mvm_work,mvm_scena_0);
	         rglPushMatrix(mvm_work,shader);			    	
			oblojka_draw(rqx0,rqy0,rqx1,rqy1,rqx2,rqy2,rqx3,rqy3,oblojka_z0,oblojka_z1, tex_obl_face_1, tex_obl_back, tex_obl_torec_1);
		
			}
     		
}


void  scena1(rglMat4 mvm, GLuint shader)
 {
   rglMat4 mvm_scena_1;
    rglMat4 mvm_work;
	
	if (rotate_page_right ==GL_TRUE)
  {
	
	rglMatrix4Identity(mvm_scena_1);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_scena_1,scena1_tx,0.0,-1.49);
	rglRotate(mvm_scena_1,angle_book, 1.0,0.0,0.0);  
	rglMatrix4Multiply(mvm_work,mvm_scena_1);
	rglPushMatrix(mvm_work,shader);	
	oblojka_draw(rqx0,rqy0,rqx1,rqy1,rqx2,rqy2,rqx3,rqy3,oblojka_z0,oblojka_z1, tex_obl_back, tex_obl_face_1, tex_obl_torec_1);
	
 	
	
 	
 	rglMatrix4Identity(mvm_scena_1);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_scena_1,scena1_tx,0.0,-1.49);
	rglRotate(mvm_scena_1,angle_book, 1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_scena_1);
	rglPushMatrix(mvm_work,shader);	
    oblojka_draw(lqx0,lqy0,lqx1,lqy1,lqx2,lqy2,lqx3,lqy3,oblojka_z0,oblojka_z1, tex_obl_back, tex_obl_face_1, tex_obl_torec_1);
	
	rglMatrix4Identity(mvm_scena_1);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_scena_1,scena1_tx+0.02-delta_tx_right,0.0,-1.4788);
	rglRotate(mvm_scena_1,angle_book, 1.0,0.0,0.0);
    rglRotate(mvm_scena_1,-alfa_right,0.0,1.0,0.0);	
	rglMatrix4Multiply(mvm_work,mvm_scena_1);
	rglPushMatrix(mvm_work,shader);		
	page_draw(rqx0,rqy0,rqx1,rqy1,rqx2,rqy2,rqx3,rqy3,pages_right_z0,pages_right_z1, tex_13, tex_14, tex_13);
	
	
	
	rglMatrix4Identity(mvm_scena_1);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_scena_1,scena2_tx+0.02,0.0,-1.48);
	rglRotate(mvm_scena_1,angle_book, 1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_scena_1);
	rglPushMatrix(mvm_work,shader);			
	page_draw(rqx0,rqy0,rqx1,rqy1,rqx2,rqy2,rqx3,rqy3,pages_right_z0,pages_right_z1, tex_15, tex_15, tex_15);

	

}
else	
	{
	 if (rotate_page_left ==GL_TRUE)
  {
	rglMatrix4Identity(mvm_scena_1);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_scena_1,scena1_tx,0.0,-1.49);
	rglRotate(mvm_scena_1,angle_book, 1.0,0.0,0.0);	
    rglMatrix4Multiply(mvm_work,mvm_scena_1);
	rglPushMatrix(mvm_work,shader);			
	oblojka_draw(rqx0,rqy0,rqx1,rqy1,rqx2,rqy2,rqx3,rqy3,oblojka_z0,oblojka_z1, tex_obl_back, tex_obl_face_1, tex_obl_torec_1);
	
 	
 	
 	rglMatrix4Identity(mvm_scena_1);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_scena_1,scena1_tx,0.0,-1.49);
	rglRotate(mvm_scena_1,angle_book, 1.0,0.0,0.0);
    rglRotate(mvm_scena_1,alfa_left,0.0,1.0,0.0);	
	rglMatrix4Multiply(mvm_work,mvm_scena_1);
	rglPushMatrix(mvm_work,shader);	
	oblojka_draw(lqx0,lqy0,lqx1,lqy1,lqx2,lqy2,lqx3,lqy3,oblojka_z0,oblojka_z1, tex_obl_back, tex_obl_face_1, tex_obl_torec_1);
		
 	
	
 	rglMatrix4Identity(mvm_scena_1);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_scena_1,scena1_tx+0.02,0.0,-1.48);
	rglRotate(mvm_scena_1,angle_book, 1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_scena_1);
	rglPushMatrix(mvm_work,shader);		
	page_draw(rqx0,rqy0,rqx1,rqy1,rqx2,rqy2,rqx3,rqy3,pages_right_z0,pages_right_z1, tex_13, tex_13, tex_13);
	

	
	
	}
	else
	{
	rglMatrix4Identity(mvm_scena_1);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_scena_1,scena1_tx,0.0,-1.49);
	rglRotate(mvm_scena_1,angle_book, 1.0,0.0,0.0);
   	rglMatrix4Multiply(mvm_work,mvm_scena_1);
	rglPushMatrix(mvm_work,shader);		
	oblojka_draw(rqx0,rqy0,rqx1,rqy1,rqx2,rqy2,rqx3,rqy3,oblojka_z0,oblojka_z1, tex_obl_back, tex_obl_face_1, tex_obl_torec_1);
	
 	
 	
 	rglMatrix4Identity(mvm_scena_1);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_scena_1,scena1_tx,0.0,-1.49);
	rglRotate(mvm_scena_1,angle_book, 1.0,0.0,0.0);		
	rglMatrix4Multiply(mvm_work,mvm_scena_1);
	rglPushMatrix(mvm_work,shader);	
	oblojka_draw(lqx0,lqy0,lqx1,lqy1,lqx2,lqy2,lqx3,lqy3,oblojka_z0,oblojka_z1, tex_obl_back, tex_obl_face_1, tex_obl_torec_1);
	
 	
	rglMatrix4Identity(mvm_scena_1);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_scena_1,scena1_tx+0.02,0.0,-1.48);
	rglRotate(mvm_scena_1,angle_book, 1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_scena_1);
	rglPushMatrix(mvm_work,shader);			
	page_draw(rqx0,rqy0,rqx1,rqy1,rqx2,rqy2,rqx3,rqy3,pages_right_z0,pages_right_z1, tex_13, tex_13, tex_13);

}
}	

 }

void  scena2(rglMat4 mvm,GLuint shader)

 {
    rglMat4 mvm_scena_2;
    rglMat4 mvm_work;
	 
 	if (rotate_page_right ==GL_TRUE)
 	{
 	
 	rglMatrix4Identity(mvm_scena_2);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_scena_2,scena2_tx,0.0,-1.49);
	rglRotate(mvm_scena_2,angle_book, 1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_scena_2);
	rglPushMatrix(mvm_work,shader);			
	oblojka_draw(lqx0,lqy0,lqx1,lqy1,lqx2,lqy2,lqx3,lqy3,oblojka_z0,oblojka_z1, tex_obl_back, tex_obl_face_1, tex_obl_torec_1);
	
	
	rglMatrix4Identity(mvm_scena_2);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_scena_2,scena2_tx,0.0,-1.49);
	rglRotate(mvm_scena_2,angle_book, 1.0,0.0,0.0);	
   	rglMatrix4Multiply(mvm_work,mvm_scena_2);
	rglPushMatrix(mvm_work,shader);	
	oblojka_draw(rqx0,rqy0,rqx1,rqy1,rqx2,rqy2,rqx3,rqy3,oblojka_z0,oblojka_z1, tex_obl_back, tex_obl_face_1, tex_obl_torec_1);
	
	
 	
	rglMatrix4Identity(mvm_scena_2);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_scena_2,scena2_tx+0.02-delta_tx_right,0.0,-1.4788);
	rglRotate(mvm_scena_2,angle_book, 1.0,0.0,0.0);
    rglRotate(mvm_scena_2,-alfa_right,0.0,1.0,0.0);	
	rglMatrix4Multiply(mvm_work,mvm_scena_2);
	rglPushMatrix(mvm_work,shader);		
	page_draw(rqx0,rqy0,rqx1,rqy1,rqx2,rqy2,rqx3,rqy3,pages_right_z0,pages_right_z1, tex_15, tex_16, tex_15);
	
	
	
	
	rglMatrix4Identity(mvm_scena_2);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_scena_2,scena2_tx-0.02,0.0,-1.48);
	rglRotate(mvm_scena_2,angle_book, 1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_scena_2);
	rglPushMatrix(mvm_work,shader);			
	page_draw(lqx0,lqy0,lqx1,lqy1,lqx2,lqy2,lqx3,lqy3,pages_left_z0,pages_left_z1, tex_14, tex_14, tex_14);
	
	
	rglMatrix4Identity(mvm_scena_2);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_scena_2,scena2_tx+0.02,0.0,-1.48);
	rglRotate(mvm_scena_2,angle_book, 1.0,0.0,0.0);	
	rglMatrix4Multiply(mvm_work,mvm_scena_2);
	rglPushMatrix(mvm_work,shader);		
	page_draw(rqx0,rqy0,rqx1,rqy1,rqx2,rqy2,rqx3,rqy3,pages_right_z0,pages_right_z1, tex_17, tex_17, tex_17);
	
	
	
}

else
{
	if (rotate_page_left ==GL_TRUE)
	{
    rglMatrix4Identity(mvm_scena_2);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_scena_2,scena2_tx,0.0,-1.49);
	rglRotate(mvm_scena_2,angle_book, 1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_scena_2);
	rglPushMatrix(mvm_work,shader);				
	oblojka_draw(lqx0,lqy0,lqx1,lqy1,lqx2,lqy2,lqx3,lqy3,oblojka_z0,oblojka_z1, tex_obl_back, tex_obl_face_1, tex_obl_torec_1);
	
	
	 rglMatrix4Identity(mvm_scena_2);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_scena_2,scena2_tx,0.0,-1.49);
	rglRotate(mvm_scena_2,angle_book, 1.0,0.0,0.0);	
   rglMatrix4Multiply(mvm_work,mvm_scena_2);
	rglPushMatrix(mvm_work,shader);			
	oblojka_draw(rqx0,rqy0,rqx1,rqy1,rqx2,rqy2,rqx3,rqy3,oblojka_z0,oblojka_z1, tex_obl_back, tex_obl_face_1, tex_obl_torec_1);
	
	
 	
	 rglMatrix4Identity(mvm_scena_2);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_scena_2,scena2_tx+0.02,0.0,-1.48);
	rglRotate(mvm_scena_2,angle_book, 1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_scena_2);
	rglPushMatrix(mvm_work,shader);
	page_draw(rqx0,rqy0,rqx1,rqy1,rqx2,rqy2,rqx3,rqy3,pages_right_z0,pages_right_z1, tex_15, tex_15, tex_15);
	
	
	
	rglMatrix4Identity(mvm_scena_2);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_scena_2,scena2_tx-0.02+delta_tx_left,0.0,-1.48);
	rglRotate(mvm_scena_2,angle_book, 1.0,0.0,0.0);
    rglRotate(mvm_scena_2,alfa_left,0.0,1.0,0.0);	
	rglMatrix4Multiply(mvm_work,mvm_scena_2);
	rglPushMatrix(mvm_work,shader);	
	page_draw(lqx0,lqy0,lqx1,lqy1,lqx2,lqy2,lqx3,lqy3,pages_left_z0,pages_left_z1, tex_14, tex_13, tex_14);

	
  }
  else
  {
  	
  	rglMatrix4Identity(mvm_scena_2);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_scena_2,scena2_tx,0.0,-1.49);
	rglRotate(mvm_scena_2,angle_book, 1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_scena_2);
	rglPushMatrix(mvm_work,shader);		
	oblojka_draw(lqx0,lqy0,lqx1,lqy1,lqx2,lqy2,lqx3,lqy3,oblojka_z0,oblojka_z1, tex_obl_back, tex_obl_face_1, tex_obl_torec_1);
	
	
	rglMatrix4Identity(mvm_scena_2);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_scena_2,scena2_tx,0.0,-1.49);
	rglRotate(mvm_scena_2,angle_book, 1.0,0.0,0.0);
   rglMatrix4Multiply(mvm_work,mvm_scena_2);
	rglPushMatrix(mvm_work,shader);			
	oblojka_draw(rqx0,rqy0,rqx1,rqy1,rqx2,rqy2,rqx3,rqy3,oblojka_z0,oblojka_z1, tex_obl_back, tex_obl_face_1, tex_obl_torec_1);
	
	
 	
	rglMatrix4Identity(mvm_scena_2);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_scena_2,scena2_tx+0.02,0.0,-1.48);
	rglRotate(mvm_scena_2,angle_book, 1.0,0.0,0.0);
	 rglMatrix4Multiply(mvm_work,mvm_scena_2);
	rglPushMatrix(mvm_work,shader);			
	page_draw(rqx0,rqy0,rqx1,rqy1,rqx2,rqy2,rqx3,rqy3,pages_right_z0,pages_right_z1, tex_15, tex_15, tex_15);
	
	
	
	rglMatrix4Identity(mvm_scena_2);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_scena_2,scena2_tx-0.02,0.0,-1.48);
	rglRotate(mvm_scena_2,angle_book, 1.0,0.0,0.0);
	 rglMatrix4Multiply(mvm_work,mvm_scena_2);
	rglPushMatrix(mvm_work,shader);		
	page_draw(lqx0,lqy0,lqx1,lqy1,lqx2,lqy2,lqx3,lqy3,pages_left_z0,pages_left_z1, tex_14, tex_14, tex_14);
	
}
  
}

 }
 
 
 void  scena3(rglMat4 mvm,GLuint shader)
 {
	 rglMat4 mvm_scena_3;
    rglMat4 mvm_work;
	 
 	if (rotate_page_right ==GL_TRUE)
 	{
 	rglMatrix4Identity(mvm_scena_3);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_scena_3,scena3_tx,0.0,-1.49);
	rglRotate(mvm_scena_3,angle_book, 1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_scena_3);
	rglPushMatrix(mvm_work,shader);			
	oblojka_draw(lqx0,lqy0,lqx1,lqy1,lqx2,lqy2,lqx3,lqy3,oblojka_z0,oblojka_z1, tex_obl_back, tex_obl_face_1, tex_obl_torec_1);

	
	rglMatrix4Identity(mvm_scena_3);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_scena_3,scena3_tx,0.0,-1.49);
	rglRotate(mvm_scena_3,angle_book, 1.0,0.0,0.0);
    rglMatrix4Multiply(mvm_work,mvm_scena_3);
	rglPushMatrix(mvm_work,shader);			
	oblojka_draw(rqx0,rqy0,rqx1,rqy1,rqx2,rqy2,rqx3,rqy3,oblojka_z0,oblojka_z1, tex_obl_back, tex_obl_face_1, tex_obl_torec_1);
	
	
 	
	rglMatrix4Identity(mvm_scena_3);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_scena_3,scena3_tx+0.02-delta_tx_right,0.0,-1.4788);
	rglRotate(mvm_scena_3,angle_book, 1.0,0.0,0.0);
    rglRotate(mvm_scena_3,-alfa_right,0.0,1.0,0.0);		
	rglMatrix4Multiply(mvm_work,mvm_scena_3);
	rglPushMatrix(mvm_work,shader);		
	page_draw(rqx0,rqy0,rqx1,rqy1,rqx2,rqy2,rqx3,rqy3,pages_right_z0,pages_right_z1, tex_17, tex_24, tex_17);
	
	
	
	
	rglMatrix4Identity(mvm_scena_3);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_scena_3,scena3_tx-0.02,0.0,-1.48);
	rglRotate(mvm_scena_3,angle_book, 1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_scena_3);
	rglPushMatrix(mvm_work,shader);		
	page_draw(lqx0,lqy0,lqx1,lqy1,lqx2,lqy2,lqx3,lqy3,pages_left_z0,pages_left_z1, tex_16, tex_16, tex_16);
	
	
	rglMatrix4Identity(mvm_scena_3);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_scena_3,scena3_tx+0.02,0.0,-1.48);
	rglRotate(mvm_scena_3,angle_book, 1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_scena_3);
	rglPushMatrix(mvm_work,shader);		
	page_draw(rqx0,rqy0,rqx1,rqy1,rqx2,rqy2,rqx3,rqy3,pages_right_z0,pages_right_z1, tex_24, tex_24, tex_24);
	
	rglMatrix4Identity(mvm_scena_3);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_scena_3,scena3_tx,0.0,-1.48);
	rglRotate(mvm_scena_3,angle_book, 1.0,0.0,0.0);
    rglMatrix4Multiply(mvm_work,mvm_scena_3);
	rglPushMatrix(mvm_work,shader);	
	oblojka_draw(rqx0,rqy0,rqx1,rqy1,rqx2,rqy2,rqx3,rqy3,oblojka_z0,oblojka_z1, tex_obl_back, tex_obl_back, tex_obl_back);		

}
else
{
	if (rotate_page_left ==GL_TRUE)
	{
	rglMatrix4Identity(mvm_scena_3);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_scena_3,scena3_tx,0.0,-1.49);
	rglRotate(mvm_scena_3,angle_book, 1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_scena_3);
	rglPushMatrix(mvm_work,shader);			
	oblojka_draw(lqx0,lqy0,lqx1,lqy1,lqx2,lqy2,lqx3,lqy3,oblojka_z0,oblojka_z1, tex_obl_back, tex_obl_face_1, tex_obl_torec_1);
	
	
	rglMatrix4Identity(mvm_scena_3);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_scena_3,scena3_tx,0.0,-1.49);
	rglRotate(mvm_scena_3,angle_book, 1.0,0.0,0.0);
    rglMatrix4Multiply(mvm_work,mvm_scena_3);
	rglPushMatrix(mvm_work,shader);		
	oblojka_draw(rqx0,rqy0,rqx1,rqy1,rqx2,rqy2,rqx3,rqy3,oblojka_z0,oblojka_z1, tex_obl_back, tex_obl_face_1, tex_obl_torec_1);
	
	
 	
	rglMatrix4Identity(mvm_scena_3);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_scena_3,scena3_tx-0.02,0.0,-1.48);
	rglRotate(mvm_scena_3,angle_book, 1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_scena_3);
	rglPushMatrix(mvm_work,shader);			
	page_draw(lqx0,lqy0,lqx1,lqy1,lqx2,lqy2,lqx3,lqy3,pages_left_z0,pages_left_z1, tex_14, tex_14, tex_14);
	
	
	rglMatrix4Identity(mvm_scena_3);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_scena_3,scena3_tx+0.02,0.0,-1.48);
	rglRotate(mvm_scena_3,angle_book, 1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_scena_3);
	rglPushMatrix(mvm_work,shader);			
	page_draw(rqx0,rqy0,rqx1,rqy1,rqx2,rqy2,rqx3,rqy3,pages_right_z0,pages_right_z1, tex_17, tex_17, tex_17);
	
	
	rglMatrix4Identity(mvm_scena_3);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_scena_3,scena3_tx-0.02+delta_tx_left,0.0,-1.48);
	rglRotate(mvm_scena_3,angle_book, 1.0,0.0,0.0);
    rglRotate(mvm_scena_3,alfa_left,0.0,1.0,0.0);	
	rglMatrix4Multiply(mvm_work,mvm_scena_3);
	rglPushMatrix(mvm_work,shader);			
	page_draw(lqx0,lqy0,lqx1,lqy1,lqx2,lqy2,lqx3,lqy3,pages_left_z0,pages_left_z1, tex_16, tex_15, tex_16);
	
}
else
{
    rglMatrix4Identity(mvm_scena_3);
	rglMatrix4Copy(mvm_work,mvm);
    rglTranslate(mvm_scena_3,scena3_tx,0.0,-1.49);
    rglRotate(mvm_scena_3,angle_book, 1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_scena_3);
	rglPushMatrix(mvm_work,shader);			
    oblojka_draw(lqx0,lqy0,lqx1,lqy1,lqx2,lqy2,lqx3,lqy3,oblojka_z0,oblojka_z1, tex_obl_back, tex_obl_face_1, tex_obl_torec_1);
    
	
     rglMatrix4Identity(mvm_scena_3);
	 rglMatrix4Copy(mvm_work,mvm);
     rglTranslate(mvm_scena_3,scena3_tx,0.0,-1.49);
     rglRotate(mvm_scena_3,angle_book, 1.0,0.0,0.0);
	 rglMatrix4Multiply(mvm_work,mvm_scena_3);
	 rglPushMatrix(mvm_work,shader);		
     oblojka_draw(rqx0,rqy0,rqx1,rqy1,rqx2,rqy2,rqx3,rqy3,oblojka_z0,oblojka_z1, tex_obl_back, tex_obl_face_1, tex_obl_torec_1);
    
	
 	
	rglMatrix4Identity(mvm_scena_3);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_scena_3,scena3_tx+0.02,0.0,-1.48);
	rglRotate(mvm_scena_3,angle_book, 1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_scena_3);
	rglPushMatrix(mvm_work,shader);				
	page_draw(rqx0,rqy0,rqx1,rqy1,rqx2,rqy2,rqx3,rqy3,pages_right_z0,pages_right_z1, tex_17, tex_17, tex_17);
	
	
	
	
	
	rglMatrix4Identity(mvm_scena_3);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_scena_3,scena3_tx-0.02,0.0,-1.48);
	rglRotate(mvm_scena_3,angle_book, 1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_scena_3);
	rglPushMatrix(mvm_work,shader);				
	page_draw(lqx0,lqy0,lqx1,lqy1,lqx2,lqy2,lqx3,lqy3,pages_left_z0,pages_left_z1, tex_16, tex_16, tex_16);
	
	
}
	
}
	
 }

void  scena4(rglMat4 mvm,GLuint shader)
 {
	 rglMat4 mvm_scena_4;
	 rglMat4 mvm_work;

	
	if (rotate_page_right ==GL_TRUE)
	{
	rglMatrix4Identity(mvm_scena_4);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_scena_4,scena4_tx,0.0,-1.49);
	rglRotate(mvm_scena_4,angle_book, 1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_scena_4);
	rglPushMatrix(mvm_work,shader);			
	oblojka_draw(lqx0,lqy0,lqx1,lqy1,lqx2,lqy2,lqx3,lqy3,oblojka_z0,oblojka_z1, tex_obl_back, tex_obl_face_1, tex_obl_torec_1);
	
		
	rglMatrix4Identity(mvm_scena_4);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_scena_4,scena4_tx,0.0,-1.49);
	rglRotate(mvm_scena_4,angle_book, 1.0,0.0,0.0);
    rglRotate(mvm_scena_4,-alfa_right,0.0,1.0,0.0);	
	rglMatrix4Multiply(mvm_work,mvm_scena_4);
	rglPushMatrix(mvm_work,shader);			
	oblojka_draw(rqx0,rqy0,rqx1,rqy1,rqx2,rqy2,rqx3,rqy3,oblojka_z0,oblojka_z1, tex_obl_back, tex_25, tex_obl_torec_1);
	
	
 
    rglMatrix4Identity(mvm_scena_4);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_scena_4,scena4_tx-0.02,0.0,-1.48);
	rglRotate(mvm_scena_4,angle_book, 1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_scena_4);
	rglPushMatrix(mvm_work,shader);			
	page_draw(lqx0,lqy0,lqx1,lqy1,lqx2,lqy2,lqx3,lqy3,pages_left_z0,pages_left_z1, tex_24, tex_24, tex_24);
	
}

else
{
	if (rotate_page_left ==GL_TRUE)
	{
	rglMatrix4Identity(mvm_scena_4);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_scena_4,scena4_tx,0.0,-1.49);
	rglRotate(mvm_scena_4,angle_book, 1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_scena_4);
	rglPushMatrix(mvm_work,shader);					
	oblojka_draw(lqx0,lqy0,lqx1,lqy1,lqx2,lqy2,lqx3,lqy3,oblojka_z0,oblojka_z1, tex_obl_back, tex_obl_face_1, tex_obl_torec_1);
	
		
    rglMatrix4Identity(mvm_scena_4);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_scena_4,scena4_tx,0.0,-1.49);
	rglRotate(mvm_scena_4,angle_book, 1.0,0.0,0.0);
    rglMatrix4Multiply(mvm_work,mvm_scena_4);
	rglPushMatrix(mvm_work,shader);			
	oblojka_draw(rqx0,rqy0,rqx1,rqy1,rqx2,rqy2,rqx3,rqy3,oblojka_z0,oblojka_z1, tex_obl_back, tex_obl_face_1, tex_obl_torec_1);
	
	
 	
	rglMatrix4Identity(mvm_scena_4);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_scena_4,scena4_tx-0.02+delta_tx_left,0.0,-1.4788);
	rglRotate(mvm_scena_4,angle_book, 1.0,0.0,0.0);
    rglRotate(mvm_scena_4,alfa_left,0.0,1.0,0.0);	
    rglMatrix4Multiply(mvm_work,mvm_scena_4);
	rglPushMatrix(mvm_work,shader);				
	page_draw(lqx0,lqy0,lqx1,lqy1,lqx2,lqy2,lqx3,lqy3,pages_left_z0,pages_left_z1, tex_24, tex_17, tex_24);
	
	
	 
	
	rglMatrix4Identity(mvm_scena_4);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_scena_4,scena4_tx-0.02,0.0,-1.48);
	rglRotate(mvm_scena_4,angle_book, 1.0,0.0,0.0);
    rglMatrix4Multiply(mvm_work,mvm_scena_4);
	rglPushMatrix(mvm_work,shader);			
	page_draw(lqx0,lqy0,lqx1,lqy1,lqx2,lqy2,lqx3,lqy3,pages_left_z0,pages_left_z1, tex_16, tex_16, tex_16);
	
	
	
}

else
{
	rglMatrix4Identity(mvm_scena_4);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_scena_4,scena4_tx,0.0,-1.49);
	rglRotate(mvm_scena_4,angle_book, 1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_scena_4);
	rglPushMatrix(mvm_work,shader);			
	oblojka_draw(lqx0,lqy0,lqx1,lqy1,lqx2,lqy2,lqx3,lqy3,oblojka_z0,oblojka_z1, tex_obl_back, tex_obl_face_1, tex_obl_torec_1);
	
	
    rglMatrix4Identity(mvm_scena_4);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_scena_4,scena4_tx,0.0,-1.49);
	rglRotate(mvm_scena_4,angle_book, 1.0,0.0,0.0);
    rglMatrix4Multiply(mvm_work,mvm_scena_4);
	rglPushMatrix(mvm_work,shader);		
	oblojka_draw(rqx0,rqy0,rqx1,rqy1,rqx2,rqy2,rqx3,rqy3,oblojka_z0,oblojka_z1, tex_obl_back, tex_obl_face_1, tex_obl_torec_1);
	
	
 	
	rglMatrix4Identity(mvm_scena_4);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_scena_4,scena4_tx-0.02,0.0,-1.48);
	rglRotate(mvm_scena_4,angle_book, 1.0,0.0,0.0);
    rglMatrix4Multiply(mvm_work,mvm_scena_4);
	rglPushMatrix(mvm_work,shader);			
	page_draw(lqx0,lqy0,lqx1,lqy1,lqx2,lqy2,lqx3,lqy3,pages_left_z0,pages_left_z1, tex_22, tex_22, tex_22);
			
}
	
}
	
	
 } 
 
void  scena5(rglMat4 mvm,GLuint shader)
{
	rglMat4 mvm_scena_5;
	rglMat4 mvm_work;
	
   if (rotate_page_left ==GL_TRUE)
   {
   		rglMatrix4Identity(mvm_scena_5);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_scena_5,scena5_tx,0.0,-1.49);
	rglRotate(mvm_scena_5,angle_book, 1.0,0.0,0.0); 
	rglMatrix4Multiply(mvm_work,mvm_scena_5);
	rglPushMatrix(mvm_work,shader);		   	
	oblojka_draw(lqx0,lqy0,lqx1,lqy1,lqx2,lqy2,lqx3,lqy3,oblojka_z0,oblojka_z1,  tex_obl_back, tex_obl_face_1, tex_obl_torec_1);
	
	
	rglMatrix4Identity(mvm_scena_5);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_scena_5,scena5_tx-0.02,0.0,-1.48);
	rglRotate(mvm_scena_5,angle_book, 1.0,0.0,0.0);
    rglMatrix4Multiply(mvm_work,mvm_scena_5);
	rglPushMatrix(mvm_work,shader);		   	
	page_draw(lqx0,lqy0,lqx1,lqy1,lqx2,lqy2,lqx3,lqy3,pages_left_z0,pages_left_z1, tex_24, tex_24, tex_24);
	
   	
	rglMatrix4Identity(mvm_scena_5);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_scena_5,scena5_tx,0.0,-1.4788);
	rglRotate(mvm_scena_5,angle_book, 1.0,0.0,0.0);
    rglRotate(mvm_scena_5,alfa_left,0.0,1.0,0.0);		
	rglMatrix4Multiply(mvm_work,mvm_scena_5);
	rglPushMatrix(mvm_work,shader);		   	
	oblojka_draw(lqx0,lqy0,lqx1,lqy1,lqx2,lqy2,lqx3,lqy3,oblojka_z0,oblojka_z1,tex_25,  tex_obl_back, tex_obl_torec_1);
	
	

}

else
{
  
  	rglMatrix4Identity(mvm_scena_5);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_scena_5,scena5_tx,0.0,-1.491);
	rglRotate(mvm_scena_5,angle_book, 1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_scena_5);
	rglPushMatrix(mvm_work,shader);		
  	oblojka_draw(lqx0,lqy0,lqx1,lqy1,lqx2,lqy2,lqx3,lqy3,oblojka_z0,oblojka_z1, tex_obl_back, tex_obl_face_1, tex_obl_torec_1);
	
  
	rglMatrix4Identity(mvm_scena_5);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_scena_5,scena5_tx,0.0,-1.49);
	rglRotate(mvm_scena_5,angle_book, 1.0,0.0,0.0);	
	rglMatrix4Multiply(mvm_work,mvm_scena_5);
	rglPushMatrix(mvm_work,shader);		
	oblojka_draw(lqx0,lqy0,lqx1,lqy1,lqx2,lqy2,lqx3,lqy3,oblojka_z0,oblojka_z1,tex_25, tex_25, tex_obl_torec_1);
	
	
}


	} 
 

	




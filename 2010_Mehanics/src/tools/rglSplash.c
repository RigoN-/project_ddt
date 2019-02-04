#include "rglSplash.h"

char *Splash_Txf00="../data/textures/formula01.jpg";
char *Splash_Txf01="../data/textures/formula02.jpg";
char *Splash_Txf02="../data/textures/formula03.jpg";

char *Splash_Txf03="../data/textures/einstein.jpg";
char *Splash_Txf04="../data/textures/faradey.jpg";
char *Splash_Txf05="../data/textures/maxwell.jpg";
char *Splash_Txf06="../data/textures/planck.jpg";
char *Splash_Txf07="../data/textures/curie.jpg";
char *Splash_Txf08="../data/textures/lenc.jpg";
char *Splash_Txf09="../data/textures/newton.jpg";
char *Splash_Txf10="../data/textures/Rezerford.jpg";
char *Splash_Txf11="../data/textures/vavilov.jpg";
char *Splash_Txf12="../data/textures/bor.jpg";
char *Splash_Txf13="../data/textures/title_base0.tga";
char *Splash_Txf14="../data/textures/title_base1.tga";
char *Splash_Txf15="../data/textures/fon01.jpg";
char *Splash_Txf16="../data/textures/fon02.jpg";
char *Splash_Txf17="../data/textures/title_base2.tga";
char *Splash_Txf18="../data/textures/devel1.tga";
char *Splash_Txf19="../data/textures/devel2.tga";

rglCol4 texEnvColor;
 GLfloat scale = 1.0;
 GLfloat m_interpol;
 GLfloat wrap=0.0;
 GLuint tex0, tex1, i_tex0, i_tex1;
 
 GLvoid splash_switch_texture (  GLuint i_tex0,  GLuint i_tex1)
{
	switch (i_tex0 )
{
	case 0:	tex0=foto_tx01;	break;	 	
	case 1:	tex0=foto_tx03;	break;	 
	case 2:	tex0=foto_tx05;	break;	 
	case 3:	tex0=foto_tx07;	break;	 
	case 4:	tex0=foto_tx09;	break;	 
	default:		;		break;
}
switch (i_tex1 )
{
	case 0:	tex1=foto_tx02;	break;	 	
	case 1:	tex1=foto_tx04;	break;	 
	case 2:	tex1=foto_tx06;	break;	 
	case 3:	tex1=foto_tx08;	break;	 
	case 4:	tex1=foto_tx10;	break;	 
	default:		;		break;
}
}
 
 
GLvoid splash_anim (  )
{

	  m_interpol += 0.0025*scale;
	  if (m_interpol > 1.0)
	  {
		m_interpol = 1.0;
		scale = -1.0;
		 i_tex1+=1;
		  if ( i_tex1> 4)
		  	 i_tex1=0;
		 splash_switch_texture(i_tex0,i_tex1);
	  }
	  else if (m_interpol < 0.0)
	  {
		m_interpol = 0.0;
		scale = 1.0;
		 i_tex0+=1;
		  if ( i_tex0> 4)
		  	 i_tex0=0;
		splash_switch_texture(i_tex0,i_tex1);
	  }
	texEnvColor=rglColor4Set(0.0,0.0,0.0,m_interpol);
	wrap+=0.001;
	
	}

GLvoid splash_init_textures(  )
{
	printf("Splash texture init---------------------------------------------------------\n");
	rglLoad_Texture(Splash_Txf00, &center_tx, txAnisotropic_16, GL_DECAL, GL_REPEAT,  txS3TC_DXT1,GL_TRUE);
	rglLoad_Texture(Splash_Txf01, &top_tx, txAnisotropic_16, GL_DECAL, GL_REPEAT,  txS3TC_DXT1,GL_TRUE);
	rglLoad_Texture(Splash_Txf02, &buttom_tx, txAnisotropic_16, GL_DECAL, GL_REPEAT,  txS3TC_DXT1 ,GL_TRUE);
	rglLoad_Texture(Splash_Txf03, &foto_tx01, txAnisotropic_16, GL_DECAL, GL_REPEAT,  txS3TC_DXT1,GL_TRUE);
	rglLoad_Texture(Splash_Txf04, &foto_tx02, txAnisotropic_16, GL_DECAL, GL_REPEAT,  txS3TC_DXT1,GL_TRUE);
	rglLoad_Texture(Splash_Txf05, &foto_tx03, txAnisotropic_16, GL_DECAL, GL_REPEAT,  txS3TC_DXT1,GL_TRUE);
	rglLoad_Texture(Splash_Txf06, &foto_tx04, txAnisotropic_16, GL_DECAL, GL_REPEAT,  txS3TC_DXT1,GL_TRUE);
	rglLoad_Texture(Splash_Txf07, &foto_tx05, txAnisotropic_16, GL_DECAL, GL_REPEAT,  txS3TC_DXT1,GL_TRUE);
	rglLoad_Texture(Splash_Txf08, &foto_tx06, txAnisotropic_16, GL_DECAL, GL_REPEAT,  txS3TC_DXT1,GL_TRUE);
	rglLoad_Texture(Splash_Txf09, &foto_tx07, txAnisotropic_16, GL_DECAL, GL_REPEAT,  txS3TC_DXT1,GL_TRUE);
	rglLoad_Texture(Splash_Txf10, &foto_tx08, txAnisotropic_16, GL_DECAL, GL_REPEAT,  txS3TC_DXT1,GL_TRUE);
	rglLoad_Texture(Splash_Txf11, &foto_tx09, txAnisotropic_16, GL_DECAL, GL_REPEAT,  txS3TC_DXT1,GL_TRUE);
	rglLoad_Texture(Splash_Txf12, &foto_tx10, txAnisotropic_16, GL_DECAL, GL_REPEAT,  txS3TC_DXT1,GL_TRUE);
	rglLoad_Texture(Splash_Txf13, &title_tx0, txAnisotropic_16, GL_DECAL, GL_REPEAT,  txS3TC_DXT1,GL_TRUE);
	rglLoad_Texture(Splash_Txf14, &title_tx1, txAnisotropic_16, GL_DECAL, GL_REPEAT,  txS3TC_DXT1,GL_TRUE);
	rglLoad_Texture(Splash_Txf15, &fon_tx0, txAnisotropic_16, GL_DECAL, GL_REPEAT,  txS3TC_DXT1,GL_TRUE);
	rglLoad_Texture(Splash_Txf16, &fon_tx1, txAnisotropic_16, GL_DECAL, GL_REPEAT,  txS3TC_DXT1,GL_TRUE);
	rglLoad_Texture(Splash_Txf17, &title_tx2, txAnisotropic_16, GL_DECAL, GL_REPEAT,  txS3TC_DXT1,GL_TRUE);
	rglLoad_Texture(Splash_Txf18, &devel_tx0, txAnisotropic_16, GL_DECAL, GL_REPEAT,  txS3TC_DXT1,GL_TRUE);
	rglLoad_Texture(Splash_Txf19, &devel_tx1, txAnisotropic_16, GL_DECAL, GL_REPEAT,  txS3TC_DXT1,GL_TRUE);
	i_tex0=0;i_tex1=0;
	splash_switch_texture(i_tex0,i_tex1);
	printf("Splash texture load  OK---------------------------------------------------------\n");
	}


	
void splash_quad(GLfloat x0,GLfloat y0, GLfloat z0,GLfloat x1,GLfloat y1,GLfloat z1,GLfloat x2,GLfloat y2, GLfloat z2,GLfloat x3,GLfloat y3,GLfloat z3)
{
	glBegin(GL_QUADS);
		 glMultiTexCoord2f(GL_TEXTURE0, 0.0, 0.0); glMultiTexCoord2f(GL_TEXTURE1, 0.0, 0.0); glColor3f( 1.0, 1.0, 1.0);glVertex3f( x0,  y0,  z0);
		 glMultiTexCoord2f(GL_TEXTURE0, 1.0, 0.0); glMultiTexCoord2f(GL_TEXTURE1, 1.0, 0.0); glColor3f( 1.0, 1.0, 1.0);glVertex3f( x1,  y1,  z1);
		 glMultiTexCoord2f(GL_TEXTURE0, 1.0, 1.0); glMultiTexCoord2f(GL_TEXTURE1, 1.0, 1.0); glColor3f( 1.0, 1.0, 1.0);glVertex3f( x2,  y2,  z2);
		 glMultiTexCoord2f(GL_TEXTURE0, 0.0, 1.0); glMultiTexCoord2f(GL_TEXTURE1, 0.0, 1.0); glColor3f( 1.0, 1.0, 1.0);glVertex3f( x3,  y3,  z3);
     glEnd();

	}	

void splash_quad2(GLfloat x0,GLfloat y0, GLfloat z0,GLfloat x1,GLfloat y1,GLfloat z1,GLfloat x2,GLfloat y2, GLfloat z2,GLfloat x3,GLfloat y3,GLfloat z3)
{
	glBegin(GL_QUADS);
		 glMultiTexCoord2f(GL_TEXTURE0, 0.0+wrap, 0.0);  glColor4f( 1.0, 1.0, 1.0, 0.0);glVertex3f( x0,  y0,  z0);
		 glMultiTexCoord2f(GL_TEXTURE0, 1.0+ wrap, 0.0);  glColor4f( 1.0, 1.0, 1.0, 0.0);glVertex3f( x1,  y1,  z1);
		 glMultiTexCoord2f(GL_TEXTURE0, 1.0+ wrap, 1.0); glColor4f( 1.0, 1.0, 1.0, 0.0);glVertex3f( x2,  y2,  z2);
		 glMultiTexCoord2f(GL_TEXTURE0, 0.0+wrap, 1.0);  glColor4f( 1.0, 1.0, 1.0, 0.0);glVertex3f( x3,  y3,  z3);
     glEnd();

	}
	
	void splash_quad3(GLfloat x0,GLfloat y0, GLfloat z0,GLfloat x1,GLfloat y1,GLfloat z1,GLfloat x2,GLfloat y2, GLfloat z2,GLfloat x3,GLfloat y3,GLfloat z3)
{
	glBegin(GL_QUADS);
		 glMultiTexCoord2f(GL_TEXTURE0, 0.0+wrap, 1.0);  glColor4f( 1.0, 1.0, 1.0, 0.0);glVertex3f( x0,  y0,  z0);
		 glMultiTexCoord2f(GL_TEXTURE0, 0.0+wrap, 0.0);  glColor4f( 1.0, 1.0, 1.0, 0.0);glVertex3f( x1,  y1,  z1);
		 glMultiTexCoord2f(GL_TEXTURE0, 1.0+wrap, 0.0); glColor4f( 1.0, 1.0, 1.0, 0.0);glVertex3f( x2,  y2,  z2);
		 glMultiTexCoord2f(GL_TEXTURE0, 1.0+wrap, 1.0);  glColor4f( 1.0, 1.0, 1.0, 0.0);glVertex3f( x3,  y3,  z3);
     glEnd();

	}
	
GLvoid rglDrawSplash(GLuint b)
{
	rglMat4 mvm;
	
	rglMatrix4Identity(mvm);
	rglTranslate(mvm, 0.0,0.0,0.0);	
	rglPushMatrix(mvm,0);
	
	
	
		glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D,fon_tx0);
	glEnable(GL_TEXTURE_2D);
	glActiveTexture(GL_TEXTURE1);
	glDisable(GL_TEXTURE_2D);	
	splash_quad(  -10.0, -8.0,  -12.0,  10.0, -8.0,  -12.0,  10.0, 8.0, -12.0, -10.0, 8.0, -12.0);
	

	
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, tex0);
	glEnable(GL_TEXTURE_2D);
		
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D,tex1);
	glEnable(GL_TEXTURE_2D);	
	

		
	  glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_COMBINE); 
	  glTexEnvf(GL_TEXTURE_ENV, GL_COMBINE_RGB, GL_INTERPOLATE); 
	  glTexEnvf(GL_TEXTURE_ENV, GL_SOURCE0_RGB, GL_TEXTURE0); 
	  glTexEnvf(GL_TEXTURE_ENV, GL_SOURCE1_RGB, GL_TEXTURE);
	  glTexEnvf(GL_TEXTURE_ENV, GL_SOURCE2_RGB, GL_CONSTANT);
	  glTexEnvf(GL_TEXTURE_ENV, GL_OPERAND2_RGB, GL_SRC_ALPHA);
	
	

 
    glTexEnvfv(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, &texEnvColor.r);
 	rglSetBlendMode(13);
	splash_quad( 5.0, -1.5, -10.0, 8.5,  -1.5, -10.0, 8.5, 1.5,  -10.0, 5.0, 1.5, -10);
	
   

	
	
	
	glActiveTexture(GL_TEXTURE1);
	glDisable(GL_TEXTURE_2D);	
	rglSetBlendMode(23);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D,fon_tx1);
	splash_quad2(  -10.0, -8.0,  -12.0,  10.0, -8.0,  -12.0,  10.0, 8.0, -12.0, -10.0, 8.0, -12.0);
	

	rglSetBlendMode(b);
	rglPushTexture(top_tx, 0, 0, " ");
	splash_quad3(  5.0, 1.5,  -10.0,  8.5, 1.5,  -10.0, 1.0, 1.0,  0.0, -2.0, 1.0, 0.0);
	rglPushTexture(buttom_tx, 0, 0, " ");
	splash_quad3(  -2.0, -1.0,  0.0,  1.0, -1.0,  0.0,  8.5, -1.5,  -10.0, 5.0, -1.5,  -10.0);
	rglPushTexture(center_tx, 0, 0, " ");
	splash_quad2(  -2.0, -1.0,  0.0,  5.0, -1.5,  -10.0,  5.0, 1.5, -10.0, -2.0, 1.0, 0.0);
	
	
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D,title_tx0);
	glEnable(GL_TEXTURE_2D);
		
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D,title_tx1);
	glEnable(GL_TEXTURE_2D);
	rglSetBlendMode(27);
	splash_quad(  -1.2, -0.3,  -1.0,  0.8, -0.3,  -1.0,  0.8, 0.3, -1.0, -1.2, 0.3, -1.0);
	
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D,title_tx2);
	glEnable(GL_TEXTURE_2D);
	glActiveTexture(GL_TEXTURE1);
	glDisable(GL_TEXTURE_2D);	
	rglSetBlendMode(27);
	splash_quad(  -0.6, -1.0,  -1.0,  0.6, -1.0,  -1.0,  0.6, -0.9, -1.0, -0.6, -0.9, -1.0);
	glDisable(GL_BLEND);
	
	/*
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D,fon_tx);
	glEnable(GL_TEXTURE_2D);
	glActiveTexture(GL_TEXTURE1);
	glDisable(GL_TEXTURE_2D);	
	splash_quad(  -8.0, -6.0,  -12.0,  8.0, -6.0,  -12.0,  8.0, 6.0, -12.0, -8.0, 6.0, -12.0);
	* */
	}
	
GLvoid rglDrawSplash2(GLuint b)
{
	rglMat4 mvm;
	
	rglMatrix4Identity(mvm);
	rglTranslate(mvm, 0.0,0.0,0.0);	
	rglPushMatrix(mvm,0);
	
	

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D,fon_tx0);
	glEnable(GL_TEXTURE_2D);
	glActiveTexture(GL_TEXTURE1);
	glDisable(GL_TEXTURE_2D);	
	splash_quad(  -10.0, -8.0,  -12.0,  10.0, -8.0,  -12.0,  10.0, 8.0, -12.0, -10.0, 8.0, -12.0);	
	
	
	glActiveTexture(GL_TEXTURE1);
	glDisable(GL_TEXTURE_2D);	
	rglSetBlendMode(23);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D,fon_tx1);
	splash_quad2(  -10.0, -8.0,  -12.0,  10.0, -8.0,  -12.0,  10.0, 8.0, -12.0, -10.0, 8.0, -12.0);
	

	rglSetBlendMode(b);
	rglPushTexture(top_tx, 0, 0, " ");
	splash_quad3(  5.0, 1.5,  -10.0,  8.5, 1.5,  -10.0, 1.0, 1.0,  0.0, -2.0, 1.0, 0.0);
	rglPushTexture(buttom_tx, 0, 0, " ");
	splash_quad3(  -2.0, -1.0,  0.0,  1.0, -1.0,  0.0,  8.5, -1.5,  -10.0, 5.0, -1.5,  -10.0);
	rglPushTexture(center_tx, 0, 0, " ");
	splash_quad2(  -2.0, -1.0,  0.0,  5.0, -1.5,  -10.0,  5.0, 1.5, -10.0, -2.0, 1.0, 0.0);
	
	
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D,title_tx0);
	glEnable(GL_TEXTURE_2D);
		
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D,title_tx1);
	glEnable(GL_TEXTURE_2D);
	  glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_COMBINE); 
	  glTexEnvf(GL_TEXTURE_ENV, GL_COMBINE_RGB, GL_INTERPOLATE); 
	  glTexEnvf(GL_TEXTURE_ENV, GL_SOURCE0_RGB, GL_TEXTURE0); 
	  glTexEnvf(GL_TEXTURE_ENV, GL_SOURCE1_RGB, GL_TEXTURE);
	  glTexEnvf(GL_TEXTURE_ENV, GL_SOURCE2_RGB, GL_CONSTANT);
	  glTexEnvf(GL_TEXTURE_ENV, GL_OPERAND2_RGB, GL_SRC_ALPHA);
	
	

   //glActiveTexture(GL_TEXTURE1);
    glTexEnvfv(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, &texEnvColor.r);
	
	rglSetBlendMode(27);
	splash_quad(  -1.0, 0.3,  -1.0,  1.0, 0.3,  -1.0,  1.0, 0.6, -1.0, -1.0, 0.6, -1.0);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D,devel_tx1);
	glEnable(GL_TEXTURE_2D);
	glActiveTexture(GL_TEXTURE1);
	glDisable(GL_TEXTURE_2D);	
	rglSetBlendMode(27);
	splash_quad( -0.65, -0.6,  -1.0,  -0.15, -0.6,  -1.0,  -0.15, 0.1, -1.0, -0.65, 0.1, -1.0);
	glDisable(GL_BLEND);
	
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D,devel_tx0);
	glEnable(GL_TEXTURE_2D);
	glActiveTexture(GL_TEXTURE1);
	glDisable(GL_TEXTURE_2D);	
	rglSetBlendMode(27);
	splash_quad( 0.25, -0.6,  -1.0,  0.75, -0.6,  -1.0,  0.75, 0.1, -1.0, 0.25, 0.1, -1.0);
	glDisable(GL_BLEND);
	

	}

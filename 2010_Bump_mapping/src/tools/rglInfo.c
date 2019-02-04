#include "rglInfo.h"

char *Font01="../data/fonts/arial.ttf";
char *Font02="../data/fonts/DejaVuSans.ttf";

void rglInitTable(char *caption )
{
	
	font_24b=TTFBuildFont(Font02, 36, 1);	
	//glColor4ub(128,255,255,0);
	glColor4f(0.5,0.8,1.0,1.0);
	SDL_string_texture_create(font_24b,(char *) caption, 2,&table_info);
	
		};


void rglInitInfo(char *caption )
{
	font_13=TTFBuildFont("../data/fonts/arial.ttf", 13, 0);	
	font_13b=TTFBuildFont("../data/fonts/arial.ttf", 13, 1);	
	glColor4f(1.0,1.0,1.0,1.0);
	SDL_string_texture_create(font_13b,(char *) caption, 2,&info_tx01);
	

	SDL_string_texture_create(font_13b,  (char *) glGetString(GL_VENDOR), 2,&info_tx03);
	SDL_string_texture_create(font_13b, (char *) glGetString(GL_RENDERER), 2,&info_tx04);
	SDL_string_texture_create(font_13b,(char *) glGetString(GL_VERSION), 2,&info_tx05);
	SDL_string_texture_create(font_13b, (char *)  glGetString(GL_SHADING_LANGUAGE_VERSION),2,&info_tx06);
	SDL_string_texture_create(font_13b, "F1 - Parallax Mapping",2, &info_tx07);
	SDL_string_texture_create(font_13b, "F2 - Step Parallax Mapping",2, &info_tx08);
	SDL_string_texture_create(font_13b, "F3 - Parallax Occlusion Mapping",2, &info_tx09);
	SDL_string_texture_create(font_13b, "F4 - Normal Mapping",2, &info_tx10);
	SDL_string_texture_create(font_13b, "P - Enable/Disable Shader",2, &info_tx11);
	SDL_string_texture_create(font_13b, "Left Button Mouse - Rotate Plane",2, &info_tx12);
	SDL_string_texture_create(font_13b, "Quit  -  Press ESC ", 2, &info_tx13);
	};
	
	
void rglUpdateInfo(char *text)
{
	glColor4f(1.0,1.0,0.5,1.0);
	SDL_string_texture_create(font_13b, text, 2, &info_tx02);
	}	;

void rglUpdateTable(char *text)
{
	glColor4f(0.5,0.8,1.0,1.0);
	SDL_string_texture_create(font_24b, text, 2, &table_info);
	}	;
	
void rglDeleteInfo()
{
	TTF_CloseFont( font_13 );
	TTF_CloseFont( font_13b );
	TTF_CloseFont( font_24b );
	};

void rglDrawTable(GLint width, GLint height, GLfloat ix, GLfloat iy, GLuint shader)
{
	
GLbyte light;

rglMat4 info_pvm, info_mvm;
 
   rglSetProjection( width,  height, RGL_PROJECTION_ORTHO,  info_pvm);
   rglMatrix4Identity( info_mvm);
	light=glIsEnabled(GL_LIGHTING);
	if (light == GL_TRUE) 
		glDisable(GL_LIGHTING);
		
	
	glUseProgram(shader); 
	glUniformMatrix4fv(glGetUniformLocation(shader,"pmatrix"), 1,GL_FALSE, &info_pvm[0]);
	glUniformMatrix4fv(glGetUniformLocation(shader,"mvmatrix"), 1,GL_FALSE,& info_mvm[0]);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D,table_info);
	glUniform1i(glGetUniformLocation(shader,"Texture"), 0);
	rglSetBlendMode(13);
	SDL_string_render2D( ix,iy,&table_info);
	
	glUseProgram(0);


	glColor4ub(255,255,255,255);
	if (light == GL_TRUE )
		glEnable(GL_LIGHTING);
	
	glDisable(GL_BLEND);
	};



void rglDrawInfo(GLint width, GLint height, GLfloat dx, GLfloat dy, GLuint shader)
{
	
GLbyte light;
GLint ix,iy;
rglMat4 info_pvm, info_mvm;
  // ogl_set_projection(SCREEN_WIDTH,SCREEN_HEIGHT, GL_PROJECTION_ORTHO);
   rglSetProjection( width,  height, RGL_PROJECTION_ORTHO,  info_pvm);
   rglMatrix4Identity( info_mvm);
	light=glIsEnabled(GL_LIGHTING);
	if (light == GL_TRUE) 
		glDisable(GL_LIGHTING);
	
	//glColor4ub(128,128,255,0);
	glColor4f(0.0,0.0,0.1,0);
	ix=0+dx;	
	iy=height-20;	
	
	glUseProgram(shader); 
	glUniformMatrix4fv(glGetUniformLocation(shader,"pmatrix"), 1,GL_FALSE, &info_pvm[0]);
	glUniformMatrix4fv(glGetUniformLocation(shader,"mvmatrix"), 1,GL_FALSE,& info_mvm[0]);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D,info_tx01);
	glUniform1i(glGetUniformLocation(shader,"Texture"), 0);
	rglSetBlendMode(13);
	SDL_string_render2D( ix,iy,&info_tx01);
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&info_tx02);
	//glColor4ub(128,128,255,0);
	
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&info_tx03);
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&info_tx04);
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&info_tx05);
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&info_tx06);
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&info_tx07);
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&info_tx08);
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&info_tx09);
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&info_tx10);
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&info_tx11);
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&info_tx12);
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&info_tx13);
	glUseProgram(0);


	glColor4ub(255,255,255,255);
	if (light == GL_TRUE )
		glEnable(GL_LIGHTING);
	//ogl_set_projection(SCREEN_WIDTH,SCREEN_HEIGHT, GL_PROJECTION_PERSPECTIVE);
	glDisable(GL_BLEND);
	};
	
void rglDrawInfo_ffp()
{
	
	
	};

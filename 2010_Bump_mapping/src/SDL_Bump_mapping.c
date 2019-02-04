#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <SDL/SDL.h>
#include <math.h>


#include "tools/rglTexture.h"
#include "tools/rglMesh3D.h"
#include "tools/rglShader.h"
#include "tools/rglMaterial.h"
#include "tools/rglMath3D.h"
#include "tools/rglInfo.h"
#include "tools/rglRender.h"

#define SCREEN_CAPTION  "OpenGL with SDL : Bump Mapping"
#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 768
#define SCREEN_BPP    24
#define EVENT_FPS 1
#define EVENT_ANIM 2
#define REDRAW_TIME    0
#define FPS_TIME    1000
#define ANIM_TIME    20

const SDL_VideoInfo *VideoInfo;
const char *ICON="../data/icons/sdl.bmp";


const char *VertexSource1="../data/shaders/BaseShaderMinTex.vs";
const char *FragmentSource1="../data/shaders/BaseShaderMinTex.fs";

const char *VertexSource2="../data/shaders/parallax_0.vs";
const char *FragmentSource2="../data/shaders/parallax_0.fs";

const char *VertexSource3="../data/shaders/steep-parallax_mapping.vs";
const char *FragmentSource3="../data/shaders/steep-parallax_mapping.fs";

const char *VertexSource4="../data/shaders/parallax-occlusion_mapping.vs";
const char *FragmentSource4="../data/shaders/parallax-occlusion_mapping.fs";

const char *VertexSource5="../data/shaders/Normal_mapping.vs";
const char *FragmentSource5="../data/shaders/Normal_mapping.fs";


char *Txf00="../data/textures/rockwall.tga";
char *Txf01="../data/textures/rockwall_height.tga";
char *Txf02="../data/textures/rockwall_normal.tga";
char *Txf03="../data/textures/rockwall_relief.tga";


char *Txf12="../data/textures/bricks_color_map.jpg";
char *Txf13="../data/textures/bricks_height_map.tga";
char *Txf14="../data/textures/bricks_normal_map.tga";

char *Txf04="../data/textures/title.tga"; //title
char *Txf05="../data/textures/author.tga";//author
char *Txf06="../data/textures/c_plus.tga";//logo
char *Txf07="../data/textures/opengl_logo.tga";//logo
char *Txf08="../data/textures/SDL_logo.tga";//logo
char *Txf09="../data/textures/UbuntuLogo.tga";//logo
char *Txf10="../data/textures/linux_logo.tga";//logo
char *Txf11="../data/textures/footer.tga";//logo

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
char caption[70]=SCREEN_CAPTION;
GLfloat tx=0.0;
GLfloat ty=0.0;
GLfloat tz=0.0;
GLfloat sx=1.0;
GLfloat sy=1.0;
GLfloat sz=1.0;
GLfloat rx=0.0;
GLfloat ry=0.0;
GLfloat rz=0.0;
GLfloat angle=0.0;
GLuint material=3;
GLuint blend_mode=0;
GLuint shader=0;
GLuint tex_00,tex_01,  tex_02,  tex_03, tex_04,tex_05,tex_06,tex_07,tex_08,tex_09,tex_10,tex_11,tex_12,tex_13,tex_14;

GLsizei width;
GLsizei height;

GLuint vs1, vs2, vs3, vs4, vs5, /* Vertex Shader */
		   fs1, fs2, fs3, fs4, fs5,/* Fragment Shader */
		   gs1, gs2, gs3, gs4, gs5,/* Geometry Shader */
		   sp1, sp2, sp3, sp4, sp5; /* Shader Program */
		  

GLfloat eye_x=0.0,eye_y=0.0,eye_z=0.1,center_x=0.0,center_y=0.0,center_z=0.0,top_x=0.0,top_y=1.0,top_z=0.0;



rglLight Light0;
rglMaterial Material0;


rglMat4 mvm_1; //model-view matrix
rglMat4 mvm_2;


rglMat4 pvm; //projection matrix
rglMat3 nm; //normal matrix
rglMat4 pmvm; //projection model view matrix

rglVec4 eyeVector;
GLint parallax=1;
GLint scena=0;


rglVec3    rot= { 0.0, 0.0, 0.0 };
int         mouseOldX = 0;
int         mouseOldY = 0;

GLvoid app_anim_proc( void)
{  
	angle=angle+0.3;	
}


GLuint app_anim_timer_callback(GLuint interval, GLvoid *param)
{
//SDL_Event user_event_1;
event.type = SDL_USEREVENT;
event.user.code = EVENT_ANIM;
event.user.data1 = &app_anim_proc;
event.user.data2 = NULL;
SDL_PushEvent(&event);
return interval;
}


GLvoid app_fps_counter(void)
{	
	fps_avr=frame_avr*1000/SDL_GetTicks();
	fps=frame_sec*1.0;
	frame_sec=0;
	sprintf(caption,"%s  FPS_avr : %5.2f  FPS_sec : %5.2f" , SCREEN_CAPTION, fps_avr,fps);
	SDL_WM_SetCaption(caption,NULL);
	sprintf(fps_str,"FPS_avr : %5.2f  FPS_sec : %5.2f" , fps_avr,fps);
	glColor4ub(255,0,0,0);	
	rglUpdateInfo(fps_str);
}

GLuint app_fps_timer_callback(GLuint interval, GLvoid *param)
{
//SDL_Event user_event_1;
event.type = SDL_USEREVENT;
event.user.code = EVENT_FPS;
event.user.data1 = &app_fps_counter;
event.user.data2 = NULL;
SDL_PushEvent(&event);
return interval;
}

GLvoid app_quit( GLint returnCode )
{  
	rglDeleteInfo();
	glDeleteShader(vs1);
	glDeleteShader(fs1);
	glDeleteProgram(sp1);

	SDL_RemoveTimer(anim_timer);
	SDL_RemoveTimer(fps_timer);
	SDL_Quit( );  
	exit( returnCode );
}


GLvoid ogl_init_shader(  )
{
 	vs1=rglInitVertexShader(VertexSource1);
    fs1 = rglInitFragmentShader(FragmentSource1);	
	sp1 = rglInitProgramShader(&vs1, &gs1, &fs1);
	
	vs2=rglInitVertexShader(VertexSource2);
    fs2 = rglInitFragmentShader(FragmentSource2);	
	sp2 = rglInitProgramShader(&vs2, &gs2, &fs2);
	
	vs3=rglInitVertexShader(VertexSource3);
    fs3 = rglInitFragmentShader(FragmentSource3);	
	sp3 = rglInitProgramShader(&vs3, &gs3, &fs3);
	
	vs4=rglInitVertexShader(VertexSource4);
    fs4 = rglInitFragmentShader(FragmentSource4);	
	sp4 = rglInitProgramShader(&vs4, &gs4, &fs4);
	
	vs5=rglInitVertexShader(VertexSource5);
    fs5 = rglInitFragmentShader(FragmentSource5);	
	sp5 = rglInitProgramShader(&vs5, &gs5, &fs5);	
	
	}

GLvoid ogl_switch_uniform(GLuint planet_shader)
{
switch (planet_shader )
{
	case 0:
		glUniform4fv(glGetUniformLocation(sp2,"lightPosition"), 1, &Light0.Lposition.x);
		glUniform4fv(glGetUniformLocation(sp2,"ambientColor"), 1,  &Light0.Lambient.x);
		glUniform4fv(glGetUniformLocation(sp2,"diffuseColor"), 1, &Light0.Ldiffuse.x);
		glUniform1i(glGetUniformLocation(sp2,"colorMap"), 0);	
		glUniform1i(glGetUniformLocation(sp2,"heightMap"), 1);
		glUniform1i(glGetUniformLocation(sp2,"normalMap"), 2);
	break;	 	
	case 1:	
		eyeVector = rglVector4Set(eye_x,eye_y,eye_z,1.0);
		glUniform4fv(glGetUniformLocation(sp3,"eye"), 1, &eyeVector.x);
		glUniform4fv(glGetUniformLocation(sp3,"light"), 1, &Light0.Lposition.x);
		glUniform1f(glGetUniformLocation(sp3,"scale"), 0.025);
		glUniform1i(glGetUniformLocation(sp3,"colorMap"), 0);	
		glUniform1i(glGetUniformLocation(sp3,"heightMap"), 1);
	break;	 
	case 2:	
		eyeVector = rglVector4Set(eye_x,eye_y,eye_z,1.0);
		glUniform4fv(glGetUniformLocation(sp4,"eye"), 1, &eyeVector.x);
		glUniform4fv(glGetUniformLocation(sp4,"light"), 1, &Light0.Lposition.x);
		glUniform1f(glGetUniformLocation(sp4,"scale"), 0.03);
		glUniform1i(glGetUniformLocation(sp4,"colorMap"), 0);	
		glUniform1i(glGetUniformLocation(sp4,"heightMap"), 1);
		glUniform1i(glGetUniformLocation(sp4,"normalMap"), 2);
			break;	 
	case 3:	
		glUniform1i(glGetUniformLocation(sp5,"colorMap"), 0);	
		glUniform1i(glGetUniformLocation(sp5,"normalMap"), 2);
	
	break;		

			
	default:			break;
}
}



GLvoid ogl_init_textures(  )
{
	rglLoad_Texture(Txf00, &tex_00, txAnisotropic_16, GL_DECAL, GL_REPEAT,  txS3TC_DXT1,GL_TRUE);
	rglLoad_Texture(Txf01, &tex_01, txAnisotropic_16, GL_DECAL, GL_REPEAT,  txGL_COMPRESS,GL_TRUE);
	rglLoad_Texture(Txf02, &tex_02, txAnisotropic_16, GL_DECAL, GL_REPEAT,  txS3TC_DXT1 ,GL_TRUE);
	rglLoad_Texture(Txf03, &tex_03, txAnisotropic_16, GL_DECAL, GL_REPEAT,  txS3TC_DXT1,GL_TRUE);
	rglLoad_Texture(Txf04, &tex_04, txAnisotropic_16, GL_DECAL, GL_CLAMP_TO_EDGE,  txS3TC_DXT1,GL_TRUE);
	rglLoad_Texture(Txf05, &tex_05, txAnisotropic_16, GL_DECAL, GL_CLAMP_TO_EDGE,  txS3TC_DXT1,GL_TRUE);
	rglLoad_Texture(Txf06, &tex_06, txAnisotropic_16, GL_DECAL, GL_CLAMP_TO_EDGE,  txS3TC_DXT1,GL_TRUE);
	rglLoad_Texture(Txf07, &tex_07, txAnisotropic_16, GL_DECAL, GL_CLAMP_TO_EDGE,  txS3TC_DXT1,GL_TRUE);
	rglLoad_Texture(Txf08, &tex_08, txAnisotropic_16, GL_DECAL, GL_CLAMP_TO_EDGE,  txS3TC_DXT1,GL_TRUE);
	rglLoad_Texture(Txf09, &tex_09, txAnisotropic_16, GL_DECAL, GL_CLAMP_TO_EDGE,  txS3TC_DXT1,GL_TRUE);
	rglLoad_Texture(Txf10, &tex_10, txAnisotropic_16, GL_DECAL, GL_CLAMP_TO_EDGE,  txS3TC_DXT1,GL_TRUE);
	rglLoad_Texture(Txf11, &tex_11, txAnisotropic_16, GL_DECAL, GL_CLAMP_TO_EDGE,  txS3TC_DXT1,GL_TRUE);
	rglLoad_Texture(Txf12, &tex_12, txAnisotropic_16, GL_DECAL, GL_REPEAT,  txS3TC_DXT1,GL_TRUE);
	rglLoad_Texture(Txf13, &tex_13, txAnisotropic_16, GL_DECAL, GL_REPEAT,  txS3TC_DXT1,GL_TRUE);
	rglLoad_Texture(Txf14, &tex_14, txAnisotropic_16, GL_DECAL, GL_REPEAT,  txS3TC_DXT1,GL_TRUE);
	
	}



 GLvoid ogl_init_models(  )
{

	}
 
 
GLvoid ogl_init(  )
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClearDepth(1.0);
	glShadeModel(GL_SMOOTH);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc( GL_LEQUAL );
	glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST );	
	
	rglInitLight();
 	rglInitLight_2(&Light0);
	rglSetMaterial_2(material, &Material0);
	rglSetMaterial(material);
	ogl_init_shader();
	ogl_init_textures();
	ogl_init_models();	
}


void  quads_draw(GLfloat x, GLfloat y, GLfloat z)
{
		glBegin(GL_QUADS);
			glNormal3f(0.0,0.0,1.0);
			glMultiTexCoord3f ( GL_TEXTURE1,  1.0, 0.0, 0.0);
			glMultiTexCoord3f ( GL_TEXTURE2,  0.0, 1.0, 0.0);
			glMultiTexCoord2f (GL_TEXTURE0,0.0,0.0);glColor3ub(255,0,0); glVertex3f(-1.0*x, -1.0*y, -1.0*z);
			glMultiTexCoord2f(GL_TEXTURE0,1.0,0.0); glColor3ub(255,0,255); glVertex3f(1.0*x, -1.0*y, -1.0*z);
			glMultiTexCoord2f(GL_TEXTURE0,1.0,1.0); glColor3ub(0,255,0) ; glVertex3f(1.0*x, 1.0*y, -1.0*z) ;
			glMultiTexCoord2f(GL_TEXTURE0,0.0,1.0); glColor3ub(0,255,255); glVertex3f(-1.0*x, 1.0*y, -1.0*z);
     	glEnd();
}


void  quads_draw2(GLfloat x, GLfloat y, GLfloat z)
{
		glBegin(GL_QUADS);
			glNormal3f(0.0,0.0,1.0);
			glMultiTexCoord3f ( GL_TEXTURE1,  1.0, 0.0, 0.0);
			glMultiTexCoord3f ( GL_TEXTURE2,  0.0, 1.0, 0.0);
			glMultiTexCoord2f (GL_TEXTURE0,0.0,0.0); glColor3ub(255,0,0); glVertex3f(-1.0*x, -1.0*y, -1.0*z);
			glMultiTexCoord2f(GL_TEXTURE0,4.0,0.0); glColor3ub(255,0,255); glVertex3f(1.0*x, -1.0*y, -1.0*z);
			glMultiTexCoord2f(GL_TEXTURE0,4.0,4.0); glColor3ub(0,255,0) ; glVertex3f(1.0*x, 1.0*y, -1.0*z) ;
			glMultiTexCoord2f(GL_TEXTURE0,0.0,4.0); glColor3ub(0,255,255); glVertex3f(-1.0*x, 1.0*y, -1.0*z);
     	glEnd();
}


GLvoid  ogl_scena0_draw()
{

	 rglMatrix4Identity(mvm_1);
	 glLoadMatrixf(mvm_1);
	 rglLookAt(mvm_1, rglVector3Set(eye_x,eye_y,eye_z), rglVector3Set(center_x,center_y,center_z), rglVector3Set(top_x,top_y,top_z));
	 rglTranslate(mvm_1,tx,ty,tz-5);
	 glMultMatrixf(mvm_1);	
		glActiveTexture(GL_TEXTURE2);
		glBindTexture(GL_TEXTURE_2D, tex_02); 
		glEnable(GL_TEXTURE_2D);		
			
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, tex_01); 
		glEnable(GL_TEXTURE_2D);	
					
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, tex_00); 
		glEnable(GL_TEXTURE_2D);			
	
		
		glUseProgram( sp5); 
		rglMatrix4Identity(mvm_2);		
		rglTranslate(mvm_2,tx,ty,tz);
		glMultMatrixf(mvm_2);
		ogl_switch_uniform(3);
		quads_draw2(5.0,  5.0, 0.0);
		glUseProgram(0);
		
		
		glActiveTexture(GL_TEXTURE2);
		glDisable(GL_TEXTURE_2D);	
		
		glActiveTexture(GL_TEXTURE1);
		glDisable(GL_TEXTURE_2D);
		
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, tex_04); 
		glEnable(GL_TEXTURE_2D);	
		
		
		rglMatrix4Identity(mvm_2);
		glLoadMatrixf(mvm_1);
		rglTranslate(mvm_2,tx,ty+1.0,tz);
		glMultMatrixf(mvm_2);
		rglSetBlendMode(17);
		quads_draw(4.0,  1.0, 0.0);
		glDisable(GL_BLEND);
	
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, tex_05); 		
		
		
		rglMatrix4Identity(mvm_2);
		glLoadMatrixf(mvm_1);
		rglTranslate(mvm_2,tx+2.0,ty-1.8,tz);
		glMultMatrixf(mvm_2);
		rglSetBlendMode(17);
		quads_draw(2.0,  0.5, 0.0);
		glDisable(GL_BLEND);
		
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, tex_06); 		
		
		
		rglMatrix4Identity(mvm_2);
		glLoadMatrixf(mvm_1);
		rglTranslate(mvm_2,tx+3.6,ty+2.8,tz);
		glMultMatrixf(mvm_2);
		rglSetBlendMode(17);
		quads_draw(0.4,  0.4, 0.0);
		glDisable(GL_BLEND);
		
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, tex_07); 		
		
		
		rglMatrix4Identity(mvm_2);
		glLoadMatrixf(mvm_1);
		rglTranslate(mvm_2,tx+2.2,ty+2.8,tz);
		glMultMatrixf(mvm_2);
		rglSetBlendMode(17);
		quads_draw(0.8,  0.3, 0.0);
		glDisable(GL_BLEND);
		
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, tex_08); 		
		
		
		rglMatrix4Identity(mvm_2);
		glLoadMatrixf(mvm_1);
		rglTranslate(mvm_2,tx-0.1,ty+2.8,tz);
		glMultMatrixf(mvm_2);
		rglSetBlendMode(17);
		quads_draw(0.8,  0.4, 0.0);
		glDisable(GL_BLEND);
		
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, tex_09); 		
		
		
		rglMatrix4Identity(mvm_2);
		glLoadMatrixf(mvm_1);
		rglTranslate(mvm_2,tx-1.8,ty+2.9,tz);
		glMultMatrixf(mvm_2);
		rglSetBlendMode(17);
		quads_draw(0.4,  0.4, 0.0);
		glDisable(GL_BLEND);
		
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, tex_10); 		
		
		
		rglMatrix4Identity(mvm_2);
		glLoadMatrixf(mvm_1);
		rglTranslate(mvm_2,tx-3.3,ty+2.9,tz);
		glMultMatrixf(mvm_2);
		rglSetBlendMode(17);
		quads_draw(0.4,  0.5, 0.0);
		glDisable(GL_BLEND);
		
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, tex_11); 		
		
		
		rglMatrix4Identity(mvm_2);
		glLoadMatrixf(mvm_1);
		rglTranslate(mvm_2,tx-0.0,ty-3.0,tz);
		glMultMatrixf(mvm_2);
		rglSetBlendMode(17);
		quads_draw(3.2,  0.5, 0.0);
		glDisable(GL_BLEND);
	}



GLvoid  ogl_paralax_draw()
{

	 rglMatrix4Identity(mvm_1);
	 glLoadMatrixf(mvm_1);
	 rglLookAt(mvm_1, rglVector3Set(eye_x,eye_y,eye_z), rglVector3Set(center_x,center_y,center_z), rglVector3Set(top_x,top_y,top_z));
	 glMultMatrixf(mvm_1);
	 	glActiveTexture(GL_TEXTURE3);
		glBindTexture(GL_TEXTURE_2D, tex_14); 
		glEnable(GL_TEXTURE_2D);	
			
		glActiveTexture(GL_TEXTURE2);
		glBindTexture(GL_TEXTURE_2D, tex_14); 
		glEnable(GL_TEXTURE_2D);		
			
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, tex_13); 
		glEnable(GL_TEXTURE_2D);	
					
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, tex_12); 
		glEnable(GL_TEXTURE_2D);			
	
		glUseProgram( sp2); 
		rglMatrix4Identity(mvm_2);		
		rglTranslate(mvm_2,tx,ty,tz+0.5);
		rglRotate(mvm_2, 45, 0.0,1.0,0.0);
		
		glMultMatrixf(mvm_2);
		ogl_switch_uniform(0);
		
		quads_draw2(3.0,2.0,2.0);
		glUseProgram(0);
		
		glUseProgram( sp2); 
		glLoadMatrixf(mvm_1);
		rglMatrix4Identity(mvm_2);		
		rglTranslate(mvm_2,tx,ty,tz+0.5);
		rglRotate(mvm_2, -45, 0.0,1.0,0.0);
		
		glMultMatrixf(mvm_2);
		ogl_switch_uniform(0);
		
		quads_draw2(3.0,2.0,2.0);
		glUseProgram(0);
		
		glUseProgram( sp2); 
		glLoadMatrixf(mvm_1);
		rglMatrix4Identity(mvm_2);		
		rglTranslate(mvm_2,tx,ty,tz-1.0);
		rglRotate(mvm_2,rot.x, 1.0,0.0,0.0);
		rglRotate(mvm_2,rot.y, 0.0,1.0,0.0);
		rglRotate(mvm_2,rot.z, 0.0,0.0,1.0);
		glMultMatrixf(mvm_2);
		ogl_switch_uniform(0);
		
		quads_draw(1.0,1.0,0.0);
		glUseProgram(0);
		
		
		
	}

GLvoid  ogl_paralax_draw_ffp()
{

	 rglMatrix4Identity(mvm_1);
	 glLoadMatrixf(mvm_1);
	 rglLookAt(mvm_1, rglVector3Set(eye_x,eye_y,eye_z), rglVector3Set(center_x,center_y,center_z), rglVector3Set(top_x,top_y,top_z));
	 glMultMatrixf(mvm_1);
		
		glActiveTexture(GL_TEXTURE3);
		glDisable(GL_TEXTURE_2D);	
		
		glActiveTexture(GL_TEXTURE2);
		glDisable(GL_TEXTURE_2D);	
		
		glActiveTexture(GL_TEXTURE1);
		glDisable(GL_TEXTURE_2D);
	
		glActiveTexture(GL_TEXTURE0);		
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, tex_12);
	
		 
		rglMatrix4Identity(mvm_2);		
		rglTranslate(mvm_2,tx,ty,tz+0.5);
		rglRotate(mvm_2, 45, 0.0,1.0,0.0);
		
		glMultMatrixf(mvm_2);	
		quads_draw2(3.0,2.0,2.0);	
		
		
		glLoadMatrixf(mvm_1);
		rglMatrix4Identity(mvm_2);		
		rglTranslate(mvm_2,tx,ty,tz+0.5);
		rglRotate(mvm_2, -45, 0.0,1.0,0.0);
		
		glMultMatrixf(mvm_2);		
		quads_draw2(3.0,2.0,2.0);		
		
		
		glLoadMatrixf(mvm_1);
		rglMatrix4Identity(mvm_2);		
		rglTranslate(mvm_2,tx,ty,tz-1.0);
		rglRotate(mvm_2,rot.x, 1.0,0.0,0.0);
		rglRotate(mvm_2,rot.y, 0.0,1.0,0.0);
		rglRotate(mvm_2,rot.z, 0.0,0.0,1.0);
		glMultMatrixf(mvm_2);
		
		quads_draw(1.0,1.0,0.0);
		
		
		
		
	}


GLvoid  ogl_step_paralax_draw()
{

	 rglMatrix4Identity(mvm_1);
	 glLoadMatrixf(mvm_1);
	 rglLookAt(mvm_1, rglVector3Set(eye_x,eye_y,eye_z), rglVector3Set(center_x,center_y,center_z), rglVector3Set(top_x,top_y,top_z));
	 glMultMatrixf(mvm_1);
	 	glActiveTexture(GL_TEXTURE3);
		glBindTexture(GL_TEXTURE_2D, tex_03); 
		glEnable(GL_TEXTURE_2D);	
			
		glActiveTexture(GL_TEXTURE2);
		glBindTexture(GL_TEXTURE_2D, tex_02); 
		glEnable(GL_TEXTURE_2D);		
			
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, tex_01); 
		glEnable(GL_TEXTURE_2D);	
					
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, tex_00); 
		glEnable(GL_TEXTURE_2D);			
	
		glUseProgram( sp3); 
		rglMatrix4Identity(mvm_2);		
		rglTranslate(mvm_2,tx,ty,tz+0.5);
		rglRotate(mvm_2, 45, 0.0,1.0,0.0);
		
		glMultMatrixf(mvm_2);
		ogl_switch_uniform(1);
		
		quads_draw2(3.0,2.0,2.0);
		glUseProgram(0);
		
		glUseProgram( sp3); 
		glLoadMatrixf(mvm_1);
		rglMatrix4Identity(mvm_2);		
		rglTranslate(mvm_2,tx,ty,tz+0.5);
		rglRotate(mvm_2, -45, 0.0,1.0,0.0);
		
		glMultMatrixf(mvm_2);
		ogl_switch_uniform(1);
		
		quads_draw2(3.0,2.0,2.0);
		glUseProgram(0);
		
		glUseProgram( sp3); 
		glLoadMatrixf(mvm_1);
		rglMatrix4Identity(mvm_2);		
		rglTranslate(mvm_2,tx,ty,tz-1.0);
		rglRotate(mvm_2,rot.x, 1.0,0.0,0.0);
		rglRotate(mvm_2,rot.y, 0.0,1.0,0.0);
		rglRotate(mvm_2,rot.z, 0.0,0.0,1.0);
		glMultMatrixf(mvm_2);
		ogl_switch_uniform(1);
		
		quads_draw(1.0,1.0,0.0);
		glUseProgram(0);
		
		
		
	}

GLvoid  ogl_step_paralax_draw_ffp()
{

	 rglMatrix4Identity(mvm_1);
	 glLoadMatrixf(mvm_1);
	 rglLookAt(mvm_1, rglVector3Set(eye_x,eye_y,eye_z), rglVector3Set(center_x,center_y,center_z), rglVector3Set(top_x,top_y,top_z));
	 glMultMatrixf(mvm_1);
		
		glActiveTexture(GL_TEXTURE3);
		glDisable(GL_TEXTURE_2D);	
		
		glActiveTexture(GL_TEXTURE2);
		glDisable(GL_TEXTURE_2D);	
		
		glActiveTexture(GL_TEXTURE1);
		glDisable(GL_TEXTURE_2D);
	
		glActiveTexture(GL_TEXTURE0);		
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, tex_00);
	
		 
		rglMatrix4Identity(mvm_2);		
		rglTranslate(mvm_2,tx,ty,tz+0.5);
		rglRotate(mvm_2, 45, 0.0,1.0,0.0);
		
		glMultMatrixf(mvm_2);	
		quads_draw2(3.0,2.0,2.0);	
		
		
		glLoadMatrixf(mvm_1);
		rglMatrix4Identity(mvm_2);		
		rglTranslate(mvm_2,tx,ty,tz+0.5);
		rglRotate(mvm_2, -45, 0.0,1.0,0.0);
		
		glMultMatrixf(mvm_2);		
		quads_draw2(3.0,2.0,2.0);		
		
		
		glLoadMatrixf(mvm_1);
		rglMatrix4Identity(mvm_2);		
		rglTranslate(mvm_2,tx,ty,tz-1.0);
		rglRotate(mvm_2,rot.x, 1.0,0.0,0.0);
		rglRotate(mvm_2,rot.y, 0.0,1.0,0.0);
		rglRotate(mvm_2,rot.z, 0.0,0.0,1.0);
		glMultMatrixf(mvm_2);
		
		quads_draw(1.0,1.0,0.0);
			
	}


GLvoid  ogl_paralax_occlusion_draw()
{

	 rglMatrix4Identity(mvm_1);
	 glLoadMatrixf(mvm_1);
	 rglLookAt(mvm_1, rglVector3Set(eye_x,eye_y,eye_z), rglVector3Set(center_x,center_y,center_z), rglVector3Set(top_x,top_y,top_z));
	 glMultMatrixf(mvm_1);
	 	glActiveTexture(GL_TEXTURE3);
		glBindTexture(GL_TEXTURE_2D, tex_14); 
		glEnable(GL_TEXTURE_2D);	
			
		glActiveTexture(GL_TEXTURE2);
		glBindTexture(GL_TEXTURE_2D, tex_14); 
		glEnable(GL_TEXTURE_2D);		
			
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, tex_13); 
		glEnable(GL_TEXTURE_2D);	
					
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, tex_12); 
		glEnable(GL_TEXTURE_2D);			
	
		glUseProgram( sp4); 
		rglMatrix4Identity(mvm_2);		
		rglTranslate(mvm_2,tx,ty,tz+0.5);
		rglRotate(mvm_2, 45, 0.0,1.0,0.0);
		
		glMultMatrixf(mvm_2);
		ogl_switch_uniform(2);
		
		quads_draw2(3.0,2.0,2.0);
		glUseProgram(0);
		
		glUseProgram( sp4); 
		glLoadMatrixf(mvm_1);
		rglMatrix4Identity(mvm_2);		
		rglTranslate(mvm_2,tx,ty,tz+0.5);
		rglRotate(mvm_2, -45, 0.0,1.0,0.0);
		
		glMultMatrixf(mvm_2);
		ogl_switch_uniform(2);
		
		quads_draw2(3.0,2.0,2.0);
		glUseProgram(0);
		
		glUseProgram( sp4); 
		glLoadMatrixf(mvm_1);
		rglMatrix4Identity(mvm_2);		
		rglTranslate(mvm_2,tx,ty,tz-1.0);
		rglRotate(mvm_2,rot.x, 1.0,0.0,0.0);
		rglRotate(mvm_2,rot.y, 0.0,1.0,0.0);
		rglRotate(mvm_2,rot.z, 0.0,0.0,1.0);
		glMultMatrixf(mvm_2);
		ogl_switch_uniform(2);
		
		quads_draw(1.0,1.0,0.0);
		glUseProgram(0);
		
		
		
	}

GLvoid  ogl_paralax_occlusion_draw_ffp()
{

	 rglMatrix4Identity(mvm_1);
	 glLoadMatrixf(mvm_1);
	 rglLookAt(mvm_1, rglVector3Set(eye_x,eye_y,eye_z), rglVector3Set(center_x,center_y,center_z), rglVector3Set(top_x,top_y,top_z));
	 glMultMatrixf(mvm_1);
		
		glActiveTexture(GL_TEXTURE3);
		glDisable(GL_TEXTURE_2D);	
		
		glActiveTexture(GL_TEXTURE2);
		glDisable(GL_TEXTURE_2D);	
		
		glActiveTexture(GL_TEXTURE1);
		glDisable(GL_TEXTURE_2D);
	
		glActiveTexture(GL_TEXTURE0);		
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, tex_12);
	
		 
		rglMatrix4Identity(mvm_2);		
		rglTranslate(mvm_2,tx,ty,tz+0.5);
		rglRotate(mvm_2, 45, 0.0,1.0,0.0);
		
		glMultMatrixf(mvm_2);	
		quads_draw2(3.0,2.0,2.0);	
		
		
		glLoadMatrixf(mvm_1);
		rglMatrix4Identity(mvm_2);		
		rglTranslate(mvm_2,tx,ty,tz+0.5);
		rglRotate(mvm_2, -45, 0.0,1.0,0.0);
		
		glMultMatrixf(mvm_2);		
		quads_draw2(3.0,2.0,2.0);		
		
		
		glLoadMatrixf(mvm_1);
		rglMatrix4Identity(mvm_2);		
		rglTranslate(mvm_2,tx,ty,tz-1.0);
		rglRotate(mvm_2,rot.x, 1.0,0.0,0.0);
		rglRotate(mvm_2,rot.y, 0.0,1.0,0.0);
		rglRotate(mvm_2,rot.z, 0.0,0.0,1.0);
		glMultMatrixf(mvm_2);
		
		quads_draw(1.0,1.0,0.0);
		
		
	}


GLvoid  ogl_normal_draw()
{

	 rglMatrix4Identity(mvm_1);
	 glLoadMatrixf(mvm_1);
	 rglLookAt(mvm_1, rglVector3Set(eye_x,eye_y,eye_z), rglVector3Set(center_x,center_y,center_z), rglVector3Set(top_x,top_y,top_z));
	 glMultMatrixf(mvm_1);
	 	glActiveTexture(GL_TEXTURE3);
		glBindTexture(GL_TEXTURE_2D, tex_14); 
		glEnable(GL_TEXTURE_2D);	
			
		glActiveTexture(GL_TEXTURE2);
		glBindTexture(GL_TEXTURE_2D, tex_14); 
		glEnable(GL_TEXTURE_2D);		
			
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, tex_13); 
		glEnable(GL_TEXTURE_2D);	
					
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, tex_12); 
		glEnable(GL_TEXTURE_2D);			
	
		glUseProgram( sp5); 
		rglMatrix4Identity(mvm_2);		
		rglTranslate(mvm_2,tx,ty,tz+0.5);
		rglRotate(mvm_2, 45, 0.0,1.0,0.0);
		
		glMultMatrixf(mvm_2);
		ogl_switch_uniform(3);
		
		quads_draw2(3.0,2.0,2.0);
		glUseProgram(0);
		
		glUseProgram( sp5); 
		glLoadMatrixf(mvm_1);
		rglMatrix4Identity(mvm_2);		
		rglTranslate(mvm_2,tx,ty,tz+0.5);
		rglRotate(mvm_2, -45, 0.0,1.0,0.0);
		
		glMultMatrixf(mvm_2);
		ogl_switch_uniform(3);
		
		quads_draw2(3.0,2.0,2.0);
		glUseProgram(0);
		
		glUseProgram( sp5); 
		glLoadMatrixf(mvm_1);
		rglMatrix4Identity(mvm_2);		
		rglTranslate(mvm_2,tx,ty,tz-1.0);
		rglRotate(mvm_2,rot.x, 1.0,0.0,0.0);
		rglRotate(mvm_2,rot.y, 0.0,1.0,0.0);
		rglRotate(mvm_2,rot.z, 0.0,0.0,1.0);
		glMultMatrixf(mvm_2);
		ogl_switch_uniform(3);
		
		quads_draw(1.0,1.0,0.0);
		glUseProgram(0);
		
		
		
	}

GLvoid  ogl_normal_draw_ffp()
{

	 rglMatrix4Identity(mvm_1);
	 glLoadMatrixf(mvm_1);
	 rglLookAt(mvm_1, rglVector3Set(eye_x,eye_y,eye_z), rglVector3Set(center_x,center_y,center_z), rglVector3Set(top_x,top_y,top_z));
	 glMultMatrixf(mvm_1);
		
		glActiveTexture(GL_TEXTURE3);
		glDisable(GL_TEXTURE_2D);	
		
		glActiveTexture(GL_TEXTURE2);
		glDisable(GL_TEXTURE_2D);	
		
		glActiveTexture(GL_TEXTURE1);
		glDisable(GL_TEXTURE_2D);
	
		glActiveTexture(GL_TEXTURE0);		
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, tex_12);
	
		 
		rglMatrix4Identity(mvm_2);		
		rglTranslate(mvm_2,tx,ty,tz+0.5);
		rglRotate(mvm_2, 45, 0.0,1.0,0.0);
		
		glMultMatrixf(mvm_2);	
		quads_draw2(3.0,2.0,2.0);	
		
		
		glLoadMatrixf(mvm_1);
		rglMatrix4Identity(mvm_2);		
		rglTranslate(mvm_2,tx,ty,tz+0.5);
		rglRotate(mvm_2, -45, 0.0,1.0,0.0);
		
		glMultMatrixf(mvm_2);		
		quads_draw2(3.0,2.0,2.0);		
		
		
		glLoadMatrixf(mvm_1);
		rglMatrix4Identity(mvm_2);		
		rglTranslate(mvm_2,tx,ty,tz-1.0);
		rglRotate(mvm_2,rot.x, 1.0,0.0,0.0);
		rglRotate(mvm_2,rot.y, 0.0,1.0,0.0);
		rglRotate(mvm_2,rot.z, 0.0,0.0,1.0);
		glMultMatrixf(mvm_2);
		
		quads_draw(1.0,1.0,0.0);	
		
	}

GLvoid  ogl_draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
	if (scena==1)	
		switch (shader)
		{
			case 0:
				 if (parallax==1)
					 ogl_paralax_draw();
				
				 if (parallax==0)
					ogl_paralax_draw_ffp();
				break;
			 case 1:
				 if (parallax==1)
					 ogl_step_paralax_draw();
				
				 if (parallax==0)
					ogl_step_paralax_draw_ffp();
				break;
				case 2:
				 if (parallax==1)
					 ogl_paralax_occlusion_draw();
				
				 if (parallax==0)
					ogl_paralax_occlusion_draw_ffp();
				break;
				case 3:
				 if (parallax==1)
					 ogl_normal_draw();
				
				 if (parallax==0)
					ogl_normal_draw_ffp();
				break;
			}
		 else
			ogl_scena0_draw();
		if (scena==1)
			{
				rglDrawInfo(SCREEN_WIDTH,SCREEN_HEIGHT, 10.0, 15.0,sp1);
				rglDrawTable(SCREEN_WIDTH,SCREEN_HEIGHT, 350, 10, sp1);
			 }
		else
			rglDrawTable(SCREEN_WIDTH,SCREEN_HEIGHT, 200, 300, sp1);
		frame_avr=frame_avr+1;
		frame_sec=frame_sec+1;
		SDL_GL_SwapBuffers( );

}

GLint app_key_pressed(SDL_keysym *keysym)
{	
switch ( keysym->sym )
{
	case SDLK_ESCAPE:
		app_quit( 0 );
	break;
	case SDLK_F1:
		shader=0;
		rglUpdateTable("Parallax Mapping");
		scena=1;
	break;
	case SDLK_F2:
		shader=1;
		rglUpdateTable("Step Parallax Mapping");
		scena=1;
	break;
	case SDLK_F3:
		shader=2;
		rglUpdateTable("Parallax Occlusion Mapping");
		scena=1;
	break;
	case SDLK_F4:
		shader=3;
		rglUpdateTable("Normal Mapping");
		scena=1;
	break;
	case SDLK_p: 
	  	 if (parallax==1)
			parallax=0;	
		else
			parallax=1;	
	 break;	

	default:
		break;
}
    return 1;
}

GLint app_mouse_button_pressed(SDL_MouseButtonEvent *button)
{	
switch ( button->button )
{
	    case SDL_BUTTON_LEFT :;break;
		case SDL_BUTTON_MIDDLE :;break;
		case SDL_BUTTON_RIGHT :;break;
		case SDL_BUTTON_WHEELUP :;break;
		case SDL_BUTTON_WHEELDOWN :;break;			
}
  return 1;
}

GLint app_mouse_motion(SDL_MouseMotionEvent *motion)
{	
	if (motion->state == SDL_PRESSED)
	{
	rot.y -= ((mouseOldY - motion->y) * 180.0f) / 200.0f;
    rot.z -= ((mouseOldX - motion->x) * 180.0f) / 200.0f;
    rot.x  = 0.0;

    if ( rot.z > 360 )
        rot.z -= 360;

    if ( rot.z < -360 )
        rot.z += 360;

    if ( rot.y > 360 )
        rot.y -= 360;

    if ( rot.y < -360 )
        rot.y += 360;
		

}
    mouseOldX = motion->x;
    mouseOldY = motion->y;

  return 1;
}

SDL_Surface *app_sdl_ogl_init( )
{
	SDL_Surface *surface;
    if ( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_TIMER ) < 0 )	{
	   SDL_GetError( ) ;
	    app_quit( 1 );	}
    VideoInfo = SDL_GetVideoInfo( );
    if ( !VideoInfo )	{
	   SDL_GetError( ) ;
	    app_quit( 1 );	}
    VideoFlags  = SDL_OPENGL;         
    VideoFlags |= SDL_GL_DOUBLEBUFFER; 
    VideoFlags |= SDL_HWPALETTE;       
    VideoFlags |= SDL_RESIZABLE;     
    if ( VideoInfo->hw_available )
	VideoFlags |= SDL_HWSURFACE;
    else
	VideoFlags |= SDL_SWSURFACE;
    if ( VideoInfo->blit_hw )
	VideoFlags |= SDL_HWACCEL;
	VideoFlagsFullscreen =VideoFlags;
	 VideoFlagsFullscreen |= SDL_FULLSCREEN;
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
	SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );
	SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
	SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 4);

   
   surface = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, VideoFlagsFullscreen );
	SDL_WM_SetCaption(SCREEN_CAPTION,NULL);
	SDL_WM_SetIcon(SDL_LoadBMP(ICON), NULL);
    if ( !surface )
	    app_quit( 1 );
    return surface;
   SDL_FreeSurface(surface);
}


GLvoid app_events(void)
{
	void (*event_exec_fps) (void);
	void (*event_exec_anim) (void);
  while ( SDL_PollEvent( &event ) )
	{
		switch( event.type )
		{	
		case SDL_QUIT:
			app_quit( 0 );
		break;
		case SDL_VIDEORESIZE:
			screen = SDL_SetVideoMode( event.resize.w, event.resize.h,SCREEN_BPP, VideoFlags );
			rglReshape(SCREEN_WIDTH,SCREEN_HEIGHT, RGL_PROJECTION_PERSPECTIVE, pvm);
			break;
		case SDL_KEYDOWN:
		  app_key_pressed( &event.key.keysym );
		break;
		case SDL_MOUSEBUTTONDOWN:
		  app_mouse_button_pressed( &event.button );
		break;
		case SDL_MOUSEBUTTONUP:
		 app_mouse_button_pressed( &event.button );
		break;
		case SDL_MOUSEMOTION:
		   app_mouse_motion( &event.motion);
		break;

		case SDL_USEREVENT:
				switch (event.user.code)
				{
					case EVENT_FPS:
										
					event_exec_fps = event.user.data1;
					event_exec_fps();
					break;
					case EVENT_ANIM:
						
					event_exec_anim = event.user.data1;
					event_exec_anim();
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

screen = app_sdl_ogl_init(); 	

rglReshape(SCREEN_WIDTH,SCREEN_HEIGHT, RGL_PROJECTION_PERSPECTIVE, pvm);
rglReshapeFFP(SCREEN_WIDTH,SCREEN_HEIGHT, RGL_PROJECTION_PERSPECTIVE);

fps_timer = SDL_AddTimer(FPS_TIME,  app_fps_timer_callback, NULL);
anim_timer = SDL_AddTimer(ANIM_TIME,  app_anim_timer_callback, NULL);

GLenum err = glewInit();
if (GLEW_OK != err)
{

  fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
}
else
fprintf(stdout, "Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));

ogl_init();	
rglInitInfo(SCREEN_CAPTION);
rglInitTable("Для запуска нажмите F1-F4");

while ( done )
	{	  
	app_events(); 
	
    ogl_draw();
  //  SDL_Delay(REDRAW_TIME );
   	}


    app_quit( 0 );
    return( 0 );

}

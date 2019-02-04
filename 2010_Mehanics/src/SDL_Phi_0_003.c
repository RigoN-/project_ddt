
#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <SDL/SDL.h>
#include <math.h>

#include "tools/rglTexture.h"
#include "tools/rglMesh3D.h"
#include "tools/rglFigures.h"
#include "tools/rglScena_Draw_03.h"
#include "tools/rglScena_Draw_01.h"
#include "tools/rglScena_Draw_07.h"
#include "tools/rglScena_Draw_14.h"
#include "tools/rglScena_Draw_19.h"
#include "tools/rglScena_Draw_18.h"
#include "tools/rglScena_Draw_book.h"
#include "tools/rglSplash.h"
#include "tools/rglShader.h"
#include "tools/rglMaterial.h"
#include "tools/rglMath3D.h"
#include "tools/rglInfo.h"
#include "tools/rglRender.h"


#define SCREEN_CAPTION  "Mehanics. Lab. task for Phisics."
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
const char *VertexSource2="../data/shaders/BaseShaderMin.vs";
const char *FragmentSource2="../data/shaders/BaseShaderMin.fs";

const char *VertexSource3="../data/shaders/dirLightDiff.vs";
const char *FragmentSource3="../data/shaders/dirLightDiff.fs";
const char *VertexSource4="../data/shaders/dirLightAmbDiff.vs";
const char *FragmentSource4="../data/shaders/dirLightAmbDiff.fs";


const char *VertexSource5="../data/shaders/dirLightAmbDiffSpec.vs";
const char *FragmentSource5="../data/shaders/dirLightAmbDiffSpec.fs";
const char *VertexSource6="../data/shaders/dirLightAmbDiffSpecPix.vs";
const char *FragmentSource6="../data/shaders/dirLightAmbDiffSpecPix.fs";



char *Txf04="../data/textures/yplastic.jpg";
char *Txf05="../data/textures/stal.jpg";
char *Txf06="../data/textures/CAMARO.JPG";
char *Txf08="../data/textures/gplastic.jpg";
char *Txf09="../data/textures/shkala.jpg";
char *Txf10="../data/textures/wplastic.jpg";
char *Txf11="../data/textures/shkala2.jpg";




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
char caption[128]=SCREEN_CAPTION;

int scena_switch=0;

GLfloat tx=0.0;
GLfloat ty=-25.0;
GLfloat tz=-60.0;
GLfloat sx=1.0;
GLfloat sy=1.0;
GLfloat sz=1.0;
GLfloat rx=0.0;
GLfloat ry=0.0;
GLfloat rz=0.0;
GLfloat theta=1.52;
 GLfloat phi=0.78;
GLuint mouseOldX=1;
GLuint mouseOldY=1;
GLfloat angle=0.0;

GLint polygon_mode_switch=1;

GLuint material=12;
GLuint prog_shader=4;
GLuint blend_mode=23;
GLuint tex_01,  tex_fon, tex_mars, yplastic, bplastic, stal;
GLuint gplastic, wood, shkala,wplastic, shkala2, speed_2,rasstoy;
GLuint tex_01,tex_02,tex_13,tex_14,tex_15,tex_16,tex_17,tex_23,tex_24,tex_20,tex_21,tex_19,tex_18,tex_22,tex_25,tex_obl_face_1,tex_obl_back,tex_obl_torec_1,help_r_tex,help_l_tex,title_tex;
GLboolean info_enable = GL_TRUE;
unsigned char *tixels;
GLsizei width;
GLsizei height;
const char *vsSource;
const char *fsSource;
GLuint vs1, vs2, vs3, vs4, vs5, vs6,/* Vertex Shader */
		   fs1, fs2, fs3, fs4, fs5, fs6,/* Fragment Shader */
		   gs1, gs2, gs3, gs4, gs5, gs6,/* Geometry Shader */
		   sp1, sp2, sp3, sp4, sp5, sp6; /* Shader Program */
GLfloat waveTime = 0.0,
			waveWidth = 0.1,
			waveHeight = 3.0,
			waveFreq = 0.1;
GLfloat eye_x=0.0,eye_y=0.0,eye_z=30.0,center_x=0.0,center_y=30.0,center_z=0.0,top_x=0.0,top_y=1.0,top_z=0.0;
GLUquadricObj *planet;
GLfloat attenuation[3] = {0.0001, 0.00001, 0.0001};

rglLight Light0;
rglMaterial Material0;


rglMat4 mvm_1; //model-view matrix
rglMat4 mvm_2;
rglMat4 mvm_3;

rglMat4 pvm; //projection matrix
rglMat3 nm; //normal matrix
rglMat4 pmvm; //projection model view matrix

GLvoid app_anim_proc( void)
{  
	angle=angle+0.3;
	
	if (scena_switch==7)
	{
		book_anim_proc();
	}
	
	if (scena_switch==0)
	{
	splash_anim(  );
	}
	if (scena_switch==8)
	{
	splash_anim(  );
	}
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
	
	vs6=rglInitVertexShader(VertexSource6);
    fs6 = rglInitFragmentShader(FragmentSource6);	
	sp6 = rglInitProgramShader(&vs6, &gs6, &fs6);
	
	
	}

GLuint ogl_switch_shader(GLuint prog_shader)
{
switch (prog_shader )
{
	case 0:	return(sp2);	break;	 	
	case 1:		return(sp3);	break;	 
	case 2:		return(sp4);	break;	 
	case 3:		return(sp5);	break;		
	case 4:		return(sp6);	break;	
	default:		return(sp2);		break;
}
}

GLvoid ogl_switch_uniform(GLuint prog_shader)
{
switch (prog_shader )
{
	case 0:
		glUniformMatrix4fv(glGetUniformLocation(sp2,"pmatrix"), 1,GL_FALSE, &pvm[0]);		
		glUniform3fv(glGetUniformLocation(sp2,"LightPosition"), 1, &Light0.Lposition.x);
		glBindTexture(GL_TEXTURE_2D, tex_mars); 
		glUniform1i(glGetUniformLocation(sp2,"EarthTexture"), 0);
	break;	 	
	case 1:	
		glUniformMatrix4fv(glGetUniformLocation(sp3,"pmatrix"), 1,GL_FALSE, &pvm[0]);		
		glUniform3fv(glGetUniformLocation(sp3,"LightPosition"), 1, &Light0.Lposition.x);
		glUniform4fv(glGetUniformLocation(sp3,"LightDiffuse"), 1, &Light0.Ldiffuse.x);
		glUniform4fv(glGetUniformLocation(sp3,"MaterialDiffuse"), 1, &Material0.Mdiffuse.x);
		glBindTexture(GL_TEXTURE_2D, tex_mars); 
		glUniform1i(glGetUniformLocation(sp3,"EarthTexture"), 0);
	break;	 
	case 2:	
		glUniformMatrix4fv(glGetUniformLocation(sp4,"pmatrix"), 1,GL_FALSE, &pvm[0]);		
		glUniform3fv(glGetUniformLocation(sp4,"LightPosition"), 1, &Light0.Lposition.x);
		glUniform4fv(glGetUniformLocation(sp4,"LightAmbient"), 1, &Light0.Lambient.x);
		glUniform4fv(glGetUniformLocation(sp4,"LightDiffuse"), 1, &Light0.Ldiffuse.x);
		glUniform4fv(glGetUniformLocation(sp4,"MaterialAmbient"), 1, &Material0.Mambient.x);
		glUniform4fv(glGetUniformLocation(sp4,"MaterialDiffuse"), 1, &Material0.Mdiffuse.x);
		glBindTexture(GL_TEXTURE_2D, tex_mars); 
		glUniform1i(glGetUniformLocation(sp4,"Texture"), 0);
	
			break;	 
	case 3:	
		glUniformMatrix4fv(glGetUniformLocation(sp5,"pmatrix"), 1,GL_FALSE, &pvm[0]);		
		glUniform3fv(glGetUniformLocation(sp5,"LightPosition"), 1, &Light0.Lposition.x);
		glUniform4fv(glGetUniformLocation(sp5,"LightAmbient"), 1, &Light0.Lambient.x);
		glUniform4fv(glGetUniformLocation(sp5,"LightDiffuse"), 1, &Light0.Ldiffuse.x);
		glUniform4fv(glGetUniformLocation(sp5,"LightSpecular"), 1, &Light0.Lspecular.x);
		glUniform4fv(glGetUniformLocation(sp5,"MaterialAmbient"), 1, &Material0.Mambient.x);
		glUniform4fv(glGetUniformLocation(sp5,"MaterialDiffuse"), 1, &Material0.Mdiffuse.x);
		glUniform4fv(glGetUniformLocation(sp5,"MaterialSpecular"), 1, &Material0.Mspecular.x);
		glUniform1fv(glGetUniformLocation(sp5,"MaterialShininess"), 1, &Material0.Mshininess);
		glBindTexture(GL_TEXTURE_2D, tex_mars); 
		glUniform1i(glGetUniformLocation(sp5,"Texture"), 0);
	
	break;		
	case 4:
		glUniformMatrix4fv(glGetUniformLocation(sp6,"pmatrix"), 1,GL_FALSE, &pvm[0]);		
		glUniform3fv(glGetUniformLocation(sp6,"LightPosition"), 1, &Light0.Lposition.x);
		glUniform4fv(glGetUniformLocation(sp6,"LightAmbient"), 1, &Light0.Lambient.x);
		glUniform4fv(glGetUniformLocation(sp6,"LightDiffuse"), 1, &Light0.Ldiffuse.x);
		glUniform4fv(glGetUniformLocation(sp6,"LightSpecular"), 1, &Light0.Lspecular.x);
		glUniform4fv(glGetUniformLocation(sp6,"MaterialAmbient"), 1, &Material0.Mambient.x);
		glUniform4fv(glGetUniformLocation(sp6,"MaterialDiffuse"), 1, &Material0.Mdiffuse.x);
		glUniform4fv(glGetUniformLocation(sp6,"MaterialSpecular"), 1, &Material0.Mspecular.x);
		glUniform1fv(glGetUniformLocation(sp6,"MaterialShininess"), 1, &Material0.Mshininess);
		glBindTexture(GL_TEXTURE_2D, tex_mars); 
		glUniform1i(glGetUniformLocation(sp5,"Texture"), 0);
	
				break;	
	default:			break;
}
}

GLvoid  ogl_draw_load()
{
	   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	   
	   rglDrawLoad(SCREEN_WIDTH,SCREEN_HEIGHT, 350.0, 350.0, sp1);
	   SDL_GL_SwapBuffers( );

}

GLvoid ogl_init_textures(  )
{
	rglUpdateLoad("Загрузка....0%");
	ogl_draw_load();
	
	rglUpdateLoad("Загрузка....8%");
	ogl_draw_load();
	rglLoad_Texture(Txf04, &yplastic, txAnisotropic_16, GL_DECAL, GL_REPEAT,txGL_COMPRESS,GL_TRUE);
	rglLoad_Texture(Txf05, &stal, txAnisotropic_16, GL_DECAL, GL_REPEAT,  txS3TC_DXT1,GL_TRUE);
	rglUpdateLoad("Загрузка....15%");
	ogl_draw_load();
	rglLoad_Texture(Txf06, &bplastic, txAnisotropic_16, GL_DECAL, GL_REPEAT,txGL_COMPRESS,GL_TRUE);
	rglLoad_Texture(Txf08, &gplastic, txAnisotropic_16, GL_DECAL, GL_REPEAT,txGL_COMPRESS,GL_TRUE);
	rglUpdateLoad("Загрузка....25%");
	ogl_draw_load();
	rglLoad_Texture(Txf09, &shkala, txAnisotropic_16, GL_DECAL, GL_REPEAT,txGL_COMPRESS,GL_TRUE);
	rglLoad_Texture(Txf10, &wplastic, txAnisotropic_16, GL_DECAL, GL_REPEAT,txGL_COMPRESS,GL_TRUE);
	rglLoad_Texture(Txf11, &shkala2, txAnisotropic_16, GL_DECAL, GL_REPEAT,txGL_COMPRESS,GL_TRUE);
	rglUpdateLoad("Загрузка....32%");
	ogl_draw_load();
	
	rglUpdateLoad("Загрузка....44%");
	ogl_draw_load();
	book_ogl_init_textures(  );
	rglUpdateLoad("Загрузка....74%");
	ogl_draw_load();
	splash_init_textures(  );
	rglUpdateLoad("Загрузка....100%");
	ogl_draw_load();
	}
	



 GLvoid ogl_init_models(  )
{

	}
 
 
GLvoid ogl_init(  )
{
	glClearColor(0.15, 0.15, 0.2, 1.0);
	glClearDepth(1.0);
	glShadeModel(GL_SMOOTH);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
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
	eye_x=-tz*sin(phi)*cos(theta);
	eye_z=-tz*sin(phi)*sin(theta);
	eye_y=-tz*cos(phi);
}


void  quads_draw(GLfloat x, GLfloat y, GLfloat z)
{
		glBegin(GL_QUADS);
			glTexCoord2f(0.0,0.0); glColor3ub(255,0,0); glVertex3f(-1.0*x, -1.0*y, -1.0*z);
			glTexCoord2f(1.0,0.0); glColor3ub(255,0,255); glVertex3f(1.0*x, -1.0*y, -1.0*z);
			glTexCoord2f(1.0,1.0); glColor3ub(0,255,0) ; glVertex3f(1.0*x, 1.0*y, -1.0*z) ;
			glTexCoord2f(0.0,1.0); glColor3ub(0,255,255); glVertex3f(-1.0*x, 1.0*y, -1.0*z);
     	glEnd();
}


GLvoid  ogl_space_draw()
{
	
	    rglMatrix4Identity(mvm_1);		
		rglTranslate(mvm_1,tx,ty,-55);	
		
		glUseProgram(sp1); 
		glUniformMatrix4fv(glGetUniformLocation(sp1,"pmatrix"), 1,GL_FALSE, &pvm[0]);
		glUniformMatrix4fv(glGetUniformLocation(sp1,"mvmatrix"), 1,GL_FALSE,&mvm_1[0]);
		
		glColor3ub(255,255,255);
		glEnable(GL_TEXTURE_2D);	
		glBindTexture(GL_TEXTURE_2D, speed_2);
		glUniform1i(glGetUniformLocation(sp1,"Texture"), 0);

	
		
		glUseProgram(0);
	
	}


GLvoid  ogl_planet_draw()
{
	
		
		
		glUseProgram( ogl_switch_shader(prog_shader)); 
		rglMatrix4Identity(mvm_1);		
		rglTranslate(mvm_1,tx,ty,tz+45);	
		rglRotate(mvm_1,0.0, 1.0,0.0,0.0);	
		
		rglMatrixNormal(nm,mvm_1);
		glLoadMatrixf(mvm_1);
	    ogl_switch_uniform(prog_shader);
		
	
	glUseProgram(0);
	
	
	
	}

GLvoid  ogl_book_draw()
{
		//glUseProgram( ogl_switch_shader(prog_shader)); 
		rglMatrix4Identity(mvm_1);		
		switch (scena_switch)
		{
		case 7:Scena_book(mvm_1, pvm, sp1);break;
	    
		default: 
		break;
		}
		
		//glUseProgram(0);
	
	}




GLvoid  ogl_draw()
{
	   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	   
	 	glDisable(GL_TEXTURE_2D);
		rglMatrix4Identity(mvm_1);		
		rglLookAt(mvm_1, rglVector3Set(eye_x,eye_y,eye_z), rglVector3Set(center_x,center_y,center_z), rglVector3Set(top_x,top_y,top_z));
		glLoadMatrixf(mvm_1);	
		glUseProgram( ogl_switch_shader(prog_shader)); 
	    ogl_switch_uniform(prog_shader);
		
		switch (scena_switch)
		{
		case 0:glUseProgram(0);rglDrawSplash(blend_mode);break;	
		case 1:Scena_Draw_01(mvm_1,0.05,shkala,wplastic,yplastic,gplastic,stal,bplastic,ogl_switch_shader(prog_shader), sp1);break;
		case 2:Scena_Draw_03(mvm_1,yplastic,gplastic,stal,bplastic,ogl_switch_shader(prog_shader),sp1);break;	    
		case 3:Scena_Draw_07(mvm_1,0.05,wplastic,shkala,shkala2,yplastic,gplastic,stal,bplastic,ogl_switch_shader(prog_shader), sp1);break;
		case 4:Scena_Draw_14(mvm_1,0.05,shkala2,shkala,wplastic,yplastic,gplastic,stal,bplastic,ogl_switch_shader(prog_shader), sp1);break;
		case 5:Scena_Draw_19(mvm_1,0.05,shkala2,shkala,wplastic,yplastic,gplastic,stal,bplastic,ogl_switch_shader(prog_shader), sp1);break;
		case 6:Scena_Draw_18(mvm_1,0.05,wplastic,shkala,shkala2,yplastic,gplastic,stal,bplastic,ogl_switch_shader(prog_shader), sp1);break;
		case 7:glUseProgram(0); rglMatrix4Identity(mvm_1);Scena_book(mvm_1, pvm, sp1);break;	
		case 8:glUseProgram(0);rglDrawSplash2(blend_mode);break;	
		default: 	break;
		}
		
		glUseProgram(0);


		if ((scena_switch > 0)	 && 		(scena_switch < 7))
			rglDrawInfo(SCREEN_WIDTH,SCREEN_HEIGHT, 670.0, 18.0, sp1, blend_mode);					
		
			 


		
		
		glDisable(GL_LIGHTING);	
		glDisable(GL_TEXTURE_2D);
 
		frame_avr=frame_avr+1;
		frame_sec=frame_sec+1;
		waveTime += waveFreq;
		SDL_GL_SwapBuffers( );

}

GLint app_key_pressed(SDL_keysym *keysym)
{	
	
	switch (scena_switch)
		{
		case 0:break;	
		case 1: Scena_Draw_01_key_pressed(keysym);break;
		case 2: Scena_Draw_03_key_pressed(keysym);break;	    
		case 3:Scena_Draw_07_key_pressed(keysym);break;
		case 4:Scena_Draw_14_key_pressed(keysym);break;
		case 5:Scena_Draw_19_key_pressed(keysym);break;
		case 6:Scena_Draw_18_key_pressed(keysym);break;
		case 7:Scena_Draw_book_key_pressed(keysym);break;
		default: 	break;
		}
	








switch ( keysym->sym )
{
	case SDLK_ESCAPE:
		app_quit( 0 );
	break;
	 case SDLK_F1:
	 rglInitResult1( );
	 scena_switch=1;
	 break;
	 
	  case SDLK_F2:
	  rglInitResult3( );
	  scena_switch=2;	
		
	 break;
	 
	 case SDLK_F3:
	  rglInitResult7( );
	  scena_switch=3;	
		
	 break;
	 
	  case SDLK_F4:
	  rglInitResult14( );
	  scena_switch=4;	
		
	 break;
	 
	 case SDLK_F5:
	  rglInitResult19( );
	  scena_switch=5;	
		
	 break;
	 
	  case SDLK_F6:
	  rglInitResult18( );
	  scena_switch=6;	
		
	 break;
	 
	  case SDLK_F11:
	    
	  scena_switch=8;	
		
	 break;
	 
	 
	  case SDLK_F12:
	    
	  scena_switch=7;	
		
	 break;
	 
	 case SDLK_RIGHT:ry=ry+1.0;break;
	 case SDLK_LEFT:ry=ry-1.0;break;
	 
	

	 case SDLK_UP:rx=rx+1.0; break;
	 case SDLK_DOWN:rx=rx-1.0;break;

	 case SDLK_PAGEUP:{sx=sx+0.1; sy=sy+0.1; sz=sz+0.1;} ;break;
	 case SDLK_PAGEDOWN:{sx=sx-0.1; sy=sy-0.1; sz=sz-0.1;} ;break;		
	 
	 case SDLK_e:	eye_x=-tz*sin(0.78)*cos(1.52);	eye_z=-tz*sin(0.78)*sin(1.52);eye_y=-tz*cos(0.78);rx=0.0; ry=0.0; rz=0.0, tz=-60;break;
	 case SDLK_i: 
		 if (info_enable)
			info_enable=GL_FALSE;
		 else
			info_enable=GL_TRUE;
	 break;
	 case SDLK_m: 
	  	 material++;	
		 if (material>29)
			material=0;		
		rglSetMaterial_2(material, &Material0);
		rglSetMaterial(material);
		 break;
	case SDLK_s: 
	  	 prog_shader++;	
		 if (prog_shader>4)
			prog_shader=0;	
	case SDLK_b: 
	  	 blend_mode+=1;	
		 if (blend_mode>109)
			blend_mode=0;		
		 break;
		 
	case SDLK_p: 
	  	 glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		
		 break;	 
		
		case SDLK_l: 
	  	 glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		
		 break;	 
		
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
		case SDL_BUTTON_WHEELUP :tz=tz-0.4;	eye_x=-tz*sin(phi)*cos(theta);	eye_z=-tz*sin(phi)*sin(theta);eye_y=-tz*cos(phi);break;
		case SDL_BUTTON_WHEELDOWN :tz=tz+0.4;eye_x=-tz*sin(phi)*cos(theta);	eye_z=-tz*sin(phi)*sin(theta);eye_y=-tz*cos(phi);break;			
}
  return 1;
}

GLint app_mouse_motion(SDL_MouseMotionEvent *motion)
{	

	if (motion->state == SDL_PRESSED)
	{
	phi+= ((GLfloat)(motion->yrel) /  (GLfloat) SCREEN_HEIGHT)*2*M_PI;


    theta+=  (GLfloat)(motion->xrel) / (GLfloat)SCREEN_WIDTH*2*M_PI;


    if (theta > 6.28 )
        theta =0.0I;

    if ( theta < -6.28 )
        theta = 0.0;

    if ( phi > 3.14 )
       phi = 0.0;

    if ( phi < -3.14 )
        phi = 0.0;
		

}
    mouseOldX = motion->x;
    mouseOldY = motion->y;
	eye_x=-tz*sin(phi)*cos(theta);
	eye_z=-tz*sin(phi)*sin(theta);
	eye_y=-tz*cos(phi);
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

if (glewIsSupported("GL_VERSION_2_0"))
			printf("Ready for OpenGL 2.0\n");
		else {
			printf("OpenGL 2.0 not supported\n");
			exit(1);
		}


rglInitInfo(SCREEN_CAPTION);
rglInitTable("Для начала работы нажмите F1");




rglInitLoad("Загрузка....0%");

ogl_init();	


while ( done )
	{	  
	app_events(); 
	
    ogl_draw();
   	}


    app_quit( 0 );
    return( 0 );

}

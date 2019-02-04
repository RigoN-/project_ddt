#include <GL/glew.h>
#include "rglScena_Draw_01.h"
#include "rglScena_Draw_03.h"
#include "rglScena_Draw_19.h"
#include "rglMesh3D.h"
#include "rglShader.h"
#include <SDL/SDL.h>

char *text19_1="|        1          |      0,03   |      0,07    |      0,04   |     0,03   |      0,06     |       0,032   | ";
char *text19_2="|        1          |      0,03   |      0,09    |      0,06   |     0,05   |      0,15     |       0,072   | ";
char *text19_3="|        1          |      0,03   |      0,1      |      0,07   |     0,06   |      0,24     |       0,098   | ";
char *text19_0="|        0          |      0        |      0         |      0        |     0        |        0        |          0       | ";

GLint scena_ddraw_19=1;

GLint Scena_Draw_19_key_pressed(SDL_keysym *keysym)
{	
	
switch ( keysym->sym )
{
    
	 case SDLK_1:rglUpdateResult19(text19_0,text19_0,text19_0);scena_ddraw_19=1; break;
	 case SDLK_2:rglUpdateResult19(text19_0,text19_0,text19_0);scena_ddraw_19=2; break;
	 case SDLK_3:rglUpdateResult19(text19_0,text19_0,text19_0);scena_ddraw_19=3; break;
	 case SDLK_4:rglUpdateResult19(text19_0,text19_0,text19_0);scena_ddraw_19=4; break;
	 case SDLK_5:rglUpdateResult19(text19_1,text19_0,text19_0);scena_ddraw_19=5; break;
	 case SDLK_6:rglUpdateResult19(text19_1,text19_0,text19_0);scena_ddraw_19=6; break;
	 case SDLK_7:rglUpdateResult19(text19_1,text19_2,text19_0);scena_ddraw_19=7; break;
	 case SDLK_8:rglUpdateResult19(text19_1,text19_2,text19_0);scena_ddraw_19=8; break;
	 case SDLK_9:rglUpdateResult19(text19_1,text19_2,text19_3);scena_ddraw_19=9; break;
	 case SDLK_0:rglUpdateResult19(text19_1,text19_2,text19_3);scena_ddraw_19=0; break;
	default:		break;
}
    return 1;
}

void Scena_Draw_19_1(rglMat4 mvm,GLuint h,GLuint shkala2,GLuint shkala, GLuint wplastic, GLuint yplastic, GLuint gplastic,GLuint stal,GLuint bplastic,GLuint shader)
{
	rglSetMaterial(3);
	rglMat4 mvm_op_19_1;
    rglMat4 mvm_work;
	
	rglMatrix4Identity(mvm_op_19_1);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_19_1,0.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_19_1);
	rglPushMatrix(mvm_work,shader);
	rglShtativ_Draw(mvm_work,yplastic,stal,bplastic,shader);
	
	rglMatrix4Identity(mvm_op_19_1);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_19_1,0.0,1.2,4.0);
	rglRotate(mvm_op_19_1,90.0,0.0,1.0,0.0);
	rglRotate(mvm_op_19_1,90.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_19_1);
	rglPushMatrix(mvm_work,shader);
	rglHook_2_Draw(mvm_work,0.5,0.1,32,32,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_19_1);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_19_1,-11.0,2.0,-4.0);
	rglRotate(mvm_op_19_1,90.0,0.0,0.0,1.0);
	rglMatrix4Multiply(mvm_work,mvm_op_19_1);
	rglPushMatrix(mvm_work,shader);
	rglNapravlenie_Draw(mvm_work,shkala2,gplastic,yplastic,shader);
	
	rglMatrix4Identity(mvm_op_19_1);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_19_1,0.0,-1.0,10.4);
	rglRotate(mvm_op_19_1,-90.0,1.0,0.0,0.0);
	rglRotate(mvm_op_19_1,90.0,0.0,0.0,1.0);
	rglMatrix4Multiply(mvm_work,mvm_op_19_1);
	rglPushMatrix(mvm_work,shader);
	rglDinamometr_Draw(mvm_work,0.05,shkala,wplastic,stal,shader);
 	
	rglMatrix4Identity(mvm_op_19_1);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_19_1,8.1,-1.0,12.9);
	rglRotate(mvm_op_19_1,-50.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_19_1);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_19_1);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_19_1,4.1,-1.0,12.9);
	rglRotate(mvm_op_19_1,50.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_19_1);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_19_1);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_19_1,10.1,-1.0,15.9);
	rglRotate(mvm_op_19_1,-50.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_19_1);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_19_1);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_19_1,7.1,-1.0,15.9);
	rglRotate(mvm_op_19_1,50.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_19_1);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
}

void Scena_Draw_19_2(rglMat4 mvm,GLuint h,GLuint shkala2,GLuint shkala, GLuint wplastic, GLuint yplastic, GLuint gplastic,GLuint stal,GLuint bplastic,GLuint shader)
{
	rglSetMaterial(3);
	rglMat4 mvm_op_19_2;
    rglMat4 mvm_work;
	
	rglMatrix4Identity(mvm_op_19_2);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_19_2,0.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_19_2);
	rglPushMatrix(mvm_work,shader);
	rglShtativ_Draw(mvm_work,yplastic,stal,bplastic,shader);
	
	rglMatrix4Identity(mvm_op_19_2);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_19_2,-10.0,36.8,3.5);
	rglRotate(mvm_op_19_2,90.0,0.0,1.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_19_2);
	rglPushMatrix(mvm_work,shader);
	rglHook_2_Draw(mvm_work,0.5,0.1,32,32,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_19_2);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_19_2,-11.0,2.0,-4.0);
	rglMatrix4Multiply(mvm_work,mvm_op_19_2);
	rglPushMatrix(mvm_work,shader);
	rglNapravlenie_Draw(mvm_work,shkala2,gplastic,yplastic,shader);
	
	rglMatrix4Identity(mvm_op_19_2);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_19_2,0.0,-1.0,10.4);
	rglRotate(mvm_op_19_2,-90.0,1.0,0.0,0.0);
	rglRotate(mvm_op_19_2,90.0,0.0,0.0,1.0);
	rglMatrix4Multiply(mvm_work,mvm_op_19_2);
	rglPushMatrix(mvm_work,shader);
	rglDinamometr_Draw(mvm_work,0.08,shkala,wplastic,stal,shader);
 	
	rglMatrix4Identity(mvm_op_19_2);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_19_2,8.1,-1.0,12.9);
	rglRotate(mvm_op_19_2,-50.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_19_2);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_19_2);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_19_2,4.1,-1.0,12.9);
	rglRotate(mvm_op_19_2,50.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_19_2);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_19_2);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_19_2,10.1,-1.0,16.9); 
	rglRotate(mvm_op_19_2,-50.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_19_2);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_19_2);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_19_2,7.1,-1.0,16.9);
	rglRotate(mvm_op_19_2,50.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_19_2);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
}

void Scena_Draw_19_3(rglMat4 mvm,GLuint h,GLuint shkala2,GLuint shkala, GLuint wplastic, GLuint yplastic, GLuint gplastic,GLuint stal,GLuint bplastic,GLuint shader)
{
	rglSetMaterial(3);
	rglMat4 mvm_op_19_3;
    rglMat4 mvm_work;
	
	rglMatrix4Identity(mvm_op_19_3);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_19_3,0.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_19_3);
	rglPushMatrix(mvm_work,shader);
	rglShtativ_Draw(mvm_work,yplastic,stal,bplastic,shader);
	
	rglMatrix4Identity(mvm_op_19_3);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_19_3,-10.0,36.8,3.5);
	rglRotate(mvm_op_19_3,90.0,0.0,1.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_19_3);
	rglPushMatrix(mvm_work,shader);
	rglHook_2_Draw(mvm_work,0.5,0.1,32,32,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_19_3);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_19_3,-11.0,2.0,-4.0);
	rglMatrix4Multiply(mvm_work,mvm_op_19_3);
	rglPushMatrix(mvm_work,shader);
	rglNapravlenie_Draw(mvm_work,shkala2,gplastic,yplastic,shader);
	
	rglMatrix4Identity(mvm_op_19_3);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_19_3,-10.0,20.55,2.4);
	rglMatrix4Multiply(mvm_work,mvm_op_19_3);
	rglPushMatrix(mvm_work,shader);
	rglDinamometr_Draw(mvm_work,0.05,shkala,wplastic,stal,shader);
 	
	rglMatrix4Identity(mvm_op_19_3);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_19_3,8.1,-1.0,12.9);
	rglRotate(mvm_op_19_3,-50.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_19_3);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_19_3);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_19_3,4.1,-1.0,12.9);
	rglRotate(mvm_op_19_3,50.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_19_3);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_19_3);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_19_3,10.1,-1.0,16.9);
	rglRotate(mvm_op_19_3,-50.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_19_3);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_19_3);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_19_3,7.1,-1.0,16.9);
	rglRotate(mvm_op_19_3,50.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_19_3);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
}

void Scena_Draw_19_4(rglMat4 mvm,GLuint h,GLuint shkala2,GLuint shkala, GLuint wplastic, GLuint yplastic, GLuint gplastic,GLuint stal,GLuint bplastic,GLuint shader)
{
	rglSetMaterial(3);
	rglMat4 mvm_op_19_4;
    rglMat4 mvm_work;
	
	rglMatrix4Identity(mvm_op_19_4);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_19_4,0.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_19_4);
	rglPushMatrix(mvm_work,shader);
	rglShtativ_Draw(mvm_work,yplastic,stal,bplastic,shader);
	
	rglMatrix4Identity(mvm_op_19_4);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_19_4,-10.0,36.8,3.5);
	rglRotate(mvm_op_19_4,90.0,0.0,1.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_19_4);
	rglPushMatrix(mvm_work,shader);
	rglHook_2_Draw(mvm_work,0.5,0.1,32,32,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_19_4);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_19_4,-11.0,2.0,-4.0);
	rglMatrix4Multiply(mvm_work,mvm_op_19_4);
	rglPushMatrix(mvm_work,shader);
	rglNapravlenie_Draw(mvm_work,shkala2,gplastic,yplastic,shader);
	
	rglMatrix4Identity(mvm_op_19_4);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_19_4,-10.0,20.55,2.4);
	rglMatrix4Multiply(mvm_work,mvm_op_19_4);
	rglPushMatrix(mvm_work,shader);
	rglDinamometr_Draw(mvm_work,0.05,shkala,wplastic,stal,shader);
 	
	rglMatrix4Identity(mvm_op_19_4);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_19_4,-10.2,18.9,2.9);
	rglRotate(mvm_op_19_4,90.0,0.0,1.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_19_4);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_19_4);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_19_4,-10.2,15.0,2.9);
	rglMatrix4Multiply(mvm_work,mvm_op_19_4);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_19_4);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_19_4,10.1,-1.0,16.9);
	rglRotate(mvm_op_19_4,-50.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_19_4);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_19_4);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_19_4,6.1,-1.0,16.9);
	rglRotate(mvm_op_19_4,50.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_19_4);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
}

void Scena_Draw_19_5(rglMat4 mvm,GLuint h,GLuint shkala2,GLuint shkala, GLuint wplastic, GLuint yplastic, GLuint gplastic,GLuint stal,GLuint bplastic,GLuint shader)
{
	rglSetMaterial(3);
	rglMat4 mvm_op_19_5;
    rglMat4 mvm_work;
	
	rglMatrix4Identity(mvm_op_19_5);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_19_5,0.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_19_5);
	rglPushMatrix(mvm_work,shader);
	rglShtativ_Draw(mvm_work,yplastic,stal,bplastic,shader);
	
	rglMatrix4Identity(mvm_op_19_5);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_19_5,-10.0,36.8,3.5);
	rglRotate(mvm_op_19_5,90.0,0.0,1.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_19_5);
	rglPushMatrix(mvm_work,shader);
	rglHook_2_Draw(mvm_work,0.5,0.1,32,32,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_19_5);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_19_5,-11.0,2.0,-4.0);
	rglMatrix4Multiply(mvm_work,mvm_op_19_5);
	rglPushMatrix(mvm_work,shader);
	rglNapravlenie_Draw(mvm_work,shkala2,gplastic,yplastic,shader);
	
	rglMatrix4Identity(mvm_op_19_5);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_19_5,-10.0,20.55,2.4);
	rglMatrix4Multiply(mvm_work,mvm_op_19_5);
	rglPushMatrix(mvm_work,shader);
	rglDinamometr_Draw(mvm_work,0.10,shkala,wplastic,stal,shader);
 	
	rglMatrix4Identity(mvm_op_19_5);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_19_5,-10.2,15.9,2.9);
	rglRotate(mvm_op_19_5,90.0,0.0,1.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_19_5);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_19_5);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_19_5,-10.2,12.0,2.9);
	rglMatrix4Multiply(mvm_work,mvm_op_19_5);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_19_5);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_19_5,10.1,-1.0,16.9);
	rglRotate(mvm_op_19_5,-50.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_19_5);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_19_5);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_19_5,6.1,-1.0,16.9);
	rglRotate(mvm_op_19_5,50.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_19_5);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
}

void Scena_Draw_19_6(rglMat4 mvm,GLuint h,GLuint shkala2,GLuint shkala, GLuint wplastic, GLuint yplastic, GLuint gplastic,GLuint stal,GLuint bplastic,GLuint shader)
{
	rglSetMaterial(3);
	rglMat4 mvm_op_19_6;
    rglMat4 mvm_work;
	
	rglMatrix4Identity(mvm_op_19_6);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_19_6,0.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_19_6);
	rglPushMatrix(mvm_work,shader);
	rglShtativ_Draw(mvm_work,yplastic,stal,bplastic,shader);
	
	rglMatrix4Identity(mvm_op_19_6);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_19_6,-10.0,36.8,3.5);
	rglRotate(mvm_op_19_6,90.0,0.0,1.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_19_6);
	rglPushMatrix(mvm_work,shader);
	rglHook_2_Draw(mvm_work,0.5,0.1,32,32,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_19_6);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_19_6,-11.0,2.0,-4.0);
	rglMatrix4Multiply(mvm_work,mvm_op_19_6);
	rglPushMatrix(mvm_work,shader);
	rglNapravlenie_Draw(mvm_work,shkala2,gplastic,yplastic,shader);
	
	rglMatrix4Identity(mvm_op_19_6);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_19_6,-10.0,20.55,2.4);
	rglMatrix4Multiply(mvm_work,mvm_op_19_6);
	rglPushMatrix(mvm_work,shader);
	rglDinamometr_Draw(mvm_work,0.05,shkala,wplastic,stal,shader);
 	
	rglMatrix4Identity(mvm_op_19_6);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_19_6,-10.2,18.9,2.9);
	rglRotate(mvm_op_19_6,90.0,0.0,1.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_19_6);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_19_6);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_19_6,-10.2,15.1,2.9);
	rglMatrix4Multiply(mvm_work,mvm_op_19_6);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_19_6);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_19_6,-10.2,11.4,2.9);
	rglRotate(mvm_op_19_6,-90.0,0.0,1.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_19_6);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_19_6);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_19_6,6.1,-1.2,16.9);
	rglRotate(mvm_op_19_6,50.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_19_6);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
}
void Scena_Draw_19_7(rglMat4 mvm,GLuint h,GLuint shkala2,GLuint shkala, GLuint wplastic, GLuint yplastic, GLuint gplastic,GLuint stal,GLuint bplastic,GLuint shader)
{
	rglSetMaterial(3);
	rglMat4 mvm_op_19_7;
    rglMat4 mvm_work;
	
	rglMatrix4Identity(mvm_op_19_7);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_19_7,0.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_19_7);
	rglPushMatrix(mvm_work,shader);
	rglShtativ_Draw(mvm_work,yplastic,stal,bplastic,shader);
	
	rglMatrix4Identity(mvm_op_19_7);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_19_7,-10.0,36.8,3.5);
	rglRotate(mvm_op_19_7,90.0,0.0,1.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_19_7);
	rglPushMatrix(mvm_work,shader);
	rglHook_2_Draw(mvm_work,0.5,0.1,32,32,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_19_7);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_19_7,-11.0,2.0,-4.0);
	rglMatrix4Multiply(mvm_work,mvm_op_19_7);
	rglPushMatrix(mvm_work,shader);
	rglNapravlenie_Draw(mvm_work,shkala2,gplastic,yplastic,shader);
	
	rglMatrix4Identity(mvm_op_19_7);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_19_7,-10.0,20.55,2.4);
	rglMatrix4Multiply(mvm_work,mvm_op_19_7);
	rglPushMatrix(mvm_work,shader);
	rglDinamometr_Draw(mvm_work,0.12,shkala,wplastic,stal,shader);
 	
	rglMatrix4Identity(mvm_op_19_7);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_19_7,-10.2,14.7,2.9);
	rglRotate(mvm_op_19_7,90.0,0.0,1.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_19_7);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_19_7);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_19_7,-10.2,11.0,2.9);
	rglMatrix4Multiply(mvm_work,mvm_op_19_7);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_19_7);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_19_7,-10.2,7.2,2.9);
	rglRotate(mvm_op_19_7,-90.0,0.0,1.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_19_7);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
    rglMatrix4Identity(mvm_op_19_7);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_19_7,6.1,-1.2,16.9);
	rglRotate(mvm_op_19_7,50.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_19_7);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
}

void Scena_Draw_19_8(rglMat4 mvm,GLuint h,GLuint shkala2,GLuint shkala, GLuint wplastic, GLuint yplastic, GLuint gplastic,GLuint stal,GLuint bplastic,GLuint shader)
{
	rglSetMaterial(3);
	rglMat4 mvm_op_19_8;
    rglMat4 mvm_work;
	
	rglMatrix4Identity(mvm_op_19_8);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_19_8,0.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_19_8);
	rglPushMatrix(mvm_work,shader);
	rglShtativ_Draw(mvm_work,yplastic,stal,bplastic,shader);
	
	rglMatrix4Identity(mvm_op_19_8);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_19_8,-10.0,36.8,3.5);
	rglRotate(mvm_op_19_8,90.0,0.0,1.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_19_8);
	rglPushMatrix(mvm_work,shader);
	rglHook_2_Draw(mvm_work,0.5,0.1,32,32,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_19_8);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_19_8,-11.0,2.0,-4.0);
	rglMatrix4Multiply(mvm_work,mvm_op_19_8);
	rglPushMatrix(mvm_work,shader);
	rglNapravlenie_Draw(mvm_work,shkala2,gplastic,yplastic,shader);
	
	rglMatrix4Identity(mvm_op_19_8);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_19_8,-10.0,20.55,2.4);
	rglMatrix4Multiply(mvm_work,mvm_op_19_8);
	rglPushMatrix(mvm_work,shader);
	rglDinamometr_Draw(mvm_work,0.05,shkala,wplastic,stal,shader);
 	
	rglMatrix4Identity(mvm_op_19_8);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_19_8,-10.2,18.9,2.9);
	rglRotate(mvm_op_19_8,90.0,0.0,1.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_19_8);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_19_8);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_19_8,-10.2,15.1,2.9);
	rglMatrix4Multiply(mvm_work,mvm_op_19_8);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_19_8);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_19_8,-10.2,11.4,2.9);
	rglRotate(mvm_op_19_8,-90.0,0.0,1.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_19_8);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
    rglMatrix4Identity(mvm_op_19_8);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_19_8,-10.2,7.6,2.9);
	rglMatrix4Multiply(mvm_work,mvm_op_19_8);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
}


void Scena_Draw_19_9(rglMat4 mvm,GLuint h,GLuint shkala2,GLuint shkala, GLuint wplastic, GLuint yplastic, GLuint gplastic,GLuint stal,GLuint bplastic,GLuint shader)
{
	rglSetMaterial(3);
	rglMat4 mvm_op_19_9;
    rglMat4 mvm_work;
	
	rglMatrix4Identity(mvm_op_19_9);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_19_9,0.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_19_9);
	rglPushMatrix(mvm_work,shader);
	rglShtativ_Draw(mvm_work,yplastic,stal,bplastic,shader);
	
	rglMatrix4Identity(mvm_op_19_9);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_19_9,-10.0,36.8,3.5);
	rglRotate(mvm_op_19_9,90.0,0.0,1.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_19_9);
	rglPushMatrix(mvm_work,shader);
	rglHook_2_Draw(mvm_work,0.5,0.1,32,32,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_19_9);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_19_9,-11.0,2.0,-4.0);
	rglMatrix4Multiply(mvm_work,mvm_op_19_9);
	rglPushMatrix(mvm_work,shader);
	rglNapravlenie_Draw(mvm_work,shkala2,gplastic,yplastic,shader);
	
	rglMatrix4Identity(mvm_op_19_9);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_19_9,-10.0,20.55,2.4);
	rglMatrix4Multiply(mvm_work,mvm_op_19_9);
	rglPushMatrix(mvm_work,shader);
	rglDinamometr_Draw(mvm_work,0.14,shkala,wplastic,stal,shader);
 	
	rglMatrix4Identity(mvm_op_19_9);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_19_9,-10.2,13.7,2.9);
	rglRotate(mvm_op_19_9,90.0,0.0,1.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_19_9);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_19_9);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_19_9,-10.2,10.0,2.9);
	rglMatrix4Multiply(mvm_work,mvm_op_19_9);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_19_9);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_19_9,-10.2,6.2,2.9);
	rglRotate(mvm_op_19_9,-90.0,0.0,1.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_19_9);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
    rglMatrix4Identity(mvm_op_19_9);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_19_9,-10.2,2.4,2.9);
	rglMatrix4Multiply(mvm_work,mvm_op_19_9);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
}


void Scena_Draw_19_10(rglMat4 mvm,GLuint h,GLuint shkala2,GLuint shkala, GLuint wplastic, GLuint yplastic, GLuint gplastic,GLuint stal,GLuint bplastic,GLuint shader)
{
	rglSetMaterial(3);
	rglMat4 mvm_op_19_10;
    rglMat4 mvm_work;
	
	rglMatrix4Identity(mvm_op_19_10);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_19_10,0.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_19_10);
	rglPushMatrix(mvm_work,shader);
	rglShtativ_Draw(mvm_work,yplastic,stal,bplastic,shader);
	
	rglMatrix4Identity(mvm_op_19_10);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_19_10,0.0,1.2,4.0);
	rglRotate(mvm_op_19_10,90.0,0.0,1.0,0.0);
	rglRotate(mvm_op_19_10,90.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_19_10);
	rglPushMatrix(mvm_work,shader);
	rglHook_2_Draw(mvm_work,0.5,0.1,32,32,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_19_10);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_19_10,-11.0,2.0,-4.0);
	rglRotate(mvm_op_19_10,90.0,0.0,0.0,1.0);
	rglMatrix4Multiply(mvm_work,mvm_op_19_10);
	rglPushMatrix(mvm_work,shader);
	rglNapravlenie_Draw(mvm_work,shkala2,gplastic,yplastic,shader);
	
	rglMatrix4Identity(mvm_op_19_10);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_19_10,0.0,-1.0,10.4);
	rglRotate(mvm_op_19_10,-90.0,1.0,0.0,0.0);
	rglRotate(mvm_op_19_10,90.0,0.0,0.0,1.0);
	rglMatrix4Multiply(mvm_work,mvm_op_19_10);
	rglPushMatrix(mvm_work,shader);
	rglDinamometr_Draw(mvm_work,0.05,shkala,wplastic,stal,shader);
 	
	rglMatrix4Identity(mvm_op_19_10);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_19_10,8.1,-1.0,12.9);
	rglRotate(mvm_op_19_10,-50.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_19_10);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_19_10);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_19_10,4.1,-1.0,12.9);
	rglRotate(mvm_op_19_10,50.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_19_10);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_19_10);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_19_10,10.1,-1.0,15.9);
	rglRotate(mvm_op_19_10,-50.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_19_10);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_19_10);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_19_10,7.1,-1.0,15.9);
	rglRotate(mvm_op_19_10,50.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_19_10);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
}

void Scena_Draw_19(rglMat4 mvm,GLuint h,GLuint shkala2,GLuint shkala, GLuint wplastic, GLuint yplastic, GLuint gplastic,GLuint stal,GLuint bplastic,GLuint shader, GLuint shader2)
{
	switch (scena_ddraw_19)
	{
		case 1:Scena_Draw_19_1(mvm,0.05,shkala2,shkala,wplastic,yplastic,gplastic,stal,bplastic,shader);break;
		case 2:Scena_Draw_19_2(mvm,0.05,shkala2,shkala,wplastic,yplastic,gplastic,stal,bplastic,shader);break;
		case 3:Scena_Draw_19_3(mvm,0.05,shkala2,shkala,wplastic,yplastic,gplastic,stal,bplastic,shader);break;
		case 4:Scena_Draw_19_4(mvm,0.07,shkala2,shkala,wplastic,yplastic,gplastic,stal,bplastic,shader);break;
		case 5:Scena_Draw_19_5(mvm,0.09,shkala2,shkala,wplastic,yplastic,gplastic,stal,bplastic,shader);break;
		case 6:Scena_Draw_19_6(mvm,0.05,shkala2,shkala,wplastic,yplastic,gplastic,stal,bplastic,shader);break;
		case 7:Scena_Draw_19_7(mvm,0.12,shkala2,shkala,wplastic,yplastic,gplastic,stal,bplastic,shader);break;
		case 8:Scena_Draw_19_8(mvm,0.05,shkala2,shkala,wplastic,yplastic,gplastic,stal,bplastic,shader);break;
		case 9:Scena_Draw_19_9(mvm,0.14,shkala2,shkala,wplastic,yplastic,gplastic,stal,bplastic,shader);break;
		case 0:Scena_Draw_19_10(mvm,0.14,shkala2,shkala,wplastic,yplastic,gplastic,stal,bplastic,shader);break;
	
		default: 
		break;
		
	}
  rglDrawResult7(1024,768, 20.0, 15.0, shader2);
	
}



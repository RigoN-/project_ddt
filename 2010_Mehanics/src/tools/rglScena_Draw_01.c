#include <GL/glew.h>
#include "rglScena_Draw_01.h"
#include "rglScena_Draw_03.h"
#include "rglFigures.h"
#include "rglShader.h"
#include <SDL/SDL.h>



GLint scena_ddraw_2=1;
GLint scena_switch;

char *text1_1="|        1          |               0,1              |               0,98          |                 1                   | ";
char *text1_2="|        2          |               0,2              |               1,96          |                 2                   | ";
char *text1_3="|        3          |               0,3              |               2,94          |                 3                   | ";
char *text1_4="|        4          |               0,4              |               3,92          |                 4                   | ";
char *text1_0="|        0          |               0                 |               0               |                 0                   | ";





GLint Scena_Draw_01_key_pressed(SDL_keysym *keysym)
{	
	
switch ( keysym->sym )
{
    
	 case SDLK_1:rglUpdateResult3(text1_0,text1_0,text1_0,text1_0);scena_ddraw_2=1; break;
	 case SDLK_2:rglUpdateResult3(text1_0,text1_0,text1_0,text1_0);scena_ddraw_2=2; break;
	 case SDLK_3:rglUpdateResult3(text1_0,text1_0,text1_0,text1_0);scena_ddraw_2=3; break;
	 case SDLK_4:rglUpdateResult3(text1_1,text1_0,text1_0,text1_0);scena_ddraw_2=4; break;
	 case SDLK_5:rglUpdateResult3(text1_1,text1_2,text1_0,text1_0);scena_ddraw_2=5; break;
	 case SDLK_6:rglUpdateResult3(text1_1,text1_2,text1_3,text1_0);scena_ddraw_2=6; break;
	 case SDLK_7:rglUpdateResult3(text1_1,text1_2,text1_3,text1_4);scena_ddraw_2=7; break;
	 case SDLK_8:rglUpdateResult3(text1_1,text1_2,text1_3,text1_4);scena_ddraw_2=8; break;
	default:		break;
}
    return 1;
}

void Scena_Draw_01_1(rglMat4 mvm,GLuint h,GLuint shkala, GLuint wplastic, GLuint yplastic, GLuint gplastic,GLuint stal,GLuint bplastic,GLuint shader)
{
	rglSetMaterial(3);
	rglMat4 mvm_op_1_1;
    rglMat4 mvm_work;
	
	rglMatrix4Identity(mvm_op_1_1);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_1_1,0.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_1_1);
	rglPushMatrix(mvm_work,shader);
	rglShtativ_Draw(mvm_work,yplastic,stal,bplastic,shader);
	
	rglMatrix4Identity(mvm_op_1_1);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_1_1,0.0,1.2,4.0);
	rglRotate(mvm_op_1_1,90.0,0.0,1.0,0.0);
	rglRotate(mvm_op_1_1,90.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_1_1);
	rglPushMatrix(mvm_work,shader);
	rglHook_2_Draw(mvm_work,0.5,0.1,32,32,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_1_1);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_1_1,0.0,-1.0,10.4);
	rglRotate(mvm_op_1_1,-90.0,1.0,0.0,0.0);
	rglRotate(mvm_op_1_1,90.0,0.0,0.0,1.0);
	rglMatrix4Multiply(mvm_work,mvm_op_1_1);
	rglPushMatrix(mvm_work,shader);
	rglDinamometr_Draw(mvm_work,0.08,shkala,wplastic,stal,shader);
 	
	rglMatrix4Identity(mvm_op_1_1);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_1_1,8.1,-1.0,12.9);
	rglRotate(mvm_op_1_1,-50.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_1_1);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_1_1);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_1_1,4.1,-1.0,12.9);
	rglRotate(mvm_op_1_1,50.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_1_1);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_1_1);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_1_1,10.1,-1.0,15.9);
	rglRotate(mvm_op_1_1,-50.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_1_1);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_1_1);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_1_1,7.1,-1.0,15.9);
	rglRotate(mvm_op_1_1,50.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_1_1);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
}

void Scena_Draw_01_2(rglMat4 mvm,GLuint h,GLuint shkala, GLuint wplastic, GLuint yplastic, GLuint gplastic,GLuint stal,GLuint bplastic,GLuint shader)
{
	rglSetMaterial(3);
	rglMat4 mvm_op_1_2;
    rglMat4 mvm_work;
	
	rglMatrix4Identity(mvm_op_1_2);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_1_2,0.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_1_2);
	rglPushMatrix(mvm_work,shader);
	rglShtativ_Draw(mvm_work,yplastic,stal,bplastic,shader);
	
	rglMatrix4Identity(mvm_op_1_2);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_1_2,-10.0,36.8,3.5);
	rglRotate(mvm_op_1_2,90.0,0.0,1.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_1_2);
	rglPushMatrix(mvm_work,shader);
	rglHook_2_Draw(mvm_work,0.5,0.1,32,32,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_1_2);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_1_2,0.0,-1.0,10.4);
	rglRotate(mvm_op_1_2,-90.0,1.0,0.0,0.0);
	rglRotate(mvm_op_1_2,90.0,0.0,0.0,1.0);
	rglMatrix4Multiply(mvm_work,mvm_op_1_2);
	rglPushMatrix(mvm_work,shader);
	rglDinamometr_Draw(mvm_work,0.08,shkala,wplastic,stal,shader);
 	
	rglMatrix4Identity(mvm_op_1_2);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_1_2,8.1,-1.0,12.9);
	rglRotate(mvm_op_1_2,-50.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_1_2);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_1_2);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_1_2,4.1,-1.0,12.9);
	rglRotate(mvm_op_1_2,50.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_1_2);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_1_2);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_1_2,10.1,-1.0,16.9);
	rglRotate(mvm_op_1_2,-50.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_1_2);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_1_2);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_1_2,7.1,-1.0,16.9);
	rglRotate(mvm_op_1_2,50.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_1_2);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
}

void Scena_Draw_01_3(rglMat4 mvm,GLuint h,GLuint shkala, GLuint wplastic, GLuint yplastic, GLuint gplastic,GLuint stal,GLuint bplastic,GLuint shader)
{
	rglSetMaterial(3);
	rglMat4 mvm_op_1_3;
    rglMat4 mvm_work;
	
	rglMatrix4Identity(mvm_op_1_3);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_1_3,0.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_1_3);
	rglPushMatrix(mvm_work,shader);
	rglShtativ_Draw(mvm_work,yplastic,stal,bplastic,shader);
	
	rglMatrix4Identity(mvm_op_1_3);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_1_3,-10.0,36.8,3.5);
	rglRotate(mvm_op_1_3,90.0,0.0,1.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_1_3);
	rglPushMatrix(mvm_work,shader);
	rglHook_2_Draw(mvm_work,0.5,0.1,32,32,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_1_3);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_1_3,-10.0,20.55,2.4);
	rglMatrix4Multiply(mvm_work,mvm_op_1_3);
	rglPushMatrix(mvm_work,shader);
	rglDinamometr_Draw(mvm_work,0.05,shkala,wplastic,stal,shader);
 	
	rglMatrix4Identity(mvm_op_1_3);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_1_3,8.1,-1.0,12.9);
	rglRotate(mvm_op_1_3,-50.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_1_3);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_1_3);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_1_3,4.1,-1.0,12.9);
	rglRotate(mvm_op_1_3,50.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_1_3);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_1_3);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_1_3,10.1,-1.0,16.9);
	rglRotate(mvm_op_1_3,-50.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_1_3);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_1_3);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_1_3,7.1,-1.0,16.9);
	rglRotate(mvm_op_1_3,50.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_1_3);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
}

void Scena_Draw_01_4(rglMat4 mvm,GLuint h,GLuint shkala, GLuint wplastic, GLuint yplastic, GLuint gplastic,GLuint stal,GLuint bplastic,GLuint shader)
{
	rglSetMaterial(3);
	rglMat4 mvm_op_1_4;
    rglMat4 mvm_work;
	
	rglMatrix4Identity(mvm_op_1_4);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_1_4,0.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_1_4);
	rglPushMatrix(mvm_work,shader);
	rglShtativ_Draw(mvm_work,yplastic,stal,bplastic,shader);
	
	rglMatrix4Identity(mvm_op_1_4);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_1_4,-10.0,36.8,3.5);
	rglRotate(mvm_op_1_4,90.0,0.0,1.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_1_4);
	rglPushMatrix(mvm_work,shader);
	rglHook_2_Draw(mvm_work,0.5,0.1,32,32,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_1_4);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_1_4,-10.0,20.55,2.4);
	rglMatrix4Multiply(mvm_work,mvm_op_1_4);
	rglPushMatrix(mvm_work,shader);
	rglDinamometr_Draw(mvm_work,0.07,shkala,wplastic,stal,shader);
 	
	rglMatrix4Identity(mvm_op_1_4);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_1_4,-10.2,17.9,2.9);
	rglRotate(mvm_op_1_4,90.0,0.0,1.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_1_4);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_1_4);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_1_4,4.1,-1.0,12.9);
	rglRotate(mvm_op_1_4,50.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_1_4);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_1_4);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_1_4,10.1,-1.0,16.9);
	rglRotate(mvm_op_1_4,-50.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_1_4);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_1_4);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_1_4,6.1,-1.0,16.9);
	rglRotate(mvm_op_1_4,50.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_1_4);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
}

void Scena_Draw_01_5(rglMat4 mvm,GLuint h,GLuint shkala, GLuint wplastic, GLuint yplastic, GLuint gplastic,GLuint stal,GLuint bplastic,GLuint shader)
{
	rglSetMaterial(3);
	rglMat4 mvm_op_1_5;
    rglMat4 mvm_work;
	
	rglMatrix4Identity(mvm_op_1_5);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_1_5,0.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_1_5);
	rglPushMatrix(mvm_work,shader);
	rglShtativ_Draw(mvm_work,yplastic,stal,bplastic,shader);
	
	rglMatrix4Identity(mvm_op_1_5);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_1_5,-10.0,36.8,3.5);
	rglRotate(mvm_op_1_5,90.0,0.0,1.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_1_5);
	rglPushMatrix(mvm_work,shader);
	rglHook_2_Draw(mvm_work,0.5,0.1,32,32,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_1_5);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_1_5,-10.0,20.55,2.4);
	rglMatrix4Multiply(mvm_work,mvm_op_1_5);
	rglPushMatrix(mvm_work,shader);
	rglDinamometr_Draw(mvm_work,0.09,shkala,wplastic,stal,shader);
 	
	rglMatrix4Identity(mvm_op_1_5);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_1_5,-10.2,16.8,2.9);
	rglRotate(mvm_op_1_5,90.0,0.0,1.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_1_5);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_1_5);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_1_5,-10.2,13.0,2.9);
	rglMatrix4Multiply(mvm_work,mvm_op_1_5);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_1_5);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_1_5,10.1,-1.0,16.9);
	rglRotate(mvm_op_1_5,-50.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_1_5);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_1_5);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_1_5,6.1,-1.0,16.9);
	rglRotate(mvm_op_1_5,50.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_1_5);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
}

void Scena_Draw_01_6(rglMat4 mvm,GLuint h,GLuint shkala, GLuint wplastic, GLuint yplastic, GLuint gplastic,GLuint stal,GLuint bplastic,GLuint shader)
{
	rglSetMaterial(3);
	rglMat4 mvm_op_1_6;
    rglMat4 mvm_work;
	
	rglMatrix4Identity(mvm_op_1_6);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_1_6,0.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_1_6);
	rglPushMatrix(mvm_work,shader);
	rglShtativ_Draw(mvm_work,yplastic,stal,bplastic,shader);
	
	rglMatrix4Identity(mvm_op_1_6);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_1_6,-10.0,36.8,3.5);
	rglRotate(mvm_op_1_6,90.0,0.0,1.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_1_6);
	rglPushMatrix(mvm_work,shader);
	rglHook_2_Draw(mvm_work,0.5,0.1,32,32,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_1_6);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_1_6,-10.0,20.55,2.4);
	rglMatrix4Multiply(mvm_work,mvm_op_1_6);
	rglPushMatrix(mvm_work,shader);
	rglDinamometr_Draw(mvm_work,0.11,shkala,wplastic,stal,shader);
 	
	rglMatrix4Identity(mvm_op_1_6);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_1_6,-10.2,15.7,2.9);
	rglRotate(mvm_op_1_6,90.0,0.0,1.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_1_6);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_1_6);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_1_6,-10.2,12.0,2.9);
	rglMatrix4Multiply(mvm_work,mvm_op_1_6);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_1_6);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_1_6,-10.2,8.2,2.9);
	rglRotate(mvm_op_1_6,-90.0,0.0,1.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_1_6);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_1_6);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_1_6,6.1,-1.0,16.9);
	rglRotate(mvm_op_1_6,50.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_1_6);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
}
void Scena_Draw_01_7(rglMat4 mvm,GLuint h,GLuint shkala, GLuint wplastic, GLuint yplastic, GLuint gplastic,GLuint stal,GLuint bplastic,GLuint shader)
{
	rglSetMaterial(3);
	rglMat4 mvm_op_1_7;
    rglMat4 mvm_work;
	
	rglMatrix4Identity(mvm_op_1_7);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_1_7,0.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_1_7);
	rglPushMatrix(mvm_work,shader);
	rglShtativ_Draw(mvm_work,yplastic,stal,bplastic,shader);
	
	rglMatrix4Identity(mvm_op_1_7);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_1_7,-10.0,36.8,3.5);
	rglRotate(mvm_op_1_7,90.0,0.0,1.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_1_7);
	rglPushMatrix(mvm_work,shader);
	rglHook_2_Draw(mvm_work,0.5,0.1,32,32,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_1_7);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_1_7,-10.0,20.55,2.4);
	rglMatrix4Multiply(mvm_work,mvm_op_1_7);
	rglPushMatrix(mvm_work,shader);
	rglDinamometr_Draw(mvm_work,0.13,shkala,wplastic,stal,shader);
 	
	rglMatrix4Identity(mvm_op_1_7);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_1_7,-10.2,14.4,2.9);
	rglRotate(mvm_op_1_7,90.0,0.0,1.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_1_7);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_1_7);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_1_7,-10.2,10.7,2.9);
	rglMatrix4Multiply(mvm_work,mvm_op_1_7);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_1_7);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_1_7,-10.2,6.9,2.9);
	rglRotate(mvm_op_1_7,-90.0,0.0,1.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_1_7);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
    rglMatrix4Identity(mvm_op_1_7);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_1_7,-10.2,3.1,2.9);
	rglMatrix4Multiply(mvm_work,mvm_op_1_7);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
}

void Scena_Draw_01_8(rglMat4 mvm,GLuint h,GLuint shkala, GLuint wplastic, GLuint yplastic, GLuint gplastic,GLuint stal,GLuint bplastic,GLuint shader)
{
	rglSetMaterial(3);
	rglMat4 mvm_op_1_8;
    rglMat4 mvm_work;
	
	rglMatrix4Identity(mvm_op_1_8);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_1_8,0.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_1_8);
	rglPushMatrix(mvm_work,shader);
	rglShtativ_Draw(mvm_work,yplastic,stal,bplastic,shader);
	
	rglMatrix4Identity(mvm_op_1_8);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_1_8,0.0,1.2,4.0);
	rglRotate(mvm_op_1_8,90.0,0.0,1.0,0.0);
	rglRotate(mvm_op_1_8,90.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_1_8);
	rglPushMatrix(mvm_work,shader);
	rglHook_2_Draw(mvm_work,0.5,0.1,32,32,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_1_8);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_1_8,0.0,-1.0,10.4);
	rglRotate(mvm_op_1_8,-90.0,1.0,0.0,0.0);
	rglRotate(mvm_op_1_8,90.0,0.0,0.0,1.0);
	rglMatrix4Multiply(mvm_work,mvm_op_1_8);
	rglPushMatrix(mvm_work,shader);
	rglDinamometr_Draw(mvm_work,0.08,shkala,wplastic,stal,shader);
 	
	rglMatrix4Identity(mvm_op_1_8);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_1_8,8.1,-1.0,12.9);
	rglRotate(mvm_op_1_8,-50.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_1_8);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_1_8);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_1_8,4.1,-1.0,12.9);
	rglRotate(mvm_op_1_8,50.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_1_8);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_1_8);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_1_8,10.1,-1.0,15.9);
	rglRotate(mvm_op_1_8,-50.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_1_8);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_1_8);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_1_8,7.1,-1.0,15.9);
	rglRotate(mvm_op_1_8,50.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_1_8);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
}

void Scena_Draw_01(rglMat4 mvm,GLuint h,GLuint shkala, GLuint wplastic, GLuint yplastic, GLuint gplastic,GLuint stal,GLuint bplastic,GLuint shader,GLuint shader2)
{
	switch (scena_ddraw_2)
	{
		
		case 1:Scena_Draw_01_1(mvm,0.05,shkala,wplastic,yplastic,gplastic,stal,bplastic,shader);break;
		case 2:Scena_Draw_01_2(mvm,0.05,shkala,wplastic,yplastic,gplastic,stal,bplastic,shader);break;
		case 3:Scena_Draw_01_3(mvm,0.05,shkala,wplastic,yplastic,gplastic,stal,bplastic,shader);break;
		case 4:Scena_Draw_01_4(mvm,0.07,shkala,wplastic,yplastic,gplastic,stal,bplastic,shader);break;
		case 5:Scena_Draw_01_5(mvm,0.09,shkala,wplastic,yplastic,gplastic,stal,bplastic,shader);break;
		case 6:Scena_Draw_01_6(mvm,0.11,shkala,wplastic,yplastic,gplastic,stal,bplastic,shader);break;
		case 7:Scena_Draw_01_7(mvm,0.13,shkala,wplastic,yplastic,gplastic,stal,bplastic,shader);break;
		case 8:Scena_Draw_01_8(mvm,0.05,shkala,wplastic,yplastic,gplastic,stal,bplastic,shader);break;
	
		default: 
		break;
		
	}
    rglDrawResult3(1024,768, 20.0, 15.0, shader2);
	
}

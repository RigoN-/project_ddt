#include <GL/glew.h>
#include "rglScena_Draw_01.h"
#include "rglScena_Draw_03.h"
#include "rglScena_Draw_07.h"
#include "rglScena_Draw_18.h"
#include "rglShader.h"
#include <SDL/SDL.h>

char *text18_1="|        1          |      2        |      0,16    |      0.32   |     4        |      0,08     |         0.32   | ";
char *text18_2="|        1          |      2        |      0,04    |      0.08   |     1        |      0,08     |         0.08   | ";
char *text18_3="|        1          |      3        |      0,08    |      0.24   |     2        |      0,12     |         0.24   | ";
char *text18_0="|        0          |      0        |      0         |      0        |     0        |        0        |          0       | ";


GLint scena_ddraw_18=1;

GLint Scena_Draw_18_key_pressed(SDL_keysym *keysym)
{	
	
switch ( keysym->sym )
{
     
	 case SDLK_1:rglUpdateResult18(text18_0,text18_0,text18_0);scena_ddraw_18=1; break;
	 case SDLK_2:rglUpdateResult18(text18_0,text18_0,text18_0);scena_ddraw_18=2; break;
	 case SDLK_3:rglUpdateResult18(text18_0,text18_0,text18_0);scena_ddraw_18=3; break;
	 case SDLK_4:rglUpdateResult18(text18_1,text18_0,text18_0);scena_ddraw_18=4; break;
	 case SDLK_5:rglUpdateResult18(text18_1,text18_0,text18_0);scena_ddraw_18=5; break;
	 case SDLK_6:rglUpdateResult18(text18_1,text18_2,text18_0);scena_ddraw_18=6; break;
	 case SDLK_7:rglUpdateResult18(text18_1,text18_2,text18_0);scena_ddraw_18=7; break;
	 case SDLK_8:rglUpdateResult18(text18_1,text18_2,text18_3);scena_ddraw_18=8; break;
	 case SDLK_9:rglUpdateResult18(text18_1,text18_2,text18_3);scena_ddraw_18=9; break;
	
	
	
	default:		break;
}
    return 1;
}


void Scena_Draw_18(rglMat4 mvm,GLuint h, GLuint wplastic,GLuint shkala,GLuint shkala2, GLuint yplastic, GLuint gplastic,GLuint stal,GLuint bplastic,GLuint shader,GLuint shader2)
{
	switch (scena_ddraw_18)
	{
		
		case 1:Scena_Draw_18_1(mvm,0.05,wplastic,shkala,shkala2,yplastic,gplastic,stal,bplastic,shader);break;
		case 2:Scena_Draw_18_2(mvm,0.05,wplastic,shkala,shkala2,yplastic,gplastic,stal,bplastic,shader);break;
		case 3:Scena_Draw_18_3(mvm,0.05,wplastic,shkala,shkala2,yplastic,gplastic,stal,bplastic,shader);break;
	    case 4:Scena_Draw_18_4(mvm,0.05,wplastic,shkala,shkala2,yplastic,gplastic,stal,bplastic,shader);break;
	    case 5:Scena_Draw_18_5(mvm,0.13,wplastic,shkala,shkala2,yplastic,gplastic,stal,bplastic,shader);break;
	    case 6:Scena_Draw_18_6(mvm,0.13,wplastic,shkala,shkala2,yplastic,gplastic,stal,bplastic,shader);break;
	    case 7:Scena_Draw_18_7(mvm,0.09,wplastic,shkala,shkala2,yplastic,gplastic,stal,bplastic,shader);break;
        case 8:Scena_Draw_18_8(mvm,0.09,wplastic,shkala,shkala2,yplastic,gplastic,stal,bplastic,shader);break;
        case 9:Scena_Draw_18_9(mvm,0.09,wplastic,shkala,shkala2,yplastic,gplastic,stal,bplastic,shader);break;
        
	
		default: 
		break;
		
	}
	 rglDrawResult7(1024,768, 20.0, 15.0, shader2);
	
}


void Scena_Draw_18_1(rglMat4 mvm,GLuint h,GLuint wplastic,GLuint shkala,GLuint shkala2, GLuint yplastic, GLuint gplastic,GLuint stal,GLuint bplastic,GLuint shader)
{
	rglSetMaterial(3);
	rglMat4 mvm_op_18_1;
    rglMat4 mvm_work;
	
	rglMatrix4Identity(mvm_op_18_1);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_18_1,0.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_18_1);
	rglPushMatrix(mvm_work,shader);
	rglShtativ_Draw_3(mvm_work,yplastic,stal,bplastic,shader);
	
	
    rglMatrix4Identity(mvm_op_18_1);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_18_1,0.0,0.0,7.0);
	rglMatrix4Multiply(mvm_work,mvm_op_18_1);
	rglPushMatrix(mvm_work,shader);
	rglRule_Draw(mvm_work,gplastic,bplastic,stal,shader);
	
	
	
	rglMatrix4Identity(mvm_op_18_1);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_18_1,2.0,0.0,11.0);
	rglRotate(mvm_op_18_1,90.0,0.0,1.0,0.0);
	rglRotate(mvm_op_18_1,-90.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_18_1);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_18_1);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_18_1,6.0,0.0,11.0);
	rglRotate(mvm_op_18_1,-90.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_18_1);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_18_1);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_18_1,10.0,0.0,11.0);
	rglRotate(mvm_op_18_1,90.0,0.0,1.0,0.0);
	rglRotate(mvm_op_18_1,60.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_18_1);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_18_1);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_18_1,10.0,0.0,14.0);
	rglRotate(mvm_op_18_1,-90.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_18_1);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
    rglMatrix4Identity(mvm_op_18_1);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_18_1,0.0,-1.0,10.4);
	rglRotate(mvm_op_18_1,-90.0,1.0,0.0,0.0);
	rglRotate(mvm_op_18_1,90.0,0.0,0.0,1.0);
	rglMatrix4Multiply(mvm_work,mvm_op_18_1);
	rglPushMatrix(mvm_work,shader);
	rglDinamometr_Draw(mvm_work,0.08,shkala,wplastic,stal,shader);
	
}

void Scena_Draw_18_2(rglMat4 mvm,GLuint h,GLuint wplastic,GLuint shkala,GLuint shkala2, GLuint yplastic, GLuint gplastic,GLuint stal,GLuint bplastic,GLuint shader)
{
	rglSetMaterial(3);
	rglMat4 mvm_op_18_2;
    rglMat4 mvm_work;
	
	rglMatrix4Identity(mvm_op_18_2);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_18_2,0.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_18_2);
	rglPushMatrix(mvm_work,shader);
	rglShtativ_Draw_3(mvm_work,yplastic,stal,bplastic,shader);
	
	
    rglMatrix4Identity(mvm_op_18_2);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_18_2,0.0,30.0,4.0);
	rglMatrix4Multiply(mvm_work,mvm_op_18_2);
	rglPushMatrix(mvm_work,shader);
	rglRule_Draw(mvm_work,gplastic,bplastic,stal,shader);
	
	
	
	rglMatrix4Identity(mvm_op_18_2);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_18_2,2.0,0.0,11.0);
	rglRotate(mvm_op_18_2,90.0,0.0,1.0,0.0);
	rglRotate(mvm_op_18_2,-90.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_18_2);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_18_2);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_18_2,6.0,0.0,11.0);
	rglRotate(mvm_op_18_2,-90.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_18_2);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_18_2);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_18_2,10.0,0.0,11.0);
	rglRotate(mvm_op_18_2,90.0,0.0,1.0,0.0);
	rglRotate(mvm_op_18_2,60.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_18_2);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_18_2);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_18_2,10.0,0.0,14.0);
	rglRotate(mvm_op_18_2,-90.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_18_2);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
    rglMatrix4Identity(mvm_op_18_2);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_18_2,0.0,-1.0,10.4);
	rglRotate(mvm_op_18_2,-90.0,1.0,0.0,0.0);
	rglRotate(mvm_op_18_2,90.0,0.0,0.0,1.0);
	rglMatrix4Multiply(mvm_work,mvm_op_18_2);
	rglPushMatrix(mvm_work,shader);
	rglDinamometr_Draw(mvm_work,0.08,shkala,wplastic,stal,shader);
	
}

void Scena_Draw_18_3(rglMat4 mvm,GLuint h,GLuint wplastic,GLuint shkala,GLuint shkala2, GLuint yplastic, GLuint gplastic,GLuint stal,GLuint bplastic,GLuint shader)
{
	rglSetMaterial(3);
	rglMat4 mvm_op_18_3;
    rglMat4 mvm_work;
	
	rglMatrix4Identity(mvm_op_18_3);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_18_3,0.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_18_3);
	rglPushMatrix(mvm_work,shader);
	rglShtativ_Draw_3(mvm_work,yplastic,stal,bplastic,shader);
	
	
    rglMatrix4Identity(mvm_op_18_3);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_18_3,0.0,30.0,4.0);
	rglRotate(mvm_op_18_3,20.0,0.0,0.0,1.0);
	rglMatrix4Multiply(mvm_work,mvm_op_18_3);
	rglPushMatrix(mvm_work,shader);
	rglRule_Draw(mvm_work,gplastic,bplastic,stal,shader);
	
	
	
	rglMatrix4Identity(mvm_op_18_3);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_18_3,-14.5,20.7,4.0);
	rglRotate(mvm_op_18_3,90.0,0.0,1.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_18_3);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_18_3);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_18_3,-14.5,16.9,4.0);
	rglMatrix4Multiply(mvm_work,mvm_op_18_3);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_18_3);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_18_3,10.0,0.0,11.0);
	rglRotate(mvm_op_18_3,90.0,0.0,1.0,0.0);
	rglRotate(mvm_op_18_3,60.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_18_3);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_18_3);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_18_3,10.0,0.0,14.0);
	rglRotate(mvm_op_18_3,-90.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_18_3);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
    rglMatrix4Identity(mvm_op_18_3);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_18_3,0.0,-1.0,10.4);
	rglRotate(mvm_op_18_3,-90.0,1.0,0.0,0.0);
	rglRotate(mvm_op_18_3,90.0,0.0,0.0,1.0);
	rglMatrix4Multiply(mvm_work,mvm_op_18_3);
	rglPushMatrix(mvm_work,shader);
	rglDinamometr_Draw(mvm_work,0.08,shkala,wplastic,stal,shader);
	
}

void Scena_Draw_18_4(rglMat4 mvm,GLuint h,GLuint wplastic,GLuint shkala,GLuint shkala2, GLuint yplastic, GLuint gplastic,GLuint stal,GLuint bplastic,GLuint shader)
{
	rglSetMaterial(3);
	rglMat4 mvm_op_18_4;
    rglMat4 mvm_work;
	
	rglMatrix4Identity(mvm_op_18_4);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_18_4,0.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_18_4);
	rglPushMatrix(mvm_work,shader);
	rglShtativ_Draw_3(mvm_work,yplastic,stal,bplastic,shader);
	
	
 	rglMatrix4Identity(mvm_op_18_4);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_18_4,0.0,30.0,4.0);
	rglMatrix4Multiply(mvm_work,mvm_op_18_4);
	rglPushMatrix(mvm_work,shader);
	rglRule_Draw(mvm_work,gplastic,bplastic,stal,shader);
	
	
	
	rglMatrix4Identity(mvm_op_18_4);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_18_4,-16.0,26.0,4.0);
	rglRotate(mvm_op_18_4,90.0,0.0,1.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_18_4);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_18_4);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_18_4,-16.0,22.5,4.0);
	rglMatrix4Multiply(mvm_work,mvm_op_18_4);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_18_4);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_18_4,10.0,0.0,11.0);
	rglRotate(mvm_op_18_4,90.0,0.0,1.0,0.0);
	rglRotate(mvm_op_18_4,60.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_18_4);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_18_4);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_18_4,10.0,0.0,14.0);
	rglRotate(mvm_op_18_4,-90.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_18_4);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_18_4);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_18_4,8.0,25.1,3.4);
	rglRotate(mvm_op_18_4,180.0,0.0,0.0,1.0);
	rglMatrix4Multiply(mvm_work,mvm_op_18_4);
	rglPushMatrix(mvm_work,shader);
	rglDinamometr_Draw(mvm_work,0.13,shkala,wplastic,stal,shader);
	
}

void Scena_Draw_18_5(rglMat4 mvm,GLuint h,GLuint wplastic,GLuint shkala,GLuint shkala2, GLuint yplastic, GLuint gplastic,GLuint stal,GLuint bplastic,GLuint shader)
{
	rglSetMaterial(3);
	rglMat4 mvm_op_18_5;
    rglMat4 mvm_work;
	
	rglMatrix4Identity(mvm_op_18_5);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_18_5,0.0,0.0,0.0);
	
	rglMatrix4Multiply(mvm_work,mvm_op_18_5);
	rglPushMatrix(mvm_work,shader);
	rglShtativ_Draw_3(mvm_work,yplastic,stal,bplastic,shader);
	
	
 	rglMatrix4Identity(mvm_op_18_5);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_18_5,0.0,30.0,4.0);
	rglRotate(mvm_op_18_5,20.0,0.0,0.0,1.0);
	rglMatrix4Multiply(mvm_work,mvm_op_18_5);
	rglPushMatrix(mvm_work,shader);
	rglRule_Draw(mvm_work,gplastic,bplastic,stal,shader);
	

	
	rglMatrix4Identity(mvm_op_18_5);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_18_5,-3.5,24.7,4.0);
	rglRotate(mvm_op_18_5,90.0,0.0,1.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_18_5);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_18_5);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_18_5,-3.5,20.9,4.0);
	rglMatrix4Multiply(mvm_work,mvm_op_18_5);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	
	rglMatrix4Identity(mvm_op_18_5);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_18_5,10.0,0.0,14.0);
	rglRotate(mvm_op_18_5,-90.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_18_5);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
    rglMatrix4Identity(mvm_op_18_5);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_18_5,0.0,-1.0,10.4);
	rglRotate(mvm_op_18_5,-90.0,1.0,0.0,0.0);
	rglRotate(mvm_op_18_5,90.0,0.0,0.0,1.0);
	rglMatrix4Multiply(mvm_work,mvm_op_18_5);
	rglPushMatrix(mvm_work,shader);
	rglDinamometr_Draw(mvm_work,0.13,shkala,wplastic,stal,shader);
	
}

void Scena_Draw_18_6(rglMat4 mvm,GLuint h,GLuint wplastic,GLuint shkala,GLuint shkala2, GLuint yplastic, GLuint gplastic,GLuint stal,GLuint bplastic,GLuint shader)
{
	rglSetMaterial(3);
	rglMat4 mvm_op_18_6;
    rglMat4 mvm_work;
	
	rglMatrix4Identity(mvm_op_18_6);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_18_6,0.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_18_6);
	rglPushMatrix(mvm_work,shader);
	rglShtativ_Draw_3(mvm_work,yplastic,stal,bplastic,shader);
	
	
 	rglMatrix4Identity(mvm_op_18_6);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_18_6,0.0,30.0,4.0);
	rglMatrix4Multiply(mvm_work,mvm_op_18_6);
	rglPushMatrix(mvm_work,shader);
	rglRule_Draw(mvm_work,gplastic,bplastic,stal,shader);

	
	
	rglMatrix4Identity(mvm_op_18_6);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_18_6,-4.0,26.0,4.0);
	rglRotate(mvm_op_18_6,90.0,0.0,1.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_18_6);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_18_6);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_18_6,-4.0,22.5,4.0);
	rglMatrix4Multiply(mvm_work,mvm_op_18_6);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	
	rglMatrix4Identity(mvm_op_18_6);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_18_6,10.0,0.0,14.0);
	rglRotate(mvm_op_18_6,-90.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_18_6);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_18_6);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_18_6,8.0,28.3,3.4);
	rglRotate(mvm_op_18_6,180.0,0.0,0.0,1.0);
	rglMatrix4Multiply(mvm_work,mvm_op_18_6);
	rglPushMatrix(mvm_work,shader);
	rglDinamometr_Draw(mvm_work,0.07,shkala,wplastic,stal,shader);
	
}

void Scena_Draw_18_7(rglMat4 mvm,GLuint h,GLuint wplastic,GLuint shkala,GLuint shkala2, GLuint yplastic, GLuint gplastic,GLuint stal,GLuint bplastic,GLuint shader)
{
	rglSetMaterial(3);
	rglMat4 mvm_op_18_7;
    rglMat4 mvm_work;
	
	rglMatrix4Identity(mvm_op_18_7);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_18_7,0.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_18_7);
	rglPushMatrix(mvm_work,shader);
	rglShtativ_Draw_3(mvm_work,yplastic,stal,bplastic,shader);
	
	
 	rglMatrix4Identity(mvm_op_18_7);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_18_7,0.0,30.0,4.0);
	rglRotate(mvm_op_18_7,15.0,0.0,0.0,1.0);
	rglMatrix4Multiply(mvm_work,mvm_op_18_7);
	rglPushMatrix(mvm_work,shader);
	rglRule_Draw(mvm_work,gplastic,bplastic,stal,shader);

	
	
	rglMatrix4Identity(mvm_op_18_7);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_18_7,-7.8,24.4,4.0);
	rglRotate(mvm_op_18_7,90.0,0.0,1.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_18_7);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_18_7);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_18_7,-7.8,20.5,4.0);
	rglMatrix4Multiply(mvm_work,mvm_op_18_7);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_18_7);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_18_7,-7.8,16.6,4.0);
	rglRotate(mvm_op_18_7,90.0,0.0,1.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_18_7);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	
	rglMatrix4Identity(mvm_op_18_7);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_18_7,0.0,-1.0,10.4);
	rglRotate(mvm_op_18_7,-90.0,1.0,0.0,0.0);
	rglRotate(mvm_op_18_7,90.0,0.0,0.0,1.0);
	rglMatrix4Multiply(mvm_work,mvm_op_18_7);
	rglPushMatrix(mvm_work,shader);
	rglDinamometr_Draw(mvm_work,0.13,shkala,wplastic,stal,shader);
	
}

void Scena_Draw_18_8(rglMat4 mvm,GLuint h,GLuint wplastic,GLuint shkala,GLuint shkala2, GLuint yplastic, GLuint gplastic,GLuint stal,GLuint bplastic,GLuint shader)
{
	rglSetMaterial(3);
	rglMat4 mvm_op_18_8;
    rglMat4 mvm_work;
	
	rglMatrix4Identity(mvm_op_18_8);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_18_8,0.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_18_8);
	rglPushMatrix(mvm_work,shader);
	rglShtativ_Draw_3(mvm_work,yplastic,stal,bplastic,shader);
	
	
 	rglMatrix4Identity(mvm_op_18_8);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_18_8,0.0,30.0,4.0);
	rglMatrix4Multiply(mvm_work,mvm_op_18_8);
	rglPushMatrix(mvm_work,shader);
	rglRule_Draw(mvm_work,gplastic,bplastic,stal,shader);

	
	
	rglMatrix4Identity(mvm_op_18_8);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_18_8,-8.0,26.0,4.0);
	rglRotate(mvm_op_18_8,90.0,0.0,1.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_18_8);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_18_8);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_18_8,-8.0,22.1,4.0);
	rglMatrix4Multiply(mvm_work,mvm_op_18_8);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_18_8);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_18_8,-8.0,18.3,4.0);
	rglRotate(mvm_op_18_8,90.0,0.0,1.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_18_8);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	
    rglMatrix4Identity(mvm_op_18_8);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_18_8,12.0,26.3,3.4);
	rglRotate(mvm_op_18_8,180.0,0.0,0.0,1.0);
	rglMatrix4Multiply(mvm_work,mvm_op_18_8);
	rglPushMatrix(mvm_work,shader);
	rglDinamometr_Draw(mvm_work,0.11,shkala,wplastic,stal,shader);
	
}

void Scena_Draw_18_9(rglMat4 mvm,GLuint h,GLuint wplastic,GLuint shkala,GLuint shkala2, GLuint yplastic, GLuint gplastic,GLuint stal,GLuint bplastic,GLuint shader)
{
	rglSetMaterial(3);
	rglMat4 mvm_op_18_9;
    rglMat4 mvm_work;
	
	rglMatrix4Identity(mvm_op_18_9);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_18_9,0.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_18_9);
	rglPushMatrix(mvm_work,shader);
	rglShtativ_Draw_3(mvm_work,yplastic,stal,bplastic,shader);
	
	
    rglMatrix4Identity(mvm_op_18_9);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_18_9,0.0,0.0,7.0);
	rglMatrix4Multiply(mvm_work,mvm_op_18_9);
	rglPushMatrix(mvm_work,shader);
	rglRule_Draw(mvm_work,gplastic,bplastic,stal,shader);
	
	
	
	rglMatrix4Identity(mvm_op_18_9);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_18_9,2.0,0.0,11.0);
	rglRotate(mvm_op_18_9,90.0,0.0,1.0,0.0);
	rglRotate(mvm_op_18_9,-90.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_18_9);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_18_9);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_18_9,6.0,0.0,11.0);
	rglRotate(mvm_op_18_9,-90.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_18_9);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_18_9);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_18_9,10.0,0.0,11.0);
	rglRotate(mvm_op_18_9,90.0,0.0,1.0,0.0);
	rglRotate(mvm_op_18_9,60.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_18_9);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_18_9);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_18_9,10.0,0.0,14.0);
	rglRotate(mvm_op_18_9,-90.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_18_9);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
    rglMatrix4Identity(mvm_op_18_9);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_18_9,0.0,-1.0,10.4);
	rglRotate(mvm_op_18_9,-90.0,1.0,0.0,0.0);
	rglRotate(mvm_op_18_9,90.0,0.0,0.0,1.0);
	rglMatrix4Multiply(mvm_work,mvm_op_18_9);
	rglPushMatrix(mvm_work,shader);
	rglDinamometr_Draw(mvm_work,0.08,shkala,wplastic,stal,shader);
	
}

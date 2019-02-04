#include <GL/glew.h>
#include "rglScena_Draw_01.h"
#include "rglScena_Draw_03.h"
#include "rglScena_Draw_07.h"
#include "rglShader.h"
#include <SDL/SDL.h>

char *text7_1="|        1          |      4        |      0,025  |      2        |     0,045 |      0,1       |         0.09   | ";
char *text7_2="|        2          |      2        |      0,025  |      1.1     |     0,045 |      0,05     |       0.0495 | ";
char *text7_3="|        3          |      2        |      0,04    |      4,5     |     0,03   |      0,08     |         0.135 | ";
char *text7_0="|        0          |      0        |      0         |      0        |     0        |        0        |          0       | ";

GLint scena_ddraw_7=1;


GLint Scena_Draw_07_key_pressed(SDL_keysym *keysym)
{	
	
switch ( keysym->sym )
{
     
	 case SDLK_1:rglUpdateResult7(text7_0,text7_0,text7_0);scena_ddraw_7=1; break;
	 case SDLK_2:rglUpdateResult7(text7_0,text7_0,text7_0);scena_ddraw_7=2; break;
	 case SDLK_3:rglUpdateResult7(text7_0,text7_0,text7_0);scena_ddraw_7=3; break;
	 case SDLK_4:rglUpdateResult7(text7_0,text7_0,text7_0);scena_ddraw_7=4; break;
	 case SDLK_5:rglUpdateResult7(text7_0,text7_0,text7_0);scena_ddraw_7=5; break;
	 case SDLK_6:rglUpdateResult7(text7_1,text7_0,text7_0);scena_ddraw_7=6; break;
	 case SDLK_7:rglUpdateResult7(text7_1,text7_0,text7_0);scena_ddraw_7=7; break;
	 case SDLK_8:rglUpdateResult7(text7_1,text7_2,text7_0);scena_ddraw_7=8; break;
	 case SDLK_9:rglUpdateResult7(text7_1,text7_2,text7_0);scena_ddraw_7=9; break;
	 case SDLK_0:rglUpdateResult7(text7_1,text7_2,text7_3);scena_ddraw_7=0; break;
	
	default:		break;
}
    return 1;
}


void Scena_Draw_07(rglMat4 mvm,GLuint h, GLuint wplastic,GLuint shkala,GLuint shkala2, GLuint yplastic, GLuint gplastic,GLuint stal,GLuint bplastic,GLuint shader, GLuint shader2)
{
	switch (scena_ddraw_7)
	{
		
		case 1:Scena_Draw_07_1(mvm,0.05,wplastic,shkala,shkala2,yplastic,gplastic,stal,bplastic,shader);break;
		case 2:Scena_Draw_07_2(mvm,0.05,wplastic,shkala,shkala2,yplastic,gplastic,stal,bplastic,shader);break;
		case 3:Scena_Draw_07_3(mvm,0.05,wplastic,shkala,shkala2,yplastic,gplastic,stal,bplastic,shader);break;
	    case 4:Scena_Draw_07_4(mvm,0.05,wplastic,shkala,shkala2,yplastic,gplastic,stal,bplastic,shader);break;
	    case 5:Scena_Draw_07_5(mvm,0.13,wplastic,shkala,shkala2,yplastic,gplastic,stal,bplastic,shader);break;
	    case 6:Scena_Draw_07_6(mvm,0.13,wplastic,shkala,shkala2,yplastic,gplastic,stal,bplastic,shader);break;
	    case 7:Scena_Draw_07_7(mvm,0.09,wplastic,shkala,shkala2,yplastic,gplastic,stal,bplastic,shader);break;
        case 8:Scena_Draw_07_8(mvm,0.09,wplastic,shkala,shkala2,yplastic,gplastic,stal,bplastic,shader);break;
        case 9:Scena_Draw_07_9(mvm,0.09,wplastic,shkala,shkala2,yplastic,gplastic,stal,bplastic,shader);break;
        case 0:Scena_Draw_07_10(mvm,0.09,wplastic,shkala,shkala2,yplastic,gplastic,stal,bplastic,shader);break;
	
		default: 
		break;
		
	}

	 rglDrawResult7(1024,768, 20.0, 15.0, shader2);
}


void Scena_Draw_07_1(rglMat4 mvm,GLuint h,GLuint wplastic,GLuint shkala,GLuint shkala2, GLuint yplastic, GLuint gplastic,GLuint stal,GLuint bplastic,GLuint shader)
{
	rglSetMaterial(3);
	rglMat4 mvm_op_7_1;
    rglMat4 mvm_work;
	
	rglMatrix4Identity(mvm_op_7_1);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_7_1,0.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_7_1);
	rglPushMatrix(mvm_work,shader);
	rglShtativ_Draw_2(mvm_work,yplastic,stal,bplastic,shader);
	
	
    rglMatrix4Identity(mvm_op_7_1);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_7_1,0.0,0.0,7.0);
	rglMatrix4Multiply(mvm_work,mvm_op_7_1);
	rglPushMatrix(mvm_work,shader);
	rglRule_Draw(mvm_work,gplastic,bplastic,stal,shader);
	
	rglMatrix4Identity(mvm_op_7_1);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_7_1,19.0,2.0,-4.0);
	rglRotate(mvm_op_7_1,90.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_7_1);
	rglPushMatrix(mvm_work,shader);
	rglNapravlenie_Draw(mvm_work,shkala2,gplastic,yplastic,shader);
	
	
	rglMatrix4Identity(mvm_op_7_1);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_7_1,2.0,0.0,11.0);
	rglRotate(mvm_op_7_1,90.0,0.0,1.0,0.0);
	rglRotate(mvm_op_7_1,-90.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_7_1);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_7_1);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_7_1,6.0,0.0,11.0);
	rglRotate(mvm_op_7_1,-90.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_7_1);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_7_1);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_7_1,10.0,0.0,11.0);
	rglRotate(mvm_op_7_1,90.0,0.0,1.0,0.0);
	rglRotate(mvm_op_7_1,60.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_7_1);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_7_1);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_7_1,10.0,0.0,14.0);
	rglRotate(mvm_op_7_1,-90.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_7_1);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
    rglMatrix4Identity(mvm_op_7_1);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_7_1,0.0,-1.0,10.4);
	rglRotate(mvm_op_7_1,-90.0,1.0,0.0,0.0);
	rglRotate(mvm_op_7_1,90.0,0.0,0.0,1.0);
	rglMatrix4Multiply(mvm_work,mvm_op_7_1);
	rglPushMatrix(mvm_work,shader);
	rglDinamometr_Draw(mvm_work,0.08,shkala,wplastic,stal,shader);
	
}

void Scena_Draw_07_2(rglMat4 mvm,GLuint h,GLuint wplastic,GLuint shkala,GLuint shkala2, GLuint yplastic, GLuint gplastic,GLuint stal,GLuint bplastic,GLuint shader)
{
	rglSetMaterial(3);
	rglMat4 mvm_op_7_2;
    rglMat4 mvm_work;
	
	rglMatrix4Identity(mvm_op_7_2);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_7_2,0.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_7_2);
	rglPushMatrix(mvm_work,shader);
	rglShtativ_Draw_2(mvm_work,yplastic,stal,bplastic,shader);
	
	
    rglMatrix4Identity(mvm_op_7_2);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_7_2,0.0,20.0,4.0);
	rglMatrix4Multiply(mvm_work,mvm_op_7_2);
	rglPushMatrix(mvm_work,shader);
	rglRule_Draw(mvm_work,gplastic,bplastic,stal,shader);
	
	rglMatrix4Identity(mvm_op_7_2);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_7_2,19.0,2.0,-4.0);
	rglRotate(mvm_op_7_2,90.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_7_2);
	rglPushMatrix(mvm_work,shader);
	rglNapravlenie_Draw(mvm_work,shkala2,gplastic,yplastic,shader);
	
	
	rglMatrix4Identity(mvm_op_7_2);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_7_2,2.0,0.0,11.0);
	rglRotate(mvm_op_7_2,90.0,0.0,1.0,0.0);
	rglRotate(mvm_op_7_2,-90.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_7_2);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_7_2);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_7_2,6.0,0.0,11.0);
	rglRotate(mvm_op_7_2,-90.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_7_2);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_7_2);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_7_2,10.0,0.0,11.0);
	rglRotate(mvm_op_7_2,90.0,0.0,1.0,0.0);
	rglRotate(mvm_op_7_2,60.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_7_2);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_7_2);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_7_2,10.0,0.0,14.0);
	rglRotate(mvm_op_7_2,-90.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_7_2);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
    rglMatrix4Identity(mvm_op_7_2);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_7_2,0.0,-1.0,10.4);
	rglRotate(mvm_op_7_2,-90.0,1.0,0.0,0.0);
	rglRotate(mvm_op_7_2,90.0,0.0,0.0,1.0);
	rglMatrix4Multiply(mvm_work,mvm_op_7_2);
	rglPushMatrix(mvm_work,shader);
	rglDinamometr_Draw(mvm_work,0.08,shkala,wplastic,stal,shader);
	
}

void Scena_Draw_07_3(rglMat4 mvm,GLuint h,GLuint wplastic,GLuint shkala,GLuint shkala2, GLuint yplastic, GLuint gplastic,GLuint stal,GLuint bplastic,GLuint shader)
{
	rglSetMaterial(3);
	rglMat4 mvm_op_7_3;
    rglMat4 mvm_work;
	
	rglMatrix4Identity(mvm_op_7_3);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_7_3,0.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_7_3);
	rglPushMatrix(mvm_work,shader);
	rglShtativ_Draw_2(mvm_work,yplastic,stal,bplastic,shader);
	
	
    rglMatrix4Identity(mvm_op_7_3);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_7_3,0.0,20.0,4.0);
	rglMatrix4Multiply(mvm_work,mvm_op_7_3);
	rglPushMatrix(mvm_work,shader);
	rglRule_Draw(mvm_work,gplastic,bplastic,stal,shader);
	
	rglMatrix4Identity(mvm_op_7_3);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_7_3,12.0,2.0,-4.0);
	rglMatrix4Multiply(mvm_work,mvm_op_7_3);
	rglPushMatrix(mvm_work,shader);
	rglNapravlenie_Draw(mvm_work,shkala2,gplastic,yplastic,shader);
	
	
	rglMatrix4Identity(mvm_op_7_3);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_7_3,2.0,0.0,11.0);
	rglRotate(mvm_op_7_3,90.0,0.0,1.0,0.0);
	rglRotate(mvm_op_7_3,-90.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_7_3);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_7_3);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_7_3,6.0,0.0,11.0);
	rglRotate(mvm_op_7_3,-90.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_7_3);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_7_3);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_7_3,10.0,0.0,11.0);
	rglRotate(mvm_op_7_3,90.0,0.0,1.0,0.0);
	rglRotate(mvm_op_7_3,60.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_7_3);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_7_3);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_7_3,10.0,0.0,14.0);
	rglRotate(mvm_op_7_3,-90.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_7_3);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
    rglMatrix4Identity(mvm_op_7_3);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_7_3,0.0,-1.0,10.4);
	rglRotate(mvm_op_7_3,-90.0,1.0,0.0,0.0);
	rglRotate(mvm_op_7_3,90.0,0.0,0.0,1.0);
	rglMatrix4Multiply(mvm_work,mvm_op_7_3);
	rglPushMatrix(mvm_work,shader);
	rglDinamometr_Draw(mvm_work,0.08,shkala,wplastic,stal,shader);
	
}

void Scena_Draw_07_4(rglMat4 mvm,GLuint h,GLuint wplastic,GLuint shkala,GLuint shkala2, GLuint yplastic, GLuint gplastic,GLuint stal,GLuint bplastic,GLuint shader)
{
	rglSetMaterial(3);
	rglMat4 mvm_op_7_4;
    rglMat4 mvm_work;
	
	rglMatrix4Identity(mvm_op_7_4);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_7_4,0.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_7_4);
	rglPushMatrix(mvm_work,shader);
	rglShtativ_Draw_2(mvm_work,yplastic,stal,bplastic,shader);
	
	
 	rglMatrix4Identity(mvm_op_7_4);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_7_4,0.0,20.0,4.0);
	rglRotate(mvm_op_7_4,-30.0,0.0,0.0,1.0);
	rglMatrix4Multiply(mvm_work,mvm_op_7_4);
	rglPushMatrix(mvm_work,shader);
	rglRule_Draw(mvm_work,gplastic,bplastic,stal,shader);
	
	rglMatrix4Identity(mvm_op_7_4);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_7_4,12.0,2.0,-4.0);
	rglMatrix4Multiply(mvm_work,mvm_op_7_4);
	rglPushMatrix(mvm_work,shader);
	rglNapravlenie_Draw(mvm_work,shkala2,gplastic,yplastic,shader);
	
	
	rglMatrix4Identity(mvm_op_7_4);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_7_4,6.5,8.5,4.0);
	rglMatrix4Multiply(mvm_work,mvm_op_7_4);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_7_4);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_7_4,6.5,12.3,4.0);
	rglRotate(mvm_op_7_4,90.0,0.0,1.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_7_4);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_7_4);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_7_4,6.5,4.7,4.0);
	rglRotate(mvm_op_7_4,90.0,0.0,1.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_7_4);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_7_4);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_7_4,6.5,0.9,4.0);
	rglMatrix4Multiply(mvm_work,mvm_op_7_4);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_7_4);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_7_4,0.0,-1.0,10.4);
	rglRotate(mvm_op_7_4,-90.0,1.0,0.0,0.0);
	rglRotate(mvm_op_7_4,90.0,0.0,0.0,1.0);
	rglMatrix4Multiply(mvm_work,mvm_op_7_4);
	rglPushMatrix(mvm_work,shader);
	rglDinamometr_Draw(mvm_work,0.08,shkala,wplastic,stal,shader);
	
}

void Scena_Draw_07_5(rglMat4 mvm,GLuint h,GLuint wplastic,GLuint shkala,GLuint shkala2, GLuint yplastic, GLuint gplastic,GLuint stal,GLuint bplastic,GLuint shader)
{
	rglSetMaterial(3);
	rglMat4 mvm_op_7_5;
    rglMat4 mvm_work;
	
	rglMatrix4Identity(mvm_op_7_5);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_7_5,0.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_7_5);
	rglPushMatrix(mvm_work,shader);
	rglShtativ_Draw_2(mvm_work,yplastic,stal,bplastic,shader);
	
	
 	rglMatrix4Identity(mvm_op_7_5);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_7_5,0.0,20.0,4.0);
	rglMatrix4Multiply(mvm_work,mvm_op_7_5);
	rglPushMatrix(mvm_work,shader);
	rglRule_Draw(mvm_work,gplastic,bplastic,stal,shader);
	
	rglMatrix4Identity(mvm_op_7_5);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_7_5,12.0,2.0,-4.0);
	rglMatrix4Multiply(mvm_work,mvm_op_7_5);
	rglPushMatrix(mvm_work,shader);
	rglNapravlenie_Draw(mvm_work,shkala2,gplastic,yplastic,shader);
	
	
	rglMatrix4Identity(mvm_op_7_5);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_7_5,8.0,12.2,4.0);
	rglMatrix4Multiply(mvm_work,mvm_op_7_5);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_7_5);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_7_5,8.0,16.0,4.0);
	rglRotate(mvm_op_7_5,90.0,0.0,1.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_7_5);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_7_5);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_7_5,8.0,8.4,4.0);
	rglRotate(mvm_op_7_5,90.0,0.0,1.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_7_5);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_7_5);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_7_5,8.0,4.6,4.0);
	rglMatrix4Multiply(mvm_work,mvm_op_7_5);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_7_5);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_7_5,16.0,20.25,3.55);
	rglMatrix4Multiply(mvm_work,mvm_op_7_5);
	rglPushMatrix(mvm_work,shader);
	rglDinamometr_Draw(mvm_work,0.09,shkala,wplastic,stal,shader);
	
}

void Scena_Draw_07_6(rglMat4 mvm,GLuint h,GLuint wplastic,GLuint shkala,GLuint shkala2, GLuint yplastic, GLuint gplastic,GLuint stal,GLuint bplastic,GLuint shader)
{
	rglSetMaterial(3);
	rglMat4 mvm_op_7_6;
    rglMat4 mvm_work;
	
	rglMatrix4Identity(mvm_op_7_6);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_7_6,0.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_7_6);
	rglPushMatrix(mvm_work,shader);
	rglShtativ_Draw_2(mvm_work,yplastic,stal,bplastic,shader);
	
	
 	rglMatrix4Identity(mvm_op_7_6);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_7_6,0.0,20.0,4.0);
	rglRotate(mvm_op_7_6,15.0,0.0,0.0,1.0);
	rglMatrix4Multiply(mvm_work,mvm_op_7_6);
	rglPushMatrix(mvm_work,shader);
	rglRule_Draw(mvm_work,gplastic,bplastic,stal,shader);
	
	rglMatrix4Identity(mvm_op_7_6);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_7_6,12.0,2.0,-4.0);
	rglMatrix4Multiply(mvm_work,mvm_op_7_6);
	rglPushMatrix(mvm_work,shader);
	rglNapravlenie_Draw(mvm_work,shkala2,gplastic,yplastic,shader);
	
	
	rglMatrix4Identity(mvm_op_7_6);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_7_6,8.0,14.5,4.0);
	rglMatrix4Multiply(mvm_work,mvm_op_7_6);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_7_6);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_7_6,8.0,18.3,4.0);
	rglRotate(mvm_op_7_6,90.0,0.0,1.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_7_6);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_7_6);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_7_6,8.0,10.7,4.0);
	rglRotate(mvm_op_7_6,90.0,0.0,1.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_7_6);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_7_6);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_7_6,8.0,6.9,4.0);
	rglMatrix4Multiply(mvm_work,mvm_op_7_6);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_7_6);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_7_6,16.0,25.55,3.55);
	rglMatrix4Multiply(mvm_work,mvm_op_7_6);
	rglPushMatrix(mvm_work,shader);
	rglDinamometr_Draw(mvm_work,0.11,shkala,wplastic,stal,shader);
	
}

void Scena_Draw_07_7(rglMat4 mvm,GLuint h,GLuint wplastic,GLuint shkala,GLuint shkala2, GLuint yplastic, GLuint gplastic,GLuint stal,GLuint bplastic,GLuint shader)
{
	rglSetMaterial(3);
	rglMat4 mvm_op_7_7;
    rglMat4 mvm_work;
	
	rglMatrix4Identity(mvm_op_7_7);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_7_7,0.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_7_7);
	rglPushMatrix(mvm_work,shader);
	rglShtativ_Draw_2(mvm_work,yplastic,stal,bplastic,shader);
	
	
 	rglMatrix4Identity(mvm_op_7_7);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_7_7,0.0,20.0,4.0);
	rglMatrix4Multiply(mvm_work,mvm_op_7_7);
	rglPushMatrix(mvm_work,shader);
	rglRule_Draw(mvm_work,gplastic,bplastic,stal,shader);
	
	rglMatrix4Identity(mvm_op_7_7);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_7_7,12.0,2.0,-4.0);
	rglMatrix4Multiply(mvm_work,mvm_op_7_7);
	rglPushMatrix(mvm_work,shader);
	rglNapravlenie_Draw(mvm_work,shkala2,gplastic,yplastic,shader);
	
	
	rglMatrix4Identity(mvm_op_7_7);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_7_7,4.0,12.2,4.0);
	rglMatrix4Multiply(mvm_work,mvm_op_7_7);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_7_7);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_7_7,4.0,16.0,4.0);
	rglRotate(mvm_op_7_7,90.0,0.0,1.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_7_7);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	
	rglMatrix4Identity(mvm_op_7_7);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_7_7,12.0,18.8,3.55);
	rglMatrix4Multiply(mvm_work,mvm_op_7_7);
	rglPushMatrix(mvm_work,shader);
	rglDinamometr_Draw(mvm_work,0.07,shkala,wplastic,stal,shader);
	
}

void Scena_Draw_07_8(rglMat4 mvm,GLuint h,GLuint wplastic,GLuint shkala,GLuint shkala2, GLuint yplastic, GLuint gplastic,GLuint stal,GLuint bplastic,GLuint shader)
{
	rglSetMaterial(3);
	rglMat4 mvm_op_7_8;
    rglMat4 mvm_work;
	
	rglMatrix4Identity(mvm_op_7_8);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_7_8,0.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_7_8);
	rglPushMatrix(mvm_work,shader);
	rglShtativ_Draw_2(mvm_work,yplastic,stal,bplastic,shader);
	
	
 	rglMatrix4Identity(mvm_op_7_8);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_7_8,0.0,20.0,4.0);
	rglRotate(mvm_op_7_8,15.0,0.0,0.0,1.0);
	rglMatrix4Multiply(mvm_work,mvm_op_7_8);
	rglPushMatrix(mvm_work,shader);
	rglRule_Draw(mvm_work,gplastic,bplastic,stal,shader);
	
	rglMatrix4Identity(mvm_op_7_8);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_7_8,12.0,2.0,-4.0);
	rglMatrix4Multiply(mvm_work,mvm_op_7_8);
	rglPushMatrix(mvm_work,shader);
	rglNapravlenie_Draw(mvm_work,shkala2,gplastic,yplastic,shader);
	
	
	rglMatrix4Identity(mvm_op_7_8);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_7_8,4.0,13.2,4.0);
	rglMatrix4Multiply(mvm_work,mvm_op_7_8);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_7_8);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_7_8,4.0,17.0,4.0);
	rglRotate(mvm_op_7_8,90.0,0.0,1.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_7_8);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	
	rglMatrix4Identity(mvm_op_7_8);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_7_8,12.0,21.93,3.55);
	rglMatrix4Multiply(mvm_work,mvm_op_7_8);
	rglPushMatrix(mvm_work,shader);
	rglDinamometr_Draw(mvm_work,0.07,shkala,wplastic,stal,shader);
	
}

void Scena_Draw_07_9(rglMat4 mvm,GLuint h,GLuint wplastic,GLuint shkala,GLuint shkala2, GLuint yplastic, GLuint gplastic,GLuint stal,GLuint bplastic,GLuint shader)
{
	rglSetMaterial(3);
	rglMat4 mvm_op_7_9;
    rglMat4 mvm_work;
	
		rglMatrix4Identity(mvm_op_7_9);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_7_9,0.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_7_9);
	rglPushMatrix(mvm_work,shader);
	rglShtativ_Draw_2(mvm_work,yplastic,stal,bplastic,shader);
	
	
 	rglMatrix4Identity(mvm_op_7_9);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_7_9,0.0,20.0,4.0);
	rglMatrix4Multiply(mvm_work,mvm_op_7_9);
	rglPushMatrix(mvm_work,shader);
	rglRule_Draw(mvm_work,gplastic,bplastic,stal,shader);
	
	rglMatrix4Identity(mvm_op_7_9);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_7_9,14.0,2.0,-4.0);
	rglMatrix4Multiply(mvm_work,mvm_op_7_9);
	rglPushMatrix(mvm_work,shader);
	rglNapravlenie_Draw(mvm_work,shkala2,gplastic,yplastic,shader);
	
	
	rglMatrix4Identity(mvm_op_7_9);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_7_9,16.0,12.2,4.0);
	rglMatrix4Multiply(mvm_work,mvm_op_7_9);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_7_9);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_7_9,16.0,16.0,4.0);
	rglRotate(mvm_op_7_9,90.0,0.0,1.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_7_9);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	
	rglMatrix4Identity(mvm_op_7_9);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_7_9,8.0,23.0,3.55);
	rglMatrix4Multiply(mvm_work,mvm_op_7_9);
	rglPushMatrix(mvm_work,shader);
	rglDinamometr_Draw(mvm_work,0.14,shkala,wplastic,stal,shader);
	
}

void Scena_Draw_07_10(rglMat4 mvm,GLuint h,GLuint wplastic,GLuint shkala,GLuint shkala2, GLuint yplastic, GLuint gplastic,GLuint stal,GLuint bplastic,GLuint shader)
{
	rglSetMaterial(3);
	rglMat4 mvm_op_7_10;
    rglMat4 mvm_work;
	
	rglMatrix4Identity(mvm_op_7_10);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_7_10,0.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_7_10);
	rglPushMatrix(mvm_work,shader);
	rglShtativ_Draw_2(mvm_work,yplastic,stal,bplastic,shader);
	
	
 	rglMatrix4Identity(mvm_op_7_10);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_7_10,0.0,20.0,4.0);
	rglRotate(mvm_op_7_10,15.0,0.0,0.0,1.0);
	rglMatrix4Multiply(mvm_work,mvm_op_7_10);
	rglPushMatrix(mvm_work,shader);
	rglRule_Draw(mvm_work,gplastic,bplastic,stal,shader);
	
	rglMatrix4Identity(mvm_op_7_10);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_7_10,14.0,2.0,-4.0);
	rglMatrix4Multiply(mvm_work,mvm_op_7_10);
	rglPushMatrix(mvm_work,shader);
	rglNapravlenie_Draw(mvm_work,shkala2,gplastic,yplastic,shader);
	
	
	rglMatrix4Identity(mvm_op_7_10);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_7_10,15.5,16.5,4.0);
	rglMatrix4Multiply(mvm_work,mvm_op_7_10);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_7_10);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_7_10,15.5,20.5,4.0);
	rglRotate(mvm_op_7_10,90.0,0.0,1.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_7_10);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	
	rglMatrix4Identity(mvm_op_7_10);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_7_10,8.3,25.2,3.55);
	rglMatrix4Multiply(mvm_work,mvm_op_7_10);
	rglPushMatrix(mvm_work,shader);
	rglDinamometr_Draw(mvm_work,0.14,shkala,wplastic,stal,shader);
	
}



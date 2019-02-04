#include <GL/glew.h>
#include "rglScena_Draw_03.h"
#include "rglShader.h"
#include <SDL/SDL.h>
char *text1="|        1          |      1        |      20       |      2        |     10      |      0,5       |         2        | ";
char *text2="|        2          |      3        |      20       |      2        |     10      |      1,5       |         2        | ";
char *text3="|        3          |      3        |      7         |      1        |     21      |        3        |         0.33   | ";
char *text4="|        4          |      1        |      21       |      3        |     7        |        0.33   |          3       | ";
char *text0="|        0          |      0        |      0         |      0        |     0        |        0        |          0       | ";

GLint scena_ddraw=1;

GLint Scena_Draw_03_key_pressed(SDL_keysym *keysym)
{	
	
	
switch ( keysym->sym )
{
     case SDLK_1:rglUpdateResult3(text0,text0,text0,text0);scena_ddraw=1; break;
	 case SDLK_2:rglUpdateResult3(text0,text0,text0,text0);scena_ddraw=2; break;
	 case SDLK_3:rglUpdateResult3(text0,text0,text0,text0);scena_ddraw=3; break;
	 case SDLK_4:rglUpdateResult3(text1,text0,text0,text0);scena_ddraw=4; break;
	 case SDLK_5:rglUpdateResult3(text1,text2,text0,text0);scena_ddraw=5; break;
	 case SDLK_6:rglUpdateResult3(text1,text2,text3,text0);scena_ddraw=6; break;
	 case SDLK_7:rglUpdateResult3(text1,text2,text3,text0);scena_ddraw=7; break;
	 case SDLK_8:rglUpdateResult3(text1,text2,text3,text4);scena_ddraw=8; break;
     case SDLK_9:rglUpdateResult3(text1,text2,text3,text4);scena_ddraw=9; break;
	default:		break;
}
    return 1;
}


void Scena_Draw_03_1(rglMat4 mvm, GLuint yplastic, GLuint gplastic,GLuint stal,GLuint bplastic,GLuint shader)
{
	rglSetMaterial(3);
	rglMat4 mvm_op_3_1;
    rglMat4 mvm_work;
	
	rglMatrix4Identity(mvm_op_3_1);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_3_1,0.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_3_1);
	rglPushMatrix(mvm_work,shader);
	rglShtativ_Draw_2(mvm_work,yplastic,stal,bplastic,shader);
	
	
 	rglMatrix4Identity(mvm_op_3_1);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_3_1,0.0,0.0,7.0);
	rglMatrix4Multiply(mvm_work,mvm_op_3_1);
	rglPushMatrix(mvm_work,shader);
	rglRule_Draw(mvm_work,gplastic,bplastic,stal,shader);
	
	
	rglMatrix4Identity(mvm_op_3_1);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_3_1,2.0,0.0,11.0);
	rglRotate(mvm_op_3_1,90.0,0.0,1.0,0.0);
	rglRotate(mvm_op_3_1,-90.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_3_1);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_3_1);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_3_1,6.0,0.0,11.0);
	rglRotate(mvm_op_3_1,-90.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_3_1);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_3_1);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_3_1,10.0,0.0,11.0);
	rglRotate(mvm_op_3_1,90.0,0.0,1.0,0.0);
	rglRotate(mvm_op_3_1,60.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_3_1);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_3_1);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_3_1,10.0,0.0,14.0);
	rglRotate(mvm_op_3_1,-90.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_3_1);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_3_1);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_3_1,14.0,0.0,14.0);
	rglRotate(mvm_op_3_1,90.0,0.0,1.0,0.0);
	rglRotate(mvm_op_3_1,60.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_3_1);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
}

void Scena_Draw_03_2(rglMat4 mvm, GLuint yplastic, GLuint gplastic,GLuint stal,GLuint bplastic,GLuint shader)
{
	rglSetMaterial(3);
	rglMat4 mvm_op_3_2;
    rglMat4 mvm_work;
	
	rglMatrix4Identity(mvm_op_3_2);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_3_2,0.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_3_2);
	rglPushMatrix(mvm_work,shader);
	rglShtativ_Draw_2(mvm_work,yplastic,stal,bplastic,shader);
	
	
 	
 	rglMatrix4Identity(mvm_op_3_2);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_3_2,0.0,20.0,4.0);
	rglMatrix4Multiply(mvm_work,mvm_op_3_2);
	rglPushMatrix(mvm_work,shader);
	rglRule_Draw(mvm_work,gplastic,bplastic,stal,shader);
	
	
	rglMatrix4Identity(mvm_op_3_2);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_3_2,2.0,0.0,11.0);
	rglRotate(mvm_op_3_2,90.0,0.0,1.0,0.0);
	rglRotate(mvm_op_3_2,-90.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_3_2);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_3_2);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_3_2,6.0,0.0,11.0);
	rglRotate(mvm_op_3_2,-90.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_3_2);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_3_2);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_3_2,10.0,0.0,11.0);
	rglRotate(mvm_op_3_2,90.0,0.0,1.0,0.0);
	rglRotate(mvm_op_3_2,60.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_3_2);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_3_2);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_3_2,10.0,0.0,14.0);
	rglRotate(mvm_op_3_2,-90.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_3_2);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_3_2);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_3_2,14.0,0.0,14.0);
	rglRotate(mvm_op_3_2,90.0,0.0,1.0,0.0);
	rglRotate(mvm_op_3_2,60.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_3_2);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
}

void Scena_Draw_03_3_1(rglMat4 mvm, GLuint yplastic, GLuint gplastic,GLuint stal,GLuint bplastic,GLuint shader)
{
	rglSetMaterial(3);
	rglMat4 mvm_op_3_3_1;
    rglMat4 mvm_work;
	
	rglMatrix4Identity(mvm_op_3_3_1);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_3_3_1,0.0,0.0,0.0);
	
	rglMatrix4Multiply(mvm_work,mvm_op_3_3_1);
	rglPushMatrix(mvm_work,shader);
	rglShtativ_Draw_2(mvm_work,yplastic,stal,bplastic,shader);
	
	
 	
 	rglMatrix4Identity(mvm_op_3_3_1);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_3_3_1,0.0,20.0,4.0);
	rglRotate(mvm_op_3_3_1,-40.0,0.0,0.0,1.0);
	rglMatrix4Multiply(mvm_work,mvm_op_3_3_1);
	rglPushMatrix(mvm_work,shader);
	rglRule_Draw(mvm_work,gplastic,bplastic,stal,shader);
	
	
	rglMatrix4Identity(mvm_op_3_3_1);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_3_3_1,5.5,11.0,4.0);
	rglRotate(mvm_op_3_3_1,90.0,0.0,1.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_3_3_1);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_3_3_1);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_3_3_1,5.5,7.5,4.0);
	rglMatrix4Multiply(mvm_work,mvm_op_3_3_1);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_3_3_1);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_3_3_1,10.0,0.0,11.0);
	rglRotate(mvm_op_3_3_1,90.0,0.0,1.0,0.0);
	rglRotate(mvm_op_3_3_1,60.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_3_3_1);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_3_3_1);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_3_3_1,10.0,0.0,14.0);
	rglRotate(mvm_op_3_3_1,-90.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_3_3_1);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_3_3_1);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_3_3_1,14.0,0.0,14.0);
	rglRotate(mvm_op_3_3_1,90.0,0.0,1.0,0.0);
	rglRotate(mvm_op_3_3_1,60.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_3_3_1);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
}

void Scena_Draw_03_3_2(rglMat4 mvm, GLuint yplastic, GLuint gplastic,GLuint stal,GLuint bplastic,GLuint shader)
{
	rglSetMaterial(3);
	rglMat4 mvm_op_3_3_2;
    rglMat4 mvm_work;
	
	rglMatrix4Identity(mvm_op_3_3_2);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_3_3_2,0.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_3_3_2);
	rglPushMatrix(mvm_work,shader);
	rglShtativ_Draw_2(mvm_work,yplastic,stal,bplastic,shader);
	
	
 	rglMatrix4Identity(mvm_op_3_3_2);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_3_3_2,0.0,20.0,4.0);
	rglMatrix4Multiply(mvm_work,mvm_op_3_3_2);
	rglPushMatrix(mvm_work,shader);
	rglRule_Draw(mvm_work,gplastic,bplastic,stal,shader);
	
	
	rglMatrix4Identity(mvm_op_3_3_2);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_3_3_2,8.0,16.0,4.0);
	rglRotate(mvm_op_3_3_2,90.0,0.0,1.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_3_3_2);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_3_3_2);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_3_3_2,8.0,12.2,4.0);
	rglMatrix4Multiply(mvm_work,mvm_op_3_3_2);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_3_3_2);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_3_3_2,-16.0,16.0,4.0);
	rglRotate(mvm_op_3_3_2,90.0,0.0,1.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_3_3_2);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
		
		
	rglMatrix4Identity(mvm_op_3_3_2);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_3_3_2,10.0,0.0,14.0);
	rglRotate(mvm_op_3_3_2,-90.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_3_3_2);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_3_3_2);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_3_3_2,14.0,0.0,14.0);
	rglRotate(mvm_op_3_3_2,90.0,0.0,1.0,0.0);
	rglRotate(mvm_op_3_3_2,60.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_3_3_2);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
}

void Scena_Draw_03_4_1(rglMat4 mvm, GLuint yplastic, GLuint gplastic,GLuint stal,GLuint bplastic,GLuint shader)
{
	rglSetMaterial(3);
	rglMat4 mvm_op_3_4_1;
    rglMat4 mvm_work;
	
	rglMatrix4Identity(mvm_op_3_4_1);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_3_4_1,0.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_3_4_1);
	rglPushMatrix(mvm_work,shader);
	rglShtativ_Draw_2(mvm_work,yplastic,stal,bplastic,shader);
	
	
 	rglMatrix4Identity(mvm_op_3_4_1);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_3_4_1,0.0,20.0,4.0);
	rglRotate(mvm_op_3_4_1,30.0,0.0,0.0,1.0);
	rglMatrix4Multiply(mvm_work,mvm_op_3_4_1);
	rglPushMatrix(mvm_work,shader);
	rglRule_Draw(mvm_work,gplastic,bplastic,stal,shader);
	
	
	rglMatrix4Identity(mvm_op_3_4_1);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_3_4_1,7.5,20.3,4.0);
	rglRotate(mvm_op_3_4_1,90.0,0.0,1.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_3_4_1);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_3_4_1);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_3_4_1,7.5,16.5,4.0);
	rglMatrix4Multiply(mvm_work,mvm_op_3_4_1);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_3_4_1);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_3_4_1,-13.5,8.4,4.0);
	rglRotate(mvm_op_3_4_1,90.0,0.0,1.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_3_4_1);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_3_4_1);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_3_4_1,-13.5,4.5,4.0);
	rglMatrix4Multiply(mvm_work,mvm_op_3_4_1);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_3_4_1);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_3_4_1,-13.5,0.7,4.0);
	rglRotate(mvm_op_3_4_1,90.0,0.0,1.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_3_4_1);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
		
}

void Scena_Draw_03_4_2(rglMat4 mvm, GLuint yplastic, GLuint gplastic,GLuint stal,GLuint bplastic,GLuint shader)
{
	rglSetMaterial(3);
	rglMat4 mvm_op_3_4_2;
    rglMat4 mvm_work;
	
	rglMatrix4Identity(mvm_op_3_4_2);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_3_4_2,0.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_3_4_2);
	rglPushMatrix(mvm_work,shader);
	rglShtativ_Draw_2(mvm_work,yplastic,stal,bplastic,shader);
	
	
 	rglMatrix4Identity(mvm_op_3_4_2);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_3_4_2,0.0,20.0,4.0);
	rglMatrix4Multiply(mvm_work,mvm_op_3_4_2);
	rglPushMatrix(mvm_work,shader);
	rglRule_Draw(mvm_work,gplastic,bplastic,stal,shader);
	
	
	rglMatrix4Identity(mvm_op_3_4_2);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_3_4_2,16.0,16.0,4.0);
	rglRotate(mvm_op_3_4_2,90.0,0.0,1.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_3_4_2);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	
	rglMatrix4Identity(mvm_op_3_4_2);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_3_4_2,-4.0,16.0,4.0);
	rglRotate(mvm_op_3_4_2,90.0,0.0,1.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_3_4_2);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_3_4_2);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_3_4_2,-4.0,12.2,4.0);
	rglMatrix4Multiply(mvm_work,mvm_op_3_4_2);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_3_4_2);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_3_4_2,-4.0,8.4,4.0);
	rglRotate(mvm_op_3_4_2,90.0,0.0,1.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_3_4_2);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
		
}

void Scena_Draw_03_5_1(rglMat4 mvm, GLuint yplastic, GLuint gplastic,GLuint stal,GLuint bplastic,GLuint shader)
{
	rglSetMaterial(3);
	rglMat4 mvm_op_3_5_1;
    rglMat4 mvm_work;
	
	rglMatrix4Identity(mvm_op_3_5_1);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_3_5_1,0.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_3_5_1);
	rglPushMatrix(mvm_work,shader);
	rglShtativ_Draw_2(mvm_work,yplastic,stal,bplastic,shader);
	
	
 	rglMatrix4Identity(mvm_op_3_5_1);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_3_5_1,0.0,20.0,4.0);
	rglRotate(mvm_op_3_5_1,-30.0,0.0,0.0,1.0);
	rglMatrix4Multiply(mvm_work,mvm_op_3_5_1);
	rglPushMatrix(mvm_work,shader);
	rglRule_Draw(mvm_work,gplastic,bplastic,stal,shader);
	
	
	rglMatrix4Identity(mvm_op_3_5_1);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_3_5_1,2.6,14.5,4.0);
	rglRotate(mvm_op_3_5_1,90.0,0.0,1.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_3_5_1);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_3_5_1);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_3_5_1,2.6,11.2,4.0);
	rglMatrix4Multiply(mvm_work,mvm_op_3_5_1);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_3_5_1);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_3_5_1,2.6,7.4,4.0);
	rglRotate(mvm_op_3_5_1,90.0,0.0,1.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_3_5_1);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
		
}

void Scena_Draw_03_5_2(rglMat4 mvm, GLuint yplastic, GLuint gplastic,GLuint stal,GLuint bplastic,GLuint shader)
{
	rglSetMaterial(3);
	rglMat4 mvm_op_3_5_2;
    rglMat4 mvm_work;
	
	rglMatrix4Identity(mvm_op_3_5_2);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_3_5_2,0.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_3_5_2);
	rglPushMatrix(mvm_work,shader);
	rglShtativ_Draw_2(mvm_work,yplastic,stal,bplastic,shader);
	
	
 	rglMatrix4Identity(mvm_op_3_5_2);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_3_5_2,0.0,20.0,4.0);
	rglMatrix4Multiply(mvm_work,mvm_op_3_5_2);
	rglPushMatrix(mvm_work,shader);
	rglRule_Draw(mvm_work,gplastic,bplastic,stal,shader);
	
	
	rglMatrix4Identity(mvm_op_3_5_2);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_3_5_2,-16.0,16.0,4.0);
	rglRotate(mvm_op_3_5_2,90.0,0.0,1.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_3_5_2);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	
	rglMatrix4Identity(mvm_op_3_5_2);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_3_5_2,4.0,16.0,4.0);
	rglRotate(mvm_op_3_5_2,90.0,0.0,1.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_3_5_2);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_3_5_2);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_3_5_2,4.0,12.2,4.0);
	rglMatrix4Multiply(mvm_work,mvm_op_3_5_2);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_3_5_2);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_3_5_2,4.0,8.4,4.0);
	rglRotate(mvm_op_3_5_2,90.0,0.0,1.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_3_5_2);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
		
}

void Scena_Draw_03_6_1(rglMat4 mvm, GLuint yplastic, GLuint gplastic,GLuint stal,GLuint bplastic,GLuint shader)
{
	rglSetMaterial(3);
	rglMat4 mvm_op_3_6_1;
    rglMat4 mvm_work;
	
	rglMatrix4Identity(mvm_op_3_6_1);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_3_6_1,0.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_3_6_1);
	rglPushMatrix(mvm_work,shader);
	rglShtativ_Draw_2(mvm_work,yplastic,stal,bplastic,shader);
	
	
 	rglMatrix4Identity(mvm_op_3_6_1);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_3_6_1,0.0,0.0,7.0);
	rglMatrix4Multiply(mvm_work,mvm_op_3_6_1);
	rglPushMatrix(mvm_work,shader);
	rglRule_Draw(mvm_work,gplastic,bplastic,stal,shader);
	
	
	rglMatrix4Identity(mvm_op_3_6_1);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_3_6_1,2.0,0.0,11.0);
	rglRotate(mvm_op_3_6_1,90.0,0.0,1.0,0.0);
	rglRotate(mvm_op_3_6_1,-90.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_3_6_1);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_3_6_1);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_3_6_1,6.0,0.0,11.0);
	rglRotate(mvm_op_3_6_1,-90.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_3_6_1);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_3_6_1);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_3_6_1,10.0,0.0,11.0);
	rglRotate(mvm_op_3_6_1,90.0,0.0,1.0,0.0);
	rglRotate(mvm_op_3_6_1,60.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_3_6_1);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_3_6_1);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_3_6_1,10.0,0.0,14.0);
	rglRotate(mvm_op_3_6_1,-90.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_3_6_1);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
	rglMatrix4Identity(mvm_op_3_6_1);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_op_3_6_1,14.0,0.0,14.0);
	rglRotate(mvm_op_3_6_1,90.0,0.0,1.0,0.0);
	rglRotate(mvm_op_3_6_1,60.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_op_3_6_1);
	rglPushMatrix(mvm_work,shader);
	rglGruzik_Draw(mvm_work,32,32,1.5,1.5,2*M_PI,stal,shader);
	
}

void Scena_Draw_03(rglMat4 mvm, GLuint yplastic, GLuint gplastic,GLuint stal,GLuint bplastic,GLuint shader, GLuint shader2)
{

switch (scena_ddraw)
	{
		case 1:Scena_Draw_03_1(mvm,yplastic,gplastic,stal,bplastic,shader);break;
		case 2:Scena_Draw_03_2(mvm,yplastic,gplastic,stal,bplastic,shader);break;
		case 3:Scena_Draw_03_3_1(mvm,yplastic,gplastic,stal,bplastic,shader);break;
		case 4:Scena_Draw_03_3_2(mvm,yplastic,gplastic,stal,bplastic,shader);break;
		case 5:Scena_Draw_03_4_1(mvm,yplastic,gplastic,stal,bplastic,shader);break;
		case 6:Scena_Draw_03_4_2(mvm,yplastic,gplastic,stal,bplastic,shader);break;
		case 7:Scena_Draw_03_5_1(mvm,yplastic,gplastic,stal,bplastic,shader);break;
		case 8:Scena_Draw_03_5_2(mvm,yplastic,gplastic,stal,bplastic,shader);break;
		case 9:Scena_Draw_03_6_1(mvm,yplastic,gplastic,stal,bplastic,shader);break;
		default: 
		break;
		
	}
   rglDrawResult3(1024,768, 20.0, 15.0, shader2);
}




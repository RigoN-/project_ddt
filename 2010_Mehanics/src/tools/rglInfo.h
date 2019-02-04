#ifndef _RGLINFO_H
#define _RGLINFO_H
#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <GL/gl.h>
#include <SDL/SDL_ttf.h>

#include "rglText.h"

#include "rglRender.h"
#include "rglMaterial.h"


TTF_Font *font_13;
TTF_Font *font_13b;
TTF_Font *font_14b;
TTF_Font *font_24b;

GLuint result_fon, result_tx01,result_tx02, result_tx03, result_tx04, result_tx05, result_tx06, result_tx07, load_tx01, info_tx01,info_tx02,info_tx03,info_tx04, info_tx05, info_tx06, info_tx07, info_tx08, info_tx09, info_tx10, info_tx11, info_tx12, info_tx13,info_tx14,info_tx15, info_tx16, table_info, multi_text_tx01,tex_render;

extern  void rglInitInfo(char *caption);
extern  void rglUpdateInfo(char *text);
extern  void rglDeleteInfo();
extern  void rglDrawInfo(GLint width, GLint height, GLfloat dx, GLfloat dy, GLuint shader,GLuint blend_mode);
extern  void rglDrawInfoFFP(GLint width, GLint height, GLfloat dx, GLfloat dy, GLuint blend_mode);

extern void rglInitTable(char *caption );
extern void rglUpdateTable(char *text);
extern void rglDrawTable(GLint width, GLint height, GLfloat ix, GLfloat iy, GLuint shader);

extern void rglInitLoad(char *caption );
extern void rglUpdateLoad(char *text);
extern void rglDrawLoad(GLint width, GLint height, GLfloat ix, GLfloat iy, GLuint shader);

extern void rglDrawInfoToTexture(GLint width, GLint height, GLfloat dx, GLfloat dy, GLuint blend_mode);
extern void rglDrawInfo2();

extern void rglInitResultTable( );
extern void rglDrawResultTableFFP(GLint width, GLint height, GLfloat x, GLfloat y, GLfloat dx);
extern void rglDrawResultToTexture(GLint width, GLint height, GLfloat x, GLfloat y, GLfloat dx);
extern void rglDrawResultTable();

extern void rglDrawResult3(GLint width, GLint height, GLfloat dx, GLfloat dy, GLuint shader);
extern void rglUpdateResult3(char *text1, char *text2, char *text3, char *text4);
extern void rglInitResult3( );

extern void rglDrawResult7(GLint width, GLint height, GLfloat dx, GLfloat dy, GLuint shader);
extern void rglUpdateResult7(char *text1, char *text2, char *text3);
extern void rglInitResult7( );

extern void rglDrawResult14(GLint width, GLint height, GLfloat dx, GLfloat dy, GLuint shader);
extern void rglInitResult14( );

extern void rglDrawResult18(GLint width, GLint height, GLfloat dx, GLfloat dy, GLuint shader);
extern void rglUpdateResult18(char *text1, char *text2, char *text3);
extern void rglInitResult18( );

extern void rglDrawResult19(GLint width, GLint height, GLfloat dx, GLfloat dy, GLuint shader);
extern void rglUpdateResult19(char *text1, char *text2, char *text3);
extern void rglInitResult19( );


extern void rglDrawResult1(GLint width, GLint height, GLfloat dx, GLfloat dy, GLuint shader);
//extern void rglUpdateResult3(char *text1, char *text2, char *text3, char *text4);
extern void rglInitResult1( );
#endif

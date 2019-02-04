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
TTF_Font *font_24b;

GLuint info_tx01,info_tx02,info_tx03,info_tx04, info_tx05, info_tx06, info_tx07, info_tx08, info_tx09, info_tx10, info_tx11, info_tx12, info_tx13,table_info, multi_text_tx01;

extern  void rglInitInfo(char *caption);
extern  void rglUpdateInfo(char *text);
extern  void rglDeleteInfo();
extern  void rglDrawInfo(GLint width, GLint height, GLfloat dx, GLfloat dy, GLuint shader);
extern  void rglDrawInfo_ffp();

extern void rglInitTable(char *caption );
extern void rglUpdateTable(char *text);
extern void rglDrawTable(GLint width, GLint height, GLfloat ix, GLfloat iy, GLuint shader);

#endif

#ifndef _SCENADRAWBOOK_H
#define _SCENADRAWBOOK_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/gl.h>
#include <GL/glext.h>
#include <GL/glu.h>
#include "rglMath3D.h"
#include "rglMaterial.h"
#include "rglMesh3D.h"
#include "rglFigures.h"
#include "rglTexture.h"
#include <SDL/SDL.h>


extern void Scena_book(rglMat4 mvm, rglMat4 pvm, GLuint shader);
extern GLint Scena_Draw_book_key_pressed(SDL_keysym *keysym);
extern GLvoid book_ogl_init_textures(  );
extern GLvoid book_anim_proc();
extern void scena0(rglMat4 mvm, GLuint shader);
extern void scena1(rglMat4 mvm, GLuint shader);
extern void scena2(rglMat4 mvm, GLuint shader);
extern void scena3(rglMat4 mvm, GLuint shader);
extern void scena4(rglMat4 mvm, GLuint shader);
extern void scena5(rglMat4 mvm, GLuint shader);
extern void page_draw(GLfloat x0, GLfloat y0, GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLfloat x3, GLfloat y3, GLfloat z0,  GLfloat z1, GLuint face, GLuint back, GLuint torec);
extern void oblojka_draw(GLfloat x0, GLfloat y0, GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLfloat x3, GLfloat y3, GLfloat z0,  GLfloat z1, GLuint face, GLuint back, GLuint torec);


#endif

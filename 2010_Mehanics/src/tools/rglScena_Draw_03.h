#ifndef _SCENADRAW03_H
#define _SCENADRAW03_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/gl.h>
#include <GL/glext.h>
#include <GL/glu.h>
#include "rglMath3D.h"
#include "rglMaterial.h"
#include "rglMesh3D.h"
#include "rglInfo.h"
#include <SDL/SDL.h>


extern GLint Scena_Draw_03_key_pressed(SDL_keysym *keysym);
extern void Scena_Draw_03(rglMat4 mvm, GLuint yplastic, GLuint gplastic,GLuint stal,GLuint bplastic,GLuint shader, GLuint shader2);
extern void Scena_Draw_03_1(rglMat4 mvm, GLuint yplastic, GLuint gplastic,GLuint stal,GLuint bplastic,GLuint shader);
extern void Scena_Draw_03_2(rglMat4 mvm, GLuint yplastic, GLuint gplastic,GLuint stal,GLuint bplastic,GLuint shader);
extern void Scena_Draw_03_3_1(rglMat4 mvm, GLuint yplastic, GLuint gplastic,GLuint stal,GLuint bplastic,GLuint shader);
extern void Scena_Draw_03_3_2(rglMat4 mvm, GLuint yplastic, GLuint gplastic,GLuint stal,GLuint bplastic,GLuint shader);
extern void Scena_Draw_03_4_1(rglMat4 mvm, GLuint yplastic, GLuint gplastic,GLuint stal,GLuint bplastic,GLuint shader);
extern void Scena_Draw_03_4_2(rglMat4 mvm, GLuint yplastic, GLuint gplastic,GLuint stal,GLuint bplastic,GLuint shader);
extern void Scena_Draw_03_5_1(rglMat4 mvm, GLuint yplastic, GLuint gplastic,GLuint stal,GLuint bplastic,GLuint shader);
extern void Scena_Draw_03_5_2(rglMat4 mvm, GLuint yplastic, GLuint gplastic,GLuint stal,GLuint bplastic,GLuint shader);
extern void Scena_Draw_03_6_1(rglMat4 mvm, GLuint yplastic, GLuint gplastic,GLuint stal,GLuint bplastic,GLuint shader);


#endif

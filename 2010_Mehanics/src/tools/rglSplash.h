#ifndef _RGLSPLASH_H
#define _RGLSPLASH_H
#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <GL/gl.h>

#include "rglRender.h"
#include "rglMaterial.h"
#include "rglMath3D.h"
#include "rglShader.h"
#include "rglTexture.h"

GLuint foto_tx01, foto_tx02, foto_tx03, foto_tx04,  foto_tx05,  foto_tx06, foto_tx07, foto_tx08, foto_tx09, foto_tx10,top_tx, center_tx,buttom_tx, title_tx0,title_tx1 ,title_tx2, fon_tx0,  fon_tx1,  devel_tx0, devel_tx1;

extern GLvoid splash_init_textures(  );
extern GLvoid rglDrawSplash(GLuint b);
extern GLvoid rglDrawSplash2(GLuint b);
extern GLvoid splash_anim(  );

#endif

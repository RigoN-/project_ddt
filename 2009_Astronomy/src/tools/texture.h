#ifndef _TEXTURE_H
#define _TEXTURE_H
#include "image_lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glext.h>

#define IMG_BMP 1
#define IMG_TGA 2
#define IMG_JPEG 3
// texture filter type
#define txNoFilter 0
#define txBilinear 1
#define txTrilinear 3
#define txAnisotropic_02 2
#define txAnisotropic_04 4
#define txAnisotropic_08 8
#define txAnisotropic_16 16
// texture compressed type
#define txNoCompressed 0


GLboolean LoadTextures(char *filename,GLuint *texti);
GLboolean OGL_Load_Texture(char *filename, GLuint *texti, GLuint txFilter, GLuint txMode, GLuint txPlace, GLuint txCompress, GLboolean txMip_map);
//Filename - имя файла
//texti - openg текстура
//txFilter - фильтрация (txNoFilter, txBilinear, txTrilinear, txAnisotropic_02, txAnisotropic_04, txAnisotropic_08, txAnisotropic_16)
// txMode режим наложения (GL_REPLACE, GL_BLEND,  GL_DECAL,  GL_MODULATE)
//txPlace способ наложения (GL_REPEAT,GL_CLAMP_TO_EDGE, GL_CLAMP)
//txCompress - способ сжатия текстур (txNoCompressed)
//txMip_map - мипмапинг включение и выключение (GL_TRUE, GL_FALSE)
#endif

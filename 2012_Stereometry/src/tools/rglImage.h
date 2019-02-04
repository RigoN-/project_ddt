#ifndef _IMAGE_LIB_H
#define _IMAGE_LIB_H
#include <stdio.h>
#include <stdlib.h>  
#include <string.h>
#include <GL/gl.h>
#define TGA_RGB		 2
#define TGA_A		 3
#define TGA_RLE		10

struct RGL_TextureImage {
    GLint width;
    GLint height;
    GLint imgChanal;
    unsigned char *data;
} ;
typedef struct RGL_TextureImage RGL_TextureImage;

GLint rglLoadBMP(char *filename, RGL_TextureImage *image);
//GLint rglLoadTGA(char *filename, RGL_TextureImage *image);


#endif


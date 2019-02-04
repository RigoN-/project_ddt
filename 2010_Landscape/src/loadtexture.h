#ifndef _IMAGE_H
#define _IMAGE_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<setjmp.h>
#include<GL/gl.h>

struct textureImage {
    int width;
    int height;
    int imgChanal;
    unsigned char *data;
};

typedef struct textureImage textureImage;
extern int LoadBMPTexture(char *filename, textureImage *image);
extern int LoadBMPHeightMap(char *filename, textureImage *image);
#endif

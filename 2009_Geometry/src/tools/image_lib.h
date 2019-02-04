#ifndef _IMAGE_LIB_H
#define _IMAGE_LIB_H
#include <stdio.h>
#include <stdlib.h>  
#include <string.h>
//#include <jpeglib.h> 
//#include <setjmp.h>
#define TGA_RGB		 2
#define TGA_A		 3
#define TGA_RLE		10

struct textureImage {
    int width;
    int height;
    int imgChanal;
    unsigned char *data;
} ;
typedef struct textureImage textureImage;

int LoadBMP(char *filename, textureImage *image);
int LoadTGA(char *filename, textureImage *image);
//int LoadJPG(char *filename, textureImage *image);

#endif

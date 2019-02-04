#ifndef _IMAGE_LIB_H
#define _IMAGE_LIB_H
#include <stdio.h>
#include <stdlib.h>  
#include <string.h>
#include <jpeglib.h> 
#include <setjmp.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
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
GLint rglLoadTGA(char *filename, RGL_TextureImage *image);
GLint rglLoadJPG(char *filename, RGL_TextureImage *image);
//  LoadImageSDL - TGA, BMP, PNM( Portable Anymap (.pnm)), XPM(X11 Pixmap (.xpm)), XCF(GIMP native (.xcf)), GIF, PCX, 
GLint rglLoadImageSDL(char *filename, RGL_TextureImage *image);

#endif


#ifndef _RGLTEXT_H
#define _RGLTEXT_H
#include <stdio.h>
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glext.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

extern TTF_Font *TTFBuildFont(char *filename, GLint size, GLint style);
extern  void SDL_string_texture_create(TTF_Font  *font, char *text, GLuint solid,  GLuint *texture);
extern  void SDL_string_texture_update(TTF_Font  *font, char *text, GLuint solid,  GLuint *texture);
extern  void SDL_string_render2D( GLuint x, GLuint y, GLuint *texture );



#endif

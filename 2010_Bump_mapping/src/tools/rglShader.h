#ifndef _RGLSHADER_H
#define _RGLSHADER_H

#include <stdio.h>
#include <stdlib.h>


extern char *rglFileToString(const char *path);
extern void rglPrintShaderInfoLog(const char *coment, GLuint *obj);
extern void rglPrintProgramInfoLog(const char *coment,GLuint *obj);
extern GLuint rglInitVertexShader(const char *ShaderFile);
extern GLuint rglInitFragmentShader(const char *ShaderFile);
extern GLuint rglInitProgramShader(GLuint *vert,GLuint *geom, GLuint *frag);
extern GLboolean rglPutUniformf(GLuint *prog,const char *Name, GLfloat *arg);
extern GLboolean rglPutUniformi(GLuint *prog,const char *Name, GLint *arg);
extern GLboolean rglPutUniformMatrix(GLuint *prog,const char *Name, GLfloat arg[]);
#endif


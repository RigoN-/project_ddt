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
extern GLboolean rglPushUniformf(GLuint *prog,const char *Name, GLfloat *arg);
extern GLboolean rglPushUniformi(GLuint *prog,const char *Name, GLint *arg);
extern GLboolean rglPushUniformMatrix(GLuint *prog,const char *Name, GLfloat arg[]);
extern void rglPushTexture(GLuint texture, GLuint shader, GLuint texture_module, const char *sampler_name);
#endif



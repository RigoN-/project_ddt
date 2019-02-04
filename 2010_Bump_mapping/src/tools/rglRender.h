#ifndef _RENDER_H
#define _RENDER_H
#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glext.h>
#include "rglMesh3D.h"
#include "rglMath3D.h"
#include "rglMaterial.h"

//rglProjectionType
#define RGL_PROJECTION_ORTHO   101
#define RGL_PROJECTION_PERSPECTIVE    102
#define ANGLE_PERSPECTIVE 60
#define rglProjectionType RGL_PROJECTION_PERSPECTIVE; 

// rglRenderMode
#define RGL_FFP_RENDER   1011
#define RGL_SHADER_RENDER   1012

// rglRenderType
#define RGL_OPENGL12   1021
#define RGL_OPENGL14   1022
//-------------------------------------------------
#define RGL_OPENGL15   1023
//-------------------------------------------------
#define RGL_OPENGL20   1024
#define RGL_OPENGL21   1025
//-------------------------------------------------
#define RGL_OPENGL30   1026
#define RGL_OPENGL31   1027
#define RGL_OPENGL32   1028

// rglDrawMode
#define RGL_VERT_COLOR   1001
#define RGL_VERT_COLOR_NORM   1002
#define RGL_VERT_COLOR_NORM_TEX   1003
// rglDrawMode end

struct rglRenderObject {
   rglMesh *mesh;
   GLuint vbo; 
   GLuint ibo; 
   GLuint dl;
  // GLuint*vao; 
  // rglMaterial material;
   rglMat4 mvm;
   rglMat4 pvm;  
  } ;
typedef struct  rglRenderObject rglRenderObject;



GLvoid rglSetProjection( GLint width, GLint height, GLint projection, rglMat4 pvm);
GLvoid rglSetProjectionFFP( GLint width, GLint height, GLint projection );
GLvoid rglReshape(GLint width, GLint height, GLint projection,rglMat4 pvm);
GLvoid rglReshapeFFP(GLint width, GLint height, GLint projection);

extern GLuint rglInitDL(rglVertex *data,  GLenum face_type, GLuint count, GLuint rglDrawMode);
extern rglRenderObject *rglInitRenderObjectVA( rglMesh *mesh);
extern GLuint rglInitVBO(rglVertex *data, GLuint count);
extern GLuint rglInitIBO(GLuint *data,GLuint count);
extern GLuint rglBufferInfo(GLuint buffer,GLenum target, GLchar *str);
extern GLuint *rglInitVAO();

extern rglRenderObject *rglInitRenderObjectDL( rglMesh *mesh, GLuint rglDrawMode);
extern rglRenderObject *rglInitRenderObjectVBO( rglMesh *mesh);
extern rglRenderObject *rglInitRenderObjectIBO( rglMesh *mesh);
extern rglRenderObject *rglInitRenderObjectVAO( rglMesh *mesh, GLuint *vboID, GLuint *iboID, GLuint *vaoID);
extern rglRenderObject *rglInitRenderObjectALL( rglMesh *mesh, GLuint rglDrawMode);
extern void rglFreeRenderObject( rglRenderObject *obj);

extern  void rglDrawObjectIMM(rglRenderObject *object, GLuint rglDrawMode);
extern void rglDrawObjectDL(rglRenderObject *object);
extern void rglDrawObjectVA(rglRenderObject *object, GLuint rglDrawMode);
extern void rglDrawObjectVAE(rglRenderObject *object, GLuint rglDrawMode);
extern void rglDrawObjectVBO(rglRenderObject *object, GLuint rglDrawMode);
extern void rglDrawObjectIBO(rglRenderObject *object, GLuint rglDrawMode);
extern void rglDrawObjectVAO(rglRenderObject *object);

/*
 * mesh - structure rglMesh
 * rglDrawMode - mode draw (vertex_color) or (vertex_color_normal)  or (vertex_color_normal_texcoord)
 */


#endif

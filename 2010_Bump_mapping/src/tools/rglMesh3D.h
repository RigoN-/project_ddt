#ifndef _MESH3D_H
#define _MESH3D_H
//#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glext.h>
#include <GL/glu.h>
#include "rglMath3D.h"
#include "rglMaterial.h"

struct rglVertex {
    rglVec4 position;
	rglCol4 color;
    rglVec3 normal;
    rglTex2 texcoord;    
	rglVec3 padding;
} ;
typedef struct  rglVertex  rglVertex;

struct rglMesh {
   rglVertex *vertices;
   GLuint *indices;
// count vertex of mesh
   GLuint count;
//   GL_POINTS, GL_LINE_STRIP, GL_LINE_LOOP, GL_LINES, GL_TRIANGLE_STRIP, GL_TRIANGLE_FAN, GL_TRIANGLES, GL_QUAD_STRIP, GL_QUADS и GL_POLYGON
   GLenum face_type;
   } ;
typedef struct  rglMesh rglMesh;


extern void rglTorus_draw(GLint solid, GLint cual, GLint size);
//extern void rglTorus_draw_glut(GLint solid, GLint cual, GLint size);
//extern void rglTeapot_draw_glut(GLint solid,GLint size);
extern void rglSphere_draw(GLint solid, GLint cual,GLint size);
//extern void rglSphere_draw_glut(GLint solid, GLint cual, GLint size);
//extern void rglSphere_draw_glu(GLUquadricObj *quadObj,GLint solid, GLint cual, GLint size);
extern void rglCube_draw(GLint solid,GLint size);
//extern void rglCube_draw_glut(GLint solid,GLint size);
//extern void rglCone_draw_glut(GLint solid,GLint cual,GLint size);
extern void rglCilinder_draw(GLint solid,GLint cual,GLint size);
//extern void rglCilinder_draw_glu(GLUquadricObj *quadObj,GLint solid,GLint cual,GLint baserad, GLint toprad, GLint height);
//extern void rglDisk_draw_glu(GLUquadricObj *quadObj,GLint solid, GLint cual,GLint size);
//extern void rglPartialDisk_draw_glu(GLUquadricObj *quadObj,GLint solid,GLint cual,GLint size, GLint sangle, GLint eangle);
//extern GLUquadricObj *rglNew_Quadric_glu(GLint normal, GLint texture, GLint orient);


extern rglVertex *rglCubeVertexArrayCreate(GLint size);
extern GLuint *rglCubeIndexArrayCreate();
extern rglMesh *rglInitCubeMesh(GLint size);
rglMesh *rglInitCloneCubeMesh(GLint size, GLuint count_clone);
extern void rglFreeMesh(rglMesh *mesh);
#endif

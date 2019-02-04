#ifndef _MESH3D_H
#define _MESH3D_H
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




//пружина 
extern void rglSpring_Draw(GLfloat R, GLfloat r, GLint n, GLint m, GLfloat theta_x, GLfloat phi_x, GLfloat h, GLfloat CYCLES);
//Грузик
extern void rglDinamometr_Draw(rglMat4 mvm,GLfloat h,GLuint shkala,GLuint wplastic,GLuint stal, GLuint shader);
extern void rglGruzik_Draw(rglMat4 mvm, GLfloat n, GLfloat m, GLfloat h, GLfloat R, GLfloat angle, GLuint stal, GLuint shader);
//Крючок
extern void rglHook_Draw(rglMat4 mvm, GLfloat R, GLfloat r, GLint n, GLint m, GLfloat phi_x, GLuint tex, GLuint shader);
////Крючок_2
extern void rglHook_2_Draw(rglMat4 mvm,GLfloat R, GLfloat r, GLint n, GLint m, GLfloat phi_x, GLuint stal, GLuint shader );
////кубик
extern void rglCube_Draw(rglMat4 mvm,GLfloat size_x, GLfloat size_y, GLfloat size_z,GLuint face_tex,GLuint back_tex,GLuint up_tex, GLuint down_tex, GLuint right_tex, GLuint left_tex, GLuint shader);
//коретка
extern void rglKoretka_Draw(rglMat4 mvm, GLuint tex, GLuint tex_05, GLuint shader);
//Рычаг
extern void rglRule_Draw(rglMat4 mvm, GLuint bplastic, GLuint gplastic, GLuint stal, GLuint shader);
//Направление
extern void rglNapravlenie_Draw(rglMat4 mvm,GLuint shkala2, GLuint tex_05,GLuint tex_02, GLuint shader);
//Штативы
extern void rglShtativ_Draw(rglMat4 mvm, GLuint yplastic,GLuint stal, GLuint bplastic, GLuint shader);
extern void rglShtativ_Draw_2(rglMat4 mvm, GLuint yplastic,GLuint stal, GLuint bplastic, GLuint shader);
extern void rglShtativ_Draw_3(rglMat4 mvm, GLuint yplastic,GLuint stal, GLuint bplastic, GLuint shader);
//Маленькая пружина
extern void rglSpring_Draw_2 (GLfloat R, GLfloat r, GLint n, GLint m, GLfloat theta_x, GLfloat phi_x, GLfloat h, GLfloat CYCLES);
//Проццедура всей пружины динамометра
extern void DinoSpring(rglMat4 mvm,GLfloat h, GLuint tex_04, GLuint shader);
//Шарик
extern void rglSharik_Draw(GLfloat r, GLfloat n, GLfloat phi3, GLfloat theta3);
extern void rglPushMatrix(rglMat4 mvm_w, GLuint shader);
extern void rglPushMaterial(rglMaterial material, GLuint shader);
extern rglVertex *rglCubeVertexArrayCreate(GLint size);
extern GLuint *rglCubeIndexArrayCreate();
extern rglMesh *rglInitCubeMesh(GLint size);
rglMesh *rglInitCloneCubeMesh(GLint size, GLuint count_clone);
extern void rglFreeMesh(rglMesh *mesh);
#endif

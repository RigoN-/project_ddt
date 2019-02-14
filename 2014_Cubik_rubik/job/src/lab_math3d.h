#ifndef _LAB_MATH_3D_H
#define _LAB_MATH_3D_H
#include "lab_common.h"

//const----------------------------------------------------------------------------------------------------------------------------------
#define PI 3.14159265358979323846
#define M_PI 3.14159265358979323846
#define DEG2RAD (PI / 180.0)
#define RAD2DEG (180.0 / PI)
#define SIGN(x) (x < 0 ? (-1) : 1)
//type------------------------------------------------------------------------------------------------------------------------------------
struct rglVec3 {
    GLfloat x;
	GLfloat y;  
	GLfloat z;  
};

typedef struct  rglVec3  rglVec3;

typedef  GLfloat rglMat4 [16];
//typedef  GLfloat  rglMat3 [9];



//vector2------------------------------------------------------------------------------------------------------------------------------------------------

//vector3-----------------------------------------------------------------------------------------------------------------------------------------------
rglVec3 rglVector3Setf(GLfloat x, GLfloat y, GLfloat z);
rglVec3 rglVector3Add( rglVec3 v1, rglVec3 v2);
rglVec3 rglVector3Sub( rglVec3 v1, rglVec3 v2);
rglVec3 rglVector3Scale(rglVec3  v1, GLfloat scale );
GLfloat rglVector3Length(rglVec3 v);
GLint rglVector3Clear(rglVec3 *v);
GLint rglVector3Copy( rglVec3 *dest, rglVec3 src);
rglVec3 rglVector3Cross(rglVec3 v1, rglVec3 v2); 
rglVec3 rglVector3Normalize(rglVec3 v1);
GLint rglVector3Print(rglVec3 v, const char * header);

//vector4
 
//matrix2
  
//matrix3

//matrix4
extern GLint rglMatrix4Identity(rglMat4 dest);
extern GLint rglMatrix4Copy(rglMat4 dest, rglMat4 src);
extern GLint rglMatrix4Multiply(rglMat4 m1, rglMat4 m2);
rglVec3 rglMatrix4MulVector3(const rglMat4 m, rglVec3 v3);
extern GLint rglMatrix4Print(rglMat4 m,const char * header);


//opengl matrix
GLint rglFrustum(rglMat4 dest, GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat zNear, GLfloat zFar);
GLint rglPerspective(rglMat4 dest,GLfloat fov, GLfloat aspect, GLfloat znear, GLfloat zfar);
GLint rglOrtho(rglMat4 dest,GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat znear, GLfloat zfar);
GLint rglTranslate(rglMat4 dest,GLfloat x, GLfloat y, GLfloat z);
GLint rglScale(rglMat4 dest,GLfloat x, GLfloat y, GLfloat z);
GLint rglRotate(rglMat4 dest,GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
GLint rglLookAt(rglMat4 dest,rglVec3 v1, rglVec3 v2, rglVec3 v3);
GLint rglMatrix4MemPrint(GLuint matrix_type, const char * header);

#endif

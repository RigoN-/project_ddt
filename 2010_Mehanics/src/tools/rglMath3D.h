#ifndef _MATH_LIB_H
#define _MATH_LIB_H
#include <stdio.h>
#include <stdlib.h> 
#include <math.h> 
#include <string.h> 
#include <GL/gl.h>


#define PI 3.14159265358979323846
#define M_PI 3.14159265358979323846
#define DEG2RAD (PI / 180.0)
#define RAD2DEG (180.0 / PI)

struct rglVec2 {
	GLfloat x;
	GLfloat y;  
} ;
typedef struct  rglVec2  rglVec2;

struct rglTex2 {
    GLfloat s;
	GLfloat t;  
} ;
typedef struct  rglTex2  rglTex2;

struct rglVec3 {
    GLfloat x;
	GLfloat y;  
	GLfloat z;  
} ;
typedef struct  rglVec3  rglVec3;


struct rglTex3 {
    GLfloat s;
	GLfloat t;  
	GLfloat r;  
} ;
typedef struct  rglTex3  rglTex3;

struct rglCol3 {
    GLfloat r;
	GLfloat g;  
	GLfloat b;  
} ;
typedef struct  rglCol3  rglCol3;


struct rglVec4 {
    GLfloat x;
	GLfloat y;  
	GLfloat z; 
	GLfloat w;   
} ;
typedef struct  rglVec4  rglVec4;

struct rglCol4 {
    GLfloat r;
	GLfloat g;  
	GLfloat b; 
	GLfloat a;   
} ;
typedef struct  rglCol4  rglCol4;


typedef  GLfloat rglMat4 [16];
typedef  GLfloat  rglMat3 [9];


rglVec2 rglVector2Set(GLfloat x, GLfloat y);
rglTex2 rglTexCoord2Set(GLfloat s, GLfloat t);
rglVec3 rglVector3Set(GLfloat x, GLfloat y, GLfloat z);
rglCol3 rglColor3Set(GLfloat r, GLfloat g, GLfloat b);
rglTex3 rglTex3Set(GLfloat s, GLfloat t, GLfloat r);
rglVec4 rglVector4Set(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
rglCol4 rglColor4Set(GLfloat r, GLfloat g, GLfloat b, GLfloat a);

rglVec3 rglVec4ToVec3(rglVec4 v1);
rglCol3 rglColor4ToColor3(rglCol4 v1);
rglVec2 rglVec4ToVec2(rglVec4 v1);
rglVec2 rglVec3ToVec2(rglVec3 v1);
GLint rglVector2Clear(rglVec2 v);
 
 GLint rglVector3Clear(rglVec3 v);
 GLint rglVector4Clear(rglVec4 v);
 GLint rglVector2Copy( rglVec2 v1, rglVec2 v2);
 GLint rglVector3Copy( rglVec3 v1, rglVec3 v2);
 GLint rglVector4Copy( rglVec4 v1, rglVec4 v2);
 rglVec2 rglVector2Scale(rglVec2 v1, GLfloat scale );
 rglVec3 rglVector3Scale(rglVec3  v1, GLfloat scale );
 rglVec4 rglVector4Scale(rglVec4 v1, GLfloat scale );
 rglVec2 rglVector2Add( rglVec2 v1, rglVec2 v2);
 rglVec3 rglVector3Add( rglVec3 v1, rglVec3 v2);
 rglVec4 rglVector4Add( rglVec4 v1, rglVec4 v2);
 rglVec2 rglVector2Sub( rglVec2 v1, rglVec2 v2);
 rglVec3 rglVector3Sub( rglVec3 v1, rglVec3 v2);
 rglVec4 rglVector4Sub( rglVec4 v1, rglVec4 v2);
 GLfloat rglVector2Dot( rglVec2 v1, rglVec2 v2);
 GLfloat rglVector3Dot( rglVec3 v1, rglVec3 v2);
 GLfloat rglVector4Dot( rglVec4 v1, rglVec4 v2);
 rglVec3 rglVector3Cross(rglVec3 v1, rglVec3 v2);
 GLfloat rglVector2Length(rglVec2 v);
 GLfloat rglVector3Length(rglVec3 v);
 GLfloat rglVector4Length(rglVec4 v);
 rglVec2 rglVector2Normalize(rglVec2 v1);
 rglVec3 rglVector3Normalize(rglVec3 v1);
 rglVec4 rglVector4Normalize(rglVec4 v1);
 rglVec2 rglMatrix4MulVector2(const rglMat4 m, rglVec2 v3);
 rglVec3 rglMatrix4MulVector3(const rglMat4 m, rglVec3 v3);
 rglVec4 rglMatrix4MulVector4(const rglMat4 m, rglVec4 v3);
 rglVec2 rglMatrix3MulVector2(const rglMat3 m, rglVec2 v3);
 rglVec3 rglMatrix3MulVector3(const rglMat3 m, rglVec3 v3);
 GLint rglVector2Print(rglVec2 v);
 GLint rglVector3Print(rglVec3 v);
 GLint rglVector4Print(rglVec4 v);
 


GLint rglMatrix3Identity(rglMat4 mat);
GLint rglMatrix4Identity(rglMat4 mat);

GLint rglMatrix4Multiply(rglMat4 m1, rglMat4 m2);
GLfloat rglMatrix3Determinant(rglMat3 m);
GLint rglMatrix3Inverse(rglMat3 m1, rglMat3 m2);
GLint rglMatrix3Copy(rglMat3 m1, rglMat3 m2) ;
GLint rglMatrix3Transpose(rglMat3 m1, rglMat3 m2) ;
GLint rglMatrix4to3(rglMat3 m1, rglMat4 m2);
GLint rglMatrix4Copy(rglMat4 m1, rglMat4 m2) ;
GLint rglMatrix4Transpose(rglMat4 m1, rglMat4 m2);
GLint rglMatrix4Inverse(rglMat4 m1, rglMat4 m2);
GLint rglMatrix3Print(rglMat4 m);
GLint rglMatrix4Print(rglMat4 m);

GLint rglPerspective(rglMat4 mat, GLfloat fov, GLfloat aspect, GLfloat znear, GLfloat zfar);
GLint rglOrtho(rglMat4 mat, GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat znear, GLfloat zfar);
GLint rglTranslate(rglMat4 mat, GLfloat x, GLfloat y, GLfloat z);
GLint rglScale(rglMat4 mat,GLfloat x, GLfloat y, GLfloat z);
GLint rglRotate(rglMat4 mat, GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
GLint rglLookAt(rglMat4 mat, rglVec3 v1, rglVec3 v2, rglVec3 v3);
GLint rglMatrixNormal(rglMat4 m1, rglMat3 m2);



//old function
GLint rotate(rglMat4 mat,GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
/*
rglMat4 *perspective(GLfloat angle, GLfloat ratio, GLfloat near, GLfloat fear);
rglMat4 *ortho(GLfloat left, GLfloat right, GLfloat butom, GLfloat ratio, GLfloat near, GLfloat fear);
*/

#endif

#ifndef MATERIAL_H
#define MATERIAL_H
//0 Черная пластмасса
#define BLACK_PLASTIC 0
//1 Латунь
#define BRASS 1
//2 Бронза
#define BRONZE 2
//3 Хром
#define CHROME 3
//4 Медь
#define COOPER 4
//5 Золото
#define GOLD 5
//6 Олово
#define PEWTER 6
//7 Серебро
#define SILVER 7
//8 Полированное Cеребро
#define POLISH_SILVER 8
//9 изумруд
#define EMERALD 9
//10 нефрит
#define JADE 10
//11 обсиден
#define OBSIDIAN 11
//12 жемчуг
#define PEARLE 12
//13 рубин
#define RUBY 13
//14 бирюза Turquoise
#define  TUEQUOISE 14
//15 черный каучук
#define BLACK_RUBBER 15
//16 Полированная бронза
#define POLISH_BRONZE 16
//17 Полированное медь
#define POLISH_COOPER 17
//18 Полированное золото
#define POLISH_GOLD 18
//19 Черный пластик
#define BLACK_PLASTIC2 19
//20 Голубой Пластик
#define CAYN_PLASTIC2 20
//21 Зеленый Пластик
#define GREEN_PLASTIC2 21
//22 Красный Пластик
#define RED_PLASTIC2 22
//23 Белый Пластик
#define WHITE_PLASTIC2 23
//24 Желтый Пластик
#define YELLOW_PLASTIC2 24
//25 Голубая резина
#define BLUE_RUBBER 25
//26 Зеленая резина
#define GREEN_RUBBER 26
//27Красная резина
#define RED_RUBBER 27
//28 Белая резина
#define WHITE_RUBBER 28
//29 Желтая резина
#define YELLOW_RUBBER 29
#include <GL/gl.h>
#include <GL/glu.h>
#include "rglMath3D.h"
/*
GLfloat  light_pos[];
GLfloat light_Ka[];
GLfloat light_Kd[];
GLfloat light_Ks[];

GLfloat material_Ka[31][4] ;
GLfloat material_Kd[30][4] ;
GLfloat material_Ks[30][4];
GLfloat material_Ke[4] ;
GLfloat material_Se[30] ;
*/
struct rglLight {
	rglVec4 Lposition;
    rglVec4 Lambient;
   rglVec4 Ldiffuse;
   rglVec4 Lspecular;
   /*
rglVec4 spotDirection;
GLfloat spotExponent;
GLfloat spotCutoff;
GLfloat spotCosCutoff;
GLfloat constantAttenuation;
GLfloat linearAttenuation;
GLfloat quadraticAttenuation;

   */
   
   
} ;
typedef struct rglLight rglLight;

struct rglMaterial {	
    rglVec4 Mambient;
    rglVec4 Mdiffuse;
    rglVec4 Mspecular;
	rglVec4 Memission;
    GLfloat Mshininess;
	GLuint *Mtexture;
} ;
typedef struct rglMaterial rglMaterial;

extern GLvoid rglInitLight();
extern GLvoid rglInitLight_2(rglLight *L);
extern GLvoid rglSetMaterial(GLint material);
extern GLvoid  rglSetMaterial_2(GLint material, rglMaterial *M);
extern GLvoid  rglSetBlendMode(GLint blend);


#endif


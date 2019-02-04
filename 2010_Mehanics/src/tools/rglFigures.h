#ifndef _FIGURES_H
#define _FIGURES_H
#include <GL/gl.h>
#include <GL/glext.h>
#include <GL/glu.h>
#include "rglMath3D.h"
#include "rglMesh3D.h"
#include "rglMaterial.h"





//Процедура Диск(число m, угол альфа, Радиус внешней окружности , радиус внутреней окружность);	
extern void rglDisk_Draw(GLfloat m, GLfloat a_x, GLfloat r2, GLfloat r1);
// Процедура Трубка ( число n, число m, высота трубки, радиус трубки, угол)
extern void rglTube_Draw(GLfloat n, GLfloat m, GLfloat h, GLfloat R, GLfloat angle);
//Процедура Шара ( Радиус, число n, Угол вертикальной плоскости, угол горизонтальной плоскости)
extern void rglSphere_Draw(GLfloat r, GLfloat n, GLfloat phi3, GLfloat theta3);
//процедура Торус(R-большой радиус,r-маленький радиус, число n, число m, theta-угол тета , phi-угол фи)	
extern void rglTorus_Draw(GLfloat R, GLfloat r, GLint n, GLint m, GLfloat theta_x, GLfloat phi_x );
//процедура Цилиндр( число "Эн", число "Эм", Высота цилиндра, Радиус Цилиндра, угол)
extern void rglCylinder_Draw(rglMat4 mvm, GLfloat n, GLfloat m, GLfloat h, GLfloat R, GLfloat angle,GLuint tex, GLuint shader);
//Процедура Хеликс(Спираль) (Большой радиус, число n , число m, угол горизонтальной плоскости, угол вертикальной плоскости, Длина спирали, количество повторов)
extern void rglSpiral_Draw(GLfloat R, GLfloat r, GLint n, GLint m, GLfloat theta_x, GLfloat phi_x, GLfloat h, GLfloat CYCLES);
//пружина 

extern void rglPushMatrix(rglMat4 mvm_w, GLuint shader);



#endif

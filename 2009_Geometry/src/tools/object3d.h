#ifndef _OBJECT3D_H
#define _OBJECT3D_H
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

extern void Torus_draw(GLint solid, GLint cual, GLint size);
extern void Torus_draw_glut(GLint solid, GLint cual, GLint size);
extern void Teapot_draw_glut(GLint solid,GLint size);
extern void Sphere_draw(GLint solid, GLint cual,GLint size);
extern void Sphere_draw_glut(GLint solid, GLint cual, GLint size);
extern void Sphere_draw_glu(GLUquadricObj *quadObj,GLint solid, GLint cual, GLint size);
extern void Cube_draw(GLint solid,GLint size);
extern void Cube_draw_glut(GLint solid,GLint size);
extern void Cone_draw_glut(GLint solid,GLint cual,GLint size);
extern void Cilinder_draw(GLint solid,GLint cual,GLint size);
extern void Cilinder_draw_glu(GLUquadricObj *quadObj,GLint solid,GLint cual,GLint baserad, GLint toprad, GLint height);
extern void Disk_draw_glu(GLUquadricObj *quadObj,GLint solid, GLint cual,GLint inradius, GLint outradius);
extern void PartialDisk_draw_glu(GLUquadricObj *quadObj,GLint solid,GLint cual,GLint size, GLint sangle, GLint eangle);
extern GLUquadricObj *New_Quadric_glu(GLint normal, GLint texture, GLint orient);

#endif

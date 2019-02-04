#include <stdio.h>
#include <stdlib.h>
#include "object3d.h"


void Torus_draw(GLint solid, GLint cual, GLint size)
{

}

void Torus_draw_glut(GLint solid, GLint cual, GLint size)
{
	GLint slices;
	GLint loops;
	GLint inradius;
	GLint outradius;
	inradius=1*size;
	outradius=3*size;
		if (cual < 8)
	{
		slices=25*cual;
		loops=25*cual;
	}
	else
	{
		slices=25*8;
		loops=25*8;
	}
	switch(solid)
	{
		case 0: glutWireTorus(inradius,outradius,slices,loops);	break;
		case 1: glutSolidTorus(inradius,outradius,slices,loops);  break;
		default:
			glutSolidTorus(inradius,outradius,slices,loops); 
		break;
	}
}

void Teapot_draw_glut(GLint solid,GLint size)
{
	switch(solid)
	{
		case 0: glutWireTeapot(size);	break;
		case 1: glutSolidTeapot(size); 	break;
		default:
			glutSolidTeapot(size); 
		break;
	}
}

void Sphere_draw(GLint solid, GLint cual,GLint size)
{
}

void Sphere_draw_glut(GLint solid, GLint cual, GLint size)
{
	GLint slices;
	GLint loops;	
	if (cual < 8)
	{
		slices=25*cual;
		loops=25*cual;
	}
	else
	{
		slices=25*8;
		loops=25*8;
	}
	switch(solid)
	{
		case 0: glutWireSphere(size, slices,loops);	break;
		case 1: glutSolidSphere(size, slices,loops);	break;
		default:
			glutSolidSphere(size, slices,loops); 
		break;
	}
}

void Sphere_draw_glu(GLUquadricObj *quadObj,GLint solid, GLint cual, GLint size)
{
	GLint slices;
	GLint loops;	
	if (cual < 8)
	{
		slices=25*cual;
		loops=25*cual;
	}
	else
	{
		slices=25*8;
		loops=25*8;
	}
	switch(solid)
	{
		case 0: gluQuadricDrawStyle(quadObj,GLU_POINT);		break;
		case 1: gluQuadricDrawStyle(quadObj,GLU_LINE);	break;
		case 2: gluQuadricDrawStyle(quadObj,GLU_SILHOUETTE);	break;
		case 3: gluQuadricDrawStyle(quadObj,GLU_FILL);	break;
		default:
			gluQuadricDrawStyle(quadObj,GLU_FILL);
		break;
	}
	gluSphere(quadObj, size,slices,loops);
}

void Cube_draw(GLint solid, GLint size)
{
	GLint mode ;
	//glGetIntegerv(GL_POLYGON_MODE, &mode);
	switch(solid)
	{
		case 0: glPolygonMode(GL_FRONT_AND_BACK,GL_POINT);		break;
		case 1: glPolygonMode(GL_FRONT_AND_BACK,GL_LINE); 	break;
		case 2: glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);	break;
		default:
			glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
		break;
	}
	glBegin(GL_QUADS);
		// Front Face
		glNormal3f( 0.0, 0.0, 1.0);glTexCoord2f(0.0, 0.0); glVertex3f(-1.0*size, -1.0*size,  1.0*size);
		glNormal3f( 0.0, 0.0, 1.0);glTexCoord2f(1.0, 0.0); glVertex3f( 1.0*size, -1.0*size,  1.0*size);
		glNormal3f( 0.0, 0.0, 1.0);glTexCoord2f(1.0, 1.0); glVertex3f( 1.0*size,  1.0*size,  1.0*size);
		glNormal3f( 0.0, 0.0, 1.0);glTexCoord2f(0.0, 1.0); glVertex3f(-1.0*size,  1.0*size,  1.0*size);
		// Back Face
		glNormal3f( 0.0, 0.0, -1.0);glTexCoord2f(1.0, 0.0); glVertex3f(-1.0*size, -1.0*size, -1.0*size);
		glNormal3f( 0.0, 0.0, -1.0);glTexCoord2f(1.0, 1.0); glVertex3f(-1.0*size,  1.0*size, -1.0*size);
		glNormal3f( 0.0, 0.0, -1.0);glTexCoord2f(0.0, 1.0); glVertex3f( 1.0*size,  1.0*size, -1.0*size);
		glNormal3f( 0.0, 0.0, -1.0);glTexCoord2f(0.0, 0.0); glVertex3f( 1.0*size, -1.0*size, -1.0*size);
		// Top Face
		glNormal3f( 0.0, 1.0, 0.0);glTexCoord2f(0.0, 1.0); glVertex3f(-1.0*size,  1.0*size, -1.0*size);
		glNormal3f( 0.0, 1.0, 0.0);glTexCoord2f(0.0, 0.0); glVertex3f(-1.0*size,  1.0*size,  1.0*size);
		glNormal3f( 0.0, 1.0, 0.0);glTexCoord2f(1.0, 0.0); glVertex3f( 1.0*size,  1.0*size,  1.0*size);
		glNormal3f( 0.0, 1.0, 0.0);glTexCoord2f(1.0, 1.0); glVertex3f( 1.0*size,  1.0*size, -1.0*size);
		// Bottom Face
		glNormal3f( 0.0, -1.0, 0.0);glTexCoord2f(1.0, 1.0); glVertex3f(-1.0*size, -1.0*size, -1.0*size);
		glNormal3f( 0.0, -1.0, 0.0);glTexCoord2f(0.0, 1.0); glVertex3f( 1.0*size, -1.0*size, -1.0*size);
		glNormal3f( 0.0, -1.0, 0.0);glTexCoord2f(0.0, 0.0); glVertex3f( 1.0*size, -1.0*size,  1.0*size);
		glNormal3f( 0.0, -1.0, 0.0);glTexCoord2f(1.0, 0.0); glVertex3f(-1.0*size, -1.0*size,  1.0*size);
		// Right face
		glNormal3f(1.0, 0.0, 0.0);glTexCoord2f(1.0, 0.0); glVertex3f( 1.0*size, -1.0*size, -1.0*size);
		glNormal3f(1.0, 0.0, 0.0);glTexCoord2f(1.0, 1.0); glVertex3f( 1.0*size,  1.0*size, -1.0*size);
		glNormal3f(1.0, 0.0, 0.0);glTexCoord2f(0.0, 1.0); glVertex3f( 1.0*size,  1.0*size,  1.0*size);
		glNormal3f(1.0, 0.0, 0.0);glTexCoord2f(0.0, 0.0); glVertex3f( 1.0*size, -1.0*size,  1.0*size);
		// Left Face
		glNormal3f( -1.0, 0.0, 0.0);glTexCoord2f(0.0, 0.0); glVertex3f(-1.0*size, -1.0*size, -1.0*size);
		glNormal3f( -1.0, 0.0, 0.0);glTexCoord2f(1.0, 0.0); glVertex3f(-1.0*size, -1.0*size,  1.0*size);
		glNormal3f( -1.0, 0.0, 0.0);glTexCoord2f(1.0, 1.0); glVertex3f(-1.0*size,  1.0*size,  1.0*size);
		glNormal3f( -1.0, 0.0, 0.0);glTexCoord2f(0.0, 1.0); glVertex3f(-1.0*size,  1.0*size, -1.0*size);
	glEnd();
	
	//glPolygonMode(GL_FRONT_AND_BACK, mode);
}

void Cube_draw_glut(GLint solid, GLint size)
{
	switch(solid)
	{
		case 0: glutWireCube(size);	break;
		case 1: glutSolidCube(size); 	break;
		default:
			glutSolidCube(size);
		break;
	}
}

void Cone_draw_glut(GLint solid, GLint cual, GLint size) 
{
	GLint slices;
	GLint loops;
	GLint base;
	GLint height;
	base=size;
	height=2*size;
		if (cual < 8)
	{
		slices=25*cual;
		loops=25*cual;
	}
	else
	{
		slices=25*8;
		loops=25*8;
	}
	switch(solid)
	{
		case 0: glutSolidCone(base,height,slices,loops);	break;
		case 1: glutWireCone(base,height,slices,loops);  break;
		default:
			glutSolidCone(base,height,slices,loops);
		break;
	}
}

void Cilinder_draw(GLint solid,GLint cual,GLint size)
{
}

void Cilinder_draw_glu(GLUquadricObj *quadObj,GLint solid,GLint cual,GLint baserad, GLint toprad, GLint height)
{
	GLint slices;
	GLint loops;
	
	if (cual < 8)
	{
		slices=25*cual;
		loops=25*cual;
	}
	else
	{
		slices=25*8;
		loops=25*8;
	}
	switch(solid)
	{
		case 0: gluQuadricDrawStyle(quadObj,GLU_POINT);		break;
		case 1: gluQuadricDrawStyle(quadObj,GLU_LINE);	break;
		case 2: gluQuadricDrawStyle(quadObj,GLU_SILHOUETTE);	break;
		case 3: gluQuadricDrawStyle(quadObj,GLU_FILL);	break;
		default:
			gluQuadricDrawStyle(quadObj,GLU_FILL);
		break;
	}
	gluCylinder(quadObj,baserad,toprad,height,slices,loops);
}

void Disk_draw_glu(GLUquadricObj *quadObj,GLint solid, GLint cual,GLint inradius, GLint outradius)
{
	GLint slices;
	GLint loops;


		if (cual < 8)
	{
		slices=25*cual;
		loops=25*cual;
	}
	else
	{
		slices=25*8;
		loops=25*8;
	}
	switch(solid)
	{
		case 0: gluQuadricDrawStyle(quadObj,GLU_POINT);		break;
		case 1: gluQuadricDrawStyle(quadObj,GLU_LINE);	break;
		case 2: gluQuadricDrawStyle(quadObj,GLU_SILHOUETTE);	break;
		case 3: gluQuadricDrawStyle(quadObj,GLU_FILL);	break;
		default:
			gluQuadricDrawStyle(quadObj,GLU_FILL);
		break;
	}
	gluDisk (quadObj, inradius, outradius,slices,loops);
}

void PartialDisk_draw_glu(GLUquadricObj *quadObj,GLint solid,GLint cual,GLint size, GLint sangle, GLint eangle)
{
	GLint slices;
	GLint loops;
	GLint inradius;
	GLint outradius;
	inradius=1*size;
	outradius=3*size;
		if (cual < 8)
	{
		slices=25*cual;
		loops=25*cual;
	}
	else
	{
		slices=25*8;
		loops=25*8;
	}
	switch(solid)
	{
		case 0: gluQuadricDrawStyle(quadObj,GLU_POINT);		break;
		case 1: gluQuadricDrawStyle(quadObj,GLU_LINE);	break;
		case 2: gluQuadricDrawStyle(quadObj,GLU_SILHOUETTE);	break;
		case 3: gluQuadricDrawStyle(quadObj,GLU_FILL);	break;
		default:
			gluQuadricDrawStyle(quadObj,GLU_FILL);
		break;
	}
	gluPartialDisk (quadObj, inradius, outradius,slices,loops, sangle,eangle);
}

GLUquadricObj *New_Quadric_glu(GLint normal, GLint texture, GLint orient)
{
	GLUquadricObj *New_Quadric;
	New_Quadric = gluNewQuadric();
	switch(normal)
	{
		case 0: gluQuadricNormals(New_Quadric, GLU_NONE);	break;
		case 1: gluQuadricNormals(New_Quadric, GLU_FLAT);	break;
		case 2: gluQuadricNormals(New_Quadric, GLU_SMOOTH);	break;
		default:
			gluQuadricNormals(New_Quadric, GLU_SMOOTH);
		break;
	}
	
		switch(texture)
	{
		case 0: gluQuadricDrawStyle(New_Quadric,GLU_FALSE);	break;
		case 1: gluQuadricDrawStyle(New_Quadric,GLU_TRUE);	break;
		default:
			gluQuadricDrawStyle(New_Quadric,GLU_TRUE);
		break;
	}
	
		switch(orient)
	{
		case 0: gluQuadricDrawStyle(New_Quadric,GLU_INSIDE);	break;
		case 1: gluQuadricDrawStyle(New_Quadric,GLU_OUTSIDE);	break;
		default:
			gluQuadricDrawStyle(New_Quadric,GLU_OUTSIDE);
		break;
	}
	return New_Quadric;
	free(New_Quadric);
}

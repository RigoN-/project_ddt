#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "rglMesh3D.h"


void rglTorus_draw(GLint solid, GLint cual, GLint size)
{
switch(solid)
	{
		case 0: glPolygonMode(GL_FRONT_AND_BACK,GL_POINT);		break;
		case 1: glPolygonMode(GL_FRONT_AND_BACK,GL_LINE); 	break;
		case 2: glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);	break;
		default:
			glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
		break;
	}

}
/*
void rglTorus_draw_glut(GLint solid, GLint cual, GLint size)
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

void rglTeapot_draw_glut(GLint solid,GLint size)
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
*/
void rglSphere_draw(GLint solid, GLint cual,GLint size)
{
}
/*
void rglSphere_draw_glut(GLint solid, GLint cual, GLint size)
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

void rglSphere_draw_glu(GLUquadricObj *quadObj,GLint solid, GLint cual, GLint size)
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
*/
void rglCube_draw(GLint solid, GLint size)
{
	GLint mode ;
	glGetIntegerv(GL_POLYGON_MODE, &mode);
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
	
	glPolygonMode(GL_FRONT_AND_BACK, mode);
}
/*
void rglCube_draw_glut(GLint solid, GLint size)
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

void rglCone_draw_glut(GLint solid, GLint cual, GLint size) 
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
*/
void rglCilinder_draw(GLint solid,GLint cual,GLint size)
{
}
/*
void rglCilinder_draw_glu(GLUquadricObj *quadObj,GLint solid,GLint cual,GLint baserad, GLint toprad, GLint height)
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

void rglDisk_draw_glu(GLUquadricObj *quadObj,GLint solid, GLint cual,GLint size)
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
	gluDisk (quadObj, inradius, outradius,slices,loops);
}

void rglPartialDisk_draw_glu(GLUquadricObj *quadObj,GLint solid,GLint cual,GLint size, GLint sangle, GLint eangle)
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

GLUquadricObj *rglNew_Quadric_glu(GLint normal, GLint texture, GLint orient)
{
	GLUquadricObj *New_Quadric;
	New_Quadric = gluNewQuadric();
	switch(normal)
	{
		case 0: gluQuadricNormals(New_Quadric, GLU_NONE);	break;
		case 1: gluQuadricNormals(New_Quadric, GLU_FLAT);	break;
		case 3: gluQuadricNormals(New_Quadric, GLU_SMOOTH);	break;
		default:
			gluQuadricNormals(New_Quadric, GLU_SMOOTH);
		break;
	}
	
		switch(texture)
	{
		case 0:  gluQuadricTexture(New_Quadric,GLU_FALSE);	break;
		case 1:  gluQuadricTexture(New_Quadric,GLU_TRUE);	break;
		default:
			     gluQuadricTexture(New_Quadric,GLU_TRUE);
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
*/
rglVertex *rglCubeVertexArrayCreate(GLint size)
{
	GLfloat	vertices_1[]=
			{
				// Front Face
				-1.0*size, -1.0*size, 1.0*size,//0
				1.0*size, -1.0*size,  1.0*size,//1
				1.0*size,  1.0*size,  1.0*size,//2
				-1.0*size,  1.0*size,  1.0*size,//3
				// Back Face
				1.0*size,  -1.0*size, -1.0*size,//4
				-1.0*size,  -1.0*size, -1.0*size,//5
				-1.0*size,  1.0*size, -1.0*size,//6
				1.0*size, 1.0*size, -1.0*size,//7
				// Top Face
				-1.0*size,  1.0*size, 1.0*size,//8-5
				1.0*size,  1.0*size,  1.0*size,//9-3
				1.0*size,  1.0*size,  -1.0*size, //10
				-1.0*size,  1.0*size, -1.0*size, //11
				// Bottom Face
				-1.0*size, -1.0*size, -1.0*size,//12
				1.0*size, -1.0*size, -1.0*size, //13
				1.0*size, -1.0*size,  1.0*size, //14
				-1.0*size, -1.0*size,  1.0*size, //15
				// Right face
				1.0*size, -1.0*size, 1.0*size,//16
				1.0*size,  -1.0*size, -1.0*size,//17
				1.0*size,  1.0*size,  -1.0*size,//18
				1.0*size,  1.0*size,  1.0*size,//19
				// Left Face
				-1.0*size, -1.0*size, -1.0*size,//20
				-1.0*size, -1.0*size,  1.0*size,//21
				-1.0*size,  1.0*size,  1.0*size,//22
				-1.0*size,  1.0*size, -1.0*size//23
			};
/*			GLuint	indices_1[]=
		{
			0,1,2,3,
			4,5,6,7,
			8,9,10,11,
			12,13,14,15,
			16,17,18,19,
			20,21,22,23
         };*/
		GLfloat colors_1[]=
         {
         	
         	        1.0,1.0,1.0,  1.0,1.0,0.0,  1.0,0.0,0.0,  1.0,0.0,1.0,              // v0-v1-v2-v3         	        
                    1.0,1.0,1.0,  1.0,0.0,1.0,  0.0,0.0,1.0,  0.0,1.0,1.0,              // v0-v3-v4-v5                    
                    1.0,1.0,1.0,  0.0,1.0,1.0,  0.0,1.0,0.0,  1.0,1.0,0.0,              // v0-v5-v6-v1                    
                    1.0,1.0,0.0,  0.0,1.0,0.0,  0.0,0.0,0.0,  1.0,0.0,0.0,              // v1-v6-v7-v2                    
                    0.0,0.0,0.0,  0.0,0.0,1.0,  1.0,0.0,1.0,  1.0,0.0,0.0,              // v7-v4-v3-v2                    
                    0.0,0.0,1.0,  0.0,0.0,0.0,  0.0,1.0,0.0,  0.0,1.0,1.0				// v4-v7-v6-v5
		};
		GLfloat   normals_1[]=
         {
         // Front Face
         0.0, 0.0, 1.0,	 0.0, 0.0, 1.0,	 0.0, 0.0, 1.0,		 0.0, 0.0, 1.0,
		// Back Face
		 0.0, 0.0, -1.0,	 0.0, 0.0, -1.0,	 0.0, 0.0, -1.0,	 0.0, 0.0, -1.0,
		// Top Face
		 0.0, 1.0, 0.0,	 0.0, 1.0, 0.0,	 0.0, 1.0, 0.0,	 0.0, 1.0, 0.0,
		// Bottom Face
		 0.0, -1.0, 0.0,	 0.0, -1.0, 0.0,	 0.0, -1.0, 0.0,	 0.0, -1.0, 0.0,
		// Right face
		1.0, 0.0, 0.0,	1.0, 0.0, 0.0,	1.0, 0.0, 0.0,	1.0, 0.0, 0.0,
		// Left Face
		 -1.0, 0.0, 0.0,	 -1.0, 0.0, 0.0,	 -1.0, 0.0, 0.0,	 -1.0, 0.0, 0.0
		};
		GLfloat    texcoords_1[]=
         {
         		// Front Face
		0.0, 0.0, 	1.0, 0.0, 	1.0, 1.0, 	0.0, 1.0,
		// Back Face
		1.0, 0.0, 	1.0, 1.0, 	0.0, 1.0, 	0.0, 0.0, 
		// Top Face
		0.0, 1.0, 	0.0, 0.0, 	1.0, 0.0, 	1.0, 1.0, 
		// Bottom Face
		1.0, 1.0, 	0.0, 1.0, 	0.0, 0.0, 	1.0, 0.0, 
		// Right face
		1.0, 0.0, 	1.0, 1.0, 	0.0, 1.0, 	0.0, 0.0, 
		// Left Face
		0.0, 0.0, 	1.0, 0.0, 	1.0, 1.0, 	0.0, 1.0
		};
/*	vertices=(GLfloat *)malloc(24*3*sizeof(GLfloat));
	indices=(GLbyte *)malloc(24*sizeof(GLbyte));	
	colors=(GLfloat *)malloc(24*3*sizeof(GLfloat));
	normals=(GLfloat *)malloc(24*3*sizeof(GLfloat));
	texcoords=(GLfloat *)malloc(24*2*sizeof(GLfloat));
	
		memcpy(&vertices[0]], &vertices_1[0],sizeof(GLfloat)*72); 	
		memcpy(&indices[0]], &indices_1[0],sizeof(GLbyte)*24);
		memcpy(&colors[0]], &colors_1[0],sizeof(GLfloat)*72);
		memcpy(&normals[0]], &normals_1[0],sizeof(GLfloat)*72);
		memcpy(&texcoords[0]], &texcoords_1[0],sizeof(GLfloat)*48);
	*/
	rglVertex *vertexes=(rglVertex *)malloc(24*sizeof(rglVertex));	
	//printf("Size vertices: %i\n", 24*sizeof(rglVertex));
	//indices=(GLuint *)malloc(24*3*sizeof(GLuint));	
		for (GLint i=0; i<=23; i++)
	{
	vertexes[i].position.x=vertices_1[i*3+0];
	vertexes[i].position.y=vertices_1[i*3+1];
	vertexes[i].position.z=vertices_1[i*3+2];
	vertexes[i].position.w=1.0;
	vertexes[i].color.r= colors_1[i*3+0];
	vertexes[i].color.g= colors_1[i*3+1];
	vertexes[i].color.b= colors_1[i*3+2];
	vertexes[i].color.a= 1.0;
	vertexes[i].normal.x= normals_1[i*3+0];
	vertexes[i].normal.y= normals_1[i*3+1];
	vertexes[i].normal.z= normals_1[i*3+2];
	vertexes[i].texcoord.s= texcoords_1[i*2+0];
	vertexes[i].texcoord.t= texcoords_1[i*2+1];
	};    
		return vertexes;
	//printf("Size vertices: %i\n", 24*sizeof(rglVertex));
		free(vertexes);
	}
GLuint *rglCubeIndexArrayCreate()
{
	GLuint *indices=(GLuint *)malloc(24*sizeof(GLuint));	
	//printf("Size indices: %i\n", 24*sizeof(GLuint));
	//printf("Size indices: %i\n", sizeof(*indices));
	
	for (GLint i=0; i<=23; i++)
	indices[i]=i;
	return indices;
	free(indices);
}

rglMesh *rglInitCubeMesh(GLint size)
{
	rglMesh *mesh=(rglMesh *)malloc(sizeof(rglMesh));
	mesh->vertices=rglCubeVertexArrayCreate(size);
	mesh->indices=rglCubeIndexArrayCreate();
	mesh->count=24;
	mesh->face_type=GL_QUADS;
	return mesh;
	free(mesh->vertices);
	free(mesh->indices);
	free(mesh);
	}

rglMesh *rglInitCloneCubeMesh(GLint size, GLuint count_clone)
{
	rglMesh *mesh=(rglMesh *)malloc(sizeof(rglMesh));
	mesh->vertices=rglCubeVertexArrayCreate(size);
	mesh->indices=rglCubeIndexArrayCreate();
	mesh->count=24;
	mesh->face_type=GL_QUADS;
	rglMesh *mesh_clones=(rglMesh *)malloc(sizeof(rglMesh));
	GLuint count=count_clone;
	mesh_clones->vertices=(rglVertex *)malloc(24*count*count*count*sizeof(rglVertex));
	//printf("size: %i\n", 24*count*count*count*sizeof(rglVertex));
	GLuint n=0;
	//GLint i=-1*(count_clone-1);
	//GLint j=-1*(count_clone-1);
	//GLint k=-1*(count_clone-1);
	for (GLint i=0; i<=(count_clone-1); i++)
	for (GLint j=0; j<=(count_clone-1); j++)
	for (GLint k=0; k<=(count_clone-1); k++)
	{
	//	printf("Point 1\n");
	//	printf("size: %i\n", n*sizeof(rglVertex)*24);
		memcpy(&mesh_clones->vertices[(n*24)], &mesh->vertices[0],sizeof(rglVertex)*24);
		
	//	printf("Point 2\n");
	for (GLint r=0; r<=23; r++)
	{
		
		mesh_clones->vertices[n*24+r].position.x=mesh->vertices[r].position.x + i*size*2.5;
		mesh_clones->vertices[n*24+r].position.y=mesh->vertices[r].position.y + j*size*2.5;
		mesh_clones->vertices[n*24+r].position.z=mesh->vertices[r].position.z + k*size*2.5;
		mesh_clones->vertices[n*24+r].position.w=mesh->vertices[r].position.w ;
		//printf("cube.vertices: %5.2f\n", mesh_clones->vertices[n*24+r].position[0]);
		//printf("cube.vertices: %5.2f\n", mesh_clones->vertices[n*24+r].position[1]);
		//printf("cube.vertices: %5.2f\n", mesh_clones->vertices[n*24+r].position[2]);
		//printf("n - : %i\n", n);
		//printf("r - : %i\n", r);
	}
	n++;
	}
	//printf("n - : %i\n", n);
	//printf("i - : %i\n", i);
	//printf("j - : %i\n", j);
	//printf("k - : %i\n", k);
	mesh_clones->indices=(GLuint *)malloc(sizeof(GLuint)*24*count*count*count);
	for (GLint i=0; i<=24*count*count*count-1; i++)
	mesh_clones->indices[i]=i;
	
	mesh_clones->count=24*count*count*count;
	mesh_clones->face_type=mesh->face_type;
	return mesh_clones;
	free(mesh->vertices);
	free(mesh->indices);
	free(mesh);
	free(mesh_clones->vertices);
	free(mesh_clones->indices);
	free(mesh_clones);
	}

void rglFreeMesh(rglMesh *mesh)
{
	if (mesh->vertices != NULL)
	
		free(mesh->vertices);
		
	
	if (mesh->indices != NULL)
		free(mesh->indices);
	if (mesh != NULL)	
		free(mesh);
	}

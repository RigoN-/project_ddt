#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glew.h>
#include "rglMesh3D.h"
#include "rglFigures.h"
#include "rglShader.h"
#include "rglMaterial.h"



void rglPushMatrix(rglMat4 mvm_w, GLuint shader)
{
	rglMat3 nm_o;	
	if (shader == 0)
		{
			glLoadMatrixf(mvm_w);	
		}
		else
		{
	
		rglMatrixNormal(nm_o,mvm_w);	
		glUniformMatrix3fv(glGetUniformLocation(shader,"nmatrix"), 1,GL_FALSE,&nm_o[0]);
		glUniformMatrix4fv(glGetUniformLocation(shader,"mvmatrix"), 1,GL_FALSE,&mvm_w[0]);	
		
		}

}

void rglPushMaterial(rglMaterial material, GLuint shader)
{

	if (shader != 0)
		{
		glUniform4fv(glGetUniformLocation(shader,"MaterialAmbient"), 1, &material.Mambient.x);
		glUniform4fv(glGetUniformLocation(shader,"MaterialDiffuse"), 1, &material.Mdiffuse.x);
		glUniform4fv(glGetUniformLocation(shader,"MaterialSpecular"), 1, &material.Mspecular.x);
		glUniform1fv(glGetUniformLocation(shader,"MaterialShininess"), 1,&material.Mshininess);	
		}
		

}


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
	
	GLuint n=0;
	
	for (GLint i=0; i<=(count_clone-1); i++)
	for (GLint j=0; j<=(count_clone-1); j++)
	for (GLint k=0; k<=(count_clone-1); k++)
	{

		memcpy(&mesh_clones->vertices[(n*24)], &mesh->vertices[0],sizeof(rglVertex)*24);
		
	
	for (GLint r=0; r<=23; r++)
	{
		
		mesh_clones->vertices[n*24+r].position.x=mesh->vertices[r].position.x + i*size*2.5;
		mesh_clones->vertices[n*24+r].position.y=mesh->vertices[r].position.y + j*size*2.5;
		mesh_clones->vertices[n*24+r].position.z=mesh->vertices[r].position.z + k*size*2.5;
		mesh_clones->vertices[n*24+r].position.w=mesh->vertices[r].position.w ;
	
	}
	n++;
	}
	
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
	
	
	
	





void rglSpring_Draw (GLfloat R, GLfloat r, GLint n, GLint m, GLfloat theta_x, GLfloat phi_x, GLfloat h, GLfloat CYCLES)
{
	rglSetMaterial(4);
GLfloat dy=(2*M_PI*h*CYCLES-2*M_PI*0.1*23)/M_PI;	

	glPushMatrix();
	glTranslatef(0.0,0.0,0.0);	
	rglSpiral_Draw(R,r,n,m,theta_x,phi_x,h,CYCLES);
	glPopMatrix();


	glPushMatrix();
	
	
	glPushMatrix();	
	glTranslatef(0.754,4.7724+dy,-0.004);
	glRotatef(0.0,1.0,0.0,0.0);
	glRotatef(0.0,0.0,1.0,0.0);
	glRotatef(-35.0,0.0,0.0,1.0);
	rglTorus_Draw(R,r,16,16,M_PI/2,2*M_PI);	
	glPopMatrix();
		
	glPushMatrix();	
	glTranslatef(0.56,4.7124+dy,-0.68);
	glRotatef(-73.3,1.0,0.0,0.0);
	glRotatef(-55.7,0.0,1.0,0.0);
	glRotatef(-67.3,0.0,0.0,1.0);	
	rglTorus_Draw(R,r,16,16,M_PI/1.5,2*M_PI);	
	glPopMatrix();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(0.754,-0.1724,0.004);
	glRotatef(180.0,1.0,0.0,0.0);
	glRotatef(0.0,0.0,1.0,0.0);
	glRotatef(-35.0,0.0,0.0,1.0);
	rglTorus_Draw(R,r,16,16,M_PI/2,2*M_PI);	
	glPopMatrix();
	
	
	
	
	glPushMatrix();
	glTranslatef(0.56,-0.080,0.68);
	glRotatef(104.7,1.0,0.0,0.0);
	glRotatef(-57.7,0.0,1.0,0.0);
	glRotatef(-67.3,0.0,0.0,1.0);	
	rglTorus_Draw(R,r,16,16,M_PI/1.5,2*M_PI);	
	glPopMatrix();

}
void rglSpring_Draw_2 (GLfloat R, GLfloat r, GLint n, GLint m, GLfloat theta_x, GLfloat phi_x, GLfloat h, GLfloat CYCLES)
{


	glPushMatrix();
	glTranslatef(0.0,0.0,0.0);	
	rglSpiral_Draw(R,r,n,m,theta_x,phi_x,h,CYCLES);
	glPopMatrix();

}

void DinoSpring(rglMat4 mvm,GLfloat h,GLuint tex_04, GLuint shader)
{
	rglMaterial material;
	rglMat4 mvm_d_s;
	rglMat4 mvm_work;
	GLfloat dy=(2*M_PI*h*30-2*M_PI*0.05*30)/M_PI;
  
	rglSetMaterial_2(3,&material);
	rglPushMaterial(material,shader);
	glBindTexture(GL_TEXTURE_2D, tex_04);
	rglMatrix4Identity(mvm_d_s);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_d_s,0.0,0.0-dy,0.0);

	rglMatrix4Multiply(mvm_work,mvm_d_s);
	rglPushMatrix(mvm_work,shader);
	rglSpring_Draw_2 (0.3, 0.05, 32,32, 2*M_PI,2*M_PI,h,30);
	
	
	
	
    rglSetMaterial_2(3,&material);
	rglPushMaterial(material,shader);
	glBindTexture(GL_TEXTURE_2D, tex_04);
	rglMatrix4Identity(mvm_d_s);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_d_s,0.0,2.9,0.0);
	rglMatrix4Multiply(mvm_work,mvm_d_s);
	rglPushMatrix(mvm_work,shader);
    rglDisk_Draw(32, 2*M_PI, 0.3, 0.0);
    
   rglSetMaterial_2(3,&material);
	rglPushMaterial(material,shader);
	glBindTexture(GL_TEXTURE_2D, tex_04);
	rglMatrix4Identity(mvm_d_s);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_d_s,0.0,0.1-dy,0.0);
	rglMatrix4Multiply(mvm_work,mvm_d_s);
	rglPushMatrix(mvm_work,shader);
    rglDisk_Draw(32, 2*M_PI, 0.3, 0.0);
 
	rglSetMaterial_2(3,&material);
	rglPushMaterial(material,shader);
	glBindTexture(GL_TEXTURE_2D, tex_04);
	rglMatrix4Identity(mvm_d_s);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_d_s,0.0,2.9,0.0);
	rglMatrix4Multiply(mvm_work,mvm_d_s);
	rglPushMatrix(mvm_work,shader);
    rglCylinder_Draw(mvm_work,32,32, 0.5,0.05,2*M_PI,tex_04,shader);
  

	rglSetMaterial_2(3,&material);
	rglPushMaterial(material,shader);
	glBindTexture(GL_TEXTURE_2D, tex_04);
	rglMatrix4Identity(mvm_d_s);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_d_s,0.0,3.4,0.2);
	rglRotate(mvm_d_s,-90.0,1.0,0.0,0.0);
	rglRotate(mvm_d_s,0.0,0.0,1.0,0.0);
	rglRotate(mvm_d_s,90.0,0.0,0.0,1.0);
	rglMatrix4Multiply(mvm_work,mvm_d_s);
	rglPushMatrix(mvm_work,shader);
    rglTorus_Draw(0.1, 0.05, 32, 32,M_PI,2*M_PI);
  
	rglSetMaterial_2(3,&material);
	rglPushMaterial(material,shader);
	glBindTexture(GL_TEXTURE_2D, tex_04);
	rglMatrix4Identity(mvm_d_s);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_d_s,0.0,-0.2-dy,0.05);
	rglRotate(mvm_d_s,90.0,1.0,0.0,0.0);
	rglRotate(mvm_d_s,180.0,0.0,0.0,1.0);
	rglMatrix4Multiply(mvm_work,mvm_d_s);
	rglPushMatrix(mvm_work,shader);
    rglCylinder_Draw(mvm_work,32,32, 0.3,0.05, 2*M_PI,tex_04,shader);
   
	
	rglSetMaterial_2(3,&material);
	rglPushMaterial(material,shader);
	glBindTexture(GL_TEXTURE_2D, tex_04);
	rglMatrix4Identity(mvm_d_s);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_d_s,2.0,-0.2-dy,-0.2);
	rglRotate(mvm_d_s,90.0,1.0,0.0,0.0);
	rglRotate(mvm_d_s,90.0,0.0,0.0,1.0);
	rglMatrix4Multiply(mvm_work,mvm_d_s);
	rglPushMatrix(mvm_work,shader);
    rglCylinder_Draw(mvm_work,32,32, 3.8,0.05, 2*M_PI,tex_04,shader);
  
  
   rglSetMaterial_2(3,&material);
	rglPushMaterial(material,shader);
	glBindTexture(GL_TEXTURE_2D, tex_04);
	rglMatrix4Identity(mvm_d_s);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_d_s,0.0,-12.0-dy,0.0);
	rglMatrix4Multiply(mvm_work,mvm_d_s);
	rglPushMatrix(mvm_work,shader);
    rglCylinder_Draw(mvm_work,32,32, 12.5,0.05, 2*M_PI,tex_04,shader);
   
	rglSetMaterial_2(3,&material);
	rglPushMaterial(material,shader);
	glBindTexture(GL_TEXTURE_2D, tex_04);
	rglMatrix4Identity(mvm_d_s);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_d_s,-0.1,-12.0-dy,0.0);
	rglRotate(mvm_d_s,90.0,1.0,0.0,0.0);
	rglRotate(mvm_d_s,180.0,0.0,0.0,1.0);
	rglMatrix4Multiply(mvm_work,mvm_d_s);
	rglPushMatrix(mvm_work,shader);
    rglTorus_Draw(0.1, 0.05, 32, 32,M_PI,2*M_PI);
 
	
}

void rglDinamometr_Draw(rglMat4 mvm,GLfloat h,GLuint shkala,GLuint wplastic,GLuint stal, GLuint shader)
{
	rglMaterial material;
	rglMat4 mvm_d;
	rglMat4 mvm_work;
	
	rglSetMaterial_2(28,&material);
    rglPushMaterial(material,shader);
	rglMatrix4Identity(mvm_d);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_d,0.0,10.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_d);
	rglPushMatrix(mvm_work,shader);
    rglCube_Draw(mvm_work,2.0, 7.0, 0.3,shkala,wplastic,wplastic,wplastic,wplastic,wplastic,shader);
 
	rglMatrix4Identity(mvm_d);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_d,0.0,17.0,0.65);
	rglMatrix4Multiply(mvm_work,mvm_d);
	rglPushMatrix(mvm_work,shader);
	rglCube_Draw(mvm_work,2.0, 0.3, 1.0,wplastic,wplastic,wplastic,wplastic,wplastic,wplastic,shader);
	
		
	rglMatrix4Identity(mvm_d);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_d,0.0,17.1,0.8);
	rglRotate(mvm_d,90.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_d);
	rglPushMatrix(mvm_work,shader);
    rglTorus_Draw(0.6, 0.1, 32, 32, M_PI, 2*M_PI );

    rglMatrix4Identity(mvm_d);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_d,0.0,17.3,0.65);
	rglRotate(mvm_d,-90.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_d);
	rglPushMatrix(mvm_work,shader);
    rglTorus_Draw(0.6, 0.1, 32, 32, M_PI, 2*M_PI );



    rglMatrix4Identity(mvm_d);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_d,0.0,4.0,0.2);
	rglMatrix4Multiply(mvm_work,mvm_d);
	rglPushMatrix(mvm_work,shader);
    rglTorus_Draw(0.6, 0.1, 32, 32, M_PI, 2*M_PI );

	
	rglSetMaterial_2(3,&material);
    rglPushMaterial(material,shader);	
    glBindTexture(GL_TEXTURE_2D, stal);
	rglMatrix4Identity(mvm_d);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_d,0.0,13.1,0.7);
	rglMatrix4Multiply(mvm_work,mvm_d);
	rglPushMatrix(mvm_work,shader);
	DinoSpring(mvm_work,h,stal,shader);
	
	

	
}
void rglGruzik_Draw(rglMat4 mvm, GLfloat n, GLfloat m, GLfloat h, GLfloat R, GLfloat angle, GLuint stal, GLuint shader)
{
rglMaterial material;	
rglMat4 mvm_g;
rglMat4 mvm_work;

rglSetMaterial_2(3,&material);
rglPushMaterial(material,shader);	
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, stal);
	
	rglMatrix4Identity(mvm_g);
	rglMatrix4Copy(mvm_work,mvm);
	rglMatrix4Multiply(mvm_work,mvm_g);
	rglPushMatrix(mvm_work,shader);
	rglCylinder_Draw(mvm_work, n, m,  h,  R,  angle, stal, shader);



   	rglMatrix4Identity(mvm_g);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_g,0.0,h-0.15,0.0);
	rglMatrix4Multiply(mvm_work,mvm_g);
	rglPushMatrix(mvm_work,shader);
	rglSphere_Draw(0.3, n, M_PI/3,2*M_PI);




   	rglMatrix4Identity(mvm_g);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_g,0.0,0.15,0.0);
	rglRotate(mvm_g,180.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_g);
	rglPushMatrix(mvm_work,shader);
	rglSphere_Draw(0.3, n, M_PI/3,2*M_PI);


   	rglMatrix4Identity(mvm_g);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_g,0.2,-0.7,-0.05);
	rglRotate(mvm_g,2.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_g);	
    rglPushMatrix(mvm_work,shader);
    rglHook_Draw(mvm_work, 0.5, 0.1, 32, 32, 2*M_PI, stal, shader );


   	rglMatrix4Identity(mvm_g);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_g,-0.90,2.1,0.0);
	rglRotate(mvm_g,-180.0,1.0,0.0,0.0);
	rglRotate(mvm_g,-180.0,0.0,1.0,0.0);
	rglRotate(mvm_g,20.0,0.0,0.0,1.0);
	rglMatrix4Multiply(mvm_work,mvm_g);			
    rglPushMatrix(mvm_work,shader);
	rglHook_Draw(mvm_work, 0.5, 0.1, 32, 32, 2*M_PI,stal, shader); 



}

void rglHook_Draw(rglMat4 mvm, GLfloat R, GLfloat r, GLint n, GLint m, GLfloat phi_x, GLuint tex, GLuint shader ) 
{
	rglMaterial material;
	rglMat4 mvm_h;
	rglMat4 mvm_work;
	
    
    rglSetMaterial_2(3,&material);
    rglPushMaterial(material,shader);	
	glBindTexture(GL_TEXTURE_2D, tex);
	
   	rglMatrix4Identity(mvm_h);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_h,0.0,3.0,0.0);
	rglRotate(mvm_h,90.0,1.0,0.0,0.0);
	rglRotate(mvm_h,170.0,0.0,1.0,0.0);	
	rglMatrix4Multiply(mvm_work,mvm_h);
	rglPushMatrix(mvm_work,shader);
	rglTorus_Draw(R,r,n,m,2*M_PI*2/3,2*M_PI);	
	
	
	
   	rglMatrix4Identity(mvm_h);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_h,0.2,2.02,-0.0185);
	rglRotate(mvm_h,-88.0,1.0,0.0,0.0);
	rglRotate(mvm_h,-10.0,0.0,1.0,0.0);
	rglRotate(mvm_h,180.0,0.0,0.0,1.0);
	rglMatrix4Multiply(mvm_work,mvm_h);
	rglPushMatrix(mvm_work,shader);

	rglTorus_Draw(R,r,n,m,M_PI/2,2*M_PI);	
		
		
	
   	rglMatrix4Identity(mvm_h);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_h,-0.49,3.09,0.0);
	rglRotate(mvm_h,171.0,1.0,0.0,0.0);
	rglRotate(mvm_h,33.0,0.0,1.0,0.0);
	rglRotate(mvm_h,12.0,0.0,0.0,1.0);
	rglMatrix4Multiply(mvm_work,mvm_h);
	rglPushMatrix(mvm_work,shader);
    rglDisk_Draw(32,2*M_PI,r,0.0);	
  	
}

void rglHook_2_Draw(rglMat4 mvm,GLfloat R, GLfloat r, GLint n, GLint m, GLfloat phi_x, GLuint stal, GLuint shader ) 
{
	rglMaterial material;
	rglMat4 mvm_h_2;
	rglMat4 mvm_work;
	
	rglSetMaterial_2(3,&material);
    rglPushMaterial(material,shader);
	glBindTexture(GL_TEXTURE_2D, stal);
   	rglMatrix4Identity(mvm_h_2);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_h_2,0.0,3.0,0.0);
	rglRotate(mvm_h_2,90.0,1.0,0.0,0.0);
	rglRotate(mvm_h_2,170.0,0.0,1.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_h_2);
	rglPushMatrix(mvm_work,shader);
	rglTorus_Draw(R,r,n,m,2*M_PI*3/5,2*M_PI);	

	
	
	
    rglMatrix4Identity(mvm_h_2);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_h_2,0.27,1.82,0.01);
	rglRotate(mvm_h_2,90.0,1.0,0.0,0.0);
	rglRotate(mvm_h_2,-3.10,0.0,1.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_h_2);
	rglPushMatrix(mvm_work,shader);
	rglTorus_Draw(0.5,0.1,32,32,2*M_PI*3/5,2*M_PI);	
	
	
	rglMatrix4Identity(mvm_h_2);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_h_2,0.77,1.79,0.01);
	rglRotate(mvm_h_2,0.0,1.0,0.0,0.0);
	rglRotate(mvm_h_2,1.0,0.0,1.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_h_2);
	rglPushMatrix(mvm_work,shader);	
    rglDisk_Draw(32,2*M_PI,0.1,0.0);	
   
   
	rglMatrix4Identity(mvm_h_2);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_h_2,-0.49,3.09,0.0);
	rglRotate(mvm_h_2,171.0,1.0,0.0,0.0);
	rglRotate(mvm_h_2,33.0,0.0,1.0,0.0);
	rglRotate(mvm_h_2,12.0,0.0,0.0,1.0);
	rglMatrix4Multiply(mvm_work,mvm_h_2);
	rglPushMatrix(mvm_work,shader);		
    rglDisk_Draw(32,2*M_PI,0.1,0.0);	
  
	

	rglMatrix4Identity(mvm_h_2);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_h_2,0.352,2.645,0.00);
	rglRotate(mvm_h_2,1.10,1.0,0.0,0.0);
	rglRotate(mvm_h_2,2.50,0.0,1.0,0.0);
	rglRotate(mvm_h_2,137.40,0.0,0.0,1.0);
	rglMatrix4Multiply(mvm_work,mvm_h_2);
	rglPushMatrix(mvm_work,shader);		
	rglTube_Draw(32,32,0.7,0.1,2*M_PI);
	
	
	
}
void rglKoretka_Draw(rglMat4 mvm, GLuint tex_02, GLuint tex_03, GLuint shader)
{
	rglSetMaterial(3);
	rglMat4 mvm_k;
	rglMat4 mvm_work;
  

    glBindTexture(GL_TEXTURE_2D, tex_02);
   	rglMatrix4Identity(mvm_k);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_k,0.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_k);
	rglPushMatrix(mvm_work,shader);
    rglCube_Draw(mvm_work,6.0,1.5,4.0,tex_02,tex_02,tex_02,tex_02,tex_02,tex_02,shader);

	glBindTexture(GL_TEXTURE_2D, tex_02);
   	rglMatrix4Identity(mvm_k);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_k,0.0,1.5,0.0);
	rglMatrix4Multiply(mvm_work,mvm_k);
	rglPushMatrix(mvm_work,shader);
    rglTorus_Draw(1.0, 0.6, 32, 32,2*M_PI,M_PI);
   
	glBindTexture(GL_TEXTURE_2D, tex_02);
   	rglMatrix4Identity(mvm_k);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_k,4.0,1.5,0.0);
	rglMatrix4Multiply(mvm_work,mvm_k);
	rglPushMatrix(mvm_work,shader);
    rglTorus_Draw(1.0, 0.6, 32, 32,2*M_PI,M_PI);
  
  
	glBindTexture(GL_TEXTURE_2D, tex_02);
   	rglMatrix4Identity(mvm_k);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_k,-4.0,1.5,0.0);
	rglMatrix4Multiply(mvm_work,mvm_k);
	rglPushMatrix(mvm_work,shader);
    rglTorus_Draw(1.0, 0.6, 32, 32,2*M_PI,M_PI);
   
	glBindTexture(GL_TEXTURE_2D, tex_03);
   	rglMatrix4Identity(mvm_k);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_k,6.0,0.0,0.0);
	rglRotate(mvm_k,90.0,1.0,0.0,0.0);
	rglRotate(mvm_k,90.0,0.0,1.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_k);
	rglPushMatrix(mvm_work,shader);
    rglTorus_Draw(1.0, 0.3, 32, 32,M_PI,2*M_PI);
   
   
	glBindTexture(GL_TEXTURE_2D, tex_03);
   	rglMatrix4Identity(mvm_k);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_k,-6.0,0.0,0.0);
	rglRotate(mvm_k,90.0,1.0,0.0,0.0);
	rglRotate(mvm_k,180.0,0.0,0.0,1.0);
    rglRotate(mvm_k,90.0,0.0,1.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_k);
	rglPushMatrix(mvm_work,shader);
    rglTorus_Draw(1.0, 0.3, 32, 32,M_PI,2*M_PI);
	
  

}
 


void rglShtativ_Draw(rglMat4 mvm, GLuint yplastic,GLuint stal, GLuint bplastic, GLuint shader)
{
rglMaterial material;	
rglMat4 mvm_s;
rglMat4 mvm_work;

rglSetMaterial_2(24, &material);
rglPushMaterial(material,shader);
glBindTexture(GL_TEXTURE_2D, yplastic);

////основа
	
   	rglMatrix4Identity(mvm_s);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_s,0.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_s);
	rglPushMatrix(mvm_work,shader);
	rglCube_Draw(mvm_work,5.5,1.1,5.5,yplastic,yplastic,yplastic,yplastic,yplastic,yplastic,shader);
	
/////Отверств

	rglMatrix4Identity(mvm_s);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_s,0.0,1.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_s);
	rglPushMatrix(mvm_work,shader);	
	rglTorus_Draw(0.6, 0.4, 32, 32, 2*M_PI, M_PI );


rglSetMaterial_2(3,&material);
rglPushMaterial(material,shader);
glBindTexture(GL_TEXTURE_2D, stal);
////Осн. Штатив

	rglMatrix4Identity(mvm_s);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_s,0.0,1.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_s);
	rglPushMatrix(mvm_work,shader);
	rglCylinder_Draw(mvm_work, 32, 32, 40.0, 0.5, 2*M_PI,stal,shader);


//////крепеж
	
	rglMatrix4Identity(mvm_s);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_s,0.0,40.0,-2.0);
	rglRotate(mvm_s,90.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_s);
	rglPushMatrix(mvm_work,shader);
	rglCylinder_Draw(mvm_work, 32,32, 10.0, 1.0, 2*M_PI,stal,shader);


//////Держатель

	rglMatrix4Identity(mvm_s);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_s,6.0,39.8,3.5);
	rglRotate(mvm_s,90.0,0.0,0.0,1.0);
	rglMatrix4Multiply(mvm_work,mvm_s);
	rglPushMatrix(mvm_work,shader);
	rglCylinder_Draw(mvm_work, 32,32, 20.0, 0.5, 2*M_PI,stal,shader);	



rglSetMaterial_2(0,&material);
rglPushMaterial(material,shader);
glBindTexture(GL_TEXTURE_2D, bplastic);
////болт 1

    rglMatrix4Identity(mvm_s);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_s,0.0,39.8,4.0);
	rglRotate(mvm_s,90.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_s);
	rglPushMatrix(mvm_work,shader);
    rglCylinder_Draw(mvm_work, 32,32, 5.0, 0.5, 2*M_PI,bplastic,shader);

glBindTexture(GL_TEXTURE_2D, bplastic);
//////болт 2

	rglMatrix4Identity(mvm_s);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_s,0.0,39.8,-4.0);
	rglRotate(mvm_s,90.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_s);
	rglPushMatrix(mvm_work,shader);
	rglCylinder_Draw(mvm_work, 32,32, 5.0, 0.5, 2*M_PI,bplastic,shader);




}

void rglShtativ_Draw_3(rglMat4 mvm, GLuint yplastic,GLuint stal, GLuint bplastic, GLuint shader)
{
rglMaterial material;	
rglMat4 mvm_s_3;
rglMat4 mvm_work;

rglSetMaterial_2(24,&material);
rglPushMaterial(material,shader);
glBindTexture(GL_TEXTURE_2D, yplastic);

////основа
	
   	rglMatrix4Identity(mvm_s_3);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_s_3,0.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_s_3);
	rglPushMatrix(mvm_work,shader);
	rglCube_Draw(mvm_work,5.5,1.1,5.5,yplastic,yplastic,yplastic,yplastic,yplastic,yplastic,shader);
	
/////Отверств

	rglMatrix4Identity(mvm_s_3);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_s_3,0.0,1.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_s_3);
	rglPushMatrix(mvm_work,shader);	
	rglTorus_Draw(0.6, 0.4, 32, 32, 2*M_PI, M_PI );

rglSetMaterial_2(3,&material);
rglPushMaterial(material,shader);
glBindTexture(GL_TEXTURE_2D, stal);
////Осн. Штатив

	rglMatrix4Identity(mvm_s_3);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_s_3,0.0,1.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_s_3);
	rglPushMatrix(mvm_work,shader);
	rglCylinder_Draw(mvm_work, 32, 32, 40.0, 0.5, 2*M_PI,stal,shader);


//////крепеж

	rglMatrix4Identity(mvm_s_3);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_s_3,0.0,30.0,-2.0);
	rglRotate(mvm_s_3,90.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_s_3);
	rglPushMatrix(mvm_work,shader);
	rglCylinder_Draw(mvm_work, 32,32, 6.0, 1.0, 2*M_PI,stal,shader);


}

void rglShtativ_Draw_2(rglMat4 mvm, GLuint yplastic,GLuint stal, GLuint bplastic, GLuint shader)
{
rglMaterial material;	
rglMat4 mvm_s_2;
rglMat4 mvm_work;


rglSetMaterial_2(24,&material);
rglPushMaterial(material,shader);
glBindTexture(GL_TEXTURE_2D, yplastic);

////основа
	
   	rglMatrix4Identity(mvm_s_2);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_s_2,0.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_s_2);
	rglPushMatrix(mvm_work,shader);
	rglCube_Draw(mvm_work,5.5,1.1,5.5,yplastic,yplastic,yplastic,yplastic,yplastic,yplastic,shader);
	
/////Отверств

	rglMatrix4Identity(mvm_s_2);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_s_2,0.0,1.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_s_2);
	rglPushMatrix(mvm_work,shader);	
	rglTorus_Draw(0.6, 0.4, 32, 32, 2*M_PI, M_PI );



rglSetMaterial_2(3,&material);
rglPushMaterial(material,shader);
glBindTexture(GL_TEXTURE_2D, stal);
////Осн. Штатив

	rglMatrix4Identity(mvm_s_2);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_s_2,0.0,1.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_s_2);
	rglPushMatrix(mvm_work,shader);
	rglCylinder_Draw(mvm_work, 32, 32, 40.0, 0.5, 2*M_PI,stal,shader);


//////крепеж

	rglMatrix4Identity(mvm_s_2);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_s_2,0.0,20.0,-2.0);
	rglRotate(mvm_s_2,90.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_s_2);
	rglPushMatrix(mvm_work,shader);
	rglCylinder_Draw(mvm_work, 32,32, 6.0, 1.0, 2*M_PI,stal,shader);


}

void rglRule_Draw(rglMat4 mvm, GLuint gplastic, GLuint bplastic, GLuint stal, GLuint shader)
{
	rglMaterial material;
	rglMat4 mvm_r;
 rglMat4 mvm_work;


rglSetMaterial_2(21,&material);
rglPushMaterial(material,shader);
glBindTexture(GL_TEXTURE_2D, gplastic);

   	rglMatrix4Identity(mvm_r);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_r,0.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_r);
	rglPushMatrix(mvm_work,shader);
	rglCube_Draw(mvm_work,18.0, 1.0, 0.25,gplastic,gplastic,gplastic,gplastic,gplastic,gplastic,shader);	
	


rglSetMaterial_2(0,&material);
rglPushMaterial(material,shader);
glBindTexture(GL_TEXTURE_2D, bplastic);

   	rglMatrix4Identity(mvm_r);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_r,0.0,0.0,0.0);
	rglRotate(mvm_r,90.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_r);
	rglPushMatrix(mvm_work,shader);		
    rglCylinder_Draw(mvm_work,32,32,2.5,0.5,2*M_PI,bplastic,shader);




///////////////Отверстия/////////// right

rglSetMaterial_2(3,&material);
rglPushMaterial(material,shader);
    glBindTexture(GL_TEXTURE_2D,stal);
   	rglMatrix4Identity(mvm_r);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_r,4.0,-0.75,0.0);
	rglRotate(mvm_r,90.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_r);
	rglPushMatrix(mvm_work,shader);
    rglTorus_Draw(0.6, 0.1, 32, 32, M_PI, 2*M_PI );


   	rglMatrix4Identity(mvm_r);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_r,8.0,-0.75,0.0);
	rglRotate(mvm_r,90.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_r);
	rglPushMatrix(mvm_work,shader);
    rglTorus_Draw(0.6, 0.1, 32, 32, M_PI, 2*M_PI );

   
   	rglMatrix4Identity(mvm_r);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_r,12.0,-0.75,0.0);
	rglRotate(mvm_r,90.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_r);
	rglPushMatrix(mvm_work,shader);
    rglTorus_Draw(0.6, 0.1, 32, 32, M_PI, 2*M_PI );
	
	
	rglMatrix4Identity(mvm_r);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_r,16.0,-0.75,0.0);
	rglRotate(mvm_r,90.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_r);
	rglPushMatrix(mvm_work,shader);
    rglTorus_Draw(0.6, 0.1, 32, 32, M_PI, 2*M_PI );


////////Отверстия/////////////left


    rglSetMaterial_2(3,&material);
    rglPushMaterial(material,shader);
   	rglMatrix4Identity(mvm_r);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_r,-4.0,-0.75,0.0);
	rglRotate(mvm_r,90.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_r);
	rglPushMatrix(mvm_work,shader);
    rglTorus_Draw(0.6, 0.1, 32, 32, M_PI, 2*M_PI );

   
   	rglMatrix4Identity(mvm_r);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_r,-8.0,-0.75,0.0);
	rglRotate(mvm_r,90.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_r);
	rglPushMatrix(mvm_work,shader);
    rglTorus_Draw(0.6, 0.1, 32, 32, M_PI, 2*M_PI );

   
   	rglMatrix4Identity(mvm_r);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_r,-12.0,-0.75,0.0);
	rglRotate(mvm_r,90.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_r);
	rglPushMatrix(mvm_work,shader);
    rglTorus_Draw(0.6, 0.1, 32, 32, M_PI, 2*M_PI );
	
	rglMatrix4Identity(mvm_r);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_r,-16.0,-0.75,0.0);
	rglRotate(mvm_r,90.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_r);
	rglPushMatrix(mvm_work,shader);
    rglTorus_Draw(0.6, 0.1, 32, 32, M_PI, 2*M_PI );

   
	rglMatrix4Identity(mvm_r);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_r,0.0,0.0,-1.5);
	rglRotate(mvm_r,90.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_r);
	rglPushMatrix(mvm_work,shader);
    rglCylinder_Draw(mvm_work,32,32,1.0,0.2,2*M_PI,stal,shader);

   
   	rglMatrix4Identity(mvm_r);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_r,0.0,0.0,-0.8);
	rglRotate(mvm_r,90.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_r);
	rglPushMatrix(mvm_work,shader);
    rglDisk_Draw(32, 2*M_PI, 0.5, 0.2);

}

void rglNapravlenie_Draw(rglMat4 mvm,GLuint shkala2, GLuint gplastic, GLuint yplastic, GLuint shader)
{
	rglMaterial material;
	rglSetMaterial(21);
	rglMat4 mvm_n;
	rglMat4 mvm_work;
	
    rglSetMaterial_2(21,&material);
	rglPushMaterial(material,shader);
    glBindTexture(GL_TEXTURE_2D, gplastic);
   	rglMatrix4Identity(mvm_n);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_n,0.0,20.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_n);
	rglPushMatrix(mvm_work,shader);
	rglCube_Draw(mvm_work,2.0, 22.5, 0.5,gplastic,gplastic,gplastic,gplastic,gplastic,gplastic,shader);
	
	
	
	rglSetMaterial_2(24,&material);
	rglPushMaterial(material,shader);
	glBindTexture(GL_TEXTURE_2D, yplastic);
   	rglMatrix4Identity(mvm_n);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_n,2.5,20.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_n);
	rglPushMatrix(mvm_work,shader);
	rglCube_Draw(mvm_work,0.5, 22.5, 1.5,yplastic,yplastic,yplastic,yplastic,yplastic,yplastic,shader);
	
	
	glBindTexture(GL_TEXTURE_2D, yplastic);
   	rglMatrix4Identity(mvm_n);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_n,-3.0,20.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_n);
	rglPushMatrix(mvm_work,shader);
	rglCube_Draw(mvm_work,1.0, 22.5, 1.5,shkala2,yplastic,yplastic,yplastic,yplastic,yplastic,shader);
	
	rglSetMaterial_2(21,&material);
	rglPushMaterial(material,shader);
	glBindTexture(GL_TEXTURE_2D, gplastic);
   	rglMatrix4Identity(mvm_n);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_n,-0.5,-2.9,-1.3);
	rglMatrix4Multiply(mvm_work,mvm_n);
	rglPushMatrix(mvm_work,shader);
	rglCube_Draw(mvm_work,4.0, 0.4, 3.0,gplastic,gplastic,gplastic,gplastic,gplastic,gplastic,shader);

	
}


void rglSharik_Draw(GLfloat r, GLfloat n, GLfloat phi3, GLfloat theta3)
{
	rglSphere_Draw(0.5,32, 2*M_PI,2*M_PI);
}




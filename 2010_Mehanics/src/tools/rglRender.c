#include "rglRender.h"




GLvoid rglSetProjection( GLint width, GLint height, GLint projection, rglMat4 pvm)
{
	switch (projection)
	{
		case RGL_PROJECTION_ORTHO :			
		  
			rglMatrix4Identity(pvm);
			rglOrtho(pvm, 0.0,width, 0.0, height, 1.0, -10.0);			
			
	    break;
		case RGL_PROJECTION_PERSPECTIVE :		
			
		rglMatrix4Identity(pvm);
		rglPerspective(pvm,  ANGLE_PERSPECTIVE,  ((GLfloat) width) /((GLfloat) height), 1.0,  1400.0);			
		
	    break;
	}
}

GLvoid rglSetProjectionFFP( GLint width, GLint height, GLint projection )
{
	rglMat4 pvm;	
	switch (projection)
		{
				case RGL_PROJECTION_ORTHO :
					
				   
					glMatrixMode( GL_PROJECTION );
					glLoadIdentity();
					//glOrtho(0.0,(GLfloat) width, 0.0, (GLfloat) height, -1.0, 20.0);
					rglMatrix4Identity(pvm);
					rglOrtho(pvm, 0.0,width, 0.0, height, 1.0, -10.0);	
					glLoadMatrixf(pvm);
					glMatrixMode( GL_MODELVIEW );
					glLoadIdentity();
					
				break;
				case RGL_PROJECTION_PERSPECTIVE :
					
					
					glMatrixMode(GL_PROJECTION);
					glLoadIdentity();
					//gluPerspective(ANGLE_PERSPECTIVE, ((GLfloat) width) /((GLfloat) height) , 1.0, 10000.0);		
					rglMatrix4Identity(pvm);
					rglPerspective(pvm,  ANGLE_PERSPECTIVE,  ((GLfloat) width) /((GLfloat) height), 1.0,  1400.0);
					glLoadMatrixf(pvm);
					glMatrixMode(GL_MODELVIEW);
					glLoadIdentity();	
								
				break;
		}
	
}

GLvoid rglReshape(GLint width, GLint height, GLint projection,rglMat4 pvm)
{
	
	if (height == 0)
		height = 1;
	glViewport( 0, 0, width, height );
	rglSetProjection(width, height, projection, pvm);
	
}

GLvoid rglReshapeFFP(GLint width, GLint height, GLint projection)
{
	
	if (height == 0)
		height = 1;
	glViewport( 0, 0, width, height );
	rglSetProjectionFFP(width, height, projection);
	
}


void rglDrawIMM(rglVertex *data,  GLenum face_type, GLuint count, GLuint rglDrawMode)
{
	
		glBegin( face_type);
			for (GLuint i=0; i<=count; i++)
		{
		
	 		switch (rglDrawMode )
			{
				case RGL_VERT_COLOR :
					glColor4fv(&data[i].color.r);glVertex3fv(&data[i].position.x);
				;break;
				case RGL_VERT_COLOR_NORM :
					glNormal3fv(&data[i].normal.x); glColor4fv(&data[i].color.r);glVertex3fv(&data[i].position.x);
				;break;
				case RGL_VERT_COLOR_NORM_TEX :
					glNormal3fv(&data[i].normal.x);glTexCoord2fv(&data[i].texcoord.s); glColor4fv(&data[i].color.r);glVertex3fv(&data[i].position.x);
				;break;				
			}	
		}	
		 glEnd();		
			 
}



GLuint rglBufferInfo(GLuint buffer,GLenum target, GLchar *str)
{
	GLint nBufferSize;
	GLint nBufferUsage, nBufferAccess;
	if (glIsBuffer(buffer)==GL_TRUE)
		{
			printf("Buffer %s  is TRUE\n",str);
			glGetBufferParameteriv(target,GL_BUFFER_SIZE,&nBufferSize);
			printf("Buffer %s  size : %i\n",str, nBufferSize);
			glGetBufferParameteriv(target,GL_BUFFER_USAGE,&nBufferUsage);
			switch (nBufferUsage )
			{
				case GL_STREAM_DRAW: 
					printf("Buffer %s  usage : GL_STREAM_DRAW\n",str);
				break;
				case GL_STREAM_READ:
					printf("Buffer %s  usage : GL_STREAM_READ\n",str);
				break;
				case GL_STREAM_COPY:  
					printf("Buffer %s  usage : GL_STREAM_COPY\n",str);
				break;
				case GL_STATIC_DRAW:  
					printf("Buffer %s  usage : GL_STATIC_DRAW\n",str);
				break;
				case GL_STATIC_READ:
					printf("Buffer %s  usage : GL_STATIC_READ\n",str);
				break;
				case GL_STATIC_COPY:
					printf("Buffer %s  usage : GL_STATIC_COPY\n",str);
				break;
				case GL_DYNAMIC_DRAW:
					printf("Buffer %s  usage : GL_DYNAMIC_DRAW\n",str);
				break;
				case GL_DYNAMIC_READ:
					printf("Buffer %s  usage : GL_DYNAMIC_READ\n",str);
				break;
				case GL_DYNAMIC_COPY:
					printf("Buffer %s  usage : GL_DYNAMIC_COPY\n",str);
				break;
			}
			glGetBufferParameteriv(target,GL_BUFFER_ACCESS,&nBufferAccess);
			switch (nBufferAccess )
			{
				case GL_READ_ONLY: 
					printf("Buffer %s  access : GL_READ_ONLY\n",str);
				break;
				case GL_WRITE_ONLY:
					printf("Buffer %s  access : GL_WRITE_ONLY\n",str);
				break;
				case GL_READ_WRITE:  
					printf("Buffer %s  access : GL_READ_WRITE\n",str);
				break;
				case GL_STATIC_DRAW:  
					printf("Buffer %s  usage : GL_STATIC_DRAW\n",str);
				break;			
			}
		}
	 else
		 {
			printf("Buffer %s  is FALSE",str); 
		 }
	return 1;
	}

//--++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

GLuint rglInitDL(rglVertex *data,  GLenum face_type, GLuint count, GLuint rglDrawMode)
{
	
	GLuint DLid=glGenLists(1);	
	 glNewList(DLid, GL_COMPILE);
		 rglDrawIMM(data,  face_type, count, rglDrawMode);
	 glEndList();
	return  DLid;
	
	}


GLuint rglInitVBO(rglVertex *data,  GLuint count)
{
	GLenum target=GL_ARRAY_BUFFER;
	GLuint vboID;	
	glGenBuffers(1, &vboID);	
	glBindBuffer(target, vboID);	
	glBufferData(target, count*sizeof(rglVertex), data, GL_STATIC_DRAW);	
	rglBufferInfo(vboID,target, "vboID");	
	return   vboID;
	glBindBuffer(target, 0);
	}

GLuint rglInitIBO(GLuint *data,GLuint count)
{
	GLenum target=GL_ELEMENT_ARRAY_BUFFER;
	GLuint iboID;	
	glGenBuffers(1, &iboID);	
	glBindBuffer(target, iboID);	
	glBufferData(target, count*sizeof(GLuint), data, GL_STATIC_DRAW);
	 rglBufferInfo(iboID,target, "iboID");	
	return  iboID;
	glBindBuffer(target, 0);
	}

GLuint *rglInitVAO()
{
	GLuint vaoID=0;
	return (GLuint *) vaoID;
	}

//--+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


rglRenderObject *rglInitRenderObjectVA( rglMesh *mesh)
{
	rglRenderObject *obj_temp=(rglRenderObject *)malloc(sizeof(rglRenderObject));
	
	obj_temp->mesh=mesh;	
	obj_temp->vbo=0;	
	obj_temp->ibo=0;
	obj_temp->dl=0;
	return obj_temp;
	free(obj_temp);
	}

rglRenderObject *rglInitRenderObjectDL( rglMesh *mesh, GLuint rglDrawMode)
{
	rglRenderObject *obj_temp=(rglRenderObject *)malloc(sizeof(rglRenderObject));
	
	obj_temp->mesh=mesh;	
	obj_temp->vbo=0;	
	obj_temp->ibo=0;
	obj_temp->dl= rglInitDL(obj_temp->mesh->vertices,  obj_temp->mesh->face_type, obj_temp->mesh->count, rglDrawMode);
	return obj_temp;
	free(obj_temp);
	}

rglRenderObject *rglInitRenderObjectVBO( rglMesh *mesh)
{
	rglRenderObject *obj_temp=(rglRenderObject *)malloc(sizeof(rglRenderObject));
	
	obj_temp->mesh=mesh;
	obj_temp->vbo=rglInitVBO(obj_temp->mesh->vertices,obj_temp->mesh->count);
	obj_temp->ibo=0;
	obj_temp->dl=0;
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	return obj_temp;	
	free(obj_temp);
	}
	
rglRenderObject *rglInitRenderObjectIBO( rglMesh *mesh)
{
	rglRenderObject *obj_temp=(rglRenderObject *)malloc(sizeof(rglRenderObject));
	
	obj_temp->mesh=mesh;	
	obj_temp->vbo=rglInitVBO(obj_temp->mesh->vertices,obj_temp->mesh->count);	
	obj_temp->ibo=rglInitIBO(obj_temp->mesh->indices, obj_temp->mesh->count );
	obj_temp->dl=0;
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	return obj_temp;	
	free(obj_temp);
	}
	
rglRenderObject *rglInitRenderObjectVAO( rglMesh *mesh, GLuint *vboID, GLuint *iboID, GLuint *vaoID)
{
	rglRenderObject	*obj_temp=(rglRenderObject *)malloc(sizeof(rglRenderObject));
	return obj_temp;
	free(obj_temp); 
	}

rglRenderObject *rglInitRenderObjectALL( rglMesh *mesh, GLuint rglDrawMode)
{
	rglRenderObject *obj_temp=(rglRenderObject *)malloc(sizeof(rglRenderObject));
	
	obj_temp->mesh=mesh;
	
	obj_temp->vbo=rglInitVBO(obj_temp->mesh->vertices,obj_temp->mesh->count);
	obj_temp->ibo=rglInitIBO(obj_temp->mesh->indices, obj_temp->mesh->count );
	obj_temp->dl= rglInitDL(obj_temp->mesh->vertices,  obj_temp->mesh->face_type, obj_temp->mesh->count, rglDrawMode);
	
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	return obj_temp;
	
	free(obj_temp);
	}


//--+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


 void rglDrawObjectIMM(rglRenderObject *object, GLuint rglDrawMode)
{
	rglDrawIMM(object->mesh->vertices,  object->mesh->face_type, object->mesh->count, rglDrawMode);		 
			 
}

 void rglDrawObjectDL(rglRenderObject *object)
{
	glCallList(object->dl);		 
			 
}

void rglDrawObjectVBO(rglRenderObject *object, GLuint rglDrawMode)
{
	
glBindBuffer(GL_ARRAY_BUFFER, (GLuint) object->vbo);

	switch (rglDrawMode )
	{
	    case RGL_VERT_COLOR :
			glEnableClientState(GL_COLOR_ARRAY);
			glEnableClientState(GL_VERTEX_ARRAY);
			
					
			glColorPointer(4, GL_FLOAT, sizeof(rglVertex), (GLuint *) (sizeof(GLfloat)*4));
			glVertexPointer(4, GL_FLOAT, sizeof(rglVertex), NULL);	
			
			glDrawArrays(object->mesh->face_type, 0, object->mesh->count);
			
			glDisableClientState(GL_VERTEX_ARRAY);  
 		    glDisableClientState(GL_COLOR_ARRAY);
		;break;
		case RGL_VERT_COLOR_NORM :
			
			glEnableClientState(GL_COLOR_ARRAY);
			glEnableClientState(GL_NORMAL_ARRAY);
			glEnableClientState(GL_VERTEX_ARRAY);
			
			
			glColorPointer(4, GL_FLOAT, sizeof(rglVertex), (GLuint *) (4*sizeof(GLfloat)));
			glNormalPointer(GL_FLOAT, sizeof(rglVertex),  (GLuint *) (8*sizeof(GLfloat)));
			glVertexPointer(4, GL_FLOAT, sizeof(rglVertex), NULL);
		//	printf("rglDrawVBO ---------Point 2\n");
			glDrawArrays(object->mesh->face_type, 0, object->mesh->count);
		//	printf("rglDrawVBO ---------Point 2\n");
			glDisableClientState(GL_VERTEX_ARRAY);  
 		    glDisableClientState(GL_COLOR_ARRAY);
			glDisableClientState(GL_NORMAL_ARRAY);
		;break;
		case RGL_VERT_COLOR_NORM_TEX :
			
			glEnableClientState(GL_COLOR_ARRAY);
			glEnableClientState(GL_NORMAL_ARRAY);
			glEnableClientState(GL_TEXTURE_COORD_ARRAY);
			glEnableClientState(GL_VERTEX_ARRAY);
			
			
			glColorPointer(4, GL_FLOAT, sizeof(rglVertex), (GLuint *)  (4*sizeof(GLfloat)));
			glNormalPointer(GL_FLOAT, sizeof(rglVertex),   (GLuint *) (8*sizeof(GLfloat)));
			glTexCoordPointer(2, GL_FLOAT,  sizeof(rglVertex),   (GLuint *) (11*sizeof(GLfloat)));
			glVertexPointer(4, GL_FLOAT, sizeof(rglVertex), NULL);
			//	printf("rglDrawVBO ---------Point 2\n");
			glDrawArrays(object->mesh->face_type, 0, object->mesh->count);
			//	printf("rglDrawVBO ---------Point 2\n");
			glDisableClientState(GL_VERTEX_ARRAY);  
 		    glDisableClientState(GL_COLOR_ARRAY);
			glDisableClientState(GL_NORMAL_ARRAY);
			glDisableClientState(GL_TEXTURE_COORD_ARRAY );		
		;break;				
	}	
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	
}

void rglDrawObjectIBO(rglRenderObject *object, GLuint rglDrawMode)
{
	glBindBuffer(GL_ARRAY_BUFFER, object->vbo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, object->ibo);
	switch (rglDrawMode )
	{
	    case RGL_VERT_COLOR :
			glEnableClientState(GL_VERTEX_ARRAY);
			glEnableClientState(GL_COLOR_ARRAY);
			
			glVertexPointer(4, GL_FLOAT, sizeof(rglVertex), NULL);			
			glColorPointer(4, GL_FLOAT, sizeof(rglVertex), (GLuint *) (sizeof(GLfloat)*4));
			
			glDrawElements(object->mesh->face_type, object->mesh->count, GL_UNSIGNED_INT,0);
			
			glDisableClientState(GL_VERTEX_ARRAY);  
 		    glDisableClientState(GL_COLOR_ARRAY);
		;break;
		case RGL_VERT_COLOR_NORM :
			glEnableClientState(GL_VERTEX_ARRAY);
			glEnableClientState(GL_COLOR_ARRAY);
			glEnableClientState(GL_NORMAL_ARRAY);
			
			glVertexPointer(4, GL_FLOAT, sizeof(rglVertex), NULL);
			glColorPointer(4, GL_FLOAT, sizeof(rglVertex), (GLuint *) (4*sizeof(GLfloat)));
			glNormalPointer(GL_FLOAT, sizeof(rglVertex),  (GLuint *) (8*sizeof(GLfloat)));
		
			glDrawElements(object->mesh->face_type, object->mesh->count, GL_UNSIGNED_INT,0);
		
			glDisableClientState(GL_VERTEX_ARRAY);  
 		    glDisableClientState(GL_COLOR_ARRAY);
			glDisableClientState(GL_NORMAL_ARRAY);
		;break;
		case RGL_VERT_COLOR_NORM_TEX :
			glEnableClientState(GL_VERTEX_ARRAY);
			glEnableClientState(GL_COLOR_ARRAY);
			glEnableClientState(GL_NORMAL_ARRAY);
			glEnableClientState(GL_TEXTURE_COORD_ARRAY);
			
			glVertexPointer(4, GL_FLOAT, sizeof(rglVertex), NULL);
			glColorPointer(4, GL_FLOAT, sizeof(rglVertex), (GLuint *)  (4*sizeof(GLfloat)));
			glNormalPointer(GL_FLOAT, sizeof(rglVertex),   (GLuint *) (8*sizeof(GLfloat)));
			glTexCoordPointer(2, GL_FLOAT,  sizeof(rglVertex),   (GLuint *) (11*sizeof(GLfloat)));
			
			glDrawElements(object->mesh->face_type, object->mesh->count, GL_UNSIGNED_INT,0);
			
			glDisableClientState(GL_VERTEX_ARRAY);  
 		    glDisableClientState(GL_COLOR_ARRAY);
			glDisableClientState(GL_NORMAL_ARRAY);
			glDisableClientState(GL_TEXTURE_COORD_ARRAY );		
		;break;				
	}	
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

void rglDrawObjectVAO(rglRenderObject *object)
{
	}
	
 void rglDrawObjectVA(rglRenderObject *object, GLuint rglDrawMode)
{
	
	switch (rglDrawMode )
	{
	    case RGL_VERT_COLOR :
			glEnableClientState(GL_VERTEX_ARRAY);
			glEnableClientState(GL_COLOR_ARRAY);
			
			glColorPointer(4, GL_FLOAT, sizeof(rglVertex),    &object->mesh->vertices[0].color.r);
			glVertexPointer(4, GL_FLOAT, sizeof(rglVertex),    &object->mesh->vertices[0].position.x);
			
			glDrawArrays(object->mesh->face_type, 0, object->mesh->count);
			
			glDisableClientState(GL_VERTEX_ARRAY);  
 		    glDisableClientState(GL_COLOR_ARRAY);
		;break;
		case RGL_VERT_COLOR_NORM :
			glEnableClientState(GL_VERTEX_ARRAY);
			glEnableClientState(GL_COLOR_ARRAY);
			glEnableClientState(GL_NORMAL_ARRAY);
			
			glColorPointer(4, GL_FLOAT,sizeof(rglVertex),    &object->mesh->vertices[0].color.r);
			glNormalPointer(GL_FLOAT, sizeof(rglVertex),   &object->mesh->vertices[0].normal.x);
			glVertexPointer(4, GL_FLOAT, sizeof(rglVertex),    &object->mesh->vertices[0].position.x);
			
			glDrawArrays(object->mesh->face_type, 0,object-> mesh->count);
			
			glDisableClientState(GL_VERTEX_ARRAY);  
 		    glDisableClientState(GL_COLOR_ARRAY);
			glDisableClientState(GL_NORMAL_ARRAY);
		;break;
		case RGL_VERT_COLOR_NORM_TEX :
			glEnableClientState(GL_VERTEX_ARRAY);
			glEnableClientState(GL_COLOR_ARRAY);
			glEnableClientState(GL_NORMAL_ARRAY);
			glEnableClientState(GL_TEXTURE_COORD_ARRAY);
			
			
			glColorPointer(4, GL_FLOAT, sizeof(rglVertex),    &object->mesh->vertices[0].color.r);
			glNormalPointer(GL_FLOAT, sizeof(rglVertex),   &object->mesh->vertices[0].normal.x);
			glTexCoordPointer(2, GL_FLOAT, sizeof(rglVertex),   &object->mesh->vertices[0].texcoord.s);
			glVertexPointer(4, GL_FLOAT, sizeof(rglVertex),    &object->mesh->vertices[0].position.x);
			
			glDrawArrays(object->mesh->face_type, 0, object->mesh->count);
			
			glDisableClientState(GL_VERTEX_ARRAY);  
 		    glDisableClientState(GL_COLOR_ARRAY);
			glDisableClientState(GL_NORMAL_ARRAY);
			glDisableClientState(GL_TEXTURE_COORD_ARRAY );		
		;break;				
	}	
}

void rglDrawObjectVAE(rglRenderObject *object, GLuint rglDrawMode)
{
	//glBindBuffer(GL_ARRAY_BUFFER, 0);
	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	switch (rglDrawMode )
	{
	    case RGL_VERT_COLOR :
			glEnableClientState(GL_VERTEX_ARRAY);
			glEnableClientState(GL_COLOR_ARRAY);
			
			glColorPointer(4, GL_FLOAT, sizeof(rglVertex),    &object->mesh->vertices[0].color.r);
			glVertexPointer(4, GL_FLOAT, sizeof(rglVertex),    &object->mesh->vertices[0].position.x);
			
			glDrawElements(object->mesh->face_type, object->mesh->count, GL_UNSIGNED_INT, &object->mesh->indices[0]);
			
			glDisableClientState(GL_VERTEX_ARRAY);  
 		    glDisableClientState(GL_COLOR_ARRAY);
		;break;
		case RGL_VERT_COLOR_NORM :
			glEnableClientState(GL_VERTEX_ARRAY);
			glEnableClientState(GL_COLOR_ARRAY);
			glEnableClientState(GL_NORMAL_ARRAY);
		
			glColorPointer(4, GL_FLOAT, sizeof(rglVertex),    &object->mesh->vertices[0].color.r);
			glNormalPointer(GL_FLOAT, sizeof(rglVertex),   &object->mesh->vertices[0].normal.x);
				glVertexPointer(4, GL_FLOAT, sizeof(rglVertex),    &object->mesh->vertices[0].position.x);
			
			glDrawElements(object->mesh->face_type, object->mesh->count, GL_UNSIGNED_INT, &object->mesh->indices[0]);
			
			glDisableClientState(GL_VERTEX_ARRAY);  
 		    glDisableClientState(GL_COLOR_ARRAY);
			glDisableClientState(GL_NORMAL_ARRAY);
		;break;
		case RGL_VERT_COLOR_NORM_TEX :
			glEnableClientState(GL_VERTEX_ARRAY);
			glEnableClientState(GL_COLOR_ARRAY);
			glEnableClientState(GL_NORMAL_ARRAY);
			glEnableClientState(GL_TEXTURE_COORD_ARRAY);
			
			
			glColorPointer(4, GL_FLOAT, sizeof(rglVertex),    &object->mesh->vertices[0].color.r);
			glNormalPointer(GL_FLOAT, sizeof(rglVertex),   &object->mesh->vertices[0].normal.x);
			glTexCoordPointer(2, GL_FLOAT, sizeof(rglVertex),   &object->mesh->vertices[0].texcoord.s);
			glVertexPointer(4, GL_FLOAT, sizeof(rglVertex),    &object->mesh->vertices[0].position.x);
			
			glDrawElements(object->mesh->face_type, object->mesh->count, GL_UNSIGNED_INT, &object->mesh->indices[0]);
			
			glDisableClientState(GL_VERTEX_ARRAY);  
 		    glDisableClientState(GL_COLOR_ARRAY);
			glDisableClientState(GL_NORMAL_ARRAY);
			glDisableClientState(GL_TEXTURE_COORD_ARRAY );		
		;break;				
	}	
	
	
	}

void rglFreeRenderObject( rglRenderObject *obj)
{
	rglFreeMesh(obj->mesh);
	
	if ( glIsBuffer (obj->vbo))
	{
		
		glDeleteBuffers(1, &obj->vbo);
		
	}
	
	if ( glIsBuffer (obj->ibo))
	{
		glDeleteBuffers(1,&obj->ibo);
		
	}
	if ( glIsList (obj->dl))
	{
		glDeleteLists(obj->dl,1);
		
	}
	if (obj != NULL)
	{
		free(obj);
		
	}
	
	}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glew.h>
#include "rglMesh3D.h"
#include "rglFigures.h"
#include "rglShader.h"









	
	
void rglDisk_Draw(GLfloat m, GLfloat a_x, GLfloat r2, GLfloat r1)
{
GLfloat x,y,z,n,delta,a;
GLint i,j;
i=0;
j=0;
n=16;
y=0;
delta=a_x/m;
	
glBegin(GL_TRIANGLE_STRIP);
	  
 for (a=0.0; a<=a_x+delta; a+=delta)
		{  
          x=r2*cos(a);
		  y=0;
		  z=r2*sin(a);
		  glTexCoord2f(x/r2,z/r2);
		 glNormal3f(0, 1, 0);
		  glVertex3f(x, y, z);
		  glColor3ub(255,255,255);
		  		
		  x=r1*cos(a+delta);
		  y=0;
		  z=r1*sin(a+delta);
		     glTexCoord2f(x/r2,z/r2);
			glNormal3f(0, 1, 0);
		  glVertex3f(x, y, z);
		  glColor3ub(255,255,255);
				
   }
 
glEnd();	
      
}
// Процедура Трубка ( число n, число m, высота трубки, радиус трубки, угол)
void rglTube_Draw(GLfloat n, GLfloat m, GLfloat h, GLfloat R, GLfloat angle)
{
GLfloat x,y,z,a,deltau,deltah,h1,h2,deltaalfa,ds,dt,s,t;
GLfloat j,i, nx,ny,nz;
i=0;
j=0;
h1=0;
h2=0;
s=0.0;
t=0.0;
ds=1.0/(GLfloat) n;
dt=1.0/(GLfloat) m;
deltah=(GLfloat) h/ (GLfloat) m;
deltaalfa=angle/(GLfloat) n;

deltau=2*M_PI/n;

for (i=0; i<=m-1; i++)
	{
		
		h1=h2;
		h2=h1+deltah;
		glBegin(GL_TRIANGLE_STRIP);
	for (a=0.0; a<=angle+deltaalfa; a+=deltaalfa)
			{
			nx=cos(a);
			nz=sin(a);
			ny=(GLfloat) h1/	(GLfloat) h;
			x=R*cos(a);
			y=h1;
			z=R*sin(a);
			glColor3ub(255,255,255);
			glTexCoord2f(s,t);
			glNormal3f(nx, ny, nz); 
			glVertex3f(x, y, z);
			
			
			nx=cos(a);
			nz=sin(a);
			ny=(GLfloat) h2/	(GLfloat) h;
			x=R*cos(a);
			y=h2;
			z=R*sin(a);
			glColor3ub(255,255,255);
			glTexCoord2f(s,t+dt);
			glNormal3f(nx, ny, nz); 
			glVertex3f(x, y, z);
			
			s+=ds;
			
		}
		s=0.0;
		t+=dt;
	glEnd();
	}

	


}
//Процедура Шара ( Радиус, число n, Угол вертикальной плоскости, угол горизонтальной плоскости)
void rglSphere_Draw(GLfloat r, GLfloat n, GLfloat phi3, GLfloat theta3)
{
	
	
	
   	GLfloat deltatheta,deltaPhi,phi,theta1,x,y,z,s,t,ds,dt;
	deltatheta=theta3/n;
	deltaPhi=phi3/n;
	s=0.0;
	t=1.0;
	ds=1.0/(float)n;
	dt=1.0/(float)n;
	glColor3ub(255,255,255);
	glBegin(GL_TRIANGLE_STRIP);
	
	for (phi=0.0;phi<=phi3-deltaPhi;phi+=deltaPhi) 
	{
		 
		for(theta1=0.0;theta1 <= theta3;theta1+=deltatheta)
		{
			
	  x=r*sin(phi)*cos(theta1);
	  z=r*sin(phi)*sin(theta1);
	  y=r*cos(phi);
	  glTexCoord2f(s,t);
	  glNormal3f(x/r, y/r, z/r);
	  glVertex3f(x, y, z);
	//  printf("s=%5.2f ,t=%5.2f\n",s,t);
	  x=r*sin(phi+deltaPhi)*cos(theta1);
	  z=r*sin(phi+deltaPhi)*sin(theta1);
	  y=r*cos(phi+deltaPhi);
	  glTexCoord2f(s,t-dt);
	  glNormal3f(x/r, y/r, z/r);
	  glVertex3f(x, y, z); 
	 // printf("s=%5.2f ,t=%5.2f\n",s+ds,t);
	  
	 s+=ds;
        }  
		s=0.0;
		t-=dt;
	
	}
   glEnd(); 	
}
//процедура Торус(R-большой радиус,r-маленький радиус, число n, число m, theta-угол тета , phi-угол фи)	
void rglTorus_Draw(GLfloat R, GLfloat r, GLint n, GLint m, GLfloat theta_x, GLfloat phi_x ) 
{
GLfloat x,y,z,deltav,deltau,nx,ny,nz,theta,phi,s,t,ds,dt;
GLint j;



j=0;
s=0.0;
t=1.0;
ds=1.0/m;
dt=1.0/n;
deltau=theta_x/m;
deltav=phi_x/n;

glColor3ub(255,255,255);

	//  glBegin(GL_TRIANGLE_STRIP);

 for (phi=0.0;phi<=phi_x;phi+=deltav)
		{  
 glBegin(GL_TRIANGLE_STRIP);
			for (theta=0.0;theta <= theta_x+deltau;theta+=deltau)
			{
			
			
			x=(R+r*cos(phi))*cos(theta);
			z=(R+r*cos(phi))*sin(theta);
			y=r*sin(phi);
			
			nx=cos(phi)*cos(theta);
			nz=cos(phi)*sin(theta);
			ny=sin(phi);
			glTexCoord2f(s,t);
			glNormal3f(nx, ny, nz);
			glVertex3f(x, y, z);
				
			x=(R+r*cos(phi+deltav))*cos(theta);
			z=(R+r*cos(phi+deltav))*sin(theta);
			y=r*sin(phi+deltav);
			
		    nx=cos(phi+deltav)*cos(theta);
			nz=cos(phi+deltav)*sin(theta);
			ny=sin(phi+deltav);
			glTexCoord2f(s,t-dt);
			glNormal3f(nx, ny, nz);
			glVertex3f(x, y, z);
			
			s+=ds;	
			}
			s=0.0;
			t-=dt;
			 glEnd();	 			
		}
  

}
//процедура Цилиндр( число "Эн", число "Эм", Высота цилиндра, Радиус Цилиндра, угол)		
void rglCylinder_Draw(rglMat4 mvm, GLfloat n, GLfloat m, GLfloat h, GLfloat R, GLfloat angle,GLuint tex, GLuint shader )
{
	rglMat4 mvm_c;
	rglMat4 mvm_work;
	
	rglSetMaterial(3);
	glBindTexture(GL_TEXTURE_2D, tex);
	rglTube_Draw(n,m,h,R,angle);
	
	
	
	rglMatrix4Identity(mvm_c);
	rglMatrix4Copy(mvm_work,mvm);
	rglRotate(mvm_c,180.0,1.0,0.0,0.0);
	rglMatrix4Multiply(mvm_work,mvm_c);
	rglPushMatrix(mvm_work,shader);
	rglDisk_Draw(n,angle,R,0);	


	rglMatrix4Identity(mvm_c);
	rglMatrix4Copy(mvm_work,mvm);
	rglTranslate(mvm_c,0.0,h,0.0);	
	rglMatrix4Multiply(mvm_work,mvm_c);
	rglPushMatrix(mvm_work,shader);
	rglDisk_Draw(n,angle,R,0);	

}
//Процедура Хеликс(Спираль) (Большой радиус, число n , число m, угол горизонтальной плоскости, угол вертикальной плоскости, Длина спирали, количество повторов)
void rglSpiral_Draw(GLfloat R, GLfloat r, GLint n, GLint m, GLfloat theta_x, GLfloat phi_x, GLfloat h, GLfloat CYCLES)
{
GLfloat x,y,z,deltatheta,deltaphi,deltah,nx,ny,nz,theta,phi,s,t,ds,dt;

s=0.0;
t=1.0;
ds=1.0/n;
dt=1.0/m;
deltatheta=theta_x/n;
deltaphi=phi_x/m;
deltah=h/n;

glColor3ub(255,255,255);
	  
  for (phi=0.0;phi<=phi_x;phi+=deltaphi)
		{  
            glBegin(GL_TRIANGLE_STRIP);
		 
			for (theta=0.0;theta <= theta_x*CYCLES+deltatheta;theta+=deltatheta)
			{
			
			x=(R+r*cos(phi))*cos(theta);
			z=(R+r*cos(phi))*sin(theta);
			y=r*sin(phi)+((theta/M_PI)*h);
			
			
			nx=cos(phi)*cos(theta);
			nz=cos(phi)*sin(theta);
			ny=sin(phi);
			glTexCoord2f(s,t);
			glNormal3f(nx, ny, nz); 
			glVertex3f(x, y, z);
			
			x=(R+r*cos(phi+deltaphi))*cos(theta);
			z=(R+r*cos(phi+deltaphi))*sin(theta);
			y=r*sin(phi+deltaphi)+((theta/M_PI)*h);
			
			
			nx=cos(phi+deltaphi)*cos(theta);
			nz=cos(phi+deltaphi)*sin(theta);
			ny=sin(phi+deltaphi);
			glTexCoord2f(s,t-dt);
			glNormal3f(nx, ny, nz); 
		    glVertex3f(x, y, z);
	 		
			s+=ds;
			}
		
		s=0.0;
		t-=dt;
		 glEnd();
		
		}	
		
	
}



	

 
void rglCube_Draw(rglMat4 mvm,GLfloat size_x, GLfloat size_y, GLfloat size_z,GLuint face_tex,GLuint back_tex,GLuint up_tex, GLuint down_tex, GLuint right_tex, GLuint left_tex, GLuint shader)
{

glEnable(GL_LINE_SMOOTH);
////face
glBindTexture(GL_TEXTURE_2D,face_tex);
glBegin(GL_QUADS);
glNormal3f(0.0, 0.0, 1.0);
glColor3f(0.0,0.0,1.0);
glTexCoord2f(0.0,1.0);glVertex3f(-1.0*size_x,1.0*size_y,1.0*size_z);
glTexCoord2f(1.0,1.0);glVertex3f(1.0*size_x,1.0*size_y,1.0*size_z);
glTexCoord2f(1.0,0.0);glVertex3f(1.0*size_x,-1.0*size_y,1.0*size_z);
glTexCoord2f(0.0,0.0);glVertex3f(-1.0*size_x,-1.0*size_y,1.0*size_z);
glEnd();
////back
glBindTexture(GL_TEXTURE_2D,back_tex);
glBegin(GL_QUADS);
glNormal3f(0.0, 0.0, -1.0);
glColor3f(0.0,0.0,1.0);
glTexCoord2f(1.0,1.0);glVertex3f(1.0*size_x,1.0*size_y,-1.0*size_z);
glTexCoord2f(0.0,1.0);glVertex3f(-1.0*size_x,1.0*size_y,-1.0*size_z);
glTexCoord2f(0.0,0.0);glVertex3f(-1.0*size_x,-1.0*size_y,-1.0*size_z);
glTexCoord2f(1.0,0.0);glVertex3f(1.0*size_x,-1.0*size_y,-1.0*size_z);
glEnd();

/////up
glBindTexture(GL_TEXTURE_2D,up_tex);
glBegin(GL_QUADS);
glNormal3f(0, 1.0, 0);
glColor3f(0.0,0.0,1.0);
glTexCoord2f(0.0,1.0);glVertex3f(-1.0*size_x,1.0*size_y,-1.0*size_z);
glTexCoord2f(1.0,1.0);glVertex3f(1.0*size_x,1.0*size_y,-1.0*size_z);
glTexCoord2f(1.0,1.0);glVertex3f(1.0*size_x,1.0*size_y,1.0*size_z);
glTexCoord2f(0.0,1.0);glVertex3f(-1.0*size_x,1.0*size_y,1.0*size_z);
glEnd();

////////down
glBindTexture(GL_TEXTURE_2D,down_tex);
glBegin(GL_QUADS);
glNormal3f(0.0, -1.0, 0.0);
glColor3f(0.0,0.0,1.0);
glTexCoord2f(0.0,0.0);glVertex3f(-1.0*size_x,-1.0*size_y,1.0*size_z);
glTexCoord2f(1.0,0.0);glVertex3f(1.0*size_x,-1.0*size_y,1.0*size_z);
glTexCoord2f(1.0,0.0);glVertex3f(1.0*size_x,-1.0*size_y,-1.0*size_z);
glTexCoord2f(0.0,0.0);glVertex3f(-1.0*size_x,-1.0*size_y,-1.0*size_z);
glEnd();

/////right
glBindTexture(GL_TEXTURE_2D,right_tex);
glBegin(GL_QUADS);
glNormal3f(1.0, 0.0, 0.0);
glColor3f(0.0,0.0,1.0);
glTexCoord2f(1.0,1.0);glVertex3f(1.0*size_x,1.0*size_y,1.0*size_z);
glTexCoord2f(1.0,1.0);glVertex3f(1.0*size_x,1.0*size_y,-1.0*size_z);
glTexCoord2f(1.0,0.0);glVertex3f(1.0*size_x,-1.0*size_y,-1.0*size_z);
glTexCoord2f(1.0,0.0);glVertex3f(1.0*size_x,-1.0*size_y,1.0*size_z);
glEnd();

////left
glBindTexture(GL_TEXTURE_2D,left_tex);
glBegin(GL_QUADS);
glNormal3f(-1.0, 0.0, 0.0);
glColor3f(0.0,0.0,1.0);
glTexCoord2f(0.0,1.0);glVertex3f(-1.0*size_x,1.0*size_y,-1.0*size_z);
glTexCoord2f(0.0,1.0);glVertex3f(-1.0*size_x,1.0*size_y,1.0*size_z);
glTexCoord2f(0.0,0.0);glVertex3f(-1.0*size_x,-1.0*size_y,1.0*size_z);
glTexCoord2f(0.0,0.0);glVertex3f(-1.0*size_x,-1.0*size_y,-1.0*size_z);

glEnd();
}





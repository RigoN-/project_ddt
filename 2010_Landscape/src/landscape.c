#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
#include "loadtexture.h"

float anglex = 0.0;
float angley = 0.0;
float anglez = 0.0;
float tz = 0.0;
float divider = 100.0;
int i;
int size;
int a,b;
int sizer;

textureImage texture;
GLuint tex1;
textureImage height;
GLuint tex2;

GLfloat LightAmbient[]= { 0.5f, 0.5f, 0.5f, 1.0f };
GLfloat LightDiffuse[]= { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat LightPosition[]= { 0.0f, 0.0f, 2.0f, 1.0f };

void InitGL ( GLvoid )
{
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glShadeModel(GL_SMOOTH);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glEnable ( GL_TEXTURE_2D );
//	glEnable(GL_LIGHT0);
//	glEnable(GL_LIGHTING);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmbient);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiffuse);
	glLightfv(GL_LIGHT1, GL_POSITION,LightPosition);
}

void changeSize(int w, int h) {

	if(h == 0)
		h = 1;

	float ratio = 1.0* w / h;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

    glViewport(0, 0, w, h);

	gluPerspective(45,ratio,1,1000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0,0.0,5.0,
		      0.0,0.0,-1.0,
			  0.0f,1.0f,0.0f);


}

void LoadTexture ( void )
{
	LoadBMPHeightMap("heightmap.bmp",&height);
	LoadBMPTexture("texture.bmp",&texture);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glPixelStorei(GL_UNPACK_ALIGNMENT,1);
	glGenTextures(1, &tex1);
	glBindTexture(GL_TEXTURE_2D, tex1);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D,0,GL_RGB, height.width, height.height,0,GL_RGB,GL_UNSIGNED_BYTE,height.data);
	glTexImage2D(GL_TEXTURE_2D,0,GL_RGB, texture.width, texture.height,0,GL_RGB,GL_UNSIGNED_BYTE,texture.data);
}

void CreatePlane( )
{
if (height.height>height.width)
{
sizer=height.height/(height.height/height.width);
}
else if (height.height<height.width)
{
sizer=height.height*(height.width/height.height);
}
else if (height.height==height.width)
{
sizer=height.height;
}
	for (a=-height.height/2+1;a<height.height/2-1;a+=1)
	{
	glBegin(GL_TRIANGLE_STRIP);
	 for (b=-height.width/2+1;b<height.width/2-1;b+=1)
	{
		glNormal3f( 20.0f, 20.0f, 5.0f);
			glTexCoord2f((float)b/24,(float)a/24); glVertex3f(b,a,(float)height.data[((a+height.height/2)*sizer+(b+height.width/2))*3]/3);
			glTexCoord2f((float)b/24,(float)a/24); glVertex3f(b,a+1,(float)height.data[(((a+height.height/2)+1)*sizer+(b+height.width/2))*3]/3);
	}
	glEnd();
	}
};



void renderScene(void) 
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	glTranslatef( 0.0, -20.0, -200.0+tz );
	glRotatef(anglex,1.0,0.0,0.0);
	glRotatef(angley,0.0,1.0,0.0);
	glRotatef(anglez,0.0,0.0,1.0);
	glRotatef(-90,1.0,0.0,0.0);
	CreatePlane();
	glPopMatrix();
	glutSwapBuffers();
//if (divider>10.0){
//printf("%f \n",divider);
//divider-=0.1;};
//if (divider<=10.0){
//divider=10.0;}
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
  switch ( key ) {
    case 27:        // When Escape Is Pressed...
      exit ( 0 );   // Exit The Program
      break;        // Ready For Next Case
    default:        // Now Wrap It Up
      break;
  }
}

void kb_control ( int a_keys, int x, int y )
{
  switch ( a_keys ) {
    case GLUT_KEY_F1:
      tz+=1.5f;
      break;
    case GLUT_KEY_F2:
      tz-=1.5f;
      break;
    case GLUT_KEY_UP:
      anglex+=1.5f;
      break;
    case GLUT_KEY_DOWN:
      anglex-=1.5f;
      break;
    case GLUT_KEY_LEFT:
      angley+=1.5f;
      break;
    case GLUT_KEY_RIGHT:
      angley-=1.5f;
      break;
    default:
      break;

  }
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH |  GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(800,600);
	glutCreateWindow("Creating Landscape via HeightMap");
	InitGL ();
	LoadTexture();
	glutDisplayFunc(renderScene);
	glutIdleFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutKeyboardFunc    ( keyboard );
	glutSpecialFunc(kb_control);
	glutMainLoop();
}

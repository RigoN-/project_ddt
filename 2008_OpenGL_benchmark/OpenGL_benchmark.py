#! /usr/bin/python

if __name__ == '__build__':
	raise Exception

import string
__version__ = string.split('$Revision: 1.8 $')[1]
__date__ = string.join(string.split('$Date: 2008/03/12 21:14:55 $')[1:3], ' ')
__author__ = '133Mhz_aka_Purity <chernobyl13@gmail.com>'

from OpenGL.GL import *
from OpenGL.GLUT import *
from OpenGL.GLU import *
import sys
from Image import *

import glFreeType 

texture = []
texture_patch = "textures/"
ESCAPE = '\033'
window = 0
rtri = 0.0
main_timer = 0.0
DrawScene = 0
our_font = None
our_font2 = None
fps_count = 0.0

def LoadTextures(files_texture):
   	global texture,texture_w,texture_h,image
	count=0
	for file_name in files_texture:
		image = open(texture_patch+file_name)
		texture_w = image.size[0]
		texture_h = image.size[1]
		image = image.tostring("raw", "RGBX", 0, -1)		
		texture.append(glGenTextures(1))	
		glBindTexture(GL_TEXTURE_2D, texture[count])   
		glPixelStorei(GL_UNPACK_ALIGNMENT,1)
		glTexParameterf   ( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT )
	   	glTexParameterf   ( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT )
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR)
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_LINEAR)
		gluBuild2DMipmaps ( GL_TEXTURE_2D, 3,  texture_w, texture_h, GL_RGBA, GL_UNSIGNED_BYTE, image )		
		count+=1
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE)
	
#	Куб
def Cube():
	global texture, rtri
	glBindTexture(GL_TEXTURE_2D, texture[0])			
	glBegin(GL_QUADS)		
#1		
	glTexCoord2f(0.0, 0.0); glVertex3f(-1.0, -1.0,  1.0)
	glTexCoord2f(1.0, 0.0); glVertex3f( 1.0, -1.0,  1.0)
	glTexCoord2f(1.0, 1.0); glVertex3f( 1.0,  1.0,  1.0)
	glTexCoord2f(0.0, 1.0); glVertex3f(-1.0,  1.0,  1.0)
#2		
	glTexCoord2f(1.0, 0.0); glVertex3f(-1.0, -1.0, -1.0)
	glTexCoord2f(1.0, 1.0); glVertex3f(-1.0,  1.0, -1.0)
	glTexCoord2f(0.0, 1.0); glVertex3f( 1.0,  1.0, -1.0)
	glTexCoord2f(0.0, 0.0); glVertex3f( 1.0, -1.0, -1.0)
#3
	glTexCoord2f(0.0, 1.0); glVertex3f(-1.0,  1.0, -1.0)
	glTexCoord2f(0.0, 0.0); glVertex3f(-1.0,  1.0,  1.0)
	glTexCoord2f(1.0, 0.0); glVertex3f( 1.0,  1.0,  1.0)
	glTexCoord2f(1.0, 1.0); glVertex3f( 1.0,  1.0, -1.0)	
#4
	glTexCoord2f(1.0, 1.0); glVertex3f(-1.0, -1.0, -1.0)
	glTexCoord2f(0.0, 1.0); glVertex3f( 1.0, -1.0, -1.0)
	glTexCoord2f(0.0, 0.0); glVertex3f( 1.0, -1.0,  1.0)
	glTexCoord2f(1.0, 0.0); glVertex3f(-1.0, -1.0,  1.0)	
#5
	glTexCoord2f(1.0, 0.0); glVertex3f( 1.0, -1.0, -1.0)
	glTexCoord2f(1.0, 1.0); glVertex3f( 1.0,  1.0, -1.0)
	glTexCoord2f(0.0, 1.0); glVertex3f( 1.0,  1.0,  1.0)
	glTexCoord2f(0.0, 0.0); glVertex3f( 1.0, -1.0,  1.0)
#6
	glTexCoord2f(0.0, 0.0); glVertex3f(-1.0, -1.0, -1.0)
	glTexCoord2f(1.0, 0.0); glVertex3f(-1.0, -1.0,  1.0)
	glTexCoord2f(1.0, 1.0); glVertex3f(-1.0,  1.0,  1.0)
	glTexCoord2f(0.0, 1.0); glVertex3f(-1.0,  1.0, -1.0)
	glEnd()
	rtri = rtri + 0.1

def CubeBlend():
	global texture, rtri
	glBindTexture(GL_TEXTURE_2D, texture[3])			
	glBegin(GL_QUADS)		
#1		
	glTexCoord2f(0.0, 0.0); glVertex3f(-1.0, -1.0,  1.0)
	glTexCoord2f(1.0, 0.0); glVertex3f( 1.0, -1.0,  1.0)
	glTexCoord2f(1.0, 1.0); glVertex3f( 1.0,  1.0,  1.0)
	glTexCoord2f(0.0, 1.0); glVertex3f(-1.0,  1.0,  1.0)
#2		
	glTexCoord2f(1.0, 0.0); glVertex3f(-1.0, -1.0, -1.0)
	glTexCoord2f(1.0, 1.0); glVertex3f(-1.0,  1.0, -1.0)
	glTexCoord2f(0.0, 1.0); glVertex3f( 1.0,  1.0, -1.0)
	glTexCoord2f(0.0, 0.0); glVertex3f( 1.0, -1.0, -1.0)
#3
	glTexCoord2f(0.0, 1.0); glVertex3f(-1.0,  1.0, -1.0)
	glTexCoord2f(0.0, 0.0); glVertex3f(-1.0,  1.0,  1.0)
	glTexCoord2f(1.0, 0.0); glVertex3f( 1.0,  1.0,  1.0)
	glTexCoord2f(1.0, 1.0); glVertex3f( 1.0,  1.0, -1.0)	
#4
	glTexCoord2f(1.0, 1.0); glVertex3f(-1.0, -1.0, -1.0)
	glTexCoord2f(0.0, 1.0); glVertex3f( 1.0, -1.0, -1.0)
	glTexCoord2f(0.0, 0.0); glVertex3f( 1.0, -1.0,  1.0)
	glTexCoord2f(1.0, 0.0); glVertex3f(-1.0, -1.0,  1.0)	
#5
	glTexCoord2f(1.0, 0.0); glVertex3f( 1.0, -1.0, -1.0)
	glTexCoord2f(1.0, 1.0); glVertex3f( 1.0,  1.0, -1.0)
	glTexCoord2f(0.0, 1.0); glVertex3f( 1.0,  1.0,  1.0)
	glTexCoord2f(0.0, 0.0); glVertex3f( 1.0, -1.0,  1.0)
#6
	glTexCoord2f(0.0, 0.0); glVertex3f(-1.0, -1.0, -1.0)
	glTexCoord2f(1.0, 0.0); glVertex3f(-1.0, -1.0,  1.0)
	glTexCoord2f(1.0, 1.0); glVertex3f(-1.0,  1.0,  1.0)
	glTexCoord2f(0.0, 1.0); glVertex3f(-1.0,  1.0, -1.0)
	glEnd()
	rtri = rtri + 0.1	

	
#	Стены
def Room():
	global texture
	glBindTexture(GL_TEXTURE_2D, texture[1])			
	glBegin(GL_QUADS)
	#Left face
	glNormal3f( 1.0, 0.0, 0.0)
	glTexCoord2f(2.0, 0.0); glVertex3f( -20.0, -15.0, -34.0)
	glTexCoord2f(2.0, 2.0); glVertex3f( -20.0,  15.0, -34.0)
	glTexCoord2f(0.0, 2.0); glVertex3f( -20.0,  15.0,  34.0)
	glTexCoord2f(0.0, 0.0); glVertex3f( -20.0, -15.0,  34.0)
	#Back
	glNormal3f( 0.0, 0.0, 1.0)
	glTexCoord2f(0.0, 0.0); glVertex3f(-20.0, -15.0,  -34.0)
	glTexCoord2f(2.0, 0.0); glVertex3f( 20.0, -15.0,  -34.0)
	glTexCoord2f(2.0, 2.0); glVertex3f( 20.0,  15.0,  -34.0)
	glTexCoord2f(0.0, 2.0); glVertex3f(-20.0,  15.0,  -34.0)
	#Right
	glNormal3f(-1.0, 0.0, 0.0)
	glTexCoord2f(0.0, 0.0); glVertex3f( 20.0, -15.0, -34.0)
	glTexCoord2f(2.0, 0.0); glVertex3f( 20.0, -15.0,  34.0)
	glTexCoord2f(2.0, 2.0); glVertex3f( 20.0,  15.0,  34.0)
	glTexCoord2f(0.0, 2.0); glVertex3f( 20.0,  15.0, -34.0)
	glEnd()
	
# 	Пол и потолок
def Floor():
	global texture
	glBindTexture(GL_TEXTURE_2D, texture[2])	
	glBegin(GL_QUADS)
	#Floor
	glNormal3f( 0.0, 1.0, 0.0)
	glTexCoord2f(0.0, 1.0); glVertex3f(-20.0,  -15.0, -60.0)
	glTexCoord2f(0.0, 0.0); glVertex3f(-20.0,  -15.0,  60.0)
	glTexCoord2f(1.0, 0.0); glVertex3f( 20.0,  -15.0,  60.0)
	glTexCoord2f(1.0, 1.0); glVertex3f( 20.0,  -15.0, -60.0)
	#Roof
	glNormal3f( 0.0,-1.0, 0.0)
	glTexCoord2f(1.0, 1.0); glVertex3f(-20.0, 15.0, -60.0)
	glTexCoord2f(0.0, 1.0); glVertex3f( 20.0, 15.0, -60.0)
	glTexCoord2f(0.0, 0.0); glVertex3f( 20.0, 15.0,  60.0)
	glTexCoord2f(1.0, 0.0); glVertex3f(-20.0, 15.0,  60.0)
	glEnd()

def Wall(): 
	# 1
	Cube()
	#2
	glPushMatrix()
	glTranslatef(0.0, 2.5, 0.0)
	Cube()
	glPopMatrix()
	#3
	glPushMatrix()
	glTranslatef(0.0, -2.5, 0.0)
	Cube()
	glPopMatrix()
	#4
	glPushMatrix()
	glTranslatef(2.5, 0.0, 0.0)
	Cube()
	glPopMatrix()
	#5
	glPushMatrix()
	glTranslatef(-2.5, 0.0, 0.0)
	Cube()
	glPopMatrix()
	#6
	glPushMatrix()
	glTranslatef(-2.5, 2.5, 0.0)
	Cube()
	glPopMatrix()
	#7
	glPushMatrix()
	glTranslatef(2.5, 2.5, 0.0)
	Cube()
	glPopMatrix()
	#8
	glPushMatrix()
	glTranslatef(-2.5, -2.5, 0.0)
	Cube()
	glPopMatrix()
	#8
	glPushMatrix()
	glTranslatef(2.5, -2.5, 0.0)
	Cube()
	glPopMatrix()

def Cubert():
	# 1st wall
	Wall()
	#2nd wall	
	glPushMatrix()
	glTranslatef(0.0,0.0,-2.5)
	Wall()
	glPopMatrix()
	#3d wall
	glPushMatrix()
	glTranslatef(0.0,0.0,2.5)
	Wall()
	glPopMatrix()	
	
#	Инициализация		
def InitGL(Width, Height):
	global width,height,our_font,our_font2
	LoadTextures(("texture.jpg", "walls.jpg", "floor.jpg","blend.jpg"))
	glEnable(GL_TEXTURE_2D)
	glShadeModel(GL_SMOOTH)
	glDepthFunc(GL_LESS)
	glEnable(GL_DEPTH_TEST)
	glDepthFunc(GL_LEQUAL)
	glHint (GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST)	
	glClearColor(0.0, 0.0, 0.0, 0.0)
	glClearDepth(1.0)	
	glShadeModel(GL_SMOOTH) 
	glBlendFunc(GL_SRC_ALPHA,GL_ONE)
	our_font = glFreeType.font_data ("font.ttf", 50)
	our_font2 = glFreeType.font_data ("fonter.ttf", 25)
	return True
		
def ReSizeGLScene(Width, Height):
	global texture
	if Height ==0:
           Height ==1
	glViewport(0, 0, Width, Height)
	glMatrixMode(GL_PROJECTION)
	glLoadIdentity()
	gluPerspective(45.0, float(Width)/float(Height), 0.1, 100.0)
	glMatrixMode(GL_MODELVIEW)
	glLoadIdentity()
	
def DrawGLScene():
	global DrawScene
	global cnt1
	global our_font, our_font2
	global fps_count
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
	if DrawScene == 1:
		glTranslatef (0.0, 0.0, -1.0)
		glColor3f (-0.5, 1.0, 0.7)
		glPushMatrix ()
		glLoadIdentity ()
		our_font.glPrint (120, 240, "Loading:%3.0f%%"%((main_timer/100)*2))
		glPopMatrix ()
	elif DrawScene == 2:
		glTranslatef(0.0,0.0,-30.0)
		glRotatef(rtri,1.0,1.0,0.0)
		Cubert()
		glLoadIdentity()	
		glTranslatef(0.0, 0.0,-24)
		Floor()
		glLoadIdentity()	
		glTranslatef(0.0, 0.0,-50)	
		Room()
		glTranslatef (0.0, 0.0, -25.0)
		glColor3f (-0.5, 1.0, 0.7)
		glPushMatrix ()	
		glLoadIdentity ()
		our_font2.glPrint (20, 440, "Elapsed Time: %2.0f sec." % ((glutGet(GLUT_ELAPSED_TIME)/1000)*1))
		our_font2.glPrint (20, 410, "Rotate Speed: %0.2f " % ((rtri/100)*1))
		our_font2.glPrint (20, 380, "FPS: %3.0f " % ((fps_count*1000/glutGet(GLUT_ELAPSED_TIME))*1))
		glPopMatrix ()
	elif DrawScene == 3:
		glTranslatef (0.0, 0.0, -1.0)
		glColor3f (-0.5, 1.0, 0.7)
		glPushMatrix ()
		glLoadIdentity ()
		our_font2.glPrint (90, 240, "Loading Scene. Please Wait")
		glPopMatrix ()
	elif DrawScene == 4:
		glTranslatef(0.0,0.0,-10.0)
		glRotatef(rtri,0.0,1.0,1.0)
		glEnable(GL_BLEND)
		glColor4f(0.0, 0.0, 0.0, 0.3)
		CubeBlend()
		glLoadIdentity()
		glDisable(GL_BLEND)
		glTranslatef(0.0, 0.0,-24)
		Floor()
		glLoadIdentity()	
		glTranslatef(0.0, 0.0,-50)	
		Room()
		glTranslatef (0.0, 0.0, -25.0)
		glColor3f (-0.5, 1.0, 0.7)
		glPushMatrix ()	
		glLoadIdentity ()
		our_font2.glPrint (20, 440, "Elapsed Time: %2.0f sec." % ((glutGet(GLUT_ELAPSED_TIME)/1000)*1))
		our_font2.glPrint (20, 410, "Rotate Speed: %0.2f " % ((rtri/100)*1))
		our_font2.glPrint (20, 380, "FPS: %3.0f " % ((fps_count*1000/glutGet(GLUT_ELAPSED_TIME))*1))
		glPopMatrix ()
	elif DrawScene == 5:
		glTranslatef (0.0, 0.0, -1.0)
		glColor3f (-0.5, 1.0, 0.7)
		glPushMatrix ()
		glLoadIdentity ()
		our_font2.glPrint (150, 250, "Your Result: %3.0f " % ((fps_count)*1))
		our_font2.glPrint (150, 220, "Press ESC to exit")
		glPopMatrix ()
	if 0 < main_timer < 27000:
		fps_count = fps_count +1
	elif main_timer > 27000:
		fps_count
	glLoadIdentity()
	glutSwapBuffers()
	return
 
def keyPressed(*args):
	global window
	if args[0] == ESCAPE:
		sys.exit()
		our_font.release ()

def ogl_timer(number):
	global window, main_timer, DrawScene
	main_timer = main_timer + 10
	if 0 < main_timer < 4500:
		DrawScene = 1
	elif 5001 < main_timer < 15000:
		DrawScene = 2
	elif 15000< main_timer < 17000:
		DrawScene = 3
	elif 17000 < main_timer < 27000:
		DrawScene = 4
	elif main_timer > 27000:
		DrawScene = 5
	glutPostRedisplay()
	glutTimerFunc(10, ogl_timer, 0)	
		
def main():
	global window
	glutInit(sys.argv)
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_ALPHA | GLUT_DEPTH)		
	glutInitWindowSize(640, 480) 
	glutInitWindowPosition(0, 0)
	window = glutCreateWindow("OpenGL Benchmark")	
	glutDisplayFunc(DrawGLScene)
	glutTimerFunc(10, ogl_timer, 0)
	glutReshapeFunc(ReSizeGLScene)
	glutKeyboardFunc(keyPressed)
	InitGL(640, 480)
	glutMainLoop()

print "Hit ESC key to quit."
print "" 
print "Copyright by 133Mhz"
print "" 
print "This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version."
main()
		

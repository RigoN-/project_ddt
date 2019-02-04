

program Linux_3D_benchmark;

uses
SysUtils,GL,GLU,GLUT,LoadBmp ;


var
angle:real;
xt,yt,zt:real;


  CubeTexture : glUint;
  RoomTexture : glUint;
  LightTexture : glUint;
  FloorTexture : glUint;
  Scene_L_Texture : glUint;
  End_Texture : glUint;

  XLightpos : GLfloat;              
  YLightpos : GLfloat;  
 main_frame,Scene_L_frame: LongInt;
 Fps: GLfloat;        
  LightOn : boolean;  

  CubeDL : glUint;                   
  RoomDL : glUint;                  
  FloorDL : glUint; 
   

 const
prog_name='Linux 3D Benchmark';         
patch_texture='textures/';

procedure CreateCubeDisplayList;
begin
  CubeDL :=glGenLists(1);
  glNewList(CubeDL, GL_COMPILE);
    glBegin(GL_QUADS);
      // Front Face
      glTexCoord2f(0.0, 0.0); glVertex3f(-1.0, -1.0,  1.0);
      glTexCoord2f(1.0, 0.0); glVertex3f( 1.0, -1.0,  1.0);
      glTexCoord2f(1.0, 1.0); glVertex3f( 1.0,  1.0,  1.0);
      glTexCoord2f(0.0, 1.0); glVertex3f(-1.0,  1.0,  1.0);
      // Back Face
      glTexCoord2f(1.0, 0.0); glVertex3f(-1.0, -1.0, -1.0);
      glTexCoord2f(1.0, 1.0); glVertex3f(-1.0,  1.0, -1.0);
      glTexCoord2f(0.0, 1.0); glVertex3f( 1.0,  1.0, -1.0);
      glTexCoord2f(0.0, 0.0); glVertex3f( 1.0, -1.0, -1.0);
      // Top Face
      glTexCoord2f(0.0, 1.0); glVertex3f(-1.0,  1.0, -1.0);
      glTexCoord2f(0.0, 0.0); glVertex3f(-1.0,  1.0,  1.0);
      glTexCoord2f(1.0, 0.0); glVertex3f( 1.0,  1.0,  1.0);
      glTexCoord2f(1.0, 1.0); glVertex3f( 1.0,  1.0, -1.0);
      // Bottom Face
      glTexCoord2f(1.0, 1.0); glVertex3f(-1.0, -1.0, -1.0);
      glTexCoord2f(0.0, 1.0); glVertex3f( 1.0, -1.0, -1.0);
      glTexCoord2f(0.0, 0.0); glVertex3f( 1.0, -1.0,  1.0);
      glTexCoord2f(1.0, 0.0); glVertex3f(-1.0, -1.0,  1.0);
      // Right face
      glTexCoord2f(1.0, 0.0); glVertex3f( 1.0, -1.0, -1.0);
      glTexCoord2f(1.0, 1.0); glVertex3f( 1.0,  1.0, -1.0);
      glTexCoord2f(0.0, 1.0); glVertex3f( 1.0,  1.0,  1.0);
      glTexCoord2f(0.0, 0.0); glVertex3f( 1.0, -1.0,  1.0);
      // Left Face
      glTexCoord2f(0.0, 0.0); glVertex3f(-1.0, -1.0, -1.0);
      glTexCoord2f(1.0, 0.0); glVertex3f(-1.0, -1.0,  1.0);
      glTexCoord2f(1.0, 1.0); glVertex3f(-1.0,  1.0,  1.0);
      glTexCoord2f(0.0, 1.0); glVertex3f(-1.0,  1.0, -1.0);
    glEnd();
  glEndList();
end;

procedure CreateRoomDisplayLists;
begin
  RoomDL :=glGenLists(1);
  glNewList(RoomDL, GL_COMPILE);
    glBegin(GL_QUADS);
      // Left face
      glNormal3f( 1.0, 0.0, 0.0);
      glTexCoord2f(2.0, 0.0); glVertex3f( -10.0, -10.0, -10.0);
      glTexCoord2f(2.0, 2.0); glVertex3f( -10.0,  10.0, -10.0);
      glTexCoord2f(0.0, 2.0); glVertex3f( -10.0,  10.0,  10.0);
      glTexCoord2f(0.0, 0.0); glVertex3f( -10.0, -10.0,  10.0);

      //Back
      glNormal3f( 0.0, 0.0, 1.0);
      glTexCoord2f(0.0, 0.0); glVertex3f(-10.0, -10.0,  -10.0);
      glTexCoord2f(2.0, 0.0); glVertex3f( 10.0, -10.0,  -10.0);
      glTexCoord2f(2.0, 2.0); glVertex3f( 10.0,  10.0,  -10.0);
      glTexCoord2f(0.0, 2.0); glVertex3f(-10.0,  10.0,  -10.0);

      // Right
      glNormal3f(-1.0, 0.0, 0.0);
      glTexCoord2f(0.0, 0.0); glVertex3f( 10.0, -10.0, -10.0);
      glTexCoord2f(2.0, 0.0); glVertex3f( 10.0, -10.0,  10.0);
      glTexCoord2f(2.0, 2.0); glVertex3f( 10.0,  10.0,  10.0);
      glTexCoord2f(0.0, 2.0); glVertex3f( 10.0,  10.0, -10.0);
    glEnd();
  glEndList();

  FloorDL :=glGenLists(1);
  glNewList(FloorDL, GL_COMPILE);
    glBegin(GL_QUADS);
      // Floor
      glNormal3f( 0.0, 1.0, 0.0);
      glTexCoord2f(0.0, 1.0); glVertex3f(-10.0,  -10.0, -10.0);
      glTexCoord2f(0.0, 0.0); glVertex3f(-10.0,  -10.0,  10.0);
      glTexCoord2f(1.0, 0.0); glVertex3f( 10.0,  -10.0,  10.0);
      glTexCoord2f(1.0, 1.0); glVertex3f( 10.0,  -10.0, -10.0);

      // Roof
      glNormal3f( 0.0,-1.0, 0.0);
      glTexCoord2f(1.0, 1.0); glVertex3f(-10.0, 10.0, -10.0);
      glTexCoord2f(0.0, 1.0); glVertex3f( 10.0, 10.0, -10.0);
      glTexCoord2f(0.0, 0.0); glVertex3f( 10.0, 10.0,  10.0);
      glTexCoord2f(1.0, 0.0); glVertex3f(-10.0, 10.0,  10.0);
    glEnd();
  glEndList();
end;

procedure OGL_Render_String(x:GLfloat;y:GLfloat;z:GLfloat;s:pchar);
var
i:integer;
begin
glRasterPos3f(x, y, z);
for i:=0 to strlen(s)-1 do
glutBitmapCharacter(GLUT_BITMAP_9_BY_15, smallint(s[i]));
end;

procedure OGL_init(width,height:longint);cdecl;
begin
glClearColor(0.0,0.0,0.0,0.0);
glClearDepth(1.0);
glEnable(GL_DEPTH_TEST);
glDepthFunc(GL_LESS);	
//glBlendFunc(GL_SRC_ALPHA, GL_ONE);	        
//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
OGL_Load_Texture(patch_texture+'marble.bmp', CubeTexture); 
OGL_Load_Texture(patch_texture+'walls.bmp', RoomTexture);  
OGL_Load_Texture(patch_texture+'texture1.bmp', LightTexture); 
OGL_Load_Texture(patch_texture+'ceiling.bmp', FloorTexture);
OGL_Load_Texture(patch_texture+'end.bmp',  End_Texture); 
CreateCubeDisplayList;
CreateRoomDisplayLists;
LightOn:=true;
main_frame:=0;
Scene_L_frame:=0;
fps:=0.0;
XLightpos := 0.0;
YLightpos := 0.0;
xt:=0.0;
yt:=0.0;
zt:=-24.0;
      
end;

Procedure OGL_reshape(width,height:longint);cdecl;
begin
glViewPort(0,0,width,height);
glMatrixMode(GL_PROJECTION);
glLoadIdentity;
//glOrtho(-2,2,-2*height/width,2*height/width,-2,2);
gluPerspective (45,1.3,1,100);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity;
glutPostRedisplay;

end;

procedure OGL_Scene_L;cdecl;
var

file_n:string;
begin

glEnable(GL_TEXTURE_2D);
case Scene_L_frame of
0..50:begin file_n:=patch_texture+'Loading_' +IntToStr(2)+'.bmp';OGL_Load_Texture(file_n, Scene_L_Texture) end;
51..100:begin file_n:=patch_texture+'Loading_' +IntToStr(3)+'.bmp';OGL_Load_Texture(file_n, Scene_L_Texture) end;
101..150:begin file_n:=patch_texture+'Loading_' +IntToStr(4)+'.bmp';OGL_Load_Texture(file_n, Scene_L_Texture) end;
151..200:begin file_n:=patch_texture+'Loading_' +IntToStr(5)+'.bmp';OGL_Load_Texture(file_n, Scene_L_Texture) end;
201..250:begin file_n:=patch_texture+'Loading_' +IntToStr(6)+'.bmp';OGL_Load_Texture(file_n, Scene_L_Texture) end;
251:Scene_L_frame:=0;
end;
glTranslatef(xt,yt,zt);
glBindTexture(GL_TEXTURE_2D, Scene_L_Texture);
glBegin(GL_QUADS);
			glColor3ub(0,0,0);
			glTexCoord2f(0.0, 0.0);glVertex3f(-2.0, -2.0, 2.0);  
			glTexCoord2f(0.0, 1.0);glVertex3f(-2.0, 2.0, 2.0) ;  
			glTexCoord2f(1.0, 1.0);glVertex3f(2.0, 2.0, 2.0);       
			glTexCoord2f(1.0, 0.0);glVertex3f(2.0, -2.0, 2.0);  
glEnd;
glDisable(GL_TEXTURE_2D);	
inc(Scene_L_frame);
end;

procedure OGL_Scene_E;cdecl;
begin

glEnable(GL_TEXTURE_2D);
glTranslatef(xt,yt,zt);
glBindTexture(GL_TEXTURE_2D, End_Texture);
glBegin(GL_QUADS);
			glColor3ub(0,0,0);
			glTexCoord2f(0.0, 0.0);glVertex3f(-2.0, -2.0, 2.0);  
			glTexCoord2f(0.0, 1.0);glVertex3f(-2.0, 2.0, 2.0) ;  
			glTexCoord2f(1.0, 1.0);glVertex3f(2.0, 2.0, 2.0);       
			glTexCoord2f(1.0, 0.0);glVertex3f(2.0, -2.0, 2.0);  
glEnd;
glDisable(GL_TEXTURE_2D);	

end;

procedure gl_render_info(x,y,z:real);
var
s:pchar;
begin
glColor3f(0.0,1.0,1.0);
OGL_Render_String(x, y,z,  prog_name);
OGL_Render_String(x, y-0.1, z,  glGetString(GL_VENDOR));
OGL_Render_String(x, y-0.2, z,  glGetString(GL_RENDERER));
OGL_Render_String(x, y-0.3, z,  glGetString(GL_VERSION)); 
OGL_Render_String(x, y-0.4,z,  pchar('FPS - '+FloatToStrf(Fps,ffFixed,2,2)));
s:=pchar('Time - '+ FloatToStrf(glutGet(GLUT_ELAPSED_TIME)/1000,ffFixed,3,2)+' sec');
OGL_Render_String(x, y-0.5,z,  pchar(s));
OGL_Render_String(x, y-0.6, z,  'Esc - Quit');

end;

procedure OGL_Scene_1;cdecl;
var
h, r : glFloat;
i:integer;
begin
zt:=-24.0;
glEnable(GL_TEXTURE_2D);
glPushMatrix;
      glTranslatef(xt,yt,zt);
//	glRotatef(angle, 0, 0, 1);
      glBindTexture(GL_TEXTURE_2D, RoomTexture);
      glCallList(RoomDL);
     glBindTexture(GL_TEXTURE_2D, FloorTexture);
      glCallList(FloorDL);
glPopMAtrix;

glPushMatrix();  
	 glEnable(GL_BLEND);
       glColor4f(0.8, 0.8, 0.8,0.3);
	glBlendFunc(GL_ONE, GL_ONE);
      
      glTranslatef(xt,yt,zt+13);
      glRotatef(angle, 1, 0, 0);
      glRotatef(angle, 0, 1, 0);
	 glRotatef(angle, 0, 0, 1);
      glBindTexture(GL_TEXTURE_2D, CubeTexture);
      glCallList(CubeDL);
	glDisable(GL_BLEND);
glPopMatrix();

  glPushMatrix();  
      glEnable(GL_BLEND);   
	glBlendFunc(GL_SRC_ALPHA, GL_ONE);
      glTranslatef(xt,yt,-2.5);
      glBindTexture(GL_TEXTURE_2D, LightTexture);
      glBegin(GL_QUADS);
        if LightOn then
        begin
          glColor3f(0.4, 0.4, 0.4);  
        end
        else
        begin
          glColor3f(0.4, 0.4, 0.4); 
        end;
		glColor4f(0.4, 0.4, 0.4,0.4);	  
        glTexCoord2f(0, 0);  glVertex3f(-0.5,-0.5, 0);
        glTexCoord2f(1, 0);  glVertex3f( 0.5,-0.5, 0);
        glTexCoord2f(1, 1);  glVertex3f( 0.5, 0.5, 0);
        glTexCoord2f(0, 1);  glVertex3f(-0.5, 0.5, 0);
      glEnd();
      glDisable(GL_BLEND);
    glPopMatrix();

glPushMatrix(); 
 glTranslatef(xt,yt-1,zt+13);
 glPointSize(2);
  glDisable(GL_TEXTURE_2D);
  glEnable(GL_BLEND);
 glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glColor4f(0.2, 0.6, 0.9,0.6);
  glBegin(GL_POINTS);
    For I :=0 to 164 do
    begin
      h :=(Round(6*Angle + I*4) MOD 200)/120 + abs(sin(I))/2;    // Height
      r :=0.4+0.4*h;   // radius varies from 0.4 - 1.18         // Radius
      glVertex3f(r*cos(Angle/4+I/2), -3+h, r*sin(Angle/4+I/2));
    end;
  glEnd();
  glColor3f(1.0, 1.0, 1.0);
  glDisable(GL_BLEND);
  glEnable(GL_TEXTURE_2D);
glPopMatrix();

glDisable(GL_TEXTURE_2D);	

end;

procedure  OGL_Scene_2;cdecl;
begin

glEnable(GL_TEXTURE_2D);
glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
glPushMatrix();  
      glTranslatef(xt,yt,zt);
      glRotatef(angle, 1, 0, 0);
      glRotatef(angle, 0, 1, 0);
      glBindTexture(GL_TEXTURE_2D, CubeTexture);
      glCallList(CubeDL);
glPopMatrix();

	glEnable(GL_STENCIL_TEST); 
	glColorMask(1, 0, 0, 0);
	glDisable(GL_DEPTH_TEST); 
	glStencilFunc(GL_ALWAYS, 1, 1); 
	glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);

glPushMatrix;
      glTranslatef(xt,yt,zt);
//	glRotatef(angle, 0, 0, 1);
      glBindTexture(GL_TEXTURE_2D, RoomTexture);
      glCallList(RoomDL);
     glBindTexture(GL_TEXTURE_2D, FloorTexture);
     glCallList(FloorDL);
glPopMatrix;

	glColorMask(1, 1, 1, 1); 
	glEnable(GL_DEPTH_TEST); 
	glStencilFunc(GL_EQUAL, 1, 1);
	glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP); 
   
glPushMatrix(); 
	glScalef(1, -1, 1); 
      glTranslatef(xt,yt+12,zt-6);
      glRotatef(angle, 1, 0, 0);
     glRotatef(angle, 0, 1, 0);
      glBindTexture(GL_TEXTURE_2D, CubeTexture);
     glCallList(CubeDL);
glPopMatrix();
   
glPushMatrix(); 
	glScalef(1, -1, 1); 
      glTranslatef(xt,yt-12,zt-6);
      glRotatef(angle, 1, 0, 0);
     glRotatef(angle, 0, 1, 0);
      glBindTexture(GL_TEXTURE_2D, CubeTexture);
     glCallList(CubeDL);
glPopMatrix();

glPushMatrix(); 
	glScalef(1, -1, 1); 
      glTranslatef(xt+14,yt,zt-6);
      glRotatef(angle, 1, 0, 0);
     glRotatef(angle, 0, 1, 0);
      glBindTexture(GL_TEXTURE_2D, CubeTexture);
     glCallList(CubeDL);
glPopMatrix();

glPushMatrix(); 
	glScalef(1, -1, 1); 
      glTranslatef(xt-14,yt,zt-6);
      glRotatef(angle, 1, 0, 0);
     glRotatef(angle, 0, 1, 0);
      glBindTexture(GL_TEXTURE_2D, CubeTexture);
     glCallList(CubeDL);
glPopMatrix();
  glDisable(GL_STENCIL_TEST);    
    
    glEnable(GL_BLEND);
    glColor4f(1,0,0, 0.7);
glPushMatrix;
	glTranslatef(xt,yt,zt);
//	glRotatef(angle, 0, 0, 1);
      glBindTexture(GL_TEXTURE_2D, RoomTexture);
	glCallList(RoomDL);
	glBindTexture(GL_TEXTURE_2D, FloorTexture);
	glCallList(FloorDL);
glPopMAtrix;  
    glDisable(GL_BLEND);


   glPushMatrix();  
	glBlendFunc(GL_SRC_ALPHA, GL_ONE); 
      glEnable(GL_BLEND);   
      glTranslatef(XLightpos,YLightpos,-3.0);
      glBindTexture(GL_TEXTURE_2D, LightTexture);
      glBegin(GL_QUADS);
        if LightOn then
        begin
          glColor3f(1.0, 1.0, 1.0);  
        end
        else
        begin
          glColor3f(0.7, 0.7, 0.7); 
        end;
        glTexCoord2f(0, 0);  glVertex3f(-0.5,-0.5, 0);
        glTexCoord2f(1, 0);  glVertex3f( 0.5,-0.5, 0);
        glTexCoord2f(1, 1);  glVertex3f( 0.5, 0.5, 0);
        glTexCoord2f(0, 1);  glVertex3f(-0.5, 0.5, 0);
      glEnd();
      glDisable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glPopMatrix();

glDisable(GL_TEXTURE_2D);	

end;

procedure OGL_Draw;cdecl;
begin
glClear (GL_COLOR_BUFFER_BIT OR GL_DEPTH_BUFFER_BIT);
glLoadIdentity;
gl_render_info(-1.6,1.1,-3);
glLoadIdentity;
case main_frame of
0..251:begin OGL_Scene_L end;
252..1252:begin OGL_Scene_1 end;
1253..1504:begin OGL_Scene_L end;
1505..2505:begin OGL_Scene_2 end;
2506..2606:begin OGL_Scene_E end;
2607:halt(0);
end;

glFlush();
glutSwapBuffers();
inc(main_frame);
fps:= main_frame*1000 /  glutGet(GLUT_ELAPSED_TIME) ;
end;

procedure OGL_OnTimer(Value:LongInt);CDecl;
begin
angle:=angle+0.6;

glutPostRedisplay;
glutTimerFunc(20,@OGL_OnTimer,0);
end;

procedure Key_pressed(k:byte;x,y:longint);CDecl;
begin
case k of
27:halt(0);
end;
end;


begin
glutInit(@argc,argv);
glutInitDisplayMode(GLUT_RGBA or GLUT_DOUBLE or GLUT_DEPTH);
glutInitWindowSize(800,600);
glutCreateWindow('Linux 3D Benchmark');
glutTimerFunc(20,@OGL_OnTimer,0);
glutKeyboardFunc(@key_pressed);
glutDisplayFunc(@OGL_Draw);
glutReshapeFunc(@OGL_reshape);
OGL_init(800,600);
glutMainLoop;


end.

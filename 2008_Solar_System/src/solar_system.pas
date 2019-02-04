 // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //.
//                    Savka Taras                   //
//                ------------------                //
//                   Vilychinsk-3                   //
//                 scool¹ 2   fom 10                //
//                opengl program demo               //
//                Copyright   : GPL v3              //
//                ------------------                //
//                      23.03.08                    //
 // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //'
program solar_system;
uses
  GL, GLU, GLUT,LoadBMP;


var
  counter: Integer;
  angle,mercury_angle,venerus_angle,Eart_angle,Mars_angle,Jupiter_angle,Saturn_angle,
  Neptune_angle,Pluton_angle,uranus_angle :real;

  MyQuadratic : PgluQuadricObj;

  Texture1 : glUint;
  Texture2 : glUint;
  Texture3 : glUint;
  Texture4 : glUint;
  Texture5 : glUint;
  Texture6 : glUint;
  Texture7 : glUint;
  Texture8 : glUint;
  Texture9 : glUint;
  Texture10 : glUint;
  Texture11 : glUint;
  Texture12 : glUint;
  Texture13 : glUint;
  Texture14 : glUint;
  Texture15 : glUint;
  Texture16 : glUint;
  Texture17 : glUint;
  Texture18 : glUint;
  Texture19 : glUint;
  Texture20 : glUint;
  Texture21 : glUint;
  Texture22 : glUint;
  Texture23 : glUint;
  Texture24 : glUint;
  Texture25 : glUint;
  Texture26 : glUint;
  Texture27 : glUint;

procedure OGL_init(width, height : longint);
begin
   glClearColor( 0.0, 0.0, 0.0, 1.0 );
//   glViewport( 0, 0, width, height );

  glEnable(GL_TEXTURE_2D);
  glEnable(GL_AUTO_NORMAL);
  glEnable(GL_NORMALIZE);
  angle:=0.0;
  mercury_angle:=0.0;
  venerus_angle:=0.0;
  Eart_angle:=0.0;
  Mars_angle:=0.0;
  Jupiter_angle:=0.0;
  Saturn_angle:=0.0;
  uranus_angle:=0.0;
  Neptune_angle:=0.0;
  Pluton_angle:=0.0;
 glEnable(GL_DEPTH_TEST);

 glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

 glTexGenf(GL_S, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
 glTexGenf(GL_T, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);

glShadeModel(GL_SMOOTH);
glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);

 OGL_Load_Texture('Texture/Fon.bmp', Texture1);
 OGL_Load_Texture('Texture/sun_tex.bmp', Texture2);
 OGL_Load_Texture('Texture/mercury.bmp', Texture3);
 OGL_Load_Texture('Texture/venerus.bmp', Texture4);
 OGL_Load_Texture('Texture/Eart.bmp', Texture5);
 OGL_Load_Texture('Texture/Mars.bmp', Texture6);
 OGL_Load_Texture('Texture/Jupiter.bmp', Texture7);
 OGL_Load_Texture('Texture/Saturn.bmp', Texture8);
 OGL_Load_Texture('Texture/uranus.bmp', Texture9);
 OGL_Load_Texture('Texture/Neptune.bmp', Texture10);
 OGL_Load_Texture('Texture/Pluton.bmp', Texture11);

 OGL_Load_Texture('Texture/Gagarin.bmp', Texture12);
 OGL_Load_Texture('Texture/Grechko.bmp', Texture13);
 OGL_Load_Texture('Texture/Lionov.bmp', Texture14);
 OGL_Load_Texture('Texture/Tereshkova.bmp', Texture15);
 OGL_Load_Texture('Texture/Titov G.bmp', Texture16);
 OGL_Load_Texture('Texture/Aleksandrov.bmp', Texture17);
 OGL_Load_Texture('Texture/Artyxin.bmp', Texture18);
 OGL_Load_Texture('Texture/Belyaev.bmp', Texture19);
 OGL_Load_Texture('Texture/Djabibekov.bmp', Texture20);
 OGL_Load_Texture('Texture/Glazkov.bmp', Texture21);
 OGL_Load_Texture('Texture/Kizim.bmp', Texture22);
 OGL_Load_Texture('Texture/Klimuk.bmp', Texture23);
 OGL_Load_Texture('Texture/Komarov.bmp', Texture24);
 OGL_Load_Texture('Texture/Kovalenko.bmp', Texture25);
 OGL_Load_Texture('Texture/Volinov.bmp', Texture26);

 MyQuadratic := gluNewQuadric();
 gluQuadricNormals(MyQuadratic, GLU_SMOOTH);
 gluQuadricTexture(MyQuadratic, GL_TRUE);

 end;
 Procedure OGL_reshape(width, height : longint); cdecl;
Var aspect : glFloat;
Begin
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity;
  gluPerspective(60, width/height, 1, 400);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity;
  glutPostRedisplay;

End;

procedure OGL_Draw; cdecl;
Begin
  glClear(GL_COLOR_BUFFER_BIT OR GL_DEPTH_BUFFER_BIT);    //clear the screen or window
  glLoadIdentity;

  glPushMatrix();
  glBindTexture(GL_TEXTURE_2D, Texture1);
  glTranslatef(0.0,0.0,-399.0);
  glBegin(GL_QUADS);
  glColor4f(1.0,0.0,0.0,0.2);
      glTexCoord2f(0.0, 1.0); glVertex3f(-310.0, 300.0,  1.0);
      glTexCoord2f(0.0, 0.0); glVertex3f( -310.0, -300.0,  1.0);
      glTexCoord2f(1.0, 0.0); glVertex3f( 310.0,  -300.0,  1.0);
      glTexCoord2f(1.0, 1.0); glVertex3f(310.0,  300.0,  1.0);
     glEnd;
   glPopMatrix();
  glEnable(GL_BLEND);
  glTranslatef(0.0,0.0,-200);
    glPushMatrix();
  glBindTexture(GL_TEXTURE_2D, Texture12);
  glTranslatef(-160.0,82.0,-150.0);
  glBegin(GL_QUADS);
      glTexCoord2f(0.0, 1.0); glVertex3f(-110.0, 120.0,  0.0);
      glTexCoord2f(0.0, 0.0); glVertex3f(-110.0, -15.0,  0.0);
      glTexCoord2f(1.0, 0.0); glVertex3f( 0.0,  -15.0,  0.0);
      glTexCoord2f(1.0, 1.0); glVertex3f(0.0,  120.0,  0.0);
     glEnd;
  glPopMatrix();

    glPushMatrix();
  glBindTexture(GL_TEXTURE_2D, Texture13);
  glTranslatef(-50.0,82.0,-150.0);
  glBegin(GL_QUADS);
      glTexCoord2f(0.0, 1.0); glVertex3f(-110.0, 120.0,  0.0);
      glTexCoord2f(0.0, 0.0); glVertex3f(-110.0, -15.0,  0.0);
      glTexCoord2f(1.0, 0.0); glVertex3f( 0.0,  -15.0,  0.0);
      glTexCoord2f(1.0, 1.0); glVertex3f(0.0,  120.0,  0.0);
     glEnd;
  glPopMatrix();

     glPushMatrix();
  glBindTexture(GL_TEXTURE_2D, Texture15);
  glTranslatef(60.0,82.0,-150.0);
  glBegin(GL_QUADS);
      glTexCoord2f(0.0, 1.0); glVertex3f(-110.0, 120.0,  0.0);
      glTexCoord2f(0.0, 0.0); glVertex3f(-110.0, -15.0,  0.0);
      glTexCoord2f(1.0, 0.0); glVertex3f( 0.0,  -15.0,  0.0);
      glTexCoord2f(1.0, 1.0); glVertex3f(0.0,  120.0,  0.0);
     glEnd;
  glPopMatrix();

       glPushMatrix();
  glBindTexture(GL_TEXTURE_2D, Texture14);
  glTranslatef(170.0,82.0,-150.0);
  glBegin(GL_QUADS);
      glTexCoord2f(0.0, 1.0); glVertex3f(-110.0, 120.0,  0.0);
      glTexCoord2f(0.0, 0.0); glVertex3f(-110.0, -15.0,  0.0);
      glTexCoord2f(1.0, 0.0); glVertex3f( 0.0,  -15.0,  0.0);
      glTexCoord2f(1.0, 1.0); glVertex3f(0.0,  120.0,  0.0);
     glEnd;
  glPopMatrix();

       glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, Texture16);
  glTranslatef(280.0,82.0,-150.0);
  glBegin(GL_QUADS);
      glTexCoord2f(0.0, 1.0); glVertex3f(-110.0, 120.0,  0.0);
      glTexCoord2f(0.0, 0.0); glVertex3f(-110.0, -15.0,  0.0);
      glTexCoord2f(1.0, 0.0); glVertex3f( 0.0,  -15.0,  0.0);
      glTexCoord2f(1.0, 1.0); glVertex3f(0.0,  120.0,  0.0);
     glEnd;
  glPopMatrix();

        glPushMatrix();
      glBindTexture(GL_TEXTURE_2D, Texture17);
  glTranslatef(-160.0,-53.0,-150.0);
  glBegin(GL_QUADS);
      glTexCoord2f(0.0, 1.0); glVertex3f(-110.0, 120.0,  0.0);
      glTexCoord2f(0.0, 0.0); glVertex3f(-110.0, -15.0,  0.0);
      glTexCoord2f(1.0, 0.0); glVertex3f( 0.0,  -15.0,  0.0);
      glTexCoord2f(1.0, 1.0); glVertex3f(0.0,  120.0,  0.0);
     glEnd;
  glPopMatrix();

        glPushMatrix();
      glBindTexture(GL_TEXTURE_2D, Texture18);
  glTranslatef(-50.0,-53.0,-150.0);
  glBegin(GL_QUADS);
      glTexCoord2f(0.0, 1.0); glVertex3f(-110.0, 120.0,  0.0);
      glTexCoord2f(0.0, 0.0); glVertex3f(-110.0, -15.0,  0.0);
      glTexCoord2f(1.0, 0.0); glVertex3f( 0.0,  -15.0,  0.0);
      glTexCoord2f(1.0, 1.0); glVertex3f(0.0,  120.0,  0.0);
     glEnd;
  glPopMatrix();

      glPushMatrix();
      glBindTexture(GL_TEXTURE_2D, Texture19);
  glTranslatef(60.0,-53.0,-150.0);
  glBegin(GL_QUADS);
      glTexCoord2f(0.0, 1.0); glVertex3f(-110.0, 120.0,  0.0);
      glTexCoord2f(0.0, 0.0); glVertex3f(-110.0, -15.0,  0.0);
      glTexCoord2f(1.0, 0.0); glVertex3f( 0.0,  -15.0,  0.0);
      glTexCoord2f(1.0, 1.0); glVertex3f(0.0,  120.0,  0.0);
     glEnd;
  glPopMatrix();

        glPushMatrix();
      glBindTexture(GL_TEXTURE_2D, Texture20);
  glTranslatef(170.0,-53.0,-150.0);
  glBegin(GL_QUADS);
      glTexCoord2f(0.0, 1.0); glVertex3f(-110.0, 120.0,  0.0);
      glTexCoord2f(0.0, 0.0); glVertex3f(-110.0, -15.0,  0.0);
      glTexCoord2f(1.0, 0.0); glVertex3f( 0.0,  -15.0,  0.0);
      glTexCoord2f(1.0, 1.0); glVertex3f(0.0,  120.0,  0.0);
     glEnd;
  glPopMatrix();

        glPushMatrix();
      glBindTexture(GL_TEXTURE_2D, Texture21);
  glTranslatef(280.0,-53.0,-150.0);
  glBegin(GL_QUADS);
      glTexCoord2f(0.0, 1.0); glVertex3f(-110.0, 120.0,  0.0);
      glTexCoord2f(0.0, 0.0); glVertex3f(-110.0, -15.0,  0.0);
      glTexCoord2f(1.0, 0.0); glVertex3f( 0.0,  -15.0,  0.0);
      glTexCoord2f(1.0, 1.0); glVertex3f(0.0,  120.0,  0.0);
     glEnd;
  glPopMatrix();

          glPushMatrix();
      glBindTexture(GL_TEXTURE_2D, Texture22);
  glTranslatef(-160.0,-187.0,-150.0);
  glBegin(GL_QUADS);
      glTexCoord2f(0.0, 1.0); glVertex3f(-110.0, 120.0,  0.0);
      glTexCoord2f(0.0, 0.0); glVertex3f(-110.0, -15.0,  0.0);
      glTexCoord2f(1.0, 0.0); glVertex3f( 0.0,  -15.0,  0.0);
      glTexCoord2f(1.0, 1.0); glVertex3f(0.0,  120.0,  0.0);
     glEnd;
  glPopMatrix();

       glPushMatrix();
      glBindTexture(GL_TEXTURE_2D, Texture23);
  glTranslatef(-50.0,-187.0,-150.0);
  glBegin(GL_QUADS);
      glTexCoord2f(0.0, 1.0); glVertex3f(-110.0, 120.0,  0.0);
      glTexCoord2f(0.0, 0.0); glVertex3f(-110.0, -15.0,  0.0);
      glTexCoord2f(1.0, 0.0); glVertex3f( 0.0,  -15.0,  0.0);
      glTexCoord2f(1.0, 1.0); glVertex3f(0.0,  120.0,  0.0);
     glEnd;
  glPopMatrix();

      glPushMatrix();
      glBindTexture(GL_TEXTURE_2D, Texture24);
  glTranslatef(60.0,-187.0,-150.0);
  glBegin(GL_QUADS);
      glTexCoord2f(0.0, 1.0); glVertex3f(-110.0, 120.0,  0.0);
      glTexCoord2f(0.0, 0.0); glVertex3f(-110.0, -15.0,  0.0);
      glTexCoord2f(1.0, 0.0); glVertex3f( 0.0,  -15.0,  0.0);
      glTexCoord2f(1.0, 1.0); glVertex3f(0.0,  120.0,  0.0);
     glEnd;
  glPopMatrix();

        glPushMatrix();
      glBindTexture(GL_TEXTURE_2D, Texture25);
  glTranslatef(170.0,-187.0,-150.0);
  glBegin(GL_QUADS);
      glTexCoord2f(0.0, 1.0); glVertex3f(-110.0, 120.0,  0.0);
      glTexCoord2f(0.0, 0.0); glVertex3f(-110.0, -15.0,  0.0);
      glTexCoord2f(1.0, 0.0); glVertex3f( 0.0,  -15.0,  0.0);
      glTexCoord2f(1.0, 1.0); glVertex3f(0.0,  120.0,  0.0);
     glEnd;
  glPopMatrix();

        glPushMatrix();
      glBindTexture(GL_TEXTURE_2D, Texture26);
  glTranslatef(280.0,-187.0,-150.0);
  glBegin(GL_QUADS);
      glTexCoord2f(0.0, 1.0); glVertex3f(-110.0, 120.0,  0.0);
      glTexCoord2f(0.0, 0.0); glVertex3f(-110.0, -15.0,  0.0);
      glTexCoord2f(1.0, 0.0); glVertex3f( 0.0,  -15.0,  0.0);
      glTexCoord2f(1.0, 1.0); glVertex3f(0.0,  120.0,  0.0);
     glEnd;
  glPopMatrix();


  glDisable(GL_BLEND);

  glLoadIdentity;
  glTranslatef(0.0,10.0,-200);
  glPushMatrix();
  glBindTexture(GL_TEXTURE_2D, Texture2);
  glTranslatef(0.0,0.0,0.0);
  glRotatef(angle,0.0,1.0,0.0);
  glRotatef(90,1.0, 0.0,0.0);
  gluSphere(MyQuadratic, 9, 52, 52);
  glPopMatrix();

  glPushMatrix();
  glRotatef(mercury_angle,0.0,1.0,1.0);
  glPushMatrix();
  glBindTexture(GL_TEXTURE_2D, Texture3);
  glTranslatef(15.0,0.0,0.0);
  glRotatef(angle,0.0,1.0,0.0);
  glRotatef(90,1.0, 0.0,0.0);
  gluSphere(MyQuadratic, 2.5, 52, 52);
  glPopMatrix();
  glPopMatrix();

  glPushMatrix();
  glRotatef(venerus_angle,0.0,1.0,1.0);
  glPushMatrix();
  glBindTexture(GL_TEXTURE_2D, Texture4);
  glTranslatef(25.0,3.0,0.0);
  glRotatef(angle,0.0,1.0,0.0);
  glRotatef(90,1.0, 0.0,0.0);
  gluSphere(MyQuadratic, 4.0, 52, 52);
  glPopMatrix();
  glPopMatrix();

  glPushMatrix();
  glRotatef(Eart_angle,0.0,1.0,1.0);
  glPushMatrix();
  glBindTexture(GL_TEXTURE_2D, Texture5);
  glTranslatef(40.0,3.0,0.0);
  glRotatef(angle,0.0,1.0,0.0);
  glRotatef(90,1.0, 0.0,0.0);
  gluSphere(MyQuadratic, 5.0, 52, 52);
  glPopMatrix();
  glPopMatrix();

  glPushMatrix();
  glRotatef(Mars_angle,0.0,1.0,1.0);
  glPushMatrix();
  glBindTexture(GL_TEXTURE_2D, Texture6);
  glTranslatef(55.0,-1.0,0.0);
  glRotatef(angle,0.0,1.0,0.0);
  glRotatef(90,1.0, 0.0,0.0);
  gluSphere(MyQuadratic, 4.0, 52, 52);
  glPopMatrix();
  glPopMatrix();

  glPushMatrix();
  glRotatef(Jupiter_angle,0.0,1.0,1.0);
  glPushMatrix();
  glBindTexture(GL_TEXTURE_2D, Texture7);
  glTranslatef(70.0,6.0,0.0);
  glRotatef(angle,0.0,1.0,0.0);
  glRotatef(90,1.0, 0.0,0.0);
  gluSphere(MyQuadratic, 8.0, 52, 52);
  glPopMatrix();
  glPopMatrix();

  glPushMatrix();
  glRotatef(Saturn_angle,0.0,1.0,1.0);
  glPushMatrix();
  glBindTexture(GL_TEXTURE_2D, Texture8);  
  glTranslatef(90.0,8.0,0.0);

  glColor4f(1.0,0.0,0.0,0.5);
  glEnable(GL_BLEND);
  glRotatef(90,1.0, 0.0,0.0);
  gluDisk(MyQuadratic,7.8,11.5,32,32);
  glDisable(GL_BLEND);
  
   glRotatef(angle,0.0, 1.0,0.0);
  gluSphere(MyQuadratic, 7.0, 52, 52);
  glPopMatrix();

  glPushMatrix();
  glRotatef(uranus_angle,0.0,1.0,1.0);
  glPushMatrix();
  glBindTexture(GL_TEXTURE_2D, Texture9);
  glTranslatef(110.0,6.0,0.0);
  glRotatef(angle,0.0,1.0,0.0);
  glRotatef(90,1.0, 0.0,0.0);
  gluSphere(MyQuadratic, 7.0, 52, 52);
  glPopMatrix();
  glPopMatrix();

  glPushMatrix();
  glRotatef(Neptune_angle,0.0,1.0,1.0);
  glPushMatrix();
  glBindTexture(GL_TEXTURE_2D, Texture10);
  glTranslatef(125.0,9.0,0.0);
  glRotatef(angle,0.0,1.0,0.0);
  glRotatef(90,1.0, 0.0,0.0);
  gluSphere(MyQuadratic, 6.0, 52, 52);
  glPopMatrix();
  glPopMatrix();

  glPushMatrix();
  glRotatef(Pluton_angle,0.0,1.0,1.0);
  glPushMatrix();
  glBindTexture(GL_TEXTURE_2D, Texture11);
  glTranslatef(135.0,10.0,0.0);
  glRotatef(angle,0.0,1.0,0.0);
  glRotatef(90,1.0, 0.0,0.0);
  gluSphere(MyQuadratic, 3.0, 52, 52);
  glPopMatrix();
  glPopMatrix();

glTranslatef(0.0,40.0,0.0);
  glFlush;
  glutSwapBuffers;
End;
procedure Key_pressed(K:byte;x,y:longint);cdecl;
Begin
  case K of
 27: halt(0)
  end;
End;
procedure OGL_OnTimer(value: LongInt); cdecl;
begin
  angle:=angle+0.6;
  mercury_angle:=mercury_angle+1/0.24;
  venerus_angle:=venerus_angle+1/0.61;
  Eart_angle:=Eart_angle+1/1;
  Mars_angle:=Mars_angle+1/1.88;
  Jupiter_angle:=Jupiter_angle+1/11.86;
  Saturn_angle:=Saturn_angle+1/29.45;
  uranus_angle:=uranus_angle+1/84.01;
  Neptune_angle:=Neptune_angle+1/164.78;
  Pluton_angle:=Pluton_angle+1/247.69;

  glutPostRedisplay;
  glutTimerFunc(20, @OGL_OnTimer, 0);
end;

begin

  glutInit(@argc, argv);

  glutInitDisplayMode(GLUT_RGBA or GLUT_DOUBLE);
  glutInitWindowSize(800,600);
  glutCreateWindow('OpenGL program demo solar system');
  glutTimerFunc(20, @OGL_OnTimer, 0);
  glutDisplayFunc(@OGL_Draw);
  glutReshapeFunc(@OGL_reshape);
  glutKeyboardFunc(@Key_pressed);
  OGL_init(800,600);
  glutMainLoop;

end.

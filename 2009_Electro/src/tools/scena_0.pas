{$R-}
{$MODE DELPHI}
unit scena_0;
interface
uses sdl, gl,  glu,  SysUtils, glut, glext,text_glut,  text_gl,  ogl_texture,menu,shema;

const
SPEED0=0.0007;
SPEED1=0.006;
SPEED2=0.0055;
SPEED3=0.005;
SPEED_T=0.0005;
PATH_TEXTURE='../data/textures/';

var
Font_base : GLuint;
Zadniy_fon_00:GLUInt;
Zadniy_fon_01:GLUInt;
Zadniy_fon_02:GLUInt;
Zadniy_fon_03:GLUInt;
Zadniy_fon_04:GLUInt;
Zadniy_fon_05:GLUInt;
Zadniy_fon_06:GLUInt;
Zadniy_fon_07:GLUInt;
Zadniy_fon_08:GLUInt;
Zadniy_fon_09:GLUInt;
Zagolovok_0_1:GLUInt;
Zagolovok_0_2:GLUInt;
alfa0,alfa1,alfa2,alfa3,ky0,kx0,kx1,ky1,kx2,ky2,kx3,ky3,ch3,a3,r3,s:GLFloat;
patch:Boolean=true;
Blend_func:GLUInt=0;
wrap:GLFloat;

//--------------------------------------------------------------------------------------------------------------------------------------
procedure quads_draw_sxema_1(size_x,size_y:GLFloat);
procedure anim_proc_scena_0();
procedure load_texture_scena_0();
procedure ogl_on_start_scena_0(width,height:glInt);
procedure key_pressed_scena_0( keysym : PSDL_keysym );
procedure mouse_button_pressed_scena_0 ( button : TSDL_MouseButtonEvent );
procedure mouse_motion_scena_0( motion :  TSDL_MouseMotionEvent );
procedure fon_draw_scena_0();
procedure title_draw_scena_0();

///////////////////////////////////////////////////////////////////////////////
implementation
///////////////////////////////////////////////////////////////////////////////


procedure patch_0();
begin
	if alfa0>=pi() then 
		patch:=true;
	if alfa0<=-pi() then 
		patch:=false;
	if patch then
	 begin
		alfa0:=alfa0-SPEED0;
		ky0:=sin(alfa0);
	 end
	else
	 begin
		alfa0:=alfa0+SPEED0;
		ky0:=sin(alfa0);
	  end;
	kx0:=alfa0;	
end;
//////////////////////////////////////////////////////////////////////////////
procedure patch_1();
begin
	
	if alfa1>=2*pi() then 
		alfa1:=0;
	alfa1:=alfa1+SPEED1;
	ky1:=sin(alfa1);
	kx1:=1+cos(alfa1);
	
end;
//////////////////////////////////////////////////////////////////////////////
procedure patch_2();
begin
	
	if alfa2>=2*pi() then 
		alfa2:=0;
	alfa2:=alfa2+SPEED2;
	ky2:=sin(alfa2);
	kx2:=cos(alfa2);
	
end;
//////////////////////////////////////////////////////////////////////////////////
procedure patch_3();
begin	
	if (r3>5.0) or (r3<0.1) then
		ch3:=-ch3;
	
	r3:=r3+ch3;	
	kx3:=(r3)*cos(alfa3);
	ky3:=(r3)*sin(alfa3);
	alfa3:=alfa3+SPEED3;
end;
/////////////////////////////////////////////////////////////////////////////////////
procedure patch_4();
begin	
	 	if wrap >1 then
		wrap := 0;
	
	wrap := wrap +SPEED_T;
end;

////////////////////////////////////////////////////////////////////////////////////
procedure anim_proc_scena_0();
begin
		patch_0();
		patch_1();
		patch_2();
		patch_3();
		patch_4();
end;

///////////////////////////////////////////////////////////////////////////////////
procedure load_texture_scena_0();
begin
	OGL_Load_Texture(PATH_TEXTURE+'Zagolovok_0_1.tga', Zagolovok_0_1, txBilinear, GL_REPLACE, GL_CLAMP, txNoCompressed,GL_TRUE);
	OGL_Load_Texture(PATH_TEXTURE+'Zagolovok_0_2.tga', Zagolovok_0_2, txBilinear, GL_REPLACE, GL_CLAMP, txNoCompressed,GL_TRUE);
    OGL_Load_Texture(PATH_TEXTURE+'formula_1.bmp', Zadniy_fon_01, txBilinear, GL_MODULATE, GL_CLAMP, txNoCompressed,GL_TRUE);
	OGL_Load_Texture(PATH_TEXTURE+'formula_4.bmp', Zadniy_fon_02, txBilinear, GL_MODULATE, GL_CLAMP, txNoCompressed,GL_TRUE);
	OGL_Load_Texture(PATH_TEXTURE+'formula_2.bmp', Zadniy_fon_03, txBilinear, GL_MODULATE, GL_CLAMP, txNoCompressed,GL_TRUE);
	OGL_Load_Texture(PATH_TEXTURE+'op8_ris3.bmp', Zadniy_fon_04, txBilinear, GL_MODULATE, GL_CLAMP, txNoCompressed,GL_TRUE);
	OGL_Load_Texture(PATH_TEXTURE+'op9_ris1.bmp', Zadniy_fon_05, txBilinear, GL_MODULATE, GL_CLAMP, txNoCompressed,GL_TRUE);
	OGL_Load_Texture(PATH_TEXTURE+'cep_1.bmp', Zadniy_fon_06, txBilinear, GL_MODULATE, GL_CLAMP, txNoCompressed,GL_TRUE);
	OGL_Load_Texture(PATH_TEXTURE+'cep_2.bmp', Zadniy_fon_07, txBilinear, GL_MODULATE, GL_CLAMP, txNoCompressed,GL_TRUE);
	OGL_Load_Texture(PATH_TEXTURE+'cep_3.bmp', Zadniy_fon_08, txBilinear, GL_MODULATE, GL_CLAMP, txNoCompressed,GL_TRUE);
	OGL_Load_Texture(PATH_TEXTURE+'op8_ris2.bmp', Zadniy_fon_09, txBilinear, GL_MODULATE, GL_CLAMP, txNoCompressed,GL_TRUE);
	OGL_Load_Texture(PATH_TEXTURE+'fon.bmp', Zadniy_fon_00, txBilinear, GL_MODULATE, GL_REPEAT, txNoCompressed,GL_TRUE);
	load_texture_shema();
end;

//////////////////////////////////////////////////////////////////////////////////////
procedure ogl_on_start_scena_0(width,height:glInt);
begin
    alfa0:=pi();
	alfa1:=0;
	alfa1:=0;
	ch3:=0.01;
	a3:=Pi/2;	
	ch3:=0.0005;
	a3:=0.0;
	r3:=0.1;
	wrap:=0;

end;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
procedure key_pressed_scena_0( keysym : PSDL_keysym );
begin
	case keysym.sym of		
		SDLK_b:
			begin
				blend_func:=blend_func+1;
				if blend_func > 109 then
					blend_func:=0;
			end;
		end;
end;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
procedure mouse_button_pressed_scena_0 ( button : TSDL_MouseButtonEvent );
begin
	mouse_button_pressed_menu(button);	
end;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
procedure mouse_motion_scena_0( motion :  TSDL_MouseMotionEvent );
begin
	mouse_motion_menu(motion);
end;


/////////////////////////////////////////////////////////////////////////////////////
procedure quads_draw_sxema_1(size_x,size_y:GLFloat);
begin
	
	glBegin(GL_QUADS);
			glTexCoord2f(0.0,0.0);glVertex3f(-1.0*size_x,-1.0*size_y,-1.0);
			glTexCoord2f(1.0,0.0);glVertex3f(1.0*size_x,-1.0*size_y,-1.0);
			glTexCoord2f(1.0,1.0);glVertex3f(1.0*size_x,1.0*size_y,-1.0);
			glTexCoord2f(0.0,1.0);glVertex3f(-1.0*size_x, 1.0*size_y,-1.0);
	glEnd();
	 
end;
////////////////////////////////////////////////////////////////////////////////////
procedure quads_draw_sxema_4(size_x,size_y:GLFloat);
begin
	
	glBegin(GL_QUADS);
			glTexCoord2f(0.0,0.0);glVertex3f(-1.0*size_x,-1.0*size_y,-1.0);
			glTexCoord2f(1.0,0.0);glVertex3f(1.0*size_x,-1.0*size_y,-1.0);
			glTexCoord2f(1.0,1.0);glVertex3f(1.0*size_x,1.0*size_y,-1.0);
			glTexCoord2f(0.0,1.0);glVertex3f(-1.0*size_x, 1.0*size_y,-1.0);
	glEnd();
	
	end;
////////////////////////////////////////////////////////////////////////////////////
procedure quads_draw_formula(size_x,size_y:GLFloat);
begin
	
	glBegin(GL_QUADS);
			glTexCoord2f(0.0,0.0);glVertex3f(-1.0*size_x,-1.0*size_y,-1.0);
			glTexCoord2f(1.0,0.0);glVertex3f(1.0*size_x,-1.0*size_y,-1.0);
			glTexCoord2f(1.0,1.0);glVertex3f(1.0*size_x,1.0*size_y,-1.0);
			glTexCoord2f(0.0,1.0);glVertex3f(-1.0*size_x, 1.0*size_y,-1.0);
	glEnd();
	 
end;
/////////////////////////////////////////////////////////////////////////////////////
procedure quads_draw(size_x,size_y:GLFloat);
begin	
	glBegin(GL_QUADS);
			glTexCoord2f(0.0+wrap,0.0);glVertex3f(-1.0*size_x,-1.0*size_y,-1.0);
			glTexCoord2f(1.0+wrap,0.0);glVertex3f(1.0*size_x,-1.0*size_y,-1.0);
			glTexCoord2f(1.0+wrap,1.0);glVertex3f(1.0*size_x,1.0*size_y,-1.0);
			glTexCoord2f(0.0+wrap,1.0);glVertex3f(-1.0*size_x, 1.0*size_y,-1.0);
	glEnd();
end;

////////////////////////////////////////////////////////////////////////////////////
procedure quads_draw_zagolovok_0_1(size_x,size_y:GLFloat);
begin
	
	glBegin(GL_QUADS);
			glTexCoord2f(0.0,0.0);glVertex3f(-1.0*size_x,-1.0*size_y,-1.0);
			glTexCoord2f(1.0,0.0);glVertex3f(1.0*size_x,-1.0*size_y,-1.0);
			glTexCoord2f(1.0,1.0);glVertex3f(1.0*size_x,1.0*size_y,-1.0);
			glTexCoord2f(0.0,1.0);glVertex3f(-1.0*size_x, 1.0*size_y,-1.0);			
	glEnd();	 
end;
///////////////////////////////////////////////////////////////////////////////////////////////////
procedure quads_draw_zagolovok_0_2(size_x,size_y:GLFloat);
begin
	
	glBegin(GL_QUADS);
			glTexCoord2f(0.0,0.0);glVertex3f(-1.0*size_x,-1.0*size_y,-1.0);
			glTexCoord2f(1.0,0.0);glVertex3f(1.0*size_x,-1.0*size_y,-1.0);
			glTexCoord2f(1.0,1.0);glVertex3f(1.0*size_x,1.0*size_y,-1.0);
			glTexCoord2f(0.0,1.0);glVertex3f(-1.0*size_x, 1.0*size_y,-1.0);
	glEnd();
	 
end;
///////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
procedure title_draw_scena_0();
begin
	glColor4f(1.0,1.0,1.0,1.0);
	glEnable(GL_BLEND);
	glEnable(GL_TEXTURE_2D);
	glBlendFunc(GL_ONE,GL_ONE_MINUS_SRC_ALPHA);
	glPushMatrix();	
	glTranslatef(0.0, 2.0,-2.0);
	glBindTexture( GL_TEXTURE_2D, Zagolovok_0_1 );
	quads_draw_zagolovok_0_1(5.5,0.5);
	glPopMatrix();	
	
	glPushMatrix();	
	glTranslatef(0.0, 0.0,-2.0);
	glBindTexture( GL_TEXTURE_2D, Zagolovok_0_2 );
	quads_draw_zagolovok_0_2(8.0,1.5);
	glPopMatrix();
	glColor4f(1.0,1.0,1.0,1.0);
    glDisable(GL_BLEND);
    glDisable(GL_TEXTURE_2D);
end;


///////////////////////////////////////////////////////////////////////////////////////
//процедура отрисовки основной сцены 
procedure fon_draw_scena_0();
begin
	glEnable(GL_TEXTURE_2D);		
	glPushMatrix();		
	glTranslatef(0.0,0.0,-40);
	glBindTexture( GL_TEXTURE_2D, Zadniy_fon_00 );
	quads_draw(38.0,30.0);	
	glPopMatrix();	
	
	glColor4f(0.1294,0.4941,0.54235,1.0);
	glEnable(GL_BLEND);
	glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_COLOR);
	glPushMatrix();	
	glBindTexture( GL_TEXTURE_2D, Zadniy_fon_01 );
	glTranslatef(-4.0+kx0,-4.0+ky0*2,-5);
	quads_draw_formula(2.0, 2.0);
	glPopMatrix();
	
	
	glPushMatrix();	
	glBindTexture( GL_TEXTURE_2D, Zadniy_fon_02 );
	glTranslatef(4.0+ky1,3.0+kx1,-5);
	quads_draw_formula(2.0,2.0);
	glPopMatrix();
	
	glPushMatrix();	
	glTranslatef(-1.0+kx2,0.0+ky2,-5);
	glBindTexture( GL_TEXTURE_2D, Zadniy_fon_03 );
	quads_draw_formula(2.0,2.0);
	glPopMatrix();
	
	glPushMatrix();	
	glTranslatef(0.0+ky3,4.0+kx3,-5);
	glBindTexture( GL_TEXTURE_2D, Zadniy_fon_04 );
	quads_draw_sxema_1(4.3,3.0);
	glPopMatrix();
	
	glPushMatrix();	
	glTranslatef(0.0-kx0*3,3.0-ky0*3,-5);
	glBindTexture( GL_TEXTURE_2D, Zadniy_fon_05 );
	quads_draw_sxema_1(4.8,3.0);
	glPopMatrix();
	
	glPushMatrix();	
	glTranslatef(4.0+kx1,-2.0+ky1,-5);
	glBindTexture( GL_TEXTURE_2D, Zadniy_fon_06 );
	quads_draw_sxema_1(4.0,3.0);
	glPopMatrix();
	
	glPushMatrix();	
	glTranslatef(0.0+kx2,-5.0+ky2,-5);
	glBindTexture( GL_TEXTURE_2D, Zadniy_fon_07 );
	quads_draw_sxema_4(4.5,3.0);
	glPopMatrix();
	
	glPushMatrix();	
	glTranslatef(-4.0+kx3*2.5,2.0+ky3*1.5,-5);
	glBindTexture( GL_TEXTURE_2D, Zadniy_fon_08 );
	quads_draw_sxema_1(4.0,3.0);
	glPopMatrix();
	
	glPushMatrix();	
	glTranslatef(-4.0-kx1,-4.0-ky1,-5);
	glBindTexture( GL_TEXTURE_2D, Zadniy_fon_09 );
	quads_draw_sxema_1(4.0,3.0);
	glPopMatrix();	
	
	glColor4f(1.0,1.0,1.0,1.0);

    glDisable(GL_BLEND);
    glDisable(GL_TEXTURE_2D);
end;	

end.

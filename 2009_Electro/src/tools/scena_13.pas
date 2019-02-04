{$R-}
{$MODE DELPHI}
unit scena_13;
interface
uses sdl, gl,  glu,  SysUtils, glut, glext,text_glut,  text_gl,  ogl_texture,menu;

const
SPEED0=0.0007;
SPEED1=0.006;
SPEED2=0.0055;
SPEED3=0.005;
SPEED_T=0.0005;
PATH_TEXTURE='../data/textures/';

var
Font_base : GLuint;
Ten_1:GLUInt;
Ten_2:GLUInt;
Ten_3:GLUInt;
Opisanie_avtor_1:GLUInt;
Opisanie_avtor_2:GLUInt;
Opisanie_avtor_3:GLUInt;
Avtor_1:GLUInt;
Avtor_2:GLUInt;
Avtor_3:GLUInt;
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
procedure anim_proc_scena_13();
procedure load_texture_scena_13();
procedure ogl_on_start_scena_13(width,height:glInt);
procedure key_pressed_scena_13( keysym : PSDL_keysym );
procedure mouse_button_pressed_scena_13 ( button : TSDL_MouseButtonEvent );
procedure mouse_motion_scena_13( motion :  TSDL_MouseMotionEvent );
procedure fon_draw_scena_13();
procedure title_draw_scena_13();
procedure quads_draw_avtor(size_x,size_y:GLFloat);
procedure quads_draw_Opisanie_avtor(size_x,size_y:GLFloat);

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
procedure anim_proc_scena_13();
begin
		patch_0();
		patch_1();
		patch_2();
		patch_3();
		patch_4();
end;

///////////////////////////////////////////////////////////////////////////////////
procedure load_texture_scena_13();
begin
	OGL_Load_Texture(PATH_TEXTURE+'Opisanie_avtor_1.bmp', Opisanie_avtor_1, txBilinear, GL_REPLACE, GL_CLAMP, txNoCompressed,GL_TRUE);
	OGL_Load_Texture(PATH_TEXTURE+'Opisanie_avtor_2.bmp', Opisanie_avtor_2, txBilinear, GL_REPLACE, GL_CLAMP, txNoCompressed,GL_TRUE);
	OGL_Load_Texture(PATH_TEXTURE+'Opisanie_avtor_3.bmp', Opisanie_avtor_3, txBilinear, GL_REPLACE, GL_CLAMP, txNoCompressed,GL_TRUE);
	OGL_Load_Texture(PATH_TEXTURE+'Avtor_1.tga', Avtor_1, txBilinear, GL_REPLACE, GL_CLAMP, txNoCompressed,GL_TRUE);
	OGL_Load_Texture(PATH_TEXTURE+'Avtor_2.tga', Avtor_2, txBilinear, GL_REPLACE, GL_CLAMP, txNoCompressed,GL_TRUE);
	OGL_Load_Texture(PATH_TEXTURE+'Avtor_3_1.tga', Avtor_3, txBilinear, GL_REPLACE, GL_CLAMP, txNoCompressed,GL_TRUE);
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
end;

//////////////////////////////////////////////////////////////////////////////////////
procedure ogl_on_start_scena_13(width,height:glInt);
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
procedure key_pressed_scena_13( keysym : PSDL_keysym );
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
procedure mouse_button_pressed_scena_13 ( button : TSDL_MouseButtonEvent );
begin
	mouse_button_pressed_menu(button);	
end;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
procedure mouse_motion_scena_13( motion :  TSDL_MouseMotionEvent );
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
procedure title_draw_scena_13();
begin
	glColor4f(1.0,1.0,1.0,1.0);
	glEnable(GL_BLEND);
	glEnable(GL_TEXTURE_2D);
	glBlendFunc(GL_ONE,GL_ONE_MINUS_SRC_ALPHA);
	glPushMatrix();	
	glTranslatef(0.0, 6.0,-2.0);
	glBindTexture( GL_TEXTURE_2D, Zagolovok_0_1 );
	quads_draw_zagolovok_0_1(5.5,0.5);
	glPopMatrix();	
	
	glPushMatrix();	
	glTranslatef(0.0, 4.0,-2.0);
	glBindTexture( GL_TEXTURE_2D, Zagolovok_0_2 );
	quads_draw_zagolovok_0_2(8.0,1.5);
	glPopMatrix();
	glColor4f(1.0,1.0,1.0,1.0);
    glDisable(GL_BLEND);
    glDisable(GL_TEXTURE_2D);
end;
//////////////////////////////////////////////////////////////////////////////////////
procedure quads_draw_avtor(size_x,size_y:GLFloat);
begin
	
	glBegin(GL_QUADS);
			glTexCoord2f(0.0,0.0);glVertex3f(-1.0*size_x,-1.0*size_y,-1.0);
			glTexCoord2f(1.0,0.0);glVertex3f(1.0*size_x,-1.0*size_y,-1.0);
			glTexCoord2f(1.0,1.0);glVertex3f(1.0*size_x,1.0*size_y,-1.0);
			glTexCoord2f(0.0,1.0);glVertex3f(-1.0*size_x, 1.0*size_y,-1.0);
	glEnd();
	 
end;

////////////////////////////////////////////////////////////////////////////////////////
procedure quads_draw_Opisanie_avtor(size_x,size_y:GLFloat);
begin
	
	glBegin(GL_QUADS);
			glTexCoord2f(0.0,0.0);glVertex3f(-1.0*size_x,-0.5*size_y,-1.0);
			glTexCoord2f(1.0,0.0);glVertex3f(1.0*size_x,-0.5*size_y,-1.0);
			glTexCoord2f(1.0,1.0);glVertex3f(1.0*size_x,0.5*size_y,-1.0);
			glTexCoord2f(0.0,1.0);glVertex3f(-1.0*size_x, 0.5*size_y,-1.0);
	glEnd();
	 
end;
///////////////////////////////////////////////////////////////////////////////////////
//процедура отрисовки основной сцены 
procedure fon_draw_scena_13();
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
		
	glColor3f(1.0,1.0,1.0);

		glPushMatrix();	
	glTranslatef(-5.0, 1.0,-2.0);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glBindTexture( GL_TEXTURE_2D, Avtor_1 );
	quads_draw_avtor(1.5,2.0);
	glPopMatrix();
	
		glPushMatrix();	
	glTranslatef(0.0, 1.0,-2.0);
	case Blend_func of
		0:glBlendFunc(GL_ZERO,GL_ZERO);
		1:glBlendFunc(GL_ZERO,GL_ONE);
		2:glBlendFunc(GL_ZERO,GL_SRC_COLOR);
		3:glBlendFunc(GL_ZERO,GL_ONE_MINUS_SRC_COLOR);
		4:glBlendFunc(GL_ZERO,GL_DST_COLOR);
		5:glBlendFunc(GL_ZERO,GL_ONE_MINUS_DST_COLOR);
		6:glBlendFunc(GL_ZERO,GL_SRC_ALPHA);
		7:glBlendFunc(GL_ZERO,GL_ONE_MINUS_SRC_ALPHA);
		8:glBlendFunc(GL_ZERO,GL_DST_ALPHA);
		9:glBlendFunc(GL_ZERO,GL_ONE_MINUS_DST_ALPHA);
		10:glBlendFunc(GL_ONE,GL_ZERO);
		11:glBlendFunc(GL_ONE,GL_ONE);
		12:glBlendFunc(GL_ONE,GL_SRC_COLOR);
		13:glBlendFunc(GL_ONE,GL_ONE_MINUS_SRC_COLOR);
		14:glBlendFunc(GL_ONE,GL_DST_COLOR);
		15:glBlendFunc(GL_ONE,GL_ONE_MINUS_DST_COLOR);
		16:glBlendFunc(GL_ONE,GL_SRC_ALPHA);
		17:glBlendFunc(GL_ONE,GL_ONE_MINUS_SRC_ALPHA);
		18:glBlendFunc(GL_ONE,GL_DST_ALPHA);
		19:glBlendFunc(GL_ONE,GL_ONE_MINUS_DST_ALPHA);
		20:glBlendFunc(GL_SRC_COLOR,GL_ZERO);
		21:glBlendFunc(GL_SRC_COLOR,GL_ONE);
		22:glBlendFunc(GL_SRC_COLOR,GL_SRC_COLOR);
		23:glBlendFunc(GL_SRC_COLOR,GL_ONE_MINUS_SRC_COLOR);
		24:glBlendFunc(GL_SRC_COLOR,GL_DST_COLOR);
		25:glBlendFunc(GL_SRC_COLOR,GL_ONE_MINUS_DST_COLOR);
		26:glBlendFunc(GL_SRC_COLOR,GL_SRC_ALPHA);
		27:glBlendFunc(GL_SRC_COLOR,GL_ONE_MINUS_SRC_ALPHA);
		28:glBlendFunc(GL_SRC_COLOR,GL_DST_ALPHA);
		29:glBlendFunc(GL_SRC_COLOR,GL_ONE_MINUS_DST_ALPHA);
		30:glBlendFunc(GL_ONE_MINUS_SRC_COLOR,GL_ZERO);
		31:glBlendFunc(GL_ONE_MINUS_SRC_COLOR,GL_ONE);
		32:glBlendFunc(GL_ONE_MINUS_SRC_COLOR,GL_SRC_COLOR);
		33:glBlendFunc(GL_ONE_MINUS_SRC_COLOR,GL_ONE_MINUS_SRC_COLOR);
		34:glBlendFunc(GL_ONE_MINUS_SRC_COLOR,GL_DST_COLOR);
		35:glBlendFunc(GL_ONE_MINUS_SRC_COLOR,GL_ONE_MINUS_DST_COLOR);
		36:glBlendFunc(GL_ONE_MINUS_SRC_COLOR,GL_SRC_ALPHA);
		37:glBlendFunc(GL_ONE_MINUS_SRC_COLOR,GL_ONE_MINUS_SRC_ALPHA);
		38:glBlendFunc(GL_ONE_MINUS_SRC_COLOR,GL_DST_ALPHA);
		39:glBlendFunc(GL_ONE_MINUS_SRC_COLOR,GL_ONE_MINUS_DST_ALPHA);
		40:glBlendFunc(GL_DST_COLOR,GL_ZERO);
		41:glBlendFunc(GL_DST_COLOR,GL_ONE);
		42:glBlendFunc(GL_DST_COLOR,GL_SRC_COLOR);
		43:glBlendFunc(GL_DST_COLOR,GL_ONE_MINUS_SRC_COLOR);
		44:glBlendFunc(GL_DST_COLOR,GL_DST_COLOR);
		45:glBlendFunc(GL_DST_COLOR,GL_ONE_MINUS_DST_COLOR);
		46:glBlendFunc(GL_DST_COLOR,GL_SRC_ALPHA);
		47:glBlendFunc(GL_DST_COLOR,GL_ONE_MINUS_SRC_ALPHA);
		48:glBlendFunc(GL_DST_COLOR,GL_DST_ALPHA);
		49:glBlendFunc(GL_DST_COLOR,GL_ONE_MINUS_DST_ALPHA);
		50:glBlendFunc(GL_ONE_MINUS_DST_COLOR,GL_ZERO);
		51:glBlendFunc(GL_ONE_MINUS_DST_COLOR,GL_ONE);
		52:glBlendFunc(GL_ONE_MINUS_DST_COLOR,GL_SRC_COLOR);
		53:glBlendFunc(GL_ONE_MINUS_DST_COLOR,GL_ONE_MINUS_SRC_COLOR);
		54:glBlendFunc(GL_ONE_MINUS_DST_COLOR,GL_DST_COLOR);
		55:glBlendFunc(GL_ONE_MINUS_DST_COLOR,GL_ONE_MINUS_DST_COLOR);
		56:glBlendFunc(GL_ONE_MINUS_DST_COLOR,GL_SRC_ALPHA);
		57:glBlendFunc(GL_ONE_MINUS_DST_COLOR,GL_ONE_MINUS_SRC_ALPHA);
		58:glBlendFunc(GL_ONE_MINUS_DST_COLOR,GL_DST_ALPHA);
		59:glBlendFunc(GL_ONE_MINUS_DST_COLOR,GL_ONE_MINUS_DST_ALPHA);
		60:glBlendFunc(GL_SRC_ALPHA,GL_ZERO);
		61:glBlendFunc(GL_SRC_ALPHA,GL_ONE);
		62:glBlendFunc(GL_SRC_ALPHA,GL_SRC_COLOR);
		63:glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_COLOR);
		64:glBlendFunc(GL_SRC_ALPHA,GL_DST_COLOR);
		65:glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_DST_COLOR);
		66:glBlendFunc(GL_SRC_ALPHA,GL_SRC_ALPHA);
		67:glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
		68:glBlendFunc(GL_SRC_ALPHA,GL_DST_ALPHA);
		69:glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_DST_ALPHA);
		70:glBlendFunc(GL_ONE_MINUS_SRC_ALPHA,GL_ZERO);
		71:glBlendFunc(GL_ONE_MINUS_SRC_ALPHA,GL_ONE);
		72:glBlendFunc(GL_ONE_MINUS_SRC_ALPHA,GL_SRC_COLOR);
		73:glBlendFunc(GL_ONE_MINUS_SRC_ALPHA,GL_ONE_MINUS_SRC_COLOR);
		74:glBlendFunc(GL_ONE_MINUS_SRC_ALPHA,GL_DST_COLOR);
		75:glBlendFunc(GL_ONE_MINUS_SRC_ALPHA,GL_ONE_MINUS_DST_COLOR);
		76:glBlendFunc(GL_ONE_MINUS_SRC_ALPHA,GL_SRC_ALPHA);
		77:glBlendFunc(GL_ONE_MINUS_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
		78:glBlendFunc(GL_ONE_MINUS_SRC_ALPHA,GL_DST_ALPHA);
		79:glBlendFunc(GL_ONE_MINUS_SRC_ALPHA,GL_ONE_MINUS_DST_ALPHA);
		80:glBlendFunc(GL_DST_ALPHA,GL_ZERO);
		81:glBlendFunc(GL_DST_ALPHA,GL_ONE);
		82:glBlendFunc(GL_DST_ALPHA,GL_SRC_COLOR);
		83:glBlendFunc(GL_DST_ALPHA,GL_ONE_MINUS_SRC_COLOR);
		84:glBlendFunc(GL_DST_ALPHA,GL_DST_COLOR);
		85:glBlendFunc(GL_DST_ALPHA,GL_ONE_MINUS_DST_COLOR);
		86:glBlendFunc(GL_DST_ALPHA,GL_SRC_ALPHA);
		87:glBlendFunc(GL_DST_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
		88:glBlendFunc(GL_DST_ALPHA,GL_DST_ALPHA);
		89:glBlendFunc(GL_DST_ALPHA,GL_ONE_MINUS_DST_ALPHA);
		90:glBlendFunc(GL_ONE_MINUS_DST_ALPHA,GL_ZERO);
		91:glBlendFunc(GL_ONE_MINUS_DST_ALPHA,GL_ONE);
		92:glBlendFunc(GL_ONE_MINUS_DST_ALPHA,GL_SRC_COLOR);
		93:glBlendFunc(GL_ONE_MINUS_DST_ALPHA,GL_ONE_MINUS_SRC_COLOR);
		94:glBlendFunc(GL_ONE_MINUS_DST_ALPHA,GL_DST_COLOR);
		95:glBlendFunc(GL_ONE_MINUS_DST_ALPHA,GL_ONE_MINUS_DST_COLOR);
		96:glBlendFunc(GL_ONE_MINUS_DST_ALPHA,GL_SRC_ALPHA);
		97:glBlendFunc(GL_ONE_MINUS_DST_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
		98:glBlendFunc(GL_ONE_MINUS_DST_ALPHA,GL_DST_ALPHA);
		99:glBlendFunc(GL_ONE_MINUS_DST_ALPHA,GL_ONE_MINUS_DST_ALPHA);
		100:glBlendFunc(GL_SRC_ALPHA_SATURATE,GL_ZERO);
		101:glBlendFunc(GL_SRC_ALPHA_SATURATE,GL_ONE);
		102:glBlendFunc(GL_SRC_ALPHA_SATURATE,GL_SRC_COLOR);
		103:glBlendFunc(GL_SRC_ALPHA_SATURATE,GL_ONE_MINUS_SRC_COLOR);
		104:glBlendFunc(GL_SRC_ALPHA_SATURATE,GL_DST_COLOR);
		105:glBlendFunc(GL_SRC_ALPHA_SATURATE,GL_ONE_MINUS_DST_COLOR);
		106:glBlendFunc(GL_SRC_ALPHA_SATURATE,GL_SRC_ALPHA);
		107:glBlendFunc(GL_SRC_ALPHA_SATURATE,GL_ONE_MINUS_SRC_ALPHA);
		108:glBlendFunc(GL_SRC_ALPHA_SATURATE,GL_DST_ALPHA);
		109:glBlendFunc(GL_SRC_ALPHA_SATURATE,GL_ONE_MINUS_DST_ALPHA);
	else
		glBlendFunc(GL_ONE, GL_ZERO);
	end;	
	
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glBindTexture( GL_TEXTURE_2D, Avtor_2 );
	quads_draw_avtor(1.7,2.0);
	glPopMatrix();
	
		glPushMatrix();	
	glTranslatef(5.0, 1.0,-2.0);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glBindTexture( GL_TEXTURE_2D, Avtor_3 );
	quads_draw_avtor(1.8,2.0);
	glPopMatrix();
	
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	glColor3f(0.9450,0.9098,0.4314);
	glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_COLOR);
		glPushMatrix();	
	glTranslatef(-5.0, -3.0,-2.0);
	
	glBindTexture( GL_TEXTURE_2D, Opisanie_avtor_1 );
	quads_draw_avtor(2.0,2.0);
	glPopMatrix();
	
		glPushMatrix();	
	glTranslatef(0.0, -3.0,-2.0);
	glBindTexture( GL_TEXTURE_2D, Opisanie_avtor_2 );
	quads_draw_avtor(2.0,2.0);
	glPopMatrix();
	
		glPushMatrix();	
	glTranslatef(5.0, -3.0,-2.0);	
	glBindTexture( GL_TEXTURE_2D, Opisanie_avtor_3 );
	quads_draw_avtor(2.0,2.0);
	glPopMatrix();
	
    glDisable(GL_BLEND);
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
{	glColor3f(0.0,0.0,0.0);
	glPushMatrix();	
	glTranslatef(-4.9, 1.1,-2.1);
	glBindTexture( GL_TEXTURE_2D, Ten_1 );
	quads_draw_avtor(1.5,2.0);
	glPopMatrix();
	
	glPushMatrix();	
	glTranslatef(0.2, 1.1,-2.1);
	glBindTexture( GL_TEXTURE_2D, Ten_2 );
	quads_draw_avtor(1.7,2.0);
	glPopMatrix();
	
	glPushMatrix();	
	glTranslatef(5.3, 1.1,-2.1);
	glBindTexture( GL_TEXTURE_2D, Ten_3 );
	quads_draw_avtor(1.8,2.0);
	glPopMatrix();}
    glDisable(GL_TEXTURE_2D);
end;	

end.

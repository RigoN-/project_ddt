{$R-}
{$MODE DELPHI}
unit scena_4;
interface
uses sdl, gl,  glu,  SysUtils, glut, glext,text_glut,  text_gl,  ogl_texture,  menu, shema;

const
PATH_TEXTURE='../data/textures/';

var
Font_base : GLuint;
Zadniy_fon_00:GLUInt;
Zadniy_fon_01:GLUInt;
Zadniy_fon_02:GLUInt;
Zadniy_fon_03:GLUInt;
Zadniy_fon_04:GLUInt;
Zadniy_fon_05:GLUInt;
ky0,kx0,kx1,ky1,kx2,ky2,kx3,ky3,ch3,a3,r3,s:GLFloat;
patch:Boolean=true;
Blend_func:GLUInt=0;


procedure load_texture_scena_4();
procedure ogl_on_start_scena_4(width,height:glInt);
procedure key_pressed_scena_4( keysym : PSDL_keysym );
procedure mouse_button_pressed_scena_4 ( button : TSDL_MouseButtonEvent );
procedure mouse_motion_scena_4( motion :  TSDL_MouseMotionEvent );
procedure fon_draw_scena_4();
procedure  shema_draw_scena_4(begunok: glFloat; on_off: GLInt);
procedure quads_draw_okno_1(size_x,size_y:GLFloat);
implementation
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////
procedure load_texture_scena_4();
begin
	OGL_Load_Texture(PATH_TEXTURE+'op4_ris1.bmp', Zadniy_fon_01, txBilinear, GL_MODULATE, GL_CLAMP, txNoCompressed,GL_TRUE);
	OGL_Load_Texture(PATH_TEXTURE+'opisanie_op_4.bmp', Zadniy_fon_02, txBilinear, GL_MODULATE, GL_CLAMP, txNoCompressed,GL_TRUE);
end;
//////////////////////////////////////////////////////////////////////////////////////
procedure ogl_on_start_scena_4(width,height:glInt);
begin
 	ogl_on_start_shema();  
end;

procedure key_pressed_scena_4( keysym : PSDL_keysym );
begin
	case keysym.sym of		
		SDLK_b:
			begin
				blend_func:=blend_func+1;
				if blend_func > 109 then
					blend_func:=0;
			end;
		SDLK_1:begin id_shema_draw:=1;on_off:=-1;end;
		SDLK_2:begin id_shema_draw:=2;on_off:=-1;end;
		SDLK_3:begin id_shema_draw:=3;on_off:=-1;end;
		SDLK_z:
			begin
				if opisanie_enable = GL_TRUE then
					opisanie_enable:=GL_FALSE
				else
					opisanie_enable:=GL_TRUE;	
			end;
		end;
end;

procedure mouse_button_pressed_scena_4 ( button : TSDL_MouseButtonEvent );
begin
	mouse_button_pressed_menu(button);
end;


procedure mouse_motion_scena_4( motion :  TSDL_MouseMotionEvent );
begin
	mouse_motion_menu(motion);
end;

/////////////////////////////////////////////////////////////////////////////////////
procedure quads_draw_okno_1(size_x,size_y:GLFloat);
begin
	
	glBegin(GL_QUADS);
			glTexCoord2f(0.0,0.0);glVertex3f(-1.0*size_x,-1.0*size_y,-1.0);
			glTexCoord2f(1.0,0.0);glVertex3f(1.0*size_x,-1.0*size_y,-1.0);
			glTexCoord2f(1.0,1.0);glVertex3f(1.0*size_x,1.0*size_y,-1.0);
			glTexCoord2f(0.0,1.0);glVertex3f(-1.0*size_x, 1.0*size_y,-1.0);
	glEnd();
	 
end;
////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////
//��������� ��������� �������� ����� 
procedure  shema_draw_scena_4(begunok: glFloat; on_off: GLInt);
begin
    glPushMatrix();	
    glTranslatef(0.0,-3.0,-8.0);
    glRotatef(20,1.0,0.0,0.0);
    glRotatef(povorot,0.0,1.0,0.0);
		case id_shema_draw of
		1:shema_7(begunok,on_off,1);
		2:shema_7(begunok,on_off,2);
		3:shema_7(begunok,on_off,3);
		end;
    glPopMatrix();
end;

procedure fon_draw_scena_4();
begin
	glEnable(GL_TEXTURE_2D);		
	
	//glColor4f(0.1294,0.4941,0.54235,1.0);
	glColor4f(1.0,1.0,1.0,1.0);
	glEnable(GL_BLEND);
	glBlendFunc(GL_ONE,GL_ONE);

	
	if opisanie_enable=GL_TRUE then		
	begin
	glPushMatrix();	
	glBindTexture( GL_TEXTURE_2D, Zadniy_fon_01 );
	glTranslatef(4.0,2.5,0.0);
	quads_draw_okno_1(3.0,1.5);
	glPopMatrix();
	
	glPushMatrix();	
	glBindTexture( GL_TEXTURE_2D, Zadniy_fon_02 );
	glTranslatef(-3.2,2.4,0.0);
	quads_draw_okno_1(3.7, 2.7);
	glPopMatrix();
	end;
	glColor4f(1.0,1.0,1.0,1.0);

    glDisable(GL_BLEND);
    glDisable(GL_TEXTURE_2D);
end;	

end.

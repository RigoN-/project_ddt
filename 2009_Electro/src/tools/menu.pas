{$R-}
{$MODE DELPHI}
unit menu;
interface
uses sdl, gl,  glu,  SysUtils, glut, glext,text_glut,  text_gl,  ogl_texture;

const
PATH_TEXTURE='../data/textures/';

var
on_off : GLInt=-1;
begunok: glFloat=0.0;
bt_01,bt_02,bt_03,bt_04,bt_05,bt_06,bt_07,bt_08,bt_09,bt_10,bt_11,bt_12,bt_13,bt_15:GLUInt;
wx,wy:glInt;
 sx,sy, kx, ky:glFloat;
 w_width, w_height: GLUint;
 w_inf0:PSDL_VideoInfo;
id_button: GLUint;
id_scena_draw:GLUInt;
id_shema_draw:GLUInt=1;
opisanie_enable:GLBoolean=GL_TRUE;
povorot: glFloat=-20;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
procedure menu_draw();
procedure load_texture_menu();
procedure ogl_on_start_menu(width,height:glInt);
procedure mouse_motion_menu( motion :  TSDL_MouseMotionEvent );
procedure mouse_button_pressed_menu ( button : TSDL_MouseButtonEvent );

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
implementation

procedure quit_menu();
begin
	SDL_QUIT;
	Halt(0);
end;

procedure load_texture_menu();
begin	
	OGL_Load_Texture(PATH_TEXTURE+'bt_01_1.tga', bt_01, txTrilinear, GL_MODULATE, GL_REPEAT, txNoCompressed,GL_TRUE);
	OGL_Load_Texture(PATH_TEXTURE+'bt_02_1.tga', bt_02, txTrilinear, GL_MODULATE, GL_REPEAT, txNoCompressed,GL_TRUE);
	OGL_Load_Texture(PATH_TEXTURE+'bt_03_1.tga', bt_03, txTrilinear, GL_MODULATE, GL_REPEAT, txNoCompressed,GL_TRUE);
	OGL_Load_Texture(PATH_TEXTURE+'bt_04_1.tga', bt_04, txTrilinear, GL_MODULATE, GL_REPEAT, txNoCompressed,GL_TRUE);
	OGL_Load_Texture(PATH_TEXTURE+'bt_05_1.tga', bt_05, txTrilinear, GL_MODULATE, GL_REPEAT, txNoCompressed,GL_TRUE);
	OGL_Load_Texture(PATH_TEXTURE+'bt_06_1.tga', bt_06, txTrilinear, GL_MODULATE, GL_REPEAT, txNoCompressed,GL_TRUE);
	OGL_Load_Texture(PATH_TEXTURE+'bt_07_1.tga', bt_07, txTrilinear, GL_MODULATE, GL_REPEAT, txNoCompressed,GL_TRUE);
	OGL_Load_Texture(PATH_TEXTURE+'bt_08_1.tga', bt_08, txTrilinear, GL_MODULATE, GL_REPEAT, txNoCompressed,GL_TRUE);
	OGL_Load_Texture(PATH_TEXTURE+'bt_09_1.tga', bt_09, txTrilinear, GL_MODULATE, GL_REPEAT, txNoCompressed,GL_TRUE);
	OGL_Load_Texture(PATH_TEXTURE+'bt_10_1.tga', bt_10, txTrilinear, GL_MODULATE, GL_REPEAT, txNoCompressed,GL_TRUE);
	OGL_Load_Texture(PATH_TEXTURE+'bt_11_1.tga', bt_11, txTrilinear, GL_MODULATE, GL_REPEAT, txNoCompressed,GL_TRUE);
	OGL_Load_Texture(PATH_TEXTURE+'bt_12_1.tga', bt_12, txTrilinear, GL_MODULATE, GL_REPEAT, txNoCompressed,GL_TRUE);
	OGL_Load_Texture(PATH_TEXTURE+'bt_13_1.tga', bt_13, txTrilinear, GL_MODULATE, GL_REPEAT, txNoCompressed,GL_TRUE);
	OGL_Load_Texture(PATH_TEXTURE+'bt_15_1.tga', bt_15, txTrilinear, GL_MODULATE, GL_REPEAT, txNoCompressed,GL_TRUE);
end;


procedure ogl_on_start_menu(width,height:glInt);
begin	
	kx:=width/1024;
    ky:=height/768;
    sx:=120.0;
    sy:=40.0; 
    w_inf0:=SDL_GetVideoInfo;
end;

procedure mouse_motion_menu( motion :  TSDL_MouseMotionEvent );
begin
//write ('x = ', motion.x,' y = ', motion.y, 'xrel = ', motion.xrel,' yrel = ', motion.yrel);
id_button:=0;
wx:=motion.x; wy:=motion.y;
if ((wx >= 70*kx)  and (wx<= 70*kx+sx*kx)) then
if ((wy>= w_inf0.current_h - 40*ky*2) and (wy<=w_inf0.current_h - 40*ky)) then	
	id_button:=1;
	
if ((wx >= 70*kx  + kx*sx +2)  and (wx<= 70*kx+sx*kx *2 +2)) then
if ((wy>= w_inf0.current_h - 40*ky*2) and (wy<=w_inf0.current_h - 40*ky)) then
	id_button:=2;
	
if ((wx>= (70*kx+sx*kx *2 +2))  and (wx<= (70*kx+sx*kx *3 +2))) then
if ((wy>= w_inf0.current_h - 40*ky*2) and (wy<=w_inf0.current_h - 40*ky)) then	
	id_button:=3;

if ((wx>= (70*kx+sx*kx *3 +2))  and (wx<= (70*kx+sx*kx *4 +2))) then
if ((wy>= w_inf0.current_h - 40*ky*2) and (wy<=w_inf0.current_h - 40*ky)) then	
	id_button:=4;
	
if ((wx>= (70*kx+sx*kx *4 +2))  and (wx<= (70*kx+sx*kx *5 +2))) then
if ((wy>= w_inf0.current_h - 40*ky*2) and (wy<=w_inf0.current_h - 40*ky)) then	
	id_button:=5;

if ((wx>= (70*kx+sx*kx *5 +2))  and (wx<= (70*kx+sx*kx *6 +2))) then
if ((wy>= w_inf0.current_h - 40*ky*2) and (wy<=w_inf0.current_h - 40*ky)) then	
	id_button:=6;

if ((wx>= (70*kx+sx*kx *6 +2))  and (wx<= (70*kx+sx*kx *7 +2))) then
if ((wy>= w_inf0.current_h - 40*ky*2) and (wy<=w_inf0.current_h - 40*ky)) then	
	id_button:=7;
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

if ((wx >= 70*kx)  and (wx<= 70*kx+sx*kx)) then
if ((wy>= w_inf0.current_h - 40*ky+3) and (wy<=w_inf0.current_h - 1 )) then
	id_button:=8;
	
if ((wx >= 70*kx  + kx*sx +2)  and (wx<= 70*kx+sx*kx *2 +2)) then
if ((wy>= w_inf0.current_h - 40*ky+3) and (wy<=w_inf0.current_h - 1 )) then	
	id_button:=9;
	
if ((wx>= (70*kx+sx*kx *2 +2))  and (wx<= (70*kx+sx*kx *3 +2))) then
if ((wy>= w_inf0.current_h - 40*ky+3) and (wy<=w_inf0.current_h - 1 )) then	
	id_button:=10;

if ((wx>= (70*kx+sx*kx *3 +2))  and (wx<= (70*kx+sx*kx *4 +2))) then
if ((wy>= w_inf0.current_h - 40*ky+3) and (wy<=w_inf0.current_h - 1 )) then	
	id_button:=11;
	
if ((wx>= (70*kx+sx*kx *4 +2))  and (wx<= (70*kx+sx*kx *5 +2))) then
if ((wy>= w_inf0.current_h - 40*ky+3) and (wy<=w_inf0.current_h - 1 )) then	
	id_button:=12;

if ((wx>= (70*kx+sx*kx *5 +2))  and (wx<= (70*kx+sx*kx *6 +2))) then
if ((wy>= w_inf0.current_h - 40*ky+3) and (wy<=w_inf0.current_h - 1 )) then	
	id_button:=13;

if ((wx>= (70*kx+sx*kx *6 +2))  and (wx<= (70*kx+sx*kx *7 +2))) then
if ((wy>= w_inf0.current_h - 40*ky+3) and (wy<=w_inf0.current_h - 1 )) then	
	id_button:=14;
	//writeln('Button', id_button, ' x -', wx, ' y -', wy);
end;

procedure mouse_button_pressed_menu ( button : TSDL_MouseButtonEvent );
begin
	case button.button of
		SDL_BUTTON_LEFT :
			begin
				case id_button of
		1 :
			begin
			id_scena_draw:=1;id_shema_draw:=1;on_off:=-1;begunok:=0;povorot:=-20;
			end;
		2 :
			begin
			id_scena_draw:=2;id_shema_draw:=1;on_off:=-1;begunok:=0;povorot:=-20;
			end;
		3 :
			begin
			id_scena_draw:=3;id_shema_draw:=1;on_off:=-1;begunok:=0;povorot:=-20;
			end;
		4 :
			begin
			id_scena_draw:=4;id_shema_draw:=1;on_off:=-1;begunok:=0;povorot:=-20;
			end;
		5 :
			begin
			id_scena_draw:=5;id_shema_draw:=1;on_off:=-1;begunok:=0;povorot:=-20;
			end;
		6 :
			begin
			id_scena_draw:=6;id_shema_draw:=1;on_off:=-1;begunok:=0;povorot:=-20;
			end;
		7 :
			begin
			id_scena_draw:=7;id_shema_draw:=1;on_off:=-1;begunok:=0;povorot:=-20;
			end;
		8 :
			begin
			id_scena_draw:=8;id_shema_draw:=1;on_off:=-1;begunok:=0;povorot:=-20;
			end;
		9 :
			begin
			id_scena_draw:=9;id_shema_draw:=1;on_off:=-1;begunok:=0;povorot:=-20;
			end;
		10 :
			begin
			id_scena_draw:=10;id_shema_draw:=1;on_off:=-1;begunok:=0;povorot:=-20;
			end;
		11 :
			begin
			id_scena_draw:=11;id_shema_draw:=1;on_off:=-1;begunok:=0;povorot:=-20;
			end;
		12 :
			begin
			id_scena_draw:=12;id_shema_draw:=1;on_off:=-1;begunok:=0;povorot:=-20;
			end;
		13  :
			id_scena_draw:=13;
		14  :
			quit_menu();
				end;
			end;
		SDL_BUTTON_MIDDLE :;
		SDL_BUTTON_RIGHT :;
		SDL_BUTTON_WHEELUP :;
		SDL_BUTTON_WHEELDOWN :;
	end;
end;


procedure bt_draw(size_x,size_y:GLFloat);
begin
	
	glBegin(GL_QUADS);
			glTexCoord2f(0.0,0.0);glVertex3f(0.0*size_x,0.0*size_y,0.0);
			glTexCoord2f(1.0,0.0);glVertex3f(1.0*size_x,0.0*size_y,0.0);
			glTexCoord2f(1.0,1.0);glVertex3f(1.0*size_x,1.0*size_y,0.0);
			glTexCoord2f(0.0,1.0);glVertex3f(0.0*size_x, 1.0*size_y,0.0);
	glEnd();
	
end;

procedure menu_draw();
var
mx,my, dx, dy:glFloat;
begin
   
    dx:=sx+2;
    dy:=sy+1;
   
    mx:=70.0*kx;
    my:=40.0*ky;
	glColor4f(1.0,1.0,1.0,1.0);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_COLOR,GL_ONE_MINUS_SRC_COLOR);
//********menu************************************	
	if id_button = 1 then 
	glBlendFunc(GL_ONE,GL_DST_ALPHA);
	glPushMatrix();	
	glTranslatef(mx, my,0.0);
	glBindTexture( GL_TEXTURE_2D, bt_01 );
	 bt_draw(sx*kx,sy*ky);
	glPopMatrix();
	glBlendFunc(GL_SRC_COLOR,GL_ONE_MINUS_SRC_COLOR);
//-------------------------------------------------------------------------------	
    if id_button = 2 then 
	glBlendFunc(GL_ONE,GL_DST_ALPHA);
     mx:=mx+dx*kx;
	glPushMatrix();	
	glTranslatef(mx, my,0.0);
	glBindTexture( GL_TEXTURE_2D, bt_02 );
	bt_draw(sx*kx,sy*ky);
	glPopMatrix();
	glBlendFunc(GL_SRC_COLOR,GL_ONE_MINUS_SRC_COLOR);
//-------------------------------------------------------------------------------	
	 if id_button = 3 then 
	glBlendFunc(GL_ONE,GL_DST_ALPHA);	
	mx:=mx+dx*kx;
	glPushMatrix();	
	glTranslatef(mx, my,0.0);
	glBindTexture( GL_TEXTURE_2D, bt_03 );
	 bt_draw(sx*kx,sy*ky);
	glPopMatrix();
	glBlendFunc(GL_SRC_COLOR,GL_ONE_MINUS_SRC_COLOR);
//-------------------------------------------------------------------------------	
	if id_button = 4 then 
	glBlendFunc(GL_ONE,GL_DST_ALPHA);	
	mx:=mx+dx*kx;
	glPushMatrix();	
	glTranslatef(mx, my,0.0);
	glBindTexture( GL_TEXTURE_2D, bt_04 );
	bt_draw(sx*kx,sy*ky);
	glPopMatrix();
	glBlendFunc(GL_SRC_COLOR,GL_ONE_MINUS_SRC_COLOR);
//-------------------------------------------------------------------------------	
	if id_button = 5 then 
	glBlendFunc(GL_ONE,GL_DST_ALPHA);	
	mx:=mx+dx*kx;
	glPushMatrix();	
	glTranslatef(mx, my,0.0);
	glBindTexture( GL_TEXTURE_2D, bt_05 );
	bt_draw(sx*kx,sy*ky);
	glPopMatrix();
	glBlendFunc(GL_SRC_COLOR,GL_ONE_MINUS_SRC_COLOR);
//-------------------------------------------------------------------------------	
	if id_button = 6 then 
	glBlendFunc(GL_ONE,GL_DST_ALPHA);	
	mx:=mx+dx*kx;
	glPushMatrix();	
	glTranslatef(mx, my,0.0);
	glBindTexture( GL_TEXTURE_2D, bt_06 );
	bt_draw(sx*kx,sy*ky);
	glPopMatrix();
	glBlendFunc(GL_SRC_COLOR,GL_ONE_MINUS_SRC_COLOR);
//-------------------------------------------------------------------------------	
	if id_button = 7 then 
	glBlendFunc(GL_ONE,GL_DST_ALPHA);
	mx:=mx+dx*kx;
	glPushMatrix();	
	glTranslatef(mx, my,0.0);
	glBindTexture( GL_TEXTURE_2D, bt_07 );
	bt_draw(sx*kx,sy*ky);
	glPopMatrix();
	glBlendFunc(GL_SRC_COLOR,GL_ONE_MINUS_SRC_COLOR);
//-------------------------------------------------------------------------------	
    mx:=70.0*kx;
	my:=my-dy*ky;
	
	if id_button = 8 then 
	glBlendFunc(GL_ONE,GL_DST_ALPHA);
	glPushMatrix();	
	glTranslatef(mx, my,0.0);
	glBindTexture( GL_TEXTURE_2D, bt_08 );
	 bt_draw(sx*kx,sy*ky);
	glPopMatrix();
	glBlendFunc(GL_SRC_COLOR,GL_ONE_MINUS_SRC_COLOR);
//-------------------------------------------------------------------------------	
//-------------------------------------------------------------------------------  
	if id_button = 9 then 
	glBlendFunc(GL_ONE,GL_DST_ALPHA);   
     mx:=mx+dx*kx;
	glPushMatrix();	
	glTranslatef(mx, my,0.0);
	glBindTexture( GL_TEXTURE_2D, bt_09);
	bt_draw(sx*kx,sy*ky);
	glPopMatrix();
	glBlendFunc(GL_SRC_COLOR,GL_ONE_MINUS_SRC_COLOR);
//-------------------------------------------------------------------------------	
	if id_button = 10 then 
	glBlendFunc(GL_ONE,GL_DST_ALPHA);   
	 mx:=mx+dx*kx;
	glPushMatrix();	
	glTranslatef(mx, my,0.0);
	glBindTexture( GL_TEXTURE_2D, bt_10 );
	bt_draw(sx*kx,sy*ky);
	glPopMatrix();
	glBlendFunc(GL_SRC_COLOR,GL_ONE_MINUS_SRC_COLOR);
//-------------------------------------------------------------------------------	
	if id_button = 11 then 
	glBlendFunc(GL_ONE,GL_DST_ALPHA);   
	 mx:=mx+dx*kx;
	glPushMatrix();	
	glTranslatef(mx, my,0.0);
	glBindTexture( GL_TEXTURE_2D, bt_11 );
	bt_draw(sx*kx,sy*ky);
	glPopMatrix();
	glBlendFunc(GL_SRC_COLOR,GL_ONE_MINUS_SRC_COLOR);
//-------------------------------------------------------------------------------	
	if id_button = 12 then 
	glBlendFunc(GL_ONE,GL_DST_ALPHA);   
	 mx:=mx+dx*kx;
	glPushMatrix();	
	glTranslatef(mx, my,0.0);
	glBindTexture( GL_TEXTURE_2D, bt_12 );
	bt_draw(sx*kx,sy*ky);
	glPopMatrix();
	glBlendFunc(GL_SRC_COLOR,GL_ONE_MINUS_SRC_COLOR);
//-------------------------------------------------------------------------------	
	if id_button = 13 then 
	glBlendFunc(GL_ONE,GL_DST_ALPHA);
	 mx:=mx+dx*kx;
	glPushMatrix();	
	glTranslatef(mx, my,0.0);
	glBindTexture( GL_TEXTURE_2D, bt_15 );
	bt_draw(sx*kx,sy*ky);
	glPopMatrix();
	glBlendFunc(GL_SRC_COLOR,GL_ONE_MINUS_SRC_COLOR);
//-------------------------------------------------------------------------------	
	if id_button = 14 then 
	glBlendFunc(GL_ONE,GL_DST_ALPHA);
	 mx:=mx+dx*kx;
	glPushMatrix();	
	glTranslatef(mx, my,0.0);
	glBindTexture( GL_TEXTURE_2D, bt_13 );
	bt_draw(sx*kx,sy*ky);
	glPopMatrix();
	glBlendFunc(GL_SRC_COLOR,GL_ONE_MINUS_SRC_COLOR);
//-------------------------------------------------------------------------------	
	glDisable(GL_BLEND);
	glDisable(GL_TEXTURE_2D);
end;

end.

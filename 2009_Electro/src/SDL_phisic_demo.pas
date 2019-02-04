program phisic_demo_sdl;
{$MODE delphi}
uses
SysUtils, SDL, gl, glu, glext, glut, text_glut,  text_gl,  ogl_texture,scena_0,scena_1,scena_2,scena_3,scena_4,scena_5,
scena_6,scena_7,scena_8,scena_9,scena_10, scena_11,scena_12, scena_13,menu;

const
	
	SCREEN_CAPTION= 'OpenGL with SDL : Phisic_demo'; //название в заголовке
	SCREEN_WIDTH = 1024;//размеры окна
	SCREEN_HEIGHT = 768;//размеры окна
	SCREEN_BPP = 24;//глубина цветопередачи
	REDRAW_TIME=0;//время отрисовки
	FPS_TIME=1000;//время подсчёта fps
	ANIM_TIME=10;//время для анимации
	EVENT_REDRAW = 0;//номер события отрисовки
	EVENT_FPS  =1;//номер события для подсчёта fps
	EVENT_ANIM  =2;//номер события для анимации
	PATH_TEXTURE='../data/textures/';//путь к папке где находятся текстуры
	ANGLE_PERSPECTIVE=60.0;//угол перспективы
    GL_PROECTION_ORTHO=101;//номер ортографической проекции
    GL_PROECTION_PERSPECTIVE=102;//номер перспективной проекции 
	
var	
	
	vrashenie: GLInt=-1;
	screen : PSDL_Surface;//поверхность окна для отрисовки Open GL
	event : TSDL_Event;//переменная событий
	videoflags : Uint32;//видео флаги оконного режима
	videoInfo : PSDL_VideoInfo;//информация о видеосистеме
	VideoFlags_Fullscreen:Uint32;//видеофлаг для полноэкранного режима
	fullscreen:boolean = false;//переменная отслеживает режим окна
	fps_timer: PSDL_TimerID;//переменная для подсчёта  fps
	anim_timer: PSDL_TimerID;//переменная для обработки анимации
	icon:PChar='../data/icons/sdl.bmp';//путь к файлу иконки
	frame_avr : GLInt=0;//кол-во кадров среднее
	frame_sec : GLInt=0;//кол-во кадров в данную секунду
	fps_avr : GLFloat=0.0;//среднее значение кадров в секунду
	fps :  GLInt=0;//кол-во кадров в данную секунду
	angle: Extended=0.0;//величина угла для поворота
	done:GLInt=1;//переменная показывающая работу основного цикла программы
	Font_tex:GLUInt;//текстура растрового шрифта
	Info_tex:GLUInt;
	info_enable:GLBoolean=GL_FALSE;//включатель режима отображения информации
	help_enable:GLBoolean=GL_FALSE;
	help_tex,load_tex,load_1_tex,load_2_tex,load_3_tex,load_4_tex,load_5_tex:GLUInt;


	
//функция обратного вызова таймера анимации
function anim_timer_callback(interval_anim:Uint32;param:Pointer): Uint32;cdecl;
var
	event_anim:TSDL_Event;
begin
	event_anim.type_ := SDL_USEREVENT;
	event_anim.user.code :=2;
	event_anim.user.data1 := nil;
	event_anim.user.data2 := nil;
	SDL_PushEvent(@event_anim);
	result:=interval_anim;
end;	
//функция обратного вызова для подсчёта FPS
function  fps_timer_callback(interval_fps:Uint32;param:Pointer): Uint32;cdecl;
var
	event_fps:TSDL_Event;
begin
	event_fps.type_ := SDL_USEREVENT;
	event_fps.user.code :=1;
	event_fps.user.data1 := nil;
	event_fps.user.data2 := nil;
	SDL_PushEvent(@event_fps);
	result:= interval_fps;
end;

//процедура обработки действий при анимации
procedure anim_proc();
begin
	if vrashenie=1 then
	begin
	povorot:=povorot+0.1;
	end;
	angle:=angle+0.9;
	anim_proc_scena_0();
	anim_proc_scena_13();
end;

//процедура  при выходе
procedure quit();
begin
	SDL_RemoveTimer(anim_timer);
	SDL_RemoveTimer(fps_timer);
	SDL_QUIT;
	Halt(0);
end;
//функция для задания типа проекции
function ogl_set_projection( width ,height,  proection : GLInt ) : Boolean;
begin
	if ( height = 0 ) then
		height := 1; 
	case  proection of
		GL_PROECTION_ORTHO:
			begin	
				glViewport( 0, 0, width, height );
				glMatrixMode( GL_PROJECTION );
				glLoadIdentity();
				glOrtho(0,width,0,height,2,-2);
				glMatrixMode( GL_MODELVIEW );
				glLoadIdentity();
			end;
		 GL_PROECTION_PERSPECTIVE:
		 	begin	
				glViewport( 0, 0, width, height );
				glMatrixMode( GL_PROJECTION );
				glLoadIdentity();
				gluPerspective(ANGLE_PERSPECTIVE, width / height, 0.1, 1000.0 );
				glMatrixMode( GL_MODELVIEW );
				glLoadIdentity();
			end;
		end;
	result := true;
end;

//функция которая  вызывается при изменении размеров окна
function ogl_reshape( width, height, proection :GLInt ) : Boolean;
begin	
	result := ogl_set_projection( width ,height,  proection );
end;

//инициализация параметров open gl
procedure ogl_init;
begin 
	glShadeModel( GL_SMOOTH );
	glClearColor( 0.0, 0.0, 0.2, 1.0 );
	glClearDepth( 1.0 );
	glEnable( GL_DEPTH_TEST );
	glDepthFunc( GL_LEQUAL );
	glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST );
	OGL_Load_Texture(PATH_TEXTURE+'load.bmp', load_tex, txBilinear, GL_MODULATE, GL_CLAMP_TO_EDGE, txNoCompressed,GL_TRUE);
	OGL_Load_Texture(PATH_TEXTURE+'zagruzka_1.bmp', load_1_tex, txBilinear, GL_MODULATE, GL_CLAMP_TO_EDGE, txNoCompressed,GL_TRUE);
	OGL_Load_Texture(PATH_TEXTURE+'zagruzka_2.bmp', load_2_tex, txBilinear, GL_MODULATE, GL_CLAMP_TO_EDGE, txNoCompressed,GL_TRUE);
	OGL_Load_Texture(PATH_TEXTURE+'zagruzka_3.bmp', load_3_tex, txBilinear, GL_MODULATE, GL_CLAMP_TO_EDGE, txNoCompressed,GL_TRUE);
	OGL_Load_Texture(PATH_TEXTURE+'zagruzka_4.bmp', load_4_tex, txBilinear, GL_MODULATE, GL_CLAMP_TO_EDGE, txNoCompressed,GL_TRUE);
	OGL_Load_Texture(PATH_TEXTURE+'zagruzka_5.bmp', load_5_tex, txBilinear, GL_MODULATE, GL_CLAMP_TO_EDGE, txNoCompressed,GL_TRUE);
	OGL_Load_Texture(PATH_TEXTURE+'Spravka.bmp', help_tex, txBilinear, GL_MODULATE, GL_CLAMP_TO_EDGE, txNoCompressed,GL_TRUE);
end;

procedure splash_draw(texture1,texture2:GLUInt);
begin
	glClearColor( 0.0, 0.0, 0.0, 1.0 );
	glClear(GL_COLOR_BUFFER_BIT or GL_DEPTH_BUFFER_BIT);
	glLoadIdentity(); 
	glEnable(GL_TEXTURE_2D);
	glEnable( GL_BLEND );
	
	glBlendFunc(GL_ONE,GL_ONE);
    glBindTexture( GL_TEXTURE_2D, texture1 );
	
	glPushMatrix();
	//glTranslatef(0.0,1.0,0.0);
	quads_draw_sxema_1(0.25,0.25);
	glPopMatrix();
	
	glBindTexture( GL_TEXTURE_2D, texture2 );
	glPushMatrix();
	glTranslatef(0.02,-0.23,0.0);
	quads_draw_sxema_1(0.18,0.03);
	glPopMatrix();
	
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
	glFlush();
	glFinish();	
	SDL_GL_SwapBuffers( );
end;

procedure help_draw(texture:GLUInt);
begin
	glEnable(GL_TEXTURE_2D);
	glEnable( GL_BLEND );
	
	glBlendFunc(GL_ONE,GL_ONE);
    glBindTexture( GL_TEXTURE_2D, help_tex);
	glPushMatrix();
	glTranslatef(0.5,0.3,0.0);
	quads_draw_sxema_1(0.25,0.25);
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
end;
procedure load_texture();
begin
    OGL_Load_Texture(PATH_TEXTURE+'tahoma_20.bmp', Font_tex, txBilinear, GL_MODULATE, GL_CLAMP_TO_EDGE, txNoCompressed,GL_TRUE);
	
	splash_draw(load_tex,load_1_tex);
	load_texture_menu();
	load_texture_scena_0();
	load_texture_scena_1();
	load_texture_scena_2();
	splash_draw(load_tex,load_2_tex);
	load_texture_scena_3();	
	load_texture_scena_4();
	load_texture_scena_5();
	splash_draw(load_tex,load_3_tex);
	load_texture_scena_6();
	load_texture_scena_7();
	load_texture_scena_8();
	splash_draw(load_tex,load_4_tex);
	load_texture_scena_9();
	load_texture_scena_10();
	load_texture_scena_11();
	load_texture_scena_12();
	splash_draw(load_tex,load_5_tex);
	load_texture_scena_13();
end;

procedure ogl_on_start();
begin
    glutInit(@argc,argv);	
	glBuildFont(Font_tex);
	glClearColor( 0.0, 0.0, 0.1, 1.0 );
	ogl_on_start_menu(SCREEN_WIDTH,SCREEN_HEIGHT);
	ogl_on_start_scena_0(SCREEN_WIDTH,SCREEN_HEIGHT);	
	ogl_on_start_scena_1(SCREEN_WIDTH,SCREEN_HEIGHT);	
	ogl_on_start_scena_2(SCREEN_WIDTH,SCREEN_HEIGHT);	
	ogl_on_start_scena_3(SCREEN_WIDTH,SCREEN_HEIGHT);
	ogl_on_start_scena_4(SCREEN_WIDTH,SCREEN_HEIGHT);
	ogl_on_start_scena_5(SCREEN_WIDTH,SCREEN_HEIGHT);
	ogl_on_start_scena_6(SCREEN_WIDTH,SCREEN_HEIGHT);
	ogl_on_start_scena_7(SCREEN_WIDTH,SCREEN_HEIGHT);
	ogl_on_start_scena_8(SCREEN_WIDTH,SCREEN_HEIGHT);
	ogl_on_start_scena_9(SCREEN_WIDTH,SCREEN_HEIGHT);
	ogl_on_start_scena_10(SCREEN_WIDTH,SCREEN_HEIGHT);
	ogl_on_start_scena_11(SCREEN_WIDTH,SCREEN_HEIGHT);
	ogl_on_start_scena_12(SCREEN_WIDTH,SCREEN_HEIGHT);
	ogl_on_start_scena_13(SCREEN_WIDTH,SCREEN_HEIGHT);
end;
//процедура отрисовки текстовой информации
procedure info_create(dx,dy:GLInt);
var
light:GLByte;
ix,iy:GLInt;
begin
	
	
	light:=glIsEnabled(GL_LIGHTING);
	if light = GL_TRUE then
		glDisable(GL_LIGHTING);
	glEnable(GL_TEXTURE_2D);
	glEnable( GL_BLEND );
	glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);
	glColor4ub(0,255,255,0);
	ix:=0+dx;	
	iy:=SCREEN_HEIGHT-20;	
	glDrawText(ix,iy,SCREEN_WIDTH,SCREEN_HEIGHT,Font_tex,1.0,  SCREEN_CAPTION, 1);
	glColor4ub(255,128,255,0);
	iy:=iy-dy;
	glDrawText(ix,iy,SCREEN_WIDTH,SCREEN_HEIGHT,Font_tex,1.0, PChar( 'Fps_avr = '+ FloattoStrF(fps_avr, ffFixed, 5, 2)+ ' Fps= ' + FloattoStrF(fps, ffFixed, 5, 2)+''), 1);
	glColor4ub(0,255,255,0);
	iy:=iy-dy;
	glDrawText(ix,iy,SCREEN_WIDTH,SCREEN_HEIGHT,Font_tex,1.0,  glGetString(GL_VENDOR), 1);
	iy:=iy-dy;
	glDrawText(ix,iy,SCREEN_WIDTH,SCREEN_HEIGHT,Font_tex,1.0,  glGetString(GL_RENDERER), 1);
	iy:=iy-dy;
	glDrawText(ix,iy,SCREEN_WIDTH,SCREEN_HEIGHT,Font_tex,1.0,  PChar( 'OpenGL version: '+glGetString(GL_VERSION)), 1);
	iy:=iy-dy;
	glDrawText(ix,iy,SCREEN_WIDTH,SCREEN_HEIGHT,Font_tex,1.0,   PChar( 'Kamchatka, Viluchinsk City'), 1);
	iy:=iy-dy;
	glDrawText(ix,iy,SCREEN_WIDTH,SCREEN_HEIGHT,Font_tex,1.0,   PChar('Developers:'), 1);
	iy:=iy-dy;
	glDrawText(ix,iy,SCREEN_WIDTH,SCREEN_HEIGHT,Font_tex,1.0,   PChar('Romanenko Igor'), 1);
	iy:=iy-dy;
	glDrawText(ix,iy,SCREEN_WIDTH,SCREEN_HEIGHT,Font_tex,1.0,   PChar('Cheremnov Sergey'), 1);
	iy:=iy-dy;
	glDrawText(ix,iy,SCREEN_WIDTH,SCREEN_HEIGHT,Font_tex,1.0,   PChar('Kuzmichov Alexander'), 1);
	glColor4ub(255,255,255,255);
	if light = GL_TRUE then
		glEnable(GL_LIGHTING);
	
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
end;

//функция вычисления fps
procedure fps_counter();
var
caption:PChar;
begin
	fps_avr:=frame_avr*1000/SDL_GetTicks();
	fps:=frame_sec;
	frame_sec:=0;
	caption:=pchar(SCREEN_CAPTION  + '  FPS_avr = '+ FloattoStrF(fps_avr, ffFixed, 5, 2)+ ' FPS = ' + FloattoStrF(fps, ffFixed, 5, 2)+'');
	SDL_WM_SetCaption(caption,nil);	
end;

procedure scena_0_draw();
begin	
		glDisable(GL_LIGHTING);
		fon_draw_scena_0();
		title_draw_scena_0();
		ogl_set_projection(SCREEN_WIDTH,SCREEN_HEIGHT,GL_PROECTION_ORTHO); 
		glTranslatef(0.0,0.0,0.0);	
		menu_draw();  
		ogl_set_projection(SCREEN_WIDTH,SCREEN_HEIGHT,GL_PROECTION_PERSPECTIVE);			
end;

procedure scena_1_draw();
begin	
		shema_draw_scena_1(on_off);
		fon_draw_scena_1();
		glEnable( GL_DEPTH_TEST );
		glDisable(GL_LIGHTING);
		ogl_set_projection(SCREEN_WIDTH,SCREEN_HEIGHT,GL_PROECTION_ORTHO); 
		glTranslatef(0.0,0.0,0.0);	
		menu_draw();  
		ogl_set_projection(SCREEN_WIDTH,SCREEN_HEIGHT,GL_PROECTION_PERSPECTIVE);			
		
end;

procedure scena_2_draw();
begin	
		shema_draw_scena_2(on_off);
		fon_draw_scena_2();
		glEnable( GL_DEPTH_TEST );
		glDisable(GL_LIGHTING);
		ogl_set_projection(SCREEN_WIDTH,SCREEN_HEIGHT,GL_PROECTION_ORTHO); 
		glTranslatef(0.0,0.0,0.0);	
		menu_draw();  
		ogl_set_projection(SCREEN_WIDTH,SCREEN_HEIGHT,GL_PROECTION_PERSPECTIVE);			
		
end;

procedure scena_3_draw();
begin	
		shema_draw_scena_3(on_off);
		fon_draw_scena_3();
		glEnable( GL_DEPTH_TEST );
		glDisable(GL_LIGHTING);
		ogl_set_projection(SCREEN_WIDTH,SCREEN_HEIGHT,GL_PROECTION_ORTHO); 
		glTranslatef(0.0,0.0,0.0);	
		menu_draw();  
		ogl_set_projection(SCREEN_WIDTH,SCREEN_HEIGHT,GL_PROECTION_PERSPECTIVE);			
		
end;

procedure scena_4_draw();
begin	
		shema_draw_scena_4(begunok,on_off);
		fon_draw_scena_4();
		glEnable( GL_DEPTH_TEST );
		glDisable(GL_LIGHTING);
		ogl_set_projection(SCREEN_WIDTH,SCREEN_HEIGHT,GL_PROECTION_ORTHO); 
		glTranslatef(0.0,0.0,0.0);	
		menu_draw();  
		ogl_set_projection(SCREEN_WIDTH,SCREEN_HEIGHT,GL_PROECTION_PERSPECTIVE);			
		
end;

procedure scena_5_draw();
begin	
		shema_draw_scena_5(begunok,on_off);
		fon_draw_scena_5();
		glEnable( GL_DEPTH_TEST );
		glDisable(GL_LIGHTING);
		ogl_set_projection(SCREEN_WIDTH,SCREEN_HEIGHT,GL_PROECTION_ORTHO); 
		glTranslatef(0.0,0.0,0.0);	
		menu_draw();  
		ogl_set_projection(SCREEN_WIDTH,SCREEN_HEIGHT,GL_PROECTION_PERSPECTIVE);			
		
end;

procedure scena_6_draw();
begin	
		shema_draw_scena_6(begunok,on_off);
		fon_draw_scena_6();
		glEnable( GL_DEPTH_TEST );
		glDisable(GL_LIGHTING);
		ogl_set_projection(SCREEN_WIDTH,SCREEN_HEIGHT,GL_PROECTION_ORTHO); 
		glTranslatef(0.0,0.0,0.0);	
		menu_draw();  
		ogl_set_projection(SCREEN_WIDTH,SCREEN_HEIGHT,GL_PROECTION_PERSPECTIVE);			
		
end;

procedure scena_7_draw();
begin	
		shema_draw_scena_7(begunok,on_off);
		fon_draw_scena_7();
		glEnable( GL_DEPTH_TEST );
		glDisable(GL_LIGHTING);
		ogl_set_projection(SCREEN_WIDTH,SCREEN_HEIGHT,GL_PROECTION_ORTHO); 
		glTranslatef(0.0,0.0,0.0);	
		menu_draw();  
		ogl_set_projection(SCREEN_WIDTH,SCREEN_HEIGHT,GL_PROECTION_PERSPECTIVE);			
		
end;

procedure scena_8_draw();
begin
		shema_draw_scena_8(on_off);
		fon_draw_scena_8();
		glEnable( GL_DEPTH_TEST );
		glDisable(GL_LIGHTING);
		ogl_set_projection(SCREEN_WIDTH,SCREEN_HEIGHT,GL_PROECTION_ORTHO); 
		glTranslatef(0.0,0.0,0.0);	
		menu_draw();  
		ogl_set_projection(SCREEN_WIDTH,SCREEN_HEIGHT,GL_PROECTION_PERSPECTIVE);			
		
end;

procedure scena_9_draw();
begin
		shema_draw_scena_9(on_off);
		fon_draw_scena_9();
		glEnable( GL_DEPTH_TEST );
		glDisable(GL_LIGHTING);
		ogl_set_projection(SCREEN_WIDTH,SCREEN_HEIGHT,GL_PROECTION_ORTHO); 
		glTranslatef(0.0,0.0,0.0);	
		menu_draw();  
		ogl_set_projection(SCREEN_WIDTH,SCREEN_HEIGHT,GL_PROECTION_PERSPECTIVE);			
		
end;

procedure scena_10_draw();
begin
		shema_draw_scena_10(on_off,begunok);
		fon_draw_scena_10();
		glEnable( GL_DEPTH_TEST );
		glDisable(GL_LIGHTING);
		ogl_set_projection(SCREEN_WIDTH,SCREEN_HEIGHT,GL_PROECTION_ORTHO); 
		glTranslatef(0.0,0.0,0.0);	
		menu_draw();  
		ogl_set_projection(SCREEN_WIDTH,SCREEN_HEIGHT,GL_PROECTION_PERSPECTIVE);			
		
end;

procedure scena_11_draw();
begin
		shema_draw_scena_11(on_off,begunok);
		fon_draw_scena_11();
		glEnable( GL_DEPTH_TEST );
		glDisable(GL_LIGHTING);
		ogl_set_projection(SCREEN_WIDTH,SCREEN_HEIGHT,GL_PROECTION_ORTHO); 
		glTranslatef(0.0,0.0,0.0);	
		menu_draw();  
		ogl_set_projection(SCREEN_WIDTH,SCREEN_HEIGHT,GL_PROECTION_PERSPECTIVE);			
		
end;

procedure scena_12_draw();
begin
		shema_draw_scena_12(on_off);
		fon_draw_scena_12();
		glEnable( GL_DEPTH_TEST );
		glDisable(GL_LIGHTING);
		ogl_set_projection(SCREEN_WIDTH,SCREEN_HEIGHT,GL_PROECTION_ORTHO); 
		glTranslatef(0.0,0.0,0.0);	
		menu_draw();  
		ogl_set_projection(SCREEN_WIDTH,SCREEN_HEIGHT,GL_PROECTION_PERSPECTIVE);			
			
end;

procedure scena_13_draw();
begin
		glDisable(GL_LIGHTING);		
		fon_draw_scena_13();
		title_draw_scena_13();
		ogl_set_projection(SCREEN_WIDTH,SCREEN_HEIGHT,GL_PROECTION_ORTHO); 
		glTranslatef(0.0,0.0,0.0);	
		menu_draw();  
		ogl_set_projection(SCREEN_WIDTH,SCREEN_HEIGHT,GL_PROECTION_PERSPECTIVE);			
end;

procedure ogl_draw;
begin	
	glClear(GL_COLOR_BUFFER_BIT or GL_DEPTH_BUFFER_BIT);
	glLoadIdentity(); 		
	glColor4ub(255,255,255,255);
	glTranslatef(0.0,0.0,-8.0);	
	
	case id_scena_draw of
		0:	scena_0_draw();
		1:	scena_1_draw();
		2:	scena_2_draw();
		3:	scena_3_draw();
		4:	scena_4_draw();
		5:	scena_5_draw();
		6:	scena_6_draw();
		7:	scena_7_draw();
		8:	scena_8_draw();
		9:	scena_9_draw();
		10:	scena_10_draw();
		11:	scena_11_draw();
		12:	scena_12_draw();
		13:	scena_13_draw();
	else
		scena_0_draw();
	end;	
	
	
	if info_enable=GL_TRUE then		
		info_create(10,15);
	
	if help_enable=GL_TRUE then		
		help_draw(help_tex);
		
	glFlush();
	glFinish();
	frame_avr:=frame_avr+1;
	frame_sec:=frame_sec+1;
	SDL_GL_SwapBuffers( );
end;


//процедура обрабатывает нажатие кнопок мыши
procedure mouse_button_pressed ( button : TSDL_MouseButtonEvent );
begin

	case id_scena_draw of
		0:	mouse_button_pressed_scena_0(button);
		1:	mouse_button_pressed_scena_1(button);
		2:	mouse_button_pressed_scena_2(button);
		3:	mouse_button_pressed_scena_3(button);
		4:	mouse_button_pressed_scena_4(button);
		5:	mouse_button_pressed_scena_5(button);
		6:	mouse_button_pressed_scena_6(button);
		7:	mouse_button_pressed_scena_7(button);
		8:	mouse_button_pressed_scena_8(button);
		9:	mouse_button_pressed_scena_9(button);
		10:	mouse_button_pressed_scena_10(button);
		11:	mouse_button_pressed_scena_11(button);
		12:	mouse_button_pressed_scena_12(button);
		13:	mouse_button_pressed_scena_13(button);
	else
		mouse_button_pressed_scena_0(button);
	end;

end;


//процедура обработки движения мыши 
procedure mouse_motion( motion :  TSDL_MouseMotionEvent );
begin
//write ('x = ', motion.x,' y = ', motion.y, 'xrel = ', motion.xrel,' yrel = ', motion.yrel);
	case id_scena_draw of
		0:mouse_motion_scena_0(motion);
		1:mouse_motion_scena_1(motion);
		2:mouse_motion_scena_2(motion);
		3:mouse_motion_scena_3(motion);
		4:mouse_motion_scena_4(motion);
		5:mouse_motion_scena_5(motion);
		6:mouse_motion_scena_6(motion);
		7:mouse_motion_scena_7(motion);
		8:mouse_motion_scena_8(motion);
		9:mouse_motion_scena_9(motion);
		10:mouse_motion_scena_10(motion);
		11:mouse_motion_scena_11(motion);
		12:mouse_motion_scena_12(motion);
		13:mouse_motion_scena_13(motion);
	else
		mouse_motion_scena_0(motion);
	end;

end;


//процедура инициализации sdl приложений
function SDL_ogl_init():PSDL_Surface;cdecl;
var 
	surface : PSDL_Surface;
begin
 	 if ( SDL_Init( SDL_INIT_VIDEO or SDL_INIT_TIMER ) < 0 ) then
 		Quit();
	videoInfo := SDL_GetVideoInfo;
	if ( videoInfo = nil ) then
 		Quit();
	videoFlags := SDL_OPENGL;  	
	videoFlags := videoFlags or SDL_DOUBLEBUF;
	videoFlags := videoFlags or SDL_HWPALETTE;

	if ( videoInfo.hw_available <> 0 ) then
		videoFlags := videoFlags or SDL_HWSURFACE
	else
		videoFlags := videoFlags or SDL_SWSURFACE;
	if ( videoInfo.blit_hw <> 0 ) then
		videoFlags := videoFlags or SDL_HWACCEL;
	//videoFlags := videoFlags or  SDL_RESIZABLE;
	SDL_GL_SetAttribute( SDL_GL_RED_SIZE, 8 );
  SDL_GL_SetAttribute( SDL_GL_GREEN_SIZE, 8 );
  SDL_GL_SetAttribute( SDL_GL_BLUE_SIZE, 8 );
  SDL_GL_SetAttribute( SDL_GL_ALPHA_SIZE, 8 );
  SDL_GL_SetAttribute( SDL_GL_DEPTH_SIZE, 24 );
  SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );
  SDL_GL_SetAttribute( SDL_GL_ACCELERATED_VISUAL, 1 );
  
	VideoFlags_Fullscreen:=VideoFlags or SDL_FULLSCREEN;
	surface := SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, VideoFlags_Fullscreen);	
	SDL_WM_SetCaption( SCREEN_CAPTION, nil );
	SDL_WM_SetIcon(SDL_LoadBMP(ICON), 0);
	
	if ( surface = nil ) then
		Quit();
	
	result:=surface;
	SDL_FreeSurface(surface);
end;
//процедура обработки нажатий клавиш на клавиатуре
procedure key_pressed( keysym : PSDL_keysym );
begin
	case keysym.sym of
		SDLK_F1 :
			begin
			id_scena_draw:=1;id_shema_draw:=1;on_off:=-1;begunok:=0;povorot:=-20;
			end;
		SDLK_F2 :
			begin
			id_scena_draw:=2;id_shema_draw:=1;on_off:=-1;begunok:=0;povorot:=-20;
			end;
		SDLK_F3 :
			begin
			id_scena_draw:=3;id_shema_draw:=1;on_off:=-1;begunok:=0;povorot:=-20;
			end;
		SDLK_F4 :
			begin
			id_scena_draw:=4;id_shema_draw:=1;on_off:=-1;begunok:=0;povorot:=-20;
			end;
		SDLK_F5 :
			begin
			id_scena_draw:=5;id_shema_draw:=1;on_off:=-1;begunok:=0;povorot:=-20;
			end;
		SDLK_F6 :
			begin
			id_scena_draw:=6;id_shema_draw:=1;on_off:=-1;begunok:=0;povorot:=-20;
			end;
		SDLK_F7 :
			begin
			id_scena_draw:=7;id_shema_draw:=1;on_off:=-1;begunok:=0;povorot:=-20;
			end;
		SDLK_F8 :
			begin
			id_scena_draw:=8;id_shema_draw:=1;on_off:=-1;begunok:=0;povorot:=-20;
			end;
		SDLK_F9 :
			begin
			id_scena_draw:=9;id_shema_draw:=1;on_off:=-1;begunok:=0;povorot:=-20;
			end;
		SDLK_F10 :
			begin
			id_scena_draw:=10;id_shema_draw:=1;on_off:=-1;begunok:=0;povorot:=-20;
			end;
		SDLK_F11 :
			begin
			id_scena_draw:=11;id_shema_draw:=1;on_off:=-1;begunok:=0;povorot:=-20;
			end;
		SDLK_F12 :
			begin
			id_scena_draw:=12;id_shema_draw:=1;on_off:=-1;begunok:=0;povorot:=-20;
			end;	
		SDLK_a :	id_scena_draw:=13;
		SDLK_O: on_off:=-on_off;
		
		SDLK_KP_MINUS:
			begin
				if begunok>=-3.0625 then
				begin
				begunok:=begunok-0.6125;
				end;
			end;
		SDLK_KP_PLUS:
			begin
				if begunok<=3.0625 then
				begin
				begunok:=begunok+0.6125;
				end;
			end;
		
		SDLK_ESCAPE :	Quit();
			
		SDLK_i:
			begin
				if info_enable = GL_TRUE then
					info_enable:=GL_FALSE
				else
					info_enable:=GL_TRUE;	
			end;
		
		//SDLK_R:	vrashenie:=-vrashenie;
		
		SDLK_h:
			begin
				if help_enable = GL_TRUE then
					help_enable:=GL_FALSE
				else
					help_enable:=GL_TRUE;	
			end;
		end;
	case id_scena_draw of
		0:	key_pressed_scena_0(keysym);
		1:	key_pressed_scena_1(keysym);
		2:	key_pressed_scena_2(keysym);
		3:	key_pressed_scena_3(keysym);
		4:	key_pressed_scena_4(keysym);
		5:	key_pressed_scena_5(keysym);
		6:	key_pressed_scena_6(keysym);
		7:	key_pressed_scena_7(keysym);
		8:	key_pressed_scena_8(keysym);
		9:	key_pressed_scena_9(keysym);
		10:	key_pressed_scena_10(keysym);
		11:	key_pressed_scena_11(keysym);
		12:	key_pressed_scena_12(keysym);
		13:	key_pressed_scena_13(keysym);
	else
		key_pressed_scena_0(keysym);
	end;	
	
end;

//процедура отслеживаний событий в программе
procedure glAppEvents();cdecl;
var event       : TSDL_Event;
begin;
     while (SDL_PollEvent( @event )  = 1 ) do
		begin
				case event.type_ of
					SDL_QUITEV:
						begin									
							done:=0
						end;
					SDL_VIDEORESIZE :
						begin
							//SDL_FreeSurface(screen);
							//screen := SDL_SetVideoMode( event.resize.w, event.resize.h, SCREEN_BPP, videoflags );
							ogl_reshape( event.resize.w, event.resize.h, GL_PROECTION_PERSPECTIVE );
							//ogl_init();
						end;
					SDL_KEYDOWN :
						begin
							key_pressed( @event.key.keysym );
						end;
					SDL_MOUSEBUTTONDOWN:
						begin
							mouse_button_pressed( event.button );
						end;				
					SDL_MOUSEBUTTONUP:
						begin
							mouse_button_pressed( event.button);
						end;	
					SDL_MOUSEMOTION:
						begin
							mouse_motion( event.motion );
						end;
					SDL_USEREVENT:
						case event.user.code of	
							EVENT_FPS:	
								begin
									fps_counter();
								end;
							EVENT_ANIM:	
								begin
									anim_proc();
								end;
						end;	
				end;
			end;
end;


begin
	screen:= SDL_ogl_init();//создание окна и sdl отрисовки
	ogl_init();//задаются параметры opengl	
	ogl_reshape( SCREEN_WIDTH,SCREEN_HEIGHT,GL_PROECTION_PERSPECTIVE);//задаются размеры окна и тип проэкций
	fps_timer := SDL_AddTimer(FPS_TIME, fps_timer_callback, nil);//создаётся таймер для подсчёта fps	
	anim_timer := SDL_AddTimer(ANIM_TIME, anim_timer_callback, nil);//создаётся таймер для подсчёта анимации
	load_texture();
	ogl_on_start();
	while done = 1 do //основной цикл программы
	begin
		glAppEvents();//процедура отслеживающая события в программе
		ogl_draw();//процедура отрисовки основной сцены
		SDL_Delay(REDRAW_TIME);//задержка при отрисовке между кадрами
	end;
	
	Quit();
end.

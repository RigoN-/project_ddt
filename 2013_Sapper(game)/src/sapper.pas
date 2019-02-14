program Sapper;
{$MODE DELPHI}
uses
	SysUtils,dglOpenGL,glfw,bass,typcon;
var
	error:boolean=false;
	help:boolean=false;
	win_stat:boolean=false;
	little_help:boolean=true;
	little_help_s2:boolean=true;
	soundON:boolean=true;
	actbomb:byte=0;
	backgroundID:byte=0;
	x0,y0,dY,dX,BUTTON_W,BUTTON_H,BUTTON_C,BUTTON_K:integer;
	w_handle:integer=0;
	done:integer=1;
	sbd:integer=0;
	height:integer=W_HEIGHT;
	width:integer=W_WIDTH;
	screen_factor:real;
	sapper:sapper_type;
	id:array[0..num_tex-1] of word;
	tex_name:array[0..num_tex-1] of ansistring;
	cells:array[0..29,0..29] of cell_type;
	level:array[0..level_up] of level_type;
	scene:record
		o,d:byte;
	end;
	button:record
		start,exit,restart,next,clas,arcd,save,menu:byte;
	end;
	sounds:record
		win,restart,start,bomb,bang,beg:HSTREAM;
	end;
	
procedure prog_exit();
begin		
	if (glfwGetWindowParam(GLFW_OPENED)<>1) then glfwCloseWindow();
	glfwTerminate();	
end;

procedure ogl_print_info();
var glfw_major,glfw_minor,glfw_rev:integer;
begin
	glfwGetVersion(glfw_major,glfw_minor,glfw_rev);
end;

{*****************************‘¿…À€*****************************}

	function sound_init(f:PChar):HSTREAM;cdecl;
	begin
		BASS_Init(-1,44100,0,0,Nil);
		result:=BASS_StreamCreateFile(FALSE,f,0,0,0); 
	end;

procedure sounds_load;
begin
	sounds.win:=sound_init('../data/sounds/win.wav');
	sounds.restart:=sound_init('../data/sounds/restart.wav');
	sounds.start:=sound_init('../data/sounds/start.wav');
	sounds.bomb:=sound_init('../data/sounds/bomb.wav');
	sounds.bang:=sound_init('../data/sounds/bang.wav');
	sounds.beg:=sound_init('../data/sounds/beg.wav');
end;
	
	procedure sound_on(h:HSTREAM);
	begin
		BASS_ChannelPlay(h,false);
	end;
	
	{procedure Load_textures;
	var i:byte;
	begin
		tex_name[0]:='../data/textures/0.tga';
		tex_name[1]:='../data/textures/1.tga';
		tex_name[2]:='../data/textures/2.tga';
		tex_name[3]:='../data/textures/3.tga';
		tex_name[4]:='../data/textures/4.tga';
		tex_name[5]:='../data/textures/5.tga';
		tex_name[6]:='../data/textures/6.tga';
		tex_name[7]:='../data/textures/7.tga';
		tex_name[8]:='../data/textures/8.tga';
		tex_name[9]:='../data/textures/9.tga';
		tex_name[10]:='../data/textures/back_s1.tga';
		tex_name[11]:='../data/textures/button_start_1.tga';
		tex_name[12]:='../data/textures/button_exit_1.tga';
		tex_name[13]:='../data/textures/cell_close.tga';
		tex_name[14]:='../data/textures/cell_open.tga';
		tex_name[15]:='../data/textures/cell_open_1.tga';
		tex_name[16]:='../data/textures/cell_open_2.tga';
		tex_name[17]:='../data/textures/cell_open_3.tga';
		tex_name[18]:='../data/textures/cell_open_4.tga';
		tex_name[19]:='../data/textures/cell_open_5.tga';
		tex_name[20]:='../data/textures/cell_open_6.tga';
		tex_name[21]:='../data/textures/cell_open_7.tga';
		tex_name[22]:='../data/textures/cell_open_8.tga';
		tex_name[23]:='../data/textures/cell_open_bomb.tga';
		tex_name[24]:='../data/textures/back_s2.tga';
		tex_name[25]:='../data/textures/cell_close_bomb.tga';
		tex_name[26]:='../data/textures/bombs.tga';
		tex_name[27]:='../data/textures/cell_open_red.tga';
		tex_name[28]:='../data/textures/cell_open_det.tga';
		tex_name[29]:='../data/textures/win.tga';
		tex_name[30]:='../data/textures/button_start_2.tga';
		tex_name[31]:='../data/textures/button_exit_2.tga';
		tex_name[32]:='../data/textures/button_restart_1.tga';
		tex_name[33]:='../data/textures/button_restart_2.tga';
		tex_name[34]:='../data/textures/button_next_1.tga';
		tex_name[35]:='../data/textures/button_next_2.tga';
		tex_name[36]:='../data/textures/button_class_1.tga';
		tex_name[37]:='../data/textures/button_class_2.tga';
		tex_name[38]:='../data/textures/button_arcd_1.tga';
		tex_name[39]:='../data/textures/button_arcd_2.tga';
		tex_name[40]:='../data/textures/lifes.tga';
		tex_name[41]:='../data/textures/-.tga';
		tex_name[42]:='../data/textures/name.tga';
		tex_name[43]:='../data/textures/button_save_1.tga';
		tex_name[44]:='../data/textures/button_save_2.tga';
		tex_name[45]:='../data/textures/error.tga';
		tex_name[46]:='../data/textures/little_help.tga';
		tex_name[47]:='../data/textures/help_1.tga';
		tex_name[48]:='../data/textures/help_2.tga';
		tex_name[49]:='../data/textures/button_menu_1.tga';
		tex_name[50]:='../data/textures/button_menu_2.tga';
		tex_name[51]:='../data/textures/b1.tga';
		tex_name[52]:='../data/textures/b2.tga';
		tex_name[53]:='../data/textures/b3.tga';
		tex_name[54]:='../data/textures/b4.tga';
		tex_name[55]:='../data/textures/b5.tga';
		tex_name[56]:='../data/textures/b6.tga';
		tex_name[57]:='../data/textures/b7.tga';
		tex_name[58]:='../data/textures/b8.tga';
		tex_name[59]:='../data/textures/b9.tga';
		glGenTextures(1,@id[0]);
		glBindTexture(GL_TEXTURE_2D,id[0]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glfwLoadTexture2D(PChar(tex_name[0]),GLFW_BUILD_MIPMAPS_BIT);
		for i:=1 to num_tex-1 do
			glGenTextures(1,@id[i]);
		for i:=1 to num_tex-1 do
		begin
			glBindTexture(GL_TEXTURE_2D,id[i]);
			glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
			glfwLoadTexture2D(PChar(tex_name[i]),GLFW_BUILD_MIPMAPS_BIT);
		end;
		if FileExists('../data/saves/settings.dat') then
		begin
			assign(input,'../data/saves/settings.dat');reset(input);
				read(backgroundID);
				read(i);
				if i=1
				then
					soundON:=true
				else
					soundON:=false;
			close(input);
		end;
	end;}
	
	procedure file_save;
		var
			i,j:byte;
		begin
			assign(output,'../data/saves/save.dat');rewrite(output);
			writeln(scene.d);
			for i:=0 to level[scene.d].h-1 do
				for j:=0 to level[scene.d].w-1 do
					write(cells[i,j].close,' ');
			writeln;
			for i:=0 to level[scene.d].h-1 do
				for j:=0 to level[scene.d].w-1 do
					write(cells[i,j].open,' ');
			writeln;
			for i:=0 to level[scene.d].h-1 do
				for j:=0 to level[scene.d].w-1 do
					if cells[i,j].stat=true
					then
						write(1,' ')
					else
						write(0,' ');
			writeln;
			writeln(sapper.life);
			writeln(sapper.sap);
			writeln(actbomb);
			if sapper.block=true
			then
				writeln('1')
			else
				writeln('0');
			close(output);
		end;
		
		procedure file_load;
		var
			i,j,a:byte;
		begin
			assign(input,'../data/saves/save.dat');reset(input);
			readln(scene.d);
			for i:=0 to level[scene.d].h-1 do
				for j:=0 to level[scene.d].w-1 do
					read(cells[i,j].close);
			readln;
			for i:=0 to level[scene.d].h-1 do
				for j:=0 to level[scene.d].w-1 do
					read(cells[i,j].open);
			readln;
			for i:=0 to level[scene.d].h-1 do
				for j:=0 to level[scene.d].w-1 do
				begin
					read(a);
					if a=1
					then
						cells[i,j].stat:=true
					else
						cells[i,j].stat:=false;
				end;
			readln;
			readln(sapper.life);
			readln(sapper.sap);
			readln(actbomb);
			readln(a);
			if a=1
			then
				sapper.block:=true
			else
				sapper.block:=false;
			close(input);
		end;
		
{*****************************»Õ»÷»¿À»«¿÷»ﬂ*****************************}

	procedure bombs_init;
	var
		x1,y1,x2,y2:integer;
		i,j,a,b,s,x,y:byte;
	begin
		actbomb:=0;
		randomize;
		sapper.block:=false;
		sapper.life:=1;
		sapper.sap:=level[scene.d].b;
		for i:=0 to level[scene.d].h-1 do
			for j:=0 to level[scene.d].w-1 do cells[i,j].close:=13;
		for i:=0 to level[scene.d].h-1 do
			for j:=0 to level[scene.d].w-1 do cells[i,j].stat:=true;
		for i:=0 to level[scene.d].h-1 do
			for j:=0 to level[scene.d].w-1 do cells[i,j].open:=14;
		s:=0;
		while s<level[scene.d].b do
		begin
			a:=random(level[scene.d].h);
			b:=random(level[scene.d].w);
			if cells[a,b].open=14 then
			begin
				cells[a,b].open:=23;
				s:=s+1;
			end;
		end;
		for y:=0 to level[scene.d].h-1 do
			for x:=0 to level[scene.d].w-1 do
				if cells[y,x].open<>23 then
				begin
					if x<>0
					then
						x1:=x-1
					else
						x1:=x;
					if y<>0
					then
						y1:=y-1
					else
						y1:=y;
					if x<>level[scene.d].w-1
					then
						x2:=x+1
					else
						x2:=x;
					if y<>level[scene.d].h-1
					then
						y2:=y+1
					else
						y2:=y;
					for i:=y1 to y2 do
						for j:=x1 to x2 do
							if cells[i,j].open=23 then
								cells[y,x].open:=cells[y,x].open+1;
				end;
	end;
	
	procedure coord_0_init;
	begin
		x0:=round(0.26*width);
		y0:=(height-dY*level[scene.d].h) div 2;
	end;
	
	procedure level_init;
	begin
		level[0].h:=10;
		level[0].w:=10;
		level[0].b:=10;
		level[1].h:=15;
		level[1].w:=15;
		level[1].b:=34;
		level[2].h:=20;
		level[2].w:=20;
		level[2].b:=80;
		level[3].h:=25;
		level[3].w:=25;
		level[3].b:=140;
		level[4].h:=30;
		level[4].w:=30;
		level[4].b:=225;
	end;
	
procedure variable_init;
begin
	button.start:=11;
	button.exit:=12;
	button.restart:=32;
	button.next:=34;
	button.clas:=36;
	button.arcd:=38;
	button.save:=43;
	button.menu:=49;
	scene.o:=1;
	scene.d:=0;
	level_init;
	bombs_init;
end;
	
procedure ogl_init();
begin
	glClearColor(0.0,0.0,0.0, 1.0);
	glClearDepth(1.0);	
	glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);	
	glShadeModel(GL_SMOOTH);
	glEnable (GL_DEPTH_TEST);
	Load_textures;
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glfwEnable(GLFW_MOUSE_CURSOR);
end;

	procedure win_stat_init;
	var
		s:integer;
		i,j:byte;
	begin
		s:=0;
			for i:=0 to level[scene.d].h-1 do
				for j:=0 to level[scene.d].w-1 do
					if cells[i,j].stat=true then
						s:=s+1;
		if s=(level[scene.d].b-actbomb)
		then begin
			win_stat:=true;
			if soundON then
				sound_on(sounds.win);
			for i:=0 to level[scene.d].h-1 do
				for j:=0 to level[scene.d].w-1 do
					cells[i,j].close:=25;
			sapper.sap:=0;
		end else
			win_stat:=false;
	end;

{*****************************Œ“–»—Œ¬ ¿*****************************}

procedure ogl_reshape(w,h:integer);cdecl;
begin
	width:=w;
	height:=h;
	if (h=0) then h:=1;
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
    glLoadIdentity;
	glOrtho(0,width,height,0,-2000.0,2000.0);
	glMatrixMode(GL_MODELVIEW);
    glLoadIdentity;
	dY:=round(height*0.03);
	dX:=dY;
	coord_0_init;
	BUTTON_W:=x0;
	BUTTON_H:=x0;
	BUTTON_C:=round(x0*0.57);
	BUTTON_K:=(BUTTON_H-BUTTON_C)div 2;
	sbd:=x0 div 2;
	screen_factor:=width/2/height;
end;

		procedure error_draw;
		var
			a:real;
		begin
			a:=height/3;
			glBindTexture(GL_TEXTURE_2D,id[45]);
			glBegin(GL_QUADS);
				glTexCoord2f(1.0,1.0);
				glVertex3f(width/2+a,height/2-a,6);
				glTexCoord2f(0.0,1.0);
				glVertex3f(width/2-a,height/2-a,6);
				glTexCoord2f(0.0,0.0);
				glVertex3f(width/2-a,height/2+a,6);
				glTexCoord2f(1.0,0.0);
				glVertex3f(width/2+a,height/2+a,6);
			glEnd;
		end;
		
		procedure s1_help_draw;
		var
			a:real;
		begin
			a:=height/2;
			glBindTexture(GL_TEXTURE_2D,id[47]);
			glBegin(GL_QUADS);
				glTexCoord2f(1.0,1.0);
				glVertex3f(width/2+a,height/2-a,6);
				glTexCoord2f(0.0,1.0);
				glVertex3f(width/2-a,height/2-a,6);
				glTexCoord2f(0.0,0.0);
				glVertex3f(width/2-a,height/2+a,6);
				glTexCoord2f(1.0,0.0);
				glVertex3f(width/2+a,height/2+a,6);
			glEnd;
		end;
		
		procedure s2_help_draw;
		var
			a:real;
		begin
			a:=height/2;
			glBindTexture(GL_TEXTURE_2D,id[48]);
			glBegin(GL_QUADS);
				glTexCoord2f(1.0,1.0);
				glVertex3f(width/2+a,height/2-a,6);
				glTexCoord2f(0.0,1.0);
				glVertex3f(width/2-a,height/2-a,6);
				glTexCoord2f(0.0,0.0);
				glVertex3f(width/2-a,height/2+a,6);
				glTexCoord2f(1.0,0.0);
				glVertex3f(width/2+a,height/2+a,6);
			glEnd;
		end;
		
		procedure s1_little_help_draw;
		var
			a:real;
		begin
			a:=BUTTON_W*3/32;
			glBindTexture(GL_TEXTURE_2D,id[46]);
			glBegin(GL_QUADS);
				glTexCoord2f(0.0,1.0);
				glVertex3f(width/2-1.5*BUTTON_W,height-1.5*a,3);
				glTexCoord2f(0.0,0.0);
				glVertex3f(width/2-1.5*BUTTON_W,height-a/2,3);
				glTexCoord2f(1.0,0.0);
				glVertex3f(width/2+1.5*BUTTON_W,height-a/2,3);
				glTexCoord2f(1.0,1.0);
				glVertex3f(width/2+1.5*BUTTON_W,height-1.5*a,3);
			glEnd;
		end;
		
		procedure s2_little_help_draw;
		var
			a:real;
		begin
			a:=(width-x0)/32;
			glBindTexture(GL_TEXTURE_2D,id[46]);
			glBegin(GL_QUADS);
				glTexCoord2f(0.0,1.0);
				glVertex3f(x0,height-1.5*a,3);
				glTexCoord2f(0.0,0.0);
				glVertex3f(x0,height-a/2,3);
				glTexCoord2f(1.0,0.0);
				glVertex3f(width,height-a/2,3);
				glTexCoord2f(1.0,1.0);
				glVertex3f(width,height-1.5*a,3);
			glEnd;
		end;
	
	procedure start_draw;
	var
		a:real;
	begin
		a:=(1-screen_factor)/2;
		glBindTexture(GL_TEXTURE_2D,id[10]);
		glBegin(GL_QUADS);
			glTexCoord2f(a,1.0);
			glVertex3f(2,2,-5);
			glTexCoord2f(1-a,1.0);
			glVertex3f(width-2,2,-5);
			glTexCoord2f(1-a,0.0);
			glVertex3f(width-2,height-2,-5);
			glTexCoord2f(a,0.0);
			glVertex3f(2,height-2,-5);
		glEnd;
		a:=0.29*height;
		glBindTexture(GL_TEXTURE_2D,id[42]);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0,1.0);
			glVertex3f(width/2-a,0,-4);
			glTexCoord2f(1,1.0);
			glVertex3f(width/2+a,0,-4);
			glTexCoord2f(1,0.0);
			glVertex3f(width/2+a,a,-4);
			glTexCoord2f(0,0.0);
			glVertex3f(width/2-a,a,-4);
		glEnd;
		glBindTexture(GL_TEXTURE_2D,id[button.start]);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0,1.0);
			glVertex3f(width/2-BUTTON_W-sbd,height-BUTTON_H,0.0);
			glTexCoord2f(0.0,0.0);
			glVertex3f(width/2-BUTTON_W-sbd,height,0.0);
			glTexCoord2f(1.0,0.0);
			glVertex3f(width/2-sbd,height,0.0);
			glTexCoord2f(1.0,1.0);
			glVertex3f(width/2-sbd,height-BUTTON_H,0.0);
		glEnd;
		glBindTexture(GL_TEXTURE_2D,id[button.exit]);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0,1.0);
			glVertex3f(width/2+sbd,height-BUTTON_H,0.0);
			glTexCoord2f(0.0,0.0);
			glVertex3f(width/2+sbd,height,0.0);
			glTexCoord2f(1.0,0.0);
			glVertex3f(width/2+BUTTON_W+sbd,height,0.0);
			glTexCoord2f(1.0,1.0);
			glVertex3f(width/2+BUTTON_W+sbd,height-BUTTON_H,0.0);
		glEnd;
		glBindTexture(GL_TEXTURE_2D,id[button.clas]);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0,1.0);
			glVertex3f(width/2-BUTTON_W/2,height-BUTTON_H,1);
			glTexCoord2f(0.0,0.0);
			glVertex3f(width/2-BUTTON_W/2,height,1);
			glTexCoord2f(1.0,0.0);
			glVertex3f(width/2+BUTTON_W/2,height,1);
			glTexCoord2f(1.0,1.0);
			glVertex3f(width/2+BUTTON_W/2,height-BUTTON_H,1);
		glEnd;
		glBindTexture(GL_TEXTURE_2D,id[button.arcd]);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0,1.0);
			glVertex3f(width/2-BUTTON_W/2,height-BUTTON_H,2);
			glTexCoord2f(0.0,0.0);
			glVertex3f(width/2-BUTTON_W/2,height,2);
			glTexCoord2f(1.0,0.0);
			glVertex3f(width/2+BUTTON_W/2,height,2);
			glTexCoord2f(1.0,1.0);
			glVertex3f(width/2+BUTTON_W/2,height-BUTTON_H,2);
		glEnd;
		if little_help=true then
			s1_little_help_draw;
		if error=true
		then
			error_draw
		else
			if help=true then
				s1_help_draw;
	end;
	
		procedure s2_win_draw;
		begin
			if win_stat then
			begin
				glBindTexture(GL_TEXTURE_2D,id[29]);
				glBegin(GL_QUADS);
					glTexCoord2f(1.0,0.0);
					glVertex3f(width/2+height/2.1,height/2+height/4.2,1.5);
					glTexCoord2f(0.0,0.0);
					glVertex3f(width/2-height/2.1,height/2+height/4.2,1.5);
					glTexCoord2f(0.0,1.0);
					glVertex3f(width/2-height/2.1,height/2-height/4.2,1.5);
					glTexCoord2f(1.0,1.0);
					glVertex3f(width/2+height/2.1,height/2-height/4.2,1.5);
				glEnd;
				sapper.block:=true;
			end;
		end;
		
		procedure back_draw;
		begin
			case backgroundID of
				0:glBindTexture(GL_TEXTURE_2D,id[24]);
				1:glBindTexture(GL_TEXTURE_2D,id[51]);
				2:glBindTexture(GL_TEXTURE_2D,id[52]);
				3:glBindTexture(GL_TEXTURE_2D,id[53]);
				4:glBindTexture(GL_TEXTURE_2D,id[54]);
				5:glBindTexture(GL_TEXTURE_2D,id[55]);
				6:glBindTexture(GL_TEXTURE_2D,id[56]);
				7:glBindTexture(GL_TEXTURE_2D,id[57]);
				8:glBindTexture(GL_TEXTURE_2D,id[58]);
				9:glBindTexture(GL_TEXTURE_2D,id[59]);
			end;
			glBegin(GL_QUADS);
				glTexCoord2f(0,1.0);
				glVertex3f(0,0,-5);
				glTexCoord2f(screen_factor,1.0);
				glVertex3f(width,0,-5);
				glTexCoord2f(screen_factor,0.0);
				glVertex3f(width,height,-5);
				glTexCoord2f(0,0);
				glVertex3f(0,height,-5);
			glEnd;
		end;
		
		procedure mines_draw;
		var
			s,a,i:byte;
			b,c,m,n:integer;
		begin
			glBindTexture(GL_TEXTURE_2D,id[26]);
			glBegin(GL_QUADS);
				glTexCoord2f(1.0,1.0);
				glVertex3f(x0,0,-1);
				glTexCoord2f(0.0,1.0);
				glVertex3f(0,0,-1);
				glTexCoord2f(0.0,0.0);
				glVertex3f(0,x0/2,-1);
				glTexCoord2f(1.0,0.0);
				glVertex3f(x0,x0/2,-1);
			glEnd;
			b:=sapper.sap div 10;
			s:=1;
			while b<>0 do
			begin
				if b<>0 then s:=s+1;
				b:=b div 10;
			end;
			n:=x0;
			m:=x0 div 4;
			c:=sapper.sap;
			if c<0 then b:=1;
			for i:=1 to s do
			begin
				a:=abs(c mod 10);
				glBindTexture(GL_TEXTURE_2D,id[a]);
				glBegin(GL_QUADS);
					glTexCoord2f(1.0,1.0);
					glVertex3f(n-x0/20,m-x0/40,0);
					glTexCoord2f(0.0,1.0);
					glVertex3f(n-x0/8-x0/20,m-x0/40,0);
					glTexCoord2f(0.0,0.0);
					glVertex3f(n-x0/8-x0/20,2*m-x0/40,0);
					glTexCoord2f(1.0,0.0);
					glVertex3f(n-x0/20,2*m-x0/40,0);
				glEnd;
				c:=c div 10;
				n:=n-x0 div 8;
			end;
			if b=1 then
			begin
				glBindTexture(GL_TEXTURE_2D,id[41]);
				glBegin(GL_QUADS);
					glTexCoord2f(1.0,1.0);
					glVertex3f(n-x0/20,m-x0/40,0);
					glTexCoord2f(0.0,1.0);
					glVertex3f(n-x0/8-x0/20,m-x0/40,0);
					glTexCoord2f(0.0,0.0);
					glVertex3f(n-x0/8-x0/20,2*m-x0/40,0);
					glTexCoord2f(1.0,0.0);
					glVertex3f(n-x0/20,2*m-x0/40,0);
				glEnd;
			end;
		end;
		
		procedure next_draw;
		begin
			glBindTexture(GL_TEXTURE_2D,id[button.next]);
			glBegin(GL_QUADS);
				glTexCoord2f(1.0,1.0);
				glVertex3f(BUTTON_W,height-BUTTON_K-2*BUTTON_C,2);
				glTexCoord2f(0.0,1.0);
				glVertex3f(0,height-BUTTON_K-2*BUTTON_C,2);
				glTexCoord2f(0.0,0.0);
				glVertex3f(0,height-BUTTON_C+BUTTON_K,2);
				glTexCoord2f(1.0,0.0);
				glVertex3f(BUTTON_W,height-BUTTON_C+BUTTON_K,2);
			glEnd;
		end;
		
		procedure restart_draw;
		begin
				glBindTexture(GL_TEXTURE_2D,id[button.restart]);
				glBegin(GL_QUADS);
					glTexCoord2f(1.0,1.0);
					glVertex3f(BUTTON_W,height-BUTTON_K-2*BUTTON_C,2);
					glTexCoord2f(0.0,1.0);
					glVertex3f(0,height-BUTTON_K-2*BUTTON_C,2);
					glTexCoord2f(0.0,0.0);
					glVertex3f(0,height-BUTTON_C+BUTTON_K,2);
					glTexCoord2f(1.0,0.0);
					glVertex3f(BUTTON_W,height-BUTTON_C+BUTTON_K,2);
				glEnd;
		end;
		
		procedure save_draw;
		begin
			glBindTexture(GL_TEXTURE_2D,id[button.save]);
			glBegin(GL_QUADS);
				glTexCoord2f(1.0,1.0);
				glVertex3f(BUTTON_W,height-BUTTON_K-2*BUTTON_C,2);
				glTexCoord2f(0.0,1.0);
				glVertex3f(0,height-BUTTON_K-2*BUTTON_C,2);
				glTexCoord2f(0.0,0.0);
				glVertex3f(0,height-BUTTON_C+BUTTON_K,2);
				glTexCoord2f(1.0,0.0);
				glVertex3f(BUTTON_W,height-BUTTON_C+BUTTON_K,2);
			glEnd;
		end;
		
		procedure menu_draw;
		begin
			glBindTexture(GL_TEXTURE_2D,id[button.menu]);
			glBegin(GL_QUADS);
				glTexCoord2f(1.0,1.0);
				glVertex3f(BUTTON_W,height-BUTTON_H+BUTTON_K,1);
				glTexCoord2f(0.0,1.0);
				glVertex3f(0,height-BUTTON_H+BUTTON_K,1);
				glTexCoord2f(0.0,0.0);
				glVertex3f(0,height+BUTTON_K,1);
				glTexCoord2f(1.0,0.0);
				glVertex3f(BUTTON_W,height+BUTTON_K,1);
			glEnd;
		end;
		
			procedure quad_draw(xx,yy:integer);
			begin
				glBegin(GL_QUADS);
					glTexCoord2f(1.0,1.0);
					glVertex3f(xx+dX,yy,0);
					glTexCoord2f(0,1);
					glVertex3f(xx,yy,0);
					glTexCoord2f(0.0,0.0);
					glVertex3f(xx,yy+dY,0);
					glTexCoord2f(1.0,0);
					glVertex3f(xx+dX,yy+dY,0);
				glEnd;
			end;
		
		procedure grid_draw;
		var
			i,j:byte;
			xx,yy:integer;
		begin
			xx:=x0;
			yy:=y0;
			for i:=0 to level[scene.d].h-1 do
			begin
				for j:=0 to level[scene.d].w-1 do
				begin
					if cells[i,j].stat=true then
						glBindTexture(GL_TEXTURE_2D,id[cells[i,j].close])
					else
						glBindTexture(GL_TEXTURE_2D,id[cells[i,j].open]);
					quad_draw(xx,yy);
					xx:=xx+dX;
				end;
				xx:=x0;
				yy:=yy+dY;
			end;
		end;

		procedure s3_win_draw;
		begin
			if win_stat then
			begin
				sapper.block:=true;
				if scene.d=level_up
				then begin
					glBindTexture(GL_TEXTURE_2D,id[29]);
					glBegin(GL_QUADS);
						glTexCoord2f(1.0,0.0);
						glVertex3f(width/2+height/2.1,height/2+height/4.2,1.5);
						glTexCoord2f(0.0,0.0);
						glVertex3f(width/2-height/2.1,height/2+height/4.2,1.5);
						glTexCoord2f(0.0,1.0);
						glVertex3f(width/2-height/2.1,height/2-height/4.2,1.5);
						glTexCoord2f(1.0,1.0);
						glVertex3f(width/2+height/2.1,height/2-height/4.2,1.5);
					glEnd;
				end else
					next_draw;
			end;
			if win_stat=false then
				if sapper.block=true then
					restart_draw;
		end;
		
		procedure life_draw;
		begin
			glBindTexture(GL_TEXTURE_2D,id[40]);
			glBegin(GL_QUADS);
				glTexCoord2f(1.0,1.0);
				glVertex3f(x0,x0/2,2);
				glTexCoord2f(0.0,1);
				glVertex3f(0,x0/2,2);
				glTexCoord2f(0.0,0);
				glVertex3f(0,x0,2);
				glTexCoord2f(1.0,0);
				glVertex3f(x0,x0,2);
			glEnd;
			glBindTexture(GL_TEXTURE_2D,id[sapper.life]);
			glBegin(GL_QUADS);
				glTexCoord2f(1.0,1.0);
				glVertex3f(x0-x0/20,3/4*x0-x0/40,2.1);
				glTexCoord2f(0.0,1.0);
				glVertex3f(x0-x0/8-x0/20,3/4*x0-x0/40,2.1);
				glTexCoord2f(0.0,0.0);
				glVertex3f(x0-x0/8-x0/20,x0-x0/40,2.1);
				glTexCoord2f(1.0,0.0);
				glVertex3f(x0-x0/20,x0-x0/40,2.1);
			glEnd;
		end;
			
	procedure s2_draw;
	begin
		back_draw;
		grid_draw;
		mines_draw;
		s2_win_draw;
		menu_draw;
		if sapper.block=true then
			restart_draw;
		if help=true then
			s2_help_draw;
		if little_help_s2 then
			s2_little_help_draw;
	end;

	procedure s3_draw;
	begin
		grid_draw;
		back_draw;
		mines_draw;
		menu_draw;
		s3_win_draw;
		life_draw;
		if sapper.block=false then
			save_draw;
		if help=true then
			s2_help_draw;
		if little_help_s2 then
			s2_little_help_draw;
	end;
	
procedure ogl_draw();
begin
	glClear(GL_COLOR_BUFFER_BIT or GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
    glLoadIdentity;
	gluLookAt(	0.0,0.0,5.0,	// Eye-position
				0.0,0.0,0.0,	// View-point
				0.0,1.0,0.0 );	// Up-vector
	if scene.o=1 then start_draw;
	if scene.o=2 then s2_draw;
	if scene.o=3 then s3_draw;
	glfwSwapBuffers();
end;

{*****************************”œ–¿¬À≈Õ»≈*****************************}

	procedure kp_s2(key,action:integer);
	begin
		if ((key=GLFW_KEY_SPACE) and (action=GLFW_PRESS)) then bombs_init;
		if ((key=GLFW_KEY_KP_1) and (action=GLFW_PRESS)) then
		begin
			scene.d:=0;
			bombs_init;
			coord_0_init;
		end;
		if ((key=GLFW_KEY_KP_2) and (action=GLFW_PRESS)) then
		begin
			scene.d:=1;
			bombs_init;
			coord_0_init;
			little_help_s2:=false;
		end;
		if ((key=GLFW_KEY_KP_3) and (action=GLFW_PRESS)) then
		begin
			scene.d:=2;
			bombs_init;
			coord_0_init;
			little_help_s2:=false;
		end;
		if ((key=GLFW_KEY_KP_4) and (action=GLFW_PRESS)) then
		begin
			scene.d:=3;
			bombs_init;
			coord_0_init;
			little_help_s2:=false;
		end;
		if ((key=GLFW_KEY_KP_5) and (action=GLFW_PRESS)) then
		begin
			scene.d:=4;
			bombs_init;
			coord_0_init;
			little_help_s2:=false;
		end;
	end;
	
	procedure kp_s3(key,action:integer);
	begin
		if ((key=GLFW_KEY_SPACE) and (action=GLFW_PRESS)) then
		begin
			scene.d:=0;
			bombs_init;
			coord_0_init;
			sapper.life:=5;
		end;
	end;

procedure key_press(key,action:integer);
begin
	if ((key=GLFW_KEY_ESC) and (action=GLFW_PRESS))then
		done:=0;
	if ((key=GLFW_KEY_F1) and (action=GLFW_PRESS)) then
	begin
		error:=false;
		little_help:=false;
		help:=true;
	end;
	if ((key=GLFW_KEY_F2) and (action=GLFW_PRESS)) then
		soundON:=not soundON;
	if ((key=GLFW_KEY_F3) and (action=GLFW_PRESS)) then
	begin
		backgroundID:=backgroundID+1;
		if backgroundID=10 then
			backgroundID:=0;
	end;
	if scene.o=2 then kp_s2(key,action);
	if scene.o=3 then kp_s3(key,action);
end;

	procedure mbp_s1(butt,action:integer);
	var x,y:integer;
	begin
		if butt=GLFW_MOUSE_BUTTON_LEFT then
			if action=GLFW_PRESS then
				if (error=false) and (help=false)
				then begin
					glfwGetMousePos(x,y);
					if (y<height-BUTTON_K) and (y>height-BUTTON_K-BUTTON_C) then
					begin
						if (x>width/2-BUTTON_W/2) and (x<width/2+BUTTON_W/2) then
						begin
							if y<height-BUTTON_K-BUTTON_C/2 then
							begin
								scene.o:=2;
								scene.d:=0;
								coord_0_init;
								bombs_init;
								little_help:=false;
								win_stat_init;
							end;
							if y>height-BUTTON_K-BUTTON_C/2 then
							begin
								scene.o:=3;
								scene.d:=0;
								coord_0_init;
								bombs_init;
								sapper.life:=5;
								little_help:=false;
								win_stat_init;
							end;
							if soundON then
								sound_on(sounds.start);
						end;
						if (x<width/2-sbd) and (x>width/2-BUTTON_W-sbd) then
							if FileExists('../data/saves/save.dat')
							then begin
								scene.o:=3;
								file_load;
								coord_0_init;
								little_help:=false;
							end else
								error:=true;
						if (x>width/2+sbd) and (x<width+BUTTON_W+sbd) then
							done:=0;
					end;
				end else
				begin
					error:=false;
					help:=false;
				end;
	end;
	
		procedure mbp_s2(y:integer);
		begin
			if y>height-BUTTON_C then
			begin
				scene.o:=1;
				button.menu:=49;
			end;
			if sapper.block=true then
				if (y>height-2*BUTTON_C) and (y<height-BUTTON_C) then
				begin
					bombs_init;
					win_stat_init;
					if soundON then
						sound_on(sounds.restart);
				end;
		end;
		
		procedure mbp_s3(y:integer);
		var
			a:byte;
		begin
			if y>height-BUTTON_C then
			begin
				scene.o:=1;
				button.menu:=49;
			end;
			if sapper.block=false then
				if (y>height-2*BUTTON_C) and (y<height-BUTTON_C) then
					file_save;
			if sapper.block=true then
			begin
				if win_stat=false then
					if (y>height-2*BUTTON_C) and (y<height-BUTTON_C) then
					begin
						scene.o:=3;
						scene.d:=0;
						coord_0_init;
						bombs_init;
						sapper.life:=5;
						if soundON then
							sound_on(sounds.restart);
					end;
				if scene.d<>level_up then
					if win_stat then
						if (y>height-2*BUTTON_C) and (y<height-BUTTON_C) then
						begin
							scene.d:=scene.d+1;
							a:=sapper.life;
							bombs_init;
							sapper.life:=a;
							coord_0_init;
							win_stat_init;
						end;						
			end;			
		end;
	
	procedure mbp_r;
	var
		x,y:integer;
	begin
		glfwGetMousePos(x,y);
		if sapper.block=false then
		begin
		glfwGetMousePos(x,y);
		if (x>x0) and (x<x0+dX*level[scene.d].w) then
			if (y>y0) and (y<(dY*level[scene.d].h+y0)) then
			begin
				x:=(x-x0) div dX;
				y:=(y-y0) div dY;
				if cells[y,x].stat=true then
					if cells[y,x].close=25
					then begin
						cells[y,x].close:=13;
						sapper.sap:=sapper.sap+1;
					end else begin
						cells[y,x].close:=25;
						sapper.sap:=sapper.sap-1;
					end;
			end;
		end;
		little_help_s2:=false;
	end;
		
		procedure cell_open(x,y:integer);
		var
			x1,y1,x2,y2:integer;
			i,j:byte;
		begin
			cells[y,x].stat:=false;
			if x<>0
			then
				x1:=x-1
			else
				x1:=x;
			if y<>0
			then
				y1:=y-1
			else
				y1:=y;
			if x<>level[scene.d].w-1
			then
				x2:=x+1
			else
				x2:=x;
			if y<>level[scene.d].h-1
			then
				y2:=y+1
			else
				y2:=y;
			for i:=y1 to y2 do
				for j:=x1 to x2 do
					if cells[i,j].stat=true then
						if cells[i,j].close<>25 then
						begin
							cells[i,j].stat:=false;
							if cells[i,j].open=14 then
								cell_open(j,i);
						end;
		end;
	
	procedure mbp_l;
	var
		x,y:integer;
		i,j:byte;
	begin
		if help=false then
		begin
			glfwGetMousePos(x,y);
			if scene.o<>1 then
			begin
				if sapper.block=false then
				begin
					if (x>x0) and (x<x0+dX*level[scene.d].w) then
						if (y>y0) and (y<(dY*level[scene.d].h+y0)) then
						begin
							x:=(x-x0) div dX;
							y:=(y-y0) div dY;
							if cells[y,x].close<>25 then
							begin
								if cells[y,x].stat=true then
									if cells[y,x].open=23 then
									begin
										sapper.life:=sapper.life-1;
										sapper.sap:=sapper.sap-1;
										actbomb:=actbomb+1;
										if sapper.life>1 then
											if soundON then
												sound_on(sounds.bang);
										if sapper.life=0 then
										begin
											sapper.block:=true;
											for i:=0 to level[scene.d].h-1 do
												for j:=0 to level[scene.d].w-1 do
													if cells[i,j].open=23 then
													begin
														cells[i,j].stat:=false;
														if cells[i,j].close=25 then
															cells[i,j].open:=28;
													end;
											cells[y,x].open:=27;
											if soundON then
												sound_on(sounds.bomb);
										end;
									cells[y,x].stat:=false;
									end;
								if cells[y,x].open=14 then
									cell_open(x,y)
								else
									cells[y,x].stat:=false;
							end;
						end;
					if not sapper.block then
						win_stat_init;
				end;
			end;
			if x<BUTTON_W then
			begin
				if scene.o=2 then
					mbp_s2(y);
				if scene.o=3 then
					mbp_s3(y);
			end;
		end else
			help:=false;
		little_help_s2:=false;
	end;
	
procedure mouse_button_press(butt,action:integer);
begin
	if scene.o=1
	then
		mbp_s1(butt,action)
	else begin
		if butt=GLFW_MOUSE_BUTTON_LEFT then
			if action=GLFW_PRESS then
				mbp_l;
		if butt=GLFW_MOUSE_BUTTON_RIGHT then
			if action=GLFW_PRESS then
				mbp_r;
	end;
end;

	procedure mp_s1(x,y:integer);
	begin
		if (y<height-BUTTON_K) and (y>height-BUTTON_K-BUTTON_C)
		then begin
			if (x>width/2-BUTTON_W-sbd) and (x<width/2-sbd)
			then
				button.start:=30
			else
				button.start:=11;
			if (x>width/2+sbd) and (x<width/2+BUTTON_W+sbd)
			then
				button.exit:=31
			else
				button.exit:=12;
			if (x>width/2-BUTTON_W/2) and (x<width/2+BUTTON_W/2)
			then begin
				if (y>height-BUTTON_K-BUTTON_C) and (y<height-BUTTON_K-BUTTON_C/2)
				then
					button.clas:=37
				else
					button.clas:=36;
				if y>height-BUTTON_K-BUTTON_C/2
				then
					button.arcd:=39
				else
					button.arcd:=38;
			end else begin
				button.clas:=36;
				button.arcd:=38;
			end;
		end else begin
			button.start:=11;
			button.exit:=12;
			button.clas:=36;
			button.arcd:=38;
		end;
end;
	
	procedure mp_s2(x,y:integer);
	begin
		if x<BUTTON_W
		then begin
			if y>height-BUTTON_C
			then
				button.menu:=50
			else
				button.menu:=49;
			if (y>height-2*BUTTON_C) and (y<height-BUTTON_C)
			then
				button.restart:=33
			else
				button.restart:=32;
		end else begin
			button.menu:=49;
			button.restart:=32;
		end;
	end;
	
	procedure mp_s3(x,y:integer);
	begin
		if x<BUTTON_W
		then begin
			if y>height-BUTTON_C
			then
				button.menu:=50
			else
				button.menu:=49;
			if sapper.block=false then
				if (y>height-2*BUTTON_C) and (y<height-BUTTON_C)
				then
					button.save:=44
				else
					button.save:=43;
			if sapper.block=true
			then if (y>height-2*BUTTON_C) and (y<height-BUTTON_C) then
				begin
					if win_stat=false
						then
							button.restart:=33
						else
							button.restart:=32;
					if win_stat then
						if scene.d<>level_up
						then
							button.next:=35
						else
							button.next:=34;
				end
			else begin
				button.restart:=32;
				button.next:=34;
			end;
		end else begin
			button.menu:=49;
			button.restart:=32;
			button.next:=34;
			button.save:=43
		end;
	end;

procedure mouse_pos;
var
	x,y:integer;
begin
	glfwGetMousePos(x,y);
	if (error=false) and (help=false) then
	begin
		if scene.o=1 then
			mp_s1(x,y);
		if scene.o=2 then
			mp_s2(x,y);
		if scene.o=3 then
			mp_s3(x,y);
	end;
end;

{*****************************¬¿∆ÕŒ≈*****************************}

procedure glfw_callback_init;
begin
	glfwSetWindowSizeCallback(@ogl_reshape);  
	glfwSetKeyCallback(@key_press);	
	glfwSetMouseButtonCallback(@mouse_button_press);
	glfwSetMousePosCallback(@mouse_pos);
end;

procedure init_Window();
begin
	w_handle:=glfwOpenWindow(W_WIDTH,W_HEIGHT,0,0,0,0,0,0,GLFW_FULLSCREEN);
	if w_handle <> 1 then
	begin
		glfwTerminate;
		Exit;
	end;
end;

procedure glfw_window_set_params();
begin
	glfwSetWindowTitle(W_CAPTION);	
	glfwSwapInterval(SWAP_INT);       
end;

	procedure sound_free(h:HSTREAM);
	begin
		BASS_StreamFree(h); 	
		BASS_Free(); 
	end;

procedure glfw_main_loop;
begin
	while done=1 do 
		begin
		ogl_draw();		 
		if glfwGetWindowParam(GLFW_OPENED)<>1 then done:=0;
		end;
	sound_free(sounds.win);
	sound_free(sounds.restart);
	sound_free(sounds.start);
	sound_free(sounds.bomb);
	sound_free(sounds.bang);
	sound_free(sounds.beg);
	assign(output,'../data/saves/settings.dat');rewrite(output);
		write(backgroundID,' ');
		if soundON
		then
			write('1')
		else
			write('0');
	close(output);
	prog_exit();
end;

begin
glfwInit;
InitOpenGL;
ReadExtensions;
init_Window();
sounds_load;
ogl_init();
coord_0_init;
glfw_window_set_params;
glfw_callback_init;
ogl_print_info;
if soundON then
	sound_on(sounds.beg);
variable_init;
glfw_main_loop;
glfwTerminate;
end.
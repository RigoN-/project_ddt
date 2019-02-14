{$MODE DELPHI}
unit init;
interface
uses
	dglOpenGL,glfw,typcon;
procedure Load_textures(id:pAROFlongint);cdecl;

implementation

procedure Load_textures(id:pAROFlongint);
	var
		i:byte;
		tex_name:parPChar;
	begin
		GetMem(tex_name, num_tex*SizeOf(PChar));
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
		for i:=0 to num_tex-1 do
			glGenTextures(1,@id[i]);
		for i:=0 to num_tex-1 do
		begin
			glBindTexture(GL_TEXTURE_2D,id[i]);
			glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
			glfwLoadTexture2D(PChar(tex_name[i]),GLFW_BUILD_MIPMAPS_BIT);
		end;
		freemem(tex_name);
	end;
end.
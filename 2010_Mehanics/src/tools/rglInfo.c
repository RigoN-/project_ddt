#include "rglInfo.h"
#include "rglTexture.h"
char *Font01="../data/fonts/arial.ttf";
char *Font02="../data/fonts/DejaVuSans.ttf";
char *Font03="../data/fonts/terminator_cyr_v4.ttf";

char *result_fon_tx="../data/textures/result_table.jpg";

void rglInitTable(char *caption )
{
	
	font_24b=TTFBuildFont(Font02, 16, 1);	
	//glColor4ub(128,255,255,0);
	glColor4f(1.0,0.1,0.1,1.0);
	SDL_string_texture_create(font_24b,(char *) caption, 2,&table_info);
	
		};

void rglInitLoad(char *caption )
{
	
	font_24b=TTFBuildFont(Font03, 20, 1);	
	//glColor4ub(128,255,255,0);
	glColor4f(0.5,0.8,1.0,1.0);
	SDL_string_texture_create(font_24b,(char *) caption, 2,&load_tx01);
	
		};

void rglInitInfo(char *caption )
{
	font_13=TTFBuildFont(Font01, 13, 0);	
	font_13b=TTFBuildFont(Font02, 13, 1);	
	font_14b=TTFBuildFont(Font02, 14, 1);	
	glColor4f(1.0,1.0,1.0,1.0);
	SDL_string_texture_create(font_14b,(char *) caption, 2,&info_tx01);
	
    glColor4f(0.4,0.8,0.0,8.0); 
	SDL_string_texture_create(font_13b, "Информация о программе", 2,&info_tx03);
     glColor4f(1.0,1.0,1.0,1.0);
	SDL_string_texture_create(font_13b, (char *) glGetString(GL_RENDERER), 2,&info_tx04);
	SDL_string_texture_create(font_13b,(char *) glGetString(GL_VERSION), 2,&info_tx05);
	SDL_string_texture_create(font_13b, (char *)  glGetString(GL_SHADING_LANGUAGE_VERSION),2,&info_tx06);
	 glColor4f(0.4,0.8,0.0,8.0); 
	SDL_string_texture_create(font_13b, "Справка по управлению ", 2, &info_tx14);
	glColor4f(1.0,1.0,1.0,1.0);
	SDL_string_texture_create(font_13b, "F1-F6 - Переключение лаб. работ",2, &info_tx07);
	SDL_string_texture_create(font_13b, "F12 - Руководство по опытам",2, &info_tx08);
	SDL_string_texture_create(font_13b, "0-9 - Перключение опытов",2, &info_tx09);
	SDL_string_texture_create(font_13b, "Зажатая ЛКМ - Поворот сцены",2, &info_tx10);
	SDL_string_texture_create(font_13b, "Колесо мыши - приблизить/jотдалить",2, &info_tx11);
	SDL_string_texture_create(font_13b, "E - начальное положение",2, &info_tx12);
	SDL_string_texture_create(font_13b, "Quit  -  Press ESC ", 2, &info_tx13);
	SDL_string_texture_create(font_13b, "F11 - О разработчиках",2, &info_tx15);
	SDL_string_texture_create(font_13b, "S - Смена шейдерных программ",2, &info_tx16);
	//rglCreateTexture(GL_RGBA, 312, 256, &tex_render, txNoFilter, GL_REPLACE, GL_REPEAT, txNoCompressed,GL_FALSE);
	
	};
	
	void rglInitResult3( )
{
	font_13=TTFBuildFont(Font02, 13, 0);	
	font_13b=TTFBuildFont(Font02, 13, 1);	
	glColor4f(1.0,1.0,1.0,1.0);
	
	

	SDL_string_texture_create(font_13,   "Таблица результатов измерений. Условия равновесия", 2,&result_tx01);
	SDL_string_texture_create(font_13b, "|    № опыта  |    F1        |      L1       |      F2       |     L2      |     F1/F2    |       L1/L2     | ", 2,&result_tx02);
	SDL_string_texture_create(font_13,   "------------------------------------------------------------------------------------------------------------------------------- ", 2,&result_tx03);
	SDL_string_texture_create(font_13b, "|        0          |     0         |      0         |      0        |     0        |        0        |          0       | ", 2,&result_tx04);
	SDL_string_texture_create(font_13b, "|        0          |     0         |      0         |      0        |     0        |        0        |          0       | ", 2,&result_tx05);
	SDL_string_texture_create(font_13b, "|        0          |     0         |      0         |      0        |     0        |        0        |          0       | ", 2,&result_tx06);
	SDL_string_texture_create(font_13b, "|        0          |     0         |      0         |      0        |     0        |        0        |          0       | ", 2,&result_tx07);
	

	//rglCreateTexture(GL_RGBA, 312, 256, &tex_render, txNoFilter, GL_REPLACE, GL_REPEAT, txNoCompressed,GL_FALSE);
	
	};
	
	void rglInitResult7( )
{
	font_13=TTFBuildFont(Font02, 13, 0);	
	font_13b=TTFBuildFont(Font02, 13, 1);	
	glColor4f(1.0,1.0,1.0,1.0);
	
	

	SDL_string_texture_create(font_13,   "Таблица результатов измерений. Золотое правило механики", 2,&result_tx01);
	SDL_string_texture_create(font_13b, "|    № опыта  |    F1        |      h1       |      F2       |    h2      |      A1        |       A2        | ", 2,&result_tx02);
	SDL_string_texture_create(font_13,   "------------------------------------------------------------------------------------------------------------------------------- ", 2,&result_tx03);
	SDL_string_texture_create(font_13b, "|        0          |     0         |      0         |      0        |     0        |        0        |          0       | ", 2,&result_tx04);
	SDL_string_texture_create(font_13b, "|        0          |     0         |      0         |      0        |     0        |        0        |          0       | ", 2,&result_tx05);
	SDL_string_texture_create(font_13b, "|        0          |     0         |      0         |      0        |     0        |        0        |          0       | ", 2,&result_tx06);
	
	

	//rglCreateTexture(GL_RGBA, 312, 256, &tex_render, txNoFilter, GL_REPLACE, GL_REPEAT, txNoCompressed,GL_FALSE);
	
	};
	
	
	
	void rglInitResult1( )
{
	font_13=TTFBuildFont(Font02, 13, 0);	
	font_13b=TTFBuildFont(Font02, 13, 1);	
	glColor4f(1.0,1.0,1.0,1.0);
	
	

	SDL_string_texture_create(font_13,   "Таблица результатов измерений. Измерение сил ", 2,&result_tx01);
	SDL_string_texture_create(font_13b, "|    № опыта  |   Масса груза кг.      |   Сила тяжести Н   |   Показания прибора     | ", 2,&result_tx02);
	SDL_string_texture_create(font_13,   "------------------------------------------------------------------------------------------------------------------------------- ", 2,&result_tx03);
	SDL_string_texture_create(font_13b, "|        0          |               0                 |               0               |                 0                   | ", 2,&result_tx04);
	SDL_string_texture_create(font_13b, "|        0          |               0                 |               0               |                 0                   | ", 2,&result_tx05);
	SDL_string_texture_create(font_13b, "|        0          |               0                 |               0               |                 0                   | ", 2,&result_tx06);
	SDL_string_texture_create(font_13b, "|        0          |               0                 |               0               |                 0                   | ", 2,&result_tx07);
	

	//rglCreateTexture(GL_RGBA, 312, 256, &tex_render, txNoFilter, GL_REPLACE, GL_REPEAT, txNoCompressed,GL_FALSE);
	
	};	
	
	
		void rglInitResult14( )
{
	font_13=TTFBuildFont(Font02, 13, 0);	
	font_13b=TTFBuildFont(Font02, 13, 1);	
	glColor4f(1.0,1.0,1.0,1.0);
	
	

	SDL_string_texture_create(font_13,   "Таблица результатов измерений. Жесткость пружины ", 2,&result_tx01);
	SDL_string_texture_create(font_13b, "|    № опыта  |         | F упр |  H        |             | dL |  мм     |  ", 2,&result_tx02);
	SDL_string_texture_create(font_13,   "------------------------------------------------------------------------------------------ ",  2,&result_tx03);
	SDL_string_texture_create(font_13b, "|        0          |               0                 |               0               |  ", 2,&result_tx04);
	SDL_string_texture_create(font_13b, "|        0          |               0                 |               0               |  ", 2,&result_tx05);
	SDL_string_texture_create(font_13b, "|        0          |               0                 |               0               |  ", 2,&result_tx06);
	SDL_string_texture_create(font_13b, "|        0          |               0                 |               0               |  ", 2,&result_tx07);
	

	//rglCreateTexture(GL_RGBA, 312, 256, &tex_render, txNoFilter, GL_REPLACE, GL_REPEAT, txNoCompressed,GL_FALSE);
	
	};	
	
		void rglInitResult18( )
{
	font_13=TTFBuildFont(Font02, 13, 0);	
	font_13b=TTFBuildFont(Font02, 13, 1);	
	glColor4f(1.0,1.0,1.0,1.0);
	
	

	SDL_string_texture_create(font_13,   "Таблица результатов измерений. Условия равновесия", 2,&result_tx01);
	SDL_string_texture_create(font_13b, "|    № опыта  |    P, н     |     L1, м     | M1=P*L1 |     F, н   |     L2, м      | M2=F*L2    | ", 2,&result_tx02);
	SDL_string_texture_create(font_13,   "------------------------------------------------------------------------------------------------------------------------------- ", 2,&result_tx03);
	SDL_string_texture_create(font_13b, "|        0          |     0         |      0         |      0        |     0        |        0        |          0       | ", 2,&result_tx04);
	SDL_string_texture_create(font_13b, "|        0          |     0         |      0         |      0        |     0        |        0        |          0       | ", 2,&result_tx05);
	SDL_string_texture_create(font_13b, "|        0          |     0         |      0         |      0        |     0        |        0        |          0       | ", 2,&result_tx06);
	SDL_string_texture_create(font_13b, "|        0          |     0         |      0         |      0        |     0        |        0        |          0       | ", 2,&result_tx07);
	

	//rglCreateTexture(GL_RGBA, 312, 256, &tex_render, txNoFilter, GL_REPLACE, GL_REPEAT, txNoCompressed,GL_FALSE);
	
	};
	
	
void rglInitResult19( )
{
	font_13=TTFBuildFont(Font02, 13, 0);	
	font_13b=TTFBuildFont(Font02, 13, 1);	
	glColor4f(1.0,1.0,1.0,1.0);
	
	

	SDL_string_texture_create(font_13,   "Таблица результатов измерений. Золотое правило механики", 2,&result_tx01);
	SDL_string_texture_create(font_13b, "|    № опыта  |    X1        |      X2       |      dX     |    dXср   |      dEp      |       dEn      | ", 2,&result_tx02);
	SDL_string_texture_create(font_13,   "------------------------------------------------------------------------------------------------------------------------------- ", 2,&result_tx03);
	SDL_string_texture_create(font_13b, "|        0          |     0         |      0         |      0        |     0        |        0        |          0       | ", 2,&result_tx04);
	SDL_string_texture_create(font_13b, "|        0          |     0         |      0         |      0        |     0        |        0        |          0       | ", 2,&result_tx05);
	SDL_string_texture_create(font_13b, "|        0          |     0         |      0         |      0        |     0        |        0        |          0       | ", 2,&result_tx06);
	
	

	//rglCreateTexture(GL_RGBA, 312, 256, &tex_render, txNoFilter, GL_REPLACE, GL_REPEAT, txNoCompressed,GL_FALSE);
	
	};
	
	
void rglInitResultTable( )
{	
	font_13=TTFBuildFont(Font02, 18, 1);	
	SDL_string_texture_create(font_13, "N1    ", 2,&result_tx01);
	SDL_string_texture_create(font_13, "N2     ", 2,&result_tx02);
	SDL_string_texture_create(font_13, "N3     ", 2,&result_tx03);
	SDL_string_texture_create(font_13, "N4    ", 2,&result_tx04);
	SDL_string_texture_create(font_13, "N5     ", 2,&result_tx05);
	SDL_string_texture_create(font_13, "N6     ", 2,&result_tx06);
	SDL_string_texture_create(font_13, "F2 - Step Parallax Mapping", 2,&result_tx07);
	rglCreateTexture(GL_RGBA, 1024, 512, &tex_render, txNoFilter, GL_REPLACE, GL_REPEAT, txNoCompressed,GL_FALSE);
	rglLoad_Texture(result_fon_tx, &result_fon, txAnisotropic_16, GL_DECAL, GL_REPEAT,txGL_COMPRESS,GL_TRUE);
	};	
	
	
void rglUpdateInfo(char *text)
{
	glColor4f(1.0,1.0,0.5,1.0);
	SDL_string_texture_create(font_13b, text, 2, &info_tx02);
	}	;
	
void rglUpdateResult3(char *text1, char *text2, char *text3, char *text4)
{
	//glColor4f(1.0,1.0,0.5,1.0);
	SDL_string_texture_create(font_13b, text1, 2, &result_tx04);
	SDL_string_texture_create(font_13b, text2, 2, &result_tx05);
	SDL_string_texture_create(font_13b, text3, 2, &result_tx06);
	SDL_string_texture_create(font_13b, text4, 2, &result_tx07);
	}	;

void rglUpdateResult7(char *text1, char *text2, char *text3)
{
	//glColor4f(1.0,1.0,0.5,1.0);
	SDL_string_texture_create(font_13b, text1, 2, &result_tx04);
	SDL_string_texture_create(font_13b, text2, 2, &result_tx05);
	SDL_string_texture_create(font_13b, text3, 2, &result_tx06);
	
	}	;

void rglUpdateResult18(char *text1, char *text2, char *text3)
{
	//glColor4f(1.0,1.0,0.5,1.0);
	SDL_string_texture_create(font_13b, text1, 2, &result_tx04);
	SDL_string_texture_create(font_13b, text2, 2, &result_tx05);
	SDL_string_texture_create(font_13b, text3, 2, &result_tx06);
	
	}	;

void rglUpdateResult19(char *text1, char *text2, char *text3)
{
	//glColor4f(1.0,1.0,0.5,1.0);
	SDL_string_texture_create(font_13b, text1, 2, &result_tx04);
	SDL_string_texture_create(font_13b, text2, 2, &result_tx05);
	SDL_string_texture_create(font_13b, text3, 2, &result_tx06);
	
	}	;

void rglUpdateTable(char *text)
{
	glColor4f(0.5,0.8,1.0,1.0);
	SDL_string_texture_create(font_24b, text, 2, &table_info);
	}	;
	
void rglUpdateLoad(char *text)
{
	glColor4f(0.5,0.8,1.0,1.0);
	SDL_string_texture_create(font_24b, text, 2, &load_tx01);
	}	;
	
void rglDeleteInfo()
{
	TTF_CloseFont( font_13 );
	TTF_CloseFont( font_13b );
	TTF_CloseFont( font_14b );
	TTF_CloseFont( font_24b );
	};

void rglDrawTable(GLint width, GLint height, GLfloat ix, GLfloat iy, GLuint shader)
{
	
GLbyte light;

rglMat4 info_pvm, info_mvm;
 
   rglSetProjection( width,  height, RGL_PROJECTION_ORTHO,  info_pvm);
   rglMatrix4Identity( info_mvm);
	light=glIsEnabled(GL_LIGHTING);
	if (light == GL_TRUE) 
		glDisable(GL_LIGHTING);
		
	
	glUseProgram(shader); 
	glUniformMatrix4fv(glGetUniformLocation(shader,"pmatrix"), 1,GL_FALSE, &info_pvm[0]);
	glUniformMatrix4fv(glGetUniformLocation(shader,"mvmatrix"), 1,GL_FALSE,& info_mvm[0]);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D,table_info);
	glUniform1i(glGetUniformLocation(shader,"Texture"), 0);
	rglSetBlendMode(13);
	SDL_string_render2D( ix,iy,&table_info);
	
	glUseProgram(0);


	glColor4ub(255,255,255,255);
	if (light == GL_TRUE )
		glEnable(GL_LIGHTING);
	
	glDisable(GL_BLEND);
	};

void rglDrawLoad(GLint width, GLint height, GLfloat ix, GLfloat iy, GLuint shader)
{
	
GLbyte light;

rglMat4 info_pvm, info_mvm;
 
   rglSetProjection( width,  height, RGL_PROJECTION_ORTHO,  info_pvm);
   rglMatrix4Identity( info_mvm);
	light=glIsEnabled(GL_LIGHTING);
	if (light == GL_TRUE) 
		glDisable(GL_LIGHTING);
		
	
	glUseProgram(shader); 
	glUniformMatrix4fv(glGetUniformLocation(shader,"pmatrix"), 1,GL_FALSE, &info_pvm[0]);
	glUniformMatrix4fv(glGetUniformLocation(shader,"mvmatrix"), 1,GL_FALSE,& info_mvm[0]);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D,table_info);
	glUniform1i(glGetUniformLocation(shader,"Texture"), 0);
	rglSetBlendMode(13);
	SDL_string_render2D( ix,iy,&load_tx01);
	
	glUseProgram(0);


	glColor4ub(255,255,255,255);
	if (light == GL_TRUE )
		glEnable(GL_LIGHTING);
	
	glDisable(GL_BLEND);
	};


void rglDrawInfo(GLint width, GLint height, GLfloat dx, GLfloat dy, GLuint shader, GLuint blend_mode)
{
	
GLbyte light;
GLint ix,iy;
rglMat4 info_pvm, info_mvm;
  // ogl_set_projection(SCREEN_WIDTH,SCREEN_HEIGHT, GL_PROJECTION_ORTHO);
   rglSetProjection( width,  height, RGL_PROJECTION_ORTHO,  info_pvm);
   rglMatrix4Identity( info_mvm);
	light=glIsEnabled(GL_LIGHTING);
	if (light == GL_TRUE) 
		glDisable(GL_LIGHTING);
	
	glColor4ub(128,128,255,0);
	//glColor4f(0.0,0.0,0.1,0);
	ix=0+dx;	
	iy=height-20;	
	
	glUseProgram(shader); 
	glUniformMatrix4fv(glGetUniformLocation(shader,"pmatrix"), 1,GL_FALSE, &info_pvm[0]);
	glUniformMatrix4fv(glGetUniformLocation(shader,"mvmatrix"), 1,GL_FALSE,& info_mvm[0]);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D,info_tx01);
	glUniform1i(glGetUniformLocation(shader,"Texture"), 0);
	rglSetBlendMode(13);
	SDL_string_render2D( ix,iy,&info_tx01);
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&info_tx02);
	//glColor4ub(128,128,255,0);
	
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&info_tx03);
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&info_tx04);
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&info_tx05);
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&info_tx06);
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&info_tx14);
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&info_tx07);
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&info_tx08);
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&info_tx09);
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&info_tx10);
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&info_tx11);
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&info_tx12);
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&info_tx15);
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&info_tx16);
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&info_tx13);
	glUseProgram(0);


	glColor4ub(255,255,255,255);
	if (light == GL_TRUE )
		glEnable(GL_LIGHTING);
	//ogl_set_projection(SCREEN_WIDTH,SCREEN_HEIGHT, GL_PROJECTION_PERSPECTIVE);
	glDisable(GL_BLEND);
	};
	
void rglDrawInfoFFP(GLint width, GLint height, GLfloat dx, GLfloat dy, GLuint blend_mode)
{
	GLbyte light;
GLint ix,iy;
//rglMat4 info_pvm, info_mvm;
  // ogl_set_projection(SCREEN_WIDTH,SCREEN_HEIGHT, GL_PROJECTION_ORTHO);
   rglSetProjectionFFP( width,  height, RGL_PROJECTION_ORTHO);
  // rglMatrix4Identity( info_mvm);
	light=glIsEnabled(GL_LIGHTING);
	if (light == GL_TRUE) 
		glDisable(GL_LIGHTING);
	
	//glColor4ub(128,128,255,0);
	glColor4f(0.0,0.0,0.1,0);
	ix=0+dx;	
	iy=height-20;	
	
	
	//glUseProgram(shader); 
	//glUniformMatrix4fv(glGetUniformLocation(shader,"pmatrix"), 1,GL_FALSE, &info_pvm[0]);
	//glUniformMatrix4fv(glGetUniformLocation(shader,"mvmatrix"), 1,GL_FALSE,& info_mvm[0]);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D,info_tx01);
	//glUniform1i(glGetUniformLocation(shader,"Texture"), 0);
	rglSetBlendMode(blend_mode);
	SDL_string_render2D( ix,iy,&info_tx01);
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&info_tx02);
	//glColor4ub(128,128,255,0);
	
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&info_tx03);
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&info_tx04);
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&info_tx05);
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&info_tx06);
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&info_tx07);
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&info_tx08);
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&info_tx09);
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&info_tx10);
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&info_tx11);
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&info_tx12);
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&info_tx13);
	//glUseProgram(0);




	glColor4ub(255,255,255,255);
	if (light == GL_TRUE )
		glEnable(GL_LIGHTING);
	
	rglSetProjectionFFP( width,  height, RGL_PROJECTION_PERSPECTIVE);
	glDisable(GL_BLEND);
	
	};

void rglDrawResult3(GLint width, GLint height, GLfloat dx, GLfloat dy, GLuint shader)
{
	GLbyte light;
GLint ix,iy;
rglMat4 info_pvm, info_mvm;
  // ogl_set_projection(SCREEN_WIDTH,SCREEN_HEIGHT, GL_PROJECTION_ORTHO);
   rglSetProjection( width,  height, RGL_PROJECTION_ORTHO,  info_pvm);
   rglMatrix4Identity( info_mvm);
	light=glIsEnabled(GL_LIGHTING);
	if (light == GL_TRUE) 
		glDisable(GL_LIGHTING);
	
	//glColor4ub(128,128,255,0);
	glColor4f(0.0,0.0,0.1,0);
	ix=0+dx;	
	iy=height-20;	
	
	glUseProgram(shader); 
	glUniformMatrix4fv(glGetUniformLocation(shader,"pmatrix"), 1,GL_FALSE, &info_pvm[0]);
	glUniformMatrix4fv(glGetUniformLocation(shader,"mvmatrix"), 1,GL_FALSE,& info_mvm[0]);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D,info_tx01);
	glUniform1i(glGetUniformLocation(shader,"Texture"), 0);
	rglSetBlendMode(13);
	//rglSetBlendMode(blend_mode);
	SDL_string_render2D( ix,iy,&result_tx01);
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&result_tx03);
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&result_tx02);
	//glColor4ub(128,128,255,0);	
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&result_tx03);
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&result_tx04);
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&result_tx03);
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&result_tx05);
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&result_tx03);
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&result_tx06);
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&result_tx03);
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&result_tx07);
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&result_tx03);

	glUseProgram(0);




	glColor4ub(255,255,255,255);
	if (light == GL_TRUE )
		glEnable(GL_LIGHTING);
	
	rglSetProjectionFFP( width,  height, RGL_PROJECTION_PERSPECTIVE);
	glDisable(GL_BLEND);
	
	};


void rglDrawResult14(GLint width, GLint height, GLfloat dx, GLfloat dy, GLuint shader)
{
	GLbyte light;
GLint ix,iy;
rglMat4 info_pvm, info_mvm;
  // ogl_set_projection(SCREEN_WIDTH,SCREEN_HEIGHT, GL_PROJECTION_ORTHO);
   rglSetProjection( width,  height, RGL_PROJECTION_ORTHO,  info_pvm);
   rglMatrix4Identity( info_mvm);
	light=glIsEnabled(GL_LIGHTING);
	if (light == GL_TRUE) 
		glDisable(GL_LIGHTING);
	
	//glColor4ub(128,128,255,0);
	glColor4f(0.0,0.0,0.1,0);
	ix=0+dx;	
	iy=height-20;	
	
	glUseProgram(shader); 
	glUniformMatrix4fv(glGetUniformLocation(shader,"pmatrix"), 1,GL_FALSE, &info_pvm[0]);
	glUniformMatrix4fv(glGetUniformLocation(shader,"mvmatrix"), 1,GL_FALSE,& info_mvm[0]);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D,info_tx01);
	glUniform1i(glGetUniformLocation(shader,"Texture"), 0);
	rglSetBlendMode(13);
	//rglSetBlendMode(blend_mode);
	SDL_string_render2D( ix,iy,&result_tx01);
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&result_tx03);
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&result_tx02);
	//glColor4ub(128,128,255,0);
	
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&result_tx03);
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&result_tx04);
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&result_tx03);
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&result_tx05);
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&result_tx03);
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&result_tx06);
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&result_tx03);
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&result_tx07);
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&result_tx03);

	glUseProgram(0);




	glColor4ub(255,255,255,255);
	if (light == GL_TRUE )
		glEnable(GL_LIGHTING);
	
	rglSetProjectionFFP( width,  height, RGL_PROJECTION_PERSPECTIVE);
	glDisable(GL_BLEND);
	
	};



void rglDrawResult7(GLint width, GLint height, GLfloat dx, GLfloat dy, GLuint shader)
{
	GLbyte light;
GLint ix,iy;
rglMat4 info_pvm, info_mvm;
  // ogl_set_projection(SCREEN_WIDTH,SCREEN_HEIGHT, GL_PROJECTION_ORTHO);
   rglSetProjection( width,  height, RGL_PROJECTION_ORTHO,  info_pvm);
   rglMatrix4Identity( info_mvm);
	light=glIsEnabled(GL_LIGHTING);
	if (light == GL_TRUE) 
		glDisable(GL_LIGHTING);
	
	//glColor4ub(128,128,255,0);
	glColor4f(0.0,0.0,0.1,0);
	ix=0+dx;	
	iy=height-20;	
	
	glUseProgram(shader); 
	glUniformMatrix4fv(glGetUniformLocation(shader,"pmatrix"), 1,GL_FALSE, &info_pvm[0]);
	glUniformMatrix4fv(glGetUniformLocation(shader,"mvmatrix"), 1,GL_FALSE,& info_mvm[0]);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D,info_tx01);
	glUniform1i(glGetUniformLocation(shader,"Texture"), 0);
	rglSetBlendMode(13);
	//rglSetBlendMode(blend_mode);
	SDL_string_render2D( ix,iy,&result_tx01);
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&result_tx03);
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&result_tx02);
	//glColor4ub(128,128,255,0);
	
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&result_tx03);
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&result_tx04);
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&result_tx03);
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&result_tx05);
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&result_tx03);
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&result_tx06);
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&result_tx03);
	iy=iy-dy;
	glUseProgram(0);




	glColor4ub(255,255,255,255);
	if (light == GL_TRUE )
		glEnable(GL_LIGHTING);
	
	rglSetProjectionFFP( width,  height, RGL_PROJECTION_PERSPECTIVE);
	glDisable(GL_BLEND);
	
	};

void rglDrawResult18(GLint width, GLint height, GLfloat dx, GLfloat dy, GLuint shader)
{
	GLbyte light;
GLint ix,iy;
rglMat4 info_pvm, info_mvm;
  // ogl_set_projection(SCREEN_WIDTH,SCREEN_HEIGHT, GL_PROJECTION_ORTHO);
   rglSetProjection( width,  height, RGL_PROJECTION_ORTHO,  info_pvm);
   rglMatrix4Identity( info_mvm);
	light=glIsEnabled(GL_LIGHTING);
	if (light == GL_TRUE) 
		glDisable(GL_LIGHTING);
	
	//glColor4ub(128,128,255,0);
	glColor4f(0.0,0.0,0.1,0);
	ix=0+dx;	
	iy=height-20;	
	
	glUseProgram(shader); 
	glUniformMatrix4fv(glGetUniformLocation(shader,"pmatrix"), 1,GL_FALSE, &info_pvm[0]);
	glUniformMatrix4fv(glGetUniformLocation(shader,"mvmatrix"), 1,GL_FALSE,& info_mvm[0]);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D,info_tx01);
	glUniform1i(glGetUniformLocation(shader,"Texture"), 0);
	rglSetBlendMode(13);
	//rglSetBlendMode(blend_mode);
	SDL_string_render2D( ix,iy,&result_tx01);
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&result_tx03);
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&result_tx02);
	//glColor4ub(128,128,255,0);
	
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&result_tx03);
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&result_tx04);
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&result_tx03);
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&result_tx05);
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&result_tx03);
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&result_tx06);
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&result_tx03);
	iy=iy-dy;
	glUseProgram(0);




	glColor4ub(255,255,255,255);
	if (light == GL_TRUE )
		glEnable(GL_LIGHTING);
	
	rglSetProjectionFFP( width,  height, RGL_PROJECTION_PERSPECTIVE);
	glDisable(GL_BLEND);
	
	};

void rglDrawResult19(GLint width, GLint height, GLfloat dx, GLfloat dy, GLuint shader)
{
	GLbyte light;
GLint ix,iy;
rglMat4 info_pvm, info_mvm;
  // ogl_set_projection(SCREEN_WIDTH,SCREEN_HEIGHT, GL_PROJECTION_ORTHO);
   rglSetProjection( width,  height, RGL_PROJECTION_ORTHO,  info_pvm);
   rglMatrix4Identity( info_mvm);
	light=glIsEnabled(GL_LIGHTING);
	if (light == GL_TRUE) 
		glDisable(GL_LIGHTING);
	
	//glColor4ub(128,128,255,0);
	glColor4f(0.0,0.0,0.1,0);
	ix=0+dx;	
	iy=height-20;	
	
	glUseProgram(shader); 
	glUniformMatrix4fv(glGetUniformLocation(shader,"pmatrix"), 1,GL_FALSE, &info_pvm[0]);
	glUniformMatrix4fv(glGetUniformLocation(shader,"mvmatrix"), 1,GL_FALSE,& info_mvm[0]);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D,info_tx01);
	glUniform1i(glGetUniformLocation(shader,"Texture"), 0);
	rglSetBlendMode(13);
	//rglSetBlendMode(blend_mode);
	SDL_string_render2D( ix,iy,&result_tx01);
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&result_tx03);
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&result_tx02);
	//glColor4ub(128,128,255,0);
	
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&result_tx03);
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&result_tx04);
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&result_tx03);
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&result_tx05);
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&result_tx03);
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&result_tx06);
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&result_tx03);
	iy=iy-dy;
	glUseProgram(0);




	glColor4ub(255,255,255,255);
	if (light == GL_TRUE )
		glEnable(GL_LIGHTING);
	
	rglSetProjectionFFP( width,  height, RGL_PROJECTION_PERSPECTIVE);
	glDisable(GL_BLEND);
	
	};

void rglDrawResult1(GLint width, GLint height, GLfloat dx, GLfloat dy, GLuint shader)
{
	GLbyte light;
GLint ix,iy;
rglMat4 info_pvm, info_mvm;
  // ogl_set_projection(SCREEN_WIDTH,SCREEN_HEIGHT, GL_PROJECTION_ORTHO);
   rglSetProjection( width,  height, RGL_PROJECTION_ORTHO,  info_pvm);
   rglMatrix4Identity( info_mvm);
	light=glIsEnabled(GL_LIGHTING);
	if (light == GL_TRUE) 
		glDisable(GL_LIGHTING);
	
	//glColor4ub(128,128,255,0);
	glColor4f(0.0,0.0,0.1,0);
	ix=0+dx;	
	iy=height-20;	
	
	glUseProgram(shader); 
	glUniformMatrix4fv(glGetUniformLocation(shader,"pmatrix"), 1,GL_FALSE, &info_pvm[0]);
	glUniformMatrix4fv(glGetUniformLocation(shader,"mvmatrix"), 1,GL_FALSE,& info_mvm[0]);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D,info_tx01);
	glUniform1i(glGetUniformLocation(shader,"Texture"), 0);
	rglSetBlendMode(13);
	//rglSetBlendMode(blend_mode);
	SDL_string_render2D( ix,iy,&result_tx01);
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&result_tx03);
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&result_tx02);
	//glColor4ub(128,128,255,0);
	
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&result_tx03);
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&result_tx04);
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&result_tx03);
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&result_tx05);
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&result_tx03);
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&result_tx06);
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&result_tx03);
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&result_tx07);
	iy=iy-dy;
	SDL_string_render2D( ix,iy,&result_tx03);

	glUseProgram(0);




	glColor4ub(255,255,255,255);
	if (light == GL_TRUE )
		glEnable(GL_LIGHTING);
	
	rglSetProjectionFFP( width,  height, RGL_PROJECTION_PERSPECTIVE);
	glDisable(GL_BLEND);
	
	};


void rglDrawResultTableFFP(GLint width, GLint height, GLfloat x, GLfloat y, GLfloat dx)
{
	GLbyte light;
GLint ix,iy;
	
   rglSetProjectionFFP( width,  height, RGL_PROJECTION_ORTHO);

	light=glIsEnabled(GL_LIGHTING);
	if (light == GL_TRUE) 
		glDisable(GL_LIGHTING);
	

	glColor4f(0.0,0.0,0.1,0);
	ix=(GLuint)x;	
	iy=height-(GLuint)y;	   
   
   //rglSetBlendMode(93);
  /*
	glActiveTexture(GL_TEXTURE0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, result_fon);	
	 glDisable( GL_DEPTH_TEST ); 
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glColor3f( 0.0, 1.0, 1.0);glVertex3f( 0.0,  0.0,  0.0);
		glTexCoord2f(1.0, 0.0); glColor3f( 0.0, 1.0, 1.0);glVertex3f( (float)width, 0.0,  0.0);
		glTexCoord2f(1.0, 1.0); glColor3f( 0.0, 1.0, 1.0);glVertex3f( (float)width,   (float)height,  0.0);
		glTexCoord2f(0.0, 1.0); glColor3f( 0.0, 1.0, 1.0);glVertex3f(0,   (float)height, 0.0);
     glEnd();
glEnable( GL_DEPTH_TEST );
	*/
	
	
	rglSetBlendMode(13);
	SDL_string_render2D( ix,iy,&result_tx01);
	ix=ix+(GLuint)dx;
	SDL_string_render2D( ix,iy,&result_tx02);
	ix=ix+(GLuint)dx;
	SDL_string_render2D( ix,iy,&result_tx03);
	ix=ix+(GLuint)dx;
	SDL_string_render2D( ix,iy,&result_tx04);
	ix=ix+(GLuint)dx;
	SDL_string_render2D( ix,iy,&result_tx05);
	ix=ix+(GLuint)dx;
	SDL_string_render2D( ix,iy,&result_tx06);
	ix=ix+(GLuint)dx;
	SDL_string_render2D( ix,iy,&result_tx07);
	

	glColor4ub(255,255,255,255);
	if (light == GL_TRUE )
		glEnable(GL_LIGHTING);
	
	rglSetProjectionFFP( width,  height, RGL_PROJECTION_PERSPECTIVE);
	glDisable(GL_BLEND);
	
	};




void rglDrawInfoToTexture(GLint width, GLint height, GLfloat dx, GLfloat dy, GLuint blend_mode)
{
	glClearColor(0.1, 0.1, 0.1, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glViewport(0, 0, 312, 256);
	glEnable(GL_TEXTURE_2D);
	
	rglDrawInfoFFP(312, 256, 20.0, dy, blend_mode);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, tex_render);	
 	glCopyTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 0, 0, 312, 256, 0);
	
	glDisable(GL_TEXTURE_2D);
 	glViewport(0, 0, width, height);
 	glClearColor(0.0, 0.0, 0.0, 1.0);
 	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();		
	
	};
	
void rglDrawResultToTexture(GLint width, GLint height, GLfloat x, GLfloat y, GLfloat dx)
{
	glClearColor(0.1, 0.1, 0.1, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glViewport(0, 0, 1024, 512);
	glEnable(GL_TEXTURE_2D);
	
	
	rglDrawResultTableFFP(1024, 512, x, y, dx);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, tex_render);	
 	glCopyTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 0, 0, 1024, 512, 0);
	
	glDisable(GL_TEXTURE_2D);
 	glViewport(0, 0, width, height);
 	glClearColor(0.0, 0.0, 0.0, 1.0);
 	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();		
	
	};	
	
	
	
void quad(GLfloat size)
{
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glColor3f( 0.0, 1.0, 1.0);glVertex3f( 0.0*size,  0.0*size,  0.0*size);
		glTexCoord2f(1.0, 0.0); glColor3f( 0.0, 1.0, 1.0);glVertex3f( 4.0*size, 0.0*size,  0.0*size);
		glTexCoord2f(1.0, 1.0); glColor3f( 0.0, 1.0, 1.0);glVertex3f( 4.0*size,  2.0*size,  0.0*size);
		glTexCoord2f(0.0, 1.0); glColor3f( 0.0, 1.0, 1.0);glVertex3f( 0.0*size,  2.0*size, 0.0*size);
     glEnd();

	}	
	
void rglDrawInfo2()
{
	//rglSetProjectionFFP( width,  height, RGL_PROJECTION_ORTHO);

	glActiveTexture(GL_TEXTURE0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, tex_render);
	glTranslatef(-3.0, -3.0,-10.0);
	//glRotatef(55, 0.0,1.0,0.0);
	quad(1.0);
	//rglSetProjectionFFP( width,  height, RGL_PROJECTION_PERSPECTIVE);
	}

void rglDrawResultTable()
{
	

	glActiveTexture(GL_TEXTURE0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, tex_render);
	glTranslatef(-6.0, -3.0,-5.0);
	
	quad(1.0);
	
	}	

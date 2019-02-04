#include "rglText.h"



TTF_Font *TTFBuildFont(char *filename, GLint size, GLint style)
{
TTF_Init ();

if(!filename) printf("file %s not found\n", filename); 
TTF_Font *temp_font = TTF_OpenFont(filename, size );
if(!temp_font) 
    printf("TTF_OpenFont: %s\n", TTF_GetError());    


switch  (style) 
{
case 0: TTF_SetFontStyle( temp_font, TTF_STYLE_NORMAL );break;
case 1: TTF_SetFontStyle( temp_font, TTF_STYLE_BOLD );break;
case 2: TTF_SetFontStyle( temp_font, TTF_STYLE_ITALIC );break;
case 3: TTF_SetFontStyle( temp_font, TTF_STYLE_UNDERLINE );break;
case 4: TTF_SetFontStyle( temp_font, TTF_STYLE_BOLD | TTF_STYLE_ITALIC);break;
default:TTF_SetFontStyle( temp_font, TTF_STYLE_NORMAL );break;
}

return temp_font;
}

 void SDL_string_texture_create(TTF_Font *font, char *text, GLuint solid,  GLuint *texture)
 {
SDL_Surface *text_image ;
SDL_Surface *temp_image ;

SDL_Color fg_color, bg_color; 

GLfloat f_color[4];
GLfloat b_color[4];


	glGetFloatv(GL_CURRENT_COLOR, f_color);
	fg_color.r=(GLint) (f_color[0]*255);
	fg_color.g=(GLint) (f_color[1]*255);
	fg_color.b=(GLint) (f_color[2]*255);
	glGetFloatv(GL_CURRENT_SECONDARY_COLOR, b_color);
	bg_color.r=(GLint) (b_color[0]*255);
	bg_color.g=(GLint) (b_color[1]*255);
	bg_color.b=(GLint) (b_color[2]*255);	
	
	switch (solid) 
	{
		case 0: text_image = TTF_RenderUTF8_Solid(font, text , fg_color);break;
		case 1:text_image = TTF_RenderUTF8_Shaded(font, text , fg_color, bg_color); break;
		case 2: text_image = TTF_RenderUTF8_Blended(font, text , fg_color); break;
		default: text_image = TTF_RenderUTF8_Solid(font, text , fg_color);break;
	}
   	temp_image = SDL_CreateRGBSurface(SDL_HWSURFACE, text_image->w, text_image->h, 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);
   	SDL_BlitSurface(text_image, 0, temp_image, 0); 
   	
    glGenTextures(1, texture);    
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);    	
	glBindTexture(GL_TEXTURE_2D, *texture);	
	
	
	glTexImage2D(GL_TEXTURE_2D, 0,  4, temp_image->w, temp_image->h, 0, GL_BGRA, GL_UNSIGNED_BYTE, temp_image->pixels );
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);	
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);	

	SDL_FreeSurface(text_image);
  	SDL_FreeSurface(temp_image);
}

void SDL_string_texture_update(TTF_Font *font, char *text, GLuint solid,  GLuint *texture)
 {
SDL_Surface *text_image ;
SDL_Surface *temp_image ;

SDL_Color fg_color, bg_color; 

GLfloat f_color[4];
GLfloat b_color[4];


	glGetFloatv(GL_CURRENT_COLOR, f_color);
	fg_color.r=(GLint) (f_color[0]*255);
	fg_color.g=(GLint) (f_color[1]*255);
	fg_color.b=(GLint) (f_color[2]*255);
	glGetFloatv(GL_CURRENT_SECONDARY_COLOR, b_color);
	bg_color.r=(GLint) (b_color[0]*255);
	bg_color.g=(GLint) (b_color[1]*255);
	bg_color.b=(GLint) (b_color[2]*255);	
	
	switch (solid) 
	{
		case 0: text_image = TTF_RenderUTF8_Solid(font, text , fg_color);break;
		case 1: text_image = TTF_RenderUTF8_Shaded(font, text , fg_color, bg_color); break;
		case 2: text_image = TTF_RenderUTF8_Blended(font, text , fg_color); break;
		default: text_image = TTF_RenderUTF8_Solid(font, text , fg_color);break;
	}
   	temp_image = SDL_CreateRGBSurface(SDL_HWSURFACE, text_image->w, text_image->h, 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);
   	SDL_BlitSurface(text_image, 0, temp_image, 0); 
   	
       	
	glBindTexture(GL_TEXTURE_2D, *texture);	
	glTexSubImage2D(GL_TEXTURE_2D, 0,  1, 1, temp_image->w, temp_image->h, GL_BGRA, GL_UNSIGNED_BYTE, temp_image->pixels );
	

	SDL_FreeSurface(text_image);
  	SDL_FreeSurface(temp_image);
}


void SDL_string_render2D( GLuint x, GLuint y, GLuint *texture )
 {
 		
GLint w;
GLint h;

	glEnable(GL_TEXTURE_2D);	
    glDisable( GL_DEPTH_TEST ); 	
	
	
    glBindTexture(GL_TEXTURE_2D, *texture);
	glGetTexLevelParameteriv(GL_TEXTURE_2D,0,GL_TEXTURE_WIDTH, &w);
    glGetTexLevelParameteriv(GL_TEXTURE_2D,0,GL_TEXTURE_HEIGHT,&h);
	//printf("Width= %i\n", w);
	//printf("Height= %i\n", h);
   glBegin(GL_QUADS);			
			glTexCoord2f(0.0,1.0);glVertex3f(x, y, 0.0);			
			glTexCoord2f(0.0,0.0);glVertex3f(x, y+h, 0.0) ;			
			glTexCoord2f(1.0,0.0);glVertex3f(x+w, y+h, 0.0);			
			glTexCoord2f(1.0,1.0);glVertex3f(x+w, y, 0.0);			
     glEnd(); 
     
   glDisable(GL_TEXTURE_2D);

	
  glEnable( GL_DEPTH_TEST );
 
 	
}


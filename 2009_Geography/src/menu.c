#include "menu.h"

GLint menu_size_w=100* menu_size_coef;
GLint menu_size_h=30* menu_size_coef;
GLint menu_coords [4] [MENU_COUNT];
GLuint menu_tex [MENU_COUNT+1];


GLint menu_activ_button=-1;

GLvoid menu_init(){
	menu_create_tex();
	menu_create_coords(botom);
	};
GLvoid menu_create_tex(){

	OGL_Load_Texture("../data/textures/menu/menu0.tga", &menu_tex[0], txTrilinear, GL_MODULATE, GL_CLAMP, txNoCompressed,GL_TRUE);
	OGL_Load_Texture("../data/textures/menu/menu1.tga", &menu_tex[1], txTrilinear, GL_MODULATE, GL_CLAMP, txNoCompressed,GL_TRUE);
	OGL_Load_Texture("../data/textures/menu/menu2.tga", &menu_tex[2], txTrilinear, GL_MODULATE, GL_CLAMP, txNoCompressed,GL_TRUE);
	OGL_Load_Texture("../data/textures/menu/menu4.tga", &menu_tex[3], txTrilinear, GL_MODULATE, GL_CLAMP, txNoCompressed,GL_TRUE);
	OGL_Load_Texture("../data/textures/menu/menu3.tga", &menu_tex[4], txTrilinear, GL_MODULATE, GL_CLAMP, txNoCompressed,GL_TRUE);
	//OGL_Load_Texture("../data/textures/menu/menu0.tga", &menu_tex[5], txTrilinear, GL_MODULATE, GL_CLAMP, txNoCompressed,GL_TRUE);
	//OGL_Load_Texture("../data/textures/menu/menu0.tga", &menu_tex[6], txTrilinear, GL_MODULATE, GL_CLAMP, txNoCompressed,GL_TRUE);
	//OGL_Load_Texture("../data/textures/menu/menu0.tga", &menu_tex[7], txTrilinear, GL_MODULATE, GL_CLAMP, txNoCompressed,GL_TRUE);	
	//OGL_Load_Texture("../data/textures/menu/menu0.tga", &menu_tex[8], txTrilinear, GL_MODULATE, GL_CLAMP, txNoCompressed,GL_TRUE);
	//OGL_Load_Texture("../data/textures/menu/menu0.tga", &menu_tex[9], txTrilinear, GL_MODULATE, GL_CLAMP, txNoCompressed,GL_TRUE);
	};
	
GLvoid menu_create_coords(menu_position ps){
	menu_coords[0][0]=((SCREEN_WIDTH - MENU_COUNT*2) - (MENU_COUNT*menu_size_w))/2;
	menu_coords[1][0]= 2;
	menu_coords[2][0]=menu_coords[0][0]+menu_size_w;
	menu_coords[3][0]=menu_coords[1][0] + menu_size_h;
	
	for (GLint i=1;i<MENU_COUNT;i++)
		{
			menu_coords[0][i]=menu_coords[0][i-1]+menu_size_w+1;
			menu_coords[1][i]=menu_coords[1][0];
			menu_coords[2][i]=menu_coords[2][i-1]+menu_size_w+1;
			menu_coords[3][i]=menu_coords[3][0];
		} 
		

	};
GLvoid menu_draw(){
	
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	for (GLint i=0;i<MENU_COUNT;i++)
		{
			   glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
			   
			   if ( (scena_draw==9) && (i==1))
				   glBindTexture(GL_TEXTURE_2D, menu_tex[MENU_COUNT]);
			   else
			   		glBindTexture(GL_TEXTURE_2D, menu_tex[i]); 
					
			  if (i == menu_activ_button)
			  		glBlendFunc(GL_SRC_ALPHA,GL_DST_ALPHA);
				
						
			   glBegin(GL_QUADS);   
					glTexCoord2f(0.0,0.0);glColor3ub(255,255,255);glVertex3f( menu_coords[0][i],menu_coords[1][i], 0);
					glTexCoord2f(1.0,0.0);glColor3ub(255,255,255);glVertex3f(menu_coords[2][i],menu_coords[1][i], 0);	
					glTexCoord2f(1.0,1.0);glColor3ub(255,255,255);glVertex3f(menu_coords[2][i],menu_coords[3][i], 0);			 		
					glTexCoord2f(0.0,1.0);glColor3ub(255,255,255);glVertex3f( menu_coords[0][i],menu_coords[3][i], 0);
				glEnd();
				  if (i == menu_activ_button)
			  		  glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
		}
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
	};
	
GLvoid menu_mouse_motion(SDL_MouseMotionEvent *motion){
	GLint x_mouse=motion->x;
	GLint y_mouse=SCREEN_HEIGHT - motion->y;
	menu_activ_button=-1;
	for (GLint i=0;i<MENU_COUNT;i++)
		{
	if ((x_mouse> menu_coords[0][i]) &&  (x_mouse< menu_coords[2][i]) && (y_mouse> menu_coords[1][i]) &&  (y_mouse< menu_coords[3][i]))
			menu_activ_button=i;
		}

	};
	
GLvoid menu_mouse_button_pressed(SDL_MouseButtonEvent *button){
	switch ( button->button )
{
	    case SDL_BUTTON_LEFT :;break;
		case SDL_BUTTON_MIDDLE :;break;
		case SDL_BUTTON_RIGHT :;break;
		case SDL_BUTTON_WHEELUP :;break;
		case SDL_BUTTON_WHEELDOWN :;break;			
}
	
	
	};

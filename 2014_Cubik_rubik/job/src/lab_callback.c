#include "lab_callback.h"
int flag_alter=0;
int draw_scena_help=0;
extern int done;
extern float ray;
extern float rax;
extern float raz;
extern float angle;
extern int flag;
extern int flag_FR;
extern int flag_BL;
extern int flag_BR;
extern int flag_UL;
extern int flag_UR;
extern int flag_DL;
extern int flag_DR;
extern int flag_LL;
extern int flag_LR;
extern int flag_RL;
extern int flag_RR;
extern int draw_scena;
extern int button_1;
extern int button_2;
extern int button_3;

extern float w_const;
extern float h_const;

extern int flag_SND;
//переменные флаги нажатия кнопок мыши
int LBM_press=0,MBM_press=0,RBM_press=0;
double xx=0.0, yy=0.0;
//Функция изменения размеров окна
void ogl_reshape(GLFWwindow *w, int width, int height)
{
	if (height==0)
			height=1;
		glViewport(0,0, width, height);
		ogl_init();
}
//Функция реакции на нажатие клавиши
void key_press(GLFWwindow *w, int key, int scancode, int action, int mods)
{
	if ((key==GLFW_KEY_ESCAPE)&&(action==GLFW_PRESS)){
		//printf("Press - %i\n",key);
			if (draw_scena==1){
			draw_scena=0;
			}else{
			if (draw_scena_help==1){
			draw_scena_help=0;
			}
			else{
			done=0;}
			}
		}
	if ((key==GLFW_KEY_F1)&&(action==GLFW_PRESS)){
		printf("Press - F1\n");
		}
		
		
	if ((key==GLFW_KEY_LEFT)&&(action==GLFW_PRESS)){
		ray-=5.0;
		//printf("Press - LEFT %5.2f\n",ray);
		}
	if ((key==GLFW_KEY_RIGHT)&&(action==GLFW_PRESS)){
		ray+=5.0;
		//printf("Press - RIGHT %5.2f\n",ray);
		}	
	if ((key==GLFW_KEY_UP)&&(action==GLFW_PRESS)){
		rax-=5.0;
		//printf("Press - UP %5.2f\n",rax);
		}
	if ((key==GLFW_KEY_DOWN)&&(action==GLFW_PRESS)){
		rax+=5.0;
		//printf("Press - DOWN %5.2f\n",rax);
		}
	if ((key==GLFW_KEY_HOME)&&(action==GLFW_PRESS)){
		raz+=5.0;
	}
	if ((key==GLFW_KEY_END)&&(action==GLFW_PRESS)){
		raz-=5.0;
	}
	if ((key==GLFW_KEY_V)&&(action==GLFW_PRESS)&&(flag==0)&&(flag_alter==0)){
		angle=0.0;
		flag=1;
		flag_alter=1;
		}
	if ((key==GLFW_KEY_N)&&(action==GLFW_PRESS)&&(flag_FR==0)&&(flag_alter==0)){
		angle=0.0;
		flag_FR=1;
		flag_alter=1;
		}
	if ((key==GLFW_KEY_KP_7)&&(action==GLFW_PRESS)&&(flag_UL==0)&&(flag_alter==0)){
		angle=0.0;
		flag_UL=1;
		flag_alter=1;
		}
	if ((key==GLFW_KEY_KP_9)&&(action==GLFW_PRESS)&&(flag_UR==0)&&(flag_alter==0)){
		angle=0.0;
		flag_UR=1;
		flag_alter=1;
		}
	if ((key==GLFW_KEY_R)&&(action==GLFW_PRESS)&&(flag_BL==0)&&(flag_alter==0)){
		angle=0.0;
		flag_BL=1;
		flag_alter=1;
		}
	if ((key==GLFW_KEY_Y)&&(action==GLFW_PRESS)&&(flag_BR==0)&&(flag_alter==0)){
		angle=0.0;
		flag_BR=1;
		flag_alter=1;
		}
	if ((key==GLFW_KEY_KP_1)&&(action==GLFW_PRESS)&&(flag_DL==0)&&(flag_alter==0)){
		angle=0.0;
		flag_DL=1;
		flag_alter=1;
		}
	if ((key==GLFW_KEY_KP_3)&&(action==GLFW_PRESS)&&(flag_DR==0)&&(flag_alter==0)){
		angle=0.0;
		flag_DR=1;
		flag_alter=1;
		}
	if ((key==GLFW_KEY_Q)&&(action==GLFW_PRESS)&&(flag_LL==0)&&(flag_alter==0)){
		angle=0.0;
		flag_LL=1;
		flag_alter=1;
		}
	if ((key==GLFW_KEY_Z)&&(action==GLFW_PRESS)&&(flag_LR==0)&&(flag_alter==0)){
		angle=0.0;
		flag_LR=1;
		flag_alter=1;
		}
	if ((key==GLFW_KEY_C)&&(action==GLFW_PRESS)&&(flag_RL==0)&&(flag_alter==0)){
		angle=0.0;
		flag_RL=1;
		flag_alter=1;
		}
	if ((key==GLFW_KEY_E)&&(action==GLFW_PRESS)&&(flag_RR==0)&&(flag_alter==0)){
		angle=0.0;
		flag_RR=1;
		flag_alter=1;
		}
	if ((key==GLFW_KEY_S)&&(action==GLFW_PRESS)&&(flag_RR==0)&&(flag_alter==0)){
		if (flag_SND==0)
			flag_SND=1;
		else
			flag_SND=0;
		printf("flag_SND - %d \n",flag_SND);
		}
}
//Функция реакции на ввод символов
void char_input(GLFWwindow *w, unsigned int ch)
{
	if((ch=='q')||(ch=='Q'))
		done=0;
	if((ch=='f')||(ch=='F'))
		printf("Press - %c\n",ch);
}

int old_x=0;
int old_y=0;
//Функция реакции на нажатие кнопок мыши
void mouse_button_press(GLFWwindow *w, int button, int action, int mods)
{
double x,y;
	//action is GLFW_PRESS or GLFW_RELEASE, MBM_press=0,RBM_press=0
		if (button==GLFW_MOUSE_BUTTON_LEFT){
			if(action==GLFW_PRESS){
				LBM_press=1;
				//printf("Press left mouse button\n");
				glfwGetCursorPos(w,&x,&y);
				old_x=x;old_y=y;
					if (((x>=390.0)&&(x<=635.0))&&((y>=385.0)&&(y<=446.0))&&(draw_scena==0)&&(draw_scena==0)){
						if (draw_scena_help==0){
						draw_scena=1;
						}
					}
					if (((x>=390.0)&&(x<=635.0))&&((y>=469.0)&&(y<=531.0))&&(draw_scena_help==0)&&(draw_scena==0)){
					draw_scena_help=1;
					}
					if (((x>=390.0)&&(x<=635.0))&&((y>=557.0)&&(y<=617.0))&&(draw_scena==0)&&(draw_scena==0)){
						if (draw_scena_help==0){
						done=0;}
					}
				printf("%0.2lf %0.2lf\n",x,y);
			}
			else
			{
				LBM_press=0;
				//printf("Release left mouse button\n");
			}
		}
		if (button==GLFW_MOUSE_BUTTON_MIDDLE){
			if (action==GLFW_PRESS){
				MBM_press=1;
				//printf("Press middle mouse button\n");
			}
			else
			{
				MBM_press=0;
				//printf("Release middle mouse button\n");
			}
		}
		if(button==GLFW_MOUSE_BUTTON_RIGHT){
			if(action==GLFW_PRESS){
				RBM_press=1; //printf("Press right mouse button \n");
			}
			else
			{
				RBM_press=0; //printf("Release right mouse button\n");
			}
		}
}

float rxa=0.0;
float rya=0.0;
//Функция реакции на движение мыши
void mouse_pos(GLFWwindow *w, double x, double y)
{
int dx,dy;
dx=x-old_x; dy=y-old_y;
	if (((x>=384.0)&&(x<=640.0))&&((y>=385.0)&&(y<=446.0))){
	if (button_1==0){
	button_1=1;}
	}else{if (button_1==1){button_1=0;}}
	
	if (((x>=384.0)&&(x<=640.0))&&((y>=469.0)&&(y<=531.0))){
	if (button_2==0){
	button_2=1;}
	}else{if (button_2==1){button_2=0;}}
	
	if (((x>=384.0)&&(x<=640.0))&&((y>=557.0)&&(y<=617.0))){
	if (button_3==0){
	button_3=1;}
	}else{if (button_3==1){button_3=0;}}
	//printf("mouse pos: x= %5.2f y= %5.2f\n",x,y);
	
	if (LBM_press==1){
	printf("h_const=%0.4f",h_const);
	rxa+=((float) dx/ (float) h_const)*M_PI;
	rya+=((float) dy/ (float) h_const)*M_PI;
	printf(" rxa=%0.4f rya=%0.4f\n",rxa,rya);
	}
	old_x=x;old_y=y;
}
//Функция реакции на прокрутку колеса мыши
void mouse_wheel(GLFWwindow *w, double x, double y)
{
	xx+=x;yy+=y;
	printf("Wheel pos x= %5.2f y= %5.2f\n",x,y);
}

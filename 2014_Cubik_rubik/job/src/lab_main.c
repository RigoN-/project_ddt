#include "lab_main.h"
float angle=90.0;
extern cubik_t b;
extern cubik_t c;
extern cube_t g;
extern cube_t g1;
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
extern float SPEED;
extern int flag_alter;
//sound virable
HSTREAM stream;
HSAMPLE sam01 ;
HCHANNEL ch01;
int flag_SND=1;
char *sndrs="../data/sound/01.mp3";

void prog_exit(GLFWwindow *w)
{
	if(!glfwWindowShouldClose(w)) {
	glfwDestroyWindow(w);
	}
	BASS_SampleFree(sam01);
	BASS_Free();
	glfwTerminate();
	
	printf("%s\n","Exit Ok");
}

//Функция подсчета и вывода FPS
void fps_counter(GLFWwindow *w, int t)
{
	if(fps_enable){
		current_time=glfwGetTime();
		if((current_time - old_time)*1000>=t){
			frame_sum+=frame;
			double fps= frame_sum / (current_time);
			sprintf(str_title,"%s: FPS:%.2f FPS_AVR:%.2f",W_CAPTION,frame/(t/1000),fps);
			frame=0.0; old_time=current_time;
			if(!w_mode)
				glfwSetWindowTitle(w,str_title);
				printf("%s\n",str_title);
		}
	}
}

//Функция обработки параметров командной строки
void argc_init(int argc, char **argv)
{
	int i;
	for(i=1;i<argc;i++){
		if(!strcmp(argv[i],"--info")){
		gl_info=1;
		glfw_info=1;
		}
		/*
		if(!strcmp(argv[i],"--help")){
		help_info=1;
		}*/	
		if(!strcmp(argv[i],"--full")){
		w_mode=1;
		}
		if(!strcmp(argv[i],"--fps")){
		fps_enable=1;
		}
	}
}
//Функция округления значений координат куба 3х3х3
void correct(cubik_t *b){
int  n,i,j,k;
	for (i=0;i<3;i++){
		for (j=0;j<3;j++){
			for (k=0;k<3;k++){
				for (n=0;n<36;n++){
				b->mass[i][j][k].m[n].x=round(b->mass[i][j][k].m[n].x);
				b->mass[i][j][k].m[n].y=round(b->mass[i][j][k].m[n].y);
				b->mass[i][j][k].m[n].z=round(b->mass[i][j][k].m[n].z);
				//printf("b = %0.6f %0.6f %0.6f\n",b->mass[0][0][0].m[0].x,b->mass[0][0][0].m[0].y,b->mass[0][0][0].m[0].z);
				}
			}
		}
	}
}
//Анимация поворота граней
void animation(cube_t *g, cube_t *g1, cubik_t *b/*, cubik_t *c*/){
	if (angle<90.0){
		angle+=SPEED;
	}
	else
	{
	correct(b);
		if (flag==1){
		*g=b->mass[0][0][0];
		b->mass[0][0][0]=b->mass[0][0][2];
		*g1=b->mass[0][2][0];
		b->mass[0][2][0]=*g;
		*g=b->mass[0][2][2];
		b->mass[0][2][2]=*g1;
		b->mass[0][0][2]=*g;
		
		*g=b->mass[0][0][1];
		b->mass[0][0][1]=b->mass[0][1][2];
		*g1=b->mass[0][1][0];
		b->mass[0][1][0]=*g;
		*g=b->mass[0][2][1];
		b->mass[0][2][1]=*g1;
		b->mass[0][1][2]=*g;
		flag=0;
		}
		
		if (flag_FR==1){
		*g=b->mass[0][0][0];
		b->mass[0][0][0]=b->mass[0][2][0];
		*g1=b->mass[0][0][2];
		b->mass[0][0][2]=*g;
		*g=b->mass[0][2][2];
		b->mass[0][2][2]=*g1;
		b->mass[0][2][0]=*g;
		
		*g=b->mass[0][0][1];
		b->mass[0][0][1]=b->mass[0][1][0];
		*g1=b->mass[0][1][2];
		b->mass[0][1][2]=*g;
		*g=b->mass[0][2][1];
		b->mass[0][2][1]=*g1;
		b->mass[0][1][0]=*g;
		flag_FR=0;
		}
		
		if (flag_LL==1){
		*g=b->mass[2][0][0];
		b->mass[2][0][0]=b->mass[0][0][0];
		*g1=b->mass[2][2][0];
		b->mass[2][2][0]=*g;
		*g=b->mass[0][2][0];
		b->mass[0][2][0]=*g1;
		b->mass[0][0][0]=*g;
		
		*g=b->mass[1][0][0];
		b->mass[1][0][0]=b->mass[0][1][0];
		*g1=b->mass[2][1][0];
		b->mass[2][1][0]=*g;
		*g=b->mass[1][2][0];
		b->mass[1][2][0]=*g1;
		b->mass[0][1][0]=*g;
		flag_LL=0;
		}
		
		if (flag_LR==1){
		*g=b->mass[2][0][0];
		b->mass[2][0][0]=b->mass[2][2][0];
		*g1=b->mass[0][0][0];
		b->mass[0][0][0]=*g;
		*g=b->mass[0][2][0];
		b->mass[0][2][0]=*g1;
		b->mass[2][2][0]=*g;
		
		*g=b->mass[1][0][0];
		b->mass[1][0][0]=b->mass[2][1][0];
		*g1=b->mass[0][1][0];
		b->mass[0][1][0]=*g;
		*g=b->mass[1][2][0];
		b->mass[1][2][0]=*g1;
		b->mass[2][1][0]=*g;
		flag_LR=0;
		}
		
		if (flag_BL==1){
		*g=b->mass[2][0][2];
		b->mass[2][0][2]=b->mass[2][2][2];
		*g1=b->mass[2][0][0];
		b->mass[2][0][0]=*g;
		*g=b->mass[2][2][0];
		b->mass[2][2][0]=*g1;
		b->mass[2][2][2]=*g;
		
		*g=b->mass[2][0][1];
		b->mass[2][0][1]=b->mass[2][1][2];
		*g1=b->mass[2][1][0];
		b->mass[2][1][0]=*g;
		*g=b->mass[2][2][1];
		b->mass[2][2][1]=*g1;
		b->mass[2][1][2]=*g;
		flag_BL=0;
		}
		
		if (flag_BR==1){
		*g=b->mass[2][0][0];
		b->mass[2][0][0]=b->mass[2][2][0];
		*g1=b->mass[2][0][2];
		b->mass[2][0][2]=*g;
		*g=b->mass[2][2][2];
		b->mass[2][2][2]=*g1;
		b->mass[2][2][0]=*g;
		
		*g=b->mass[2][0][1];
		b->mass[2][0][1]=b->mass[2][1][0];
		*g1=b->mass[2][1][2];
		b->mass[2][1][2]=*g;
		*g=b->mass[2][2][1];
		b->mass[2][2][1]=*g1;
		b->mass[2][1][0]=*g;
		flag_BR=0;
		}
		
		if (flag_RL==1){
		*g=b->mass[0][0][2];
		b->mass[0][0][2]=b->mass[2][0][2];
		*g1=b->mass[0][2][2];
		b->mass[0][2][2]=*g;
		*g=b->mass[2][2][2];
		b->mass[2][2][2]=*g1;
		b->mass[2][0][2]=*g;
		
		*g=b->mass[1][0][2];
		b->mass[1][0][2]=b->mass[2][1][2];
		*g1=b->mass[0][1][2];
		b->mass[0][1][2]=*g;
		*g=b->mass[1][2][2];
		b->mass[1][2][2]=*g1;
		b->mass[2][1][2]=*g;
		flag_RL=0;
		}
		
		if (flag_RR==1){
		*g=b->mass[0][0][2];
		b->mass[0][0][2]=b->mass[0][2][2];
		*g1=b->mass[2][0][2];
		b->mass[2][0][2]=*g;
		*g=b->mass[2][2][2];
		b->mass[2][2][2]=*g1;
		b->mass[0][2][2]=*g;
		
		*g=b->mass[1][0][2];
		b->mass[1][0][2]=b->mass[0][1][2];
		*g1=b->mass[2][1][2];
		b->mass[2][1][2]=*g;
		*g=b->mass[1][2][2];
		b->mass[1][2][2]=*g1;
		b->mass[0][1][2]=*g;
		flag_RR=0;
		}
		
		if (flag_UL==1){
		*g=b->mass[0][0][2];
		b->mass[0][0][2]=b->mass[2][0][2];
		*g1=b->mass[0][0][0];
		b->mass[0][0][0]=*g;
		*g=b->mass[2][0][0];
		b->mass[2][0][0]=*g1;
		b->mass[2][0][2]=*g;
		
		*g=b->mass[2][0][1];
		b->mass[2][0][1]=b->mass[1][0][0];
		*g1=b->mass[1][0][2];
		b->mass[1][0][2]=*g;
		*g=b->mass[0][0][1];
		b->mass[0][0][1]=*g1;
		b->mass[1][0][0]=*g;
		flag_UL=0;
		}
		
		if (flag_UR==1){
		*g=b->mass[0][0][2];
		b->mass[0][0][2]=b->mass[0][0][0];
		*g1=b->mass[2][0][2];
		b->mass[2][0][2]=*g;
		*g=b->mass[2][0][0];
		b->mass[2][0][0]=*g1;
		b->mass[0][0][0]=*g;
		
		*g=b->mass[2][0][1];
		b->mass[2][0][1]=b->mass[1][0][2];
		*g1=b->mass[1][0][0];
		b->mass[1][0][0]=*g;
		*g=b->mass[0][0][1];
		b->mass[0][0][1]=*g1;
		b->mass[1][0][2]=*g;
		flag_UR=0;
		}
		
		if (flag_DL==1){
		*g=b->mass[0][2][0];
		b->mass[0][2][0]=b->mass[0][2][2];
		*g1=b->mass[2][2][0];
		b->mass[2][2][0]=*g;
		*g=b->mass[2][2][2];
		b->mass[2][2][2]=*g1;
		b->mass[0][2][2]=*g;
		
		*g=b->mass[0][2][1];
		b->mass[0][2][1]=b->mass[1][2][2];
		*g1=b->mass[1][2][0];
		b->mass[1][2][0]=*g;
		*g=b->mass[2][2][1];
		b->mass[2][2][1]=*g1;
		b->mass[1][2][2]=*g;
		flag_DL=0;
		}
		
		if (flag_DR==1){
		*g=b->mass[0][2][0];
		b->mass[0][2][0]=b->mass[2][2][0];
		*g1=b->mass[0][2][2];
		b->mass[0][2][2]=*g;
		*g=b->mass[2][2][2];
		b->mass[2][2][2]=*g1;
		b->mass[2][2][0]=*g;
		
		*g=b->mass[0][2][1];
		b->mass[0][2][1]=b->mass[1][2][0];
		*g1=b->mass[1][2][2];
		b->mass[1][2][2]=*g;
		*g=b->mass[2][2][1];
		b->mass[2][2][1]=*g1;
		b->mass[1][2][0]=*g;
		flag_DR=0;
		}
	flag_alter=0;
	}
//printf("%0.0f\n",angle);
}

void glfw_main_loop(GLFWwindow *w)
{
	while( done ) {
		if( glfwWindowShouldClose(w) ) {
					done = 0;
		}
		glfwPollEvents();
		if (flag_SND==0) {
			if (BASS_ChannelIsActive(ch01)!=BASS_ACTIVE_PAUSED)
				BASS_ChannelPause(ch01);
			}
		else {
			if (BASS_ChannelIsActive(ch01)==BASS_ACTIVE_PAUSED)
				BASS_ChannelPlay(ch01, FALSE);
		}
		
		ogl_draw();
		if(fps_enable)
			frame+=1.0;
		fps_counter(w,F_TIME);
		animation(&g,&g1,&b);
		glfwSwapBuffers(w);
	}
	prog_exit(w);
}

int main(int argc, char **argv)
{
	argc_init(argc,argv);

	w_handle=glfw_window_init(W_WIDTH,W_HEIGHT,W_CAPTION,w_mode);
	glfw_window_set_params(w_handle,W_CAPTION,SWAP_INT);
	//sound system
	BASS_Init(-1, 44100, 0, 0, NULL);
	sam01=BASS_SampleLoad(FALSE, sndrs,0,0,2 , BASS_SAMPLE_LOOP);
	ch01=BASS_SampleGetChannel(sam01, FALSE );
	if (flag_SND==1)
		BASS_ChannelPlay(ch01, FALSE);
	
	glew_init();
	ogl_init();
	ogl_print_info(gl_info);
	//help_printf_info(help_info);
	glfw_print_info(glfw_info);
	glfw_callback_init(w_handle);
	glfw_main_loop(w_handle);
	return 0;
}

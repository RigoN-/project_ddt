#include "lab_win.h"

//Функция инициализации обработки функций обратного вызова
void glfw_callback_init(GLFWwindow *w)
{
	glfwSetFramebufferSizeCallback(w,ogl_reshape);
	glfwSetKeyCallback(w,key_press);
	glfwSetCharCallback(w,char_input);
	glfwSetMouseButtonCallback(w,mouse_button_press);
	glfwSetCursorPosCallback(w,mouse_pos);
	glfwSetScrollCallback(w,mouse_wheel);
}
//Функция инициализации предварительных параметров окна
void glfw_context_init()
{
	glfwWindowHint(GLFW_CLIENT_API,GLFW_OPENGL_API);
	//params
	//GLFW_SAMPLES,GLFW_OPENGL_DEBUG_CONTEXT,GLFW_OPENGL_FORWARD_COMPAT, GLFW_WINDOW_NO_RESIZE
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
	//GLFW_OPENGL_ANY_PROFILE,GLFW_OPENGL_COMPAT_PROFILE,GLFW_OPENGL_CORE_PROFILE
	
glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_COMPAT_PROFILE);
}

void glfw_window_init_params(GLFWwindow *w)
{
	glfw_context_init();
}

GLFWwindow *glfw_window_init(int width, int height, char *caption, int w_mode)
{
	GLFWwindow *temp_handle=NULL;
	const GLFWvidmode *video_mode=NULL;
	GLFWmonitor *primary_monitor=NULL;
	if(!glfwInit()){
		fprintf( stderr, "Failed to initialize GLFW\n");
		exit( EXIT_FAILURE );
	}
//temp_handle=glfwCreateWindow(W_WIDTH,W_HEIGHT,W_CAPTION,NULL,NULL);
	if(w_mode==0){
		temp_handle=glfwCreateWindow(width,height,caption,NULL,NULL);
		}
		else
		{
		primary_monitor=glfwGetPrimaryMonitor();
		video_mode=glfwGetVideoMode(primary_monitor);
		temp_handle=glfwCreateWindow(video_mode->width,video_mode->height,caption,primary_monitor,NULL);
	}
	if(temp_handle){
		glfw_window_init_params(temp_handle);
		glfwMakeContextCurrent(temp_handle);
		return	temp_handle;
	}
	else{
		fprintf( stderr, "Failed to open GLFW window\n");
		glfwTerminate();
		exit( EXIT_FAILURE );
	}
}

void glfw_window_set_params(GLFWwindow *w, char *caption, int swap_int)
{
	glfwSetWindowTitle(w,caption);
	glfwSetWindowPos(w,200, 100);
	glfwSwapInterval( swap_int );//интервал обновления экранного буфера
	glfwSetInputMode(w,GLFW_CURSOR,GLFW_CURSOR_NORMAL);
}
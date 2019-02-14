#include "lab_info.h"

//Функция информации о версии GLFW
void glfw_print_info(int glfw_info)
{
	int glfw_major,glfw_minor,glfw_rev;
	if (glfw_info){
		glfwGetVersion(&glfw_major,&glfw_minor,&glfw_rev);
		printf("GLFW version %i.%i.%i\n",glfw_major,glfw_minor,glfw_rev);
		exit ( EXIT_FAILURE );
		}
}
//Функция информации о версии OpenGL
void ogl_print_info(int gl_info)
{
	if(gl_info){
	printf("%s\n",glGetString(GL_VENDOR));
	printf("%s\n",glGetString(GL_RENDERER));
	printf("%s\n",glGetString(GL_VERSION));
	exit ( EXIT_FAILURE );
	}
}
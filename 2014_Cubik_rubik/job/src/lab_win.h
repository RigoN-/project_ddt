#ifndef _LAB_WIN_H
#define _LAB_WIN_H
#include "lab_common.h"
#include "lab_callback.h"

void glfw_callback_init(GLFWwindow *w);
void glfw_context_init();
void glfw_window_init_params(GLFWwindow *w);
GLFWwindow *glfw_window_init(int width, int height, char *caption, int w_mode);
void glfw_window_set_params(GLFWwindow *w, char *caption, int swap_int);
#endif
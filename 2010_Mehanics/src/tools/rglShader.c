#include <GL/glew.h>

#include "rglShader.h"


char *rglFileToString(const char *path)
{
	FILE *fd;
	long len, r;
	char *str;
 
	if (!(fd = fopen(path, "r")))
	{
		fprintf(stderr, "Can't open file '%s' for reading\n", path);
		return NULL;
	}
 
	fseek(fd, 0, SEEK_END);
	len = ftell(fd);
 
	printf("File '%s' is %ld long\n", path, len);
 
	fseek(fd, 0, SEEK_SET);
 
	if (!(str = malloc(len * sizeof(char))))
	{
		fprintf(stderr, "Can't malloc space for '%s'\n", path);
		return NULL;
	}
 
	r = fread(str, sizeof(char), len, fd);
 
	str[r - 1] = '\0'; /* Shader sources have to term with null */
 
	fclose(fd);
 
	return str;
}

void rglPrintShaderInfoLog(const char *coment, GLuint *obj)
	{
	    GLint infologLength = 0;
	    char *infoLog;

		glGetShaderiv(*obj, GL_INFO_LOG_LENGTH,&infologLength);

	    if (infologLength > 0)
	    {
	        infoLog = (char *)malloc(infologLength);
	        glGetShaderInfoLog(*obj, infologLength, NULL, infoLog);
			printf("%s : %s\n",coment,infoLog);
	        free(infoLog);
	    }
	}

	void  rglPrintProgramInfoLog(const char *coment,GLuint *obj)
	{
	    GLint infologLength = 0;
	    char *infoLog;

		glGetProgramiv(*obj, GL_INFO_LOG_LENGTH,&infologLength);

	    if (infologLength > 0)
	    {
	        infoLog = (char *)malloc(infologLength);
	        glGetProgramInfoLog(*obj, infologLength, NULL, infoLog);
			printf("%s : %s\n",coment, infoLog);
	        free(infoLog);
	    }
	}

GLuint rglInitVertexShader(const char *ShaderFile)
{
	const char *vsSource;
	GLuint vert;
	GLint result;
	vsSource = rglFileToString(ShaderFile);
	vert = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vert, 1, &vsSource, NULL);
	glCompileShader(vert);
	glGetShaderiv (vert, GL_COMPILE_STATUS, &result);
	if (GL_FALSE == result)
		{
			printf ("Compilation Vertex Shader: FAILED\n");
			rglPrintShaderInfoLog("Vertex Shader log",&vert);
		}
	else
		{
			printf ("Compilation Vertex Shader: SUCCESSFUL\n");			
		}
	
	return vert;
	free(&vert);
}

GLuint rglInitFragmentShader(const char *ShaderFile)
 {
	const char *fsSource;
	GLuint frag;
	GLint result;
	fsSource = rglFileToString(ShaderFile);
	frag = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(frag, 1, &fsSource, NULL);
	glCompileShader(frag);
	glGetShaderiv (frag, GL_COMPILE_STATUS, &result);
	if (GL_FALSE == result)
		{
			printf ("Compilation Fragment Shader: FAILED\n");
			rglPrintShaderInfoLog("Fragment Shader log",&frag);
		}
	else
		{
			printf ("Compilation Fragment Shader: SUCCESSFUL\n");			
		}	
	return frag;
	free(&fsSource);
	free(&frag);
 }
 
GLuint rglInitProgramShader(GLuint *vert,GLuint *geom, GLuint *frag)
{
	GLuint prog;
	GLint result;
	
	prog= glCreateProgram();
	
	if (vert != NULL)
		glAttachShader(prog, *vert);
	if (geom != NULL)
		glAttachShader(prog, *geom);
	if (frag != NULL)
		glAttachShader(prog, *frag);	
		
	glLinkProgram(prog);
	glGetProgramiv (prog, GL_LINK_STATUS, &result);
	if (GL_FALSE == result)
		{
			printf ("Link Shader Program: FAILED\n");
			rglPrintProgramInfoLog("Shader program log",&prog);
		}
	else
		{
			printf ("Link Shader Program:  SUCCESSFUL\n");			
		}	

	
	return prog;
	free(&prog);

	if (vert != NULL)
		glDeleteShader(*vert);
	if (geom != NULL)
		glDeleteShader(*geom);
	if (frag != NULL)
		glDeleteShader(*frag);
	
}

GLboolean rglPushUniformf(GLuint *prog,const char *Name, GLfloat *arg)
{
	GLint count= sizeof(arg)/sizeof(GLfloat);
	switch (count  )
		{	
			case 0:
				printf("Don't uniform %s arguments", Name);
				return GL_FALSE;
			break;
			case 1:
				glUniform1fv(glGetUniformLocation(*prog,Name), count,arg);
			break;
			case 2:
				glUniform2fv(glGetUniformLocation(*prog,Name), count, arg);
			break;
			case 3:
				glUniform3fv(glGetUniformLocation(*prog,Name), count, arg);
			break;
			case 4:
				glUniform4fv(glGetUniformLocation(*prog,Name), count, arg);
			break;
			default:
				printf("Error push uniform %s arguments", Name);
				return GL_FALSE;
			break;
		}
	return GL_TRUE;
}

GLboolean rglPushUniformi(GLuint *prog,const char *Name, GLint *arg)
{
	GLint count= sizeof(arg)/sizeof(GLint);
	switch (count  )
		{	
			case 0:
				printf("Don't uniform %s arguments\n", Name);
				return GL_FALSE;
			break;
			case 1:
				glUniform1iv(glGetUniformLocation(*prog,Name), count,arg);
			break;
			case 2:
				glUniform2iv(glGetUniformLocation(*prog,Name), count, arg);
			break;
			case 3:
				glUniform3iv(glGetUniformLocation(*prog,Name), count, arg);
			break;
			case 4:
				glUniform4iv(glGetUniformLocation(*prog,Name), count, arg);
			break;
			default:
				printf("Error push uniform %s arguments\n", Name);
				return GL_FALSE;
			break;
		}
	return GL_TRUE;
}

GLboolean rglPushUniformMatrix(GLuint *prog,const char *Name,GLfloat *arg)
{
	GLint count= sizeof(arg)/sizeof(GLfloat);
	switch (count  )
		{	
			case 0:
				printf("Don't uniform %s arguments\n", Name);
				return GL_FALSE;
			break;
			case 4:
				glUniformMatrix2fv(glGetUniformLocation(*prog,Name), count,GL_FALSE,arg);
			break;
			case 9:
				glUniformMatrix3fv(glGetUniformLocation(*prog,Name), count,GL_FALSE,arg);
			break;
			case 16:
				glUniformMatrix4fv(glGetUniformLocation(*prog,Name), count,GL_FALSE,arg);
			break;			
			default:
				printf("Error push uniform %s arguments\n", Name);
				return GL_FALSE;
			break;
		}
	return GL_TRUE;
}

 void rglPushTexture(GLuint texture, GLuint shader, GLuint texture_module, const char *sampler_name)
 {
	
	if (shader == 0)
		{
			glActiveTexture(GL_TEXTURE0+texture_module);
			glBindTexture(GL_TEXTURE_2D, texture);
		}
		else
		{
			glActiveTexture(GL_TEXTURE0+texture_module);
			glBindTexture(GL_TEXTURE_2D,texture);
			glUniform1i(glGetUniformLocation(shader,sampler_name), texture_module);
		}

}

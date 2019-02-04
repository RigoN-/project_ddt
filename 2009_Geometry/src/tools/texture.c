#include "texture.h"



/////////////////////////////////////////////////////////////////////////////////////////////////
//										TEXTURE LOADER
/////////////////////////////////////////////////////////////////////////////////////////////////
GLboolean LoadTextures(char *filename,GLuint *texti)
{   
     textureImage *image;
     GLint color_type = GL_RGB;
      image=(textureImage *) malloc(sizeof(textureImage));
	if(!filename)  return GL_FALSE;
	if(strstr(filename, ".jpg") || strstr(filename, ".JPG")) 
	{    
	//	textureType = GL_RGBA;
	//	LoadJPG(filename,image);
	}
	// Load TGA Image
	else if(strstr(filename, ".tga") || strstr(filename, ".TGA"))
	{
	//	textureType = GL_RGBA;
		LoadTGA(filename,image);
	}
	// Load BMP Image
	else if(strstr(filename, ".bmp") || strstr(filename, ".BMP"))
	{
	//	textureType = GL_RGB;
		LoadBMP(filename,image);
	}
	else	return GL_FALSE;
	
	if (image-> imgChanal == 3) color_type = GL_RGB;
	if (image-> imgChanal == 4) color_type = GL_RGBA;
	
     printf(" imgChanal of %s: %d\n", filename,image-> imgChanal); 
	 glGenTextures(1, texti);  
   	 glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	 glBindTexture(GL_TEXTURE_2D, *texti);   
		
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT) ;   
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_LINEAR);
		gluBuild2DMipmaps ( GL_TEXTURE_2D,color_type, image->width, image->height, color_type, GL_UNSIGNED_BYTE, image->data );
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);	
		free(image->data); 
		free(image); 
  	return GL_TRUE;
}

GLboolean OGL_Load_Texture(char *filename, GLuint *texti, GLuint txFilter, GLuint txMode, GLuint txPlace, GLuint txCompress, GLboolean txMip_map)
{   
     textureImage *image;
     GLint color_type = GL_RGB;
     GLfloat anis_level;
     GLint filter_tx;
     filter_tx= txFilter;
    // printf(" filter_tx : %d\n", filter_tx ); 
      image= (textureImage *)malloc(sizeof(textureImage));
	if(!filename)  return GL_FALSE;
	if(strstr(filename, ".jpg") || strstr(filename, ".JPG")) 
	{    
	//	textureType = GL_RGBA;
	//	LoadJPG(filename,image);
	}
	// Load TGA Image
	else if(strstr(filename, ".tga") || strstr(filename, ".TGA"))
	{
	//	textureType = GL_RGBA;
		LoadTGA(filename,image);
	}
	// Load BMP Image
	else if(strstr(filename, ".bmp") || strstr(filename, ".BMP"))
	{
		LoadBMP(filename,image);
	}
	else	return GL_FALSE;
	//	textureType = GL_RGB;
	if (image-> imgChanal == 3) color_type = GL_RGB;
	if (image-> imgChanal == 4) color_type = GL_RGBA;
      
	 glGenTextures(1, texti);  
   	 glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	 glBindTexture(GL_TEXTURE_2D, *texti);  
	  
	  glGetFloatv(GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT, &anis_level);	
	 // printf(" ANISOTROPY: %f\n", anis_level); 
	  if (anis_level < 2.0)
	  { 
	  	filter_tx = txTrilinear;
  		}
	  if  (( filter_tx == txAnisotropic_02) || ( filter_tx == txAnisotropic_04) || ( filter_tx == txAnisotropic_08) || ( filter_tx == txAnisotropic_16)) 
	  		if ( filter_tx >  anis_level )
	  			 filter_tx=  anis_level;
	  if (txMip_map == GL_FALSE) 
		   switch (   filter_tx )
				{	
				case txTrilinear:
					  filter_tx=txBilinear;
				break;
				case txAnisotropic_02:
					  filter_tx=txBilinear;
				break;
				case txAnisotropic_04:
					  filter_tx=txBilinear;
				break;
				case txAnisotropic_08:
					  filter_tx=txBilinear;
				break;
				case txAnisotropic_16:
					 filter_tx=txBilinear;
				break;
				}
	 // printf(" filter_tx : %d\n", filter_tx ); 			
	  switch (   filter_tx  )
		{	
		case  txNoFilter:
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		break;
		case txBilinear:
				if  (txMip_map == GL_TRUE) 
					{
						glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
						glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
					}
				else
					{
						glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
						glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
					}				
		break;
		case txTrilinear:
		  	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		break;
		case txAnisotropic_02:
		 	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_LINEAR);
			glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, 2.0);
		break;
		case txAnisotropic_04:
		 	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_LINEAR);
			glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, 4.0);
		break;
		case txAnisotropic_08:
		 	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_LINEAR);
			glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, 8.0);
		break;
		case txAnisotropic_16:
		 	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_LINEAR);
			glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, 16.0);
		break;		
		default:
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		break;
		}
	
	    switch ( txMode  )
		{	
			case  GL_REPLACE:
				glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
			break;
			case GL_BLEND:
				glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_BLEND);
			break;
			case GL_DECAL:
				glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
			break;
			case GL_MODULATE:
				glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE); 
			break;
			default:
				glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
			break;
		}
	  
	   switch ( txMode  )
		{	
			case   GL_REPEAT:
				glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	    		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT) ;	
			break;
			case GL_CLAMP_TO_EDGE:
				glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	    		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE) ;	
			break;
			case GL_CLAMP:
				glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	    		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP) ;
			break;			
			default:
				glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	    		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT) ;
			break;
		}
	  
	     if (txMip_map == GL_TRUE) 
	     	gluBuild2DMipmaps ( GL_TEXTURE_2D, color_type,  image->width, image->height,  color_type, GL_UNSIGNED_BYTE,  image->data );
		else
			glTexImage2D(GL_TEXTURE_2D, 0, color_type,  image->width, image->height, 0,  color_type, GL_UNSIGNED_BYTE, image->data);
		
      
		free(image->data); 
		free(image); 
		printf("Texture %s load OK\n",filename);
  	return GL_TRUE;
}

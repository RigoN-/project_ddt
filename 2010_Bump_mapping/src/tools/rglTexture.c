#include "rglTexture.h"



/////////////////////////////////////////////////////////////////////////////////////////////////
//										TEXTURE LOADER
/////////////////////////////////////////////////////////////////////////////////////////////////
GLboolean rglLoadTextures(char *filename,GLuint *texti)
{   
     RGL_TextureImage *image;
     GLint color_type = GL_RGB;
      image=(RGL_TextureImage *) malloc(sizeof(RGL_TextureImage));
	if(!filename)  return GL_FALSE;
	if(strstr(filename, ".jpg") || strstr(filename, ".JPG")) 
	{    
	//	textureType = GL_RGBA;
		rglLoadJPG(filename,image);
	}
	// Load TGA Image
	else if(strstr(filename, ".tga") || strstr(filename, ".TGA"))
	{
	//	textureType = GL_RGBA;
		rglLoadTGA(filename,image);
	}
	// Load BMP Image
	else if(strstr(filename, ".bmp") || strstr(filename, ".BMP"))
	{
	//	textureType = GL_RGB;
		rglLoadBMP(filename,image);
	}
	else	return GL_FALSE;
	
	if (image-> imgChanal == 3) color_type = GL_BGR;
	if (image-> imgChanal == 4) color_type = GL_BGRA;
	
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

GLboolean rglLoad_Texture(char *filename, GLuint *texti, GLuint txFilter, GLuint txMode, GLuint txPlace, GLuint txCompress, GLboolean txMip_map)
{   
    RGL_TextureImage *image;
     GLint color_type_in = GL_RGB;
     GLint color_type_pixels = GL_BGR;
     GLfloat anis_level;
     GLint filter_tx;
     GLfloat compress_size;
     filter_tx= txFilter;
  
      image= (RGL_TextureImage *)malloc(sizeof(RGL_TextureImage));
	if(!filename)  return GL_FALSE;
	if(strstr(filename, ".jpg") || strstr(filename, ".JPG")) 
	{    
	//	textureType = GL_RGBA;
		rglLoadJPG(filename,image);
		if (image-> imgChanal == 3) color_type_in = GL_RGB;
		if (image-> imgChanal == 4) color_type_in = GL_RGBA;
		if (image-> imgChanal == 3) color_type_pixels = GL_RGB;
		if (image-> imgChanal == 4) color_type_pixels = GL_RGBA;
	}
	// Load TGA Image
	else if(strstr(filename, ".tga") || strstr(filename, ".TGA"))
	{
	//	textureType = GL_RGBA;
		rglLoadTGA(filename,image);
		if (image-> imgChanal == 3) color_type_in = GL_RGB;
		if (image-> imgChanal == 4) color_type_in = GL_RGBA;
		if (image-> imgChanal == 3) color_type_pixels = GL_BGR;
		if (image-> imgChanal == 4) color_type_pixels = GL_BGRA;
	}
	// Load BMP Image
	else if(strstr(filename, ".bmp") || strstr(filename, ".BMP"))
	{
		rglLoadBMP(filename,image);
		if (image-> imgChanal == 3) color_type_in = GL_RGB;
		if (image-> imgChanal == 4) color_type_in = GL_RGBA;
		if (image-> imgChanal == 3) color_type_pixels = GL_BGR;
		if (image-> imgChanal == 4) color_type_pixels = GL_BGRA;		
	}
	else	return GL_FALSE;
	//	textureType = GL_RGB;

#define txGL_COMPRESS 4
	if (txCompress>0)
	{
		  switch (txCompress  )
		{	
			case  txS3TC_DXT1:
				if (image-> imgChanal == 3) color_type_in = GL_COMPRESSED_RGB_S3TC_DXT1_EXT;
				if (image-> imgChanal == 4) color_type_in = GL_COMPRESSED_RGBA_S3TC_DXT1_EXT;
			break;
			case txS3TC_DXT3:
				if (image-> imgChanal == 3) color_type_in = GL_COMPRESSED_RGBA_S3TC_DXT3_EXT;
				if (image-> imgChanal == 4) color_type_in = GL_COMPRESSED_RGBA_S3TC_DXT3_EXT;
			break;
			case txS3TC_DXT5:
				if (image-> imgChanal == 3) color_type_in = GL_COMPRESSED_RGBA_S3TC_DXT5_EXT;
				if (image-> imgChanal == 4) color_type_in = GL_COMPRESSED_RGBA_S3TC_DXT5_EXT;
			break;
			case txGL_COMPRESS:
				if (image-> imgChanal == 3) color_type_in = GL_COMPRESSED_RGB;
				if (image-> imgChanal == 4) color_type_in = GL_COMPRESSED_RGBA;
			break;
			default:
				if (image-> imgChanal == 3) color_type_in = GL_COMPRESSED_RGB;
				if (image-> imgChanal == 4) color_type_in = GL_COMPRESSED_RGBA;
			break;
		}
	}
      
	 glGenTextures(1, texti);  
   	 glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
	 glBindTexture(GL_TEXTURE_2D, *texti);  
	  
	  glGetFloatv(GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT, &anis_level);	
	
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
	  
	   switch ( txPlace  )
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
	     {
	     		glTexParameteri(GL_TEXTURE_2D,GL_GENERATE_MIPMAP, GL_TRUE);
	    // 		gluBuild2DMipmaps ( GL_TEXTURE_2D, color_type_in,  image->width, image->height,  color_type_pixels, GL_UNSIGNED_BYTE,   image->data );
				glTexImage2D(GL_TEXTURE_2D, 0, color_type_in,  image->width, image->height, 0,  color_type_pixels, GL_UNSIGNED_BYTE, image->data);
		}
		else
			glTexImage2D(GL_TEXTURE_2D, 0, color_type_in,  image->width, image->height, 0,  color_type_pixels, GL_UNSIGNED_BYTE, image->data);
		
		glGetTexLevelParameterfv(GL_TEXTURE_2D, 0,GL_TEXTURE_COMPRESSED_IMAGE_SIZE, &compress_size);
		
		if (compress_size <=1024 )
		{
			printf("Texture compressed size %8.2f  byte \n", compress_size );
			printf("Image size %d  byte \n", image->width*image->height*image-> imgChanal );
		}
		else
		{
			printf("Texture compressed size %8.2f  Kb \n", compress_size/1024 );
			printf("Image size %d  Kb \n", image->width*image->height*image-> imgChanal/1024 );
		}
		printf("Texture load OK!!! \n" );
		free(image->data); 
		free(image); 
  	return GL_TRUE;
}


GLboolean rglLoad_Texture_SDL(char *filename, GLuint *texti, GLuint txFilter, GLuint txMode, GLuint txPlace, GLuint txCompress, GLboolean txMip_map)
{   
     RGL_TextureImage *image;
     GLint color_type_in = GL_RGB;
     GLint color_type_pixels = GL_BGR;
     GLfloat anis_level;
     GLint filter_tx;
     GLfloat compress_size;
     filter_tx= txFilter; 
  
      image= (RGL_TextureImage *)malloc(sizeof(RGL_TextureImage));
	if(!filename)  return GL_FALSE;
	rglLoadImageSDL(filename,image);
		
		if (image-> imgChanal == 3) color_type_in = GL_RGB;
		if (image-> imgChanal == 4) color_type_in = GL_RGBA;
		if (image-> imgChanal == 3) color_type_pixels = GL_BGR;
		if (image-> imgChanal == 4) color_type_pixels = GL_BGRA;
			
	//	textureType = GL_RGB;
	
	if (txCompress>0)
	{
		  switch (txCompress  )
		{	
			case  txS3TC_DXT1:
				if (image-> imgChanal == 3) color_type_in = GL_COMPRESSED_RGB_S3TC_DXT1_EXT;
				if (image-> imgChanal == 4) color_type_in = GL_COMPRESSED_RGBA_S3TC_DXT1_EXT;
			break;
			case txS3TC_DXT3:
				if (image-> imgChanal == 3) color_type_in = GL_COMPRESSED_RGBA_S3TC_DXT3_EXT;
				if (image-> imgChanal == 4) color_type_in = GL_COMPRESSED_RGBA_S3TC_DXT3_EXT;
			break;
			case txS3TC_DXT5:
				if (image-> imgChanal == 3) color_type_in = GL_COMPRESSED_RGBA_S3TC_DXT5_EXT;
				if (image-> imgChanal == 4) color_type_in = GL_COMPRESSED_RGBA_S3TC_DXT5_EXT;
			break;
			case txGL_COMPRESS:
				if (image-> imgChanal == 3) color_type_in = GL_COMPRESSED_RGB;
				if (image-> imgChanal == 4) color_type_in = GL_COMPRESSED_RGBA;
			break;
			default:
				if (image-> imgChanal == 3) color_type_in = GL_COMPRESSED_RGB;
				if (image-> imgChanal == 4) color_type_in = GL_COMPRESSED_RGBA;
			break;
		}
	}
      
	 glGenTextures(1, texti);  
   	 glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
	 glBindTexture(GL_TEXTURE_2D, *texti);  
	 
	  glGetFloatv(GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT, &anis_level);	
	
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
	  
	   switch ( txPlace  )
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
	     {
	   		glTexParameteri(GL_TEXTURE_2D,GL_GENERATE_MIPMAP, GL_TRUE);
	    // 		gluBuild2DMipmaps ( GL_TEXTURE_2D, color_type_in,  image->width, image->height,  color_type_pixels, GL_UNSIGNED_BYTE,   image->data );
			glTexImage2D(GL_TEXTURE_2D, 0, color_type_in,  image->width, image->height, 0,  color_type_pixels, GL_UNSIGNED_BYTE, image->data);
		}
		else
			glTexImage2D(GL_TEXTURE_2D, 0, color_type_in,  image->width, image->height, 0,  color_type_pixels, GL_UNSIGNED_BYTE, image->data);
		
			glGetTexLevelParameterfv(GL_TEXTURE_2D, 0,GL_TEXTURE_COMPRESSED_IMAGE_SIZE, &compress_size);
		
		if (compress_size <=1024 )
		{
			printf("Texture compressed size %8.2f  byte \n", compress_size );
			printf("Image size %d  byte \n", image->width*image->height*image-> imgChanal );
		}
		else
		{
			printf("Texture compressed size %8.2f  Kb \n", compress_size/1024 );
			printf("Image size %d  Kb \n", image->width*image->height*image-> imgChanal/1024 );
		}
		printf("Texture load OK!!! \n" );
		free(image->data); 
		free(image); 
  	return GL_TRUE;
}

GLboolean rglCreateTexture(GLint tx_iner_format, GLint tx_width, GLint tx_heght, GLuint *texti, GLuint txFilter, GLuint txMode, GLuint txPlace, GLuint txCompress, GLboolean txMip_map)
{   
	 GLint color_type = GL_RGB;
	 GLfloat anis_level;
	 GLint filter_tx;
   	unsigned char *pdata=NULL;
   
      color_type = tx_iner_format;
	  if (color_type == GL_RGBA)
      pdata = (unsigned char *) malloc(tx_width*tx_heght*4);
      if (color_type == GL_RGB)
      pdata = (unsigned char *) malloc(tx_width*tx_heght*3);
	 glGenTextures(1, texti);  
   	 glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	 glBindTexture(GL_TEXTURE_2D, *texti);  
	  
	  glGetFloatv(GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT, &anis_level);	
	  printf(" ANISOTROPY: %f\n", anis_level); 
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
	  printf(" filter_tx : %d\n", filter_tx ); 			
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
	  
	   switch ( txPlace  )
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
	     	{
	     	glTexParameteri(GL_TEXTURE_2D,GL_GENERATE_MIPMAP, GL_TRUE);
	    // 		gluBuild2DMipmaps ( GL_TEXTURE_2D, color_type_in,  image->width, image->height,  color_type_pixels, GL_UNSIGNED_BYTE,   image->data );
			glTexImage2D(GL_TEXTURE_2D, 0, color_type,  tx_width, tx_heght, 0,  color_type, GL_UNSIGNED_BYTE, pdata);
		}
		else
			glTexImage2D(GL_TEXTURE_2D, 0, color_type,  tx_width, tx_heght, 0,  color_type, GL_UNSIGNED_BYTE, pdata);
		

		free(pdata); 
		
  	return GL_TRUE;
}

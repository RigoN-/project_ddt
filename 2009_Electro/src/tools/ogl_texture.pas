unit ogl_texture; {процедуры загрузки текстуры}

{$R-}
{$MODE DELPHI}
interface
uses sysutils,classes,gl,  glu,glext,lib_image; 

const
// image type
IMG_BMP=1;
IMG_TGA=2;
IMG_JPEG=3;
// texture filter type
txNoFilter=0;
txBilinear=1;
txTrilinear=3;
txAnisotropic_02=2;
txAnisotropic_04=4;
txAnisotropic_08=8;
txAnisotropic_16=16;
// texture compressed type
txNoCompressed=0;

procedure OGL_Load_Texture(Filename: String; var texti:GLuint;txFilter,txMode,txPlace,txCompress:GLUint;txMip_map:GLBoolean);cdecl;
//Filename - имя файла
//texti - openg текстура
//txFilter - фильтрация (txNoFilter, txBilinear, txTrilinear, txAnisotropic_02, txAnisotropic_04, txAnisotropic_08, txAnisotropic_16)
// txMode режим наложения (GL_REPLACE, GL_BLEND,  GL_DECAL,  GL_MODULATE)
//txPlace способ наложения (GL_REPEAT,GL_CLAMP_TO_EDGE, GL_CLAMP)
//txCompress - способ сжатия текстур (txNoCompressed)
//txMip_map - мипмапинг включение и выключение (GL_TRUE, GL_FALSE)
procedure OGL_Create_Texture(file_type, width, height:GLUint; texti: PGLUInt;txFilter,txMode,txPlace,txCompress:GLUint;txMip_map:GLBoolean);cdecl;
//txMip_map - формат текстуры (GL_RGB, GL_RGBA)
procedure CreateRenderTexture_2(width, height:GLUint;  texti: PGLUInt);cdecl;


implementation

procedure OGL_Load_Texture(Filename: String; var texti:GLuint;txFilter,txMode,txPlace,txCompress:GLUint;txMip_map:GLBoolean);cdecl;
var
img:image_type;
temp,file_ext:string;
file_type:GLInt;
anis_level:GLfloat;
begin
	    img.image_data:=nil;     
	    temp:=UpperCase(Filename);
	    file_ext:=ExtractFileExt( temp);
	    if  file_ext='.BMP' then
	    	img:=LoadBMP(Filename);	
	    if  file_ext='.TGA' then
	    	img:=LoadTGA(Filename);
	    if  file_ext='.JPG' then
	    	img:=LoadJPG(Filename);
	    if  file_ext='.JPEG' then
	    	img:=LoadJPG(Filename);
		glGenTextures(1, @texti);
		glBindTexture(GL_TEXTURE_2D, texti);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		if img.imgChanal = 3 then
			file_type:=GL_RGB;
		if img.imgChanal = 4 then
			file_type:=GL_RGBA;
			
	glGetFloatv(GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT, @anis_level);	
	if anis_level < 2 then
		txFilter:=txTrilinear;
	if  (txFilter = txAnisotropic_02) or (txFilter = txAnisotropic_04) or (txFilter = txAnisotropic_08) or (txFilter = txAnisotropic_16) then
		begin
			if txFilter > anis_level then
				txfilter:=trunc(anis_level);
		end;	
		
	  case txFilter of 
	  txNoFilter:
	  		begin
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	  		end;
	  txBilinear:
			begin
			   if txMip_map = GL_TRUE then
			   		begin
						glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
						glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
			   		end
			   	else
			   		begin
			   			glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
						glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
			   		end;
	  		end;
	  txTrilinear:
	  		begin
	  			glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
				glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	  		end;
	  txAnisotropic_02:
	  	  	begin
	  	  		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_LINEAR);
				glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, 2.0);
	  		end;
	  txAnisotropic_04:
	  	  	begin
	  	  		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_LINEAR);
				glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, 4.0);
	  		end;
	  txAnisotropic_08:
	  	  	begin
	  	  		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_LINEAR);
				glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, 8.0);
	  		end;
	  txAnisotropic_16:
	  	  	begin
	  	 	 	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_LINEAR);
				glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, 16.0);
	  		end;
	  else
	  		begin
	  			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	  		end;
	  end;
	  
	  case txMode of 
	  GL_REPLACE:
	  		begin
	  			glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);			
	  		end;
	 GL_BLEND:
			begin	
				glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_BLEND);	
	  		end;
	  GL_DECAL:
	  		begin	 
	  		 	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);		
	  		end;
	  GL_MODULATE:
	  	  	begin	 
	  	  	 	 glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE); 		
	  		end;
	  GL_ADD:
	  	  	begin	 
	  	  	 	 glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_ADD); 		
	  		end;
	  GL_COMBINE:
	  	  	begin	 
	  	  	 	 glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_COMBINE); 		
	  		end;
	 
	  end;  

	  case txPlace of 
	  GL_REPEAT:
	  		begin
	  			glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	    		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT) ;		
	  		end;
	 GL_CLAMP_TO_EDGE:
			begin	
				glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	    		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE) ;		
	  		end;
	  GL_CLAMP_TO_BORDER:
			begin	
				glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
	    		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER) ;		
	  		end;
	  GL_CLAMP:
	  		begin	 
	  		 	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	    		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP) ;			
	  		end;
	  end;	  
	  
	   if txMip_map = GL_TRUE then
			   		begin
						gluBuild2DMipmaps ( GL_TEXTURE_2D, file_type, img.Width, img.Height,  file_type, GL_UNSIGNED_BYTE, img.image_data );
			   		end
			   	else
			   		begin
			   			glTexImage2D(GL_TEXTURE_2D, 0, file_type, img.Width, img.Height, 0,  file_type, GL_UNSIGNED_BYTE, img.image_data);
			   		end;
		
end;

procedure OGL_Create_Texture(file_type, width, height:GLUint; texti: PGLUInt;txFilter,txMode,txPlace,txCompress:GLUint;txMip_map:GLBoolean);cdecl;
var
image_data:arptr;
anis_level:GLfloat;
begin
		 case file_type of 
     		GL_RGBA: GetMem(image_data, 512*512*4);
	   		GL_RGB:GetMem(image_data, 512*512*3);
	   	 end;
	 
	glGenTextures(1, texti);
	glBindTexture(GL_TEXTURE_2D, texti^);
	//glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	   			
	glGetFloatv(GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT, @anis_level);	
	if anis_level < 2 then
		txFilter:=txTrilinear;
	if  (txFilter = txAnisotropic_02) or (txFilter = txAnisotropic_04) or (txFilter = txAnisotropic_08) or (txFilter = txAnisotropic_16) then
		begin
			if txFilter > anis_level then
				txfilter:=trunc(anis_level);
		end;	
		
	  case txFilter of 
	  txNoFilter:
	  		begin
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	  		end;
	  txBilinear:
			begin
			   if txMip_map = GL_TRUE then
			   		begin
						glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
						glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
			   		end
			   	else
			   		begin
			   			glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
						glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
			   		end;
	  		end;
	  txTrilinear:
	  		begin
	  			glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
				glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	  		end;
	  txAnisotropic_02:
	  	  	begin
	  	  		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_LINEAR);
				glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, 2.0);
	  		end;
	  txAnisotropic_04:
	  	  	begin
	  	  		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_LINEAR);
				glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, 4.0);
	  		end;
	  txAnisotropic_08:
	  	  	begin
	  	  		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_LINEAR);
				glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, 8.0);
	  		end;
	  txAnisotropic_16:
	  	  	begin
	  	 	 	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_LINEAR);
				glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, 16.0);
	  		end;
	  else
	  		begin
	  			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	  		end;
	  end;
	  
	  case txMode of 
	  GL_REPLACE:
	  		begin
	  			glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);			
	  		end;
	 GL_BLEND:
			begin	
				glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_BLEND);	
	  		end;
	  GL_DECAL:
	  		begin	 
	  		 	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);		
	  		end;
	  GL_MODULATE:
	  	  	begin	 
	  	  	 	 glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE); 		
	  		end;
	 
	  end;  

	  case txPlace of 
	  GL_REPEAT:
	  		begin
	  			glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	    		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT) ;		
	  		end;
	 GL_CLAMP_TO_EDGE:
			begin	
				glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	    		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE) ;		
	  		end;
	  GL_CLAMP:
	  		begin	 
	  		 	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	    		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP) ;			
	  		end;
	  end;	  
	  
	   if txMip_map = GL_TRUE then
			   		begin
						gluBuild2DMipmaps ( GL_TEXTURE_2D, file_type, Width, Height,  file_type, GL_UNSIGNED_BYTE,image_data );
			   		end
			   	else
			   		begin
			   			glTexImage2D(GL_TEXTURE_2D, 0, file_type, Width, Height, 0,  file_type, GL_UNSIGNED_BYTE, image_data);
			   		end;
	FreeMem(image_data);	
end;

procedure CreateRenderTexture_2(width, height:GLUint;  texti: PGLUInt);cdecl;
var pData: Pointer;
begin
  // allocate memory for a 512x512 texture
	GetMem(pData, width*height*3);

	glGenTextures(1, texti);
	glBindTexture(GL_TEXTURE_2D,  texti^);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);  {Texture blends with object background}
//	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
//	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE) ;
	glTexImage2D(GL_TEXTURE_2D, 0, 3,  width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, pData);  // Use when not wanting mipmaps to be built by openGL
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); { only first two can be used }
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); { all of the above can be used }

	FreeMem(pData);
	end;


end.

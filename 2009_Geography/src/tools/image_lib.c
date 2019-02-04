#include "image_lib.h" 



int LoadBMP(char *filename, textureImage *image)
{
    FILE *file;
    unsigned long size;                 // size of the image in bytes.
    unsigned long i;                    // standard counter.
    unsigned short int planes;          // number of planes in image (must be 1) 
    unsigned short int bpp;             // number of bits per pixel (must be 24)
    char temp;                          // temporary color storage for bgr-rgb conversion.

    // make sure the file is there.
    if ((file = fopen(filename, "rb"))==NULL)
    {
	printf("File Not Found : %s\n",filename);
	return 0;
    }
    
    // seek through the bmp header, up to the width/height:
    fseek(file, 18, SEEK_CUR);
    // read the width
    if ((i = fread(&image->width, 4, 1, file)) != 1) {
	printf("Error reading width from %s.\n", filename);
	return 0;
    }
      // read the height 
    if ((i = fread(&image->height, 4, 1, file)) != 1) {
	printf("Error reading height from %s.\n", filename);
	return 0;
    }
   
    
    // calculate the size (assuming 24 bits or 3 bytes per pixel).
  
    // read the planes
    if ((fread(&planes, 2, 1, file)) != 1) {
	printf("Error reading planes from %s.\n", filename);
	return 0;
    }
    if (planes != 1) {
	printf("Planes from %s is not 1: %u\n", filename, planes);
	return 0;
    }

    // read the bpp
    if ((i = fread(&bpp, 2, 1, file)) != 1) {
	printf("Error reading bpp from %s.\n", filename);
	return 0;
    }
    if (bpp != 24) {
	printf("Bpp from %s is not 24: %u\n", filename, bpp);
	return 0;
    }
     image->imgChanal=bpp/8;
     
      size = image->width * image->height * bpp/8;	
    // seek past the rest of the bitmap header.
    fseek(file, 24, SEEK_CUR);

    // read the data. 
    image->data = (unsigned char *) malloc(size);
    if (image->data == NULL) {
	printf("Error allocating memory for color-corrected image data");
	return 0;	
    }

    if ((i = fread(image->data, size, 1, file)) != 1) {
	printf("Error reading image data from %s.\n", filename);
	return 0;
    }

    for (i=0;i<size;i+=3) { // reverse all of the colors. (bgr -> rgb)
	temp = image->data[i];
	image->data[i] = image->data[i+2];
	image->data[i+2] = temp;
    }
   printf("BMP load OK %s \n", filename);
   fclose(file);
     
    // we're done.

    return 1;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int LoadTGA(char *filename, textureImage *image)
 {
	unsigned char rep,*buf,*ptr,info[18];
	unsigned long i,j,k,l,components,size;     
	FILE *file; 
    if ((file = fopen(filename, "rb"))==NULL)
    {
	printf("File Not Found : %s\n",filename);
	return 0;
    }
	 
	  if ((i = fread(&info,1,18,file)) != 0) {
	printf("1   Error reading  from %s.\n",filename);}
	 

	
	
	
	image -> width = info[12] + info[13] * 256;
	image -> height = info[14] + info[15] * 256;
      
	switch(info[16]) {
		case 32: components = 4; break;
		case 24: components = 3; break;
		default: fclose(file); return 0;
	}
	
	 image->imgChanal=components;
	 
	size = image -> width * image -> height * components;
      
	buf = (unsigned char*) malloc(size);
    //printf("size of %s: %d\n", filename,size);
      
	image -> data = (unsigned char*) malloc(size);
   //printf("size of %s: %d\n", filename,components);
	if(!image -> data || !buf) {
		fclose(file);
		return 0;
	}
	fseek(file,info[0],SEEK_CUR);     
	switch(info[2]) {
		case 2:
		 if ((i = fread(buf,1,size,file)) != 0) {
			printf("2 Error reading  from %s.\n", filename);}
		  
		//printf("info[2] of %s: %d\n", filename,info[2]);
		break;
        case 10:
			i = 0;
			ptr = buf;
			while(i < size) {
				 if ((i = fread(&rep,1,1,file)) != 0) {
					printf(" 3 Error reading  from %s.\n", filename);}
				
				
				if(rep & 0x80) {
					rep ^= 0x80;
					 if ((i =fread(ptr,1,components,file)) != 0) {
						printf(" 4 Error reading  from %s.\n", filename);}
					
					ptr += components;
					for(j = 0; j < rep * components; j++) {
						*ptr = *(ptr - components);
						ptr ++;
					}
					i += components * (rep + 1);
				} else {
					k = components * (rep + 1);
					 if ((i =fread(ptr,1,k,file)) != 0) {
						printf(" 5 Error reading  from %s.\n", filename);}
					
					ptr += k;
					i += k;
				}
			}
			break;
		default:
			fclose(file);
			free(buf);
			free(image -> data);
			return 0;
	}
	//printf("info[17] of %s: %d\n", filename,info[17]);
	for(i = 0, j = 0; i < size; i += components, j += components) 
    {
		image -> data[j] = buf[i + 2];
		image -> data[j + 1] = buf[i + 1];
		image -> data[j + 2] = buf[i];
    
		if(components == 4) image -> data[j + 3] = buf[i + 3];
		else image -> data[j + 3] = 255;
 //          printf("data: %d\n", image ->data[j]);
	}
   //printf("info[17] of %s: %d\n", filename,info[17]);
	if((info[17] & 0x20)!=0)
		for(j = 0, k = image -> width * components; j < image -> height / 2; j ++)
			for(i = 0; i < image -> width * components; i ++) {
				l = image -> data[j * k + i];
				image -> data[j * k + i] = image -> data[(image -> height - j - 1) * k + i];
				image -> data[(image -> height - j - 1) * k + i] = l;
			}
      
	fclose(file);
	free(buf);
    printf("TGA load OK %s \n", filename);
	return 1;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
struct my_error_mgr {
	struct jpeg_error_mgr pub;
	jmp_buf setjmp_buffer;
};

typedef struct my_error_mgr *my_error_ptr;

static void my_error_exit(j_common_ptr cinfo) {
	my_error_ptr myerr = (my_error_ptr)cinfo->err;
	(*cinfo->err->output_message)(cinfo);
	longjmp(myerr->setjmp_buffer,1);
}


int LoadJPG(char *filename, textureImage *image) {

struct jpeg_decompress_struct cinfo;
	struct my_error_mgr jerr;
	FILE * infile;
	JSAMPARRAY buffer;
	int row_stride;
	long cont;
	JSAMPLE *data_buffer;
	int i,j;
	

	if(!(infile = fopen(filename,"rb"))) return 0;
	cinfo.err = jpeg_std_error(&jerr.pub);
	jerr.pub.error_exit = my_error_exit;
	if(setjmp(jerr.setjmp_buffer)) {
		jpeg_destroy_decompress(&cinfo);
		fclose(infile);
		return 0;
	}
	jpeg_create_decompress(&cinfo);
	jpeg_stdio_src(&cinfo, infile);
	jpeg_read_header(&cinfo,TRUE);
	jpeg_start_decompress(&cinfo);
	row_stride = cinfo.output_width * cinfo.num_components;
	buffer = (*cinfo.mem->alloc_sarray)((j_common_ptr)&cinfo,JPOOL_IMAGE,row_stride,1);
	data_buffer = (JSAMPLE *)malloc(cinfo.image_width * cinfo.image_height * cinfo.num_components);
	cont = 0;
	while(cinfo.output_scanline < cinfo.output_height) {
		jpeg_read_scanlines(&cinfo,buffer,1);
		memcpy(data_buffer + cinfo.image_width * cinfo.num_components * cont,buffer[0],row_stride);
		cont++;
	}
	jpeg_finish_decompress(&cinfo);
	jpeg_destroy_decompress(&cinfo);
	fclose(infile);
       image ->width =cinfo.image_width;
     image ->height = cinfo.image_height;
      image->imgChanal = cinfo.num_components;
     image -> data = (unsigned char *) malloc(image ->width *  image ->height * cinfo.num_components);
 
  
switch(cinfo.num_components) {
		case 1:
			for(i = 0, j = 0; i < image ->width * image ->height; i++, j += cinfo.num_components) {
				image -> data[j] = image -> data[j + 1] = image -> data[j + 2] = data_buffer[i];
				image -> data[j + 3] = 255;
			}
			break;
		case 3:
			for(i = 0, j = 0; i < image ->width * image ->height * cinfo.num_components; i += cinfo.num_components, j += cinfo.num_components) {
				image -> data[j] = data_buffer[i];
				image -> data[j + 1] = data_buffer[i + 1];
				image -> data[j + 2] = data_buffer[i + 2];
			}
			case 4:
			for(i = 0, j = 0; i < image ->width * image ->height * cinfo.num_components; i += cinfo.num_components, j += cinfo.num_components) {
				image -> data[j] = data_buffer[i];
				image -> data[j + 1] = data_buffer[i + 1];
				image -> data[j + 2] = data_buffer[i + 2];
				image -> data[j + 3] = 255;
			}
			break;
		default:
			free(data_buffer);
			return 0;
}

 int      counterDown   = 0,  counterUp     = 0;	
 int y,yy,x;		
switch(cinfo.num_components) {
		case 1:
			 for(y = 0, yy = image ->height - 1; y < image ->height; y++, yy--)
				  for(x = 0; x < image ->width; x++){
					counterUp   = x + yy* image ->width;
					counterDown = x +  y*image ->width;
					image -> data[counterUp + 0]   = data_buffer[counterDown + 0];
				  }
			break;
		case 3:
			for(y = 0, yy = image ->height - 1; y < image ->height; y++, yy--)
				  for(x = 0; x < image ->width; x++){
					counterUp   = (x + yy* image ->width)*cinfo.num_components;
					counterDown = (x +   image ->width)*cinfo.num_components;
					image -> data[counterUp + 0]   = data_buffer[counterDown + 0];
					image -> data[counterUp + 1]   = data_buffer[counterDown + 1];
					image -> data[counterUp + 2]   = data_buffer[counterDown + 2];
				 }
			case 4:
			 for(y = 0, yy = image ->height - 1; y < image ->height; y++, yy--)
				  for(x = 0; x < image ->width; x++){
					counterUp   = (x + yy* image ->width)*cinfo.num_components;
					counterDown = (x +  y* image ->width)*cinfo.num_components;
					image -> data[counterUp + 0]   = data_buffer[counterDown + 0];
					image -> data[counterUp + 1]   = data_buffer[counterDown + 1];
					image -> data[counterUp + 2]   = data_buffer[counterDown + 2];
					image -> data[counterUp + 3]   = data_buffer[counterDown + 3];
				  }
			break;
		default:				
			free(data_buffer);
			return 0;
	}
	free(data_buffer);
   
	printf("JPEG load OK %s \n", filename);

    return 1;
}
*/


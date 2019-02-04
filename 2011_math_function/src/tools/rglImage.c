#include "rglImage.h" 




int rglLoadBMP(char *filename, RGL_TextureImage *image)
{
    FILE *file;
    unsigned long size;                 // size of the image in bytes.
    unsigned long i;                    // standard counter.
    unsigned short int planes;          // number of planes in image (must be 1) 
    unsigned short int bpp;             // number of bits per pixel (must be 24)
 //   char temp;                          // temporary color storage for bgr-rgb conversion.

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

printf("Image BMP load OK %s \n", filename);
    return 1;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
int rglLoadTGA(char *filename, RGL_TextureImage *image)
 {
	unsigned char rep,*ptr,info[18];
	GLint i,j,k,l,components,size;     
	FILE *file = fopen(filename,"rb");
	
	if(!file) {
		printf("Don't open file : %s", filename);
		return 0;
	}
	
	if (fread(&info,1,18,file) != 18)
	{
	printf("Error read header image from %s.\n", filename);
	return 0;
    }
      
	switch(info[16]) {
		case 32: components = 4; break;
		case 24: components = 3; break;
		default: fclose(file); return 0;
	}
	
		image->imgChanal=components;
		image -> width = info[12] + info[13] * 256;
		image -> height = info[14] + info[15] * 256;
		size = image -> width * image -> height * components;
		   
		image -> data = (unsigned char*) malloc(size);
 
		fseek(file,info[0],SEEK_CUR);     
	switch(info[2]) {
		case 2:
			if (fread(image -> data,1,size,file) !=size)
				{
					printf("Error read data image from %s.\n", filename);
					return 0;
				} 
		break;
        case 10:
			i = 0;
			ptr = image -> data;
			while(i < size) {
				if (fread(&rep,1,1,file) != 1)
					{
					printf("Error read data image from %s.\n", filename);
					return 0;
					} 
				if(rep & 0x80) {
					rep ^= 0x80;
					if (fread(ptr,1,components,file) !=components)
						{
							printf("Error read data image from %s.\n", filename);
							return 0;
						} 
					ptr += components;
					for(j = 0; j < rep * components; j++) {
						*ptr = *(ptr - components);
						ptr ++;
					}
					i += components * (rep + 1);
				} else {
					k = components * (rep + 1);
					if (fread(ptr,1,k,file)  !=k )
						{
							printf("Error read data image from %s.\n", filename);
							return 0;
						} 
					ptr += k;
					i += k;
				}
			}
			break;
		default:
			fclose(file);
			free(image -> data);
			return 0;
	}
	if((info[17] & 0x20)!=0)
		for(j = 0, k = image -> width * components; j < image -> height / 2; j ++)
			for(i = 0; i < image -> width * components; i ++) {
				l = image -> data[j * k + i];
				image -> data[j * k + i] = image -> data[(image -> height - j - 1) * k + i];
				image -> data[(image -> height - j - 1) * k + i] = l;
			}
      
	fclose(file);
	printf("Image TGA load OK %s \n", filename);
	return 1;
}
*/

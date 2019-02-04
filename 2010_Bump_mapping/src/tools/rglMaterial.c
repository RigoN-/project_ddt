#include <stdio.h>
#include <stdlib.h>
#include "rglMaterial.h"


GLfloat  light_pos[] = {1.0, 0.0, 4.0, 1.0};
GLfloat light_Ka[]  = {0.9, 0.9, 0.9, 1.0};
GLfloat light_Kd[]  = {0.9, 0.9, 0.9, 1.0};
GLfloat light_Ks[]  = {1.0, 1.0, 1.0, 1.0};
GLfloat light_Se  = 32.0;

GLfloat material_Ka[31][4] = {{0.0,0.0,0.0,1.0},{0.329412, 0.223529, 0.027451, 1.0} ,{0.2125,0.1275,0.0540,1.0},
 {0.2500,0.2500,0.2500,1.0},{0.1913,0.0735,0.0225,1.0},{0.2473,0.1995,0.0745,1.0},{0.1059,0.0588,0.1137,1.0},
 {0.19225, 0.19225, 0.19225, 1.0},{0.23125, 0.23125, 0.23125, 1.0},{0.0215, 0.1745, 0.0215, 0.55},
 {0.135, 0.2225, 0.1575, 0.95},{0.05375, 0.05, 0.06625, 0.82},{0.25, 0.20725, 0.20725, 0.922},
 {0.1745, 0.01175, 0.01175, 0.55},{0.1, 0.18725, 0.1745, 0.8},{0.02, 0.02, 0.02, 1.0},{0.25, 0.148, 0.06475, 1.0},
 {0.2295, 0.08825, 0.0275, 1.0},{0.24725, 0.2245, 0.0645, 1.0},{0.0, 0.0, 0.0, 1.0},{0.0, 0.1, 0.6, 1.0},{0.0, 0.0, 0.0, 1.0},
 {0.5, 0.0, 0.0, 1.0},{0.5 , 0.0 , 0.0, 1.0},{0.3, 0.3, 0.3, 1.0},{0.0, 0.0, 0.0, 1.0},{0.0, 0.05, 0.05, 1.0},
 {0.00, 0.05, 0.00, 1.0},{0.05, 0.00, 0.00, 1.0},{0.05, 0.05, 0.05, 1.0},{0.05, 0.05, 0.00, 1.0}};
GLfloat material_Kd[30][4] = {{0.0100,0.0100,0.0100,1.0},{0.780392, 0.568627, 0.113725, 1.0} ,{0.7140,0.4284,0.1814,1.0},
	{0.4000,0.4000,0.4000,1.0},{0.7038,0.2705,0.0828,1.0},{0.7516,0.6065,0.2265,1.0},{0.4275,0.4706,0.5412,1.0},{0.50754, 0.50754, 0.50754, 1.0},
	{0.2775, 0.2775, 0.2775, 1.0},{0.07568, 0.61424, 0.07568, 0.55},{0.54, 0.89, 0.63, 0.95},{0.18275, 0.17, 0.22525, 0.82},
	{1.0, 0.829, 0.829, 0.922},{0.61424, 0.04136, 0.04136, 0.55},{0.396, 0.74151, 0.69102, 0.8},{0.01, 0.01, 0.01, 1.0},
	{0.4, 0.2368, 0.1036, 1.0},{0.5508, 0.2118, 0.066, 1.0},{0.34615, 0.3143, 0.0903, 1.0},{0.01, 0.01, 0.01, 1.0},
	{0.0 , 0.50980392 , 0.50980392, 1.0},{0.1 , 0.35 , 0.1, 1.0},{0.5 , 0.0 , 0.0, 1.0},{0.55 , 0.55 , 0.55, 1.0},
	{0.5 , 0.5 , 0.0, 1.0},{0.4, 0.5, 0.5, 1.0},{0.4, 0.5, 0.4, 1.0},{0.5, 0.4, 0.4, 1.0},{0.5 , 0.5 , 0.5, 1.0},{0.5 , 0.5 , 0.4, 1.0}};
GLfloat material_Ks[30][4] = {{0.5000,0.5000,0.5000,1.0},{0.992157, 0.941176, 0.807843, 1.0} ,{0.3935,0.2719,0.1667,1.0},
	{0.7746,0.7746,0.7746,1.0},{0.2568,0.1376,0.0860,1.0},{0.6283,0.5558,0.3661,1.0},
	{0.3333,0.3333,0.5216,1.0},{0.508273, 0.508273, 0.508273, 1.0} ,{0.773911, 0.773911, 0.773911, 1.0},
	{0.633, 0.727811, 0.633, 0.55},{0.316228, 0.316228, 0.316228, 0.95},{0.332741, 0.328634, 0.346435, 0.82},
	{0.296648, 0.296648, 0.296648, 0.922},{0.727811, 0.626959, 0.626959, 0.55},{0.297254, 0.30829, 0.306678, 0.8},
	{0.4, 0.4, 0.4, 1.0},{0.774597, 0.458561, 0.200621, 1.0},{0.580594, 0.223257, 0.0695701, 1.0},{0.797357, 0.723991, 0.208006, 1.0},
	{0.50, 0.50, 0.50, 1.0},{0.50196, 0.501968, 0.50196, 1.0},{0.45, 0.55, 0.45, 1.0},{0.7, 0.6, 0.6, 1.0},{0.7, 0.7, 0.7, 1.0},
	{0.6, 0.6, 0.5, 1.0},{0.04, 0.7, 0.7, 1.0},{0.04, 0.7, 0.04, 1.0},{0.7, 0.04, 0.04, 1.0},{0.7, 0.7, 0.7, 1.0},{0.7, 0.7, 0.04, 1.0}};
GLfloat material_Ke[4] = {0.0, 0.0, 0.0, 0.0};
GLfloat material_Se[30] =  {32.0,27.8974,26.0,77.0,13.0,51.0,10.0,51.2,89.6,76.8,12.8,38.4,11.264,76.8,12.8,10.0,76.8,51.2,
	83.2,32.0,32.0,32.0,32.0,32.0,32.0,10.00000,10.00000,10.00000,10.00000,10.00000};
	
GLvoid rglInitLight_2(rglLight *L)
{
	 L->Lposition=rglVector4Set(light_pos[0],light_pos[1],light_pos[2],light_pos[3]);
	 L->Lambient=rglVector4Set(light_Ka[0],light_Ka[1],light_Ka[2],light_Ka[3]);
	L->Ldiffuse=rglVector4Set(light_Kd[0],light_Kd[1],light_Kd[2],light_Kd[3] );
	L->Lspecular=rglVector4Set(light_Ks[0],light_Ks[1],light_Ks[2],light_Ks[3] );
	}

GLvoid rglInitLight()
{
   
     glEnable(GL_LIGHTING);
     glEnable(GL_LIGHT0);
     glEnable(GL_NORMALIZE);
     
     // Light model parameters:
     // -------------------------------------------
     
     GLfloat lmKa[] = {0.0, 0.0, 0.0, 0.0 };
     glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmKa);
     
     glLightModelf(GL_LIGHT_MODEL_LOCAL_VIEWER, 1.0);
     glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, 0.0);
     
     // -------------------------------------------
     // Spotlight Attenuation
     
     GLfloat spot_direction[] = {1.0, -1.0, -1.0 };
     GLint spot_exponent = 30;
     GLint spot_cutoff = 180;
     
     glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spot_direction);
     glLighti(GL_LIGHT0, GL_SPOT_EXPONENT, spot_exponent);
     glLighti(GL_LIGHT0, GL_SPOT_CUTOFF, spot_cutoff);
    
     GLfloat Kc = 1.0;
     GLfloat Kl = 0.0;
     GLfloat Kq = 0.0;
     
     glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION,Kc);
     glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, Kl);
     glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, Kq);
     
     
     // ------------------------------------------- 
     // Lighting parameters:
	

     glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
     glLightfv(GL_LIGHT0, GL_AMBIENT, light_Ka);
     glLightfv(GL_LIGHT0, GL_DIFFUSE, light_Kd);
     glLightfv(GL_LIGHT0, GL_SPECULAR, light_Ks);

     // -------------------------------------------
     // Material parameters:



     glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_Ka[0]);
     glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_Kd[0]);
     glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_Ks[0]);
     glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, material_Ke);
     glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, material_Se[0]);

}

GLvoid  rglSetMaterial_2(GLint material, rglMaterial *M)
{
	M->Memission= rglVector4Set(material_Ke[0],material_Ke[1],material_Ke[2],material_Ke[3] );
	 M->Mambient=rglVector4Set(material_Ka[material][0],material_Ka[material][1],material_Ka[material][2],material_Ka[material][3]);
	M->Mdiffuse= rglVector4Set(material_Kd[material][0],material_Kd[material][1],material_Kd[material][2],material_Kd[material][3]);
	M->Mspecular= rglVector4Set(material_Ks[material][0],material_Ks[material][1],material_Ks[material][2],material_Ks[material][3]);
	M->Mshininess=material_Se[material];  
}

GLvoid  rglSetMaterial(GLint material )
{
	 glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_Ka[material]);
     glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_Kd[material]);
     glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_Ks[material]);
     glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, material_Ke);
     glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, material_Se[material]);
  
}

GLvoid  rglSetBlendMode(GLint blend)
{
	glDisable(GL_BLEND);
//	printf("Blend = %i\n", blend);
	 switch ( blend )
				{	
			case 0: glBlendFunc(GL_ZERO,GL_ZERO);     break;
			case 1: glBlendFunc(GL_ZERO,GL_ONE);      break;
			case 2: glBlendFunc(GL_ZERO,GL_SRC_COLOR);break;
			case 3: glBlendFunc(GL_ZERO,GL_ONE_MINUS_SRC_COLOR);break;
			case 4:glBlendFunc(GL_ZERO,GL_DST_COLOR); break;
			case 5:glBlendFunc(GL_ZERO,GL_ONE_MINUS_DST_COLOR);break;
		    case 6:glBlendFunc(GL_ZERO,GL_SRC_ALPHA); break;
		    case 7:glBlendFunc(GL_ZERO,GL_ONE_MINUS_SRC_ALPHA);break;
		    case 8:glBlendFunc(GL_ZERO,GL_DST_ALPHA);break;
		    case 9:glBlendFunc(GL_ZERO,GL_ONE_MINUS_DST_ALPHA); break;
		    case 10:glBlendFunc(GL_ONE,GL_ZERO);break;
		    case 11:glBlendFunc(GL_ONE,GL_ONE);break;
		    case 12:glBlendFunc(GL_ONE,GL_SRC_COLOR);break;
		    case 13:glBlendFunc(GL_ONE,GL_ONE_MINUS_SRC_COLOR); break;
			case 14:glBlendFunc(GL_ONE,GL_DST_COLOR); break;
			case 15:glBlendFunc(GL_ONE,GL_ONE_MINUS_DST_COLOR); break;
			case 16:glBlendFunc(GL_ONE,GL_SRC_ALPHA); break;
			case 17:glBlendFunc(GL_ONE,GL_ONE_MINUS_SRC_ALPHA); break;
			case 18:glBlendFunc(GL_ONE,GL_DST_ALPHA); break;
			case 19:glBlendFunc(GL_ONE,GL_ONE_MINUS_DST_ALPHA); break;
		    case 20:glBlendFunc(GL_SRC_COLOR,GL_ZERO); break;
		    case 21:glBlendFunc(GL_SRC_COLOR,GL_ONE); break;
			case 22:glBlendFunc(GL_SRC_COLOR,GL_SRC_COLOR); break;
			case 23:glBlendFunc(GL_SRC_COLOR,GL_ONE_MINUS_SRC_COLOR); break;
			case 24:glBlendFunc(GL_SRC_COLOR,GL_DST_COLOR); break; 
			case 25:glBlendFunc(GL_SRC_COLOR,GL_ONE_MINUS_DST_COLOR); break;
		case 26:glBlendFunc(GL_SRC_COLOR,GL_SRC_ALPHA); break;
		case 27:glBlendFunc(GL_SRC_COLOR,GL_ONE_MINUS_SRC_ALPHA); break;
		case 28:glBlendFunc(GL_SRC_COLOR,GL_DST_ALPHA); break;
		case 29:glBlendFunc(GL_SRC_COLOR,GL_ONE_MINUS_DST_ALPHA); break;
		case 30:glBlendFunc(GL_ONE_MINUS_SRC_COLOR,GL_ZERO); break;
		case 31:glBlendFunc(GL_ONE_MINUS_SRC_COLOR,GL_ONE); break;
		case 32:glBlendFunc(GL_ONE_MINUS_SRC_COLOR,GL_SRC_COLOR); break;
		case 33:glBlendFunc(GL_ONE_MINUS_SRC_COLOR,GL_ONE_MINUS_SRC_COLOR); break;
		case 34:glBlendFunc(GL_ONE_MINUS_SRC_COLOR,GL_DST_COLOR); break;
		case 35:glBlendFunc(GL_ONE_MINUS_SRC_COLOR,GL_ONE_MINUS_DST_COLOR); break;
		case 36:glBlendFunc(GL_ONE_MINUS_SRC_COLOR,GL_SRC_ALPHA); break;
		case 37:glBlendFunc(GL_ONE_MINUS_SRC_COLOR,GL_ONE_MINUS_SRC_ALPHA); break;
		case 38:glBlendFunc(GL_ONE_MINUS_SRC_COLOR,GL_DST_ALPHA); break;
		case 39:glBlendFunc(GL_ONE_MINUS_SRC_COLOR,GL_ONE_MINUS_DST_ALPHA); break;
		case 40:glBlendFunc(GL_DST_COLOR,GL_ZERO); break;
		case 41:glBlendFunc(GL_DST_COLOR,GL_ONE); break;
		case 42:glBlendFunc(GL_DST_COLOR,GL_SRC_COLOR); break;
		case 43:glBlendFunc(GL_DST_COLOR,GL_ONE_MINUS_SRC_COLOR); break;
		case 44:glBlendFunc(GL_DST_COLOR,GL_DST_COLOR); break;
		case 45:glBlendFunc(GL_DST_COLOR,GL_ONE_MINUS_DST_COLOR); break;
		case 46:glBlendFunc(GL_DST_COLOR,GL_SRC_ALPHA); break;
		case 47:glBlendFunc(GL_DST_COLOR,GL_ONE_MINUS_SRC_ALPHA); break;
		case 48:glBlendFunc(GL_DST_COLOR,GL_DST_ALPHA); break;
		case 49:glBlendFunc(GL_DST_COLOR,GL_ONE_MINUS_DST_ALPHA); break;
		case 50:glBlendFunc(GL_ONE_MINUS_DST_COLOR,GL_ZERO);break;
		case 51:glBlendFunc(GL_ONE_MINUS_DST_COLOR,GL_ONE);break;
		case 52:glBlendFunc(GL_ONE_MINUS_DST_COLOR,GL_SRC_COLOR);break;
		case 53:glBlendFunc(GL_ONE_MINUS_DST_COLOR,GL_ONE_MINUS_SRC_COLOR);break;
		case 54:glBlendFunc(GL_ONE_MINUS_DST_COLOR,GL_DST_COLOR);break;
		case 55:glBlendFunc(GL_ONE_MINUS_DST_COLOR,GL_ONE_MINUS_DST_COLOR);break;
		case 56:glBlendFunc(GL_ONE_MINUS_DST_COLOR,GL_SRC_ALPHA);break;
		case 57:glBlendFunc(GL_ONE_MINUS_DST_COLOR,GL_ONE_MINUS_SRC_ALPHA);break;
		case 58:glBlendFunc(GL_ONE_MINUS_DST_COLOR,GL_DST_ALPHA);break;
		case 59:glBlendFunc(GL_ONE_MINUS_DST_COLOR,GL_ONE_MINUS_DST_ALPHA);break;
		case 60:glBlendFunc(GL_SRC_ALPHA,GL_ZERO);break;
		case 61:glBlendFunc(GL_SRC_ALPHA,GL_ONE);break;
		case 62:glBlendFunc(GL_SRC_ALPHA,GL_SRC_COLOR);break;
		case 63:glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_COLOR);break;
		case 64:glBlendFunc(GL_SRC_ALPHA,GL_DST_COLOR);break;
		case 65:glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_DST_COLOR);break;
		case 66:glBlendFunc(GL_SRC_ALPHA,GL_SRC_ALPHA);break;
		case 67:glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);break;
		case 68:glBlendFunc(GL_SRC_ALPHA,GL_DST_ALPHA);break;
		case 69:glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_DST_ALPHA);break;
		case 70:glBlendFunc(GL_ONE_MINUS_SRC_ALPHA,GL_ZERO);break;
		case 71:glBlendFunc(GL_ONE_MINUS_SRC_ALPHA,GL_ONE);break;
		case 72:glBlendFunc(GL_ONE_MINUS_SRC_ALPHA,GL_SRC_COLOR);break;
		case 73:glBlendFunc(GL_ONE_MINUS_SRC_ALPHA,GL_ONE_MINUS_SRC_COLOR);break;
		case 74:glBlendFunc(GL_ONE_MINUS_SRC_ALPHA,GL_DST_COLOR);break;
		case 75:glBlendFunc(GL_ONE_MINUS_SRC_ALPHA,GL_ONE_MINUS_DST_COLOR);break;
		case 76:glBlendFunc(GL_ONE_MINUS_SRC_ALPHA,GL_SRC_ALPHA);  break;
		case 77:glBlendFunc(GL_ONE_MINUS_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);printf("Point1\n");break;
		case 78:glBlendFunc(GL_ONE_MINUS_SRC_ALPHA,GL_DST_ALPHA);break;
		case 79:glBlendFunc(GL_ONE_MINUS_SRC_ALPHA,GL_ONE_MINUS_DST_ALPHA);break;
		case 80:glBlendFunc(GL_DST_ALPHA,GL_ZERO);break;
		case 81:glBlendFunc(GL_DST_ALPHA,GL_ONE);break;
		case 82:glBlendFunc(GL_DST_ALPHA,GL_SRC_COLOR);break;
		case 83:glBlendFunc(GL_DST_ALPHA,GL_ONE_MINUS_SRC_COLOR);break;
		case 84:glBlendFunc(GL_DST_ALPHA,GL_DST_COLOR);break;
		case 85:glBlendFunc(GL_DST_ALPHA,GL_ONE_MINUS_DST_COLOR);break;
		case 86:glBlendFunc(GL_DST_ALPHA,GL_SRC_ALPHA);break;
		case 87:glBlendFunc(GL_DST_ALPHA,GL_ONE_MINUS_SRC_ALPHA);break;
		case 88:glBlendFunc(GL_DST_ALPHA,GL_DST_ALPHA);break;
		case 89:glBlendFunc(GL_DST_ALPHA,GL_ONE_MINUS_DST_ALPHA);break;
		case 90:glBlendFunc(GL_ONE_MINUS_DST_ALPHA,GL_ZERO);break;
		case 91:glBlendFunc(GL_ONE_MINUS_DST_ALPHA,GL_ONE);break;
		case 92:glBlendFunc(GL_ONE_MINUS_DST_ALPHA,GL_SRC_COLOR);break;
		case 93:glBlendFunc(GL_ONE_MINUS_DST_ALPHA,GL_ONE_MINUS_SRC_COLOR);break;
		case 94:glBlendFunc(GL_ONE_MINUS_DST_ALPHA,GL_DST_COLOR);break;
		case 95:glBlendFunc(GL_ONE_MINUS_DST_ALPHA,GL_ONE_MINUS_DST_COLOR);break;
		case 96:glBlendFunc(GL_ONE_MINUS_DST_ALPHA,GL_SRC_ALPHA);break;
		case 97:glBlendFunc(GL_ONE_MINUS_DST_ALPHA,GL_ONE_MINUS_SRC_ALPHA);break;
		case 98:glBlendFunc(GL_ONE_MINUS_DST_ALPHA,GL_DST_ALPHA);break;
		case 99:glBlendFunc(GL_ONE_MINUS_DST_ALPHA,GL_ONE_MINUS_DST_ALPHA);break;
		case 100:glBlendFunc(GL_SRC_ALPHA_SATURATE,GL_ZERO);break;
		case 101:glBlendFunc(GL_SRC_ALPHA_SATURATE,GL_ONE);break;
		case 102:glBlendFunc(GL_SRC_ALPHA_SATURATE,GL_SRC_COLOR);break;
		case 103:glBlendFunc(GL_SRC_ALPHA_SATURATE,GL_ONE_MINUS_SRC_COLOR);break;
		case 104:glBlendFunc(GL_SRC_ALPHA_SATURATE,GL_DST_COLOR);break;
		case 105:glBlendFunc(GL_SRC_ALPHA_SATURATE,GL_ONE_MINUS_DST_COLOR);break;
		case 106:glBlendFunc(GL_SRC_ALPHA_SATURATE,GL_SRC_ALPHA);break;
		case 107:glBlendFunc(GL_SRC_ALPHA_SATURATE,GL_ONE_MINUS_SRC_ALPHA);break;
		case 108:glBlendFunc(GL_SRC_ALPHA_SATURATE,GL_DST_ALPHA);break;
		case 109:glBlendFunc(GL_SRC_ALPHA_SATURATE,GL_ONE_MINUS_DST_ALPHA);break;
				}
				
	glEnable(GL_BLEND);			
}


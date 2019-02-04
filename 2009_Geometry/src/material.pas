{$R-}
{$MODE DELPHI}
unit material;
interface
uses SDL_gl,  SDL_glu,  SysUtils,  sdl, text_glut, SDL_glut, SDL_glext;
var
	LightPosition : array[0..3] of glFloat = (-1.0,-1.0,3.0,0.0);
	Ambient_Light : array[0..3] of glFloat = (1.0,1.0,1.0,1.0);
	Diffuse_Light : array[0..3] of glFloat = (1.0,1.0,1.0,1.0);
	Specular_Light : array[0..3] of glFloat = (1.0,1.0,1.0,1.0);
	Shininess:glFloat=0.99*128;

//Черная пластмасса
//Латунь
//Бронза
//Хром
//Медь
//Золото
//Олово
//Серебро
//Полированное Cеребро
//изумруд
//нефрит
//обсиден
//жемчуг
//рубин
//бирюза
//черный каучук
	
	Ambient_mat : array[0..15,0..3] of glFloat = ((0.0,0.0,0.0,1.0),(0.329412, 0.223529, 0.027451, 1.0) ,(0.2125,0.1275,0.0540,1.0),(0.2500,0.2500,0.2500,1.0),(0.1913,0.0735,0.0225,1.0),(0.2473,0.1995,0.0745,1.0),(0.1059,0.0588,0.1137,1.0),(0.19225, 0.19225, 0.19225, 1.0),(0.23125, 0.23125, 0.23125, 1.0),(0.0215, 0.1745, 0.0215, 0.55),(0.135, 0.2225, 0.1575, 0.95),(0.05375, 0.05, 0.06625, 0.82),(0.25, 0.20725, 0.20725, 0.922),(0.1745, 0.01175, 0.01175, 0.55),(0.1, 0.18725, 0.1745, 0.8),(0.02, 0.02, 0.02, 1.0));
	Diffuse_mat : array[0..15,0..3] of glFloat = ((0.0100,0.0100,0.0100,1.0),(0.780392, 0.568627, 0.113725, 1.0) ,(0.7140,0.4284,0.1814,1.0),(0.4000,0.4000,0.4000,1.0),(0.7038,0.2705,0.0828,1.0),(0.7516,0.6065,0.2265,1.0),(0.4275,0.4706,0.5412,1.0),(0.50754, 0.50754, 0.50754, 1.0),(0.2775, 0.2775, 0.2775, 1.0),(0.07568, 0.61424, 0.07568, 0.55),(0.54, 0.89, 0.63, 0.95),(0.18275, 0.17, 0.22525, 0.82),(1.0, 0.829, 0.829, 0.922),(0.61424, 0.04136, 0.04136, 0.55),(0.396, 0.74151, 0.69102, 0.8),(0.01, 0.01, 0.01, 1.0));
	Specular_mat : array[0..15,0..3] of glFloat = ((0.5000,0.5000,0.5000,1.0),(0.992157, 0.941176, 0.807843, 1.0) ,(0.3935,0.2719,0.1667,1.0),(0.7746,0.7746,0.7746,1.0),(0.2568,0.1376,0.0860,1.0),(0.6283,0.5558,0.3661,1.0),(0.3333,0.3333,0.5216,1.0),(0.508273, 0.508273, 0.508273, 1.0) ,(0.773911, 0.773911, 0.773911, 1.0),(0.633, 0.727811, 0.633, 0.55),(0.316228, 0.316228, 0.316228, 0.95),(0.332741, 0.328634, 0.346435, 0.82),(0.296648, 0.296648, 0.296648, 0.922),(0.727811, 0.626959, 0.626959, 0.55),(0.297254, 0.30829, 0.306678, 0.8),(0.4, 0.4, 0.4, 1.0));
	Shininess_mat : array[0..15] of glFloat = (32.0,27.8974,26.0,77.0,13.0,51.0,10.0,51.2,89.6,76.8,12.8,38.4,11.264,76.8,12.8,10.0);

implementation
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


end.

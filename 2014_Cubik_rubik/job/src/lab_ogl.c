#include "lab_ogl.h"
#include "lab_texture.h"
cube_t a;
cube_t g,g1;
cubik_t b;
black_t clr;
void glew_init(void)
{
	int err=glewInit();
	if (GLEW_OK != err){
		printf("Error: %s\n",glewGetErrorString(err));
		glfwTerminate(); exit(EXIT_FAILURE);
	}
	else
	{
	printf("Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));
	}
	
	if (glewIsSupported("GL_VERSION_3_3")){
		printf("Support OpenGl successful\n");
	}
	else
	{
	printf("Version OpenGL not supported\n");
	glfwTerminate(); exit(EXIT_FAILURE);
	}
}
extern int draw_scena_help;
extern float angle;
float ray=0.0;
float rax=0.0;
float raz=0.0;
float SPEED=0.3;
int flag=0;
int flag_FR=0;
int flag_BL=0;
int flag_BR=0;
int flag_UL=0;
int flag_UR=0;
int flag_DL=0;
int flag_DR=0;
int flag_LL=0;
int flag_LR=0;
int flag_RL=0;
int flag_RR=0;
int draw_scena=0;
int button_1=0;
int button_2=0;
int button_3=0;

char *txtrs="../data/textures/txtrs_3.tga";
//char *txtrs="../data/textures/txtrs_2.tga";
//char *txtrs="../data/textures/txtrs.tga";
//char *txtrs="../data/textures/test.tga";
char *stl="../data/textures/m/stl.tga";
char *nch="../data/textures/m/nch.tga";
char *help="../data/textures/m/help.tga";
char *exit1="../data/textures/m/exit.tga";
char *name="../data/textures/m/name.tga";
char *help_2="../data/textures/m/help_2.tga";
GLuint txtrs_1;
GLuint stl_1;
GLuint nch_1;
GLuint help_1;
GLuint exit_1;
GLuint name_1;
GLuint help_22;

char *nch_bb="../data/textures/m/nch_b.tga";
char *help_bb="../data/textures/m/help_b.tga";
char *exit_bb="../data/textures/m/exit_b.tga";
GLuint nch_b,help_b,exit_b;

char *h="../data/textures/m/h.tga";
GLuint h_1;

rglMat4f_t mvm,mvm2;
rglVec3f_t v,vu,vd,vl,vr,vb,vf;
void vector_init(){
rglVectorInit3f(&vf,0.0,0.0,10.0);
rglVectorInit3f(&vb,0.0,0.0,-10.0);
rglVectorInit3f(&vr,10.0,0.0,0.0);
rglVectorInit3f(&vl,-10.0,0.0,0.0);
rglVectorInit3f(&vu,0.0,10.0,0.0);
rglVectorInit3f(&vd,0.0,-10.0,0.0);
}
//Функция инициализации куба со стороной 2
void cube_init(cube_t *cub){
int i;
	//cub->m[0].x=-1.0;cub->m[0].y=-1.0;cub->m[0].z=1.0;	/*низ*/			cub->m[0].colorR=1.0;cub->m[0].colorG=1.0;cub->m[0].colorB=0.0;
	//cub->m[1].x=-1.0;cub->m[1].y=-1.0;cub->m[1].z=-1.0;	/*низ*/			cub->m[1].colorR=1.0;cub->m[1].colorG=1.0;cub->m[1].colorB=0.0;
	//cub->m[2].x=1.0;cub->m[2].y=-1.0;cub->m[2].z=1.0;	/*низ*/			cub->m[2].colorR=1.0;cub->m[2].colorG=1.0;cub->m[2].colorB=0.0;
	//cub->m[3].x=1.0;cub->m[3].y=-1.0;cub->m[3].z=-1.0;	/*низ*/			cub->m[3].colorR=1.0;cub->m[3].colorG=1.0;cub->m[3].colorB=0.0;
	//cub->m[4].x=1.0;cub->m[4].y=1.0;cub->m[4].z=-1.0;	/*право*/		cub->m[4].colorR=0.0;cub->m[4].colorG=1.0;cub->m[4].colorB=0.0;
	//cub->m[5].x=-1.0;cub->m[5].y=-1.0;cub->m[5].z=-1.0;	/*тыл*/			cub->m[5].colorR=1.0;cub->m[5].colorG=0.5;cub->m[5].colorB=0.0;
	//cub->m[6].x=-1.0;cub->m[6].y=1.0;cub->m[6].z=-1.0;	/*тыл*/			cub->m[6].colorR=1.0;cub->m[6].colorG=0.5;cub->m[6].colorB=0.0;
	//cub->m[7].x=-1.0;cub->m[7].y=-1.0;cub->m[7].z=1.0;	/*лево*/		cub->m[7].colorR=0.2;cub->m[7].colorG=0.0;cub->m[7].colorB=0.8;
	//cub->m[8].x=-1.0;cub->m[8].y=1.0;cub->m[8].z=1.0;	/*лево*/		cub->m[8].colorR=0.2;cub->m[8].colorG=0.0;cub->m[8].colorB=0.8;
	//cub->m[9].x=1.0;cub->m[9].y=-1.0;cub->m[9].z=1.0;	/*лицо*/		cub->m[9].colorR=1.0;cub->m[9].colorG=0.0;cub->m[9].colorB=0.0;
	//cub->m[10].x=1.0;cub->m[10].y=1.0;cub->m[10].z=1.0;	/*лицо*/		cub->m[10].colorR=1.0;cub->m[10].colorG=0.0;cub->m[10].colorB=0.0;
	//cub->m[11].x=1.0;cub->m[11].y=1.0;cub->m[11].z=-1.0;/*право*/		cub->m[11].colorR=0.0;cub->m[11].colorG=1.0;cub->m[11].colorB=0.0;
	//cub->m[12].x=-1.0;cub->m[12].y=1.0;cub->m[12].z=1.0;/*вверх*/		cub->m[12].colorR=1.0;cub->m[12].colorG=1.0;cub->m[12].colorB=1.0;
	//cub->m[13].x=-1.0;cub->m[13].y=1.0;cub->m[13].z=-1.0;/*вверх*/		cub->m[13].colorR=1.0;cub->m[13].colorG=1.0;cub->m[13].colorB=1.0;
	
	cub->m[0].x=1.0;cub->m[0].y=-1.0;cub->m[0].z=1.0;cub->m[0].texture_x=0.75;cub->m[0].texture_y=0.5;
	cub->m[1].x=-1.0;cub->m[1].y=-1.0;cub->m[1].z=1.0;cub->m[1].texture_x=0.5;cub->m[1].texture_y=0.5;
	cub->m[2].x=-1.0;cub->m[2].y=-1.0;cub->m[2].z=-1.0;cub->m[2].texture_x=0.5;cub->m[2].texture_y=0.0;
	cub->m[3].x=1.0;cub->m[3].y=-1.0;cub->m[3].z=1.0;cub->m[3].texture_x=0.75;cub->m[3].texture_y=0.5;
	cub->m[4].x=-1.0;cub->m[4].y=-1.0;cub->m[4].z=-1.0;cub->m[4].texture_x=0.5;cub->m[4].texture_y=0.0;
	cub->m[5].x=1.0;cub->m[5].y=-1.0;cub->m[5].z=-1.0;cub->m[5].texture_x=0.75;cub->m[5].texture_y=0.0;
	cub->m[6].x=1.0;cub->m[6].y=1.0;cub->m[6].z=1.0;cub->m[6].texture_x=1.0;cub->m[6].texture_y=0.5;
	cub->m[7].x=-1.0;cub->m[7].y=1.0;cub->m[7].z=1.0;cub->m[7].texture_x=0.75;cub->m[7].texture_y=0.5;
	cub->m[8].x=-1.0;cub->m[8].y=-1.0;cub->m[8].z=1.0;cub->m[8].texture_x=0.75;cub->m[8].texture_y=0.0;
	cub->m[9].x=1.0;cub->m[9].y=1.0;cub->m[9].z=1.0;cub->m[9].texture_x=1.0;cub->m[9].texture_y=0.5;
	cub->m[10].x=-1.0;cub->m[10].y=-1.0;cub->m[10].z=1.0;cub->m[10].texture_x=0.75;cub->m[10].texture_y=0.0;
	cub->m[11].x=1.0;cub->m[11].y=-1.0;cub->m[11].z=1.0;cub->m[11].texture_x=1.0;cub->m[11].texture_y=0.0;
	cub->m[12].x=1.0;cub->m[12].y=1.0;cub->m[12].z=-1.0;cub->m[12].texture_x=0.5;cub->m[12].texture_y=1.0;
	cub->m[13].x=-1.0;cub->m[13].y=1.0;cub->m[13].z=-1.0;cub->m[13].texture_x=0.25;cub->m[13].texture_y=1.0;
	cub->m[14].x=-1.0;cub->m[14].y=1.0;cub->m[14].z=1.0;cub->m[14].texture_x=0.25;cub->m[14].texture_y=0.5;
	cub->m[15].x=1.0;cub->m[15].y=1.0;cub->m[15].z=-1.0;cub->m[15].texture_x=0.5;cub->m[15].texture_y=1.0;
	cub->m[16].x=-1.0;cub->m[16].y=1.0;cub->m[16].z=1.0;cub->m[16].texture_x=0.25;cub->m[16].texture_y=0.5;
	cub->m[17].x=1.0;cub->m[17].y=1.0;cub->m[17].z=1.0;cub->m[17].texture_x=0.5;cub->m[17].texture_y=0.5;
	cub->m[18].x=1.0;cub->m[18].y=-1.0;cub->m[18].z=-1.0;cub->m[18].texture_x=0.5;cub->m[18].texture_y=0.5;
	cub->m[19].x=-1.0;cub->m[19].y=-1.0;cub->m[19].z=-1.0;cub->m[19].texture_x=0.25;cub->m[19].texture_y=0.5;
	cub->m[20].x=-1.0;cub->m[20].y=1.0;cub->m[20].z=-1.0;cub->m[20].texture_x=0.25;cub->m[20].texture_y=0.0;
	cub->m[21].x=1.0;cub->m[21].y=-1.0;cub->m[21].z=-1.0;cub->m[21].texture_x=0.5;cub->m[21].texture_y=0.5;
	cub->m[22].x=-1.0;cub->m[22].y=1.0;cub->m[22].z=-1.0;cub->m[22].texture_x=0.25;cub->m[22].texture_y=0.0;
	cub->m[23].x=1.0;cub->m[23].y=1.0;cub->m[23].z=-1.0;cub->m[23].texture_x=0.5;cub->m[23].texture_y=0.0;
	cub->m[24].x=1.0;cub->m[24].y=1.0;cub->m[24].z=-1.0;cub->m[24].texture_x=1.0;cub->m[24].texture_y=1.0;
	cub->m[25].x=1.0;cub->m[25].y=1.0;cub->m[25].z=1.0;cub->m[25].texture_x=0.75;cub->m[25].texture_y=1.0;
	cub->m[26].x=1.0;cub->m[26].y=-1.0;cub->m[26].z=1.0;cub->m[26].texture_x=0.75;cub->m[26].texture_y=0.5;
	cub->m[27].x=1.0;cub->m[27].y=1.0;cub->m[27].z=-1.0;cub->m[27].texture_x=1.0;cub->m[27].texture_y=1.0;
	cub->m[28].x=1.0;cub->m[28].y=-1.0;cub->m[28].z=1.0;cub->m[28].texture_x=0.75;cub->m[28].texture_y=0.5;
	cub->m[29].x=1.0;cub->m[29].y=-1.0;cub->m[29].z=-1.0;cub->m[29].texture_x=1.0;cub->m[29].texture_y=0.5;
	cub->m[30].x=-1.0;cub->m[30].y=1.0;cub->m[30].z=1.0;cub->m[30].texture_x=0.75;cub->m[30].texture_y=1.0; 
	cub->m[31].x=-1.0;cub->m[31].y=1.0;cub->m[31].z=-1.0;cub->m[31].texture_x=0.5;cub->m[31].texture_y=1.0;
	cub->m[32].x=-1.0;cub->m[32].y=-1.0;cub->m[32].z=-1.0;cub->m[32].texture_x=0.5;cub->m[32].texture_y=0.5;
	cub->m[33].x=-1.0;cub->m[33].y=1.0;cub->m[33].z=1.0;cub->m[33].texture_x=0.75;cub->m[33].texture_y=1.0;
	cub->m[34].x=-1.0;cub->m[34].y=-1.0;cub->m[34].z=-1.0;cub->m[34].texture_x=0.5;cub->m[34].texture_y=0.5;
	cub->m[35].x=-1.0;cub->m[35].y=-1.0;cub->m[35].z=1.0;cub->m[35].texture_x=0.75;cub->m[35].texture_y=0.5;
	
	for (i=0;i<36;i++){
		cub->m[i].colorR=1.0;cub->m[i].colorG=1.0;cub->m[i].colorB=0.0;
	}
}

//Функция заполнения массива 3х3х3 подмассивом
void mass_enter(cubik_t *b,cube_t *a,int i,int j,int k){
int ij;
	for (ij=0;ij<36;ij++){
		b->mass[i][j][k].m[ij].x=a->m[ij].x;
		b->mass[i][j][k].m[ij].y=a->m[ij].y;
		b->mass[i][j][k].m[ij].z=a->m[ij].z;
		b->mass[i][j][k].m[ij].colorR=a->m[ij].colorR;
		b->mass[i][j][k].m[ij].colorG=a->m[ij].colorG;
		b->mass[i][j][k].m[ij].colorB=a->m[ij].colorB;
		b->mass[i][j][k].m[ij].texture_x=a->m[ij].texture_x;
		b->mass[i][j][k].m[ij].texture_y=a->m[ij].texture_y;
	}
}

//Функция изменения координат куба
void change_cube(cube_t *cub,float delX, float delY, float delZ){
int i;
	for (i=0;i<36;i++){
	cub->m[i].x+=delX;cub->m[i].y+=delY;cub->m[i].z+=delZ;
	}
/*	cub->m[0].x+=delX;cub->m[0].y+=delY;cub->m[0].z+=delZ;
	cub->m[1].x+=delX;cub->m[1].y+=delY;cub->m[1].z+=delZ;
	cub->m[2].x+=delX;cub->m[2].y+=delY;cub->m[2].z+=delZ;
	cub->m[3].x+=delX;cub->m[3].y+=delY;cub->m[3].z+=delZ;
	cub->m[4].x+=delX;cub->m[4].y+=delY;cub->m[4].z+=delZ;
	cub->m[5].x+=delX;cub->m[5].y+=delY;cub->m[5].z+=delZ;
	cub->m[6].x+=delX;cub->m[6].y+=delY;cub->m[6].z+=delZ;
	cub->m[7].x+=delX;cub->m[7].y+=delY;cub->m[7].z+=delZ;
	cub->m[8].x+=delX;cub->m[8].y+=delY;cub->m[8].z+=delZ;
	cub->m[9].x+=delX;cub->m[9].y+=delY;cub->m[9].z+=delZ;
	cub->m[10].x+=delX;cub->m[10].y+=delY;cub->m[10].z+=delZ;
	cub->m[11].x+=delX;cub->m[11].y+=delY;cub->m[11].z+=delZ;
	cub->m[12].x+=delX;cub->m[12].y+=delY;cub->m[12].z+=delZ;
	cub->m[13].x+=delX;cub->m[13].y+=delY;cub->m[13].z+=delZ;
	
	printf("%0.0f %0.0f %0.0f\n",cub->m[0].x,cub->m[0].y,cub->m[0].z);
	printf("%0.0f %0.0f %0.0f\n",cub->m[1].x,cub->m[1].y,cub->m[1].z);
	printf("%0.0f %0.0f %0.0f\n",cub->m[2].x,cub->m[2].y,cub->m[2].z);
	printf("%0.0f %0.0f %0.0f\n",cub->m[3].x,cub->m[3].y,cub->m[3].z);
	printf("%0.0f %0.0f %0.0f\n",cub->m[4].x,cub->m[4].y,cub->m[4].z);
	printf("%0.0f %0.0f %0.0f\n",cub->m[5].x,cub->m[5].y,cub->m[5].z);
	printf("%0.0f %0.0f %0.0f\n",cub->m[6].x,cub->m[6].y,cub->m[6].z);
	printf("%0.0f %0.0f %0.0f\n",cub->m[7].x,cub->m[7].y,cub->m[7].z);
	printf("%0.0f %0.0f %0.0f\n",cub->m[8].x,cub->m[8].y,cub->m[8].z);
	printf("%0.0f %0.0f %0.0f\n",cub->m[9].x,cub->m[9].y,cub->m[9].z);
	printf("%0.0f %0.0f %0.0f\n",cub->m[10].x,cub->m[10].y,cub->m[10].z);
	printf("%0.0f %0.0f %0.0f\n",cub->m[11].x,cub->m[11].y,cub->m[11].z);
	printf("%0.0f %0.0f %0.0f\n",cub->m[12].x,cub->m[12].y,cub->m[12].z);
	printf("%0.0f %0.0f %0.0f\n",cub->m[13].x,cub->m[13].y,cub->m[13].z);
	printf("----------------------------------\n");
*/
}
void black_init(black_t *clr){
	clr->t[0].texture_x=0.25;clr->t[0].texture_y=0.5;
	clr->t[1].texture_x=0.0;clr->t[1].texture_y=0.5;
	clr->t[2].texture_x=0.0;clr->t[2].texture_y=0.0;
	clr->t[3].texture_x=0.25;clr->t[3].texture_y=0.5;
	clr->t[4].texture_x=0.0;clr->t[4].texture_y=0.0;
	clr->t[5].texture_x=0.25;clr->t[5].texture_y=0.0;
}
void black(cubik_t *b,black_t *clr,int min,int max,int ii,int jj,int kk){
int i,k;
k=0;
black_init(clr);
	for (i=min;i<=max;i++){
	b->mass[ii][jj][kk].m[i].texture_x=clr->t[k].texture_x;
	b->mass[ii][jj][kk].m[i].texture_y=clr->t[k].texture_y;
	k++;
	}
}
//Заполнение массива
void ttt(cubik_t *b,cube_t *a,black_t *clr){
int i,j;
	cube_init(a);
	change_cube(a,-2.0,2.0,2.0);
	mass_enter(b,a,0,0,0);
	cube_init(a);
	change_cube(a,0.0,2.0,2.0);
	mass_enter(b,a,0,0,1);
	cube_init(a);
	change_cube(a,2.0,2.0,2.0);
	mass_enter(b,a,0,0,2);
	cube_init(a);
	change_cube(a,-2.0,0.0,2.0);
	mass_enter(b,a,0,1,0);
	cube_init(a);
	change_cube(a,0.0,0.0,2.0);
	mass_enter(b,a,0,1,1);
	cube_init(a);
	change_cube(a,2.0,0.0,2.0);
	mass_enter(b,a,0,1,2);
	cube_init(a);
	change_cube(a,-2.0,-2.0,2.0);
	mass_enter(b,a,0,2,0);
	cube_init(a);
	change_cube(a,0.0,-2.0,2.0);
	mass_enter(b,a,0,2,1);
	cube_init(a);
	change_cube(a,2.0,-2.0,2.0);
	mass_enter(b,a,0,2,2);
		cube_init(a);
		change_cube(a,-2.0,2.0,0.0);
		mass_enter(b,a,1,0,0);
		cube_init(a);
		change_cube(a,0.0,2.0,0.0);
		mass_enter(b,a,1,0,1);
		cube_init(a);
		change_cube(a,2.0,2.0,0.0);
		mass_enter(b,a,1,0,2);
		cube_init(a);
		change_cube(a,-2.0,0.0,0.0);
		mass_enter(b,a,1,1,0);
		cube_init(a);
		change_cube(a,0.0,0.0,0.0);
		mass_enter(b,a,1,1,1);
		cube_init(a);
		change_cube(a,2.0,0.0,0.0);
		mass_enter(b,a,1,1,2);
		cube_init(a);
		change_cube(a,-2.0,-2.0,0.0);
		mass_enter(b,a,1,2,0);
		cube_init(a);
		change_cube(a,0.0,-2.0,0.0);
		mass_enter(b,a,1,2,1);
		cube_init(a);
		change_cube(a,2.0,-2.0,0.0);
		mass_enter(b,a,1,2,2);
			cube_init(a);
			change_cube(a,-2.0,2.0,-2.0);
			mass_enter(b,a,2,0,0);
			cube_init(a);
			change_cube(a,0.0,2.0,-2.0);
			mass_enter(b,a,2,0,1);
			cube_init(a);
			change_cube(a,2.0,2.0,-2.0);
			mass_enter(b,a,2,0,2);
			cube_init(a);
			change_cube(a,-2.0,0.0,-2.0);
			mass_enter(b,a,2,1,0);
			cube_init(a);
			change_cube(a,0.0,0.0,-2.0);
			mass_enter(b,a,2,1,1);
			cube_init(a);
			change_cube(a,2.0,0.0,-2.0);
			mass_enter(b,a,2,1,2);
			cube_init(a);
			change_cube(a,-2.0,-2.0,-2.0);
			mass_enter(b,a,2,2,0);
			cube_init(a);
			change_cube(a,0.0,-2.0,-2.0);
			mass_enter(b,a,2,2,1);
			cube_init(a);
			change_cube(a,2.0,-2.0,-2.0);
			mass_enter(b,a,2,2,2);
//Заливка черным цветом отдельных граней
	for (i=0;i<3;i++){
		for (j=0;j<3;j++){
		black(b,clr,18,23,0,i,j);
		black(b,clr,18,23,1,i,j);
		black(b,clr,6,11,1,i,j);
		black(b,clr,6,11,2,i,j);
		black(b,clr,0,5,i,0,j);
		black(b,clr,0,5,i,1,j);
		black(b,clr,12,17,i,1,j);
		black(b,clr,12,17,i,2,j);
		black(b,clr,24,29,i,j,0);
		black(b,clr,24,29,i,j,1);
		black(b,clr,30,35,i,j,1);
		black(b,clr,30,35,i,j,2);
		}
	}
}
//Функция поворота граней
//==========================================================================
void ROTATE(cubik_t *b){
int i,j,n;
rglMatrixIdentity4f(mvm);
if (flag==1){
	rglRotatef(mvm,SPEED, 0.0, 0.0, 1.0);
	for (i=0;i<3;i++){
		for (j=0;j<3;j++){
			for (n=0;n<36;n++){
			rglVectorInit3f(&v,b->mass[0][i][j].m[n].x,b->mass[0][i][j].m[n].y,b->mass[0][i][j].m[n].z);
			rglMatrix4fMulVector3f(mvm,&v);
			b->mass[0][i][j].m[n].x=v.x;
			b->mass[0][i][j].m[n].y=v.y;
			b->mass[0][i][j].m[n].z=v.z;
			}
		}
	}
//printf("%0.6f %0.6f %0.6f\n",b->mass[0][0][0].m[0].x,b->mass[0][0][0].m[0].y,b->mass[0][0][0].m[0].z);
}

if (flag_FR==1){
	rglRotatef(mvm,-SPEED, 0.0, 0.0, 1.0);
	for (i=0;i<3;i++){
		for (j=0;j<3;j++){
			for (n=0;n<36;n++){
			rglVectorInit3f(&v,b->mass[0][i][j].m[n].x,b->mass[0][i][j].m[n].y,b->mass[0][i][j].m[n].z);
			rglMatrix4fMulVector3f(mvm,&v);
			b->mass[0][i][j].m[n].x=v.x;
			b->mass[0][i][j].m[n].y=v.y;
			b->mass[0][i][j].m[n].z=v.z;
			}
		}
	}
}

if (flag_BL==1){
	rglRotatef(mvm,SPEED, 0.0, 0.0, 1.0);
	for (i=0;i<3;i++){
		for (j=0;j<3;j++){
			for (n=0;n<36;n++){
			rglVectorInit3f(&v,b->mass[2][i][j].m[n].x,b->mass[2][i][j].m[n].y,b->mass[2][i][j].m[n].z);
			rglMatrix4fMulVector3f(mvm,&v);
			b->mass[2][i][j].m[n].x=v.x;
			b->mass[2][i][j].m[n].y=v.y;
			b->mass[2][i][j].m[n].z=v.z;
			}
		}
	}
}

if (flag_BR==1){
	rglRotatef(mvm,-SPEED, 0.0, 0.0, 1.0);
	for (i=0;i<3;i++){
		for (j=0;j<3;j++){
			for (n=0;n<36;n++){
			rglVectorInit3f(&v,b->mass[2][i][j].m[n].x,b->mass[2][i][j].m[n].y,b->mass[2][i][j].m[n].z);
			rglMatrix4fMulVector3f(mvm,&v);
			b->mass[2][i][j].m[n].x=v.x;
			b->mass[2][i][j].m[n].y=v.y;
			b->mass[2][i][j].m[n].z=v.z;
			}
		}
	}
}

if (flag_UL==1){
	rglRotatef(mvm,-SPEED, 0.0, 1.0, 0.0);
	for (i=0;i<3;i++){
		for (j=0;j<3;j++){
			for (n=0;n<36;n++){
			rglVectorInit3f(&v,b->mass[i][0][j].m[n].x,b->mass[i][0][j].m[n].y,b->mass[i][0][j].m[n].z);
			rglMatrix4fMulVector3f(mvm,&v);
			b->mass[i][0][j].m[n].x=v.x;
			b->mass[i][0][j].m[n].y=v.y;
			b->mass[i][0][j].m[n].z=v.z;
			}
		}
	}
}

if (flag_UR==1){
	rglRotatef(mvm,SPEED, 0.0, 1.0, 0.0);
	for (i=0;i<3;i++){
		for (j=0;j<3;j++){
			for (n=0;n<36;n++){
			rglVectorInit3f(&v,b->mass[i][0][j].m[n].x,b->mass[i][0][j].m[n].y,b->mass[i][0][j].m[n].z);
			rglMatrix4fMulVector3f(mvm,&v);
			b->mass[i][0][j].m[n].x=v.x;
			b->mass[i][0][j].m[n].y=v.y;
			b->mass[i][0][j].m[n].z=v.z;
			}
		}
	}
}

if (flag_DL==1){
	rglRotatef(mvm,-SPEED, 0.0, 1.0, 0.0);
	for (i=0;i<3;i++){
		for (j=0;j<3;j++){
			for (n=0;n<36;n++){
			rglVectorInit3f(&v,b->mass[i][2][j].m[n].x,b->mass[i][2][j].m[n].y,b->mass[i][2][j].m[n].z);
			rglMatrix4fMulVector3f(mvm,&v);
			b->mass[i][2][j].m[n].x=v.x;
			b->mass[i][2][j].m[n].y=v.y;
			b->mass[i][2][j].m[n].z=v.z;
			}
		}
	}
}

if (flag_DR==1){
	rglRotatef(mvm,SPEED, 0.0, 1.0, 0.0);
	for (i=0;i<3;i++){
		for (j=0;j<3;j++){
			for (n=0;n<36;n++){
			rglVectorInit3f(&v,b->mass[i][2][j].m[n].x,b->mass[i][2][j].m[n].y,b->mass[i][2][j].m[n].z);
			rglMatrix4fMulVector3f(mvm,&v);
			b->mass[i][2][j].m[n].x=v.x;
			b->mass[i][2][j].m[n].y=v.y;
			b->mass[i][2][j].m[n].z=v.z;
			}
		}
	}
}

if (flag_RL==1){
	rglRotatef(mvm,SPEED, 1.0, 0.0, 0.0);
	for (i=0;i<3;i++){
		for (j=0;j<3;j++){
			for (n=0;n<36;n++){
			rglVectorInit3f(&v,b->mass[i][j][2].m[n].x,b->mass[i][j][2].m[n].y,b->mass[i][j][2].m[n].z);
			rglMatrix4fMulVector3f(mvm,&v);
			b->mass[i][j][2].m[n].x=v.x;
			b->mass[i][j][2].m[n].y=v.y;
			b->mass[i][j][2].m[n].z=v.z;
			}
		}
	}
}

if (flag_RR==1){
	rglRotatef(mvm,-SPEED, 1.0, 0.0, 0.0);
	for (i=0;i<3;i++){
		for (j=0;j<3;j++){
			for (n=0;n<36;n++){
			rglVectorInit3f(&v,b->mass[i][j][2].m[n].x,b->mass[i][j][2].m[n].y,b->mass[i][j][2].m[n].z);
			rglMatrix4fMulVector3f(mvm,&v);
			b->mass[i][j][2].m[n].x=v.x;
			b->mass[i][j][2].m[n].y=v.y;
			b->mass[i][j][2].m[n].z=v.z;
			}
		}
	}
}

if (flag_LL==1){
	rglRotatef(mvm,-SPEED, 1.0, 0.0, 0.0);
	for (i=0;i<3;i++){
		for (j=0;j<3;j++){
			for (n=0;n<36;n++){
			rglVectorInit3f(&v,b->mass[i][j][0].m[n].x,b->mass[i][j][0].m[n].y,b->mass[i][j][0].m[n].z);
			rglMatrix4fMulVector3f(mvm,&v);
			b->mass[i][j][0].m[n].x=v.x;
			b->mass[i][j][0].m[n].y=v.y;
			b->mass[i][j][0].m[n].z=v.z;
			}
		}
	}
}

if (flag_LR==1){
	rglRotatef(mvm,SPEED, 1.0, 0.0, 0.0);
	for (i=0;i<3;i++){
		for (j=0;j<3;j++){
			for (n=0;n<36;n++){
			rglVectorInit3f(&v,b->mass[i][j][0].m[n].x,b->mass[i][j][0].m[n].y,b->mass[i][j][0].m[n].z);
			rglMatrix4fMulVector3f(mvm,&v);
			b->mass[i][j][0].m[n].x=v.x;
			b->mass[i][j][0].m[n].y=v.y;
			b->mass[i][j][0].m[n].z=v.z;
			}
		}
	}
}
//rglVector3Print( v, "vector");
}
//==========================================================================
void ogl_init(void)
{
	glClearColor(0.0,0.0,0.0,1.0);
	glClearDepth(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-12.0,12.0,-9.0,9.0,-10.0,10.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);//GL_LINE, GL_FILL, GL_POINT
	glShadeModel(GL_FLAT);//Однородный цвет - GL_FLAT, градиент - GL_SMOOTH 
	glEnable(GL_DEPTH_TEST);
		
	vector_init();
	ttt(&b,&a,&clr);//Заполнение массива
	//cube_init(&a);
	rglLoadTextures(txtrs,&txtrs_1);
	rglLoadTextures(stl,&stl_1);
	rglLoadTextures(nch,&nch_1);
	rglLoadTextures(help,&help_1);
	rglLoadTextures(exit1,&exit_1);
	rglLoadTextures(name,&name_1);
	rglLoadTextures(nch_bb,&nch_b);
	rglLoadTextures(help_bb,&help_b);
	rglLoadTextures(exit_bb,&exit_b);
	rglLoadTextures(h,&h_1);
	rglLoadTextures(help_2,&help_22);
}

//функция отрисовки куба через массив 3х3х3
void draw_cube_array(cubik_t *b){
int i,j,jj,jjj;
	glLineWidth(1.0);
	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,txtrs_1);
	for (j=0;j<3;j++){
		for (jj=0;jj<3;jj++){
			for (jjj=0;jjj<3;jjj++){
			glBegin(GL_TRIANGLES);
				for (i=0;i<36;i++){	
					glColor3f(b->mass[j][jj][jjj].m[i].colorR,b->mass[j][jj][jjj].m[i].colorG,b->mass[j][jj][jjj].m[i].colorB);
					glTexCoord2f(b->mass[j][jj][jjj].m[i].texture_x,b->mass[j][jj][jjj].m[i].texture_y);
					glVertex3f(b->mass[j][jj][jjj].m[i].x,b->mass[j][jj][jjj].m[i].y,b->mass[j][jj][jjj].m[i].z);
				}
			glEnd();	
			}
		}
	}
	glDisable(GL_TEXTURE_2D);
/*	
	glBegin(GL_LINES);
	glColor3f(1.0,0.0,0.5);
	glVertex3f(0.0,0.0,0.0);
	glVertex3f(vf.x,vf.y,vf.z);
	glColor3f(0.0,1.0,0.5);
	glVertex3f(0.0,0.0,0.0);
	glVertex3f(vb.x,vb.y,vb.z);
	glColor3f(0.5,1.0,1.0);
	glVertex3f(0.0,0.0,0.0);
	glVertex3f(vr.x,vr.y,vr.z);
	glColor3f(1.0,0.5,0.0);
	glVertex3f(0.0,0.0,0.0);
	glVertex3f(vl.x,vl.y,vl.z);
	glColor3f(1.0,1.0,0.0);
	glVertex3f(0.0,0.0,0.0);
	glVertex3f(vu.x,vu.y,vu.z);
	glColor3f(0.0,0.5,0.5);
	glVertex3f(0.0,0.0,0.0);
	glVertex3f(vd.x,vd.y,vd.z);
	glEnd();*/
}
void hhh(){
glLineWidth(1.0);
glEnable(GL_LINE_SMOOTH);
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D,h_1);
		glBegin(GL_TRIANGLES);
		glTexCoord2f(1.0,1.0);
		glVertex3f(-7.5,9.0,-5.0);
		glTexCoord2f(0.0,1.0);
		glVertex3f(-12.0,9.0,-5.0);
		glTexCoord2f(0.0,0.0);
		glVertex3f(-12.0,-9.0,-5.0);
		glTexCoord2f(1.0,1.0);
		glVertex3f(-7.5,9.0,-5.0);
		glTexCoord2f(0.0,0.0);
		glVertex3f(-12.0,-9.0,-5.0);
		glTexCoord2f(1.0,0.0);
		glVertex3f(-7.5,-9.0,-5.0);
		glEnd();
glBindTexture(GL_TEXTURE_2D,stl_1);
		glBegin(GL_TRIANGLES);
		glTexCoord2f(1.0,1.0);
		glVertex3f(12.0,12.0,-5.0);
		glTexCoord2f(0.0,1.0);
		glVertex3f(-12.0,12.0,-5.0);
		glTexCoord2f(0.0,0.0);
		glVertex3f(-12.0,-12.0,-5.0);
		glTexCoord2f(1.0,1.0);
		glVertex3f(12.0,12.0,-5.0);
		glTexCoord2f(0.0,0.0);
		glVertex3f(-12.0,-12.0,-5.0);
		glTexCoord2f(1.0,0.0);
		glVertex3f(12.0,-12.0,-5.0);
		glEnd();
}
//Функция отрисовки "единичного" куба
void cub(cube_t *a){
int i;
	glLineWidth(1.0);
	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,txtrs_1);
			glBegin(GL_TRIANGLES);
				for (i=0;i<36;i++){	
					glColor3f(a->m[i].colorR,a->m[i].colorG,a->m[i].colorB);
					glTexCoord2f(a->m[i].texture_x,a->m[i].texture_y);
					glVertex3f(a->m[i].x,a->m[i].y,a->m[i].z);
				}
			glEnd();
}
void cubecube(GLint size){
 glBegin(GL_QUADS);
      // Front Face
	glNormal3f( 0.0, 0.0, -1.0);
      glTexCoord2f(0.0, 0.0); glVertex3f(-1.0*size, -1.0*size,  1.0*size);
      glTexCoord2f(1.0, 0.0); glVertex3f( 1.0*size, -1.0*size,  1.0*size);
      glTexCoord2f(1.0, 1.0); glVertex3f( 1.0*size,  1.0*size,  1.0*size);
      glTexCoord2f(0.0, 1.0); glVertex3f(-1.0*size,  1.0*size,  1.0*size);
      // Back Face
	glNormal3f( 0.0, 0.0, 1.0);
      glTexCoord2f(1.0, 0.0); glVertex3f(-1.0*size, -1.0*size, -1.0*size);
      glTexCoord2f(1.0, 1.0); glVertex3f(-1.0*size,  1.0*size, -1.0*size);
      glTexCoord2f(0.0, 1.0); glVertex3f( 1.0*size,  1.0*size, -1.0*size);
      glTexCoord2f(0.0, 0.0); glVertex3f( 1.0*size, -1.0*size, -1.0*size);
      // Top Face
	glNormal3f( 0.0, -1.0, 0.0);
      glTexCoord2f(0.0, 1.0); glVertex3f(-1.0*size,  1.0*size, -1.0*size);
      glTexCoord2f(0.0, 0.0); glVertex3f(-1.0*size,  1.0*size,  1.0*size);
      glTexCoord2f(1.0, 0.0); glVertex3f( 1.0*size,  1.0*size,  1.0*size);
      glTexCoord2f(1.0, 1.0); glVertex3f( 1.0*size,  1.0*size, -1.0*size);
      // Bottom Face
	glNormal3f( 0.0, 1.0, 0.0);
      glTexCoord2f(1.0, 1.0); glVertex3f(-1.0*size, -1.0*size, -1.0*size);
      glTexCoord2f(0.0, 1.0); glVertex3f( 1.0*size, -1.0*size, -1.0*size);
      glTexCoord2f(0.0, 0.0); glVertex3f( 1.0*size, -1.0*size,  1.0*size);
      glTexCoord2f(1.0, 0.0); glVertex3f(-1.0*size, -1.0*size,  1.0*size);
      // Right face
	glNormal3f(-1.0, 0.0, 0.0);
      glTexCoord2f(1.0, 0.0); glVertex3f( 1.0*size, -1.0*size, -1.0*size);
      glTexCoord2f(1.0, 1.0); glVertex3f( 1.0*size,  1.0*size, -1.0*size);
      glTexCoord2f(0.0, 1.0); glVertex3f( 1.0*size,  1.0*size,  1.0*size);
      glTexCoord2f(0.0, 0.0); glVertex3f( 1.0*size, -1.0*size,  1.0*size);
      // Left Face
	glNormal3f( 1.0, 0.0, 0.0);
      glTexCoord2f(0.0, 0.0); glVertex3f(-1.0*size, -1.0*size, -1.0*size);
      glTexCoord2f(1.0, 0.0); glVertex3f(-1.0*size, -1.0*size,  1.0*size);
      glTexCoord2f(1.0, 1.0); glVertex3f(-1.0*size,  1.0*size,  1.0*size);
      glTexCoord2f(0.0, 1.0); glVertex3f(-1.0*size,  1.0*size, -1.0*size);
    glEnd();
}
void draw_help(){
	glLineWidth(1.0);
	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	//glBlendFunc(GL_ONE,GL_ONE_MINUS_SRC_ALPHA);
	glBlendFunc(GL_SRC_COLOR,GL_ONE_MINUS_SRC_ALPHA);//27
	//glBlendFunc(GL_ONE_MINUS_DST_COLOR,GL_ONE_MINUS_SRC_ALPHA);//57
	//glBlendFunc(GL_DST_ALPHA,GL_ONE_MINUS_SRC_ALPHA); //87
	glBindTexture(GL_TEXTURE_2D,help_22);
		glBegin(GL_TRIANGLES);
		glTexCoord2f(1.0,1.0);
		glVertex3f(8.0,8.0,2.2);
		glTexCoord2f(0.0,1.0);
		glVertex3f(-8.0,8.0,2.2);
		glTexCoord2f(0.0,0.0);
		glVertex3f(-8.0,-8.0,2.2);
		glTexCoord2f(1.0,1.0);
		glVertex3f(8.0,8.0,2.2);
		glTexCoord2f(0.0,0.0);
		glVertex3f(-8.0,-8.0,2.2);
		glTexCoord2f(1.0,0.0);
		glVertex3f(8.0,-8.0,2.2);
		glEnd();
	glDisable(GL_BLEND);
}
void button(){
int y;
y=-2.0;
	glLineWidth(1.0);
	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_ONE,GL_ONE_MINUS_SRC_ALPHA); //17
	//glBlendFunc(GL_SRC_COLOR,GL_ONE_MINUS_SRC_ALPHA);//27
	//glBlendFunc(GL_ONE_MINUS_DST_COLOR,GL_ONE_MINUS_SRC_ALPHA)//57
	//glBlendFunc(GL_DST_ALPHA,GL_ONE_MINUS_SRC_ALPHA); //87
	if (button_1==0){
	glBindTexture(GL_TEXTURE_2D,nch_1);}else{glBindTexture(GL_TEXTURE_2D,nch_b);}
		glBegin(GL_TRIANGLES);
		glTexCoord2f(1.0,1.0);
		glVertex3f(3.0,0.0,2.1);
		glTexCoord2f(0.0,1.0);
		glVertex3f(-3.0,0.0,2.1);
		glTexCoord2f(0.0,0.0);
		glVertex3f(-3.0,-1.5,2.1);
		glTexCoord2f(1.0,1.0);
		glVertex3f(3.0,0.0,2.1);
		glTexCoord2f(0.0,0.0);
		glVertex3f(-3.0,-1.5,2.1);
		glTexCoord2f(1.0,0.0);
		glVertex3f(3.0,-1.5,2.1);
		glEnd();
	if (button_2==0){
	glBindTexture(GL_TEXTURE_2D,help_1);}else{glBindTexture(GL_TEXTURE_2D,help_b);}
		glBegin(GL_TRIANGLES);
		glTexCoord2f(1.0,1.0);
		glVertex3f(3.0,0.0+y,2.1);
		glTexCoord2f(0.0,1.0);
		glVertex3f(-3.0,0.0+y,2.1);
		glTexCoord2f(0.0,0.0);
		glVertex3f(-3.0,-1.5+y,2.1);
		glTexCoord2f(1.0,1.0);
		glVertex3f(3.0,0.0+y,2.1);
		glTexCoord2f(0.0,0.0);
		glVertex3f(-3.0,-1.5+y,2.1);
		glTexCoord2f(1.0,0.0);
		glVertex3f(3.0,-1.5+y,2.1);
		glEnd();	
	if (button_3==0){
	glBindTexture(GL_TEXTURE_2D,exit_1);}else{glBindTexture(GL_TEXTURE_2D,exit_b);}
		glBegin(GL_TRIANGLES);
		glTexCoord2f(1.0,1.0);
		glVertex3f(3.0,0.0+2*y,2.1);
		glTexCoord2f(0.0,1.0);
		glVertex3f(-3.0,0.0+2*y,2.1);
		glTexCoord2f(0.0,0.0);
		glVertex3f(-3.0,-1.5+2*y,2.1);
		glTexCoord2f(1.0,1.0);
		glVertex3f(3.0,0.0+2*y,2.1);
		glTexCoord2f(0.0,0.0);
		glVertex3f(-3.0,-1.5+2*y,2.1);
		glTexCoord2f(1.0,0.0);
		glVertex3f(3.0,-1.5+2*y,2.1);
		glEnd();	
	glBindTexture(GL_TEXTURE_2D,name_1);
		glBegin(GL_TRIANGLES);
		glTexCoord2f(1.0,1.0);
		glVertex3f(8.0,8.0,2.1);
		glTexCoord2f(0.0,1.0);
		glVertex3f(-8.0,8.0,2.1);
		glTexCoord2f(0.0,0.0);
		glVertex3f(-8.0,4.0,2.1);
		glTexCoord2f(1.0,1.0);
		glVertex3f(8.0,8.0,2.1);
		glTexCoord2f(0.0,0.0);
		glVertex3f(-8.0,4.0,2.1);
		glTexCoord2f(1.0,0.0);
		glVertex3f(8.0,4.0,2.1);
		glEnd();
	glDisable(GL_BLEND);
}
void draw_menu(){
	glLineWidth(1.0);
	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,stl_1);
		glBegin(GL_TRIANGLES);
		glTexCoord2f(1.0,1.0);
		glVertex3f(12.0,12.0,2.0);
		glTexCoord2f(0.0,1.0);
		glVertex3f(-12.0,12.0,2.0);
		glTexCoord2f(0.0,0.0);
		glVertex3f(-12.0,-12.0,2.0);
		glTexCoord2f(1.0,1.0);
		glVertex3f(12.0,12.0,2.0);
		glTexCoord2f(0.0,0.0);
		glVertex3f(-12.0,-12.0,2.0);
		glTexCoord2f(1.0,0.0);
		glVertex3f(12.0,-12.0,2.0);
		glEnd();
	if (draw_scena_help==0){
	button();
	}
	else{
	draw_help();}
}

void ogl_draw()//draw_basis();cub(cube_t *a);draw_cube_array(cubik_t *b);
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	if (draw_scena==0){
	draw_menu();
	}
	if (draw_scena==1){
	hhh();
	rglMatrixIdentity4f(mvm2);
	rglRotatef(mvm2,rax,1.0,0.0,0.0);
	rglRotatef(mvm2,raz,0.0,0.0,1.0);
	rglRotatef(mvm2,ray,0.0,1.0,0.0);
	glLoadMatrixf(mvm2);
	//cubecube(2);
	draw_cube_array(&b);
	ROTATE(&b);}
}
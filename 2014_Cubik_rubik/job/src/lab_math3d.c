#include "lab_math3d.h" 

rglMat4 m_identity4={1.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0};
//rglMat3 m_identity3={1.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,1.0};

//vector operation vec2-------------------------------------------------------------------------------------------------------------------

//vector operation vec3-------------------------------------------------------------------------------------------------------------------
//инициализация 3-х вектора

rglVec3 rglVector3Setf(GLfloat x, GLfloat y, GLfloat z)
{
	 rglVec3 v={x,y,z};
	return v;
}
//сумма векторов
rglVec3 rglVector3Add( rglVec3 v1, rglVec3 v2)
{
	rglVec3 v={v1.x+v2.x, v1.y+v2.y,  v1.z+v2.z};
   return v;
}
//разность векторов
rglVec3 rglVector3Sub( rglVec3 v1, rglVec3 v2)
{
  rglVec3 v ={v1.x-v2.x, v1.y-v2.y, v1.z-v2.z};
   return v;
}
//масштабирование векторов(умножение на скаляр)
rglVec3 rglVector3Scale(rglVec3 v, GLfloat scale )
{
 	rglVec3 v1={ v.x*scale, v.y*scale,  v.z*scale};
    return v1;
}
//длина вектора
GLfloat rglVector3Length(rglVec3 v)
{
    return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}
//обнуление вектора
GLint rglVector3Clear(rglVec3 *v)
{
	v->x=v->y=v->z=0.0;
	return 1;
}
//копирование векторов
GLint rglVector3Copy( rglVec3 *dest, rglVec3 src)
{
 // dest.x = src.x; dest.y = src.y; dest.z = src.z;
	memcpy(dest, &src,sizeof(rglVec3)); 
	return 1;
}
//Векторное произведение (cross product) двух векторов.
rglVec3 rglVector3Cross(rglVec3 v1, rglVec3 v2)
{
   rglVec3 v={
   v1.y * v2.z - v1.z * v2.y,
   v1.z * v2.x - v1.x * v2.z,
   v1.x * v2.y - v1.y * v2.x};
    return v;
}	
//нормализация вектора
rglVec3 rglVector3Normalize(rglVec3 v1)
{
   GLfloat length,ilength;
    rglVec3 v;  
	length=rglVector3Length(v1);
	
    if(length == 0) {
        rglVector3Clear(&v);
        return v;
    }
	else
	{
    ilength = 1.0 / length;	
    v=rglVector3Scale(v1,ilength);
    return v;
	}
}

//вывод на экран значений вектора
GLint rglVector3Print(rglVec3 v, const char * header)
{   
	if (header!=NULL)
		printf("%s:\n",header);
	printf("v.x = %5.2f , v.y = %5.2f, v.z = %5.2f\n", v.x, v.y,v.z);
    return 1;
}


//vector operation vec4------------------------------------------------------------------------------------------------------------------

//-------------------------------------------MATRIX OPERATION----------------------------------------------------------------------------

//--------------------------------MATRIX2-----------------------------------------------------------------------------------------------------

//--------------------------------MATRIX3-----------------------------------------------------------------------------------------------------

//--------------------------------MATRIX4-----------------------------------------------------------------------------------------------------

//инициализация единичной 4-х матрицы
GLint rglMatrix4Identity(rglMat4 dest)
{		
	memcpy(dest, m_identity4,sizeof(dest)*16); 	
	return 1;
}

//копирование матрицы
GLint rglMatrix4Copy(rglMat4 dest, rglMat4 src) 
{
	memcpy(dest, src,sizeof(dest)*16);										
   return 1;
}
//произведение матриц
GLint rglMatrix4Multiply(rglMat4 m1, rglMat4 m2)
{
	rglMat4 dest={0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0};
	GLint n,i;	
     for(n=0;n<16;n+=1){
		 for(i=0;i<4;i+=1){
			dest[n]+=m1[n%4+i*4]*m2[n/4*4+i];
		}
		 if(fabs(dest[n])<1e-6)
			dest[n]=0.0;
	}   	
     rglMatrix4Copy(m1, dest) ;   
    return 1;	
}

rglVec3 rglMatrix4MulVector3(const rglMat4 m, rglVec3 v3)
{   
	rglVec3 v;    
    v.x = v3.x * m[0] + v3.y * m[4] + v3.z * m[8] + m[12];
    v.y = v3.x * m[1] + v3.y * m[5] + v3.z * m[9] + m[13];
    v.z = v3.x * m[2] + v3.y * m[6] + v3.z * m[10] + m[14];
    return v;
}



//выод матрицы
GLint rglMatrix4Print(rglMat4 m,const char * header)
{
	if (header!=NULL)
		printf("%s:\n",header);
	printf("m[0] = %5.6f m[4] = %5.6f m[8] = %5.6f m[12] = %5.6f\n", m[0],m[4],m[8],m[12]);
	printf("m[1] = %5.6f m[5] = %5.6f m[9] = %5.6f m[13] = %5.6f\n", m[1],m[5],m[9],m[13]);
	printf("m[2] = %5.6f m[6] = %5.6f m[10] = %5.6f m[14] = %5.6f\n", m[2],m[6],m[10],m[14]);
	printf("m[3] = %5.6f m[7] = %5.6f m[11] = %5.6f m[15] = %5.6f\n", m[3],m[7],m[11],m[15]);
	printf("--------------------------------------------------------------------------------------------------\n");
	return 1;
}
//--------------------------------OPENGL MATRIX-----------------------------------------------------------------------------------------------------
//матрица перспективной проекции аналог glFrustum
GLint  rglFrustum(rglMat4 dest,GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat zNear, GLfloat zFar)
{	
	
	   dest[0] = (2.0 * zNear / (right - left));
       dest[1] = 0.0;
       dest[2] = 0.0;
       dest[3] = 0.0;

       dest[4] = 0.0;
       dest[5] = (2.0 * zNear / (top - bottom));
       dest[6] = 0.0;
       dest[7] = 0.0;

       dest[8] = ((right + left) / (right - left));
       dest[9] = ((top + bottom) / (top - bottom));
       dest[10] = -((zFar + zNear) / (zFar - zNear));
       dest[11] = -1;

       dest[12] = 0.0;
       dest[13]= 0.0;
       dest[14] = -(2.0 * zFar * zNear / (zFar - zNear));
       dest[15] = 0.0;	
	return 1;
	
}
//матрица перспективной проекции аналог gluPerspective
GLint  rglPerspective(rglMat4 dest,GLfloat fov, GLfloat aspect, GLfloat znear, GLfloat zfar)
{	
	GLint i;
	GLfloat rad = fov * DEG2RAD;
	for (i =0; i<16; i++)
			dest[i]=0.0;			
	dest[0]=1.0/(tan(rad/2.0)*aspect);
	dest[5]=1.0/tan(rad/2.0);
	dest[10]=(znear+zfar)/(znear-zfar);
	dest[11]=-1.0;
	dest[14]=(2.0*znear*zfar)/(znear-zfar);	
	dest[15]=1.0;			
	return 1;
}
//матрица ортографичекой проекции аналог glOrtho
GLint rglOrtho(rglMat4 dest, GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat znear, GLfloat zfar)
{	
	GLint i;
	for (i =0; i<16; i++)
			dest[i]=0.0;			
	dest[0]=2.0/(right - left);
	dest[5]=2.0/(top - bottom);
	dest[10]=-2.0/(zfar - znear);
	dest[12]=-(right + left)/(right - left);
	dest[13]=-(top+bottom)/(top - bottom);	
	dest[14]=-(zfar + znear)/(zfar - znear);	
	dest[15]=1.0;		
	return 1;
}
//матрица афинных преобразований - перемещение
GLint rglTranslate(rglMat4 dest, GLfloat x, GLfloat y, GLfloat z)
{
	rglMat4 m;
	rglMatrix4Identity(m);
	m[12]+=x;
	m[13]+=y;
	m[14]+=z;
	
	rglMatrix4Multiply(dest,m);	
	return 1;	
}
//матрица афинных преобразований - масштабирование
GLint rglScale(rglMat4 dest, GLfloat x, GLfloat y, GLfloat z)
{
	rglMat4 m;
	rglMatrix4Identity(m);
	m[0]=x;
	m[5]=y;
	m[10]=z;	
	rglMatrix4Multiply(dest,m);		
	return 1;		
}
//матрица афинных преобразований - поворот
GLint rglRotate( rglMat4 dest, GLfloat angle, GLfloat x, GLfloat y, GLfloat z)
{
    GLfloat rad = angle * DEG2RAD;
    GLfloat cosA = cos(rad);
    GLfloat sinA = sin(rad);
   
	rglMat4 m;
	rglMatrix4Identity(m);
    GLfloat ux =x;
	GLfloat uy = y;
	GLfloat uz = z;
	
	 double l = sqrt(ux*ux +uy*uy + uz*uz);
     if (l != 1.0) 
	 	{ 
		 ux /= l; uy /= l; uz /= l; 
		 }	    
	m[0]  = (1-cosA) * (ux*ux) + cosA ;
	m[1]  = (1-cosA) * (ux*uy) + (sinA*uz);
	m[2]  = (1-cosA) * (ux*uz) - (sinA*uy);		
	m[4]  = (1-cosA) * (ux*uy) - (sinA*uz);
	m[5]  = (1-cosA) * (uy*uy) + cosA;
	m[6]  = (1-cosA) * (uy*uz) + (sinA*ux);		
	m[8]  = (1-cosA) * (ux*uz) + (sinA*uy);
	m[9]  = (1-cosA) * (uy*uz) - (sinA*ux);
	m[10] = (1-cosA) * (uz*uz)+ cosA;
	
	rglMatrix4Multiply(dest,m);
	return 1;
	
}
//матрица просмотра(видовая матрица) аналог gluLookAT
GLint rglLookAt(rglMat4 dest, rglVec3 v1, rglVec3 v2, rglVec3 v3)
{
	
	rglVec3 f,up,x,y;
	rglMat4 m1;
	rglMatrix4Identity(m1);
    f=rglVector3Sub(v2,v1);
    f=rglVector3Normalize(f);	
	up=rglVector3Normalize(v3);	
    x=rglVector3Cross(f,up);
	x=rglVector3Normalize(x);	
    y= rglVector3Cross(x,f);  
    y=rglVector3Normalize(y);	
    m1[0] = x.x; m1[4] = x.y; m1[8] = x.z; m1[12] = 0.0;
    m1[1] = y.x; m1[5] = y.y; m1[9] = y.z; m1[13] = 0.0;
    m1[2] = -f.x; m1[6] = -f.y; m1[10] = -f.z; m1[14] = 0.0;
    m1[3] = 0.0; m1[7] = 0.0; m1[11] = 0.0; m1[15] = 1.0;
   	rglTranslate(m1,-v1.x,-v1.y,-v1.z);	   	
	rglMatrix4Multiply(dest,m1);
	return 1;
	
}
//вывод матрицы загруженной в память
GLint rglMatrix4MemPrint(GLuint matrix_type, const char * header)
{
	rglMat4 m;
	if (matrix_type==GL_MODELVIEW_MATRIX)
		glGetFloatv(GL_MODELVIEW_MATRIX, m);
	if (matrix_type==GL_PROJECTION_MATRIX)
		glGetFloatv(GL_PROJECTION_MATRIX, m);
	rglMatrix4Print(m,header);
	return 1;
}


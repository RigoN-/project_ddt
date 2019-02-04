/*TODO
 * редизайн названий
 * переписать вектора из массивов под структуры
 * добавить комментарии
 * добавить векторный функционал для Vec2 Vec4
 * добавить новые функции для mat4 
 * добавить новые функции для кватарнионов
 * 
 * 
 * 
 * 
 */
  
#include "rglMath3D.h" 

rglMat4 m_identity4={1.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0};
rglMat3 m_identity3={1.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,1.0};

//vector operation
rglVec2 rglVector2Set(GLfloat x, GLfloat y)
{
	 rglVec2 v={x,y};
	return v;
}

rglTex2 rglTexCoord2Set(GLfloat s, GLfloat t)
{
	 rglTex2 v={s,t};
	return v;
}

rglVec3 rglVector3Set(GLfloat x, GLfloat y, GLfloat z)
{
	 rglVec3 v={x,y,z};
	return v;
}

rglCol3 rglColor3Set(GLfloat r, GLfloat g, GLfloat b)
{
	 rglCol3 v={r,g,b};
	return v;
}
rglTex3 rglTex3Set(GLfloat s, GLfloat t, GLfloat r)
{
	 rglTex3 v={s,t,r};
	return v;
}


 rglVec4 rglVector4Set(GLfloat x, GLfloat y, GLfloat z, GLfloat w)
{
	 rglVec4 v={x,y,z,w};
	return v;
}

rglCol4 rglColor4Set(GLfloat r, GLfloat g, GLfloat b, GLfloat a)
{
	 rglCol4 v={r,g,b,a};
	return v;
}

 rglVec2 rglVec4ToVec2(rglVec4 v1)
{
	 rglVec2 v={v1.x,v1.y};
	return v;
}

 rglVec3 rglVec4ToVec3(rglVec4 v1)
{
	 rglVec3 v={v1.x,v1.y,v1.z};
	return v;
}

rglCol3 rglColor4ToColor3(rglCol4 v1)
{
	 rglCol3 v={v1.r,v1.g,v1.b};
	return v;
}

 rglVec2 rglVec3ToVec2(rglVec3 v1)
{
	 rglVec2 v={v1.x,v1.y};
	return v;
}

rglCol4 rglColor3ToColor4(rglCol3 v1)
{
	 rglCol4 v={v1.r,v1.g,v1.b,1.0};
	return v;
}


GLint rglVector2Clear(rglVec2 v)
{
	v.x=v.y=0.0;
	return 1;
}

GLint rglVector3Clear(rglVec3 v)
{
	v.x=v.y=v.z=0.0;
	return 1;
}

GLint rglVector4Clear(rglVec4 v)
{
	v.x=v.y=v.z=v.w=0.0;
	return 1;
}

GLint rglVector2Copy( rglVec2 v1, rglVec2 v2)
{
  v2.x = v1.x; v2.y = v1.y;
   return 1;
}

GLint rglVector3Copy( rglVec3 v1, rglVec3 v2)
{
  v2.x = v1.x; v2.y = v1.y; v2.z = v1.z;
   return 1;
}

GLint rglVector4Copy( rglVec4 v1, rglVec4 v2)
{
  v2.x = v1.x; v2.y = v1.y; v2.z = v1.z; v2.w = v1.w;
   return 1;
}
//масштабирование векторов
rglVec2 rglVector2Scale(rglVec2 v, GLfloat scale )
{
 	rglVec2 v1={ v.x*scale, v.y*scale};
    return v1;
}

rglVec3 rglVector3Scale(rglVec3 v, GLfloat scale )
{
 	rglVec3 v1={ v.x*scale, v.y*scale,  v.z*scale};
    return v1;
}

rglVec4 rglVector4Scale(rglVec4 v, GLfloat scale )
{
 	rglVec4 v1={ v.x*scale, v.y*scale,  v.z*scale, v.w*scale};
    return v1;
}

//сложение векторов
rglVec2 rglVector2Add( rglVec2 v1, rglVec2 v2)
{
	rglVec2 v={v1.x+v2.x, v1.y+v2.y};
   return v;
}

rglVec3 rglVector3Add( rglVec3 v1, rglVec3 v2)
{
	rglVec3 v={v1.x+v2.x, v1.y+v2.y,  v1.z+v2.z};
   return v;
}

rglVec4 rglVector4Add( rglVec4 v1, rglVec4 v2)
{
	rglVec4 v={v1.x+v2.x, v1.y+v2.y,  v1.z+v2.z, v1.w+v2.w};
   return v;
}

//вычетание векторов
rglVec2 rglVector2Sub( rglVec2 v1, rglVec2 v2)
{
  rglVec2 v ={v1.x-v2.x, v1.y-v2.y};
   return v;
}

rglVec3 rglVector3Sub( rglVec3 v1, rglVec3 v2)
{
  rglVec3 v ={v1.x-v2.x, v1.y-v2.y, v1.z-v2.z};
   return v;
}

rglVec4 rglVector4Sub( rglVec4 v1, rglVec4 v2)
{
  rglVec4 v ={v1.x-v2.x, v1.y-v2.y, v1.z-v2.z, v1.w-v2.w};
   return v;
}

//Скалярное произведение двух векторов(dot product).
GLfloat rglVector2Dot( rglVec2 v1, rglVec2 v2)
{
  return  v1.x*v2.x+ v1.y*v2.y;   
}

GLfloat rglVector3Dot( rglVec3 v1, rglVec3 v2)
{
  return  v1.x*v2.x+ v1.y*v2.y+ v1.z*v2.z;   
}

GLfloat rglVector4Dot( rglVec4 v1, rglVec4 v2)
{
  return  v1.x*v2.x+ v1.y*v2.y+ v1.z*v2.z+ v1.w*v2.w;   
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

//Длина вектора

GLfloat rglVector2Length(rglVec2 v)
{
    return sqrt(v.x * v.x + v.y * v.y );
}

GLfloat rglVector3Length(rglVec3 v)
{
    return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

GLfloat rglVector4Length(rglVec4 v)
{
    return sqrt(v.x * v.x + v.y * v.y + v.z * v.z+v.w * v.w);
}

//нормализация вектора
rglVec2 rglVector2Normalize(rglVec2 v1)
{
   GLfloat length,ilength;
    rglVec2 v;  
	length=rglVector2Length(v1);
    if(length == 0) {
        rglVector2Clear(v);
        return v;
    }
	else
	{
    ilength = 1.0 / length;
    v=rglVector2Scale(v1,ilength);
    return v;
	}
}

rglVec3 rglVector3Normalize(rglVec3 v1)
{
   GLfloat length,ilength;
    rglVec3 v;  
	length=rglVector3Length(v1);
	
    if(length == 0) {
        rglVector3Clear(v);
        return v;
    }
	else
	{
    ilength = 1.0 / length;
	
    v=rglVector3Scale(v1,ilength);
    return v;
	}
}

rglVec4 rglVector4Normalize(rglVec4 v1)
{
   GLfloat length,ilength;
    rglVec4 v;  
	length=rglVector4Length(v1);
    if(length == 0) {
        rglVector4Clear(v);
        return v;
    }
	else
	{
    ilength = 1.0 / length;
    v=rglVector4Scale(v1,ilength);
    return v;
	}
}

//умножение матрицы на вектор 
rglVec2 rglMatrix4MulVector2(const rglMat4 m, rglVec2 v3)
{   
	rglVec2 v;    
    v.x = v3.x * m[0] + v3.y * m[4] + m[8] + m[12];
    v.y = v3.x * m[1] + v3.y * m[5] + m[9] + m[13];   
    return v;
}

rglVec3 rglMatrix4MulVector3(const rglMat4 m, rglVec3 v3)
{   
	rglVec3 v;    
    v.x = v3.x * m[0] + v3.y * m[4] + v3.z * m[8] + m[12];
    v.y = v3.x * m[1] + v3.y * m[5] + v3.z * m[9] + m[13];
    v.z = v3.x * m[2] + v3.y * m[6] + v3.z * m[10] + m[14];
    return v;
}

rglVec4 rglMatrix4MulVector4(const rglMat4 m, rglVec4 v3)
{   
	rglVec4 v;    
    v.x = v3.x * m[0] + v3.y * m[4] + v3.z * m[8] + v3.w *m[12];
    v.y = v3.x * m[1] + v3.y * m[5] + v3.z * m[9] + v3.w *m[13];
    v.z = v3.x * m[2] + v3.y * m[6] + v3.z * m[10] + v3.w *m[14];
	v.w = v3.x * m[2] + v3.y * m[6] + v3.z * m[10] + v3.w *m[14];
    return v;
}



rglVec2 rglMatrix3MulVector2(const rglMat3 m, rglVec2 v3)
{   
	rglVec2 v;    
    v.x = v3.x * m[0] + v3.y * m[4] + m[8] ;
    v.y = v3.x * m[1] + v3.y * m[5] + m[9] ;   
    return v;
}

rglVec3 rglMatrix3MulVector3(const rglMat3 m, rglVec3 v3)
{   
	rglVec3 v;    
    v.x = v3.x * m[0] + v3.y * m[4] + v3.z * m[8] ;
    v.y = v3.x * m[1] + v3.y * m[5] + v3.z * m[9] ;
    v.z = v3.x * m[2] + v3.y * m[6] + v3.z * m[10];
    return v;
}

GLint rglVector2Print(rglVec2 v)
{   
	printf("v.x = %5.2f , v.y = %5.2f\n", v.x, v.y);
    return 1;
}

  rglVec3 rglVector3Tangent(rglVec3 v1, rglVec3 v2, rglVec3 v3, rglTex2 t1, rglTex2 t2, rglTex2 t3)
  {
	 rglVec3 edge1,edge2, tangent;
	 rglVec2 texEdge1,texEdge2;
	 edge1=rglVector3Normalize(rglVector3Sub(v2,v1)) ;
	 edge2=rglVector3Normalize(rglVector3Sub(v3,v1)) ;
	 
	 texEdge1=rglVector2Normalize(rglVector2Sub(rglVector2Set(t2.s,t2.t),rglVector2Set(t1.s,t1.t))) ;
	 texEdge2=rglVector2Normalize(rglVector2Sub(rglVector2Set(t3.s,t3.t),rglVector2Set(t1.s,t1.t))) ;
	 float det = (texEdge1.x * texEdge2.y) - (texEdge1.y * texEdge2.x);
	  if (fabsf(det) < 1e-6f)    // almost equal to zero
    {
        tangent.x = 1.0f;
        tangent.y = 0.0f;
        tangent.z = 0.0f;

    }
    else
    {
        det = 1.0f / det;
		
        tangent.x = (texEdge2.y * edge1.x - texEdge1.y * edge2.x) * det;
        tangent.y = (texEdge2.y * edge1.y - texEdge1.y * edge2.y) * det;
        tangent.z = (texEdge2.y * edge1.z - texEdge1.y * edge2.z) * det;

	  }
	 return rglVector3Normalize(tangent) ;
}

  rglVec3 rglVector3Binormal(rglVec3 v1, rglVec3 v2, rglVec3 v3, rglTex2 t1, rglTex2 t2, rglTex2 t3)
  {
	 rglVec3 edge1,edge2, bitangent;
	 rglVec2 texEdge1,texEdge2;
	
	 edge1=rglVector3Normalize(rglVector3Sub(v2,v1)) ;
	 edge2=rglVector3Normalize(rglVector3Sub(v3,v1)) ;
	 
	 texEdge1=rglVector2Normalize(rglVector2Sub(rglVector2Set(t2.s,t2.t),rglVector2Set(t1.s,t1.t))) ;
	 texEdge2=rglVector2Normalize(rglVector2Sub(rglVector2Set(t3.s,t3.t),rglVector2Set(t1.s,t1.t))) ;
	  float det = (texEdge1.x * texEdge2.y) - (texEdge1.y * texEdge2.x);
	  if (fabsf(det) < 1e-6f)    // almost equal to zero
    {
       
      bitangent.x = 0.0f;
        bitangent.y = 1.0f;
       bitangent.z = 0.0f;
    }
    else
    {
        det = 1.0f / det;      
           
       bitangent.x = (-texEdge2.x * edge1.x + texEdge1.x * edge2.x) * det;
       bitangent.y = (-texEdge2.x * edge1.y + texEdge1.x * edge2.y) * det;
       bitangent.z = (-texEdge2.x * edge1.z + texEdge1.x * edge2.z) * det;
	  }
	 return rglVector3Normalize(bitangent) ;
}



GLint rglVector3Print(rglVec3 v)
{   
	printf("v.x = %5.2f , v.y = %5.2f, v.z = %5.2f\n", v.x, v.y,v.z);
    return 1;
}

GLint rglVector4Print(rglVec4 v)
{   
	printf("v.x = %5.2f , v.y = %5.2f, v.z = %5.2f,  v.w = %5.2f\n", v.x, v.y,v.z,v.w);
    return 1;
}

//matrix operation
GLint rglMatrix4Identity(rglMat4 mat)
{	
	/*
	for (GLint i =0; i<16; i++)
			mat[i]=0.0;
	mat[0]=1.0;mat[5]=1.0;mat[10]=1.0;	mat[15]=1.0;		
*/	

	memcpy(&mat[0], &m_identity4[0],sizeof(mat)*16); 	
	return 1;
}	

GLint rglMatrix3Identity(rglMat3 mat)
{	
	/*
	for (GLint i =0; i<9; i++)
			mat[i]=0.0;
	mat[0]=1.0;mat[4]=1.0;mat[8]=1.0;		
	*/
	 memcpy(mat, m_identity3,sizeof(mat)*9); 			
	return 1;
	
 
}

GLint rglMatrix4Multiply(rglMat4 mat1, rglMat4 mat2)
{
	rglMat4 mat_t;
	for (GLint i =0; i<16; i++)
		mat_t[i]=mat1[i];
 	mat1[0] = mat_t[0] * mat2[0] + mat_t[4] * mat2[1] + mat_t[8] * mat2[2] + mat_t[12] * mat2[3];
    mat1[1] = mat_t[1] * mat2[0] + mat_t[5] * mat2[1] + mat_t[9] * mat2[2] + mat_t[13] * mat2[3];
    mat1[2] = mat_t[2] * mat2[0] + mat_t[6] * mat2[1] + mat_t[10] * mat2[2] + mat_t[14] * mat2[3];
    mat1[3] = mat_t[3] * mat2[0] + mat_t[7] * mat2[1] + mat_t[11] * mat2[2] + mat_t[15] * mat2[3];
    mat1[4] = mat_t[0] * mat2[4] + mat_t[4] * mat2[5] + mat_t[8] * mat2[6] + mat_t[12] * mat2[7];    
    mat1[5] = mat_t[1] * mat2[4] + mat_t[5] * mat2[5] + mat_t[9] * mat2[6] + mat_t[13] * mat2[7];
    mat1[6] = mat_t[2] * mat2[4] + mat_t[6] * mat2[5] + mat_t[10] * mat2[6] + mat_t[14] * mat2[7];
    mat1[7] = mat_t[3] * mat2[4] + mat_t[7] * mat2[5] + mat_t[11] * mat2[6] + mat_t[15] * mat2[7];
    mat1[8] = mat_t[0] * mat2[8] + mat_t[4] * mat2[9] + mat_t[8] * mat2[10] + mat_t[12] * mat2[11];
    mat1[9] = mat_t[1] * mat2[8] + mat_t[5] * mat2[9] + mat_t[9] * mat2[10] + mat_t[13] * mat2[11];
    mat1[10] = mat_t[2] * mat2[8] + mat_t[6] * mat2[9] + mat_t[10] * mat2[10] + mat_t[14] * mat2[11];
    mat1[11] = mat_t[3] * mat2[8] + mat_t[7] * mat2[9] + mat_t[11] * mat2[10] + mat_t[15] * mat2[11];
    mat1[12] = mat_t[0] * mat2[12] + mat_t[4] * mat2[13] + mat_t[8] * mat2[14] + mat_t[12] * mat2[15];
    mat1[13] = mat_t[1] * mat2[12] + mat_t[5] * mat2[13] + mat_t[9] * mat2[14] + mat_t[13] * mat2[15];
    mat1[14] = mat_t[2] * mat2[12] + mat_t[6] * mat2[13] + mat_t[10] * mat2[14] + mat_t[14] * mat2[15];
    mat1[15] = mat_t[3] * mat2[12] + mat_t[7] * mat2[13] + mat_t[11] * mat2[14] + mat_t[15] * mat2[15];    
    return 1;
	free(mat_t);
}

GLfloat rglMatrix3Determinant(rglMat3 m)
{
  GLfloat det= -m[6]*m[4]*m[2]+m[3]*m[7]*m[2]+ m[6]*m[1]*m[5]- m[0]*m[7]*m[5]-  m[3]*m[1]*m[8]+ m[0]*m[4]*m[8];
  return   det;
}

GLint rglMatrix3Inverse(rglMat3 m1, rglMat3 m2)
{
  GLfloat x= rglMatrix3Determinant(m2);
  if (x==0) return 0;

  m1[0]=(-m2[7]*m2[5]+m2[4]*m2[8])/x;
  m1[3]=( m2[6]*m2[5]-m2[3]*m2[8])/x;
  m1[6]=(-m2[6]*m2[4]+m2[3]*m2[7])/x;
  m1[1]=( m2[7]*m2[2]-m2[1]*m2[8])/x;
  m1[4]=(-m2[6]*m2[2]+m2[0]*m2[8])/x;
  m1[7]=( m2[6]*m2[1]-m2[0]*m2[7])/x;
  m1[2]=(-m2[4]*m2[2]+m2[1]*m2[5])/x;
  m1[5]=( m2[3]*m2[2]-m2[0]*m2[5])/x;
  m1[8]=(-m2[3]*m2[1]+m2[0]*m2[4])/x;

  return 1;
}

GLint rglMatrix4to3(rglMat3 m1, rglMat4 m2)
{
 	m1[0] =  m2[0];
    m1[1] =  m2[1];
    m1[2] =  m2[2];
    m1[3] =  m2[4];
    m1[4] =  m2[5];
    m1[5] =  m2[6];;
    m1[6] =  m2[8];;
    m1[7] =  m2[9];
    m1[8] =  m2[10];    

  return 1;;
}

GLint rglMatrix3Transpose(rglMat3 m1, rglMat3 m2) 
{
   m1[0] = m2[0]; m1[3] = m2[1]; m1[6] = m2[2]; 
   m1[1] = m2[3]; m1[4] = m2[4]; m1[7] = m2[5];
   m1[2] = m2[6]; m1[5] = m2[7]; m1[8] = m2[8];
    						
   return 1;
}

GLint rglMatrix3Copy(rglMat3 m1, rglMat3 m2) 
{
	for (GLint i =0; i<9; i++)
			m1[i]=m2[i];    						
   return 1;
}

GLint rglMatrix4Copy(rglMat4 m1, rglMat4 m2) 
{
	for (GLint i =0; i<16; i++)
			m1[i]=m2[i];    						
   return 1;
}

GLint rglMatrix4Transpose(rglMat4 m1, rglMat4 m2) 
{
   m1[0] = m2[0]; m1[4] = m2[1]; m1[8] = m2[2]; m1[12] = m2[3];
   m1[1] = m2[4]; m1[5] = m2[5]; m1[9] = m2[6]; m1[13] = m2[7];
   m1[2] = m2[8]; m1[6] = m2[9]; m1[10] = m2[10]; m1[14] = m2[11];
   m1[3] = m2[12]; m1[7] = m2[13]; m1[11] = m2[14]; m1[15] = m2[15];
   return 1;
}


GLint rglMatrix4Inverse(rglMat4 m2, rglMat4 m1)
 {
    float   det;
    det = m1[0] * m1[5] * m1[10];
    det += m1[4] * m1[9] * m1[2];
    det += m1[8] * m1[1] * m1[6];
    det -= m1[8] * m1[5] * m1[2];
    det -= m1[4] * m1[1] * m1[10];
    det -= m1[0] * m1[9] * m1[6];
    if(det * det < 1e-25) return 0;
    det = 1.0 / det;    
    m2[0] =    (m1[5] * m1[10] - m1[9] * m1[6]) * det;
    m2[1] =  - (m1[1] * m1[10] - m1[9] * m1[2]) * det;
    m2[2] =    (m1[1] * m1[6] -  m1[5] * m1[2]) * det;
    m2[3] = 0.0;
    m2[4] =  - (m1[4] * m1[10] - m1[8] * m1[6]) * det;
    m2[5] =    (m1[0] * m1[10] - m1[8] * m1[2]) * det;
    m2[6] =  - (m1[0] * m1[6] -  m1[4] * m1[2]) * det;
    m2[7] = 0.0;
    m2[8] =    (m1[4] * m1[9] -  m1[8] * m1[5]) * det;
    m2[9] =  - (m1[0] * m1[9] -  m1[8] * m1[1]) * det;
    m2[10] =   (m1[0] * m1[5] -  m1[4] * m1[1]) * det;
    m2[11] = 0.0;
    m2[12] = - (m1[12] * m2[0] + m1[13] * m2[4] + m1[14] * m2[8]);
    m2[13] = - (m1[12] * m2[1] + m1[13] * m2[5] + m1[14] * m2[9]);
    m2[14] = - (m1[12] * m2[2] + m1[13] * m2[6] + m1[14] * m2[10]);
    m2[15] = 1.0;
    return 1;
}



GLint  rglPerspective(rglMat4 mat, GLfloat fov, GLfloat aspect, GLfloat znear, GLfloat zfar)
{	
	float rad = fov * DEG2RAD;
	for (GLint i =0; i<16; i++)
			mat[i]=0.0;			
	mat[0]=1.0f/(tan(rad/2.0f)*aspect);
	mat[5]=1.0/tan(rad/2.0f);
	mat[10]=(znear+zfar)/(znear-zfar);
	mat[11]=-1.0f;
	mat[14]=(2.0f*znear*zfar)/(znear-zfar);	
	mat[15]=1.0;			
	return 1;
}

GLint  rglOrtho(rglMat4 mat, GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat znear, GLfloat zfar)
{	
	for (GLint i =0; i<16; i++)
			mat[i]=0.0;			
	mat[0]=2.0/(right - left);
	mat[5]=2.0/(top - bottom);
	mat[10]=2.0/(zfar - znear);
	mat[12]=-(right + left)/(right - left);
	mat[13]=-(top+bottom)/(top - bottom);	
	mat[14]=(zfar + znear)/(zfar - znear);	
	mat[15]=1.0;		
	return 1;
}

GLint rglTranslate(rglMat4 mat, GLfloat x, GLfloat y, GLfloat z)
{
	mat[12]+=x;
	mat[13]+=y;
	mat[14]+=z;
	return 1;
}

GLint rglScale(rglMat4 mat, GLfloat x, GLfloat y, GLfloat z)
{
	rglMat4 m;
	rglMatrix4Identity(m);
	m[0]=x;
	m[5]=y;
	m[10]=z;
	rglMatrix4Multiply(mat, m);
	return 1;
	free(m);
	
}

GLint rglRotate(rglMat4 mat, GLfloat angle, GLfloat x, GLfloat y, GLfloat z)
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

	rglMatrix4Multiply(mat, m);	
	return 1;
	free(m);
}

GLint rglLookAt(rglMat4 mat, rglVec3 v1, rglVec3 v2, rglVec3 v3)
{
	
	rglVec3 f,up,x,y;
	rglMat4 m1,m2;
	rglMatrix4Identity(m2);
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
   	rglTranslate(m2,-v1.x,-v1.y,-v1.z);
    rglMatrix4Multiply(m1,m2);
	rglMatrix4Multiply(mat,m1);
	//free(x);free(y);free(z);
	return 1;
	free(m1);
	free(m2);
}

GLint rglMatrixNormal(rglMat3 m1, rglMat4 m2)
 {
 	rglMat3   m3;
	rglMat3   mt;
	rglMat3   mi;
	rglMatrix4to3(m3,m2);
	rglMatrix3Transpose(mt,m3);
	rglMatrix3Inverse(mi,mt);  
	rglMatrix3Copy(m1,mi);
	return 1;
	free(m3);
	free(mt);
	free(mi);
}


GLint rglMatrix3Print(rglMat4 m)
{
	printf("m[0] = %5.2f m[3] = %5.2f m[6] = %5.2f \n", m[0],m[3],m[6]);
	printf("m[1] = %5.2f m[4] = %5.2f m[7] = %5.2f \n", m[1],m[4],m[7]);
	printf("m[2] = %5.2f m[5] = %5.2f m[8] = %5.2f \n", m[2],m[5],m[8]);
	printf("--------------------------------------------------------------------------------------------------\n");
	return 1;
}

GLint rglMatrix4Print(rglMat4 m)
{
	printf("m[0] = %5.2f m[4] = %5.2f m[8] = %5.2f m[12] = %5.2f\n", m[0],m[4],m[8],m[12]);
	printf("m[1] = %5.2f m[5] = %5.2f m[9] = %5.2f m[13] = %5.2f\n", m[1],m[5],m[9],m[13]);
	printf("m[2] = %5.2f m[6] = %5.2f m[10] = %5.2f m[14] = %5.2f\n", m[2],m[6],m[10],m[14]);
	printf("m[3] = %5.2f m[7] = %5.2f m[11] = %5.2f m[15] = %5.2f\n", m[3],m[7],m[11],m[15]);
	printf("--------------------------------------------------------------------------------------------------\n");
	return 1;
}

//old and test code
GLint rotate(rglMat4 mat, GLfloat angle, GLfloat x, GLfloat y, GLfloat z)
{
    float rad = angle * DEG2RAD;
    float cosA = cos(rad);
    float sinA = sin(rad);
    rglMat4 m_t;
    rglMatrix4Identity(m_t);
    
	if (x ==1.0)
	{
	rglMat4 m_x;
	rglMatrix4Identity(m_x);
	m_x[5]=cosA;
	m_x[6]=sinA;
	m_x[9]=-sinA;
	m_x[10]=cosA;
	rglMatrix4Multiply(m_t, m_x);
	}
	
	if (y ==1.0)
	{
	rglMat4 m_y;
	rglMatrix4Identity(m_y);
	m_y[0]=cosA;
	m_y[2]=-sinA;
	m_y[8]=sinA;
	m_y[10]=cosA;
	rglMatrix4Multiply(m_t, m_y);
	}
	
	if (z ==1.0)
	{
	rglMat4 m_z;
	rglMatrix4Identity(m_z);
	m_z[0]=cosA;
	m_z[1]=sinA;
	m_z[4]=-sinA;
	m_z[5]=cosA;
	rglMatrix4Multiply(m_t, m_z);
	}
	rglMatrix4Multiply(mat, m_t);
	return 1;
	free(m_t);
}

GLint MatrixNormalOld(rglMat3 m1, rglMat4 m2)
 {
    rglMat4   mt;
	rglMat4   mi;
	rglMatrix4Transpose(mt,m2);
	rglMatrix4Inverse(mi,mt);  
    m1[0] =  mi[0];
    m1[1] =  mi[1];
    m1[2] =  mi[2];
    m1[3] =  mi[4];
    m1[4] =  mi[5];
    m1[5] =  mi[6];;
    m1[6] =  mi[8];;
    m1[7] =  mi[9];
    m1[8] =  mi[10];    
    return 1;
	free(mt);
	free(mi);

}

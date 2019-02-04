
	uniform mat4 pmatrix;
	uniform mat4 mvmatrix;
	uniform mat3 nmatrix;
	

	uniform vec3 LightPosition;
	uniform vec4 LightDiffuse;
	uniform vec4 LightAmbient;	
	uniform vec4 MaterialDiffuse;
	uniform vec4 MaterialAmbient;
	
	

varying vec4 diffuse,ambient;
varying vec3 normal,lightVec,halfVector, eyeVec, ecPosition;

void main()
{	

	normal = normalize(nmatrix * gl_Normal);
	

	ecPosition = vec3(mvmatrix * gl_Vertex);
	lightVec = normalize(LightPosition - ecPosition);
    
	eyeVec = normalize (-ecPosition);

	halfVector= normalize(eyeVec + lightVec);

	diffuse = MaterialDiffuse * LightDiffuse;
	ambient = MaterialAmbient * LightAmbient;
	
	
	gl_TexCoord[0] = gl_MultiTexCoord0;	
	gl_Position = pmatrix * mvmatrix * gl_Vertex;
	
	
	
	
	
} 

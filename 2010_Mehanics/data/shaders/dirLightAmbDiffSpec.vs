
	uniform mat4 pmatrix;
	uniform mat4 mvmatrix;
	uniform mat3 nmatrix;
	uniform vec3 LightPosition;
	uniform vec4 LightDiffuse;
	uniform vec4 LightAmbient;
	uniform vec4 LightSpecular;
	uniform vec4 MaterialDiffuse;
	uniform vec4 MaterialAmbient;
	uniform vec4 MaterialSpecular;
	uniform float MaterialShininess;

void main()
{	
	vec3 normal, lightVec, viewVector, halfVector, eyeVec, ecPosition;
	vec4 diffuse, ambient, globalAmbient, specular = vec4(0.0);
	float NdotL,NdotHV;
	
	
	normal = normalize(nmatrix * gl_Normal);
	ecPosition = vec3(mvmatrix * gl_Vertex);



	lightVec = normalize(LightPosition - ecPosition);
	eyeVec= normalize(- ecPosition);
	halfVector= normalize( lightVec + eyeVec);

	
	NdotL = max(dot(normal, lightVec), 0.0);
	


	diffuse = MaterialDiffuse * LightDiffuse;
	ambient = LightAmbient * MaterialAmbient;
	
	
	
	if (NdotL > 0.0)
	 {
		NdotHV = max(dot(normal, normalize(halfVector)),0.0);
		specular = MaterialSpecular * LightSpecular * pow(NdotHV,MaterialShininess);
	}
	gl_FrontColor = NdotL * diffuse + ambient + specular;
	gl_TexCoord[0] = gl_MultiTexCoord0;
	gl_Position = pmatrix * mvmatrix * gl_Vertex;
	
	
	
	
	
} 

/* Vertex shader */
// Lambert lightning  Ld= Ldiff * Mdiff * cos(a); 
// 								La =Gamb* Mamb + Lamb*Mamb; 
//								Lad=Ld + La

uniform mat4 pmatrix;
uniform mat4 mvmatrix;
uniform mat3 nmatrix;
uniform vec3 LightPosition;
uniform vec4 LightDiffuse;
uniform vec4 LightAmbient;	
uniform vec4 MaterialDiffuse;
uniform vec4 MaterialAmbient;

varying vec4 FrontColor;

void main(void)  
{     
vec3 normal;
vec3 lightDir;
	
	normal = normalize(nmatrix * gl_Normal);
	lightDir = normalize(LightPosition);
	
	float NdotL = max(dot(normal, lightDir),0.0);
	
	vec4 diffuse =  LightDiffuse * MaterialDiffuse;
	
	FrontColor = diffuse * NdotL+LightAmbient *MaterialAmbient;

	gl_TexCoord[0] = gl_MultiTexCoord0;
   	gl_Position     = pmatrix * mvmatrix * gl_Vertex; 
}
          



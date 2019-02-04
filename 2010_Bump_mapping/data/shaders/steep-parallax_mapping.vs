//
// Steep parallax mapping vertex shader
// 

varying	vec3 lt;
varying	vec3 et;

uniform	vec4	light;
uniform	vec4	eye;

void main(void)
{
	vec3	p = vec3      ( gl_ModelViewMatrix * gl_Vertex );		

	vec3	l = normalize ( vec3 ( light ) - p );					
	vec3	e = normalize ( vec3 ( eye   ) - p );					
	vec3	n = gl_NormalMatrix * gl_Normal;						

	vec3 t = gl_NormalMatrix * gl_MultiTexCoord1.xyz;				
	vec3 b = gl_NormalMatrix * gl_MultiTexCoord2.xyz;				

																	
	et = vec3 ( dot ( e, t ), dot ( e, b ), dot ( e, n ) );
	lt = vec3 ( dot ( l, t ), dot ( l, b ), dot ( l, n ) );

	gl_Position     = gl_ModelViewProjectionMatrix * gl_Vertex;
	gl_TexCoord [0] = gl_MultiTexCoord0;
}

//
// Steep parallax mapping fragment shader
// 

varying	vec3 et;
varying	vec3 lt;

uniform sampler2D colorMap;
uniform sampler2D heightMap;
uniform	float	  scale;

void main (void)
{
	const float numSteps  = 10.0;
																
	float	step   = 1.0 / numSteps;
	vec2	dtex   = et.xy * scale / ( numSteps * et.z );	
	float	height = 1.0;									
	vec2	tex    = gl_TexCoord [0].xy;					
	float	h      =1.0 - texture2D ( heightMap, tex ).r;		

	while ( h < height )
	{
		height -= step;
		tex    += dtex;
		h       =1.0 - texture2D ( heightMap, tex ).r;
	}	
																
	gl_FragColor = vec4 ( texture2D ( colorMap, tex ).rgb, 1.0 );
}

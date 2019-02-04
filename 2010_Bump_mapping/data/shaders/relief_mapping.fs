//
// Relief mapping with binary search GLSL fragment shader
//

varying	vec3 et;
varying	vec3 lt;
varying	vec3 ht;

uniform sampler2D colorMap;
uniform sampler2D heightMap;
uniform	float	  scale;

void main (void)
{
	const float numSteps  = 10.0;
	const float	specExp   = 80.0;

	float	step   = 1.0 / numSteps;
	vec2	dtex   = et.xy * scale / ( numSteps * et.z );	
	float	height = 1.0;									
	vec2	tex    = gl_TexCoord [0].xy;					
	float	h      =1.0 - texture2D ( heightMap, tex ).a;		

	while ( h < height )
	{
		height -= step;
		tex    += dtex;
		h       = 1.0 - texture2D ( heightMap, tex ).a;

	}
									
	vec2	delta = 0.5 * dtex;
	vec2	mid   = tex - delta;	

	for ( int i = 0; i < 5; i++ )
	{
		delta *= 0.5;

		if ((1.0 -  texture2D ( heightMap, mid ).a) < height )
			mid += delta;
		else
			mid -= delta;
	}

	tex = mid;
																
	vec3	color = texture2D ( colorMap, tex ).rgb;
	vec3	n     = normalize ( texture2D ( heightMap, tex ).rgb * 2.0 - vec3 ( 1.0 ) );
	float	diff  = max ( dot ( n, normalize ( lt ) ), 0.0 );
	float	spec  = pow ( max ( dot ( n, normalize ( ht ) ), 0.0 ), specExp );

	gl_FragColor = vec4 ( color * diff + vec3 ( 0.7 * spec ), 1.0 );
}

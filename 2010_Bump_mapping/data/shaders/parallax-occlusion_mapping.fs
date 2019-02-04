//
//  Parallax Occlusion maping GLSL fragment shader
//

varying	vec3 et;
varying	vec3 lt;
varying	vec3 ht;

uniform sampler2D colorMap;
uniform sampler2D heightMap;
uniform sampler2D normalMap;
uniform	float	  scale;

void main (void)
{
	const float numSteps  = 10.0;
	const float	specExp   = 80.0;
	const float	eps       = 0.05;

	float	step   = 1.0 / numSteps;
	vec2	dtex   = step * scale * et.xy / et.z;	
	float	height = 1.0;								
	vec2	tex    = gl_TexCoord [0].xy;				
	float	h      =1.0 - texture2D ( heightMap, tex ).r;

	while ( h < height )
	{
		height -= step;
		tex    += dtex;
		h       = 1.0 - texture2D ( heightMap, tex ).r;
	}
												
	vec2	prev   = tex - dtex;				
	float	hPrev  = texture2D ( heightMap, prev ).r - (height + step); 
	float	hCur   = h - height;				
	float	weight = hCur / (hCur - hPrev );
	
	tex = weight * prev + (1.0 - weight) * tex;
	
	vec4	color = texture2D ( colorMap, tex );
	vec3	n     = normalize ( texture2D ( normalMap, tex ).rgb * 2.0 - vec3 ( 1.0 ) );
	float	diff  = dot ( n, normalize ( lt ) );
	float	spec  = pow ( max ( dot ( n, normalize ( ht ) ), 0.0 ), specExp );

													
	float	vis          = 1.0;						
	float	sampleWeight = 9.0 / numSteps;			
	vec2	ltex;
	
	if ( diff > eps )								
	{
		height        = 1.0 - color.a;
		step          = color.a / numSteps;
		ltex          = scale * step * lt.xy / lt.z;
		height       += step;						
		tex          += ltex;
		sampleWeight *= pow ( 1.0 - lt.z, 3.0 );	
		
		while ( height < 1.0 - eps )
		{
			if ( 1.0 - texture2D ( heightMap, tex ).r > height )
				vis -= sampleWeight;
							
			height += step;
			tex    += ltex;
		}	
	}
	else											
		diff = 0.0;
			
	gl_FragColor = vec4 ( vis * ( color.rgb * diff + vec3 ( 0.7 * spec ) ), 1.0 );
}

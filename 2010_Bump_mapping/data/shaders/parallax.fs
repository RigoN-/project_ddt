//
// Simple parallax effect vertex shader
/
varying	vec3 et;
varying	vec3 lt;

uniform sampler2D colorMap;
uniform sampler2D heightMap;
float	  scale=0.03;
float	  bias=0.015;
	
void main (void)
{
																
	float	h    = scale * (1.0-texture2D ( heightMap, gl_TexCoord [0].xy ).r) + bias;
	
																
	vec2	tex  = gl_TexCoord [0].xy - et.xy * h / et.z;
															
	gl_FragColor = vec4 ( texture2D ( colorMap, tex ).rgb, 1.0 );
}

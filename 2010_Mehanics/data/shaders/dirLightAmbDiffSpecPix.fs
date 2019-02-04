
uniform sampler2D Texture;

uniform vec4 LightSpecular;
uniform vec4 MaterialSpecular;
uniform float MaterialShininess;

varying vec4 diffuse,ambient;
varying vec3 normal,lightVec,halfVector;


void main()
{
	vec3 normalVec,halfV,viewV,ldir;
	float NdotL,NdotHV;
	vec4 color = ambient;
	

	normalVec = normalize(normal);
	

	NdotL = max(dot(normalVec,lightVec),0.0);

	if (NdotL > 0.0) {
		halfV = normalize(halfVector);
		NdotHV = max(dot(normalVec,halfV),0.0);
		color += LightSpecular * MaterialSpecular * pow(NdotHV,MaterialShininess);
		color += diffuse * NdotL;
	}

	gl_FragColor = vec4(texture2D(Texture, gl_TexCoord[0].st) * color);
}

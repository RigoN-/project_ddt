uniform mat4 pmatrix;
uniform mat4 mvmatrix;
varying vec3 FrontColor;

void main()
{
    gl_TexCoord[0]  = gl_MultiTexCoord0;	
	gl_Position = pmatrix * mvmatrix * gl_Vertex;
}

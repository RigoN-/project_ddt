
uniform mat4 pmatrix;
uniform mat4 mvmatrix;
uniform mat4 pvm;
varying vec3 FrontColor;

void main()
{

	 FrontColor=gl_Color;
	gl_Position = pmatrix * mvmatrix * gl_Vertex;

}

/* Fragment shader */
uniform sampler2D Texture;
varying vec4 FrontColor;

void main (void)  
{ 
	vec4 color =(texture2D(Texture, gl_TexCoord[0].st));
     gl_FragColor =color *FrontColor;      
}
          

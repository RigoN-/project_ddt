/* Fragment shader */



uniform sampler2D EarthTexture;
varying vec4 FrontColor;

void main (void)  
{ 
	vec4 lightColor =(texture2D(EarthTexture, gl_TexCoord[0].st));
     gl_FragColor =lightColor *FrontColor;      
}
          

uniform sampler2D Texture;

void main()
{
    vec3 Color = vec3(texture2D(Texture, gl_TexCoord[0].st));
    gl_FragColor    = vec4(Color, 1.0);
}

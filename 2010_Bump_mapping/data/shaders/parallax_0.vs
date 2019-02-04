varying vec2 textureCoordinate;
varying vec3 lightVector;
varying vec3 eyeVector;

uniform vec4 lightPosition;

// Hard code tangent...since RenderMonkey doesn't appear to be passing in
// what I expected.
//const vec3 tangent = vec3( 1.0, 0.0, 0.0 );


void main()
{
   gl_Position = ftransform();
   vec3 tangent = gl_NormalMatrix * gl_MultiTexCoord1.xyz;
   vec3 cameraInWorldSpace = gl_Position.xyz - gl_ModelViewMatrixInverse[ 3 ].xyz;

   textureCoordinate = gl_MultiTexCoord0.xy;
   
   lightVector = ( lightPosition - gl_Vertex ).xyz;
   
   vec3 normal = gl_NormalMatrix * gl_Normal;
   
   vec3 binormal = cross( tangent, normal );
   
   mat3 tangentBinormalNormalMatrix = mat3( tangent, binormal, normal );

   lightVector = tangentBinormalNormalMatrix * lightVector;

   eyeVector = cameraInWorldSpace - ( gl_ModelViewMatrixInverse * gl_Vertex ).xyz;
   eyeVector = tangentBinormalNormalMatrix * eyeVector;
}

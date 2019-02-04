{$R-}
{$MODE DELPHI}
unit text_gl;
interface
uses gl,  glu,  SysUtils, glut, glext;

var
Font_base : GLuint;

procedure glBuildFont(texFont:GLUInt);cdecl;
procedure glDrawText( x, y,SCREEN_WIDTH,SCREEN_HEIGHT, texFont : GLint; scale: GLFloat; Text : string; sett : integer);cdecl;

implementation

procedure glBuildFont(texFont:GLUInt);cdecl;
var
  loop : GLuint; 
  cx : single;
  cy : single; 
  
begin
  // Creating 256 Display List */
   Font_base := glGenLists( 256 );
  /// Select Our Font Texture */
  glBindTexture( GL_TEXTURE_2D, texFont );

  // Loop Through All 256 Lists */
  for loop := 0 to 255 do
  begin
     // X Position Of Current Character
    //cx := 1 - ( loop mod 16 ) / 16.0;
	cx := ( loop mod 16 ) / 16.0;
    // Y Position Of Current Character */
    cy := 1 - ( loop div 16 ) / 16.0;
	//cy := ( loop div 16 ) / 16.0;
	
    // Start Building A List
    glNewList(Font_base + ( loop ), GL_COMPILE );
    // Use A Quad For Each Character
    glBegin( GL_QUADS );
   
   	glTexCoord2f( cx , cy - 0.0625 );
    // Vertex Coord (Bottom Left) */
    glVertex2i( 0, 0 );
    // Texture Coord (Bottom Right)
    glTexCoord2f( cx + 0.0625, cy - 0.0625);
    // Vertex Coord (Bottom Right)
    glVertex2i( 16, 0 );
    // Texture Coord (Top Right)
    glTexCoord2f( cx + 0.0625, cy );
    // Vertex Coord (Top Right)
    glVertex2i( 16, 16 );
    // Texture Coord (Top Left)
    glTexCoord2f( cx , cy );
    // Vertex Coord (Top Left)
    glVertex2i( 0, 16 );
	
    glEnd;
    // Move To The Left Of The Character
    glTranslated( 10, 0, 0 );
    glEndList;
  end;
end;

procedure glDrawText( x, y,SCREEN_WIDTH,SCREEN_HEIGHT, texFont : GLint; scale: GLFloat; Text : string; sett : integer);cdecl;
begin
  if ( sett > 1 ) then
      sett := 1;
        
  glBindTexture( GL_TEXTURE_2D, texFont );
  glDisable( GL_DEPTH_TEST );
  glMatrixMode( GL_PROJECTION );
  glPushMatrix; 
  glLoadIdentity;
  glOrtho( 0, SCREEN_WIDTH, 0, SCREEN_HEIGHT, -1, 1 );
  glMatrixMode( GL_MODELVIEW );
  glPushMatrix;
  glLoadIdentity; 
  glTranslated( x, y, -1 );
  glScalef(scale*1,scale*1,1);
  glListBase(Font_base + 0 );
  glCallLists( Length( Text ), GL_UNSIGNED_BYTE, PChar( Text ) );
  glMatrixMode( GL_PROJECTION );
  glPopMatrix; 
  glMatrixMode( GL_MODELVIEW );
  glPopMatrix;  
  glEnable( GL_DEPTH_TEST );
end;


end.

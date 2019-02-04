{$R-}
{$MODE DELPHI}
unit text_glut;
interface
uses GL,GLU, GLUT;

procedure glutDrawText( x, y, z : GLFloat; Text : PChar; fontset:integer);

implementation

procedure glutDrawText( x, y, z : GLFloat; Text : PChar; fontset:integer);
var
i:integer;
begin
glRasterPos3f(x, y, z);

case fontset of
0: for i:=0 to strlen(Text)-1 do
	glutBitmapCharacter(GLUT_BITMAP_8_BY_13,  smallint(Text[i]));
1: for i:=0 to strlen(Text)-1 do
	glutBitmapCharacter(GLUT_BITMAP_9_BY_15,  smallint(Text[i]));
2: for i:=0 to strlen(Text)-1 do
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,  smallint(Text[i]));
3: for i:=0 to strlen(Text)-1 do
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,  smallint(Text[i]));
4: for i:=0 to strlen(Text)-1 do
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10,  smallint(Text[i]));
5: for i:=0 to strlen(Text)-1 do
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,  smallint(Text[i]));
6: for i:=0 to strlen(Text)-1 do
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,  smallint(Text[i]));
else
	 for i:=0 to strlen(Text)-1 do
	glutBitmapCharacter(GLUT_STROKE_MONO_ROMAN,  smallint(Text[i]));
end;
 
end;
end.

unit figure;

interface
uses SysUtils, SDL, gl, glu, glext, glut, text_glut,  text_gl,  ogl_texture;

procedure spiral_draw(r_max,r_tolsh,dlina,vitki,gorizont_loop,vertikal_loop,konec: glFloat);cdecl;
//r_max  -   внешний радиус
//r_tolsh  -   радиус толщины
//dlina  -   длина
//vitki  -   количество витков
//gorizont_loop  -   порядок количества треуольников по горизонтали
//vertikal_loop   -   порядок количества треугольников по вертикали
//konec   -   есть/нет закругление в конце (если есть - 1)
	
procedure cilindr_draw(h,max_alfa,r_top,r_base,vertikal_loop,gorizont_loop: glFloat);
//h   -   высота
//max_alfa   -   угол по ширине
//r_top   -   радиус верхнего основания
//r_nase   -   радиус нижнего основания
//gorizont_loop  -   порядок количества треуольников по горизонтали
//vertikal_loop   -   порядок количества треугольников по вертикали

procedure garmonichniy_cilindr_draw(h,max_alfa,r_base,vertikal_loop,gorizont_loop,plavnost_x,plavnost_y: glFloat);
//h   -   высота
//max_alfa   -   угол по ширине
//r_nase   -   радиус нижнего основания
//gorizont_loop  -   порядок количества треуольников по горизонтали
//vertikal_loop   -   порядок количества треугольников по вертикали
//plavnost_x   -   резкость
//plavnost_y   -   сжатие (обратная пропорциональность)

procedure shar_draw(r,max_a,max_b,verikal_loop,gorizont_loop: glFloat);
//r   -   радиус
//max_a   -   угол по высоте
//max_b   -   угол по ширине
//gorizont_loop  -   порядок количества треуольников по горизонтали
//vertikal_loop   -   порядок количества треугольников по вертикали

procedure torus_draw(r_max,r_min,a_max,b_max,gorizont_loop,vertikal_loop: glFloat);cdecl;
//r_max   -   внешний радиус
//r_min   -   внутренний радиус
//a_max   -   угол по высоте
//b_max   -   угол по ширине
//gorizont_loop  -   порядок количества треуольников по горизонтали
//vertikal_loop   -   порядок количества треугольников по вертикали

procedure torus_draw_el(r_max,r_min,a_max,b_max,gorizont_loop,vertikal_loop,raznica: glFloat);cdecl;
//r_max   -   внешний радиус
//r_min   -   внутренний радиус
//a_max   -   угол по высоте
//b_max   -   угол по ширине
//gorizont_loop  -   порядок количества треуольников по горизонтали
//vertikal_loop   -   порядок количества треугольников по вертикали
//raznica  -  во сколько по х больше

procedure krug_draw(r_min,r_max,max_alfa,cirkle_loop,y,gorizont_loop: glFloat);
//r_min   -   радиус внутреннего круга
//r_max   -   радиус внешнего круга
//max_alfa   -   угол по ширине
//cirkle-loop   -   количество полосок в окружности
//y   -   координата у
//gorizontal_loop   -   порядок количества треугольников в полоске

procedure kvadrat_draw(y,h_max,sh_max,gorizont_loop,vertikal_loop: glFloat);
//y   -   координата у
//h_max   -   длина(высота)
//sh_max   -   ширина
//gorizont_loop  -   порядок количества треуольников по горизонтали
//vertikal_loop   -   порядок количества треугольников по вертикали

procedure paral_draw(h,sh,d: glFloat);
//h   -   высота
//sh   -   ширина
//d   -   длина

procedure Cube_draw_ext(solid:GLInt;size_x,size_y, size_z:GLFloat; CubeTex_BC, CubeTex_R,CubeTex_T, CubeTex_L, CubeTex_BT, CubeTex_F: GLuint );

procedure quads_draw(size_x,size_y:GLFloat;Fon: GLuint);

procedure quads_draw_strelka(size_x,size_y:GLFloat;Fon: GLuint);

procedure tringle_draw(size_x,size_y:GLFloat; Fon: GLuint);

procedure tringle_draw_2(size_x,size_y:GLFloat; Fon: GLuint);

//////////////////////////////////////////////////////////////////////
implementation

procedure normali(x,y,z,xc,yc,zc: glFloat);
var xn,yn,zn: glFloat;	length : glFLoat;
begin
xn:=-x+xc;
yn:=-y+yc;
zn:=-z+zc;
glNormal3f(xn,yn,zn);
end;	

procedure cilindr_draw(h,max_alfa,r_top,r_base,vertikal_loop,gorizont_loop: glFloat);
var	 x,y,z,r,ch,a: glFloat;
begin

r:=r_top;
a:=0;
x:=r;
z:=0;
y:=h/2;
ch:=h/vertikal_loop;
		
	while y-ch>=-h/2 do	
	begin
		glBegin(GL_TRIANGLE_STRIP);	
			while a-max_alfa/gorizont_loop<max_alfa do
			begin
			x:=r*cos(a);
			z:=r*sin(a);
			normali(x,y,z,0,y,0);
			glVertex3f(x,y,z);
			x:=(r+(r_base-r_top)/vertikal_loop)*cos(a);
			z:=(r+(r_base-r_top)/vertikal_loop)*sin(a);
			normali(x,y-ch,z,0,y-ch,0);
			glVertex3f(x,y-ch,z);
			a:=a+max_alfa/gorizont_loop;
			end;
		glEnd();
		

	y:=y-ch;
	r:=r+(r_base-r_top)/vertikal_loop;
	a:=0;
	end;

end;

procedure garmonichniy_cilindr_draw(h,max_alfa,r_base,vertikal_loop,gorizont_loop,plavnost_x,plavnost_y: glFloat);
var	 x,y,z,r,ch,a,ch_r: glFloat;
begin

r:=r_base;
a:=0;
x:=r;
z:=0;
y:=-h/2;
ch:=h/vertikal_loop;
ch_r:=plavnost_x;
		
	while y+ch<=h/2 do	
	begin
	ch_r:=ch_r+plavnost_x;

		glBegin(GL_TRIANGLE_STRIP);	
			while a-max_alfa/gorizont_loop<max_alfa do
			begin
			x:=r*cos(a);
			z:=r*sin(a);
			normali(-x,y,-z,0,y,0);
			glVertex3f(x,y,z);
			x:=(r+plavnost_y*ch_r*ch_r)*cos(a);
			z:=(r+plavnost_y*ch_r*ch_r)*sin(a);
			normali(-x,y+ch,-z,0,y+ch,0);
			glVertex3f(x,y+ch,z);
			a:=a+max_alfa/gorizont_loop;
			end;
		glEnd();
		
	y:=y+ch;
	r:=r+plavnost_y*ch_r*ch_r;
	a:=0;
	end;

end;

procedure krug_draw(r_min,r_max,max_alfa,cirkle_loop,y,gorizont_loop: glFloat);
var r,a,x,z: glFloat;
begin	
r:=r_min;
a:=0;

	while r+(r_max-r_min)/cirkle_loop<r_max do
	begin
	
		glBegin(GL_TRIANGLE_STRIP);	
			while a-max_alfa/gorizont_loop<max_alfa do
			begin
			x:=r*cos(a);
			z:=r*sin(a);
			glNormal3f(0,1,0);
			glVertex3f(x,y,z);
			x:=(r+(r_max-r_min)/cirkle_loop)*cos(a);
			z:=(r+(r_max-r_min)/cirkle_loop)*sin(a);
			glNormal3f(0,1,0);
			glVertex3f(x,y,z);
			a:=a+max_alfa/gorizont_loop;
			end;
		glEnd();
				
	r:=r+(r_max-r_min)/cirkle_loop;
	a:=0;
	end;
end;

procedure shar_draw(r,max_a,max_b,verikal_loop,gorizont_loop: glFloat);
var	x,y,z,a,b,ak,bk: glFloat;
begin

	ak:=verikal_loop;
	bk:=gorizont_loop;
	a:=0;
	b:=0;
	
	while a<max_a do
	begin
		glBegin(GL_TRIANGLE_STRIP);
		while b-max_b/bk<=max_b do
		begin
			x:=(r*sin(a))*cos(b);
			y:=r*cos(a);
			z:=(r*sin(a))*sin(b);
			normali(x,y,z,0,0,0);
			glVertex3f(x,y,z);
			x:=(r*sin(a+max_a/ak))*cos(b);
			y:=r*cos(a+max_a/ak);
			z:=(r*sin(a+max_a/ak))*sin(b);
			normali(x,y,z,0,0,0);
			glVertex3f(x,y,z);
			b:=b+max_b/bk;
		end;
		glEnd();
	a:=a+max_a/ak;
	b:=0;
	end;
end;

procedure torus_draw(r_max,r_min,a_max,b_max,gorizont_loop,vertikal_loop: glFloat);cdecl;
var x,y,z,r,a,b,TubeRadius,Radius: glFloat;
begin
	
		TubeRadius:=(r_max-r_min)/2;
		Radius:=r_min+TubeRadius;
		r:=TubeRadius;
		b:=0;
		a:=0;
			while b<b_max do
			begin
			glBegin(GL_TRIANGLE_STRIP);	
				while a-a_max/vertikal_loop<a_max do
				begin
				x:=(Radius+r*cos(a))*cos(b);
				z:=(Radius+r*cos(a))*sin(b);
				y:=r*sin(a);
				normali(x,y,z,(r_max-TubeRadius)*cos(b),0,(r_max-TubeRadius)*sin(b));
				glVertex3f(x,y,z);
				x:=(Radius+r*cos(a))*cos(b+b_max/gorizont_loop);
				z:=(Radius+r*cos(a))*sin(b+b_max/gorizont_loop);
				y:=r*sin(a);
				normali(x,y,z,(r_max-TubeRadius)*cos(b+b_max/gorizont_loop),0,(r_max-TubeRadius)*sin(b+b_max/gorizont_loop));
				glVertex3f(x,y,z);
				a:=a+a_max/vertikal_loop;
				end;
			glEnd();
			a:=0;
			b:=b+b_max/gorizont_loop;
			end;
end;

procedure torus_draw_el(r_max,r_min,a_max,b_max,gorizont_loop,vertikal_loop,raznica: glFloat);cdecl;
var x,y,z,r,a,b,TubeRadius,Radius: glFloat;
begin
	
		TubeRadius:=(r_max-r_min)/2;
		Radius:=r_min+TubeRadius;
		r:=TubeRadius;
		b:=0;
		a:=0;
			while b<b_max do
			begin
			glBegin(GL_TRIANGLE_STRIP);	
				while a-a_max/vertikal_loop<a_max do
				begin
				x:=(Radius+r*cos(a))*cos(b);
				z:=(Radius+r*cos(a))/raznica*sin(b);
				y:=r*sin(a);
				normali(x,y,z,(r_max-TubeRadius)*cos(b),0,(r_max-TubeRadius)*sin(b));
				glVertex3f(x,y,z);
				x:=(Radius+r*cos(a))*cos(b+b_max/gorizont_loop);
				z:=(Radius+r*cos(a))/raznica*sin(b+b_max/gorizont_loop);
				y:=r*sin(a);
				normali(x,y,z,(r_max-TubeRadius)*cos(b+b_max/gorizont_loop),0,(r_max-TubeRadius)*sin(b+b_max/gorizont_loop));
				glVertex3f(x,y,z);
				a:=a+a_max/vertikal_loop;
				end;
			glEnd();
			a:=0;
			b:=b+b_max/gorizont_loop;
			end;
end;

procedure spiral_draw(r_max,r_tolsh,dlina,vitki,gorizont_loop,vertikal_loop,konec: glFloat);cdecl;
var x,y,z,a,b,ch,ch1,k: glFloat;
begin

if konec=1 then
begin
glPushMatrix();
glRotatef(90,0,0,1);
glTranslatef(0,dlina/2-r_tolsh,0);
torus_draw(r_max,r_max-2*r_tolsh,2*pi(),2*pi(),32,21);
glPopMatrix();

glPushMatrix();
glRotatef(90,0,0,1);
glTranslatef(0,-dlina/2+r_tolsh,0);
torus_draw(r_max,r_max-2*r_tolsh,2*pi(),2*pi(),32,21);
glPopMatrix();
end;

a:=0;
ch:=-dlina/2+r_tolsh;

			k:=0;
			b:=0;
			while not(b-2*pi()/vertikal_loop>2*pi()) do
			begin
			b:=b+2*pi()/vertikal_loop;
			k:=k+1;
			end;
ch1:=(dlina/vitki)/k;
x:=ch;

while x<dlina/2-ch1 do
begin

b:=0;
		glBegin(GL_TRIANGLE_STRIP);	
			while not(b-2*pi()/vertikal_loop>2*pi()) do
			begin
			x:=r_tolsh*cos(b)+ch;
			z:=(r_max-r_tolsh-r_tolsh*sin(b))*cos(a);
			y:=(r_max-r_tolsh-r_tolsh*sin(b))*sin(a);
			normali(x,y,z,ch,(r_max-r_tolsh/2)*sin(a),(r_max-r_tolsh/2)*cos(a));
			glVertex3f(x,y,z);
			
			z:=(r_max-r_tolsh-r_tolsh*sin(b))*cos(a+2*pi()/gorizont_loop);
			y:=(r_max-r_tolsh-r_tolsh*sin(b))*sin(a+2*pi()/gorizont_loop);	
			normali(x+ch1,y,z,ch+ch1,(r_max-r_tolsh/2)*sin(a+2*pi()/gorizont_loop),(r_max-r_tolsh/2)*cos(a+2*pi()/gorizont_loop));
			glVertex3f(x+ch1,y,z);
			
			b:=b+2*pi()/vertikal_loop;
			end;
		glEnd();
		
a:=a+2*pi()/gorizont_loop;
ch:=ch+ch1;
	
end;

end;

procedure kvadrat_draw(y,h_max,sh_max,gorizont_loop,vertikal_loop: glFloat);
var x,z,h,sh: glFloat;
begin
h:=-h_max/2;
	while not (h+h_max/vertikal_loop>(h_max/2)) do
	begin
	sh:=-sh_max/2;
	glBegin(GL_TRIANGLE_STRIP);
		while not (sh>(sh_max/2)) do
		begin
		x:=sh;
		z:=h;
		glVertex3f(x,y,z);
		z:=z+h_max/vertikal_loop;
		glVertex3f(x,y,z);
		sh:=sh+sh_max/gorizont_loop;
		end;
	glEnd();

	h:=h+h_max/vertikal_loop;
	end;
end;

procedure paral_draw(h,sh,d: glFloat);
begin

glBegin(GL_QUADS);

//нелицо
	glNormal3f(0,0,-1);
	glVertex3f(-d/2,-h/2,-sh/2);
	glNormal3f(0,0,-1);
	glVertex3f(d/2,-h/2,-sh/2);
	glNormal3f(0,0,-1);
	glVertex3f(d/2,h/2,-sh/2);
	glNormal3f(0,0,-1);
	glVertex3f(-d/2,h/2,-sh/2);

//лицо
	glNormal3f(0,0,1);
	glVertex3f(-d/2,-h/2,sh/2);
	glNormal3f(0,0,1);
	glVertex3f(d/2,-h/2,sh/2);
	glNormal3f(0,0,1);
	glVertex3f(d/2,h/2,sh/2);
	glNormal3f(0,0,1);
	glVertex3f(-d/2,h/2,sh/2);

//потолок
	glTexCoord2f(0.0,0.0);glNormal3f(0,1,0);glVertex3f(-d/2,h/2,-sh/2);
	glTexCoord2f(0.0,1.0);glNormal3f(0,1,0);glVertex3f(-d/2,h/2,sh/2);
	glTexCoord2f(1.0,1.0);glNormal3f(0,1,0);glVertex3f(d/2,h/2,sh/2);
	glTexCoord2f(1.0,0.0);glNormal3f(0,1,0);glVertex3f(d/2,h/2,-sh/2);

//пол
	glTexCoord2f(0.0,0.0);glNormal3f(0,-1,0);	glVertex3f(-d/2,-h/2,-sh/2);
	glTexCoord2f(0.0,1.0);glNormal3f(0,-1,0);	glVertex3f(-d/2,-h/2,sh/2);
	glTexCoord2f(1.0,1.0);glNormal3f(0,-1,0);	glVertex3f(d/2,-h/2,sh/2);
	glTexCoord2f(1.0,0.0);glNormal3f(0,-1,0);	glVertex3f(d/2,-h/2,-sh/2);

//прав
	glNormal3f(1,0,0);
	glVertex3f(d/2,h/2,-sh/2);
	glNormal3f(1,0,0);
	glVertex3f(d/2,h/2,sh/2);
	glNormal3f(1,0,0);
	glVertex3f(d/2,-h/2,sh/2);
	glNormal3f(1,0,0);
	glVertex3f(d/2,-h/2,-sh/2);

//лев
	glNormal3f(-1,0,0);
	glVertex3f(-d/2,h/2,-sh/2);
	glNormal3f(-1,0,0);
	glVertex3f(-d/2,h/2,sh/2);
	glNormal3f(-1,0,0);
	glVertex3f(-d/2,-h/2,sh/2);
	glNormal3f(-1,0,0);
	glVertex3f(-d/2,-h/2,-sh/2);

glEnd();

end;
/////////////////////////////////////////////////////////////////////////////////
procedure Cube_draw_ext(solid:GLInt;size_x,size_y, size_z:GLFloat; CubeTex_BC, CubeTex_R,CubeTex_T, CubeTex_L, CubeTex_BT, CubeTex_F: GLuint );
var
mode:GLInt;
begin
	case solid of
		0:glPolygonMode(GL_FRONT_AND_BACK,GL_POINT);
		1:glPolygonMode(GL_FRONT_AND_BACK,GL_LINE); 
		2:glPolygonMode(GL_FRONT_AND_BACK,GL_FILL); 
	else
		glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
	end;
	glBindTexture(GL_TEXTURE_2D, CubeTex_BC);
	glBegin(GL_QUADS);
		// Back Face
		glNormal3f( 0.0, 0.0, -1.0);
		glTexCoord2f(0.0, 0.0); glVertex3f(-1.0*size_x, -1.0*size_y, -1.0*size_z);
		glTexCoord2f(0.0, 1.0); glVertex3f(-1.0*size_x,  1.0*size_y, -1.0*size_z);
		glTexCoord2f(1.0, 1.0); glVertex3f( 1.0*size_x,  1.0*size_y, -1.0*size_z);
		glTexCoord2f(1.0, 0.0); glVertex3f( 1.0*size_x, -1.0*size_y, -1.0*size_z);
	glEnd;
	glBindTexture(GL_TEXTURE_2D, CubeTex_R);
	glBegin(GL_QUADS);
		// Right face
		glNormal3f(1.0, 0.0, 0.0);
		glTexCoord2f(1.0, 0.0); glVertex3f( 1.0*size_x, -1.0*size_y, -1.0*size_z);
		glTexCoord2f(1.0, 1.0); glVertex3f( 1.0*size_x,  1.0*size_y, -1.0*size_z);
		glTexCoord2f(0.0, 1.0); glVertex3f( 1.0*size_x,  1.0*size_y,  1.0*size_z);
		glTexCoord2f(0.0, 0.0); glVertex3f(1.0*size_x, -1.0*size_y,  1.0*size_z);
	glEnd;
	glBindTexture(GL_TEXTURE_2D, CubeTex_T);
	glBegin(GL_QUADS);
		// Top Face
		glNormal3f( 0.0, 1.0, 0.0);
		glTexCoord2f(0.0, 1.0); glVertex3f(-1.0*size_x,  1.0*size_y, -1.0*size_z);
		glTexCoord2f(0.0, 0.0); glVertex3f( 1.0*size_x,  1.0*size_y, -1.0*size_z);
		glTexCoord2f(1.0, 0.0); glVertex3f( 1.0*size_x,  1.0*size_y,  1.0*size_z);
		glTexCoord2f(1.0, 1.0); glVertex3f(-1.0*size_x,  1.0*size_y,  1.0*size_z);
	glEnd;
	glBindTexture(GL_TEXTURE_2D, CubeTex_L);
	glBegin(GL_QUADS);	
		// Left Face
		glNormal3f( -1.0, 0.0, 0.0);
		glTexCoord2f(0.0, 0.0); glVertex3f(-1.0*size_x, -1.0*size_y, -1.0*size_z);
		glTexCoord2f(0.0, 1.0); glVertex3f(-1.0*size_x,  1.0*size_y, -1.0*size_z);
		glTexCoord2f(1.0, 1.0); glVertex3f(-1.0*size_x,  1.0*size_y,  1.0*size_z);
		glTexCoord2f(1.0, 0.0); glVertex3f(-1.0*size_x, -1.0*size_y,  1.0*size_z);
	glEnd;
	glBindTexture(GL_TEXTURE_2D, CubeTex_BT);
	glBegin(GL_QUADS);	
		// Bottom Face
		glNormal3f( 0.0, -1.0, 0.0);
		glTexCoord2f(1.0, 1.0); glVertex3f(-1.0*size_x, -1.0*size_y, -1.0*size_z);
		glTexCoord2f(0.0, 1.0); glVertex3f( 1.0*size_x, -1.0*size_y, -1.0*size_z);
		glTexCoord2f(0.0, 0.0); glVertex3f( 1.0*size_x, -1.0*size_y,  1.0*size_z);
		glTexCoord2f(1.0, 0.0); glVertex3f(-1.0*size_x, -1.0*size_y,  1.0*size_z);
	glEnd;
	glBindTexture(GL_TEXTURE_2D, CubeTex_F);
	glBegin(GL_QUADS);	
		// Front Face
		glNormal3f( 0.0, 0.0, 1.0);
		glTexCoord2f(0.0, 0.0); glVertex3f(-1.0*size_x, -1.0*size_y,  1.0*size_z);
		glTexCoord2f(1.0, 0.0); glVertex3f( 1.0*size_x, -1.0*size_y,  1.0*size_z);
		glTexCoord2f(1.0, 1.0); glVertex3f( 1.0*size_x,  1.0*size_y,  1.0*size_z);
		glTexCoord2f(0.0, 1.0); glVertex3f(-1.0*size_x,  1.0*size_y,  1.0*size_z);
	
	glEnd;
	glPolygonMode(GL_FRONT_AND_BACK,mode);
end;

procedure quads_draw(size_x,size_y:GLFloat;Fon: GLuint);
begin
	glBindTexture(GL_TEXTURE_2D, Fon);
	glBegin(GL_QUADS);
			glNormal3f( 0.0, 0.0, 1.0);
			glTexCoord2f(0.0,0.0);glVertex3f(-1.0*size_x,-1.0*size_y,0.0);
			glTexCoord2f(1.0,0.0);glVertex3f(1.0*size_x,-1.0*size_y,0.0);
			glTexCoord2f(1.0,1.0);glVertex3f(1.0*size_x,1.0*size_y,0.0);
			glTexCoord2f(0.0,1.0);glVertex3f(-1.0*size_x, 1.0*size_y,0.0);
	glEnd();
end;

procedure quads_draw_strelka(size_x,size_y:GLFloat;Fon: GLuint);
begin
	glBindTexture(GL_TEXTURE_2D, Fon);
	glBegin(GL_QUADS);
			glNormal3f( 0.0, 0.0, 1.0);
			glTexCoord2f(0.0,0.0);glVertex3f(-1.0*size_x,0.0*size_y,0.0);
			glTexCoord2f(1.0,0.0);glVertex3f(1.0*size_x,0.0*size_y,0.0);
			glTexCoord2f(1.0,1.0);glVertex3f(1.0*size_x,1.0*size_y,0.0);
			glTexCoord2f(0.0,1.0);glVertex3f(-1.0*size_x, 1.0*size_y,0.0);
	glEnd();
end;

procedure tringle_draw(size_x,size_y:GLFloat; Fon: GLuint);
begin
	glBindTexture(GL_TEXTURE_2D, Fon);
	glBegin(GL_TRIANGLES);
			glNormal3f( 0.0, 0.0, 1.0);
			glTexCoord2f(0.0,0.0);glVertex3f(-1.0*size_x,-1.0*size_y,0.0);
			glTexCoord2f(1.0,0.0);glVertex3f(1.0*size_x,-1.0*size_y,0.0);
			glTexCoord2f(1.0,1.0);glVertex3f(1.0*size_x,1.0*size_y,0.0);			
	glEnd();
end;

procedure tringle_draw_2(size_x,size_y:GLFloat; Fon: GLuint);
begin
	glBindTexture(GL_TEXTURE_2D, Fon);
	glBegin(GL_TRIANGLES);
			glNormal3f( 0.0, 0.0, -1.0);
			glTexCoord2f(0.0,0.0);glVertex3f(-1.0*size_x,-1.0*size_y,0.0);
			glTexCoord2f(1.0,0.0);glVertex3f(1.0*size_x,-1.0*size_y,0.0);
			glTexCoord2f(1.0,1.0);glVertex3f(1.0*size_x,1.0*size_y,0.0);			
	glEnd();
end;






end.


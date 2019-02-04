unit models;

interface
uses SysUtils, SDL, gl, glu, glext, glut, text_glut,  text_gl,  ogl_texture, figure, material,menu;

procedure kontakt_draw(material: GLInt; mashtab: glFloat);

procedure key_draw(on_off: glFloat);

procedure big_rezistor_draw(begunok: glFloat; texture: GLUInt);

procedure kontakt_na_provod_draw();

procedure lampa_draw_local(on_off:glFloat; glass_tex,light_tex:GLUInt; lamp_pawer:GLfloat);

procedure rezister_1_draw();

procedure rezister_2_draw();

procedure rezister_3_draw();

procedure pitanie_draw();

procedure provod_draw(x1,z1,x2,z2,y: glFloat);

procedure provolka_draw(amb,dif,spec,shin: glFloat);

procedure perehodnik_draw();

procedure nagrev(skorost,napravlenie: glFloat);

procedure provod_s_kontaktom_draw(r,x1,z1,x2,z2,y,niz: glFloat);

procedure voltmetr_draw(napryajenie:GLFloat;shcala:GLInt;ceferblat,steklo,korpus:GLUInt);

procedure ampermetr_draw(sila_toka:GLFloat;shcala:GLInt;ceferblat,steklo,korpus:GLUInt);

procedure blok_pitaniya_draw(korpus_bp_back,korpus_bp_r,korpus_bp_top,korpus_bp_l,korpus_bp_bt,korpus_bp_face_tex: GLUInt);

procedure polnostiyu_pitanie_draw(korpus_bp_back,korpus_bp_r,korpus_bp_top,korpus_bp_l,korpus_bp_bt,korpus_bp_face_tex: GLUInt);

procedure provod_s_kontaktom_polukrugliy_draw(radius,x,y,z,razbivka: glFloat);

procedure provolka_draw_off(amb,dif,spec,shin: glFloat);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
implementation

procedure podstavka_draw(h,sh,d: glFloat);
begin
glDisable(GL_TEXTURE_2D);
glPushMatrix();
		glEnable(GL_LIGHTING);
		set_material(18);
glTranslatef(0,-h/2,0);
paral_draw(h,sh,d);
		glDisable(GL_LIGHTING);
glPopMatrix();
end;

procedure podstavka_draw_tex(h,sh,d: glFloat);
begin
glEnable(GL_TEXTURE_2D);
glPushMatrix();
		glEnable(GL_LIGHTING);
		set_material(18);
glTranslatef(0,-h/2,0);
paral_draw(h,sh,d);
		glDisable(GL_LIGHTING);
glPopMatrix();
glDisable(GL_TEXTURE_2D);
end;

procedure nagrev(skorost,napravlenie: glFloat);
var amb,dif,spec,shin: glFloat;
begin

if napravlenie=1 then
begin
	if amb<=0.25 then
	begin
	dif:=dif+(0.50754-0.4)/skorost;
	amb:=amb+(0.25-0.19225)/skorost;
	spec:=spec+(0.7746-0.50873)/skorost;
	shin:=shin+(77-51)/skorost;
	end;
end
else
begin
	if amb>=0.19225 then
	begin
	dif:=dif-(0.50754-0.4)/skorost;
	amb:=amb-(0.25-0.19225)/skorost;
	spec:=spec-(0.7746-0.50873)/skorost;
	shin:=shin-(77-51)/skorost;
	end;
end;

end;

procedure provolka_draw(amb,dif,spec,shin: glFloat);
var
amb_m: array[0..3] of glFloat;
dif_m: array[0..3] of glFloat;
spec_m: array[0..3] of glFloat;
begin
glPushMatrix();

		amb_m[0]:=amb;amb_m[1]:=amb;amb_m[2]:=amb;amb_m[3]:=1.0;
		dif_m[0]:=dif;dif_m[1]:=dif;dif_m[2]:=dif;dif_m[3]:=1.0;
		spec_m[0]:=spec;spec_m[1]:=spec;spec_m[2]:=spec;spec_m[3]:=1.0;

		glEnable(GL_LIGHTING);

		glLightfv(GL_LIGHT0,GL_DIFFUSE,@dif_m);
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT,@amb_m);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,@dif_m);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR,@spec_m);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS,@shin);	

//		set_material(4);
glPushMatrix();
glRotatef(-90,0,0,1);
glTranslatef(-0.3,0.0,0.0);
cilindr_draw(16,2*pi(),0.1,0.1,32,32);
glPopMatrix();

glPushMatrix();
glTranslatef(8.0,0.0,0.0);
kontakt_draw(15,0.3);
glPopMatrix();

glPushMatrix();
glTranslatef(-8.0,0.0,0.0);
kontakt_draw(15,0.3);
glPopMatrix();

podstavka_draw(3.5,18,18);

glPopMatrix();	
		glDisable(GL_LIGHTING);
end;

procedure provolka_draw_off(amb,dif,spec,shin: glFloat);
var
amb_m: array[0..3] of glFloat;
dif_m: array[0..3] of glFloat;
spec_m: array[0..3] of glFloat;
begin
glPushMatrix();

		amb_m[0]:=amb;amb_m[1]:=amb;amb_m[2]:=amb;amb_m[3]:=1.0;
		dif_m[0]:=dif;dif_m[1]:=dif;dif_m[2]:=dif;dif_m[3]:=1.0;
		spec_m[0]:=spec;spec_m[1]:=spec;spec_m[2]:=spec;spec_m[3]:=1.0;

		glEnable(GL_LIGHTING);

		glLightfv(GL_LIGHT0,GL_DIFFUSE,@dif_m);
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT,@amb_m);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,@dif_m);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR,@spec_m);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS,@shin);	

//		set_material(4);
glPushMatrix();
glTranslatef(4.0,0.0,-0.9);
glPushMatrix();
glRotatef(-7,0,1,0);
glPushMatrix();
glRotatef(-90,0,0,1);
glTranslatef(-0.3,0.0,0.0);
cilindr_draw(8,2*pi(),0.1,0.1,32,32);
glPopMatrix();
glPopMatrix();
glPopMatrix();

glPushMatrix();
glTranslatef(-4.0,0.0,0.9);
glPushMatrix();
glRotatef(-7,0,1,0);
glPushMatrix();
glRotatef(-90,0,0,1);
glTranslatef(-0.3,0.0,0.0);
cilindr_draw(8,2*pi(),0.1,0.1,32,32);
glPopMatrix();
glPopMatrix();
glPopMatrix();

glPushMatrix();
glTranslatef(8.0,0.0,0.0);
kontakt_draw(15,0.3);
glPopMatrix();

glPushMatrix();
glTranslatef(-8.0,0.0,0.0);
kontakt_draw(15,0.3);
glPopMatrix();

podstavka_draw(3.5,18,18);

glPopMatrix();	
		glDisable(GL_LIGHTING);
end;

procedure provod_draw(x1,z1,x2,z2,y: glFloat);
var h,a: glFloat;
begin

if x1=x2 then
begin
h:=abs(z2-z1)-1.64;
a:=90;
end
else
begin
h:=abs(x2-x1)-1.64;
a:=0;
end;

glPushMatrix();
glTranslatef((x1+x2)/2,y,(z1+z2)/2);

glPushMatrix();
glRotatef(a,0,1,0);

////////////////////////контакты
	glEnable(GL_LIGHTING);
	set_material(23);
glPushMatrix();
glTranslatef((h/2+0.82),0,0);
cilindr_draw(0.2,2*pi(),0.5,0.5,32,6);
cilindr_draw(0.2,2*pi(),0.82,0.82,32,6);
krug_draw(0.5,0.82,2*pi(),5,0.1,6);
krug_draw(0.5,0.82,2*pi(),5,-0.1,6);
glPopMatrix();

glPushMatrix();
glTranslatef(-(h/2+0.82),0,0);
cilindr_draw(0.2,2*pi(),0.5,0.5,32,6);
cilindr_draw(0.2,2*pi(),0.82,0.82,32,6);
krug_draw(0.5,0.82,2*pi(),5,0.1,6);
krug_draw(0.5,0.82,2*pi(),5,-0.1,6);
glPopMatrix();

//////////////////////сам провод
	set_material(22);
glPushMatrix();
glRotatef(90,0,0,1);
cilindr_draw(h,2*pi(),0.1,0.1,32,32);
glPopMatrix();

glPushMatrix();
glRotatef(-90,0,0,1);
cilindr_draw(h,2*pi(),0.1,0.1,32,32);
glPopMatrix();

glPushMatrix();
glRotatef(90,0,1,0);
glTranslatef(0,0,h/2);
shar_draw(0.1,pi(),pi(),32,32);
glPopMatrix();

glPushMatrix();
glRotatef(270,0,1,0);
glTranslatef(0,0,h/2);
shar_draw(0.1,pi(),pi(),32,32);
glPopMatrix();

glPopMatrix();
glPopMatrix();

	glDisable(GL_LIGHTING);
end;

procedure kontakt_draw(material: GLInt; mashtab: glFloat);
begin
glPushMatrix();
	glEnable(GL_LIGHTING);
	set_material(material);
	
glScalef(mashtab/1.6,mashtab,mashtab/1.6);
glTranslatef(0,5.8,0);
glPushMatrix();

	//внешн€€ наклонна€
	glPushMatrix();
	glTranslatef(0,1.2,0);
	cilindr_draw(4.6,2*Pi(),4.2,4.5,30,30);
	glPopMatrix();
	
	//внешн€€ пр€ма€ 1
	glPushMatrix();
	glTranslatef(0,-1.45,0);
	cilindr_draw(0.7,2*Pi(),5,5,30,30);
	glPopMatrix();
	
	//внешн€€ пр€ма€ 2
	glPushMatrix();
	glTranslatef(0,-2.8,0);
	cilindr_draw(2,2*Pi(),4.7,4.7,30,30);
	glPopMatrix();
	
	//внутренний объЄм
	glPushMatrix();
	glTranslatef(0,-0.15,0);
	cilindr_draw(7.3,2*Pi(),3.5,3.5,30,30);
	glPopMatrix();
	
	//стык внешних
	krug_draw(4.5,5,2*Pi,5,-1.1,32);
	krug_draw(4.7,5,2*Pi,5,-1.8,32);
	
	//заворот внешнего
	glPushMatrix();
	glTranslatef(0,3.5,0);
	torus_draw(4.2,3.5,pi(),2*Pi(),32,32);	
	glPopMatrix();
			
	set_material(8);
	
	//контакт
	glPushMatrix();
	glTranslatef(0,-2.15,0);
	cilindr_draw(7.3,2*Pi(),2.5,2.5,30,30);
	cilindr_draw(7.3,2*Pi(),1.8,1.8,30,30);
	glPopMatrix();
	
	//заворот контакта
	glPushMatrix();
	glTranslatef(0,1.5,0);
	torus_draw(2.5,1.8,pi(),2*Pi(),32,32);	
	glPopMatrix();
		
	//дно1
	krug_draw(2.5,5,2*Pi,5,-3.8,32);
	krug_draw(0,1.8,2*Pi,5,-3.8,32);
	
glPopMatrix();
	glDisable(GL_LIGHTING);
glPopMatrix();
end;

procedure perehodnik_draw();
begin
podstavka_draw(3.5,18,18);
kontakt_draw(15,0.3);
end;

procedure key_draw(on_off: glFloat);
begin
glPushMatrix();
glScalef(1.5,1.5,1.5);

glPushMatrix();
		glEnable(GL_LIGHTING);
		set_material(11);
glTranslatef(-3,0.05,0);
paral_draw(0.1,0.5,4);
		glDisable(GL_LIGHTING);
glPopMatrix();

glPushMatrix();
		glEnable(GL_LIGHTING);
		set_material(11);
glTranslatef(3,0.05,0);
paral_draw(0.1,0.5,4);
		glDisable(GL_LIGHTING);
glPopMatrix();

glPushMatrix();
glTranslatef(0,0.1,0);
		glEnable(GL_LIGHTING);
		set_material(0);
		
glPushMatrix();
glTranslatef(-0.6,0.05,-1.7);
		glRotatef(60,0.0, 1.0, 0.0);
glTranslatef(-1.7,0,0);
	paral_draw(0.1,1,1.5);
glTranslatef(1.7,0,0);
			glRotatef(30,0.0, 0.0, 1.0);
			glTranslatef(0,0.575,0);
				paral_draw(0.1,1,2);
			glTranslatef(0,-0.575,0);
			glRotatef(-30,0.0, 0.0, 1.0);
		glRotatef(-60,0.0, 1.0, 0.0);
glTranslatef(0.6,-0.05,1.7);
		glDisable(GL_LIGHTING);
glPopMatrix();

glPushMatrix();
glTranslatef(-1.55,0.122,0);
		glEnable(GL_LIGHTING);
		set_material(1);
cilindr_draw(0.04,2*Pi(),0.4,0.4,32,32);
krug_draw(0.02,0.5,2*pi(),5,0.02,32);
		set_material(8);
shar_draw(0.25,pi()/2,2*pi(),32,32);
		glDisable(GL_LIGHTING);
glPopMatrix();

glPushMatrix();
glTranslatef(1.55,0.122,0);
		glEnable(GL_LIGHTING);
		set_material(1);
cilindr_draw(0.04,2*Pi(),0.4,0.4,32,32);
krug_draw(0.02,0.5,2*pi(),5,0.02,32);
		set_material(8);
shar_draw(0.25,pi()/2,2*pi(),32,32);
		glDisable(GL_LIGHTING);
glPopMatrix();

if on_off=1 then
begin
glPushMatrix();
		glEnable(GL_LIGHTING);
		set_material(0);
glRotatef(-30,0.0, 1.0, 0.0);
glTranslatef(-1,0.05,-0.78);
paral_draw(0.1,1,6);
		glDisable(GL_LIGHTING);
glPopMatrix();

glPushMatrix();
		glEnable(GL_LIGHTING);
		set_material(15);
glTranslatef(-2.7,0.25,-2.415);
cilindr_draw(0.3,2*pi(),0.4,0.4,32,32);
krug_draw(0.4,0.9,2*pi(),32,0.15,32);
glTranslatef(0,1.84,0);
cilindr_draw(3.6,2*pi(),0.6,0.9,32,32);
glTranslatef(0,-1.84,0);
glTranslatef(0,2.955,0);
shar_draw(0.91,pi()/4.5,2*pi(),32,32);
		glDisable(GL_LIGHTING);
glPopMatrix();
end
else
begin
glPushMatrix();
glRotatef(-50,0.0, 1.0, 0.0);
glTranslatef(-0.7,0,-1.3);

glPushMatrix();
		glEnable(GL_LIGHTING);
		set_material(0);
glRotatef(-30,0.0, 1.0, 0.0);
glTranslatef(-1,0.05,-0.75);
paral_draw(0.1,1,6);
		glDisable(GL_LIGHTING);
glPopMatrix();

glPushMatrix();
		glEnable(GL_LIGHTING);
		set_material(15);
glTranslatef(-2.7,0.25,-2.415);
cilindr_draw(0.3,2*pi(),0.4,0.4,32,32);
krug_draw(0.4,0.9,2*pi(),32,0.15,32);
glTranslatef(0,1.84,0);
cilindr_draw(3.6,2*pi(),0.6,0.9,32,32);
glTranslatef(0,-1.84,0);
glTranslatef(0,2.955,0);
shar_draw(0.91,pi()/4.5,2*pi(),32,32);
		glDisable(GL_LIGHTING);
glPopMatrix();

glPopMatrix();
end;
glPopMatrix();

glPushMatrix();
glTranslatef(5,0,0);
kontakt_draw(15,0.2);
glPopMatrix();

glPushMatrix();
glTranslatef(-5,0,0);
kontakt_draw(15,0.2);
glPopMatrix();

glPopMatrix();

podstavka_draw(3.5,18,18);
end;

procedure big_rezistor_draw(begunok: glFloat; texture: GLUInt);
begin
glPushMatrix();

glEnable(GL_LIGHTING);

glScalef(2.1,2.1,2.1);
glTranslatef(0,1.5,0);
//////////////////////////////////////////////////////////////////////////основа
glPushMatrix();
glRotatef(90,0,0,1);
glTranslatef(0.8,0,0);

	set_material(8);
//cilindr_draw(8,2*pi(),0.8,0.8,32,32);
glPushMatrix();
glRotatef(-90,0,0,1);
spiral_draw(0.8,0.05,8.2,90,32,32,1);
glPopMatrix();
	
		set_material(16);
	glPushMatrix();
	glTranslatef(0,4.35,0);
	cilindr_draw(0.7,2*pi(),0.8,0.8,8,32);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0,4.7,0);
	krug_draw(0.75,0.81,2*pi(),5,0,32);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(0,-4.35,0);
	cilindr_draw(0.7,2*pi(),0.8,0.8,8,32);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0,-4.7,0);
	krug_draw(0.75,0.81,2*pi(),5,0,32);
	glPopMatrix();
	
		set_material(12);
	glPushMatrix();
	glTranslatef(0,4.85,0);
	cilindr_draw(0.3,2*pi(),0.75,0.75,2,32);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(0,-4.85,0);
	cilindr_draw(0.3,2*pi(),0.75,0.75,2,32);
	glPopMatrix();

glPopMatrix();

	set_material(16);
glPushMatrix();
glTranslatef(-4.35,-0.35,0);
paral_draw(0.7,0.4,0.7);
glPopMatrix();

glPushMatrix();
glTranslatef(4.35,-0.35,0);
paral_draw(0.7,0.4,0.7);
glPopMatrix();

	set_material(7);
glPushMatrix();
glRotatef(90,0,0,1);
glTranslatef(2.5,0,0);
cilindr_draw(11,2*pi(),0.1,0.1,32,32);
glPopMatrix();
////////////////////////////////////////////////////////////////////////бегунок
glPushMatrix();

	set_material(16);
glTranslatef(begunok,0,0);
glPushMatrix();
glTranslatef(0,2,0);
paral_draw(0.05,1.6,0.65);
glPopMatrix();

glPushMatrix();
glTranslatef(0,1.42,0.825);
paral_draw(1.2,0.05,0.65);
glPopMatrix();

glPushMatrix();
glTranslatef(0,1.42,-0.825);
paral_draw(1.2,0.05,0.65);
glPopMatrix();

	set_material(0);
glPushMatrix();
glTranslatef(0,2.78,0);
paral_draw(1.5,1.6,2.2);
glPopMatrix();

glPopMatrix();
////////////////////////////////////////////////////////////////////////боковушки
//1
glPushMatrix();
glRotatef(90,0,0,1);
glTranslatef(0.8,5.1,0);
cilindr_draw(0.2,2*pi(),0.95,0.95,32,32);
glPopMatrix();

glPushMatrix();
glRotatef(90,0,0,1);
glTranslatef(0.8,-5.1,0);
cilindr_draw(0.2,2*pi(),0.95,0.95,32,32);
glPopMatrix();

glPushMatrix();
glRotatef(90,0,0,1);
glTranslatef(0.8,-5,0);
krug_draw(0.75,0.985,2*pi(),5,0,32);
glPopMatrix();

glPushMatrix();
glRotatef(90,0,0,1);
glTranslatef(0.8,5,0);
krug_draw(0.75,0.985,2*pi(),5,0,32);
glPopMatrix();
//

//крылышки
glPushMatrix();
glTranslatef(5.075,0.8,-0.95);
paral_draw(0.68,0.15,0.15);
glPopMatrix();

glPushMatrix();
glTranslatef(5.075,0.8,0.95);
paral_draw(0.68,0.15,0.15);
glPopMatrix();

glPushMatrix();
glTranslatef(-5.075,0.8,-0.95);
paral_draw(0.68,0.15,0.15);
glPopMatrix();

glPushMatrix();
glTranslatef(-5.075,0.8,0.95);
paral_draw(0.68,0.15,0.15);
glPopMatrix();
//

//2
glPushMatrix();
glTranslatef(-5.225,0.2,0);
paral_draw(2.2,2.05,0.15);
glPopMatrix();

glPushMatrix();
glRotatef(90,0.0, 1.0, 0.0);
glRotatef(-90,1.0, 0.0, 0.0);
glTranslatef(0,5.225,1.3);
cilindr_draw(0.15,pi(),1.025,1.025,32,32);
	glPushMatrix();
	glTranslatef(0,-0.075,0);
	krug_draw(0,1.28125,pi(),5,0,32);
	glTranslatef(0,0.15,0);
	krug_draw(0,1.28125,pi(),5,0,32);
	glPopMatrix();
glPopMatrix();

glPushMatrix();
glTranslatef(5.225,0.2,0);
paral_draw(2.2,2.05,0.15);
glPopMatrix();


glPushMatrix();
glRotatef(90,0.0, 1.0, 0.0);
glRotatef(-90,1.0, 0.0, 0.0);
glTranslatef(0,-5.225,1.3);
cilindr_draw(0.15,pi(),1.025,1.025,32,32);
	glPushMatrix();
	glTranslatef(0,-0.075,0);
	krug_draw(0,1.28125,pi(),5,0,32);
	glTranslatef(0,0.15,0);
	krug_draw(0,1.28125,pi(),5,0,32);
	glPopMatrix();
glPopMatrix();
/////////////////////
glPushMatrix();
glTranslatef(5.225,2.2,0);
paral_draw(0.4,1.35,0.15);
glPopMatrix();


glPushMatrix();
glRotatef(90,0.0, 1.0, 0.0);
glRotatef(-90,1.0, 0.0, 0.0);
glTranslatef(0,-5.225,2.4);
cilindr_draw(0.15,pi(),0.675,0.675,32,32);
	glPushMatrix();
	glTranslatef(0,-0.075,0);
	krug_draw(0,0.84375,pi(),5,0,32);
	glTranslatef(0,0.15,0);
	krug_draw(0,0.84375,pi(),5,0,32);
	glPopMatrix();
glPopMatrix();

glPushMatrix();
glTranslatef(-5.225,2.2,0);
paral_draw(0.4,1.35,0.15);
glPopMatrix();

glPushMatrix();
glRotatef(90,0.0, 1.0, 0.0);
glRotatef(-90,1.0, 0.0, 0.0);
glTranslatef(0,5.225,2.4);
cilindr_draw(0.15,pi(),0.675,0.675,32,32);
	glPushMatrix();
	glTranslatef(0,-0.075,0);
	krug_draw(0,0.84375,pi(),5,0,32);
	glTranslatef(0,0.15,0);
	krug_draw(0,0.84375,pi(),5,0,32);
	glPopMatrix();
glPopMatrix();

////////
glPushMatrix();
glRotatef(90,0,0,1);
glTranslatef(2.5,5.3,0);
torus_draw(0.3,0.15,pi(),pi()*2,32,32);
glPopMatrix();

glPushMatrix();
glRotatef(270,0,0,1);
glTranslatef(-2.5,5.3,0);
torus_draw(0.3,0.15,pi(),pi()*2,32,32);
glPopMatrix();

glPushMatrix();
glRotatef(90,0,0,1);
glTranslatef(0.8,5.3,0);
torus_draw(0.3,0.15,pi(),pi()*2,32,32);
glPopMatrix();
glPushMatrix();
glRotatef(90,0,0,1);
glTranslatef(0.8,5.385,0);
cilindr_draw(0.17,pi()*2,0.1,0.1,16,16);
glPopMatrix();

glPushMatrix();
glRotatef(270,0,0,1);
glTranslatef(-0.8,5.3,0);
torus_draw(0.3,0.15,pi(),pi()*2,32,32);
glPopMatrix();
glPushMatrix();
glRotatef(90,0,0,1);
glTranslatef(0.8,-5.385,0);
cilindr_draw(0.17,pi()*2,0.1,0.1,16,16);
glTranslatef(0,-0.085,0);
krug_draw(0,0.125,2*pi(),5,0,16);
glPopMatrix();
////////

glPushMatrix();
glTranslatef(5.8,-0.8,0);
paral_draw(0.2,2.05,1);
glPopMatrix();

glPushMatrix();
glTranslatef(-5.8,-0.8,0);
paral_draw(0.2,2.05,1);
glPopMatrix();

////////
glPushMatrix();
glRotatef(90,1,0,0);
glRotatef(90,0,1,0);
glTranslatef(-0.7,0.975,5.3);
cilindr_draw(0.1,pi()/2,0.7,0.7,16,1);
krug_draw(0,0.93,pi()/2,4,-0.05,1);
krug_draw(0,0.93,pi()/2,4,0.05,1);
glPopMatrix();

glPushMatrix();
glRotatef(90,1,0,0);
glRotatef(90,0,1,0);
glTranslatef(-0.7,-0.975,5.3);
cilindr_draw(0.1,pi()/2,0.7,0.7,16,1);
krug_draw(0,0.93,pi()/2,4,-0.05,1);
krug_draw(0,0.93,pi()/2,4,0.05,1);
glPopMatrix();

glPushMatrix();
glRotatef(90,1,0,0);
glRotatef(180,0,1,0);
glTranslatef(5.3,0.975,-0.7);
cilindr_draw(0.1,pi()/2,0.7,0.7,16,1);
krug_draw(0,0.93,pi()/2,4,-0.05,1);
krug_draw(0,0.93,pi()/2,4,0.05,1);
glPopMatrix();

glPushMatrix();
glRotatef(90,1,0,0);
glRotatef(180,0,1,0);
glTranslatef(5.3,-0.975,-0.7);
cilindr_draw(0.1,pi()/2,0.7,0.7,16,1);
krug_draw(0,0.93,pi()/2,4,-0.05,1);
krug_draw(0,0.93,pi()/2,4,0.05,1);
glPopMatrix();

glPushMatrix();
glRotatef(90,0,0,1);
glTranslatef(0.8,5.4625,0);
kontakt_draw(15,0.125);
glPopMatrix();

glPushMatrix();
glRotatef(-90,0,0,1);
glTranslatef(-2.5,5.4625,0);
kontakt_draw(15,0.125);
glPopMatrix();

////////шайбы
////лев
	glEnable(GL_LIGHTING);
	set_material(23);
glPushMatrix();
glRotatef(90,0,0,1);
glTranslatef(0.8,5.425,0);
krug_draw(0,0.315,2*pi(),5,0.0375,6);
cilindr_draw(0.075,2*pi(),0.25,0.25,2,6);
krug_draw(0,0.315,2*pi(),5,-0.0375,6);
glPopMatrix();

glPushMatrix();
glRotatef(90,0,0,1);
glTranslatef(0.8,5.575,0);
krug_draw(0,0.315,2*pi(),5,0.0375,6);
cilindr_draw(0.075,2*pi(),0.25,0.25,2,6);
krug_draw(0,0.315,2*pi(),5,-0.0375,6);
glPopMatrix();

////прав
//низ
glPushMatrix();
glRotatef(90,0,0,1);
glTranslatef(0.8,-5.4125,0);
krug_draw(0,0.315,2*pi(),5,0.0375,6);
cilindr_draw(0.075,2*pi(),0.25,0.25,2,6);
krug_draw(0,0.315,2*pi(),5,-0.0375,6);
glPopMatrix();

//верх
glPushMatrix();
glRotatef(90,0,0,1);
glTranslatef(2.5,-5.425,0);
krug_draw(0,0.315,2*pi(),5,0.0375,6);
cilindr_draw(0.075,2*pi(),0.25,0.25,2,6);
krug_draw(0,0.315,2*pi(),5,-0.0375,6);
glPopMatrix();

glPushMatrix();
glRotatef(90,0,0,1);
glTranslatef(2.5,-5.575,0);
krug_draw(0,0.315,2*pi(),5,0.0375,6);
cilindr_draw(0.075,2*pi(),0.25,0.25,2,6);
krug_draw(0,0.315,2*pi(),5,-0.0375,6);
glPopMatrix();

glPushMatrix();
glRotatef(90,0,0,1);
glTranslatef(2.5,-5.105,0);
krug_draw(0,0.315,2*pi(),5,0.0375,6);
cilindr_draw(0.075,2*pi(),0.25,0.25,2,6);
krug_draw(0,0.315,2*pi(),5,-0.0375,6);
glPopMatrix();

/////сред
glPushMatrix();
glRotatef(90,1,0,0);
glTranslatef(-4.35,0.2375,0.4);
krug_draw(0,0.315,2*pi(),5,0.0375,6);
cilindr_draw(0.075,2*pi(),0.25,0.25,2,6);
krug_draw(0,0.315,2*pi(),5,-0.0375,6);
glPopMatrix();

glPushMatrix();
glRotatef(90,1,0,0);
glTranslatef(4.35,0.2375,0.4);
krug_draw(0,0.315,2*pi(),5,0.0375,6);
cilindr_draw(0.075,2*pi(),0.25,0.25,2,6);
krug_draw(0,0.315,2*pi(),5,-0.0375,6);
glPopMatrix();

//////////винты
/////нижние
//1

	set_material(1);
glPushMatrix();
glTranslatef(-5.9,-0.7,0);
glPushMatrix();
glTranslatef(0,0.025,0);
krug_draw(0,0.25,2*pi(),5,0.025,16);
cilindr_draw(0.05,2*pi(),0.2,0.2,16,16);
glPopMatrix();

	set_material(8);
glPushMatrix();
glTranslatef(0,0.025,0);
shar_draw(0.12,pi()/2,2*pi(),16,16);
glPopMatrix();
glPopMatrix();

//2

	set_material(1);
glPushMatrix();
glTranslatef(5.9,-0.7,0);
glPushMatrix();
glTranslatef(0,0.025,0);
krug_draw(0,0.25,2*pi(),5,0.025,16);
cilindr_draw(0.05,2*pi(),0.2,0.2,16,16);
glPopMatrix();

	set_material(8);
glPushMatrix();
glTranslatef(0,0.025,0);
shar_draw(0.12,pi()/2,2*pi(),16,16);
glPopMatrix();
glPopMatrix();

////верхние
///1
glPushMatrix();

	set_material(1);
glRotatef(-90,1,0,0);
glTranslatef(4.35,0.2,-0.4);
glPushMatrix();
glTranslatef(0,0.025,0);
krug_draw(0,0.25,2*pi(),5,0.025,16);
cilindr_draw(0.05,2*pi(),0.2,0.2,16,16);
glPopMatrix();

	set_material(8);
glPushMatrix();
glTranslatef(0,0.025,0);
shar_draw(0.12,pi()/2,2*pi(),16,16);
glPopMatrix();

	set_material(8);
glPushMatrix();
glTranslatef(0,-0.35,0);
cilindr_draw(0.92,pi()*2,0.075,0.075,8,16);
krug_draw(0,0.09375,2*pi(),5,-0.35,16);
glPopMatrix();

glPopMatrix();

///2
glPushMatrix();

	set_material(1);
glRotatef(-90,1,0,0);
glTranslatef(-4.35,0.2,-0.4);
glPushMatrix();
glTranslatef(0,0.025,0);
krug_draw(0,0.25,2*pi(),5,0.025,16);
cilindr_draw(0.05,2*pi(),0.2,0.2,16,16);
glPopMatrix();

	set_material(8);
glPushMatrix();
glTranslatef(0,0.025,0);
shar_draw(0.12,pi()/2,2*pi(),16,16);
glPopMatrix();

	set_material(8);
glPushMatrix();
glTranslatef(0,-0.3,0);
cilindr_draw(0.92,pi()*2,0.075,0.075,8,16);
krug_draw(0,0.09375,2*pi(),5,-0.35,16);
glPopMatrix();

glPopMatrix();

	set_material(0);
glPushMatrix();
glTranslatef(0,-1.2,0);
paral_draw(0.6,2.3,13);
glPopMatrix();

glPushMatrix();
glTranslatef(-8,-1.5,3);
kontakt_draw(15,1/7);
glPopMatrix();

glPushMatrix();
glTranslatef(8,-1.5,3);
kontakt_draw(15,1/7);
glPopMatrix();
//////////////////////////////////////////////////////////////////////////////////

///////////////////нижние контакты
	glEnable(GL_LIGHTING);
	set_material(0);
glPushMatrix();
glTranslatef(0,-1.5,0);
paral_draw(0.1,0.8,15.2);
glPopMatrix();

glPushMatrix();
glTranslatef(-8,-1.5,1.5);
paral_draw(0.1,3.8,0.8);
glPopMatrix();

glPushMatrix();
glTranslatef(8,-1.5,1.5);
paral_draw(0.1,3.8,0.8);
glPopMatrix();

glPopMatrix();

glDisable(GL_LIGHTING);

glBindTexture( GL_TEXTURE_2D, texture);
podstavka_draw_tex(3.5,18,36);
end;

procedure kontakt_na_provod_draw();
begin
glPushMatrix();
glScalef(0.5,0.5,0.5);
glTranslatef(0,2,0);

		glEnable(GL_LIGHTING);
		set_material(13);

glPushMatrix();
krug_draw(0.7,1.08,2*pi(),5,2,32);
cilindr_draw(4,2*pi(),1,1.2,32,32);
cilindr_draw(4,2*pi(),0.7,0.7,32,32);
krug_draw(0.7,1.2815,2*pi(),5,-2,32);
glPopMatrix();
		
glPushMatrix();
glTranslatef(0,2.5,0);
krug_draw(0,1.25,2*pi(),5,0.5,6);
cilindr_draw(1,2*pi(),1,1,32,6);
glPopMatrix();

		set_material(1);

glPushMatrix();
glTranslatef(0,5.5,0);
cilindr_draw(5,2*pi(),0.5,0.5,32,32);
glPopMatrix();

glPushMatrix();
glTranslatef(0,8,0);
shar_draw(0.5,pi()/2,2*pi(),32,32);
glPopMatrix();
	
		glDisable(GL_LIGHTING);

glPopMatrix();
end;

procedure lampa_draw_local(on_off:glFloat; glass_tex,light_tex:GLUInt; lamp_pawer:GLfloat);
var lamp_enable:GLBoolean;
begin

if on_off=1 then
begin
lamp_enable:=GL_TRUE;
end
else
begin
lamp_enable:=GL_FALSE;
end;

glDisable(GL_LIGHTING);
glPushMatrix();
glScalef(1.5,1.5,1.5);



//////////////////////////////////////////////////////////всЄ остальное
glPushMatrix();
glTranslatef(5,0,0);
kontakt_draw(15,0.2);
glPopMatrix();

glPushMatrix();
glTranslatef(-5,0,0);
kontakt_draw(15,0.2);
glPopMatrix();

		glEnable(GL_LIGHTING);
		set_material(3);
glPushMatrix();
glTranslatef(0,0.5,0);
cilindr_draw(1,2*pi(),1.2,1.5,32,32);
glPopMatrix();

krug_draw(0,1.5,2*pi(),5,1,32);	
		glDisable(GL_LIGHTING);
/////////////
		glEnable(GL_LIGHTING);
		set_material(0);
glPushMatrix();
paral_draw(0.1,0.8,11);
glPopMatrix();
		glDisable(GL_LIGHTING);
		
glPopMatrix();

podstavka_draw(3.5,18,18);

////////////////////////////////////////////////////////сама лампа


glPushMatrix();
glScalef(0.45,0.45,0.45);
glTranslatef(0,4,0);


//внутрен€€
	glEnable(GL_LIGHTING);
	set_material(8);
		glPushMatrix();
		glTranslatef(0,-2.6,0);
		cilindr_draw(2.8,2*pi(),1.2,1.2,32,32);
		glTranslatef(0,1.4,0);
		shar_draw(1.2,pi()/2,2*pi(),32,32);
		glPopMatrix();

		glPushMatrix();
		glRotatef(15,0,0,1);
		glTranslatef(0,1.5,0);
		glTranslatef(-0.7,0,0);
		cilindr_draw(3.5,2*pi(),0.1,0.1,32,32);
		glTranslatef(0,1.75,0);
		shar_draw(0.1,pi()/2,2*pi(),32,32);
		glPopMatrix();

		glPushMatrix();
		glRotatef(-15,0,0,1);
		glTranslatef(0,1.5,0);
		glTranslatef(0.7,0,0);
		cilindr_draw(3.5,2*pi(),0.1,0.1,32,32);
		glTranslatef(0,1.75,0);
		shar_draw(0.1,pi()/2,2*pi(),32,32);
		glPopMatrix();
		
	set_material(0);
		glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION,@Specular_mat[0]);	
		glPushMatrix();
		glTranslatef(0,3,0);
		glTranslatef(0,0,0);
		spiral_draw(0.3,0.1,3,2.4,16,16,0);
	glDisable(GL_LIGHTING);		
		if lamp_enable=GL_TRUE then
		begin
		glEnable(GL_TEXTURE_2D);
		 glEnable(GL_BLEND);
		 glBlendFunc(GL_SRC_COLOR,GL_DST_ALPHA);
		 glDisable( GL_DEPTH_TEST );
		 glBindTexture(GL_TEXTURE_2D, light_tex);	
		 	glRotatef(-povorot,0,1,0);
		glPushMatrix();
		 //glRotatef(-angle,0.0,1.0,0.0);
		glBegin(GL_QUADS);
		glColor4f(lamp_pawer,lamp_pawer,lamp_pawer, lamp_pawer);	
		glNormal3f( 0.0, 0.0, 1.0);glTexCoord2f(0.0, 0.0); glVertex3f(-10.0, -10.0, 0.0);
		glNormal3f( 0.0, 0.0, 1.0);glTexCoord2f(1.0, 0.0); glVertex3f( 10.0, -10.0,  0.0);
		glNormal3f( 0.0, 0.0, 1.0);glTexCoord2f(1.0, 1.0); glVertex3f( 10.0,  10.0,  0.0);
		glNormal3f( 0.0, 0.0, 1.0);glTexCoord2f(0.0, 1.0); glVertex3f(-10.0,  10.0,  0.0);
		glEnd();
		glPopMatrix();
		glDisable(GL_TEXTURE_2D);
		glDisable(GL_BLEND);	
		glEnable( GL_DEPTH_TEST );		
		end;		

		//glDisable(GL_LIGHTING);

		//внешнее стекло
		 glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, glass_tex);
		glEnable(GL_TEXTURE_GEN_S);     // Enable spherical
 		glEnable(GL_TEXTURE_GEN_T); 
		glEnable( GL_CULL_FACE );
        glEnable(GL_BLEND);
        if lamp_enable=GL_FALSE then
        glBlendFunc(GL_SRC_COLOR,GL_SRC_ALPHA);
        glCullFace( GL_FRONT );	
      
	glEnable(GL_LIGHTING);
	set_material(0);
		glPushMatrix();
		
		glPushMatrix();
		glTranslatef(0,-2,0);
		garmonichniy_cilindr_draw(4,2*pi(),1.5,32,32,0.00996,1);
		glPopMatrix();
		       
		glPushMatrix();
		glTranslatef(0,1.8,0);
		shar_draw(3.3,2*pi()/3,2*pi,32,32);		
		glPopMatrix();
		
		glCullFace( GL_BACK );
		
		glPushMatrix();		
		glTranslatef(0,-2,0);
		garmonichniy_cilindr_draw(4,2*pi(),1.5,32,32,0.00996,1);
		glPopMatrix();    
		    
		glPushMatrix();
		glTranslatef(0,1.8,0);
		shar_draw(3.3,2*pi()/3,2*pi,32,32);		
		glPopMatrix();
		
		glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION,@Emission_Light);	
	glDisable(GL_LIGHTING);
		glDisable( GL_CULL_FACE );
		glDisable(GL_BLEND);	
		glDisable(GL_TEXTURE_2D);
		glDisable(GL_TEXTURE_GEN_S);
   		glDisable(GL_TEXTURE_GEN_T);
		glPopMatrix();
glPopMatrix();

glPopMatrix();

end;

procedure rezister_1_draw();
begin
glPushMatrix();
glTranslatef(0,0.25,0);

glPushMatrix();
glTranslatef(6,0,0);
kontakt_draw(15,0.3);
glPopMatrix();

		glEnable(GL_LIGHTING);
		set_material(6);

glPushMatrix();
glRotatef(180,0,1,0);
glTranslatef(5.3,0.2,0);
torus_draw(0.5,0.3,2*pi(),pi(),16,16);
glPopMatrix();

glPushMatrix();
glRotatef(90,1,0,0);
glTranslatef(0,0,-1.4);
spiral_draw(1.3,0.1,10,7.915,32,32,0);
glPopMatrix();

glPushMatrix();
glTranslatef(5.3,0.2,0);
torus_draw(0.5,0.3,2*pi(),pi(),16,16);
glPopMatrix();

glPushMatrix();
glTranslatef(-6,0,0);
kontakt_draw(15,0.3);
glPopMatrix();

		glEnable(GL_LIGHTING);
		set_material(12);

glPushMatrix();
glTranslatef(0,0.-0.125,0);
paral_draw(0.25,5,16);
glPopMatrix();
		
		glDisable(GL_LIGHTING);
		
glPopMatrix();

podstavka_draw(3.5,18,18);
end;

procedure rezister_2_draw();
begin
glPushMatrix();
glTranslatef(0,0.25,0);

glPushMatrix();
glTranslatef(6,0,0);
kontakt_draw(15,0.3);
glPopMatrix();

		glEnable(GL_LIGHTING);
		set_material(6);

glPushMatrix();
glRotatef(180,0,2,0);
glTranslatef(5.3,0.2,0);
torus_draw(0.5,0.3,2*pi(),pi(),16,16);
glPopMatrix();

glPushMatrix();
glRotatef(90,1,0,0);
glTranslatef(0,0,-1.6);
spiral_draw(1.5,0.1,10,9.894,32,32,0);
glPopMatrix();

glPushMatrix();
glTranslatef(5.3,0.2,0);
torus_draw(0.5,0.3,2*pi(),pi(),16,16);
glPopMatrix();

glPushMatrix();
glTranslatef(-6,0,0);
kontakt_draw(15,0.3);
glPopMatrix();

		glEnable(GL_LIGHTING);
		set_material(12);

glPushMatrix();
glTranslatef(0,0.-0.125,0);
paral_draw(0.25,5,16);
glPopMatrix();

		glDisable(GL_LIGHTING);

glPopMatrix();

podstavka_draw(3.5,18,18);
end;

procedure rezister_3_draw();
begin
glPushMatrix();
glTranslatef(0,0.25,0);

glPushMatrix();
glTranslatef(6,0,0);
kontakt_draw(15,0.3);
glPopMatrix();

		glEnable(GL_LIGHTING);
		set_material(6);

glPushMatrix();
glRotatef(180,0,2,0);
glTranslatef(5.3,0.2,0);
torus_draw(0.5,0.3,2*pi(),pi(),16,16);
glPopMatrix();

glPushMatrix();
glRotatef(90,1,0,0);
glTranslatef(0,0,-1.9);
spiral_draw(1.8,0.1,10,12.861,32,32,0);
glPopMatrix();

glPushMatrix();
glTranslatef(5.3,0.2,0);
torus_draw(0.5,0.3,2*pi(),pi(),16,16);
glPopMatrix();

glPushMatrix();
glTranslatef(-6,0,0);
kontakt_draw(15,0.3);
glPopMatrix();

		glEnable(GL_LIGHTING);
		set_material(12);

glPushMatrix();
glTranslatef(0,0.-0.125,0);
paral_draw(0.25,5,16);
glPopMatrix();

		glDisable(GL_LIGHTING);

glPopMatrix();

podstavka_draw(3.5,18,18);
end;

procedure pitanie_draw();
begin
glPushMatrix();
glTranslatef(7,0,0);
kontakt_draw(22,0.3);
glPopMatrix();

glPushMatrix();
glTranslatef(-7,0,0);
kontakt_draw(15,0.3);
glPopMatrix();

podstavka_draw(3.5,18,18);
end;

procedure provod_s_kontaktom_draw(r,x1,z1,x2,z2,y,niz: glFloat);
var h: glFloat;
begin

h:=abs(x2-x1)+abs(z2-z1);

glPushMatrix();
glTranslatef((x1+x2)/2,y,(z1+z2)/2);

///стык 1
glPushMatrix();
glTranslatef(-h/2,0,0);

glPushMatrix();
glRotatef(180,1,0,0);
kontakt_na_provod_draw();
glPopMatrix();

		glEnable(GL_LIGHTING);
		set_material(22);
glPushMatrix();
glTranslatef(0,0,r-0.1);
glPushMatrix();
glRotatef(-90,1,0,0);
glRotatef(90,0,0,1);
torus_draw(r,r-0.2,2*pi(),pi(),32,32);
glPopMatrix();
glPopMatrix();

glPushMatrix();
glTranslatef(0,-niz/2,2*r-0.2);
cilindr_draw(niz,2*pi(),0.1,0.1,32,32);
glPopMatrix();

glPushMatrix();
glTranslatef(2.9,-niz,2*r-0.2);
glPushMatrix();
glRotatef(90,1,0,0);
glRotatef(-90,0,1,0);
torus_draw(3,2.8,2*pi(),pi()/2,32,32);
glPopMatrix();
glPopMatrix();

glPopMatrix();

///стык 2
glPushMatrix();
glTranslatef(h/2,0,0);

glPushMatrix();
glRotatef(180,1,0,0);
kontakt_na_provod_draw();
glPopMatrix();

		glEnable(GL_LIGHTING);
		set_material(22);
glPushMatrix();
glTranslatef(0,0,r-0.1);
glPushMatrix();
glRotatef(-90,1,0,0);
glRotatef(90,0,0,1);
torus_draw(r,r-0.2,2*pi(),pi(),32,32);
glPopMatrix();
glPopMatrix();

glPushMatrix();
glTranslatef(0,-niz/2,2*r-0.2);
cilindr_draw(niz,2*pi(),0.1,0.1,32,32);
glPopMatrix();

glPushMatrix();
glTranslatef(-2.9,-niz,2*r-0.2);
glPushMatrix();
glRotatef(90,1,0,0);
torus_draw(3,2.8,2*pi(),pi()/2,32,32);
glPopMatrix();
glPopMatrix();

glPopMatrix();

//провод
glPushMatrix();
glTranslatef(0,-2.9-niz,2*r-0.2);

glPushMatrix();
glRotatef(90,0,0,1);
cilindr_draw(h-5.8,2*pi(),0.1,0.1,32,32);
glPopMatrix();

glPushMatrix();
glRotatef(-90,0,0,1);
cilindr_draw(h-5.8,2*pi(),0.1,0.1,32,32);
glPopMatrix();

glPopMatrix();
		glDisable(GL_LIGHTING);
glPopMatrix();
end;

procedure voltmetr_draw(napryajenie:GLFloat;shcala:GLInt;ceferblat,steklo,korpus:GLUInt);
var
angle_strelka:GLFloat;
begin

if napryajenie>6 then
napryajenie:=6;
	
glPushMatrix();
glTranslatef(6,0,0);
kontakt_draw(15,0.3);
glPopMatrix();

glPushMatrix();
glTranslatef(-6,0,0);
kontakt_draw(22,0.3);
glPopMatrix();

glPushMatrix();
glTranslatef(-3,0,0);
kontakt_draw(22,0.3);
glPopMatrix();

glPushMatrix();
glTranslatef(0.0,6.4,-14.0);
		glEnable(GL_LIGHTING);
		set_material(3);
glEnable(GL_TEXTURE_2D);
case shcala of
0:angle_strelka:=19-napryajenie*9.0;
1:angle_strelka:=19-napryajenie*18.0;
else
angle_strelka:=19-napryajenie*9.0;
end;
glPushMatrix();
glTranslatef(0.05*4,-1.1*4,2.5*4);
glRotatef(-35, 1.0, 0.0, 0.0);
glRotatef(angle_strelka, 0.0, 0.0, 1.0);
quads_draw_strelka(0.02*4,3.2*4, korpus);
glPopMatrix();

glEnable(GL_BLEND);	
//glDisable(GL_DEPTH_TEST);
glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
glPushMatrix();
glTranslatef(0.0*4,0.2*4,1.607*4);
glRotatef(-35, 1.0, 0.0, 0.0);
Cube_draw_ext(2, 2.0*4,2.0*4,0.08*4, ceferblat,korpus,korpus,korpus,korpus,steklo);
glPopMatrix();
glDisable(GL_BLEND);
//glEnable(GL_DEPTH_TEST);

glPushMatrix();
Cube_draw_ext(2, 2.0*4,2.0*4,0.25*4, korpus,korpus,korpus,korpus,korpus,korpus);
glPopMatrix();

glPushMatrix();
glTranslatef(0.0*4,-1.8*4,2.5*4);
Cube_draw_ext(2, 2.0*4,0.2*4,2.25*4, korpus,korpus,korpus,korpus,korpus,korpus);
glPopMatrix();

glPushMatrix();
glTranslatef(0.0*4,0.2*4,1.51*4);
glRotatef(-35, 1.0, 0.0, 0.0);
quads_draw(2.0*4,2.198*4, korpus);
glPopMatrix();

glPushMatrix();
glTranslatef(2.0*4,0.2*4,1.51*4);
glRotatef(90, 0.0, 1.0, 0.0);
tringle_draw(1.26*4,1.8*4, korpus);
glPopMatrix();

glPushMatrix();
glTranslatef(-2.0*4,0.2*4,1.51*4);
glRotatef(90, 0.0, 1.0, 0.0);
tringle_draw_2(1.26*4,1.8*4, korpus);
glPopMatrix();
glDisable(GL_TEXTURE_2D);

glPopMatrix();

//ножки
		glEnable(GL_LIGHTING);
		set_material(15);
glPushMatrix();
glTranslatef(6,-2.1,3);
cilindr_draw(2.9,2*pi(),0.5,0.5,32,32);
glPopMatrix();

glPushMatrix();
glTranslatef(6,-2.1,-12);
cilindr_draw(2.9,2*pi(),0.5,0.5,32,32);
glPopMatrix();

glPushMatrix();
glTranslatef(-6,-2.1,3);
cilindr_draw(2.9,2*pi(),0.5,0.5,32,32);
glPopMatrix();

glPushMatrix();
glTranslatef(-6,-2.1,-12);
cilindr_draw(2.9,2*pi(),0.5,0.5,32,32);
glPopMatrix();
		glDisable(GL_LIGHTING);

end;

procedure ampermetr_draw(sila_toka:GLFloat;shcala:GLInt;ceferblat,steklo,korpus:GLUInt);
var
angle_strelka:GLFloat;
begin

if sila_toka>3 then
sila_toka:=3;

glPushMatrix();
glTranslatef(6,0,0);
kontakt_draw(15,0.3);
glPopMatrix();

glPushMatrix();
glTranslatef(-6,0,0);
kontakt_draw(22,0.3);
glPopMatrix();

glPushMatrix();
glTranslatef(-3,0,0);
kontakt_draw(22,0.3);
glPopMatrix();

glPushMatrix();
glTranslatef(0.0,6.4,-14.0);
		glEnable(GL_LIGHTING);
		set_material(3);
glEnable(GL_TEXTURE_2D);
case shcala of
0:angle_strelka:=19-sila_toka*18.0;
1:angle_strelka:=19-sila_toka*90.0;
else
angle_strelka:=19-sila_toka*18.0;
end;
glPushMatrix();
glTranslatef(0.05*4,-1.1*4,2.5*4);
glRotatef(-35, 1.0, 0.0, 0.0);
glRotatef(angle_strelka, 0.0, 0.0, 1.0);
quads_draw_strelka(0.02*4,3.2*4, korpus);
glPopMatrix();

glEnable(GL_BLEND);	
//glDisable(GL_DEPTH_TEST);
glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
glPushMatrix();
glTranslatef(0.0*4,0.2*4,1.607*4);
glRotatef(-35, 1.0, 0.0, 0.0);
Cube_draw_ext(2, 2.0*4,2.0*4,0.08*4, ceferblat,korpus,korpus,korpus,korpus,steklo);
glPopMatrix();
glDisable(GL_BLEND);
//glEnable(GL_DEPTH_TEST);

glPushMatrix();
Cube_draw_ext(2, 2.0*4,2.0*4,0.25*4, korpus,korpus,korpus,korpus,korpus,korpus);
glPopMatrix();

glPushMatrix();
glTranslatef(0.0*4,-1.8*4,2.5*4);
Cube_draw_ext(2, 2.0*4,0.2*4,2.25*4, korpus,korpus,korpus,korpus,korpus,korpus);
glPopMatrix();

glPushMatrix();
glTranslatef(0.0*4,0.2*4,1.51*4);
glRotatef(-35, 1.0, 0.0, 0.0);
quads_draw(2.0*4,2.198*4, korpus);
glPopMatrix();

glPushMatrix();
glTranslatef(2.0*4,0.2*4,1.51*4);
glRotatef(90, 0.0, 1.0, 0.0);
tringle_draw(1.26*4,1.8*4, korpus);
glPopMatrix();

glPushMatrix();
glTranslatef(-2.0*4,0.2*4,1.51*4);
glRotatef(90, 0.0, 1.0, 0.0);
 tringle_draw_2(1.26*4,1.8*4, korpus);
glPopMatrix();
glDisable(GL_TEXTURE_2D);

glPopMatrix();

//ножки
		glEnable(GL_LIGHTING);
		set_material(15);
glPushMatrix();
glTranslatef(6,-2.1,3);
cilindr_draw(2.9,2*pi(),0.5,0.5,32,32);
glPopMatrix();

glPushMatrix();
glTranslatef(6,-2.1,-12);
cilindr_draw(2.9,2*pi(),0.5,0.5,32,32);
glPopMatrix();

glPushMatrix();
glTranslatef(-6,-2.1,3);
cilindr_draw(2.9,2*pi(),0.5,0.5,32,32);
glPopMatrix();

glPushMatrix();
glTranslatef(-6,-2.1,-12);
cilindr_draw(2.9,2*pi(),0.5,0.5,32,32);
glPopMatrix();
		glDisable(GL_LIGHTING);

end;

procedure blok_pitaniya_draw(korpus_bp_back,korpus_bp_r,korpus_bp_top,korpus_bp_l,korpus_bp_bt,korpus_bp_face_tex: GLUInt);
begin
		glEnable(GL_LIGHTING);
		set_material(3);
glPushMatrix();
//glScalef(0.2,0.2,0.2);

glEnable(GL_TEXTURE_2D);
glPushMatrix();
glTranslatef(0.0,10.0,0.0);
Cube_draw_ext(2,7,10,10,korpus_bp_back,korpus_bp_r,korpus_bp_top,korpus_bp_l,korpus_bp_bt,korpus_bp_face_tex);
glPopMatrix();

glPushMatrix();
glRotatef(90,0,1,0);
glRotatef(-90,1,0,0);
glTranslatef(0.0,0.0,20.0);
torus_draw(5,3,2*pi(),pi(),32,32);
glPopMatrix();

glDisable(GL_TEXTURE_2D);

glPushMatrix();
glRotatef(90,1,0,0);
glTranslatef(2.5,10,-8);
	glPushMatrix();
			set_material(19);
		glPushMatrix();
		glTranslatef(0.0,0.5,0.0);
		cilindr_draw(1,2*pi(),1.5,1.5,32,32);
		glPopMatrix();
		
		glPushMatrix();
		glTranslatef(0.0,1.0,0.0);
		shar_draw(1.5,pi()/2,2*pi(),32,32);
		glPopMatrix();

			set_material(8);		
		torus_draw(2,1.5,pi(),2*pi(),32,32);
	glPopMatrix();
glPopMatrix();

glPushMatrix();
glRotatef(90,1,0,0);
glTranslatef(5,10,-4);
kontakt_draw(22,0.3);
glPopMatrix();

glPushMatrix();
glRotatef(90,1,0,0);
glTranslatef(0.8,10,-4);
kontakt_draw(15,0.3);
glPopMatrix();

glPushMatrix();
glRotatef(90,1,0,0);
glTranslatef(-4,10,-4);
kontakt_draw(15,0.3);
glPopMatrix();

glPushMatrix();
glRotatef(90,1,0,0);
glTranslatef(-4,10,-8);
kontakt_draw(22,0.3);
glPopMatrix();

glPopMatrix();
		glDisable(GL_LIGHTING);
end;

procedure polnostiyu_pitanie_draw(korpus_bp_back,korpus_bp_r,korpus_bp_top,korpus_bp_l,korpus_bp_bt,korpus_bp_face_tex: GLUInt);
begin
glPushMatrix();
glTranslatef(0.0,-3.5,0.0);

glPushMatrix();
glTranslatef(0.0,3.5,0.0);
pitanie_draw();
glPopMatrix();

glPushMatrix();
glTranslatef(2.0,0.0,-30.0);
blok_pitaniya_draw(korpus_bp_back,korpus_bp_r,korpus_bp_top,korpus_bp_l,korpus_bp_bt,korpus_bp_face_tex);
	glPushMatrix();
	glTranslatef(0.0,4.0,15.5);
	
	glPushMatrix();
	glTranslatef(0.8,0.0,0.0);
	glRotatef(-90,1,0,0);
	kontakt_na_provod_draw();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(5.0,0.0,0.0);
	glRotatef(-90,1,0,0);
	kontakt_na_provod_draw();
	glPopMatrix();
	
	glPopMatrix();
glPopMatrix();

glPushMatrix();
glRotatef(180,0,0,1);
glTranslatef(7.0,-9.0,0.0);
kontakt_na_provod_draw();
glPopMatrix();

glPushMatrix();
glRotatef(180,0,0,1);
glTranslatef(-7.0,-9.0,0.0);
kontakt_na_provod_draw();
glPopMatrix();

//провода
		glEnable(GL_LIGHTING);
		set_material(22);
//1

glPushMatrix();
glRotatef(90,0,0,1);
glRotatef(90,0,1,0);
glTranslatef(4.9,-7.0,9.0);
torus_draw(5,4.8,2*pi(),pi(),32,32);
glPopMatrix();

glPushMatrix();
glRotatef(-90,0,0,1);
glTranslatef(-9.0,7.0,-14.7);
torus_draw(5,4.8,2*pi(),pi()/2,32,32);
glPopMatrix();

//2
glPushMatrix();
glRotatef(90,0,0,1);
glRotatef(90,0,1,0);
glTranslatef(4.9,7.0,8.9);
torus_draw(5,4.8,2*pi(),pi(),32,32);
glPopMatrix();

glPushMatrix();
glTranslatef(0.9,0.0,0.0);

glPushMatrix();
glTranslatef(-3.0,4.0,-14.7);
torus_draw(5,4.8,2*pi(),pi()/2,32,32);
glPopMatrix();

glPushMatrix();
glRotatef(-90,0,1,0);
glRotatef(-90,0,0,1);
glTranslatef(-8.9,-9.8,3.0);
torus_draw(5,4.8,2*pi(),pi()/2,32,32);
glPopMatrix();
glPopMatrix();
		glDisable(GL_LIGHTING);

glPopMatrix();
end;

procedure provod_s_kontaktom_polukrugliy_draw(radius,x,y,z,razbivka: glFloat);
begin
glPushMatrix();
glTranslatef(x,y,z);

glPushMatrix();
glRotatef(180,1,0,0);
glTranslatef(0.0,0.0,radius-0.1);
kontakt_na_provod_draw();
glPopMatrix();

glPushMatrix();
glRotatef(180,1,0,0);
glTranslatef(0.0,0.0,-radius+0.1);
kontakt_na_provod_draw();
glPopMatrix();

if razbivka=0 then
begin
		glEnable(GL_LIGHTING);
		set_material(22);
glPushMatrix();
glRotatef(90,0,0,1);
glRotatef(90,0,1,0);
torus_draw_el(radius,radius-0.2,2*pi(),pi(),32,32,2);
glPopMatrix();
		glDisable(GL_LIGHTING);
end
else
begin
		glEnable(GL_LIGHTING);
		set_material(22);
glPushMatrix();
glRotatef(90,0,0,1);
glRotatef(90,0,1,0);
glTranslatef(radius*(1-1/(2*razbivka)),0.0,0.0);
torus_draw(radius/(2*razbivka),radius/(2*razbivka)-0.2,2*pi(),pi(),32,32);
glPopMatrix();
		
glPushMatrix();
glRotatef(-90,0,0,1);
glRotatef(90,0,1,0);
torus_draw_el(radius-radius/razbivka+0.2,radius-radius/razbivka,2*pi(),pi(),32,32,2);
glPopMatrix();
		
glPushMatrix();
glRotatef(90,0,0,1);
glRotatef(90,0,1,0);
glTranslatef(-radius*(1-1/(2*razbivka)),0.0,0.0);
torus_draw(radius/(2*razbivka),radius/(2*razbivka)-0.2,2*pi(),pi(),32,32);
glPopMatrix();
		glDisable(GL_LIGHTING);
end;

glPopMatrix();
end;

end.

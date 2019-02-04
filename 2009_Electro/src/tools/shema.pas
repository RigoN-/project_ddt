unit shema;
{$MODE delphi}
interface
uses SysUtils, SDL, gl, glu, glext, glut, text_glut,  text_gl,  ogl_texture, models,material;

procedure load_texture_shema();

procedure ogl_on_start_shema();

procedure shema_1(on_off: GLInt);

procedure shema_2(on_off: GLInt);

procedure shema_3(on_off: GLInt);

procedure shema_4(on_off: GLInt);

procedure shema_5(on_off: GLInt);

procedure shema_6(on_off: GLInt);

procedure shema_7(begunok: glFloat; on_off,rezistor: GLInt);

procedure shema_8(begunok: glFloat; on_off: GLInt);

procedure shema_9(begunok: glFloat; on_off: GLInt);

procedure shema_10(begunok: glFloat; on_off: GLInt);

procedure shema_11(on_off: GLInt);

procedure shema_12(voltmetr,on_off: GLInt);

procedure shema_13(on_off: GLInt);

procedure shema_14(on_off: GLInt);

procedure shema_15(on_off: GLInt);

procedure shema_16(on_off: GLInt);

procedure shema_17(on_off: GLInt; begunok,amb,dif,spec,shin: glFloat);

procedure shema_18(on_off: GLInt; begunok: glFloat);

procedure shema_19(on_off: GLInt; amb,dif,spec,shin: glFloat);

procedure shema_20(on_off: GLInt; amb,dif,spec,shin: glFloat);

const
PATH_TEXTURE='../data/textures/';
var
big_rez_tex,glass_tex,light_tex,ceferblat_v_tex,ceferblat_a_tex,steklo_tex,korpus_tex:GLUInt;
korpus_bp_back_tex,korpus_bp_face_tex,korpus_bp_lr_tex,korpus_bp_top_tex:GLUInt;

////////////////////////////////////////////////////////////////////////////////////////////////

implementation

procedure load_texture_shema();
begin
		OGL_Load_Texture(PATH_TEXTURE+'glass.tga', glass_tex, txAnisotropic_16, GL_MODULATE, GL_REPEAT, txNoCompressed,GL_TRUE);
		OGL_Load_Texture(PATH_TEXTURE+'light.bmp', light_tex, txAnisotropic_16, GL_MODULATE, GL_REPEAT, txNoCompressed,GL_TRUE);
		OGL_Load_Texture(PATH_TEXTURE+'volt2.tga', ceferblat_v_tex, txBilinear, GL_MODULATE, GL_REPEAT, txNoCompressed,GL_TRUE);
		OGL_Load_Texture(PATH_TEXTURE+'amper2.tga', ceferblat_a_tex, txBilinear, GL_MODULATE, GL_REPEAT, txNoCompressed,GL_TRUE);
		OGL_Load_Texture(PATH_TEXTURE+'glass_2.tga', steklo_tex, txBilinear, GL_MODULATE, GL_REPEAT, txNoCompressed,GL_TRUE);
		OGL_Load_Texture(PATH_TEXTURE+'korpus.tga', korpus_tex, txBilinear, GL_MODULATE, GL_REPEAT, txNoCompressed,GL_TRUE);
		
		OGL_Load_Texture(PATH_TEXTURE+'korpus_bp_back.tga', korpus_bp_back_tex, txBilinear, GL_MODULATE, GL_REPEAT, txNoCompressed,GL_TRUE);
		OGL_Load_Texture(PATH_TEXTURE+'korpus_bp_face.tga', korpus_bp_face_tex, txBilinear, GL_MODULATE, GL_REPEAT, txNoCompressed,GL_TRUE);
		OGL_Load_Texture(PATH_TEXTURE+'korpus_bp_lr.tga', korpus_bp_lr_tex, txBilinear, GL_MODULATE, GL_REPEAT, txNoCompressed,GL_TRUE);
		OGL_Load_Texture(PATH_TEXTURE+'korpus_bp_top.tga', korpus_bp_top_tex, txBilinear, GL_MODULATE, GL_REPEAT, txNoCompressed,GL_TRUE);
		OGL_Load_Texture(PATH_TEXTURE+'big_rez.bmp', big_rez_tex, txBilinear, GL_MODULATE, GL_REPEAT, txNoCompressed,GL_TRUE);
end;

procedure ogl_on_start_shema();
begin
set_light_model();
   
end;

procedure key_pressed_shema( keysym : PSDL_keysym );
begin
	
end;

procedure shema_1(on_off: GLInt);
begin
glScalef(0.2,0.2,0.2);

provod_draw(-5.4,12,5.4,12,3.9);
provod_draw(-20.5,12,-20.5,-12,3.9);
provod_draw(-6.5,-12,20.55,-12,3.9);
provod_draw(20.55,12,20.55,-12,3.9);

glTranslatef(0,3.5,0);

glPushMatrix();
glTranslatef(-13.5,0,-12);
polnostiyu_pitanie_draw(korpus_bp_back_tex,korpus_bp_lr_tex,korpus_bp_top_tex,korpus_bp_lr_tex,korpus_bp_back_tex,korpus_bp_face_tex);
glPopMatrix();

glPushMatrix();
glTranslatef(-13,0,12);
key_draw(on_off);
glPopMatrix();

glPushMatrix();
glTranslatef(13,0,12);
lampa_draw_local(on_off,glass_tex,light_tex, 0.7);
glPopMatrix();

glPushMatrix();
glTranslatef(20.5,0,-12);
perehodnik_draw();
glPopMatrix();

end;

procedure shema_2(on_off: GLInt);
begin
glScalef(0.2,0.2,0.2);

provod_draw(-5.4,12,5.4,12,3.9);
provod_draw(-20.5,12,-20.5,-12,3.9);
provod_draw(-6.5,-12,8.55,-12,3.9);
provod_draw(20.55,12,20.55,-12,3.9);

glTranslatef(0,3.5,0);

glPushMatrix();
glTranslatef(-13.5,0,-12);
polnostiyu_pitanie_draw(korpus_bp_back_tex,korpus_bp_lr_tex,korpus_bp_top_tex,korpus_bp_lr_tex,korpus_bp_back_tex,korpus_bp_face_tex);
glPopMatrix();

glPushMatrix();
glTranslatef(-13,0,12);
key_draw(on_off);
glPopMatrix();

glPushMatrix();
glTranslatef(13,0,12);
lampa_draw_local(on_off,glass_tex,light_tex, 0.7);
glPopMatrix();

glPushMatrix();
glTranslatef(14.5,0,-12);
rezister_3_draw();
glPopMatrix();

end;

procedure shema_3(on_off: GLInt);
var
Ui: glFloat=15.0;
I: glFloat;
R1: glFloat=3.0;
R2: glFloat=7.0;
begin

if on_off=1 then
begin
I:=Ui/(R1+R2);
end
else
begin
I:=0;
end;

glScalef(0.2,0.2,0.2);

provod_draw(-12.4,12,12.4,12,3.9);
provod_draw(-27.5,12,-27.5,-12,3.9);
provod_draw(-13.5,-12,-5.5,-12,3.9);
provod_draw(6.55,-12,15.55,-12,3.9);
provod_draw(27.55,12,27.55,-12,3.9);

glTranslatef(0,3.5,0);

glPushMatrix();
glTranslatef(-20.5,0,-12);
polnostiyu_pitanie_draw(korpus_bp_back_tex,korpus_bp_lr_tex,korpus_bp_top_tex,korpus_bp_lr_tex,korpus_bp_back_tex,korpus_bp_face_tex);
glPopMatrix();

glPushMatrix();
glTranslatef(-20,0,12);
key_draw(on_off);
glPopMatrix();

glPushMatrix();
glTranslatef(0.5,0,-12);
ampermetr_draw(I,2,ceferblat_a_tex,steklo_tex,korpus_tex);
glPopMatrix();

glPushMatrix();
glTranslatef(20,0,12);
lampa_draw_local(on_off,glass_tex,light_tex, 0.7);
glPopMatrix();

glPushMatrix();
glTranslatef(21.5,0,-12);
rezister_3_draw();
glPopMatrix();
end;

procedure shema_4(on_off: GLInt);
var
Ui: glFloat=15.0;
I: glFloat;
R1: glFloat=3.0;
R2: glFloat=7.0;
begin

if on_off=1 then
begin
I:=Ui/(R1+R2);
end
else
begin
I:=0;
end;

glScalef(0.2,0.2,0.2);

provod_draw(-12.4,12,12.4,12,3.9);
provod_draw(-27.5,12,-27.5,-12,3.9);
provod_draw(-13.5,-12,-6,-12,3.9);
provod_draw(15.5,-12,6,-12,3.9);
provod_draw(27.55,12,27.55,-12,3.9);

glTranslatef(0,3.5,0);

glPushMatrix();
glTranslatef(-20.5,0,-12);
polnostiyu_pitanie_draw(korpus_bp_back_tex,korpus_bp_lr_tex,korpus_bp_top_tex,korpus_bp_lr_tex,korpus_bp_back_tex,korpus_bp_face_tex);
glPopMatrix();

glPushMatrix();
glTranslatef(-20,0,12);
key_draw(on_off);
glPopMatrix();

glPushMatrix();
glTranslatef(20,0,12);
lampa_draw_local(on_off,glass_tex,light_tex, 0.7);
glPopMatrix();

glPushMatrix();
glTranslatef(0,0,-12);
rezister_3_draw();
glPopMatrix();

glPushMatrix();
glTranslatef(21.5,0,-12);
ampermetr_draw(I,2,ceferblat_a_tex,steklo_tex,korpus_tex);
glPopMatrix();

end;

procedure shema_5(on_off: GLInt);
var
Ui: glFloat=15.0;
I: glFloat;
R1: glFloat=3.0;
R2: glFloat=7.0;
begin

if on_off=1 then
begin
I:=Ui/(R1+R2);
end
else
begin
I:=0;
end;

glScalef(0.2,0.2,0.2);

provod_draw(-12.4,12,-7.5,12,3.9);
provod_draw(14.5,12,7.5,12,3.9);
provod_draw(-27.5,12,-27.5,-12,3.9);
provod_draw(-13.5,-12,-6,-12,3.9);
provod_draw(14.5,-12,6,-12,3.9);
provod_draw(26.55,12,26.55,-12,3.9);

glTranslatef(0,3.5,0);

glPushMatrix();
glTranslatef(-20.5,0,-12);
polnostiyu_pitanie_draw(korpus_bp_back_tex,korpus_bp_lr_tex,korpus_bp_top_tex,korpus_bp_lr_tex,korpus_bp_back_tex,korpus_bp_face_tex);
glPopMatrix();

glPushMatrix();
glTranslatef(-20,0,12);
key_draw(on_off);
glPopMatrix();

glPushMatrix();
glTranslatef(0,0,12);
lampa_draw_local(on_off,glass_tex,light_tex, 0.7);
glPopMatrix();

glPushMatrix();
glTranslatef(20.5,0,12);
rezister_3_draw();
glPopMatrix();

glPushMatrix();
glTranslatef(0,0,-12);
ampermetr_draw(I,2,ceferblat_a_tex,steklo_tex,korpus_tex);
glPopMatrix();

glPushMatrix();
glTranslatef(20.5,0,-12);
ampermetr_draw(I,2,ceferblat_a_tex,steklo_tex,korpus_tex);
glPopMatrix();

end;

procedure shema_6(on_off: GLInt);
var
Ui: glFloat=8.0;
U1: glFloat;
U2: glFloat;
I: glFloat;
R1: glFloat=3.0;
R2: glFloat=7.0;
begin

if on_off=1 then
begin
I:=Ui/(R1+R2);
U1:=I*R1;
U2:=I*R2;
end
else
begin
U1:=0;
U2:=0;
end;

glScalef(0.2,0.2,0.2);
glTranslatef(-12,0,0);

provod_s_kontaktom_draw(4,39.5,12,4.5,12,8.5,1.5);
provod_s_kontaktom_draw(2,27.5,12,19.5,12,8.5,1.5);
provod_s_kontaktom_draw(4,39.5,-12,19.5,-12,8.5,1.5);
provod_s_kontaktom_draw(2,27.5,-12,7.5,-12,8.5,1.5);
provod_draw(-4.4,12,4.4,12,3.9);
provod_draw(-19.5,12,-19.5,-12,3.9);
provod_draw(-5.5,-12,7.5,-12,3.9);
provod_draw(19.55,12,19.55,-12,3.9);

glTranslatef(0,3.5,0);

glPushMatrix();
glTranslatef(-12.5,0,-12);
polnostiyu_pitanie_draw(korpus_bp_back_tex,korpus_bp_lr_tex,korpus_bp_top_tex,korpus_bp_lr_tex,korpus_bp_back_tex,korpus_bp_face_tex);
glPopMatrix();

glPushMatrix();
glTranslatef(-12,0,12);
key_draw(on_off);
glPopMatrix();

glPushMatrix();
glTranslatef(12,0,12);
lampa_draw_local(on_off,glass_tex,light_tex, 0.7);
glPopMatrix();

glPushMatrix();
glTranslatef(13.5,0,-12);
rezister_3_draw();
glPopMatrix();

glPushMatrix();
glTranslatef(33.5,0,12);
voltmetr_draw(U2,2,ceferblat_v_tex,steklo_tex,korpus_tex);
glPopMatrix();

glPushMatrix();
glTranslatef(33.5,0,-12);
voltmetr_draw(U1,2,ceferblat_v_tex,steklo_tex,korpus_tex);
glPopMatrix();

end;

procedure shema_7(begunok: glFloat; on_off,rezistor: GLInt);
var
Ui: glFloat;
U: glFloat;
I: glFloat;
R1: glFloat;
R2: glFloat;
begin

if on_off=1 then
begin
	case rezistor of
	1:
		begin
		Ui:=12.0;
		R1:=1.0;
		end;
	2:
		begin
		Ui:=8.0;
		R1:=2.0;
		end;

	3:
		begin
		Ui:=6.0;
		R1:=3.0;
		end;

	end;
	R2:=(begunok+3.675)/1.225;
	I:=Ui/(R1+R2);
	U:=I*R1;	
end
else
begin
U:=0;
I:=0;
end;

glPushMatrix();
glScalef(0.2,0.2,0.2);

provod_s_kontaktom_polukrugliy_draw(10,6,9,-20,3);
provod_s_kontaktom_polukrugliy_draw(10,-6,9,-20,3);
provod_draw(-38.5,16,-38.5,-10,3.9);
provod_draw(-23.5,16,3.4,16,3.9);
provod_draw(37.05,-10,37.05,16.1,3.9);
provod_draw(-24.5,-10,-6,-10,3.9);
provod_draw(6,-10,25,-10,3.9);

glTranslatef(0,3.5,0);

glPushMatrix();
glTranslatef(-31.5,0,-10);
polnostiyu_pitanie_draw(korpus_bp_back_tex,korpus_bp_lr_tex,korpus_bp_top_tex,korpus_bp_lr_tex,korpus_bp_back_tex,korpus_bp_face_tex);
glPopMatrix();

glPushMatrix();
glTranslatef(20.2,0,9.8);
big_rezistor_draw(begunok,big_rez_tex);
glPopMatrix();

glPushMatrix();
glTranslatef(-31,0,16);
key_draw(on_off);
glPopMatrix();

glPushMatrix();
glTranslatef(0,0,-10);
case rezistor of
1:rezister_1_draw();
2:rezister_2_draw();
3:rezister_3_draw();
end;
glPopMatrix();

glPushMatrix();
glTranslatef(31,0,-10);
ampermetr_draw(I,2,ceferblat_a_tex,steklo_tex,korpus_tex);
glPopMatrix();

glPushMatrix();
glTranslatef(0,0,-30);
voltmetr_draw(U,2,ceferblat_v_tex,steklo_tex,korpus_tex);
glPopMatrix();

glPopMatrix();
end;

procedure shema_8(begunok: glFloat; on_off: GLInt);
var
Ui: glFloat=10.0;
U: glFloat;
I: glFloat;
R1: glFloat=2.0;
R2: glFloat;
begin

if on_off=1 then
begin
	R2:=(begunok+3.675)/1.225;
	I:=Ui/(R1+R2);
	U:=I*R1;	
end
else
begin
U:=0;
I:=0;
end;

glPushMatrix();
glScalef(0.2,0.2,0.2);

provod_s_kontaktom_polukrugliy_draw(10,6,9,-20,3);
provod_s_kontaktom_polukrugliy_draw(10,-6,9,-20,3);
provod_draw(-38.5,16,-38.5,-10,3.9);
provod_draw(-23.5,16,3.4,16,3.9);
provod_draw(37.05,-10,37.05,16.1,3.9);
provod_draw(-24.5,-10,-6,-10,3.9);
provod_draw(6,-10,25,-10,3.9);

glTranslatef(0,3.5,0);

glPushMatrix();
glTranslatef(-31.5,0,-10);
polnostiyu_pitanie_draw(korpus_bp_back_tex,korpus_bp_lr_tex,korpus_bp_top_tex,korpus_bp_lr_tex,korpus_bp_back_tex,korpus_bp_face_tex);
glPopMatrix();

glPushMatrix();
glTranslatef(20.2,0,9.8);
big_rezistor_draw(begunok,big_rez_tex);
glPopMatrix();

glPushMatrix();
glTranslatef(-31,0,16);
key_draw(on_off);
glPopMatrix();

glPushMatrix();
glTranslatef(0,0,-10);
rezister_2_draw();
glPopMatrix();

glPushMatrix();
glTranslatef(31,0,-10);
ampermetr_draw(I,2,ceferblat_a_tex,steklo_tex,korpus_tex);
glPopMatrix();

glPushMatrix();
glTranslatef(0,0,-30);
voltmetr_draw(U,2,ceferblat_v_tex,steklo_tex,korpus_tex);
glPopMatrix();

glPopMatrix();
end;

procedure shema_9(begunok: glFloat; on_off: GLInt);
var
Ui: glFloat=10.0;
U: glFloat;
I: glFloat;
R1: glFloat=3.0;
R2: glFloat;
begin

if on_off=1 then
begin
	R2:=(begunok+3.675)/1.225;
	I:=Ui/(R1+R2);
	U:=I*R1;	
end
else
begin
U:=0;
I:=0;
end;

glPushMatrix();
glScalef(0.2,0.2,0.2);

provod_s_kontaktom_polukrugliy_draw(10,6,9,-20,3);
provod_s_kontaktom_polukrugliy_draw(10,-6,9,-20,3);
provod_draw(-38.5,16,-38.5,-10,3.9);
provod_draw(-23.5,16,3.4,16,3.9);
provod_draw(37.05,-10,37.05,16.1,3.9);
provod_draw(-24.5,-10,-6,-10,3.9);
provod_draw(6,-10,25,-10,3.9);

glTranslatef(0,3.5,0);

glPushMatrix();
glTranslatef(-31.5,0,-10);
polnostiyu_pitanie_draw(korpus_bp_back_tex,korpus_bp_lr_tex,korpus_bp_top_tex,korpus_bp_lr_tex,korpus_bp_back_tex,korpus_bp_face_tex);
glPopMatrix();

glPushMatrix();
glTranslatef(20.2,0,9.8);
big_rezistor_draw(begunok,big_rez_tex);
glPopMatrix();

glPushMatrix();
glTranslatef(-31,0,16);
key_draw(on_off);
glPopMatrix();

glPushMatrix();
glTranslatef(0,0,-10);
rezister_2_draw();
glPopMatrix();

glPushMatrix();
glTranslatef(31,0,-10);
ampermetr_draw(I,2,ceferblat_a_tex,steklo_tex,korpus_tex);
glPopMatrix();

glPushMatrix();
glTranslatef(0,0,-30);
voltmetr_draw(U,2,ceferblat_v_tex,steklo_tex,korpus_tex);
glPopMatrix();

glPopMatrix();
end;

procedure shema_10(begunok: glFloat; on_off: GLInt);
var
Ui: glFloat=10.0;
I: glFloat;
R: glFloat;
R1: glFloat=7.0;
begin

if on_off=1 then
begin
	R:=(begunok+3.675)/1.225;
	I:=Ui/(R+R1);
end
else
begin
I:=0;
end;

glPushMatrix();
glScalef(0.2,0.2,0.2);

provod_draw(-38.5,16,-38.5,-10,3.9);
provod_draw(-23.5,16,3.4,16,3.9);
provod_draw(37.05,-10,37.05,16.1,3.9);
provod_draw(-24.5,-10,-6,-10,3.9);
provod_draw(6,-10,22,-10,3.9);


glTranslatef(0,3.5,0);

glPushMatrix();
glTranslatef(-31.5,0,-10);
polnostiyu_pitanie_draw(korpus_bp_back_tex,korpus_bp_lr_tex,korpus_bp_top_tex,korpus_bp_lr_tex,korpus_bp_back_tex,korpus_bp_face_tex);
glPopMatrix();

glPushMatrix();
glTranslatef(20.2,0,9.8);
big_rezistor_draw(begunok,big_rez_tex);
glPopMatrix();

glPushMatrix();
glTranslatef(-31,0,16);
key_draw(on_off);
glPopMatrix();

glPushMatrix();
glTranslatef(0,0,-10);
ampermetr_draw(I,2,ceferblat_a_tex,steklo_tex,korpus_tex);
glPopMatrix();

glPushMatrix();
glTranslatef(29.5,0,-10);
lampa_draw_local(on_off,glass_tex,light_tex, 0.7);
glPopMatrix();

glPopMatrix();
end;

procedure shema_11(on_off: GLInt);
var
Ui: glFloat=6.0;
I: glFloat;
R1: glFloat=2.0;
R2: glFloat=1.0;
begin

if on_off=1 then
begin
I:=Ui/(R1+R2);
end
else
begin
I:=0;
end;

glPushMatrix();
glScalef(0.2,0.2,0.2);

provod_draw(-13,-10,-6,-10,3.9);
provod_draw(6,-10,14,-10,3.9);
provod_draw(26,-10,26,10,3.9);
provod_draw(-12,10,14,10,3.9);
provod_draw(-27,-10,-27,10,3.9);

glTranslatef(0.0,3.5,0.0);


glPushMatrix();
glTranslatef(-20.0,0.0,-10.0);
polnostiyu_pitanie_draw(korpus_bp_back_tex,korpus_bp_lr_tex,korpus_bp_top_tex,korpus_bp_lr_tex,korpus_bp_back_tex,korpus_bp_face_tex);
glPopMatrix();

glPushMatrix();
glTranslatef(0.0,0.0,-10.0);
ampermetr_draw(I,2,ceferblat_a_tex,steklo_tex,korpus_tex);
glPopMatrix();

glPushMatrix();
glTranslatef(20.0,0.0,-10.0);
rezister_2_draw();
glPopMatrix();

glPushMatrix();
glTranslatef(-19.5,0.0,10.0);
key_draw(on_off);
glPopMatrix();

glPushMatrix();
glTranslatef(20.0,0.0,10.0);
rezister_1_draw();
glPopMatrix();

glPopMatrix();
end;

procedure shema_12(voltmetr,on_off: GLInt);
var
Ui: glFloat=6.0;
U1: glFloat;
U2: glFloat;
U3: glFloat;
I: glFloat;
R1: glFloat=1.0;
R2: glFloat=2.0;
begin

if on_off=1 then
begin
I:=Ui/(R1+R2);
U1:=I*R1;
U2:=I*R2;
U3:=U1+U2;
end
else
begin
U1:=0;
U2:=0;
U3:=0;
end;

glPushMatrix();
glScalef(0.2,0.2,0.2);
glTranslatef(-12.0,0.0,0.0);

provod_draw(-18,-10,-6,-10,3.9);
provod_draw(-6,-10,20,-10,3.9);
provod_draw(32,-10,32,10,3.9);
provod_draw(-18,10,6,10,3.9);
provod_draw(6,10,20,10,3.9);
provod_draw(-33,-10,-33,10,3.9);

glTranslatef(0.0,3.5,0.0);


glPushMatrix();
glTranslatef(-26.0,0.0,-10.0);
polnostiyu_pitanie_draw(korpus_bp_back_tex,korpus_bp_lr_tex,korpus_bp_top_tex,korpus_bp_lr_tex,korpus_bp_back_tex,korpus_bp_face_tex);
glPopMatrix();

glPushMatrix();
glTranslatef(-6.0,0.0,-10.0);
perehodnik_draw();
glPopMatrix();

glPushMatrix();
glTranslatef(26.0,0.0,-10.0);
rezister_2_draw();
glPopMatrix();

glPushMatrix();
glTranslatef(-25.5,0.0,10.0);
key_draw(on_off);
glPopMatrix();

glPushMatrix();
glTranslatef(6.0,0.0,10.0);
perehodnik_draw();
glPopMatrix();

glPushMatrix();
glTranslatef(26.0,0.0,10.0);
rezister_1_draw();
glPopMatrix();

case voltmetr of

1:
begin
	glPushMatrix();
	
	provod_s_kontaktom_draw(4,20,10,56,10,5,1.5);
	provod_s_kontaktom_draw(1,32,10,44,10,5,1.5);
	
	glTranslatef(50.0,0.0,10.0);
	voltmetr_draw(U1,2,ceferblat_v_tex,steklo_tex,korpus_tex);
	
	glPopMatrix();
end;

2:
begin
	glPushMatrix();
	
	provod_s_kontaktom_draw(4,20,-10,56,-10,5,1.5);
	provod_s_kontaktom_draw(1,32,-10,44,-10,5,1.5);
	
	glTranslatef(50.0,0.0,-10.0);
	voltmetr_draw(U2,2,ceferblat_v_tex,steklo_tex,korpus_tex);
	
	glPopMatrix();
end;

3:
begin
	glPushMatrix();
	
	provod_s_kontaktom_polukrugliy_draw(10,-6,5.5,-20,4);
	provod_s_kontaktom_polukrugliy_draw(20,6,5.5,-10,4);
	
	glTranslatef(0.0,0.0,-30);
	voltmetr_draw(U3,2,ceferblat_v_tex,steklo_tex,korpus_tex);
	
	glPopMatrix();
end;

end;

glPopMatrix();
end;

procedure shema_13(on_off: GLInt);
var
Ui: glFloat=6.0;
U1: glFloat;
U2: glFloat;
U3: glFloat;
I: glFloat;
R1: glFloat=1.0;
R2: glFloat=2.0;
begin

if on_off=1 then
begin
I:=Ui/(R1+R2);
U1:=I*R1;
U2:=I*R2;
U3:=U1+U2;
end
else
begin
I:=0;
U1:=0;
U2:=0;
U3:=0;
end;

glPushMatrix();
glScalef(0.2,0.2,0.2);
glTranslatef(-12.0,0.0,0.0);

provod_draw(-18,-10,-6,-10,3.9);
provod_draw(-6,-10,10,-10,3.9);
provod_draw(22,-10,29,-10,3.9);
provod_draw(41,-10,41,15,3.9);
provod_draw(-18,15,6,15,3.9);
provod_draw(6,15,29,15,3.9);
provod_draw(-33,-10,-33,15,3.9);

glTranslatef(0.0,3.5,0.0);

provod_s_kontaktom_draw(4,29,-10,53,-10,5,1.5);
provod_s_kontaktom_draw(2,41,-10,65,-10,5,1.5);
provod_s_kontaktom_draw(4,29,15,65,15,5,1.5);
provod_s_kontaktom_draw(2,41,15,53,15,5,1.5);
provod_s_kontaktom_polukrugliy_draw(10,-6,5.5,-20,4);
provod_s_kontaktom_polukrugliy_draw(22.5,6,5.5,-7.5,4);

glPushMatrix();
glTranslatef(-26.0,0.0,-10.0);
polnostiyu_pitanie_draw(korpus_bp_back_tex,korpus_bp_lr_tex,korpus_bp_top_tex,korpus_bp_lr_tex,korpus_bp_back_tex,korpus_bp_face_tex);
glPopMatrix();

glPushMatrix();
glTranslatef(-6.0,0.0,-10.0);
perehodnik_draw();
glPopMatrix();

glPushMatrix();
glTranslatef(35.0,0.0,-10.0);
rezister_2_draw();
glPopMatrix();

glPushMatrix();
glTranslatef(-25.5,0.0,15.0);
key_draw(on_off);
glPopMatrix();

glPushMatrix();
glTranslatef(6.0,0.0,15.0);
perehodnik_draw();
glPopMatrix();

glPushMatrix();
glTranslatef(35.0,0.0,15.0);
rezister_1_draw();
glPopMatrix();

glPushMatrix();
glTranslatef(59.0,0.0,15.0);
voltmetr_draw(U1,2,ceferblat_v_tex,steklo_tex,korpus_tex);
glPopMatrix();

glPushMatrix();
glTranslatef(59.0,0.0,-10.0);
voltmetr_draw(U2,2,ceferblat_v_tex,steklo_tex,korpus_tex);
glPopMatrix();

glPushMatrix();
glTranslatef(0.0,0.0,-30);
voltmetr_draw(U3,2,ceferblat_v_tex,steklo_tex,korpus_tex);
glPopMatrix();

glPushMatrix();
glTranslatef(16.0,0.0,-10.0);
ampermetr_draw(I,2,ceferblat_a_tex,steklo_tex,korpus_tex);
glPopMatrix();


glPopMatrix();
end;

procedure shema_14(on_off: GLInt);
var
Ui: glFloat=6.0;
U1: glFloat;
U2: glFloat;
U3: glFloat;
begin

if on_off=1 then
begin
U1:=Ui;
U2:=Ui;
U3:=Ui;
end
else
begin
U1:=0;
U2:=0;
U3:=0;
end;

glPushMatrix();
glScalef(0.2,0.2,0.2);
glTranslatef(-12.0,0.0,0.0);

provod_draw(-18,-10,-6,-10,3.9);
provod_draw(-6,-10,20,-10,3.9);
provod_draw(20,-35,20,-10,3.9);
provod_draw(32,-35,32,-10,3.9);
provod_draw(-18,15,6,15,3.9);
provod_draw(6,15,32,15,3.9);
provod_draw(-33,-10,-33,15,3.9);
provod_draw(32,-10,32,15,3.9);

glTranslatef(0.0,3.5,0.0);

provod_s_kontaktom_draw(4,20,-35,44,-35,5,1.5);
provod_s_kontaktom_draw(2,32,-35,56,-35,5,1.5);
provod_s_kontaktom_draw(4,20,-10,44,-10,5,1.5);
provod_s_kontaktom_draw(2,32,-10,56,-10,5,1.5);
provod_s_kontaktom_polukrugliy_draw(10,-6,5.5,-20,4);
provod_s_kontaktom_polukrugliy_draw(22.5,6,5.5,-7.5,4);

glPushMatrix();
glTranslatef(-26.0,0.0,-10.0);
polnostiyu_pitanie_draw(korpus_bp_back_tex,korpus_bp_lr_tex,korpus_bp_top_tex,korpus_bp_lr_tex,korpus_bp_back_tex,korpus_bp_face_tex);
glPopMatrix();

glPushMatrix();
glTranslatef(-6.0,0.0,-10.0);
perehodnik_draw();
glPopMatrix();

glPushMatrix();
glTranslatef(26.0,0.0,-35.0);
rezister_2_draw();
glPopMatrix();

glPushMatrix();
glTranslatef(-25.5,0.0,15.0);
key_draw(on_off);
glPopMatrix();

glPushMatrix();
glTranslatef(6.0,0.0,15.0);
perehodnik_draw();
glPopMatrix();

glPushMatrix();
glTranslatef(26.0,0.0,-10.0);
rezister_1_draw();
glPopMatrix();

glPushMatrix();
glTranslatef(32.0,0.0,15.0);
perehodnik_draw();
glPopMatrix();

glPushMatrix();
glTranslatef(50.0,0.0,-10.0);
voltmetr_draw(U1,2,ceferblat_v_tex,steklo_tex,korpus_tex);
glPopMatrix();

glPushMatrix();
glTranslatef(50.0,0.0,-35.0);
voltmetr_draw(U2,2,ceferblat_v_tex,steklo_tex,korpus_tex);
glPopMatrix();

glPushMatrix();
glTranslatef(0.0,0.0,-30);
voltmetr_draw(U3,2,ceferblat_v_tex,steklo_tex,korpus_tex);
glPopMatrix();

glPopMatrix();
end;

procedure shema_15(on_off: GLInt);
var
Ui: glFloat=6.0;
I: glFloat;
R1: glFloat=2.0;
R2: glFloat=3.0;
begin

if on_off=1 then
begin
I:=Ui/(1/(1/R1+1/R2));
end
else
begin
I:=0;
end;

glPushMatrix();
glScalef(0.2,0.2,0.2);

provod_draw(-13,-10,-6,-10,3.9);
provod_draw(6,-10,14,-10,3.9);
provod_draw(-12,10,26,10,3.9);
provod_draw(-27,-10,-27,10,3.9);
provod_draw(26,-10,26,10,3.9);
provod_s_kontaktom_polukrugliy_draw(10.1,14,9,-20.0,3);
provod_s_kontaktom_polukrugliy_draw(10.1,26,9,-20.0,3);

glTranslatef(0.0,3.5,0.0);

glPushMatrix();
glTranslatef(-20.0,0.0,-10.0);
polnostiyu_pitanie_draw(korpus_bp_back_tex,korpus_bp_lr_tex,korpus_bp_top_tex,korpus_bp_lr_tex,korpus_bp_back_tex,korpus_bp_face_tex);
glPopMatrix();

glPushMatrix();
glTranslatef(0.0,0.0,-10.0);
ampermetr_draw(I,2,ceferblat_a_tex,steklo_tex,korpus_tex);
glPopMatrix();

glPushMatrix();
glTranslatef(20.0,0.0,-30.0);
rezister_2_draw();
glPopMatrix();

glPushMatrix();
glTranslatef(-19.5,0.0,10.0);
key_draw(on_off);
glPopMatrix();

glPushMatrix();
glTranslatef(20.0,0.0,-10.0);
rezister_3_draw();
glPopMatrix();

glPushMatrix();
glTranslatef(26.0,0.0,10.0);
perehodnik_draw();
glPopMatrix();

glPopMatrix();
end;

procedure shema_16(on_off: GLInt);
var
Ui: glFloat=6.0;
U1: glFloat;
I: glFloat;
R1: glFloat=2.0;
R2: glFloat=3.0;
begin

if on_off=1 then
begin
I:=Ui/(1/(1/R1+1/R2));
U1:=Ui;
end
else
begin
I:=0;
U1:=0;
end;

glPushMatrix();
glScalef(0.2,0.2,0.2);
glTranslatef(-10.0,0.0,0.0);

provod_draw(-13,-10,-6,-10,3.9);
provod_draw(6,-10,14,-10,3.9);
provod_draw(26,-10,26,10,3.9);
provod_draw(-12,10,26,10,3.9);
provod_draw(-27,-10,-27,10,3.9);
provod_draw(46,-10,46,-30,3.9);
provod_draw(14,-10,14,-30,3.9);
provod_s_kontaktom_draw(3,14,-30,34,-30,8.5,1.5);
provod_s_kontaktom_draw(3,14,-10,46,-10,8.5,1.5);
provod_s_kontaktom_polukrugliy_draw(10.1,26,9,-20.0,3);

glTranslatef(0.0,3.5,0.0);

glPushMatrix();
glTranslatef(-20.0,0.0,-10.0);
polnostiyu_pitanie_draw(korpus_bp_back_tex,korpus_bp_lr_tex,korpus_bp_top_tex,korpus_bp_lr_tex,korpus_bp_back_tex,korpus_bp_face_tex);
glPopMatrix();

glPushMatrix();
glTranslatef(0.0,0.0,-10.0);
ampermetr_draw(I,2,ceferblat_a_tex,steklo_tex,korpus_tex);
glPopMatrix();

glPushMatrix();
glTranslatef(20.0,0.0,-30.0);
rezister_2_draw();
glPopMatrix();

glPushMatrix();
glTranslatef(-19.5,0.0,10.0);
key_draw(on_off);
glPopMatrix();

glPushMatrix();
glTranslatef(20.0,0.0,-10.0);
rezister_3_draw();
glPopMatrix();

glPushMatrix();
glTranslatef(40.0,0.0,-30.0);
voltmetr_draw(U1,2,ceferblat_v_tex,steklo_tex,korpus_tex);
glPopMatrix();

glPushMatrix();
glTranslatef(46.0,0.0,-10.0);
perehodnik_draw();
glPopMatrix();

glPushMatrix();
glTranslatef(26.0,0.0,10.0);
perehodnik_draw();
glPopMatrix();

glPopMatrix();
end;

procedure shema_17(on_off: GLInt; begunok,amb,dif,spec,shin: glFloat);
var
Ui: glFloat=6.87;
I: glFloat;
R1: glFloat=0.435;
R2: glFloat;
begin

if on_off=1 then
begin
R2:=(begunok+3.675)/1.225;
I:=Ui/(R1+R2);
writeln(R2:8:2);
end
else
begin
I:=0;
end;

glPushMatrix();
glScalef(0.2,0.2,0.2);

provod_draw(26.8,-10,26.8,16.3,3.9);
provod_draw(-12.5,16.3,-6.8,16.3,3.9);
provod_draw(-27.5,16.3,-27.5,-10,3.9);
provod_draw(-13.5,-10,-8,-10,3.9);
provod_draw(14.8,-10,8,-10,3.9);

glTranslatef(0.0,3.5,0.0);

glPushMatrix();
glTranslatef(-20.5,0.0,-10.0);
polnostiyu_pitanie_draw(korpus_bp_back_tex,korpus_bp_lr_tex,korpus_bp_top_tex,korpus_bp_lr_tex,korpus_bp_back_tex,korpus_bp_face_tex);
glPopMatrix();

glPushMatrix();
glTranslatef(0.0,0.0,-10.0);
provolka_draw(amb,dif,spec,shin);
glPopMatrix();

glPushMatrix();
glTranslatef(20.8,0.0,-10.0);
ampermetr_draw(I,2,ceferblat_a_tex,steklo_tex,korpus_tex);
glPopMatrix();

glPushMatrix();
glTranslatef(-20.0,0.0,16.3);
key_draw(on_off);
glPopMatrix();

glPushMatrix();
glTranslatef(10.0,0.0,10.0);
big_rezistor_draw(begunok,big_rez_tex);
glPopMatrix();

glPopMatrix();
end;

procedure shema_18(on_off: GLInt; begunok: glFloat);
var
Ui: glFloat=10.0;
U1: glFloat;
I: glFloat;
R1: glFloat;
R2: glFloat=7;
begin

if on_off=1 then
begin
R1:=(begunok+3.675)/1.225;
I:=Ui/(R1+R2);
U1:=I*R2;
end
else
begin
U1:=0;
I:=0;
end;

glPushMatrix();
glScalef(0.2,0.2,0.2);

provod_draw(26.8,-10,26.8,16.3,3.9);
provod_draw(-12.5,16.3,-6.8,16.3,3.9);
provod_draw(-27.5,16.3,-27.5,-10,3.9);
provod_draw(-13.5,-10,-7.5,-10,3.9);
provod_draw(14.8,-10,7.5,-10,3.9);

glTranslatef(0.0,3.5,0.0);

glPushMatrix();
glRotatef(-4,0,1,0);
provod_s_kontaktom_polukrugliy_draw(10.2,-8.15,5.5,-19.45,4);
glPopMatrix();

glPushMatrix();
glRotatef(4,0,1,0);
provod_s_kontaktom_polukrugliy_draw(10.2,8.15,5.5,-19.45,4);
glPopMatrix();



glPushMatrix();
glTranslatef(-20.5,0.0,-10.0);
polnostiyu_pitanie_draw(korpus_bp_back_tex,korpus_bp_lr_tex,korpus_bp_top_tex,korpus_bp_lr_tex,korpus_bp_back_tex,korpus_bp_face_tex);
glPopMatrix();

glPushMatrix();
glTranslatef(0.0,0.0,-10.0);
lampa_draw_local(on_off,glass_tex,light_tex, 0.7);
glPopMatrix();

glPushMatrix();
glTranslatef(0.0,0.0,-30.0);
voltmetr_draw(U1,2,ceferblat_v_tex,steklo_tex,korpus_tex);
glPopMatrix();

glPushMatrix();
glTranslatef(20.8,0.0,-10.0);
ampermetr_draw(I,2,ceferblat_a_tex,steklo_tex,korpus_tex);
glPopMatrix();

glPushMatrix();
glTranslatef(-20.0,0.0,16.3);
key_draw(on_off);
glPopMatrix();

glPushMatrix();
glTranslatef(10.0,0.0,10.0);
big_rezistor_draw(begunok,big_rez_tex);
glPopMatrix();

glPopMatrix();
end;

procedure shema_19(on_off: GLInt; amb,dif,spec,shin: glFloat);
begin
glPushMatrix();
glScalef(0.2,0.2,0.2);
glTranslatef(10.0,0.0,0.0);

provod_draw(-13.5,-10,-7,-10,3.9);
provod_draw(-27.5,-10,-27.5,10,3.9);
provod_draw(-12.5,10,-8,10,3.9);
provod_draw(8,10,8,-10,3.9);

glTranslatef(0.0,3.5,0.0);

glPushMatrix();
glRotatef(-4,0,1,0);
provod_s_kontaktom_polukrugliy_draw(10.15,-7.575,5.5,-19.45,4);
glPopMatrix();

glPushMatrix();
glRotatef(4,0,1,0);
provod_s_kontaktom_polukrugliy_draw(10.15,8.65,5.5,-19.45,4);
glPopMatrix();



glPushMatrix();
glTranslatef(-20.5,0.0,-10.0);
polnostiyu_pitanie_draw(korpus_bp_back_tex,korpus_bp_lr_tex,korpus_bp_top_tex,korpus_bp_lr_tex,korpus_bp_back_tex,korpus_bp_face_tex);
glPopMatrix();

glPushMatrix();
glTranslatef(0.5,0.0,-30.0);
rezister_2_draw();
glPopMatrix();

glPushMatrix();
glTranslatef(0.5,0.0,-10.0);
lampa_draw_local(on_off,glass_tex,light_tex, 0.7);
glPopMatrix();

glPushMatrix();
glTranslatef(-20,0.0,10.0);
key_draw(on_off);
glPopMatrix();

glPushMatrix();
glTranslatef(0.0,0.0,10.0);
provolka_draw(amb,dif,spec,shin);
glPopMatrix();

glPopMatrix();
end;

procedure shema_20(on_off: GLInt; amb,dif,spec,shin: glFloat);
begin
glPushMatrix();
glScalef(0.2,0.2,0.2);

provod_draw(-4,-10,2.5,-10,3.9);
provod_draw(-18,-10,-18,10,3.9);
provod_draw(-2,10,17.5,10,3.9);
provod_draw(17.5,-10,17.5,10,3.9);

glTranslatef(0.0,3.5,0.0);

provod_s_kontaktom_polukrugliy_draw(10.1,17.5,5.5,-20.0,4);
provod_s_kontaktom_polukrugliy_draw(10.1,2.5,5.5,-20.0,4);



glPushMatrix();
glTranslatef(-11.0,0.0,-10);
polnostiyu_pitanie_draw(korpus_bp_back_tex,korpus_bp_lr_tex,korpus_bp_top_tex,korpus_bp_lr_tex,korpus_bp_back_tex,korpus_bp_face_tex);
glPopMatrix();

glPushMatrix();
glTranslatef(10.0,0.0,-30);
key_draw(on_off);
glPopMatrix();

on_off:=-on_off;

glPushMatrix();
glTranslatef(10.0,0.0,-10);
lampa_draw_local(on_off,glass_tex,light_tex, 0.7);
glPopMatrix();

glPushMatrix();
glTranslatef(-10.0,0.0,10);
if on_off=-1 then
begin
provolka_draw_off(amb,dif,spec,shin);
end
else
begin
provolka_draw(amb,dif,spec,shin);
end;
glPopMatrix();

glPushMatrix();
glTranslatef(17.5,0.0,10);
perehodnik_draw();
glPopMatrix();

glPopMatrix();
end;

end.


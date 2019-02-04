{$R-}
{$MODE DELPHI}

unit LoadBmp; {процедуры для работы с Bmp}

interface
uses GL,GLU;
type
  artype = array[0..0]of byte;
  arptr = ^artype;

  bmFileHeader = record	{заголовок файла}
    Typf : word;        {сигнатура }
    Sizef : longint;     {длина файла в байтах}
    Res1 : word;        {зарезервировано}
    Res2 : word;        {зарезервировано}
    OfBm : longint;     {смещение изображения в байтах (1078)}
  end;

  bmInfoHeader = record   {информационный заголовок}
    Size : longint;       {длина заголовка в байтах (40)}
    Widt : longint;       {ширина изображения (в точках)}
    Heig : longint;       {высота изображения (в точках)}
    Plan : word;          {число плоскостей (1)}
    BitC : word;          {глубина цвета (бит на точку) (8)}
    Comp : longint;       {тип компрессии (0 - нет)}
    SizI : longint;       {размер изображения в байтах}
    XppM : longint;       {горизонтальное разрешение}	          {(точек на метр - обычно 0)}
    YppM : longint;       {вертикальное разрешение}		          {(точек на метр - обычно 0)}
    NCoL : longint;       {число цветов}		          {(если максимально допустимое - 0)}
    NCoI : longint;       {число основных цветов}
  end;  
                 
  bmHeader = record       {полный заголовок файла}
    f : bmFileHeader;     {заголовок файла}
    i : bmInfoHeader;     {информационный заголовок}
    p : array[0..255,0..3]of byte; {таблица палитры}
  end;

  bmhptr = ^bmHeader;

{чтение изображения из Bmp-файла}
//procedure ReadBMP(var filename:string;   image:arptr;  bmWidth:longint;  bmHeight:longint);
procedure OGL_Load_Texture(Filename: String; var texti:GLuint);

implementation
var
bmWidth:longint;
bmHeight:longint;
Image:arptr;

procedure LoadBMP(var filename:string);
var
  h	  : bmHeader;
  i	  :longint;
  bmpfile : file;
  BitmapLength  : longint;
   Temp: byte;

begin
  assign(bmpfile,filename);
  reset(bmpfile,1);
  blockread(bmpfile,h.f.Typf,2);
  blockread(bmpfile,h.f.Sizef,4);
  blockread(bmpfile,h.f.Res1,2);
  blockread(bmpfile,h.f.Res2,2);
  blockread(bmpfile,h.f.OfBm,4);
  blockread(bmpfile,h.i,40);
  bmWidth:=h.i.Widt;
  bmHeight:=h.i.Heig;
  BitmapLength := bmWidth * bmHeight * 3;
  GetMem(image, BitmapLength);
  blockread(bmpfile, image^, BitmapLength);
  close(bmpfile);
i:=0;
while i < (bmWidth * bmHeight*3-2)  do
  begin
    Temp := image^[i];
    image^[i] := image^[i+2];
    image^[i+2] := Temp;
    i:=i+3;
  end;
end;


procedure OGL_Load_Texture(Filename: String; var texti:GLuint);
begin
image:=nil;
LoadBMP(Filename);
glGenTextures(1, @texti);
glBindTexture(GL_TEXTURE_2D, texti);
glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR_MIPMAP_LINEAR);
glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_LINEAR);
gluBuild2DMipmaps ( GL_TEXTURE_2D, 3,  bmWidth,bmHeight, GL_RGB, GL_UNSIGNED_BYTE, Image );
glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
end;


{чтение изображения из Bmp-файла}

end.

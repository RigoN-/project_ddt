unit lib_image; {процедуры загрузки изображений}

{$R-}
{$MODE DELPHI}
interface
uses sysutils,classes,gl,  glu,glext, 
   jmorecfg, jerror, jpeglib,  jdatadst, jcparam, jcapimin, jcapistd, jdapimin, jdatasrc, jdapistd;

 
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

 // Header type for TGA images
   TGA_file_Header = packed record   
    FileType     : Byte;
    ColorMapType : Byte;
    ImageType    : Byte;
    ColorMapSpec : Array[0..4] of Byte;
    OrigX  : Array [0..1] of Byte;
    OrigY  : Array [0..1] of Byte;
    Width  : Array [0..1] of Byte;
    Height : Array [0..1] of Byte;
    BPP    : Byte;
    ImageInfo : Byte;
    end;
  
  
image_struct = record
	Width:longint;
	Height:longint;
	imgChanal:byte;
	image_data:arptr;
	end;
image_type = 	image_struct;

const
IMG_BMP=1;
IMG_TGA=2;
IMG_JPEG=3;

var
image: image_type;

 // bmhptr = ^bmHeader;

{чтение изображения из Bmp-файла}
//procedure ReadBMP(var filename:string;   image:arptr;  bmWidth:longint;  bmHeight:longint);
//procedure OGL_Load_Texture_BMP(Filename: String; var texti:GLuint);cdecl;
//procedure OGL_Load_Texture_TGA(Filename: String; var texti:GLuint);cdecl;
//procedure OGL_Load_Texture_JPG(Filename: String; var texti:GLuint);cdecl;
//procedure OGL_Load_Texture(Filename: String; var texti:GLuint);cdecl;
function LoadBMP(var filename:string): image_type;cdecl;
function LoadTGA(Filename: String):image_type;cdecl;
function LoadJPG(Filename: String): image_type; cdecl;


implementation


function LoadBMP(var filename:string): image_type;cdecl;
var
  h  : bmHeader;
  i	  :longint;
  bmpfile : file;
  BitmapLength  : longint;
  Temp: byte;
  image_tmp:image_type;

begin
  AssignFile(bmpfile,filename);
  reset(bmpfile,1);
 
//  GetMem(image, sizeof(image_type));
  with image_tmp do 
  begin
  blockread(bmpfile,h.f.Typf,2);
  blockread(bmpfile,h.f.Sizef,4);
  blockread(bmpfile,h.f.Res1,2);
  blockread(bmpfile,h.f.Res2,2);
  blockread(bmpfile,h.f.OfBm,4);
  blockread(bmpfile,h.i,40);
  
  Width:=h.i.Widt;
  Height:=h.i.Heig;
  imgChanal:=3; 
  BitmapLength := Width * Height * 3;
  GetMem(image_data, BitmapLength);
  blockread(bmpfile, image_data^, BitmapLength);
  CloseFile(bmpfile);
  i:=0;
  while i < (Width * Height*3-2)  do
    begin
		Temp := image_data^[i];
		image_data^[i] := image_data^[i+2];
		image_data^[i+2] := Temp;
		i:=i+3;
    end;
 
  end;
 result:=image_tmp;
 writeln(PChar('Load '+ Filename +' is OK'), ' Chanal - ',image_tmp.imgChanal);
// freemem(@image_tmp);
end;


function LoadTGA(Filename: String):image_type;cdecl;
var
  TGAHeader : TGA_file_Header;   // Header type for TGA images
  TGAFile   : File;
  bytesRead : Integer;
  ColorDepth    : Integer;
  ImageSize     : Integer;
  i: longint;
  Temp: Byte;
  image_tmp:image_type;
 
begin
      AssignFile(TGAFile, Filename);
      Reset(TGAFile, 1);
      // Read in the TGA file header
      BlockRead(TGAFile, TGAHeader, SizeOf(TGAHeader));      
    // Only support uncompressed images
    if (TGAHeader.ImageType <> 2) then  { TGA_RGB }
    begin
      CloseFile(tgaFile);
      writeln(0, PChar('Couldn''t load "'+ Filename +'". Compressed TGA files not supported.'), PChar('TGA File Error'));
      Exit;
    end;

    // Don't support colormapped files
    if TGAHeader.ColorMapType <> 0 then
    begin      
      CloseFile(TGAFile);
      writeln(0, PChar('Couldn''t load "'+ Filename +'". Colormapped TGA files not supported.'), PChar('TGA File Error'));
      Exit;
    end;
    
    with image_tmp do 
     begin
    // Get the width, height, and color depth
    Width  := TGAHeader.Width[0]  + TGAHeader.Width[1]  * 256;
    Height := TGAHeader.Height[0] + TGAHeader.Height[1] * 256;
    ColorDepth := TGAHeader.BPP;
    imgChanal:= TGAHeader.BPP div 8;
    ImageSize  := Width*Height*(ColorDepth div 8);

    if ColorDepth < 24 then
    begin
      CloseFile(TGAFile);
      writeln(0, PChar('Couldn''t load "'+ Filename +'". Only 24 bit TGA files supported.'), PChar('TGA File Error'));
      Exit;
    end;

    GetMem(image_data, ImageSize);

   // Read in the image from file
      BlockRead(TGAFile, image_data^, ImageSize, bytesRead);
      if bytesRead <> ImageSize then
      begin
        CloseFile(TGAFile);
        writeln(0, PChar('Couldn''t read file "'+ Filename +'".'), PChar('TGA File Error'));
        Exit;
      end;

   i:=0;
  // TGAs are stored BGR and not RGB, so swap the R and B bytes.
  // 32 bit TGA files have alpha channel and gets loaded differently
  if ColorDepth = 24 then
   while i < (Width * Height*3-2)  do
    begin
		Temp := image_data^[i];
		image_data^[i] := image_data^[i+2];
		image_data^[i+2] := Temp;
		i:=i+3;
    end   
  else
    while i < (Width * Height*4-2)  do
    begin
		Temp := image_data^[i];
		image_data^[i] := image_data^[i+2];
		image_data^[i+2] := Temp;
		i:=i+4;
    end;
  
  end;
   result:=image_tmp;
   CloseFile(TGAFile);
   writeln(PChar('Load '+ Filename +' is OK'), ' Chanal - ',image_tmp.imgChanal);
end;

function LoadJPG(Filename: String): image_type; cdecl;
{var
 jerr: jpeg_error_mgr;

  cinfo : jpeg_decompress_struct;
  ImageSize:LongInt;  
  num_scanlines : JDIMENSION;
  buffer : JSAMPARRAY;         
  row_stride : int;   
   //JPGFile : TFileStream;   
   JPGFile:File;
  image_tmp:image_type; }
  
  
begin
 {      AssignFile(JPGFile, Filename);
        Reset(JPGFile, 1);
//JPGFile := TFileStream.Create(filename, fmOpenRead or fmShareDenyWrite);

  //initialize the JPEG decompression object with default error handling.
  cinfo.err := jpeg_std_error(jerr);
  jpeg_create_decompress(@cinfo);
      //specify the source of the compressed data
      jpeg_stdio_src(@cinfo, @JPGFile);
     writeln(1); 
      //obtain image info from header, set default decompression parameters
      jpeg_read_header(@cinfo, FALSE);
      writeln(2);  
	  cinfo.scale_num := 1;
	  cinfo.scale_denom := 1;       // 1:1 scaling 
	  cinfo.dct_method := JDCT_IFAST;
	  cinfo.quantize_colors := TRUE;
	  cinfo.two_pass_quantize := TRUE;
	  cinfo.dither_mode := JDITHER_FS;  // Floyd-Steinberg error diffusion dither 
	writeln(3);  
      
      
      jpeg_start_decompress(@cinfo);
        writeln(4); 
      row_stride := cinfo.output_width * cinfo.output_components;
        writeln(5); 
  // Make a one-row-high sample array that will go away when done with image 
     buffer := cinfo.mem^.alloc_sarray(j_common_ptr(@cinfo), JPOOL_IMAGE, row_stride, 1);
  writeln(6); 
    //process data
      while (cinfo.output_scanline < cinfo.output_height) do
       begin
       jpeg_read_scanlines(@cinfo, buffer, 1);
       end;
		
     writeln(7);  
     
        with  image_tmp do 
    begin  
//    save_color_map(@cinfo);
    Width:=cinfo.output_width;
    Height:=cinfo.output_height; 
    imgChanal:= cinfo.num_components;  
    ImageSize:= Width*   Height*4;           
    GetMem(image_data, ImageSize); 
    image_data:=@buffer;
    end;
writeln(8);  
      jpeg_finish_decompress(@cinfo);
   
 	
    //destroy
    jpeg_destroy_decompress(@cinfo);
      result:=image_tmp;}
  end;

end.

{$MODE DELPHI}
unit typcon;
interface
type
	cell_type=record
		stat:boolean;
		open:byte;
		close:byte;
	end;
	level_type=record
		h,w,b:byte;
	end;
	sapper_type=record
		life:byte;
		sap:integer;
		block:boolean;
	end;
const
	W_CAPTION=	'Сапер 1.4';
	W_WIDTH=	1280;
	W_HEIGHT=	1024;
	SWAP_INT=	0;
	num_tex=	60;
	level_up=	4;
implementation
end.
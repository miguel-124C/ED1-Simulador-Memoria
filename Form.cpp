//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <Vcl.Graphics.hpp>

#include "Form.h"
#include "CMemoria.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{

}
void __fastcall TForm2::FormPaint(TObject *Sender)
{
	if(!MemoriaCreada) return;

	int x1 = 430; int y1 = 10;
	int y2 = HeightFields + y1;

	TColor colorTextHeader = (TColor)0x0000ff;

	DibujarField( x1, y1, clBtnFace, WidthDir, "DIR", colorTextHeader);
	DibujarField( x1, y1, clBtnFace, WidthDato, "DATO", colorTextHeader);
	DibujarField( x1, y1, clBtnFace, WidthId, "ID", colorTextHeader);
	DibujarField( x1, y1, clBtnFace, WidthLink, "LINK", colorTextHeader);

   	x1 = 430; y1 = y2;
	for( int i = 0; i < MEMORIA->Max(); i++ ) {
		DibujarRow(x1, y1, i);
		x1 = 430;
	}

    UpdateLabelLibre();
}
//---------------------------------------------------------------------------
void TForm2::DibujarField( int &x1, int &y1, TColor color, int width, AnsiString texto, TColor colorText ){
	int y2 = HeightFields + y1;

	Canvas->Brush->Color = color;
	int x2 = x1 + width;
	Canvas->Rectangle(x1, y1, x2, y2);

	Canvas->Font->Size = 16;
	Canvas->Font->Color = colorText;
	Canvas->TextOut(x1 + 2, y1 + 5, texto);
	x1 = x2;
}
void TForm2:: DibujarRow( int &x1, int &y1, int index ){
	Canvas->Pen->Color = (TColor)0x000000;
	int y2 = HeightFields + y1;

   	TColor colorTextBody = (TColor)0x000000;

	DibujarField( x1, y1, BgDir, WidthDir, MEMORIA->MEM[index].dir, colorTextBody );
	DibujarField( x1, y1, BgDato, WidthDato, MEMORIA->MEM[index].dato, colorTextBody );
	DibujarField( x1, y1, BgId, WidthId, MEMORIA->MEM[index].id, colorTextBody );
	DibujarField( x1, y1, BgLink, WidthLink, MEMORIA->MEM[index].link, colorTextBody );

	y1 = y2;
}


void __fastcall TForm2::OnCreateMemoria(TObject *Sender)
{
	if(MemoriaCreada) return;

	MEMORIA = new CMemoria();
	MemoriaCreada = true;

	Panel2->Visible = true;
    Button1->Visible = false;
	Invalidate();
}

void TForm2::UpdateLabelLibre(){
	Label6->Caption = "Dirección libre " + IntToStr(MEMORIA->getLibre());
	Label7->Caption = "Espacio disponible " + IntToStr(MEMORIA->EspacioDisponible());
}
//---------------------------------------------------------------------------

void __fastcall TForm2::OnPedirEspacio(TObject *Sender)
{
    if(!ValidarMemoria()) return;

	AnsiString nombreEspacio = EEspacioName->Text.Trim();
	int disponible = MEMORIA->EspacioDisponible();

	if( disponible == 0 ){
		ShowMessage("Memoria llena, no hay espacios disponibles");
		return;
	}
	if( nombreEspacio.Length() == 0 ){
		ShowMessage("Ingrese un nombre");
		return;
	}
	int direccion = MEMORIA->NewEspacio( nombreEspacio );

	EEspacioName->Text = "";
	ShowMessage("Se creo un espacio en memoria en la dirección: " + IntToStr(direccion) );
	Invalidate();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::OnLiberarEspacio(TObject *Sender)
{
    if(!ValidarMemoria()) return;

	AnsiString dirStr = EEspacioALiberar->Text.Trim();
	if( dirStr.Length() == 0 ){
		ShowMessage("Ingrese una dirección");
		return;
	}

	int dir = StrToInt(dirStr);

    bool estaLibre = MEMORIA->DirLibre(dir);

	if(estaLibre){
		ShowMessage("Dir ya estaba liberado");
        EEspacioALiberar->Text = "";
		return;
	}
	MEMORIA->DeleteEspacio( dir );
	ShowMessage("Espacio en memoria liberado");
	EEspacioALiberar->Text = "";
	Invalidate();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::OnPonerDato(TObject *Sender)
{
	if(!ValidarMemoria()) return;

	int dir 		 = StrToInt(EDirDato->Text);
	AnsiString id 	 = EIdDato->Text;
	AnsiString valor = EValorDato->Text;

	bool estaLibre = MEMORIA->DirLibre(dir);

	if(estaLibre){
    	ShowMessage("Dir está libre");
		return;
	}

	MEMORIA->PonerDato(dir, id, valor);
	Invalidate();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::OnMostrarMemoria(TObject *Sender)
{
	if(!ValidarMemoria()) return;
	int dir 		 = StrToInt(EShowDir->Text);
    if( EShowDir->Text.Trim().Length() == 0 ){
		ShowMessage("Ingrese una dirección");
		return;
	}
	AnsiString id 	 = EShowId->Text;
    if( id.Trim().Length() == 0 ){
		ShowMessage("Ingrese un id");
		return;
	}

	NodoM dato = MEMORIA->ObtieneDato( dir, id );

	Edit1->Text = dato.dir;
	Edit2->Text = dato.dato;
	Edit3->Text = dato.id;
	Edit4->Text = dato.link;

    Panel1->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button6Click(TObject *Sender)
{
    Panel1->Visible = false;
}
//---------------------------------------------------------------------------


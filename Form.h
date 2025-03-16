//---------------------------------------------------------------------------

#ifndef FormH
#define FormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>

#include "CMemoria.h"
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TButton *Button4;
	TButton *Button5;
	TEdit *EEspacioName;
	TEdit *EEspacioALiberar;
	TEdit *EShowDir;
	TEdit *EDirDato;
	TEdit *EShowId;
	TEdit *EIdDato;
	TEdit *EValorDato;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TPanel *Panel1;
	TEdit *Edit1;
	TEdit *Edit2;
	TEdit *Edit3;
	TEdit *Edit4;
	TEdit *Edit5;
	TEdit *Edit6;
	TEdit *Edit7;
	TEdit *Edit8;
	TButton *Button6;
	TLabel *Label6;
	TButton *Button7;
	TButton *Button8;
	TPanel *Panel2;
	void __fastcall FormPaint(TObject *Sender);
	void __fastcall OnCreateMemoria(TObject *Sender);
	void __fastcall OnPedirEspacio(TObject *Sender);
	void __fastcall OnLiberarEspacio(TObject *Sender);
	void __fastcall OnPonerDato(TObject *Sender);
	void __fastcall OnMostrarMemoria(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
private:	// User declarations

	HMemoria* MEMORIA;
	bool MemoriaCreada = false;

	bool ValidarMemoria(){
		if(!MemoriaCreada){
			ShowMessage("No se creo ninguna memoria");
			return false;
		}
		return true;
	}

	// Propiedades para dibujar con canvas
	TColor BgDir  = (TColor)0xffffff;
	TColor BgDato = (TColor)0x55dd33;
	TColor BgId   = (TColor)0x22ffff;
	TColor BgLink = (TColor)0x22ffff;

	int WidthDir  = 30;
	int WidthDato = 300;
	int WidthId   = 300;
	int WidthLink = 40;

	int HeightFields = 40;

	void DibujarRow( int &x1, int &y1, int index );
	void DibujarField( int &x1, int &y1, TColor color, int width, AnsiString texto );

public:		// User declarations
	__fastcall TForm2(TComponent* Owner);

    void UpdateLabelLibre();
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif

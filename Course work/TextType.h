//---------------------------------------------------------------------------

#ifndef TextTypeH
#define TextTypeH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.AppEvnts.hpp>
//---------------------------------------------------------------------------
class TForm5 : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TEdit *Edit1;
	TButton *Приступить;
	TPanel *Panel1;
	TPanel *Panel2;
	TPanel *Panel3;
	TLabel *Label1;
	TTimer *Timer1;
	TTimer *Timer2;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TProgressBar *ProgressBar1;
	TLabel *Label5;
	TButton *Button2;
	TButton *Button3;
	TButton *Button4;
	TButton *Button5;
	TRichEdit *RichEdit1;
	TApplicationEvents *ApplicationEvents1;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall ПриступитьClick(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall Timer2Timer(TObject *Sender);
	void __fastcall Edit1Change(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall RichEdit1Enter(TObject *Sender);
	void __fastcall RichEdit1Click(TObject *Sender);
	void __fastcall ApplicationEvents1ShortCut(TWMKey &Msg, bool &Handled);
private:	// User declarations
public:		// User declarations
	__fastcall TForm5(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm5 *Form5;
//---------------------------------------------------------------------------
#endif

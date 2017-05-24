//---------------------------------------------------------------------------

#include <vcl.h>
#include <ctime>
#include <conio.h>
#pragma hdrstop

#include "TextType.h"
#include "UserWindow.h"
extern I;
extern struct Init
{
	char Prob[4];
	char Record[4];
	char Med[4];
	char Mist[4];
} Info;
String Nabor, Path;
int i = 5, TimeSec = 1, Mistakes = 0, CursorEd = 1, CursorEdit,  Mist = 0;;
float SpeedText = 0;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm5 *Form5;
//---------------------------------------------------------------------------
__fastcall TForm5::TForm5(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm5::Button1Click(TObject *Sender)
{
	Edit1->Text = "Здесь будете набирать текст";
	Edit1->Enabled = false;
	Timer2->Enabled = false;
	Timer1->Enabled = false;
	i = 5;
	Label1->Caption = "Начало через: " + IntToStr(i) + "...";
	Label2->Caption = "";
	Panel1->Color = clLime;
	CursorEd = 1;
	ProgressBar1->Min = CursorEd;
	ProgressBar1->Position = CursorEd;
	Nabor = "";
	TimeSec = 1;
	SpeedText = 0;
	Mistakes = 0;
	Form5->Close();
	Form4->Show();
}
//---------------------------------------------------------------------------
void __fastcall TForm5::ПриступитьClick(TObject *Sender)
{
	srand(time(0));
	Panel3->Caption = "0";
	int Num = 1 + rand()% 5;
	if (I == 1) {
		Path = "Texts\\Easy\\" + IntToStr(Num) + ".txt";
	}
	else if (I == 2){
		Path = "Texts\\Normal\\" + IntToStr(Num) + ".txt";
	}
	else if (I == 3){
		Path = "Texts\\Hard\\" + IntToStr(Num) + ".txt";
	}
	Button3->Click();
}
//---------------------------------------------------------------------------

void __fastcall TForm5::Timer1Timer(TObject *Sender)
{
	i--;
	Label1->Caption = "Начало через: " + IntToStr(i) + "...";
	if (i == 0){
		Label1->Caption = "Набирайте!";
		Edit1->Enabled = true;
		Edit1->SetFocus();
		Timer1->Enabled = false;
		Timer2->Enabled = true;
		Edit1->Clear();
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm5::Timer2Timer(TObject *Sender)
{
	Label1->Caption = "Прошло время: " + IntToStr(TimeSec);
	TimeSec++;
}
//---------------------------------------------------------------------------

void __fastcall TForm5::Edit1Change(TObject *Sender)
{
	if (Edit1->Text != ""){
		String A = Edit1->Text;
		CursorEdit = A.Length();
		Button5->Click();
		if(A[CursorEdit] == Nabor[CursorEd]){ // исправить
			Panel1->Color = clLime;
			Label2->Caption = "";
			CursorEd++;
			ProgressBar1->Position = CursorEd;
			if (Nabor[CursorEd + 1] == '~'){
				Button2->Click();
			}
			if (A[CursorEdit] == ' '){
				SpeedText = 60*CursorEd/TimeSec;
				Panel2->Caption = FloatToStr(SpeedText);
				Edit1->Clear();
			}
		}
		else {
			Button4->Click();
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm5::Button2Click(TObject *Sender)
{
	Timer2->Enabled = false;
	Edit1->Clear();
	Edit1->Enabled = false;
	ShowMessage("Завершено.\nПрошло времени: " + IntToStr(TimeSec) + " сек.\nСкорость: "+ FloatToStr(60*CursorEd/TimeSec) + "\nОшибок: " + IntToStr(Mistakes/2)+ "\nНажмите <Выход>, для выхода из режима.");
	int Temp = atoi(Info.Prob);
	Temp++;
	itoa(Temp, Info.Prob, 10);
	Mist = (Mistakes*1000)/CursorEd;
	Form4->Button2->Click();
}
//---------------------------------------------------------------------------

void __fastcall TForm5::Button3Click(TObject *Sender)
{
	TStringList *SL = new TStringList;
	SL->LoadFromFile(Path);
	Nabor = SL->Strings[0];
	RichEdit1->Text = Nabor;
	ProgressBar1->Max = Nabor.Length();
	Nabor = Nabor + ".~";
	Timer1->Enabled = true;
	Приступить->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm5::Button4Click(TObject *Sender)
{
	Mistakes++;
	RichEdit1->SelStart = CursorEd - 1;// исправление ошибок сделать норм
	RichEdit1->SelLength = 1;
	RichEdit1->SelAttributes->Color = clRed;
	Panel1->Color = clRed;
	Panel3->Caption = IntToStr(Mistakes);
	Label2->Font->Color = clRed;
	Label2->Caption = "Исправьте ошибку!";
}
//---------------------------------------------------------------------------

void __fastcall TForm5::Button5Click(TObject *Sender)
{
	RichEdit1->SelStart = CursorEd - 1;
	RichEdit1->SelLength = 1;
	RichEdit1->SelAttributes->Color = clGreen;
}
//---------------------------------------------------------------------------

void __fastcall TForm5::RichEdit1Enter(TObject *Sender)
{
    SelectNext(Form5->ActiveControl, true, true);
}
//---------------------------------------------------------------------------

void __fastcall TForm5::RichEdit1Click(TObject *Sender)
{
	Edit1->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TForm5::ApplicationEvents1ShortCut(TWMKey &Msg, bool &Handled)
{
	if (CursorEd > 1){               // исправить
		if (Msg.CharCode == 0x8) { // Клавиша Backspace
			Mistakes--;
		}
	}
}
//---------------------------------------------------------------------------


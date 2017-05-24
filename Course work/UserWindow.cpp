//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UserWindow.h"
#include "UserInfo.h"
#include "TextType.h"
extern struct Init
{
	char Prob[4];
	char Record[4];
	char Med[4];
	char Mist[4];
} Info;
int I;
int Speed;
extern String PathGl;
extern int Mist;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Button1Click(TObject *Sender)
{
	Form4->Close();
	Form3->Show();
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Button4Click(TObject *Sender)
{
	if (I == 0)
		ShowMessage("Выберите сложность!");
	else
	{
	Form5->RichEdit1->Text = "Нажмите \"Приступить\" для начала испытания.";
	if (I == 1)
		Form5->Caption = "Набор текста: легко";
	if (I == 2)
		Form5->Caption = "Набор текста: средне";
	if (I == 3)
		Form5->Caption = "Набор текста: сложно";
	Form5->Приступить->Enabled = true;
	Form4->Hide();
	Form5->Show();
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm4::RadioButton1Click(TObject *Sender)
{
    I = 1;
}
//---------------------------------------------------------------------------

void __fastcall TForm4::RadioButton2Click(TObject *Sender)
{
    I = 2;
}
//---------------------------------------------------------------------------

void __fastcall TForm4::RadioButton3Click(TObject *Sender)
{
    I = 3;
}
//---------------------------------------------------------------------------

void UpdateStat(){
	Speed = StrToInt(Form5->Panel2->Caption);
	Form5->Panel2->Caption = "";
	Form5->Panel3->Caption = "";
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button2Click(TObject *Sender)
{
	UpdateStat();
	Panel1->Caption = "Пройдено текстов: " + AnsiString(Info.Prob);
	if (Speed > atoi(Info.Record)){
		char BUF[4];
		itoa(Speed, BUF, 10);
		strcpy(Info.Record, BUF);
		Panel2->Caption = "Рекорд: " + AnsiString(Info.Record);
	}
	Button3->Click();
	DeleteFile(PathGl);
	TFileStream* fb = new TFileStream(PathGl, fmCreate);
	fb->Position = soFromBeginning;
	fb->Write(&Info,sizeof(Info));
	delete fb;
	fb = NULL;
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button3Click(TObject *Sender)
{
	int TempMiddle, TempMist;
	TempMiddle = ((atoi(Info.Prob) - 1) * atoi(Info.Med) + Speed)/(atoi(Info.Prob));
	itoa(TempMiddle, Info.Med, 10);
	Panel3->Caption = "Средняя скорость: " + AnsiString(Info.Med);
	TempMist = ((atoi(Info.Prob) - 1) * atoi(Info.Mist) + Mist)/(atoi(Info.Prob));
	itoa(TempMist, Info.Mist, 10);
	Panel4->Caption = "Ошибок: " + IntToStr(TempMist/10) + "," + IntToStr(TempMist%10) + "%";
}
//---------------------------------------------------------------------------


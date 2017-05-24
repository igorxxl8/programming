//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UserInfo.h"
#include "Menu.h"
#include "UserWindow.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
struct Init
{
	char Prob[4];
	char Record[4];
	char Med[4];
	char Mist[4];
} Cr, Info;
String PathGl;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
	strcpy(Cr.Prob, "0");
	strcpy(Cr.Record,"0");
	strcpy(Cr.Med,"0");
	strcpy(Cr.Mist,"0");
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button1Click(TObject *Sender)
{
	Form1->Show();
	Form3->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button2Click(TObject *Sender)
{
	String User, Path;
	User = Edit1->Text;
	Path ="Users\\" + User + ".txt";
	PathGl = Path;
	if (!FileExists(Path)){
		ShowMessage("Пользователь \""+ User + "\" не существует! Нажмите <Создать> для создания нового пользователя.");
		Button3->Enabled = true;
	}
	else{
		TFileStream* fb = new TFileStream(Path, fmOpenReadWrite);
		fb->Position = soFromBeginning;
		fb->Read(&Info,sizeof(Info));
		delete fb;
		fb = NULL;
		Form4->Caption ="Информация о пользователе: \"" + User + "\"";
		Button5->Click();
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button3Click(TObject *Sender)
{
	String User, Path;
	User = Edit1->Text;
	Path ="Users\\" + User + ".txt";
	if (FileExists(Path))
		{
		if (MessageDlg("Пользователь \""+ User + "\" уже существует! Перезаписать данного пользователя?\nПредыдущая статистика будет утеряна!", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo,0) == mrNo){}
		else{
			TFileStream* fb = new TFileStream(Path, fmCreate);
			ShowMessage("Пользователь \"" + User + "\" создан.");
			fb->Position = soFromBeginning;
			fb->Write(&Cr,sizeof(Cr));
			delete fb;
			fb = NULL;
			}
		}
	else{
		TFileStream* fb = new TFileStream(Path, fmCreate);
		ShowMessage("Пользователь \"" + User + "\" создан.");
		fb->Position = soFromBeginning;
		fb->Write(&Cr,sizeof(Cr));
		delete fb;
		fb = NULL;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button4Click(TObject *Sender)
{
	String User, Path;
	User = Edit1->Text;
	Path ="Users\\" + User + ".txt";
	if (!FileExists(Path)){
		ShowMessage("Такого пользователя \""+ User + "\" не существует!");
	}
	else{
		DeleteFile(Path);
		ShowMessage("Пользователь \""+ User + "\" удален!");
	}
}
//---------------------------------------------------------------------------


void __fastcall TForm3::Button5Click(TObject *Sender)
{
	Form3->Hide();
	Form4->Panel1->Caption = "Пройдено текстов: " + AnsiString(Info.Prob);
	Form4->Panel2->Caption = "Рекорд: " + AnsiString(Info.Record);
	Form4->Panel3->Caption = "Средняя скорость: " + AnsiString(Info.Med);
	Form4->Panel4->Caption = "Ошибок: " + IntToStr(atoi(Info.Mist)/10) + "," + IntToStr(atoi(Info.Mist)%10) + "%";
	Form4->Show();
}
//---------------------------------------------------------------------------


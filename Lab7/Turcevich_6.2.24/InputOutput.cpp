#include "stdafx.h"
#include "InputOutput.h"

void ClearFile()
{
	fstream clear_file("Программы.txt", ios::out);
	clear_file.close();
}

void FileInit(ifstream &FileIn, turProgram** Begin)
{
	turProgram* Temp = new turProgram;
	printf("lol\n");
	if (!FileIn.is_open()) {
		puts("Файл не может быть открыт!");
		_getch();
		exit(-1);
	}
	int i = 0;
	const int N = 1000;
	char str[N];
	while (!FileIn.eof())
	{
		FileIn.getline(str, N, '\n');
		i++;
	}
	FileIn.clear();
	FileIn.seekg(0, ios_base::beg);
	char **BUFER = new char*[i - 1];
	for (int A = 0; A < i - 1; A++)
		BUFER[A] = new char[N];
	for (int B = 0; B < i - 1; B++) {
		FileIn.getline(BUFER[B], N);
		InitProgram(&Temp, BUFER[B]);
		Temp->next = *Begin;
		*Begin = Temp;
	}

	for (int A = 0; A < i - 1; A++)
		delete BUFER[A];
	delete[] BUFER;
}

void FileOutput(ofstream &File, turProgram *A) {
	File << A->Number << '~';
	File << A->ProgramName << '~';
	File << A->Path << '~';
	File << A->Date << '~';
	File << A->EmptySpace << '~';
	File << A->TourPrice << '~';
	File << A->ServCount << '`';
	services *Temp = A->Service;
	for (int i = 1; i <= A->ServCount; i++) {
		File << Temp->NumberServ << '~';
		File << Temp->NameServ << '~';
		File << Temp->Price << '~';
		File << Temp->Obligatory << '`';
		Temp = Temp->next;
	}
	File << endl;
};

void InitService(services** Head, char* Str1, char* Str2, char* Str3, char* Str4)
{
	services *TempServ = new services;
	TempServ->NumberServ = atoi(Str1);
	TempServ->NameServ = Str2;
	TempServ->Price = atoi(Str3);
	if (atoi(Str4))
		TempServ->Obligatory = true;
	else
		TempServ->Obligatory = false;
	TempServ->next = *Head;
	*Head = TempServ;
}

void InitProgram(turProgram ** Begin, char* Str)
{
	int C = 8;
	int Usl = -1;
	for (int i = 0, j = strlen(Str); i <= j; i++)
		if (Str[i] == '`')
			Usl++;
	C += Usl * 4;
	char **Temp = new char*[C];
	for (int A = 0; A < C; A++)
		Temp[A] = new char[1000];
	for (int i = 0, j = strlen(Str), t = 0, k = 0; i <= j; i++, k++) {
		if (Str[i] != '~' && Str[i] != '`')
			Temp[t][k] = Str[i];
		else
		{
			Temp[t][k] = '\0';
			t++;
			k = -1;
		}
	}
	turProgram *Elem = new turProgram;
	Elem->Number = atoi(Temp[0]);
	Elem->ProgramName = Temp[1];
	Elem->Path = Temp[2];
	Elem->Date = Temp[3];
	Elem->EmptySpace = atoi(Temp[4]);
	Elem->TourPrice = atoi(Temp[5]);
	Elem->ServCount = atoi(Temp[6]);
	for (int i = 0, j = 7; i < Usl; i++) {
		InitService(&(Elem->Service), Temp[j], Temp[j + 1], Temp[j + 2], Temp[j + 3]);
		j += 4;
	}
	Elem->next = *Begin;
	*Begin = Elem;
}

void FileUpd(ofstream &FileOut, turProgram * Begin)
{
	turProgram* Temp = Begin;
	while (Temp) {
		FileOutput(FileOut, Temp);
		Temp = Temp->next;
	}
}

void ShowService(services * Head)
{
	services *show = Head;
	while (show) {
		printf("-----------------------------------------\n");
		cout << show->NumberServ << "-ая услуга:\n";
		cout << "Название услуги: " << show->NameServ << endl;
		cout << "Стоимость услуги: " << show->Price << "$" << endl;
		cout << "Обязательность: ";
		if (show->Obligatory)
			cout << "Да\n";
		else
			cout << "Нет\n";
		printf("-----------------------------------------\n");
		show = show->next;
	}
}

void ShowProgram(turProgram * Begin)
{
	turProgram *print = Begin;
	while (print)
	{
		printf("\n_________________________________________\n");
		cout << "Номер турпрограммы: " << print->Number << endl;
		cout << "Название: " << print->ProgramName << endl;
		cout << "Маршрут: " << print->Path << endl;
		cout << "Дата проведения: " << print->Date << endl;
		cout << "Количество свободных мест: " << print->EmptySpace << endl;
		cout << "Стоимость поездки: " << print->TourPrice << "$" << endl;
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		cout << "Количество услуг: " << print->ServCount << endl;
		cout << "Услуги: " << endl;
		ShowService(print->Service);
		printf("_________________________________________\n");
		print = print->next;
	}
}


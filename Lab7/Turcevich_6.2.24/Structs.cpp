#pragma once
#include "stdafx.h"
#include "Structs.h"

static bool Obl()
{
	char Ch;
	Ch = _getch();
	cout << endl;
	if (Ch == 'y' || Ch == 'Y')
		return true;
	else
		return false;
}

void ExMenu()
{
	printf("������� ����� ������� ��� ������ � ����: ");
	_getch();
}

int Input() {
	char a[BUF];
	for (;;) {
		gets_s(a, BUF);
		if (a[0] == 'e' && a[1] == 'x' && a[2] == 'i' && a[3] == 't')
			return -1;
		int b = strlen(a);
		if (b >= 10) {
			printf("������ ����������� ������� ��������. ������� �������� ������ 10 ������: ");
		}
		else {
			for (int i = 0; i < BUF; i++) {
				if (a[i] <= 57 && a[i] >= 48) {
					b--;
				}
			}
			if (a[0] == '0')
				return 0;
			else if (!atoi(a))
				printf("Error. Enter natural number or control word exit: ");
			else if (!b)
				return atoi(a);
			else
				printf("Error. Enter natural number or control word exit: ");
		}
	}
}

int AddService(services** Head, int i)
{
	services *TempServ = new services;
	printf("------------------------------------------\n");
	printf("���������� %d ������: \n", i);
	TempServ->NumberServ = i;
	printf("������� �������� ������: ");
	getline(cin, TempServ->NameServ);
	printf("������� ��������� ������ ($): ");
	TempServ->Price = Input();
	printf("������������ ������?(������� Y, ���� ��, ��� ������� ������ ������� - ���): ");
	TempServ->Obligatory = Obl();
	TempServ->next = *Head;
	*Head = TempServ;
	return 1;
}

int OformProgram(turProgram** Begin)
{
	if (*Begin == NULL) {
		return 0;
	}
	turProgram *avaible = *Begin;
	if (avaible->EmptySpace == NULL) {
		printf("��������� %d ���������;\n", avaible->Number);
		*Begin = avaible->next;
		delete avaible;
		return 1;
	}
	turProgram *avaible1 = avaible->next;
	while (avaible1) {
		if (avaible1->EmptySpace == NULL) {
			printf("��������� %d ���������;\n", avaible1->Number);
			avaible->next = avaible1->next;
			delete avaible1;
			return 1;
		}
		avaible = avaible1;
		avaible1 = avaible1->next;
	}
	return 0;
}

int AvaibleProgram(turProgram * Begin)
{
	int i = 0;
	turProgram *avaible = Begin;
	while (avaible) {
		if (avaible->EmptySpace > NULL) {
			cout << avaible->ProgramName;
			printf(" (����� - %d, - c�������� ���� - %d), ", avaible->Number, avaible->EmptySpace);
			i++;
		}
		avaible = avaible->next;
	}
	if (i!=0)
		printf("\n");
	return i;
}

int ChooseService(services *Head, int *Money, int Pass, bool X)
{
	services *show = Head;
	while (show) {
		if(X){
			*Money += Pass*show->Price;
			show = show->next;
		}
		else {
			if (show->Obligatory) {
				*Money += Pass*show->Price;
				show = show->next;
			}
			else {
				printf("-----------------------------------------\n");
				cout << "����� ������: " << show->NumberServ << endl;
				cout << "�������� ������: " << show->NameServ << endl;
				cout << "��������� ������: " << show->Price << "$" << endl;
				printf("�������� � ������ �����?(������� Y, ���� ��, ��� ������� ������ ������� - ���): ");
				if (Obl()) {
					printf("���������!\n");
					*Money += Pass*show->Price;
				}
				else
					printf("�� ���������!\n");
				show = show->next;
			}
		}
	}
	return 1;
}

void ChooseProgram(turProgram** Begin, bool X, int *Money)
{
	printf("�������� ����� ��������� ������������, ������� ������ �������� ��� exit ��� ������ ������: ");
	int Passenger;
	int YourMoney = 0;
	int LoL = 0;
	for (;;) {
		turProgram *avaible = *Begin;
		int Choice = Input();
		if (Choice == -1)
			break;
		while (avaible) {
			if (Choice == avaible->Number) {
				system("cls");
				if (X) {
					Passenger = 1;
					avaible->EmptySpace--;
				}
				else{
					printf("������� ���������� ���� ������� ������ ��������: \n");
					for (;;) {
						Passenger = Input();
						if (Passenger > avaible->EmptySpace)
							printf("���������� ��������� ���� ������������ ��� ������� ������. ������� ������� �����!\n");
						else
							break;
					}
					avaible->EmptySpace -= Passenger;
				}
				YourMoney += Passenger*avaible->TourPrice;
				printf("������� ������ ��������� ��� ������� �������������� �������������� ������?(������� Y ��� ������ ������ ���������, ��� ������� ������ ������� - ��������������): ");
				if (Obl()) {
					printf("������� ������ ���������!\n");
					LoL = ChooseService(avaible->Service, &YourMoney, Passenger, true);
				}
				else {
					printf("�������������� ������, ������� ������ ������ � ���� ���������: \n");
					LoL = ChooseService(avaible->Service, &YourMoney, Passenger, false);
				}
				Sleep(3000);
				system("cls");
				cout<<"������� ������������: " << avaible->ProgramName<<", ��������� ���� ��� ����� �����: "<< avaible->TourPrice<<endl;
				printf("�������� ����: %d, �������� ������ �����: %d$\n", Passenger, YourMoney/Passenger);
				printf("��������� ������ ������������: %d$\n", YourMoney);
				string Contact;
				printf("������� ���� ������ (����� ��������, ���� ������ ��������): \n");
				getline(cin, Contact);
				printf("����� ��� �������� � ���� ��������!\n");
				break;
			}
			avaible = avaible->next;
		}
		if (!LoL)
			printf("����� ��������� �� ����������. �������� �� ������ ���������: ");
		else {
			*Money += YourMoney;
			break;
		}
	}
}

void AddServiceInProgram(turProgram** Begin)
{
	printf("�������� ����� ��������� ������������, � ������� ������ �������� ������ ��� ������� exit ��� ������ ����������: ");
	int LoL = 0;
	for (;;) {
		turProgram *avaible = *Begin;
		int Choice = Input();
		if (Choice == -1)
			break;
		while (avaible) {
			if (Choice == avaible->Number) {
				LoL = AddService(&(avaible->Service), ++avaible->ServCount);
				break;
			}
			avaible = avaible->next;
		}
		if (!LoL)
			printf("����� ��������� �� ����������. �������� �� ������ ���������: ");
		else
			break;
	}
}

int CheckNum(turProgram * Begin)
{
	turProgram *check = Begin;
	int A;
	A = Input();
	for (;;) {
		while (check) {
			if (A == check->Number) {
				printf("��������� � ����� ������� ��� ����������. ������� ������ �����: ");
				A = Input();
				check = Begin;
			}
			else 
				check = check->next;
		}
		return A;
	}
}

void AddProgram(turProgram** Begin) {
	turProgram *Temp = new turProgram;
	printf("������� ����� ������������: ");
	Temp->Number = CheckNum(*Begin);
	printf("������� �������� ������������: ");
	getline(cin, Temp->ProgramName);
	printf("������� ��������� ������������ ($): ");
	Temp->TourPrice =Input();
	printf("���������� � ������������:\n");
	printf("������� �������: ");
	getline(cin, Temp->Path);
	printf("������� ���������� ��������� ����: ");
	Temp->EmptySpace = Input();
	printf("������� ���� �������: ");
	getline(cin, Temp->Date);
	printf("���������� �����: \n");
	for (int i = 1; ; i++) {
		AddService(&(Temp->Service), i);
		printf("�������� ��� ������?(������� Y, ���� ��, ��� ������� ������ ������� - ���): ");
		if (!Obl()) {
			Temp->ServCount = i;
			break;
		}
	}
	Temp->next = *Begin;
	*Begin = Temp;
}



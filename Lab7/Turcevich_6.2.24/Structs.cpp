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
	printf("Нажмите любую клавишу для выхода в меню: ");
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
			printf("Ошибка недопустимо большое значение. Введите значение меньше 10 знаков: ");
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
	printf("Добавление %d услуги: \n", i);
	TempServ->NumberServ = i;
	printf("Введите название услуги: ");
	getline(cin, TempServ->NameServ);
	printf("Введите стоимость услуги ($): ");
	TempServ->Price = Input();
	printf("Обязательная услуга?(Введите Y, если да, при нажатии другой клавиши - нет): ");
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
		printf("Программа %d оформлена;\n", avaible->Number);
		*Begin = avaible->next;
		delete avaible;
		return 1;
	}
	turProgram *avaible1 = avaible->next;
	while (avaible1) {
		if (avaible1->EmptySpace == NULL) {
			printf("Программа %d оформлена;\n", avaible1->Number);
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
			printf(" (номер - %d, - cвободных мест - %d), ", avaible->Number, avaible->EmptySpace);
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
				cout << "Номер услуги: " << show->NumberServ << endl;
				cout << "Название услуги: " << show->NameServ << endl;
				cout << "Стоимость услуги: " << show->Price << "$" << endl;
				printf("Добавить в список услуг?(Введите Y, если да, при нажатии другой клавиши - нет): ");
				if (Obl()) {
					printf("Добавлено!\n");
					*Money += Pass*show->Price;
				}
				else
					printf("Не добавлено!\n");
				show = show->next;
			}
		}
	}
	return 1;
}

void ChooseProgram(turProgram** Begin, bool X, int *Money)
{
	printf("Выберите номер доступной турпрограммы, которую хотите заказать или exit для отмены заказа: ");
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
					printf("Введите количество мест которые хотите заказать: \n");
					for (;;) {
						Passenger = Input();
						if (Passenger > avaible->EmptySpace)
							printf("Количества свободных мест недостаточно для данного заказа. Введите меньшее число!\n");
						else
							break;
					}
					avaible->EmptySpace -= Passenger;
				}
				YourMoney += Passenger*avaible->TourPrice;
				printf("Выбрать полную программу или выбрать самостоятельно необязательные услуги?(Введите Y для выбора полной программы, при нажатии другой клавиши - самостоятельно): ");
				if (Obl()) {
					printf("Выбрана полная программа!\n");
					LoL = ChooseService(avaible->Service, &YourMoney, Passenger, true);
				}
				else {
					printf("Необязательные услуги, которые хотите внести в свою программу: \n");
					LoL = ChooseService(avaible->Service, &YourMoney, Passenger, false);
				}
				Sleep(3000);
				system("cls");
				cout<<"Выбрана турпрограмма: " << avaible->ProgramName<<", стоимость тура без учета услуг: "<< avaible->TourPrice<<endl;
				printf("Заказано мест: %d, стоимось одного места: %d$\n", Passenger, YourMoney/Passenger);
				printf("Стоимость заказа турпрограммы: %d$\n", YourMoney);
				string Contact;
				printf("Введите ваши данные (номер телефона, либо другие контакты): \n");
				getline(cin, Contact);
				printf("Скоро наш оператор с вами свяжется!\n");
				break;
			}
			avaible = avaible->next;
		}
		if (!LoL)
			printf("Такой программы не существует. Выберите из списка доступных: ");
		else {
			*Money += YourMoney;
			break;
		}
	}
}

void AddServiceInProgram(turProgram** Begin)
{
	printf("Выберите номер доступной турпрограммы, в которую хотите добавить услугу или введите exit для отмены добавления: ");
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
			printf("Такой программы не существует. Выберите из списка доступных: ");
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
				printf("Программа с таким номером уже существует. Введите другой номер: ");
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
	printf("Введите номер турпрограммы: ");
	Temp->Number = CheckNum(*Begin);
	printf("Введите название турпрограммы: ");
	getline(cin, Temp->ProgramName);
	printf("Введите стоимость турпрограммы ($): ");
	Temp->TourPrice =Input();
	printf("Информация о турпрограмме:\n");
	printf("Введите маршрут: ");
	getline(cin, Temp->Path);
	printf("Введите количество свободных мест: ");
	Temp->EmptySpace = Input();
	printf("Введите дату поездки: ");
	getline(cin, Temp->Date);
	printf("Добавление услуг: \n");
	for (int i = 1; ; i++) {
		AddService(&(Temp->Service), i);
		printf("Добавить еще услугу?(Введите Y, если да, при нажатии другой клавиши - нет): ");
		if (!Obl()) {
			Temp->ServCount = i;
			break;
		}
	}
	Temp->next = *Begin;
	*Begin = Temp;
}



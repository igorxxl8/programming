#include "stdafx.h"
#include "InputOutput.h"
#include "Menu.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <fstream>

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	turProgram* Begin = NULL;
	int DOXOD = 0;
	ifstream FileIn("���������.txt");
	ofstream FileOut("���������.txt", ios_base::app);
	FileInit(FileIn, &Begin);
	for (;;) {
		system("cls");
		switch (Menu()) {
		case 1: {
			printf("��������� ������������: ");
			if (!Begin)
				printf("��� ��������� �����������!\n");
			else
				ShowProgram(Begin);
			ExMenu();
		}break;
		case 2:{
			printf("��������� ������������: ");
			int T = AvaibleProgram(Begin);
			if (!T) {
				printf("��� ��������� �����������.\n����� �������� ������ ���������� ������������� ������������!\n");
				Sleep(3000);
				break;
			}
			AddServiceInProgram(&Begin);
			ClearFile();
			FileUpd(FileOut, Begin);
			ExMenu();
		}break;
		case 3:{
			puts("�������� ����� ��� ���������:");
			printf("__________________________________________\n");
			AddProgram(&Begin);
			FileOutput(FileOut, Begin);
		}break;
		case 4:{
			printf("��������� ������������: ");
			int T = AvaibleProgram(Begin);
			if (!T) {
				printf("��� ��������� �����������.\n��� ������ ��������� ���������� �� �������������!\n");
				Sleep(3000);
				break;
			}
			ChooseProgram(&Begin, true, &DOXOD);
			ClearFile();
			FileUpd(FileOut, Begin);
			ExMenu();
		}break;
		case 5:{
			printf("��������� ������������: ");
			int T = AvaibleProgram(Begin);
			if (!T) {
				printf("��� ��������� �����������.\n��� ������ ��������� ���������� �� �������������!\n");
				Sleep(3000);
				break;
			}
			ChooseProgram(&Begin, false, &DOXOD);
			ClearFile();
			FileUpd(FileOut, Begin);
			ExMenu();
		}break;
		case 6:{
			int K;
			int N = 0;
			printf("���������� ���������������� �����������:\n");
			for (;;) {
				K = OformProgram(&Begin);
				N++;
				if (!K) {
					break;
				}
			}
			if (N == 1)
				printf("��� ���������������� ��������!\n");
			else {
				ClearFile();
				FileUpd(FileOut, Begin);
			}
			printf("���������� �� ������� ����� ��������: %d$\n", DOXOD);
			ExMenu();
		}break;
		case 0:{
			FileIn.close();
			FileOut.close();
			exit(0);
		}
		}
	}
	system("pause");
	return 0;
}
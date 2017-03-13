#include "stdafx.h"
#include <string.h>
#include <windows.h>

#define CEMENT_1 230
#define CEMENT_2 160
#define GRAVII_1 142
#define GRAVII_2 96
#define BETON_1 260
#define BETON_2 205
#define VAGON 50
#define BEL_DOS 200
#define RUS_UKR 320
#define MOL_DOS 360
#define DOXOD 25000

struct Zakaz
{
	int Cement = 0;
	int Gravii = 0;
	int Beton = 0;
	int Cost = 0;
	int Doxod = 0;
	int Weight = 0;
	int CounVag = 0;
	char Country1[10];

};
int Input() {
	char a[10];
	for (;;) {
		gets_s(a, 10);
		int b = strlen(a);
		for (int i = 0; i < 10; i++) {
			if (a[i] <= 57 && a[i] >= 48) {
				b--;
			}
		}
		if (!b)
			return atoi(a);
		else
			printf("Error. Enter a number: ");
	}
};
int Menu();
void Cement(Zakaz *a) {
	system("cls");
	printf("---------------------------------------------\n");
	printf("How many tonn of cement do you want to buy?\n");
	a[0].Cement = Input();
	int Cost= a[0].Cement * CEMENT_1;
	a[0].Cost += Cost;
	a[0].Weight += a[0].Cement;
	a[0].Doxod += (Cost - a[0].Cement*CEMENT_2);
	printf("---------------------------------------------\n");
}
void Gravii(Zakaz *a) {
	system("cls");
	printf("---------------------------------------------\n");
	printf("How many tonn of gravii do you want to buy?\n");
	a[0].Gravii = Input();
	int Cost = a[0].Gravii * GRAVII_1;
	a[0].Cost += Cost;
	a[0].Weight += a[0].Gravii;
	a[0].Doxod += (Cost - a[0].Gravii*GRAVII_2);
	printf("---------------------------------------------\n");
}
void Beton(Zakaz *a) {
	system("cls");
	printf("---------------------------------------------\n");
	printf("How many tonn of beton do you want to buy?\n");
	a[0].Beton = Input();
	int Cost = a[0].Beton * BETON_1;
	a[0].Cost += Cost;
	a[0].Weight += a[0].Beton;
	a[0].Doxod += (Cost - a[0].Beton*BETON_2);
	printf("---------------------------------------------\n");
};
void Country(Zakaz *a) {
	system("cls");
	printf("Delivery in which country?\n");
	for (;;) {
		gets_s(a[0].Country1, 9);
		if (strstr(a[0].Country1, "belarus") || strstr(a[0].Country1, "Belarus")|| strstr(a[0].Country1, "BELARUS")) {
			a[0].CounVag=BEL_DOS;
			break;
		}
		else if (strstr(a[0].Country1, "ukraine") || strstr(a[0].Country1, "russia") || strstr(a[0].Country1, "Ukraine") || strstr(a[0].Country1, "RUSSIA")||strstr(a[0].Country1, "UKRAINE") || strstr(a[0].Country1, "Russia")) {
			a[0].CounVag = RUS_UKR;
			break;
		}
		else if (strstr(a[0].Country1, "moldova") || strstr(a[0].Country1, "Moldova") || strstr(a[0].Country1, "MOLDOVA")) {
			a[0].CounVag = MOL_DOS;
			break;
		}
		else
			printf("Delivery in this country is not available.\nPlease choose Russia, Belarus, Ukraine, Moldova.\n");
		}
	printf("---------------------------------------------\n");
};
void DevVer() {
	system("cls");
	printf("----------------------------------------------------------------\n");
	printf("Developer: Turcevich Igor Mikhailovich. Group 653502.\nVersion 1.0a.\n");
	printf("----------------------------------------------------------------\n");
	Sleep(5000);
}
void View(Zakaz *a) {
	system("cls");
	float b = (float)a[0].Weight / (float)VAGON;
	if (b - a[0].Weight / VAGON)
		b++;
	a[0].Doxod -= a[0].CounVag*(int)b;
	printf("---------------------------------------------\n");
	printf("Beton cost - %d;\nGravii cost - %d\nCement cost - %d\n", BETON_1, GRAVII_1, CEMENT_1);
	printf("You buy:\nBeton - %d, Gravii - %d, Cement - %d.\n", a[0].Beton,a[0].Gravii, a[0].Cement);
	printf("Vagons quantity - %d, Delivery cost - %d.\n", (int)b,a[0].CounVag*(int)b);
	printf("---------------------------------------------\n");
	Sleep(10000);
}
void Buy(Zakaz *a, Zakaz *b, int N) {
	system("cls");
	b = (Zakaz*)malloc(sizeof(Zakaz) * N);
	N--; 
	b[N] = a[0];
}
int main() {
	Zakaz zakaz[1];
	strcpy_s(zakaz[0].Country1, "undefine");
	for (;;) {
		switch (Menu()) {
		case 1: {
			Cement(zakaz);
		}
			break;
		case 2:
			Gravii(zakaz);
			break;
		case 3:
			Beton(zakaz);
			break;
		case 4:
			Country(zakaz);
			break;
		case 5:
			View(zakaz);
			break;
		case 6: {
			system("cls");
			if (zakaz[0].Doxod >= DOXOD && !strstr(zakaz[0].Country1, "undefine")) {
				printf("Order?(Y|N or exit)\n");
				char ch[3];
				for (;;) {
					gets_s(ch, 2);
					if (ch[0] == 'Y' || ch[0] == 'y') {
						printf("Info about order:\n");
						printf("---------------------------------------------\n");
						printf("Order cost = %d$;\nProfit for interprise = %d$;\n", zakaz[0].Cost, zakaz[0].Doxod);
						printf("---------------------------------------------\nFor exit to menu hit N\n");
					}
					else {
						printf("Enter Y if you change your mind or Q for exit to menu.\n");
						break;
					}
				}
			}
			else {
				printf("-----------------------------------------\n");
				printf("Ordering inappropriate for the enterprise.\nPlease buy more raw or choose country.\n");
				printf("-----------------------------------------\n");
			}
		}
				break;
		case 7:
			DevVer();
			break;
		case 0: {
			exit(0);
		}
			break;
		default:
		{
			system("cls");
			printf("Error Choose number 0 - 7.\n------------------------\n");
			Sleep(1000);
			main();
		}
		}
	}
}
int Menu() {
	system("cls");
	printf("---------------------\n");
	printf("OAO StroiInvest.\n---------------------\nChoose punkt:\n");
	printf("1. Order cement (tons);\n");
	printf("2. Order gravii (tons);\n");
	printf("3. Order beton (tons);\n");
	printf("4. Country delivery;\n");
	printf("5. Order params;\n");
	printf("6. Buy;\n");
	printf("7. Program info;\n");
	printf("0. Quit.\n");
	printf("(>>>)");
	int a = Input();
	return a;
}
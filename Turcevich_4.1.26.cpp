#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <conio.h>

#define BUF 50

void GenData(char* a, char* b) {
	int c = 10 + rand() % (BUF - 10), d = 10 + rand() % (BUF - 10);
	for (int i = 0; i < c; i++)
		a[i] = 48 + (rand() % 10);
	a[c] = '\0';
	for (int i = 0; i < d; i++)
		b[i] = 48 + (rand() % 10);
	b[d] = '\0';
}

void Validate(char* a) {
	for (;;) {
		std::cin >> a;
		int b = strlen(a);
		for (int i = 0; i < BUF; i++) {
			if (a[i] <= 57 && a[i] >= 48) {
				b--;
			}
		}
		if (!atoi(a))
			std::cout << "Error. Enter natural number: ";
		else if (!b)
			return;
		else
			std::cout << "Error.Enter natural number: ";
	}
}

void InputData(char* a, char* b) {
	std::cout << "Enter a first number:";
	Validate(a);
	std::cout << "Enter a second number:";
	Validate(b);
}

void Value(char* a, char* b) {
	std::cout << "Use random data (click 1) or input from the keyboard (click 2)?\n";
	int i = 0;
	for (;;) {
		switch (_getch()) {
		case '1': {
			GenData(a, b); 
			return;
		}
		case '2': {
			InputData(a, b);
			return;
		}
		}
		i++;
		if (i == 1) {
			std::cout << "\nError. Please click 1 or 2.\n";
		}
	}
}

void PrintNum(char* a, char* b, char* c) {
	std::cout << "First number - " << a << "\nSecond number - " << b << std::endl;
	std::cout << "First + Second = " << a << " + " << b <<" = "<< c << std::endl;
}

int SumCharToInt(char a ,char b) {
	int NumA = 0, NumB = 0;
	for (int i = 48; i <= 57; i++) {
		if (a == i)
			NumA = i - 48;
		if (b == i)
			NumB = i - 48;
	}
	return NumA + NumB;
}

char IntToChar(int a) {
	char Ch;
	for (int i = 0; i <= 10; i++)
		if (a == i)
			Ch = i + 48;
	return Ch;
}

void Add(char *a, char *b, char* c) {
	int aLen = strlen(a), bLen = strlen(b), cLen, Num;
	if (aLen < bLen)
		cLen = bLen + 2;
	else
		cLen = aLen + 2;
	bool Razrad= false;
	for (int i = 0; i <= cLen; i++) {
		Num = SumCharToInt(a[aLen - i], b[bLen - i]);
		if (Razrad) {
			Num++;
			Razrad = false;
		}
		c[i] = IntToChar(Num % 10);
		if (Num >= 10)
			Razrad = true;
	}
	c[cLen] = '\0';
	_strrev(c);
	c[cLen - 1] = '\0';
	if ((cLen - 1 > 2)||(cLen - 1 == 2 && c[0] != 49)) {
		c[0] = ' ';
	}
}

int main()
{
	srand((unsigned int)time(0));
	char First[BUF], Second[BUF], Third[BUF+1];
	Value(First, Second);
	Add(First, Second, Third);
	PrintNum(First, Second, Third);
	system("pause");
    return 0;
}


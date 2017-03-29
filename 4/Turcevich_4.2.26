#include "stdafx.h"
#include <iostream>
#include <string.h>

#define BUF 25

void InputPattern(char* a) {
	std::cout << "Enter a \"Pattern\" (<25 symbols) of the word, which you want to find in the dictionary (use symbol \"_\" for unknown letter): ";
	for (;;) {
		gets_s(a, BUF);
		int B = strlen(a);
		for (int i = 0, e = strlen(a); i < e; i++) {
			if (a[i] == 95 || (a[i] >= 65 && a[i] <= 90) || (a[i] >= 97 && a[i] <= 122))
				B--;
		}
		if (!B)
			return;
		else
			std::cout << "Error. Please use alphabet letter or this symbol \"_\" !:";
	}
}

bool CompareSymbols(char* a, char* b) {
	int LenA = strlen(a);
		for (int i = 0; i < LenA; i++) {
			while (b[i] == 95)
				i++;
			if (a[i] != b[i] && a[i] != b[i] + 32)
				return false;
		}
	return true;
}

int FileRead(FILE *a, char* b) {
	int i = 0;
	char Temp[BUF];
	while (fgets(Temp, BUF, a)) {
		Temp[strlen(Temp) - 1] = '\0';
		int LenA = strlen(Temp);
		int LenB = strlen(b);
		if (CompareSymbols(Temp, b) && LenA == LenB) {
			i++;
			std::cout << i << " word, which meet pattern: " << Temp << std::endl;
		}
	}
	return i;
}

int main()
{
	char Pattern[BUF];
	InputPattern(Pattern);
	std::cout << "Your word is " << Pattern << std::endl;
	FILE *file;
	file = fopen("Dictionary.txt", "r");
	if (!file) {
		std::cout << "File doesn't exist.";
		exit(1);
	}
	if (FileRead(file, Pattern) == 0)
		std::cout << "This word doesn't find in dictionary!\n";
	fclose(file);
	system("pause");
    return 0;
}

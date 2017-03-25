#include "stdafx.h"
#include <iostream>
#include <ctime>

int** CrArray(int b) {
	int **a = new int*[b];
	for (int i = 0; i < b; i++) {
		a[i] = new int[b];
	}
	return a;
}
void Init(int **a, int b) {
	srand(time(0));
	for (int i = 0; i < b; i++)
		for (int j = 0; j < b; j++)
			a[i][j] = rand() % 100;
}
void printA(int **a, int b, int c) {
	std::cout << "----------------------\n";
	if (b == c)
	std::cout << "Start Array:\n";
	else if (c - b == 1)
		std::cout << "New Array:\n";
	for (int i = 0; i < b; i++) {
		for (int j = 0; j < b; j++)
			std::cout << a[i][j] << '\t';
		std::cout << '\n';
	}
	std::cout << "----------------------\n";
}
#define BUF 15
int Input() {
	char a[BUF];
	for (;;) {
		gets_s(a, BUF);
		int b = strlen(a);
		for (int i = 0; i < BUF; i++) {
			if (a[i] <= 57 && a[i] >= 48) {
				b--;
			}
		}
		if (!atoi(a))
			printf("Error. Enter natural number.");
		else if (!b)
			return atoi(a);
		else
			printf("Error. Enter natural number.");
	}
};
void Dim(int *a) {
	std::cout << "Enter a dimension of array: ";
	*a = Input();
}
int* SearchMax(int** A, int a) {
	int Temp = 0, line, column;
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < a; j++) {
			if (A[i][j] > Temp) {
				Temp = A[i][j];
				line = i;
				column = j;
			}
		}
	}
	int* B = (int*)malloc(sizeof(int) * 3);
	B[0] = Temp;
	B[1] = line;
	B[2] = column;
	return B;
}
void NewArrayFirst(int **a, int *b, int *c) {
	for (int i = c[1]; i < *b - 1; i++)
		for (int j = 0; j < *b; j++)
			a[i][j] = a[i + 1][j];
	for (int i = c[2]; i < *b - 1; i++)
		for (int j = 0; j < *b; j++)
			a[j][i] = a[j][i + 1];
	b--;
}
void NewArraySecond(int** a, int b) {
	int temp;
	for (int i = 0, j = b - 1; i < b / 2; i++, j--)
		for (int k = 0; k < b; k++) {
			temp = a[i][k];
			a[i][k] = a[j][k];
			a[j][k] = temp;
		}
	for (int i = 0, j = b - 1; i < b / 2; i++, j--)
		for (int k = 0; k < b; k++) {
			temp = a[k][i];
			a[k][i] = a[k][j];
			a[k][j] = temp;
		}
}
int main()
{
	int Dimension, **Array = NULL, lol;
	Dim(&Dimension);
	lol = Dimension;
	Array = CrArray(Dimension);
	Init(Array, Dimension);
	printA(Array, Dimension, Dimension);
	int* MaxEl = SearchMax(Array, Dimension);
	printf("MaxEl = %d, Str - %d, Column - %d\n",MaxEl[0], MaxEl[1], MaxEl[2]);
	NewArrayFirst(Array, &Dimension, MaxEl);
	NewArraySecond(Array, --Dimension);
	printA(Array, Dimension, lol);
	Dimension++;
	for (int i = 0; i < Dimension; i++)
		delete Array[i];
	delete[] Array;
	system("pause");
    return 0;
}
#include "stdafx.h"
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define BUF 15
#define ITERATOR 1000

double Input() {
	char a[BUF];
	for (;;) {
		gets_s(a, BUF);
		int b = strlen(a);
		for (int i = 0; i < BUF; i++) {
			if ((a[i] <= 57 && a[i] >= 48) || a[i] == 46) {
				b--;
			}
		}
		if (!atof(a))
			printf("Error. Enter natural number.");
		else if (!b)
			return atof(a);
		else
			printf("Error. Enter natural number.");
	}
};

double FuncSin(double a) {
	return sin(a);
}

int factor(int a) {
	int Factorial = 1;
	int b = 2 * a - 1;
	for (int i = 2; i <= a; i++)
		Factorial *= i;
	return Factorial;
}

double FuncCicle(double a, double b, double c) {
	double REZULT = 0, e0;
	int L = 0;
	for (int i = 1; i < ITERATOR; i++) {
		REZULT = powl(-1, i - 1)*powl(a, 2 * i - 1) / factor(2 * i - 1);
		e0 = REZULT - c;
		if (e0 < 0)
			e0 = e0*(-1);
		if (e0 < b) {
			L = i;
			printf("Iteracii n = %d\n", L);
			break;
		}
	}
	if (L = 0)
		printf("Accuracy don't achieved.\n");
	return REZULT;
}

double FuncRekurs(double a) {

	return 0;
}

double calculate(long x, long n) {
	double result = 1;
	for (long i = 1; i <= 2 * n - 1; i++) {
		result *= ((double)x / (double)i);
	}
	return result;
}

double FuncRekurs(double *res, long *i, double *x, long *n) {
	if (*i == *n) {
		return *res + pow(-1, *i - 1)*calculate(*x, *i);
	}
	*res += pow(-1, *i - 1)*calculate(*x, *i);
	(*i)++;
	return FuncRekurs(res, i, x, n);
}

int main()
{
	double x, SIN_X, Cicle_Rez, Rekurs_Rez;
	double e;
	printf("Enter any number x: ");
	x = Input();
	SIN_X = FuncSin(x);
	printf("Enter accuracy e: ");
	e = Input();
	Cicle_Rez = FuncCicle(x, e, SIN_X);//cycle
	double res = 0;
	long i = 1;
	long n = 1;
	Rekurs_Rez = FuncRekurs(&res, &i, &x, &n);//rekursion
	printf("sinx = %lf\nMacLoren (iteration method) = %lf\nMacLoren (rekursion method) = %lf\n", SIN_X, Cicle_Rez, Rekurs_Rez);
	system("pause");
	return 0;
}

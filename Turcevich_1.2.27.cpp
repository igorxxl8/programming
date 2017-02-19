#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int BinTrans(int a) {//Перевод в двоичную систему счисления
	int bin=0, i;
	for (i=0; a > 0; i++) {
		bin += (int)((a % 2)*pow(10, i));
		a /= 2;
	}
	return bin;
};
int Quntity(int a) {//Подсчет количества единиц
	int q = 0,i = 0;
	for (i; a > 0; i++) {
		if (a % 10 == 1)
			q++;
		a /= 10;
	}
	return q;
};
int main()
{
	int a,b,i,bin,stack1=0,stack2,stack3,ed;
	printf("Enter a start of the interval:");
	scanf_s("%d", &a);
	printf("Enter a end of the interval:");
	scanf_s("%d", &b);
	for (i = a; i <= b; i++) {
		bin = BinTrans(i);
		ed = Quntity(bin);
		if (ed > stack1) {//Сравнение количества единиц.И запоминание числа в промежуточной переменной.
			stack1 = ed;
			stack2 = bin;
			stack3 = i;
		}
	}
	printf("A natural number from a given interval in the binary representation the most 1s - %d , this number in decimal system - %d\n", stack2, stack3);
	system("pause");
    return 0;
}


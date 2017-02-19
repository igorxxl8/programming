#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int EnterStart() {
	int a;
	printf("Enter a start of the interval:");
	do {
		scanf_s("%d", &a);
		if (a <= 0) {
			a = 0;
			printf("Please,enter a natural number:");
		}
	} while (a == 0);
	return a;
};
int EnterEnd(int a) {
	int b;
	printf("Enter a end of the interval:");
	do {
		scanf_s("%d", &b);
		if (b <= 0) {
			b = 0;
			printf("Please,enter a natural number:");
		}
		else if (b < a) {
			b = 0;
			printf("Please,enter a number greater than start of the inteval:");
		}
	} while (b == 0);
	return b;
};
int BinTrans(int a) {
	int bin=0, i;
	for (i=0; a > 0; i++) {
		bin += (int)((a % 2)*pow(10, i));
		a /= 2;
	}
	return bin;
};

int Quntity(int a) {
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
	a = EnterStart();
	b = EnterEnd(a);
	for (i = a; i <= b; i++) {
		bin = BinTrans(i);
		ed = Quntity(bin);
		if (ed > stack1) {
			stack1 = ed;
			stack2 = bin;
			stack3 = i;
		}
	}
	printf("A natural number from a given interval in the binary representation the most 1s - %d , this number in decimal system - %d\n", stack2, stack3);
	system("pause");
    return 0;
}


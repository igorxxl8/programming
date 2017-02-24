#include "stdafx.h"
#include <stdlib.h>
#include <math.h>
#include <string.h>

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
int EnterStart() {
	int a;
	printf("Enter a start of the interval:");
	a = Input();
	return a;
};
int EnterEnd(int a) {
	int b;
	printf("Enter a end of the interval:");
	for (;;) {
		b = Input();
		if (b >= a)
			return b;
		else
			printf("Error. The end of the interal is less than start.\nPlease, enter a number which bigger than start of interval.");
	}
};
int BinTrans(int a) {
	int bin=0, i;
	for (i= 0; a > 0; i++) {
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
	printf("A natural number from a given interval in the binary representation with the most 1s - %d , this number in decimal system - %d\n", stack2, stack3);
	system("pause");
    return 0;
}


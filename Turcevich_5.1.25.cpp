#include "stdafx.h"
#include <iostream>
#include <conio.h>

#define BUF 25

struct Stack
{
	char value;
	struct Stack *next;
};

void push(Stack* &NEXT, const char VALUE)
{
	Stack *MyStack = new Stack;
	MyStack->value = VALUE;
	MyStack->next = NEXT;
	NEXT = MyStack;
	std::cout << VALUE;
}

char pop(Stack* &NEXT)
{
	char temp = NEXT->value;
	Stack *MyStack = NEXT;
	NEXT = NEXT->next;
	delete MyStack;
	return temp;
}

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
			printf("Error. Enter natural number: ");
		else if (!b)
			return atoi(a);
		else
			printf("Error. Enter natural number: ");
	}
};

int main()
{
	Stack *FirstStack = 0;
	int N;
	std::cout << "How many cymbols in stack?: ";
	N = Input();
	std::cout << "First Stack: ";
	for (int i = 0; i < N; i++) {
		push(FirstStack, _getch());
	}
	std::cout << "\nInvertion Stack: ";
	Stack *SecondStack = 0;
	for (int i = 0; i < N; i++) {
		push(SecondStack, pop(FirstStack));
	}
	std::cout << '\n';
	system("pause");
	return 0;
} 

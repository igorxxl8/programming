#include "stdafx.h"
#include <iostream>

#define BUF 25

struct Tree { // the structure of the ternary tree
	int info;
	Tree* left;
	Tree* right;
	Tree* middle;
};

void AddNode(int data, Tree **node); // function which add item in the tree
int Depth(Tree *node, int depth_count); // function of counting the number of levels int the tree
int Input();// input validation function

int main()
{
	Tree *root = NULL;
	puts("How many elements do you want to put in the tree?");
	int NumInTree = Input(), TreeLevels = 0;
	puts("Enter these numbers: ");
	for (int i = 0; i < NumInTree; i++) {
		AddNode(Input(), &root);
	}
	TreeLevels = Depth(root, 0);
	std::cout << "There are " <<TreeLevels <<" levels in the tree!"<< std::endl;
	system("pause");
    return 0;
}
void AddNode(int data, Tree **node) {// function which add item in the tree
	if (*node == NULL) {
		*node = (Tree*)calloc(1, sizeof(Tree));
		(*node)->info = data;
		(*node)->left = (*node)->middle = (*node)->right = NULL;
	}
	else {
		if (data < (*node)->info)
			AddNode(data, &(*node)->left);
		else if (data > (*node)->info)
			AddNode(data, &(*node)->right);
		else if (data == (*node)->info)
			AddNode(data, &(*node)->middle);
		else
			puts("There is such element in the tree!");
	}
}
int Max(int a, int b, int c) {// function which serach maximum number
	if ((a > b) && ((a > c) || (a == c)))
		return a;
	else if ((b > a) && ((b > c) || (b == c)))
		return b;
	else if ((c > a) && (c > b))
		return c;
	else 
		return a;
}

int Depth(Tree *Ptr, int dep_count)// function of counting the number of levels int the tree
{
	if (Ptr == NULL)
		return dep_count;

	return Max(Depth(Ptr->left, dep_count + 1), Depth(Ptr->right, dep_count + 1), Depth(Ptr->middle, dep_count + 1));
}

int Input() {// input validation function
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
}

#pragma once
#include <string>
#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;

#define BUF 25

struct services {// struct of services
	int NumberServ;
	string NameServ;
	int Price;
	bool Obligatory;
	services *next;
} ;

struct turProgram {// turist programm set of services
	int Number;
	int TourPrice;
	int ServCount;
	string ProgramName;
	services* Service = NULL;
	string Path;
	string Date;
	int EmptySpace;
	turProgram *next;
};

void ExMenu();
int Input();// func of input validation
int AddService(services** Head, int i);
int OformProgram(turProgram** Begin);
int AvaibleProgram(turProgram* Begin);
int ChooseService(services* Head, int *Money, int Pass, bool X);
void ChooseProgram(turProgram** Begin, bool X, int *Money);
void AddServiceInProgram(turProgram** Begin);
int CheckNum(turProgram* Begin);
void AddProgram(turProgram** Begin);

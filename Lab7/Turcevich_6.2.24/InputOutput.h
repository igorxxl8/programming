#pragma once

#include <string>
#include <fstream>
#include "Structs.h"

using namespace std;

void ClearFile();
void FileInit(ifstream &FileIn, turProgram** Begin);
void FileOutput(ofstream &File, turProgram* A);
void InitService(services** Head, char* Str1, char* Str2, char* Str3, char* Str4);
void InitProgram(turProgram** Begin, char* Str);
void FileUpd(ofstream &FileOut, turProgram* Begin);
void ShowService(services* Head);
void ShowProgram(turProgram* Begin);
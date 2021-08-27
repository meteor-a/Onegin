#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <Windows.h>
#include <locale.h>

const int CODE_ERROR = -1;
const int OK_RESULT = 1;
const int BuffSize = 200;
const int SizeText = 9000;
char const* const Path = "text_on.txt";

int OutputSortStrings(wchar_t**, int);
int InputText(wchar_t**, int*);
int DeleteExtraSymb(int);
int SortStrings(wchar_t**, int);


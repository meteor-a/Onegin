#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <Windows.h>
#include <locale.h>

const int CODE_ERROR = -1;
const int OK_RESULT = 1;
const int BuffSize = 250;
const int SizeText = 10000;
char const* const Path = "text_on.txt";

int OutputSortStrings(wchar_t**, int);
int InputText(wchar_t**, int*);
int SortStrings(wchar_t**, int);

int Partition(wchar_t**, int, int);
int RandomPivotPartition(wchar_t**, int, int);
int QuickSort(wchar_t**, int, int);


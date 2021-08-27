#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <assert.h>
#include <Windows.h>
#include <locale.h>

const int CODE_ERROR = -1;
const int OK_RESULT = 1;
const int BUFFER_SIZE = 3000;
const int FILE_SIZE = 10000;
char const* const PATH_FILE_TEXT = "text_on.txt";

int OutputSortStrings(wchar_t**, int);
int InputText(wchar_t**, int*);
int SortStrings(wchar_t**, int);

int Partition(wchar_t**, int, int);
int RandomPivotPartition(wchar_t**, int, int);
int QuickSort(wchar_t**, int, int);


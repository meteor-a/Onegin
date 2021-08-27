#pragma once
#include < stdio.h >  //Äëÿ printf, fgets, fopen, fclose, feof
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <assert.h>
#include <locale.h>

const int BUFFER_SIZE = 1500;
const int OK_RESULT = 1;
const int CODE_ERROR = -9;

void swap_str(wchar_t**, wchar_t**);

int OutputSortStrings(wchar_t**, int);
int SortStrings(wchar_t**, int);
wchar_t** InputStrings(wchar_t**, int*);
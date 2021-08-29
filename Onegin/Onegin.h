#pragma once
#include < stdio.h >  //Äëÿ printf, fgets, fopen, fclose, feof
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <Windows.h>
#include <assert.h>
#include <locale.h>
#include <algorithm>

const int BUFFER_SIZE = 1500;
const int OK_RESULT = 1;
const int CODE_ERROR = -9;
const char PATH_FILE[] = { "text_on.txt" };

struct StringStruct {
    wchar_t str[BUFFER_SIZE];
};

void swap_str(wchar_t**, wchar_t**);

int OutputSortStrings(wchar_t**, int);
int SortStrings(wchar_t**, int);
wchar_t** InputStrings(wchar_t**, int*);

int getFileSize(FILE*);



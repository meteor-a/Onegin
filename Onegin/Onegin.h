#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <wchar.h> 
#include <malloc.h>
#include <Windows.h>
#include <assert.h>
#include <locale.h>

const int OK_RESULT = 1;
const int CODE_ERROR = -9;

const char PATH_FILE_ONEGIN[] = { "text_on.txt" };
const char PATH_FILE_OUTPUT[] = { "output.txt" };

int RandGenStr();

wchar_t** InputText(long long*, int*);
void OutputConsole(wchar_t**, long long);
void OutputFile(wchar_t**, long long);

int getFileSize(FILE*);
FILE* OpenFile(const char*, const char*);
int CloseFile(FILE*);

int comparator(const void*, const void*);


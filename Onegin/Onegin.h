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
const char PATH_FILE_OUTPUT_ALPHABET[] = { "output.txt" };
const char PATH_FILE_OUTPUT_BACK_ALPHABET[] = { "output_back.txt" };


int RandGenStr();

wchar_t** InputText(long long*, int*);
void OutputConsole(wchar_t**, long long);
void OutputFile(wchar_t**, long long, const char*);

int getFileSize(FILE*);
FILE* OpenFile(const char*, const char*);
int CloseFile(FILE*);

int comparator_alphabet(const void*, const void*);
int comparator_back_alphabet(const void*, const void*);


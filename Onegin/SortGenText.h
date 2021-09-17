#pragma once
#include <locale.h>
#include <Windows.h>
#include "QSort.h"
#include "StringStruct.h"
#include "TextStruct.h"
#include "FileWork.h"
#include "Constants.h"


int SortGenText(const char* file_name);
int GetMemoryForTextBuf(TextStruct* text_analyze, FILE* file);
int InputText(TextStruct* text_file, FILE* open_file);

int Output(TextStruct* text_file);
int OutputFile(TextStruct* text_file, FILE* file_output);
int OutputSeparatorFile(const wchar_t* symb_separator, int num_separator, FILE*  file_output);
int OutputOriginText(TextStruct* text_file, FILE* file_output);

void SetOutputSettings();
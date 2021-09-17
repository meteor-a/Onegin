#pragma once
#include <locale.h>
#include <Windows.h>
#include "QSort.h"
#include "StringStruct.h"
#include "TextStruct.h"
#include "FileWork.h"
#include "Constants.h"


int SortGenText();
int GetMemoryForTextBuf(TextStruct* text_analyze, FILE* file);
int InputText(TextStruct* text_file, FILE* open_file);

int Output(TextStruct* text_file);
int OutputFile(TextStruct* text_file, const char* file_name, const char* type_open);
int OutputSeparatorFile(int num_separator, const char* file_name, const char* type_open);
int OutputOriginText(TextStruct* text_file, const char* file_name, const char* type_open);

void SetOutputSettings();
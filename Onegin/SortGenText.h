#pragma once
#include <locale.h>
#include <Windows.h>
#include "StringStruct.h"
#include "TextStruct.h"
#include "FileWork.h"
#include "Constants.h"
#include "QSort.h"

int SortGenText();
int InputText(TextStruct*, FILE* open_file);

int comparator_start_str(const void*, const void*);
// int comparator_back_str(const void*, const void*);

int Output(TextStruct*);
void OutputConsole(TextStruct*);
int OutputFile(TextStruct*, const char*);

void SetOutputSettings();
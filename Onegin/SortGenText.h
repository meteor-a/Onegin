#pragma once
#include <locale.h>
#include <Windows.h>
#include "QSort.h"
#include "StringStruct.h"
#include "TextStruct.h"
#include "FileWork.h"
#include "Constants.h"


int SortGenText();
int InputText(TextStruct*, FILE* open_file);

int Output(TextStruct*);
void OutputConsole(TextStruct*);
int OutputFile(TextStruct*, const char*, const char*);
int OutputSeparatorFile(int, const char*, const char*);
int OutputOriginText(TextStruct*, const char*, const char*);

void SetOutputSettings();
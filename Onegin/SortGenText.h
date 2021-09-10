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

int Output(TextStruct*);
void OutputConsole(TextStruct*);
int OutputFile(TextStruct*, const char*);

void SetOutputSettings();
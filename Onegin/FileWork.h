#pragma once
#include <stdio.h>
#include <assert.h>
#include "Constants.h"

int getFileSize(FILE* file);
FILE* OpenFile(const char* name_file, const char* type);
int CloseFile(FILE* file);
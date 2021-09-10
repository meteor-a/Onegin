#pragma once
#include <stdio.h>
#include <assert.h>
#include "Constants.h"

int getFileSize(FILE*);
FILE* OpenFile(const char*, const char*);
int CloseFile(FILE*);
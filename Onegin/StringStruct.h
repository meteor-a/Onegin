#pragma once
#include <wchar.h> 
#include <assert.h>
#include <ctype.h>
#include "Constants.h"

struct StringStruct {
    wchar_t* str = nullptr;
    size_t length = 0;
};

int swap_str(StringStruct* left, StringStruct* right);
int wcscmp_miss_punct(const StringStruct* left, const StringStruct* right);
int rev_wcscmp_miss_punct(const StringStruct* left, const StringStruct* right);
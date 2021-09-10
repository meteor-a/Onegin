#pragma once
#include <wchar.h> 
#include <assert.h>
#include <ctype.h>
#include "Constants.h"

struct StringStruct {
    wchar_t* str = nullptr;
    size_t length = 0;
};

int swap_str(StringStruct*, StringStruct*);
int wcscmp_miss_punct(const StringStruct*, const StringStruct*);
int rev_wcscmp_miss_punct(const StringStruct*, const StringStruct*);
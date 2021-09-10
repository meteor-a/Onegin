#pragma once
#include <wchar.h> 
#include "Constants.h"

struct StringStruct {
    wchar_t* str = nullptr;
    long long length = 0;
};

int swap_str(StringStruct*, StringStruct*);
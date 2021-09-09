#pragma once
#include <wchar.h> 

struct StringStruct {
    wchar_t* str = nullptr;
    size_t length = 0;
};
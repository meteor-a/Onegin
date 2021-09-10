#include "StringStruct.h"

int swap_str(StringStruct* left, StringStruct* right) {
    wchar_t* tmp = (*left).str;
    (*left).str = (*right).str;
    (*right).str = tmp;
    size_t tmp_length = (*left).length;
    (*left).length = (*right).length;
    (*right).length = tmp_length;

    return OK_RESULT;
}
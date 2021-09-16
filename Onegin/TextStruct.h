#pragma once
#include <stdlib.h>
#include <io.h>
#include "Constants.h"
#include "StringStruct.h"

struct TextStruct {
    StringStruct text;
    StringStruct* string_text = nullptr;
    size_t num_strings = 1;
};


int SeparateText(TextStruct*);
int DestructorText(TextStruct*);
void ConstructorText(TextStruct*);
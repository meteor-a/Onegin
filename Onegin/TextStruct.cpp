#include "TextStruct.h"

int DestructorText(TextStruct* text) {
    assert(text != nullptr);
    if (text == nullptr) {
        return CODE_ERROR;
    }

    free((*text).string_text);
    free((*text).text.str);

    return OK_RESULT;
}

int SeparateText(TextStruct* text) {
    assert(text != nullptr);
    if (text == nullptr) {
        return CODE_ERROR;
    }

    size_t cur_size_str = (*text).text.length;

    (*text).string_text = (StringStruct*)calloc(cur_size_str, sizeof(StringStruct));
    assert((*text).string_text != nullptr);
    if ((*text).string_text == nullptr) {
        return CODE_ERROR;
    }

    size_t n_line = 0;
    size_t cur_num_symb = 0;
    for (size_t num_symb = 0; num_symb < cur_size_str; ++num_symb) {
        if ((*text).text.str[num_symb] == L'\0' || (*text).text.str[num_symb] == 65535) {
            (*text).string_text[n_line].str = ((*text).text.str + num_symb - cur_num_symb);
            (*text).string_text[n_line].length = cur_num_symb;
            ++n_line;
            cur_num_symb = 0;
        }
        else {
            ++cur_num_symb;
        }
    }
    ((*text).num_strings) = n_line;

    return OK_RESULT;
}
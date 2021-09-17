#include "SortGenText.h"

int SortGenText(const char* file_name) {
    SetOutputSettings();

    FILE* file_text = OpenFile(file_name, "r");
    assert(file_text != nullptr);
    if (file_text == nullptr) {
        return CODE_ERROR;
    }

    TextStruct text_analyze{};

    ConstructorText(&text_analyze);
    GetMemoryForTextBuf(&text_analyze, file_text);

    int res_input = InputText(&text_analyze, file_text);
    SeparateText(&text_analyze);

    Output(&text_analyze);

    DestructorText(&text_analyze);

    return OK_RESULT;
}

int GetMemoryForTextBuf(TextStruct* text_analyze, FILE* file) {
    text_analyze->text.str = (wchar_t*)calloc(getFileSize(file) + 1, sizeof(wchar_t));
    assert(text_analyze->text.str != nullptr);
    if (text_analyze->text.str == nullptr) {
        return CODE_ERROR;
    }

    return OK_RESULT;
}

int InputText(TextStruct* text_file, FILE* open_file) {
    assert(text_file != nullptr);
    assert(open_file != nullptr);
    if (text_file == nullptr || open_file == nullptr) {
        return CODE_ERROR;
    }

    wchar_t ch = 0;
    size_t count_symb = 0;
    size_t count_lines = 0;
    bool is_empty_str = true;
    while (!feof(open_file)) {
        ch = fgetwc(open_file);
        if (iswspace(ch)) {
            if (ch == '\n' && !is_empty_str) {
                text_file->text.str[count_symb] = L'\0';
                ++count_symb;
                ++count_lines;
                is_empty_str = true;
            }
            if (!is_empty_str) {
                text_file->text.str[count_symb] = ch;
                ++count_symb;
            }
        }
        else {
            text_file->text.str[count_symb] = ch;
            ++count_symb;
            is_empty_str = false;
        }
    }
    text_file->text.str[count_symb] = L'\0';
    ++count_symb;

    text_file->text.length = count_symb;
    text_file->num_strings = count_lines;

    return OK_RESULT;
}

int Output(TextStruct* text_file) {
    //qsort(text_file->string_text, text_file->num_strings, sizeof(StringStruct), comparator_wcscmp);
    quickSortR(text_file->string_text, 0, text_file->num_strings - 1, comparator_wcscmp);
    OutputFile(text_file, PATH_FILE_OUTPUT, "w");

    OutputSeparatorFile(200, PATH_FILE_OUTPUT, "a");

    qsort(text_file->string_text, text_file->num_strings, sizeof(StringStruct), comparator_rev_wcscmp);
    //quickSortR(text_file->string_text, 0, text_file->num_strings - 1, comparator_rev_wcscmp);
    OutputFile(text_file, PATH_FILE_OUTPUT, "a");

    OutputSeparatorFile(200, PATH_FILE_OUTPUT, "a");

    OutputOriginText(text_file, PATH_FILE_OUTPUT, "a");
    
    return OK_RESULT;
}

int OutputOriginText(TextStruct* text_file, const char* file_name, const char* type_open) {
    assert(text_file != nullptr);
    if (text_file == nullptr) {
        return CODE_ERROR;
    }

    FILE* file = nullptr;
    file = OpenFile(file_name, type_open);
    assert(file != nullptr);
    if (file == nullptr) {
        return CODE_ERROR;
    }

    size_t nLines = text_file->text.length;
    for (size_t num_symb = 0; num_symb < nLines; ++num_symb) {
        if (text_file->text.str[num_symb] == '\0') {
            putwc(L'\n', file);
        }
        else {
            putwc(text_file->text.str[num_symb], file);
        }
    }

    CloseFile(file);

    return OK_RESULT;
}

int OutputSeparatorFile(int num_separator, const char* file_name, const char* type_open) {
    FILE* file = nullptr;
    file = OpenFile(file_name, type_open);
    assert(file != nullptr);
    if (file == nullptr) {
        return CODE_ERROR;
    }

    fputws(L"\n", file);
    for (int nSep = 0; nSep < num_separator; ++nSep) {
        fputws(L"-", file);
    }
    fputws(L"\n", file);

    CloseFile(file);

    return OK_RESULT;
}

int OutputFile(TextStruct* text_file, const char* file_name, const char* type_open) {
    assert(text_file != nullptr);
    if (text_file == nullptr) {
        return CODE_ERROR;
    }

    FILE* file = OpenFile(file_name, type_open);
    assert(file != nullptr);
    if (file == nullptr) {
        return CODE_ERROR;
    }

    long long nLines = text_file->num_strings;
    for (int num_str = 0; num_str < nLines; ++num_str) {
        fputws(text_file->string_text[num_str].str, file);
        fputws(L"\n\0", file);
    }

    CloseFile(file);

    return OK_RESULT;
}

void SetOutputSettings() {
    _wsetlocale(LC_ALL, L"Rus");

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
}

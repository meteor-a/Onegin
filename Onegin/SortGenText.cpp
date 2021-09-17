#include "SortGenText.h"

/**
    * Function for read, sort and out[ut text from file
    * \return 0- if no error
    * \return -9- if error
*/
int SortGenText(const char* file_name/*!< - File name*/) {
    TextStruct text_analyze{};

    ConstructorText(&text_analyze);

    FILE* file_text = OpenFile(file_name, "r");
    assert(file_text != nullptr);
    if (file_text == nullptr) {
        return CODE_ERROR;
    }

    GetMemoryForTextBuf(&text_analyze, file_text);

    int res_input = InputText(&text_analyze, file_text);
    CloseFile(file_text);
    SeparateText(&text_analyze);

    Output(&text_analyze);

    DestructorText(&text_analyze);

    return OK_RESULT;
}

/**
    * Function for calloc memory for buffer
    * \return 0- if no error
    * \return -9- if error
*/
int GetMemoryForTextBuf(TextStruct* text_analyze, FILE* file) {
    text_analyze->text.str = (wchar_t*)calloc(getFileSize(file) + 1, sizeof(wchar_t));
    assert(text_analyze->text.str != nullptr);
    if (text_analyze->text.str == nullptr) {
        return CODE_ERROR;
    }

    return OK_RESULT;
}

/**
    * Function for read text from file
    * \return 0- if no error
    * \return -9- if error
*/
int InputText(TextStruct* text_file, FILE* open_file) {
    assert(text_file != nullptr);
    assert(open_file != nullptr);
    if (text_file == nullptr || open_file == nullptr) {
        return CODE_ERROR;
    }

    wchar_t ch = 0;
    size_t count_symb  = 0;
    size_t count_lines = 0;
    bool is_empty_str  = true;

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

/**
    * Function for sort and output string in some order in output.txt
    * \return 0- if no error
    * \return -9- if error
*/
int Output(TextStruct* text_file) {
    FILE* file_output = OpenFile("output.txt", "w");
    assert(file_output != nullptr);
    if (file_output == nullptr) {
        return CODE_ERROR;
    }

    quickSortR(text_file->string_text, 0, text_file->num_strings - 1, comparator_wcscmp);
    OutputFile(text_file, file_output);

    const wchar_t* symb_separ = L"-";
    OutputSeparatorFile(symb_separ, 200, file_output);

    qsort(text_file->string_text, text_file->num_strings, sizeof(StringStruct), comparator_rev_wcscmp);
    OutputFile(text_file, file_output);

    OutputSeparatorFile(symb_separ, 200, file_output);

    OutputOriginText(text_file, file_output);

    CloseFile(file_output);
    
    return OK_RESULT;
}

/**
    * Function for output original text in output.txt
    * \return 0- if no error
    * \return -9- if error
*/
int OutputOriginText(TextStruct* text_file, FILE* file_output) {
    assert(text_file != nullptr);
    if (text_file == nullptr) {
        return CODE_ERROR;
    }

    size_t nLines = text_file->text.length;
    for (size_t num_symb = 0; num_symb < nLines; ++num_symb) {
        if (text_file->text.str[num_symb] == '\0') {
            putwc(L'\n', file_output);
        }
        else {
            putwc(text_file->text.str[num_symb], file_output);
        }
    }

    return OK_RESULT;
}

/**
    * Function for output separator beetween two texts in output.txt
    * \return 0- if no error
    * \return -9- if error
*/
int OutputSeparatorFile(const wchar_t* symb_separ, int num_separator, FILE* file_output) {
    assert(file_output != nullptr);
    if (file_output == nullptr) {
        return CODE_ERROR;
    }

    fputws(L"\n", file_output);
    for (int nSep = 0; nSep < num_separator; ++nSep) {
        fputws(symb_separ, file_output);
    }
    fputws(L"\n", file_output);

    return OK_RESULT;
}

/**
    * Function for output sorted text in output.txt
    * \return 0- if no error
    * \return -9- if error
*/
int OutputFile(TextStruct* text_file, FILE* file_output) {
    assert(text_file != nullptr);
    if (text_file == nullptr) {
        return CODE_ERROR;
    }

    assert(file_output != nullptr);
    if (file_output == nullptr) {
        return CODE_ERROR;
    }

    long long nLines = text_file->num_strings;
    for (int num_str = 0; num_str < nLines; ++num_str) {
        fputws(text_file->string_text[num_str].str, file_output);
        fputws(L"\n\0", file_output);
    }

    return OK_RESULT;
}

/**
    * Function for set default configs of output unicode
*/
void SetOutputSettings() {
    _wsetlocale(LC_ALL, L"Rus");

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
}

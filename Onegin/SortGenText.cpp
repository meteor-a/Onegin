#include "SortGenText.h"

int SortGenText() {
    SetOutputSettings();

    FILE* file_text = OpenFile(PATH_FILE_ONEGIN, "r");
    if (file_text == nullptr) {
        return CODE_ERROR;
    }

    TextStruct text_analyze;
    text_analyze.text.str = (wchar_t*)calloc(getFileSize(file_text), sizeof(wchar_t));
    if (text_analyze.text.str == nullptr) {
        return CODE_ERROR;
    }

    int res_input = InputText(&text_analyze, file_text);
    SeparateText(&text_analyze);

    QuickSort(text_analyze.string_text, 0, text_analyze.num_strings - 1);
    qsort(text_analyze.string_text, text_analyze.num_strings, sizeof(StringStruct), comparator_start_str);

    Output(&text_analyze);

    DestructorText(&text_analyze);

    return OK_RESULT;
}

int InputText(TextStruct* text_file, FILE* open_file) {
    if (text_file == nullptr || open_file == nullptr) {
        return CODE_ERROR;
    }

    wchar_t ch = 0;
    long long count_symb = 0;
    bool is_empty_str = true;
    while (!feof(open_file)) {
        ch = fgetwc(open_file);
        if (iswspace(ch)) {
            if (ch == '\n' && !is_empty_str) {
                (*text_file).text.str[count_symb] = L'\0';
                ++count_symb;
                is_empty_str = true;
            }
            if (!is_empty_str) {
                (*text_file).text.str[count_symb] = ch;
                ++count_symb;
            }
        }
        else {
            (*text_file).text.str[count_symb] = ch;
            ++count_symb;
            is_empty_str = false;
        }
    }
    (*text_file).text.length = count_symb;

    return OK_RESULT;
}

int Output(TextStruct* text_file) {
    OutputConsole(text_file);
    int res = OutputFile(text_file, PATH_FILE_OUTPUT);
    
    return res;
}

void OutputConsole(TextStruct* text_file) {
    long long nLines = (*text_file).num_strings;
    for (int num_str = 0; num_str < nLines; ++num_str) {
        wprintf(L"%s \n", (*text_file).string_text[num_str].str);
    }
}

int OutputFile(TextStruct* text_file, const char* file_name) {
    FILE* file = nullptr;
    file = OpenFile(file_name, "w");
    if (file == nullptr) {
        return CODE_ERROR;
    }

    long long nLines = (*text_file).num_strings;
    for (int num_str = 0; num_str < nLines; ++num_str) {
        fputws((*text_file).string_text[num_str].str, file);
        fputws(L"\n\0", file);
    }

    CloseFile(file);

    return OK_RESULT;
}

void SetOutputSettings() {
    setlocale(LC_ALL, "Rus");

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
}
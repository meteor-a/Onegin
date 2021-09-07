#include "Onegin.h"

int RandGenStr() {
    setlocale(LC_CTYPE, "rus");

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    long long nLines = 1;
    int err = 0;
    wchar_t** text = InputText(&nLines, &err);
    if (err == CODE_ERROR) {
        return CODE_ERROR;
    }

    if (text == nullptr) {
        return CODE_ERROR;
    }

    qsort(text, nLines, sizeof(wchar_t*), comparator);

    OutputConsole(text, nLines);
    OutputFile(text, nLines);

    free(text);

    return OK_RESULT;
}

int comparator(const void* left, const void* right) {
    const wchar_t* first_str = *(const wchar_t**)left;
    const wchar_t* second_str = *(const wchar_t**)right;

    return wcscmp(first_str, second_str);
}

int getFileSize(FILE* file) {
    if (file == nullptr) {
        printf("Cant open file text!");
        return CODE_ERROR;
    }

    fseek(file, 0L, SEEK_END);
    int sz = ftell(file);
    rewind(file);
    return sz;
}

wchar_t** InputText(long long* nLines, int* err) {
    FILE* file_text = OpenFile(PATH_FILE_ONEGIN, "r");
    if (file_text == nullptr) {
        *err = CODE_ERROR;
        return nullptr;
    }

    wchar_t* text_str = nullptr;
    text_str = (wchar_t*)calloc(getFileSize(file_text), sizeof(wchar_t));
    if (text_str == nullptr) {
        *err = CODE_ERROR;
        return nullptr;
    }

    long long count_symb = 0;
    wchar_t ch = 0;
    text_str[count_symb] = L'\0';
    ++count_symb;
    bool is_empty_str = true;
    while (!feof(file_text)) {
        ch = fgetwc(file_text);
        if (iswspace(ch)) {
            if (ch == '\n' && !is_empty_str) {
                ++(*nLines);
                text_str[count_symb] = L'\0';
                ++count_symb;
                is_empty_str = true;
            }
            if (!is_empty_str) {
                text_str[count_symb] = ch;
                ++count_symb;
            }
        }
        else {
            text_str[count_symb] = ch;
            ++count_symb;
            is_empty_str = false;
        }
    }

    if (CloseFile(file_text) == CODE_ERROR) {
        *err = CODE_ERROR;
        return nullptr;
    }

    wchar_t** ind = nullptr;
    ind = (wchar_t**)calloc(*nLines, sizeof(wchar_t*));
    if (ind == nullptr) {
        *err = CODE_ERROR;
        return nullptr;
    }

    long long n_line = 0;
    for (int num_symb = 0; num_symb < count_symb; ++num_symb) {
        if (*(text_str + num_symb) == L'\0') {
            *(ind + n_line) = (text_str + num_symb + 1);
            ++n_line;
        }
    }

    return ind;
}

void OutputConsole(wchar_t** text, long long nLines) {
    for (int num_str = 0; num_str < nLines; ++num_str) {
        wprintf(L"%s \n", text[num_str]);
    }
}

void OutputFile(wchar_t** text, long long nLines) {
    FILE* file = nullptr;
    file = OpenFile(PATH_FILE_OUTPUT, "w");
    assert(file != nullptr);

    for (int num_str = 0; num_str < nLines; ++num_str) {
        fputws(text[num_str], file);
        fputws(L"\n\0", file);
    }

    CloseFile(file);
}

FILE* OpenFile(const char* name_file, const char* type) {
    FILE* file = nullptr;
    file = fopen(name_file, type);
    if (file == nullptr) {
        printf("error, while opening file\n");
    }
    else {
        printf("File open successfull\n");
    }

    return file;
}

int CloseFile(FILE* file) {
    if (fclose(file) == 0) {
        return OK_RESULT;
    }
    else {
        return CODE_ERROR;
    }
}
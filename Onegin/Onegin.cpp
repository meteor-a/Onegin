#include "Onegin.h"

int main() {
    StringStruct* text_new_str = nullptr;

    wchar_t** text_str = nullptr;
    int nLines = 0;

    text_str = InputStrings(text_str, &nLines);

    SortStrings(text_str, nLines);

   // qsort(text_str, nLines, sizeof(char*), cmp);

    OutputSortStrings(text_str, nLines);

    free(text_str);

    return OK_RESULT;
}

//int cmp(const void* left, const void* right) {
//    const char* leftStr = *(const char**)left;
//}

void swap_str(wchar_t** first, wchar_t** second) {
    assert(first != nullptr);
    assert(second != nullptr);

    wchar_t* tmp = nullptr;
    tmp = *first;
    *first = *second;
    *second = tmp;
}

int OutputSortStrings(wchar_t** text_str, int nLines) {
    assert(text_str != nullptr);

    setlocale(LC_CTYPE, "rus");

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    printf("Sort by code symbol:\n");
    for (int str_num = 0; str_num < nLines; ++str_num) {
        wprintf(L"%i: %s\n", str_num + 1, *(text_str + str_num));
        free(*(text_str + str_num));
    }

    return OK_RESULT;
}

int SortStrings(wchar_t** text_str, int nLines) {
    assert(text_str != nullptr);

    for (int ii = 0; ii < nLines; ++ii) {
        for (int jj = ii + 1; jj < nLines; ++jj) {
            if (wcscmp(*(text_str + ii), *(text_str + jj)) > 0) {
                swap_str((text_str + ii), (text_str + jj));
            }
        }
    }
    
    return OK_RESULT;
}


wchar_t** InputStrings(wchar_t** text_str, int* nLines) {
    assert(nLines != nullptr);

    FILE* file_text = nullptr;
    file_text = fopen(PATH_FILE, "r");
    if (file_text == nullptr) {
        printf("error, while opening file\n");
        return nullptr;
    } else {
        printf("File open successfull\n");
    }

    text_str = (wchar_t**)calloc(getFileSize(file_text), sizeof(wchar_t));

    assert(text_str != nullptr);

    char str[BUFFER_SIZE] = {};
    wchar_t* res;

    while (!feof(file_text)) {
        res = (wchar_t*)calloc(BUFFER_SIZE, sizeof(wchar_t));
        assert(res != nullptr);

        fgets(str, BUFFER_SIZE, file_text);
        ::MultiByteToWideChar(CP_UTF8, 0, str, BUFFER_SIZE, res, BUFFER_SIZE);

        for (int symb_num = 0; symb_num < wcslen(res); ++symb_num) {
            if (iswspace(*(res + symb_num))) {
                for (int change_symb = symb_num; change_symb < wcslen(res) - 1;
                    ++change_symb) {

                    *(res + change_symb) = *(res + change_symb + 1);
                }
                *(res + wcslen(res) - 1) = '\0';

                --symb_num;
            }
            else {
                break;
            }
        }

        for (int symb_num = wcslen(res) - 1; symb_num >= 0; --symb_num) {
            if (iswspace(*(res + symb_num))) {
                *(res + wcslen(res) - 1) = '\000';

                ++symb_num;
            } else {
                break;
            }
        }

        if (wcslen(res) != 0) {
            *(text_str + *nLines) = (wchar_t*)malloc(sizeof(res));

            if (*(text_str + *nLines) == nullptr) {
                return nullptr;
            }

            *(text_str + *nLines) = res;
            ++(*nLines);
        }
    }

    fclose(file_text);

    return text_str;
}

int getFileSize(FILE* file){
    assert(file != nullptr);

    fseek(file, 0L, SEEK_END);
    int sz = ftell(file);
    rewind(file);
    return sz;
}


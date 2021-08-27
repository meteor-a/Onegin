#include "Onegin.h"

int main() {
    wchar_t** text_str = nullptr;
    int nLines = 0;

    text_str = InputStrings(text_str, &nLines);

    SortStrings(text_str, nLines);

    OutputSortStrings(text_str, nLines);

    return OK_RESULT;
}

void swap_str(wchar_t** first, wchar_t** second) {
    wchar_t* tmp = nullptr;
    tmp = *first;
    *first = *second;
    *second = tmp;
}

int OutputSortStrings(wchar_t** text_str, int nLines) {
    setlocale(LC_CTYPE, "rus");

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    printf("Sort by code symbol:\n");
    for (int ii = 0; ii < nLines; ++ii) {
        wprintf(L"%i: %s\n", ii + 1, *(text_str + ii));
    }

    return OK_RESULT;
}

int SortStrings(wchar_t** text_str, int nLines) {
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
    FILE* file_text;
    file_text = fopen("text_on.txt", "r");
    if (file_text == NULL) {
        printf("error, while opening file\n");
        return nullptr;
    }
    else {
        printf("complete\n");
    }

    fseek(file_text, 0L, SEEK_END);
    int sz = ftell(file_text);
    rewind(file_text);
    text_str = (wchar_t**)calloc(sz, sizeof(wchar_t));

    char str[BUFFER_SIZE] = {};
    wchar_t* res;

    while (!feof(file_text)) {
        res = (wchar_t*)calloc(BUFFER_SIZE, sizeof(wchar_t));

        fgets(str, BUFFER_SIZE, file_text);
        ::MultiByteToWideChar(CP_UTF8, 0, str, BUFFER_SIZE, res, BUFFER_SIZE);

        for (int ii = 0; ii < wcslen(res); ++ii) {
            if (*(res + ii) == '\n' || *(res + ii) == '\r' || *(res + ii) == '\t' ||
                *(res + ii) == 160 || *(res + ii) == ' ') {

                for (int jj = ii; jj < wcslen(res) - 1; ++jj) {
                    *(res + jj) = *(res + jj + 1);
                }
                *(res + wcslen(res) - 1) = '\000';

                --ii;
            }
        }

        if (wcslen(res) != 0) {
            *(text_str + *nLines) = (wchar_t*)malloc(sizeof(res));
            *(text_str + *nLines) = res;
            ++(*nLines);
        }
    }

    fclose(file_text);

    return text_str;
}

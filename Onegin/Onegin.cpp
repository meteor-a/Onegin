#include "Onegin.h"

void swap_str(wchar_t** first, wchar_t** second) {
    wchar_t* tmp = nullptr;
    tmp = *first;
    *first = *second;
    *second = tmp;
}

int main() {
    setlocale(LC_CTYPE, "rus");

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    wchar_t** text_str;
    int nLines = 0;

    FILE* file_text;
    file_text = fopen("text_on.txt", "r");

    // Проверка открытия файла
    if (file_text == NULL) {
        printf("error\n");
        return -1;
    } else {
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
            *text_str = (wchar_t*)malloc(sizeof(res));
            *(text_str + nLines) = res;
            ++nLines;
        }
    }

    fclose(file_text);

    for (int ii = 0; ii < nLines; ++ii) {
        for (int jj = ii + 1; jj < nLines; ++jj) {
            if (wcscmp(*(text_str + ii), *(text_str + jj)) > 0) {
                swap_str((text_str + ii), (text_str + jj));
            }
        }
    }

    printf("Sort by code symbol:\n");
    for (int ii = 0; ii < nLines; ++ii) {
        wprintf(L"%i: %s\n", ii + 1, *(text_str + ii));
    }

    return 1;
}
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <Windows.h>
#include <locale.h>

const int CODE_ERROR = -1;
const int BuffSize = 9000;
char const* const Path = "text_on.txt";


int main() {
    setlocale(LC_CTYPE, "rus"); // вызов функции настройки локали

    SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода

    FILE* file_text = nullptr;
    file_text = fopen(Path, "rt");
    if (!file_text) {
        printf("Error open text file\n");
        return CODE_ERROR;
    }

    wchar_t* rr[BuffSize];
    int nLines = 0;

    char str[BuffSize] = {};
    wchar_t* res[1];

    while (!feof(file_text)) {
        res[0] = new wchar_t[BuffSize];

        fgets(str, BuffSize, file_text);
        ::MultiByteToWideChar(CP_UTF8, 0, str, BuffSize, res[0], BuffSize);
        for (int ii = 0; ii < wcslen(res[0]); ++ii) {
            if ((res[0])[ii] == ' ' || (res[0])[ii] == '\n' || (res[0])[ii] == '\t' || (res[0])[ii] == '\r' || (res[0])[ii] == 160) {
                for (int jj = ii; jj < wcslen(res[0]); ++jj) {
                    (res[0])[jj] = (res[0])[jj + 1];
                }
                (res[0])[wcslen(res[0]) - 1] = '\000';
                --ii;
            }
        }

        if (wcslen(res[0]) != 0) {
            rr[nLines] = new wchar_t[BuffSize];
            rr[nLines] = res[0];
            ++nLines;
        }
    }

    fclose(file_text);

    wchar_t tmp[BuffSize] = {};
    for (int ii = 0; ii < nLines; ++ii) {
        for (int jj = ii + 1; jj < nLines; ++jj) {
            if (wcscmp(rr[ii], rr[jj]) > 0) {
                wcscpy(tmp, rr[ii]);
                wcscpy(rr[ii], rr[jj]);
                wcscpy(rr[jj], tmp);
            }
        }
    }

    printf("Sort by code symbol:\n");
    for (int ii = 0; ii < nLines; ++ii) {
        wprintf(L"%i: %s\n", ii + 1, rr[ii]);
    }
}

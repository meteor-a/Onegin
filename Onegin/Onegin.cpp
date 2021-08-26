#include <stdio.h>
#include <wchar.h>
#include <Windows.h>

const int CODE_ERROR = -1;

int main() {
    char const* const Path = "text_on.txt";

    FILE* file_text = nullptr;
    file_text = fopen(Path, "rt");
    if (!file_text) {
        printf("Error open text file\n");
        return CODE_ERROR;
    }

    const int BuffSize = 1000;
    char str[BuffSize] = {};
    wchar_t res[BuffSize] = {};

    while (!feof(file_text)) {
        fgets(str, BuffSize, file_text);
        ::MultiByteToWideChar(CP_UTF8, 0, str, BuffSize, res, BuffSize);

        for (int ii = wcslen(res) - 1; ii >= 0; --ii) {
            if (res[ii] == ' ' || res[ii] == '\n') {
                for (int jj = ii; jj < wcslen(res) - 1; ++jj) {
                    res[jj] = res[jj + 1];
                }
                res[wcslen(res) - 1] = '\000';
            }
        }
    }

    fclose(file_text);
}

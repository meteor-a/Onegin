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
    }

    fclose(file_text);
}

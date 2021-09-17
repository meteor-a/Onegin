#include "SortGenText.h"

int main(int argc, char* argv[]) {
    SetOutputSettings();
    char file_name[100];
    int result = 0;
    if (argc > 1) {
        result = SortGenText(argv[1]);
    }
    else {
        printf("Input name of text file: ");
        scanf("%s", file_name);
        result = SortGenText(file_name);
    }

    return result;
}

#include "SortGenText.h"

int main(int argc, char* argv[]) {
    SetOutputSettings();

    printf("Input name of text file: ");
    char file_name[100];
    scanf("%s", file_name);
    int result = SortGenText(file_name);
    return result;
}

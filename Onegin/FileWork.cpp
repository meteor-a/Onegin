#include "FileWork.h"

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
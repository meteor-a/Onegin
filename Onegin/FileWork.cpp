#include "FileWork.h"

/**
    * Function to get size of file
    * \return - size of file in bytes
*/
int getFileSize(FILE* file/*!< - Pointer to opened file*/) {
    assert(file != nullptr);
    if (file == nullptr) {
        return CODE_ERROR;
    }

    fseek(file, 0L, SEEK_END);
    int sz = ftell(file);
    rewind(file);
    return sz;
}

/**
    * Function to get size of file
    * \return pointer- if file open successful
    * \return nullptr- if file not open
*/
FILE* OpenFile(const char* name_file/*!< - name file*/, const char* type/*!< - type open*/) {
    FILE* file = nullptr;
    file = fopen(name_file, type);
    assert(file != nullptr);
    if (file == nullptr) {
        return nullptr;
    }

    return file;
}

/**
    * Function to get size of file
    * \return 0- if no error
    * \return -9- if error
*/
int CloseFile(FILE* file/*!< - Pointer to opened file*/) {
    assert(file != nullptr);
    if (file == nullptr) {
        return CODE_ERROR;
    }

    if (fclose(file) == 0) {
        return OK_RESULT;
    }
    else {
        return CODE_ERROR;
    }
}

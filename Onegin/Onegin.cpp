#include "Onegin.h"

int main() {
    wchar_t** text_str = nullptr;
    int nLines = 0;

    text_str = InputStrings(text_str, &nLines);

    QuickSort(text_str, 0, nLines - 1);
    //SortStrings(text_str, nLines);

    OutputSortStrings(text_str, nLines);

    return OK_RESULT;
}

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
    for (int ii = 0; ii < nLines; ++ii) {
        wprintf(L"%i: %s\n", ii + 1, *(text_str + ii));
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

int Partition(wchar_t** text_str, int low, int high) {
    assert(text_str != nullptr);

    int pivot = high;
    int index = low;

    for (int ii = low; ii < high; ++ii) {
        if (wcscmp(*(text_str + ii), *(text_str + pivot)) < 0) {
            swap_str((text_str + ii), (text_str + index));
            ++index;
        }
    }
    swap_str((text_str + pivot), (text_str + index));

    return index;
}

int RandomPivotPartition(wchar_t** text_str, int low, int high) {
    assert(text_str != nullptr);
    
    int n = rand();
    int pvt = low + n % (high - low + 1); 
    
    pvt = low + n % (high - low + 1);
    swap_str((text_str + high), (text_str + pvt));

    return Partition(text_str, low, high);
}

int QuickSort(wchar_t** text_str, int low, int high) {
    assert(text_str != nullptr);
    
    int pindex = 0;
    if (low < high) {
        pindex = RandomPivotPartition(text_str, low, high);
        QuickSort(text_str, low, pindex - 1);
        QuickSort(text_str, pindex + 1, high);
    }
    return OK_RESULT;
}

wchar_t** InputStrings(wchar_t** text_str, int* nLines) {
    assert(nLines != nullptr);

    FILE* file_text;
    file_text = fopen(PATH_FILE, "r");
    if (file_text == NULL) {
        printf("error, while opening file\n");
        return nullptr;
    } else {
        printf("File open successfull\n");
    }

    fseek(file_text, 0L, SEEK_END);
    int sz = ftell(file_text);
    rewind(file_text);
    text_str = (wchar_t**)calloc(sz, sizeof(wchar_t));

    assert(text_str != nullptr);

    char str[BUFFER_SIZE] = {};
    wchar_t* res;

    while (!feof(file_text)) {
        res = (wchar_t*)calloc(BUFFER_SIZE, sizeof(wchar_t));
        assert(res != nullptr);

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

            assert(*(text_str + *nLines) != nullptr);

            *(text_str + *nLines) = res;
            ++(*nLines);
        }
    }

    fclose(file_text);

    return text_str;
}


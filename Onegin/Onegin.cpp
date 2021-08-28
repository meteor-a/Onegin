#include "Onegin.h"

int main() {
    wchar_t* text_str[SIZE_TEXT];
    int nLines = 0;

    InputText(text_str, &nLines);

    QuickSort(text_str, 0, nLines - 1);

    //SortStrings(text_str, nLines);

    OutputSortStrings(text_str, nLines);

    return OK_RESULT;
}

void swap_str(wchar_t** first, wchar_t** second) {
    wchar_t* tmp = nullptr;
    tmp = *first;
    *first = *second;
    *second = tmp;
}


int InputText(wchar_t** text_str, int* nLines) {
    FILE* file_text = nullptr;
    file_text = fopen(PATH_FILE_TEXT, "r");
    if (!file_text) {
        printf("Error open text file!\n");
        return CODE_ERROR;
    }

    char str[BUFFER_SIZE] = {};
    wchar_t res;

    while (!feof(file_text)) {
        res = getc(file_text);
        printf("%s", &res);
    }

    fclose(file_text);

    return OK_RESULT;
}

int SortStrings(wchar_t** text_str, int nLines) {
    for (int ii = 0; ii < nLines; ++ii) {
        for (int jj = ii + 1; jj < nLines; ++jj) {
            if (wcscmp(text_str[ii], text_str[jj]) > 0) {
                swap_str(&text_str[jj], &text_str[ii]);
            }
        }
    }

    return OK_RESULT;
}

int Partition(wchar_t** text_str, int low, int high) {
    int pivot = 0;
    int index = 0;
    index = low;
    pivot = high;

    for (int ii = low; ii < high; ++ii) {
        if (wcscmp(text_str[ii], text_str[pivot]) < 0) {
            swap_str(&text_str[ii], &text_str[index]);
            ++index;
        }
    }
    swap_str(&text_str[pivot], &text_str[index]);

    return index;
}

int RandomPivotPartition(wchar_t** text_str, int low, int high) {
    int pvt = 0;
    int n = 0;
    int temp = 0;
    n = rand();
    pvt = low + n % (high - low + 1);
    swap_str(&text_str[high], &text_str[pvt]);

    return Partition(text_str, low, high);
}

int QuickSort(wchar_t** text_str, int low, int high) {
    int pindex = 0;

    if (low < high) {
        pindex = RandomPivotPartition(text_str, low, high);
        QuickSort(text_str, low, pindex - 1);
        QuickSort(text_str, pindex + 1, high);
    }

    return 0;
}

int OutputSortStrings(wchar_t** text_str, int nLines) {
    setlocale(LC_CTYPE, "rus");

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    printf("Sort by code symbol:\n");
    for (int ii = 0; ii < nLines; ++ii) {
        wprintf(L"%i: %s\n", ii + 1, *text_str);
        if (ii + 1 != nLines) {
            text_str = text_str + 1;
        }
    }

    return OK_RESULT;
}



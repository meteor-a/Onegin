#include "Onegin.h"

int main() {
    wchar_t* rr[SizeText];
    int nLines = 0;

    InputText(rr, &nLines);

    QuickSort(rr, 0, nLines - 1);

    // SortStrings(rr, nLines);

    OutputSortStrings(rr, nLines);

    return OK_RESULT;
}

void swap_str(wchar_t* first, wchar_t* second) {
    wchar_t tmp[BuffSize] = {};
    wcscpy(tmp, first);
    wcscpy(first, second);
    wcscpy(second, tmp);
}

int InputText(wchar_t** rr, int* nLines) {
    FILE* file_text = nullptr;
    file_text = fopen(Path, "rt");
    if (!file_text) {
        printf("Error open text file!\n");
        return CODE_ERROR;
    }

    char str[BuffSize] = {};
    wchar_t* res[1];

    while (!feof(file_text)) {
        res[0] = new wchar_t[BuffSize];

        fgets(str, BuffSize, file_text);
        ::MultiByteToWideChar(CP_UTF8, 0, str, BuffSize, res[0], BuffSize);

        for (int ii = 0; ii < wcslen(res[0]); ++ii) {
            if ((res[0])[ii] == ' ' || (res[0])[ii] == '\n' || (res[0])[ii] == '\t' ||
                (res[0])[ii] == '\r' || (res[0])[ii] == 160) { // 160 - code of Non-breaking space

                for (int jj = ii; jj < wcslen(res[0]) - 1; ++jj) {
                    (res[0])[jj] = (res[0])[jj + 1];
                }
                (res[0])[wcslen(res[0]) - 1] = '\000';

                --ii;
            }
        }

        if (wcslen(res[0]) != 0) {
            *rr = new wchar_t[BuffSize];
            *rr = res[0];
            rr = rr + 1;
            ++(*nLines);
        }
    }

    fclose(file_text);

    return OK_RESULT;
}

int SortStrings(wchar_t** rr, int nLines) {
    for (int ii = 0; ii < nLines; ++ii) {
        for (int jj = ii + 1; jj < nLines; ++jj) {
            if (wcscmp(rr[ii], rr[jj]) > 0) {
                swap_str(rr[jj], rr[ii]);
            }
        }
    }

    return OK_RESULT;
}

int Partition(wchar_t** a, int low, int high) {
    int pivot, index, i;
    index = low;
    pivot = high;

    for (i = low; i < high; i++) {
        if (wcscmp(a[i], a[pivot]) < 0) {
            swap_str(a[i], a[index]);
            ++index;
        }
    }
    swap_str(a[pivot], a[index]);

    return index;
}

int RandomPivotPartition(wchar_t** a, int low, int high) {
    int pvt, n, temp;
    n = rand();
    pvt = low + n % (high - low + 1);
    swap_str(a[high], a[pvt]);

    return Partition(a, low, high);
}

int QuickSort(wchar_t** a, int low, int high) {
    int pindex = 0;

    if (low < high) {
        pindex = RandomPivotPartition(a, low, high);
        QuickSort(a, low, pindex - 1);
        QuickSort(a, pindex + 1, high);
    }

    return 0;
}


int OutputSortStrings(wchar_t** rr, int nLines) {
    setlocale(LC_CTYPE, "rus");

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    printf("Sort by code symbol:\n");
    for (int ii = 0; ii < nLines; ++ii) {
        wprintf(L"%i: %s\n", ii + 1, *rr);
        if (ii + 1 != nLines) {
            rr = rr + 1;
        }
    }

    return OK_RESULT;
}



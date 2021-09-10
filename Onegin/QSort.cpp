#include "QSort.h"


int comparator_start_str(const void* left, const void* right) {
    assert(left != nullptr);
    assert(right != nullptr);

    const StringStruct first = *((const StringStruct*)left);
    const StringStruct second = *((const StringStruct*)right);

     // return wcscmp_miss_punct(&first, &second);
     // return wcscmp(first.str, second.str);
     // return rev_wcscmp_miss_punct(&first, &second);
}

int Partition(StringStruct* input_arr, size_t left_ind, size_t right_ind) {
    size_t pivot = 0;
    size_t index = 0;

    index = left_ind;
    pivot = right_ind;

    for (size_t nStr = left_ind; nStr < right_ind; ++nStr) {
        if (comparator_start_str(input_arr + nStr, input_arr + pivot)) {
            swap_str(input_arr + nStr, input_arr + index);
            ++index;
        }
    }
    swap_str(input_arr + pivot, input_arr + index);

    return index;
}

int RandomPivotPartition(StringStruct* input_arr, size_t left_ind, size_t right_ind) {
    size_t pvt = 0;
    size_t n = 0;
    size_t temp = 0;

    n = rand();
    pvt = left_ind + n % (right_ind - left_ind + 1);
    swap_str(input_arr + right_ind, input_arr + pvt);

    return Partition(input_arr, left_ind, right_ind);
}

int QuickSort(StringStruct* input_arr, size_t left_ind, size_t right_ind) {
    size_t pindex = 0;
    if (left_ind < right_ind) {
        pindex = RandomPivotPartition(input_arr, left_ind, right_ind);
        QuickSort(input_arr, left_ind, pindex - 1);
        QuickSort(input_arr, pindex + 1, right_ind);
    }
    return OK_RESULT;
}
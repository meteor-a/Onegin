#include "QSort.h"

/**
    * Function for compare two strings since start
    * \return 1  - if first string > second by alphabet
    * \return -1 - if first string < second by alphabet
    * \return 0  - if first string == second by alphabet
*/
int comparator_wcscmp(const void* left/*!< - First string*/, const void* right/*!< - Second string*/) {
    assert(left  != nullptr);
    assert(right != nullptr);

    const StringStruct first  = *((const StringStruct*)left);
    const StringStruct second = *((const StringStruct*)right);

    return wcscmp_miss_punct(&first, &second);
}

/**
    * Function for compare two strings since end
    * \return 1  - if first string > second by alphabet
    * \return -1 - if first string < second by alphabet
    * \return 0  - if first string == second by alphabet
*/
int comparator_rev_wcscmp(const void* left/*!< - First string*/, const void* right/*!< - Second string*/) {
    assert(left  != nullptr);
    assert(right != nullptr);

    const StringStruct first  = *((const StringStruct*)left);
    const StringStruct second = *((const StringStruct*)right);

    return rev_wcscmp_miss_punct(&first, &second);
}

/**
    * Function for separate array 
    * \return index  - middle index of arrays
*/
long long partition(StringStruct* arr/*!< - Array*/, long long left/*!< - left index*/, long long right/*!< - right index*/, int (*comp)(const void*, const void*)/*!< - compare function*/) {
    assert(arr != nullptr);

    StringStruct* pivot = &arr[right];
    long long ind = (left - 1);

    for (long long cur_ind_elem = left; cur_ind_elem <= right - 1; ++cur_ind_elem) {
        if (comp(arr + cur_ind_elem, pivot) <= 0) {
            ++ind;
            swap_str(arr + ind, arr + cur_ind_elem);
        }
    }
    swap_str(arr + ind + 1, arr + right);

    return (ind + 1);
}

/**
    * Function for qsort arrays
*/
void quickSortR(StringStruct* arr/*!< - Array*/, long long left/*!< - left index*/, long long right/*!< - right index*/, int (*comp)(const void*, const void*)/*!< - compare function*/) {
    assert(arr  != nullptr);
    assert(comp != nullptr);

    if (left < right) {
        long long pi = partition(arr, left, right, comp);
        quickSortR(arr, left, pi - 1, comp);
        quickSortR(arr, pi + 1, right, comp);
    }
}

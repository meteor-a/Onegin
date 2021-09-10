#include "QSort.h"

int comparator_wcscmp(const void* left, const void* right) {
    assert(left != nullptr);
    assert(right != nullptr);

    const StringStruct first = *((const StringStruct*)left);
    const StringStruct second = *((const StringStruct*)right);

    return wcscmp_miss_punct(&first, &second);
}

int comparator_rev_wcscmp(const void* left, const void* right) {
    assert(left != nullptr);
    assert(right != nullptr);

    const StringStruct first = *((const StringStruct*)left);
    const StringStruct second = *((const StringStruct*)right);

    return rev_wcscmp_miss_punct(&first, &second);
}

long long partition(StringStruct* arr, long long left, long long right, int (*comp)(const void*, const void*)) {
    assert(arr != nullptr);

    StringStruct pivot = arr[right];
    long long ind = (left - 1);

    for (long long cur_ind_elem = left; cur_ind_elem <= right - 1; cur_ind_elem++) {
        if (comp(arr + cur_ind_elem, &pivot) <= 0) {
            ++ind;
            swap_str(arr + ind, arr + cur_ind_elem);
        }
    }
    swap_str(arr + ind + 1, arr + right);

    return (ind + 1);
}

void quickSortR(StringStruct* arr, long long left, long long right, int (*comp)(const void*, const void*)) {
    assert(arr != nullptr);
    assert(comp != nullptr);

    if (left < right) {
        long long pi = partition(arr, left, right, comp); // partitioning index
        quickSortR(arr, left, pi - 1, comp);
        quickSortR(arr, pi + 1, right, comp);
    }
}
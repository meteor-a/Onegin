#include "QSort.h"

int comparator(const void* left, const void* right) {
    assert(left != nullptr);
    assert(right != nullptr);

    const StringStruct first = *((const StringStruct*)left);
    const StringStruct second = *((const StringStruct*)right);

      return wcscmp_miss_punct(&first, &second);
     // return rev_wcscmp_miss_punct(&first, &second);
}
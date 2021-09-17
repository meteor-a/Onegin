#include "StringStruct.h"

/*!
    * Function for swap two StringStruct elems
    * \return 0- if no error
    * \return -9- if error
*/
int swap_str(StringStruct* left, StringStruct* right) {
    assert(left != nullptr);
    assert(right != nullptr);
    if (left == nullptr || right == nullptr) {
        return CODE_ERROR;
    }

    StringStruct tmp = *left;
    *left  = *right;
    *right = tmp;

    return OK_RESULT;
}

/*!
    * Function for compare two StringStruct by albphabet from start
    * \return 0- if StringStruct equal
    * \return 1- if first string > second
    * \return -1 - if first string < second
*/
int wcscmp_miss_punct(const StringStruct* left/*!< - First string*/, const StringStruct* right/*!< - Second number*/) {
    assert(left  != nullptr);
    assert(right != nullptr);
    if (left == nullptr || right == nullptr) {
        return CODE_ERROR;
    }

    size_t size_left      = left->length;
    size_t size_right     = right->length;
    size_t cur_symb_left  = 0;
    size_t cur_symb_right = 0;
    while (cur_symb_left < size_left && cur_symb_right < size_right) {
        if (!(iswalpha(left->str[cur_symb_left]))) {
            ++cur_symb_left;
            continue;
        }

        if (!(iswalpha(right->str[cur_symb_right]))) {
            ++cur_symb_right;
            continue;
        }

        wchar_t letter_left  = towlower(left->str[cur_symb_left]);
        wchar_t letter_right = towlower(right->str[cur_symb_right]);

        if (letter_left < letter_right) return -1;
        if (letter_left > letter_right) return +1;

        ++cur_symb_right;
        ++cur_symb_left;

    }

    if (cur_symb_left == size_left && cur_symb_right == size_right)  return 0;
    if (cur_symb_left < size_left) return +1;

    return -1;

}

/*!
    * Function for compare two StringStruct by albphabet from end
    * \return 0- if StringStruct equal
    * \return 1- if first string > second
    * \return -1 - if first string < second
*/
int rev_wcscmp_miss_punct(const StringStruct* left/*!< - First string*/, const StringStruct* right/*!< - Second number*/) {
    assert(left  != nullptr);
    assert(right != nullptr);
    if (left == nullptr || right == nullptr) {
        return CODE_ERROR;
    }

    long long cur_symb_left  = left->length  - 1;
    long long cur_symb_right = right->length - 1;
    
    while (cur_symb_left >= 0 && cur_symb_right >= 0) {
        if (!(iswalpha(left->str[cur_symb_left]))) {
            --cur_symb_left;
            continue;
        }
        
        if (!(iswalpha(right->str[cur_symb_right]))) {
            --cur_symb_right;
            continue;
        }

        wchar_t letter_left  = towlower(left->str[cur_symb_left]);
        wchar_t letter_right = towlower(right->str[cur_symb_right]);

        if (letter_left < letter_right) return -1;
        if (letter_left > letter_right) return +1;

        --cur_symb_right;
        --cur_symb_left;
    }

    if (cur_symb_left == 0 && cur_symb_right == 0) return 0;
    if (cur_symb_left > 0) return 1;

    return -1;

}

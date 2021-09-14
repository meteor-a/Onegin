#include "StringStruct.h"

int swap_str(StringStruct* left, StringStruct* right) {
    assert(left != nullptr);
    assert(right != nullptr);
    if (left == nullptr || right == nullptr) {
        return CODE_ERROR;
    }

    wchar_t* tmp = left->str;
    left->str = right->str;
    right->str = tmp;
    size_t tmp_length = left->length;
    left->length = right->length;
    right->length = tmp_length;

    return OK_RESULT;
}

int wcscmp_miss_punct(const StringStruct* left, const StringStruct* right) {
    assert(left != nullptr);
    assert(right != nullptr);
    if (left == nullptr || right == nullptr) {
        return CODE_ERROR;
    }

    size_t size_left = left->length;
    size_t size_right = right->length;
    size_t cur_symb_left = 0;
    size_t cur_symb_right = 0;
    while (cur_symb_left < size_left && cur_symb_right < size_right) {
        if (!(iswalpha(left->str[cur_symb_left]))) {
            ++cur_symb_left;
        }
        else if (!(iswalpha(right->str[cur_symb_right]))) {
            ++cur_symb_right;
        }
        else {
            wchar_t letter_left = towlower(left->str[cur_symb_left]);
            wchar_t letter_right = towlower(right->str[cur_symb_right]);

            if (letter_left < letter_right) {
                return -1;
            }
            else if (letter_left > letter_right) {
                return 1;
            }

            ++cur_symb_right;
            ++cur_symb_left;
        }
    }

    if (cur_symb_left == size_left && cur_symb_right == size_right) {
        return 0;
    }
    else if (cur_symb_left < size_left) {
        return 1;
    }
    else {
        return -1;
    }
}

int rev_wcscmp_miss_punct(const StringStruct* left, const StringStruct* right) {
    assert(left != nullptr);
    assert(right != nullptr);
    if (left == nullptr || right == nullptr) {
        return CODE_ERROR;
    }

    long long cur_symb_left = left->length - 1;
    long long cur_symb_right = right->length - 1;
    while (cur_symb_left >= 0 && cur_symb_right >= 0) {
        if (!(iswalpha(left->str[cur_symb_left]))) {
            --cur_symb_left;
        }
        else if (!(iswalpha(right->str[cur_symb_right]))) {
            --cur_symb_right;
        }
        else {
            wchar_t letter_left = towlower(left->str[cur_symb_left]);
            wchar_t letter_right = towlower(right->str[cur_symb_right]);

            if (letter_left < letter_right) {
                return -1;
            }
            else if (letter_left > letter_right) {
                return 1;
            }

            --cur_symb_right;
            --cur_symb_left;
        }
    }

    if (cur_symb_left == 0 && cur_symb_right == 0) {
        return 0;
    }
    else if (cur_symb_left > 0) {
        return 1;
    }
    else {
        return -1;
    }
}
#pragma once
#include "Constants.h"
#include "StringStruct.h"
#include <stdlib.h>
#include <assert.h>

int comparator_wcscmp(const void* left, const void* right);
int comparator_rev_wcscmp(const void* left, const void* right);

long long partition(StringStruct* arr, long long left, long long right, int (*comp)(const void*, const void*));
void quickSortR(StringStruct* arr, long long left, long long right, int (*comp)(const void*, const void*));
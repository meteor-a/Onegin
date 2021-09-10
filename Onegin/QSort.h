#pragma once
#include "Constants.h"
#include "StringStruct.h"
#include <stdlib.h>
#include <assert.h>

int comparator_wcscmp(const void*, const void*);
int comparator_rev_wcscmp(const void*, const void*);

long long partition(StringStruct*, long long, long long, int (*)(const void*, const void*));
void quickSortR(StringStruct*, long long, long long, int (*)(const void*, const void*));
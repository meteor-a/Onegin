#pragma once
#include "Constants.h"
#include "StringStruct.h"
#include <stdlib.h>
#include <assert.h>

int RandomPivotPartition(StringStruct*, size_t, size_t);
int Partition(StringStruct*, size_t, size_t);
int QuickSort(StringStruct*, size_t, size_t);

int comparator_start_str(const void*, const void*);
#pragma once

#include <ppl.h>
#include <vector>
#include <algorithm>

#include "Row.h"
#include "Data.h"

#define DataIter std::vector<Row>::iterator

class ParallelMergeSort
{
public:
	void merge(DataIter b, DataIter m, DataIter e);
	void merge_sort(DataIter b, DataIter e);
	ParallelMergeSort();
	~ParallelMergeSort();
};


#pragma once

#include <ppl.h>
#include <vector>
#include <algorithm>

#include "Row.h"
#include "Data.h"

#define DataIter std::vector<Row>::iterator

class ParallelMergeSort
{
private:
	static void merge(DataIter b, DataIter m, DataIter e);
	ParallelMergeSort();
public:
	
	virtual ~ParallelMergeSort() = 0;
	static void mergeSortParallel(DataIter b, DataIter e);
};


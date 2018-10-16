#include "ParallelMergeSort.h"



ParallelMergeSort::ParallelMergeSort()
{
}


ParallelMergeSort::~ParallelMergeSort()
{
}

void merge(DataIter b, DataIter m, DataIter e)
{ 
	// this is the merger, doing the important job
	std::vector<typename DataIter::value_type> left(b, m);
	std::vector<typename DataIter::value_type> right(m, e);

	// guards for the two ranges
	left.push_back(std::numeric_limits<typename DataIter::value_type>::max());
	right.push_back(std::numeric_limits<typename DataIter::value_type>::max());

	auto itl = std::begin(left);
	auto itr = std::begin(right);

	while (b != e) {
		if (*itl < *itr)
			*b++ = *itl++;
		else
			*b++ = *itr++;
	}
}
/*
void merge_sort(DataIter b, DataIter e) { // serial merge_sort, used for pieces smaller < 500
	if (b < e - 1) {
		auto dis = std::distance(b, e) / 2;
		DataIter m = b + dis;

		if (dis > 100) {
			merge_sort(b, m);
			merge_sort(m, e);
			merge(b, m, e);
		}
		//switch to insertion sort for pieces < 100
		else
			std::sort(b, e);
	}
}
*/

void merge_sort_parallel(DataIter b, DataIter e) { // merge_sort parallel 
	if (b != e - 1) {
		auto dis = std::distance(b, e);
		DataIter m = b + dis / 2;
		if (dis > 500) {
			concurrency::parallel_invoke([&]() { merge_sort_parallel(b, m); },
				[&]() { merge_sort_parallel(m, e); });
			merge(b, m, e);
		}
		else {
			std::sort(b, e);
		}
		
	}
}
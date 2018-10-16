#include "ParallelMergeSort.h"


void ParallelMergeSort::merge(DataIter b, DataIter m, DataIter e)
{
	std::vector<typename DataIter::value_type> left(b, m);
	std::vector<typename DataIter::value_type> right(m, e);

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

void ParallelMergeSort::mergeSortParallel(DataIter b, DataIter e)
{
	if (b != e - 1)
	{
		auto dis = std::distance(b, e);
		DataIter m = b + dis / 2;
		if (dis > 500)
		{
			concurrency::parallel_invoke([&]() { mergeSortParallel(b, m); },
				[&]() { mergeSortParallel(m, e); });
			merge(b, m, e);
		}
		else
		{
			std::sort(b, e);
		}
	}

}

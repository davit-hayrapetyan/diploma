#include "ParallelMergeSort.h"


void ParallelMergeSort::merge(DataIter b, DataIter m, DataIter e)
{
	std::vector<typename DataIter::value_type> left(b, m);
	std::vector<typename DataIter::value_type> right(m, e);

	left.push_back(std::numeric_limits<typename DataIter::value_type>::max());
	right.push_back(std::numeric_limits<typename DataIter::value_type>::max());

	auto itl = left.begin();
	auto itr = right.begin();
	
	/*while (b != e) {
		if ((itl != left.end())  && (*itl < *itr) )
			*b++ = *itl++;
		else
			*b++ = *itr++;
	}*/
	/*while (b != e)
	{*/
		while (itl != left.end() && itr != right.end())
		{
			if (*itl < *itr)
				*b++ = *itl++;
			else
				*b++ = *itr++;
		}
		while (itl != left.end())
		{
			*b++ = *itl++;
		}
		while (itr != right.end())
		{
			*b++ = *itr++;
		}
	//}
}

ParallelMergeSort::ParallelMergeSort()
{
}

ParallelMergeSort::~ParallelMergeSort()
{
}

void ParallelMergeSort::mergeSortParallel(DataIter b, DataIter e)
{
	int dist = std::distance(b, e);
	//if (b != e - 1)
	//{
	//	//auto dis = std::distance(b, e);
	//	DataIter m = b + dis / 2;
	//	if (dis > 500)
	//	{
	//		concurrency::parallel_invoke([&]() { mergeSortParallel(b, m); },
	//			[&]() { mergeSortParallel(m, e); });
	//		merge(b, m, e);
	//	}
	//	else
	//	{
	//		std::sort(b, e);
	//	}
	//}
	nTC = QThread::idealThreadCount();
	int offset = dist / nTC;
	QFutureSynchronizer<void> synchronizer;
	QVector<QPair<DataIter, DataIter> > Ranges;
	for (auto beginIter = b; std::distance(b, beginIter) < dist;/*beginIter += offset*/)
	{
		DataIter endIter = beginIter + offset;
		if (std::distance(b, endIter) + offset > dist)
			endIter = e;
		Ranges.append(qMakePair(beginIter , endIter));
		synchronizer.addFuture(QtConcurrent::run(this, &ParallelMergeSort::mySort, beginIter, endIter) );
		beginIter = endIter;
		if (beginIter == e)
			break;
	}
	synchronizer.waitForFinished();
	synchronizer.clearFutures();
	while (Ranges.count() != 1)
	{
		QVector<QPair<DataIter, DataIter> > tmpRanges;
		QFutureSynchronizer<void> mergeSynchronizer;
		for (auto rangesIter = Ranges.begin();(rangesIter != Ranges.end() - 1) && (rangesIter != Ranges.end());/* rangesIter ++*/)
		{
			DataIter begin, mid, end;
			begin = rangesIter->first;
			mid = rangesIter->second;
			end = (rangesIter + 1)->second;
			rangesIter += 2;
			tmpRanges.append(qMakePair(begin , end));
			if (rangesIter == Ranges.end() - 1)
				tmpRanges.append( *(Ranges.end() - 1));
			mergeSynchronizer.addFuture(QtConcurrent::run(this, &ParallelMergeSort::merge, begin, mid, end));
		}
		mergeSynchronizer.waitForFinished();
		mergeSynchronizer.clearFutures();
		Ranges.clear();
		Ranges.append(tmpRanges);
		tmpRanges.clear();
	}
}

void ParallelMergeSort::mySort(DataIter begin, DataIter end)
{
	std::sort(begin, end);
}

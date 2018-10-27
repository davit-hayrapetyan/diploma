#ifndef PARALLELMERGESORT_H
#define PARALLELMERGESORT_H

#include <ppl.h>
#include <vector>
#include <algorithm>

#include "Row.h"
#include "Data.h"

#include <QVector>
#include <QPair>
#include <QFuture>
#include <QFutureSynchronizer>
#include <QThread>
#include <QtConcurrent/qtconcurrentrun.h>

#define DataIter std::vector<Row>::iterator

class ParallelMergeSort
{
private:
	void merge(DataIter b, DataIter m, DataIter e);
	int nTC;
public:
	
	ParallelMergeSort();
	~ParallelMergeSort();
	void mergeSortParallel(DataIter b, DataIter e);
	void mySort(DataIter begin, DataIter end);
};

#endif //PARALLELMERGESORT_H
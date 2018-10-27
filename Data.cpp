#include "Data.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>

void Data::sort()
{
	ParallelMergeSort sorter;
	//std::sort(m_PriorityData.begin(), m_PriorityData.end());
	sorter.mergeSortParallel(m_PriorityData.begin(), m_PriorityData.end());
	for (int i = 0; i < mySize; i++)
	{
		m_indexMap[i] = *(m_PriorityData[i].Cells.back());
	}
}

void Data::reset()
{
	for (int i = 0; i < mySize; i++)
	{
		m_indexMap[i] = i;
	}
}

Data::Data()
{
	std::srand(unsigned(std::time(0)));
	for (int i = 0; i < 1000; i++)
	{
		std::vector<int> temp;
		temp.push_back(i);
		m_Data.push_back(temp);
		m_indexMap.emplace(i, i);
	}
	for (int i = 0; i < mySize; i++)
	{
		for (int j = 1; j < mySize; j++)
			m_Data[i].push_back(std::rand()%10000);
	}
	m_Colindex.emplace(std::string("N") , 0);
	for (int i = 1; i <= mySize; i++)
	{
		m_Colindex.emplace(std::string("Name " + std::to_string(i)), i);
	}
	for (std::string name : m_PriorityList)
	{
		for (int i = 0; i < mySize; i++)
		{
			m_PriorityData[i].Cells.push_back(m_Data[i].begin() + m_Colindex[name]);
		}
	}
	for (int i = 0; i < mySize; i++)
	{
		m_PriorityData[i].Cells.push_back(m_Data[i].begin());
	}
}

bool operator<(Row a, Row b)
{
	for (int i = 0; i < a.Cells.size(); i++)
	{
		if ( *(a.Cells.at(i)) < *(b.Cells.at(i)) )
			return true;
		if ( *(a.Cells.at(i)) > *(b.Cells.at(i)) )
			return false;
	}
	return false;
}

Data::~Data()
{
}

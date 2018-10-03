#pragma once
#include <vector>
#include <map>
#include "Row.h"
class Data
{
public:
	std::vector<std::vector<int>> m_Data;
	std::vector<Row> m_PriorityData = std::vector<Row>(mySize);
	std::vector<std::string> m_PriorityList = { "Name 3", "Name 4", "Name 7", "Name 45", "Name 34" };
	std::map<int, int> m_IndexMap;
	std::map<std::string, int> m_ColIndex;
	void sort();
	void reset();
	Data();
	~Data();
};


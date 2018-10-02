#pragma once
#include <vector>
#include <string>
#define mySize 1000 
class Row
{
public:
	std::vector<std::vector<int>::iterator> Cells;
	Row();
	~Row();
	friend bool operator < (Row a, Row b);
};


#include <array>
#include <algorithm>
#include <vector>
#include <random>
#include <numeric>
#include <print>
#include <list>
#include <ranges>
#include "String.h"
#include "save.h"

//-----------------------------------------------------------------
// 2024.04.30 1�б� stl				                        (15�� 1)
//  
// c++20 range
// - [begin, end)
// - begin + size
// - [begin, predicate)
// - [begin, ...)   ����
//-----------------------------------------------------------------

extern bool ����;



int main()
{
	save("FileName.cpp");

	vector<int>v;

	// ADL(argument dependent lookup) ����� �۵����� �ʵ���
	// Eric Niebler
	find(v.begin(), v.end(), 3);
	ranges::find(v.begin(), v.end(), 3);


}
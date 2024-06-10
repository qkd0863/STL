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
// 2024.04.30 1학기 stl				                        (15주 1)
//  
// c++20 range
// - [begin, end)
// - begin + size
// - [begin, predicate)
// - [begin, ...)   무한
//-----------------------------------------------------------------

extern bool 관찰;



int main()
{
	save("FileName.cpp");

	vector<int>v;

	// ADL(argument dependent lookup) 기능이 작동하지 않도록
	// Eric Niebler
	find(v.begin(), v.end(), 3);
	ranges::find(v.begin(), v.end(), 3);


}
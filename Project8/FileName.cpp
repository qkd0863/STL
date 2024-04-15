#include <vector>
#include <numeric>
#include <algorithm>
#include <array>
#include "String.h"
#include "save.h"

//-----------------------------------------------------------------
// 2024.04.15 1학기 stl				                        (7주 1)
// 
// vector - dynamic array
//-----------------------------------------------------------------

extern bool 관찰;



int main()	
{
	save("FileName.cpp");

	vector<int> v{ 1,2,3,4,5 };
	//문제 v에서 3을 제거하고 출력하라
	// erase-remove idiom

	//auto p = remove(v.begin(), v.end(), 3);
	//v.erase(p, v.end());

	v.erase(remove(v.begin(), v.end(), 3), v.end());


	for (int num : v)
		cout << num << ' ' << endl;		// 1 2 4 5 5    한칸씩 땡긴다
}
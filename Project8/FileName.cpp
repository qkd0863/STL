#include <map>
#include <unordered_map>
#include <unordered_set>
#include <fstream>
#include <random>
#include "String.h"
#include "save.h"

//-----------------------------------------------------------------
// 2024.04.30 1학기 stl				                        (13주 1)
//  
// unordered associative container
// unordered의 의미
// 메모리 구조 어떻게?
// 내가 만든 String도 관리가능해?
//-----------------------------------------------------------------

extern bool 관찰;

default_random_engine dre;
uniform_int_distribution uid{1,99999};
normal_distribution nd{ 0.0,0.1 };

int main()	
{
	//save("FileName.cpp");


	unordered_set<int> us{ 1,2,3,4 };


	us.insert(7);
	us.insert(10);
	for (int num : us)
		cout << num << endl;

}                
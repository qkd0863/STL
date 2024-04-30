#include <algorithm>
#include <fstream>
#include <list>
#include <ranges>
#include "save.h"
#include "String.h"
//-----------------------------------------------------------------
// 2024.04.30 1학기 stl				                        (9주 2)
//  
// 
//-----------------------------------------------------------------

extern bool 관찰;


int main()	
{
	//save("FileName.cpp");
	
	//문제 "FileName.cpp"의 소문자를 list<char>에 push_back()으로 저장하라
	//출력하라
	//모든 소문자가 다 있나 확인하라


	ifstream in{ "FileName.cpp" };
	if (not in)
		return 12345;
	char c;
	vector<char> List;
	//list<char> List;
	
	while (in >> c)
		if (islower(c))
			List.push_back(c);
	sort(List.begin(), List.end());
	auto p = unique(List.begin(), List.end());
	List.erase(p, List.end());			//지워줘야한다
	//List.sort();	
	//List.unique();

	for (const char& c : List)
		cout << c;
	cout << endl;

	
	if (List.size() == 26)
		cout << "모든 문자가 있다" << endl;
	else
		cout << "없다" << endl;



}                
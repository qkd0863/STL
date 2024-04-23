#include <algorithm>
#include <fstream>
#include <list>
#include <ranges>
#include "save.h"
#include "String.h"
//-----------------------------------------------------------------
// 2024.04.22 1학기 stl				                        (8주 1)
//  
// list
//-----------------------------------------------------------------

extern bool 관찰;


int main()	
{
	//save("FileName.cpp");
	list<String>container;
	관찰 = true;
	//문제 container를 길이오름차순으로 정렬하라
	ifstream in{ "String.cpp" };
	if (not in)
	{
		return 1234;
	}
	
	while (in)
	{
		in >> container.emplace_back();
	}

	container.sort([](const String& a, const String& b) {return a.getLen() < b.getLen(); });
	//sort(container.begin(), container.end(), [](const String& a, const String& b) {return a.getLen() < b.getLen(); });
	//sort(container, [](const String& a, const String& b) {return a.getLen() < b.getLen(); });
	
	//원소의 순서를 거꾸로 뒤집어라
	container.reverse();


	관찰 = false;


	// 출력을 거꾸로 해라

	cout << endl;
	for (const String& s : container)
		cout << s << endl;
	for (auto p = container.rbegin(); p != container.rend(); ++p)
		cout << *p << endl;

	// 문제 길이가 5인 것들만 화면에 출력하라
	for (const String& s : container)
		if (s.getLen() == 5)
			cout << s << endl;

}                
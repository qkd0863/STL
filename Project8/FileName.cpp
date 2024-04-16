#include <deque>
#include <vector>
#include <list>
#include "String.h"
#include "save.h"

//-----------------------------------------------------------------
// 2024.04.16 1학기 stl				                        (7주 2)
//  
// deque - vecto와 list의 중간형태를 띄는 자료구조다
//-----------------------------------------------------------------

extern bool 관찰;

class Test
{
	char x[4096];
};

int main()	
{
	save("FileName.cpp");
	//vector<Test> v;  //1574803
	//deque<Test> v;   //2500000
	list<Test>v;	   //2500000
	while (1)
	{
		try
		{
			v.push_back(Test{});
		}
		catch (...)
		{
			cout << "끝" << endl;
			cout << v.size() << endl;
			break;
		}
		if (!(v.size() % 100000))
			cout << v.size() << endl;
	}
}                
#include <string>
#include <vector>
#include "String.h"
#include "save.h"

//-----------------------------------------------------------------
// 2024.04.30 1학기 stl				                        (11주 2)
//  
// Associative Conatainer - set
// 6/11 화요일 기말 
//-----------------------------------------------------------------

extern bool 관찰;

// 세번째 인자는 callable type인데 이 중에서 boolean 값을 리턴하는 것을 
// 특별히 predicate라고 부른다(조건자, 서술자, 판단자)


template<class initer,class outiter>
void my_copy(initer begin, initer end, outiter d)
{
	while (begin != end)
	{
		//*d operator=(*begin)
		*d = *begin;
		++begin;
		++d;
	}
}



int main()	
{
	//save("FileName.cpp");
	
	
	String s{ "20240514 기말시험 6월 15일 15주 2일" };
	vector<char>v;

	my_copy(s.begin(), s.end(), back_inserter(v));	//undefind behavior

	for (char c : v)
		cout << c;
}                
#include "String.h"
#include "save.h"
#include <vector>
#include <algorithm>
#include <string>
#include <span>


//-----------------------------------------------------------------
// 2024.04.30 1학기 stl				                        (10주 2)
//  
//
//-----------------------------------------------------------------

extern bool 관찰;

template <class 반복자>
void f(반복자 iter)
{
	cout << typeid(iterator_traits<반복자>::iterator_category).name() << endl;
	//c++17
	cout << typeid(반복자::iterator_concept).name() << endl;
}



int main()	
{
	save("FileName.cpp");
	
	string s{ "1357924680" };
	
	
	sort(s.rbegin(), s.rend());
	cout << s << endl;
}                
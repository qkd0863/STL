#include "String.h"
#include "save.h"
#include <vector>
#include <algorithm>
#include <string>
#include <span>


//-----------------------------------------------------------------
// 2024.04.30 1�б� stl				                        (10�� 2)
//  
//
//-----------------------------------------------------------------

extern bool ����;

template <class �ݺ���>
void f(�ݺ��� iter)
{
	cout << typeid(iterator_traits<�ݺ���>::iterator_category).name() << endl;
	//c++17
	cout << typeid(�ݺ���::iterator_concept).name() << endl;
}



int main()	
{
	save("FileName.cpp");
	
	string s{ "1357924680" };
	
	
	sort(s.rbegin(), s.rend());
	cout << s << endl;
}                
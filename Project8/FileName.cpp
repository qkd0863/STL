#include <string>
#include <vector>
#include "String.h"
#include "save.h"

//-----------------------------------------------------------------
// 2024.04.30 1�б� stl				                        (11�� 2)
//  
// Associative Conatainer - set
// 6/11 ȭ���� �⸻ 
//-----------------------------------------------------------------

extern bool ����;

// ����° ���ڴ� callable type�ε� �� �߿��� boolean ���� �����ϴ� ���� 
// Ư���� predicate��� �θ���(������, ������, �Ǵ���)


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
	
	
	String s{ "20240514 �⸻���� 6�� 15�� 15�� 2��" };
	vector<char>v;

	my_copy(s.begin(), s.end(), back_inserter(v));	//undefind behavior

	for (char c : v)
		cout << c;
}                
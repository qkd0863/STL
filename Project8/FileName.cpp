#include <algorithm>
#include <fstream>
#include <list>
#include <ranges>
#include "save.h"
#include "String.h"
//-----------------------------------------------------------------
// 2024.04.22 1�б� stl				                        (8�� 1)
//  
// list
//-----------------------------------------------------------------

extern bool ����;


int main()	
{
	//save("FileName.cpp");
	list<String>container;
	���� = true;
	//���� container�� ���̿����������� �����϶�
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
	
	//������ ������ �Ųٷ� �������
	container.reverse();


	���� = false;


	// ����� �Ųٷ� �ض�

	cout << endl;
	for (const String& s : container)
		cout << s << endl;
	for (auto p = container.rbegin(); p != container.rend(); ++p)
		cout << *p << endl;

	// ���� ���̰� 5�� �͵鸸 ȭ�鿡 ����϶�
	for (const String& s : container)
		if (s.getLen() == 5)
			cout << s << endl;

}                
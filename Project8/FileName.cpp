#include <algorithm>
#include <fstream>
#include <list>
#include <ranges>
#include "save.h"
#include "String.h"
//-----------------------------------------------------------------
// 2024.04.30 1�б� stl				                        (9�� 2)
//  
// 
//-----------------------------------------------------------------

extern bool ����;


int main()	
{
	//save("FileName.cpp");
	
	//���� "FileName.cpp"�� �ҹ��ڸ� list<char>�� push_back()���� �����϶�
	//����϶�
	//��� �ҹ��ڰ� �� �ֳ� Ȯ���϶�


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
	List.erase(p, List.end());			//��������Ѵ�
	//List.sort();	
	//List.unique();

	for (const char& c : List)
		cout << c;
	cout << endl;

	
	if (List.size() == 26)
		cout << "��� ���ڰ� �ִ�" << endl;
	else
		cout << "����" << endl;



}                
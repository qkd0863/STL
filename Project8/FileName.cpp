#include <string>
#include "String.h"
#include "save.h"

//-----------------------------------------------------------------
// 2024.04.30 1�б� stl				                        (11�� 1)
//  
// �˰��� �Լ��� �ݺ��ڸ� ���ڷ� �޴´�
// 
//-----------------------------------------------------------------

extern bool ����;

//template<class �ݺ���,class ��>
//�ݺ��� my_find(�ݺ��� begin, �ݺ��� end, �� val)
//{
//	return begin
//};

int main()	
{
	save("FileName.cpp");
	
	String s{ "20240513 - stl container iterator algorithm" };
	
	// ���� ����ڰ� ã�� ���ڰ� s�� �ִ��� �˷�����

	while (1)
	{
		cout << "ã�� ���ڴ�?";
		char ch;
	/*	auto p = my_find(s.begin(), s.end(), ch);
		if (p != s.end())
			cout << "��ġ - " << "�� ã��" << endl;
		else
			cout << ch << "�� s�� ���� �����Դϴ�" << endl;*/
	}
}                
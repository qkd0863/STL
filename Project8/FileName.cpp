#include "save.h"
#include <string>
#include <array>
#include <numeric>
#include <memory>
#include <algorithm>
#include <random>
#include <print>
#include <functional>

//-----------------------------------------------------------------
// 2024.04.1 1�б� stl				                        (5�� 1)
// 
// 
// callable type - ���Ѱ��� Ÿ���� �ִ�
// � �Լ��� �ٸ� �Լ��� �����Ѵ�
// sort�� �� � �������� ���������� ��� sort�Լ����� �˷��ֳ�?
// 1. �Լ� �����͸� �����Ѵ�
// 2. ���ٸ� �����Ѵ� - visual studio�� �Լ� ��ü�� ����
// 3. ()�����ڸ� �����ε��� Ŭ������ ��ü�� �����Ѵ� (funtion call - () )
//  �Լ� ��ü(function object)
// 1�� 2,3�� �ٸ��� - 2,3�� ���¸� ���� �� �ִ�
// 
// ȣ�Ⱑ���� Ÿ���� ��ǥ�ϴ� Ÿ���� ������� - function 
// 
//-----------------------------------------------------------------


class String
{
	size_t len{};
	unique_ptr<char[]> p;
public:
	String(const char* s):len(strlen(s))
	{
		p = make_unique<char[]>(len);
		memcpy(p.get(), s, len);
	}

	friend ostream& operator<<(ostream& os, const String& str)
	{
		for (size_t i = 0; i < str.len; ++i)
			os << str.p.get()[i];
		return os;
	}
};



int main()
{
	save("FileName.cpp");
	String s{ "STL�� �����ϱ� ���� Ŭ�����Դϴ�" };
	//String t = s;
	cout << s << endl;
	//cout << t << endl;
}




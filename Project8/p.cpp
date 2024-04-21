#include <deque>
#include <vector>
#include <list>
#include <array>
#include <algorithm>
#include <fstream>
#include <numeric>
#include <random>
#include "String.h"
#include "save.h"

//-----------------------------------------------------------------
// 2024.04.16 1�б� stl				                        (7�� 2)
//  
// deque - vecto�� list�� �߰����¸� ��� �ڷᱸ����
//-----------------------------------------------------------------

extern bool ����;

class Test
{
	char x[4096];
};
  

default_random_engine dre;
uniform_int_distribution uidNum{ 1,9999 };
uniform_int_distribution<int> uidChar{ 'a','z' };

class Dog
{
	char c{ (char)uidChar(dre) };
	int num{ uidNum(dre) };
public:
	int getN()const { return num; }

	void show()const
	{
		cout << c << " - " << num << endl;
	}

	friend ostream& operator<<(ostream& os, const Dog& dog)
	{
		return os << "����:" << dog.c << ", ����" << dog.num;
	}

	friend bool operator<(const Dog& lhs, const Dog& rhs)
	{
		return lhs.num < rhs.num;
	}


	friend istream& operator>>(istream& is, Dog& dog)
	{
		return is.read((char*)&dog, sizeof(Dog));
	}


};


int main()
{
	
	array<int, 26> T{};
	//���� a�� "FileName.cpp"�� �ִ� �ܾ �����϶�
	//a�� ���� ������������ �����϶�
	//ȭ�鿡 a�� ����϶�

	ifstream in{ "FileName.cpp" };
	if (not in)
		return 123456;

	char c;
	while (in.read(&c, sizeof(char)))
	{
		if (iswlower(c))
			T[static_cast<int>(c) - 'a'] += 1;
	}
		
		


		
	for (int i = 0; i < 26; ++i)
	{
		cout << char(i + 'a') << " - " << T[i] << endl;
	}

	



		
}
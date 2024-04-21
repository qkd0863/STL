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
// 2024.04.16 1학기 stl				                        (7주 2)
//  
// deque - vecto와 list의 중간형태를 띄는 자료구조다
//-----------------------------------------------------------------

extern bool 관찰;

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
		return os << "글자:" << dog.c << ", 숫자" << dog.num;
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
	//문제 a에 "FileName.cpp"에 있는 단어를 저장하라
	//a를 길이 오름차순으로 정렬하라
	//화면에 a를 출력하라

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
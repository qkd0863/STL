#include <deque>
#include <vector>
#include <list>
#include <array>
#include <algorithm>
#include <fstream>
#include <numeric>
#include <random>
#include <string>
#include "String.h"
#include "save.h"


extern bool ����;



default_random_engine dre;
uniform_int_distribution uidNum{ 1,9999 };
uniform_int_distribution<int> uidChar{ 'a','z' };



//void Player::read(istream& is)
//{
//	is.read((char*)this, sizeof(Player));
//	p.release();
//	p = make_unique<char[]>(num);
//	is.read((char*)p.get(), num);
//}


template <class b ,class val>
b my_find(b begin, b end, val v)
{
	while (begin != end)
	{
		if (*begin == v)
			return begin;
		++begin;
	}
	return begin;
}


int main()
{
	String s{ "20240513 - stl container iterator algorithm" };

	// ���� ����ڰ� ã�� ���ڰ� s�� �ִ��� �˷�����

	while (1)
	{
		cout << "ã�� ���ڴ�?";
		char ch;
		cin >> ch;
		auto p = my_find(s.begin(), s.end(), ch);
		if (p != s.end())
			cout << "��ġ - " << "�� ã��" << endl;
		else
			cout << ch << "�� s�� ���� �����Դϴ�" << endl;
	}


}
#include <array>
#include <algorithm>
#include <numeric>
#include <print>
#include <thread>
#include <random>
#include <ranges>
#include "String.h"
#include "save.h"

//-----------------------------------------------------------------
// 2024.04.30 1�б� stl				                        (14�� 1)
//  
// sort ���� algorithm - ���⵵
// partition
// nth_element
// partial_sort
// sort
// stable_sort
//-----------------------------------------------------------------

extern bool ����;

random_device rd;
default_random_engine dre{ rd() };
uniform_int_distribution<int> uidC{ 'A','Z' };
uniform_int_distribution uidN{ 1,30 };

int main()
{
	save("FileName.cpp");

	struct Dog
	{
		char c = uidC(dre);
		int n{ uidN(dre) };
	};

	array<Dog, 100> dogs;

	//���� dogs�� ���� ������������ ����


	//sort(dogs.begin(), dogs.end(), [](const Dog& a, const Dog& b) {return a.c < b.c; });
	ranges::sort(dogs, {}, & Dog::c);
	ranges::stable_sort(dogs, {}, & Dog::n);	//������ �͵��� ������ �����ȴ�

	cout << endl;
	for (auto [����, ����] : dogs)
		cout << "\t" << ���� << " - " << ���� << endl;;
	
}
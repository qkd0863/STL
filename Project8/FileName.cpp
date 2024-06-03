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
// 2024.04.30 1학기 stl				                        (14주 1)
//  
// sort 관련 algorithm - 복잡도
// partition
// nth_element
// partial_sort
// sort
// stable_sort
//-----------------------------------------------------------------

extern bool 관찰;

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

	//문제 dogs를 글자 오름차순으로 정렬


	//sort(dogs.begin(), dogs.end(), [](const Dog& a, const Dog& b) {return a.c < b.c; });
	ranges::sort(dogs, {}, & Dog::c);
	ranges::stable_sort(dogs, {}, & Dog::n);	//동등한 것들의 순서가 유지된다

	cout << endl;
	for (auto [글자, 숫자] : dogs)
		cout << "\t" << 글자 << " - " << 숫자 << endl;;
	
}
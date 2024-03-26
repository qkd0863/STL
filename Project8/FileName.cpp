#include "save.h"
#include <string>
#include <array>
#include <numeric>
#include <memory>
#include <algorithm>
#include <random>
#include <print>

//-----------------------------------------------------------------
// 2024.03.26 1학기 stl 화 5~6 목 5~6                       (4주 2)
// 
// 
//-----------------------------------------------------------------

//문제 [10000, 99999] 범위의 값을 갖는 int 100개를 만들어라
// qsort를 사용하여 오름차순으로 정렬하시오
// 정렬한 결과를 화면에 출력하세요


default_random_engine dre;
uniform_int_distribution uidNum{ 1,1000 };


int static compare(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}


int main()
{
	save("FileName.cpp");	//함수 포인터 참조
	
	auto a = compare;
	cout << typeid(a).name() << endl;

}
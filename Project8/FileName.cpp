#include <array>
#include <algorithm>
#include <vector>
#include <list>
#include <ranges>
#include "String.h"
#include "save.h"

//-----------------------------------------------------------------
// 2024.04.30 1학기 stl				                        (14주 2)
//  
// 반복자간의 거리를 재는 distance 함수를 잘 알아본다
// c++20 concept / range
//-----------------------------------------------------------------

extern bool 관찰;



template<class T>
concept 숫자만 = is_integral_v<T> or is_floating_point_v<T>;

template<숫자만 T>
T add(T a, T b)
{
	return a + b;
}


int main()
{
	//문제 함수 템플릿 add를 만들어라
	//save("FileName.cpp");
	list<int> list{ 1,2,3 };
	ranges::sort(list.begin(),list.end();

}
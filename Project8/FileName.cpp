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
// 2024.04.1 1학기 stl				                        (5주 1)
// 
// 
// callable type - 무한개의 타입이 있다
// 어떤 함수에 다른 함수를 전달한다
// sort할 때 어떤 기준으로 정렬할지를 어떻게 sort함수에게 알려주나?
// 1. 함수 포인터를 전달한다
// 2. 람다를 전달한다 - visual studio는 함수 객체로 구현
// 3. ()연산자를 오버로딩한 클래스의 객체를 전달한다 (funtion call - () )
//  함수 객체(function object)
// 1과 2,3의 다른점 - 2,3은 상태를 가질 수 있다
// 
// 호출가능한 타입을 대표하는 타입을 만들었다 - function 
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
	String s{ "STL을 관찰하기 위한 클래스입니다" };
	//String t = s;
	cout << s << endl;
	//cout << t << endl;
}




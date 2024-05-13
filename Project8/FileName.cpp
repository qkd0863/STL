#include <string>
#include "String.h"
#include "save.h"

//-----------------------------------------------------------------
// 2024.04.30 1학기 stl				                        (11주 1)
//  
// 알고리즘 함수는 반복자를 인자로 받는다
// 
//-----------------------------------------------------------------

extern bool 관찰;

//template<class 반복자,class 값>
//반복자 my_find(반복자 begin, 반복자 end, 값 val)
//{
//	return begin
//};

int main()	
{
	save("FileName.cpp");
	
	String s{ "20240513 - stl container iterator algorithm" };
	
	// 문제 사용자가 찾는 글자가 s에 있는지 알려주자

	while (1)
	{
		cout << "찾을 문자는?";
		char ch;
	/*	auto p = my_find(s.begin(), s.end(), ch);
		if (p != s.end())
			cout << "위치 - " << "을 찾음" << endl;
		else
			cout << ch << "는 s에 없는 글자입니다" << endl;*/
	}
}                
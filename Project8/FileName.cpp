#include "save.h"
#include <string>
#include <array>
#include <numeric>
//-----------------------------------------------------------------
// 2024.03.25 1학기 stl 화 5~6 목 5~6                       (4주 1)
// 
// 메모리 동적할당 - RAII
// 
// 앞으로 c++ 에서 사용하지 않아야 할 것들
// char*  -> string 
// T[N]  -> array<T,N>
// T*    -> unique_ptr, shared_ptr( 스마트 포인터로 대체)
//-----------------------------------------------------------------


// 문제 사용자가 입력한 int num 만큼 메모리를 동적할당하라
// int를 num개 동적할당한다
// 이 메모리를 1부터 시작하는 정수로 채운다
// 이 메모리의 합계를 화면에 출력한다
// 이 모든 과정을 영원히 반복하라

// -> run-time에서야 num값이 결정된다 --> new T[num]
// -> complie time에 모든 값이 결정 --> constexpr

class Dog
{
public:
	Dog() { cout << "생성" << endl; }
	~Dog() { cout << "소멸" << endl; }
};


// RAII idiom(관용구) - 메모리, 파일, jthread

class Smart_ptr
{
	Dog* p;
public:
	Smart_ptr(Dog* p):p{p}{}
	~Smart_ptr()
	{
		delete p;
	}
};

void f() 
{
	cout << "f 시작" << endl;
	
	{//예외 발생
		Smart_ptr p{ new Dog };	// stack-unwinding   c++ 언어가 보장
		throw 1234;		// catch 라인으로 이동
	}


	cout << "f 종료" << endl;
};

int main()
{
	save("FileName.cpp");
	cout << "메인 시작" << endl;

	try
	{
		f();// 자원을 확보하고 정리하는 함수
	}
	catch (...)
	{

	}

	cout << "메인 끝" << endl;
}




// 메모리 해제를 까먹음
// 메모리를 여러번 해제함 - dangling 프로그램이 바로 죽는다
// 지역을 벗어나면 반드시 소멸한다 - 연결시켜줘야한다
// 예외 처리가되면 소멸이 안될 수 있다

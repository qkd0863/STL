//-----------------------------------------------------------------------------------------------------------------------------------------
// String.h		STL 동작을 관찰하기 위한 클래스
// 
// 2024 4/2 시작
//-----------------------------------------------------------------------------------------------------------------------------------------

#pragma once
#include <memory>
#include <iostream>

class String
{
	size_t len{};
	std::unique_ptr<char[]> p;
	size_t id{};
public:
	// 디폴트 생성자 - 2024 4 2
	String();

	String(const char* s);
	~String();	//소멸자는 관찰하려고 코딩하였다 2024 4 2

	// 복사생성과 복사할당 - 2024 4 2
	String(const String&);
	String& operator=(const String&);


	// 이동생성과 이동할당 2024 4 2
	// 예외를 던지지 않음을 보장 noexcept 2024 4 15
	String(String&&)noexcept;
	String& operator=(String&&)noexcept;



	//sort에서 필요한 getLen 2024 4 2
	size_t getLen()const; 
	//p가 가리키는 메모리를 알려준다 2024 4 2
	char* getMem() const;

	friend std::ostream& operator<<(std::ostream& os, const String& str)
	{
		for (size_t i = 0; i < str.len; ++i)
			os << str.p.get()[i];
		return os;
	}

	// 2024 4 9 
	friend std::istream& operator>>(std::istream& is, String& s);

private:
	static size_t uid;
};

#include <algorithm>		//2024 4 16
#include "String.h"
//-----------------------------------------------------------------------------------------------------------------------------------------
// String.cpp		STL 동작을 관찰하기 위한 클래스
// 
// 2024 4/2 시작
// 2024 4 15 noexecpt
// 2024 4 16 operator==
// 2024 4 30 <
//-----------------------------------------------------------------------------------------------------------------------------------------





// 관찰용 변수 추가 2024 4 2
bool 관찰{ false };		//관찰을 원하면 true로 바꾸자

size_t String::uid{  };			//class static 변수 초기화

// 디폴트 생성자 - 2024 4 2
String::String() :id{ ++uid }
{
	if(관찰)
		std::cout << "[" << id << "] - 생성(), 길이 - " << len << ", 주소 - " << (void*)p.get() << std::endl;
}

// 생성자
String::String(const char* s) :len(strlen(s)), id{ ++uid }
{
	p = std::make_unique<char[]>(len);
	memcpy(p.get(), s, len);
	if (관찰)
		std::cout << "[" << id << "] - 생성(char*), 길이 - " << len << ", 주소 - " << (void*)p.get() << std::endl;
}


//소멸자는 관찰하려고 코딩하였다 2024 4 2
String::~String()
{
	if (관찰)
		std::cout << "[" << id << "] - 소멸(char*), 길이 - " << len << ", 주소 - " << (void*)p.get() << std::endl;
}


// 복사생성과 복사할당 - 2024 4 2
String::String(const String& other) :len(other.len), id{ ++uid }
{
	p = std::make_unique<char[]>(len);
	memcpy(p.get(), other.p.get(), len);
	
	if (관찰)
		std::cout << "[" << id << "] - 복사생성(char*), 길이 - " << len << ", 주소 - " << (void*)p.get() << std::endl;
}

String& String::operator=(const String& rhs)
{
	if (this == &rhs)
		return *this;

	p.release();
	
	len = rhs.len;
	p = std::make_unique<char[]>(len);
	memcpy(p.get(), rhs.p.get(), len);
	if (관찰)
		std::cout << "[" << id << "] - 복사할당(char*), 길이 - " << len << ", 주소 - " << (void*)p.get() << std::endl;
	return *this;
}



// 이동생성과 이동할당 2024 4 2
// 예외를 던지지 않음을 보장 noexcept 2024 4 15
String::String(String&& other)noexcept :len(other.len), id{ ++uid }
{
	p.reset(other.p.release());
	if (관찰)
		std::cout << "[" << id << "] - 이동생성, 길이 - " << len << ", 주소 - " << (void*)p.get() << std::endl;
}

String& String::operator=(String&& other)noexcept
{
	if (this == &other)
		return *this;

	p.reset();
	len = other.len;

	p.reset(other.p.release());
	if (관찰)
		std::cout << "[" << id << "] - 이동할당, 길이 - " << len << ", 주소 - " << (void*)p.get() << std::endl;

	return *this;
}



size_t String::getLen() const
{
	return len;
}

char* String::getMem() const
{
	return p.get();
}

//2024 4 16 operator==
bool String::operator==(const String& rhs) const
{
	if (len != rhs.len)
		return false;
	return std::equal(p.get(), p.get() + len, rhs.p.get());
}
//2024 4 30 <
bool String::operator<(const String& rhs) const
{
	return std::lexicographical_compare(p.get(), p.get() + len, rhs.p.get(), rhs.p.get() + rhs.len);
}


//2024 4 9
std::istream& operator>>(std::istream& is, String& s)
{
	std::string ts;
	is >> ts;

	s.len = ts.size();
	s.p = std::make_unique<char[]>(s.len);
	memcpy(s.p.get(), ts.data(), s.len);



	return is;
}

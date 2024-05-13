//-----------------------------------------------------------------------------------------------------------------------------------------
// String.h		STL 동작을 관찰하기 위한 클래스
// 
// 2024 4/2 시작
// 2024 4 15 noexecpt
// 2024 4 16 operator==
// 2024 4 30 operator< 
// 2024 5 7  begin() end()
// 2024 5 7  rbegin() rend()의 결과는 class 객체이어야 한다
// 2024 5 13 String iterator가 진짜 random_access 반복자가 되도록 코딩
//-----------------------------------------------------------------------------------------------------------------------------------------

#pragma once
#include <memory>
#include <iostream>

//String이 리턴하는 반복자 - iterator
class String_iterator
{
public:
	using difference_type = ptrdiff_t;
	using value_type = char;
	using pointer = char*;
	using reference = char&;
	using iterator_category = std::random_access_iterator_tag;

	using iterator_concept = std::contiguous_iterator_tag;

private:
	char* p;
public:
	String_iterator(char* p) :p{ p } {}


	char* operator++()
	{
		return ++p;
	}

	bool operator==(const String_iterator& rhs)const
	{
		return p == rhs.p;
	}

	// 2024 5 13
	difference_type operator-(const String_iterator& rhs)const
	{
		return p - rhs.p;
	}

	reference operator*()
	{
		return *p;
	}

	reference operator*()const 
	{
		return *p;
	}

	String_iterator& operator--()
	{
		--p;
		return *this;
	}

	String_iterator operator+(difference_type d)const
	{
		return p + d;
	}

	bool operator<(const String_iterator& rhs)const
	{
		return p < rhs.p;
	}


	String_iterator operator-(difference_type d)const
	{
		return p - d;
	}

};

//역방향 반복자 - iterator adaptor
class String_reverse_iterator
{
public:
	using difference_type = int;
	using value_type = char;
	using pointer = char*;
	using reference = char&;
	using iterator_category = std::random_access_iterator_tag;

	using iterator_concept = std::contiguous_iterator_tag;

private:
	char* p;
public:
	String_reverse_iterator(char* p) :p{ p } {}


	char* operator++()
	{
		return --p;
	}
	char operator*()const 
	{
		return *(p - 1);
	}

	bool operator==(const String_reverse_iterator& rhs)const
	{
		return p == rhs.p;
	}

};


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

	// 2024 5 7
	String_iterator begin()const { return String_iterator{ p.get() }; };
	String_iterator end()const {return String_iterator{p.get()+len}; };
	String_reverse_iterator rbegin()const { return String_reverse_iterator{ p.get() + len }; };
	String_reverse_iterator rend()const { return String_reverse_iterator{ p.get() }; };
	
	friend std::ostream& operator<<(std::ostream& os, const String& str)
	{
		for (size_t i = 0; i < str.len; ++i)
			os << str.p.get()[i];
		return os;
	}

	// 2024 4 9 
	friend std::istream& operator>>(std::istream& is, String& s);

	// 2024 4 16 operator==
	bool operator==(const String& rhs)const;
	
	// 2024 4 30 <
	bool operator<(const String& rhs)const;


	
private:
	static size_t uid;
};

//-----------------------------------------------------------------------------------------------------------------------------------------
// String.h		STL ������ �����ϱ� ���� Ŭ����
// 
// 2024 4/2 ����
// 2024 4 15 noexecpt
// 2024 4 16 operator==
// 2024 4 30 operator< 
// 2024 5 7  begin() end()
// 2024 5 7  rbegin() rend()�� ����� class ��ü�̾�� �Ѵ�
// 2024 5 13 String iterator�� ��¥ random_access �ݺ��ڰ� �ǵ��� �ڵ�
//-----------------------------------------------------------------------------------------------------------------------------------------

#pragma once
#include <memory>
#include <iostream>

//String�� �����ϴ� �ݺ��� - iterator
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

//������ �ݺ��� - iterator adaptor
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
	// ����Ʈ ������ - 2024 4 2
	String();

	String(const char* s);
	~String();	//�Ҹ��ڴ� �����Ϸ��� �ڵ��Ͽ��� 2024 4 2

	// ��������� �����Ҵ� - 2024 4 2
	String(const String&);
	String& operator=(const String&);


	// �̵������� �̵��Ҵ� 2024 4 2
	// ���ܸ� ������ ������ ���� noexcept 2024 4 15
	String(String&&)noexcept;
	String& operator=(String&&)noexcept;



	//sort���� �ʿ��� getLen 2024 4 2
	size_t getLen()const; 
	//p�� ����Ű�� �޸𸮸� �˷��ش� 2024 4 2
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

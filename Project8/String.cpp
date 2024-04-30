#include <algorithm>		//2024 4 16
#include "String.h"
//-----------------------------------------------------------------------------------------------------------------------------------------
// String.cpp		STL ������ �����ϱ� ���� Ŭ����
// 
// 2024 4/2 ����
// 2024 4 15 noexecpt
// 2024 4 16 operator==
// 2024 4 30 <
//-----------------------------------------------------------------------------------------------------------------------------------------





// ������ ���� �߰� 2024 4 2
bool ����{ false };		//������ ���ϸ� true�� �ٲ���

size_t String::uid{  };			//class static ���� �ʱ�ȭ

// ����Ʈ ������ - 2024 4 2
String::String() :id{ ++uid }
{
	if(����)
		std::cout << "[" << id << "] - ����(), ���� - " << len << ", �ּ� - " << (void*)p.get() << std::endl;
}

// ������
String::String(const char* s) :len(strlen(s)), id{ ++uid }
{
	p = std::make_unique<char[]>(len);
	memcpy(p.get(), s, len);
	if (����)
		std::cout << "[" << id << "] - ����(char*), ���� - " << len << ", �ּ� - " << (void*)p.get() << std::endl;
}


//�Ҹ��ڴ� �����Ϸ��� �ڵ��Ͽ��� 2024 4 2
String::~String()
{
	if (����)
		std::cout << "[" << id << "] - �Ҹ�(char*), ���� - " << len << ", �ּ� - " << (void*)p.get() << std::endl;
}


// ��������� �����Ҵ� - 2024 4 2
String::String(const String& other) :len(other.len), id{ ++uid }
{
	p = std::make_unique<char[]>(len);
	memcpy(p.get(), other.p.get(), len);
	
	if (����)
		std::cout << "[" << id << "] - �������(char*), ���� - " << len << ", �ּ� - " << (void*)p.get() << std::endl;
}

String& String::operator=(const String& rhs)
{
	if (this == &rhs)
		return *this;

	p.release();
	
	len = rhs.len;
	p = std::make_unique<char[]>(len);
	memcpy(p.get(), rhs.p.get(), len);
	if (����)
		std::cout << "[" << id << "] - �����Ҵ�(char*), ���� - " << len << ", �ּ� - " << (void*)p.get() << std::endl;
	return *this;
}



// �̵������� �̵��Ҵ� 2024 4 2
// ���ܸ� ������ ������ ���� noexcept 2024 4 15
String::String(String&& other)noexcept :len(other.len), id{ ++uid }
{
	p.reset(other.p.release());
	if (����)
		std::cout << "[" << id << "] - �̵�����, ���� - " << len << ", �ּ� - " << (void*)p.get() << std::endl;
}

String& String::operator=(String&& other)noexcept
{
	if (this == &other)
		return *this;

	p.reset();
	len = other.len;

	p.reset(other.p.release());
	if (����)
		std::cout << "[" << id << "] - �̵��Ҵ�, ���� - " << len << ", �ּ� - " << (void*)p.get() << std::endl;

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

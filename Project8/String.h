//-----------------------------------------------------------------------------------------------------------------------------------------
// String.h		STL ������ �����ϱ� ���� Ŭ����
// 
// 2024 4/2 ����
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

#include "save.h"
#include <string>
#include <array>
#include <numeric>
//-----------------------------------------------------------------
// 2024.03.25 1�б� stl ȭ 5~6 �� 5~6                       (4�� 1)
// 
// �޸� �����Ҵ� - RAII
// 
// ������ c++ ���� ������� �ʾƾ� �� �͵�
// char*  -> string 
// T[N]  -> array<T,N>
// T*    -> unique_ptr, shared_ptr( ����Ʈ �����ͷ� ��ü)
//-----------------------------------------------------------------


// ���� ����ڰ� �Է��� int num ��ŭ �޸𸮸� �����Ҵ��϶�
// int�� num�� �����Ҵ��Ѵ�
// �� �޸𸮸� 1���� �����ϴ� ������ ä���
// �� �޸��� �հ踦 ȭ�鿡 ����Ѵ�
// �� ��� ������ ������ �ݺ��϶�

// -> run-time������ num���� �����ȴ� --> new T[num]
// -> complie time�� ��� ���� ���� --> constexpr

class Dog
{
public:
	Dog() { cout << "����" << endl; }
	~Dog() { cout << "�Ҹ�" << endl; }
};


// RAII idiom(���뱸) - �޸�, ����, jthread

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
	cout << "f ����" << endl;
	
	{//���� �߻�
		Smart_ptr p{ new Dog };	// stack-unwinding   c++ �� ����
		throw 1234;		// catch �������� �̵�
	}


	cout << "f ����" << endl;
};

int main()
{
	save("FileName.cpp");
	cout << "���� ����" << endl;

	try
	{
		f();// �ڿ��� Ȯ���ϰ� �����ϴ� �Լ�
	}
	catch (...)
	{

	}

	cout << "���� ��" << endl;
}




// �޸� ������ �����
// �޸𸮸� ������ ������ - dangling ���α׷��� �ٷ� �״´�
// ������ ����� �ݵ�� �Ҹ��Ѵ� - �����������Ѵ�
// ���� ó�����Ǹ� �Ҹ��� �ȵ� �� �ִ�

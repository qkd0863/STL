#include "save.h"
#include <random>
#include <format>
#include <print>
#include <array>
#include <numeric>


//���� ���� "int100�����޸𸮱״������.txt"��
// int�� 100���� wrtie �Լ��� ����Ͽ� ��ϵǾ� �ִ�
// ������ binary ���� ���� ����Ͽ���
// ���Ͽ� ��ϵ� int�� 100���� �޸𸮷� �о�� �� 
// ȭ�鿡 ����϶�


default_random_engine dre;
uniform_int_distribution<int> uidChar{ 'a','z' };
uniform_int_distribution uidNum{ 1,99999 };

class Dog
{
	char c{ (char)uidChar(dre) };
	int num{ uidNum(dre) };
public:
	Dog()
	{
		//cout << "����Ʈ ����" << endl;
	}
	friend ostream& operator<<(ostream& os, const Dog& dog)
	{
		return os << "����:" << dog.c << ", ����" << dog.num;
	}
};



int main()
{
	array<Dog, 100> dogs;		//�ʱ�ȭ ���ص� ����Ʈ ������


	// ���� dogs�� binary mode/write �� ���Ͽ� ����϶�
	// ��ϵ� ������ �о num���� ���� ū dog�� ã�� ȭ�鿡 ����϶�

	ofstream out{ "Dog.txt",ios::binary };
	out.write((const char*)dogs.data(), sizeof(Dog) * 100);

	for (Dog dog : dogs)
		cout << dog << endl;

	cout << endl << endl;


	array<Dog, 100> dogs_read{};

	ifstream in{ "Dog.txt",ios::binary };
	if (not in)
	{
		cout << "���Ͽ��� ����";
		exit(0);
	}




	in.read((char*)dogs_read.data(), sizeof(Dog) * 100);
	for (Dog dog : dogs_read)
		cout << dog << endl;


	//auto pos = max_element(dogs_read.begin(), dogs_read.end());
	//cout << "�ִ�:" << *pos << endl;



	save("FileName.cpp");
}
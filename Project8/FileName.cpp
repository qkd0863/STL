#include "save.h"
#include <random>
#include <format>
#include <print>
#include <array>
#include <numeric>


//-----------------------------------------------------------------
// 2024.03.018 1�б� stl ȭ 5~6 �� 5~6                       (3�� 1)
// 
//-----------------------------------------------------------------



//���� ���� "int100�����޸𸮱״������.txt"��
// int�� 100���� wrtie �Լ��� ����Ͽ� ��ϵǾ� �ִ�
// ������ binary ���� ���� ����Ͽ���
// ���Ͽ� ��ϵ� int�� 100���� �޸𸮷� �о�� �� 
// ȭ�鿡 ����϶�


default_random_engine dre;
uniform_int_distribution<int> uidChar{ 'a','z' };
uniform_int_distribution uidNum{ 1,99999 };


// ���� "Dog.txt" ������ binary ���� ��ϵǾ���
// ���⿡�� �� ������ �𸣴� class Dog ��ü�� write �Լ��� ����Ͽ� ����Ͽ���
// class Dog�� ����� ������ ����
// ������ �о� num���� 1000�̸��� Dog ��ü�� ȭ�鿡 ����϶�

class Dog
{
	char c;
	int num;
public:
	int getN()const 
	{
		return num;
	}
	void show()const
	{
		cout << "char - " << c << ", num - " << num << endl;
	}
	friend istream& operator>>(istream& is, Dog& dog)
	{
		return is.read((char*)&dog, sizeof(Dog));
	}
	
};

int main()
{
	

	ifstream in{ "Dog.txt",ios::binary };
	if (not in)
	{
		cout << "���� ���� ����" << endl;
		exit(0);
	}
	

	//������ Dog   char - i, num - 38857
	//���� ū Dog:char - y, num - 99646

	array<Dog, 100> dogs_read;
	in.read((char*)dogs_read.data(), sizeof(Dog) * 100);
	for (Dog d : dogs_read)
		d.show();
	
	
	auto pos=max_element(dogs_read.begin(), dogs_read.end(), [](const Dog& a, const Dog& b) {return a.getN() < b.getN(); });
	//begin=a end=b, b-a == 800  -> a�� type�� ����? -> a�� type���� ������ ������ �˾Ƴ���
	
	cout << "num ���� ���� ū Dog:";
	pos->show();

	auto p = count_if(dogs_read.begin(), dogs_read.end(), [](const Dog& dog) {return  dog.getN() & 1; }); //���ڴ� ���ʿ� ����
	cout << p;

	int cnt{};
	for (Dog d : dogs_read)
		if (d.getN() < 1000)
			cnt++;
		
	cout << "num ���� 1000 �̸��� ����:" << cnt << endl;





	//save("FileName.cpp");
}




//Dog dog;
//int count{};
//while (in >> dog)
//count++;
//cout << "����:" << count << endl;
//dog.show();


// dogs.data() == �����ּ�
#include <deque>
#include <vector>
#include <list>
#include <array>
#include <algorithm>
#include <fstream>
#include <numeric>
#include <random>
#include <string>
#include "String.h"
#include "save.h"

//-----------------------------------------------------------------
// 2024.04.16 1�б� stl				                        (7�� 2)
//  
// deque - vecto�� list�� �߰����¸� ��� �ڷᱸ����
//-----------------------------------------------------------------

extern bool ����;

class Test
{
	char x[4096];
};


default_random_engine dre;
uniform_int_distribution uidNum{ 1,9999 };
uniform_int_distribution<int> uidChar{ 'a','z' };

class Dog
{
	char c{ (char)uidChar(dre) };
	int num{ uidNum(dre) };
public:
	int getN()const { return num; }

	void show()const
	{
		cout << c << " - " << num << endl;
	}

	friend ostream& operator<<(ostream& os, const Dog& dog)
	{
		return os << "����:" << dog.c << ", ����" << dog.num;
	}

	friend bool operator<(const Dog& lhs, const Dog& rhs)
	{
		return lhs.num < rhs.num;
	}


	friend istream& operator>>(istream& is, Dog& dog)
	{
		return is.read((char*)&dog, sizeof(Dog));
	}


};



void saveArrayToBinaryFile(const array<array<Dog, 100>, 100>& d, const string& filename)
{
	ofstream file(filename, ios::binary);

	if (file.is_open())
	{
		for (const auto& row : d)
		{
			for (const auto& dog : row)
			{
				file.write(reinterpret_cast<const char*>(&dog), sizeof(Dog));
			}
		}

		file.close();
		cout << "Saved to " << filename << " successfully!" << endl;
	}
	else
	{
		cout << "Failed to open file " << filename << " for writing!" << endl;
	}
}
void loadArrayFromBinaryFile(array<array<Dog, 100>, 100>& d, const string& filename)
{
	ifstream file(filename, ios::binary);

	if (file.is_open())
	{
		for (auto& row : d)
		{
			for (auto& dog : row)
			{
				file >> dog;
			}
		}

		file.close();
		cout << "Loaded from " << filename << " successfully!" << endl;
	}
	else
	{
		cout << "Failed to open file " << filename << " for reading!" << endl;
	}
}
void sortArray(array<Dog, 100>& arr)
{
	sort(arr.begin(), arr.end());
}
void sortArrayOfArrays(array<array<Dog, 100>, 100>& d)
{
	for (auto& arr : d)
	{
		sortArray(arr);
	}
}



int main()
{
	//���� a�� "FileName.cpp"�� �ִ� �ܾ �����϶�
	//a�� ���� ������������ �����϶�
	//ȭ�鿡 a�� ����϶�
	
	

	array<int, 26> alpha{};


	char c;

	ifstream in{ "Dog.txt",ios::binary };


	array<Dog, 100>read;
	
	Dog temp;
	int count = 1;
	in.read((char*)read.data(), sizeof(Dog) * read.size());


	sort(read.begin(), read.end(), [](const Dog& a, const Dog& b) {return a.getN() < b.getN(); });
	cout << "N �� �� - " << accumulate(read.begin(), read.end(), 0LL, [](long long sum, Dog& d) {return sum + d.getN(); }) << endl;

	for (const Dog& d : read)
		cout << d << endl;
}
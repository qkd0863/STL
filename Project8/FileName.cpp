#include "save.h"
#include <random>
#include <format>
#include <print>
#include <array>
#include <numeric>


//문제 파일 "int100개를메모리그대로저장.txt"에
// int값 100개가 wrtie 함수를 사용하여 기록되어 있다
// 파일은 binary 모드로 열어 기록하였다
// 파일에 기록된 int값 100개를 메모리로 읽어온 후 
// 화면에 출력하라


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
		//cout << "디폴트 생성" << endl;
	}
	friend ostream& operator<<(ostream& os, const Dog& dog)
	{
		return os << "글자:" << dog.c << ", 숫자" << dog.num;
	}
};



int main()
{
	array<Dog, 100> dogs;		//초기화 안해도 디폴트 생성됨


	// 문제 dogs를 binary mode/write 로 파일에 기록하라
	// 기록된 파일을 읽어서 num값이 가장 큰 dog를 찾아 화면에 출력하라

	ofstream out{ "Dog.txt",ios::binary };
	out.write((const char*)dogs.data(), sizeof(Dog) * 100);

	for (Dog dog : dogs)
		cout << dog << endl;

	cout << endl << endl;


	array<Dog, 100> dogs_read{};

	ifstream in{ "Dog.txt",ios::binary };
	if (not in)
	{
		cout << "파일열기 실패";
		exit(0);
	}




	in.read((char*)dogs_read.data(), sizeof(Dog) * 100);
	for (Dog dog : dogs_read)
		cout << dog << endl;


	//auto pos = max_element(dogs_read.begin(), dogs_read.end());
	//cout << "최댓값:" << *pos << endl;



	save("FileName.cpp");
}
#include "save.h"
#include <random>
#include <format>
#include <print>
#include <array>
#include <numeric>


//-----------------------------------------------------------------
// 2024.03.018 1학기 stl 화 5~6 목 5~6                       (3주 1)
// 
//-----------------------------------------------------------------



//문제 파일 "int100개를메모리그대로저장.txt"에
// int값 100개가 wrtie 함수를 사용하여 기록되어 있다
// 파일은 binary 모드로 열어 기록하였다
// 파일에 기록된 int값 100개를 메모리로 읽어온 후 
// 화면에 출력하라


default_random_engine dre;
uniform_int_distribution<int> uidChar{ 'a','z' };
uniform_int_distribution uidNum{ 1,99999 };


// 문제 "Dog.txt" 파일은 binary 모드로 기록되었다
// 여기에는 몇 개인지 모르는 class Dog 객체를 write 함수를 사용하여 기록하였다
// class Dog의 멤버는 다음과 같다
// 파일을 읽어 num값이 1000미만인 Dog 객체를 화면에 출력하라

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
		cout << "파일 열기 실패" << endl;
		exit(0);
	}
	

	//마지막 Dog   char - i, num - 38857
	//가장 큰 Dog:char - y, num - 99646

	array<Dog, 100> dogs_read;
	in.read((char*)dogs_read.data(), sizeof(Dog) * 100);
	for (Dog d : dogs_read)
		d.show();
	
	
	auto pos=max_element(dogs_read.begin(), dogs_read.end(), [](const Dog& a, const Dog& b) {return a.getN() < b.getN(); });
	//begin=a end=b, b-a == 800  -> a의 type이 뭐야? -> a의 type으로 나눠서 개수를 알아낸다
	
	cout << "num 값이 가장 큰 Dog:";
	pos->show();

	auto p = count_if(dogs_read.begin(), dogs_read.end(), [](const Dog& dog) {return  dog.getN() & 1; }); //숫자는 왼쪽에 쓰자
	cout << p;

	int cnt{};
	for (Dog d : dogs_read)
		if (d.getN() < 1000)
			cnt++;
		
	cout << "num 값이 1000 미만인 개수:" << cnt << endl;





	//save("FileName.cpp");
}




//Dog dog;
//int count{};
//while (in >> dog)
//count++;
//cout << "개수:" << count << endl;
//dog.show();


// dogs.data() == 시작주소
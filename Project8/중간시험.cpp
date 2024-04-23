//-----------------------------------------------------------------------------
// 2024 STL 중간시험
// 
// Visual Studio 버전 17.9.0 이상 
// Release / x64
// 프로젝트 속성 - C++ 언어 표준 - 최신 C++ 초안의 기능(/std:c++latest)
//-----------------------------------------------------------------------------
// 답지 작성 방법
// - 각 문제를 해결하는 데 필요한 코드만 적는다.
// - 화면에 출력을 요구하는 문제는 출력된 내용을 답지에 적는다.
// - 헤더 파일을 적을 필요는 없다.
//-----------------------------------------------------------------------------

#include <algorithm>
#include <array>
#include <deque>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <list>
#include <print>
#include <random>
#include <string>
#include <vector>
using namespace std;

default_random_engine dre;
uniform_int_distribution uidNum{ 1, 1'000 };
uniform_int_distribution uid{ 1, 999'999 };

//-----------------------------------------------------------------------------
// class Dog은 num개의 int값을 array a에 저장하고 있다.
//-----------------------------------------------------------------------------
// file "개들"에는 몇 개인지 모르는 Dog 객체가 기록되어 있다
// file은 binary mode로 열어 Dog의 멤버함수 write를 사용하여 기록하였다.
//-----------------------------------------------------------------------------
// (참고) class의 멤버를 추가하지 않아도 여기에 있는 모든 문제를 풀 수 있다.
//-----------------------------------------------------------------------------

//----------
// class Dog
//----------

class Dog {
private:
	int num{};							// [1, 1000] random 값
	array<int, 1'000> a{};				// 여기에 num개의 int 값이 저장된다

public:
	Dog( ) = default;

	Dog( int num ) : num{ num } {		// 파일을 읽지 못한 경우 사용할 생성자
		for (int i = 0; i < num; ++i)
			a[i] = uid( dre );
	}

	int getNum( ) const {
		return num;
	}

	int* getData( ) const {
		return const_cast<int*>(a.data());
	}

	void show( ) const {
		cout << "저장하고 있는 int 개수 - " << num << endl;
		for (int i = 0; i < num; ++i)
			print( "{:8}", a[i] );
		cout << endl;
	}

	void write( ostream& os ) {
		os.write( (const char*)(this), sizeof( *this ) );
	}
};


//---------
int main( )
//---------
{
	//------------------------------------------------------------
	// 이 파일을 그대로 실행하면 오류없이 실행될 것이다. 
	// 실행되는지 확인하고 문제를 해결하자. 
	//------------------------------------------------------------
	string inFileName{ "개들" };
	ifstream in{ inFileName, ios::binary };

	if (not in) {
		cout << inFileName << "을 열 수 없습니다" << endl;
		return 0;
	}

	size_t fileSize = filesystem::file_size( inFileName );
	cout << "파일 \"" << inFileName << "\"의 크기는 " << fileSize << " 바이트 입니다" << endl;

	{
		// 실행 확인용 코드
		Dog dog{ 23 };
		dog.show( );

		// 화면 출력(예)
		// 저장하고 있는 int 개수 - 23
		//	814723  135477  905792  835008  126987  968867  913375  221034  632359  308167
		//	 97541  547221  278498  188382  546881  992881  957506  996461  964888  967694
		//	157613  725839  970592
	}

	//--------------------------------------------------------------------------
	// [문제 1] 파일에 저장된 Dog 객체가 모두 몇 개인지 화면에 출력하라.	(10)
	//--------------------------------------------------------------------------
	// (주의) Compile-time에는 Dog 객체의 수를 알 수 없다.
	// Dog 객체가 몇 개인지 계산하여 출력하는 코드를 답지에 쓴다.
	// 화면에 출력된 개수도 답지에 쓴다.
	//--------------------------------------------------------------------------
	int dogNum{};				// 여기에 Dog 객체의 개수를 저장한다
	dogNum = fileSize / sizeof(Dog);
	cout << "Dog 객체의 수 - " << dogNum << endl;



	//--------------------------------------------------------------------------
	// [문제 2] 파일에 있는 Dog 객체를 컨테이너에 저장하라.                  
	// 마지막 Dog 객체의 num 값을 화면에 출력하라.							(20) 
	//--------------------------------------------------------------------------
	// 컨테이너에 저장하기 위해 추가한 코드도 답지에 적는다.
	// Dog의 멤버를 추가하여 문제를 해결하면 감점한다.
	// 화면에 출력된 num 값을 답지에 쓴다.
	//--------------------------------------------------------------------------
	vector<Dog> D(dogNum);
	in.read((char*)D.data(), sizeof(Dog) * dogNum);
	cout << D.back().getNum() << endl;



	//**************************************************************************
	// 파일에 있는 Dog를 읽지 못한 학생은 아래 주석을 제거한 후 
	// [문제 3] [문제 4]의 답을 구하라.
	// [문제 2]를 해결하지 못한것으로 인한 감점 없음
	//**************************************************************************

	// 파일을 읽지 못했다면 주석을 풀어 다음 코드를 사용하여 진행하면 된다.
	/* 
		dogNum = 1234;
		vector<Dog> v;
		v.reserve( 1234 );
		for ( int i = 0; i < 1'234; ++i )
		v.emplace_back( uidNum(dre) );

	*/

	//--------------------------------------------------------------------------
	// [문제 3] Dog 객체를 num 기준 오름차순으로 정렬하라.				   	
	// 정렬 알고리즘이 비교함수를 몇 번 호출하였는지 화면에 출력하라.		(20)
	//--------------------------------------------------------------------------
	// 문제를 해결하는 코드를 답지에 적어라.
	// 화면에 출력된 호출횟수를 답지에 적어라.
	//--------------------------------------------------------------------------

	static int count = 0;
	sort(D.begin(), D.end(), [](const Dog& a, const Dog& b) { count++; return a.getNum() < b.getNum(); });
	cout << count << endl;




	//--------------------------------------------------------------------------
	// [문제 4] 각 Dog 객체가 저장한 num개 int 값들의 평균값을 계산하여,  
	// 평균값이 가장 큰 Dog 객체의 정보를 화면에 출력하라.	
	// 화면에 출력된 Dog 객체의 num 값을 답지에 적어라.						(20)
	//--------------------------------------------------------------------------
	// 문제를 해결하는 코드를 답지에 적는다.
	// 화면에 출력된 num 값을 답지에 쓴다.
	//--------------------------------------------------------------------------
	int max = 0;
	for (const Dog& d : D)
	{
		int sum = 0;
		for (int i = 0; i < d.getNum(); ++i)
			sum += d.getData()[i];		
		sum / d.getNum();
		if (sum > max)
			max = sum;
	}
	
	cout << max << endl;//508513398
	for (const Dog& d : D)
	{
		long long sum = 0;
		for (int i = 0; i < d.getNum(); ++i)
			sum += d.getData()[i];
		sum / d.getNum();
		if (sum == max)
			cout << d.getNum();
	}

	
	


	//--------------------------------------------------------------------------
	// [문제 5] 이 시험에서는 int 값을 메모리 크기 그대로 파일에 기록하였다.
	// 만일 int 값을 글자로 기록한다면 한 개의 int를 기록하기 위해 필요한 
	// 메모리는 평균 몇 바이트일까 알고 싶다.
	// 
	// 예시)  int값         글자로 저장            메모리크기대로 저장 
	//		   -12345           6                           4
	//         -100             4                           4
	//          0			    1							4
	//		    123				3							4
	//			123456			6							4
	//			2140000000      10							4
	// 
	// 우리 컴파일 환경에서 int가 표현할 수 있는 모든 값을 글자로 저장한다면
	// 평균 몇 바이트가 필요한 지 소수점 2자리 까지 출력하라.				(40)
	//--------------------------------------------------------------------------
	// 문제를 해결하는 코드를 답지에 적는다.
	// 출력된 평균값도 답지에 적는다.
	// (힌트) 전역함수 to_string()은 int를 string으로 변환한다.
	//--------------------------------------------------------------------------

	long long M = 0;
	for (int i =  -2147483647; i < INT_MAX; ++i)
		M += to_string(i).length();
	M / (float)((long long)INT_MAX - (long long)INT_MIN + 1);

	cout << M;

}
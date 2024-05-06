#include <forward_list>
#include <list>
#include <deque>
#include <vector>
#include <iterator>
#include "save.h"
#include "String.h"
//-----------------------------------------------------------------
// 2024.04.30 1학기 stl				                        (10주 1)
//  
// iterator -iterator are a generalization of pointers
// 포인터를 일반화 한 것이 반복자다. 이걸 사용하면 자료구조가 뭔지
// 신경쓸 필요없이 동일한 방식으로 코딩할 수 있다
//-----------------------------------------------------------------

extern bool 관찰;


template <class 반복자>
void f(반복자 iter)
{
	//c++17 이후
	// 벡터만 컴파일 통과
	// 다른 컨테이너는 실패 - SFINAE
	cout << typeid(반복자::iterator_concept).name() << endl;
	//iterator_category
}

int main()	
{
	//save("FileName.cpp");
	// 반복자란 무엇인가.
	// 출력스트림 반복자(stream 반복자, 반복자 어댑터)의 동작을 통해 반복자가 
	// 무엇인지 알아본다
	// 반복자는 포인터가 절대 아니다

	// 문제 반복자는 6가지 종류가 있다
	// 함수 f에게 반복자를 인자로 넘겨주면 어떤 종류인지 출력하게 하라
	
	// 문제 벡터가 contiguous 인지 판별하려면 질문을 바꿔야 한다



	f(istream_iterator<String>{cin});
	f(ostream_iterator<String>{cout});
	f(forward_list<char>::iterator{});
	f(list<double>::reverse_iterator{});
	f(deque<int>{}.cbegin());
	f(vector<int>{}.begin());	//벡터의 반복자는 다른 반복자 종류가 될 수 있다 
	
	f(int{});






	
}                
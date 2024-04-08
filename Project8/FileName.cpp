#include <array>
#include <list>
#include "String.h"
#include "save.h"

//-----------------------------------------------------------------
// 2024.04.8 1학기 stl				                        (6주 1)
// 
// STL - Container
// 
// Containers are objects that store other objects 컨테이너는 다른 오브젝트를 저장하는 오브젝트
// 오브젝트 - 클래스로 만들어진 객체
//-----------------------------------------------------------------

extern bool 관찰;


int main()
{
	save("FileName.cpp");
	array<String, 100>a;

	//문제 a에 "FileName.cpp"에 있는 단어를 저장하라
	//a를 길이 오름차순으로 정렬하라
	//화면에 a를 출력하라

	ifstream in{ "FileName.cpp" };
	if (not in)
		return 123456;
	for (int i = 0; i < 100; ++i);
		//in >> a[i];
	
		
}

//syntactic sugar
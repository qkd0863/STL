#include <string>
#include <array>
#include <numeric>
#include <memory>
#include <algorithm>
#include <random>
#include <print>
#include <functional>
#include "String.h"
#include "save.h"

//-----------------------------------------------------------------
// 2024.04.2 1학기 stl				                        (5주 2)
// 
// 
//-----------------------------------------------------------------

extern bool 관찰;


int main()
{
	//save("FileName.cpp");
	
	array<String, 5> a{ "dsadsadasdad","sadasfsafasd","wqewqreqe","wqewqrqwwe","xzczxcvzxc" };
	
	
	// sort를 사용하여 a가 관리하는 String을 오름차순으로 정렬한 후 출력하라

	관찰 = true;
	for (const String& s : a)
		sort(s.getMem(), s.getMem() + s.getLen());
	관찰 = false;

	for (String& s : a)
		cout << s << endl;

}



//String t = s;		//디폴트 복사생성자를 만들 수 없다 - 스마트포인터는 복사생성이 불가
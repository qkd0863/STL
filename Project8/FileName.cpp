#include <string>
#include <list>
#include <map>
#include <fstream>
#include <algorithm>
#include "String.h"
#include "save.h"

//-----------------------------------------------------------------
// 2024.04.30 1학기 stl				                        (12주 2)
//  
// Associative Conatainer - map<key, value> -> dictionary
// map -> 연관배열처럼 사용할 수 있다 인덱스가 int가 아니다
// 
//-----------------------------------------------------------------

extern bool 관찰;




int main()	
{
	//save("FileName.cpp");
	// 그룹과 멤버
	map<String, list<String>> m{ {"아이브",{"안유진","가을","레이","장원영","리즈","이서"}} };

	m.insert(pair<String, list<String>>{"블랙핑크", { "지수","제니","로제","리사" }});
	m.insert(make_pair("아이유", list<String>{"아이유"}));
	m["르세라핌"] = { "사쿠라","김채원","허윤진","카즈하","홍은채"};

	//전체 출력

	for (const auto& [그룹, 멤버] : m)
	{
		cout << 그룹 << " - " << 멤버.size() << "명 ";
		for (const auto& a : 멤버)
			cout << a << " ";
		cout << endl;
	}
}                
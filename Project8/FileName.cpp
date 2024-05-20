#include <string>
#include <vector>
#include <set>
#include <fstream>
#include "String.h"
#include "save.h"

//-----------------------------------------------------------------
// 2024.04.30 1학기 stl				                        (11주 2)
//  
// Associative Conatainer - set
// set은 어떻게 정렬하는가
// 디폴트 less<Key> - > operator<를 이용한다
// 
//-----------------------------------------------------------------

extern bool 관찰;


bool 찾았다면(multiset<String> ms)
{

}


int main()	
{
	save("FileName.cpp");
	//문제 "이상한 나라의 앨리스.txt" 파일에 있는 단어를 mutiset에 읽어왔다
	

	multiset<String> s; //(*)==함수
	ifstream in{ "이상한 나라의 앨리스.txt" };
	if (not in)
		return 123456;
	
	
	s = { istream_iterator<String>{in}, {} };
	// 문제 찾는 단어가 set에 있는지 알려준다
	while (true)
	{
		cout << "찾을 단어는?";
		String word;
		cin >> word;

		if (s.find(word) != s.end())	//s.contains(word) 이 단어가 있는지 bool로 반환
			cout << word << "는 앨리스에 있는 단어입니다" << endl;
		else
			cout << "그런 단어 없습니다" << endl;
	}
	cout << s.size();
	
}                
#include <vector>
#include <numeric>
#include <algorithm>
#include "String.h"
#include "save.h"

//-----------------------------------------------------------------
// 2024.04.9 1학기 stl				                        (6주 2)
// 
// vector - dynamic array
//-----------------------------------------------------------------

extern bool 관찰;



int main()	
{
	save("FileName.cpp");


	//문제 키보드에서 입력한 int값의 합계와 평균을 출력하라
	//문제 키보드에서 입력한 String을 길이 오름차순 정렬하여 출력하라
	
	vector<String> v{ istream_iterator<String>{cin},{} };		//cin - 키보드 입력  {}키보드 입력 끝

	sort(v.begin(), v.end(), [](const String& a,const String& b) {return a.getLen()< b.getLen(); });
	for (const String& s : v)
		cout << s << endl;
}

#include <vector>
#include <numeric>
#include <algorithm>
#include "String.h"
#include "save.h"

//-----------------------------------------------------------------
// 2024.04.9 1�б� stl				                        (6�� 2)
// 
// vector - dynamic array
//-----------------------------------------------------------------

extern bool ����;



int main()	
{
	save("FileName.cpp");


	//���� Ű���忡�� �Է��� int���� �հ�� ����� ����϶�
	//���� Ű���忡�� �Է��� String�� ���� �������� �����Ͽ� ����϶�
	
	vector<String> v{ istream_iterator<String>{cin},{} };		//cin - Ű���� �Է�  {}Ű���� �Է� ��

	sort(v.begin(), v.end(), [](const String& a,const String& b) {return a.getLen()< b.getLen(); });
	for (const String& s : v)
		cout << s << endl;
}

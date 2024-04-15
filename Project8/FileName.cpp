#include <vector>
#include <numeric>
#include <algorithm>
#include <array>
#include "String.h"
#include "save.h"

//-----------------------------------------------------------------
// 2024.04.15 1�б� stl				                        (7�� 1)
// 
// vector - dynamic array
//-----------------------------------------------------------------

extern bool ����;



int main()	
{
	save("FileName.cpp");

	vector<int> v{ 1,2,3,4,5 };
	//���� v���� 3�� �����ϰ� ����϶�
	// erase-remove idiom

	//auto p = remove(v.begin(), v.end(), 3);
	//v.erase(p, v.end());

	v.erase(remove(v.begin(), v.end(), 3), v.end());


	for (int num : v)
		cout << num << ' ' << endl;		// 1 2 4 5 5    ��ĭ�� �����
}
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
// 2024.04.2 1�б� stl				                        (5�� 2)
// 
// 
//-----------------------------------------------------------------

extern bool ����;


int main()
{
	//save("FileName.cpp");
	
	array<String, 5> a{ "dsadsadasdad","sadasfsafasd","wqewqreqe","wqewqrqwwe","xzczxcvzxc" };
	
	
	// sort�� ����Ͽ� a�� �����ϴ� String�� ������������ ������ �� ����϶�

	���� = true;
	for (const String& s : a)
		sort(s.getMem(), s.getMem() + s.getLen());
	���� = false;

	for (String& s : a)
		cout << s << endl;

}



//String t = s;		//����Ʈ ��������ڸ� ���� �� ���� - ����Ʈ�����ʹ� ��������� �Ұ�
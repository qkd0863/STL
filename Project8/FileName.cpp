#include <array>
#include <algorithm>
#include <vector>
#include <list>
#include <ranges>
#include "String.h"
#include "save.h"

//-----------------------------------------------------------------
// 2024.04.30 1�б� stl				                        (14�� 2)
//  
// �ݺ��ڰ��� �Ÿ��� ��� distance �Լ��� �� �˾ƺ���
// c++20 concept / range
//-----------------------------------------------------------------

extern bool ����;



template<class T>
concept ���ڸ� = is_integral_v<T> or is_floating_point_v<T>;

template<���ڸ� T>
T add(T a, T b)
{
	return a + b;
}


int main()
{
	//���� �Լ� ���ø� add�� ������
	//save("FileName.cpp");
	list<int> list{ 1,2,3 };
	ranges::sort(list.begin(),list.end();

}
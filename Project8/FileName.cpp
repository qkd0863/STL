#include "save.h"
#include <string>
#include <array>
#include <numeric>
#include <memory>
#include <algorithm>
#include <random>
#include <print>

//-----------------------------------------------------------------
// 2024.03.26 1�б� stl ȭ 5~6 �� 5~6                       (4�� 2)
// 
// 
//-----------------------------------------------------------------

//���� [10000, 99999] ������ ���� ���� int 100���� ������
// qsort�� ����Ͽ� ������������ �����Ͻÿ�
// ������ ����� ȭ�鿡 ����ϼ���


default_random_engine dre;
uniform_int_distribution uidNum{ 1,1000 };


int static compare(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}


int main()
{
	save("FileName.cpp");	//�Լ� ������ ����
	
	auto a = compare;
	cout << typeid(a).name() << endl;

}
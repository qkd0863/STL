#include <array>
#include <list>
#include "String.h"
#include "save.h"

//-----------------------------------------------------------------
// 2024.04.8 1�б� stl				                        (6�� 1)
// 
// STL - Container
// 
// Containers are objects that store other objects �����̳ʴ� �ٸ� ������Ʈ�� �����ϴ� ������Ʈ
// ������Ʈ - Ŭ������ ������� ��ü
//-----------------------------------------------------------------

extern bool ����;


int main()
{
	save("FileName.cpp");
	array<String, 100>a;

	//���� a�� "FileName.cpp"�� �ִ� �ܾ �����϶�
	//a�� ���� ������������ �����϶�
	//ȭ�鿡 a�� ����϶�

	ifstream in{ "FileName.cpp" };
	if (not in)
		return 123456;
	for (int i = 0; i < 100; ++i);
		//in >> a[i];
	
		
}

//syntactic sugar
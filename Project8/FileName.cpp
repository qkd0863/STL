#include <string>
#include <list>
#include <map>
#include <fstream>
#include <algorithm>
#include "String.h"
#include "save.h"

//-----------------------------------------------------------------
// 2024.04.30 1�б� stl				                        (12�� 2)
//  
// Associative Conatainer - map<key, value> -> dictionary
// map -> �����迭ó�� ����� �� �ִ� �ε����� int�� �ƴϴ�
// 
//-----------------------------------------------------------------

extern bool ����;




int main()	
{
	//save("FileName.cpp");
	// �׷�� ���
	map<String, list<String>> m{ {"���̺�",{"������","����","����","�����","����","�̼�"}} };

	m.insert(pair<String, list<String>>{"����ũ", { "����","����","����","����" }});
	m.insert(make_pair("������", list<String>{"������"}));
	m["��������"] = { "�����","��ä��","������","ī����","ȫ��ä"};

	//��ü ���

	for (const auto& [�׷�, ���] : m)
	{
		cout << �׷� << " - " << ���.size() << "�� ";
		for (const auto& a : ���)
			cout << a << " ";
		cout << endl;
	}
}                
#include <string>
#include <vector>
#include <set>
#include <fstream>
#include "String.h"
#include "save.h"

//-----------------------------------------------------------------
// 2024.04.30 1�б� stl				                        (11�� 2)
//  
// Associative Conatainer - set
// set�� ��� �����ϴ°�
// ����Ʈ less<Key> - > operator<�� �̿��Ѵ�
// 
//-----------------------------------------------------------------

extern bool ����;


bool ã�Ҵٸ�(multiset<String> ms)
{

}


int main()	
{
	save("FileName.cpp");
	//���� "�̻��� ������ �ٸ���.txt" ���Ͽ� �ִ� �ܾ mutiset�� �о�Դ�
	

	multiset<String> s; //(*)==�Լ�
	ifstream in{ "�̻��� ������ �ٸ���.txt" };
	if (not in)
		return 123456;
	
	
	s = { istream_iterator<String>{in}, {} };
	// ���� ã�� �ܾ set�� �ִ��� �˷��ش�
	while (true)
	{
		cout << "ã�� �ܾ��?";
		String word;
		cin >> word;

		if (s.find(word) != s.end())	//s.contains(word) �� �ܾ �ִ��� bool�� ��ȯ
			cout << word << "�� �ٸ����� �ִ� �ܾ��Դϴ�" << endl;
		else
			cout << "�׷� �ܾ� �����ϴ�" << endl;
	}
	cout << s.size();
	
}                
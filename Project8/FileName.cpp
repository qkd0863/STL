#include <forward_list>
#include <list>
#include <deque>
#include <vector>
#include <iterator>
#include "save.h"
#include "String.h"
//-----------------------------------------------------------------
// 2024.04.30 1�б� stl				                        (10�� 1)
//  
// iterator -iterator are a generalization of pointers
// �����͸� �Ϲ�ȭ �� ���� �ݺ��ڴ�. �̰� ����ϸ� �ڷᱸ���� ����
// �Ű澵 �ʿ���� ������ ������� �ڵ��� �� �ִ�
//-----------------------------------------------------------------

extern bool ����;


template <class �ݺ���>
void f(�ݺ��� iter)
{
	//c++17 ����
	// ���͸� ������ ���
	// �ٸ� �����̳ʴ� ���� - SFINAE
	cout << typeid(�ݺ���::iterator_concept).name() << endl;
	//iterator_category
}

int main()	
{
	//save("FileName.cpp");
	// �ݺ��ڶ� �����ΰ�.
	// ��½�Ʈ�� �ݺ���(stream �ݺ���, �ݺ��� �����)�� ������ ���� �ݺ��ڰ� 
	// �������� �˾ƺ���
	// �ݺ��ڴ� �����Ͱ� ���� �ƴϴ�

	// ���� �ݺ��ڴ� 6���� ������ �ִ�
	// �Լ� f���� �ݺ��ڸ� ���ڷ� �Ѱ��ָ� � �������� ����ϰ� �϶�
	
	// ���� ���Ͱ� contiguous ���� �Ǻ��Ϸ��� ������ �ٲ�� �Ѵ�



	f(istream_iterator<String>{cin});
	f(ostream_iterator<String>{cout});
	f(forward_list<char>::iterator{});
	f(list<double>::reverse_iterator{});
	f(deque<int>{}.cbegin());
	f(vector<int>{}.begin());	//������ �ݺ��ڴ� �ٸ� �ݺ��� ������ �� �� �ִ� 
	
	f(int{});






	
}                
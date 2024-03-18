#pragma once
#include <iostream>
#include <chrono>
#include <vector>
#include <fstream>

using namespace std;



void save(string_view fileName)
{
	//fileName을 읽을 파일로 연다
	ifstream in{ fileName.data() };
	if (not in)
	{
		cout << fileName << " - 파일 열기 실패" << endl;
		exit(0);
	}

	//저장한 파일을 덧붙여 쓰기모드로 연다
	ofstream out("2024 1학기 STL 월910화78 강의저장.txt", ios::app);

	//저장한 시간을 기록한다
	out << endl << endl << endl;
	auto now = chrono::system_clock::now();	//epoch로 부터 증가한 tick
	auto time = chrono::system_clock::to_time_t(now);	//UTC 시간으로 변환
	auto lt = localtime(&time); //현지 시간으로 변환

	auto old = out.imbue(locale("ko_KR"));
	//날짜를 내 마음대로 출력한다
	out << "====================================================================================================" << endl;
	out << fileName << put_time(lt, ", 저장시간: %x %A %X ") << endl;
	out << "====================================================================================================" << endl;
	out.imbue(old);

	//읽을 파일의 내용을 모두 읽어 쓸 파일에 덧붙여 쓴다
	//STL 자료구조와 알고리즘을 이용해 본다, 좋은 코딩은 아니다
	vector<char> v{ istreambuf_iterator<char>{in},{} };
	copy(v.begin(), v.end(), ostreambuf_iterator<char>{out});

	/*for (char c : v)
		out << c;*/

}
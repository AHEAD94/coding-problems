/////////////////////////////////////////////////////////////////////////////////////////////
// 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의
// 아래 표준 입출력 예제 필요시 참고하세요.
// 표준 입력 예제
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int 변수 1개 입력받는 예제
// cin >> b >> c;                       // float 변수 2개 입력받는 예제 
// cin >> d >> e >> f;                  // double 변수 3개 입력받는 예제
// cin >> g;                            // char 변수 1개 입력받는 예제
// cin >> var;                          // 문자열 1개 입력받는 예제
// cin >> AB;                           // long long 변수 1개 입력받는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
// 표준 출력 예제
// int a = 0;                            
// float b = 1.0, c = 2.0;               
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int 변수 1개 출력하는 예제
// cout << b << " " << c;               // float 변수 2개 출력하는 예제
// cout << d << " " << e << " " << f;   // double 변수 3개 출력하는 예제
// cout << g;                           // char 변수 1개 출력하는 예제
// cout << var;                         // 문자열 1개 출력하는 예제
// cout << AB;                          // long long 변수 1개 출력하는 예제
/////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void initProblem(vector<vector<int>> &gears, vector<pair<int, int>> &rotation) {
	int K; // 회전 횟수
	cin >> K;

	for (int i = 0; i < 4; i++) {
		vector<int> gear;

		for (int j = 0; j < 8; j++) {
			int blade;
			cin >> blade;

			gear.push_back(blade);
		}
		gears.push_back(gear);
	}

	for (int i = 0; i < K; i++) {
		int gear_number;
		int direction;
		cin >> gear_number >> direction;

		rotation.push_back(make_pair(gear_number - 1, direction));
	}

	return;
}

void rotateGear(vector<vector<int>> &gears, int gear_number, int direction, int caller_gear) {
	// 반대 극성 검사 후 다를 경우 다른 자석도 회전
	// 다른 자석을 회전시킨 자석은 재귀함수 내에서 다시 회전되지 않아야 함 
	if (gear_number == 0 or gear_number == 1 or gear_number == 2) {
		int right_gear = gear_number + 1;
		if (right_gear != caller_gear and gears[gear_number][2] != gears[right_gear][6]) {
			rotateGear(gears, right_gear, direction * (-1), gear_number);
		}
	}
	if (gear_number == 1 or gear_number == 2 or gear_number == 3) {
		int left_gear = gear_number - 1;
		if (left_gear != caller_gear and gears[gear_number][6] != gears[left_gear][2]) {
			rotateGear(gears, left_gear, direction * (-1), gear_number);
		}
	}

	// 현재 자석 회전
	if (direction == 1) { // 시계방향 - back을 front로 이동
		int back = gears[gear_number].back();
		gears[gear_number].pop_back();
		gears[gear_number].insert(gears[gear_number].begin(), back);
	}
	else { // 반시계방향 - front를 back으로 이동
		int front = gears[gear_number].front();
		gears[gear_number].erase(gears[gear_number].begin());
		gears[gear_number].push_back(front);
	}

	return;
}

int getScore(vector<vector<int>> &gears) {
	int score = 0;

	for (int i = 0; i < 4; i++) {
		score += gears[i][0] * pow(2, i);
	}

	return score;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	/*
	   아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	   앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
	   //여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
	   freopen 함수를 이용하면 이후 cin 을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
	   따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
	   freopen 함수를 사용하기 위해서는 #include <cstdio>, 혹은 #include <stdio.h> 가 필요합니다.
	   단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
	*/
	//freopen("input.txt", "r", stdin);
	cin>>T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for(test_case = 1; test_case <= T; ++test_case)
	{
		vector<vector<int>> gears;
		vector<pair<int, int>> rotation;

		initProblem(gears, rotation);

		// 빨간색 화살표의 위치는 각 기어 벡터의 0번 인덱스로 함
		// 날이 맞붙은지 확인하는 절차는 기어 번호에 따라 0: {2}, 1: {2, 6}, 2: {2, 6}, 3: {6} 만 검사하면 됨

		int rotation_num = rotation.size();
		for (int i = 0; i < rotation_num; i++) {
			rotateGear(gears, rotation[i].first, rotation[i].second, rotation[i].first);
		}

		cout << "#" << test_case << " " << getScore(gears) << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
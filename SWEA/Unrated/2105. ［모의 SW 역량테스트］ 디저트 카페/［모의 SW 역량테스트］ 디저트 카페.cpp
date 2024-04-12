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
#include <set>

#define DIRECTION_NUM 4

using namespace std;

void initMap(int length, vector<vector<int>> &map) {
	for (int i = 0; i < length; i++) {
		vector<int> map_row;

		for (int j = 0; j < length; j++) {
			int dessert_type;
			cin >> dessert_type;

			map_row.push_back(dessert_type);
		}
		map.push_back(map_row);
	}
}

void DFS(vector<vector<int>> &map, int start_row, int start_col, int curr_row, int curr_col, set<int> &eaten_desserts, vector<vector<int>> &directions, int last_direction, int &max_desserts) {
	// map을 움직일 때, 대각선으로 움직이면서 map의 경계를 확인해야함
	// map을 움직일 때, 다음 카페의 디저트가 이미 먹은 것인지 set에서 검색해야함
	// map을 움직이고 시작위치로 돌아온 경우에만 먹은 디저트 수 반영
	//cout << "curr pos: (" << curr_row << ", " << curr_col << ") " << map[curr_row][curr_col] << ", eaten_num: " << eaten_num << "\n";

	for (int next_direction = last_direction; next_direction < DIRECTION_NUM; next_direction++) {
		int next_row = curr_row + directions[next_direction][0];
		int next_col = curr_col + directions[next_direction][1];

		// 시작점으로의 사격형 경로를 만족하는 경우 max_desserts 업데이트
		if (next_row == start_row and next_col == start_col) {
			int eaten_num = eaten_desserts.size();
			max_desserts = max(max_desserts, eaten_num);
			//cout << "eaten_num: " << eaten_num << "\n";
			return;
		}

		const int MAP_SIZE = map.size();
		if (0 <= next_row and next_row < MAP_SIZE and 0 <= next_col and next_col < MAP_SIZE) {
			int dessert_type = map[next_row][next_col];
			set<int>::iterator iter = eaten_desserts.find(dessert_type);

			if (iter == eaten_desserts.end()) {
				//cout << " - next direction: (" << next_row << ", " << next_col << ") " << dessert_type << "\n";
				eaten_desserts.insert(dessert_type);
				DFS(map, start_row, start_col, next_row, next_col, eaten_desserts, directions, next_direction, max_desserts);
				eaten_desserts.erase(dessert_type);
			}
		}
	}

	return;
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
		int N;
		cin >> N;

		vector<vector<int>> map;
		initMap(N, map);

		vector<vector<int>> directions = {
			{1, 1},		// Right Down
			{1, -1},	// Left Down
			{-1, -1},	// Left Up
			{-1, 1},	// Right Up
		};

		int max_desserts = 0;

		// map 내의 각 시작점을 기준으로 DFS를 수행
		for (int i = 0; i < N - 2; i++) {
			for (int j = 1; j < N - 1; j++) {
				//cout << "========== START (" << i << ", " << j << ") ========== \n";
				int curr_row = i;
				int curr_col = j;
				set<int> eaten_desserts;
				
				int dessert_type = map[curr_row][curr_col];
				eaten_desserts.insert(dessert_type);

				DFS(map, curr_row, curr_col, curr_row, curr_col, eaten_desserts, directions, 0, max_desserts);
			}
		}
		
		// 가장 작은 단위의 사각형 경로도 만들지 못 한 경우
		if (max_desserts < 4) max_desserts = -1;

		cout << "#" << test_case << " " << max_desserts << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
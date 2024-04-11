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
#include <queue>
#include <algorithm>

using namespace std;

void initMap(vector<vector<int>> &map, int row, int col) {
    for (int i = 0; i < row; i++) {
        vector<int> map_rows;

        for (int j = 0; j < col; j++) {
            int pipe_type;
            cin >> pipe_type;
            //cout << pipe_type << " ";

            map_rows.push_back(pipe_type);
        }
        map.push_back(map_rows);
        //cout << endl;
    }
}

void setDirections(vector<vector<int>> &directions, int pipe_type) {
    if (pipe_type == 1 or pipe_type == 2 or pipe_type == 4 or pipe_type == 7) {
        directions.push_back({-1, 0}); // up
    }
    if (pipe_type == 1 or pipe_type == 2 or pipe_type == 5 or pipe_type == 6) {
        directions.push_back({1, 0}); // down
    }
    if (pipe_type == 1 or pipe_type == 3 or pipe_type == 6 or pipe_type == 7) {
        directions.push_back({0, -1}); // left
    }
    if (pipe_type == 1 or pipe_type == 3 or pipe_type == 4 or pipe_type == 5) {
        directions.push_back({0, 1}); // right
    }

    return;
}

bool arePipesConnected(int curr_pipe, int next_pipe, vector<int> curr_pos, vector<int> next_pos) {
    bool is_connected = false;

    vector<vector<int>> curr_directions;
    vector<vector<int>> next_directions;
    setDirections(curr_directions, curr_pipe);
    setDirections(next_directions, next_pipe);

    int curr_row = curr_pos[0];
    int curr_col = curr_pos[1];
    int next_row = next_pos[0];
    int next_col = next_pos[1];

    // 서로 반대되는 파이프 방향이 있다면 연결처리
    for (vector<int> curr_dir : curr_directions) {
        for (vector<int> next_dir : next_directions) {
            if (curr_col < next_col and curr_dir[1] == 1 and next_dir[1] == -1) {
                is_connected = true;
            }
            if (curr_col > next_col and curr_dir[1] == -1 and next_dir[1] == 1) {
                is_connected = true;
            }
            if (curr_row < next_row and curr_dir[0] == 1 and next_dir[0] == -1) {
                is_connected = true;
            }
            if (curr_row > next_row and curr_dir[0] == -1 and next_dir[0] == 1) {
                is_connected = true;
            }
        }
    }

    return is_connected;
}

int BFS(vector<vector<int>> &map, int hole_row, int hole_col, int target_time) {
    int total_row = map.size();
    int total_col = map[0].size();
    int area_num = 1;

    queue<vector<int>> position_queue;
    position_queue.push({hole_row, hole_col, map[hole_row][hole_col], 1}); // 맨홀 row, 맨홀 col, 맨홀 타입, 경과시간
    map[hole_row][hole_col] = 0;

    while (!position_queue.empty()) {
        int curr_time = position_queue.front()[3];
        if (curr_time >= target_time) break;

        int curr_row = position_queue.front()[0];
        int curr_col = position_queue.front()[1];
        int curr_pipe = position_queue.front()[2];
        position_queue.pop();
        //cout << "----------------------\ncurr pos: (" << curr_row << ", " << curr_col << ")\n";

        vector<vector<int>> directions;
        setDirections(directions, curr_pipe);

        int direction_size = directions.size();
        //cout << "type: " << curr_pipe << ", directions: " << direction_size << "\n";
        for (int i = 0; i < direction_size; i++) {
            int next_row = curr_row + directions[i][0];
            int next_col = curr_col + directions[i][1];

            if (0 <= next_row and next_row < total_row and 0 <= next_col and next_col < total_col) {
                int next_pipe = map[next_row][next_col];
                
                if (arePipesConnected(curr_pipe, next_pipe, {curr_row, curr_col}, {next_row, next_col})) {
                    //cout << " - next pos: (" << next_row << ", " << next_col << ")\n";
                    vector<int> new_pos = {next_row, next_col, map[next_row][next_col], curr_time + 1};
                    map[next_row][next_col] = 0;
                    position_queue.push(new_pos);
                    area_num++;
                }
            }
        }
        //cout << "area_num: " << area_num << "\n";
    }
    
    return area_num;
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
        int N, M;
        int R, C;
        int L;
        cin >> N >> M >> R>> C >> L;

        vector<vector<int>> map;
        initMap(map, N, M);

        int area_num = 0;
        area_num = BFS(map, R, C, L);

        cout << "#" << test_case << " " << area_num << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
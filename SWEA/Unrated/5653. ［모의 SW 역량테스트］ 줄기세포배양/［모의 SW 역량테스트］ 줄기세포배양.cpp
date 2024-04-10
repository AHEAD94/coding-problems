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

#include<iostream>
#include <vector>
#include <algorithm>

#define STATUS_INACTIVE 0
#define STATUS_ACTIVE 1
#define STATUS_DEAD 2

using namespace std;

typedef struct Cell {
    int row;
    int col;
    int X;
    int time;
    int status;
} Cell;

bool cmpByX(Cell a, Cell b) {
    return a.X > b.X;
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
        int M;
        int K;
        cin >> N >> M >> K;
        
        int row_size = K + N + 1;
        int col_size = K + M + 1;
        vector<vector<int>> map(row_size, vector<int>(col_size, 0));
        int direction[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // up, down, left, right
        
        vector<Cell> cells;
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                int x;
                cin >> x;
                
                int row = K / 2 + i + 1;
                int col = K / 2 + j + 1;
                
                if (x > 0) {
                    map[row][col] = x;
                    Cell initial_cell = {row, col, x, 1, STATUS_INACTIVE};
                    cells.push_back(initial_cell);
                }
            }
        }
        
        while (K > 0) {
            int cell_num = cells.size();
            // cout << K << ", " << cell_num << "\n";
            sort(cells.begin(), cells.end(), cmpByX);
            
            for (int i = 0; i < cell_num; i++) {
                Cell cur_cell = cells.front();
                cells.erase(cells.begin());
                // cout << "[" << cur_cell.row << ", " << cur_cell.col << "] X = " << cur_cell.X << ", time = " << cur_cell.time << ", status = " << cur_cell.status << "\n";
                
                /* 세포 분열 */
                if (cur_cell.status == STATUS_ACTIVE) {
                    // 세포 4면에 다른 세포가 없는지 확인
                    for (int j = 0; j < 4; j++) {
                        int next_row = cur_cell.row + direction[j][0];
                        int next_col = cur_cell.col + direction[j][1];
                        
                        // 세포 벡터에 삽입
                        if (map[next_row][next_col] == 0) {
                            map[next_row][next_col] = cur_cell.X;
                            
                            Cell new_cell = {next_row, next_col, cur_cell.X, 1, STATUS_INACTIVE};
                            cells.push_back(new_cell);
                            // cout << "new cell [" << new_cell.row << ", " << new_cell.col << "] X = " << new_cell.X << endl;
                        }
                    }
                }
                
                /* 세포 시간 경과 */
                if (cur_cell.time < cur_cell.X)  {
                    cur_cell.time++;
                }
                else {
                    cur_cell.time = 1;
                    cur_cell.status++;
                }
                
                /* 살아있는 세포는 다시 벡터에 삽입 */
                if (cur_cell.status < STATUS_DEAD) {
                    cells.push_back(cur_cell);
                }
            }
            
            K--;
        }
        
        cout << "#" << test_case << " " << cells.size() << endl;
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
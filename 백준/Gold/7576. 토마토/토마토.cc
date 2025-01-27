#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

template <typename T>
void PrintContainer(const T cont) {
    for (auto row : cont) {
        for (auto data : row) {
            cout << data << ' ';
        }
        cout << '\n';
    }
}

int MultiBFS(vector<vector<int>>& box, const vector<pair<int, int>> dirs, const vector<tuple<int, int, int>>& sources) {
    int max_time = 0;
    
    // {row, col, time} 세 데이터의 묶음을 큐에 저장
    queue<tuple<int, int, int>> pos_q;
    
    // 큐 벡터에 초기 시작점 추가 및 방문처리
    for (auto pos : sources) {
        box[get<0>(pos)][get<1>(pos)] = 1;
        pos_q.push(pos);
    }
    
    // while 문 안에서 동일한 시간을 공유하도록 구현
    while (!pos_q.empty()) {
        // 큐에서 pop해서 현재 값 로드
        int cur_row = get<0>(pos_q.front());
        int cur_col = get<1>(pos_q.front());
        int cur_time = get<2>(pos_q.front());
        pos_q.pop();
        
        // 시간 증가
        max_time = max(max_time, cur_time);
        
        // for 문으로 4방향 방문 가능여부 확인
        for (auto dir : dirs) {
            int next_row = cur_row + dir.first;
            int next_col = cur_col + dir.second;
            
            // 방문 가능하다면 방문처리 및 queue에 삽입
            if ((0 <= next_row && next_row < box.size()) && (0 <= next_col && next_col < box[0].size())) {
                if (box[next_row][next_col] == 0) {
                    box[next_row][next_col] = 1;
                    pos_q.push(make_tuple(next_row, next_col, cur_time + 1));
                }
            }
        }
    }
    
    // 안익은 토마토가 있는지 확인
    for (const auto& row : box) {
        for (const int tomato : row) {
            if (tomato == 0) {
                return -1;
            }
        }
    }
    
    return max_time;
}

int main() {
    int M, N;
    cin >> M >> N;
    
    vector<vector<int>> box(N, vector<int>(M, 0));
    vector<pair<int, int>> dirs = {
        {0, 1}, {0, -1}, {1, 0}, {-1, 0}
    };
    
    vector<tuple<int, int, int>> sources;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> box[i][j];
            
            if (box[i][j] == 1) {
                sources.push_back(make_tuple(i, j, 0));
            }
        }
    }
    
    // 각 시작점을 토대로 BFS 수행 (시간 공유)
    int result = MultiBFS(box, dirs, sources);
    cout << result << endl;
    
    return 0;
}
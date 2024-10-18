#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int BFS(vector<vector<int>>& map, vector<vector<bool>>& visited, vector<vector<int>>& dirs) {
    int goal_x = static_cast<int>(map[0].size() - 1);
    int goal_y = static_cast<int>(map.size() - 1);
    
    int answer = 0;
    
    queue<vector<int>> pos_queue;
    
    visited[0][0] = true;
    pos_queue.push({0, 0, 1}); // {x, y, count}
    
    while (!pos_queue.empty()) {
        int curr_x = pos_queue.front()[0];
        int curr_y = pos_queue.front()[1];
        int count = pos_queue.front()[2];
        pos_queue.pop();
        
        // 미로 종점 처리
        if (curr_x == goal_x and curr_y == goal_y) {
            answer = count;
            break;
        }
        
        size_t dirs_size = dirs.size();
        for (size_t i = 0; i < dirs_size; i++) {
            int next_x = curr_x + dirs[i][0];
            int next_y = curr_y + dirs[i][1];
            
            if (0 <= next_x and next_x <= goal_x and 0 <= next_y and next_y <= goal_y) {
                if (map[next_y][next_x] == 1 and visited[next_y][next_x] == false) {
                    visited[next_y][next_x] = true;
                    pos_queue.push({next_x, next_y, count + 1});
                }
            }
        }
    }
    
    return answer;
}

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> map(N, vector<int>(M));
    
    for (int i = 0; i < N; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < M; j++) {
            map[i][j] = row[j] - '0';
        }
    }
    
    // 이동 벡터
    vector<vector<int>> dirs = {
        {0, 1}, {0, -1}, {1, 0}, {-1, 0}
    };
    
    // 방문 기록
    vector<vector<bool>> visited(N, vector<bool>(M, false));
        
    int answer = BFS(map, visited, dirs);
    
    cout << answer << endl;
    
    return 0;
}
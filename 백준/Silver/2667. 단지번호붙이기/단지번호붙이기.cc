#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void BFS(vector<vector<int>>& map, const vector<vector<int>> dirs, int start_row, int start_col, vector<int>& result) {
    int count = 1;
    size_t map_size = map.size();
    
    queue<vector<int>> pos_q;
    pos_q.push({start_row, start_col});
    map[start_row][start_col] = 0;
    
    while (!pos_q.empty()) {
        int curr_row = pos_q.front()[0];
        int curr_col = pos_q.front()[1];
        pos_q.pop();

        for (int i = 0; i < 4; i++) {
            int next_row = curr_row + dirs[i][0];
            int next_col = curr_col + dirs[i][1];
            
            if (0 <= next_row and next_row < map_size and 0 <= next_col and next_col < map_size) {
                if (map[next_row][next_col] == 1) {
                    pos_q.push({next_row, next_col});
                    map[next_row][next_col] = 0;
                    count++;
                }
            }
        }
    }
    
    result.push_back(count);
}

int main() {
    int N;
    cin >> N;
    vector<vector<int>> map(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < N; j++) {
            map[i][j] = row[j] - '0';
        }
    }
        
    vector<vector<int>> dirs = {
        {0, -1}, {0, 1}, {-1, 0}, {1, 0}
    };
    
    vector<int> result;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == 1) {
                BFS(map, dirs, i, j, result);
            }
        }
    }
    
    sort(result.begin(), result.end());
    
    size_t result_size = result.size();
    cout << result_size << "\n";
    for (auto cnt : result) {
        cout << cnt << "\n";
    }
    
    return 0;
}
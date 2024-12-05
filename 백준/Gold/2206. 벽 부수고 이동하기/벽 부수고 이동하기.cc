#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

struct BFSArgs {
    int row;
    int col;
    int dist;
    int chance;
};

int BFS(const vector<vector<int>>& map, const int N, const int M) {
    vector<vector<vector<int>>> visited(N, vector<vector<int>>(M, vector<int>(2, false)));
    const vector<pair<int, int>> dirs{
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}
    };
    
    queue<BFSArgs> bfs_q;
    bfs_q.push(BFSArgs{0, 0, 1, 1});
    visited[0][0][1] = 1;
        
    while (!bfs_q.empty()) {
        int row = bfs_q.front().row;
        int col = bfs_q.front().col;
        int dist = bfs_q.front().dist;
        int chance = bfs_q.front().chance;
        bfs_q.pop();
        
        if (row >= N - 1 && col >= M - 1) {
            return dist;
        }
    
        for (size_t i = 0; i < dirs.size(); i++) {
            int next_row = row + dirs[i].first;
            int next_col = col + dirs[i].second;
            int chance_i = chance;
            
            if (0 <= next_row && next_row < N && 0 <= next_col && next_col < M) {
                int visitable = 0;
            
                if (map[next_row][next_col] == 0) {
                    visitable = 1;
                }
                if (map[next_row][next_col] == 1 && chance_i > 0) { // 벽을 부술 기회가 남은 경우
                    visitable = 1;
                    chance_i--;
                }
                        
                if (visitable && !visited[next_row][next_col][chance_i]) {
                    bfs_q.push(BFSArgs{next_row, next_col, dist + 1, chance_i});
                    visited[next_row][next_col][chance_i] = 1;
                }
            }
        }
    }
    
    return -1;
}

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> map(N, vector<int>(M, 0));
    for (size_t i = 0; i < static_cast<size_t>(N); i++) {
        string str_nums;
        cin >> str_nums;
        
        for (size_t j = 0; j < static_cast<size_t>(M); j++) {
            int num = str_nums[j] - '0';
            if (num == 1) map[i][j] = num;
        }
    }
    
    cout << BFS(map, N, M) << endl;
    
    return 0;
}
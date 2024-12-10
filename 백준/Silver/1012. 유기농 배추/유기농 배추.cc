#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void BFS(const vector<vector<int>>& field, vector<vector<int>>& visited, const vector<vector<int>>& dirs, const int x, const int y, int& worms) {
    queue<pair<int, int>> bfsQueue;

    visited[y][x] = 1;
    bfsQueue.push(make_pair(x, y));

    while (!bfsQueue.empty()) {
        int curX = bfsQueue.front().first;
        int curY = bfsQueue.front().second;
        bfsQueue.pop();

        for (auto dir : dirs) {
            int nextX = curX + dir[0];
            int nextY = curY + dir[1];

            if (0 <= nextX && nextX < static_cast<int>(field[0].size()) && 0 <= nextY && nextY < static_cast<int>(field.size())) {
                if (field[nextY][nextX] == 1 && !visited[nextY][nextX]) {
                    visited[nextY][nextX] = 1;
                    bfsQueue.push(make_pair(nextX, nextY));
                }
            }
        }
    }

    worms++;
}

int main() {
    int T;
    cin >> T;

    for (int test = 0; test < T; test++) {
        int M, N, K;
        cin >> M >> N >> K;
        
        vector<vector<int>> field(N, vector<int>(M, 0));
        for (int i = 0; i < K; i++) {
            int X, Y;
            cin >> X >> Y;
            field[Y][X] = 1;
        }
        vector<vector<int>> visited(N, vector<int>(M, 0));
        vector<vector<int>> dirs{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        int worms = 0;
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                if (field[y][x] == 1 && !visited[y][x]) {
                    BFS(field, visited, dirs, x, y, worms);
                }
            }
        }
        cout << worms << endl;
    } 

    return 0;
}
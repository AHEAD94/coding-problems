#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void BFS(const vector<vector<char>>& grid, vector<vector<int>>& visited, const vector<pair<int, int>>& dirs, int row, int col, bool rg_weak) {
    size_t grid_size = grid.size();
    char color_group = grid[row][col];

    queue<pair<int, int>> pos_q;
    visited[row][col] = 1;
    pos_q.push(make_pair(row, col));

    while (!pos_q.empty()) {
        int cur_row = pos_q.front().first;
        int cur_col = pos_q.front().second;
        pos_q.pop();

        for (auto dir : dirs) {
            int next_row = cur_row + dir.first;
            int next_col = cur_col + dir.second;

            if (0 <= next_row && next_row < grid_size && 0 <= next_col && next_col < grid_size) {
                char next_color = grid[next_row][next_col];

                // 정상인, 색약인 공통 방문 처리
                if (next_color == color_group) {
                    if (visited[next_row][next_col] == 0) {
                        visited[next_row][next_col] = 1;
                        pos_q.push(make_pair(next_row, next_col));
                    }
                }

                // 색약 방문 처리
                if (rg_weak) { 
                    if (color_group + next_color == 'R' + 'G') {
                        if (visited[next_row][next_col] == 0) {
                            visited[next_row][next_col] = 1;
                            pos_q.push(make_pair(next_row, next_col));
                        }
                    }
                }
            }
        }
    }
}

void PrintMatrix(const vector<vector<int>>& matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << matrix[i][j];
        }
        cout << '\n';
    }
    cout << '\n';
}

int main() {
    int N;
    cin >> N;

    vector<vector<char>> grid(N, vector<char>(N, '\n'));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    // 정상인과 색약인의 결과 구분을 위한 3차원 벡터
    vector<vector<vector<int>>> visited(2, vector<vector<int>>(N, vector<int>(N, 0)));

    vector<pair<int, int>> dirs = {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}
    };

    vector<int> sections(2, 0);

    // 정상인 영역 구분
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (visited[0][i][j] == 0) {
                sections[0]++;
                BFS(grid, visited[0], dirs, i, j, false);
            }
        }
    }

    // 색약인 영역 구분
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (visited[1][i][j] == 0) {
                sections[1]++;
                BFS(grid, visited[1], dirs, i, j, true);
            }
        }
    }

    cout << sections[0] << ' ' << sections[1] << '\n';

    return 0;
}
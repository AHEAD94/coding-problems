#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int BFS(vector<vector<int>>& grid, int row, int col) {
    vector<pair<int, int>> dirs = {
        {-1, 0}, {0, 1}, {1, 0}, {0, -1}
    };

    int rows = grid.size();
    int cols = grid[0].size();

    queue<pair<int, int>> pos_q;
    pos_q.push(make_pair(row, col));
    grid[row][col] = 101;

    int area = 0;

    while (!pos_q.empty()) {
        int cur_row = pos_q.front().first;
        int cur_col = pos_q.front().second;
        pos_q.pop();

        area++;

        for (auto dir : dirs) {
            int next_row = cur_row + dir.first;
            int next_col = cur_col + dir.second;

            if (0 <= next_row && next_row < rows && 0 <= next_col && next_col < cols &&
                grid[next_row][next_col] == 0) {
                grid[next_row][next_col] = 101;
                pos_q.push(make_pair(next_row, next_col));
            }
        }
    }

    return area;
}

void DrawRect(vector<vector<int>>& grid, int lbx, int lby, int rtx, int rty) {
    for (int y = lby; y < rty; y++) {
        for (int x = lbx; x < rtx; x++) {
            grid[y][x]++;
        }
    }
}

int main() {
    int M, N, K;
    cin >> M >> N >> K;

    vector<vector<int>> grid(M, vector<int>(N, 0));
    for (int i = 0; i < K; i++) {
        int lbx, lby, rtx, rty;
        cin >> lbx >> lby >> rtx >> rty;
        DrawRect(grid, lbx, lby, rtx, rty);
    }

    priority_queue<int, vector<int>, greater<>> empty_area;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == 0) {
                int area = BFS(grid, i, j);
                empty_area.push(area);
            }
        }
    }

    cout << empty_area.size() << '\n';
    while (!empty_area.empty()) {
        cout << empty_area.top() << ' ';
        empty_area.pop();
    }

    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

bool IsInBoundary(int row, int col, int row_size, int col_size) {
    if (0 <= row && row < row_size && 0 <= col && col < col_size) {
        return true;
    }
    return false;
}

int RunRobot(const vector<vector<int>>& room, int r, int c, int d) {
    int room_rows = static_cast<int>(room.size());
    int room_cols = static_cast<int>(room[0].size());

    auto visited = room; // 0: 청소되지 않은 영역, 1: 벽, 2: 청소된 영역

    vector<pair<int, int>> dirs = {
        {-1, 0}, {0, 1}, {1, 0}, {0, -1} // 북, 동, 남, 서
    };

    int cleaned_sections = 0;

    int cur_row = r;
    int cur_col = c;
    int cur_dir = d;

    bool is_running = true;
    while (is_running) {
        // 1. 현재 칸이 청소되지 않은 경우, 현재 칸을 청소한다.
        if (visited[cur_row][cur_col] != 2) {
            visited[cur_row][cur_col] = 2;
            cleaned_sections++;
        }

        bool need_to_clean = false;
        for (auto dir : dirs) {
            int next_row = cur_row + dir.first;
            int next_col = cur_col + dir.second;
            if (IsInBoundary(next_row, next_col, room_rows, room_cols) && visited[next_row][next_col] == 0) {
                need_to_clean = true;
                break;
            }
        }

        // 2. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 없는 경우,
        if (!need_to_clean) {
            int back_dir = (cur_dir + 2) % 4;
            int back_row = cur_row + dirs[back_dir].first;
            int back_col = cur_col + dirs[back_dir].second;

            // 후진이 가능한 경우 한 칸 후진
            if (IsInBoundary(back_row, back_col, room_rows, room_cols) && visited[back_row][back_col] != 1) {
                cur_row = back_row;
                cur_col = back_col;
            }
            // 후진이 불가능한 경우 작동 종료
            else {
                is_running = false;
            }
        }
        // 3. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는 경우,
        else { 
        // 반시계 방향 90도 회전
        cur_dir = (cur_dir + 3) % 4;
        int front_row = cur_row + dirs[cur_dir].first;
        int front_col = cur_col + dirs[cur_dir].second;

        // 앞 칸이 청소되지 않은 빈 칸이면 한 칸 전진
        if (IsInBoundary(front_row, front_col, room_rows, room_cols) && visited[front_row][front_col] == 0) {
            cur_row = front_row;
            cur_col = front_col;
            }
        }
    }
    
    return cleaned_sections;
}

int main() {
    int N, M, r, c, d;
    cin >> N >> M >> r >> c >> d;

    vector<vector<int>> room(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> room[i][j];
        }
    }

    int cleaned_sections = RunRobot(room, r, c, d);
    cout << cleaned_sections << '\n';

    return 0;
}
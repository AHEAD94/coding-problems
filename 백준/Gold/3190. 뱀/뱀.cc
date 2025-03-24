#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int playSnakeGame(vector<vector<int>>& map, queue<pair<int, char>>& moving) {
    vector<pair<int, int>> dirs = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
    int cur_dir = 1; // 0: up, 1: right, 2: down, 3: left

    deque<pair<int, int>> snake = {{0, 0}};

    int time_count = 0;

    while (true) { // 조건 세부화
        time_count++;

        int next_row = snake.front().first + dirs[cur_dir].first;
        int next_col = snake.front().second + dirs[cur_dir].second;

        // 벽에 부딪히는지 확인
        size_t map_size = map.size();
        if (!(0 <= next_row && next_row < map_size && 0 <= next_col && next_col < map_size)) {
            return time_count;
        }

        // 몸에 부딪히는지 확인
        vector<pair<int, int>> temp(snake.size());
        copy(snake.begin(), snake.end(), temp.begin());
        auto iter = find(temp.begin(), temp.end(), make_pair(next_row, next_col));
        if (iter != temp.end()) {
            return time_count;
        }

        // 머리 이동
        snake.push_front({next_row, next_col});

        // 사과 먹기 or 꼬리 이동
        if (map[next_row][next_col] == 1) {
            map[next_row][next_col] = 0;
        }
        else {
            snake.pop_back();
        }
        
        // X 초가 끝난 시점의 방향 전환
        if (!moving.empty() && moving.front().first == time_count) {
            if (moving.front().second == 'L') {
                cur_dir = (cur_dir + 3) % 4;
            }
            else {
                cur_dir = (cur_dir + 1) % 4;
            }
            moving.pop();
        }
    }

    return time_count;
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<vector<int>> map(N, vector<int>(N, 0));

    for (int i = 0; i < K; i++) {
        int row, col;
        cin >> row >> col;
        map[row - 1][col - 1] = 1;
    }

    int L;
    cin >> L;

    queue<pair<int, char>> moving;

    for (int i = 0; i < L; i++) {
        int count;
        char dir;
        cin >> count >> dir;
        moving.push({count, dir});
    }

    int end_time = playSnakeGame(map, moving);
    cout << end_time << endl;

    return 0;
}
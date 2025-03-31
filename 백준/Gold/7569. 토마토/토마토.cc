#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

bool isFullyRipe(const vector<vector<vector<int>>>& boxes) {
    for (auto h : boxes) {
        for (auto r : h) {
            for (int c : r) {
                if (c == 0) return false;
            }
        }
    }
    return true;
}

bool isInBox(const int val, const int size) {
    return 0 <= val && val < size;
}

int countTime(vector<vector<vector<int>>>& boxes, const int M, const int N, const int H, vector<tuple<int, int, int>>& ripe_tomatos) {
    // dirs : <height, row, col>
    vector<tuple<int, int, int>> dirs = {{-1, 0, 0}, {1, 0, 0}, {0, -1, 0}, {0, 1, 0}, {0, 0, -1}, {0, 0, 1}};
    
    // pos_q : <height, row, col, time>
    queue<tuple<int, int, int, int>> pos_q;
    for (auto ripe : ripe_tomatos) {
        auto [h, r, c] = ripe;
        pos_q.push({h, r, c, 0});
    }
    
    int time_count = 0;
    
    while (!pos_q.empty()) {
        auto [cur_h, cur_r, cur_c, cur_t] = pos_q.front();
        pos_q.pop();
        
        time_count = max(time_count, cur_t);
        
        for (auto dir : dirs) {
            int next_h = cur_h + get<0>(dir);
            int next_r = cur_r + get<1>(dir);
            int next_c = cur_c + get<2>(dir);
            
            if (isInBox(next_h, H) && isInBox(next_r, N) && isInBox(next_c, M)) {
                if (boxes[next_h][next_r][next_c] == 0) {
                    boxes[next_h][next_r][next_c] = 1;
                    pos_q.push({next_h, next_r, next_c, cur_t + 1});
                }
            }
        }
    }
    
    return time_count;
}

int main() {
    int M, N, H;
    cin >> M >> N >> H;

    vector<vector<vector<int>>> boxes(H, vector<vector<int>>(N, vector<int>(M, 0)));
    vector<tuple<int, int, int>> ripe_tomatos;
    
    for (int h = 0; h < H; h++) {
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < M; c++) {
                cin >> boxes[h][r][c];
                if (boxes[h][r][c] == 1) {
                    ripe_tomatos.push_back({h, r, c});
                }
            }
        }
    }
    
    int time_count = countTime(boxes, M, N, H, ripe_tomatos);
    if (!isFullyRipe(boxes)) {
        time_count = -1;
    }
    cout << time_count << endl;

    return 0;
}
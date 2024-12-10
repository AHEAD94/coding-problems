#include <string>
#include <vector>
#include <queue>

using namespace std;

int BFS(const vector<string>& maps, vector<vector<vector<bool>>>& visited, const vector<vector<int>>& dirs, const int row, const int col) {
    size_t rowSize = maps.size();
    size_t colSize = maps[0].size();
    
    queue<vector<int>> bfsQueue;

    visited[row][col][0] = true; // 시작 포인트 방문 (레버 당기기 전)
    bfsQueue.push({row, col, 0, 0}); // row, col, time, leverPulled

    while (!bfsQueue.empty()) {
        int curRow = bfsQueue.front()[0];
        int curCol = bfsQueue.front()[1];
        int time = bfsQueue.front()[2];
        int leverPulled = bfsQueue.front()[3];
        bfsQueue.pop();
        
        if (maps[curRow][curCol] == 'E' && leverPulled) {
            return time;
        }

        for (auto dir : dirs) {
            int nextRow = curRow + dir[0];
            int nextCol = curCol + dir[1];
            int leverState = leverPulled;

            if (0 <= nextRow && nextRow < rowSize && 0 <= nextCol && nextCol < colSize) {
                bool visitable = false;

                if (maps[nextRow][nextCol] != 'X') {
                    visitable = true;
                }
                if (maps[nextRow][nextCol] == 'L') {
                    leverState = 1;
                }

                if (visitable && !visited[nextRow][nextCol][leverState]) {
                    visited[nextRow][nextCol][leverState] = true;
                    bfsQueue.push({nextRow, nextCol, time + 1, leverState});
                }
            }
        }
    }

    return -1;
}

int solution(vector<string> maps) {
    int answer = 0;

    size_t mapRows = maps.size();
    size_t mapCols = maps[0].size();

    // 레버를 당기지 않은 상태 (false)와 당긴 상태 (true)를 나누어 관리
    vector<vector<vector<bool>>> visited(mapRows, vector<vector<bool>>(mapCols, vector<bool>(2, false)));
    vector<vector<int>> dirs{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    bool startPointFound = false;
    for (size_t row = 0; row < mapRows; row++) {
        for (size_t col = 0; col < mapCols; col++) {
            if (maps[row][col] == 'S') {
                answer = BFS(maps, visited, dirs, row, col);
                startPointFound = true;
                break;
            }
        }
        if (startPointFound) break;
    }

    return answer;
}
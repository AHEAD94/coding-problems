#include <string>
#include <vector>
#include <queue>

using namespace std;

int BFS(vector<vector<int>> &maps, vector<pair<int, int>> &direction) {
    int goal_x = maps[0].size() - 1;
    int goal_y = maps.size() - 1;
    queue< vector<int> > route_queue;
    route_queue.push({0, 0, 1}); // {x, y, depth} 
    maps[0][0] = 0;

    while (!route_queue.empty()) {
        int cur_x = route_queue.front()[0];
        int cur_y = route_queue.front()[1];
        int depth = route_queue.front()[2];
        route_queue.pop();

        // 목적지 도착
        if (cur_x == goal_x and cur_y == goal_y) {
            return depth;
        }
        
        // 방향별 진행 가능성 검사
        for (int dir = 0; dir < direction.size(); dir++) {
            int next_x = cur_x + direction[dir].first;
            int next_y = cur_y + direction[dir].second;

            if (0 <= next_x and next_x <= goal_x and 0 <= next_y and next_y <= goal_y) {
                if (maps[next_y][next_x] == 1) {
                    maps[next_y][next_x] = 0;
                    route_queue.push({next_x, next_y, depth + 1});
                }
            }
        }
    }
    
    return 0;
}

int solution(vector<vector<int>> maps)
{
    int answer = 0;
    vector<pair<int, int>> direction = {
        make_pair(1, 0),    // right
        make_pair(-1, 0),   // left
        make_pair(0, 1),    // down
        make_pair(0, -1)    // up 
    };
    
    answer = BFS(maps, direction);
    if (answer == 0) answer = -1;
    
    return answer;
}
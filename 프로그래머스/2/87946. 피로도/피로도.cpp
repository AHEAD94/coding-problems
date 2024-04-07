#include <string>
#include <vector>

using namespace std;

void DFS(int k, vector<vector<int>> &dungeons, vector<bool> &visited, int depth, int &answer) {
    for (int i = 0; i < dungeons.size(); i++) {
        if (k >= dungeons[i][0] and visited[i] == false) {
            visited[i] = true;
            DFS(k - dungeons[i][1], dungeons, visited, depth + 1, answer);
            visited[i] = false;
        }
    }
    
    if (depth > answer) answer = depth;
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    vector<bool> visited(dungeons.size(), false);
    
    DFS(k, dungeons, visited, 0, answer);
    
    return answer;
}
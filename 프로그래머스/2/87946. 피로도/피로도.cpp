#include <string>
#include <vector>

using namespace std;

void DFS(int k, vector<vector<int>> &dungeons, vector<bool> &visited, int count, int &answer) {
    for (int i = 0; i < dungeons.size(); i++) {
        if (k >= dungeons[i][0] and visited[i] == false) {
            visited[i] = true;
            DFS(k - dungeons[i][1], dungeons, visited, count + 1, answer);
            
            // 방문 해제
            visited[i] = false;
        }
    }
    
    answer = max(answer, count);
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    int count = 0;
    vector<bool> visited(dungeons.size(), false);
    
    DFS(k, dungeons, visited, 0, answer);
    
    return answer;
}
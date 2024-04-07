#include <string>
#include <vector>

using namespace std;

void DFS(int n, vector<vector<int>> &computers, int com_idx, vector<bool> &visited, int &answer) {    
    for (int next = 0; next < computers[com_idx].size(); next++) {
        if (computers[com_idx][next] == 1 and visited[next] == false) {
            visited[next] = true;

            DFS(n, computers, next, visited, answer);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> visited(n, false);
    
    for (int root_com = 0; root_com < computers.size(); root_com++) {
        if (visited[root_com] == false) {
            visited[root_com] = true;
            answer++;
            
            DFS(n, computers, root_com, visited, answer);
        }
    }
    
    return answer;
}
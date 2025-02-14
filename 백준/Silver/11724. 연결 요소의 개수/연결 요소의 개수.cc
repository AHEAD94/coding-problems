#include <iostream>
#include <vector>

using namespace std;

void DFS(const vector<vector<int>>& graph, vector<int>& visited, const size_t node) {
    size_t connection_size = graph[node].size();
    for (size_t i = 0; i < connection_size; i++) {
        int next_node = graph[node][i];
        if (visited[next_node] == 0) {
            visited[next_node] = 1;
            DFS(graph, visited, next_node);
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> graph(N + 1, vector<int>());
    for (int i = 0; i < M; i++) {
        int s, e;
        cin >> s >> e;
        graph[s].push_back(e);
        graph[e].push_back(s);
    }

    int groups = 0;
    
    vector<int> visited(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        if (visited[i] == 0) {
            visited[i] = 1;
            DFS(graph, visited, i);
            groups++;
        }
    }
    
    cout << groups << '\n';
    
    return 0;
}
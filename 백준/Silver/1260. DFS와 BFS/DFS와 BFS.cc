#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void printGraph(const vector<vector<int>>& graph) {
    cout << endl;
    for (const auto& row : graph) {
        for (auto col : row) {
            cout << col << " ";
        }
        cout << endl;
    }
    cout << endl;
}

size_t NumToIdx(const int vert_num) {
    return static_cast<size_t>(vert_num - 1); // 1-based to 0-based
}

int IdxToNum(const size_t vert_idx) {
    return static_cast<int>(vert_idx + 1); // 0-based to 1-based
}

void DFS(const vector<vector<bool>>& graph, vector<bool>& visited, const int num_s) {
    cout << num_s << " ";
    
    size_t idx_s = NumToIdx(num_s);
    for (size_t idx_e = 0; idx_e < graph.size(); idx_e++) {
        if (graph[idx_s][idx_e] && !visited[idx_e]) {
            visited[idx_e] = true;
            DFS(graph, visited, IdxToNum(idx_e));
        }
    }
}

void BFS(const vector<vector<bool>>& graph, vector<bool>& visited, const int num_s) {
    queue<int> num_queue;
    num_queue.push(num_s);
    visited[NumToIdx(num_s)] = true;
    
    while (!num_queue.empty()) {
        int num = num_queue.front();
        num_queue.pop();
        cout << num << " ";
        
        size_t idx_s = NumToIdx(num);
        for (size_t idx_e = 0; idx_e < graph[idx_s].size(); idx_e++) {
            if (graph[idx_s][idx_e] && !visited[idx_e]) {
                visited[idx_e] = true;
                num_queue.push(IdxToNum(idx_e));
            }
        }
    }
}

int main() {
    int N, M, V;
    cin >> N >> M >> V;
    
    vector<vector<bool>> graph(N, vector<bool>(N));
    vector<bool> visited(N, false);
    
    int v1, v2;
    for (size_t i = 0; i < static_cast<size_t>(M); i++) {
        cin >> v1 >> v2;
        // v1, v2는 1-based 입력, NumToIdx를 통해 0-based로 변환하여 그래프에 저장
        graph[NumToIdx(v1)][NumToIdx(v2)] = true;
        graph[NumToIdx(v2)][NumToIdx(v1)] = true;
    }
    // printGraph(graph);
    
    visited[NumToIdx(V)] = true;
    DFS(graph, visited, V);
    cout << endl;
    
    fill(visited.begin(), visited.end(), false); // 방문기록 초기화
    BFS(graph, visited, V);
    
    return 0;
}
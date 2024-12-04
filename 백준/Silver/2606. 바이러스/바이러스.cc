#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int BFS(const vector<vector<int>>& _adj, vector<int>& _visited) {
    queue<int> coms_q;
    coms_q.push(0); // 0-based index : actually 1
    _visited[0] = 1;
    
    int victims = 0;
    
    while (!coms_q.empty()) {
        int src = coms_q.front();
        coms_q.pop();
        
        if (src != 0) {
            victims++;
        }
        
        for (size_t dest = 0; dest < _adj.size(); dest++) {
            if (_adj[src][dest] == 1 && _visited[dest] == 0) {
                coms_q.push(dest);
                _visited[dest] = 1;
            }
        }
    }
    
    return victims;
}

int main() {
    int computers, connections;
    cin >> computers >> connections;
    
    vector<vector<int>> adj(computers, vector<int>(computers, 0));
    vector<int> visited(computers, 0);
    
    for (size_t i = 0; i < connections; i++) {
        int s, d;
        cin >> s >> d;
        adj[s - 1][d - 1] = 1; // 0-based index
        adj[d - 1][s - 1] = 1; // bi-directional
    }
    
    int victims = BFS(adj, visited);
    
    cout << victims << endl;
    
    return 0;
}
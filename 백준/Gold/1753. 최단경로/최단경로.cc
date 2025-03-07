#include <iostream>
#include <vector>
#include <queue>

using namespace std;

constexpr int INF = 999999;

void PrintAdj(const vector<vector<pair<int, int>>>& cont) {
    int v = static_cast<int>(cont.size());
    for (int i = 1; i < v; i++) {
        cout << "(" << i << "): ";
        for (auto adj : cont[i]) {
            cout << "(" << adj.first << ", " << adj.second << ") ";
        }
        cout << '\n';
    }
}

struct WEIGHT {
    bool operator ()(pair<int, int> a, pair<int, int> b){
        return a.second > b.second;
    }
};

void Dijkstra(const vector<vector<pair<int, int>>>& adj_list, vector<int>& visited, int src, vector<int>& shortest) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, WEIGHT> node_pq;
    node_pq.push(make_pair(src, 0));
    visited[src] = 1;

    while (!node_pq.empty()) {
        auto curr = node_pq.top();
        node_pq.pop();

        for (auto next : adj_list[curr.first]) {
            if (shortest[curr.first] + next.second < shortest[next.first]) {
                shortest[next.first] = shortest[curr.first] + next.second;
                node_pq.push(make_pair(next.first, shortest[next.first]));
            }
        }
    }
}

int main() {
    int V, E, K;
    cin >> V >> E >> K;

    vector<vector<pair<int, int>>> adj_list(V + 1);
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj_list[u].push_back(make_pair(v, w));
    }
    //PrintAdj(adj_list);

    vector<int> visited(V + 1, 0);
    vector<int> shortest(V + 1, INF);
    shortest[K] = 0;

    Dijkstra(adj_list, visited, K, shortest);

    for (auto iter = shortest.begin() + 1; iter != shortest.end(); iter++) {
        if (*iter == INF) {
            cout << "INF" << '\n';
        }
        else cout << *iter << '\n';
    }
    
    return 0;
}
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

constexpr int INF = 999999;

struct WEIGHT {
    bool operator ()(pair<int, int> a, pair<int, int> b){
        return a.second > b.second;
    }
};

void Dijkstra(const vector<vector<pair<int, int>>>& adj_list, int src, vector<int>& shortest) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, WEIGHT> node_pq;
    node_pq.push({src, 0});

    while (!node_pq.empty()) {
        auto curr = node_pq.top();
        node_pq.pop();
        
        for (auto next : adj_list[curr.first]) {
            if (shortest[curr.first] + next.second < shortest[next.first]) {
                shortest[next.first] = shortest[curr.first] + next.second;
                node_pq.push({next.first, shortest[next.first]});
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
        adj_list[u].push_back({v, w});
    }

    vector<int> shortest(V + 1, INF);
    shortest[K] = 0;

    Dijkstra(adj_list, K, shortest);

    for (int i = 1; i <= V; i++) {
        if (shortest[i] == INF) {
            cout << "INF" << '\n';
        }
        else {
            cout << shortest[i] << '\n';
        }
    }
    
    return 0;
}
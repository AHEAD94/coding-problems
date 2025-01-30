#include <iostream>
#include <queue>

using namespace std;

struct coordi {
    bool operator()(pair<int, int> p1, pair<int, int> p2) {
        if (p1.second == p2.second)
            return p1.first > p2.first;
        return p1.second > p2.second;
    }
};

int main() {
    ios::sync_with_stdio(false);
	cin.tie(0);
    
    int N;
    cin >> N;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, coordi> p_queue;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        p_queue.push(make_pair(x, y));
    }
    
    while (!p_queue.empty()) {
        auto p = p_queue.top();
        cout << p.first << ' ' << p.second << '\n';
        p_queue.pop();
    }
    
    return 0;
}
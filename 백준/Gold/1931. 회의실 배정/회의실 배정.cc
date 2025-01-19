#include <iostream>
#include <queue>

using namespace std;

struct cmp {
    bool operator()(pair<int, int> p1, pair<int, int> p2) {
        if (p1.second == p2.second)
            return p1.first > p2.first;
        return p1.second > p2.second;
    }
};

int main() {
    int N;
    cin >> N;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> p_queue;
    
    for (int i = 0; i < N; i++) {
        int s, e;
        cin >> s >> e;
        p_queue.push(make_pair(s, e));
    }

    int meetings = 0;
    int cur_time = 0;
    
    // (1,4), (5,7), (8,11), (12,14) 를 이용할 수 있다.
    while (!p_queue.empty()) {
        auto meeting = p_queue.top();
        p_queue.pop();
        
        if (cur_time <= meeting.first && cur_time <= meeting.second) {
            cur_time = meeting.second;
            meetings++;
        }
    }
    
    cout << meetings << endl;
    
    return 0;
}
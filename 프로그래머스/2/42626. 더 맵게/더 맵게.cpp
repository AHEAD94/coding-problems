#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<>> scoville_pq(scoville.begin(), scoville.end());
    
    while (scoville_pq.top() < K) {
        if (scoville_pq.size() < 2) return -1;
        
        int first = scoville_pq.top();
        scoville_pq.pop();
        int second = scoville_pq.top();
        scoville_pq.pop();
        
        int new_scoville = first + second * 2;
        scoville_pq.push(new_scoville);
        answer++;
    }
    
    return answer;
}
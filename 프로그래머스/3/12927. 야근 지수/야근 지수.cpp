#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> works_pq(works.begin(), works.end());
    
    while (n > 0) {
        if (!works_pq.empty()) {
            if (works_pq.top() <= 0) break;
            int work = works_pq.top();
            works_pq.pop();
            works_pq.push(--work);
        }
        n--;
    }
    
    int works_pq_size = works_pq.size();
    if (n <= 0) {
        for (int i = 0; i < works_pq_size; i++) {
            int top = works_pq.top();
            works_pq.pop();
            answer += top * top;
        }
    }
    else answer = 0;
    
    return answer;
}
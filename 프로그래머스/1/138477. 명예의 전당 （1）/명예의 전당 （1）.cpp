#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    priority_queue<int, vector<int>, greater<int>> fame_hall;
    
    for (int i = 0; i < score.size(); i++) {
        fame_hall.push(score[i]);
        
        if (fame_hall.size() > k) {
            fame_hall.pop();
        }
        
        answer.push_back(fame_hall.top());
    }
    
    return answer;
}
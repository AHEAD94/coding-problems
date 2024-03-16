#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<int> processes;
    
    for (int i = 0; i < priorities.size(); i++) {
        processes.push(priorities[i]);
    }
    
    while (location >= 0) {
        bool isHighest = true;
        
        for (int i = 0; i < priorities.size(); i++) {
            if (processes.front() < priorities[i]) {
                isHighest = false;
                break;
            }
        }
        
        if (isHighest == false) {
            processes.push(processes.front());
            processes.pop();
            if (location == 0) location = processes.size() - 1;
            else location--;
        }
        else {
            vector<int>::iterator iter = find(priorities.begin(), priorities.end(), processes.front());
            if (iter != priorities.end()) priorities.erase(iter);
            processes.pop();
            location--;
            answer++;
        }
    }
    
    return answer;
}
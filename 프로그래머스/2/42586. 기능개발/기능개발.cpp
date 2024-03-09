#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> task_queue;
    queue<int> speed_queue;
    int cycle = 0;
    
    for (int i = 0; i < progresses.size(); i++) {
        task_queue.push(progresses[i]);
        speed_queue.push(speeds[i]);
    }
     
    while (!task_queue.empty()) {
        int release = 0;
        cycle++;
                
        while (!task_queue.empty() and task_queue.front() + (speed_queue.front() * cycle) >= 100) {
            task_queue.pop();
            speed_queue.pop();
            release++;
        }
        
        if (release > 0) answer.push_back(release);
    }
    
    return answer;
}
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int cycle = 0;
     
    while (!progresses.empty()) {
        int release = 0;
        cycle++;
                
        while (!progresses.empty() and progresses.front() + (speeds.front() * cycle) >= 100) {
            progresses.erase(progresses.begin());
            speeds.erase(speeds.begin());
            release++;
        }
        
        if (release > 0) answer.push_back(release);
    }
    
    return answer;
}
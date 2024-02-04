#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    bool isCandidate = true;
    
    for (int i = 2; i <= n; i++) {
        if (n % i == 0) {
            if (answer.size() == 0) {
                answer.push_back(i);
            }
            else {
                for (int j = 0; j < answer.size(); j++) {
                    if (i % answer[j] == 0) {
                        isCandidate = false;
                        break;
                    }
                }
                
                if (isCandidate) {
                    answer.push_back(i);
                }
                isCandidate = true;
            }
        }
    }
    
    return answer;
}
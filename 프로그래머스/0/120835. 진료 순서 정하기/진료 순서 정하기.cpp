#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> emergency) {
    vector<int> answer;
    
    vector<int> emergency_sorted = emergency;
    sort(emergency_sorted.rbegin(), emergency_sorted.rend());
    
    for (int i = 0; i < emergency.size(); i++) {
        for (int j = 0; emergency_sorted.size(); j ++) {
            if (emergency[i] == emergency_sorted[j]) {
                answer.push_back(j + 1);
                break;
            }
        }
    }
    
    return answer;
}
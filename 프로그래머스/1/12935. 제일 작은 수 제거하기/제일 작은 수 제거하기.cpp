#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int min = 999999;
    int min_idx = 999999;
    
    if (arr.size() == 1) answer.push_back(-1);
    else {
        answer = arr;
        
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] < min) {
                min = arr[i];
                min_idx = i;
            }
        }
        answer.erase(answer.begin() + min_idx);
    }
    
    return answer;
}
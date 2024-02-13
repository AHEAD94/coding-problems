#include <string>
#include <vector>

using namespace std;

vector<int> solution(int num, int total) {
    vector<int> answer;
    int sum = 0;
    
    for (int i = total + num; i > -total; i--) {
        for (int j = 0; j < num; j++) {
            sum += i - j;
            answer.insert(answer.begin(), i - j);
        }
        
        if (sum == total) break;
        else {
            sum = 0;
            answer.clear();
        }
    }
    
    if (answer.size() == 0) answer.push_back(sum);
    
    return answer;
}
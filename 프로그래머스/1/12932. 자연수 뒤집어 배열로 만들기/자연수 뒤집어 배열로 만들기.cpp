#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    
    string stNum = to_string(n);
    
    for (int i = 0; i < stNum.length(); i++) {
        answer.insert(answer.begin(), stNum[i] - '0');
    }
    
    return answer;
}
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    int value = 0;
    
    while (n > 0) {
        value = s / n;
        if (value < 1) {
            answer.push_back(-1);
            break;
        }
        s -= value;
        answer.push_back(value);
        n--;
    }
    
    return answer;
}
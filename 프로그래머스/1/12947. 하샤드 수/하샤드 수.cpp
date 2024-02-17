#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    string stNum = "";
    int digitSum = 0;
    
    stNum = to_string(x);
    for (int i = 0; i < stNum.length(); i++) {
        digitSum += stNum[i] - '0';
    }
    
    if (x % digitSum != 0) answer = false;
    
    return answer;
}
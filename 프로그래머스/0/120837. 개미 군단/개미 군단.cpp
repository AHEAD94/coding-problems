#include <string>
#include <vector>

using namespace std;

int solution(int hp) {
    int answer = 0;
    
    int remainder = hp;
    
    while (remainder > 0) {
        if (remainder >= 5) {
            answer += remainder / 5;
            remainder %= 5;
        }
        else if (remainder >= 3) {
            answer += remainder / 3;
            remainder %= 3;
        }
        else {
            answer += remainder;
            remainder = 0;
        }
    }
    
    return answer;
}
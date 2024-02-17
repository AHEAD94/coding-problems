#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    long tempNum = num;
    
    while (tempNum > 1 and answer < 500) {
        if (tempNum % 2 == 0) tempNum /= 2;
        else tempNum = (tempNum * 3) + 1;
        
        answer++;
    }
    
    if (answer >= 500) answer = -1;
    
    return answer;
}
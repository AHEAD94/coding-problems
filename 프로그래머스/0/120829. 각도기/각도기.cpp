#include <string>
#include <vector>

using namespace std;

int solution(int angle) {
    int answer = 0;
    
    if (0 < angle and  angle < 90) answer = 1;
    else if (angle == 90) answer = 2;
    else if (90 < angle and  angle < 180) answer = 3;
    else if (angle == 180) answer = 4;
    
    return answer;
}
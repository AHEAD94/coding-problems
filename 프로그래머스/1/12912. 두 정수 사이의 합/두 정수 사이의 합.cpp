#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    
    int tempA = a;
    int tempB = b;
    
    if (tempA > tempB) {
        tempA = b;
        tempB = a;
    }
    
    for (int i = tempA; i <= tempB; i++) {
        answer += i;
    }
    
    return answer;
}
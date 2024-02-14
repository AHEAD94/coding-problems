#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            answer += i;
            
            if (n / i != i) answer += n / i;
        }
    }
    
    return answer;
}
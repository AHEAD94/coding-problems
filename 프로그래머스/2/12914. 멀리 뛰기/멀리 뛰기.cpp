#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    long long answer = 0;
    
    // F(1) = 1, F(2) = 2, F(3) = 3, F(4) = 5, ...
    if (n <= 3) answer = n;
    else {
        int prev1 = 2;
        int prev2 = 3;
        int now = 0;
        
        for (int i = 4; i <= n; i++) {
            now = (prev1 + prev2) % 1234567;
            
            prev1 = prev2;
            prev2 = now;
        }
        
        answer = now;
    }
    
    return answer;
}
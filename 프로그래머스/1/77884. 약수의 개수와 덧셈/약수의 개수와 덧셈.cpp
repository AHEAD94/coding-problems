#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int left, int right) {
    int answer = 0;
    int temp = 0;
    
    for (int i = left; i <= right; i++) {
        for (int j = 1; j <= sqrt(i); j++) {
            if (i % j == 0) {
                temp++;
                
                if (i % (i / j) == 0 and j != (i / j)) {
                    temp++;
                }
            }
        }
        
        if (temp % 2 == 0) answer += i;
        else answer -= i;
                
        temp = 0;
    }
    
    return answer;
}
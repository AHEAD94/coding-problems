#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    // n의 약수 개수: n이 1부터 sqrt(n)까지 나누어 떨어지는 수
    int divisor = 0;
    
    for (int num = 1; num <= n; num++) {
        
        for (int div = 1; div <= (int)sqrt(num); div++) {
            if (num % div == 0) {
                divisor++;
            }
        }
        if (num != 1) {
            divisor++; // 자기 자신은 자신의 약수
        }
        
        if (divisor >= 3) {
            answer++;
        }
        divisor = 0;
    }
    
    return answer;
}
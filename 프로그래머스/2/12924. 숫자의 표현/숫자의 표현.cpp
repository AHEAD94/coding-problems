#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int sum = 0;
    
    for (int i = 1; i <= n; i++) {
        for (int j = i; sum <= n; j++) {
            sum += j;
            
            if (sum == n) {
                answer++;
                break;
            }
        }
        sum = 0;
    }
    
    return answer;
}
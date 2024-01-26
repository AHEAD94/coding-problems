#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    int digit_mask = 10;
    int temp_n = n;

    while (digit_mask < temp_n) {
        answer += (temp_n % 10);
        temp_n /= 10;
    }
    answer += temp_n;
    
    return answer;
}
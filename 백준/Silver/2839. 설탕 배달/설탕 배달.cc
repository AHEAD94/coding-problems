#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    int answer = 0;
    
    while (0 < N) {
        // 5kg 봉지로 나누어 떨어지는 경우
        if (N % 5 == 0) {
            answer += N / 5;
            N = 0;
            break;
        }
        
        // 3kg 봉지 사용
        N -= 3;
        answer++;
    }
    
    if (N < 0) answer = -1;
    
    cout << answer << endl;
    
    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> stairs(N);
    for (int i = 0; i < N; i++) {
        cin >> stairs[i];
    }
    
    vector<int> dp(N);
    dp[0] = stairs[0];
    dp[1] = stairs[0] + stairs[1];
    dp[2] = stairs[2] + max(stairs[0], stairs[1]);
    
    for (int i = 3; i < N; i++) {
        // i - 1 번째 칸에서 올라왔다면 i - 3 번째의 dp 값을 더함 (한 번에 두 계단 규칙)
        // i - 2 번째 칸에서 올라왔다면 i - 2 번째의 dp 값을 더함
        dp[i] = stairs[i] + max(stairs[i - 1] + dp[i - 3], dp[i - 2]);
    }
    
    cout << dp[N - 1] << endl;
    
    return 0;
}
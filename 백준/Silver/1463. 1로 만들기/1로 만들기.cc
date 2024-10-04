#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    int answer = 0;
    vector<int> dp(N + 1, 0);
    
    // 0 1 2 3 4 5 6 7 8 9 10
    // 0 3 3 2 2 1 4 3 2 1 0
    for (int i = N; i > 0; i--) {
        if (i % 3 == 0) {
            if (dp[i / 3] == 0) dp[i / 3] = dp[i] + 1;
            else dp[i / 3] = min(dp[i / 3], dp[i] + 1);
        }
        if (i % 2 == 0) {
            if (dp[i / 2] == 0) dp[i / 2] = dp[i] + 1;
            else dp[i / 2] = min(dp[i / 2], dp[i] + 1);
        }
        if (i - 1 > 0) {
            if (dp[i - 1] == 0) dp[i - 1] = dp[i] + 1;
            else dp[i - 1] = min(dp[i - 1], dp[i] + 1);
        }
    }
    
    answer = dp[1];
    cout << answer << endl;
    
    return 0;
}
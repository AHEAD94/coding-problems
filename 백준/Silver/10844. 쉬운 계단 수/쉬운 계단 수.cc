#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<vector<int>> dp(10, vector<int>(N + 1));
    
    dp[0][1] = 0;
    for (int num = 1; num < 10; num++) {
        dp[num][1] = 1;
    }
    
    for (int len = 2; len <= N; len++) {
        for (int num = 0; num < 10; num++) {
            if (num > 0) dp[num][len] += dp[num - 1][len - 1];
            if (num < 9) dp[num][len] += dp[num + 1][len - 1];
            dp[num][len] %= 1000000000;
        }
    }
    
    int total_sum = 0;
    for (auto sum : dp) {
        total_sum += sum[N];
        total_sum %= 1000000000;
    }
    cout << total_sum << endl;
    
    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

// fibonacci(0) == 0
// fibonacci(1) == 1
// fibonacci(2) == fibonacci(1) + fibonacci(0)
// fibonacci(3) == fibonacci(2) + fibonacci(1)
// fibonacci(4) == fibonacci(3) + fibonacci(2)
// ...

int main() {
    int T;
    cin >> T;
    
    vector<pair<int, int>> dp;
    dp.push_back(make_pair(1, 0)); // 0
    dp.push_back(make_pair(0, 1)); // 1

    for (int i = 0; i < T; i++) {
        int N;
        cin >> N;
        
        for (int j = 2; j <= N; j++) {
            int size = dp.size();
            if (size <= j) {
                int zero = dp[size - 2].first + dp[size - 1].first;
                int one = dp[size - 2].second + dp[size - 1].second;
                dp.push_back(make_pair(zero, one));
            }
        }
        
        cout << dp[N].first << " " << dp[N].second << "\n";
    }
    
    return 0;
}
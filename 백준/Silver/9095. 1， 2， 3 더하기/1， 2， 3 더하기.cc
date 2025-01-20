#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T, n;
    cin >> T;

    vector<int> dp;
    dp.push_back(0);
    dp.push_back(1);
    dp.push_back(2);
    dp.push_back(4);

    for (int i = 0; i < T; i++) {
        cin >> n;

        while (dp.size() - 1 <= n) {
            int next_val = dp[dp.size() - 3] + dp[dp.size() - 2] + dp[dp.size() - 1];
            dp.push_back(next_val);
        }
        cout << dp[n] << endl;
    }
    return 0;
}
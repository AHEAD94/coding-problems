#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    
    vector<int> coins(N, 0);
    for (size_t i = 0; i < N; i++) {
        cin >> coins[i];
    }
    
    int minCoin = 0;
    
    int idx = N - 1;
    while (K > 0) {
        if (K >= coins[idx]) {
            minCoin += K / coins[idx];
            K %= coins[idx];
        }
        idx--;
    }
    
    cout << minCoin << endl;
    
    return 0;
}
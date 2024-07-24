#include <iostream>
#include <vector>

using namespace std;

unsigned long long GetFibo(const int n) {
    if (n == 0 or n == 1) return n;
    
    vector<unsigned long long> memo{0, 1};
    for (int i = 2; i <= n; i++) {
        memo.push_back(memo[i - 2] + memo[i - 1]);
    }
    return memo.back();
}

int main() {
    int n;
    cin >> n;
    
    cout << GetFibo(n) << endl;
    
    return 0;
}
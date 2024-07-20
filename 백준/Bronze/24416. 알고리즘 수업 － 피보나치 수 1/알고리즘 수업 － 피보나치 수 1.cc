#include <vector>
#include <iostream>

using namespace std;

int FiboRecur(const int n, int& run) {
    if (n == 1 or n == 2) {
        run++;
        return 1;
    }
    else 
        return FiboRecur(n - 1, run) + FiboRecur(n - 2, run);
}

int FiboDP(const int n, int& run) {
    vector<int> f{0, 1, 1};
    for (int i = 3; i <= n; i++) {
        run++;
        f.push_back(f[i - 1] + f[i - 2]);
    }
    return f[n];
}

int main() {
    int recur_run = 0;
    int dp_run = 0;
    int num;
    
    cin >> num;
    
    FiboRecur(num, recur_run);
    FiboDP(num, dp_run);
    
    cout << recur_run << " " << dp_run << endl;
}
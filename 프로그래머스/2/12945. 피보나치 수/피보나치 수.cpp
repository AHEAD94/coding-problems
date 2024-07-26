#include <string>
#include <vector>

using namespace std;

int GetTabulFibo(const int n) {
    if (n == 0 or n == 1) return n;
    
    vector<int> tabul{0, 1};
    for (int i = 2; i <= n; i++) {
        tabul.push_back(tabul[i - 2] % 1234567 + tabul[i - 1] % 1234567);
    }
    return tabul.back() % 1234567;
}

int GetMemoFibo(const int n, vector<int>& memo) {
    if (n == 0 or n == 1) return n;
    
    if (memo[n] == 0) {
        memo[n] = GetMemoFibo(n - 2, memo) % 1234567 + GetMemoFibo(n - 1, memo) % 1234567;
    }
    return memo[n] % 1234567;
}

int solution(int n) {
    int answer = 0;
    vector<int> memo(n + 1, 0);
    
    //answer = GetTabulFibo(n);
    answer = GetMemoFibo(n, memo);
    
    return answer;
}
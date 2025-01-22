#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> fibo;
    // 0 // 1 // 2 // 3 // 5 // 8 // ...
    for (int i = 0; i <= n; i++) {
        if (i < 3) fibo.push_back(i);
        else fibo.push_back(fibo[i - 2] % 1000000007 + fibo[i - 1] % 1000000007);
    }
    
    answer = fibo[fibo.size() - 1] % 1000000007;
    
    return answer;
}
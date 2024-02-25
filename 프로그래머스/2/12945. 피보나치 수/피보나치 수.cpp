#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> fibo;
    
    for (int i = 0; i <= n; i++) {
        if (i == 0 or i == 1) fibo.push_back(i);
        else fibo.push_back(fibo[i - 1] % 1234567 + fibo[i - 2] % 1234567);
    }
    
    answer = fibo[fibo.size() - 1] % 1234567;
    
    return answer;
}
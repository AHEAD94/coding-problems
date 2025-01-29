#include <iostream>
#include <vector>

using namespace std;

/*
[1] (1)
|
[2] (3)
||
=
ㅁ
[3]은 [1]을 [2]의 양쪽에 넣는 방법 뿐임 => [3] = [2] + (2 * [1])
*/

int main() {
    int n;
    cin >> n;
    
    vector<int> dp;
    dp.push_back(0);
    dp.push_back(1);
    dp.push_back(3);
    
    for (int i = 3; i <= n; i++) {
        int tiles = (dp[i - 2] * 2) + dp[i - 1];
        dp.push_back(tiles % 10007);
    }
    
    cout << dp[n] << endl;
    
    return 0;
}
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
[3] (5)
|||
=|
|=
ㅁ|
|ㅁ
[4] (11)
||||
=||
|=|
||=
==
ㅁ||
|ㅁ|
||ㅁ
ㅁㅁ
ㅁ=
=ㅁ
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
#include <iostream>
using namespace std;

int solution(int n)
{
    int ans = 0;
    
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    //cout << "Hello Cpp" << endl;
    
    while (n > 1) {
        if (n % 2 != 0) ans++;
        
        n /= 2;
    }
    ans += n;
    
    return ans;
}
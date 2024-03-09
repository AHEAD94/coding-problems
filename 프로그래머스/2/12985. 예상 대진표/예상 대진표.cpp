#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    //cout << "Hello Cpp" << endl;

    while (a != b) {
        answer++;
        int remainder_a = a % 2;
        int remainder_b = b % 2;
        
        a /= 2;
        if (remainder_a != 0) a++;
        b /= 2;
        if (remainder_b != 0) b++;
    }
    
    return answer;
}
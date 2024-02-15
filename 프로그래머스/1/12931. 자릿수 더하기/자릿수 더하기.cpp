#include <iostream>

using namespace std;
int solution(int n)
{
    int answer = 0;
    string stNum = to_string(n);
    
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;
    
    for (int i = 0; i < stNum.length(); i++) {
        answer += stNum[i] - '0';
    }

    return answer;
}
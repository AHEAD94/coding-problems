#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int num_of_p = 0;
    int num_of_y = 0;
    
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;
    
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'p' or s[i] == 'P') num_of_p++;
        if (s[i] == 'y' or s[i] == 'Y') num_of_y++;
    }
    
    if (num_of_p != num_of_y) answer = false;

    return answer;
}
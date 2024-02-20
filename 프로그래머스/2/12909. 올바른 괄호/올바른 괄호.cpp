#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> chStack;
    
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    //cout << "Hello Cpp" << endl;
    
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') chStack.push(s[i]);
        if (s[i] == ')') {
            if (chStack.size() != 0) chStack.pop();
            else {
                answer = false;
                break;
            }
        }
    }
    
    if (chStack.size() != 0) answer = false;

    return answer;
}
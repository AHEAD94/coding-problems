#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string s)
{
    int answer = -1;
    stack<char> charStack;

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    //cout << "Hello Cpp" << endl;

    for (int i = 0; i < s.length(); i++) {
        if (!charStack.empty() and charStack.top() == s[i])
            charStack.pop();
        else charStack.push(s[i]);
    }
    
    if (charStack.empty()) answer = 1;
    else answer = 0;
    
    return answer;
}
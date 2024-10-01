#include <iostream>
#include <string>

using namespace std;

int main() {
    string brackets;
    cin >> brackets;
    
    int answer = 0;
    int stacks = 0;
    
    // 레이저 인식 : 닫힌 괄호가 나왔을 때, 바로 이전 괄호가 여는 괄호이면 레이저로 인식
    // 레이저로 인식되면 stacks에서 1만큼 제거
    
    // [ PSUDO CODE ]
    // IF 현재 괄호가 여는 괄호면:
    //     stacks++;
    // IF 현재 괄호가 닫는 괄호면:
    //     IF 이전 괄호가 여는 괄호면: // 레이저로 인식
    //         stacks--;
    //         answer += stacks;
    //     ELSE:
    //         stacks--;
    //         answer++;
    
    size_t size = brackets.size();
    for (size_t i = 0; i < size; i++) {
        if (brackets[i] == '(') stacks++;
        
        if (brackets[i] == ')') {
            stacks--;
            
            if (i > 0 and brackets[i - 1] == '(') // 레이저인 경우
                answer += stacks;
            else answer++;
        }
    }
    
    cout << answer << endl;
    
    return 0;
}
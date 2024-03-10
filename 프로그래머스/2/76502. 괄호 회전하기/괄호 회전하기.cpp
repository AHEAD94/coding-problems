#include <string>
#include <vector>
#include <stack>
#include <map>

using namespace std;

void clearStack(stack<char> *_stack) {
    for (int i = 0; i < _stack->size(); i++)
        _stack->pop();
}

int solution(string s) {
    int answer = 0;
    int s_len = s.length();
    bool wrong_string = false;
    stack<char> brakets;
    map<char, char> braket_pair;
    
    braket_pair.insert(make_pair(']', '['));
    braket_pair.insert(make_pair(')', '('));
    braket_pair.insert(make_pair('}', '{'));
    
    for (int i = 0; i < s_len; i++) {
        for (int j = 0; j < s_len; j++) {
            if (s[j] == '[' or s[j] == '(' or s[j] == '{') brakets.push(s[j]);
            else {
                // 닫는 괄호의 여는 괄호 쌍 확인
                map<char, char>::iterator iter = braket_pair.find(s[j]);
                if (brakets.top() == iter->second) brakets.pop();
                else {
                    wrong_string = true;
                    break;
                }
            }
        }
        
        if (brakets.empty() and wrong_string == false) answer++;
        clearStack(&brakets);
        wrong_string = false;
        
        // 배열 회전
        s = s[s.length() - 1] + s;
        s.pop_back();
    }

    return answer;
}
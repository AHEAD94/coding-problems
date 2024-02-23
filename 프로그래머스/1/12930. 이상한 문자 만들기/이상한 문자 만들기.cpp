#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    bool isEven = true;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            answer += s[i];
            isEven = true;
        }
        else {
            if (isEven) {
                answer += toupper(s[i]);
                isEven = false;
            }
            else {
                answer += tolower(s[i]);
                isEven = true;
            }
        }
    }
    
    return answer;
}
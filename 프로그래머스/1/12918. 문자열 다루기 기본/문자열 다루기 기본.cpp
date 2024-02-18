#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;
    int len = s.length();
    
    if (len == 4 or len == 6) {
        for (int i = 0; i < len; i++) {
            if (!('0' <= s[i] and s[i] <= '9')) {
                answer = false;
            }
        }
    }
    else answer = false;
    
    return answer;
}
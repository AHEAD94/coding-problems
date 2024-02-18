#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    for (int i = 0; i < s.length(); i++) {
        if (i == 0 or s[i - 1] == ' ') {
            if ('a' <= s[i] and s[i] <= 'z') {
                s[i] += ('A' - 'a');
            }
        }
        else {
            if ('A' <= s[i] and s[i] <= 'Z') {
                s[i] -= ('A' - 'a');
            }
        }
    }
    
    answer = s;
    
    return answer;
}
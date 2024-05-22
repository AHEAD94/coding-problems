#include <string>
#include <vector>

using namespace std;

char getNextChar(char curr_char) {
    if (curr_char == 'z') return 'a';
    return curr_char + 1;
}

string solution(string s, string skip, int index) {
    string answer = "";
    int s_len = s.length();
    
    for (int i = 0; i < s_len; i++) {
        char next_char = s[i];
        
        int cnt = 0;
        while (cnt < index) {
            next_char = getNextChar(next_char);
            if (skip.find(next_char) == string::npos) {
                cnt++;
            }    
        }
        answer += next_char;
    }
    
    return answer;
}
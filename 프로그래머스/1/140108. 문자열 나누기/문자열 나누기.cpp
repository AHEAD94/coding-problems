#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int str_len = s.length();
    
    char ch_x;
    int x_num = 0;
    int other_num = 0;
    int str_idx = 0;

    while (str_idx < str_len) {
        if (str_idx == 0) ch_x = s[str_idx];
        
        if (s[str_idx] == ch_x) x_num++;
        else other_num++;
        
        if (x_num == other_num) {
            s = s.substr(str_idx + 1);
            str_idx = -1;
            str_len = s.length();
            answer++;
        }
        str_idx++;
    }
    if (str_len > 0) answer++;
    
    return answer;
}
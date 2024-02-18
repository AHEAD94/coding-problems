#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int min = 999999;
    int max = -999999;
    string token = "";
    int temp = 0;
    
    for (int i = 0; i < s.length(); i++) {
        if (('0' <= s[i] and s[i] <= '9') or (s[i] == '-')) {
            token += s[i];
        }
        
        if (s[i] == ' ' or i >= s.length() - 1) {
            temp = stoi(token);
            if (temp > max) max = temp;
            if (temp < min) min = temp;
            
            token = "";
        }
    }
    
    answer += to_string(min);
    answer += ' ';
    answer += to_string(max);
    
    return answer;
}
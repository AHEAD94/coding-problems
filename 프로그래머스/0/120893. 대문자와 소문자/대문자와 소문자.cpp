#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
    string answer = "";
    
    for (int i = 0; i < my_string.length(); i++) {
        if ('A' <= my_string[i] and my_string[i] <= 'Z') {
            answer += my_string[i] + 32;
        }
        else if ('a' <= my_string[i] and my_string[i] <= 'z') {
            answer += my_string[i] - 32;
        }
        else;
    }
    
    return answer;
}
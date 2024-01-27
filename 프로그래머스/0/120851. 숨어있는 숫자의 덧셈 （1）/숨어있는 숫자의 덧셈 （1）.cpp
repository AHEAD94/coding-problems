#include <string>
#include <vector>

using namespace std;

int solution(string my_string) {
    int answer = 0;
    
    for (int i = 0; i < my_string.length(); i++) {
        if ('0' <= my_string[i] and my_string[i] <= '9') {
            answer += my_string[i] - '0';
        }
    }
    
    return answer;
}
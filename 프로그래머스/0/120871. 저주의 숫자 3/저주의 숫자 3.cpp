#include <string>
#include <vector>

using namespace std;

bool has3In(int num) {
    bool has_3 = false;
    string stNum = "";
    
    if (num % 3 == 0) {
        has_3 = true;
    }
        
    stNum = to_string(num);
    if (stNum.find("3") != string::npos) {
        has_3 = true;
    }
    
    return has_3;
}

int solution(int n) {
    int answer = 0;
        
    for (int i = 1; i <= n; i++) {
        answer++;
        
        while (has3In(answer) == true) {
            answer++;
        }
    }
 
    return answer;
}
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    
    string temp = s;
    sort(temp.begin(), temp.end());
    
    for (int i = 0; i < temp.length(); i++) {
        if (i == 0) {
            if (temp[i] != temp[i + 1]) {
                answer += temp[i];
            }
        }
        else {
            if (temp[i - 1] != temp[i] and temp[i] != temp[i + 1]) {
                answer += temp[i];
            }
        }
    }
    
    return answer;
}
#include <string>
#include <vector>

using namespace std;

vector<string> solution(string my_str, int n) {
    vector<string> answer;
    string temp_str = "";
    
    for (int i = 0; i < my_str.length(); i++) {
        temp_str += my_str[i];
        
        if ((i + 1) % n == 0) {
            answer.push_back(temp_str);
            temp_str = "";
        }
    }
    
    if (temp_str != "") {
        answer.push_back(temp_str);
    }
    
    return answer;
}
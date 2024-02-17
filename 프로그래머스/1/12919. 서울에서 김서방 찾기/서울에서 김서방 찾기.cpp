#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "";
    int posKim = 1000;
    
    if (find(seoul.begin(), seoul.end(), "Kim") != seoul.end()) {
        posKim = find(seoul.begin(), seoul.end(), "Kim") - seoul.begin();
    }
    
    answer = "김서방은 " + to_string(posKim) + "에 있다";
    
    return answer;
}
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    map<char, int> charPos;
    
    for (int i = 0; i < s.length(); i++) {
        if (charPos.find(s[i]) == charPos.end()) {
            charPos.insert(make_pair(s[i], i));
            answer.push_back(-1);
        }
        else {
            answer.push_back(i - charPos.find(s[i])->second);
            charPos.find(s[i])->second = i;
        }
    }
    
    return answer;
}
#include <string>
#include <vector>
#include <iostream>

using namespace std;

void PrintString(const string s) {
    for (auto iter = s.begin(); iter != s.end(); iter++) {
        cout << *iter;
    }
}

string solution(string new_id) {
    string answer = "";
    
    // 1단계
    for (auto iter = new_id.begin(); iter != new_id.end(); iter++) {
        if (('A' <= *iter and *iter <= 'Z'))
            *iter = tolower(*iter);
    }
    
    // 2단계
    auto iter = new_id.begin();
    while (iter != new_id.end()) {
        if (!('a' <= *iter and *iter <= 'z') and 
            !('0' <= *iter and *iter <= '9') and 
            !(*iter == '-') and !(*iter == '_') and !(*iter == '.')) {
            new_id.erase(iter);
        }
        else iter++;
    }

    // 3단계
    int idx = 0;
    while (idx < new_id.length()) {
        if (new_id[idx] == '.' and new_id[idx + 1] == '.') {
            if (idx < new_id.length() - 1) {
                new_id.erase(new_id.begin() + idx + 1);
            }
        }
        else idx++;
    }
    
    // 4단계
    if (new_id.front() == '.') new_id.erase(new_id.begin());
    if (new_id.back() == '.') new_id.pop_back();
    
    // 5단계
    if (new_id.empty()) new_id = "a";
    
    // 6단계
    if (new_id.length() >= 16) {
        new_id.erase(new_id.begin() + 15, new_id.end());
        if (new_id.back() == '.') new_id.pop_back();
    }
    
    // 7단계
    if (new_id.length() <= 2) {
        int iter_num = 3 - new_id.length();
        for (int i = 0; i < iter_num; i++) {
            new_id += new_id.back();
        }
    }
    
    answer = new_id;
    
    return answer;
}
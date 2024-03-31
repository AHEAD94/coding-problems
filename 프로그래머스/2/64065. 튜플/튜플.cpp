#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <set>

using namespace std;

bool bySize(vector<int> a, vector<int> b) {
    return a.size() < b.size();
}

vector<int> solution(string s) {
    vector<int> answer;
    stack<char> bracket;
    vector<vector<int>> tuples;
    vector<int> tuple;
    string temp_st = "";
    set<int> num_set;
    
    for (int i = 1; i < s.length() - 1; i++) { // 양 끝 중괄호 무시        
        int element = 0;
        
        // int형으로 바꾸어 tuple에 원소 저장
        if (!bracket.empty()) {
            if (s[i] == ',' or s[i] == '}') {
                element = stoi(temp_st);
                tuple.push_back(element);
                temp_st = "";
            }
            else temp_st += s[i];
        }
        
        if (s[i] == '{') bracket.push(s[i]);
        if (s[i] == '}') {
            tuples.push_back(tuple); // tuple을 tuples에 저장
            bracket.pop();
            tuple = vector<int>();
            temp_st = "";
        }
    }
    
    sort(tuples.begin(), tuples.end(), bySize);
    
    for (vector<int> tuple : tuples) {
        for (int element : tuple) {
            set<int>::iterator iter = num_set.find(element);
            if (iter == num_set.end()) {
                num_set.insert(element);
                answer.push_back(element);
            }
        }
    }
    
    return answer;
}
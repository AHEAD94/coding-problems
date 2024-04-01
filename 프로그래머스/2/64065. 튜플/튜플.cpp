#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool byValue(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) return a.first > b.first;
    return a.second > b.second;
}

vector<int> solution(string s) {
    vector<int> answer;
    map<int, int> num_cnt_map;
    string st_token = "";
    
    for (int i = 1; i < s.length() - 1; i++) { // 양 끝 중괄호 무시                
        if ('0' <= s[i] and s[i] <= '9') {
            st_token += s[i];
        }
        
        // map에 숫자와 숫자의 카운트를 저장
        if (s[i] == ',' or s[i] == '}') {
            if (st_token != "") {
                num_cnt_map[stoi(st_token)]++;
                st_token = "";
            }
        }
    }
    
    vector<pair<int, int>> sorting_vect(num_cnt_map.begin(), num_cnt_map.end());
    sort(sorting_vect.begin(), sorting_vect.end(), byValue);
    
    // 많이 나타난 숫자의 카운트 순으로 answer에 삽입
    for (pair<int, int> num_cnt_pair : sorting_vect) {
        answer.push_back(num_cnt_pair.first);
    }
    
    return answer;
}
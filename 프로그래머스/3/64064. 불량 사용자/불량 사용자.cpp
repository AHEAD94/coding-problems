#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

set<set<string>> combinations;

bool IsCandidate(const string bid, const string uid) {    
    if (bid.length() != uid.length()) // 길이가 다르면 비교대상이 아님
        return false;
    
    for (int i = 0; i < bid.length(); i++) {
        if (bid[i] != '*' and bid[i] != uid[i]) // bid에서 *이 아닌 부분은 uid와 같아야 함
            return false;
    }
    return true;
}

void DFS(vector<string>& user_id, vector<string>& banned_id, vector<bool>& visited, int depth, set<string> temp_comb) {
    if (depth == banned_id.size()) {
        combinations.insert(temp_comb);
        return;
    }
    
    for (auto u_iter = user_id.begin(); u_iter != user_id.end(); u_iter++) {
        int u_idx = u_iter - user_id.begin();
        
        if (visited[u_idx] == false and IsCandidate(banned_id[depth], *u_iter)) {
            visited[u_idx] = true;
            
            set<string> temp = temp_comb;
            temp.insert(user_id[u_idx]);
            DFS(user_id, banned_id, visited, depth + 1, temp);
            
            visited[u_idx] = false;
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    vector<bool> visited(user_id.size(), false);
    
    DFS(user_id, banned_id, visited, 0, {});
    
    answer = combinations.size();

    return answer;
}
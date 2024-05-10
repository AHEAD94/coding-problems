#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    for (string skill_tree : skill_trees) {
        int skill_idx = 0;
        int skill_tree_len = skill_tree.length();
        bool is_possible = true;
        
        for (int i = 0; i < skill_tree_len; i++) {
            if (skill.find(skill_tree[i]) != string::npos) {
                if (skill_tree[i] == skill[skill_idx])
                    skill_idx++;
                else {
                    is_possible = false;
                    break;
                }
            }
        }
        if (is_possible) answer++;
    }
    
    return answer;
}
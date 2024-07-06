#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    vector<int> min_clicks(26, -1); // 알파벳마다 입력이 적은 클릭 횟수를 저장하는 벡터
    
    for (auto target : targets) {
        int click_num = 0; // 타겟 입력까지 필요한 클릭 횟수
        //cout << "===========================" << endl;
            
        for (int tar_idx = 0; tar_idx < target.size(); tar_idx++) {
            int alp_idx = target[tar_idx] - 'A';
            //cout << "CUR_TARGET: " << target[tar_idx] << "\t";
            
            // min_clicks에 없는 알파벳인 경우
            if (min_clicks[alp_idx] == -1) {
                bool in_process = true;
                bool is_found = false;
                int click_idx = 0;
                
                while (in_process == true and is_found == false) {
                    in_process = false;
                    
                    for (int key_idx = 0; key_idx < keymap.size(); key_idx++) {
                        if (click_idx < keymap[key_idx].size()) {
                            in_process = true;
                            
                            // 키맵 입력이 타겟 글자와 같다면 min_clicks에 저장
                            if (keymap[key_idx][click_idx] == target[tar_idx]) {
                                min_clicks[alp_idx] = click_idx + 1;
                                is_found = true;
                                break;
                            }
                        }
                    }
                    click_idx++;
                }
            }
            //cout << "(" << shortcut[alp_idx] << ")" << endl;
            
            // 키 클릭 수 반영
            if (min_clicks[alp_idx] == -1) {
                click_num = -1;
                break;
            }
            click_num += min_clicks[alp_idx];
        }
        answer.push_back(click_num);
    }
    
    return answer;
}
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    
    // 사전 초기화
    vector<string> dict(26);
    char temp_char = 'A';
    for (int i = 0; i < 26; i++) {
        dict[i] = temp_char++;
    }
    
    int msg_idx = 0;
    int msg_size = msg.size();
    while (msg_idx < msg_size) {
        string word = "";
        vector<string>::iterator iter;
        vector<string>::iterator next_iter;
        
        // 사전에 있는 가장 긴 단어탐색
        int word_idx = msg_idx;
        for (; word_idx < msg_size; word_idx++) {
            word += msg[word_idx];
            if (word_idx < msg_size - 1) {
                next_iter = find(dict.begin(), dict.end(), word + msg[word_idx + 1]);
                if (next_iter == dict.end()) break;
            }
        }
        
        // 사전 인덱스 저장 및 다음 단어 추가
        iter = find(dict.begin(), dict.end(), word);
        if (iter != dict.end()) {
            int dict_idx = iter - dict.begin() + 1;
            answer.push_back(dict_idx);
            dict.push_back(word + msg[word_idx + 1]);
        }
        
        // 단어 크기만큼 msg 스킵
        msg_idx += word.size();
    }
    
    return answer;
}
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    vector<string> babb_words = {"aya", "ye", "woo", "ma"};
    int babb_size = babbling.size();
    
    for (int i = 0; i < babb_size; i++) {
        string babb = babbling[i];
        string prev_word = "";
        
        while (babb != "") {
            bool found = false;
            
            for (int j = 0; j < 4; j++) {
                int pos = babb.find(babb_words[j]);
                if (pos == 0 and babb_words[j] != prev_word) {
                    found = true;
                    prev_word = babb_words[j];
                    int word_len = babb_words[j].length();
                    babb.erase(babb.begin(), babb.begin() + word_len);
                }
            }
            if (found == false) break;
        }
        if (babb == "") answer++;
    }
    
    return answer;
}
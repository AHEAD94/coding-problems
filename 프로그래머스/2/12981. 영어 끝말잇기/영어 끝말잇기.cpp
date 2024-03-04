#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    vector<string> used;
    int turn = 1;
    int cycle = 0;
    
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다. 
    //cout << "Hello Cpp" << endl;
    
    for (int i = 0; i < words.size(); i++) {
        if (turn > n) turn %= n;
        if (turn == 1) cycle++;
    
        // 중복 단어 오류
        vector<string>::iterator iter = find(used.begin(), used.end(), words[i]);
        if (iter != used.end()) {
            answer.push_back(turn);
            answer.push_back(cycle);
            break;
        }
        used.push_back(words[i]);
        
        // 시작 단어 오류
        if (i > 0) {
            char lastChar = words[i - 1][words[i - 1].length() - 1];
            char startChar = words[i][0];
            if (lastChar != startChar) {
                answer.push_back(turn);
                answer.push_back(cycle);
                break;
            }
        }
        
        turn++;
    }
    
    if (answer.size() == 0) {
        answer.push_back(0);
        answer.push_back(0);
    }

    return answer;
}
#include <string>
#include <vector>
#include <iostream>

using namespace std;

void printScores(vector<vector<string>> personalities, const vector<vector<int>> scores) {
    for (int i = 0; i < 4; i++) {
        cout << "[" << personalities[i][0] << "] " << scores[i][0] << " : " << scores[i][1] << endl;
    }
    cout << endl;
    return;
}

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    vector<vector<string>> personalities{
        {"RT", "TR"},
        {"CF", "FC"},
        {"JM", "MJ"},
        {"AN", "NA"}
    };
    vector<vector<int>> scores(4, {0, 0});
    
    int surv_size = survey.size();
    for (int i = 0; i < surv_size; i++) {
        string surv = survey[i];
        int choice = choices[i];
        
        /* 성격 점수반영 방향과 그 점수의 계산 */
        int pers_dir = 2; // 0: 왼쪽, 1: 오른쪽
        int score = 0;
        
        if (1 <= choice and choice < 4) {
            pers_dir = 0;
            score = 4 - choice;
        }
        if (4 < choice and choice <= 7) {
            pers_dir = 1;
            score = choice - 4;
        }
        
        /* 점수를 매길 성격의 인덱스 탐색 */
        int pers_idx = 4; // 점수를 매길 성격의 인덱스
        int pers_order = 2; // 질문지에서의 성격 순서, 0: 알파벳 순, 1: 알파벳 역순
        
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 2; k++) {
                if (personalities[j][k] == surv) {
                    pers_idx = j;
                    pers_order = k;
                }
            }
        }
        
        /* 성격 점수 반영 */
        if (pers_dir == 0 or pers_dir == 1) {
            if (pers_order == 0) 
                scores[pers_idx][pers_dir] += score;
            else scores[pers_idx][pers_dir ? 0 : 1] += score;
        }
    }
    // printScores(personalities, scores);
    
    /* 성격유형 결정 */
    string result = "";
    for (int i = 0; i < 4; i++) {
        if (scores[i][0] < scores[i][1]) 
            result += personalities[i][0][1];
        else result += personalities[i][0][0]; // 두 성격의 점수가 같은 경우 포함
    }
    //cout << result << endl;
    
    answer = result;
    
    return answer;
}
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    string str_num = "";
    vector<int> scores(3, 0);
    int scores_idx = 0;
    
    int result_len = dartResult.length();
    for (int i = 0; i < result_len; i++) {
        // 점수 저장
        if ('0' <= dartResult[i] and dartResult[i] <= '9')
            str_num += dartResult[i];
        else if (str_num != "") {
            scores[scores_idx++] = stoi(str_num);
            str_num = "";
        }
        
        // 보너스 처리
        int bonus = 1;
        if (dartResult[i] == 'D') bonus = 2;
        if (dartResult[i] == 'T') bonus = 3;
        if (bonus != 1)
            scores[scores_idx - 1] = pow(scores[scores_idx - 1], bonus);
        
        // 옵션 처리
        if (dartResult[i] == '*') {
            scores[scores_idx - 1] *= 2;
            if (scores_idx - 1 > 0) scores[scores_idx - 2] *= 2;
        }
        if (dartResult[i] == '#') {
            scores[scores_idx - 1] *= -1;
        }
    }
    
    for (int i = 0; i < 3; i++) {
        answer += scores[i];
    }
    
    return answer;
}
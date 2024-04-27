#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool byScoreSum(vector<int> a, vector<int> b) {
    return a[0] + a[1] > b[0] + b[1];
}

int solution(vector<vector<int>> scores) {
    int answer = 0;
    int scores_size = scores.size();
    
    // 원호 점수
    vector<int> wanho_score = scores[0];
    int wanho_total = wanho_score[0] + wanho_score[1];
    
    // 원호보다 높은 점수의 사원들만 대상으로 지정
    vector<vector<int>> upper_scores;
    for (int i = 1; i < scores_size; i++) {
        int other_total = scores[i][0] + scores[i][1];
        if (wanho_total < other_total) upper_scores.push_back(scores[i]);
    }

    sort(upper_scores.begin(), upper_scores.end(), byScoreSum);
    
    // 비대상자를 제외한 대상자만 골라내기
    vector<vector<int>> candidates;
    int upper_size = upper_scores.size();
    for (int i = 0; i < upper_size; i++) {
        if (wanho_score[0] < upper_scores[i][0] and 
            wanho_score[1] < upper_scores[i][1])
            return -1;
        
        bool is_candidate = true;
        for (int j = 0; j < i; j++) {
            if (upper_scores[i][0] < upper_scores[j][0] and 
                upper_scores[i][1] < upper_scores[j][1]) {                
                is_candidate = false;
                break;
            }
        }
        if (is_candidate) candidates.push_back(upper_scores[i]);
    }
    
    // 등수 계산 - 원호와 같은 총점의 사원들은 원호와 등수가 같으므로, 윗 등수만 고려하면 됨
    answer = 1;
    int candidates_size = candidates.size();
    for (int i = 0; i < candidates_size; i++) {
        answer++;
    }
    
    return answer;
}
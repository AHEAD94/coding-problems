#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool byScoreSum(vector<int> a, vector<int> b) {
    return a[0] + a[1] > b[0] + b[1];
}

int solution(vector<vector<int>> scores) {
    int answer = 0;
    int employee_size = scores.size();
    vector<int> wanho_score = scores[0];
    
    // 완호보다 높은 총점의 사원들을 대상으로 설정
    vector<vector<int>> upper_scores;
    int wanho_total = wanho_score[0] + wanho_score[1];
    for (int i = 1; i < employee_size; i++) {
        int other_total = scores[i][0] + scores[i][1];
        if (wanho_total < other_total) upper_scores.push_back(scores[i]);
    }
    
    sort(upper_scores.begin(), upper_scores.end(), byScoreSum);
    
    int upper_size = upper_scores.size();
    for (int i = 0; i < upper_size; i++) {
        if (wanho_score[0] < upper_scores[i][0] and wanho_score[1] < upper_scores[i][1])
            return -1; // 원호가 대상에서 제외되는 경우
        
        bool is_candidate = true;
        for (int j = 0; j < i; j++) {
            if (upper_scores[i][0] < upper_scores[j][0] and upper_scores[i][1] < upper_scores[j][1]) {
                is_candidate = false;
                break;
            }
        }
        if (is_candidate) answer++;
    }
    answer++;
    
    return answer;
}
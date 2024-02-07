#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<vector<int>> score) {
    vector<int> answer;
    vector<double> average_score;
    vector<double> average_score_sorted;
    
    for (int i = 0; i < score.size(); i++) {
        average_score.push_back((score[i][0] + score[i][1]) / 2.0);
    }
    
    average_score_sorted = average_score;
    sort(average_score_sorted.begin(), average_score_sorted.end(), greater<>());
    
    for (int i = 0; i < average_score.size(); i++) {
        for (int j = 0; j < average_score_sorted.size(); j++) {
            if (average_score[i] == average_score_sorted[j]) {
                answer.push_back(j + 1);
                break;
            }
        }
    }
    
    return answer;
}
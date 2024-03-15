#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> person1_answer = {1, 2, 3, 4, 5};
    vector<int> person2_answer = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> person3_answer = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    int p1_idx = 0;
    int p2_idx = 0;
    int p3_idx = 0;
    int p1_score = 0;
    int p2_score = 0;
    int p3_score = 0;
    
    for (int i = 0; i < answers.size(); i++) {
        if (answers[i] == person1_answer[p1_idx]) p1_score++;
        if (answers[i] == person2_answer[p2_idx]) p2_score++;
        if (answers[i] == person3_answer[p3_idx]) p3_score++;
        p1_idx = (p1_idx + 1) % person1_answer.size();
        p2_idx = (p2_idx + 1) % person2_answer.size();
        p3_idx = (p3_idx + 1) % person3_answer.size();
    }
    
    int max_score = max(max(p1_score, p2_score), p3_score);
    if (max_score == p1_score) answer.push_back(1);
    if (max_score == p2_score) answer.push_back(2);
    if (max_score == p3_score) answer.push_back(3);
    
    return answer;
}
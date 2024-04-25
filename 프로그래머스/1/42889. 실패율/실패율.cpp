#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool byFailureRate(pair<int, float> a, pair<int, float> b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    int stages_size = stages.size();

    // stage별 실패율 초기화 
    vector<pair<int, float>> failure_rates;
    for (int i = 1; i <= N; i++) {
        failure_rates.push_back(make_pair(i, 0.0));
    }
    
    // map을 이용해 stage별 유저 수 정리
    map<int, int> temp_map;
    for (int i = 0; i < stages_size; i++) {
        temp_map[stages[i]]++;
    }
    
    // pair들을 vector에 옮김
    vector<pair<int, int>> stage_players(temp_map.size());
    copy(temp_map.begin(), temp_map.end(), stage_players.begin());
    int stage_players_size = stage_players.size();
    
    for (int i = 0; i < stage_players_size; i++) {
        int stage_idx = stage_players[i].first;
        int challengers = stage_players[i].second;
        
        if (stage_idx <= N) {
            float failure_rate = (float) challengers / (float) stages_size;
            failure_rates[stage_idx - 1].second = failure_rate;
        }
        stages_size -= challengers;
    }
    
    sort(failure_rates.begin(), failure_rates.end(), byFailureRate);
    
    for (pair<int, float> failure_rate : failure_rates) {
        int stage_number = failure_rate.first;
        answer.push_back(stage_number);
    }
    
    return answer;
}
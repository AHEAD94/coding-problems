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
    map<int, int> stage_players_map;
    int stages_size = stages.size();
    
    for (int i = 0; i < stages_size; i++) {
        stage_players_map[stages[i]]++;
    }
    
    vector<pair<int, int>> stage_players_vect(stage_players_map.begin(), stage_players_map.end());
    int stage_players_size = stage_players_vect.size();
    
    vector<pair<int, float>> failure_rates;
    for (int i = 1; i <= N; i++) {
        failure_rates.push_back(make_pair(i, 0.0));
    }
    
    for (int i = 0; i < stage_players_size; i++) {
        int stage_idx = stage_players_vect[i].first;
        int challengers = stage_players_vect[i].second;
        
        if (stage_idx < N + 1) {
            float failure_rate = (float) challengers / (float) stages_size;
            failure_rates[stage_idx - 1].second = failure_rate;
        }
        stages_size -= challengers;
    }
    
    sort(failure_rates.begin(), failure_rates.end(), byFailureRate);
    
    for (pair<int, float> num : failure_rates) {
        answer.push_back(num.first);
    }
    
    return answer;
}
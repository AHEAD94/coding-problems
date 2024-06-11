#include <string>
#include <vector>
#include <iostream>

using namespace std;

template<class T>
void PrintVector(const T& vector_begin, const T& vector_end) {
    for (auto iter = vector_begin; iter != vector_end; iter++) {
        cout << *iter << "\t";
    }
    cout << endl;
}

int GetWeight(vector<int> &on_bridge) {
    int net_weight = 0;
    for (int weight : on_bridge) {
        net_weight += weight;
    }
    return net_weight;
}

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int weight_size = truck_weights.size();
    int truck_idx = 0;
    vector<int> on_bridge(bridge_length, 0);
    
    while (truck_idx < weight_size) {
        // 트럭이 다리에서 나가는 경우
        if (on_bridge.back() != 0) {
            on_bridge.back() = 0;
        }
        
        // 트럭이 다리 위에서 길이 1만큼 이동하는 경우
        if (on_bridge.back() == 0) {
            for (int i = bridge_length - 1; i > 0; i--) {
                on_bridge[i] = on_bridge[i - 1];
            }
            on_bridge.front() = 0;
        }
        
        // 트럭이 다리에 진입하는 경우
        int next_weight = truck_weights[truck_idx];
        if (on_bridge.front() == 0 and GetWeight(on_bridge) + next_weight <= weight) {
            on_bridge.front() = next_weight;
            truck_idx++;
        }
        
        answer++;
        
        // cout << "[" << answer << "]" << endl;
        // PrintVector(on_bridge.begin(), on_bridge.end());
    }
    
    answer += bridge_length;
        
    return answer;
}
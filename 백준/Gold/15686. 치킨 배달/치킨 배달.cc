#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Store {
    pair<int, int> position;
    int distance_sum;
};

bool ByDist(Store s1, Store s2) {
    return s1.distance_sum < s2.distance_sum;
}

int CalculateDistance(const pair<int, int>& d1, const pair<int, int>& d2) {
    return abs(d1.first - d2.first) + abs(d1.second - d2.second);
}

int CalculateTotalChickenDistance(const int map_size, const int remains, const vector<pair<int, int>>& store_positions, const vector<pair<int, int>>& customer_positions) {
    vector<int> combination(store_positions.size(), 0);
    fill(combination.end() - remains, combination.end(), 1);

    int min_total_distance = 999999;

    do {
        vector<pair<int, int>> selected_stores;
        for (int i = 0; i < store_positions.size(); ++i) {
            if (combination[i]) {
                selected_stores.push_back(store_positions[i]);
            }
        }

        int total_distance = 0;
        for (const auto& customer : customer_positions) {
            int min_distance = CalculateDistance({0, 0}, {map_size - 1, map_size - 1});
            for (const auto& store : selected_stores) {
                min_distance = min(min_distance, CalculateDistance(customer, store));
            }
            total_distance += min_distance;
        }

        min_total_distance = min(min_total_distance, total_distance);
    } while (next_permutation(combination.begin(), combination.end()));

    return min_total_distance;
}

int main() {
    int  N, M, info;
    cin >> N >> M;
    
    vector<pair<int, int>> store_positions;
    vector<pair<int, int>> customer_positions;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> info;
            if (info == 1) customer_positions.push_back({i, j});
            if (info == 2) store_positions.push_back({i, j});
        }
    }

    int total_chicken_distance = CalculateTotalChickenDistance(N, M, store_positions, customer_positions);
    cout << total_chicken_distance << endl;
    
    return 0;
}
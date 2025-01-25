#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<vector<int>> people(N, vector<int>(2));
    for (int i = 0; i < N; i++) {
        cin >> people[i][0] >> people[i][1];
    }
    
    for (auto& p1 : people) {
        int p1_rank = 1;
        for (auto p2 : people) {
            if (p1[0] < p2[0] && p1[1] < p2[1]) {
                p1_rank++;
            }
        }
        p1.push_back(p1_rank);
    }
    
    for (const auto& p : people) {
        cout << p[2] << endl;
    }
    
    return 0;
}
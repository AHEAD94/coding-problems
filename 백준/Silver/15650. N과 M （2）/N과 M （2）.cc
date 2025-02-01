#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<int> nums;
    for (int i = 1; i <= N; i++) {
        nums.push_back(i);
    }
    
    vector<int> cases(N, 0);
    for (int i = 0; i < M; i++) {
        cases[i] = 1;
    }
    
    do {
        for (int i = 0; i < N; i++) {
            if (cases[i] == 1) {
                cout << nums[i] << ' ';
            }
        }
        cout << '\n';
    } while (prev_permutation(cases.begin(), cases.end()));
    
    return 0;
}
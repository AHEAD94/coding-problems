#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void BackTrack(const vector<int>& input, vector<int> visited, int target_len, vector<int>& nums) {
    int input_size = static_cast<int>(input.size());
    int nums_size = static_cast<int>(nums.size());
    
    if (nums_size == target_len) {
        for (int num : nums) {
            cout << num << ' ';
        }
        cout << '\n';
        return;
    }
    
    for (int i = 0; i < input_size; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            nums.push_back(input[i]);
            BackTrack(input, visited, target_len, nums);
            visited[i] = 0;
            nums.pop_back();
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<int> input(N);
    for (int i = 0; i < N; i++) {
        cin >> input[i];
    }
    sort(input.begin(), input.end());
    
    vector<int> visited(N, 0);
    vector<int> nums;
    
    BackTrack(input, visited, M, nums);
}
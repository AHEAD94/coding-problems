#include <iostream>
#include <vector>

using namespace std;

void BackTrack(const vector<int>& input, vector<vector<int>> visited, int target_len, vector<int>& nums) {
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
        if (!visited[nums_size][i]) {
            if (nums.empty() || (!nums.empty() && input[i] >= nums.back())) {
                visited[nums_size][i] = 1;
                nums.push_back(input[i]);
                BackTrack(input, visited, target_len, nums);
                nums.pop_back();
            }
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<int> input(N);
    for (int i = 0; i < N; i++) {
        input[i] = i + 1;
    }
    vector<vector<int>> visited(M, vector<int>(N, 0));
    vector<int> nums;
    
    BackTrack(input, visited, M, nums);
}
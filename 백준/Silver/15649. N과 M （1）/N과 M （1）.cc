#include <iostream>
#include <vector>

using namespace std;

void DFS(const int& N, const int& M, vector<int>& visited, vector<int>& nums, int depth) {
    if (depth >= M) {
        for (auto num : nums) {
            cout << num << ' ';
        }
        cout << '\n';
        return;
    }
    
    for (int i = 0; i < N; i++) {
        if (visited[i] == 0) {
            // 방문 처리 및 숫자 추가
            visited[i] = 1;
            nums.push_back(i + 1);
            
            DFS(N, M, visited, nums, depth + 1);
            
            // DFS 이전 상태로 복구
            visited[i] = 0;
            nums.pop_back();
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<int> nums;
    vector<int> visited(N, 0);
    
    DFS(N, M, visited, nums, 0);
    
    return 0;
}
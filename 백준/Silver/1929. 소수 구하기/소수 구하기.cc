#include <iostream>
#include <vector>

using namespace std;

int main() {
    int M, N;
    cin >> M >> N;
    
    vector<int> nums(N + 1, 1);
    nums[0] = 0;
    nums[1] = 0;
    
    // 에라토스테네스의 체 사용
    for (int i = 2; i <= N; i++) {
        int n = 2;
        while (i * n <= N) {
            nums[i * n] = 0;
            n++;
        }
    }
    
    for (int i = M; i <= N; i++) {
        if (nums[i] == 1) cout << i << '\n';
    }
    
    return 0;
}
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int main() {
    int n, seq;
    cin >> n >> seq;
    int seq_count = 0;

    stack<int> nums;
    queue<char> operations;
    for (int i = 1; i <= n; i++) {
        nums.push(i);
        operations.push('+');
        while (!nums.empty() && nums.top() == seq) {
            nums.pop();
            operations.push('-');
            cin >> seq;
            seq_count++;
        }
    }
    
    if (seq_count == n) {
        while (!operations.empty()) {
            cout << operations.front() << '\n';
            operations.pop();
        }
    }
    else cout << "NO\n";
    
    return 0;
}
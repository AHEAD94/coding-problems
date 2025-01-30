#include <iostream>
#include <stack>

using namespace std;

int main() {
    int K;
    cin >> K;
    
    int sum = 0;
    stack<int> nums;
    
    for (int i = 0; i < K; i++) {
        int num;
        cin >> num;
        
        if (num == 0) {
            if (!nums.empty()) {
                sum -= nums.top();
                nums.pop();
            } 
        }
        else {
            sum += num;
            nums.push(num);
        }
    }
    cout << sum << endl;
}
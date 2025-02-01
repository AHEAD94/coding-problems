#include <iostream>
#include <queue>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    queue<int> num_q;
    
    for (int i = 0; i < N; i++) {
        string command;
        cin >> command;
        
        if (command == "push") {
            int num;
            cin >> num;
            num_q.push(num);
        }
        else if (command == "pop") {
            if (!num_q.empty()) {
                cout << num_q.front() << '\n';
                num_q.pop();
            }
            else {
                cout << -1 << '\n';
            }
        }
        else if (command == "size") {
            cout << num_q.size() << '\n';
        }
        else if (command == "empty") {
            if (num_q.empty()) {
                cout << 1 << '\n';
            }
            else {
                cout << 0 << '\n';
            }
        }
        else if (command == "front") {
            if (!num_q.empty()) {
                cout << num_q.front() << '\n';
            }
            else {
                cout << -1 << '\n';
            }
        }
        else if (command == "back") {
            if (!num_q.empty()) {
                cout << num_q.back() << '\n';
            }
            else {
                cout << -1 << '\n';
            }
        }
    }
    
    return 0;
}
#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<int> num_stack;
    
    int op_num;
    cin >> op_num;
    
    for (int i = 0; i < op_num; i++) {
        string oper;
        cin>> oper;
        
        if (oper == "push") {
            int num;
            cin >> num;
            num_stack.push(num);
        }
        else if (oper == "pop") {
            if (!num_stack.empty()) {
                cout << num_stack.top() << endl;
                num_stack.pop();
            }
            else cout << -1 << endl;
        }
        else if (oper == "size") {
            cout << num_stack.size() << endl;
        }
        else if (oper == "empty") {
            if (num_stack.empty()) cout << 1 << endl;
            else cout << 0 << endl;
        }
        else if (oper == "top") {
            if (!num_stack.empty()) {
                cout << num_stack.top() << endl;
            }
            else cout << -1 << endl;
        }
        else {
            // Do nothing
        }
    }
}
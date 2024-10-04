#include <iostream>
#include <stack>

using namespace std;

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        string answer = "YES";
        stack<char> checker;
        
        string parenthesis;
        cin >> parenthesis;
        
        for (char p : parenthesis) {
            if (p == '(')
                checker.push(p);
            
            if (p == ')') {
                if (checker.empty()) {
                    answer = "NO";
                    break;
                }
                checker.pop(); 
            }
        }
        
        if (!checker.empty()) answer = "NO";
        
        cout << answer << endl;
    }
    
    return 0;
}